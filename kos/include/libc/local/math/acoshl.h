/* HASH CRC-32:0x82f3c439 */
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
#ifndef __local_acoshl_defined
#define __local_acoshl_defined 1
#include <__crt.h>
#if defined(__CRT_HAVE_acosh) || defined(__CRT_HAVE___acosh)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_acosh_defined
#define __local___localdep_acosh_defined 1
#if __has_builtin(__builtin_acosh) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_acosh)
__CEIREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_acosh,(double __x),acosh,{ return __builtin_acosh(__x); })
#elif defined(__CRT_HAVE_acosh)
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_acosh,(double __x),acosh,(__x))
#elif defined(__CRT_HAVE___acosh)
__CREDIRECT(__ATTR_WUNUSED,double,__NOTHROW,__localdep_acosh,(double __x),__acosh,(__x))
#else /* ... */
#undef __local___localdep_acosh_defined
#endif /* !... */
#endif /* !__local___localdep_acosh_defined */
__LOCAL_LIBC(acoshl) __ATTR_WUNUSED __LONGDOUBLE
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(acoshl))(__LONGDOUBLE __x) {
	return (__LONGDOUBLE)__NAMESPACE_LOCAL_SYM __localdep_acosh((double)__x);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_acoshl_defined
#define __local___localdep_acoshl_defined 1
#define __localdep_acoshl __LIBC_LOCAL_NAME(acoshl)
#endif /* !__local___localdep_acoshl_defined */
#else /* __CRT_HAVE_acosh || __CRT_HAVE___acosh */
#undef __local_acoshl_defined
#endif /* !__CRT_HAVE_acosh && !__CRT_HAVE___acosh */
#endif /* !__local_acoshl_defined */
