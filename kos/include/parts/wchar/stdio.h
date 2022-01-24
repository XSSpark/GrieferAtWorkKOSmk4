/* HASH CRC-32:0xba71bbeb */
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
#ifndef _PARTS_WCHAR_STDIO_H
#define _PARTS_WCHAR_STDIO_H 1

#include <__stdinc.h>
#include <__crt.h>

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#ifndef _STDIO_H
#include <stdio.h>
#endif /* !_STDIO_H */
#ifndef _WCHAR_H
#include <wchar.h>
#endif /* !_WCHAR_H */

#include <bits/types.h>

#ifdef __CC__
__SYSDECL_BEGIN

#ifndef __wremove_defined
#define __wremove_defined
#ifdef __CRT_HAVE_wremove
__CDECLARE(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,wremove,(wchar_t const *__filename),(__filename))
#elif defined(__CRT_HAVE__wremove)
__CREDIRECT(__ATTR_NONNULL((1)),int,__NOTHROW_NCX,wremove,(wchar_t const *__filename),_wremove,(__filename))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_remove) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_removeat)))
#include <libc/local/parts.wchar.stdio/wremove.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(wremove, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_NONNULL((1)) int __NOTHROW_NCX(__LIBCCALL wremove)(wchar_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wremove))(__filename); })
#else /* (__CRT_HAVE_convert_wcstombs || __CRT_HAVE_convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc) && (__CRT_HAVE_remove || (__AT_FDCWD && __CRT_HAVE_removeat)) */
#undef __wremove_defined
#endif /* (!__CRT_HAVE_convert_wcstombs && !__CRT_HAVE_convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc) || (!__CRT_HAVE_remove && (!__AT_FDCWD || !__CRT_HAVE_removeat)) */
#endif /* !... */
#endif /* !__wremove_defined */
#ifdef __CRT_HAVE_wfopen
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),__FILE *,__NOTHROW_NCX,wfopen,(wchar_t const *__filename, wchar_t const *__mode),(__filename,__mode))
#elif defined(__CRT_HAVE__wfopen)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),__FILE *,__NOTHROW_NCX,wfopen,(wchar_t const *__filename, wchar_t const *__mode),_wfopen,(__filename,__mode))
#else /* ... */
#include <asm/os/oflags.h>
#if (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && ((defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64))
#include <libc/local/parts.wchar.stdio/wfopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(wfopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) __FILE *__NOTHROW_NCX(__LIBCCALL wfopen)(wchar_t const *__filename, wchar_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfopen))(__filename, __mode); })
#endif /* (__CRT_HAVE_convert_wcstombs || __CRT_HAVE_convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc) && ((__CRT_HAVE_fopen && (!__USE_FILE_OFFSET64 || !__O_LARGEFILE || !__O_LARGEFILE)) || (__CRT_HAVE__IO_fopen && (!__USE_FILE_OFFSET64 || !__O_LARGEFILE || !__O_LARGEFILE)) || __CRT_HAVE_fopen64) */
#endif /* !... */
#ifdef __CRT_HAVE_wfreopen
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),__FILE *,__NOTHROW_NCX,wfreopen,(wchar_t const *__filename, wchar_t const *__mode, __FILE *__stream),(__filename,__mode,__stream))
#elif defined(__CRT_HAVE__wfreopen)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),__FILE *,__NOTHROW_NCX,wfreopen,(wchar_t const *__filename, wchar_t const *__mode, __FILE *__stream),_wfreopen,(__filename,__mode,__stream))
#else /* ... */
#include <asm/os/oflags.h>
#if (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && ((defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked))
#include <libc/local/parts.wchar.stdio/wfreopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(wfreopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) __FILE *__NOTHROW_NCX(__LIBCCALL wfreopen)(wchar_t const *__filename, wchar_t const *__mode, __FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfreopen))(__filename, __mode, __stream); })
#endif /* (__CRT_HAVE_convert_wcstombs || __CRT_HAVE_convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc) && ((__CRT_HAVE_freopen && (!__USE_FILE_OFFSET64 || !__O_LARGEFILE || !__O_LARGEFILE)) || __CRT_HAVE_freopen64 || (__CRT_HAVE_freopen_unlocked && (!__USE_FILE_OFFSET64 || !__O_LARGEFILE || !__O_LARGEFILE)) || __CRT_HAVE_freopen64_unlocked) */
#endif /* !... */
#ifndef __wpopen_defined
#define __wpopen_defined
#ifdef __CRT_HAVE_wpopen
__CDECLARE(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),__FILE *,__NOTHROW_NCX,wpopen,(wchar_t const *__command, wchar_t const *__mode),(__command,__mode))
#elif defined(__CRT_HAVE__wpopen)
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),__FILE *,__NOTHROW_NCX,wpopen,(wchar_t const *__command, wchar_t const *__mode),_wpopen,(__command,__mode))
#elif (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_popen) || defined(__CRT_HAVE__popen) || defined(__CRT_HAVE__IO_popen))
#include <libc/local/parts.wchar.stdio/wpopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(wpopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) __FILE *__NOTHROW_NCX(__LIBCCALL wpopen)(wchar_t const *__command, wchar_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wpopen))(__command, __mode); })
#else /* ... */
#undef __wpopen_defined
#endif /* !... */
#endif /* !__wpopen_defined */

__SYSDECL_END
#endif /* __CC__ */

#endif /* !_PARTS_WCHAR_STDIO_H */
