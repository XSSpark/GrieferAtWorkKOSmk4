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
#ifndef GUARD_KERNEL_INCLUDE_SCHED_SIGNAL_H
#define GUARD_KERNEL_INCLUDE_SCHED_SIGNAL_H 1

#include <kernel/compiler.h>

#include <kernel/types.h>
#include <sched/arch/task.h> /* pflag_t */
#include <sched/pertask.h>

#include <hybrid/__atomic.h>

DECL_BEGIN

/* Declare support for signal-driven poll operations
 * >> bool pollread(MyType *self) {
 * >>     if (sync_canread(self))
 * >>         return true;
 * >>     task_connect_for_poll(&self->m_signal);
 * >>     return unlikely(sync_canread(self)); // Re-check to prevent race condition
 * >> }
 */
#if defined(__cplusplus) && defined(__CC__)
#define __DEFINE_SYNC_POLL(T, _pollread, _pollwrite)                                                                                                  \
	extern "C++" {                                                                                                                                    \
	FORCELOCAL ATTR_ARTIFICIAL WUNUSED NONNULL((1)) __BOOL (KCALL sync_pollread)(T *__restrict self) THROWS(E_BADALLOC) { return _pollread(self); }   \
	FORCELOCAL ATTR_ARTIFICIAL WUNUSED NONNULL((1)) __BOOL (KCALL sync_pollwrite)(T *__restrict self) THROWS(E_BADALLOC) { return _pollwrite(self); } \
	}
#else /* __cplusplus && __CC__ */
#define __DEFINE_SYNC_POLL(T, _pollread, _pollwrite) /* nothing */
#endif /* !__cplusplus || !__CC__ */

#undef CONFIG_USE_NEW_SIGNAL_API
#if 1
#define CONFIG_USE_NEW_SIGNAL_API 1
#endif


#ifdef __CC__

struct sig;
struct task;
struct task_connection;
struct task_connections;

struct sig {
#ifdef CONFIG_NO_SMP
	struct task_connection *s_con; /* [0..1][chain(->tc_signext)]
	                                * [lock(INSERT(ATOMIC))]
	                                * [lock(REMOVE(!PREEMPTION_ENABLED() && IF_SMP(SMP_LOCK(tc_sig))))]
	                                * Chain of established connections.
	                                * In SMP, the least significant bit is a lock that needs to be
	                                * held when connections are removed. Note however that this lock
	                                * may only be acquired when preemption is disabled, as it must
	                                * be guarantied that the lock always becomes available while doing
	                                * a `while (!trylock()) task_pause()'-loop. */
#else /* CONFIG_NO_SMP */
	union {
		struct task_connection *s_con; /* [0..1][chain(->tc_signext)]
		                                * [lock(INSERT(ATOMIC))]
		                                * [lock(REMOVE(!PREEMPTION_ENABLED() && IF_SMP(SMP_LOCK(tc_sig))))]
		                                * Chain of established connections.
		                                * In SMP, the least significant bit is a lock that needs to be
		                                * held when connections are removed. Note however that this lock
		                                * may only be acquired when preemption is disabled, as it must
		                                * be guarantied that the lock always becomes available while doing
		                                * a `while (!trylock()) task_pause()'-loop. */
		uintptr_t               s_ctl; /* Signal control word */
	};
#endif /* !CONFIG_NO_SMP */
};

#ifdef CONFIG_USE_NEW_SIGNAL_API
#ifndef CONFIG_NO_SMP
#define SIG_CONTROL_SMPLOCK 0x0001 /* SMP lock bit for `struct sig::s_ctl' */
#endif /* !CONFIG_NO_SMP */
#endif /* CONFIG_USE_NEW_SIGNAL_API */

#ifdef CONFIG_NO_SMP
#define SIG_INIT     { __NULLPTR }
#else /* CONFIG_NO_SMP */
#define SIG_INIT     { { __NULLPTR } }
#endif /* !CONFIG_NO_SMP */
#define sig_init(x)  (void)((x)->s_con = __NULLPTR)
#define sig_cinit(x) (void)(__hybrid_assert((x)->s_con == __NULLPTR))



/* Send signal `self' to exactly 1 connected thread
 *  - The receiver is the thread who's connection has been pending the longest.
 *  - Note the special interaction of this function with poll-based connections.
 *    For more information on this subject, see `task_connect_for_poll()'.
 * @return: true:  A waiting thread was signaled.
 * @return: false: The given signal didn't have any active connections. */
FUNDEF NOBLOCK NONNULL((1)) __BOOL
NOTHROW(FCALL sig_send)(struct sig *__restrict self);
FUNDEF NOBLOCK NONNULL((1, 2)) __BOOL
NOTHROW(FCALL sig_altsend)(struct sig *self,
                           struct sig *sender);

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
FUNDEF NOBLOCK NONNULL((1)) size_t
NOTHROW(FCALL sig_sendmany)(struct sig *__restrict self,
                            size_t maxcount);
FUNDEF NOBLOCK NONNULL((1, 2)) size_t
NOTHROW(FCALL sig_altsendmany)(struct sig *self,
                               struct sig *sender,
                               size_t maxcount);

/* Send signal to all connected threads.
 * @return: * : The actual number of threads notified,
 *              not counting poll-based connections. */
FUNDEF NOBLOCK NONNULL((1)) size_t
NOTHROW(FCALL sig_broadcast)(struct sig *__restrict self);
FUNDEF NOBLOCK NONNULL((1, 2)) size_t
NOTHROW(FCALL sig_altbroadcast)(struct sig *self,
                                struct sig *sender);

/* Check if the given signal has viable recipients.
 * This includes poll-based connections. */
FUNDEF NOBLOCK NONNULL((1)) __BOOL
NOTHROW(FCALL sig_iswaiting)(struct sig *__restrict self);

/* Count the # of viable recipients of the given signal.
 * This includes poll-based connections. */
FUNDEF NOBLOCK NONNULL((1)) size_t
NOTHROW(FCALL sig_numwaiting)(struct sig *__restrict self);

/* Same as `sig_broadcast()', but impersonate `sender_thread', and
 * wake up thread through use of `task_wake_as()'. The same rules
 * apply, meaning that the (true) caller must ensure that their
 * CPU won't change, and that `sender_thread' is also running as
 * part of their CPU. */
FUNDEF NOBLOCK NOPREEMPT NONNULL((1)) size_t
NOTHROW(FCALL sig_broadcast_as_nopr)(struct sig *__restrict self,
                                     struct task *__restrict sender_thread);

/* Same as `sig_broadcast()', don't immediatly destroy threads when their
 * reference counter reaches 0. Instead, chain those threads together and
 * return them to the caller, to-be destroyed at their leisure.
 *
 * This function is needed to comply with the no-decref requirement of AIO
 * completion functions that have yet to invoke `aio_handle_release()':
 * >> PRIVATE NOBLOCK NOPREEMPT NONNULL((1)) void
 * >> NOTHROW(FCALL my_aio_completion)(struct aio_handle *__restrict self,
 * >>                                  unsigned int status) {
 * >>     struct task *delme_threads = NULL;
 * >>     sig_broadcast_destroylater_nopr((struct sig *)self->ah_data[0], &delme_threads);
 * >>     aio_handle_release(self);
 * >>     while (unlikely(delme_threads)) {
 * >>         struct task *next;
 * >>         next = sig_destroylater_next(delme_threads);
 * >>         destroy(delme_threads);
 * >>         delme_threads = next;
 * >>     }
 * >> } */
FUNDEF NOBLOCK NOPREEMPT NONNULL((1, 2)) size_t
NOTHROW(FCALL sig_broadcast_destroylater_nopr)(struct sig *__restrict self,
                                               struct task **__restrict pdestroy_later);
#define sig_destroylater_next(thread) KEY_task_vm_dead__next(thread)




/* Connection status values (is-connected is every `x' with `!TASK_CONNECTION_STAT_CHECK(x)')
 * This initial `!TASK_CONNECTION_STAT_CHECK(x)'-state can transition to:
 *   - TASK_CONNECTION_STAT_SENT:      Some thread called `sig_send(tc_sig)', and the
 *                                     associated `struct task_connection' was selected.
 *   - TASK_CONNECTION_STAT_BROADCAST: Some thread called `sig_broadcast(tc_sig)'.
 * Also note that any recipient can only ever have at most 1 connection with
 * a state of `TASK_CONNECTION_STAT_SENT' or `TASK_CONNECTION_STAT_BROADCAST',
 * though this invariant is only true when interlocked with the SMP-locks of
 * all attached signals. (s.a. `tcs_dlvr')
 */
#ifdef CONFIG_USE_NEW_SIGNAL_API
#define TASK_CONNECTION_STAT_BROADCAST           0x0000 /* Signal was broadcast (forwarding is unnecessary if ignored)
                                                         * In this state, `tc_sig' must be considered to be `[valid_if(false)]', and the
                                                         * thread that originally connected to the signal mustn't directly re-connect.
                                                         * When all (past) connections have entered this state, the associated signal is
                                                         * allowed to have it's backing memory be free'd!
                                                         * NOTE: THIS STATUS WILL NEVER APPEAR IN SIGNAL CONNECTION CHAINS! */
#define TASK_CONNECTION_STAT_SENT                0x0002 /* Signal was sent, and must be forwarded if not received via `task_waitfor()'
                                                         * In this state, the attached signal must not be free'd, though this case can
                                                         * easily be handled by broadcasting signals one last time before disconnecting.
                                                         * Transitions to (with [lock(SMP_LOCK(tc_sig))]):
                                                         *   - TASK_CONNECTION_STAT_BROADCAST: Any thread called `sig_broadcast()'
                                                         *                                     on the attached signal. */
#ifndef CONFIG_NO_SMP
#define TASK_CONNECTION_STAT_FLOCK               0x0001 /* SMP lock (must be held when removing the associated connection from the signal) */
#endif /* !CONFIG_NO_SMP */
#define TASK_CONNECTION_STAT_FPOLL               0x0002 /* This is a POLL-based connection. */
#define TASK_CONNECTION_STAT_FMASK               0x0003 /* Mask of flags */
#define TASK_CONNECTION_STAT_COMPLETION          0x0004 /* Special type: This is actually a `struct sig_completion' */
#define TASK_CONNECTION_STAT_COMPLETION_FOR_POLL 0x0006 /* Special type: This is actually a `struct sig_completion' established for polling */

#define TASK_CONNECTION_STAT_ISDEAD(x) ((uintptr_t)(x) <= 1) /* Connection has been disconnected. (`tc_sig' may point to deallocated memory) */
#define TASK_CONNECTION_STAT_ISDONE(x) ((uintptr_t)(x) <= 3) /* Signal has been delivered. */
#define TASK_CONNECTION_STAT_ISSPEC(x) ((uintptr_t)(x) <= 7) /* Connection requires special treatment. */
#define TASK_CONNECTION_STAT_ISCOMP(x) ((uintptr_t)(x) >= 4) /* Connection is a `struct sig_completion' (assumes that `TASK_CONNECTION_STAT_ISSPEC() == true') */
#define TASK_CONNECTION_STAT_ISPOLL(x) ((uintptr_t)(x) & TASK_CONNECTION_STAT_FPOLL) /* Connection is poll-based. */
#define TASK_CONNECTION_STAT_ASCONS(x) ((struct task_connections *)((uintptr_t)(x) & ~3)) /* When `!TASK_CONNECTION_STAT_ISSPEC(x)', return the underlying `struct task_connections' */
#else /* CONFIG_USE_NEW_SIGNAL_API */
#define TASK_CONNECTION_STAT_SENT         ((uintptr_t)-1) /* Signal was sent, and must be forwarded if not received via `task_waitfor()'
                                                           * In this state, the attached signal must not be free'd, though this case can
                                                           * easily be handled by broadcasting signals one last time before disconnecting.
                                                           * Transitions to (with [lock(SMP_LOCK(tc_sig))]):
                                                           *   - TASK_CONNECTION_STAT_BROADCAST: Any thread called `sig_broadcast()'
                                                           *                                     on the attached signal. */
#define TASK_CONNECTION_STAT_BROADCAST    ((uintptr_t)-2) /* Signal was broadcast (forwarding is unnecessary if ignored)
                                                           * In this state, `tc_sig' must be considered to be `[valid_if(false)]', and the
                                                           * thread that originally connected to the signal mustn't directly re-connect.
                                                           * When all (past) connections have entered this state, the associated signal is
                                                           * allowed to have it's backing memory be free'd!
                                                           * NOTE: THIS STATUS WILL NEVER APPEAR IN SIGNAL CONNECTION CHAINS! */
#define TASK_CONNECTION_STAT_CHECK(x)     ((uintptr_t)(x) >= (uintptr_t)-2)

/* For use when `!TASK_CONNECTION_STAT_CHECK(x)': check for poll-connections. */
#define TASK_CONNECTION_STAT_GETCONS(x)   ((struct task_connections *)((uintptr_t)(x) & ~1))
#define TASK_CONNECTION_STAT_ISNORM(x)    (((uintptr_t)(x) & 1) == 0)
#define TASK_CONNECTION_STAT_ISPOLL(x)    (((uintptr_t)(x) & 1) != 0)
#endif /* !CONFIG_USE_NEW_SIGNAL_API */

struct task_connection {
	struct sig                  *tc_sig;     /* [1..1][const] The connected signal. */
	struct task_connection      *tc_connext; /* [0..1][lock(THIS_TASK)] Next connection established by the caller. */
	struct task_connection      *tc_signext; /* [0..1][lock(!PREEMPTION_ENABLED() && IF_SMP(SMP_LOCK(tc_sig)))]
	                                          * Next connection for the same signal. */
	union {
		struct task_connections *tc_cons; /* [1..1] Attached connection set/connection status.
		                                   * The least significant bit is set in case of a poll-connection. */
		WEAK uintptr_t           tc_stat; /* Connection status (one of `TASK_CONNECTION_STAT_*'). */
	};
};


/* Max number of signal connections guarantied to not invoke `kmalloc()'
 * and potentially throw exceptions, or serve RPC functions. */
#ifndef CONFIG_TASK_STATIC_CONNECTIONS
#define CONFIG_TASK_STATIC_CONNECTIONS 3
#endif /* !CONFIG_TASK_STATIC_CONNECTIONS */

struct task_connections {
	struct task_connections *tsc_prev;   /* [0..1][lock(PRIVATE(THIS_TASK))]
	                                      * [(!= NULL) == (this == &this_root_connections)]
	                                      * Previous set of active connections. */
	WEAK struct task        *tcs_thread; /* [0..1][lock(PRIVATE(THIS_TASK))]
	                                      * The thread to wake upon signal delivery. (may also be `NULL')
	                                      * This field is usually `NULL' for all connection sets 
	                                      * `!= FORTASK(tcs_thread, this_connections)', and is set
	                                      * as equal to `THIS_TASK' for `PERTASK(this_connections)'
	                                      * Note that it is guarantied that this task-pointer remains
	                                      * valid from the point of view of potentially attached signal,
	                                      * even after this field may be set to NULL/non-NULL, for as
	                                      * long as the actual, underlying thread no longer has any
	                                      * active connections. (i.e. has called `task_disconnectall()') */
	struct task_connection  *tcs_con;    /* [0..1][chain(->tc_connext)][lock(PRIVATE(THIS_TASK))]
	                                      * Chain of active connections. */
	struct sig              *tcs_dlvr;   /* [0..1][lock(WRITE_ONCE, CLEAR(PRIVATE))]
	                                      * The first signal that got delivered. */
	struct task_connection   tcs_static[CONFIG_TASK_STATIC_CONNECTIONS];
	                                     /* [*.in_use_if(.tc_sig != NULL)][lock(PRIVATE(THIS_TASK))]
	                                      * Statically allocated connections. Any connection that belongs to
	                                      * this connections set, but points outside of this array is allocated
	                                      * dynamically using `kmalloc()', and as such, must be freed by `kfree()' */
};

/* Root connections set. */
DATDEF ATTR_PERTASK struct task_connections this_root_connections;
#define THIS_ROOT_CONNECTIONS (&PERTASK(this_root_connections))

/* [1..1][lock(PRIVATE(THIS_TASK))] Current set of in-use connections.
 * Most of the time, this will simply point to `PERTASK(this_root_connections)' */
DATDEF ATTR_PERTASK struct task_connections *this_connections;
#define THIS_CONNECTIONS PERTASK_GET(this_connections)


/* Push/pop the active set of connections. */
FUNDEF NOBLOCK NONNULL((1)) void
NOTHROW(FCALL task_pushconnections)(struct task_connections *__restrict cons);
FUNDEF NOBLOCK ATTR_RETNONNULL struct task_connections *
NOTHROW(FCALL task_popconnections)(void);




/* Connect the calling thread to a given signal.
 * NOTE: It the caller was already connected to `target', a second connection
 *       will be established, and `task_disconnect()' must be called more than
 *       once. However, aside from this, having multiple connections to the
 *       same signal has no other adverse side-effects.
 * NOTE: When the signal test expression is able to throw an exception, the
 *       caller of this function is responsible to disconnect from the signal
 *       afterwards. However, exceptions that may be thrown by `task_waitfor()'
 *       always guaranty that _all_ established connections have been removed.
 * >> if (test())
 * >>     return true;
 * >> task_connect(s);
 * >> TRY {
 * >>     if (test()) {
 * >>         task_disconnectall();
 * >>         return true;
 * >>     }
 * >> } EXCEPT {
 * >>     task_disconnectall();
 * >>     RETHROW();
 * >> }
 * >> task_waitfor();
 *
 * @throw: E_BADALLOC: Insufficient memory (only when there are at least
 *                     `CONFIG_TASK_STATIC_CONNECTIONS' connections already). */
FUNDEF NONNULL((1)) void FCALL
task_connect(struct sig *__restrict target) /*THROWS(E_BADALLOC)*/;

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
FUNDEF NONNULL((1)) void FCALL
task_connect_for_poll(struct sig *__restrict target) /*THROWS(E_BADALLOC)*/;


/* Disconnect from a specific signal `target'
 * @return: true:  Disconnected from `target'
 * @return: false: You weren't actually connected to `target' */
FUNDEF NOBLOCK NONNULL((1)) __BOOL
NOTHROW(FCALL task_disconnect)(struct sig *__restrict target);

/* Disconnect from all connected signal.
 * Signals with a state of `TASK_CONNECTION_STAT_SENT' will be forwarded. */
FUNDEF NOBLOCK void
NOTHROW(FCALL task_disconnectall)(void);

/* Same as `task_disconnectall()', but don't forward signals with a
 * `TASK_CONNECTION_STAT_SENT'-state, but rather return the sender
 * of of the signal that was received.
 * As such, the caller must properly pass on information about the
 * fact that a signal may have been received, as well as act upon
 * this fact. */
FUNDEF NOBLOCK WUNUSED struct sig *
NOTHROW(FCALL task_receiveall)(void);

/* Check if the calling thread is connected to any signal. */
FUNDEF NOBLOCK ATTR_PURE WUNUSED __BOOL
NOTHROW(FCALL task_isconnected)(void);

/* Check if the calling thread is connected to the given signal. */
FUNDEF NOBLOCK ATTR_PURE WUNUSED __BOOL
NOTHROW(FCALL task_isconnected_to)(struct sig const *__restrict target);

#ifdef __cplusplus
extern "C++" {
FUNDEF NOBLOCK ATTR_PURE WUNUSED __BOOL
NOTHROW(FCALL task_isconnected)(struct sig const *__restrict target)
		ASMNAME("task_isconnected_to");
} /* extern "C++" */
#endif /* __cplusplus */


/* Check if there is a signal to was delivered, disconnecting
 * all other connected signals if this was the case.
 * @return: NULL: No signal is available
 * @return: * :   The signal that was delivered. */
FUNDEF NOBLOCK struct sig *NOTHROW(FCALL task_trywait)(void);

/* Wait for the first signal to be delivered, unconditionally
 * disconnecting all connected signals thereafter.
 * NOTE: Prior to fully starting to block, this function will call `task_serve()'
 * @param: abs_timeout:  The `realtime()' timeout for the wait.
 * @throw: E_WOULDBLOCK: Preemption was disabled, and the operation would have blocked.
 * @throw: * :           [task_waitfor] An error was thrown by an RPC function.
 *                       NOTE: In this case, `task_disconnectall()' will have been called.
 *              WARNING: In all other cases, task connections are preserved when an exception
 *                       is thrown, meaning that if some interlocked signal check might thrown
 *                       an exception, you are required to TRY ... EXCEPT { task_disconnectall(); }
 *                       to prevent signal connections from being leaked!
 * @return: NULL: No signal has become available (never returned when `NULL' is passed for `abs_timeout').
 * @return: * :   The signal that was delivered. */
FUNDEF struct sig *FCALL
task_waitfor(struct timespec const *abs_timeout DFL(__NULLPTR))
		THROWS(E_WOULDBLOCK, ...);

/* Same as `task_waitfor', but don't serve RPC functions. */
FUNDEF struct sig *FCALL
task_waitfor_norpc(struct timespec const *abs_timeout DFL(__NULLPTR))
		THROWS(E_WOULDBLOCK);

/* Same as `task_waitfor', but only service NX RPCs, and return `NULL' if
 * there are pending RPCs that are allowed to throw exception, or if preemption
 * was disabled, and the operation would have blocked. */
FUNDEF struct sig *
NOTHROW(FCALL task_waitfor_nx)(struct timespec const *abs_timeout DFL(__NULLPTR));

/* Same as `task_waitfor', but don't serve RPC functions, and return
 * `NULL' if preemption was disabled, and the operation would have blocked. */
FUNDEF struct sig *
NOTHROW(FCALL task_waitfor_norpc_nx)(struct timespec const *abs_timeout DFL(__NULLPTR));


#ifdef CONFIG_BUILDING_KERNEL_CORE
INTDEF NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pertask_init_task_connections)(struct task *__restrict self);
#endif /* CONFIG_BUILDING_KERNEL_CORE */


#ifdef CONFIG_USE_NEW_SIGNAL_API
/* Signal completion usage example:
 * >> // `struct rising_edge_detector' can be used for implementing an asynchronous
 * >> // connection to a signal (i.e. do the equivalent of `task_connect()' asynchronous,
 * >> // including across return-to-userspace-and-back-via-syscall and similar conditions)
 * >> struct rising_edge_detector: sig_completion {
 * >> 	bool       red_detected; // Set to true when a rising edge was detected
 * >> 	struct sig red_ondetect; // Broadcast when `red_detected' becomes true
 * >> };
 * >> PRIVATE NOBLOCK NOPREEMPT NONNULL((1, 2, 3, 5)) void
 * >> NOTHROW(KCALL rising_edge_detector_completion)(struct sig_completion *__restrict self,
 * >>                                                struct sig *__restrict signal,
 * >>                                                struct task *__restrict sender_thread,
 * >>                                                unsigned int phase,
 * >>                                                struct task **__restrict pdestroy_later,
 * >>                                                struct sig *UNUSED(sender)) {
 * >> 	struct rising_edge_detector *me;
 * >> 	me = (struct rising_edge_detector *)self;
 * >> 	switch (phase) {
 * >> 	case SIG_COMPLETION_PHASE_SETUP:
 * >> #if 0 // (optional): Automatic re-prime
 * >> 		sig_completion_reprime(self, signal, true);
 * >> #endif
 * >> 		break;
 * >> 	case SIG_COMPLETION_PHASE_PAYLOAD:
 * >> 		sig_completion_release(me);
 * >> 		if (!ATOMIC_XCH(me->red_detected, true)) {
 * >> 			sig_broadcast_as_destroylater_nopr(&me->red_ondetect,
 * >> 			                                   sender_thread,
 * >> 			                                   pdestroy_later);
 * >> 		}
 * >> 		break;
 * >> 	default: __builtin_unreachable();
 * >> 	}
 * >> }
 * >> 
 * >> PRIVATE NOBLOCK NONNULL((1)) void
 * >> NOTHROW(FCALL rising_edge_detector_init)(struct rising_edge_detector *__restrict self,
 * >>                                          struct sig *__restrict signal) {
 * >> 	sig_completion_init(self, &rising_edge_detector_completion);
 * >> 	sig_init(&self->red_ondetect);
 * >> 	self->red_detected = false;
 * >> 	sig_connect_completion_for_poll(signal, self);
 * >> }
 * >> 
 * >> PRIVATE NOBLOCK NONNULL((1)) void
 * >> NOTHROW(FCALL rising_edge_detector_fini)(struct rising_edge_detector *__restrict self) {
 * >> 	sig_completion_disconnect(self);
 * >> }
 * >> 
 * >> PRIVATE NOBLOCK NONNULL((1)) void FCALL
 * >> rising_edge_detector_waitfor(struct rising_edge_detector *__restrict self) {
 * >> 	while (!ATOMIC_XCH(self->red_detected, false)) {
 * >> 		task_connect(&self->red_ondetect);
 * >> 		if unlikely(ATOMIC_XCH(self->red_detected, false)) {
 * >> 			task_disconnectall();
 * >> 			break;
 * >> 		}
 * >> 		task_waitfor();
 * >> 	}
 * >> }
 * >>
 * >> PRIVATE struct sig mysig = SIG_INIT;
 * >>
 * >> PRIVATE void demo(void) {
 * >> 	struct rising_edge_detector red;
 * >> 	// Async task_connect()
 * >> 	rising_edge_detector_init(&red, &mysig);
 * >> 
 * >> 	sig_broadcast(&mysig);
 * >> 
 * >> 	// Async task_waitfor()
 * >> 	rising_edge_detector_waitfor(&red);
 * >> 	rising_edge_detector_fini(&red);
 * >> }
 */



struct sig_completion;
struct task;
/* Callback prototype for signal completion functions.
 * >> PRIVATE NOBLOCK NOPREEMPT NONNULL((1, 2, 3, 5)) void
 * >> NOTHROW(KCALL my_sig_completion)(struct sig_completion *__restrict self,
 * >>                                  struct sig *__restrict signal,
 * >>                                  struct task *__restrict sender_thread,
 * >>                                  unsigned int phase,
 * >>                                  struct task **__restrict pdestroy_later,
 * >>                                  struct sig *sender) {
 * >>     switch (phase) {
 * >>     case SIG_COMPLETION_PHASE_SETUP:
 * >>         sig_completion_reprime(self, signal); // Optional!
 * >>         break;
 * >>     case SIG_COMPLETION_PHASE_PAYLOAD:
 * >>         sig_completion_release(self);
 * >>         break;
 * >>     default: __builtin_unreachable();
 * >>     }
 * >> }
 * @param: self:          The signal completion controller.
 * @param: phase:         One of `SIG_COMPLETION_PHASE_*'
 * @param: pdestroy_later: Chain of threads to-be destroyed later (s.a. `sig_broadcast_destroylater_nopr()') */
typedef NOBLOCK NOPREEMPT NONNULL((1, 2, 3, 5)) void
/*NOTHROW*/ (KCALL *sig_completion_t)(struct sig_completion *__restrict self,
                                      struct sig *__restrict signal,
                                      struct task *__restrict sender_thread,
                                      unsigned int phase,
                                      struct task **__restrict pdestroy_later,
                                      struct sig *sender);
#define SIG_COMPLETION_PHASE_SETUP   0 /* First phase: At this point, the SMP-lock for `signal' is
                                        * still held, During this phase, the completion function
                                        * may use `sig_completion_reprime()' to re-prime itself.
                                        * Note that even NOBLOCK operation may not be safe during
                                        * this phase due to the internal SMP-lock. Such operations must
                                        * instead be performed during the `SIG_COMPLETION_PHASE_PAYLOAD'
                                        * phase. */
#define SIG_COMPLETION_PHASE_PAYLOAD 1 /* The payload phase: During this phase, the callback is
                                        * required to invoke `sig_completion_release(self)' in
                                        * order to unlock the completion callback, allowing a
                                        * potential other thread to cancel/destroy/re-connect the
                                        * completion function.
                                        * During this phase, the callback is also allowed to trigger
                                        * other signals (but should be aware that doing so may cause
                                        * other signal completion functions to do the same, possibly
                                        * resulting in a stack-overflow if this goes on for too long) */

/* Re-prime the completion callback to be invoked once again the next time that the
 * attached signal is delivered. In this case, the completion function is responsible
 * to ensure that no-one is currently trying to destroy the associated signal. */
FUNDEF NOBLOCK NOPREEMPT void
NOTHROW(KCALL sig_completion_reprime)(struct sig_completion *__restrict self,
                                      struct sig *__restrict signal,
                                      bool for_poll);
#ifdef CONFIG_NO_SMP
#define sig_completion_release(self) (void)0
#else /* CONFIG_NO_SMP */
#define sig_completion_release(self)                       \
	__hybrid_atomic_and(_sig_completion_con(self).tc_stat, \
	                    ~TASK_CONNECTION_STAT_FLOCK,       \
	                    __ATOMIC_RELEASE)
#endif /* !CONFIG_NO_SMP */



struct sig_completion
#ifdef __cplusplus
    : task_connection              /* The underlying connection */
#endif /* __cplusplus */
{
#ifndef __cplusplus
	struct task_connection sc_con; /* The underlying connection */
#endif /* __cplusplus */
	sig_completion_t       sc_cb;  /* Completion callback. */
};

#ifdef __cplusplus
#define _sig_completion_con(self) (*(self))
#else /* __cplusplus */
#define _sig_completion_con(self) (self)->sc_con
#endif /* !__cplusplus */

/* Initialize a given signal completion controller. */
#define sig_completion_init(self, cb)                                    \
	(_sig_completion_con(self).tc_stat = TASK_CONNECTION_STAT_BROADCAST, \
	 (self)->sc_cb                     = (cb))

/* Connect the given signal completion controller to the specified signal.
 * The caller must ensure that `completion' hasn't been connected, yet. */
FUNDEF NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL sig_connect_completion)(struct sig *__restrict self,
                                      struct sig_completion *__restrict completion);
FUNDEF NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL sig_connect_completion_for_poll)(struct sig *__restrict self,
                                               struct sig_completion *__restrict completion);

/* @return: true:  Completion function was disconnected before it could be triggered,
 *                 or the last time the completion function was triggered, it made use
 *                 of `sig_completion_reprime()' to re-prime itself.
 * @return: false: Completion function was already triggered, but not re-primed.
 *                 Alternatively, the signal completion function had already been
 *                 disconnected, or had never been connected to begin with. */
FUNDEF NOBLOCK NONNULL((1)) bool
NOTHROW(FCALL sig_completion_disconnect)(struct sig_completion *__restrict self);

#endif /* CONFIG_USE_NEW_SIGNAL_API */

#endif /* __CC__ */


/* Configuration option for standard synchronization primitives.
 * Before connecting to a signal, try to yield a couple of times
 * to try and get other threads to release some kind of lock, as
 * `task_yield()' is a much faster operation than task_connect()+task_waitfor().
 * Doing this may improve performance, especially on single-core machines.
 * Note however that this option does not affect the behavior of
 * low-level `struct sig' objects, but instead primitives found in
 * <sched/[...].h>, such as `struct mutex', `struct rwlock',
 * `struct semaphore' and `struct shared_rwlock'
 * NOTE: The number that this is defined to describes the
 *       max number of times `task_yield()' is attempted
 *      (implementing a kind-of spin-locking mechanism),
 *       before a signal is actually connected. */
#ifndef CONFIG_YIELD_BEFORE_CONNECT
#ifndef CONFIG_NO_YIELD_BEFORE_CONNECT
#define CONFIG_YIELD_BEFORE_CONNECT 4
#endif /* !CONFIG_NO_YIELD_BEFORE_CONNECT */
#elif defined(CONFIG_NO_YIELD_BEFORE_CONNECT)
#undef CONFIG_YIELD_BEFORE_CONNECT
#endif /* ... */

#if defined(CONFIG_YIELD_BEFORE_CONNECT) && (CONFIG_YIELD_BEFORE_CONNECT+0) == 0
#undef CONFIG_YIELD_BEFORE_CONNECT
#endif /* CONFIG_YIELD_BEFORE_CONNECT && (CONFIG_YIELD_BEFORE_CONNECT+0) == 0 */


/* Helper macro to implement spin-locking before connecting a signal:
 * >> while (!try_lock()) {
 * >>     TASK_POLL_BEFORE_CONNECT({
 * >>         if (try_lock())
 * >>             return true;
 * >>     });
 * >>     assert(!task_isconnected());
 * >>     task_connect(&lock_signal);
 * >>     TRY {
 * >>         if unlikely(try_lock()) {
 * >>             // Prevent a race condition:
 * >>             //     Lock became available after the last
 * >>             //     check, but before a connection was made
 * >>             task_disconnectall();
 * >>             return true;
 * >>         }
 * >>     } EXCEPT {
 * >>         task_disconnectall();
 * >>         RETHROW();
 * >>     }
 * >>     if (!task_waitfor(TIMEOUT))
 * >>         return false;
 * >> }
 * >> return true;
 */
#ifdef __CC__
#ifdef CONFIG_YIELD_BEFORE_CONNECT
#ifndef __task_tryyield_defined
#define __task_tryyield_defined 1
FUNDEF NOBLOCK_IF(!PREEMPTION_ENABLED())
unsigned int NOTHROW(KCALL task_tryyield)(void);
#endif /* !__task_tryyield_defined */
#if CONFIG_YIELD_BEFORE_CONNECT == 1
#define TASK_POLL_BEFORE_CONNECT(...) \
	do {                              \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
	}	__WHILE0
#elif CONFIG_YIELD_BEFORE_CONNECT == 2
#define TASK_POLL_BEFORE_CONNECT(...) \
	do {                              \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
	}	__WHILE0
#elif CONFIG_YIELD_BEFORE_CONNECT == 3
#define TASK_POLL_BEFORE_CONNECT(...) \
	do {                              \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
	}	__WHILE0
#elif CONFIG_YIELD_BEFORE_CONNECT == 4
#define TASK_POLL_BEFORE_CONNECT(...) \
	do {                              \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
	}	__WHILE0
#elif CONFIG_YIELD_BEFORE_CONNECT == 5
#define TASK_POLL_BEFORE_CONNECT(...) \
	do {                              \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
	}	__WHILE0
#elif CONFIG_YIELD_BEFORE_CONNECT == 6
#define TASK_POLL_BEFORE_CONNECT(...) \
	do {                              \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
		if (task_tryyield() != 0)     \
			break;                    \
		__VA_ARGS__;                  \
	}	__WHILE0
#else /* CONFIG_YIELD_BEFORE_CONNECT == ... */
#define TASK_POLL_BEFORE_CONNECT(...)                            \
	do {                                                         \
		unsigned int __poll_count = CONFIG_YIELD_BEFORE_CONNECT; \
		do {                                                     \
			if (task_tryyield() != 0)                            \
				break;                                           \
			__VA_ARGS__;                                         \
		} while (--__poll_count);                                \
	}	__WHILE0
#endif /* CONFIG_YIELD_BEFORE_CONNECT != ... */
#else /* CONFIG_YIELD_BEFORE_CONNECT */
#define TASK_POLL_BEFORE_CONNECT(...) (void)0
#endif /* !CONFIG_YIELD_BEFORE_CONNECT */
#endif /* __CC__ */

DECL_END

#endif /* !GUARD_KERNEL_INCLUDE_SCHED_SIGNAL_H */
