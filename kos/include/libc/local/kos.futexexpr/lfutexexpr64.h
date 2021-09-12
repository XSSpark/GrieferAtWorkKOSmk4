/* HASH CRC-32:0xabf196c4 */
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
#ifndef __local_lfutexexpr64_defined
#define __local_lfutexexpr64_defined 1
#include <__crt.h>
#ifdef __CRT_HAVE_lfutexexpr
#include <bits/os/timespec.h>
#include <kos/bits/futex-expr.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_lfutexexpr32_defined
#define __local___localdep_lfutexexpr32_defined 1
__CREDIRECT(__ATTR_NONNULL((3)),int,__NOTHROW_RPC,__localdep_lfutexexpr32,(void *__base, __SIZE_TYPE__ __exprc, struct lfutexexpr const *__exprv, struct __timespec64 const *__timeout, unsigned int __timeout_flags),lfutexexpr,(__base,__exprc,__exprv,__timeout,__timeout_flags))
#endif /* !__local___localdep_lfutexexpr32_defined */
__LOCAL_LIBC(lfutexexpr64) __ATTR_NONNULL((3)) int
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(lfutexexpr64))(void *__base, __SIZE_TYPE__ __exprc, struct lfutexexpr const *__exprv, struct __timespec64 const *__timeout, unsigned int __timeout_flags) {
	struct __timespec32 __tms32;
	if (!__timeout)
		return __NAMESPACE_LOCAL_SYM __localdep_lfutexexpr32(__base, __exprc, __exprv, __NULLPTR, 0);
	__tms32.tv_sec  = (__time32_t)__timeout->tv_sec;
	__tms32.tv_nsec = __timeout->tv_nsec;
	return __NAMESPACE_LOCAL_SYM __localdep_lfutexexpr32(__base, __exprc, __exprv, &__tms32, __timeout_flags);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_lfutexexpr64_defined
#define __local___localdep_lfutexexpr64_defined 1
#define __localdep_lfutexexpr64 __LIBC_LOCAL_NAME(lfutexexpr64)
#endif /* !__local___localdep_lfutexexpr64_defined */
#else /* __CRT_HAVE_lfutexexpr */
#undef __local_lfutexexpr64_defined
#endif /* !__CRT_HAVE_lfutexexpr */
#endif /* !__local_lfutexexpr64_defined */
