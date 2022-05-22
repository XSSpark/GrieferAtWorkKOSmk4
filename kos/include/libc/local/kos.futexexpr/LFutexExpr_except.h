/* HASH CRC-32:0x620bcb7d */
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
#ifndef __local_LFutexExpr_except_defined
#define __local_LFutexExpr_except_defined
#include <__crt.h>
#if defined(__CRT_HAVE_LFutexExpr) || defined(__CRT_HAVE_LFutexExpr64)
#include <kos/anno.h>
#include <bits/types.h>
#include <bits/os/timespec.h>
#include <kos/bits/futex-expr.h>
__NAMESPACE_LOCAL_BEGIN
#if !defined(__local___localdep_crt_LFutexExpr32_except_defined) && defined(__CRT_HAVE_LFutexExpr)
#define __local___localdep_crt_LFutexExpr32_except_defined
__CREDIRECT(__ATTR_IN(3) __ATTR_IN_OPT(4) __ATTR_NONNULL((1)),int,__NOTHROW_RPC,__localdep_crt_LFutexExpr32_except,(__uintptr_t *__ulockaddr, void *__base, struct lfutexexpr const *__expr, struct __timespec32 const *__timeout, unsigned int __timeout_flags),LFutexExpr,(__ulockaddr,__base,__expr,__timeout,__timeout_flags))
#endif /* !__local___localdep_crt_LFutexExpr32_except_defined && __CRT_HAVE_LFutexExpr */
#if !defined(__local___localdep_crt_LFutexExpr64_except_defined) && defined(__CRT_HAVE_LFutexExpr64)
#define __local___localdep_crt_LFutexExpr64_except_defined
__CREDIRECT(__ATTR_IN(3) __ATTR_IN_OPT(4) __ATTR_NONNULL((1)),int,__NOTHROW_RPC,__localdep_crt_LFutexExpr64_except,(__uintptr_t *__ulockaddr, void *__base, struct lfutexexpr const *__expr, struct __timespec64 const *__timeout, unsigned int __timeout_flags),LFutexExpr64,(__ulockaddr,__base,__expr,__timeout,__timeout_flags))
#endif /* !__local___localdep_crt_LFutexExpr64_except_defined && __CRT_HAVE_LFutexExpr64 */
__LOCAL_LIBC(LFutexExpr_except) __ATTR_IN(3) __ATTR_IN_OPT(4) __ATTR_NONNULL((1)) int
(__LIBCCALL __LIBC_LOCAL_NAME(LFutexExpr_except))(__uintptr_t *__ulockaddr, void *__base, struct lfutexexpr const *__expr, struct timespec const *__timeout, unsigned int __timeout_flags) __THROWS(...) {
#ifdef __CRT_HAVE_LFutexExpr
	struct __timespec32 __tms32;
	if (!__timeout)
		return (__NAMESPACE_LOCAL_SYM __localdep_crt_LFutexExpr32_except)(__ulockaddr, __base, __expr, __NULLPTR, __timeout_flags);
	__tms32.tv_sec  = (__time32_t)__timeout->tv_sec;
	__tms32.tv_nsec = __timeout->tv_nsec;
	return (__NAMESPACE_LOCAL_SYM __localdep_crt_LFutexExpr32_except)(__ulockaddr, __base, __expr, &__tms32, __timeout_flags);
#else /* __CRT_HAVE_LFutexExpr */
	struct __timespec64 __tms64;
	if (!__timeout)
		return (__NAMESPACE_LOCAL_SYM __localdep_crt_LFutexExpr64_except)(__ulockaddr, __base, __expr, __NULLPTR, __timeout_flags);
	__tms64.tv_sec  = (__time64_t)__timeout->tv_sec;
	__tms64.tv_nsec = __timeout->tv_nsec;
	return (__NAMESPACE_LOCAL_SYM __localdep_crt_LFutexExpr64_except)(__ulockaddr, __base, __expr, &__tms64, __timeout_flags);
#endif /* !__CRT_HAVE_LFutexExpr */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_LFutexExpr_except_defined
#define __local___localdep_LFutexExpr_except_defined
#define __localdep_LFutexExpr_except __LIBC_LOCAL_NAME(LFutexExpr_except)
#endif /* !__local___localdep_LFutexExpr_except_defined */
#else /* __CRT_HAVE_LFutexExpr || __CRT_HAVE_LFutexExpr64 */
#undef __local_LFutexExpr_except_defined
#endif /* !__CRT_HAVE_LFutexExpr && !__CRT_HAVE_LFutexExpr64 */
#endif /* !__local_LFutexExpr_except_defined */
