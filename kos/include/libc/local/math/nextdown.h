/* HASH CRC-32:0x5d56bda2 */
/* Copyright (c) 2019-2025 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2025 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_nextdown_defined
#define __local_nextdown_defined
#include <__crt.h>
#include <ieee754.h>
#if defined(__CRT_HAVE_nextup) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_nextup_defined
#define __local___localdep_nextup_defined
#ifdef __CRT_HAVE_nextup
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_nextup,(double __x),nextup,(__x))
#elif defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
__NAMESPACE_LOCAL_END
#include <libc/local/math/nextup.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_nextup __LIBC_LOCAL_NAME(nextup)
#else /* ... */
#undef __local___localdep_nextup_defined
#endif /* !... */
#endif /* !__local___localdep_nextup_defined */
__LOCAL_LIBC(nextdown) __ATTR_CONST __ATTR_WUNUSED double
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(nextdown))(double __x) {
	return -(__NAMESPACE_LOCAL_SYM __localdep_nextup)(-__x);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_nextdown_defined
#define __local___localdep_nextdown_defined
#define __localdep_nextdown __LIBC_LOCAL_NAME(nextdown)
#endif /* !__local___localdep_nextdown_defined */
#else /* __CRT_HAVE_nextup || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
#undef __local_nextdown_defined
#endif /* !__CRT_HAVE_nextup && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
#endif /* !__local_nextdown_defined */
