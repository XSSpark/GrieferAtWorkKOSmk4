/* HASH CRC-32:0xacc2cb4c */
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
#ifndef __local_weuidaccess_defined
#define __local_weuidaccess_defined
#include <__crt.h>
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && defined(__AT_EACCESS) && (defined(__CRT_HAVE_wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_euidaccess) || defined(__CRT_HAVE_eaccess) || (defined(__CRT_HAVE__access) && defined(__CRT_DOS)) || (defined(__AT_FDCWD) && defined(__AT_EACCESS) && defined(__CRT_HAVE_faccessat))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <features.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_convert_wcstombs_defined
#define __local___localdep_convert_wcstombs_defined
#ifdef __CRT_HAVE_convert_wcstombs
__CREDIRECT(__ATTR_MALLOC __ATTR_WUNUSED __ATTR_IN_OPT(1),char *,__NOTHROW_NCX,__localdep_convert_wcstombs,(__WCHAR_TYPE__ const *__str),convert_wcstombs,(__str))
#elif defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)
__NAMESPACE_LOCAL_END
#include <libc/local/uchar/convert_wcstombs.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_convert_wcstombs __LIBC_LOCAL_NAME(convert_wcstombs)
#else /* ... */
#undef __local___localdep_convert_wcstombs_defined
#endif /* !... */
#endif /* !__local___localdep_convert_wcstombs_defined */
#ifndef __local___localdep_euidaccess_defined
#define __local___localdep_euidaccess_defined
#ifdef __CRT_HAVE_euidaccess
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1),int,__NOTHROW_RPC,__localdep_euidaccess,(char const *__file, __STDC_INT_AS_UINT_T __type),euidaccess,(__file,__type))
#elif defined(__CRT_HAVE_eaccess)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1),int,__NOTHROW_RPC,__localdep_euidaccess,(char const *__file, __STDC_INT_AS_UINT_T __type),eaccess,(__file,__type))
#elif defined(__CRT_HAVE__access) && defined(__CRT_DOS)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1),int,__NOTHROW_RPC,__localdep_euidaccess,(char const *__file, __STDC_INT_AS_UINT_T __type),_access,(__file,__type))
#elif defined(__AT_FDCWD) && defined(__AT_EACCESS) && defined(__CRT_HAVE_faccessat)
__NAMESPACE_LOCAL_END
#include <libc/local/unistd/euidaccess.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_euidaccess __LIBC_LOCAL_NAME(euidaccess)
#else /* ... */
#undef __local___localdep_euidaccess_defined
#endif /* !... */
#endif /* !__local___localdep_euidaccess_defined */
#ifndef __local___localdep_free_defined
#define __local___localdep_free_defined
#if __has_builtin(__builtin_free) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_free)
__CEIREDIRECT(,void,__NOTHROW_NCX,__localdep_free,(void *__mallptr),free,{ __builtin_free(__mallptr); })
#elif defined(__CRT_HAVE_free)
__CREDIRECT_VOID(,__NOTHROW_NCX,__localdep_free,(void *__mallptr),free,(__mallptr))
#elif defined(__CRT_HAVE_cfree)
__CREDIRECT_VOID(,__NOTHROW_NCX,__localdep_free,(void *__mallptr),cfree,(__mallptr))
#elif defined(__CRT_HAVE___libc_free)
__CREDIRECT_VOID(,__NOTHROW_NCX,__localdep_free,(void *__mallptr),__libc_free,(__mallptr))
#else /* ... */
#undef __local___localdep_free_defined
#endif /* !... */
#endif /* !__local___localdep_free_defined */
#ifndef __local___localdep_wfaccessat_defined
#define __local___localdep_wfaccessat_defined
#ifdef __CRT_HAVE_wfaccessat
__NAMESPACE_LOCAL_END
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_IN(2),int,__NOTHROW_RPC,__localdep_wfaccessat,(__fd_t __dfd, __WCHAR_TYPE__ const *__file, __STDC_INT_AS_UINT_T __type, __atflag_t __flags),wfaccessat,(__dfd,__file,__type,__flags))
#elif defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
__NAMESPACE_LOCAL_END
#include <libc/local/parts.wchar.unistd/wfaccessat.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wfaccessat __LIBC_LOCAL_NAME(wfaccessat)
#else /* ... */
#undef __local___localdep_wfaccessat_defined
#endif /* !... */
#endif /* !__local___localdep_wfaccessat_defined */
__LOCAL_LIBC(weuidaccess) __ATTR_WUNUSED __ATTR_IN(1) int
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(weuidaccess))(__WCHAR_TYPE__ const *__file, __STDC_INT_AS_UINT_T __type) {
#if defined(__AT_FDCWD) && defined(__AT_EACCESS) && (defined(__CRT_HAVE_wfaccessat) || (defined(__CRT_HAVE_faccessat) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))
	return (__NAMESPACE_LOCAL_SYM __localdep_wfaccessat)(__AT_FDCWD, __file, __type, __AT_EACCESS);
#else /* __AT_FDCWD && __AT_EACCESS && (__CRT_HAVE_wfaccessat || (__CRT_HAVE_faccessat && (__CRT_HAVE_convert_wcstombs || __CRT_HAVE_convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc))) */
	int __result;
	char *__utf8_file;
	__utf8_file = (__NAMESPACE_LOCAL_SYM __localdep_convert_wcstombs)(__file);
	if __unlikely(!__utf8_file)
		return -1;
	__result = (__NAMESPACE_LOCAL_SYM __localdep_euidaccess)(__utf8_file, __type);
#if defined(__CRT_HAVE_free) || defined(__CRT_HAVE_cfree) || defined(__CRT_HAVE___libc_free)
	(__NAMESPACE_LOCAL_SYM __localdep_free)(__utf8_file);
#endif /* __CRT_HAVE_free || __CRT_HAVE_cfree || __CRT_HAVE___libc_free */
	return __result;
#endif /* !__AT_FDCWD || !__AT_EACCESS || (!__CRT_HAVE_wfaccessat && (!__CRT_HAVE_faccessat || (!__CRT_HAVE_convert_wcstombs && !__CRT_HAVE_convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc))) */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_weuidaccess_defined
#define __local___localdep_weuidaccess_defined
#define __localdep_weuidaccess __LIBC_LOCAL_NAME(weuidaccess)
#endif /* !__local___localdep_weuidaccess_defined */
#else /* (__AT_FDCWD && __AT_EACCESS && (__CRT_HAVE_wfaccessat || (__CRT_HAVE_faccessat && (__CRT_HAVE_convert_wcstombs || __CRT_HAVE_convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc)))) || ((__CRT_HAVE_euidaccess || __CRT_HAVE_eaccess || (__CRT_HAVE__access && __CRT_DOS) || (__AT_FDCWD && __AT_EACCESS && __CRT_HAVE_faccessat)) && (__CRT_HAVE_convert_wcstombs || __CRT_HAVE_convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc)) */
#undef __local_weuidaccess_defined
#endif /* (!__AT_FDCWD || !__AT_EACCESS || (!__CRT_HAVE_wfaccessat && (!__CRT_HAVE_faccessat || (!__CRT_HAVE_convert_wcstombs && !__CRT_HAVE_convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc)))) && ((!__CRT_HAVE_euidaccess && !__CRT_HAVE_eaccess && (!__CRT_HAVE__access || !__CRT_DOS) && (!__AT_FDCWD || !__AT_EACCESS || !__CRT_HAVE_faccessat)) || (!__CRT_HAVE_convert_wcstombs && !__CRT_HAVE_convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc)) */
#endif /* !__local_weuidaccess_defined */
