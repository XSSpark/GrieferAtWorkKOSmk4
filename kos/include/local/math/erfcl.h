/* HASH CRC-32:0xdcd298f0 */
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
#ifndef __local_erfcl_defined
#if defined(__CRT_HAVE_erfc) || defined(__CRT_HAVE___erfc)
#define __local_erfcl_defined 1
/* Dependency: "erfc" */
#ifndef ____localdep_erfc_defined
#define ____localdep_erfc_defined 1
#if __has_builtin(__builtin_erfc) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_erfc)
__EXTERNINLINE __ATTR_WUNUSED double __NOTHROW(__LIBCCALL __localdep_erfc)(double __x) { return __builtin_erfc(__x); }
#elif defined(__CRT_HAVE_erfc)
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_erfc,(double __x),erfc,(__x))
#elif defined(__CRT_HAVE___erfc)
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_erfc,(double __x),__erfc,(__x))
#else /* LIBC: erfc */
#undef ____localdep_erfc_defined
#endif /* erfc... */
#endif /* !____localdep_erfc_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(erfcl) __ATTR_WUNUSED __LONGDOUBLE
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(erfcl))(__LONGDOUBLE __x) {
#line 1133 "kos/src/libc/magic/math.c"
	return (__LONGDOUBLE)__localdep_erfc((double)__x);
}
__NAMESPACE_LOCAL_END
#endif /* __CRT_HAVE_erfc || __CRT_HAVE___erfc */
#endif /* !__local_erfcl_defined */
