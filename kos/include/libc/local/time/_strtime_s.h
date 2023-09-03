/* HASH CRC-32:0x44b66b0c */
/* Copyright (c) 2019-2023 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2023 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local__strtime_s_defined
#define __local__strtime_s_defined
#include <__crt.h>
#include <bits/types.h>
#if defined(__CRT_HAVE__strtime) || defined(__CRT_HAVE_time64) || defined(__CRT_HAVE__time64) || defined(__CRT_HAVE___time64) || defined(__CRT_HAVE_time) || defined(__CRT_HAVE___time) || defined(__CRT_HAVE___libc_time) || defined(__CRT_HAVE__time32)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__strtime_defined
#define __local___localdep__strtime_defined
#ifdef __CRT_HAVE__strtime
__CREDIRECT(__ATTR_OUT(1),char *,__NOTHROW_NCX,__localdep__strtime,(char __buf[9]),_strtime,(__buf))
#elif defined(__CRT_HAVE_time64) || defined(__CRT_HAVE__time64) || defined(__CRT_HAVE___time64) || defined(__CRT_HAVE_time) || defined(__CRT_HAVE___time) || defined(__CRT_HAVE___libc_time) || defined(__CRT_HAVE__time32)
__NAMESPACE_LOCAL_END
#include <libc/local/time/_strtime.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__strtime __LIBC_LOCAL_NAME(_strtime)
#else /* ... */
#undef __local___localdep__strtime_defined
#endif /* !... */
#endif /* !__local___localdep__strtime_defined */
__NAMESPACE_LOCAL_END
#include <libc/errno.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_strtime_s) __ATTR_OUTS(1, 2) __errno_t
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_strtime_s))(char *__buf, __SIZE_TYPE__ __bufsize) {
	if __unlikely(__bufsize < 9) {
#ifdef __ERANGE
		return __ERANGE;
#else /* __ERANGE */
		return 1;
#endif /* !__ERANGE */
	}



	if __unlikely(!(__NAMESPACE_LOCAL_SYM __localdep__strtime)(__buf))
		return __libc_geterrno_or(1);

	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__strtime_s_defined
#define __local___localdep__strtime_s_defined
#define __localdep__strtime_s __LIBC_LOCAL_NAME(_strtime_s)
#endif /* !__local___localdep__strtime_s_defined */
#else /* __CRT_HAVE__strtime || __CRT_HAVE_time64 || __CRT_HAVE__time64 || __CRT_HAVE___time64 || __CRT_HAVE_time || __CRT_HAVE___time || __CRT_HAVE___libc_time || __CRT_HAVE__time32 */
#undef __local__strtime_s_defined
#endif /* !__CRT_HAVE__strtime && !__CRT_HAVE_time64 && !__CRT_HAVE__time64 && !__CRT_HAVE___time64 && !__CRT_HAVE_time && !__CRT_HAVE___time && !__CRT_HAVE___libc_time && !__CRT_HAVE__time32 */
#endif /* !__local__strtime_s_defined */
