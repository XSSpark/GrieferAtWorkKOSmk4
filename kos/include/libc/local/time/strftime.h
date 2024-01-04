/* HASH CRC-32:0xa1d9355d */
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
#ifndef __local_strftime_defined
#define __local_strftime_defined
#include <__crt.h>
#include <bits/crt/tm.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_crt_strftime_l_defined
#define __local___localdep_crt_strftime_l_defined
#ifdef __CRT_HAVE_strftime_l
__CREDIRECT(__ATTR_IN(3) __ATTR_IN(4) __ATTR_LIBC_STRFTIME(3, 0) __ATTR_OUTS(1, 2),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_crt_strftime_l,(char *__restrict __buf, __SIZE_TYPE__ __bufsize, char const *__restrict __format, struct __NAMESPACE_STD_SYM tm const *__restrict __tp, __locale_t __locale),strftime_l,(__buf,__bufsize,__format,__tp,__locale))
#elif defined(__CRT_HAVE__strftime_l)
__CREDIRECT(__ATTR_IN(3) __ATTR_IN(4) __ATTR_LIBC_STRFTIME(3, 0) __ATTR_OUTS(1, 2),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_crt_strftime_l,(char *__restrict __buf, __SIZE_TYPE__ __bufsize, char const *__restrict __format, struct __NAMESPACE_STD_SYM tm const *__restrict __tp, __locale_t __locale),_strftime_l,(__buf,__bufsize,__format,__tp,__locale))
#elif defined(__CRT_HAVE___strftime_l)
__CREDIRECT(__ATTR_IN(3) __ATTR_IN(4) __ATTR_LIBC_STRFTIME(3, 0) __ATTR_OUTS(1, 2),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_crt_strftime_l,(char *__restrict __buf, __SIZE_TYPE__ __bufsize, char const *__restrict __format, struct __NAMESPACE_STD_SYM tm const *__restrict __tp, __locale_t __locale),__strftime_l,(__buf,__bufsize,__format,__tp,__locale))
#else /* ... */
#undef __local___localdep_crt_strftime_l_defined
#endif /* !... */
#endif /* !__local___localdep_crt_strftime_l_defined */
__LOCAL_LIBC(strftime) __ATTR_IN(3) __ATTR_IN(4) __ATTR_LIBC_STRFTIME(3, 0) __ATTR_OUTS(1, 2) __SIZE_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(strftime))(char *__restrict __buf, __SIZE_TYPE__ __bufsize, char const *__restrict __format, struct __NAMESPACE_STD_SYM tm const *__restrict __tp) {
#if defined(__CRT_HAVE_strftime_l) || defined(__CRT_HAVE__strftime_l) || defined(__CRT_HAVE___strftime_l)
	return (__NAMESPACE_LOCAL_SYM __localdep_crt_strftime_l)(__buf, __bufsize, __format, __tp, __NULLPTR);
#else /* __CRT_HAVE_strftime_l || __CRT_HAVE__strftime_l || __CRT_HAVE___strftime_l */
	/* TODO */
	(void)__buf;
	(void)__bufsize;
	(void)__format;
	(void)__tp;
	__COMPILER_IMPURE();
	return 0;
#endif /* !__CRT_HAVE_strftime_l && !__CRT_HAVE__strftime_l && !__CRT_HAVE___strftime_l */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_strftime_defined
#define __local___localdep_strftime_defined
#define __localdep_strftime __LIBC_LOCAL_NAME(strftime)
#endif /* !__local___localdep_strftime_defined */
#endif /* !__local_strftime_defined */
