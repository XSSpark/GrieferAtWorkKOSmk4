/* HASH CRC-32:0x8c3f2c7f */
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
#ifndef __local_c32ncasecoll_l_defined
#define __local_c32ncasecoll_l_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_c32ncasecoll_defined
#define __local___localdep_c32ncasecoll_defined
#if defined(__CRT_HAVE_wcsncasecoll) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),wcsncasecoll,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE_KOS$wcsncasecoll)
__CREDIRECT_KOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),wcsncasecoll,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE__wcsnicoll) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),_wcsnicoll,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE_KOS$_wcsnicoll)
__CREDIRECT_KOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),_wcsnicoll,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE_wcsnicoll) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),wcsnicoll,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE_KOS$wcsnicoll)
__CREDIRECT_KOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),wcsnicoll,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE_wcsncasecmp) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),wcsncasecmp,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE_KOS$wcsncasecmp)
__CREDIRECT_KOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),wcsncasecmp,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE__wcsnicmp) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),_wcsnicmp,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE_KOS$_wcsnicmp)
__CREDIRECT_KOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),_wcsnicmp,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE_wcsnicmp) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),wcsnicmp,(__s1,__s2,__maxlen))
#elif defined(__CRT_HAVE_KOS$wcsnicmp)
__CREDIRECT_KOS(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_c32ncasecoll,(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen),wcsnicmp,(__s1,__s2,__maxlen))
#elif __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wcsncasecoll.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c32ncasecoll __NAMESPACE_LOCAL_TYPEHAX(int(__LIBKCALL*)(__CHAR32_TYPE__ const *,__CHAR32_TYPE__ const *,__SIZE_TYPE__),int(__LIBKCALL&)(__CHAR32_TYPE__ const *,__CHAR32_TYPE__ const *,__SIZE_TYPE__),wcsncasecoll)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.string/c32ncasecoll.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c32ncasecoll __LIBC_LOCAL_NAME(c32ncasecoll)
#endif /* !... */
#endif /* !__local___localdep_c32ncasecoll_defined */
__LOCAL_LIBC(c32ncasecoll_l) __ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)) int
__NOTHROW_NCX(__LIBKCALL __LIBC_LOCAL_NAME(c32ncasecoll_l))(__CHAR32_TYPE__ const *__s1, __CHAR32_TYPE__ const *__s2, __SIZE_TYPE__ __maxlen, __locale_t __locale) {
	/* XXX: Implement properly? */
	(void)__locale;
	return (__NAMESPACE_LOCAL_SYM __localdep_c32ncasecoll)(__s1, __s2, __maxlen);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c32ncasecoll_l_defined
#define __local___localdep_c32ncasecoll_l_defined
#define __localdep_c32ncasecoll_l __LIBC_LOCAL_NAME(c32ncasecoll_l)
#endif /* !__local___localdep_c32ncasecoll_l_defined */
#endif /* !__local_c32ncasecoll_l_defined */
