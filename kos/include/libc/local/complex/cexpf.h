/* HASH CRC-32:0xe27c5755 */
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
#ifndef __local_cexpf_defined
#define __local_cexpf_defined
#include <__crt.h>
#include <ieee754.h>
#if ((defined(__CRT_HAVE_expf) || defined(__CRT_HAVE___expf) || defined(__IEEE754_DOUBLE_TYPE_IS_FLOAT__) || defined(__IEEE754_FLOAT_TYPE_IS_FLOAT__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__) || defined(__CRT_HAVE_exp) || defined(__CRT_HAVE___exp) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) && (defined(__CRT_HAVE_sincosf) || defined(__CRT_HAVE___sincosf) || defined(__CRT_HAVE_sincos) || defined(__CRT_HAVE___sincos) || ((defined(__CRT_HAVE_sin) || defined(__CRT_HAVE___sin)) && (defined(__CRT_HAVE_cos) || defined(__CRT_HAVE___cos))) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || ((defined(__CRT_HAVE_sinf) || defined(__CRT_HAVE___sinf) || defined(__CRT_HAVE_sin) || defined(__CRT_HAVE___sin)) && (defined(__CRT_HAVE_cosf) || defined(__CRT_HAVE___cosf) || defined(__CRT_HAVE_cos) || defined(__CRT_HAVE___cos))) || defined(__IEEE754_DOUBLE_TYPE_IS_FLOAT__) || defined(__IEEE754_FLOAT_TYPE_IS_FLOAT__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__))) || defined(__CRT_HAVE_cexp) || ((defined(__CRT_HAVE_exp) || defined(__CRT_HAVE___exp) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) && (defined(__CRT_HAVE_sincos) || defined(__CRT_HAVE___sincos) || ((defined(__CRT_HAVE_sin) || defined(__CRT_HAVE___sin)) && (defined(__CRT_HAVE_cos) || defined(__CRT_HAVE___cos))) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_cexp_defined
#define __local___localdep_cexp_defined
#ifdef __CRT_HAVE_cexp
__CREDIRECT(__ATTR_WUNUSED,double _Complex,__NOTHROW_NCX,__localdep_cexp,(double _Complex __z),cexp,(__z))
#elif (defined(__CRT_HAVE_exp) || defined(__CRT_HAVE___exp) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) && (defined(__CRT_HAVE_sincos) || defined(__CRT_HAVE___sincos) || ((defined(__CRT_HAVE_sin) || defined(__CRT_HAVE___sin)) && (defined(__CRT_HAVE_cos) || defined(__CRT_HAVE___cos))) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__))
__NAMESPACE_LOCAL_END
#include <libc/local/complex/cexp.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_cexp __LIBC_LOCAL_NAME(cexp)
#else /* ... */
#undef __local___localdep_cexp_defined
#endif /* !... */
#endif /* !__local___localdep_cexp_defined */
#ifndef __local___localdep_cimagf_defined
#define __local___localdep_cimagf_defined
#ifdef __CRT_HAVE_cimagf
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,float,__NOTHROW_NCX,__localdep_cimagf,(float _Complex __z),cimagf,(__z))
#else /* __CRT_HAVE_cimagf */
__NAMESPACE_LOCAL_END
#include <libc/local/complex/cimagf.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_cimagf __LIBC_LOCAL_NAME(cimagf)
#endif /* !__CRT_HAVE_cimagf */
#endif /* !__local___localdep_cimagf_defined */
#ifndef __local___localdep_crealf_defined
#define __local___localdep_crealf_defined
#ifdef __CRT_HAVE_crealf
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,float,__NOTHROW_NCX,__localdep_crealf,(float _Complex __z),crealf,(__z))
#else /* __CRT_HAVE_crealf */
__NAMESPACE_LOCAL_END
#include <libc/local/complex/crealf.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_crealf __LIBC_LOCAL_NAME(crealf)
#endif /* !__CRT_HAVE_crealf */
#endif /* !__local___localdep_crealf_defined */
#ifndef __local___localdep_expf_defined
#define __local___localdep_expf_defined
#if __has_builtin(__builtin_expf) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_expf)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__ATTR_WUNUSED __DECL_SIMD_expf,float,__NOTHROW,__localdep_expf,(float __x),expf,{ return __builtin_expf(__x); })
#elif defined(__CRT_HAVE_expf)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_WUNUSED __DECL_SIMD_expf,float,__NOTHROW,__localdep_expf,(float __x),expf,(__x))
#elif defined(__CRT_HAVE___expf)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_WUNUSED __DECL_SIMD_expf,float,__NOTHROW,__localdep_expf,(float __x),__expf,(__x))
#elif defined(__IEEE754_DOUBLE_TYPE_IS_FLOAT__) || defined(__IEEE754_FLOAT_TYPE_IS_FLOAT__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__) || defined(__CRT_HAVE_exp) || defined(__CRT_HAVE___exp) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
__NAMESPACE_LOCAL_END
#include <libc/local/math/expf.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_expf __LIBC_LOCAL_NAME(expf)
#else /* ... */
#undef __local___localdep_expf_defined
#endif /* !... */
#endif /* !__local___localdep_expf_defined */
#ifndef __local___localdep_sincosf_defined
#define __local___localdep_sincosf_defined
#if __has_builtin(__builtin_sincosf) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_sincosf)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__DECL_SIMD_sincosf __ATTR_OUT(2) __ATTR_OUT(3),void,__NOTHROW,__localdep_sincosf,(float __x, float *__psinx, float *__pcosx),sincosf,{ __builtin_sincosf(__x, __psinx, __pcosx); })
#elif defined(__CRT_HAVE_sincosf)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT_VOID(__DECL_SIMD_sincosf __ATTR_OUT(2) __ATTR_OUT(3),__NOTHROW,__localdep_sincosf,(float __x, float *__psinx, float *__pcosx),sincosf,(__x,__psinx,__pcosx))
#elif defined(__CRT_HAVE___sincosf)
__NAMESPACE_LOCAL_END
#include <bits/crt/math-vector.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT_VOID(__DECL_SIMD_sincosf __ATTR_OUT(2) __ATTR_OUT(3),__NOTHROW,__localdep_sincosf,(float __x, float *__psinx, float *__pcosx),__sincosf,(__x,__psinx,__pcosx))
#elif defined(__CRT_HAVE_sincos) || defined(__CRT_HAVE___sincos) || ((defined(__CRT_HAVE_sin) || defined(__CRT_HAVE___sin)) && (defined(__CRT_HAVE_cos) || defined(__CRT_HAVE___cos))) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || ((defined(__CRT_HAVE_sinf) || defined(__CRT_HAVE___sinf) || defined(__CRT_HAVE_sin) || defined(__CRT_HAVE___sin)) && (defined(__CRT_HAVE_cosf) || defined(__CRT_HAVE___cosf) || defined(__CRT_HAVE_cos) || defined(__CRT_HAVE___cos))) || defined(__IEEE754_DOUBLE_TYPE_IS_FLOAT__) || defined(__IEEE754_FLOAT_TYPE_IS_FLOAT__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__)
__NAMESPACE_LOCAL_END
#include <libc/local/math/sincosf.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_sincosf __LIBC_LOCAL_NAME(sincosf)
#else /* ... */
#undef __local___localdep_sincosf_defined
#endif /* !... */
#endif /* !__local___localdep_sincosf_defined */
__NAMESPACE_LOCAL_END
#include <bits/crt/complex.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(cexpf) __ATTR_WUNUSED float _Complex
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(cexpf))(float _Complex __z) {
#if (defined(__CRT_HAVE_expf) || defined(__CRT_HAVE___expf) || defined(__IEEE754_DOUBLE_TYPE_IS_FLOAT__) || defined(__IEEE754_FLOAT_TYPE_IS_FLOAT__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__) || defined(__CRT_HAVE_exp) || defined(__CRT_HAVE___exp) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) && (defined(__CRT_HAVE_sincosf) || defined(__CRT_HAVE___sincosf) || defined(__CRT_HAVE_sincos) || defined(__CRT_HAVE___sincos) || ((defined(__CRT_HAVE_sin) || defined(__CRT_HAVE___sin)) && (defined(__CRT_HAVE_cos) || defined(__CRT_HAVE___cos))) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || ((defined(__CRT_HAVE_sinf) || defined(__CRT_HAVE___sinf) || defined(__CRT_HAVE_sin) || defined(__CRT_HAVE___sin)) && (defined(__CRT_HAVE_cosf) || defined(__CRT_HAVE___cosf) || defined(__CRT_HAVE_cos) || defined(__CRT_HAVE___cos))) || defined(__IEEE754_DOUBLE_TYPE_IS_FLOAT__) || defined(__IEEE754_FLOAT_TYPE_IS_FLOAT__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__))
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
	float _Complex __w;
	float __r, __x, __y;
	float __siny, __cosy;
	__x = (__NAMESPACE_LOCAL_SYM __localdep_crealf)(__z);
	__y = (__NAMESPACE_LOCAL_SYM __localdep_cimagf)(__z);
	__r = (__NAMESPACE_LOCAL_SYM __localdep_expf)(__x);
	(__NAMESPACE_LOCAL_SYM __localdep_sincosf)(__y, &__siny, &__cosy);
	__w = __CMPLXF(__r * __cosy, __r * __siny);
	return __w;
#else /* (__CRT_HAVE_expf || __CRT_HAVE___expf || __IEEE754_DOUBLE_TYPE_IS_FLOAT__ || __IEEE754_FLOAT_TYPE_IS_FLOAT__ || __IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__ || __CRT_HAVE_exp || __CRT_HAVE___exp || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) && (__CRT_HAVE_sincosf || __CRT_HAVE___sincosf || __CRT_HAVE_sincos || __CRT_HAVE___sincos || ((__CRT_HAVE_sin || __CRT_HAVE___sin) && (__CRT_HAVE_cos || __CRT_HAVE___cos)) || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ || ((__CRT_HAVE_sinf || __CRT_HAVE___sinf || __CRT_HAVE_sin || __CRT_HAVE___sin) && (__CRT_HAVE_cosf || __CRT_HAVE___cosf || __CRT_HAVE_cos || __CRT_HAVE___cos)) || __IEEE754_DOUBLE_TYPE_IS_FLOAT__ || __IEEE754_FLOAT_TYPE_IS_FLOAT__ || __IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__) */
	return (float _Complex)(__NAMESPACE_LOCAL_SYM __localdep_cexp)((double _Complex)__z);
#endif /* (!__CRT_HAVE_expf && !__CRT_HAVE___expf && !__IEEE754_DOUBLE_TYPE_IS_FLOAT__ && !__IEEE754_FLOAT_TYPE_IS_FLOAT__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__ && !__CRT_HAVE_exp && !__CRT_HAVE___exp && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || (!__CRT_HAVE_sincosf && !__CRT_HAVE___sincosf && !__CRT_HAVE_sincos && !__CRT_HAVE___sincos && ((!__CRT_HAVE_sin && !__CRT_HAVE___sin) || (!__CRT_HAVE_cos && !__CRT_HAVE___cos)) && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ && ((!__CRT_HAVE_sinf && !__CRT_HAVE___sinf && !__CRT_HAVE_sin && !__CRT_HAVE___sin) || (!__CRT_HAVE_cosf && !__CRT_HAVE___cosf && !__CRT_HAVE_cos && !__CRT_HAVE___cos)) && !__IEEE754_DOUBLE_TYPE_IS_FLOAT__ && !__IEEE754_FLOAT_TYPE_IS_FLOAT__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__) */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_cexpf_defined
#define __local___localdep_cexpf_defined
#define __localdep_cexpf __LIBC_LOCAL_NAME(cexpf)
#endif /* !__local___localdep_cexpf_defined */
#else /* ((__CRT_HAVE_expf || __CRT_HAVE___expf || __IEEE754_DOUBLE_TYPE_IS_FLOAT__ || __IEEE754_FLOAT_TYPE_IS_FLOAT__ || __IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__ || __CRT_HAVE_exp || __CRT_HAVE___exp || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) && (__CRT_HAVE_sincosf || __CRT_HAVE___sincosf || __CRT_HAVE_sincos || __CRT_HAVE___sincos || ((__CRT_HAVE_sin || __CRT_HAVE___sin) && (__CRT_HAVE_cos || __CRT_HAVE___cos)) || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ || ((__CRT_HAVE_sinf || __CRT_HAVE___sinf || __CRT_HAVE_sin || __CRT_HAVE___sin) && (__CRT_HAVE_cosf || __CRT_HAVE___cosf || __CRT_HAVE_cos || __CRT_HAVE___cos)) || __IEEE754_DOUBLE_TYPE_IS_FLOAT__ || __IEEE754_FLOAT_TYPE_IS_FLOAT__ || __IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__)) || __CRT_HAVE_cexp || ((__CRT_HAVE_exp || __CRT_HAVE___exp || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) && (__CRT_HAVE_sincos || __CRT_HAVE___sincos || ((__CRT_HAVE_sin || __CRT_HAVE___sin) && (__CRT_HAVE_cos || __CRT_HAVE___cos)) || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) */
#undef __local_cexpf_defined
#endif /* ((!__CRT_HAVE_expf && !__CRT_HAVE___expf && !__IEEE754_DOUBLE_TYPE_IS_FLOAT__ && !__IEEE754_FLOAT_TYPE_IS_FLOAT__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__ && !__CRT_HAVE_exp && !__CRT_HAVE___exp && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || (!__CRT_HAVE_sincosf && !__CRT_HAVE___sincosf && !__CRT_HAVE_sincos && !__CRT_HAVE___sincos && ((!__CRT_HAVE_sin && !__CRT_HAVE___sin) || (!__CRT_HAVE_cos && !__CRT_HAVE___cos)) && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ && ((!__CRT_HAVE_sinf && !__CRT_HAVE___sinf && !__CRT_HAVE_sin && !__CRT_HAVE___sin) || (!__CRT_HAVE_cosf && !__CRT_HAVE___cosf && !__CRT_HAVE_cos && !__CRT_HAVE___cos)) && !__IEEE754_DOUBLE_TYPE_IS_FLOAT__ && !__IEEE754_FLOAT_TYPE_IS_FLOAT__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_FLOAT__)) && !__CRT_HAVE_cexp && ((!__CRT_HAVE_exp && !__CRT_HAVE___exp && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__) || (!__CRT_HAVE_sincos && !__CRT_HAVE___sincos && ((!__CRT_HAVE_sin && !__CRT_HAVE___sin) || (!__CRT_HAVE_cos && !__CRT_HAVE___cos)) && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)) */
#endif /* !__local_cexpf_defined */
