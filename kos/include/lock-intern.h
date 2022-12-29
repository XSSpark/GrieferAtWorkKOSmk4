/* HASH CRC-32:0x118d16dd */
/* Copyright (c) 2019-2022 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2022 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
/* (#) Portability: GNU C Library (/mach/lock-intern.h) */
/* (#) Portability: GNU Hurd      (/usr/include/lock-intern.h) */
#ifndef _LOCK_INTERN_H
#define _LOCK_INTERN_H 1

#include "__stdinc.h"
#include "__crt.h"

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#include <kos/sched/shared-lock.h>
#include <hybrid/sched/__yield.h>

#ifdef __CC__
__SYSDECL_BEGIN

typedef unsigned int __spin_lock_t;
#define __SPIN_LOCK_INITIALIZER 0

#ifndef __mutex_defined
#define __mutex_defined
struct mutex {
	__spin_lock_t __held;   /* The actually used lock */
	__spin_lock_t __lock;   /* unused */
	const char   *__name;   /* unused */
	void         *__head;   /* unused */
	void         *__tail;   /* unused */
	void         *__holder; /* unused */
};
#define MUTEX_INITIALIZER { 0, 0, __NULLPTR, __NULLPTR, __NULLPTR, __NULLPTR }
#endif /* !__mutex_defined */

#ifdef __CRT_HAVE___spin_lock_init
__CEIDECLARE(,void,__NOTHROW_NCX,__spin_lock_init,(__spin_lock_t *__lock),{ *__lock = 0; })
#else /* __CRT_HAVE___spin_lock_init */
__LOCAL void __NOTHROW_NCX(__LIBCCALL __spin_lock_init)(__spin_lock_t *__lock) { *__lock = 0; }
#endif /* !__CRT_HAVE___spin_lock_init */
#if defined(__CRT_HAVE___spin_lock_solid) && defined(__shared_lock_tryacquire)
__CEIDECLARE(__ATTR_INOUT(1),void,__NOTHROW_NCX,__spin_lock_solid,(__spin_lock_t *__lock),{ while (!__shared_lock_tryacquire((struct shared_lock *)__lock)) __hybrid_yield(); })
#elif defined(__CRT_HAVE___spin_lock_solid)
__CDECLARE_VOID(__ATTR_INOUT(1),__NOTHROW_NCX,__spin_lock_solid,(__spin_lock_t *__lock),(__lock))
#elif defined(__shared_lock_tryacquire)
__LOCAL __ATTR_INOUT(1) void __NOTHROW_NCX(__LIBCCALL __spin_lock_solid)(__spin_lock_t *__lock) { while (!__shared_lock_tryacquire((struct shared_lock *)__lock)) __hybrid_yield(); }
#endif /* ... */
#ifdef __CRT_HAVE___spin_lock
__CDECLARE_VOID(__ATTR_INOUT(1),__NOTHROW_NCX,__spin_lock,(__spin_lock_t *__lock),(__lock))
#elif defined(__CRT_HAVE_shared_lock_acquire)
__CREDIRECT_VOID(__ATTR_INOUT(1),__NOTHROW_NCX,__spin_lock,(__spin_lock_t *__lock),shared_lock_acquire,(__lock))
#else /* ... */
#include <libc/local/kos.sched.shared-lock/shared_lock_acquire.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INOUT(1) void __NOTHROW_NCX(__LIBCCALL __spin_lock)(__spin_lock_t *__lock) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(shared_lock_acquire))((struct shared_lock *)__lock); }
#endif /* !... */
#if defined(__CRT_HAVE___spin_unlock) && defined(__shared_lock_release)
__CEIDECLARE(__ATTR_INOUT(1),void,__NOTHROW_NCX,__spin_unlock,(__spin_lock_t *__lock),{ __shared_lock_release((struct shared_lock *)__lock); })
#elif defined(__CRT_HAVE___spin_unlock)
__CDECLARE_VOID(__ATTR_INOUT(1),__NOTHROW_NCX,__spin_unlock,(__spin_lock_t *__lock),(__lock))
#elif defined(__shared_lock_release)
__LOCAL __ATTR_INOUT(1) void __NOTHROW_NCX(__LIBCCALL __spin_unlock)(__spin_lock_t *__lock) { __shared_lock_release((struct shared_lock *)__lock); }
#endif /* ... */
#if defined(__CRT_HAVE___spin_try_lock) && defined(__shared_lock_tryacquire)
__CEIDECLARE(__ATTR_INOUT(1),int,__NOTHROW_NCX,__spin_try_lock,(__spin_lock_t *__lock),{ return __shared_lock_tryacquire((struct shared_lock *)__lock); })
#elif defined(__CRT_HAVE___spin_try_lock)
__CDECLARE(__ATTR_INOUT(1),int,__NOTHROW_NCX,__spin_try_lock,(__spin_lock_t *__lock),(__lock))
#elif defined(__shared_lock_tryacquire)
__LOCAL __ATTR_INOUT(1) int __NOTHROW_NCX(__LIBCCALL __spin_try_lock)(__spin_lock_t *__lock) { return __shared_lock_tryacquire((struct shared_lock *)__lock); }
#endif /* ... */
#if defined(__CRT_HAVE___spin_lock_locked) && defined(__shared_lock_acquired)
__CEIDECLARE(__ATTR_IN(1),int,__NOTHROW_NCX,__spin_lock_locked,(__spin_lock_t __KOS_FIXED_CONST *__lock),{ return __shared_lock_acquired((struct shared_lock *)__lock); })
#elif defined(__CRT_HAVE___spin_lock_locked)
__CDECLARE(__ATTR_IN(1),int,__NOTHROW_NCX,__spin_lock_locked,(__spin_lock_t __KOS_FIXED_CONST *__lock),(__lock))
#elif defined(__shared_lock_acquired)
__LOCAL __ATTR_IN(1) int __NOTHROW_NCX(__LIBCCALL __spin_lock_locked)(__spin_lock_t __KOS_FIXED_CONST *__lock) { return __shared_lock_acquired((struct shared_lock *)__lock); }
#endif /* ... */



/************************************************************************/
/* """Mutex""" API                                                      */
/************************************************************************/

#ifdef __CRT_HAVE___mutex_init
__CEIDECLARE(,void,__NOTHROW_NCX,__mutex_init,(void *__lock),{ *(unsigned int *)__lock = 0; })
#else /* __CRT_HAVE___mutex_init */
__LOCAL void __NOTHROW_NCX(__LIBCCALL __mutex_init)(void *__lock) { *(unsigned int *)__lock = 0; }
#endif /* !__CRT_HAVE___mutex_init */
#ifdef __CRT_HAVE___mutex_lock
__CDECLARE_VOID(__ATTR_OUT(1),__NOTHROW_NCX,__mutex_lock,(void *__lock),(__lock))
#elif defined(__CRT_HAVE_shared_lock_acquire)
__CREDIRECT_VOID(__ATTR_OUT(1),__NOTHROW_NCX,__mutex_lock,(void *__lock),shared_lock_acquire,(__lock))
#else /* ... */
#include <libc/local/kos.sched.shared-lock/shared_lock_acquire.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_OUT(1) void __NOTHROW_NCX(__LIBCCALL __mutex_lock)(void *__lock) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(shared_lock_acquire))((struct shared_lock *)__lock); }
#endif /* !... */
#if defined(__CRT_HAVE___mutex_unlock) && defined(__shared_lock_release)
__CEIDECLARE(__ATTR_OUT(1),void,__NOTHROW_NCX,__mutex_unlock,(void *__lock),{ __shared_lock_release((struct shared_lock *)__lock); })
#elif defined(__CRT_HAVE___mutex_unlock)
__CDECLARE_VOID(__ATTR_OUT(1),__NOTHROW_NCX,__mutex_unlock,(void *__lock),(__lock))
#elif defined(__shared_lock_release)
__LOCAL __ATTR_OUT(1) void __NOTHROW_NCX(__LIBCCALL __mutex_unlock)(void *__lock) { __shared_lock_release((struct shared_lock *)__lock); }
#endif /* ... */
#if defined(__CRT_HAVE___mutex_trylock) && defined(__shared_lock_tryacquire)
__CEIDECLARE(__ATTR_OUT(1),int,__NOTHROW_NCX,__mutex_trylock,(void *__lock),{ return __shared_lock_tryacquire((struct shared_lock *)__lock); })
#elif defined(__CRT_HAVE___mutex_trylock)
__CDECLARE(__ATTR_OUT(1),int,__NOTHROW_NCX,__mutex_trylock,(void *__lock),(__lock))
#elif defined(__shared_lock_tryacquire)
__LOCAL __ATTR_OUT(1) int __NOTHROW_NCX(__LIBCCALL __mutex_trylock)(void *__lock) { return __shared_lock_tryacquire((struct shared_lock *)__lock); }
#endif /* ... */

__SYSDECL_END
#endif /* __CC__ */

#endif /* !_LOCK_INTERN_H */
