/* HASH CRC-32:0x5365dc18 */
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
#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H 1

#include <__stdinc.h>
#include <__crt.h>

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#include <bits/types.h>
#if defined(__USE_XOPEN) || defined(__USE_XOPEN2K8)
#include <bits/siginfo.h> /* We'd only need `siginfo_t' */
#endif /* __USE_XOPEN || __USE_XOPEN2K8 */

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef __WAIT_MACROS_DEFINED
#include <bits/waitflags.h>
#include <bits/waitstatus.h>
#endif /* !__WAIT_MACROS_DEFINED */

__SYSDECL_BEGIN

#ifdef __USE_MISC
#define WCOREFLAG           __WCOREFLAG
#define WCOREDUMP(status)   __WCOREDUMP(__WAIT_INT(status))
#define W_EXITCODE(ret,sig) __W_EXITCODE(ret,sig)
#define W_STOPCODE(sig)     __W_STOPCODE(sig)

#define WAIT_ANY     (-1) /* Any process. */
#define WAIT_MYPGRP    0  /* Any process in my process group. */
#endif /* __USE_MISC */


#ifdef __CC__

#ifndef __WAIT_MACROS_DEFINED
#define __WAIT_MACROS_DEFINED 1
#ifdef __USE_MISC
#if defined(__GNUC__) && !defined(__cplusplus)
#   define __WAIT_INT(status) (__extension__(((union{ __typeof__(status) __inval; int __ival; }) { .__inval = (status) }).__ival))
#else /* __GNUC__ && !__cplusplus */
#   define __WAIT_INT(status) (*(int *)&(status))
#endif /* !__GNUC__ || __cplusplus */
#ifdef __NO_ATTR_TRANSPARENT_UNION
#   define __WAIT_STATUS      void *
#   define __WAIT_STATUS_DEFN void *
#else /* __NO_ATTR_TRANSPARENT_UNION */
typedef union {
	union wait *__uptr_;
	int        *__iptr_;
} __WAIT_STATUS __ATTR_TRANSPARENT_UNION;
#   define __WAIT_STATUS_DEFN int *
#endif /* !__NO_ATTR_TRANSPARENT_UNION */
#else /* __USE_MISC */
#   define __WAIT_INT(status)  (status)
#   define __WAIT_STATUS        int *
#   define __WAIT_STATUS_DEFN   int *
#endif /* !__USE_MISC */
#   define WEXITSTATUS(status)  __WEXITSTATUS(__WAIT_INT(status))
#   define WTERMSIG(status)     __WTERMSIG(__WAIT_INT(status))
#   define WSTOPSIG(status)     __WSTOPSIG(__WAIT_INT(status))
#   define WIFEXITED(status)    __WIFEXITED(__WAIT_INT(status))
#   define WIFSIGNALED(status)  __WIFSIGNALED(__WAIT_INT(status))
#   define WIFSTOPPED(status)   __WIFSTOPPED(__WAIT_INT(status))
#ifdef __WIFCONTINUED
#   define WIFCONTINUED(status) __WIFCONTINUED(__WAIT_INT(status))
#endif /* __WIFCONTINUED */
#endif /* !__WAIT_MACROS_DEFINED */

#ifdef __CRT_HAVE_wait
/* Wait for any child process (same as `waitpid(-1, STAT_LOC, 0);') */
__CDECLARE(,__pid_t,__NOTHROW_RPC,wait,(__WAIT_STATUS __stat_loc),(__stat_loc))
#elif defined(__CRT_HAVE___wait)
/* Wait for any child process (same as `waitpid(-1, STAT_LOC, 0);') */
__CREDIRECT(,__pid_t,__NOTHROW_RPC,wait,(__WAIT_STATUS __stat_loc),__wait,(__stat_loc))
#endif /* wait... */
#ifdef __CRT_HAVE_waitpid
/* Wait for a child process:
 *  - `pid < -1':  Wait for any child process whose process group ID is `-PID'
 *  - `pid == -1': Wait for any child process
 *  - `pid == 0':  Wait for any child process whose process group ID is that of the caller
 *  - `pid > 0':   Wait for the child whose process ID is equal to `PID'
 * @param: options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CDECLARE(,__pid_t,__NOTHROW_RPC,waitpid,(__pid_t __pid, __WAIT_STATUS __stat_loc, int __options),(__pid,__stat_loc,__options))
#elif defined(__CRT_HAVE___waitpid)
/* Wait for a child process:
 *  - `pid < -1':  Wait for any child process whose process group ID is `-PID'
 *  - `pid == -1': Wait for any child process
 *  - `pid == 0':  Wait for any child process whose process group ID is that of the caller
 *  - `pid > 0':   Wait for the child whose process ID is equal to `PID'
 * @param: options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CREDIRECT(,__pid_t,__NOTHROW_RPC,waitpid,(__pid_t __pid, __WAIT_STATUS __stat_loc, int __options),__waitpid,(__pid,__stat_loc,__options))
#endif /* waitpid... */

#if defined(__USE_XOPEN) || defined(__USE_XOPEN2K8)
#ifndef __id_t_defined
#define __id_t_defined 1
typedef __id_t id_t;
#endif /* !__id_t_defined */
#ifdef __CRT_HAVE_waitid
/* @param options: At least one of `WEXITED|WSTOPPED|WCONTINUED', optionally or'd with `WNOHANG|WNOWAIT' */
__CDECLARE(,int,__NOTHROW_RPC,waitid,(idtype_t __idtype, id_t __id, siginfo_t *__infop, int __options),(__idtype,__id,__infop,__options))
#endif /* waitid... */
#endif /* __USE_XOPEN || __USE_XOPEN2K8 */

#if defined(__USE_MISC) || defined(__USE_XOPEN_EXTENDED)
struct rusage;
#if defined(__CRT_HAVE_wait3_64) && defined(__USE_TIME_BITS64)
/* Same as `waitpid(-1,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CREDIRECT(,__pid_t,__NOTHROW_RPC,wait3,(__WAIT_STATUS __stat_loc, int __options, struct rusage *__usage),wait3_64,(__stat_loc,__options,__usage))
#elif defined(__CRT_HAVE_wait3) && !defined(__USE_TIME_BITS64)
/* Same as `waitpid(-1,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CDECLARE(,__pid_t,__NOTHROW_RPC,wait3,(__WAIT_STATUS __stat_loc, int __options, struct rusage *__usage),(__stat_loc,__options,__usage))
#elif defined(__CRT_HAVE_wait3) || defined(__CRT_HAVE_wait3_64)
#include <local/sys.wait/wait3.h>
/* Same as `waitpid(-1,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__NAMESPACE_LOCAL_USING_OR_IMPL(wait3, __FORCELOCAL __pid_t __NOTHROW_RPC(__LIBCCALL wait3)(__WAIT_STATUS __stat_loc, int __options, struct rusage *__usage) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wait3))(__stat_loc, __options, __usage); })
#endif /* wait3... */
#ifdef __USE_TIME64
struct rusage64;
#ifdef __CRT_HAVE_wait3_64
/* Same as `waitpid(-1,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CDECLARE(,__pid_t,__NOTHROW_NCX,wait3_64,(__WAIT_STATUS __stat_loc, int __options, struct rusage64 *__usage),(__stat_loc,__options,__usage))
#elif defined(__CRT_HAVE_wait3) && (__SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__)
/* Same as `waitpid(-1,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CREDIRECT(,__pid_t,__NOTHROW_NCX,wait3_64,(__WAIT_STATUS __stat_loc, int __options, struct rusage64 *__usage),wait3,(__stat_loc,__options,__usage))
#elif defined(__CRT_HAVE_wait3)
#include <local/sys.wait/wait3_64.h>
/* Same as `waitpid(-1,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__NAMESPACE_LOCAL_USING_OR_IMPL(wait3_64, __FORCELOCAL __pid_t __NOTHROW_NCX(__LIBCCALL wait3_64)(__WAIT_STATUS __stat_loc, int __options, struct rusage64 *__usage) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wait3_64))(__stat_loc, __options, __usage); })
#endif /* wait3_64... */
#endif /* __USE_TIME64 */
#endif /* __USE_MISC || __USE_XOPEN_EXTENDED */

#ifdef __USE_MISC
#if defined(__CRT_HAVE_wait4_64) && defined(__USE_TIME_BITS64)
/* Same as `waitpid(pid,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CREDIRECT(,__pid_t,__NOTHROW_RPC,wait4,(__pid_t __pid, __WAIT_STATUS __stat_loc, int __options, struct rusage *__usage),wait4_64,(__pid,__stat_loc,__options,__usage))
#elif defined(__CRT_HAVE_wait4) && !defined(__USE_TIME_BITS64)
/* Same as `waitpid(pid,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CDECLARE(,__pid_t,__NOTHROW_RPC,wait4,(__pid_t __pid, __WAIT_STATUS __stat_loc, int __options, struct rusage *__usage),(__pid,__stat_loc,__options,__usage))
#elif defined(__CRT_HAVE_wait4) || defined(__CRT_HAVE_wait4_64)
#include <local/sys.wait/wait4.h>
/* Same as `waitpid(pid,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__NAMESPACE_LOCAL_USING_OR_IMPL(wait4, __FORCELOCAL __pid_t __NOTHROW_RPC(__LIBCCALL wait4)(__pid_t __pid, __WAIT_STATUS __stat_loc, int __options, struct rusage *__usage) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wait4))(__pid, __stat_loc, __options, __usage); })
#endif /* wait4... */
#ifdef __USE_TIME64
struct rusage64;
#ifdef __CRT_HAVE_wait4_64
/* Same as `waitpid(pid,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CDECLARE(,__pid_t,__NOTHROW_NCX,wait4_64,(__pid_t __pid, __WAIT_STATUS __stat_loc, int __options, struct rusage64 *__usage),(__pid,__stat_loc,__options,__usage))
#elif defined(__CRT_HAVE_wait4) && (__SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__)
/* Same as `waitpid(pid,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CREDIRECT(,__pid_t,__NOTHROW_NCX,wait4_64,(__pid_t __pid, __WAIT_STATUS __stat_loc, int __options, struct rusage64 *__usage),wait4,(__pid,__stat_loc,__options,__usage))
#elif defined(__CRT_HAVE_wait4)
#include <local/sys.wait/wait4_64.h>
/* Same as `waitpid(pid,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__NAMESPACE_LOCAL_USING_OR_IMPL(wait4_64, __FORCELOCAL __pid_t __NOTHROW_NCX(__LIBCCALL wait4_64)(__pid_t __pid, __WAIT_STATUS __stat_loc, int __options, struct rusage64 *__usage) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wait4_64))(__pid, __stat_loc, __options, __usage); })
#endif /* wait4_64... */
#endif /* __USE_TIME64 */
#endif /* __USE_MISC */

#ifdef __USE_KOS
#ifdef __CRT_HAVE_detach
/* >> detach(2)
 * Detach the descriptor of `PID' from the thread that
 * would have received a signal when it changes state,
 * as well as prevent the thread from turning into a
 * zombie once it dies.
 * For simplicity, think of it like this:
 *   - pthread_create()  -->  clone()
 *   - pthread_join()    -->  wait()
 *   - pthread_detach()  -->  detach()  // Linux's missing link, now implemented
 * A total of 4 special cases exists to alter the behavior of this function:
 *   - PID == 0 || PID == gettid():
 *     Detach the calling thread from the set of running children within
 *     its own process. Note however that when this is done by the main
 *     thread of the process, gettid() will equal getpid(), and the behavior
 *     will be different.
 *   - PID == getpid():
 *     Detach the calling process from its parent, essentially daemonizing
 *     the calling process the same way a double-fork would:
 *     >> if (fork() == 0) {
 *     >> 	if (fork() == 0) {
 *     >> 		// This is a daemonized process
 *     >> 		// aka. the parent process no longer knows
 *     >> 		// about us, and also can't wait(2) on us.
 *     >> 		...
 *     >> 	}
 *     >> 	exit(0);
 *     >> }
 *     Same as:
 *     >> if (fork() == 0) {
 *     >> 	detach(0); // or `detach(getpid())', since 0 --> gettid() and gettid() == getpid()
 *     >> 	// This is a daemonized process
 *     >> 	// aka. the parent process no longer knows
 *     >> 	// about us, and also can't wait(2) on us.
 *     >> 	...
 *     >> }
 *   - PID == -1:
 *     Detach all child processes/threads of the calling process, essentially
 *     turning its chain of children into a clean slate that no longer contains
 *     any wait(2)able child threads or processes.
 *     If no waitable children existed, `ECHILD' is set; else `0' is returned.
 * Before any of this is done, the thread referred to by `PID' is one of the following:
 *   - The leader of the process that called `fork()' or `clone()' without
 *    `CLONE_PARENT' to create the thread referred to by `PID'
 *   - The creator of the process containing a thread that called
 *    `clone()' with `CLONE_PARENT', which then created the thread
 *     referred to by `PID'.
 *   - Even if the thread doesn't deliver a signal upon it terminating,
 *     the process that would have received such a signal is still relevant.
 *   -> In other words: The thread `PID' must be one of your children,
 *                      or you had to have been assigned as its child.
 * If the calling thread isn't part of that process that will receive
 * the signal if the thread dies without being detached first, then
 * the call fails by throwing an `E_ILLEGAL_OPERATION'.
 * If the thread had already been detached, then the call fails by
 * throwing an `E_ILLEGAL_OPERATION' as well.
 * Upon success, the thread referred to by `PID' will clean up its own
 * PID descriptor without the need of anyone to wait() for it, a behavior
 * that linux implements using `CLONE_THREAD' (which you shouldn't use,
 * because it's flawed by design)
 * Once detached, any further use of PID results in a race condition
 * (which linux neglects to mention for `CLONE_THREAD'), because there
 * is no way of ensuring that PID still refers to the original thread,
 * as another thread may have been created using the same PID, after
 * the detached thread exited.
 * NOTE: If a thread is created using clone() with `CLONE_DETACHED' set,
 *       it will behave effectively as though this function had already
 *       be called.
 * NOTE: If the thread already has terminated, detaching it will kill
 *       its zombie the same way wait() would.
 * NOTE: Passing ZERO(0) for `PID' will detach the calling thread.
 *       However, this operation fails if the calling thread isn't
 *       part of the same process as the parent process of the thread.
 *       In other words, the child of a fork() can't do this, and
 *       neither can the spawnee of clone(CLONE_THREAD|CLONE_PARENT),
 *       clone(0) or clone(CLONE_PARENT).
 * @errno: EPERM:               The calling process isn't the recipient of signals
 *                              delivered when `PID' changes state. This can either
 *                              be because `PID' has already been detached, or because
 *                              YOU CAN'T DETACH SOMEONE ELSE'S THREAD!
 *                              Another possibility is that the thread was already
 *                              detached, then exited, following which a new thread
 *                              got created and had been assigned the PID of your
 *                              ancient, no longer existent thread.
 * @errno: ECHILD:             `PID' was equal to `-1', but no waitable children existed
 * @throw: E_PROCESS_EXITED:    The process referred to by `PID' doesn't exist.
 *                              This could mean that it had already been detached
 *                              and exited, or that the `PID' is just invalid (which
 *                              would also be the case if it was valid at some point) */
__CDECLARE(,int,__NOTHROW_NCX,detach,(__pid_t __pid),(__pid))
#endif /* detach... */
#endif /* __USE_KOS */

#endif /* __CC__ */

__SYSDECL_END

#endif /* !_SYS_WAIT_H */
