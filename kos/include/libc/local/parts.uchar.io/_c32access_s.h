/* HASH CRC-32:0xb2a7d638 */
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
#ifndef __local__c32access_s_defined
#define __local__c32access_s_defined
#include <__crt.h>
#include <asm/os/fcntl.h>
#if (defined(__CRT_HAVE_waccess) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$waccess) || (defined(__CRT_HAVE__waccess) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_waccess) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_access) || defined(__CRT_HAVE__access) || defined(__CRT_HAVE___access) || defined(__CRT_HAVE___libc_access) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_faccessat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wfaccessat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_faccessat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_access) || defined(__CRT_HAVE__access) || defined(__CRT_HAVE___access) || defined(__CRT_HAVE___libc_access) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_faccessat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_c32access_defined
#define __local___localdep_c32access_defined
#if defined(__CRT_HAVE_waccess) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,__localdep_c32access,(__CHAR32_TYPE__ const *__file, __STDC_INT_AS_UINT_T __type),waccess,(__file,__type))
#elif defined(__CRT_HAVE_KOS$waccess)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,__localdep_c32access,(__CHAR32_TYPE__ const *__file, __STDC_INT_AS_UINT_T __type),waccess,(__file,__type))
#elif defined(__CRT_HAVE__waccess) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,__localdep_c32access,(__CHAR32_TYPE__ const *__file, __STDC_INT_AS_UINT_T __type),_waccess,(__file,__type))
#elif defined(__CRT_HAVE_KOS$_waccess)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_RPC,__localdep_c32access,(__CHAR32_TYPE__ const *__file, __STDC_INT_AS_UINT_T __type),_waccess,(__file,__type))
#elif (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_access) || defined(__CRT_HAVE__access) || defined(__CRT_HAVE___access) || defined(__CRT_HAVE___libc_access) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_faccessat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
__NAMESPACE_LOCAL_END
#include <libc/local/parts.wchar.unistd/waccess.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c32access __NAMESPACE_LOCAL_TYPEHAX(int(__LIBKCALL*)(__CHAR32_TYPE__ const *,__STDC_INT_AS_UINT_T),int(__LIBKCALL&)(__CHAR32_TYPE__ const *,__STDC_INT_AS_UINT_T),waccess)
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wfaccessat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_faccessat) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_access) || defined(__CRT_HAVE__access) || defined(__CRT_HAVE___access) || defined(__CRT_HAVE___libc_access) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_faccessat))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.unistd/c32access.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c32access __LIBC_LOCAL_NAME(c32access)
#else /* ... */
#undef __local___localdep_c32access_defined
#endif /* !... */
#endif /* !__local___localdep_c32access_defined */
__NAMESPACE_LOCAL_END
#include <libc/errno.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_c32access_s) __ATTR_WUNUSED __ATTR_NONNULL((1)) __errno_t
__NOTHROW_RPC(__LIBKCALL __LIBC_LOCAL_NAME(_c32access_s))(__CHAR32_TYPE__ const *__file, __STDC_INT_AS_UINT_T __type) {
	if ((__NAMESPACE_LOCAL_SYM __localdep_c32access)(__file, __type) != 0)
		return __libc_geterrno_or(1);
	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__c32access_s_defined
#define __local___localdep__c32access_s_defined
#define __localdep__c32access_s __LIBC_LOCAL_NAME(_c32access_s)
#endif /* !__local___localdep__c32access_s_defined */
#else /* (__CRT_HAVE_waccess && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$waccess || (__CRT_HAVE__waccess && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$_waccess || (__AT_FDCWD && (__CRT_HAVE_wfaccessat || (__CRT_HAVE_faccessat && (__CRT_HAVE_convert_wcstombs || __CRT_HAVE_convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc)))) || ((__CRT_HAVE_access || __CRT_HAVE__access || __CRT_HAVE___access || __CRT_HAVE___libc_access || (__AT_FDCWD && __CRT_HAVE_faccessat)) && (__CRT_HAVE_convert_wcstombs || __CRT_HAVE_convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc) && __SIZEOF_WCHAR_T__ == 4) || (__AT_FDCWD && ((__CRT_HAVE_wfaccessat && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$wfaccessat || (__CRT_HAVE_faccessat && (__CRT_HAVE_convert_wcstombs || __CRT_HAVE_convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc) && __SIZEOF_WCHAR_T__ == 4) || (__CRT_HAVE_faccessat && ((__CRT_HAVE_convert_wcstombs && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$convert_wcstombs || (__CRT_HAVE_convert_wcstombsn && __SIZEOF_WCHAR_T__ == 4) || __CRT_HAVE_KOS$convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc)))) || ((__CRT_HAVE_access || __CRT_HAVE__access || __CRT_HAVE___access || __CRT_HAVE___libc_access || (__AT_FDCWD && __CRT_HAVE_faccessat)) && ((__CRT_HAVE_convert_wcstombs && __SIZEOF_WCHAR_T__ == 4 && __LIBCCALL_IS_LIBKCALL) || __CRT_HAVE_KOS$convert_wcstombs || (__CRT_HAVE_convert_wcstombsn && __SIZEOF_WCHAR_T__ == 4) || __CRT_HAVE_KOS$convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc)) */
#undef __local__c32access_s_defined
#endif /* (!__CRT_HAVE_waccess || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$waccess && (!__CRT_HAVE__waccess || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$_waccess && (!__AT_FDCWD || (!__CRT_HAVE_wfaccessat && (!__CRT_HAVE_faccessat || (!__CRT_HAVE_convert_wcstombs && !__CRT_HAVE_convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc)))) && ((!__CRT_HAVE_access && !__CRT_HAVE__access && !__CRT_HAVE___access && !__CRT_HAVE___libc_access && (!__AT_FDCWD || !__CRT_HAVE_faccessat)) || (!__CRT_HAVE_convert_wcstombs && !__CRT_HAVE_convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc) || __SIZEOF_WCHAR_T__ != 4) && (!__AT_FDCWD || ((!__CRT_HAVE_wfaccessat || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$wfaccessat && (!__CRT_HAVE_faccessat || (!__CRT_HAVE_convert_wcstombs && !__CRT_HAVE_convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc) || __SIZEOF_WCHAR_T__ != 4) && (!__CRT_HAVE_faccessat || ((!__CRT_HAVE_convert_wcstombs || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$convert_wcstombs && (!__CRT_HAVE_convert_wcstombsn || __SIZEOF_WCHAR_T__ != 4) && !__CRT_HAVE_KOS$convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc)))) && ((!__CRT_HAVE_access && !__CRT_HAVE__access && !__CRT_HAVE___access && !__CRT_HAVE___libc_access && (!__AT_FDCWD || !__CRT_HAVE_faccessat)) || ((!__CRT_HAVE_convert_wcstombs || __SIZEOF_WCHAR_T__ != 4 || !__LIBCCALL_IS_LIBKCALL) && !__CRT_HAVE_KOS$convert_wcstombs && (!__CRT_HAVE_convert_wcstombsn || __SIZEOF_WCHAR_T__ != 4) && !__CRT_HAVE_KOS$convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc)) */
#endif /* !__local__c32access_s_defined */
