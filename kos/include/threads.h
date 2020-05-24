/* HASH CRC-32:0x5afa43b5 */
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
#ifndef _THREADS_H
#define _THREADS_H 1

#include "__stdinc.h"
#include "__crt.h"
#include <kos/anno.h>

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>

#include <hybrid/typecore.h>

#include <asm/threads.h>
#include <bits/threads.h>
#include <bits/timespec.h>

__SYSDECL_BEGIN

/* Documentation taken from Glibc /usr/include/threads.h, but have since been modified */
/* ISO C11 Standard: 7.26 - Thread support library  <threads.h>.
   Copyright (C) 2018-2019 Free Software Foundation, Inc.
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


#ifndef TSS_DTOR_ITERATIONS
#define TSS_DTOR_ITERATIONS 4
#endif /* !TSS_DTOR_ITERATIONS */

/* Exit and error codes.  */
#undef thrd_success
#undef thrd_busy
#undef thrd_error
#undef thrd_nomem
#undef thrd_timedout
#ifdef __CC__
enum {
	thrd_success  = __thrd_success,
	thrd_busy     = __thrd_busy,
	thrd_error    = __thrd_error,
	thrd_nomem    = __thrd_nomem,
	thrd_timedout = __thrd_timedout
};
#endif /* __CC__ */
#ifdef __COMPILER_PREFERR_ENUMS
#define thrd_success  thrd_success
#define thrd_busy     thrd_busy
#define thrd_error    thrd_error
#define thrd_nomem    thrd_nomem
#define thrd_timedout thrd_timedout
#else /* __COMPILER_PREFERR_ENUMS */
#define thrd_success  __thrd_success
#define thrd_busy     __thrd_busy
#define thrd_error    __thrd_error
#define thrd_nomem    __thrd_nomem
#define thrd_timedout __thrd_timedout
#endif /* !__COMPILER_PREFERR_ENUMS */

/* Mutex types.  */
#undef mtx_plain
#undef mtx_recursive
#undef mtx_timed
#ifdef __CC__
enum {
	mtx_plain     = __mtx_plain,
	mtx_recursive = __mtx_recursive,
	mtx_timed     = __mtx_timed
};
#endif /* __CC__ */
#ifdef __COMPILER_PREFERR_ENUMS
#define mtx_plain     mtx_plain
#define mtx_recursive mtx_recursive
#define mtx_timed     mtx_timed
#else /* __COMPILER_PREFERR_ENUMS */
#define mtx_plain     __mtx_plain
#define mtx_recursive __mtx_recursive
#define mtx_timed     __mtx_timed
#endif /* !__COMPILER_PREFERR_ENUMS */


#ifdef __CC__

typedef __tss_t tss_t;
typedef __thrd_t thrd_t;
typedef __tss_dtor_t tss_dtor_t;
typedef __thrd_start_t thrd_start_t;
typedef __once_flag once_flag;
#define ONCE_FLAG_INIT __ONCE_FLAG_INIT
typedef __mtx_t mtx_t;
typedef __cnd_t cnd_t;

#ifdef __CRT_HAVE_thrd_create
/* Create a new thread executing the function FUNC.  Arguments for FUNC
 * are passed through ARG. If successful, THR is set to new thread identifier */
__CDECLARE(,int,__NOTHROW_NCX,thrd_create,(thrd_t *__thr, thrd_start_t __func, void *__arg),(__thr,__func,__arg))
#elif defined(__CRT_HAVE_pthread_create)
#include <local/threads/thrd_create.h>
/* Create a new thread executing the function FUNC.  Arguments for FUNC
 * are passed through ARG. If successful, THR is set to new thread identifier */
__NAMESPACE_LOCAL_USING_OR_IMPL(thrd_create, __FORCELOCAL int __NOTHROW_NCX(__LIBCCALL thrd_create)(thrd_t *__thr, thrd_start_t __func, void *__arg) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(thrd_create))(__thr, __func, __arg); })
#endif /* thrd_create... */
#ifdef __CRT_HAVE_thrd_equal
/* Check if __LHS and __RHS point to the same thread
 * s.a. `pthread_equal()' */
__CDECLARE(,int,__NOTHROW_NCX,thrd_equal,(thrd_t __lhs, thrd_t __rhs),(__lhs,__rhs))
#elif defined(__CRT_HAVE_pthread_equal)
/* Check if __LHS and __RHS point to the same thread
 * s.a. `pthread_equal()' */
__CREDIRECT(,int,__NOTHROW_NCX,thrd_equal,(thrd_t __lhs, thrd_t __rhs),pthread_equal,(__lhs,__rhs))
#else /* LIBC: pthread_equal */
#include <local/pthread/pthread_equal.h>
/* Check if __LHS and __RHS point to the same thread
 * s.a. `pthread_equal()' */
__FORCELOCAL int __NOTHROW_NCX(__LIBCCALL thrd_equal)(thrd_t __lhs, thrd_t __rhs) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(pthread_equal))((__pthread_t)__lhs, (__pthread_t)__rhs); }
#endif /* thrd_equal... */
#ifdef __CRT_HAVE_thrd_current
/* Return current thread identifier
 * s.a. `pthread_self()' */
__CDECLARE(,thrd_t,__NOTHROW_NCX,thrd_current,(void),())
#elif defined(__CRT_HAVE_pthread_self)
/* Return current thread identifier
 * s.a. `pthread_self()' */
__CREDIRECT(,thrd_t,__NOTHROW_NCX,thrd_current,(void),pthread_self,())
#endif /* thrd_current... */
#if defined(__CRT_HAVE_thrd_sleep64) && defined(__USE_TIME_BITS64)
/* Block current thread execution for at least the (relative) time pointed by TIME_POINT.
 * The current thread may resume if receives a signal. In that case, if REMAINING
 * is not NULL, the remaining time is stored in the object pointed by it
 * @return:     0: The (relative) time specified by `time_point' has elapsed
 * @return:    -1: A signal was received while waiting, and `remaining' was filled in (if given)
 * @return: <= -2: Some other error occurred */
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,thrd_sleep,(struct timespec const *__time_point, struct timespec *__remaining),thrd_sleep64,(__time_point,__remaining))
#elif defined(__CRT_HAVE_thrd_sleep) && !defined(__USE_TIME_BITS64)
/* Block current thread execution for at least the (relative) time pointed by TIME_POINT.
 * The current thread may resume if receives a signal. In that case, if REMAINING
 * is not NULL, the remaining time is stored in the object pointed by it
 * @return:     0: The (relative) time specified by `time_point' has elapsed
 * @return:    -1: A signal was received while waiting, and `remaining' was filled in (if given)
 * @return: <= -2: Some other error occurred */
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,thrd_sleep,(struct timespec const *__time_point, struct timespec *__remaining),(__time_point,__remaining))
#elif defined(__CRT_HAVE_thrd_sleep) || defined(__CRT_HAVE_thrd_sleep64) || defined(__CRT_HAVE_nanosleep) || defined(__CRT_HAVE___nanosleep) || defined(__CRT_HAVE_nanosleep64)
#include <local/threads/thrd_sleep.h>
/* Block current thread execution for at least the (relative) time pointed by TIME_POINT.
 * The current thread may resume if receives a signal. In that case, if REMAINING
 * is not NULL, the remaining time is stored in the object pointed by it
 * @return:     0: The (relative) time specified by `time_point' has elapsed
 * @return:    -1: A signal was received while waiting, and `remaining' was filled in (if given)
 * @return: <= -2: Some other error occurred */
__NAMESPACE_LOCAL_USING_OR_IMPL(thrd_sleep, __FORCELOCAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBCCALL thrd_sleep)(struct timespec const *__time_point, struct timespec *__remaining) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(thrd_sleep))(__time_point, __remaining); })
#endif /* thrd_sleep... */
#ifdef __USE_TIME64
#ifdef __CRT_HAVE_thrd_sleep64
/* Block current thread execution for at least the (relative) time pointed by TIME_POINT.
 * The current thread may resume if receives a signal. In that case, if REMAINING
 * is not NULL, the remaining time is stored in the object pointed by it
 * @return:     0: The (relative) time specified by `time_point' has elapsed
 * @return:    -1: A signal was received while waiting, and `remaining' was filled in (if given)
 * @return: <= -2: Some other error occurred */
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,thrd_sleep64,(struct timespec64 const *__time_point, struct timespec64 *__remaining),(__time_point,__remaining))
#elif defined(__CRT_HAVE_thrd_sleep) && (__SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__)
/* Block current thread execution for at least the (relative) time pointed by TIME_POINT.
 * The current thread may resume if receives a signal. In that case, if REMAINING
 * is not NULL, the remaining time is stored in the object pointed by it
 * @return:     0: The (relative) time specified by `time_point' has elapsed
 * @return:    -1: A signal was received while waiting, and `remaining' was filled in (if given)
 * @return: <= -2: Some other error occurred */
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,thrd_sleep64,(struct timespec64 const *__time_point, struct timespec64 *__remaining),thrd_sleep,(__time_point,__remaining))
#elif defined(__CRT_HAVE_thrd_sleep) || defined(__CRT_HAVE_nanosleep) || defined(__CRT_HAVE___nanosleep) || defined(__CRT_HAVE_nanosleep64)
#include <local/threads/thrd_sleep64.h>
/* Block current thread execution for at least the (relative) time pointed by TIME_POINT.
 * The current thread may resume if receives a signal. In that case, if REMAINING
 * is not NULL, the remaining time is stored in the object pointed by it
 * @return:     0: The (relative) time specified by `time_point' has elapsed
 * @return:    -1: A signal was received while waiting, and `remaining' was filled in (if given)
 * @return: <= -2: Some other error occurred */
__NAMESPACE_LOCAL_USING_OR_IMPL(thrd_sleep64, __FORCELOCAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBCCALL thrd_sleep64)(struct timespec64 const *__time_point, struct timespec64 *__remaining) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(thrd_sleep64))(__time_point, __remaining); })
#endif /* thrd_sleep64... */
#endif /* __USE_TIME64 */
#ifdef __CRT_HAVE_thrd_exit
/* Terminate current thread execution, cleaning up any thread local
 * storage and freeing resources. Returns the value specified in RES
 * s.a. `pthread_exit()' */
__CDECLARE_VOID(__ATTR_NORETURN,,thrd_exit,(int __res),(__res))
#elif defined(__CRT_HAVE_pthread_exit)
#include <local/threads/thrd_exit.h>
/* Terminate current thread execution, cleaning up any thread local
 * storage and freeing resources. Returns the value specified in RES
 * s.a. `pthread_exit()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(thrd_exit, __FORCELOCAL __ATTR_NORETURN void (__LIBCCALL thrd_exit)(int __res) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(thrd_exit))(__res); })
#endif /* thrd_exit... */
#ifdef __CRT_HAVE_thrd_detach
/* Detach the thread identified by THR from the current
 * environment (it does not allow join or wait for it)
 * s.a. `pthread_detach()' */
__CDECLARE(,int,__NOTHROW_NCX,thrd_detach,(thrd_t __thr),(__thr))
#elif defined(__CRT_HAVE_pthread_detach)
#include <local/threads/thrd_detach.h>
/* Detach the thread identified by THR from the current
 * environment (it does not allow join or wait for it)
 * s.a. `pthread_detach()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(thrd_detach, __FORCELOCAL int __NOTHROW_NCX(__LIBCCALL thrd_detach)(thrd_t __thr) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(thrd_detach))(__thr); })
#endif /* thrd_detach... */
#ifdef __CRT_HAVE_thrd_join
/* Block current thread until execution of THR is complete.
 * In case that RES is not NULL, will store the return value of THR when exiting
 * s.a. `pthread_join()' */
__CDECLARE(,int,__NOTHROW_RPC,thrd_join,(thrd_t __thr, int *__res),(__thr,__res))
#elif defined(__CRT_HAVE_pthread_join)
#include <local/threads/thrd_join.h>
/* Block current thread until execution of THR is complete.
 * In case that RES is not NULL, will store the return value of THR when exiting
 * s.a. `pthread_join()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(thrd_join, __FORCELOCAL int __NOTHROW_RPC(__LIBCCALL thrd_join)(thrd_t __thr, int *__res) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(thrd_join))(__thr, __res); })
#endif /* thrd_join... */
#ifdef __CRT_HAVE_thrd_yield
/* Stop current thread execution and call the scheduler to decide which
 * thread should execute next. The current thread may be selected by the
 * scheduler to keep running
 * s.a. `pthread_yield()' */
__CDECLARE_VOID(,__NOTHROW_NCX,thrd_yield,(void),())
#elif defined(__CRT_HAVE_sched_yield)
/* Stop current thread execution and call the scheduler to decide which
 * thread should execute next. The current thread may be selected by the
 * scheduler to keep running
 * s.a. `pthread_yield()' */
__CREDIRECT_VOID(,__NOTHROW_NCX,thrd_yield,(void),sched_yield,())
#elif defined(__CRT_HAVE_pthread_yield)
/* Stop current thread execution and call the scheduler to decide which
 * thread should execute next. The current thread may be selected by the
 * scheduler to keep running
 * s.a. `pthread_yield()' */
__CREDIRECT_VOID(,__NOTHROW_NCX,thrd_yield,(void),pthread_yield,())
#endif /* thrd_yield... */


/* Mutex functions.  */

#ifdef __CRT_HAVE_mtx_init
/* Creates a new mutex object with type TYPE.
 * If successful the new object is pointed by MUTEX
 * s.a. `pthread_mutex_init()' */
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,mtx_init,(mtx_t *__restrict __mutex, int __type),(__mutex,__type))
#elif defined(__CRT_HAVE_pthread_mutex_init)
#include <local/threads/mtx_init.h>
/* Creates a new mutex object with type TYPE.
 * If successful the new object is pointed by MUTEX
 * s.a. `pthread_mutex_init()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(mtx_init, __FORCELOCAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBCCALL mtx_init)(mtx_t *__restrict __mutex, int __type) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(mtx_init))(__mutex, __type); })
#endif /* mtx_init... */
#ifdef __CRT_HAVE_mtx_lock
/* Block the current thread until the mutex pointed to by MUTEX is
 * unlocked.  In that case current thread will not be blocked
 * s.a. `pthread_mutex_lock()' */
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_RPC,mtx_lock,(mtx_t *__restrict __mutex),(__mutex))
#elif defined(__CRT_HAVE_pthread_mutex_lock)
#include <local/threads/mtx_lock.h>
/* Block the current thread until the mutex pointed to by MUTEX is
 * unlocked.  In that case current thread will not be blocked
 * s.a. `pthread_mutex_lock()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(mtx_lock, __FORCELOCAL __ATTR_NONNULL((1)) int __NOTHROW_RPC(__LIBCCALL mtx_lock)(mtx_t *__restrict __mutex) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(mtx_lock))(__mutex); })
#endif /* mtx_lock... */
#if defined(__CRT_HAVE_mtx_timedlock64) && defined(__USE_TIME_BITS64)
/* Block the current thread until the mutex pointed by MUTEX
 * is unlocked or time pointed by TIME_POINT is reached.
 * In case the mutex is unlock, the current thread will not be blocked
 * s.a. `pthread_mutex_timedlock()' */
__CREDIRECT(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,mtx_timedlock,(mtx_t *__restrict __mutex, struct timespec const *__restrict __time_point),mtx_timedlock64,(__mutex,__time_point))
#elif defined(__CRT_HAVE_mtx_timedlock) && !defined(__USE_TIME_BITS64)
/* Block the current thread until the mutex pointed by MUTEX
 * is unlocked or time pointed by TIME_POINT is reached.
 * In case the mutex is unlock, the current thread will not be blocked
 * s.a. `pthread_mutex_timedlock()' */
__CDECLARE(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,mtx_timedlock,(mtx_t *__restrict __mutex, struct timespec const *__restrict __time_point),(__mutex,__time_point))
#elif defined(__CRT_HAVE_pthread_mutex_timedlock) || defined(__CRT_HAVE_pthread_mutex_timedlock64)
#include <local/threads/mtx_timedlock.h>
/* Block the current thread until the mutex pointed by MUTEX
 * is unlocked or time pointed by TIME_POINT is reached.
 * In case the mutex is unlock, the current thread will not be blocked
 * s.a. `pthread_mutex_timedlock()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(mtx_timedlock, __FORCELOCAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBCCALL mtx_timedlock)(mtx_t *__restrict __mutex, struct timespec const *__restrict __time_point) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(mtx_timedlock))(__mutex, __time_point); })
#endif /* mtx_timedlock... */
#ifdef __USE_TIME64
#ifdef __CRT_HAVE_mtx_timedlock64
/* Block the current thread until the mutex pointed by MUTEX
 * is unlocked or time pointed by TIME_POINT is reached.
 * In case the mutex is unlock, the current thread will not be blocked
 * s.a. `pthread_mutex_timedlock()' */
__CDECLARE(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,mtx_timedlock64,(mtx_t *__restrict __mutex, struct timespec64 const *__restrict __time_point),(__mutex,__time_point))
#elif defined(__CRT_HAVE_mtx_timedlock) && (__SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__)
/* Block the current thread until the mutex pointed by MUTEX
 * is unlocked or time pointed by TIME_POINT is reached.
 * In case the mutex is unlock, the current thread will not be blocked
 * s.a. `pthread_mutex_timedlock()' */
__CREDIRECT(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,mtx_timedlock64,(mtx_t *__restrict __mutex, struct timespec64 const *__restrict __time_point),mtx_timedlock,(__mutex,__time_point))
#elif defined(__CRT_HAVE_pthread_mutex_timedlock) || defined(__CRT_HAVE_pthread_mutex_timedlock64)
#include <local/threads/mtx_timedlock64.h>
/* Block the current thread until the mutex pointed by MUTEX
 * is unlocked or time pointed by TIME_POINT is reached.
 * In case the mutex is unlock, the current thread will not be blocked
 * s.a. `pthread_mutex_timedlock()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(mtx_timedlock64, __FORCELOCAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBCCALL mtx_timedlock64)(mtx_t *__restrict __mutex, struct timespec64 const *__restrict __time_point) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(mtx_timedlock64))(__mutex, __time_point); })
#endif /* mtx_timedlock64... */
#endif /* __USE_TIME64 */
#ifdef __CRT_HAVE_mtx_trylock
/* Try to lock the mutex pointed by MUTEX without blocking.
 * If the mutex is free the current threads takes control of
 * it, otherwise it returns immediately
 * s.a. `pthread_mutex_trylock()' */
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,mtx_trylock,(mtx_t *__restrict __mutex),(__mutex))
#elif defined(__CRT_HAVE_pthread_mutex_trylock)
#include <local/threads/mtx_trylock.h>
/* Try to lock the mutex pointed by MUTEX without blocking.
 * If the mutex is free the current threads takes control of
 * it, otherwise it returns immediately
 * s.a. `pthread_mutex_trylock()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(mtx_trylock, __FORCELOCAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBCCALL mtx_trylock)(mtx_t *__restrict __mutex) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(mtx_trylock))(__mutex); })
#endif /* mtx_trylock... */
#ifdef __CRT_HAVE_mtx_unlock
/* Unlock the mutex pointed by MUTEX.
 * It may potentially awake other threads waiting on this mutex
 * s.a. `pthread_mutex_unlock()' */
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,mtx_unlock,(mtx_t *__restrict __mutex),(__mutex))
#elif defined(__CRT_HAVE_pthread_mutex_unlock)
#include <local/threads/mtx_unlock.h>
/* Unlock the mutex pointed by MUTEX.
 * It may potentially awake other threads waiting on this mutex
 * s.a. `pthread_mutex_unlock()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(mtx_unlock, __FORCELOCAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBCCALL mtx_unlock)(mtx_t *__restrict __mutex) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(mtx_unlock))(__mutex); })
#endif /* mtx_unlock... */
#ifdef __CRT_HAVE_mtx_destroy
/* Destroy the mutex object pointed by MUTEX
 * s.a. `pthread_mutex_destroy()' */
__CDECLARE_VOID(__ATTR_NONNULL((1)),__NOTHROW_NCX,mtx_destroy,(mtx_t *__restrict __mutex),(__mutex))
#elif defined(__CRT_HAVE_pthread_mutex_destroy)
/* Destroy the mutex object pointed by MUTEX
 * s.a. `pthread_mutex_destroy()' */
__CREDIRECT_VOID(__ATTR_NONNULL((1)),__NOTHROW_NCX,mtx_destroy,(mtx_t *__restrict __mutex),pthread_mutex_destroy,(__mutex))
#endif /* mtx_destroy... */
#ifdef __CRT_HAVE_call_once
/* Call function FUNC exactly once, even if invoked from several threads.
 * All calls must be made with the same FLAG object
 * s.a. `pthread_once()' */
__CDECLARE_VOID(__ATTR_NONNULL((1, 2)),__THROWING,call_once,(once_flag *__restrict __flag, __once_func_t __func),(__flag,__func))
#elif defined(__CRT_HAVE_pthread_once)
/* Call function FUNC exactly once, even if invoked from several threads.
 * All calls must be made with the same FLAG object
 * s.a. `pthread_once()' */
__CREDIRECT_VOID(__ATTR_NONNULL((1, 2)),__THROWING,call_once,(once_flag *__restrict __flag, __once_func_t __func),pthread_once,(__flag,__func))
#endif /* call_once... */


/* Condition variable functions.  */

#ifdef __CRT_HAVE_cnd_init
/* Initialize new condition variable pointed by COND
 * s.a. `pthread_cond_init()' */
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,cnd_init,(cnd_t *__restrict __cond),(__cond))
#elif defined(__CRT_HAVE_pthread_cond_init)
#include <local/threads/cnd_init.h>
/* Initialize new condition variable pointed by COND
 * s.a. `pthread_cond_init()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(cnd_init, __FORCELOCAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBCCALL cnd_init)(cnd_t *__restrict __cond) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(cnd_init))(__cond); })
#endif /* cnd_init... */
#ifdef __CRT_HAVE_cnd_signal
/* Unblock one thread that currently waits on condition variable pointed by COND
 * s.a. `pthread_cond_signal()' */
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,cnd_signal,(cnd_t *__restrict __cond),(__cond))
#elif defined(__CRT_HAVE_pthread_cond_signal)
#include <local/threads/cnd_signal.h>
/* Unblock one thread that currently waits on condition variable pointed by COND
 * s.a. `pthread_cond_signal()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(cnd_signal, __FORCELOCAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBCCALL cnd_signal)(cnd_t *__restrict __cond) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(cnd_signal))(__cond); })
#endif /* cnd_signal... */
#ifdef __CRT_HAVE_cnd_broadcast
/* Unblock all threads currently waiting on condition variable pointed by COND
 * s.a. `pthread_cond_broadcast()' */
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,cnd_broadcast,(cnd_t *__restrict __cond),(__cond))
#elif defined(__CRT_HAVE_pthread_cond_broadcast)
#include <local/threads/cnd_broadcast.h>
/* Unblock all threads currently waiting on condition variable pointed by COND
 * s.a. `pthread_cond_broadcast()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(cnd_broadcast, __FORCELOCAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBCCALL cnd_broadcast)(cnd_t *__restrict __cond) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(cnd_broadcast))(__cond); })
#endif /* cnd_broadcast... */
#ifdef __CRT_HAVE_cnd_wait
/* Block current thread on the condition variable pointed by COND
 * s.a. `pthread_cond_wait()' */
__CDECLARE(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,cnd_wait,(cnd_t *__restrict __cond, mtx_t *__restrict __mutex),(__cond,__mutex))
#elif defined(__CRT_HAVE_pthread_cond_wait)
#include <local/threads/cnd_wait.h>
/* Block current thread on the condition variable pointed by COND
 * s.a. `pthread_cond_wait()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(cnd_wait, __FORCELOCAL __ATTR_NONNULL((1, 2)) int __NOTHROW_RPC(__LIBCCALL cnd_wait)(cnd_t *__restrict __cond, mtx_t *__restrict __mutex) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(cnd_wait))(__cond, __mutex); })
#endif /* cnd_wait... */
#if defined(__CRT_HAVE_cnd_timedwait64) && defined(__USE_TIME_BITS64)
/* Block current thread on the condition variable until condition variable
 * pointed by COND is signaled or time pointed by TIME_POINT is reached
 * s.a. `pthread_cond_timedwait()' */
__CREDIRECT(__ATTR_NONNULL((1, 2, 3)),int,__NOTHROW_RPC,cnd_timedwait,(cnd_t *__restrict __cond, mtx_t *__restrict __mutex, struct timespec const *__restrict __time_point),cnd_timedwait64,(__cond,__mutex,__time_point))
#elif defined(__CRT_HAVE_cnd_timedwait) && !defined(__USE_TIME_BITS64)
/* Block current thread on the condition variable until condition variable
 * pointed by COND is signaled or time pointed by TIME_POINT is reached
 * s.a. `pthread_cond_timedwait()' */
__CDECLARE(__ATTR_NONNULL((1, 2, 3)),int,__NOTHROW_RPC,cnd_timedwait,(cnd_t *__restrict __cond, mtx_t *__restrict __mutex, struct timespec const *__restrict __time_point),(__cond,__mutex,__time_point))
#elif defined(__CRT_HAVE_pthread_cond_timedwait) || defined(__CRT_HAVE_pthread_cond_timedwait64)
#include <local/threads/cnd_timedwait.h>
/* Block current thread on the condition variable until condition variable
 * pointed by COND is signaled or time pointed by TIME_POINT is reached
 * s.a. `pthread_cond_timedwait()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(cnd_timedwait, __FORCELOCAL __ATTR_NONNULL((1, 2, 3)) int __NOTHROW_RPC(__LIBCCALL cnd_timedwait)(cnd_t *__restrict __cond, mtx_t *__restrict __mutex, struct timespec const *__restrict __time_point) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(cnd_timedwait))(__cond, __mutex, __time_point); })
#endif /* cnd_timedwait... */
#ifdef __USE_TIME64
#ifdef __CRT_HAVE_cnd_timedwait64
/* Block current thread on the condition variable until condition variable
 * pointed by COND is signaled or time pointed by TIME_POINT is reached
 * s.a. `pthread_cond_timedwait()' */
__CDECLARE(__ATTR_NONNULL((1, 2, 3)),int,__NOTHROW_RPC,cnd_timedwait64,(cnd_t *__restrict __cond, mtx_t *__restrict __mutex, struct timespec64 const *__restrict __time_point),(__cond,__mutex,__time_point))
#elif defined(__CRT_HAVE_cnd_timedwait) && (__SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__)
/* Block current thread on the condition variable until condition variable
 * pointed by COND is signaled or time pointed by TIME_POINT is reached
 * s.a. `pthread_cond_timedwait()' */
__CREDIRECT(__ATTR_NONNULL((1, 2, 3)),int,__NOTHROW_RPC,cnd_timedwait64,(cnd_t *__restrict __cond, mtx_t *__restrict __mutex, struct timespec64 const *__restrict __time_point),cnd_timedwait,(__cond,__mutex,__time_point))
#elif defined(__CRT_HAVE_pthread_cond_timedwait) || defined(__CRT_HAVE_pthread_cond_timedwait64)
#include <local/threads/cnd_timedwait64.h>
/* Block current thread on the condition variable until condition variable
 * pointed by COND is signaled or time pointed by TIME_POINT is reached
 * s.a. `pthread_cond_timedwait()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(cnd_timedwait64, __FORCELOCAL __ATTR_NONNULL((1, 2, 3)) int __NOTHROW_RPC(__LIBCCALL cnd_timedwait64)(cnd_t *__restrict __cond, mtx_t *__restrict __mutex, struct timespec64 const *__restrict __time_point) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(cnd_timedwait64))(__cond, __mutex, __time_point); })
#endif /* cnd_timedwait64... */
#endif /* __USE_TIME64 */
#ifdef __CRT_HAVE_cnd_destroy
/* Destroy condition variable pointed by cond and free all of its resources
 * s.a. `pthread_cond_destroy()' */
__CDECLARE_VOID(,__NOTHROW_NCX,cnd_destroy,(cnd_t *__COND),(__COND))
#elif defined(__CRT_HAVE_pthread_cond_destroy)
/* Destroy condition variable pointed by cond and free all of its resources
 * s.a. `pthread_cond_destroy()' */
__CREDIRECT_VOID(,__NOTHROW_NCX,cnd_destroy,(cnd_t *__COND),pthread_cond_destroy,(__COND))
#endif /* cnd_destroy... */


/* Thread specific storage functions.  */

#ifdef __CRT_HAVE_tss_create
/* Create new thread-specific storage key and stores it in the object pointed by TSS_ID.
 * If DESTRUCTOR is not NULL, the function will be called when the thread terminates
 * s.a. `pthread_key_create()' */
__CDECLARE(,int,__NOTHROW_NCX,tss_create,(tss_t *__tss_id, tss_dtor_t __destructor),(__tss_id,__destructor))
#elif defined(__CRT_HAVE_pthread_key_create)
#include <local/threads/tss_create.h>
/* Create new thread-specific storage key and stores it in the object pointed by TSS_ID.
 * If DESTRUCTOR is not NULL, the function will be called when the thread terminates
 * s.a. `pthread_key_create()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(tss_create, __FORCELOCAL int __NOTHROW_NCX(__LIBCCALL tss_create)(tss_t *__tss_id, tss_dtor_t __destructor) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(tss_create))(__tss_id, __destructor); })
#endif /* tss_create... */
#ifdef __CRT_HAVE_tss_get
/* Return the value held in thread-specific storage
 * for the current thread identified by TSS_ID
 * s.a. `pthread_getspecific()' */
__CDECLARE(,void *,__NOTHROW_NCX,tss_get,(tss_t __tss_id),(__tss_id))
#elif defined(__CRT_HAVE_pthread_getspecific)
/* Return the value held in thread-specific storage
 * for the current thread identified by TSS_ID
 * s.a. `pthread_getspecific()' */
__CREDIRECT(,void *,__NOTHROW_NCX,tss_get,(tss_t __tss_id),pthread_getspecific,(__tss_id))
#endif /* tss_get... */
#ifdef __CRT_HAVE_tss_set
/* Sets the value of the thread-specific storage
 * identified by TSS_ID for the current thread to VAL
 * s.a. `pthread_setspecific()' */
__CDECLARE(,int,__NOTHROW_NCX,tss_set,(tss_t __tss_id, void *__val),(__tss_id,__val))
#elif defined(__CRT_HAVE_pthread_setspecific)
#include <local/threads/tss_set.h>
/* Sets the value of the thread-specific storage
 * identified by TSS_ID for the current thread to VAL
 * s.a. `pthread_setspecific()' */
__NAMESPACE_LOCAL_USING_OR_IMPL(tss_set, __FORCELOCAL int __NOTHROW_NCX(__LIBCCALL tss_set)(tss_t __tss_id, void *__val) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(tss_set))(__tss_id, __val); })
#endif /* tss_set... */
#ifdef __CRT_HAVE_tss_delete
/* Destroys the thread-specific storage identified by TSS_ID.
 * The destructor of the TSS will not be called upon thread exit
 * s.a. `pthread_key_delete()' */
__CDECLARE_VOID(,__NOTHROW_NCX,tss_delete,(tss_t __tss_id),(__tss_id))
#elif defined(__CRT_HAVE_pthread_key_delete)
/* Destroys the thread-specific storage identified by TSS_ID.
 * The destructor of the TSS will not be called upon thread exit
 * s.a. `pthread_key_delete()' */
__CREDIRECT_VOID(,__NOTHROW_NCX,tss_delete,(tss_t __tss_id),pthread_key_delete,(__tss_id))
#endif /* tss_delete... */

#endif /* __CC__ */

__SYSDECL_END

#endif /* !_THREADS_H */
