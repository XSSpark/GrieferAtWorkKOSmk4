/* HASH CRC-32:0xcb132730 */
/* Copyright (c) 2019-2024 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2024 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_futex_wakemask_defined
#define __local_futex_wakemask_defined
#include <__crt.h>
#include <bits/types.h>
#if defined(__CRT_HAVE_lfutex64) || defined(__CRT_HAVE_lfutex)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_lfutex64_defined
#define __local___localdep_lfutex64_defined
#if defined(__CRT_HAVE_lfutex) && __SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__
__CVREDIRECT(__ATTR_NONNULL((1)),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_lfutex64,(__uintptr_t *__uaddr, __syscall_ulong_t __futex_op, __uintptr_t __val),lfutex,(__uaddr,__futex_op,__val),__val,2,(void *,__UINTPTR_TYPE__))
#elif defined(__CRT_HAVE_lfutex64)
__CVREDIRECT(__ATTR_NONNULL((1)),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_lfutex64,(__uintptr_t *__uaddr, __syscall_ulong_t __futex_op, __uintptr_t __val),lfutex64,(__uaddr,__futex_op,__val),__val,2,(void *,__UINTPTR_TYPE__))
#elif defined(__CRT_HAVE_lfutex)
__NAMESPACE_LOCAL_END
#include <libc/local/kos.futex/lfutex64.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_lfutex64 __LIBC_LOCAL_NAME(lfutex64)
#else /* ... */
#undef __local___localdep_lfutex64_defined
#endif /* !... */
#endif /* !__local___localdep_lfutex64_defined */
__NAMESPACE_LOCAL_END
#include <kos/asm/futex.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(futex_wakemask) __ATTR_NONNULL((1)) __SSIZE_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(futex_wakemask))(__uintptr_t *__uaddr, __SIZE_TYPE__ __max_wake, __uintptr_t __mask_and, __uintptr_t __mask_or) {
	return (__NAMESPACE_LOCAL_SYM __localdep_lfutex64)(__uaddr, LFUTEX_WAKEMASK, __max_wake, __mask_and, __mask_or);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_futex_wakemask_defined
#define __local___localdep_futex_wakemask_defined
#define __localdep_futex_wakemask __LIBC_LOCAL_NAME(futex_wakemask)
#endif /* !__local___localdep_futex_wakemask_defined */
#else /* __CRT_HAVE_lfutex64 || __CRT_HAVE_lfutex */
#undef __local_futex_wakemask_defined
#endif /* !__CRT_HAVE_lfutex64 && !__CRT_HAVE_lfutex */
#endif /* !__local_futex_wakemask_defined */
