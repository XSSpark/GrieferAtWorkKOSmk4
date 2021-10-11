/* Copyright (c) 2019-2021 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2021 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_KERNEL_SRC_SCHED_PID_C
#define GUARD_KERNEL_SRC_SCHED_PID_C 1
#define _KOS_SOURCE 1
#define _GNU_SOURCE 1
#define _TIME64_SOURCE 1

#include <kernel/compiler.h>

#include <dev/ttybase.h>
#include <kernel/except.h>
#include <kernel/handle-proto.h>
#include <kernel/handle.h>
#include <kernel/malloc.h>
#include <kernel/syscall.h>
#include <kernel/types.h>
#include <kernel/user.h>
#include <sched/cpu.h>
#include <sched/pid.h>
#include <sched/posix-signal.h>
#include <sched/rpc-internal.h>
#include <sched/rpc.h>
#include <sched/task.h>

#include <hybrid/atomic.h>
#include <hybrid/overflow.h>

#include <bits/os/rusage-convert.h>
#include <bits/os/rusage.h>
#include <bits/os/timespec.h>
#include <compat/config.h>
#include <kos/except.h>
#include <kos/except/reason/illop.h>
#include <kos/except/reason/inval.h>
#include <sys/poll.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <sched.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>

#ifdef __ARCH_HAVE_COMPAT
#include <compat/bits/os/rusage-convert.h>
#include <compat/bits/os/rusage.h>
#include <compat/bits/os/siginfo-convert.h>
#include <compat/bits/os/siginfo.h>
#include <compat/bits/types.h>
#include <compat/kos/types.h>
#include <compat/signal.h>
#endif /* __ARCH_HAVE_COMPAT */

DECL_BEGIN

#if !defined(NDEBUG) && !defined(NDEBUG_FINI)
#define DBG_memset memset
#else /* !NDEBUG && !NDEBUG_FINI */
#define DBG_memset(...) (void)0
#endif /* NDEBUG || NDEBUG_FINI */


PRIVATE NOBLOCK NONNULL((1, 2)) void
NOTHROW(KCALL pidns_remove)(struct pidns *__restrict self,
                            /*inherit(always)*/ struct taskpid *__restrict pid);

PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(KCALL taskpid_destroy)(struct taskpid *__restrict self) {
	struct pidns *ns = self->tp_pidns;
	assert(awref_ptr(&self->tp_thread) == NULL);
	sig_broadcast_for_fini(&self->tp_changed);
	/* shouldn't be NULL, but may be in case of incomplete initialization... */
	if unlikely(!ns) {
		kfree(self);
		return;
	}
	/* Remove this taskpid from its pidns */
	pidns_remove(ns, self);
	decref_unlikely(ns);
}

/* Same as `taskpid_gettask()', but throw an exception if the thread has exited. */
PUBLIC ATTR_RETNONNULL WUNUSED REF struct task *KCALL
taskpid_gettask_srch(struct taskpid *__restrict self) THROWS(E_PROCESS_EXITED) {
	REF struct task *result;
	result = taskpid_gettask(self);
	if unlikely(!result)
		THROW(E_PROCESS_EXITED, taskpid_getpid_s(self));
	return result;
}


/* [1..1][valid_if(!TASK_FKERNTHREAD)][const] The PID associated with the calling thread.
 * NOTE: `NULL' (though assume  UNDEFINED if  the choice  comes up)  for kernel  threads. */
PUBLIC ATTR_PERTASK struct taskpid *this_taskpid = NULL;


PRIVATE NONNULL((1)) void PRPC_EXEC_CALLBACK_CC
rpc_propagate_exit_state_to_worker(struct rpc_context *__restrict ctx, void *cookie) {
	if (ctx->rc_context != RPC_REASONCTX_SHUTDOWN)
		THROW(E_EXIT_THREAD, (uintptr_t)cookie);
}


PRIVATE NOBLOCK void
NOTHROW(KCALL task_propagate_exit_status_to_worker_thread)(struct task *__restrict worker,
                                                           struct taskpid *__restrict UNUSED(worker_pid),
                                                           struct task *__restrict origin,
                                                           struct taskpid *__restrict origin_pid) {
	struct taskgroup *worker_group;
	struct pending_rpc *rpc;

	/* Send an RPC callback to `worker' to propagate the exit status
	 * that caused the  task associated with  `origin_pid' to  exit. */
	worker_group = &FORTASK(worker, this_taskgroup);
	assert(worker_group->tg_process == origin);
	rpc = ATOMIC_XCH(worker_group->tg_thread_exit, NULL);
	if unlikely(!rpc)
		return; /* Shouldn't happen, but would indicate that an RPC was already delivered. */

	/* Save the exit-status from the originating thread, and use that status for the worker. */
	rpc->pr_kern.k_cookie = (void *)(uintptr_t)(unsigned int)origin_pid->tp_status.w_status;
	if (task_rpc_schedule(worker, rpc))
		return;
	/* Failed to deliver the RPC because the worker thread has/is already
	 * terminated/terminating, and is no longer able to service any RPCs. */

	/* Cleanup the RPC, since it isn't inherited by `task_rpc_schedule()' upon failure. */
	pending_rpc_free(rpc);
}

PRIVATE NOBLOCK void
NOTHROW(KCALL task_send_sigcld_to_parent_process)(struct task *__restrict parent,
                                                  struct task *__restrict origin,
                                                  struct taskpid *__restrict origin_pid) {
	/* Signal that we've changed state. */
	sig_altbroadcast(&FORTASK(parent, this_taskgroup).tg_proc_threads_change,
	                 (struct sig *)origin_pid);
	/* TODO: Send a `SIGCLD' to `parent' */
	/*task_raisesignalprocess(parent, SIGCLD, GFP_ATOMIC);*/
	(void)parent;
	(void)origin;
	(void)origin_pid;
}


/* >> void KCALL func(struct task *__restrict new_thread, uintptr_t flags);
 * Invoked  to initialize a given clone `new_thread' of the calling thread.
 * @param: flags: Set of `CLONE_*' from `<bits/sched.h>' */
DEFINE_PERTASK_CLONE(this_taskgroup_clone);
PRIVATE ATTR_USED void KCALL
this_taskgroup_clone(struct task *__restrict new_thread, uintptr_t flags) {
	/* Allocate the PID descriptor for the new thread. */
	if (flags & CLONE_NEWPID) {
		REF struct pidns *ns;
		ns = pidns_alloc(THIS_PIDNS);
		FINALLY_DECREF_UNLIKELY(ns);
		task_setpid(new_thread, ns, 0);
	} else {
		task_setpid(new_thread, THIS_PIDNS, 0);
	}
	/* TODO: Remember `flags & CSIGNAL' as signal to-be send on exit! */
	if (flags & CLONE_THREAD) {
		/* Add to the same process as the caller */
		task_setthread(new_thread,
		               THIS_TASK);
	} else if (flags & CLONE_PARENT) {
		REF struct task *my_parent;
		my_parent = task_getprocessparent();
		FINALLY_XDECREF_UNLIKELY(my_parent);
		/* Inherit parent, group & session of the caller */
		task_setprocess(new_thread,
		                my_parent,
		                THIS_TASK,
		                THIS_TASK);
	} else {
		/* Inherit group & session of the caller; set caller as parent */
		task_setprocess(new_thread,
		                THIS_TASK,
		                THIS_TASK,
		                THIS_TASK);
	}

	/* Already pre-detach the thread if instructed to */
	if (flags & CLONE_DETACHED)
		task_detach(new_thread);
}


DEFINE_PERTASK_ONEXIT(this_taskgroup_cleanup);
PRIVATE ATTR_USED NOBLOCK void
NOTHROW(KCALL this_taskgroup_cleanup)(void) {
	struct task *proc;
	struct taskpid *mypid = THIS_TASKPID;
#ifdef __INTELLISENSE__
	struct taskgroup &mygroup = FORTASK(proc, this_taskgroup);
#else /* __INTELLISENSE__ */
#define mygroup FORTASK(proc, this_taskgroup)
#endif /* !__INTELLISENSE__ */
	proc = task_getprocess();
	if (!proc) {
		/* Kernel-space thread */
		assert(!mypid);
	} else if (proc == THIS_TASK) {
		REF struct taskpid *threads;
		assert(mypid);
		threads = ATOMIC_XCH(mygroup.tg_proc_threads.lh_first,
		                     TASKGROUP_TG_PROC_THREADS_TERMINATED);
		assert(threads != TASKGROUP_TG_PROC_THREADS_TERMINATED);
		assert(!WIFCONTINUED(mypid->tp_status) && !WIFSTOPPED(mypid->tp_status));
		/* Terminate all child threads that are still running. */
		while (threads) {
			REF struct task *child_thread;
			REF struct taskpid *next;
			next = LIST_NEXT(threads, tp_siblings);
			ATOMIC_WRITE(threads->tp_siblings.le_prev, NULL);
			__HYBRID_Q_BADPTR(threads->tp_siblings.le_next);
			child_thread = awref_get(&threads->tp_thread);
			if (child_thread) {
				/* Must differentiate:
				 *   - A child thread that is apart of our process (to which we must propagate the exit status)
				 *   - A child process (from which we must detach ourself, the same way the `detach(2)' system call would) */
				if (task_isprocessleader_p(child_thread)) {
					/* Child process (detach) */
					while (!sync_trywrite(&FORTASK(child_thread, this_taskgroup).tg_proc_parent_lock))
						task_tryyield_or_pause();
					assert(FORTASK(child_thread, this_taskgroup).tg_proc_parent == THIS_TASK);
					FORTASK(child_thread, this_taskgroup).tg_proc_parent = NULL;
					sync_endwrite(&FORTASK(child_thread, this_taskgroup).tg_proc_parent_lock);
				} else {
					/* Child thread (propagate exit status, aka. terminate) */
					task_propagate_exit_status_to_worker_thread(child_thread,
					                                            threads,
					                                            proc,
					                                            mypid);
				}
				decref(child_thread);
			}
			/* Drop the reference previously stored within the chain of linked child threads. */
			decref(threads);
			threads = next;
		}
		/* Load the parent of the process */
		{
			REF struct task *parent;
			while (!sync_tryread(&mygroup.tg_proc_parent_lock))
				task_tryyield_or_pause();
			parent = mygroup.tg_proc_parent;
			if (parent && !tryincref(parent))
				parent = NULL;
			sync_endread(&mygroup.tg_proc_parent_lock);
			if (parent) {
				/* Send an IPC signal to `parent', informing them that we've just terminated! (SIGCLD) */
				COMPILER_READ_BARRIER();
				if (LIST_ISBOUND(mypid, tp_siblings)) /* Check if we've been detached. */
					task_send_sigcld_to_parent_process(parent, proc, mypid);
				decref(parent);
			}
		}
		/* Shutdown any remaining RPCs and mark the per-process RPC list as terminated. */
		{
			struct pending_rpc *remain;
			assert(PREEMPTION_ENABLED());
			atomic_rwlock_write(&mygroup.tg_proc_rpcs.ppr_lock);
			remain = ATOMIC_XCH(mygroup.tg_proc_rpcs.ppr_list.slh_first, THIS_RPCS_TERMINATED);
			atomic_rwlock_endwrite(&mygroup.tg_proc_rpcs.ppr_lock);
			sig_broadcast_for_fini(&mygroup.tg_proc_rpcs.ppr_more);
			assert(remain != THIS_RPCS_TERMINATED);
			task_asyncrpc_destroy_list_for_shutdown(remain);
		}
	} else {
		uintptr_t thread_detach_state;
		assert(mypid);
		assert(!WIFCONTINUED(mypid->tp_status) && !WIFSTOPPED(mypid->tp_status));
		/* Broadcast without our thread that we've changed state */
		sig_altbroadcast(&mygroup.tg_proc_threads_change, (struct sig *)mypid);
		do {
			COMPILER_READ_BARRIER();
			thread_detach_state = PERTASK_GET(this_taskgroup.tg_thread_detached);
			COMPILER_READ_BARRIER();
		} while (!ATOMIC_CMPXCH_WEAK(THIS_TASKGROUP.tg_thread_detached,
		                             thread_detach_state,
		                             TASKGROUP_TG_THREAD_DETACHED_TERMINATED));
		if (thread_detach_state != TASKGROUP_TG_THREAD_DETACHED_NO) {
			/* Remove our thread link from the chain of threads of our process's leader. */
			if (LIST_ISBOUND(mypid, tp_siblings)) {
				while (!sync_trywrite(&mygroup.tg_proc_threads_lock)) {
					COMPILER_READ_BARRIER();
					if (LIST_FIRST(&mygroup.tg_proc_threads) == TASKGROUP_TG_PROC_THREADS_TERMINATED)
						goto done_unlink_pid_sibling; /* The leader has already terminated. */
					task_tryyield_or_pause();
				}
				LIST_UNBIND(mypid, tp_siblings);
				sync_endwrite(&mygroup.tg_proc_threads_lock);
				decref_nokill(mypid); /* The reference previously contained within the `tp_siblings' chain */
			}
		}
done_unlink_pid_sibling:
		;
	}
#undef mygroup
}

DEFINE_PERTASK_FINI(this_taskgroup_fini);
PRIVATE ATTR_USED NOBLOCK void
NOTHROW(KCALL this_taskgroup_fini)(struct task *__restrict self) {
	struct taskpid *mypid = FORTASK(self, this_taskpid);
#ifdef __INTELLISENSE__
	struct taskgroup &mygroup = FORTASK(self, this_taskgroup);
#else /* __INTELLISENSE__ */
#define mygroup FORTASK(self, this_taskgroup)
#endif /* !__INTELLISENSE__ */
	assert(wasdestroyed(self));
	assert(!mypid || awref_ptr(&mypid->tp_thread) == self);
	if unlikely(mygroup.tg_process == NULL)
		; /* Incomplete initialization... */
	else if (mygroup.tg_process != self) {
		decref_unlikely(mygroup.tg_process);
		/* Free up the thread-exit RPC (this happens if
		 * a  thread exits prior to the process leader) */
		if (mygroup.tg_thread_exit)
			pending_rpc_free(mygroup.tg_thread_exit);
	} else {
		/* Process leader. */
		REF struct taskpid *iter, *next;
		iter = LIST_FIRST(&mygroup.tg_proc_threads);
		/* Unload all remaining child thread PID descriptors that
		 * the process  itself  didn't  bother  wait(2)-ing  for. */
		if (iter != TASKGROUP_TG_PROC_THREADS_TERMINATED) {
			while (iter) {
				next = LIST_NEXT(iter, tp_siblings);
				decref(iter);
				iter = next;
			}
		}
		if unlikely(mygroup.tg_proc_group == NULL) {
			/* Incomplete initialization... */
		} else if (mygroup.tg_proc_group != mypid) {
			REF struct taskpid *group_leader_pid;
			REF struct task *group_leader;
			group_leader_pid = mygroup.tg_proc_group; /* Inherit reference */
			group_leader = taskpid_gettask(group_leader_pid);
			if (group_leader) {
				/* Remove ourself from the chain of processes within our group. */
				while (!sync_trywrite(&FORTASK(group_leader, this_taskgroup).tg_pgrp_processes_lock))
					task_tryyield_or_pause();
				LIST_REMOVE_P(self, KEY__this_taskgroup__tg_proc_group_siblings);
				sync_endwrite(&FORTASK(group_leader, this_taskgroup).tg_pgrp_processes_lock);
				DBG_memset(&mygroup.tg_proc_group_siblings, 0xcc, sizeof(mygroup.tg_proc_group_siblings));
				DBG_memset(&mygroup.tg_proc_group, 0xcc, sizeof(mygroup.tg_proc_group));
				decref_unlikely(group_leader);
			}
			decref(group_leader_pid);
		} else {
			/* Process group leader. */
			assertf(LIST_FIRST(&mygroup.tg_pgrp_processes) != self,
			        "The group leader should not be apart of the group process chain\n"
			        "self = %p", self);
			if (mygroup.tg_pgrp_session != mypid) {
				if (mygroup.tg_pgrp_session != NULL)
					decref(mygroup.tg_pgrp_session);
			} else {
				/* Session leader */
				REF struct ttybase_device *mytty;
				mytty = mygroup.tg_ctty.axr_obj;
				if (mytty) {
					/* Unbind the CTTY pointer.
					 * Reminder: The CTTY  (Controlling TTY)  is
					 *           the file found under `/dev/tty' */
					awref_cmpxch(&mytty->t_cproc, mypid, NULL);
					decref(mytty);
				}
				decref_nokill(mypid); /* Reference stored in `mygroup.tg_pgrp_session' */
			}
			decref_nokill(mypid); /* Reference stored in `mygroup.tg_proc_group' */
		}
		/* Finalize any signals that were never delivered. */
		assertf((mygroup.tg_proc_rpcs.ppr_list.slh_first == NULL ||
		         mygroup.tg_proc_rpcs.ppr_list.slh_first == THIS_RPCS_TERMINATED) &&
		        sig_isempty(&mygroup.tg_proc_rpcs.ppr_more),
		        "This shouldn't be because process RPCs should have gotten "
		        "cleaned up during task_exit(). So how did this happen?");
	}
	if (mypid) {
		awref_clear(&mypid->tp_thread);
		decref_likely(mypid);
	}
#undef mygroup
}

PUBLIC ATTR_PERTASK struct taskgroup this_taskgroup = {
	/* .tg_process             = */ NULL,                /* Initialized by `task_setthread()' / `task_setprocess()' */
	{
		/* .tg_proc_threads_lock = */ ATOMIC_RWLOCK_INIT
	},
	{
		/* .tg_proc_threads    = */ LIST_HEAD_INITIALIZER(this_taskgroup.tg_proc_threads)
	},
	/* .tg_proc_threads_change = */ SIG_INIT,
	/* .tg_proc_parent_lock    = */ ATOMIC_RWLOCK_INIT,
	/* .tg_proc_parent         = */ NULL,                /* Initialized by `task_setprocess()' */
	/* .tg_proc_group_lock     = */ ATOMIC_RWLOCK_INIT,
	/* .tg_proc_group          = */ NULL,                /* Initialized by `task_setprocess()' */
	/* .tg_proc_group_siblings = */ LIST_ENTRY_UNBOUND_INITIALIZER,
	/* .tg_proc_rpcs           = */ {
		/* .ppr_lock  = */ ATOMIC_RWLOCK_INIT,
		/* .ppr_list  = */ SLIST_HEAD_INITIALIZER(this_taskgroup.tg_proc_rpcs.ppr_list)
	},
	/* .tg_pgrp_processes_lock = */ ATOMIC_RWLOCK_INIT,
	/* .tg_pgrp_processes      = */ LIST_HEAD_INITIALIZER(this_taskgroup.tg_pgrp_processes),
	/* .tg_pgrp_session_lock   = */ ATOMIC_RWLOCK_INIT,
	/* .tg_pgrp_session        = */ NULL,                /* Initialized by `task_setprocess()' */
	/* .tg_ctty                = */ AXREF_INIT(NULL)
};



/* Initialize the `self' to be a member of the same process which `leader' is apart of.
 * NOTE: This function or `task_setprocess()' may only be called once for any given thread.
 *       Also  note  that  these  functions  must  _NOT_  be  called  for  kernel  threads!
 * NOTE: This function must be called _AFTER_ `task_setpid(self)' has already been invoked!
 * @return: true:  Successfully initialized `self' as a thread within the same process as `leader'
 * @return: false: The process that `leader' is apart of has already terminated. */
PUBLIC NONNULL((1, 2)) bool KCALL
task_setthread(struct task *__restrict self,
               struct task *__restrict leader)
		THROWS(E_WOULDBLOCK) {
	struct taskpid *next;
	struct taskpid *pid = FORTASK(self, this_taskpid);
	struct pending_rpc *exit_rpc;
	assertf(pid, "Must call `task_setpid()' before `task_setthread()'");
	assertf(leader && leader != self,
	        "Must use `task_setprocess()' to create a new process");
	assertf(FORTASK(self, this_taskgroup).tg_process == NULL,
	        "`task_setthread()' and `task_setprocess()' may only be called once");
	assertf(!(self->t_flags & TASK_FKERNTHREAD),
	        "`task_setthread()' and `task_setprocess()' may not be used with kernel threads");
	leader                   = task_getprocess_of(leader);
	exit_rpc                 = pending_rpc_alloc_kern(GFP_NORMAL);
	exit_rpc->pr_flags       = RPC_CONTEXT_KERN;
	exit_rpc->pr_kern.k_func = &rpc_propagate_exit_state_to_worker;
	TRY {
		sync_write(&FORTASK(leader, this_taskgroup).tg_proc_threads_lock);
	} EXCEPT {
		pending_rpc_free(exit_rpc);
		RETHROW();
	}
	FORTASK(self, this_taskgroup).tg_process     = incref(leader);
	FORTASK(self, this_taskgroup).tg_thread_exit = exit_rpc;
	assertf(FORTASK(self, this_taskgroup).tg_thread_detached == TASKGROUP_TG_THREAD_DETACHED_NO,
	        "tg_thread_detached = %" PRIuPTR, FORTASK(self, this_taskgroup).tg_thread_detached);
	assert(!LIST_ISBOUND(pid, tp_siblings));
	pid->tp_siblings.le_prev = &FORTASK(leader, this_taskgroup).tg_proc_threads.lh_first;
	incref(pid); /* The reference for the child chain */
	COMPILER_WRITE_BARRIER();
	do {
		next = LIST_FIRST(&FORTASK(leader, this_taskgroup).tg_proc_threads);
		if unlikely(next == TASKGROUP_TG_PROC_THREADS_TERMINATED) {
			pid->tp_siblings.le_prev                 = NULL;
			FORTASK(self, this_taskgroup).tg_process = NULL;
			COMPILER_WRITE_BARRIER();
			sync_endwrite(&FORTASK(leader, this_taskgroup).tg_proc_threads_lock);
			decref_nokill(leader); /* The reference that had already been stored in
			                        * `FORTASK(self, this_taskgroup).tg_process' */
			decref_nokill(pid);    /* The reference that had been created for the child chain */
			pending_rpc_free(exit_rpc);
			return false;
		}
		ATOMIC_WRITE(pid->tp_siblings.le_next, next);
	} while (!ATOMIC_CMPXCH_WEAK(FORTASK(leader, this_taskgroup).tg_proc_threads.lh_first, next, pid));
	if unlikely(next != NULL)
		next->tp_siblings.le_prev = &pid->tp_siblings.le_next;
	sync_endwrite(&FORTASK(leader, this_taskgroup).tg_proc_threads_lock);
	return true;
}

/* Initialize the `self' to be the leader of a new process, using `parent' as leader.
 * When   `parent'   is   `NULL',   initialize   `self'   as   a   detached  process.
 * @param: parent:  The parent of the process
 * @param: group:   A thread  apart  of  some process  group  that  `self' should  be  apart  of.
 *                  When `NULL' or equal to `self', initialize `self' as a its own process group.
 *                  In  this case, the process group will be  set to be apart of the session that
 *                  the given `session' is  apart of, or  `self' in case  `session' is `NULL'  or
 *                  equal to `self'.
 * @param: session: Some thread apart of the a session that a new process group should be made
 *                  apart of.
 * NOTE: This function or `task_setthread()' may only be called once for any given thread.
 *       Also note  that  these  functions  must  _NOT_  be  called  for  kernel  threads!
 * NOTE: This function must be called _AFTER_ `task_setpid(self)' has already been invoked! */
PUBLIC ATTR_RETNONNULL NONNULL((1)) struct task *KCALL
task_setprocess(struct task *__restrict self,
                struct task *parent,
                struct task *group,
                struct task *session)
		THROWS(E_WOULDBLOCK) {
	struct taskpid *pid = FORTASK(self, this_taskpid);
	assertf(pid, "Must call `task_setpid()' before `task_setthread()'");
	assertf(FORTASK(self, this_taskgroup).tg_process == NULL,
	        "`task_setthread()' and `task_setprocess()' may only be called once");
	assertf(!(self->t_flags & TASK_FKERNTHREAD),
	        "`task_setthread()' and `task_setprocess()' may not be used with kernel threads");
	FORTASK(self, this_taskgroup).tg_process = self; /* We're our own process */
	if (!group || group == self) {
		REF struct taskpid *grouppid;
		REF struct taskpid *sessionpid;
		/* Create a new process group. */
		if (!session)
			sessionpid = incref(pid);
		else {
			sessionpid = task_getsessionleaderpid_of(session);
		}
		assert(sessionpid);
		grouppid = incref(FORTASK(self, this_taskpid));
		FORTASK(self, this_taskgroup).tg_proc_group = grouppid; /* Inherit reference */
		DBG_memset(&FORTASK(self, this_taskgroup).tg_proc_group_siblings, 0xcc,
		           sizeof(FORTASK(self, this_taskgroup).tg_proc_group_siblings));
		LIST_INIT(&FORTASK(self, this_taskgroup).tg_pgrp_processes);
		FORTASK(self, this_taskgroup).tg_pgrp_session = sessionpid; /* Inherit reference */
	} else {
		REF struct taskpid *grouppid;
		/* Add to an existing process group. */
		grouppid = task_getprocessgroupleaderpid_of(group);
		/* Take  special care to  properly handle joining a
		 * process group where the leader has already died. */
		group = taskpid_gettask(grouppid);
		if (group) {
			TRY {
				sync_write(&FORTASK(group, this_taskgroup).tg_pgrp_processes_lock);
			} EXCEPT {
				decref_unlikely(group);
				decref_unlikely(grouppid);
				RETHROW();
			}
			/* Add the given thread to this process group! */
			LIST_INSERT_HEAD_P(&FORTASK(group, this_taskgroup).tg_pgrp_processes,
			                   self, KEY__this_taskgroup__tg_proc_group_siblings);
			assert(grouppid == FORTASK(group, this_taskpid));
			FORTASK(self, this_taskgroup).tg_proc_group = grouppid; /* Inherit reference */
			sync_endwrite(&FORTASK(group, this_taskgroup).tg_pgrp_processes_lock);
			decref_unlikely(group);
		} else {
			FORTASK(self, this_taskgroup).tg_proc_group = grouppid; /* Inherit reference */
		}
	}
	/* Now to bind the process's parent */
	if (!parent || parent == self) {
		/* Create a detached process. */
		pid->tp_siblings.le_prev = NULL;
		__HYBRID_Q_BADPTR(pid->tp_siblings.le_next);
	} else {
		/* Set the proper parent process. */
		parent = task_getprocess_of(parent);
again_lock_proc_threads_lock:
		sync_write(&FORTASK(parent, this_taskgroup).tg_proc_threads_lock);
		if (!sync_trywrite(&FORTASK(self, this_taskgroup).tg_proc_parent_lock)) {
			sync_endwrite(&FORTASK(parent, this_taskgroup).tg_proc_threads_lock);
			sync_write(&FORTASK(self, this_taskgroup).tg_proc_parent_lock);
			if (!sync_trywrite(&FORTASK(parent, this_taskgroup).tg_proc_threads_lock)) {
				sync_endwrite(&FORTASK(self, this_taskgroup).tg_proc_parent_lock);
				goto again_lock_proc_threads_lock;
			}
		}
		/* Add the given thread to the chain of siblings of the parent process. */
		LIST_INSERT_HEAD(&FORTASK(parent, this_taskgroup).tg_proc_threads, pid, tp_siblings);
		incref(pid); /* The reference stored in the `tg_proc_threads' chain of the parent. */
		FORTASK(self, this_taskgroup).tg_proc_parent = parent; /* Weakly referenced */
		sync_endwrite(&FORTASK(self, this_taskgroup).tg_proc_parent_lock);
		sync_endwrite(&FORTASK(parent, this_taskgroup).tg_proc_threads_lock);
	}
	return self;
}



/* Set the group leader for the process of the given thread.
 * NOTE: If `leader' isn't a process leader, `task_getprocess_of(leader)' will be set used instead.
 * @return: * : One of `TASK_SETPROCESSGROUPLEADER_*' */
PUBLIC NONNULL((1, 2)) unsigned int KCALL
task_setprocessgroupleader(struct task *thread, struct task *leader,
                           /*OUT,OPT*/ REF struct taskpid **pold_group_leader,
                           /*OUT,OPT*/ REF struct taskpid **pnew_group_leader)
		THROWS(E_WOULDBLOCK) {
#ifdef __INTELLISENSE__
	struct taskgroup &thread_taskgroup = FORTASK(thread, this_taskgroup);
	struct taskgroup &leader_taskgroup = FORTASK(leader, this_taskgroup);
#else /* __INTELLISENSE__ */
#define thread_taskgroup FORTASK(thread, this_taskgroup)
#define leader_taskgroup FORTASK(leader, this_taskgroup)
#endif /* !__INTELLISENSE__ */
	struct taskpid *threadpid;
	thread = task_getprocess_of(thread);
	leader = task_getprocess_of(leader);
	assert(task_isprocessleader_p(thread));
	assert(task_isprocessleader_p(leader));
	threadpid = FORTASK(thread, this_taskpid);
	if (thread == leader) {
		struct taskpid *old_group_pid;
again_set_self:
		/* Create a new process group. */
		sync_write(&thread_taskgroup.tg_proc_group_lock);
		old_group_pid = thread_taskgroup.tg_proc_group;
		if (old_group_pid == threadpid) {
			if (pold_group_leader)
				*pold_group_leader = incref(old_group_pid);
			sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
		} else {
			REF struct taskpid *session_pid = NULL;
			{
				REF struct task *old_group;
				old_group = taskpid_gettask(old_group_pid);
				if likely(old_group) {
					/* Figure out which session the new thread group should be apart of
					 * (make  it so that  the thread keeps  its effective, old session) */
					if (!sync_trywrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_session_lock)) {
						sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
						FINALLY_DECREF_UNLIKELY(old_group);
						sync_write(&FORTASK(old_group, this_taskgroup).tg_pgrp_session_lock);
						sync_endwrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_session_lock);
						goto again_set_self;
					}
					session_pid = incref(FORTASK(old_group, this_taskgroup).tg_pgrp_session);
					sync_endwrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_session_lock);

					/* Remove the thread from its old process group. */
					if (!sync_trywrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_processes_lock)) {
						sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
						decref_unlikely(session_pid);
						FINALLY_DECREF_UNLIKELY(old_group);
						sync_write(&FORTASK(old_group, this_taskgroup).tg_pgrp_processes_lock);
						sync_endwrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_processes_lock);
						goto again_set_self;
					}

					/* Remove the given thread from its old group */
					LIST_REMOVE_P(thread, KEY__this_taskgroup__tg_proc_group_siblings);
					sync_endwrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_processes_lock);
					decref_unlikely(old_group);
				}
			}
			/* Setup the given thread to become its own process group. */
			thread_taskgroup.tg_proc_group = incref(threadpid); /* Inherit old reference into `old_group_pid' */
			atomic_rwlock_init(&thread_taskgroup.tg_pgrp_processes_lock);
			atomic_rwlock_init(&thread_taskgroup.tg_pgrp_session_lock);
			DBG_memset(&thread_taskgroup.tg_proc_group_siblings, 0xcc,
			           sizeof(thread_taskgroup.tg_proc_group_siblings));
			LIST_INIT(&thread_taskgroup.tg_pgrp_processes);
			if (!session_pid)
				session_pid = incref(threadpid);
			thread_taskgroup.tg_pgrp_session = session_pid; /* Inherit reference */
			sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
			/* Drop the old reference from `thread_taskgroup.tg_proc_group' */
			if (pold_group_leader)
				*pold_group_leader = old_group_pid;
			else {
				decref_unlikely(old_group_pid);
			}
		}
		if (pnew_group_leader)
			*pnew_group_leader = incref(threadpid);
	} else {
		REF struct taskpid *new_group_leader_pid;
		struct taskpid *old_group_leader_pid;
		/* Add the given thread to an existing process group.
		 * But   first:  Load  the   leader  of  that  group.
		 * Also note that the identity  of that leader is quite  volatile,
		 * since processes are free to change groups as they please, which
		 * is why we keep a reference to the intended leader
		 */
again_set_existing:
		sync_read(&leader_taskgroup.tg_proc_group_lock);
		new_group_leader_pid = incref(leader_taskgroup.tg_proc_group);
		sync_endread(&leader_taskgroup.tg_proc_group_lock);
		TRY {
			/* Add the given thread to specified the process group. */
			sync_write(&thread_taskgroup.tg_proc_group_lock);
		} EXCEPT {
			decref_unlikely(new_group_leader_pid);
			RETHROW();
		}
		/* Load the leader of the old (existing) process group that `thread' is apart of. */
		old_group_leader_pid = thread_taskgroup.tg_proc_group;
		if (old_group_leader_pid == new_group_leader_pid) {
			/* Same group! */
			sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
			if (pold_group_leader)
				*pold_group_leader = incref(new_group_leader_pid);
			if (pnew_group_leader)
				*pnew_group_leader = incref(new_group_leader_pid);
			decref_unlikely(new_group_leader_pid);
		} else {
			REF struct task *new_group_leader; /* [0..1] */
			/* Check if the thread forms its own process group.
			 * If this is the case, it cannot be allowed to be transferred to a different group! */
			if (threadpid == old_group_leader_pid) {
				sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
				decref(new_group_leader_pid);
				return TASK_SETPROCESSGROUPLEADER_LEADER;
			}
			new_group_leader = taskpid_gettask(new_group_leader_pid);
			if unlikely(!new_group_leader) {
				/* Error: The targeted process group has already been terminated! */
				sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
				decref(new_group_leader_pid);
				return TASK_SETPROCESSGROUPLEADER_EXITED;
			}
			if (!sync_trywrite(&FORTASK(new_group_leader, this_taskgroup).tg_pgrp_processes_lock)) {
				sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
				assert(FORTASK(new_group_leader, this_taskpid) == new_group_leader_pid);
				/* Still kept alive through `FORTASK(new_group_leader, this_taskpid)' */
				decref_nokill(new_group_leader_pid);
				{
					FINALLY_DECREF_UNLIKELY(new_group_leader);
					sync_write(&FORTASK(new_group_leader, this_taskgroup).tg_pgrp_processes_lock);
					sync_endwrite(&FORTASK(new_group_leader, this_taskgroup).tg_pgrp_processes_lock);
				}
				goto again_set_existing;
			}
			{
				REF struct task *old_group_leader; /* [0..1] */
				old_group_leader = taskpid_gettask(old_group_leader_pid);
				/* Acquire a lock to the old process group. */
				if (old_group_leader) {
					if (!sync_trywrite(&FORTASK(old_group_leader, this_taskgroup).tg_pgrp_processes_lock)) {
						sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
						sync_endwrite(&FORTASK(new_group_leader, this_taskgroup).tg_pgrp_processes_lock);
						decref_unlikely(new_group_leader);
						decref_unlikely(new_group_leader_pid);
						{
							FINALLY_DECREF_UNLIKELY(old_group_leader);
							sync_write(&FORTASK(old_group_leader, this_taskgroup).tg_pgrp_processes_lock);
							sync_endwrite(&FORTASK(old_group_leader, this_taskgroup).tg_pgrp_processes_lock);
						}
						goto again_set_existing;
					}
				}
				/* At this point we're holding locks:
				 *  - if (old_group_leader) sync_endwrite(FORTASK(old_group_leader, this_taskgroup).tg_pgrp_processes_lock);
				 *  - sync_endwrite(FORTASK(new_group_leader, this_taskgroup).tg_pgrp_processes_lock);
				 *  - sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
				 * And references:
				 *  - xdecref(old_group_leader);
				 *  - decref(new_group_leader);
				 *  - decref(new_group_leader_pid); */
				if (new_group_leader->t_flags & (TASK_FTERMINATING | TASK_FTERMINATED)) {
					/* Error: The targeted process group has already been terminated! */
					if (old_group_leader)
						sync_endwrite(&FORTASK(old_group_leader, this_taskgroup).tg_pgrp_processes_lock);
					sync_endwrite(&FORTASK(new_group_leader, this_taskgroup).tg_pgrp_processes_lock);
					sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
					xdecref(old_group_leader);
					decref(new_group_leader);
					decref(new_group_leader_pid);
					return TASK_SETPROCESSGROUPLEADER_EXITED;
				}
				/* Remove the thread from its old group, and add it to its new group. */
				{
					struct task *new_next;
					new_next = FORTASK(new_group_leader, this_taskgroup).tg_pgrp_processes.lh_first;
					FORTASK(new_group_leader, this_taskgroup).tg_pgrp_processes.lh_first = thread;
					if (old_group_leader) {
						/* Remove  the thread from  its old process  group member chain, and
						 * set up link pointers to be apart of the new group's member chain. */
						LIST_REMOVE_P(thread, KEY__this_taskgroup__tg_proc_group_siblings);
						sync_endwrite(&FORTASK(old_group_leader, this_taskgroup).tg_pgrp_processes_lock);
					}
					thread_taskgroup.tg_proc_group_siblings.le_prev = &FORTASK(new_group_leader, this_taskgroup).tg_pgrp_processes.lh_first;
					if ((thread_taskgroup.tg_proc_group_siblings.le_next = new_next) != NULL)
						FORTASK(new_next, this_taskgroup).tg_proc_group_siblings.le_prev = &thread_taskgroup.tg_proc_group_siblings.le_next;
				}
				thread_taskgroup.tg_proc_group = new_group_leader_pid; /* Inherit reference (x2) */
				sync_endwrite(&FORTASK(new_group_leader, this_taskgroup).tg_pgrp_processes_lock);
				if (pnew_group_leader)
					*pnew_group_leader = incref(new_group_leader_pid);
				sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
				xdecref_unlikely(old_group_leader);
			}
			decref_unlikely(new_group_leader);
			if (pold_group_leader)
				*pold_group_leader = old_group_leader_pid;
			else {
				decref_unlikely(old_group_leader_pid);
			}
		}
#undef old_group_leader_taskgroup
#undef new_group_leader_taskgroup
	}
#undef leader_taskgroup
#undef thread_taskgroup
	return TASK_SETPROCESSGROUPLEADER_SUCCESS;
}



/* Set the session leader for the process group of the given thread.
 * NOTE: If `task_getprocess_of(thread)' isn't already the leader of its own process group
 *      (`task_isprocessgroupleader_p(task_getprocess_of(thread))' is false), a call to
 *       this  function  also implies  `task_setprocessgroupleader(thread,thread)', meaning
 *       that `task_getprocess_of(thread)' is turned into its own process group before that
 *       group is added to the session of `leader', or made to become a new session
 * @param: pold_group_leader:   When non-NULL store a reference to the old process group leader of `task_getprocess_of(thread)'.
 *                              NOTE: The new process group leader of `thread' is always `task_getprocess_of(thread)',
 *                                    since only the  leader of a  process group can  dictate the associated  session.
 * @param: pold_session_leader: When non-NULL store a reference to the old session leader of `task_getprocess_of(thread)'.
 * @param: pnew_session_leader: When non-NULL store a reference to the new session leader of `task_getprocess_of(thread)'.
 * @return: * : One of `TASK_SETSESSIONLEADER_*' */
PUBLIC NONNULL((1, 2)) unsigned int KCALL
task_setsessionleader(struct task *thread, struct task *leader,
                      /*OUT,OPT*/ REF struct taskpid **pold_group_leader,
                      /*OUT,OPT*/ REF struct taskpid **pold_session_leader,
                      /*OUT,OPT*/ REF struct taskpid **pnew_session_leader)
		THROWS(E_WOULDBLOCK) {
	struct taskpid *threadpid;
	REF struct taskpid *new_session_leader;
#ifdef __INTELLISENSE__
	struct taskgroup &thread_taskgroup = FORTASK(thread, this_taskgroup);
#else /* __INTELLISENSE__ */
#define thread_taskgroup FORTASK(thread, this_taskgroup)
#endif /* !__INTELLISENSE__ */
	thread = task_getprocess_of(thread);
	leader = task_getprocess_of(leader);
	assert(task_isprocessleader_p(thread));
	assert(task_isprocessleader_p(leader));
	/* Try to lookup the specified session leader. */
	new_session_leader = task_getsessionleaderpid_of(leader);
	threadpid = FORTASK(thread, this_taskpid);
	TRY {
		struct taskpid *old_group_pid;
again_set_self:
		/* Create a new process group. */
		sync_write(&thread_taskgroup.tg_proc_group_lock);
		old_group_pid = thread_taskgroup.tg_proc_group;
		if (old_group_pid == threadpid) {
			sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
			if (pold_group_leader)
				*pold_group_leader = incref(old_group_pid);
			/* Thread is already a group leader. */
			sync_write(&thread_taskgroup.tg_pgrp_session_lock);
			if (thread_taskgroup.tg_pgrp_session == FORTASK(thread, this_taskpid)) {
				/* The thread is already its own session leader.
				 * -> Only allow setting the thread once again as a no-op, but
				 *    don't allow the session to be changed to something else. */
				if (new_session_leader != FORTASK(thread, this_taskpid)) {
					sync_endwrite(&thread_taskgroup.tg_pgrp_session_lock);
					decref(new_session_leader);
					if (pold_group_leader) {
						assert(*pold_group_leader == old_group_pid);
						decref(old_group_pid); /* The reference already stored in `*pold_group_leader' */
					}
					return TASK_SETSESSIONLEADER_LEADER;
				}
				/* No-op: The thread is its own session leader, and the caller
				 *        requested exactly that to happen again. */
				decref_nokill(new_session_leader);
				sync_endwrite(&thread_taskgroup.tg_pgrp_session_lock);
			} else {
				/* Assign the new session. */
				REF struct taskpid *old_session;
				old_session = thread_taskgroup.tg_pgrp_session;
				thread_taskgroup.tg_pgrp_session = new_session_leader; /* Inherit reference */
				if (pnew_session_leader)
					*pnew_session_leader = incref(new_session_leader);
				sync_endwrite(&thread_taskgroup.tg_pgrp_session_lock);
				if (pold_session_leader)
					*pold_session_leader = old_session; /* Inherit reference */
				else {
					decref(old_session);
				}
			}
		} else {
			REF struct task *old_group;
			old_group = taskpid_gettask(old_group_pid);
			if (pold_session_leader) {
				/* Figure out which session the new thread group should be apart of
				 * (make  it so that  the thread keeps  its effective, old session) */
				if (old_group) {
					if (!sync_trywrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_session_lock)) {
						sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
						FINALLY_DECREF_UNLIKELY(old_group);
						sync_write(&FORTASK(old_group, this_taskgroup).tg_pgrp_session_lock);
						sync_endwrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_session_lock);
						goto again_set_self;
					}
					*pold_session_leader = incref(FORTASK(old_group, this_taskgroup).tg_pgrp_session);
					sync_endwrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_session_lock);
				} else {
					/* Fallback: A process apart of a dead process group uses
					 *           the  dead process group's PID as session PID */
					*pold_session_leader = incref(old_group_pid);
				}
			}

			/* Remove the thread from its old process group. */
			if (old_group) {
				if (!sync_trywrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_processes_lock)) {
					sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
					if (pold_session_leader)
						decref_unlikely(*pold_session_leader);
					FINALLY_DECREF_UNLIKELY(old_group);
					sync_write(&FORTASK(old_group, this_taskgroup).tg_pgrp_processes_lock);
					sync_endwrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_processes_lock);
					goto again_set_self;
				}
				/* Remove the given thread from its old group */
				LIST_REMOVE_P(thread, KEY__this_taskgroup__tg_proc_group_siblings);
				sync_endwrite(&FORTASK(old_group, this_taskgroup).tg_pgrp_processes_lock);
			}
			/* Setup the given thread to become its own process group. */
			thread_taskgroup.tg_proc_group = incref(FORTASK(thread, this_taskpid)); /* Inherit old reference into `old_group' */
			atomic_rwlock_init(&thread_taskgroup.tg_pgrp_processes_lock);
			atomic_rwlock_init(&thread_taskgroup.tg_pgrp_session_lock);
			DBG_memset(&thread_taskgroup.tg_proc_group_siblings, 0xcc,
			           sizeof(thread_taskgroup.tg_proc_group_siblings));
			LIST_INIT(&thread_taskgroup.tg_pgrp_processes);
			thread_taskgroup.tg_pgrp_session = new_session_leader; /* Inherit reference */
			if (pnew_session_leader)
				*pnew_session_leader = incref(new_session_leader);
			sync_endwrite(&thread_taskgroup.tg_proc_group_lock);
			/* Drop the old reference from `thread_taskgroup.tg_proc_group' */
			if (pold_group_leader)
				*pold_group_leader = old_group_pid; /* Inherit reference */
			else {
				decref_unlikely(old_group_pid);
			}
			xdecref_unlikely(old_group);
		}
	} EXCEPT {
		decref(new_session_leader);
		RETHROW();
	}
#undef thread_taskgroup
	return TASK_SETSESSIONLEADER_SUCCESS;
}



/* When  `pn_nextpid'  >=  this value,  start  recycling PIDs.
 * This value can be controlled via `/proc/sys/kernel/pid_max' */
PUBLIC upid_t pid_recycle_threshold = PID_RECYCLE_THRESHOLD_DEFAULT;


/* PIDNS */
INTERN struct pidns_entry empty_pidns_list[1] = {
	{ NULL }
};

/* The root PID namespace. */
PUBLIC struct pidns pidns_root = {
	/* .pn_refcnt      = */ 1,
	/* .pn_indirection = */ 0,
	/* .pn_parent      = */ NULL,
	/* .pn_lock        = */ ATOMIC_RWLOCK_INIT,
	/* .pn_used        = */ 0,
	/* .pn_size        = */ 0,
	/* .pn_mask        = */ 0,
	/* .pn_list        = */ empty_pidns_list,
	/* .pn_dead        = */ NULL,
	/* .pn_nextpid     = */ PIDNS_FIRST_NONRESERVED_PID
};


PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pidns_service_dead)(struct pidns *__restrict self);

PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pidns_do_remove)(struct pidns *__restrict self,
                               struct taskpid *__restrict pid) {
	upid_t pidno;
	uintptr_t i, perturb;
	assert(self->pn_used != 0);
	assert(self->pn_size >= self->pn_used);
	pidno = pid->tp_pids[self->pn_indirection];
	i = perturb = pidno & self->pn_mask;
	for (;; PIDNS_HASHNXT(i, perturb)) {
		assert(self->pn_list[i & self->pn_mask].pe_pid != NULL);
		if (self->pn_list[i & self->pn_mask].pe_pid == pid)
			break; /* Found it! */
	}
	self->pn_list[i & self->pn_mask].pe_pid = PIDNS_ENTRY_DELETED;
	--self->pn_used;
}

PRIVATE NOBLOCK NONNULL((1, 2)) void
NOTHROW(KCALL pidns_remove)(struct pidns *__restrict self,
                            /*inherit(always)*/ struct taskpid *__restrict pid) {
again:
	if (sync_trywrite(self)) {
		pidns_do_remove(self, pid);
		sync_endwrite(self);
		if (self->pn_parent) {
			self = self->pn_parent;
			goto again;
		}
		kfree(pid);
	} else {
		/* Schedule as a pending dead PID */
		struct taskpid *next;
		do {
			next = ATOMIC_READ(self->pn_dead);
			KEY__pidns_dead_next(pid) = next;
		} while (!ATOMIC_CMPXCH_WEAK(self->pn_dead, next, pid));
		if (sync_trywrite(self)) {
			pidns_service_dead(self);
			sync_endwrite(self);
		}
	}
}

#define PIDNS_MUSTSERVICE(self) \
	(ATOMIC_READ((self)->pn_dead) != NULL)
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pidns_service_dead)(struct pidns *__restrict self) {
	struct taskpid *dead, *next;
	dead = ATOMIC_XCH(self->pn_dead, NULL);
	if unlikely(dead) {
		do {
			next = KEY__pidns_dead_next(dead);
			pidns_do_remove(self, dead);
			if (self->pn_parent)
				pidns_remove(self->pn_parent, dead);
			else {
				kfree(dead);
			}
			dead = next;
		} while (dead);
	}
}

PUBLIC NOBLOCK WUNUSED NONNULL((1)) bool
NOTHROW(KCALL pidns_tryread)(struct pidns *__restrict self) {
	bool result = sync_tryread(&self->pn_lock);
	if (result && PIDNS_MUSTSERVICE(self) &&
	    sync_tryupgrade(&self->pn_lock)) {
		pidns_service_dead(self);
		sync_downgrade(&self->pn_lock);
	}
	return result;
}

PUBLIC NOBLOCK WUNUSED NONNULL((1)) bool
NOTHROW(KCALL pidns_trywrite)(struct pidns *__restrict self) {
	bool result = sync_trywrite(&self->pn_lock);
	if (result && PIDNS_MUSTSERVICE(self))
		pidns_service_dead(self);
	return result;
}

PUBLIC NOBLOCK WUNUSED NONNULL((1)) bool
NOTHROW(KCALL pidns_tryupgrade)(struct pidns *__restrict self) {
	bool result = sync_tryupgrade(&self->pn_lock);
	if (result && PIDNS_MUSTSERVICE(self))
		pidns_service_dead(self);
	return result;
}

PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pidns_end)(struct pidns *__restrict self) {
again:
	sync_end(&self->pn_lock);
	if (PIDNS_MUSTSERVICE(self) && sync_trywrite(&self->pn_lock)) {
		pidns_service_dead(self);
		goto again;
	}
}

PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pidns_endread)(struct pidns *__restrict self) {
	sync_endread(&self->pn_lock);
again:
	if (PIDNS_MUSTSERVICE(self) && sync_trywrite(&self->pn_lock)) {
		pidns_service_dead(self);
		sync_endwrite(&self->pn_lock);
		goto again;
	}
}

PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pidns_endwrite)(struct pidns *__restrict self) {
again:
	sync_endwrite(&self->pn_lock);
	if (PIDNS_MUSTSERVICE(self) && sync_trywrite(&self->pn_lock)) {
		pidns_service_dead(self);
		goto again;
	}
}

PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pidns_downgrade)(struct pidns *__restrict self) {
	if (PIDNS_MUSTSERVICE(self)) {
again_service:
		pidns_service_dead(self);
	}
	sync_downgrade(&self->pn_lock);
	if (PIDNS_MUSTSERVICE(self) && sync_tryupgrade(&self->pn_lock))
		goto again_service;
}

PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pidns_tryservice)(struct pidns *__restrict self) {
	if (sync_trywrite(&self->pn_lock)) {
		pidns_service_dead(self);
		sync_endwrite(&self->pn_lock);
	}
}

PUBLIC NONNULL((1)) void KCALL
pidns_read(struct pidns *__restrict self) THROWS(E_WOULDBLOCK) {
	sync_read(&self->pn_lock);
	while (unlikely(PIDNS_MUSTSERVICE(self)) &&
	       sync_tryupgrade(&self->pn_lock)) {
		pidns_service_dead(self);
		sync_downgrade(&self->pn_lock);
	}
}

PUBLIC NONNULL((1)) void KCALL
pidns_write(struct pidns *__restrict self) THROWS(E_WOULDBLOCK) {
	sync_write(&self->pn_lock);
	pidns_service_dead(self);
}

PUBLIC NONNULL((1)) bool KCALL
pidns_upgrade(struct pidns *__restrict self) THROWS(E_WOULDBLOCK) {
	bool result;
	result = sync_upgrade(&self->pn_lock);
	pidns_service_dead(self);
	return result;
}

PUBLIC WUNUSED NONNULL((1)) bool
NOTHROW(KCALL pidns_read_nx)(struct pidns *__restrict self) {
	bool result;
	result = sync_read_nx(&self->pn_lock);
	if
		likely(result)
	{
		while (unlikely(PIDNS_MUSTSERVICE(self)) &&
		       sync_tryupgrade(&self->pn_lock)) {
			pidns_service_dead(self);
			sync_downgrade(&self->pn_lock);
		}
	}
	return result;
}

PUBLIC WUNUSED NONNULL((1)) bool
NOTHROW(KCALL pidns_write_nx)(struct pidns *__restrict self) {
	bool result;
	result = sync_write_nx(&self->pn_lock);
	if
		likely(result)
	pidns_service_dead(self);
	return result;
}

PUBLIC WUNUSED NONNULL((1)) unsigned int
NOTHROW(KCALL pidns_upgrade_nx)(struct pidns *__restrict self) {
	unsigned int result;
	result = sync_upgrade_nx(&self->pn_lock);
	if
		likely(result != 0)
	pidns_service_dead(self);
	return result;
}

PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(KCALL pidns_destroy)(struct pidns *__restrict self) {
	assert(self != &pidns_root);
	assert(self->pn_parent != NULL);
	pidns_service_dead(self);
	assert(self->pn_used == 0);
	if (self->pn_list != empty_pidns_list)
		kfree(self->pn_list);
	decref_unlikely(self->pn_parent);
	kfree(self);
}

/* Allocate a new child PID namespace for `parent' */
PUBLIC ATTR_RETNONNULL NONNULL((1)) REF struct pidns *KCALL
pidns_alloc(struct pidns *__restrict parent) THROWS(E_BADALLOC) {
	REF struct pidns *result;
	result = (REF struct pidns *)kmalloc(sizeof(struct pidns),
	                                     GFP_NORMAL);
	result->pn_refcnt      = 1;
	result->pn_indirection = parent->pn_indirection + 1;
	result->pn_parent      = incref(parent);
	atomic_rwlock_init(&result->pn_lock);
	result->pn_used    = 0;
	result->pn_size    = 0;
	result->pn_mask    = 0;
	result->pn_list    = empty_pidns_list;
	result->pn_nextpid = PIDNS_FIRST_NONRESERVED_PID;
	return result;
}

/* Lookup a given `pid' within the specified PID namespace. */
PUBLIC ATTR_RETNONNULL WUNUSED NONNULL((1)) REF struct taskpid *KCALL
pidns_lookup(struct pidns *__restrict self, upid_t pid)
		THROWS(E_WOULDBLOCK, E_PROCESS_EXITED) {
	REF struct taskpid *result;
	uintptr_t i, perturb;
	sync_read(self);
	i = perturb = pid & self->pn_mask;
	for (;; PIDNS_HASHNXT(i, perturb)) {
		result = self->pn_list[i & self->pn_mask].pe_pid;
		if (result == PIDNS_ENTRY_DELETED)
			continue;
		if unlikely(!result)
			goto dead;
		if (result->tp_pids[self->pn_indirection] != pid)
			continue;
		/* Found it! */
		if (!tryincref(result))
			goto dead;
		break;
	}
	sync_endread(self);
	return result;
dead:
	sync_endread(self);
	THROW(E_PROCESS_EXITED, pid);
}

PUBLIC ATTR_RETNONNULL WUNUSED NONNULL((1)) REF struct task *KCALL
pidns_lookup_task(struct pidns *__restrict self, upid_t pid)
		THROWS(E_WOULDBLOCK, E_PROCESS_EXITED) {
	REF struct task *result;
	REF struct taskpid *respid;
	respid = pidns_lookup(self, pid);
	result = taskpid_gettask(respid);
	decref_unlikely(respid);
	if unlikely(!result)
		THROW(E_PROCESS_EXITED, pid);
	return result;
}

PUBLIC WUNUSED NONNULL((1)) REF struct taskpid *KCALL
pidns_trylookup(struct pidns *__restrict self, upid_t pid)
		THROWS(E_WOULDBLOCK) {
	REF struct taskpid *result;
	uintptr_t i, perturb;
	sync_read(self);
	i = perturb = pid & self->pn_mask;
	for (;; PIDNS_HASHNXT(i, perturb)) {
		result = self->pn_list[i & self->pn_mask].pe_pid;
		if (result == PIDNS_ENTRY_DELETED)
			continue;
		if unlikely(!result)
			break;
		if (result->tp_pids[self->pn_indirection] != pid)
			continue;
		/* Found it! (check if it's dead...) */
		if (!tryincref(result))
			result = NULL;
		break;
	}
	sync_endread(self);
	return result;
}

PUBLIC WUNUSED NONNULL((1)) REF struct task *KCALL
pidns_trylookup_task(struct pidns *__restrict self, upid_t pid)
		THROWS(E_WOULDBLOCK) {
	REF struct task *result;
	REF struct taskpid *respid;
	respid = pidns_trylookup(self, pid);
	if (!respid)
		return NULL;
	result = taskpid_gettask(respid);
	decref_unlikely(respid);
	return result;
}

PUBLIC WUNUSED NONNULL((1)) REF struct taskpid *
NOTHROW(KCALL pidns_trylookup_locked)(struct pidns *__restrict self, upid_t pid) {
	REF struct taskpid *result;
	uintptr_t i, perturb;
	/* Cannot be asserted, since this function is called by the GDB stub,  which
	 * doesn't have to acquire a lock if it had previously suspended everything. */
	/*assert(sync_reading(self));*/
	i = perturb = pid & self->pn_mask;
	for (;; PIDNS_HASHNXT(i, perturb)) {
		result = self->pn_list[i & self->pn_mask].pe_pid;
		if (result == PIDNS_ENTRY_DELETED)
			continue;
		if unlikely(!result)
			break;
		if (result->tp_pids[self->pn_indirection] != pid)
			continue;
		/* Found it! (check if it's dead...) */
		if (!tryincref(result))
			result = NULL;
		break;
	}
	return result;
}

PUBLIC WUNUSED NONNULL((1)) REF struct task *
NOTHROW(KCALL pidns_trylookup_task_locked)(struct pidns *__restrict self, upid_t pid) {
	REF struct task *result;
	REF struct taskpid *respid;
	respid = pidns_trylookup_locked(self, pid);
	if (!respid)
		return NULL;
	result = taskpid_gettask(respid);
	decref_unlikely(respid);
	return result;
}



PRIVATE NOBLOCK void
NOTHROW(KCALL pidns_install_list)(struct pidns *__restrict self,
                                  struct pidns_entry *__restrict new_list,
                                  size_t new_mask) {
	if (self->pn_list == empty_pidns_list) {
		assert(self->pn_mask == 0);
		assert(self->pn_used == 0);
		assert(self->pn_size == 0);
		self->pn_list = new_list;
		self->pn_mask = new_mask;
	} else {
		/* Rehash existing entries. */
		size_t i, j, perturb;
		for (i = 0; i <= self->pn_mask; ++i) {
			struct pidns_entry *dst;
			struct taskpid *pid;
			upid_t pidno;
			pid = self->pn_list[i].pe_pid;
			if (!pid || pid == PIDNS_ENTRY_DELETED)
				continue; /* Empty, or deleted. */
			pidno = pid->tp_pids[self->pn_indirection];
			j = perturb = pidno & new_mask;
			for (;; PIDNS_HASHNXT(j, perturb)) {
				dst = &new_list[j & new_mask];
				if (!dst->pe_pid)
					break;
			}
			dst->pe_pid = pid; /* Rehash */
		}
		kfree(self->pn_list);
		self->pn_list = new_list;
		self->pn_mask = new_mask;
		self->pn_size = self->pn_used; /* All deleted entries were removed... */
	}
}

/* Rehash the given pidns if necessary, so-as to prepare it
 * for  allowing  a   new  `struct taskpid'  being   added.
 * This function will never  block, or throw an  exception. - If preparation  fails,
 * `false' is returned, and the caller is expected to use `pidns_prepare_for_insert'
 * in order to forcibly prepare the PIDns (which the also allows for blocking) */
PRIVATE NOBLOCK bool
NOTHROW(KCALL pidns_prepare_for_insert_nx)(struct pidns *__restrict self) {
	if (((self->pn_size + 1) * 3) / 2 >= self->pn_mask) {
		/* Must rehash! */
		struct pidns_entry *new_list;
		size_t new_mask = 7;
		size_t thresh   = ((self->pn_used + 1) * 3) / 2;
		while (thresh >= new_mask)
			new_mask = (new_mask << 1) | 1;
		new_list = (struct pidns_entry *)kmalloc_nx((new_mask + 1) * sizeof(struct pidns_entry),
		                                            GFP_ATOMIC | GFP_CALLOC);
		if unlikely(!new_list)
			return (self->pn_size + 1) <= self->pn_mask;
		/* Install the new list */
		pidns_install_list(self, new_list, new_mask);
		assert(self->pn_used == self->pn_size);
	}
	return true;
}

PRIVATE void KCALL
pidns_prepare_for_insert(struct pidns *__restrict self)
		THROWS(E_WOULDBLOCK, E_BADALLOC) {
	if (((self->pn_size + 1) * 3) / 2 >= self->pn_mask) {
		/* Must rehash! */
		struct pidns_entry *new_list;
		size_t new_mask = 7;
		size_t thresh   = ((self->pn_used + 1) * 3) / 2;
		while (thresh >= new_mask)
			new_mask = (new_mask << 1) | 1;
		TRY {
			new_list = (struct pidns_entry *)kmalloc((new_mask + 1) * sizeof(struct pidns_entry),
			                                         GFP_NORMAL | GFP_CALLOC);
		} EXCEPT {
			if (!was_thrown(E_BADALLOC))
				RETHROW();
			if ((self->pn_size + 1) <= self->pn_mask)
				return; /* Still enough space... */
			RETHROW();
		}
		/* Install the new list */
		pidns_install_list(self, new_list, new_mask);
		assert(self->pn_used == self->pn_size);
	}
}


/* Allocate and return the next PID from `self' */
LOCAL NOBLOCK WUNUSED NONNULL((1, 2)) upid_t
NOTHROW(FCALL pidns_nextpid)(struct pidns *__restrict self,
                             upid_t *__restrict pminpid) {
	upid_t result;
	result = self->pn_nextpid++;
	if unlikely(result >= pid_recycle_threshold) {
		/* Recycle PIDs */
		result           = *pminpid;
		self->pn_nextpid = *pminpid + 1;
		/* This prevents us  from getting stuck  in an infinite  loop
		 * when some genius set the value in /proc/sys/kernel/pid_max
		 * too low. */
		++*pminpid;
	}
	return result;
}


/* Allocate a `struct taskpid' for `self' (which must not have  been
 * started yet, or have its taskpid already allocated), and register
 * that task within the given pidns `ns'
 * This function should be called after `task_alloc()', but before `task_start()'
 * WARNING: This   function   may  only   be   called  _ONCE_   for   each  task!
 * @param: ns_pid: The  PID  to  try to  assign  to `self'  within  the namespace.
 *                 When ZERO(0),  or already  in  use, sequentially  generate  IDs
 *                 Also note  that  this PID  is  only  set for  `self'  in  `ns'.
 *                 All underlying namespaces _always_ have their PIDs sequentially
 *                 generated.
 * @return: * : Always re-returns `self' */
PUBLIC ATTR_RETNONNULL NONNULL((1, 2)) struct task *KCALL
task_setpid(struct task *__restrict self,
            struct pidns *__restrict ns,
            upid_t ns_pid)
		THROWS(E_WOULDBLOCK, E_BADALLOC) {
	upid_t minpid = PIDNS_FIRST_NONRESERVED_PID;
	REF struct taskpid *pid;
	struct pidns *ns_iter, *ns_altiter;
	assert(!FORTASK(self, this_taskpid));
	/* Step #1: Allocate the PID descriptor */
	pid = (REF struct taskpid *)kmalloc(offsetof(struct taskpid, tp_pids) +
	                                    ((ns->pn_indirection + 1) * sizeof(upid_t)),
	                                    GFP_NORMAL);
	TRY {
		/* Step #2: Acquire write-locks to all of the PID namespaces in which we want to allocate,
		 *          as  well  as  prepare  all of  them  for  the  addition of  a  new  PID entry. */
restart_acquire_locks:
		ns_iter = ns;
		do {
			if (!sync_trywrite(ns_iter) ||
			    !pidns_prepare_for_insert_nx(ns_iter)) {
				/* Release all previously acquired locks. */
				for (ns_altiter = ns; ns_altiter != ns_iter;
				     ns_altiter = ns_altiter->pn_parent)
					sync_endwrite(ns_altiter);
				/* Forceably acquire a lock to `ns_iter' */
				{
					SCOPED_WRITELOCK(ns_iter);
					pidns_prepare_for_insert(ns_iter);
				}
				goto restart_acquire_locks;
			}
		} while ((ns_iter = ns_iter->pn_parent) != NULL);
	} EXCEPT {
		kfree(pid);
		RETHROW();
	}
	/* register the new taskpid structure within the namespaces. */
	ns_iter = ns;
	do {
		struct pidns_entry *ent, *candidate;
		uintptr_t i, perturb;
		assert(ns_iter->pn_parent
		       ? ns_iter->pn_parent->pn_indirection == ns_iter->pn_indirection - 1
		       : ns_iter->pn_indirection == 0 && ns_iter == &pidns_root);
		if (ns_pid == 0) {
next_pid:
			/* Generate the next sequential PID */
			ns_pid = pidns_nextpid(ns_iter, &minpid);
		}
		/* Try to install the taskpid structure under this PID */
		assert(ns_iter->pn_mask > 0);
		i = perturb = ns_pid & ns_iter->pn_mask;
		candidate   = NULL;
		for (;; PIDNS_HASHNXT(i, perturb)) {
			ent = &ns_iter->pn_list[i & ns_iter->pn_mask];
			if (!ent->pe_pid)
				break;
			if (ent->pe_pid == PIDNS_ENTRY_DELETED) {
				if (!candidate)
					candidate = ent;
				continue;
			}
			if (ent->pe_pid->tp_pids[ns_iter->pn_indirection] == ns_pid)
				goto next_pid; /* Already in use... */
		}
		if (candidate) {
			ent = candidate;
		} else {
			++ns_iter->pn_size; /* New entry (not one that was previously deleted) */
		}
		++ns_iter->pn_used;
		assert(ns_iter->pn_used <= ns_iter->pn_size);
		assert(ns_iter->pn_size <= ns_iter->pn_mask);
		/* Initialize the PID binding within this namespace. */
		pid->tp_pids[ns_iter->pn_indirection] = ns_pid;
		ent->pe_pid = pid;
		ns_pid = 0; /* Use a sequential PID during the next pass. */
	} while ((ns_iter = ns_iter->pn_parent) != NULL);

	/* Install the `struct taskpid' to be apart of the given thread. */
	pid->tp_refcnt = 1;
	awref_init(&pid->tp_thread, self);
	sig_init(&pid->tp_changed);
	LIST_ENTRY_UNBOUND_INIT(&pid->tp_siblings);
	pid->tp_pidns = incref(ns);
	COMPILER_WRITE_BARRIER();

	assert(!FORTASK(self, this_taskpid));
	FORTASK(self, this_taskpid) = pid; /* Inherit reference */

	/* Release our locks to all of the namespaces. */
	ns_iter = ns;
	do {
		sync_endwrite(ns_iter);
	} while ((ns_iter = ns_iter->pn_parent) != NULL);
	return self;
}


INTERN ATTR_FREETEXT void
NOTHROW(KCALL kernel_initialize_bootpid)(void) {
	struct taskgroup *grp;
	/* Assign PID #1 of the root PID namespace to the boot task. */
	task_setpid(&boottask, &pidns_root, 1);
	grp = &FORTASK(&boottask, this_taskgroup);
	grp->tg_process      = &boottask; /* the boot task is a process */
	grp->tg_proc_group   = incref(FORTASK(&boottask, this_taskpid)); /* the boot task is a process group */
	grp->tg_pgrp_session = incref(FORTASK(&boottask, this_taskpid)); /* the boot task is a session */
}





/************************************************************************/
/* gettid(), getpid(), getppid(), getpgrp(), getpgid()                  */
/* setpgid(), getsid(), setsid()                                        */
/************************************************************************/
#ifdef __ARCH_WANT_SYSCALL_GETTID
DEFINE_SYSCALL0(pid_t, gettid) {
	COMPILER_IMPURE();
	return task_gettid();
}
#endif /* __ARCH_WANT_SYSCALL_GETTID */

#ifdef __ARCH_WANT_SYSCALL_GETPID
DEFINE_SYSCALL0(pid_t, getpid) {
	COMPILER_IMPURE();
	return task_getpid();
}
#endif /* __ARCH_WANT_SYSCALL_GETPID */

#ifdef __ARCH_WANT_SYSCALL_GETPPID
DEFINE_SYSCALL0(pid_t, getppid) {
	upid_t result;
	REF struct task *parent;
	parent = task_getprocessparent();
	if unlikely(!parent)
		return 0;
	result = task_gettid_of(parent);
	decref_unlikely(parent);
	return (pid_t)result;
}
#endif /* __ARCH_WANT_SYSCALL_GETPPID */

#ifdef __ARCH_WANT_SYSCALL_GETPGRP
DEFINE_SYSCALL0(pid_t, getpgrp) {
	/* Same as `getpgid(0)' */
	upid_t result;
	REF struct task *group;
	group  = task_getprocessgroupleader_srch();
	result = task_gettid_of(group);
	decref_unlikely(group);
	return (pid_t)result;
}
#endif /* __ARCH_WANT_SYSCALL_GETPGRP */

#ifdef __ARCH_WANT_SYSCALL_GETPGID
DEFINE_SYSCALL1(pid_t, getpgid, pid_t, pid) {
	upid_t result;
	REF struct task *group;
	if (pid == 0) {
		group = task_getprocessgroupleader_srch();
	} else {
		REF struct task *temp;
		temp = pidns_lookup_task(THIS_PIDNS, (upid_t)pid);
		{
			FINALLY_DECREF_UNLIKELY(temp);
			group = task_getprocessgroupleader_srch_of(temp);
		}
	}
	result = task_gettid_of(group);
	decref_unlikely(group);
	return (pid_t)result;
}
#endif /* __ARCH_WANT_SYSCALL_GETPGID */

#ifdef __ARCH_WANT_SYSCALL_SETPGID
DEFINE_SYSCALL2(errno_t, setpgid, pid_t, pid, pid_t, pgid) {
	REF struct task *thread, *group;
	unsigned int error;
	if ((upid_t)pid == 0) {
		thread = THIS_TASK;
		if ((upid_t)pgid == 0) {
			task_setprocessgroupleader(thread, thread);
		} else {
			group = pidns_lookup_task(THIS_PIDNS, (upid_t)pgid);
			{
				FINALLY_DECREF_UNLIKELY(group);
				error = task_setprocessgroupleader(thread, group);
			}
handle_error:
			if (error == TASK_SETPROCESSGROUPLEADER_EXITED)
				THROW(E_PROCESS_EXITED, (upid_t)pgid);
			if (error == TASK_SETPROCESSGROUPLEADER_LEADER) {
				THROW(E_ILLEGAL_PROCESS_OPERATION,
				      E_ILLEGAL_OPERATION_CONTEXT_SETPGID_LEADER,
				      (upid_t)pid, (upid_t)pgid);
			}
		}
	} else {
		REF struct task *thread;
		thread = pidns_lookup_task(THIS_PIDNS, (upid_t)pid);
		FINALLY_DECREF_UNLIKELY(thread);
		if ((upid_t)pgid == 0 || (upid_t)pgid == (upid_t)pid) {
			task_setprocessgroupleader(thread, thread);
		} else {
			group = pidns_lookup_task(THIS_PIDNS, (upid_t)pgid);
			{
				FINALLY_DECREF_UNLIKELY(group);
				error = task_setprocessgroupleader(thread, group);
			}
			goto handle_error;
		}
	}
	return -EOK;
}
#endif /* __ARCH_WANT_SYSCALL_SETPGID */

#ifdef __ARCH_WANT_SYSCALL_GETSID
DEFINE_SYSCALL1(pid_t, getsid, pid_t, pid) {
	upid_t result;
	REF struct task *session;
	if ((upid_t)pid == 0) {
		session = task_getsessionleader_srch();
	} else {
		REF struct task *temp;
		temp = pidns_lookup_task(THIS_PIDNS, (upid_t)pid);
		FINALLY_DECREF_UNLIKELY(temp);
		session = task_getsessionleader_srch_of(temp);
	}
	result = task_gettid_of(session);
	decref_unlikely(session);
	return (pid_t)result;
}
#endif /* __ARCH_WANT_SYSCALL_GETSID */

#ifdef __ARCH_WANT_SYSCALL_SETSID
DEFINE_SYSCALL0(pid_t, setsid) {
	struct task *me = THIS_TASK;
	/* Set the calling process to become its own session. */
	task_setsessionleader(me, me);
	return (pid_t)task_getpid();
}
#endif /* __ARCH_WANT_SYSCALL_SETSID */




/* Detach the given `thread' from its parent
 * @return: true:  Successfully detached the given `thread'.
 * @return: false: The given `thread' had already been detached. */
PUBLIC bool KCALL
task_detach(struct task *__restrict thread)
		THROWS(E_WOULDBLOCK) {
	struct taskpid *pid;
	struct task *process;
	pid = FORTASK(thread, this_taskpid);
	COMPILER_READ_BARRIER();
	if (!LIST_ISBOUND(pid, tp_siblings))
		return false; /* Already detached. */
	process = FORTASK(thread, this_taskgroup).tg_process;
	if (thread == process) {
		struct task *parent;
		/* Detach from the parent process. */
again_acquire_parent_lock:
		sync_write(&FORTASK(thread, this_taskgroup).tg_proc_parent_lock);
		parent = FORTASK(thread, this_taskgroup).tg_proc_parent;
		if (!parent || wasdestroyed(parent)) {
parent_is_dead:
			sync_endwrite(&FORTASK(thread, this_taskgroup).tg_proc_parent_lock);
			/* The parent process has already died. */
			return false;
		}
		if (!sync_trywrite(&FORTASK(parent, this_taskgroup).tg_proc_threads_lock)) {
			if (!tryincref(parent))
				goto parent_is_dead;
			sync_endwrite(&FORTASK(thread, this_taskgroup).tg_proc_parent_lock);
			/* Wait for the parent's child-thread-lock to become available. */
			{
				FINALLY_DECREF_UNLIKELY(parent);
				sync_write(&FORTASK(parent, this_taskgroup).tg_proc_threads_lock);
				sync_endwrite(&FORTASK(parent, this_taskgroup).tg_proc_threads_lock);
			}
			/* Start over by acquiring the parent-lock of the given thread. */
			goto again_acquire_parent_lock;
		}
		if (LIST_ISBOUND(pid, tp_siblings)) {
			LIST_UNBIND(pid, tp_siblings);

			/* Delete the parent link within our own process. */
			FORTASK(thread, this_taskgroup).tg_proc_parent = NULL;
			sync_endwrite(&FORTASK(parent, this_taskgroup).tg_proc_threads_lock);
			sync_endwrite(&FORTASK(thread, this_taskgroup).tg_proc_parent_lock);
			decref_nokill(pid); /* Inherited from the `tp_siblings' chain */
			return true;
		}
		/* Already detached. */
		sync_endwrite(&FORTASK(parent, this_taskgroup).tg_proc_threads_lock);
		sync_endwrite(&FORTASK(thread, this_taskgroup).tg_proc_parent_lock);
		return false;
	}
	/* Update the deatch-state of a child thread. */
	{
		uintptr_t thread_detach_state;
		do {
			thread_detach_state = ATOMIC_READ(FORTASK(thread, this_taskgroup).tg_thread_detached);
			if (thread_detach_state == TASKGROUP_TG_THREAD_DETACHED_TERMINATED) {
				/* Child thread has already terminated (check for manual detach) */
				sync_write(&FORTASK(process, this_taskgroup).tg_proc_threads_lock);
				if (LIST_ISBOUND(pid, tp_siblings)) {
					LIST_UNBIND(pid, tp_siblings);
					sync_endwrite(&FORTASK(process, this_taskgroup).tg_proc_threads_lock);
					decref_nokill(pid); /* Inherited from the `tp_siblings' chain */
					return true;
				}
				sync_endwrite(&FORTASK(process, this_taskgroup).tg_proc_threads_lock);
				return false;
			}
			if (thread_detach_state == TASKGROUP_TG_THREAD_DETACHED_YES)
				return false; /* Child thread was already detached */
		} while (!ATOMIC_CMPXCH_WEAK(FORTASK(thread, this_taskgroup).tg_thread_detached,
		                             thread_detach_state,
		                             TASKGROUP_TG_THREAD_DETACHED_YES));
		/* The thread's detach-state was changed to YES */
		return true;
	}
	return false;
}

/* Detach all child threads/processes of the given `process'
 * @assume(process == task_getprocess_of(process));
 * @return: * : The number of detached children. */
PUBLIC size_t KCALL
task_detach_children(struct task *__restrict process)
		THROWS(E_WOULDBLOCK) {
	struct taskpid *iter;
	size_t result = 0;
#ifdef __INTELLISENSE__
	struct taskgroup &procgroup = FORTASK(process, this_taskgroup);
#else /* __INTELLISENSE__ */
#define procgroup FORTASK(process, this_taskgroup)
#endif /* !__INTELLISENSE__ */
	assert(process == task_getprocess_of(process));

	/* Detach all child threads. */
again:
	sync_write(&procgroup.tg_proc_threads_lock);
	iter = LIST_FIRST(&procgroup.tg_proc_threads);
continue_with_iter:
	for (; iter; iter = LIST_NEXT(iter, tp_siblings)) {
		if (!wasdestroyed(iter))
			break;
	}
	if (iter) {
		if (awref_ptr(&iter->tp_thread) != NULL) {
			/* Must unlink the parent-link of child processes. */
			REF struct task *child_thread;
			child_thread = awref_get(&iter->tp_thread);
			if likely(child_thread) {
				if (FORTASK(child_thread, this_taskgroup).tg_process != child_thread) {
					/* Child thread! */
					uintptr_t thread_detach_state;
					for (;;) {
						thread_detach_state = ATOMIC_READ(FORTASK(child_thread, this_taskgroup).tg_thread_detached);
						if (thread_detach_state == TASKGROUP_TG_THREAD_DETACHED_TERMINATED)
							goto detach_manually; /* Child thread has already terminated (detach manually) */
						if (thread_detach_state == TASKGROUP_TG_THREAD_DETACHED_YES)
							break;
						if (!ATOMIC_CMPXCH_WEAK(FORTASK(child_thread, this_taskgroup).tg_thread_detached,
						                        thread_detach_state,
						                        TASKGROUP_TG_THREAD_DETACHED_YES))
							continue;
						/* Changed a child thread to become detached! */
						++result;
						break;
					}
					decref_unlikely(child_thread);
					goto continue_with_iter;
				}
				/* Child process! */
				if (!sync_trywrite(&FORTASK(child_thread, this_taskgroup).tg_proc_parent_lock)) {
					sync_endwrite(&procgroup.tg_proc_threads_lock);
					{
						FINALLY_DECREF_UNLIKELY(child_thread);
						sync_write(&FORTASK(child_thread, this_taskgroup).tg_proc_parent_lock);
					}
					sync_endwrite(&FORTASK(child_thread, this_taskgroup).tg_proc_parent_lock);
					goto again;
				}
				assert(FORTASK(child_thread, this_taskgroup).tg_proc_parent == process);
				FORTASK(child_thread, this_taskgroup).tg_proc_parent = NULL;
				sync_endwrite(&FORTASK(child_thread, this_taskgroup).tg_proc_parent_lock);
				decref_unlikely(child_thread);
			}
		}
		/* Detach the child thread */
detach_manually:
		LIST_UNBIND(iter, tp_siblings);
		sync_endwrite(&procgroup.tg_proc_threads_lock);
		/* Drop the reference previously held by our `tp_siblings' chain. */
		decref(iter);
		++result;
		goto again;
	}
	sync_endwrite(&procgroup.tg_proc_threads_lock);
	return result;
#undef procgroup
}





/************************************************************************/
/* detach()                                                             */
/************************************************************************/
#ifdef __ARCH_WANT_SYSCALL_DETACH
DEFINE_SYSCALL1(errno_t, detach, pid_t, pid) {
	errno_t result = -EPERM;
	struct task *proc           = task_getprocess();
	struct taskgroup *procgroup = &FORTASK(proc, this_taskgroup);
	struct taskpid *mypid       = THIS_TASKPID;
	REF struct taskpid *tpid;
	struct taskpid *iter;
	/* Check for special case: `detach(0)' (daemonize the calling thread) */
	if (!pid) {
		/* Detach the calling thread. */
do_detach_self:
		if (task_detach(THIS_TASK))
			result = -EOK;
		goto done;
	}
	if (pid == -1) {
		/* Detach all child threads. */
		if (task_detach_children(proc))
			result = -EOK;
		goto done;
	}
	tpid = pidns_lookup(mypid->tp_pidns, (upid_t)pid);
	/* Check for special case: `detach(gettid())' (daemonize the calling thread) */
	if (tpid == THIS_TASKPID) {
		/* Detach the calling thread. */
		decref_nokill(tpid);
		goto do_detach_self;
	}
	/* Check for special case: `detach(getpid())' (daemonize the calling process) */
	if (tpid == FORTASK(proc, this_taskpid)) {
		decref_nokill(tpid);
		if (task_detach(proc))
			result = -EOK;
		goto done;
	}

	{
		FINALLY_DECREF_UNLIKELY(tpid);
		/* Go through the list of children of this process. */
again:
		sync_write(&procgroup->tg_proc_threads_lock);
		LIST_FOREACH (iter, &procgroup->tg_proc_threads, tp_siblings) {
			REF struct task *tpid_thread;
			if (iter != tpid)
				continue;
			/* Found it! */
			tpid_thread = awref_get(&tpid->tp_thread);
			if (tpid_thread) {
				FINALLY_DECREF_UNLIKELY(tpid_thread);
				if (!task_isprocessleader_p(tpid_thread)) {
					/* Detach a child thread. */
					uintptr_t thread_detach_state;
					for (;;) {
						thread_detach_state = ATOMIC_READ(FORTASK(tpid_thread, this_taskgroup).tg_thread_detached);
						if (thread_detach_state == TASKGROUP_TG_THREAD_DETACHED_TERMINATED)
							goto detach_manually; /* Child thread has already terminated (detach manually) */
						if (thread_detach_state == TASKGROUP_TG_THREAD_DETACHED_YES)
							break; /* Already detached. */
						if (!ATOMIC_CMPXCH_WEAK(FORTASK(tpid_thread, this_taskgroup).tg_thread_detached,
						                        thread_detach_state,
						                        TASKGROUP_TG_THREAD_DETACHED_YES))
							continue;
						/* Changed a child thread to become detached! */
						result = -EOK;
						break;
					}
					sync_endwrite(&procgroup->tg_proc_threads_lock);
					goto done;
				}
				/* We're dealing with another process here, meaning we also have
				 * to   delete  the  target  process's  `tg_proc_parent'  field. */
				if (!sync_trywrite(&FORTASK(tpid_thread, this_taskgroup).tg_proc_parent_lock)) {
					sync_endwrite(&procgroup->tg_proc_threads_lock);
					sync_write(&FORTASK(tpid_thread, this_taskgroup).tg_proc_parent_lock);
					sync_endwrite(&FORTASK(tpid_thread, this_taskgroup).tg_proc_parent_lock);
					goto again;
				}
				assert(FORTASK(tpid_thread, this_taskgroup).tg_proc_parent == THIS_TASK);
				FORTASK(tpid_thread, this_taskgroup).tg_proc_parent = NULL;
				sync_endwrite(&FORTASK(tpid_thread, this_taskgroup).tg_proc_parent_lock);
			}
detach_manually:
			/* Unbind the thread's PID from our chain of children. */
			LIST_UNBIND(iter, tp_siblings);
			sync_endwrite(&procgroup->tg_proc_threads_lock);
			decref(iter); /* The reference previously contained within the `tg_proc_threads' chain */
			result = -EOK;
			goto done;
		}
		sync_endwrite(&procgroup->tg_proc_threads_lock);
	}
done:
	return result;
}
#endif /* __ARCH_WANT_SYSCALL_DETACH */




/************************************************************************/
/* waitid(), waitpid(), wait4()                                         */
/************************************************************************/
#if (defined(__ARCH_WANT_SYSCALL_WAITID) ||         \
     defined(__ARCH_WANT_SYSCALL_WAITPID) ||        \
     defined(__ARCH_WANT_SYSCALL_WAIT4) ||          \
     defined(__ARCH_WANT_COMPAT_SYSCALL_WAITID) ||  \
     defined(__ARCH_WANT_COMPAT_SYSCALL_WAITPID) || \
     defined(__ARCH_WANT_COMPAT_SYSCALL_WAIT4))
#define WANT_WAIT 1
#endif

#ifdef WANT_WAIT
LOCAL NOBLOCK bool
NOTHROW(KCALL is_taskpid_terminating)(struct taskpid *__restrict self) {
	bool result = true;
	REF struct task *thread;
	thread = awref_get(&self->tp_thread);
	if likely(thread) {
		result = (thread->t_flags & (TASK_FTERMINATING |
		                             TASK_FTERMINATED)) != 0;
		decref_unlikely(thread);
	}
	return result;
}

PRIVATE pid_t KCALL
posix_waitfor(idtype_t which,
              id_t upid,
              USER CHECKED int32_t *wstatus,
              USER CHECKED siginfo_t *infop,
              syscall_ulong_t options,
              USER CHECKED struct rusage *ru) {
	struct taskpid *child;
	struct task *proc = task_getprocess();
#ifdef __INTELLISENSE__
	struct taskgroup &mygroup = FORTASK(proc, this_taskgroup);
#else /* __INTELLISENSE__ */
#define mygroup FORTASK(proc, this_taskgroup)
#endif /* !__INTELLISENSE__ */
	assert(!PERTASK_TESTMASK(this_task.t_flags, TASK_FKERNTHREAD));
	/* Check for special behavior when SIGCLD is being ignored. */
	{
		struct sighand_ptr *handptr;
		handptr = THIS_SIGHAND_PTR;
		if (handptr) {
			struct sighand *hand;
			hand = sighand_ptr_lockread(handptr);
			if likely(hand) {
				if ((hand->sh_actions[SIGCLD - 1].sa_flags & SA_NOCLDWAIT) ||
				    (hand->sh_actions[SIGCLD - 1].sa_handler == SIG_IGN &&
				     !(hand->sh_actions[SIGCLD - 1].sa_flags & SA_SIGINFO))) {
					sync_endread(hand);
					/* Block until  all child  processes have  exited
					 * and reap all zombies created in the mean time.
					 * Then, fail with -ECHILD. */
reapall_again:
					task_connect_for_poll(&mygroup.tg_proc_threads_change);
reapall_check:
					TRY {
						sync_read(&mygroup.tg_proc_threads_lock);
reapall_check_already_locked:
						child = LIST_FIRST(&mygroup.tg_proc_threads);
						if (!child) {
							sync_end(&mygroup.tg_proc_threads_lock);
							if (task_receiveall())
								goto reapall_again;
							return -ECHILD;
						}
						if (!(options & WNOREAP)) {
							for (; child; child = LIST_NEXT(child, tp_siblings)) {
								if (is_taskpid_terminating(child)) {
									/* Detach (reap) this child. */
									if (!sync_writing(&mygroup.tg_proc_threads_lock) &&
									    !sync_upgrade(&mygroup.tg_proc_threads_lock))
										goto reapall_check_already_locked;
									LIST_UNBIND(child, tp_siblings); /* Inherit reference. */
									sync_endwrite(&mygroup.tg_proc_threads_lock);
									decref(child);
									goto reapall_check;
								}
							}
						}
						sync_end(&mygroup.tg_proc_threads_lock);
					} EXCEPT {
						task_disconnectall();
						RETHROW();
					}
					if (options & WNOHANG) {
						if (task_receiveall())
							goto reapall_again;
						return -ECHILD; /* I feel like this should be EAGAIN, but  POSIX
						                 * says that wait() doesn't return that error... */
					}
					/* Wait for more state-change signals. */
					task_waitfor();
					goto reapall_again;
				}
				sync_endread(hand);
			}
		}
	}

	{
		size_t num_candidates;
again_connect_enum_children:
		/* Connect to the child-changed signal. */
		task_connect_for_poll(&mygroup.tg_proc_threads_change);
		TRY {
			size_t my_indirection;
			my_indirection = THIS_TASKPID->tp_pidns->pn_indirection;

			/* Enumerate child processes. */
again_enum_children:
			sync_read(&mygroup.tg_proc_threads_lock);
again_enum_children_locked:
			num_candidates = 0;
			LIST_FOREACH (child, &mygroup.tg_proc_threads, tp_siblings) {
				REF struct task *child_thread;
				if (which == P_PID) {
					if (child->tp_pids[my_indirection] != upid)
						continue;
				}
				if (which == P_PGID) {
					child_thread = awref_get(&child->tp_thread);
					/* XXX: We're not  tracking the  PGID in  the PID  descriptor,
					 *      but apparently POSIX wants  us to remember a  thread's
					 *      process  group,  even  after  the  thread  has died...
					 *      As a kind-of crappy  work-around, right now we  simply
					 *      ignore the child's PGID if the thread has already been
					 *      destroyed. */
					if (child_thread) {
						struct task *child_proc;
						struct taskpid *child_group_pid;
						bool is_group;
						child_proc = task_getprocess_of(child_thread);
						if (!sync_tryread(&FORTASK(child_proc, this_taskgroup).tg_proc_group_lock)) {
							incref(child_proc);
							sync_end(&mygroup.tg_proc_threads_lock);
							decref(child_thread);
							{
								FINALLY_DECREF_UNLIKELY(child_proc);
								while (!sync_canread(&FORTASK(child_proc, this_taskgroup).tg_proc_group_lock))
									task_yield();
							}
							goto again_enum_children;
						}
						child_group_pid = FORTASK(child_proc, this_taskgroup).tg_proc_group;
						is_group        = child_group_pid->tp_pids[my_indirection] == upid;
						sync_endread(&FORTASK(child_proc, this_taskgroup).tg_proc_group_lock);
						decref(child_thread);
						if (!is_group)
							continue;
					}
				}
				/* We're supposed to wait for this one!
				 * -> Check if we can consume/copy its state. */
				{
					pid_t result;
					union wait status;
again_read_status:
					status.w_status = ATOMIC_READ(child->tp_status.w_status);
					if ((WIFSTOPPED(status) && (options & WSTOPPED)) ||
					    (WIFCONTINUED(status) && (options & WCONTINUED))) {
						/* Try to consume the state. */
						if (!ATOMIC_CMPXCH_WEAK(child->tp_status.w_status,
						                        status.w_status,
						                        0))
							goto again_read_status;
						incref(child);
						sync_end(&mygroup.tg_proc_threads_lock);
						/* we're dealing with an stop/continue status */
					} else if ((options & WEXITED) &&
					           /* NOTE: Check for fully terminated here, since the `TASK_FTERMINATING'
					            *       flag doesn't mean that the thread has already written its exit
					            *       status message,  or broadcast  its tp_changed  signal for  the
					            *       final time. (s.a. `task_exit()') */
					           is_taskpid_terminating(child)) {
						/* we're dealing with an exit-code status */
						if (!(options & WNOREAP)) {
							/* Detach the zombie process. */
							if (!sync_writing(&mygroup.tg_proc_threads_lock) &&
							    !sync_upgrade(&mygroup.tg_proc_threads_lock))
								goto again_enum_children_locked;
							/* Unbind the child thread/process, thereby inheriting the
							 * reference  previously stored within  the chain of child
							 * threads. */
							LIST_UNBIND(child, tp_siblings);

							/* Inherit reference to `child' */
							sync_endwrite(&mygroup.tg_proc_threads_lock);
						} else {
							incref(child);
							sync_end(&mygroup.tg_proc_threads_lock);
						}
					} else {
						goto next_candidate;
					}
					/* Found a child that has been signaled! */
					task_disconnectall();
					{
						FINALLY_DECREF(child);
						result = (pid_t)child->tp_pids[my_indirection];
						/* Fill in information in user-pointers! */
						COMPILER_WRITE_BARRIER();
						if (wstatus)
							*wstatus = status.w_status;
						if (infop) {
							infop->si_signo  = SIGCLD;
							infop->si_errno  = 0;
							infop->si_code   = WIFCONTINUED(status)
							                 ? CLD_CONTINUED
							                 : WIFSTOPPED(status)
							                   ? CLD_STOPPED
							                   : WCOREDUMP(status)
							                     ? CLD_DUMPED
							                     : WIFEXITED(status)
							                       ? CLD_EXITED
							                       : WIFSIGNALED(status)
							                         ? CLD_KILLED
							                         : CLD_TRAPPED;
							infop->si_pid    = result;
							infop->si_uid    = 0; /* ??? */
							infop->si_status = status.w_status;
							infop->si_utime  = 0; /* ??? */
							infop->si_stime  = 0; /* ??? */
						}
						if (ru) {
							memset(ru, 0, sizeof(*ru));
							/* XXX: Fill in usage information? */
						}
						COMPILER_WRITE_BARRIER();
					}
					return result;
				}
next_candidate:
				/* At least it's a candidate... */
				++num_candidates;
			}
			sync_end(&mygroup.tg_proc_threads_lock);
		} EXCEPT {
			task_disconnectall();
			RETHROW();
		}
		/* All possible wait-candidates have been enumerated, however none
		 * of them was found to have changed state or to be of  relevance.
		 * Now  we  must  either  fail   (when  `WNOHANG'  was  set),   or
		 * wait for the signal that we've connected to above. */
		if ((options & WNOHANG) || !num_candidates) {
			if (task_receiveall())
				goto again_connect_enum_children; /* Try again, because doing so won't ~hang~ (block) */
#if 1
			/* Indicate that we may have succeeded without `WNOHANG' */
			return num_candidates ? -EAGAIN : -ECHILD;
#else
			return -ECHILD;
#endif
		}
		/* Wait for something to happen. */
		task_waitfor();
		goto again_connect_enum_children;
	}
#undef mygroup
}
#endif /* WANT_WAIT */

#ifdef __ARCH_WANT_SYSCALL_WAITID
DEFINE_SYSCALL5(pid_t, waitid,
                syscall_ulong_t, which, id_t, upid,
                USER UNCHECKED siginfo_t *, infop,
                syscall_ulong_t, options,
                USER UNCHECKED struct rusage32 *, ru) {
	pid_t result;
	VALIDATE_FLAGSET(options,
	                 WNOHANG | WNOREAP | WEXITED | WSTOPPED | WCONTINUED,
	                 E_INVALID_ARGUMENT_CONTEXT_WAITID_OPTIONS);
	if (!(options & (WEXITED | WSTOPPED | WCONTINUED)))
		THROW(E_INVALID_ARGUMENT_BAD_FLAG_COMBINATION,
		      E_INVALID_ARGUMENT_CONTEXT_WAITID_OPTIONS,
		      options,
		      WEXITED | WSTOPPED | WCONTINUED,
		      0);
	if (which > P_PGID)
		THROW(E_INVALID_ARGUMENT_BAD_VALUE,
		      E_INVALID_ARGUMENT_CONTEXT_WAITID_WHICH,
		      which);
	validate_writable_opt(infop, sizeof(*infop));
	validate_writable_opt(ru, sizeof(*ru));
#if __SIZEOF_TIME32_T__ == __TM_SIZEOF(TIME)
	result = posix_waitfor((idtype_t)which, upid, NULL,
	                       infop, options, ru);
#else /* __SIZEOF_TIME32_T__ == __TM_SIZEOF(TIME) */
	if (ru) {
		struct rusage kru;
		result = posix_waitfor((idtype_t)which, upid, NULL,
		                       infop, options, &kru);
		if (E_ISOK(result))
			rusage_to_rusage32(&kru, ru);
	} else {
		result = posix_waitfor((idtype_t)which, upid, NULL,
		                       infop, options, NULL);
	}
#endif /* __SIZEOF_TIME32_T__ != __TM_SIZEOF(TIME) */
	return result;
}
#endif /* __ARCH_WANT_SYSCALL_WAITID */

#ifdef __ARCH_WANT_SYSCALL_WAITID64
DEFINE_SYSCALL5(pid_t, waitid64,
                syscall_ulong_t, which, id_t, upid,
                USER UNCHECKED siginfo_t *, infop,
                syscall_ulong_t, options,
                USER UNCHECKED struct rusage64 *, ru) {
	pid_t result;
	VALIDATE_FLAGSET(options,
	                 WNOHANG | WNOREAP | WEXITED | WSTOPPED | WCONTINUED,
	                 E_INVALID_ARGUMENT_CONTEXT_WAITID_OPTIONS);
	if (!(options & (WEXITED | WSTOPPED | WCONTINUED)))
		THROW(E_INVALID_ARGUMENT_BAD_FLAG_COMBINATION,
		      E_INVALID_ARGUMENT_CONTEXT_WAITID_OPTIONS,
		      options,
		      WEXITED | WSTOPPED | WCONTINUED,
		      0);
	if (which > P_PGID)
		THROW(E_INVALID_ARGUMENT_BAD_VALUE,
		      E_INVALID_ARGUMENT_CONTEXT_WAITID_WHICH,
		      which);
	validate_writable_opt(infop, sizeof(*infop));
	validate_writable_opt(ru, sizeof(*ru));
#if __SIZEOF_TIME64_T__ == __TM_SIZEOF(TIME)
	result = posix_waitfor((idtype_t)which, upid, NULL,
	                       infop, options, ru);
#else /* __SIZEOF_TIME64_T__ == __TM_SIZEOF(TIME) */
	if (ru) {
		struct rusage kru;
		result = posix_waitfor((idtype_t)which, upid, NULL,
		                       infop, options, &kru);
		if (E_ISOK(result))
			rusage_to_rusage64(&kru, ru);
	} else {
		result = posix_waitfor((idtype_t)which, upid, NULL,
		                       infop, options, NULL);
	}
#endif /* __SIZEOF_TIME64_T__ != __TM_SIZEOF(TIME) */
	return result;
}
#endif /* __ARCH_WANT_SYSCALL_WAITID64 */

#ifdef __ARCH_WANT_COMPAT_SYSCALL_WAITID
DEFINE_COMPAT_SYSCALL5(pid_t, waitid,
                       syscall_ulong_t, which, id_t, upid,
                       USER UNCHECKED compat_siginfo_t *, infop,
                       syscall_ulong_t, options,
                       USER UNCHECKED struct compat_rusage32 *, ru) {
	pid_t result;
	siginfo_t info;
	VALIDATE_FLAGSET(options,
	                 WNOHANG | WNOREAP | WEXITED | WSTOPPED | WCONTINUED,
	                 E_INVALID_ARGUMENT_CONTEXT_WAITID_OPTIONS);
	if (!(options & (WEXITED | WSTOPPED | WCONTINUED)))
		THROW(E_INVALID_ARGUMENT_BAD_FLAG_COMBINATION,
		      E_INVALID_ARGUMENT_CONTEXT_WAITID_OPTIONS,
		      options,
		      WEXITED | WSTOPPED | WCONTINUED,
		      0);
	if (which > P_PGID)
		THROW(E_INVALID_ARGUMENT_BAD_VALUE,
		      E_INVALID_ARGUMENT_CONTEXT_WAITID_WHICH,
		      which);
	validate_writable_opt(infop, sizeof(*infop));
	validate_writable_opt(ru, sizeof(*ru));
	if (ru) {
		struct rusage kru;
		result = posix_waitfor((idtype_t)which, upid, NULL,
		                       infop ? &info : NULL,
		                       options, &kru);
		if (E_ISOK(result))
			rusage_to_compat_rusage32(&kru, ru);
	} else {
		result = posix_waitfor((idtype_t)which, upid, NULL,
		                       infop ? &info : NULL,
		                       options, NULL);
	}
	if (E_ISOK(result) && infop)
		siginfo_to_compat_siginfo(&info, infop);
	return result;
}
#endif /* __ARCH_WANT_COMPAT_SYSCALL_WAITID */

#ifdef __ARCH_WANT_COMPAT_SYSCALL_WAITID64
DEFINE_COMPAT_SYSCALL5(pid_t, waitid64,
                       syscall_ulong_t, which, id_t, upid,
                       USER UNCHECKED compat_siginfo_t *, infop,
                       syscall_ulong_t, options,
                       USER UNCHECKED struct compat_rusage64 *, ru) {
	pid_t result;
	siginfo_t info;
	VALIDATE_FLAGSET(options,
	                 WNOHANG | WNOREAP | WEXITED | WSTOPPED | WCONTINUED,
	                 E_INVALID_ARGUMENT_CONTEXT_WAITID_OPTIONS);
	if (!(options & (WEXITED | WSTOPPED | WCONTINUED)))
		THROW(E_INVALID_ARGUMENT_BAD_FLAG_COMBINATION,
		      E_INVALID_ARGUMENT_CONTEXT_WAITID_OPTIONS,
		      options,
		      WEXITED | WSTOPPED | WCONTINUED,
		      0);
	if (which > P_PGID)
		THROW(E_INVALID_ARGUMENT_BAD_VALUE,
		      E_INVALID_ARGUMENT_CONTEXT_WAITID_WHICH,
		      which);
	validate_writable_opt(infop, sizeof(*infop));
	validate_writable_opt(ru, sizeof(*ru));
	if (ru) {
		struct rusage kru;
		result = posix_waitfor((idtype_t)which, upid, NULL,
		                       infop ? &info : NULL,
		                       options, &kru);
		if (E_ISOK(result))
			rusage_to_compat_rusage64(&kru, ru);
	} else {
		result = posix_waitfor((idtype_t)which, upid, NULL,
		                       infop ? &info : NULL,
		                       options, NULL);
	}
	if (E_ISOK(result) && infop)
		siginfo_to_compat_siginfo(&info, infop);
	return result;
}
#endif /* __ARCH_WANT_COMPAT_SYSCALL_WAITID64 */

#ifdef __ARCH_WANT_SYSCALL_WAITPID
DEFINE_SYSCALL3(pid_t, waitpid,
                pid_t, pid, int32_t *, stat_loc,
                syscall_ulong_t, options) {
	return sys_wait4(pid, stat_loc, options, NULL);
}
#endif /* __ARCH_WANT_SYSCALL_WAITPID */

#ifdef __ARCH_WANT_COMPAT_SYSCALL_WAITPID
DEFINE_COMPAT_SYSCALL3(pid_t, waitpid,
                       pid_t, pid, int32_t *, stat_loc,
                       syscall_ulong_t, options) {
	return sys_wait4(pid, stat_loc, options, NULL);
}
#endif /* __ARCH_WANT_COMPAT_SYSCALL_WAITPID */

#ifdef __ARCH_WANT_SYSCALL_WAIT4
DEFINE_SYSCALL4(pid_t, wait4, pid_t, upid,
                USER UNCHECKED int32_t *, wstatus,
                syscall_ulong_t, options,
                USER UNCHECKED struct rusage32 *, ru) {
	idtype_t which;
	pid_t result;
	VALIDATE_FLAGSET(options,
	                 WNOHANG | WSTOPPED | WCONTINUED | WNOREAP,
	                 E_INVALID_ARGUMENT_CONTEXT_WAIT4_OPTIONS);
	options |= WEXITED;
	validate_writable_opt(wstatus, sizeof(*wstatus));
	validate_writable_opt(ru, sizeof(*ru));
	if (upid < -1) {
		upid  = -upid;
		which = (idtype_t)P_PGID;
	} else if (upid == -1) {
		upid  = 0;
		which = (idtype_t)P_ALL;
	} else if (upid == 0) {
		/* wait for any child process whose process group ID is equal to that of the calling process. */
		REF struct task *group;
		struct taskpid *pid;
		group = task_getprocessgroupleader_srch();
		pid   = FORTASK(group, this_taskpid);
		upid  = taskpid_getpid_s(pid);
		which = (idtype_t)P_PGID;
		decref_unlikely(group);
	} else {
		/* wait for the child whose process ID is equal to the value of pid. */
		which = (idtype_t)P_PID;
	}
#if __SIZEOF_TIME32_T__ == __TM_SIZEOF(TIME)
	result = posix_waitfor(which,
	                       (upid_t)upid,
	                       wstatus,
	                       NULL,
	                       options,
	                       ru);
#else /* __SIZEOF_TIME32_T__ == __TM_SIZEOF(TIME) */
	if (ru) {
		struct rusage kru;
		result = posix_waitfor(which,
		                       (upid_t)upid,
		                       wstatus,
		                       NULL,
		                       options,
		                       &kru);
		if (E_ISOK(result))
			rusage_to_rusage32(&kru, ru);
	} else {
		result = posix_waitfor(which,
		                       (upid_t)upid,
		                       wstatus,
		                       NULL,
		                       options,
		                       NULL);
	}
#endif /* __SIZEOF_TIME32_T__ != __TM_SIZEOF(TIME) */
	return result;
}
#endif /* __ARCH_WANT_SYSCALL_WAIT4 */

#ifdef __ARCH_WANT_SYSCALL_WAIT4_64
DEFINE_SYSCALL4(pid_t, wait4_64, pid_t, upid,
                USER UNCHECKED int32_t *, wstatus,
                syscall_ulong_t, options,
                USER UNCHECKED struct rusage64 *, ru) {
	idtype_t which;
	pid_t result;
	VALIDATE_FLAGSET(options,
	                 WNOHANG | WSTOPPED | WCONTINUED | WNOREAP,
	                 E_INVALID_ARGUMENT_CONTEXT_WAIT4_OPTIONS);
	options |= WEXITED;
	validate_writable_opt(wstatus, sizeof(*wstatus));
	validate_writable_opt(ru, sizeof(*ru));
	if (upid < -1) {
		upid  = -upid;
		which = (idtype_t)P_PGID;
	} else if (upid == -1) {
		upid  = 0;
		which = (idtype_t)P_ALL;
	} else if (upid == 0) {
		/* wait for any child process whose process group ID is equal to that of the calling process. */
		REF struct task *group;
		struct taskpid *pid;
		group = task_getprocessgroupleader_srch();
		pid   = FORTASK(group, this_taskpid);
		upid  = taskpid_getpid_s(pid);
		which = (idtype_t)P_PGID;
		decref_unlikely(group);
	} else {
		/* wait for the child whose process ID is equal to the value of pid. */
		which = (idtype_t)P_PID;
	}
#if __SIZEOF_TIME64_T__ == __TM_SIZEOF(TIME)
	result = posix_waitfor(which,
	                       (upid_t)upid,
	                       wstatus,
	                       NULL,
	                       options,
	                       ru);
#else /* __SIZEOF_TIME64_T__ == __TM_SIZEOF(TIME) */
	if (ru) {
		struct rusage kru;
		result = posix_waitfor(which,
		                       (upid_t)upid,
		                       wstatus,
		                       NULL,
		                       options,
		                       &kru);
		if (E_ISOK(result))
			rusage_to_rusage64(&kru, ru);
	} else {
		result = posix_waitfor(which,
		                       (upid_t)upid,
		                       wstatus,
		                       NULL,
		                       options,
		                       NULL);
	}
#endif /* __SIZEOF_TIME64_T__ != __TM_SIZEOF(TIME) */
	return result;
}
#endif /* __ARCH_WANT_SYSCALL_WAIT4_64 */

#ifdef __ARCH_WANT_COMPAT_SYSCALL_WAIT4
DEFINE_COMPAT_SYSCALL4(pid_t, wait4, pid_t, upid,
                       USER UNCHECKED int32_t *, wstatus,
                       syscall_ulong_t, options,
                       USER UNCHECKED struct compat_rusage32 *, ru) {
	idtype_t which;
	pid_t result;
	VALIDATE_FLAGSET(options,
	                 WNOHANG | WSTOPPED | WCONTINUED | WNOREAP,
	                 E_INVALID_ARGUMENT_CONTEXT_WAIT4_OPTIONS);
	options |= WEXITED;
	validate_writable_opt(wstatus, sizeof(*wstatus));
	validate_writable_opt(ru, sizeof(*ru));
	if (upid < -1) {
		upid  = -upid;
		which = (idtype_t)P_PGID;
	} else if (upid == -1) {
		upid  = 0;
		which = (idtype_t)P_ALL;
	} else if (upid == 0) {
		/* wait for any child process whose process group ID is equal to that of the calling process. */
		REF struct task *group;
		struct taskpid *pid;
		group = task_getprocessgroupleader_srch();
		pid   = FORTASK(group, this_taskpid);
		upid  = taskpid_getpid_s(pid);
		which = (idtype_t)P_PGID;
		decref_unlikely(group);
	} else {
		/* wait for the child whose process ID is equal to the value of pid. */
		which = (idtype_t)P_PID;
	}
	if (ru) {
		struct rusage kru;
		result = posix_waitfor(which,
		                       (upid_t)upid,
		                       wstatus,
		                       NULL,
		                       options,
		                       &kru);
		if (E_ISOK(result))
			rusage_to_compat_rusage32(&kru, ru);
	} else {
		result = posix_waitfor(which,
		                       (upid_t)upid,
		                       wstatus,
		                       NULL,
		                       options,
		                       NULL);
	}
	return result;
}
#endif /* __ARCH_WANT_COMPAT_SYSCALL_WAIT4 */

#ifdef __ARCH_WANT_COMPAT_SYSCALL_WAIT4_64
DEFINE_COMPAT_SYSCALL4(pid_t, wait4_64, pid_t, upid,
                       USER UNCHECKED int32_t *, wstatus,
                       syscall_ulong_t, options,
                       USER UNCHECKED struct compat_rusage64 *, ru) {
	idtype_t which;
	pid_t result;
	VALIDATE_FLAGSET(options,
	                 WNOHANG | WSTOPPED | WCONTINUED | WNOREAP,
	                 E_INVALID_ARGUMENT_CONTEXT_WAIT4_OPTIONS);
	options |= WEXITED;
	validate_writable_opt(wstatus, sizeof(*wstatus));
	validate_writable_opt(ru, sizeof(*ru));
	if (upid < -1) {
		upid  = -upid;
		which = (idtype_t)P_PGID;
	} else if (upid == -1) {
		upid  = 0;
		which = (idtype_t)P_ALL;
	} else if (upid == 0) {
		/* wait for any child process whose process group ID is equal to that of the calling process. */
		REF struct task *group;
		struct taskpid *pid;
		group = task_getprocessgroupleader_srch();
		pid   = FORTASK(group, this_taskpid);
		upid  = taskpid_getpid_s(pid);
		which = (idtype_t)P_PGID;
		decref_unlikely(group);
	} else {
		/* wait for the child whose process ID is equal to the value of pid. */
		which = (idtype_t)P_PID;
	}
	if (ru) {
		struct rusage kru;
		result = posix_waitfor(which,
		                       (upid_t)upid,
		                       wstatus,
		                       NULL,
		                       options,
		                       &kru);
		if (E_ISOK(result))
			rusage_to_compat_rusage64(&kru, ru);
	} else {
		result = posix_waitfor(which,
		                       (upid_t)upid,
		                       wstatus,
		                       NULL,
		                       options,
		                       NULL);
	}
	return result;
}
#endif /* __ARCH_WANT_COMPAT_SYSCALL_WAIT4_64 */


DECL_END

#endif /* !GUARD_KERNEL_SRC_SCHED_PID_C */
