/* HASH CRC-32:0x14ca8490 */
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
#ifndef __local_wcstol_l_defined
#define __local_wcstol_l_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: wcstol from wchar */
#ifndef __local___localdep_wcstol_defined
#define __local___localdep_wcstol_defined 1
#ifdef __CRT_HAVE_wcstol
__CREDIRECT(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstol,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstol) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcstol,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstol) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcstol,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstoll) && (__SIZEOF_LONG__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstoll,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoll) && (__SIZEOF_LONG__ == __SIZEOF_LONG_LONG__) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcstoll,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoll) && (__SIZEOF_LONG__ == __SIZEOF_LONG_LONG__) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcstoll,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstoq) && (__SIZEOF_LONG__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstoq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoq) && (__SIZEOF_LONG__ == __SIZEOF_LONG_LONG__) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcstoq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoq) && (__SIZEOF_LONG__ == __SIZEOF_LONG_LONG__) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcstoq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcsto32) && (__SIZEOF_LONG__ == 4)
__CREDIRECT(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcsto32,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcsto32) && (__SIZEOF_LONG__ == 4) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcsto32,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcsto32) && (__SIZEOF_LONG__ == 4) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcsto32,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcsto64) && (__SIZEOF_LONG__ == 8)
__CREDIRECT(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcsto64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcsto64) && (__SIZEOF_LONG__ == 8) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcsto64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcsto64) && (__SIZEOF_LONG__ == 8) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcsto64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE__wcstoi64) && (__SIZEOF_LONG__ == 8)
__CREDIRECT(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),_wcstoi64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$_wcstoi64) && (__SIZEOF_LONG__ == 8) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),_wcstoi64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$_wcstoi64) && (__SIZEOF_LONG__ == 8) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),_wcstoi64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstoimax) && (__SIZEOF_LONG__ == __SIZEOF_INTMAX_T__)
__CREDIRECT(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstoimax,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoimax) && (__SIZEOF_LONG__ == __SIZEOF_INTMAX_T__) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT_KOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR32_TYPE__ const *__restrict __nptr, __CHAR32_TYPE__ **__endptr, int __base),wcstoimax,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_DOS$wcstoimax) && (__SIZEOF_LONG__ == __SIZEOF_INTMAX_T__) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT_DOS(__ATTR_NONNULL((1)),long,__NOTHROW_NCX,__localdep_wcstol,(__CHAR16_TYPE__ const *__restrict __nptr, __CHAR16_TYPE__ **__endptr, int __base),wcstoimax,(__nptr,__endptr,__base))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/wchar/wcstol.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wcstol __LIBC_LOCAL_NAME(wcstol)
#endif /* !... */
#endif /* !__local___localdep_wcstol_defined */
__LOCAL_LIBC(wcstol_l) __ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)) long
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wcstol_l))(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale) {
	(void)__locale;
	return __localdep_wcstol(__nptr, __endptr, __base);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wcstol_l_defined
#define __local___localdep_wcstol_l_defined 1
#define __localdep_wcstol_l __LIBC_LOCAL_NAME(wcstol_l)
#endif /* !__local___localdep_wcstol_l_defined */
#endif /* !__local_wcstol_l_defined */
