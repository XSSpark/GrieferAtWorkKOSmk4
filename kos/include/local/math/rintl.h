/* HASH CRC-32:0x57e5da55 */
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
#ifndef __local_rintl_defined
#include <ieee754.h>
#if defined(__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || defined(__CRT_HAVE_rint) || defined(__CRT_HAVE___rint)
#define __local_rintl_defined 1
#include <libm/rint.h>
/* Dependency: "rint" from "math" */
#ifndef ____localdep_rint_defined
#define ____localdep_rint_defined 1
#if __has_builtin(__builtin_rint) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_rint)
/* Return the integer nearest X in the direction of the prevailing rounding mode */
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_rint,(double __x),rint,{ return __builtin_rint(__x); })
#elif defined(__CRT_HAVE_rint)
/* Return the integer nearest X in the direction of the prevailing rounding mode */
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_rint,(double __x),rint,(__x))
#elif defined(__CRT_HAVE___rint)
/* Return the integer nearest X in the direction of the prevailing rounding mode */
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,double,__NOTHROW,__localdep_rint,(double __x),__rint,(__x))
#else /* LIBC: rint */
#include <ieee754.h>
#if defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
#include <local/math/rint.h>
/* Return the integer nearest X in the direction of the prevailing rounding mode */
#define __localdep_rint (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(rint))
#else /* CUSTOM: rint */
#undef ____localdep_rint_defined
#endif /* rint... */
#endif /* rint... */
#endif /* !____localdep_rint_defined */

__NAMESPACE_LOCAL_BEGIN
/* Return the integer nearest X in the direction of the prevailing rounding mode */
__LOCAL_LIBC(rintl) __ATTR_CONST __ATTR_WUNUSED __LONGDOUBLE
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(rintl))(__LONGDOUBLE __x) {
#line 904 "kos/src/libc/magic/math.c"
#ifdef __LIBM_MATHFUNL
	return __LIBM_MATHFUNL(rint, __x);
#else /* __LIBM_MATHFUNL */
	return (__LONGDOUBLE)__localdep_rint((double)__x);
#endif /* !__LIBM_MATHFUNL */
}
__NAMESPACE_LOCAL_END
#endif /* __IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ || __CRT_HAVE_rint || __CRT_HAVE___rint */
#endif /* !__local_rintl_defined */
