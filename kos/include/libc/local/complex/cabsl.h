/* HASH CRC-32:0xbf6330ba */
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
#ifndef __local_cabsl_defined
#define __local_cabsl_defined
#include <__crt.h>
#include <ieee754.h>
#if defined(__CRT_HAVE_cabs) || defined(__CRT_HAVE_hypot) || defined(__CRT_HAVE___hypot) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_cabs_defined
#define __local___localdep_cabs_defined
#ifdef __CRT_HAVE_cabs
__CREDIRECT(,double,__NOTHROW_NCX,__localdep_cabs,(double _Complex __z),cabs,(__z))
#elif defined(__CRT_HAVE_hypot) || defined(__CRT_HAVE___hypot) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
__NAMESPACE_LOCAL_END
#include <libc/local/complex/cabs.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_cabs __LIBC_LOCAL_NAME(cabs)
#else /* ... */
#undef __local___localdep_cabs_defined
#endif /* !... */
#endif /* !__local___localdep_cabs_defined */
#ifndef __local___localdep_cimagl_defined
#define __local___localdep_cimagl_defined
#ifdef __CRT_HAVE_cimagl
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW_NCX,__localdep_cimagl,(long double _Complex __z),cimagl,(__z))
#else /* __CRT_HAVE_cimagl */
__NAMESPACE_LOCAL_END
#include <libc/local/complex/cimagl.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_cimagl __LIBC_LOCAL_NAME(cimagl)
#endif /* !__CRT_HAVE_cimagl */
#endif /* !__local___localdep_cimagl_defined */
#ifndef __local___localdep_creall_defined
#define __local___localdep_creall_defined
#ifdef __CRT_HAVE_creall
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW_NCX,__localdep_creall,(long double _Complex __z),creall,(__z))
#else /* __CRT_HAVE_creall */
__NAMESPACE_LOCAL_END
#include <libc/local/complex/creall.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_creall __LIBC_LOCAL_NAME(creall)
#endif /* !__CRT_HAVE_creall */
#endif /* !__local___localdep_creall_defined */
#ifndef __local___localdep_hypotl_defined
#define __local___localdep_hypotl_defined
#if __has_builtin(__builtin_hypotl) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_hypotl)
__CEIREDIRECT(__ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_hypotl,(__LONGDOUBLE __x, __LONGDOUBLE __y),hypotl,{ return __builtin_hypotl(__x, __y); })
#elif defined(__CRT_HAVE_hypotl)
__CREDIRECT(__ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_hypotl,(__LONGDOUBLE __x, __LONGDOUBLE __y),hypotl,(__x,__y))
#elif defined(__CRT_HAVE___hypotl)
__CREDIRECT(__ATTR_WUNUSED,__LONGDOUBLE,__NOTHROW,__localdep_hypotl,(__LONGDOUBLE __x, __LONGDOUBLE __y),__hypotl,(__x,__y))
#elif defined(__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__CRT_HAVE_hypot) || defined(__CRT_HAVE___hypot) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
__NAMESPACE_LOCAL_END
#include <libc/local/math/hypotl.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_hypotl __LIBC_LOCAL_NAME(hypotl)
#else /* ... */
#undef __local___localdep_hypotl_defined
#endif /* !... */
#endif /* !__local___localdep_hypotl_defined */
__LOCAL_LIBC(cabsl) __LONGDOUBLE
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(cabsl))(long double _Complex __z) {
#if defined(__CRT_HAVE_hypotl) || defined(__CRT_HAVE___hypotl) || defined(__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__) || defined(__CRT_HAVE_hypot) || defined(__CRT_HAVE___hypot) || defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
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
	return (__NAMESPACE_LOCAL_SYM __localdep_hypotl)((__NAMESPACE_LOCAL_SYM __localdep_creall)(__z), (__NAMESPACE_LOCAL_SYM __localdep_cimagl)(__z));
#else /* __CRT_HAVE_hypotl || __CRT_HAVE___hypotl || __IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ || __CRT_HAVE_hypot || __CRT_HAVE___hypot || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
	return (__LONGDOUBLE)(__NAMESPACE_LOCAL_SYM __localdep_cabs)((double _Complex)__z);
#endif /* !__CRT_HAVE_hypotl && !__CRT_HAVE___hypotl && !__IEEE754_DOUBLE_TYPE_IS_LONG_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_LONG_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_LONG_DOUBLE__ && !__CRT_HAVE_hypot && !__CRT_HAVE___hypot && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_cabsl_defined
#define __local___localdep_cabsl_defined
#define __localdep_cabsl __LIBC_LOCAL_NAME(cabsl)
#endif /* !__local___localdep_cabsl_defined */
#else /* __CRT_HAVE_cabs || __CRT_HAVE_hypot || __CRT_HAVE___hypot || __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
#undef __local_cabsl_defined
#endif /* !__CRT_HAVE_cabs && !__CRT_HAVE_hypot && !__CRT_HAVE___hypot && !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
#endif /* !__local_cabsl_defined */
