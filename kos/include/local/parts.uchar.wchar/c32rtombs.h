/* HASH CRC-32:0xd1f75599 */
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
#ifndef __local_c32rtombs_defined
#define __local_c32rtombs_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: c32rtomb from uchar */
#ifndef __local___localdep_c32rtomb_defined
#define __local___localdep_c32rtomb_defined 1
#if defined(__CRT_HAVE_wcrtomb) && (__SIZEOF_WCHAR_T__ == 4) && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_c32rtomb,(char *__restrict __str, __CHAR32_TYPE__ __wc, __mbstate_t *__mbs),wcrtomb,(__str,__wc,__mbs))
#elif defined(__CRT_HAVE_DOS$wcrtomb)
__CREDIRECT_KOS(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_c32rtomb,(char *__restrict __str, __CHAR32_TYPE__ __wc, __mbstate_t *__mbs),wcrtomb,(__str,__wc,__mbs))
#elif (__SIZEOF_WCHAR_T__ == 4)
__NAMESPACE_LOCAL_END
#include <local/wchar/wcrtomb.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c32rtomb (*(__SIZE_TYPE__(__LIBKCALL *)(char *__restrict, __CHAR32_TYPE__, __mbstate_t *))&__LIBC_LOCAL_NAME(wcrtomb))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/uchar/c32rtomb.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c32rtomb __LIBC_LOCAL_NAME(c32rtomb)
#endif /* !... */
#endif /* !__local___localdep_c32rtomb_defined */
/* Dependency: mempcpy from string */
#ifndef __local___localdep_mempcpy_defined
#define __local___localdep_mempcpy_defined 1
#ifdef __CRT_HAVE_mempcpy
/* Same as `memcpy', but return `DST + N_BYTES', rather than `DST' */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_mempcpy,(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __n_bytes),mempcpy,(__dst,__src,__n_bytes))
#elif defined(__CRT_HAVE___mempcpy)
/* Same as `memcpy', but return `DST + N_BYTES', rather than `DST' */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_mempcpy,(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __n_bytes),__mempcpy,(__dst,__src,__n_bytes))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/string/mempcpy.h>
__NAMESPACE_LOCAL_BEGIN
/* Same as `memcpy', but return `DST + N_BYTES', rather than `DST' */
#define __localdep_mempcpy __LIBC_LOCAL_NAME(mempcpy)
#endif /* !... */
#endif /* !__local___localdep_mempcpy_defined */
__LOCAL_LIBC(c32rtombs) __ATTR_NONNULL((1, 2)) __SIZE_TYPE__
__NOTHROW_NCX(__LIBKCALL __LIBC_LOCAL_NAME(c32rtombs))(char *__dst, __CHAR32_TYPE__ const **__restrict __psrc, __SIZE_TYPE__ __dstlen, __mbstate_t *__mbs) {
	__SIZE_TYPE__ __result = 0;
	__CHAR32_TYPE__ const *__src = *__psrc;
	while (__dstlen) {
		__SIZE_TYPE__ __error;
		char __buf[8];
		__error = __localdep_c32rtomb(__buf, *__src, __mbs);
		if (!__error)
			break;
		if (__error == (__SIZE_TYPE__)-1)
			return (__SIZE_TYPE__)-1; /* EILSEQ */
		if (__error > __dstlen)
			break;
		__dst = (char *)__localdep_mempcpy(__dst, __buf, __error);
		__result += __error;
		__dstlen -= __error;
		++__src;
	}
	*__psrc = __src;
	return __result;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c32rtombs_defined
#define __local___localdep_c32rtombs_defined 1
#define __localdep_c32rtombs __LIBC_LOCAL_NAME(c32rtombs)
#endif /* !__local___localdep_c32rtombs_defined */
#endif /* !__local_c32rtombs_defined */
