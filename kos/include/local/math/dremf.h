/* HASH 0x3716eb32 */
/* Copyright (c) 2019 Griefer@Work                                            *
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
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_dremf_defined
#if ((__has_builtin(__builtin_drem) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_drem)) || defined(__CRT_HAVE_drem) || defined(__CRT_HAVE___drem))
#define __local_dremf_defined 1
/* Dependency: "drem" */
#ifndef ____localdep_drem_defined
#define ____localdep_drem_defined 1
#if __has_builtin(__builtin_drem) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_drem)
/* Return the remainder of X/Y */
__FORCELOCAL __ATTR_WUNUSED double __NOTHROW(__LIBCCALL __localdep_drem)(double __x, double __y) { return __builtin_drem(__x, __y); }
#elif defined(__CRT_HAVE_drem)
/* Return the remainder of X/Y */
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_drem,(double __x, double __y),drem,(__x,__y))
#elif defined(__CRT_HAVE___drem)
/* Return the remainder of X/Y */
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_drem,(double __x, double __y),__drem,(__x,__y))
#else /* LIBC: drem */
#undef ____localdep_drem_defined
#endif /* drem... */
#endif /* !____localdep_drem_defined */

__NAMESPACE_LOCAL_BEGIN
/* Return the remainder of X/Y */
__LOCAL_LIBC(dremf) __ATTR_WUNUSED float
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(dremf))(float __x,
                                               float __y) {
#line 837 "kos/src/libc/magic/math.c"
	return (float)__localdep_drem((double)__x, (double)__y);
}
__NAMESPACE_LOCAL_END
#endif /* ((__has_builtin(__builtin_drem) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_drem)) || defined(__CRT_HAVE_drem) || defined(__CRT_HAVE___drem)) */
#endif /* !__local_dremf_defined */
