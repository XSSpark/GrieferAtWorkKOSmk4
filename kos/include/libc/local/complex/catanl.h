/* HASH CRC-32:0x3e572b35 */
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
#ifndef __local_catanl_defined
#define __local_catanl_defined
#include <__crt.h>
#include <hybrid/typecore.h>
#include <ieee754.h>
#if ((defined(__CRT_HAVE_atan2l) || defined(__CRT_HAVE___atan2l) || defined(__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__CRT_HAVE_atan2) || defined(__CRT_HAVE___atan2) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) && (defined(__CRT_HAVE_logl) || defined(__CRT_HAVE___logl) || defined(__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__CRT_HAVE_log) || defined(__CRT_HAVE___log) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__))) || defined(__CRT_HAVE_catan) || ((defined(__CRT_HAVE_atan2) || defined(__CRT_HAVE___atan2) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) && (defined(__CRT_HAVE_log) || defined(__CRT_HAVE___log) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__redupil_defined
#define __local___localdep__redupil_defined
#if defined(__CRT_HAVE__redupi) && defined(__ARCH_LONG_DOUBLE_IS_DOUBLE)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep__redupil,(__LONGDOUBLE __x),_redupi,(__x))
#else /* __CRT_HAVE__redupi && __ARCH_LONG_DOUBLE_IS_DOUBLE */
__NAMESPACE_LOCAL_END
#include <libc/local/complex/_redupil.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__redupil __LIBC_LOCAL_NAME(_redupil)
#endif /* !__CRT_HAVE__redupi || !__ARCH_LONG_DOUBLE_IS_DOUBLE */
#endif /* !__local___localdep__redupil_defined */
#ifndef __local___localdep_atan2l_defined
#define __local___localdep_atan2l_defined
#if __has_builtin(__builtin_atan2l) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_atan2l)
__CEIREDIRECT(__ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_atan2l,(__LONGDOUBLE __y, __LONGDOUBLE __x),atan2l,{ return __builtin_atan2l(__y, __x); })
#elif defined(__CRT_HAVE_atan2l)
__CREDIRECT(__ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_atan2l,(__LONGDOUBLE __y, __LONGDOUBLE __x),atan2l,(__y,__x))
#elif defined(__CRT_HAVE___atan2l)
__CREDIRECT(__ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_atan2l,(__LONGDOUBLE __y, __LONGDOUBLE __x),__atan2l,(__y,__x))
#elif defined(__CRT_HAVE_atan2) && defined(__ARCH_LONG_DOUBLE_IS_DOUBLE)
__CREDIRECT(__ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_atan2l,(__LONGDOUBLE __y, __LONGDOUBLE __x),atan2,(__y,__x))
#elif defined(__CRT_HAVE___atan2) && defined(__ARCH_LONG_DOUBLE_IS_DOUBLE)
__CREDIRECT(__ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_atan2l,(__LONGDOUBLE __y, __LONGDOUBLE __x),__atan2,(__y,__x))
#elif defined(__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__CRT_HAVE_atan2) || defined(__CRT_HAVE___atan2) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
__NAMESPACE_LOCAL_END
#include <libc/local/math/atan2l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_atan2l __LIBC_LOCAL_NAME(atan2l)
#else /* ... */
#undef __local___localdep_atan2l_defined
#endif /* !... */
#endif /* !__local___localdep_atan2l_defined */
#ifndef __local___localdep_catan_defined
#define __local___localdep_catan_defined
#ifdef __CRT_HAVE_catan
__CREDIRECT(__ATTR_WUNUSED,double _Complex,__NOTHROW_NCX,__localdep_catan,(double _Complex __z),catan,(__z))
#elif (defined(__CRT_HAVE_atan2) || defined(__CRT_HAVE___atan2) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) && (defined(__CRT_HAVE_log) || defined(__CRT_HAVE___log) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__))
__NAMESPACE_LOCAL_END
#include <libc/local/complex/catan.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_catan __LIBC_LOCAL_NAME(catan)
#else /* ... */
#undef __local___localdep_catan_defined
#endif /* !... */
#endif /* !__local___localdep_catan_defined */
#ifndef __local___localdep_cimagl_defined
#define __local___localdep_cimagl_defined
#ifdef __CRT_HAVE_cimagl
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_cimagl,(long double _Complex __z),cimagl,(__z))
#elif defined(__CRT_HAVE_cimag) && defined(__ARCH_LONG_DOUBLE_IS_DOUBLE)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_cimagl,(long double _Complex __z),cimag,(__z))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/complex/cimagl.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_cimagl __LIBC_LOCAL_NAME(cimagl)
#endif /* !... */
#endif /* !__local___localdep_cimagl_defined */
#ifndef __local___localdep_creall_defined
#define __local___localdep_creall_defined
#ifdef __CRT_HAVE_creall
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_creall,(long double _Complex __z),creall,(__z))
#elif defined(__CRT_HAVE_creal) && defined(__ARCH_LONG_DOUBLE_IS_DOUBLE)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_creall,(long double _Complex __z),creal,(__z))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/complex/creall.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_creall __LIBC_LOCAL_NAME(creall)
#endif /* !... */
#endif /* !__local___localdep_creall_defined */
#ifndef __local___localdep_logl_defined
#define __local___localdep_logl_defined
#if __has_builtin(__builtin_logl) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_logl)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__ATTR_WUNUSED __DECL_SIMD_logl,__LONGDOUBLE,__NOTHROW,__localdep_logl,(__LONGDOUBLE __x),logl,{ return __builtin_logl(__x); })
#elif defined(__CRT_HAVE_logl)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_WUNUSED __DECL_SIMD_logl,__LONGDOUBLE,__NOTHROW,__localdep_logl,(__LONGDOUBLE __x),logl,(__x))
#elif defined(__CRT_HAVE___logl)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_WUNUSED __DECL_SIMD_logl,__LONGDOUBLE,__NOTHROW,__localdep_logl,(__LONGDOUBLE __x),__logl,(__x))
#elif defined(__CRT_HAVE_log) && defined(__ARCH_LONG_DOUBLE_IS_DOUBLE)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_WUNUSED __DECL_SIMD_logl,__LONGDOUBLE,__NOTHROW,__localdep_logl,(__LONGDOUBLE __x),log,(__x))
#elif defined(__CRT_HAVE___log) && defined(__ARCH_LONG_DOUBLE_IS_DOUBLE)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_WUNUSED __DECL_SIMD_logl,__LONGDOUBLE,__NOTHROW,__localdep_logl,(__LONGDOUBLE __x),__log,(__x))
#elif defined(__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__CRT_HAVE_log) || defined(__CRT_HAVE___log) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
__NAMESPACE_LOCAL_END
#include <libc/local/math/logl.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_logl __LIBC_LOCAL_NAME(logl)
#else /* ... */
#undef __local___localdep_logl_defined
#endif /* !... */
#endif /* !__local___localdep_logl_defined */
__NAMESPACE_LOCAL_END
#include <bits/crt/complex.h>
#include <hybrid/floatcore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(catanl) __ATTR_WUNUSED long double _Complex
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(catanl))(long double _Complex __z) {
#if (defined(__CRT_HAVE_atan2l) || defined(__CRT_HAVE___atan2l) || defined(__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__CRT_HAVE_atan2) || defined(__CRT_HAVE___atan2) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) && (defined(__CRT_HAVE_logl) || defined(__CRT_HAVE___logl) || defined(__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__CRT_HAVE_log) || defined(__CRT_HAVE___log) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__))
	/* Implementation derived from NetBSD. -- See the following copyright notice. */
	/*-
	 * Copyright (c) 2007 The NetBSD Foundation, Inc.
	 * All rights reserved.
	 *
	 * This code is derived from software written by Stephen L. Moshier.
	 * It is redistributed by the NetBSD Foundation by permission of the author.
	 *
	 * Redistribution and use in source and binary forms, with or without
	 * modification, are permitted provided that the following conditions
	 * are met:
	 * 1. Redistributions of source code must retain the above copyright
	 *    notice, this list of conditions and the following disclaimer.
	 * 2. Redistributions in binary form must reproduce the above copyright
	 *    notice, this list of conditions and the following disclaimer in the
	 *    documentation and/or other materials provided with the distribution.
	 *
	 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
	 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
	 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
	 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
	 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	 * POSSIBILITY OF SUCH DAMAGE.
	 */
	long double _Complex __w;
	__LONGDOUBLE __a, __t, __x, __x2, __y;
	__x = (__NAMESPACE_LOCAL_SYM __localdep_creall)(__z);
	__y = (__NAMESPACE_LOCAL_SYM __localdep_cimagl)(__z);
	if ((__x == 0.0L) && (__y > 1.0L))
		goto __ovrf;
	__x2 = __x * __x;
	__a = 1.0L - __x2 - (__y * __y);
	if (__a == 0.0L)
		goto __ovrf;
	__t = 0.5L * (__NAMESPACE_LOCAL_SYM __localdep_atan2l)(2.0L * __x, __a);
	__w = (__NAMESPACE_LOCAL_SYM __localdep__redupil)(__t);
	__t = __y - 1.0L;
	__a = __x2 + (__t * __t);
	if (__a == 0.0L)
		goto __ovrf;
	__t = __y + 1.0L;
	__a = (__x2 + (__t * __t))/__a;
	__w = __CMPLXL(__w, (0.25L * (__NAMESPACE_LOCAL_SYM __localdep_logl)(__a)));
	return __w;
__ovrf:
	/* matherr("catan", OVERFLOW); */
	__w = __CMPLXL(__LDBL_MAX__, __LDBL_MAX__);
	return __w;
#else /* (__CRT_HAVE_atan2l || __CRT_HAVE___atan2l || __IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __CRT_HAVE_atan2 || __CRT_HAVE___atan2 || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) && (__CRT_HAVE_logl || __CRT_HAVE___logl || __IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __CRT_HAVE_log || __CRT_HAVE___log || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) */
	return (long double _Complex)(__NAMESPACE_LOCAL_SYM __localdep_catan)((double _Complex)__z);
#endif /* (!__CRT_HAVE_atan2l && !__CRT_HAVE___atan2l && !__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ && !__CRT_HAVE_atan2 && !__CRT_HAVE___atan2 && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || (!__CRT_HAVE_logl && !__CRT_HAVE___logl && !__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ && !__CRT_HAVE_log && !__CRT_HAVE___log && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_catanl_defined
#define __local___localdep_catanl_defined
#define __localdep_catanl __LIBC_LOCAL_NAME(catanl)
#endif /* !__local___localdep_catanl_defined */
#else /* ((__CRT_HAVE_atan2l || __CRT_HAVE___atan2l || __IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __CRT_HAVE_atan2 || __CRT_HAVE___atan2 || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) && (__CRT_HAVE_logl || __CRT_HAVE___logl || __IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __CRT_HAVE_log || __CRT_HAVE___log || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) || __CRT_HAVE_catan || ((__CRT_HAVE_atan2 || __CRT_HAVE___atan2 || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) && (__CRT_HAVE_log || __CRT_HAVE___log || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) */
#undef __local_catanl_defined
#endif /* ((!__CRT_HAVE_atan2l && !__CRT_HAVE___atan2l && !__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ && !__CRT_HAVE_atan2 && !__CRT_HAVE___atan2 && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || (!__CRT_HAVE_logl && !__CRT_HAVE___logl && !__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ && !__CRT_HAVE_log && !__CRT_HAVE___log && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) && !__CRT_HAVE_catan && ((!__CRT_HAVE_atan2 && !__CRT_HAVE___atan2 && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || (!__CRT_HAVE_log && !__CRT_HAVE___log && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) */
#endif /* !__local_catanl_defined */
