/* HASH CRC-32:0xa266759 */
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
#ifndef __local_sinf_defined
#define __local_sinf_defined
#include <__crt.h>
#include <ieee754.h>
#if defined(__IEEE754_DOUBLE_TYPE_IS_FLOAT__) || defined(__IEEE754_FLOAT_TYPE_IS_FLOAT__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__) || defined(__CRT_HAVE_sin) || defined(__CRT_HAVE___sin) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_sin_defined
#define __local___localdep_sin_defined
#if __has_builtin(__builtin_sin) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_sin)
__CEIREDIRECT(__ATTR_WUNUSED __DECL_SIMD_sin,double,__NOTHROW,__localdep_sin,(double __x),sin,{ return __builtin_sin(__x); })
#elif defined(__CRT_HAVE_sin)
__CREDIRECT(__ATTR_WUNUSED __DECL_SIMD_sin,double,__NOTHROW,__localdep_sin,(double __x),sin,(__x))
#elif defined(__CRT_HAVE___sin)
__CREDIRECT(__ATTR_WUNUSED __DECL_SIMD_sin,double,__NOTHROW,__localdep_sin,(double __x),__sin,(__x))
#elif defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
__NAMESPACE_LOCAL_END
#include <libc/local/math/sin.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_sin __LIBC_LOCAL_NAME(sin)
#else /* ... */
#undef __local___localdep_sin_defined
#endif /* !... */
#endif /* !__local___localdep_sin_defined */
__NAMESPACE_LOCAL_END
#include <libm/isnan.h>
#include <libm/sin.h>
#include <libm/matherr.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(sinf) __ATTR_WUNUSED __DECL_SIMD_sinf float
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(sinf))(float __x) {
#if defined(__IEEE754_DOUBLE_TYPE_IS_FLOAT__) || defined(__IEEE754_FLOAT_TYPE_IS_FLOAT__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__)


	float __result = __LIBM_MATHFUNF(sin, __x);
	if (__LIBM_MATHFUNIF(isnan, __result) && !__LIBM_MATHFUNIF(isnan, __x))
		__result = __kernel_standard_f(__x, __x, __result, __LIBM_KMATHERRF_SIN_INF);
	return __result;
#else /* __IEEE754_DOUBLE_TYPE_IS_FLOAT__ || __IEEE754_FLOAT_TYPE_IS_FLOAT__ || __IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__ */
	return (float)(__NAMESPACE_LOCAL_SYM __localdep_sin)((double)__x);
#endif /* !__IEEE754_DOUBLE_TYPE_IS_FLOAT__ && !__IEEE754_FLOAT_TYPE_IS_FLOAT__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__ */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_sinf_defined
#define __local___localdep_sinf_defined
#define __localdep_sinf __LIBC_LOCAL_NAME(sinf)
#endif /* !__local___localdep_sinf_defined */
#else /* __IEEE754_DOUBLE_TYPE_IS_FLOAT__ || __IEEE754_FLOAT_TYPE_IS_FLOAT__ || __IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__ || __CRT_HAVE_sin || __CRT_HAVE___sin || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
#undef __local_sinf_defined
#endif /* !__IEEE754_DOUBLE_TYPE_IS_FLOAT__ && !__IEEE754_FLOAT_TYPE_IS_FLOAT__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__ && !__CRT_HAVE_sin && !__CRT_HAVE___sin && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
#endif /* !__local_sinf_defined */
