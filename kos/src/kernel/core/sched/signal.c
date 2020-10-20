/* Copyright (c) 2019-2020 Griefer@Work                                       *
 *                                                                            *
 * This software is provided 'as-is', without any express or implied          *
 * warranty. In no event will the authors be held liable for any damages      *
 * arising from the use of this software.                                     *
 *                                                                            *
 * Permission is granted to anyone to use this software for any purpose,      *
 * including commercial applications, and to alter it and redistribute it     *
 * freely, subject to the following restrictions:                             *
 *                                                                            *
 * 1. The origin of this software must not be misrepresented; you must not    *
 *    claim that you wrote the original software. If you use this software    *
 *    in a product, an acknowledgement (see the following) in the product     *
 *    documentation is required:                                              *
 *    Portions Copyright (c) 2019-2020 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_KERNEL_INCLUDE_SCHED_SIGNAL_C
#define GUARD_KERNEL_INCLUDE_SCHED_SIGNAL_C 1
#define __SIG_INTERNAL_EXPOSE_CONTROL_WORD 1
#define _KOS_SOURCE 1

#include <kernel/compiler.h>

#include <kernel/except.h>
#include <kernel/paging.h>
#include <kernel/printk.h>
#include <kernel/selftest.h> /* DEFINE_TEST */
#include <sched/rpc.h>
#include <sched/signal-completion.h>
#include <sched/signal.h>
#include <sched/task.h>

#include <hybrid/align.h>
#include <hybrid/atomic.h>

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#if defined(__i386__) || defined(__x86_64__)
#include <kernel/vm/nopf.h>

#include <asm/intrin.h>
#include <kos/kernel/segment.h>
#endif /* __i386__ || __x86_64__ */

#ifdef NDEBUG
#define DBG_memset(ptr, byte, num_bytes) (void)0
#else /* NDEBUG */
#define DBG_memset(ptr, byte, num_bytes) memset(ptr, byte, num_bytes)
#endif /* !NDEBUG */

DECL_BEGIN

/* Root connections set. */
PUBLIC ATTR_PERTASK struct task_connections this_root_connections = {
	/* .tsc_prev   = */ NULL,
	/* .tcs_thread = */ NULL, /* Fill in by `pertask_init_task_connections()' */
	/* .tcs_con    = */ NULL,
	/* .tcs_dlvr   = */ NULL,
	/* .tcs_static = */ { }
};

/* [1..1][lock(PRIVATE(THIS_TASK))] Current set of in-use connections.
 * Most of the time, this will simply point to `PERTASK(this_root_connections)' */
PUBLIC ATTR_PERTASK struct task_connections *
this_connections = NULL; /* Fill in by `pertask_init_task_connections()' */

DEFINE_PERTASK_INIT(pertask_init_task_connections);
DEFINE_PERTASK_ONEXIT(task_disconnectall); /* Disconnect all remaining connections during task cleanup. */

INTERN NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pertask_init_task_connections)(struct task *__restrict self) {
	struct task_connections *rootcons;
	rootcons = &FORTASK(self, this_root_connections);
	rootcons->tcs_thread = self;
	FORTASK(self, this_connections) = rootcons;
}

#if defined(__x86_64__) || defined(__i386__)
INTERN NOBLOCK ATTR_RETNONNULL struct task *
NOTHROW(KCALL x86_repair_broken_tls_state)(void);
#endif /* __x86_64__ || __i386__ */

/* Push/pop the active set of connections. */
PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(FCALL task_pushconnections)(struct task_connections *__restrict cons) {
	struct task_connections *oldcons;
	unsigned int i;
#ifdef NDEBUG
	oldcons = THIS_CONNECTIONS;
#elif defined(__i386__) || defined(__x86_64__)
	struct task *mythread;
#ifdef __x86_64__
	mythread = (struct task *)__rdgsbaseq();
#else /* __x86_64__ */
	mythread = NULL;
	if likely(__rdfs() == SEGMENT_KERNEL_FSBASE) {
		struct desctab gdt;
		__sgdt(&gdt);
		if likely(gdt.dt_limit > SEGMENT_KERNEL_FSBASE) {
			struct segment *fsseg;
			fsseg    = (struct segment *)(gdt.dt_base + SEGMENT_KERNEL_FSBASE);
			mythread = (struct task *)segment_rdbaseX(fsseg);
		}
	}
#endif /* !__x86_64__ */
	if unlikely(memcpy_nopf(&oldcons, &FORTASK(mythread, this_connections), sizeof(oldcons)) != 0) {
		assertf(memcpy_nopf(&oldcons, &FORTASK(mythread, this_connections), sizeof(oldcons)) == 0,
		        "Corrupt TLS base pointer: mythread = %p", mythread);
		/* Allow the user to IGNORE the assertion check, in which case we'll
		 * try to repair the damage... */
		mythread = x86_repair_broken_tls_state();
		oldcons  = FORTASK(mythread, this_connections);
	}
#else /* ... */
	oldcons = THIS_CONNECTIONS;
#endif /* !... */
	assertf(cons != oldcons,
	        "Connections set %p has already been pushed",
	        cons);
	cons->tsc_prev = oldcons;
	/* Disable async notifications for the old set of connections,
	 * and use the receiver thread for the new set of connections.
	 * Really, though: This should always just be `THIS_TASK' */
	cons->tcs_thread = ATOMIC_XCH(oldcons->tcs_thread, NULL);
	cons->tcs_con    = NULL; /* No connections in use (yet) */
	cons->tcs_dlvr   = NULL; /* Nothing was delivered (yet) */
	DBG_memset(cons->tcs_static, 0xcc, sizeof(cons->tcs_static));
	/* Set-up statically allocated connections. */
	for (i = 0; i < CONFIG_TASK_STATIC_CONNECTIONS; ++i)
		cons->tcs_static[i].tc_sig = NULL; /* Available for use. */
	/* Finally, set the active connection set to `cons' */
	PERTASK_SET(this_connections, cons);
}

PUBLIC NOBLOCK ATTR_RETNONNULL struct task_connections *
NOTHROW(FCALL task_popconnections)(void) {
	struct task_connections *oldcons;
	struct task_connections *cons;
	cons = THIS_CONNECTIONS;
	assert((cons->tsc_prev == NULL) == (cons == THIS_ROOT_CONNECTIONS));
	assertf(cons != THIS_ROOT_CONNECTIONS,
	        "Cannot pop connections: Root connection set %p is already active",
	        cons);
	/* Terminate all connections that may still be active for `cons'. */
	task_disconnectall();

	/* Set the TLS pointer for the current set of connection to the old set. */
	oldcons = cons->tsc_prev;
	PERTASK_SET(this_connections, oldcons);

	/* Re-enable asynchronous notifications as the result of `sig_send()' / `sig_broadcast()' */
	ATOMIC_WRITE(oldcons->tcs_thread, THIS_TASK);

	/* Make bad usage consistent by filling memory with garbage. */
	DBG_memset(cons, 0xcc, sizeof(*cons));

	return cons;
}


/* Allocate a new task connection. */
PRIVATE ATTR_RETNONNULL WUNUSED NONNULL((1)) struct task_connection *FCALL
task_connection_alloc(struct task_connections *__restrict self) /*THROWS(E_BADALLOC)*/ {
	unsigned int i;
	struct task_connection *result;
	/* Check if one of the static slots is available. */
	for (i = 0; i < CONFIG_TASK_STATIC_CONNECTIONS; ++i) {
		result = &self->tcs_static[i];
		if (!result->tc_sig)
			goto done;
	}
	/* Must dynamically allocate a new slot. */
	result = (struct task_connection *)kmalloc(sizeof(struct task_connection),
	                                           GFP_LOCKED | GFP_PREFLT);
done:
	return result;
}

/* Freee a given task connection. */
PRIVATE NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL task_connection_free)(struct task_connections *__restrict self,
                                    struct task_connection *__restrict con) {
	if (con >= self->tcs_static &&
	    con < COMPILER_ENDOF(self->tcs_static)) {
		/* Free a static connection. */
		con->tc_sig = NULL;
	} else {
		/* Free a dynamically allocated connection. */
		kfree(con);
	}
}


#ifdef CONFIG_USE_NEW_SIGNAL_API

#if SIG_CONTROL_SMPLOCK != 0
#define sig_smplock_set(con)      ((struct task_connection *)((uintptr_t)(con) | SIG_CONTROL_SMPLOCK))
#define sig_smplock_clr(con)      ((struct task_connection *)((uintptr_t)(con) & ~SIG_CONTROL_SMPLOCK))
#define sig_smplock_tst(con)      ((uintptr_t)(con) & SIG_CONTROL_SMPLOCK)
#define sig_smplock_cpy(to, from) (struct task_connection *)((uintptr_t)(to) | ((uintptr_t)(from) & SIG_CONTROL_SMPLOCK))
#define sig_smplock_tryacquire_nopr(self) \
	(!(__hybrid_atomic_fetchor((self)->s_ctl, SIG_CONTROL_SMPLOCK, __ATOMIC_ACQUIRE) & SIG_CONTROL_SMPLOCK))
#define sig_smplock_acquire_nopr(self)             \
	do {                                           \
		while (!sig_smplock_tryacquire_nopr(self)) \
			task_pause();                          \
	}	__WHILE0
#define sig_smplock_release_nopr(self) \
	__hybrid_atomic_fetchand((self)->s_ctl, ~SIG_CONTROL_SMPLOCK, __ATOMIC_RELEASE)
#else /* SIG_CONTROL_SMPLOCK != 0 */
#define sig_smplock_set(con)      con
#define sig_smplock_clr(con)      con
#define sig_smplock_tst(con)      0
#define sig_smplock_cpy(to, from) to
#endif /* SIG_CONTROL_SMPLOCK == 0 */

#ifdef TASK_CONNECTION_STAT_FLOCK
#define TASK_CONNECTION_STAT_FLOCK_OPT TASK_CONNECTION_STAT_FLOCK
#else /* TASK_CONNECTION_STAT_FLOCK */
#define TASK_CONNECTION_STAT_FLOCK_OPT 0
#endif /* !TASK_CONNECTION_STAT_FLOCK */


/* Connect the calling thread to a given signal.
 * @throw: E_BADALLOC: Insufficient memory (only when there are at least
 *                     `CONFIG_TASK_STATIC_CONNECTIONS' connections already). */
PUBLIC NONNULL((1)) void FCALL
task_connect(struct sig *__restrict target) /*THROWS(E_BADALLOC)*/ {
	struct task_connection *con, *next;
	struct task_connections *cons;
	cons = THIS_CONNECTIONS;
	assert(IS_ALIGNED((uintptr_t)cons, TASK_CONNECTION_STAT_FMASK + 1));

	/* When a signal was already delivered, `task_connect()' becomes a no-op */
	if unlikely(ATOMIC_READ(cons->tcs_dlvr) != NULL)
		return;

	/* Allocate a new connection for `cons' */
	con = task_connection_alloc(cons);
	assert(!sig_smplock_tst(con));

	/* Fill in the new connection. */
	con->tc_sig     = target;
	con->tc_connext = cons->tcs_con;
	cons->tcs_con   = con;
	con->tc_cons    = cons;

	/* Now insert the connection onto the stack used by `target'
	 * NOTE: `sig_send()' will always traverse the chain to the last
	 *       thread, meaning that we can (and have to) insert ourselves
	 *       at the front of the chain.
	 * Also note that inserting a new connection can be done without
	 * having to tinker with the signal's SMP-lock, so this part is
	 * actually surprisingly simple. */
	do {
		next = ATOMIC_READ(target->s_con);
		con->tc_signext = sig_smplock_clr(next);
		COMPILER_WRITE_BARRIER();
	} while (!ATOMIC_CMPXCH_WEAK(target->s_con, next,
	                             sig_smplock_cpy(con, next)));
}


/* Exactly the same as `task_connect()', however must be used when the connection
 * is made for a poll-based operation that only wishes to wait for some event to
 * be triggered, but does not wish to act upon this event by acquiring some kind
 * of lock with the intend to release it eventually, where the act of releasing
 * said lock includes a call to `sig_send()'.
 *
 * This connect() function is only required for signals that may be delivered via
 * `sig_send()', meaning that only a single thread would be informed of the signal
 * event having taken place. If in this scenario, the recipient thread (i.e the
 * thread that called `task_connect()') then decides not to act upon the signal
 * in question, but rather to do something else, the original intend of `sig_send()'
 * will become lost, that intend being for some (single) thread to try to acquire
 * an accompanying lock (for an example of this, see kernel header <sched/mutex.h>)
 *
 * As far as semantics go, a signal connection established with this function will
 * never satisfy a call to `sig_send()', and will instead be skipped if encountered
 * during its search for a recipient (such that by default, poll-connections will
 * only be acted upon when `sig_broadcast()' is used). However, if a call to
 * `sig_send()' is unable to find any non-poll-based connections, it will proceed
 * to act like a call to `sig_broadcast()' and wake all polling thread, though will
 * still end up returning `false', indicative of not having woken any (properly)
 * waiting thread.
 *
 * With all of this in mind, this function can also be though of as a sort-of
 * low-priority task connection, that will only be triggered after other connections
 * have already been served, and will only be woken by `sig_send()', when no other
 * connections exist.
 *
 * In practice, this function must be used whenever it is unknown what will eventually
 * happen after `task_waitfor()', or if what happens afterwards doesn't include the
 * acquisition of some kind of lock, whose release includes the sending of `target'.
 *
 * s.a. The difference between `task_disconnectall()' and `task_receiveall()' */
PUBLIC NONNULL((1)) void FCALL
task_connect_for_poll(struct sig *__restrict target) /*THROWS(E_BADALLOC)*/ {
	struct task_connection *con, *next;
	struct task_connections *cons;
	cons = THIS_CONNECTIONS;
	assert(IS_ALIGNED((uintptr_t)cons, TASK_CONNECTION_STAT_FMASK + 1));

	/* When a signal was already delivered, `task_connect()' becomes a no-op */
	if unlikely(ATOMIC_READ(cons->tcs_dlvr) != NULL)
		return;

	/* Allocate a new connection for `cons' */
	con = task_connection_alloc(cons);
	assert(!sig_smplock_tst(con));

	/* Fill in the new connection. */
	con->tc_sig     = target;
	con->tc_connext = cons->tcs_con;
	cons->tcs_con   = con;
	con->tc_cons    = (struct task_connections *)((uintptr_t)cons | TASK_CONNECTION_STAT_FPOLL);

	/* Now insert the connection onto the stack used by `target'
	 * NOTE: `sig_send()' will always traverse the chain to the last
	 *       thread, meaning that we can (and have to) insert ourselves
	 *       at the front of the chain.
	 * Also note that inserting a new connection can be done without
	 * having to tinker with the signal's SMP-lock, so this part is
	 * actually surprisingly simple. */
	do {
		next = ATOMIC_READ(target->s_con);
		con->tc_signext = sig_smplock_clr(next);
		COMPILER_WRITE_BARRIER();
	} while (!ATOMIC_CMPXCH_WEAK(target->s_con, next,
	                             sig_smplock_cpy(con, next)));
}

/* Remove `con' from the linked list of active connections of `self'. */
LOCAL NOBLOCK NOPREEMPT NONNULL((1, 2)) void
NOTHROW(FCALL task_connection_unlink_from_sig)(struct sig *__restrict self,
                                               struct task_connection *__restrict con) {
	struct task_connection *chain;
again:
	assert(!sig_smplock_tst(con->tc_signext));
	assert(!con->tc_signext || ADDR_ISKERN(con->tc_signext));
	chain = ATOMIC_READ(self->s_con);
	if (sig_smplock_clr(chain) == con) {
		/* The first entry already is the connection we're trying to unlink!
		 * In this case, we must use an atomic operation, since other thread
		 * or CPUs may have added more connections since the the read above. */
		if (!ATOMIC_CMPXCH_WEAK(self->s_con, chain,
		                        /* Keep the SMP-lock bit set! */
		                        sig_smplock_set(con->tc_signext)))
			goto again;
	} else {
		struct task_connection **pchain;
		/* Since the caller has acquired the SMP-lock of `self' for us,
		 * we are able to access all of the attached connections! */
		chain  = sig_smplock_clr(chain);
		pchain = &chain->tc_signext;
		assert(chain->tc_sig == self);
		for (;;) {
			chain = *pchain;
			assert(!sig_smplock_tst(chain));
			assert(chain && ADDR_ISKERN(chain));
			assert(chain->tc_sig == self);
			if (chain == con)
				break; /* Found the entry! */
			pchain = &chain->tc_signext;
		}
		/* Unlink the element. */
		*pchain = chain->tc_signext;
	}
	DBG_memset(&chain->tc_signext, 0xcc, sizeof(chain->tc_signext));
}


/* Same as `task_connection_unlink_from_sig()', but also release the SMP-lock. The caller
 * must then release the preemption lock through use of `sig_smp_lock_release_nosmp(self)' */
#if SIG_CONTROL_SMPLOCK == 0
#define TASK_CONNECTION_UNLINK_FROM_SIG_AND_UNLOCK_IS_TASK_CONNECTION_UNLINK_FROM_SIG 1
#define task_connection_unlink_from_sig_and_unlock(self, con) \
	task_connection_unlink_from_sig(self, con)
#else /* SIG_CONTROL_SMPLOCK == 0 */
LOCAL NOBLOCK NOPREEMPT NONNULL((1, 2)) void
NOTHROW(FCALL task_connection_unlink_from_sig_and_unlock)(struct sig *__restrict self,
                                                          struct task_connection *__restrict con) {
	struct task_connection *chain;
again:
	assert(!sig_smplock_tst(con->tc_signext));
	assert(!con->tc_signext || ADDR_ISKERN(con->tc_signext));
	chain = ATOMIC_READ(self->s_con);
	if (sig_smplock_clr(chain) == con) {
		/* The first entry already is the connection we're trying to unlink!
		 * In this case, we must use an atomic operation, since other thread
		 * or CPUs may have added more connections since the the read above. */
		if (!ATOMIC_CMPXCH_WEAK(self->s_con,
		                        chain,
		                        /* Don't keep the SMP-lock bit set! */
		                        con->tc_signext))
			goto again;
	} else {
		struct task_connection **pchain;
		/* Since the caller has acquired the SMP-lock of `self' for us,
		 * we are able to access all of the attached connections! */
		chain  = sig_smplock_clr(chain);
		pchain = &chain->tc_signext;
		assert(chain->tc_sig == self);
		for (;;) {
			chain = *pchain;
			assert(!sig_smplock_tst(chain));
			assert(chain && ADDR_ISKERN(chain));
			assert(chain->tc_sig == self);
			if (chain == con)
				break; /* Found the entry! */
			pchain = &chain->tc_signext;
		}
		/* Unlink the element. */
		*pchain = chain->tc_signext;
		COMPILER_WRITE_BARRIER();
		/* Clear the SMP-lock bit. */
		ATOMIC_AND(self->s_ctl, ~SIG_CONTROL_SMPLOCK);
	}
	DBG_memset(&chain->tc_signext, 0xcc, sizeof(chain->tc_signext));
}
#endif /* SIG_CONTROL_SMPLOCK != 0 */

PRIVATE NOBLOCK WUNUSED NONNULL((2)) bool
NOTHROW(FCALL is_connection_is_chain)(struct task_connection *chain,
                                      struct task_connection *__restrict con) {
	for (; chain; chain = chain->tc_signext) {
		if (chain == con)
			return true;
	}
	return false;
}

LOCAL NOBLOCK void
NOTHROW(FCALL destroy_tasks)(struct task *destroy_later) {
	while (destroy_later) {
		struct task *next;
		next = sig_destroylater_next(destroy_later);
		destroy(destroy_later);
		destroy_later = next;
	}
}

/* Trigger phase #2 for pending signal-completion functions.
 * NOTE: During this, the completion callback will clear the
 *       SMP lock bit of its own completion controller. */
LOCAL NOBLOCK NONNULL((2, 3, 4)) void
NOTHROW(FCALL sig_completion_chain_phase_2)(struct sig_completion *sc_pending,
                                            struct sig *sender,
                                            struct task *__restrict sender_thread,
                                            struct task **__restrict pdestroy_later) {
	while (sc_pending) {
		/* NOTE: Our use of `tc_connext' here is save:
		 *
		 * Even if the completion function used `sig_completion_reprime()'
		 * during the SETUP-phase, and the second we've released our
		 * SMP-lock from the signal (ATOMIC_CMPXCH_WEAK(self->s_ctl, ctl, 0)),
		 * another CPU has began broadcasting our signal, it would still
		 * not be able to clobber the `tc_connext' field until the completion
		 * function has released the connection's SMP-lock, too. And since
		 * we don't use `tc_connext' of some connection C after having
		 * invoked C's callback, there is no race condition. */
		struct sig_completion *next;
		next = (struct sig_completion *)sc_pending->tc_connext;
		DBG_memset(&sc_pending->tc_connext, 0xcc,
		           sizeof(sc_pending->tc_connext));
		(*sc_pending->sc_cb)(sc_pending, sender_thread,
		                     SIG_COMPLETION_PHASE_PAYLOAD,
		                     pdestroy_later, sender);
		sc_pending = next;
	}
}



PRIVATE NOBLOCK NOPREEMPT ATTR_NOINLINE NONNULL((1, 2, 3, 5)) size_t
NOTHROW(FCALL sig_broadcast_as_destroylater_with_initial_completion_nopr)(struct sig *self,
                                                                          struct task *__restrict sender_thread,
                                                                          struct sig *sender,
                                                                          struct sig_completion *sc_pending,
                                                                          struct task **__restrict pdestroy_later,
                                                                          uintptr_t phase_one_state) {
	uintptr_t ctl;
	struct task_connections *target_cons;
	struct task_connection *receiver;
	struct task_connection *con;
	size_t result = 0;
	/* Signal completion callback. */
	if (sc_pending) {
		ATOMIC_WRITE(sc_pending->tc_stat, phase_one_state);
		assert(sc_pending->tc_sig == self);
		(*sc_pending->sc_cb)(sc_pending, sender_thread,
		                     SIG_COMPLETION_PHASE_SETUP,
		                     pdestroy_later, sender);
		sc_pending->tc_connext = NULL;
		++result;
	}
again:
	ctl = ATOMIC_READ(self->s_ctl);
	con = sig_smplock_clr(ctl);
	if unlikely(!con) {
no_cons:
		/* No one else here! (and nothing for us to do...)
		 * This is an undefined situation, since the original call to
		 * `sig_send()' that caused the signal which we ended up ignoring
		 * to be delivered returned `true', even though now, in the end,
		 * no one actually ended up getting the signal... */
#if SIG_CONTROL_SMPLOCK != 0
		if (!ATOMIC_CMPXCH_WEAK(self->s_ctl, ctl, 0))
			goto again;
#endif /* SIG_CONTROL_SMPLOCK != 0 */
		/* Trigger phase #2 for pending signal-completion functions.
		 * NOTE: During this, the completion callback will clear the
		 *       SMP lock bit of its own completion controller. */
		sig_completion_chain_phase_2(sc_pending, sender,
		                             sender_thread,
		                             pdestroy_later);
		return result;
	}
	if (!is_connection_is_chain(sc_pending, con)) {
		/* Use the first connection */
		receiver = con;
#ifndef CONFIG_NO_SMP
		assert(!sig_smplock_tst(receiver->tc_signext));
#endif /* !CONFIG_NO_SMP */
		/* Unlink `receiver' from the pending chain. */
		if (!ATOMIC_CMPXCH_WEAK(self->s_ctl, ctl, (uintptr_t)receiver->tc_signext))
			goto again;
	} else {
		/* Find another receiver. */
		struct task_connection **preceiver;
		preceiver = &con->tc_signext;
		for (;;) {
			receiver = *preceiver;
			if (!receiver)
				goto no_cons;
			if (!is_connection_is_chain(sc_pending, receiver))
				break;
			preceiver = &receiver->tc_signext;
		}
		/* Unlink the receiver. */
		*preceiver = receiver->tc_signext;
	}
#ifndef CONFIG_NO_SMP
again_read_target_cons:
	target_cons = ATOMIC_READ(receiver->tc_cons);
	/* NOTE: Waiting until we can lock the connection here is allowed, since
	 *       you're allowed to (and required to) acquire connection locks
	 *       without having to release the associated signal-lock.
	 * Doing this doesn't result in a race condition, since the other end
	 * of this syncing mechanism (which is `task_disconnect()') will release
	 * its initial connection-lock if it fails to acquire the signal lock,
	 * which it will because we're already holding that one! */
	while (unlikely((uintptr_t)target_cons & TASK_CONNECTION_STAT_FLOCK)) {
		task_pause();
		target_cons = ATOMIC_READ(receiver->tc_cons);
	}
	/* Mark the receiver for broadcast, and acquire a lock to it. */
	if (!ATOMIC_CMPXCH_WEAK(receiver->tc_cons, target_cons,
	                        (struct task_connections *)(TASK_CONNECTION_STAT_BROADCAST |
	                                                    TASK_CONNECTION_STAT_FLOCK_OPT)))
		goto again_read_target_cons;
#else /* !CONFIG_NO_SMP */
	target_cons = ATOMIC_XCH(receiver->tc_cons,
	                         (struct task_connections *)TASK_CONNECTION_STAT_BROADCAST);
#endif /* CONFIG_NO_SMP */
	if (TASK_CONNECTION_STAT_ISSPEC(target_cons)) {
		struct sig_completion *sc;
		if (TASK_CONNECTION_STAT_ISDONE(target_cons))
			goto again;
		sc = (struct sig_completion *)receiver;
		ATOMIC_WRITE(sc->tc_stat, phase_one_state);
		/* Signal completion callback. */
		(*sc->sc_cb)(sc, sender_thread,
		             SIG_COMPLETION_PHASE_SETUP,
		             pdestroy_later, sender);
		/* Enqueue `sc' for phase #2. */
		sc->tc_connext = sc_pending;
		sc_pending     = sc;
	} else {
		target_cons = TASK_CONNECTION_STAT_ASCONS(target_cons);
		/* Try to set our signal as the one delivered to `target_cons'.
		 * If that part fails, change signal state to BROADCAST (even though
		 * that's not entirely correct), so we can get rid of the connection. */
		if (!ATOMIC_CMPXCH(target_cons->tcs_dlvr, NULL, sender)) {
			/* Unlink the signal, and mark it as broadcast. */
			ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_BROADCAST);
		} else {
			REF struct task *thread;
			/* Unlock the signal, and wake-up the thread attached to the connection */
			thread = xincref(ATOMIC_READ(target_cons->tcs_thread));
			ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_BROADCAST);
			if likely(thread) {
				task_wake_as(thread, sender_thread);
				assert(thread->t_refcnt >= 1);
				if unlikely(ATOMIC_FETCHDEC(thread->t_refcnt) == 1) {
					sig_destroylater_next(thread) = *pdestroy_later;
					*pdestroy_later               = thread;
				}
			}
		}
	}
	goto again;
}

/* NOTE: This function will restore preemption behave, as specified by `was' */
PRIVATE NOBLOCK NOPREEMPT ATTR_NOINLINE NONNULL((1, 2, 3)) size_t
NOTHROW(FCALL sig_broadcast_as_with_initial_completion_nopr)(struct sig *self,
                                                             struct task *__restrict sender_thread,
                                                             struct sig *sender,
                                                             pflag_t was,
                                                             struct sig_completion *sc_pending,
                                                             uintptr_t phase_one_state) {
	struct task *destroy_later = NULL;
	size_t result;
	result = sig_broadcast_as_destroylater_with_initial_completion_nopr(self,
	                                                                    sender_thread,
	                                                                    sender,
	                                                                    sc_pending,
	                                                                    &destroy_later,
	                                                                    phase_one_state);
	PREEMPTION_POP(was);
	destroy_tasks(destroy_later);
	return result;
}

PRIVATE NOBLOCK NOPREEMPT ATTR_NOINLINE NONNULL((1, 2, 3, 5)) size_t
NOTHROW(FCALL sig_broadcast_as_with_initial_destroylater_nopr)(struct sig *self,
                                                               struct task *__restrict sender_thread,
                                                               struct sig *sender,
                                                               pflag_t was,
                                                               struct task *destroy_later,
                                                               uintptr_t phase_one_state) {
	size_t result;
	sig_destroylater_next(destroy_later) = NULL;
	result = sig_broadcast_as_destroylater_with_initial_completion_nopr(self,
	                                                                    sender_thread,
	                                                                    sender,
	                                                                    NULL,
	                                                                    &destroy_later,
	                                                                    phase_one_state);
	PREEMPTION_POP(was);
	destroy_tasks(destroy_later);
	return result;
}

PRIVATE NOBLOCK NOPREEMPT ATTR_NOINLINE NONNULL((1, 2, 3, 5)) bool
NOTHROW(FCALL sig_send_as_destroylater_with_initial_completion_nopr)(struct sig *self,
                                                                     struct task *__restrict sender_thread,
                                                                     struct sig *sender,
                                                                     struct sig_completion *sc_pending,
                                                                     struct task **__restrict pdestroy_later) {
	uintptr_t ctl;
	struct task_connections *target_cons;
	struct task_connection *receiver;
	struct task_connection *con;
	/* Signal completion callback. */
	if (sc_pending) {
		(*sc_pending->sc_cb)(sc_pending, sender_thread,
		                     SIG_COMPLETION_PHASE_SETUP,
		                     pdestroy_later, sender);
		sc_pending->tc_connext = NULL;
	}
again:
	ctl = ATOMIC_READ(self->s_ctl);
	con = sig_smplock_clr(ctl);
	if unlikely(!con) {
		/* No one else here! (and nothing for us to do...)
		 * This is an undefined situation, since the original call to
		 * `sig_send()' that caused the signal which we ended up ignoring
		 * to be delivered returned `true', even though now, in the end,
		 * no one actually ended up getting the signal... */
#if SIG_CONTROL_SMPLOCK != 0
		if (!ATOMIC_CMPXCH_WEAK(self->s_ctl, ctl, 0))
			goto again;
#endif /* SIG_CONTROL_SMPLOCK != 0 */
		/* Trigger phase #2 for pending signal-completion functions.
		 * NOTE: During this, the completion callback will clear the
		 *       SMP lock bit of its own completion controller. */
		sig_completion_chain_phase_2(sc_pending, sender,
		                             sender_thread, pdestroy_later);
		return false;
	}
	/* Find a suitable candidate:
	 *    During send:
	 *       #1: Use the last-in-chain, non-poll connection
	 *       #2: Broadcast all poll connections (but stop if
	 *           a non-poll connection shows up before we're
	 *           down)
	 *       #3: If no non-poll connection could be found,
	 *           return `false' */
	receiver = con;
	if (!receiver->tc_signext) {
		/* Special case: Only one connection to choose from... */
	} else {
		struct task_connection *iter;
		iter = receiver;
		if (TASK_CONNECTION_STAT_ISPOLL(receiver->tc_stat))
			receiver = NULL;
		/* Find the last non-poll connection. */
		do {
			if (!TASK_CONNECTION_STAT_ISPOLL(iter->tc_stat))
				receiver = iter;
		} while ((iter = iter->tc_signext) != NULL);
		if (!receiver) {
			/* No non-poll connections found.
			 * Just use the last connection in-chain. */
			receiver = sig_smplock_clr(con);
			while (receiver->tc_signext)
				receiver = receiver->tc_signext;
		}
	}
again_read_target_cons:
	target_cons = ATOMIC_READ(receiver->tc_cons);
#ifndef CONFIG_NO_SMP
	/* NOTE: Waiting until we can lock the connection here is allowed, since
	 *       you're allowed to (and required to) acquire connection locks
	 *       without having to release the associated signal-lock.
	 * Doing this doesn't result in a race condition, since the other end
	 * of this syncing mechanism (which is `task_disconnect()') will release
	 * its initial connection-lock if it fails to acquire the signal lock,
	 * which it will because we're already holding that one! */
	while (unlikely((uintptr_t)target_cons & TASK_CONNECTION_STAT_FLOCK)) {
		task_pause();
		target_cons = ATOMIC_READ(receiver->tc_cons);
	}
#endif /* !CONFIG_NO_SMP */
	if (TASK_CONNECTION_STAT_ISSPEC(target_cons)) {
		struct sig_completion *sc;
		if unlikely(TASK_CONNECTION_STAT_ISDEAD(target_cons)) {
			/* The target is already dead. (change it to broadcast) */
			if (!ATOMIC_CMPXCH_WEAK(receiver->tc_cons, target_cons,
			                        (struct task_connections *)(TASK_CONNECTION_STAT_BROADCAST |
			                                                    TASK_CONNECTION_STAT_FLOCK_OPT)))
				goto again_read_target_cons;
			task_connection_unlink_from_sig(self, receiver);
#if TASK_CONNECTION_STAT_FLOCK_OPT != 0
			ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_BROADCAST);
#endif /* TASK_CONNECTION_STAT_FLOCK_OPT != 0 */
			goto again;
		}
		/* Signal completion callback. */
		if (!ATOMIC_CMPXCH_WEAK(receiver->tc_cons, target_cons,
		                        (struct task_connections *)(TASK_CONNECTION_STAT_BROADCAST |
		                                                    TASK_CONNECTION_STAT_FLOCK_OPT)))
			goto again_read_target_cons;
		task_connection_unlink_from_sig(self, receiver);
		sc = (struct sig_completion *)receiver;
		/* Trigger phase #1 */
		(*sc->sc_cb)(sc, sender_thread,
		             SIG_COMPLETION_PHASE_SETUP,
		             pdestroy_later, sender);
		if (TASK_CONNECTION_STAT_ISPOLL(target_cons)) {
			/* Enqueue the completion function to have its phase#2 executed later. */
			sc->tc_signext = sc_pending;
			sc_pending     = sc;
			/* Search for more connections (preferably one that isn't poll-based) */
			goto again;
		}
		/* Unlock the signal. */
		sig_smplock_release_nopr(self);
		/* Invoke phase #2. (this one also unlocks `receiver') */
		(*sc->sc_cb)(sc, sender_thread,
		             SIG_COMPLETION_PHASE_PAYLOAD,
		             pdestroy_later, sender);
		goto success;
	}
	/* Check if the selected receiver is poll-based */
	if (TASK_CONNECTION_STAT_ISPOLL(target_cons)) {
		REF struct task *thread;
		/* Special case: poll-based connections don't (really) count.
		 * Instead, those get marked for broadcast. */
		if (!ATOMIC_CMPXCH_WEAK(receiver->tc_cons, target_cons,
		                        (struct task_connections *)(TASK_CONNECTION_STAT_BROADCAST |
		                                                    TASK_CONNECTION_STAT_FLOCK_OPT)))
			goto again_read_target_cons;
		task_connection_unlink_from_sig(self, receiver);
		target_cons = TASK_CONNECTION_STAT_ASCONS(target_cons);
		thread = NULL;
		/* Set the delivered signal, and capture
		 * the thread thread, if there is one */
		if (ATOMIC_CMPXCH(target_cons->tcs_dlvr, NULL, sender))
			thread = xincref(ATOMIC_READ(target_cons->tcs_thread));
		/* Unlock the connection. */
		ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_BROADCAST);
		if (thread) {
			task_wake_as(thread, sender_thread);
			/* Only destroy dead threads _after_ we've released the SMP-lock to `self' */
			assert(thread->t_refcnt >= 1);
			if unlikely(ATOMIC_FETCHDEC(thread->t_refcnt) == 1) {
				sig_destroylater_next(thread) = *pdestroy_later;
				*pdestroy_later = thread;
			}
		}
		goto again;
	}
	/* Mark the receiver as sent, and acquire a lock to it. */
	if (!ATOMIC_CMPXCH_WEAK(receiver->tc_cons, target_cons,
	                        (struct task_connections *)(TASK_CONNECTION_STAT_SENT |
	                                                    TASK_CONNECTION_STAT_FLOCK_OPT)))
		goto again_read_target_cons;
	/* Set the signal sender as being delivered for the target connection set. */
	if (!ATOMIC_CMPXCH(target_cons->tcs_dlvr, NULL, sender)) {
		/* Unlink the signal, and mark it as broadcast. */
		task_connection_unlink_from_sig(self, receiver);
		ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_BROADCAST);
		goto again;
	}
	/* The simple case: We managed to deliver the signal, and now we must wake-up
	 * the connected thread (if any) */
	{
		REF struct task *thread;
		thread = xincref(ATOMIC_READ(target_cons->tcs_thread));
#ifndef CONFIG_NO_SMP
		ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_SENT);
#endif /* !CONFIG_NO_SMP */
		sig_smplock_release_nopr(self);
		/* Wake-up the thread. */
		if likely(thread) {
			task_wake_as(thread, sender_thread);
			/* Only destroy dead threads _after_ we've released the SMP-lock to `self' */
			assert(thread->t_refcnt >= 1);
			if unlikely(ATOMIC_FETCHDEC(thread->t_refcnt) == 1) {
				sig_destroylater_next(thread) = *pdestroy_later;
				*pdestroy_later = thread;
			}
		}
	}
success:
	/* Trigger phase #2 for all of the pending completion function. */
	sig_completion_chain_phase_2(sc_pending, sender,
	                             sender_thread,
	                             pdestroy_later);
	return true;
}

PRIVATE NOBLOCK NOPREEMPT ATTR_NOINLINE NONNULL((1, 2, 3)) bool
NOTHROW(FCALL sig_send_as_with_initial_completion_nopr)(struct sig *self,
                                                        struct task *__restrict sender_thread,
                                                        struct sig *sender,
                                                        struct sig_completion *sc_pending,
                                                        pflag_t was) {
	bool result;
	struct task *destroy_later = NULL;
	result = sig_send_as_destroylater_with_initial_completion_nopr(self,
	                                                               sender_thread,
	                                                               sender,
	                                                               sc_pending,
	                                                               &destroy_later);
	PREEMPTION_POP(was);
	destroy_tasks(destroy_later);
	return result;
}

PRIVATE NOBLOCK NOPREEMPT ATTR_NOINLINE NONNULL((1, 2, 3, 5)) bool
NOTHROW(FCALL sig_send_as_with_initial_destroylater_nopr)(struct sig *self,
                                                          struct task *__restrict sender_thread,
                                                          struct sig *sender,
                                                          pflag_t was,
                                                          struct task *destroy_later) {
	bool result;
	sig_destroylater_next(destroy_later) = NULL;
	result = sig_send_as_destroylater_with_initial_completion_nopr(self,
	                                                               sender_thread,
	                                                               sender,
	                                                               NULL,
	                                                               &destroy_later);
	PREEMPTION_POP(was);
	destroy_tasks(destroy_later);
	return result;
}




/* Try to send the signal to a single, other thread, for the purpose
 * of forwarding. Additionally, release the SMP-lock of `self' */
PRIVATE NOBLOCK NOPREEMPT ATTR_NOINLINE NONNULL((1, 2)) bool
NOTHROW(FCALL sig_sendone_for_forwarding_and_unlock)(struct sig *self,
                                                     struct sig *sender,
                                                     pflag_t was) {
	bool result = false;
	bool is_broadcasting_poll = false;
	uintptr_t ctl;
	struct sig_completion *sc_pending = NULL;
	struct task_connections *target_cons;
	struct task_connection *receiver;
	struct task_connection *con;
	REF struct task *destroy_later = NULL;
again:
	ctl = ATOMIC_READ(self->s_ctl);
	con = sig_smplock_clr(ctl);
	if unlikely(!con) {
no_cons:
		/* No one else here! (and nothing for us to do...)
		 * This is an undefined situation, since the original call to
		 * `sig_send()' that caused the signal which we ended up ignoring
		 * to be delivered returned `true', even though now, in the end,
		 * no one actually ended up getting the signal... */
#if SIG_CONTROL_SMPLOCK != 0
		if (!ATOMIC_CMPXCH_WEAK(self->s_ctl, ctl, 0))
			goto again;
#endif /* SIG_CONTROL_SMPLOCK != 0 */
		result = false;
		PREEMPTION_POP(was);
		goto done;
	}
	/* Non-broadcast signals are sent to the oldest connection of `self'.
	 * As such, walk the chain of known connections until we find the last
	 * one of them all.
	 * NOTE: Since we're holding the SMP-lock at the moment, we are safe to
	 *       do this. */
	receiver = NULL;
	/* Find the first connection that is able to accept the signal. */
	for (;;) {
		uintptr_t status;
		status = ATOMIC_READ(con->tc_stat);
		assert(status != TASK_CONNECTION_STAT_BROADCAST);
		if (!TASK_CONNECTION_STAT_ISDONE(status)) {
			if (is_broadcasting_poll || !TASK_CONNECTION_STAT_ISPOLL(status)) {
				/* Make sure that `con' isn't a phase-2-pending completion callback.
				 * If it is, then the callback of `con' used `sig_completion_reprime()'
				 * during phase-1 in order to re-queue itself. */
				if (!is_connection_is_chain(sc_pending, con))
					receiver = con; /* This connection is still in alive. */
			}
		}
		con = con->tc_signext;
		if (!con)
			break;
	}
	if unlikely(!receiver) {
		if (is_broadcasting_poll)
			goto no_cons;
		is_broadcasting_poll = true;
		goto again;
	}
	/* Try to switch the connection from `!TASK_CONNECTION_STAT_ISDONE'
	 * to `TASK_CONNECTION_STAT_SENT'. */
	target_cons = ATOMIC_READ(receiver->tc_cons);
#ifndef CONFIG_NO_SMP
	/* NOTE: Waiting until we can lock the connection here is allowed, since
	 *       you're allowed to (and required to) acquire connection locks
	 *       without having to release the associated signal-lock.
	 * Doing this doesn't result in a race condition, since the other end
	 * of this syncing mechanism (which is `task_disconnect()') will release
	 * its initial connection-lock if it fails to acquire the signal lock,
	 * which it will because we're already holding that one! */
	while (unlikely((uintptr_t)target_cons & TASK_CONNECTION_STAT_FLOCK)) {
		task_pause();
		target_cons = ATOMIC_READ(receiver->tc_cons);
	}
#endif /* !CONFIG_NO_SMP */
	if (TASK_CONNECTION_STAT_ISSPEC(target_cons)) {
		struct sig_completion *sc;
		if unlikely(TASK_CONNECTION_STAT_ISDONE(target_cons))
			goto again;
		sc = (struct sig_completion *)receiver;
		if (!ATOMIC_CMPXCH_WEAK(sc->tc_cons, target_cons,
		                        (struct task_connections *)(TASK_CONNECTION_STAT_BROADCAST |
		                                                    TASK_CONNECTION_STAT_FLOCK_OPT)))
			goto again;
		/* Unlink `sc' from the signal. */
		task_connection_unlink_from_sig(self, receiver);
		/* Signal completion callback. */
		(*sc->sc_cb)(sc, THIS_TASK,
		             SIG_COMPLETION_PHASE_SETUP,
		             &destroy_later, sender);
		/* Enqueue `sc' for phase #2. */
		sc->tc_connext = sc_pending;
		sc_pending     = sc;
		if unlikely(TASK_CONNECTION_STAT_ISPOLL(target_cons))
			goto again; /* Deal with poll-based connections. */
	} else {
		struct task *thread;
		if (!ATOMIC_CMPXCH_WEAK(receiver->tc_cons, target_cons,
		                        (struct task_connections *)(TASK_CONNECTION_STAT_SENT |
		                                                    TASK_CONNECTION_STAT_FLOCK_OPT)))
			goto again;
		if unlikely(TASK_CONNECTION_STAT_ISPOLL(target_cons)) {
			/* Deal with poll-based connections. */
			bool did_deliver;
			target_cons = TASK_CONNECTION_STAT_ASCONS(target_cons);
			did_deliver = ATOMIC_CMPXCH(target_cons->tcs_dlvr, NULL, sender);
			task_connection_unlink_from_sig(self, receiver);
			if (did_deliver) {
				thread = ATOMIC_READ(target_cons->tcs_thread);
				if likely(thread)
					task_wake(thread);
			}
			ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_BROADCAST);
			goto again;
		}
		/* Try to set our signal as the one delivered to `target_cons'.
		 * If that part fails, change signal state to BROADCAST (even though
		 * that's not entirely correct), so we can get rid of the connection. */
		if (!ATOMIC_CMPXCH(target_cons->tcs_dlvr, NULL, sender)) {
			/* Unlink the signal, and mark it as broadcast. */
			task_connection_unlink_from_sig(self, receiver);
			ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_BROADCAST);
			goto again;
		}
		/* Unlock the signal, and wake-up the thread attached to the connection */
		thread = xincref(ATOMIC_READ(target_cons->tcs_thread));
		ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_SENT);
		sig_smplock_release_nopr(self);
		PREEMPTION_POP(was);
		if likely(thread) {
			task_wake(thread);
			assert(thread->t_refcnt >= 1);
			if unlikely(ATOMIC_FETCHDEC(thread->t_refcnt) == 1) {
				sig_destroylater_next(thread) = destroy_later;
				destroy_later                 = thread;
			}
		}
	}
	result = true;
done:
	/* Trigger phase #2 for pending signal-completion functions.
	 * NOTE: During this, the completion callback will clear the
	 *       SMP lock bit of its own completion controller. */
	sig_completion_chain_phase_2(sc_pending, sender,
	                             THIS_TASK, &destroy_later);
	PREEMPTION_POP(was);
	/* Destroy pending threads. */
	while (destroy_later) {
		struct task *next;
		next = sig_destroylater_next(destroy_later);
		destroy(destroy_later);
		destroy_later = next;
	}
	return result;
}

/* Re-prime the completion callback to be invoked once again the next time that the
 * attached signal is delivered. In this case, the completion function is responsible
 * to ensure that no-one is currently trying to destroy the associated signal. */
PUBLIC NOBLOCK NOPREEMPT NONNULL((1)) bool
NOTHROW(KCALL sig_completion_reprime)(struct sig_completion *__restrict self,
                                      bool for_poll) {
	struct task_connection *next;
	struct sig *signal = self->tc_sig;
	/* At this point, we're allowed to assume all of the following: */
	assert(!PREEMPTION_ENABLED());
#ifndef CONFIG_NO_SMP
	assert(signal->s_ctl & SIG_CONTROL_SMPLOCK);
	assert(self->tc_stat & TASK_CONNECTION_STAT_FLOCK);
#endif /* !CONFIG_NO_SMP */
	/* If the signal was sent for the purpose of finalization, then don't
	 * allow completion callback re-priming, since we're supposed to take
	 * care of all connections going away. */
	if unlikely(self->tc_stat & TASK_CONNECTION_STAT_FFINI)
		return false;

	/* Re-write the status of `self' to match the request. */
	ATOMIC_WRITE(self->tc_stat,
	             for_poll ? TASK_CONNECTION_STAT_FLOCK_OPT | TASK_CONNECTION_STAT_COMPLETION_FOR_POLL
	                      : TASK_CONNECTION_STAT_FLOCK_OPT | TASK_CONNECTION_STAT_COMPLETION);
	/* Now we must insert `self' into the chain of `signal' */
	do {
		next = ATOMIC_READ(signal->s_con);
#ifndef CONFIG_NO_SMP
		assert(sig_smplock_tst(next));
#endif /* !CONFIG_NO_SMP */
		self->tc_signext = sig_smplock_clr(next);
		COMPILER_WRITE_BARRIER();
	} while (!ATOMIC_CMPXCH_WEAK(signal->s_con, next,
	                             sig_smplock_set(self)));
	return true;
}

/* Connect the given signal completion controller to the specified signal.
 * The caller must ensure that `completion' hasn't been connected, yet. */
PUBLIC NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL sig_connect_completion)(struct sig *__restrict self,
                                      struct sig_completion *__restrict completion) {
	struct task_connection *next;
	/* Re-write the status of `self' to match the request. */
	completion->tc_stat = TASK_CONNECTION_STAT_COMPLETION;
	completion->tc_sig  = self;
	DBG_memset(&completion->tc_connext, 0xcc,
	           sizeof(completion->tc_connext));
	/* Now we must insert `completion' into the chain of `self' */
	do {
		next = ATOMIC_READ(self->s_con);
		completion->tc_signext = sig_smplock_clr(next);
		COMPILER_WRITE_BARRIER();
	} while (!ATOMIC_CMPXCH_WEAK(self->s_con, next,
	                             sig_smplock_cpy(completion, next)));
}

PUBLIC NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL sig_connect_completion_for_poll)(struct sig *__restrict self,
                                               struct sig_completion *__restrict completion) {
	struct task_connection *next;
	/* Re-write the status of `self' to match the request. */
	completion->tc_stat = TASK_CONNECTION_STAT_COMPLETION_FOR_POLL;
	completion->tc_sig  = self;
	DBG_memset(&completion->tc_connext, 0xcc,
	           sizeof(completion->tc_connext));
	/* Now we must insert `completion' into the chain of `self' */
	do {
		next = ATOMIC_READ(self->s_con);
		completion->tc_signext = sig_smplock_clr(next);
		COMPILER_WRITE_BARRIER();
	} while (!ATOMIC_CMPXCH_WEAK(self->s_con, next,
	                             sig_smplock_cpy(completion, next)));
}




LOCAL NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL task_disconnect_connection)(struct task_connection *__restrict self,
                                          struct task_connections *__restrict cons,
                                          bool forward_sent_signals) {
	struct sig *signal;
	struct task_connection *signal_cons;
	pflag_t was;
	uintptr_t status;
	signal = self->tc_sig;
	/* Acquire a lock to the connection. */
#ifdef CONFIG_NO_SMP
	was    = PREEMPTION_PUSHOFF();
	status = ATOMIC_READ(self->tc_stat);
	if (TASK_CONNECTION_STAT_ISDEAD(status)) {
		PREEMPTION_POP(was);
		goto done; /* Dead connection */
	}
	signal_cons = ATOMIC_READ(signal->s_con);
#else /* CONFIG_NO_SMP */
again:
	status = ATOMIC_READ(self->tc_stat);
	if (TASK_CONNECTION_STAT_ISDEAD(status))
		goto done; /* Dead connection */
	if unlikely(status & TASK_CONNECTION_STAT_FLOCK) {
		task_pause();
		goto again;
	}
	was = PREEMPTION_PUSHOFF();
	if (!ATOMIC_CMPXCH_WEAK(self->tc_stat, status,
	                        status | TASK_CONNECTION_STAT_FLOCK)) {
		PREEMPTION_POP(was);
		goto again;
	}
	/* Now upgrade the lock to also include the associated signal. */
again_signal_cons:
	signal_cons = ATOMIC_READ(signal->s_con);
	if unlikely(sig_smplock_tst(signal_cons)) {
		ATOMIC_AND(self->tc_stat, ~TASK_CONNECTION_STAT_FLOCK);
		PREEMPTION_POP(was);
		task_pause();
		goto again;
	}
	if (!ATOMIC_CMPXCH_WEAK(signal->s_con, signal_cons,
	                        sig_smplock_set(signal_cons)))
		goto again_signal_cons;
#endif /* !CONFIG_NO_SMP */
	/* At this point, we're holding all of the necessary locks, both
	 * to `self' and `signal'. With that in mind, remove `self' from
	 * the connection queue of `signal' */
	if likely(status != TASK_CONNECTION_STAT_SENT || !forward_sent_signals) {
		/* Unlink our connection, and unlock the signal. */
		task_connection_unlink_from_sig_and_unlock(signal, self);
		PREEMPTION_POP(was);
	} else {
		/* Unlink our connection. */
		task_connection_unlink_from_sig(signal, self);
		/* Forward the signal. */
		if (!sig_sendone_for_forwarding_and_unlock(signal,
		                                           ATOMIC_READ(cons->tcs_dlvr),
		                                           was)) {
			/* At least log the fact that there has been a minor inconsistency... */
			printk(KERN_WARNING "[sig] Signal %p cannot be forwarded (no recipients)\n",
			       self);
		}
	}
done:
	DBG_memset(&self->tc_sig, 0xcc, sizeof(self->tc_sig));
}

/* NOTE: When this function returns, the caller can be certain that the callback
 *       of `self' is/won't be executed anymore, unless `self' is once again connected
 *       to some signal through use of `sig_connect_completion[_for_poll]()'
 * @return: true:  Completion function was disconnected before it could be triggered,
 *                 or the last time the completion function was triggered, it made use
 *                 of `sig_completion_reprime()' to re-prime itself.
 * @return: false: Completion function was already triggered, but not re-primed.
 *                 Alternatively, the signal completion function had already been
 *                 disconnected, or had never been connected to begin with. */
PUBLIC NOBLOCK NONNULL((1)) bool
NOTHROW(FCALL sig_completion_disconnect)(struct sig_completion *__restrict self) {
	struct sig *signal;
	struct task_connection *signal_cons;
	pflag_t was;
	uintptr_t status;
	signal = self->tc_sig;
	/* Acquire a lock to the connection. */
#ifdef CONFIG_NO_SMP
	was    = PREEMPTION_PUSHOFF();
	status = ATOMIC_READ(self->tc_stat);
	if (TASK_CONNECTION_STAT_ISDEAD(status)) {
		PREEMPTION_POP(was);
		return false; /* Dead connection */
	}
	signal_cons = ATOMIC_READ(signal->s_con);
#else /* CONFIG_NO_SMP */
again:
	status = ATOMIC_READ(self->tc_stat);
	if (TASK_CONNECTION_STAT_ISDEAD(status))
		return false; /* Dead connection */
	if unlikely(status & TASK_CONNECTION_STAT_FLOCK) {
		task_pause();
		goto again;
	}
	was = PREEMPTION_PUSHOFF();
	if (!ATOMIC_CMPXCH_WEAK(self->tc_stat, status,
	                        status | TASK_CONNECTION_STAT_FLOCK)) {
		PREEMPTION_POP(was);
		goto again;
	}
	/* Now upgrade the lock to also include the associated signal. */
again_signal_cons:
	signal_cons = ATOMIC_READ(signal->s_con);
	if unlikely(sig_smplock_tst(signal_cons)) {
		ATOMIC_AND(self->tc_stat, ~TASK_CONNECTION_STAT_FLOCK);
		PREEMPTION_POP(was);
		task_pause();
		goto again;
	}
	if (!ATOMIC_CMPXCH_WEAK(signal->s_con, signal_cons,
	                        sig_smplock_set(signal_cons)))
		goto again_signal_cons;
#endif /* !CONFIG_NO_SMP */
	/* At this point, we're holding all of the necessary locks, both
	 * to `self' and `signal'. With that in mind, remove `self' from
	 * the connection queue of `signal' */
	task_connection_unlink_from_sig_and_unlock(signal, self);
	PREEMPTION_POP(was);
	DBG_memset(&self->tc_sig, 0xcc, sizeof(self->tc_sig));
	DBG_memset(&self->tc_connext, 0xcc, sizeof(self->tc_connext));
	DBG_memset(&self->tc_signext, 0xcc, sizeof(self->tc_signext));
	COMPILER_WRITE_BARRIER();
	self->tc_stat = TASK_CONNECTION_STAT_BROADCAST;
	return true;
}



LOCAL NOBLOCK NONNULL((1)) void
NOTHROW(FCALL task_connection_disconnect_all)(struct task_connections *__restrict self,
                                              bool forward_sent_signals) {
	struct task_connection *con;
	while ((con = self->tcs_con) != NULL) {
		/* Disconnect */
		task_disconnect_connection(con, self, forward_sent_signals);
		/* Unlink */
		self->tcs_con = con->tc_connext;
		/* Free */
		task_connection_free(self, con);
	}
}

/* Disconnect from all connected signal.
 * Signals with a state of `TASK_CONNECTION_STAT_SENT' will be forwarded. */
PUBLIC NOBLOCK void
NOTHROW(FCALL task_disconnectall)(void) {
	struct task_connections *self;
	self = THIS_CONNECTIONS;
	task_connection_disconnect_all(self, true);
	COMPILER_BARRIER();
	self->tcs_dlvr = NULL;
}

/* Same as `task_disconnectall()', but don't forward signals with a
 * `TASK_CONNECTION_STAT_SENT'-state, but rather return the sender
 * of of the signal that was received.
 * As such, the caller must properly pass on information about the
 * fact that a signal may have been received, as well as act upon
 * this fact. */
PUBLIC NOBLOCK WUNUSED struct sig *
NOTHROW(FCALL task_receiveall)(void) {
	struct task_connections *self;
	struct sig *result;
	self = THIS_CONNECTIONS;
	task_connection_disconnect_all(self, false);
	COMPILER_BARRIER();
	result = self->tcs_dlvr;
	self->tcs_dlvr = NULL;
	return result;
}

/* Check if the calling thread is connected to any signal. */
PUBLIC NOBLOCK ATTR_PURE WUNUSED bool
NOTHROW(FCALL task_isconnected)(void) {
	struct task_connections *self;
	self = THIS_CONNECTIONS;
	/* Check if there are any active connections. */
	return self->tcs_con != NULL;
}

/* Check if the calling thread is connected to the given signal. */
PUBLIC NOBLOCK ATTR_PURE WUNUSED bool
NOTHROW(FCALL task_isconnected_to)(struct sig const *__restrict target) {
	struct task_connections *self;
	struct task_connection *con;
	self = THIS_CONNECTIONS;
	/* Find the connection for `target' */
	for (con = self->tcs_con; con; con = con->tc_connext) {
		if (con->tc_sig == target)
			return true; /* Found it! */
	}
	return false;
}

/* Check if there is a signal to was delivered, disconnecting
 * all other connected signals if this was the case.
 * @return: NULL: No signal is available
 * @return: * :   The signal that was delivered. */
PUBLIC NOBLOCK struct sig *NOTHROW(FCALL task_trywait)(void) {
	struct task_connections *self;
	struct sig *result;
	self   = THIS_CONNECTIONS;
	result = ATOMIC_READ(self->tcs_dlvr);
	if (result) {
		task_connection_disconnect_all(self, false);
		COMPILER_BARRIER();
		self->tcs_dlvr = NULL;
	}
	return result;
}



/* Check if the given signal has viable recipients.
 * This includes poll-based connections. */
PUBLIC NOBLOCK NONNULL((1)) bool
NOTHROW(FCALL sig_iswaiting)(struct sig *__restrict self) {
	bool result = false;
	struct task_connection *cons;
	/* Quick check: Are there any established connections? */
	cons = sig_smplock_clr(ATOMIC_READ(self->s_con));
	if (cons) {
		/* Acquire the SMP-lock for `self', so we can inspect
		 * the chain of established connections more closely. */
		pflag_t was = PREEMPTION_PUSHOFF();
		sig_smplock_acquire_nopr(self);
		for (cons = sig_smplock_clr(ATOMIC_READ(self->s_con));
		     cons; cons = cons->tc_signext) {
			uintptr_t status = ATOMIC_READ(cons->tc_stat);
			if (!TASK_CONNECTION_STAT_ISDONE(status)) {
				/* Found an alive, normal connection! */
				result = true;
				break;
			}
		}
		sig_smplock_release_nopr(self);
		PREEMPTION_POP(was);
	}
	return result;
}

/* Count the # of viable recipients of the given signal.
 * This includes poll-based connections. */
PUBLIC NOBLOCK NONNULL((1)) size_t
NOTHROW(FCALL sig_numwaiting)(struct sig *__restrict self) {
	size_t result = 0;
	struct task_connection *cons;
	/* Quick check: Are there any established connections? */
	cons = sig_smplock_clr(ATOMIC_READ(self->s_con));
	if (cons) {
		/* Acquire the SMP-lock for `self', so we can inspect
		 * the chain of established connections more closely. */
		pflag_t was = PREEMPTION_PUSHOFF();
		sig_smplock_acquire_nopr(self);
		for (cons = sig_smplock_clr(ATOMIC_READ(self->s_con));
		     cons; cons = cons->tc_signext) {
			uintptr_t status;
			status = ATOMIC_READ(cons->tc_stat);
			if (!TASK_CONNECTION_STAT_ISDONE(status))
				++result; /* Found an alive, normal connection! */
		}
		sig_smplock_release_nopr(self);
		PREEMPTION_POP(was);
	}
	return result;
}


#else /* CONFIG_USE_NEW_SIGNAL_API */

#ifdef CONFIG_NO_SMP
#define SIG_CONTROL_SMPLOCK       0x0000
#define SIG_SMPLOCK_TST(ptr)      0
#define SIG_SMPLOCK_CLR(ptr)      ptr
#define SIG_SMPLOCK_SET(ptr)      ptr
#define SIG_SMPLOCK_CPY(to, from) to
#else /* CONFIG_NO_SMP */
#define SIG_CONTROL_SMPLOCK       0x0001
#define SIG_SMPLOCK_TST(ptr)      ((uintptr_t)(ptr) & SIG_CONTROL_SMPLOCK)
#define SIG_SMPLOCK_CLR(ptr)      (struct task_connection *)((uintptr_t)(ptr) & ~SIG_CONTROL_SMPLOCK)
#define SIG_SMPLOCK_SET(ptr)      (struct task_connection *)((uintptr_t)(ptr) | SIG_CONTROL_SMPLOCK)
#define SIG_SMPLOCK_CPY(to, from) (struct task_connection *)((uintptr_t)(to) | ((uintptr_t)(from) & SIG_CONTROL_SMPLOCK))
#endif /* !CONFIG_NO_SMP */


/* Acquire/release the SMP lock for a given signal,
 * alongside disabling preemption for the duration
 * of holding the lock. */
#if SIG_CONTROL_SMPLOCK != 0
LOCAL NOBLOCK NONNULL((1)) void
NOTHROW(FCALL _sig_smp_lock_acquire)(struct sig *__restrict self) {
	while ((ATOMIC_FETCHOR(self->s_ctl, SIG_CONTROL_SMPLOCK) & SIG_CONTROL_SMPLOCK) != 0)
		task_pause();
}
#define _sig_smp_lock_release(self) \
	ATOMIC_AND((self)->s_ctl, ~SIG_CONTROL_SMPLOCK)
#else /* SIG_CONTROL_SMPLOCK != 0 */
#define _sig_smp_lock_acquire(self) (void)0
#define _sig_smp_lock_release(self) (void)0
#endif /* SIG_CONTROL_SMPLOCK == 0 */

#define sig_smp_lock_acquire_nosmp(self) \
	do {                                 \
		pflag_t _ssl_was = PREEMPTION_PUSHOFF()
#define sig_smp_lock_acquire(self)        \
		sig_smp_lock_acquire_nosmp(self); \
		_sig_smp_lock_acquire(self)
#define sig_smp_lock_release(self)   \
		_sig_smp_lock_release(self); \
		sig_smp_lock_release_nosmp(self)
#define sig_smp_lock_break_nosmp(self) \
		PREEMPTION_POP(_ssl_was)
#define sig_smp_lock_break(self)      \
		(_sig_smp_lock_release(self), \
		 sig_smp_lock_break_nosmp(self))
#define sig_smp_lock_release_nosmp(self) \
		sig_smp_lock_break_nosmp(self);  \
	}	__WHILE0





/* Connect the calling thread to a given signal.
 * @throw: E_BADALLOC: Insufficient memory (only when there are at least
 *                     `CONFIG_TASK_STATIC_CONNECTIONS' connections already). */
PUBLIC NONNULL((1)) void FCALL
task_connect(struct sig *__restrict target) /*THROWS(E_BADALLOC)*/ {
	struct task_connection *con, *next;
	struct task_connections *cons;
	cons = THIS_CONNECTIONS;

	/* When a signal was already delivered, `task_connect()' becomes a no-op */
	if unlikely(ATOMIC_READ(cons->tcs_dlvr) != NULL)
		return;

	/* Allocate a new connection for `cons' */
	con = task_connection_alloc(cons);
	assert(!SIG_SMPLOCK_TST(con));

	/* Fill in the new connection. */
	con->tc_sig     = target;
	con->tc_connext = cons->tcs_con;
	cons->tcs_con   = con;
	con->tc_cons    = cons;

	/* Now insert the connection onto the stack used by `target'
	 * NOTE: `sig_send()' will always traverse the chain to the last
	 *       thread, meaning that we can (and have to) insert ourselves
	 *       at the front of the chain.
	 * Also note that inserting a new connection can be done without
	 * having to tinker with the signal's SMP-lock, so this part is
	 * actually surprisingly simple. */
	do {
		next = ATOMIC_READ(target->s_con);
		con->tc_signext = SIG_SMPLOCK_CLR(next);
		COMPILER_WRITE_BARRIER();
	} while (!ATOMIC_CMPXCH_WEAK(target->s_con, next,
	                             SIG_SMPLOCK_CPY(con, next)));
}


/* Exactly the same as `task_connect()', however must be used when the connection
 * is made for a poll-based operation that only wishes to wait for some event to
 * be triggered, but does not wish to act upon this event by acquiring some kind
 * of lock with the intend to release it eventually, where the act of releasing
 * said lock includes a call to `sig_send()'.
 *
 * This connect() function is only required for signals that may be delivered via
 * `sig_send()', meaning that only a single thread would be informed of the signal
 * event having taken place. If in this scenario, the recipient thread (i.e the
 * thread that called `task_connect()') then decides not to act upon the signal
 * in question, but rather to do something else, the original intend of `sig_send()'
 * will become lost, that intend being for some (single) thread to try to acquire
 * an accompanying lock (for an example of this, see kernel header <sched/mutex.h>)
 *
 * As far as semantics go, a signal connection established with this function will
 * never satisfy a call to `sig_send()', and will instead be skipped if encountered
 * during its search for a recipient (such that by default, poll-connections will
 * only be acted upon when `sig_broadcast()' is used). However, if a call to
 * `sig_send()' is unable to find any non-poll-based connections, it will proceed
 * to act like a call to `sig_broadcast()' and wake all polling thread, though will
 * still end up returning `false', indicative of not having woken any (properly)
 * waiting thread.
 *
 * With all of this in mind, this function can also be though of as a sort-of
 * low-priority task connection, that will only be triggered after other connections
 * have already been served, and will only be woken by `sig_send()', when no other
 * connections exist.
 *
 * In practice, this function must be used whenever it is unknown what will eventually
 * happen after `task_waitfor()', or if what happens afterwards doesn't include the
 * acquisition of some kind of lock, whose release includes the sending of `target'.
 *
 * s.a. The difference between `task_disconnectall()' and `task_receiveall()' */
PUBLIC NONNULL((1)) void FCALL
task_connect_for_poll(struct sig *__restrict target) /*THROWS(E_BADALLOC)*/ {
	struct task_connection *con, *next;
	struct task_connections *cons;
	cons = THIS_CONNECTIONS;

	/* When a signal was already delivered, `task_connect()' becomes a no-op */
	if unlikely(ATOMIC_READ(cons->tcs_dlvr) != NULL)
		return;

	/* Allocate a new connection for `cons' */
	con = task_connection_alloc(cons);
	assert(!SIG_SMPLOCK_TST(con));

	/* Fill in the new connection. */
	con->tc_sig     = target;
	con->tc_connext = cons->tcs_con;
	cons->tcs_con   = con;
	con->tc_cons    = (struct task_connections *)((uintptr_t)cons | 1);

	/* Now insert the connection onto the stack used by `target'
	 * NOTE: `sig_send()' will always traverse the chain to the last
	 *       thread, meaning that we can (and have to) insert ourselves
	 *       at the front of the chain.
	 * Also note that inserting a new connection can be done without
	 * having to tinker with the signal's SMP-lock, so this part is
	 * actually surprisingly simple. */
	do {
		next = ATOMIC_READ(target->s_con);
		con->tc_signext = SIG_SMPLOCK_CLR(next);
		COMPILER_WRITE_BARRIER();
	} while (!ATOMIC_CMPXCH_WEAK(target->s_con, next,
	                             SIG_SMPLOCK_CPY(con, next)));
}





/* Remove `con' from the linked list of active connections of `self'. */
LOCAL NOBLOCK NOPREEMPT NONNULL((1, 2)) void
NOTHROW(FCALL task_connection_unlink_from_sig)(struct sig *__restrict self,
                                               struct task_connection *__restrict con) {
	struct task_connection *chain;
again:
	assert(!SIG_SMPLOCK_TST(con->tc_signext));
	assert(!con->tc_signext || ADDR_ISKERN(con->tc_signext));
	chain = ATOMIC_READ(self->s_con);
	if (SIG_SMPLOCK_CLR(chain) == con) {
		/* The first entry already is the connection we're trying to unlink!
		 * In this case, we must use an atomic operation, since other thread
		 * or CPUs may have added more connections since the the read above. */
		if (!ATOMIC_CMPXCH_WEAK(self->s_con,
		                        chain,
		                        /* Keep the SMP-lock bit set! */
		                        SIG_SMPLOCK_SET(con->tc_signext)))
			goto again;
	} else {
		struct task_connection **pchain;
		/* Since the caller has acquired the SMP-lock of `self' for us,
		 * we are able to access all of the attached connections! */
		chain  = SIG_SMPLOCK_CLR(chain);
		pchain = &chain->tc_signext;
		assert(chain->tc_sig == self);
		for (;;) {
			chain = *pchain;
			assert(!SIG_SMPLOCK_TST(chain));
			assert(chain && ADDR_ISKERN(chain));
			assert(chain->tc_sig == self);
			if (chain == con)
				break; /* Found the entry! */
			pchain = &chain->tc_signext;
		}
		/* Unlink the element. */
		*pchain = chain->tc_signext;
	}
}


/* Same as `task_connection_unlink_from_sig()', but also release the SMP-lock. The caller
 * must then release the preemption lock through use of `sig_smp_lock_release_nosmp(self)' */
#if SIG_CONTROL_SMPLOCK == 0
#define TASK_CONNECTION_UNLINK_FROM_SIG_AND_UNLOCK_IS_TASK_CONNECTION_UNLINK_FROM_SIG 1
#define task_connection_unlink_from_sig_and_unlock(self, con) \
	task_connection_unlink_from_sig(self, con)
#else /* SIG_CONTROL_SMPLOCK == 0 */
LOCAL NOBLOCK NOPREEMPT NONNULL((1, 2)) void
NOTHROW(FCALL task_connection_unlink_from_sig_and_unlock)(struct sig *__restrict self,
                                                          struct task_connection *__restrict con) {
	struct task_connection *chain;
again:
	assert(!SIG_SMPLOCK_TST(con->tc_signext));
	assert(!con->tc_signext || ADDR_ISKERN(con->tc_signext));
	chain = ATOMIC_READ(self->s_con);
	if (SIG_SMPLOCK_CLR(chain) == con) {
		/* The first entry already is the connection we're trying to unlink!
		 * In this case, we must use an atomic operation, since other thread
		 * or CPUs may have added more connections since the the read above. */
		if (!ATOMIC_CMPXCH_WEAK(self->s_con,
		                        chain,
		                        /* Don't keep the SMP-lock bit set! */
		                        con->tc_signext))
			goto again;
	} else {
		struct task_connection **pchain;
		/* Since the caller has acquired the SMP-lock of `self' for us,
		 * we are able to access all of the attached connections! */
		chain  = SIG_SMPLOCK_CLR(chain);
		pchain = &chain->tc_signext;
		assert(chain->tc_sig == self);
		for (;;) {
			chain = *pchain;
			assert(!SIG_SMPLOCK_TST(chain));
			assert(chain && ADDR_ISKERN(chain));
			assert(chain->tc_sig == self);
			if (chain == con)
				break; /* Found the entry! */
			pchain = &chain->tc_signext;
		}
		/* Unlink the element. */
		*pchain = chain->tc_signext;
		COMPILER_WRITE_BARRIER();
		/* Clear the SMP-lock bit. */
		ATOMIC_AND(self->s_ctl, ~SIG_CONTROL_SMPLOCK);
	}
}
#endif /* SIG_CONTROL_SMPLOCK != 0 */


/* Try to send the signal to a single, other thread, for the purpose
 * of forwarding. Additionally, release the SMP-lock of `self' */
PRIVATE NOBLOCK NOPREEMPT ATTR_NOINLINE NONNULL((1, 2)) bool
NOTHROW(FCALL sig_sendone_for_forwarding_and_unlock)(struct sig *self,
                                                     struct sig *sender) {
	bool is_broadcasting_poll = false;
	uintptr_t ctl;
	struct task_connections *target_cons;
	struct task_connection *receiver;
	struct task_connection *con;
#if SIG_CONTROL_SMPLOCK != 0
	REF struct task *target_thread;
#else /* SIG_CONTROL_SMPLOCK != 0 */
	struct task *target_thread;
#endif /* SIG_CONTROL_SMPLOCK == 0 */
again:
	ctl = ATOMIC_READ(self->s_ctl);
	con = SIG_SMPLOCK_CLR(ctl);
	if unlikely(!con) {
no_cons:
		/* No one else here! (and nothing for us to do...)
		 * This is an undefined situation, since the original call to
		 * `sig_send()' that caused the signal which we ended up ignoring
		 * to be delivered returned `true', even though now, in the end,
		 * no one actually ended up getting the signal... */
#if SIG_CONTROL_SMPLOCK != 0
		if (!ATOMIC_CMPXCH_WEAK(self->s_ctl, ctl, 0))
			goto again;
#endif /* SIG_CONTROL_SMPLOCK != 0 */
		return false;
	}
	/* Non-broadcast signals are sent to the oldest connection of `self'.
	 * As such, walk the chain of known connections until we find the last
	 * one of them all.
	 * NOTE: Since we're holding the SMP-lock at the moment, we are safe to
	 *       do this. */
	receiver = NULL;
	/* Find the first connection that is able to accept the signal. */
	for (;;) {
		uintptr_t status;
		status = ATOMIC_READ(con->tc_stat);
		assert(status != TASK_CONNECTION_STAT_BROADCAST);
		if (!TASK_CONNECTION_STAT_CHECK(status)) {
			if (is_broadcasting_poll || TASK_CONNECTION_STAT_ISNORM(status))
				receiver = con; /* This connection is still in alive. */
		}
		assert(status == TASK_CONNECTION_STAT_SENT);
		con = con->tc_signext;
		if (!con)
			break;
	}
	if unlikely(!receiver) {
		if (is_broadcasting_poll)
			goto no_cons;
		is_broadcasting_poll = true;
		goto again;
	}
	/* Try to switch the connection from `!TASK_CONNECTION_STAT_CHECK'
	 * to `TASK_CONNECTION_STAT_SENT'. */
	target_cons = ATOMIC_READ(receiver->tc_cons);
	if unlikely(TASK_CONNECTION_STAT_CHECK(target_cons))
		goto again;
	if (!ATOMIC_CMPXCH_WEAK(receiver->tc_cons, target_cons,
	                        (struct task_connections *)TASK_CONNECTION_STAT_SENT))
		goto again;
	if unlikely(TASK_CONNECTION_STAT_ISPOLL(target_cons)) {
		/* Deal with poll-based connections. */
		bool did_deliver;
		target_cons = TASK_CONNECTION_STAT_GETCONS(target_cons);
		did_deliver = ATOMIC_CMPXCH(target_cons->tcs_dlvr, NULL, sender);
		task_connection_unlink_from_sig(self, receiver);
		ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_BROADCAST);
		if (did_deliver) {
			target_thread = ATOMIC_READ(target_cons->tcs_thread);
			if likely(target_thread)
				task_wake(target_thread);
		}
		goto again;
	}
	/* Try to set our signal as the one delivered to `target_cons'.
	 * If that part fails, change signal state to BROADCAST (even though
	 * that's not entirely correct), so we can get rid of the connection. */
	if (!ATOMIC_CMPXCH(target_cons->tcs_dlvr, NULL, sender)) {
		/* Unlink the signal, and mark it as broadcast. */
		task_connection_unlink_from_sig(self, receiver);
		ATOMIC_WRITE(receiver->tc_stat, TASK_CONNECTION_STAT_BROADCAST);
		goto again;
	}
	/* Unlock the signal, and wake-up the thread attached to the connection */
	target_thread = ATOMIC_READ(target_cons->tcs_thread);
#if SIG_CONTROL_SMPLOCK != 0
	xincref(target_thread);
	ATOMIC_AND(self->s_ctl, ~SIG_CONTROL_SMPLOCK);
#endif /* SIG_CONTROL_SMPLOCK != 0 */
	if likely(target_thread) {
		task_wake(target_thread);
#if SIG_CONTROL_SMPLOCK != 0
		decref(target_thread);
#endif /* SIG_CONTROL_SMPLOCK != 0 */
	}
	return true;
}


LOCAL NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL task_disconnect_connection)(struct task_connection *__restrict self,
                                          struct task_connections *__restrict cons,
                                          bool forward_sent_signals) {
	uintptr_t old_state;
	struct sig *target;
	target = self->tc_sig;
again:
	old_state = ATOMIC_READ(self->tc_stat);
	if unlikely(old_state == TASK_CONNECTION_STAT_BROADCAST)
		return; /* After a broadcast, the signal will have already disconnected itself. */
	/* FIXME: Race condition: `target' may get destroyed before we acquire a lock to it below! */
	/* Acquire the SMP-lock for the signal. */
	sig_smp_lock_acquire(target);
	/* Make sure that our state hasn't changed. */
	if unlikely(ATOMIC_READ(self->tc_stat) != old_state) {
		sig_smp_lock_break(target);
		task_pause();
		goto again;
	}
#ifdef TASK_CONNECTION_UNLINK_FROM_SIG_AND_UNLOCK_IS_TASK_CONNECTION_UNLINK_FROM_SIG
	task_connection_unlink_from_sig(target, self);
#endif /* TASK_CONNECTION_UNLINK_FROM_SIG_AND_UNLOCK_IS_TASK_CONNECTION_UNLINK_FROM_SIG */
	if likely(old_state != TASK_CONNECTION_STAT_SENT || !forward_sent_signals) {
		/* Unlink our connection, and unlock the signal. */
#ifndef TASK_CONNECTION_UNLINK_FROM_SIG_AND_UNLOCK_IS_TASK_CONNECTION_UNLINK_FROM_SIG
		task_connection_unlink_from_sig_and_unlock(target, self);
#endif /* !TASK_CONNECTION_UNLINK_FROM_SIG_AND_UNLOCK_IS_TASK_CONNECTION_UNLINK_FROM_SIG */
	} else {
		/* Unlink our connection. */
#ifndef TASK_CONNECTION_UNLINK_FROM_SIG_AND_UNLOCK_IS_TASK_CONNECTION_UNLINK_FROM_SIG
		task_connection_unlink_from_sig(target, self);
#endif /* !TASK_CONNECTION_UNLINK_FROM_SIG_AND_UNLOCK_IS_TASK_CONNECTION_UNLINK_FROM_SIG */
		/* Forward the signal. */
		if (!sig_sendone_for_forwarding_and_unlock(target, ATOMIC_READ(cons->tcs_dlvr))) {
			/* At least log the fact that there has been a minor inconsistency... */
			printk(KERN_WARNING "[sig] Signal %p cannot be forwarded (no recipients)\n",
			       self);
		}
	}
	/* Release the SMP-lock from the signal. */
	sig_smp_lock_release_nosmp(target);
}


/* Disconnect from a specific signal `target'
 * @return: true:  Disconnected from `target'
 * @return: false: You weren't actually connected to `target' */
PUBLIC NOBLOCK NONNULL((1)) bool
NOTHROW(FCALL task_disconnect)(struct sig *__restrict target) {
	struct task_connections *self;
	struct task_connection *con, **pcon;
	self = THIS_CONNECTIONS;
	/* Find the connection for `target' */
	pcon = &self->tcs_con;
	for (;;) {
		con = *pcon;
		if unlikely(!con)
			return false;
		if (con->tc_sig == target)
			break; /* Found it! */
		pcon = &con->tc_connext;
	}
	/* Delete this connection, and also forward an already-sent signal,
	 * even though in the event of the signal needing to be forwarded,
	 * the calling thread will have already received said signal, there
	 * is a good chance that once the caller notices that they've received
	 * a signal from which they've previously disconnected, they will
	 * choose to ignore that signal, though at that point we'll already
	 * no longer be able to forward it.
	 * So better be safe than sorry, and immediately forward it! */
	task_disconnect_connection(con, self, true);

	/* Unlink the connection from the thread-local active chain. */
	*pcon = con->tc_connext;

	/* Free the connection descriptor. */
	task_connection_free(self, con);
	return true;
}

LOCAL NOBLOCK NONNULL((1)) void
NOTHROW(FCALL task_connection_disconnect_all)(struct task_connections *__restrict self,
                                              bool forward_sent_signals) {
	struct task_connection *con;
	while ((con = self->tcs_con) != NULL) {
		/* Disconnect */
		task_disconnect_connection(con, self, forward_sent_signals);
		/* Unlink */
		self->tcs_con = con->tc_connext;
		/* Free */
		task_connection_free(self, con);
	}
}

/* Disconnect from all connected signal.
 * Signals with a state of `TASK_CONNECTION_STAT_SENT' will be forwarded. */
PUBLIC NOBLOCK void
NOTHROW(FCALL task_disconnectall)(void) {
	struct task_connections *self;
	self = THIS_CONNECTIONS;
	task_connection_disconnect_all(self, true);
	COMPILER_BARRIER();
	self->tcs_dlvr = NULL;
}

/* Same as `task_disconnectall()', but don't forward signals with a
 * `TASK_CONNECTION_STAT_SENT'-state, but rather return the sender
 * of of the signal that was received.
 * As such, the caller must properly pass on information about the
 * fact that a signal may have been received, as well as act upon
 * this fact. */
PUBLIC NOBLOCK WUNUSED struct sig *
NOTHROW(FCALL task_receiveall)(void) {
	struct task_connections *self;
	struct sig *result;
	self = THIS_CONNECTIONS;
	task_connection_disconnect_all(self, false);
	COMPILER_BARRIER();
	result = self->tcs_dlvr;
	self->tcs_dlvr = NULL;
	return result;
}

/* Check if the calling thread is connected to any signal. */
PUBLIC NOBLOCK ATTR_PURE WUNUSED bool
NOTHROW(FCALL task_isconnected)(void) {
	struct task_connections *self;
	self = THIS_CONNECTIONS;
	/* Check if there are any active connections. */
	return self->tcs_con != NULL;
}

/* Check if the calling thread is connected to the given signal. */
PUBLIC NOBLOCK ATTR_PURE WUNUSED bool
NOTHROW(FCALL task_isconnected_to)(struct sig const *__restrict target) {
	struct task_connections *self;
	struct task_connection *con;
	self = THIS_CONNECTIONS;
	/* Find the connection for `target' */
	for (con = self->tcs_con; con; con = con->tc_connext) {
		if (con->tc_sig == target)
			return true; /* Found it! */
	}
	return false;
}

/* Check if there is a signal to was delivered, disconnecting
 * all other connected signals if this was the case.
 * @return: NULL: No signal is available
 * @return: * :   The signal that was delivered. */
PUBLIC NOBLOCK struct sig *NOTHROW(FCALL task_trywait)(void) {
	struct task_connections *self;
	struct sig *result;
	self   = THIS_CONNECTIONS;
	result = ATOMIC_READ(self->tcs_dlvr);
	if (result) {
		task_connection_disconnect_all(self, false);
		COMPILER_BARRIER();
		self->tcs_dlvr = NULL;
	}
	return result;
}



/* Check if the given signal has viable recipients.
 * This includes poll-based connections. */
PUBLIC NOBLOCK NONNULL((1)) bool
NOTHROW(FCALL sig_iswaiting)(struct sig *__restrict self) {
	bool result = false;
	struct task_connection *cons;
	/* Quick check: Are there any established connections? */
	cons = SIG_SMPLOCK_CLR(ATOMIC_READ(self->s_con));
	if (cons) {
		/* Acquire the SMP-lock for `self', so we can inspect
		 * the chain of established connections more closely. */
		sig_smp_lock_acquire(self);
		for (cons = SIG_SMPLOCK_CLR(ATOMIC_READ(self->s_con));
		     cons; cons = cons->tc_signext) {
			uintptr_t status;
			status = ATOMIC_READ(cons->tc_stat);
			if (!TASK_CONNECTION_STAT_CHECK(status)) {
				/* Found an alive, normal connection! */
				result = true;
				break;
			}
		}
		sig_smp_lock_release(self);
	}
	return result;
}

/* Count the # of viable recipients of the given signal.
 * This includes poll-based connections. */
PUBLIC NOBLOCK NONNULL((1)) size_t
NOTHROW(FCALL sig_numwaiting)(struct sig *__restrict self) {
	size_t result = 0;
	struct task_connection *cons;
	/* Quick check: Are there any established connections? */
	cons = SIG_SMPLOCK_CLR(ATOMIC_READ(self->s_con));
	if (cons) {
		/* Acquire the SMP-lock for `self', so we can inspect
		 * the chain of established connections more closely. */
		sig_smp_lock_acquire(self);
		for (cons = SIG_SMPLOCK_CLR(ATOMIC_READ(self->s_con));
		     cons; cons = cons->tc_signext) {
			uintptr_t status;
			status = ATOMIC_READ(cons->tc_stat);
			if (!TASK_CONNECTION_STAT_CHECK(status))
				++result; /* Found an alive, normal connection! */
		}
		sig_smp_lock_release(self);
	}
	return result;
}
#endif /* !CONFIG_USE_NEW_SIGNAL_API */


/* Same as `sig_send()', but repeat the operation up to `maxcount' times,
 * and return the # of times that `sig_send()' would have returned `true'
 * Equivalent to:
 * >> size_t result = 0;
 * >> while (maxcount) {
 * >>     if (!sig_send(self))
 * >>         break;
 * >>     --maxcount;
 * >>     ++result;
 * >> }
 * >> return result; */
PUBLIC NOBLOCK NONNULL((1)) size_t
NOTHROW(FCALL sig_sendmany)(struct sig *__restrict self,
                            size_t maxcount) {
	size_t result = 0;
	while (maxcount) {
		if (!sig_send(self))
			break;
		--maxcount;
		++result;
	}
	return result;
}

PUBLIC NOBLOCK NONNULL((1, 2)) size_t
NOTHROW(FCALL sig_altsendmany)(struct sig *self,
                               struct sig *sender,
                               size_t maxcount) {
	size_t result = 0;
	while (maxcount) {
		if (!sig_altsend(self, sender))
			break;
		--maxcount;
		++result;
	}
	return result;
}

PUBLIC NOBLOCK NOPREEMPT NONNULL((1)) size_t
NOTHROW(FCALL sig_sendmany_nopr)(struct sig *__restrict self,
                                 size_t maxcount) {
	size_t result = 0;
	while (maxcount) {
		if (!sig_send_nopr(self))
			break;
		--maxcount;
		++result;
	}
	return result;
}

PUBLIC NOBLOCK NOPREEMPT NONNULL((1, 2)) size_t
NOTHROW(FCALL sig_altsendmany_nopr)(struct sig *self,
                                    struct sig *sender,
                                    size_t maxcount) {
	size_t result = 0;
	while (maxcount) {
		if (!sig_altsend_nopr(self, sender))
			break;
		--maxcount;
		++result;
	}
	return result;
}



#ifdef DEFINE_TEST
DEFINE_TEST(recursive_signals) {
	struct task_connections cons;
	struct sig s = SIG_INIT;
	task_disconnectall();
	task_connect(&s);
	task_pushconnections(&cons);
	task_connect(&s);

	assert(task_isconnected());
	assert(task_isconnected(&s));
	assert(task_trywait() == NULL);

	sig_broadcast(&s);

	/* Simulate what kfree() for the signal would do, thus
	 * ensuring that the the signal can still be received,
	 * even after it was destroyed. */
	memset(&s, 0xcc, sizeof(s));

	assert(task_isconnected());
	assert(task_isconnected(&s));

	assert(task_trywait() == &s);
	assert(task_trywait() == NULL);

	assert(task_popconnections() == &cons);

	assert(task_trywait() == &s);
	assert(task_trywait() == NULL);
}
#endif /* DEFINE_TEST */


DECL_END

#ifndef __INTELLISENSE__
#define DEFINE_sig_send 1
#include "signal-send.c.inl"

#define DEFINE_sig_send_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_altsend 1
#include "signal-send.c.inl"

#define DEFINE_sig_altsend_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_broadcast 1
#include "signal-send.c.inl"

#define DEFINE_sig_broadcast_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_altbroadcast 1
#include "signal-send.c.inl"

#define DEFINE_sig_altbroadcast_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_broadcast_as_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_broadcast_destroylater_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_broadcast_as_destroylater_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_broadcast_for_fini 1
#include "signal-send.c.inl"

#define DEFINE_sig_broadcast_for_fini_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_altbroadcast_for_fini 1
#include "signal-send.c.inl"

#define DEFINE_sig_altbroadcast_for_fini_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_broadcast_for_fini_as_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_broadcast_for_fini_destroylater_nopr 1
#include "signal-send.c.inl"

#define DEFINE_sig_broadcast_for_fini_as_destroylater_nopr 1
#include "signal-send.c.inl"

#define DEFINE_task_waitfor 1
#include "signal-waitfor.c.inl"

#define DEFINE_task_waitfor_norpc 1
#include "signal-waitfor.c.inl"

#define DEFINE_task_waitfor_nx 1
#include "signal-waitfor.c.inl"

#define DEFINE_task_waitfor_norpc_nx 1
#include "signal-waitfor.c.inl"
#endif /* !__INTELLISENSE__ */

#endif /* !GUARD_KERNEL_INCLUDE_SCHED_SIGNAL_C */
