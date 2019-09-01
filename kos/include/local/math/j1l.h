/* HASH 0xf6217bcb */
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
#ifndef __local_j1l_defined
#if ((__has_builtin(__builtin_j1) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_j1)) || defined(__CRT_HAVE_j1) || defined(__CRT_HAVE___j1))
#define __local_j1l_defined 1
/* Dependency: "j1" */
#ifndef ____localdep_j1_defined
#define ____localdep_j1_defined 1
#if __has_builtin(__builtin_j1) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_j1)
__FORCELOCAL __ATTR_WUNUSED double __NOTHROW(__LIBCCALL __localdep_j1)(double __x) { return __builtin_j1(__x); }
#elif defined(__CRT_HAVE_j1)
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_j1,(double __x),j1,(__x))
#elif defined(__CRT_HAVE___j1)
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_j1,(double __x),__j1,(__x))
#else /* LIBC: j1 */
#undef ____localdep_j1_defined
#endif /* j1... */
#endif /* !____localdep_j1_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(j1l) __ATTR_WUNUSED long double
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(j1l))(long double __x) {
#line 895 "kos/src/libc/magic/math.c"
	return (long double)__localdep_j1((double)__x);
}
__NAMESPACE_LOCAL_END
#endif /* ((__has_builtin(__builtin_j1) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_j1)) || defined(__CRT_HAVE_j1) || defined(__CRT_HAVE___j1)) */
#endif /* !__local_j1l_defined */
