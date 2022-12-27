/* HASH CRC-32:0xbc84d7f */
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
#ifndef _PARTS_UCHAR_STDIO_H
#define _PARTS_UCHAR_STDIO_H 1

#include <__stdinc.h>
#include <__crt.h>

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#include <kos/anno.h>
#ifndef _STDIO_H
#include <stdio.h>
#endif /* !_STDIO_H */
#ifndef _UCHAR_H
#include <uchar.h>
#endif /* !_UCHAR_H */

#ifdef __USE_KOS
#include <bits/crt/uformat-printer.h>
#endif /* __USE_KOS */

#ifndef WEOF16
#define WEOF16 __WEOF16
#define WEOF32 __WEOF32
#endif /* !WEOF16 */

#ifdef __CC__
__SYSDECL_BEGIN

/************************************************************************/
/* WARNING: UTF-16 functions use DOS paths under `DOSFS_ENABLED'        */
/*          s.a. `dosfs_setenabled(3)'                                  */
/************************************************************************/

#ifndef __wint16_t_defined
#define __wint16_t_defined
typedef __WINT16_TYPE__ wint16_t;
typedef __WINT32_TYPE__ wint32_t;
#endif /* !__wint16_t_defined */

#if defined(__CRT_HAVE_wremove) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_RPC,c16remove,(char16_t const *__filename),wremove,(__filename))
#elif defined(__CRT_HAVE_DOS$wremove)
__CREDIRECT_DOS(__ATTR_IN(1),int,__NOTHROW_RPC,c16remove,(char16_t const *__filename),wremove,(__filename))
#elif defined(__CRT_HAVE__wremove) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_RPC,c16remove,(char16_t const *__filename),_wremove,(__filename))
#elif defined(__CRT_HAVE_DOS$_wremove)
__CREDIRECT_DOS(__ATTR_IN(1),int,__NOTHROW_RPC,c16remove,(char16_t const *__filename),_wremove,(__filename))
#else /* ... */
#include <asm/os/fcntl.h>
#include <asm/os/errno.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wremoveat) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_remove) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR)))))) || (defined(__EISDIR) && defined(__ENOTDIR) && (defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.stdio/wremove.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) int __NOTHROW_RPC(__LIBDCALL c16remove)(char16_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wremove))((__WCHAR_TYPE__ const *)__filename); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wremoveat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wremoveat) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_remove) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR)))))) || (defined(__EISDIR) && defined(__ENOTDIR) && (defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.stdio/c16remove.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16remove, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) int __NOTHROW_RPC(__LIBDCALL c16remove)(char16_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16remove))(__filename); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wremove) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_RPC,c32remove,(char32_t const *__filename),wremove,(__filename))
#elif defined(__CRT_HAVE_KOS$wremove)
__CREDIRECT_KOS(__ATTR_IN(1),int,__NOTHROW_RPC,c32remove,(char32_t const *__filename),wremove,(__filename))
#elif defined(__CRT_HAVE__wremove) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_RPC,c32remove,(char32_t const *__filename),_wremove,(__filename))
#elif defined(__CRT_HAVE_KOS$_wremove)
__CREDIRECT_KOS(__ATTR_IN(1),int,__NOTHROW_RPC,c32remove,(char32_t const *__filename),_wremove,(__filename))
#else /* ... */
#include <asm/os/fcntl.h>
#include <asm/os/errno.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wremoveat) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_remove) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR)))))) || (defined(__EISDIR) && defined(__ENOTDIR) && (defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.stdio/wremove.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) int __NOTHROW_RPC(__LIBKCALL c32remove)(char32_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wremove))((__WCHAR_TYPE__ const *)__filename); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wremoveat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wremoveat) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_remove) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR)))))) || (defined(__EISDIR) && defined(__ENOTDIR) && (defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.stdio/c32remove.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32remove, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) int __NOTHROW_RPC(__LIBKCALL c32remove)(char32_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32remove))(__filename); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wrename) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_RPC,c16rename,(char16_t const *__oldname, char16_t const *__newname_or_path),wrename,(__oldname,__newname_or_path))
#elif defined(__CRT_HAVE_DOS$wrename)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_RPC,c16rename,(char16_t const *__oldname, char16_t const *__newname_or_path),wrename,(__oldname,__newname_or_path))
#elif defined(__CRT_HAVE__wrename) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_RPC,c16rename,(char16_t const *__oldname, char16_t const *__newname_or_path),_wrename,(__oldname,__newname_or_path))
#elif defined(__CRT_HAVE_DOS$_wrename)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_RPC,c16rename,(char16_t const *__oldname, char16_t const *__newname_or_path),_wrename,(__oldname,__newname_or_path))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wrenameat) || defined(__CRT_HAVE_wrenameat2) || (defined(__CRT_HAVE_renameat2) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_renameat) || defined(__CRT_HAVE_renameat2)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_renameat) || defined(__CRT_HAVE_renameat2)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.stdio/wrename.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) int __NOTHROW_RPC(__LIBDCALL c16rename)(char16_t const *__oldname, char16_t const *__newname_or_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wrename))((__WCHAR_TYPE__ const *)__oldname, (__WCHAR_TYPE__ const *)__newname_or_path); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wrenameat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wrenameat) || defined(__CRT_HAVE_wrenameat2) || (defined(__CRT_HAVE_renameat2) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || defined(__CRT_HAVE_DOS$wrenameat2) || (defined(__CRT_HAVE_renameat2) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_renameat) || defined(__CRT_HAVE_renameat2)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.stdio/c16rename.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16rename, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) int __NOTHROW_RPC(__LIBDCALL c16rename)(char16_t const *__oldname, char16_t const *__newname_or_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16rename))(__oldname, __newname_or_path); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wrename) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_RPC,c32rename,(char32_t const *__oldname, char32_t const *__newname_or_path),wrename,(__oldname,__newname_or_path))
#elif defined(__CRT_HAVE_KOS$wrename)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_RPC,c32rename,(char32_t const *__oldname, char32_t const *__newname_or_path),wrename,(__oldname,__newname_or_path))
#elif defined(__CRT_HAVE__wrename) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_RPC,c32rename,(char32_t const *__oldname, char32_t const *__newname_or_path),_wrename,(__oldname,__newname_or_path))
#elif defined(__CRT_HAVE_KOS$_wrename)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_RPC,c32rename,(char32_t const *__oldname, char32_t const *__newname_or_path),_wrename,(__oldname,__newname_or_path))
#else /* ... */
#include <asm/os/fcntl.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wrenameat) || defined(__CRT_HAVE_wrenameat2) || (defined(__CRT_HAVE_renameat2) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_renameat) || defined(__CRT_HAVE_renameat2)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_renameat) || defined(__CRT_HAVE_renameat2)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.stdio/wrename.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) int __NOTHROW_RPC(__LIBKCALL c32rename)(char32_t const *__oldname, char32_t const *__newname_or_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wrename))((__WCHAR_TYPE__ const *)__oldname, (__WCHAR_TYPE__ const *)__newname_or_path); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wrenameat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wrenameat) || defined(__CRT_HAVE_wrenameat2) || (defined(__CRT_HAVE_renameat2) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || defined(__CRT_HAVE_KOS$wrenameat2) || (defined(__CRT_HAVE_renameat2) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_renameat) || defined(__CRT_HAVE_renameat2)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.stdio/c32rename.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32rename, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) int __NOTHROW_RPC(__LIBKCALL c32rename)(char32_t const *__oldname, char32_t const *__newname_or_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32rename))(__oldname, __newname_or_path); })
#endif /* ... */
#endif /* !... */

#ifdef __USE_ATFILE
#if defined(__CRT_HAVE_wrenameat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_IN(4),int,__NOTHROW_RPC,c16renameat,(__fd_t __oldfd, char16_t const *__oldname, __fd_t __newfd, char16_t const *__newname_or_path),wrenameat,(__oldfd,__oldname,__newfd,__newname_or_path))
#elif defined(__CRT_HAVE_DOS$wrenameat)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_IN(4),int,__NOTHROW_RPC,c16renameat,(__fd_t __oldfd, char16_t const *__oldname, __fd_t __newfd, char16_t const *__newname_or_path),wrenameat,(__oldfd,__oldname,__newfd,__newname_or_path))
#elif defined(__CRT_HAVE_wrenameat2) || (defined(__CRT_HAVE_renameat2) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_renameat) || defined(__CRT_HAVE_renameat2)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.stdio/wrenameat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(4) int __NOTHROW_RPC(__LIBDCALL c16renameat)(__fd_t __oldfd, char16_t const *__oldname, __fd_t __newfd, char16_t const *__newname_or_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wrenameat))(__oldfd, (__WCHAR_TYPE__ const *)__oldname, __newfd, (__WCHAR_TYPE__ const *)__newname_or_path); }
#elif defined(__CRT_HAVE_DOS$wrenameat2) || (defined(__CRT_HAVE_renameat2) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_renameat) || defined(__CRT_HAVE_renameat2)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.stdio/c16renameat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16renameat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(4) int __NOTHROW_RPC(__LIBDCALL c16renameat)(__fd_t __oldfd, char16_t const *__oldname, __fd_t __newfd, char16_t const *__newname_or_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16renameat))(__oldfd, __oldname, __newfd, __newname_or_path); })
#endif /* ... */
#if defined(__CRT_HAVE_wrenameat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_IN(4),int,__NOTHROW_RPC,c32renameat,(__fd_t __oldfd, char32_t const *__oldname, __fd_t __newfd, char32_t const *__newname_or_path),wrenameat,(__oldfd,__oldname,__newfd,__newname_or_path))
#elif defined(__CRT_HAVE_KOS$wrenameat)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_IN(4),int,__NOTHROW_RPC,c32renameat,(__fd_t __oldfd, char32_t const *__oldname, __fd_t __newfd, char32_t const *__newname_or_path),wrenameat,(__oldfd,__oldname,__newfd,__newname_or_path))
#elif defined(__CRT_HAVE_wrenameat2) || (defined(__CRT_HAVE_renameat2) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_renameat) || defined(__CRT_HAVE_renameat2)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.stdio/wrenameat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(4) int __NOTHROW_RPC(__LIBKCALL c32renameat)(__fd_t __oldfd, char32_t const *__oldname, __fd_t __newfd, char32_t const *__newname_or_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wrenameat))(__oldfd, (__WCHAR_TYPE__ const *)__oldname, __newfd, (__WCHAR_TYPE__ const *)__newname_or_path); }
#elif defined(__CRT_HAVE_KOS$wrenameat2) || (defined(__CRT_HAVE_renameat2) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))) || ((defined(__CRT_HAVE_renameat) || defined(__CRT_HAVE_renameat2)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.stdio/c32renameat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32renameat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(4) int __NOTHROW_RPC(__LIBKCALL c32renameat)(__fd_t __oldfd, char32_t const *__oldname, __fd_t __newfd, char32_t const *__newname_or_path) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32renameat))(__oldfd, __oldname, __newfd, __newname_or_path); })
#endif /* ... */

#ifdef __USE_KOS
#if defined(__CRT_HAVE_wremoveat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2),int,__NOTHROW_RPC,c16removeat,(__fd_t __dirfd, char16_t const *__filename),wremoveat,(__dirfd,__filename))
#elif defined(__CRT_HAVE_DOS$wremoveat)
__CREDIRECT_DOS(__ATTR_IN(2),int,__NOTHROW_RPC,c16removeat,(__fd_t __dirfd, char16_t const *__filename),wremoveat,(__dirfd,__filename))
#else /* ... */
#include <asm/os/fcntl.h>
#include <asm/os/errno.h>
#if (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.stdio/wremoveat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) int __NOTHROW_RPC(__LIBDCALL c16removeat)(__fd_t __dirfd, char16_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wremoveat))(__dirfd, (__WCHAR_TYPE__ const *)__filename); }
#elif (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c16removeat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16removeat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) int __NOTHROW_RPC(__LIBDCALL c16removeat)(__fd_t __dirfd, char16_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16removeat))(__dirfd, __filename); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wremoveat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2),int,__NOTHROW_RPC,c32removeat,(__fd_t __dirfd, char32_t const *__filename),wremoveat,(__dirfd,__filename))
#elif defined(__CRT_HAVE_KOS$wremoveat)
__CREDIRECT_KOS(__ATTR_IN(2),int,__NOTHROW_RPC,c32removeat,(__fd_t __dirfd, char32_t const *__filename),wremoveat,(__dirfd,__filename))
#else /* ... */
#include <asm/os/fcntl.h>
#include <asm/os/errno.h>
#if (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.stdio/wremoveat.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) int __NOTHROW_RPC(__LIBKCALL c32removeat)(__fd_t __dirfd, char32_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wremoveat))(__dirfd, (__WCHAR_TYPE__ const *)__filename); }
#elif (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c32removeat.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32removeat, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) int __NOTHROW_RPC(__LIBKCALL c32removeat)(__fd_t __dirfd, char32_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32removeat))(__dirfd, __filename); })
#endif /* ... */
#endif /* !... */
#endif /* __USE_KOS */
#endif /* __USE_ATFILE */

#ifdef __USE_GNU
#if defined(__CRT_HAVE_wrenameat2) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_IN(4),int,__NOTHROW_RPC,c16renameat2,(__fd_t __oldfd, char16_t const *__oldname, __fd_t __newfd, char16_t const *__newname_or_path, __atflag_t __flags),wrenameat2,(__oldfd,__oldname,__newfd,__newname_or_path,__flags))
#elif defined(__CRT_HAVE_DOS$wrenameat2)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_IN(4),int,__NOTHROW_RPC,c16renameat2,(__fd_t __oldfd, char16_t const *__oldname, __fd_t __newfd, char16_t const *__newname_or_path, __atflag_t __flags),wrenameat2,(__oldfd,__oldname,__newfd,__newname_or_path,__flags))
#elif defined(__CRT_HAVE_renameat2) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.stdio/wrenameat2.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(4) int __NOTHROW_RPC(__LIBDCALL c16renameat2)(__fd_t __oldfd, char16_t const *__oldname, __fd_t __newfd, char16_t const *__newname_or_path, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wrenameat2))(__oldfd, (__WCHAR_TYPE__ const *)__oldname, __newfd, (__WCHAR_TYPE__ const *)__newname_or_path, __flags); }
#elif defined(__CRT_HAVE_renameat2) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c16renameat2.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16renameat2, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(4) int __NOTHROW_RPC(__LIBDCALL c16renameat2)(__fd_t __oldfd, char16_t const *__oldname, __fd_t __newfd, char16_t const *__newname_or_path, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16renameat2))(__oldfd, __oldname, __newfd, __newname_or_path, __flags); })
#endif /* ... */
#if defined(__CRT_HAVE_wrenameat2) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_IN(4),int,__NOTHROW_RPC,c32renameat2,(__fd_t __oldfd, char32_t const *__oldname, __fd_t __newfd, char32_t const *__newname_or_path, __atflag_t __flags),wrenameat2,(__oldfd,__oldname,__newfd,__newname_or_path,__flags))
#elif defined(__CRT_HAVE_KOS$wrenameat2)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_IN(4),int,__NOTHROW_RPC,c32renameat2,(__fd_t __oldfd, char32_t const *__oldname, __fd_t __newfd, char32_t const *__newname_or_path, __atflag_t __flags),wrenameat2,(__oldfd,__oldname,__newfd,__newname_or_path,__flags))
#elif defined(__CRT_HAVE_renameat2) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.stdio/wrenameat2.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(4) int __NOTHROW_RPC(__LIBKCALL c32renameat2)(__fd_t __oldfd, char32_t const *__oldname, __fd_t __newfd, char32_t const *__newname_or_path, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wrenameat2))(__oldfd, (__WCHAR_TYPE__ const *)__oldname, __newfd, (__WCHAR_TYPE__ const *)__newname_or_path, __flags); }
#elif defined(__CRT_HAVE_renameat2) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c32renameat2.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32renameat2, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(4) int __NOTHROW_RPC(__LIBKCALL c32renameat2)(__fd_t __oldfd, char32_t const *__oldname, __fd_t __newfd, char32_t const *__newname_or_path, __atflag_t __flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32renameat2))(__oldfd, __oldname, __newfd, __newname_or_path, __flags); })
#endif /* ... */
#endif /* __USE_GNU */
#if defined(__CRT_HAVE_wfopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c16fopen,(char16_t const *__filename, char16_t const *__mode),wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE_DOS$wfopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c16fopen,(char16_t const *__filename, char16_t const *__mode),wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE__wfopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c16fopen,(char16_t const *__filename, char16_t const *__mode),_wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE_DOS$_wfopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c16fopen,(char16_t const *__filename, char16_t const *__mode),_wfopen,(__filename,__mode))
#else /* ... */
#include <asm/os/oflags.h>
#if ((defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.stdio/wfopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBDCALL c16fopen)(char16_t const *__filename, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfopen))((__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode); }
#elif ((defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c16fopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16fopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBDCALL c16fopen)(char16_t const *__filename, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16fopen))(__filename, __mode); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wfopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c32fopen,(char32_t const *__filename, char32_t const *__mode),wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE_KOS$wfopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c32fopen,(char32_t const *__filename, char32_t const *__mode),wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE__wfopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c32fopen,(char32_t const *__filename, char32_t const *__mode),_wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE_KOS$_wfopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c32fopen,(char32_t const *__filename, char32_t const *__mode),_wfopen,(__filename,__mode))
#else /* ... */
#include <asm/os/oflags.h>
#if ((defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.stdio/wfopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBKCALL c32fopen)(char32_t const *__filename, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfopen))((__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode); }
#elif ((defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c32fopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32fopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBKCALL c32fopen)(char32_t const *__filename, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32fopen))(__filename, __mode); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wfreopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,c16freopen,(char16_t const *__filename, char16_t const *__mode, __FILE *__stream),wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE_DOS$wfreopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,c16freopen,(char16_t const *__filename, char16_t const *__mode, __FILE *__stream),wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE__wfreopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,c16freopen,(char16_t const *__filename, char16_t const *__mode, __FILE *__stream),_wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE_DOS$_wfreopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,c16freopen,(char16_t const *__filename, char16_t const *__mode, __FILE *__stream),_wfreopen,(__filename,__mode,__stream))
#else /* ... */
#include <asm/os/oflags.h>
#if ((defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.stdio/wfreopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3) __FILE *__NOTHROW_NCX(__LIBDCALL c16freopen)(char16_t const *__filename, char16_t const *__mode, __FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfreopen))((__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode, __stream); }
#elif ((defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c16freopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16freopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3) __FILE *__NOTHROW_NCX(__LIBDCALL c16freopen)(char16_t const *__filename, char16_t const *__mode, __FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16freopen))(__filename, __mode, __stream); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wfreopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,c32freopen,(char32_t const *__filename, char32_t const *__mode, __FILE *__stream),wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE_KOS$wfreopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,c32freopen,(char32_t const *__filename, char32_t const *__mode, __FILE *__stream),wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE__wfreopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,c32freopen,(char32_t const *__filename, char32_t const *__mode, __FILE *__stream),_wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE_KOS$_wfreopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,c32freopen,(char32_t const *__filename, char32_t const *__mode, __FILE *__stream),_wfreopen,(__filename,__mode,__stream))
#else /* ... */
#include <asm/os/oflags.h>
#if ((defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.stdio/wfreopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3) __FILE *__NOTHROW_NCX(__LIBKCALL c32freopen)(char32_t const *__filename, char32_t const *__mode, __FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfreopen))((__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode, __stream); }
#elif ((defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c32freopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32freopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3) __FILE *__NOTHROW_NCX(__LIBKCALL c32freopen)(char32_t const *__filename, char32_t const *__mode, __FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32freopen))(__filename, __mode, __stream); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wpopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c16popen,(char16_t const *__command, char16_t const *__mode),wpopen,(__command,__mode))
#elif defined(__CRT_HAVE_DOS$wpopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c16popen,(char16_t const *__command, char16_t const *__mode),wpopen,(__command,__mode))
#elif defined(__CRT_HAVE__wpopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c16popen,(char16_t const *__command, char16_t const *__mode),_wpopen,(__command,__mode))
#elif defined(__CRT_HAVE_DOS$_wpopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c16popen,(char16_t const *__command, char16_t const *__mode),_wpopen,(__command,__mode))
#elif (defined(__CRT_HAVE_popen) || defined(__CRT_HAVE__popen) || defined(__CRT_HAVE__IO_popen)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.stdio/wpopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBDCALL c16popen)(char16_t const *__command, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wpopen))((__WCHAR_TYPE__ const *)__command, (__WCHAR_TYPE__ const *)__mode); }
#elif (defined(__CRT_HAVE_popen) || defined(__CRT_HAVE__popen) || defined(__CRT_HAVE__IO_popen)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c16popen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c16popen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBDCALL c16popen)(char16_t const *__command, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16popen))(__command, __mode); })
#endif /* ... */
#if defined(__CRT_HAVE_wpopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c32popen,(char32_t const *__command, char32_t const *__mode),wpopen,(__command,__mode))
#elif defined(__CRT_HAVE_KOS$wpopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c32popen,(char32_t const *__command, char32_t const *__mode),wpopen,(__command,__mode))
#elif defined(__CRT_HAVE__wpopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c32popen,(char32_t const *__command, char32_t const *__mode),_wpopen,(__command,__mode))
#elif defined(__CRT_HAVE_KOS$_wpopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,c32popen,(char32_t const *__command, char32_t const *__mode),_wpopen,(__command,__mode))
#elif (defined(__CRT_HAVE_popen) || defined(__CRT_HAVE__popen) || defined(__CRT_HAVE__IO_popen)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.stdio/wpopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBKCALL c32popen)(char32_t const *__command, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wpopen))((__WCHAR_TYPE__ const *)__command, (__WCHAR_TYPE__ const *)__mode); }
#elif (defined(__CRT_HAVE_popen) || defined(__CRT_HAVE__popen) || defined(__CRT_HAVE__IO_popen)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c32popen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(c32popen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBKCALL c32popen)(char32_t const *__command, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32popen))(__command, __mode); })
#endif /* ... */
#if defined(__CRT_HAVE_getwchar_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,getchar16,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_DOS$getwchar_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,getchar16,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_getwchar) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,getchar16,(void),getwchar,())
#elif defined(__CRT_HAVE_DOS$getwchar)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,getchar16,(void),getwchar,())
#elif defined(__CRT_HAVE__fgetwchar) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,getchar16,(void),_fgetwchar,())
#elif defined(__CRT_HAVE_DOS$_fgetwchar)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,getchar16,(void),_fgetwchar,())
#elif defined(__CRT_HAVE_getwchar_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,getchar16,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_DOS$getwchar_unlocked)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,getchar16,(void),getwchar_unlocked,())
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/getwchar.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint16_t (__LIBDCALL getchar16)(void) __THROWS(...) { return (__WINT16_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getwchar))(); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked))
#include <libc/local/parts.uchar.stdio/getchar16.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(getchar16, __FORCELOCAL __ATTR_ARTIFICIAL wint16_t (__LIBDCALL getchar16)(void) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getchar16))(); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_getwchar_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,getchar32,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_KOS$getwchar_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,getchar32,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_getwchar) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,getchar32,(void),getwchar,())
#elif defined(__CRT_HAVE_KOS$getwchar)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,getchar32,(void),getwchar,())
#elif defined(__CRT_HAVE__fgetwchar) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,getchar32,(void),_fgetwchar,())
#elif defined(__CRT_HAVE_KOS$_fgetwchar)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,getchar32,(void),_fgetwchar,())
#elif defined(__CRT_HAVE_getwchar_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,getchar32,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_KOS$getwchar_unlocked)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,getchar32,(void),getwchar_unlocked,())
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/getwchar.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint32_t (__LIBKCALL getchar32)(void) __THROWS(...) { return (__WINT32_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getwchar))(); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked))
#include <libc/local/parts.uchar.stdio/getchar32.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(getchar32, __FORCELOCAL __ATTR_ARTIFICIAL wint32_t (__LIBKCALL getchar32)(void) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getchar32))(); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,fgetc16,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,fgetc32,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),wint16_t,__THROWING,getc16,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),wint32_t,__THROWING,getc32,(FILE *__restrict __stream),getwc_unlocked,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_putwchar_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,putchar16,(char16_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_DOS$putwchar_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,putchar16,(char16_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_putwchar) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,putchar16,(char16_t __wc),putwchar,(__wc))
#elif defined(__CRT_HAVE_DOS$putwchar)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,putchar16,(char16_t __wc),putwchar,(__wc))
#elif defined(__CRT_HAVE__fputwchar) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,putchar16,(char16_t __wc),_fputwchar,(__wc))
#elif defined(__CRT_HAVE_DOS$_fputwchar)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,putchar16,(char16_t __wc),_fputwchar,(__wc))
#elif defined(__CRT_HAVE_putwchar_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,putchar16,(char16_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_DOS$putwchar_unlocked)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,putchar16,(char16_t __wc),putwchar_unlocked,(__wc))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/putwchar.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint16_t (__LIBDCALL putchar16)(char16_t __wc) __THROWS(...) { return (__WINT16_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putwchar))((__WCHAR_TYPE__)__wc); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/putchar16.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(putchar16, __FORCELOCAL __ATTR_ARTIFICIAL wint16_t (__LIBDCALL putchar16)(char16_t __wc) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putchar16))(__wc); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_putwchar_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,putchar32,(char32_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_KOS$putwchar_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,putchar32,(char32_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_putwchar) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,putchar32,(char32_t __wc),putwchar,(__wc))
#elif defined(__CRT_HAVE_KOS$putwchar)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,putchar32,(char32_t __wc),putwchar,(__wc))
#elif defined(__CRT_HAVE__fputwchar) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,putchar32,(char32_t __wc),_fputwchar,(__wc))
#elif defined(__CRT_HAVE_KOS$_fputwchar)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,putchar32,(char32_t __wc),_fputwchar,(__wc))
#elif defined(__CRT_HAVE_putwchar_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,putchar32,(char32_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_KOS$putwchar_unlocked)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,putchar32,(char32_t __wc),putwchar_unlocked,(__wc))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/putwchar.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint32_t (__LIBKCALL putchar32)(char32_t __wc) __THROWS(...) { return (__WINT32_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putwchar))((__WCHAR_TYPE__)__wc); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/putchar32.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(putchar32, __FORCELOCAL __ATTR_ARTIFICIAL wint32_t (__LIBKCALL putchar32)(char32_t __wc) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putchar32))(__wc); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_fputwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,fputc16,(char16_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,fputc32,(char32_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__THROWING,putc16,(char16_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__THROWING,putc32,(char32_t __wc, FILE *__stream),putwc_unlocked,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetws_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_DOS$fgetws_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE__fgetws_nolock) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_DOS$_fgetws_nolock) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_fgetws) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_DOS$fgetws)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_fgetws_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_DOS$fgetws_unlocked)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE__fgetws_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_DOS$_fgetws_nolock)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif (defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/fgetws.h>
/* >> fgetws(3), fgetws_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2) char16_t *(__LIBDCALL fgetc16s)(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream) __THROWS(...) { return (__CHAR16_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fgetws))((__WCHAR_TYPE__ *)__buf, __bufsize, __stream); }
#elif ((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked))
#include <libc/local/parts.uchar.stdio/fgetc16s.h>
/* >> fgetws(3), fgetws_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(fgetc16s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2) char16_t *(__LIBDCALL fgetc16s)(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fgetc16s))(__buf, __bufsize, __stream); })
#endif /* ... */
#if defined(__CRT_HAVE_fgetws_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_KOS$fgetws_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE__fgetws_nolock) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_KOS$_fgetws_nolock) && defined(__USE_STDIO_UNLOCKED)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_fgetws) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_KOS$fgetws)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_fgetws_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_KOS$fgetws_unlocked)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE__fgetws_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_KOS$_fgetws_nolock)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif (defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/fgetws.h>
/* >> fgetws(3), fgetws_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2) char32_t *(__LIBKCALL fgetc32s)(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream) __THROWS(...) { return (__CHAR32_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fgetws))((__WCHAR_TYPE__ *)__buf, __bufsize, __stream); }
#elif ((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked))
#include <libc/local/parts.uchar.stdio/fgetc32s.h>
/* >> fgetws(3), fgetws_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(fgetc32s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_INOUT(3) __ATTR_OUTS(1, 2) char32_t *(__LIBKCALL fgetc32s)(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fgetc32s))(__buf, __bufsize, __stream); })
#endif /* ... */
#if defined(__CRT_HAVE_fputws_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s,(char16_t const *__restrict __str, FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE_DOS$fputws_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s,(char16_t const *__restrict __str, FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE__fputws_nolock) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s,(char16_t const *__restrict __str, FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif defined(__CRT_HAVE_DOS$_fputws_nolock) && defined(__USE_STDIO_UNLOCKED)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s,(char16_t const *__restrict __str, FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif defined(__CRT_HAVE_fputws) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s,(char16_t const *__restrict __str, FILE *__restrict __stream),fputws,(__str,__stream))
#elif defined(__CRT_HAVE_DOS$fputws)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s,(char16_t const *__restrict __str, FILE *__restrict __stream),fputws,(__str,__stream))
#elif defined(__CRT_HAVE_fputws_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s,(char16_t const *__restrict __str, FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE_DOS$fputws_unlocked)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s,(char16_t const *__restrict __str, FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE__fputws_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s,(char16_t const *__restrict __str, FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif defined(__CRT_HAVE_DOS$_fputws_nolock)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s,(char16_t const *__restrict __str, FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif (defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/fputws.h>
/* >> fputws(3), fputws_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_INOUT(2) __STDC_INT_AS_SIZE_T (__LIBDCALL fputc16s)(char16_t const *__restrict __str, FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fputws))((__WCHAR_TYPE__ const *)__str, __stream); }
#elif (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/fputc16s.h>
/* >> fputws(3), fputws_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(fputc16s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_INOUT(2) __STDC_INT_AS_SIZE_T (__LIBDCALL fputc16s)(char16_t const *__restrict __str, FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fputc16s))(__str, __stream); })
#endif /* ... */
#if defined(__CRT_HAVE_fputws_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s,(char32_t const *__restrict __str, FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE_KOS$fputws_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s,(char32_t const *__restrict __str, FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE__fputws_nolock) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s,(char32_t const *__restrict __str, FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif defined(__CRT_HAVE_KOS$_fputws_nolock) && defined(__USE_STDIO_UNLOCKED)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s,(char32_t const *__restrict __str, FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif defined(__CRT_HAVE_fputws) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s,(char32_t const *__restrict __str, FILE *__restrict __stream),fputws,(__str,__stream))
#elif defined(__CRT_HAVE_KOS$fputws)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s,(char32_t const *__restrict __str, FILE *__restrict __stream),fputws,(__str,__stream))
#elif defined(__CRT_HAVE_fputws_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s,(char32_t const *__restrict __str, FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE_KOS$fputws_unlocked)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s,(char32_t const *__restrict __str, FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE__fputws_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s,(char32_t const *__restrict __str, FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif defined(__CRT_HAVE_KOS$_fputws_nolock)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s,(char32_t const *__restrict __str, FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif (defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/fputws.h>
/* >> fputws(3), fputws_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_INOUT(2) __STDC_INT_AS_SIZE_T (__LIBKCALL fputc32s)(char32_t const *__restrict __str, FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fputws))((__WCHAR_TYPE__ const *)__str, __stream); }
#elif (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/fputc32s.h>
/* >> fputws(3), fputws_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(fputc32s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_INOUT(2) __STDC_INT_AS_SIZE_T (__LIBKCALL fputc32s)(char32_t const *__restrict __str, FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fputc32s))(__str, __stream); })
#endif /* ... */
#if defined(__CRT_HAVE_ungetwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__NOTHROW_NCX,ungetc16,(wint16_t __wc, FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$ungetwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__NOTHROW_NCX,ungetc16,(wint16_t __wc, FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__NOTHROW_NCX,ungetc16,(wint16_t __wc, FILE *__stream),ungetwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$ungetwc)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__NOTHROW_NCX,ungetc16,(wint16_t __wc, FILE *__stream),ungetwc,(__wc,__stream))
#elif defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint16_t,__NOTHROW_NCX,ungetc16,(wint16_t __wc, FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$ungetwc_unlocked)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),wint16_t,__NOTHROW_NCX,ungetc16,(wint16_t __wc, FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_ungetwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__NOTHROW_NCX,ungetc32,(wint32_t __wc, FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$ungetwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__NOTHROW_NCX,ungetc32,(wint32_t __wc, FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__NOTHROW_NCX,ungetc32,(wint32_t __wc, FILE *__stream),ungetwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$ungetwc)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__NOTHROW_NCX,ungetc32,(wint32_t __wc, FILE *__stream),ungetwc,(__wc,__stream))
#elif defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),wint32_t,__NOTHROW_NCX,ungetc32,(wint32_t __wc, FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$ungetwc_unlocked)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),wint32_t,__NOTHROW_NCX,ungetc32,(wint32_t __wc, FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#endif /* ... */

#if defined(__USE_ISOC95) || defined(__USE_UNIX98) || defined(__USE_DOS)
#if defined(__CRT_HAVE_fwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwprintf_unlocked");
#elif defined(__CRT_HAVE_DOS$fwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("fwprintf_unlocked");
#elif defined(__CRT_HAVE_fwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwprintf");
#elif defined(__CRT_HAVE_DOS$fwprintf)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("fwprintf");
#elif defined(__CRT_HAVE_fwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwprintf_unlocked");
#elif defined(__CRT_HAVE_DOS$fwprintf_unlocked)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("fwprintf_unlocked");
#elif (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/fwprintf.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
#define fc16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwprintf))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/fc16printf.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16printf))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_fwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwprintf_unlocked");
#elif defined(__CRT_HAVE_KOS$fwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("fwprintf_unlocked");
#elif defined(__CRT_HAVE_fwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwprintf");
#elif defined(__CRT_HAVE_KOS$fwprintf)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("fwprintf");
#elif defined(__CRT_HAVE_fwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwprintf_unlocked");
#elif defined(__CRT_HAVE_KOS$fwprintf_unlocked)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("fwprintf_unlocked");
#elif (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/fwprintf.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
#define fc32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwprintf))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/fc32printf.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32printf))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_vfwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16printf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16printf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16printf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwprintf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwprintf)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16printf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwprintf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16printf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwprintf_unlocked)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16printf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif (defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/vfwprintf.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vfc16printf)(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwprintf))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/vfc16printf.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vfc16printf)(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc16printf))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_vfwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32printf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32printf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32printf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwprintf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwprintf)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32printf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwprintf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32printf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwprintf_unlocked)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32printf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif (defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/vfwprintf.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vfc32printf)(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwprintf))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/vfc32printf.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vfc32printf)(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc32printf))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_wprintf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wprintf_unlocked");
#elif defined(__CRT_HAVE_DOS$wprintf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("wprintf_unlocked");
#elif defined(__CRT_HAVE_wprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wprintf");
#elif defined(__CRT_HAVE_DOS$wprintf)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("wprintf");
#elif defined(__CRT_HAVE_wprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wprintf_unlocked");
#elif defined(__CRT_HAVE_DOS$wprintf_unlocked)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("wprintf_unlocked");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwprintf) || defined(__CRT_HAVE_vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/wprintf.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
#define c16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wprintf))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwprintf) || (defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/c16printf.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf)(char16_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16printf))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wprintf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wprintf_unlocked");
#elif defined(__CRT_HAVE_KOS$wprintf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("wprintf_unlocked");
#elif defined(__CRT_HAVE_wprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wprintf");
#elif defined(__CRT_HAVE_KOS$wprintf)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("wprintf");
#elif defined(__CRT_HAVE_wprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wprintf_unlocked");
#elif defined(__CRT_HAVE_KOS$wprintf_unlocked)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("wprintf_unlocked");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwprintf) || defined(__CRT_HAVE_vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/wprintf.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
#define c32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wprintf))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwprintf) || (defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/c32printf.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf)(char32_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32printf))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16printf,(char16_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_DOS$vwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16printf,(char16_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16printf,(char16_t const *__restrict __format, __builtin_va_list __args),vwprintf,(__format,__args))
#elif defined(__CRT_HAVE_DOS$vwprintf)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16printf,(char16_t const *__restrict __format, __builtin_va_list __args),vwprintf,(__format,__args))
#elif defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16printf,(char16_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_DOS$vwprintf_unlocked)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16printf,(char16_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/vwprintf.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vc16printf)(char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwprintf))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/vc16printf.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vc16printf)(char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc16printf))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32printf,(char32_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_KOS$vwprintf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32printf,(char32_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32printf,(char32_t const *__restrict __format, __builtin_va_list __args),vwprintf,(__format,__args))
#elif defined(__CRT_HAVE_KOS$vwprintf)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32printf,(char32_t const *__restrict __format, __builtin_va_list __args),vwprintf,(__format,__args))
#elif defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32printf,(char32_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_KOS$vwprintf_unlocked)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32printf,(char32_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/vwprintf.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vc32printf)(char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwprintf))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/vc32printf.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vc32printf)(char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc32printf))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_fwscanf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwscanf_unlocked");
#elif defined(__CRT_HAVE_DOS$fwscanf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("fwscanf_unlocked");
#elif defined(__CRT_HAVE_fwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwscanf");
#elif defined(__CRT_HAVE_DOS$fwscanf)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("fwscanf");
#elif defined(__CRT_HAVE_fwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwscanf_unlocked");
#elif defined(__CRT_HAVE_DOS$fwscanf_unlocked)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("fwscanf_unlocked");
#elif (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/fwscanf.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
#define fc16scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwscanf))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/fc16scanf.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc16scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf)(FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16scanf))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc16scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16scanf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_fwscanf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwscanf_unlocked");
#elif defined(__CRT_HAVE_KOS$fwscanf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("fwscanf_unlocked");
#elif defined(__CRT_HAVE_fwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwscanf");
#elif defined(__CRT_HAVE_KOS$fwscanf)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("fwscanf");
#elif defined(__CRT_HAVE_fwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwscanf_unlocked");
#elif defined(__CRT_HAVE_KOS$fwscanf_unlocked)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("fwscanf_unlocked");
#elif (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/fwscanf.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
#define fc32scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwscanf))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/fc32scanf.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc32scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf)(FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32scanf))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc32scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32scanf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_wscanf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wscanf_unlocked");
#elif defined(__CRT_HAVE_DOS$wscanf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("wscanf_unlocked");
#elif defined(__CRT_HAVE_wscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wscanf");
#elif defined(__CRT_HAVE_DOS$wscanf)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("wscanf");
#elif defined(__CRT_HAVE_wscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wscanf_unlocked");
#elif defined(__CRT_HAVE_DOS$wscanf_unlocked)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("wscanf_unlocked");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/wscanf.h>
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
#define c16scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wscanf))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))))
#include <libc/local/parts.uchar.stdio/c16scanf.h>
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c16scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf)(char16_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16scanf))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c16scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16scanf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wscanf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wscanf_unlocked");
#elif defined(__CRT_HAVE_KOS$wscanf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("wscanf_unlocked");
#elif defined(__CRT_HAVE_wscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wscanf");
#elif defined(__CRT_HAVE_KOS$wscanf)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("wscanf");
#elif defined(__CRT_HAVE_wscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wscanf_unlocked");
#elif defined(__CRT_HAVE_KOS$wscanf_unlocked)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("wscanf_unlocked");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/wscanf.h>
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
#define c32scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wscanf))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))))
#include <libc/local/parts.uchar.stdio/c32scanf.h>
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c32scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf)(char32_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32scanf))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c32scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32scanf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_swscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> swscanf(3), vswscanf(3) */
__LIBC __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBDCALL sc16scanf)(char16_t const *__restrict __src, char16_t const *__restrict __format, ...) __CASMNAME("swscanf");
#elif defined(__CRT_HAVE_DOS$swscanf)
/* >> swscanf(3), vswscanf(3) */
__LIBC __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBDCALL sc16scanf)(char16_t const *__restrict __src, char16_t const *__restrict __format, ...) __CASMNAME_DOS("swscanf");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/swscanf.h>
/* >> swscanf(3), vswscanf(3) */
#define sc16scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(swscanf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/sc16scanf.h>
/* >> swscanf(3), vswscanf(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(sc16scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBDCALL sc16scanf)(char16_t const *__restrict __src, char16_t const *__restrict __format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc16scanf))(__src, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define sc16scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc16scanf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE_swscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> swscanf(3), vswscanf(3) */
__LIBC __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBKCALL sc32scanf)(char32_t const *__restrict __src, char32_t const *__restrict __format, ...) __CASMNAME("swscanf");
#elif defined(__CRT_HAVE_KOS$swscanf)
/* >> swscanf(3), vswscanf(3) */
__LIBC __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBKCALL sc32scanf)(char32_t const *__restrict __src, char32_t const *__restrict __format, ...) __CASMNAME_KOS("swscanf");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/swscanf.h>
/* >> swscanf(3), vswscanf(3) */
#define sc32scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(swscanf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/sc32scanf.h>
/* >> swscanf(3), vswscanf(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(sc32scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBKCALL sc32scanf)(char32_t const *__restrict __src, char32_t const *__restrict __format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc32scanf))(__src, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define sc32scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc32scanf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE_vswprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> vswprintf(3) */
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,vsc16printf,(char16_t *__restrict __buf, size_t __buflen, char16_t const *__restrict __format, __builtin_va_list __args),vswprintf,(__buf,__buflen,__format,__args))
#elif defined(__CRT_HAVE_DOS$vswprintf)
/* >> vswprintf(3) */
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,vsc16printf,(char16_t *__restrict __buf, size_t __buflen, char16_t const *__restrict __format, __builtin_va_list __args),vswprintf,(__buf,__buflen,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/vswprintf.h>
/* >> vswprintf(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBDCALL vsc16printf)(char16_t *__restrict __buf, size_t __buflen, char16_t const *__restrict __format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vswprintf))((__WCHAR_TYPE__ *)__buf, __buflen, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/vsc16printf.h>
/* >> vswprintf(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vsc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBDCALL vsc16printf)(char16_t *__restrict __buf, size_t __buflen, char16_t const *__restrict __format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vsc16printf))(__buf, __buflen, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE_vswprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> vswprintf(3) */
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,vsc32printf,(char32_t *__restrict __buf, size_t __buflen, char32_t const *__restrict __format, __builtin_va_list __args),vswprintf,(__buf,__buflen,__format,__args))
#elif defined(__CRT_HAVE_KOS$vswprintf)
/* >> vswprintf(3) */
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,vsc32printf,(char32_t *__restrict __buf, size_t __buflen, char32_t const *__restrict __format, __builtin_va_list __args),vswprintf,(__buf,__buflen,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/vswprintf.h>
/* >> vswprintf(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBKCALL vsc32printf)(char32_t *__restrict __buf, size_t __buflen, char32_t const *__restrict __format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vswprintf))((__WCHAR_TYPE__ *)__buf, __buflen, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/vsc32printf.h>
/* >> vswprintf(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vsc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBKCALL vsc32printf)(char32_t *__restrict __buf, size_t __buflen, char32_t const *__restrict __format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vsc32printf))(__buf, __buflen, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE_swprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> swprintf(3) */
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBDCALL sc16printf)(char16_t *__restrict __buf, size_t __buflen, char16_t const *__restrict __format, ...) __CASMNAME("swprintf");
#elif defined(__CRT_HAVE_DOS$swprintf)
/* >> swprintf(3) */
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBDCALL sc16printf)(char16_t *__restrict __buf, size_t __buflen, char16_t const *__restrict __format, ...) __CASMNAME_DOS("swprintf");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/swprintf.h>
/* >> swprintf(3) */
#define sc16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(swprintf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/sc16printf.h>
/* >> swprintf(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(sc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBDCALL sc16printf)(char16_t *__restrict __buf, size_t __buflen, char16_t const *__restrict __format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc16printf))(__buf, __buflen, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define sc16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc16printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE_swprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> swprintf(3) */
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBKCALL sc32printf)(char32_t *__restrict __buf, size_t __buflen, char32_t const *__restrict __format, ...) __CASMNAME("swprintf");
#elif defined(__CRT_HAVE_KOS$swprintf)
/* >> swprintf(3) */
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBKCALL sc32printf)(char32_t *__restrict __buf, size_t __buflen, char32_t const *__restrict __format, ...) __CASMNAME_KOS("swprintf");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/swprintf.h>
/* >> swprintf(3) */
#define sc32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(swprintf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/sc32printf.h>
/* >> swprintf(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(sc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__VLIBKCALL sc32printf)(char32_t *__restrict __buf, size_t __buflen, char32_t const *__restrict __format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc32printf))(__buf, __buflen, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define sc32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc32printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#endif /* __USE_ISOC95 || __USE_UNIX98 || __USE_DOS */

#ifdef __USE_ISOC99
#if defined(__CRT_HAVE_vfwscanf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16scanf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwscanf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16scanf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16scanf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwscanf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwscanf)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16scanf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwscanf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16scanf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwscanf_unlocked)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16scanf,(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif (defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/vfwscanf.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vfc16scanf)(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwscanf))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif ((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked))
#include <libc/local/parts.uchar.stdio/vfc16scanf.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc16scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vfc16scanf)(FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc16scanf))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_vfwscanf_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32scanf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwscanf_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32scanf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32scanf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwscanf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwscanf)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32scanf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwscanf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32scanf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwscanf_unlocked)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32scanf,(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif (defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/vfwscanf.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vfc32scanf)(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwscanf))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif ((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked))
#include <libc/local/parts.uchar.stdio/vfc32scanf.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc32scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vfc32scanf)(FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc32scanf))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> vwscanf(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16scanf,(char16_t const *__restrict __format, __builtin_va_list __args),vwscanf,(__format,__args))
#elif defined(__CRT_HAVE_DOS$vwscanf)
/* >> vwscanf(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16scanf,(char16_t const *__restrict __format, __builtin_va_list __args),vwscanf,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/vwscanf.h>
/* >> vwscanf(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vc16scanf)(char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwscanf))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked))))
#include <libc/local/parts.uchar.stdio/vc16scanf.h>
/* >> vwscanf(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vc16scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vc16scanf)(char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc16scanf))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> vwscanf(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32scanf,(char32_t const *__restrict __format, __builtin_va_list __args),vwscanf,(__format,__args))
#elif defined(__CRT_HAVE_KOS$vwscanf)
/* >> vwscanf(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32scanf,(char32_t const *__restrict __format, __builtin_va_list __args),vwscanf,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/vwscanf.h>
/* >> vwscanf(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vc32scanf)(char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwscanf))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked))))
#include <libc/local/parts.uchar.stdio/vc32scanf.h>
/* >> vwscanf(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vc32scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vc32scanf)(char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc32scanf))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vswscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> swscanf(3), vswscanf(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,vsc16scanf,(char16_t const *__restrict __input, char16_t const *__restrict __format, __builtin_va_list __args),vswscanf,(__input,__format,__args))
#elif defined(__CRT_HAVE_DOS$vswscanf)
/* >> swscanf(3), vswscanf(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,vsc16scanf,(char16_t const *__restrict __input, char16_t const *__restrict __format, __builtin_va_list __args),vswscanf,(__input,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/vswscanf.h>
/* >> swscanf(3), vswscanf(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBDCALL vsc16scanf)(char16_t const *__restrict __input, char16_t const *__restrict __format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vswscanf))((__WCHAR_TYPE__ const *)__input, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/vsc16scanf.h>
/* >> swscanf(3), vswscanf(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vsc16scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBDCALL vsc16scanf)(char16_t const *__restrict __input, char16_t const *__restrict __format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vsc16scanf))(__input, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE_vswscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> swscanf(3), vswscanf(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,vsc32scanf,(char32_t const *__restrict __input, char32_t const *__restrict __format, __builtin_va_list __args),vswscanf,(__input,__format,__args))
#elif defined(__CRT_HAVE_KOS$vswscanf)
/* >> swscanf(3), vswscanf(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,vsc32scanf,(char32_t const *__restrict __input, char32_t const *__restrict __format, __builtin_va_list __args),vswscanf,(__input,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/vswscanf.h>
/* >> swscanf(3), vswscanf(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBKCALL vsc32scanf)(char32_t const *__restrict __input, char32_t const *__restrict __format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vswscanf))((__WCHAR_TYPE__ const *)__input, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/vsc32scanf.h>
/* >> swscanf(3), vswscanf(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vsc32scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBKCALL vsc32scanf)(char32_t const *__restrict __input, char32_t const *__restrict __format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vsc32scanf))(__input, __format, __args); })
#endif /* !... */
#endif /* __USE_ISOC99 */

#ifdef __USE_GNU
#if defined(__CRT_HAVE_getwchar_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,__WINT16_TYPE__,__THROWING,getchar16_unlocked,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_DOS$getwchar_unlocked)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_DOS(,__WINT16_TYPE__,__THROWING,getchar16_unlocked,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_getwchar) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,__WINT16_TYPE__,__THROWING,getchar16_unlocked,(void),getwchar,())
#elif defined(__CRT_HAVE_DOS$getwchar)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_DOS(,__WINT16_TYPE__,__THROWING,getchar16_unlocked,(void),getwchar,())
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/getwchar_unlocked.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __WINT16_TYPE__ (__LIBDCALL getchar16_unlocked)(void) __THROWS(...) { return (__WINT16_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getwchar_unlocked))(); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc))
#include <libc/local/parts.uchar.stdio/getchar16_unlocked.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(getchar16_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __WINT16_TYPE__ (__LIBDCALL getchar16_unlocked)(void) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getchar16_unlocked))(); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_getwchar_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,__WINT32_TYPE__,__THROWING,getchar32_unlocked,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_KOS$getwchar_unlocked)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_KOS(,__WINT32_TYPE__,__THROWING,getchar32_unlocked,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_getwchar) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,__WINT32_TYPE__,__THROWING,getchar32_unlocked,(void),getwchar,())
#elif defined(__CRT_HAVE_KOS$getwchar)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_KOS(,__WINT32_TYPE__,__THROWING,getchar32_unlocked,(void),getwchar,())
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/getwchar_unlocked.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __WINT32_TYPE__ (__LIBKCALL getchar32_unlocked)(void) __THROWS(...) { return (__WINT32_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getwchar_unlocked))(); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc))
#include <libc/local/parts.uchar.stdio/getchar32_unlocked.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(getchar32_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __WINT32_TYPE__ (__LIBKCALL getchar32_unlocked)(void) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getchar32_unlocked))(); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_putwchar_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,__WINT16_TYPE__,__THROWING,putchar16_unlocked,(char16_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_DOS$putwchar_unlocked)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_DOS(,__WINT16_TYPE__,__THROWING,putchar16_unlocked,(char16_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_putwchar) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,__WINT16_TYPE__,__THROWING,putchar16_unlocked,(char16_t __wc),putwchar,(__wc))
#elif defined(__CRT_HAVE_DOS$putwchar)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_DOS(,__WINT16_TYPE__,__THROWING,putchar16_unlocked,(char16_t __wc),putwchar,(__wc))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/putwchar_unlocked.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __WINT16_TYPE__ (__LIBDCALL putchar16_unlocked)(char16_t __wc) __THROWS(...) { return (__WINT16_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putwchar_unlocked))((__WCHAR_TYPE__)__wc); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc))
#include <libc/local/parts.uchar.stdio/putchar16_unlocked.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(putchar16_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __WINT16_TYPE__ (__LIBDCALL putchar16_unlocked)(char16_t __wc) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putchar16_unlocked))(__wc); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_putwchar_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,__WINT32_TYPE__,__THROWING,putchar32_unlocked,(char32_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_KOS$putwchar_unlocked)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_KOS(,__WINT32_TYPE__,__THROWING,putchar32_unlocked,(char32_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_putwchar) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,__WINT32_TYPE__,__THROWING,putchar32_unlocked,(char32_t __wc),putwchar,(__wc))
#elif defined(__CRT_HAVE_KOS$putwchar)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_KOS(,__WINT32_TYPE__,__THROWING,putchar32_unlocked,(char32_t __wc),putwchar,(__wc))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/putwchar_unlocked.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __WINT32_TYPE__ (__LIBKCALL putchar32_unlocked)(char32_t __wc) __THROWS(...) { return (__WINT32_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putwchar_unlocked))((__WCHAR_TYPE__)__wc); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc))
#include <libc/local/parts.uchar.stdio/putchar32_unlocked.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(putchar32_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __WINT32_TYPE__ (__LIBKCALL putchar32_unlocked)(char32_t __wc) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putchar32_unlocked))(__wc); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE_DOS$_getwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_DOS$_fgetwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,fgetc16_unlocked,(__FILE *__restrict __stream),fgetwc,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE_KOS$_getwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_KOS$_fgetwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,fgetc32_unlocked,(__FILE *__restrict __stream),fgetwc,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$_putwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$_fputwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,fputc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$_putwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$_fputwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,fputc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE_DOS$_getwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_DOS$_fgetwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,getc16_unlocked,(__FILE *__restrict __stream),fgetwc,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE_KOS$_getwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_KOS$_fgetwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,getc32_unlocked,(__FILE *__restrict __stream),fgetwc,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$_putwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$_fputwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,putc16_unlocked,(char16_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$_putwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$_fputwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,putc32_unlocked,(char32_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetws_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s_unlocked,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_DOS$fgetws_unlocked)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s_unlocked,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE__fgetws_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s_unlocked,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_DOS$_fgetws_nolock)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s_unlocked,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_fgetws) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s_unlocked,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgetws,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_DOS$fgetws)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char16_t *,__THROWING,fgetc16s_unlocked,(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgetws,(__buf,__bufsize,__stream))
#elif (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/fgetws_unlocked.h>
/* >> fgetws(3), fgetws_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INOUT(3) __ATTR_OUTS(1, 2) char16_t *(__LIBDCALL fgetc16s_unlocked)(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream) __THROWS(...) { return (__CHAR16_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fgetws_unlocked))((__WCHAR_TYPE__ *)__buf, __bufsize, __stream); }
#elif ((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc)) && ((defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked) || (defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_ungetwc_nolock) || (defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked))
#include <libc/local/parts.uchar.stdio/fgetc16s_unlocked.h>
/* >> fgetws(3), fgetws_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(fgetc16s_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INOUT(3) __ATTR_OUTS(1, 2) char16_t *(__LIBDCALL fgetc16s_unlocked)(char16_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fgetc16s_unlocked))(__buf, __bufsize, __stream); })
#endif /* ... */
#if defined(__CRT_HAVE_fgetws_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s_unlocked,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_KOS$fgetws_unlocked)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s_unlocked,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgetws_unlocked,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE__fgetws_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s_unlocked,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_KOS$_fgetws_nolock)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s_unlocked,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),_fgetws_nolock,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_fgetws) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s_unlocked,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgetws,(__buf,__bufsize,__stream))
#elif defined(__CRT_HAVE_KOS$fgetws)
/* >> fgetws(3), fgetws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(3) __ATTR_OUTS(1, 2),char32_t *,__THROWING,fgetc32s_unlocked,(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgetws,(__buf,__bufsize,__stream))
#elif (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/fgetws_unlocked.h>
/* >> fgetws(3), fgetws_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INOUT(3) __ATTR_OUTS(1, 2) char32_t *(__LIBKCALL fgetc32s_unlocked)(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream) __THROWS(...) { return (__CHAR32_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fgetws_unlocked))((__WCHAR_TYPE__ *)__buf, __bufsize, __stream); }
#elif ((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc)) && ((defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked) || (defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_ungetwc_nolock) || (defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked))
#include <libc/local/parts.uchar.stdio/fgetc32s_unlocked.h>
/* >> fgetws(3), fgetws_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(fgetc32s_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INOUT(3) __ATTR_OUTS(1, 2) char32_t *(__LIBKCALL fgetc32s_unlocked)(char32_t *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fgetc32s_unlocked))(__buf, __bufsize, __stream); })
#endif /* ... */
#if defined(__CRT_HAVE_fputws_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s_unlocked,(char16_t const *__restrict __str, __FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE_DOS$fputws_unlocked)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s_unlocked,(char16_t const *__restrict __str, __FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE__fputws_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s_unlocked,(char16_t const *__restrict __str, __FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif defined(__CRT_HAVE_DOS$_fputws_nolock)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s_unlocked,(char16_t const *__restrict __str, __FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif defined(__CRT_HAVE_fputws) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s_unlocked,(char16_t const *__restrict __str, __FILE *__restrict __stream),fputws,(__str,__stream))
#elif defined(__CRT_HAVE_DOS$fputws)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc16s_unlocked,(char16_t const *__restrict __str, __FILE *__restrict __stream),fputws,(__str,__stream))
#elif (defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/fputws_unlocked.h>
/* >> fputws(3), fputws_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_INOUT(2) __STDC_INT_AS_SIZE_T (__LIBDCALL fputc16s_unlocked)(char16_t const *__restrict __str, __FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fputws_unlocked))((__WCHAR_TYPE__ const *)__str, __stream); }
#elif (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || ((defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc)
#include <libc/local/parts.uchar.stdio/fputc16s_unlocked.h>
/* >> fputws(3), fputws_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(fputc16s_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_INOUT(2) __STDC_INT_AS_SIZE_T (__LIBDCALL fputc16s_unlocked)(char16_t const *__restrict __str, __FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fputc16s_unlocked))(__str, __stream); })
#endif /* ... */
#if defined(__CRT_HAVE_fputws_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s_unlocked,(char32_t const *__restrict __str, __FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE_KOS$fputws_unlocked)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s_unlocked,(char32_t const *__restrict __str, __FILE *__restrict __stream),fputws_unlocked,(__str,__stream))
#elif defined(__CRT_HAVE__fputws_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s_unlocked,(char32_t const *__restrict __str, __FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif defined(__CRT_HAVE_KOS$_fputws_nolock)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s_unlocked,(char32_t const *__restrict __str, __FILE *__restrict __stream),_fputws_nolock,(__str,__stream))
#elif defined(__CRT_HAVE_fputws) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s_unlocked,(char32_t const *__restrict __str, __FILE *__restrict __stream),fputws,(__str,__stream))
#elif defined(__CRT_HAVE_KOS$fputws)
/* >> fputws(3), fputws_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_INOUT(2),__STDC_INT_AS_SIZE_T,__THROWING,fputc32s_unlocked,(char32_t const *__restrict __str, __FILE *__restrict __stream),fputws,(__str,__stream))
#elif (defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/fputws_unlocked.h>
/* >> fputws(3), fputws_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_INOUT(2) __STDC_INT_AS_SIZE_T (__LIBKCALL fputc32s_unlocked)(char32_t const *__restrict __str, __FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fputws_unlocked))((__WCHAR_TYPE__ const *)__str, __stream); }
#elif (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || ((defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc)
#include <libc/local/parts.uchar.stdio/fputc32s_unlocked.h>
/* >> fputws(3), fputws_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(fputc32s_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_INOUT(2) __STDC_INT_AS_SIZE_T (__LIBKCALL fputc32s_unlocked)(char32_t const *__restrict __str, __FILE *__restrict __stream) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fputc32s_unlocked))(__str, __stream); })
#endif /* ... */
#endif /* __USE_GNU */

#ifdef __USE_XOPEN2K8
#if defined(__CRT_HAVE_open_wmemstream) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> open_wmemstream(3) */
__CREDIRECT(,__FILE *,__NOTHROW_NCX,open_c16memstream,(char16_t **__bufloc, __SIZE_TYPE__ *__sizeloc),open_wmemstream,(__bufloc,__sizeloc))
#elif defined(__CRT_HAVE_DOS$open_wmemstream)
/* >> open_wmemstream(3) */
__CREDIRECT_DOS(,__FILE *,__NOTHROW_NCX,open_c16memstream,(char16_t **__bufloc, __SIZE_TYPE__ *__sizeloc),open_wmemstream,(__bufloc,__sizeloc))
#endif /* ... */
#if defined(__CRT_HAVE_open_wmemstream) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> open_wmemstream(3) */
__CREDIRECT(,__FILE *,__NOTHROW_NCX,open_c32memstream,(char32_t **__bufloc, __SIZE_TYPE__ *__sizeloc),open_wmemstream,(__bufloc,__sizeloc))
#elif defined(__CRT_HAVE_KOS$open_wmemstream)
/* >> open_wmemstream(3) */
__CREDIRECT_KOS(,__FILE *,__NOTHROW_NCX,open_c32memstream,(char32_t **__bufloc, __SIZE_TYPE__ *__sizeloc),open_wmemstream,(__bufloc,__sizeloc))
#endif /* ... */
#endif /* __USE_XOPEN2K8 */

#ifdef __USE_KOS
#if defined(__CRT_HAVE_fopen_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fopen_wprinter(3)
 * Create and return a new write-only file-stream that will write to the given printer.
 * Note  that by default, the buffering is enabled for the file-stream, meaning you may
 * have to call `fflush(return)' before printed data is committed to the given printer.
 * - Buffering can be disabled with `setvbuf(return, NULL, _IONBF, 0)'
 * - When `printer' returns a negative value, `ferror(return)' becomes set
 * - When calling `fflush(return)', with the current unicode sequence is incomplete,
 *   that function will return with `-1' and `errno == EILSEQ'
 * @return: * :   A file-stream that emits its data to `printer'
 * @return: NULL: Insufficient memory. */
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),__FILE *,__NOTHROW_NCX,fopen_c16printer,(__pc16formatprinter __printer, void *__arg),fopen_wprinter,(__printer,__arg))
#elif defined(__CRT_HAVE_DOS$fopen_wprinter)
/* >> fopen_wprinter(3)
 * Create and return a new write-only file-stream that will write to the given printer.
 * Note  that by default, the buffering is enabled for the file-stream, meaning you may
 * have to call `fflush(return)' before printed data is committed to the given printer.
 * - Buffering can be disabled with `setvbuf(return, NULL, _IONBF, 0)'
 * - When `printer' returns a negative value, `ferror(return)' becomes set
 * - When calling `fflush(return)', with the current unicode sequence is incomplete,
 *   that function will return with `-1' and `errno == EILSEQ'
 * @return: * :   A file-stream that emits its data to `printer'
 * @return: NULL: Insufficient memory. */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),__FILE *,__NOTHROW_NCX,fopen_c16printer,(__pc16formatprinter __printer, void *__arg),fopen_wprinter,(__printer,__arg))
#else /* ... */
#include <bits/types.h>
#if (defined(__CRT_HAVE_malloc) || defined(__CRT_HAVE___libc_malloc) || defined(__CRT_HAVE_calloc) || defined(__CRT_HAVE___libc_calloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc) || defined(__CRT_HAVE_memalign) || defined(__CRT_HAVE_aligned_alloc) || defined(__CRT_HAVE___libc_memalign) || defined(__CRT_HAVE_posix_memalign)) && (defined(__CRT_HAVE_funopen2_64) || defined(__CRT_HAVE_funopen2)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/fopen_wprinter.h>
/* >> fopen_wprinter(3)
 * Create and return a new write-only file-stream that will write to the given printer.
 * Note  that by default, the buffering is enabled for the file-stream, meaning you may
 * have to call `fflush(return)' before printed data is committed to the given printer.
 * - Buffering can be disabled with `setvbuf(return, NULL, _IONBF, 0)'
 * - When `printer' returns a negative value, `ferror(return)' becomes set
 * - When calling `fflush(return)', with the current unicode sequence is incomplete,
 *   that function will return with `-1' and `errno == EILSEQ'
 * @return: * :   A file-stream that emits its data to `printer'
 * @return: NULL: Insufficient memory. */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) __FILE *__NOTHROW_NCX(__LIBDCALL fopen_c16printer)(__pc16formatprinter __printer, void *__arg) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fopen_wprinter))((__pwformatprinter)__printer, __arg); }
#elif (defined(__CRT_HAVE_malloc) || defined(__CRT_HAVE___libc_malloc) || defined(__CRT_HAVE_calloc) || defined(__CRT_HAVE___libc_calloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc) || defined(__CRT_HAVE_memalign) || defined(__CRT_HAVE_aligned_alloc) || defined(__CRT_HAVE___libc_memalign) || defined(__CRT_HAVE_posix_memalign)) && (defined(__CRT_HAVE_funopen2_64) || defined(__CRT_HAVE_funopen2))
#include <libc/local/parts.uchar.stdio/fopen_c16printer.h>
/* >> fopen_wprinter(3)
 * Create and return a new write-only file-stream that will write to the given printer.
 * Note  that by default, the buffering is enabled for the file-stream, meaning you may
 * have to call `fflush(return)' before printed data is committed to the given printer.
 * - Buffering can be disabled with `setvbuf(return, NULL, _IONBF, 0)'
 * - When `printer' returns a negative value, `ferror(return)' becomes set
 * - When calling `fflush(return)', with the current unicode sequence is incomplete,
 *   that function will return with `-1' and `errno == EILSEQ'
 * @return: * :   A file-stream that emits its data to `printer'
 * @return: NULL: Insufficient memory. */
__NAMESPACE_LOCAL_USING_OR_IMPL(fopen_c16printer, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) __FILE *__NOTHROW_NCX(__LIBDCALL fopen_c16printer)(__pc16formatprinter __printer, void *__arg) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fopen_c16printer))(__printer, __arg); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_fopen_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fopen_wprinter(3)
 * Create and return a new write-only file-stream that will write to the given printer.
 * Note  that by default, the buffering is enabled for the file-stream, meaning you may
 * have to call `fflush(return)' before printed data is committed to the given printer.
 * - Buffering can be disabled with `setvbuf(return, NULL, _IONBF, 0)'
 * - When `printer' returns a negative value, `ferror(return)' becomes set
 * - When calling `fflush(return)', with the current unicode sequence is incomplete,
 *   that function will return with `-1' and `errno == EILSEQ'
 * @return: * :   A file-stream that emits its data to `printer'
 * @return: NULL: Insufficient memory. */
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1)),__FILE *,__NOTHROW_NCX,fopen_c32printer,(__pc32formatprinter __printer, void *__arg),fopen_wprinter,(__printer,__arg))
#elif defined(__CRT_HAVE_KOS$fopen_wprinter)
/* >> fopen_wprinter(3)
 * Create and return a new write-only file-stream that will write to the given printer.
 * Note  that by default, the buffering is enabled for the file-stream, meaning you may
 * have to call `fflush(return)' before printed data is committed to the given printer.
 * - Buffering can be disabled with `setvbuf(return, NULL, _IONBF, 0)'
 * - When `printer' returns a negative value, `ferror(return)' becomes set
 * - When calling `fflush(return)', with the current unicode sequence is incomplete,
 *   that function will return with `-1' and `errno == EILSEQ'
 * @return: * :   A file-stream that emits its data to `printer'
 * @return: NULL: Insufficient memory. */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_NONNULL((1)),__FILE *,__NOTHROW_NCX,fopen_c32printer,(__pc32formatprinter __printer, void *__arg),fopen_wprinter,(__printer,__arg))
#else /* ... */
#include <bits/types.h>
#if (defined(__CRT_HAVE_malloc) || defined(__CRT_HAVE___libc_malloc) || defined(__CRT_HAVE_calloc) || defined(__CRT_HAVE___libc_calloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc) || defined(__CRT_HAVE_memalign) || defined(__CRT_HAVE_aligned_alloc) || defined(__CRT_HAVE___libc_memalign) || defined(__CRT_HAVE_posix_memalign)) && (defined(__CRT_HAVE_funopen2_64) || defined(__CRT_HAVE_funopen2)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/fopen_wprinter.h>
/* >> fopen_wprinter(3)
 * Create and return a new write-only file-stream that will write to the given printer.
 * Note  that by default, the buffering is enabled for the file-stream, meaning you may
 * have to call `fflush(return)' before printed data is committed to the given printer.
 * - Buffering can be disabled with `setvbuf(return, NULL, _IONBF, 0)'
 * - When `printer' returns a negative value, `ferror(return)' becomes set
 * - When calling `fflush(return)', with the current unicode sequence is incomplete,
 *   that function will return with `-1' and `errno == EILSEQ'
 * @return: * :   A file-stream that emits its data to `printer'
 * @return: NULL: Insufficient memory. */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) __FILE *__NOTHROW_NCX(__LIBKCALL fopen_c32printer)(__pc32formatprinter __printer, void *__arg) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fopen_wprinter))((__pwformatprinter)__printer, __arg); }
#elif (defined(__CRT_HAVE_malloc) || defined(__CRT_HAVE___libc_malloc) || defined(__CRT_HAVE_calloc) || defined(__CRT_HAVE___libc_calloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc) || defined(__CRT_HAVE_memalign) || defined(__CRT_HAVE_aligned_alloc) || defined(__CRT_HAVE___libc_memalign) || defined(__CRT_HAVE_posix_memalign)) && (defined(__CRT_HAVE_funopen2_64) || defined(__CRT_HAVE_funopen2))
#include <libc/local/parts.uchar.stdio/fopen_c32printer.h>
/* >> fopen_wprinter(3)
 * Create and return a new write-only file-stream that will write to the given printer.
 * Note  that by default, the buffering is enabled for the file-stream, meaning you may
 * have to call `fflush(return)' before printed data is committed to the given printer.
 * - Buffering can be disabled with `setvbuf(return, NULL, _IONBF, 0)'
 * - When `printer' returns a negative value, `ferror(return)' becomes set
 * - When calling `fflush(return)', with the current unicode sequence is incomplete,
 *   that function will return with `-1' and `errno == EILSEQ'
 * @return: * :   A file-stream that emits its data to `printer'
 * @return: NULL: Insufficient memory. */
__NAMESPACE_LOCAL_USING_OR_IMPL(fopen_c32printer, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_NONNULL((1)) __FILE *__NOTHROW_NCX(__LIBKCALL fopen_c32printer)(__pc32formatprinter __printer, void *__arg) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fopen_c32printer))(__printer, __arg); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_file_wprinter_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c16printer,(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_DOS$file_wprinter_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT_DOS(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c16printer,(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c16printer,(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_DOS$file_wprinter)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT_DOS(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c16printer,(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c16printer,(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_DOS$file_wprinter_unlocked)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT_DOS(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c16printer,(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif (defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/file_wprinter.h>
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INS(2, 3) __ATTR_NONNULL((1)) __SSIZE_TYPE__ (__LIBDCALL file_c16printer)(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(file_wprinter))(__arg, (__WCHAR_TYPE__ const *)__data, __datalen); }
#elif (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/file_c16printer.h>
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__NAMESPACE_LOCAL_USING_OR_IMPL(file_c16printer, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INS(2, 3) __ATTR_NONNULL((1)) __SSIZE_TYPE__ (__LIBDCALL file_c16printer)(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(file_c16printer))(__arg, __data, __datalen); })
#endif /* ... */
#if defined(__CRT_HAVE_file_wprinter_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c32printer,(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_KOS$file_wprinter_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT_KOS(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c32printer,(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c32printer,(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_KOS$file_wprinter)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT_KOS(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c32printer,(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c32printer,(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_KOS$file_wprinter_unlocked)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT_KOS(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c32printer,(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif (defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/file_wprinter.h>
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INS(2, 3) __ATTR_NONNULL((1)) __SSIZE_TYPE__ (__LIBKCALL file_c32printer)(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(file_wprinter))(__arg, (__WCHAR_TYPE__ const *)__data, __datalen); }
#elif (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/file_c32printer.h>
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__NAMESPACE_LOCAL_USING_OR_IMPL(file_c32printer, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INS(2, 3) __ATTR_NONNULL((1)) __SSIZE_TYPE__ (__LIBKCALL file_c32printer)(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(file_c32printer))(__arg, __data, __datalen); })
#endif /* ... */
#if defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c16printer_unlocked,(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_DOS$file_wprinter_unlocked)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT_DOS(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c16printer_unlocked,(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c16printer_unlocked,(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_DOS$file_wprinter)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT_DOS(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c16printer_unlocked,(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter,(__arg,__data,__datalen))
#elif (defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/file_wprinter_unlocked.h>
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INS(2, 3) __ATTR_NONNULL((1)) __SSIZE_TYPE__ (__LIBDCALL file_c16printer_unlocked)(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(file_wprinter_unlocked))(__arg, (__WCHAR_TYPE__ const *)__data, __datalen); }
#elif (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc)
#include <libc/local/parts.uchar.stdio/file_c16printer_unlocked.h>
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__NAMESPACE_LOCAL_USING_OR_IMPL(file_c16printer_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INS(2, 3) __ATTR_NONNULL((1)) __SSIZE_TYPE__ (__LIBDCALL file_c16printer_unlocked)(void *__arg, char16_t const *__restrict __data, __SIZE_TYPE__ __datalen) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(file_c16printer_unlocked))(__arg, __data, __datalen); })
#endif /* ... */
#if defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c32printer_unlocked,(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_KOS$file_wprinter_unlocked)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT_KOS(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c32printer_unlocked,(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter_unlocked,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c32printer_unlocked,(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter,(__arg,__data,__datalen))
#elif defined(__CRT_HAVE_KOS$file_wprinter)
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__CREDIRECT_KOS(__ATTR_INS(2, 3) __ATTR_NONNULL((1)),__SSIZE_TYPE__,__THROWING,file_c32printer_unlocked,(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen),file_wprinter,(__arg,__data,__datalen))
#elif (defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/file_wprinter_unlocked.h>
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INS(2, 3) __ATTR_NONNULL((1)) __SSIZE_TYPE__ (__LIBKCALL file_c32printer_unlocked)(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(file_wprinter_unlocked))(__arg, (__WCHAR_TYPE__ const *)__data, __datalen); }
#elif (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc)
#include <libc/local/parts.uchar.stdio/file_c32printer_unlocked.h>
/* >> file_wprinter(3), file_wprinter_unlocked(3)
 * For use with `format_wprintf()' and friends: Prints to a `FILE *' closure argument */
__NAMESPACE_LOCAL_USING_OR_IMPL(file_c32printer_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_INS(2, 3) __ATTR_NONNULL((1)) __SSIZE_TYPE__ (__LIBKCALL file_c32printer_unlocked)(void *__arg, char32_t const *__restrict __data, __SIZE_TYPE__ __datalen) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(file_c32printer_unlocked))(__arg, __data, __datalen); })
#endif /* ... */
#if defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,ungetc16_unlocked,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),ungetwc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE_DOS$ungetwc_unlocked)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,ungetc16_unlocked,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),ungetwc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,ungetc16_unlocked,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),_ungetwc_nolock,(__ch,__stream))
#elif defined(__CRT_HAVE_DOS$_ungetwc_nolock)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,ungetc16_unlocked,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),_ungetwc_nolock,(__ch,__stream))
#elif defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,ungetc16_unlocked,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),ungetwc,(__ch,__stream))
#elif defined(__CRT_HAVE_DOS$ungetwc)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,ungetc16_unlocked,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),ungetwc,(__ch,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,ungetc32_unlocked,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),ungetwc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE_KOS$ungetwc_unlocked)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,ungetc32_unlocked,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),ungetwc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,ungetc32_unlocked,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),_ungetwc_nolock,(__ch,__stream))
#elif defined(__CRT_HAVE_KOS$_ungetwc_nolock)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,ungetc32_unlocked,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),_ungetwc_nolock,(__ch,__stream))
#elif defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,ungetc32_unlocked,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),ungetwc,(__ch,__stream))
#elif defined(__CRT_HAVE_KOS$ungetwc)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,ungetc32_unlocked,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),ungetwc,(__ch,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16printf_unlocked,(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwprintf_unlocked)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16printf_unlocked,(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16printf_unlocked,(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwprintf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwprintf)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16printf_unlocked,(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwprintf,(__stream,__format,__args))
#elif (defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/vfwprintf_unlocked.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vfc16printf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwprintf_unlocked))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || ((defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc)
#include <libc/local/parts.uchar.stdio/vfc16printf_unlocked.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc16printf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vfc16printf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc16printf_unlocked))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32printf_unlocked,(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwprintf_unlocked)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32printf_unlocked,(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32printf_unlocked,(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwprintf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwprintf)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32printf_unlocked,(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwprintf,(__stream,__format,__args))
#elif (defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/vfwprintf_unlocked.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vfc32printf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwprintf_unlocked))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || ((defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc)
#include <libc/local/parts.uchar.stdio/vfc32printf_unlocked.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc32printf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vfc32printf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc32printf_unlocked))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_fwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwprintf_unlocked");
#elif defined(__CRT_HAVE_DOS$fwprintf_unlocked)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("fwprintf_unlocked");
#elif defined(__CRT_HAVE_fwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwprintf");
#elif defined(__CRT_HAVE_DOS$fwprintf)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("fwprintf");
#elif (defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/fwprintf_unlocked.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
#define fc16printf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwprintf_unlocked))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || ((defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || ((defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc)
#include <libc/local/parts.uchar.stdio/fc16printf_unlocked.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc16printf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16printf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16printf_unlocked))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc16printf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16printf_unlocked))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_fwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwprintf_unlocked");
#elif defined(__CRT_HAVE_KOS$fwprintf_unlocked)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("fwprintf_unlocked");
#elif defined(__CRT_HAVE_fwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwprintf");
#elif defined(__CRT_HAVE_KOS$fwprintf)
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("fwprintf");
#elif (defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/fwprintf_unlocked.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
#define fc32printf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwprintf_unlocked))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || ((defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || ((defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc)
#include <libc/local/parts.uchar.stdio/fc32printf_unlocked.h>
/* >> fwprintf(3), vfwprintf(3), fwprintf_unlocked(3), vfwprintf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc32printf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32printf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32printf_unlocked))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc32printf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32printf_unlocked))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_wprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf_unlocked)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wprintf_unlocked");
#elif defined(__CRT_HAVE_DOS$wprintf_unlocked)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf_unlocked)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("wprintf_unlocked");
#elif defined(__CRT_HAVE_wprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf_unlocked)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wprintf");
#elif defined(__CRT_HAVE_DOS$wprintf)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf_unlocked)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("wprintf");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwprintf_unlocked) || defined(__CRT_HAVE_vwprintf) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/wprintf_unlocked.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
#define c16printf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wprintf_unlocked))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwprintf_unlocked) || (defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwprintf) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || ((defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || ((defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc)))
#include <libc/local/parts.uchar.stdio/c16printf_unlocked.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c16printf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16printf_unlocked)(char16_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16printf_unlocked))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c16printf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16printf_unlocked))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf_unlocked)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wprintf_unlocked");
#elif defined(__CRT_HAVE_KOS$wprintf_unlocked)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf_unlocked)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("wprintf_unlocked");
#elif defined(__CRT_HAVE_wprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf_unlocked)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wprintf");
#elif defined(__CRT_HAVE_KOS$wprintf)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf_unlocked)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("wprintf");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwprintf_unlocked) || defined(__CRT_HAVE_vwprintf) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/wprintf_unlocked.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
#define c32printf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wprintf_unlocked))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwprintf_unlocked) || (defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwprintf) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || ((defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || ((defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc)))
#include <libc/local/parts.uchar.stdio/c32printf_unlocked.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c32printf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32printf_unlocked)(char32_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32printf_unlocked))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c32printf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32printf_unlocked))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16printf_unlocked,(char16_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_DOS$vwprintf_unlocked)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16printf_unlocked,(char16_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16printf_unlocked,(char16_t const *__restrict __format, __builtin_va_list __args),vwprintf,(__format,__args))
#elif defined(__CRT_HAVE_DOS$vwprintf)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16printf_unlocked,(char16_t const *__restrict __format, __builtin_va_list __args),vwprintf,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/vwprintf_unlocked.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vc16printf_unlocked)(char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwprintf_unlocked))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || ((defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || ((defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc))
#include <libc/local/parts.uchar.stdio/vc16printf_unlocked.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vc16printf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vc16printf_unlocked)(char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc16printf_unlocked))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32printf_unlocked,(char32_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_KOS$vwprintf_unlocked)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32printf_unlocked,(char32_t const *__restrict __format, __builtin_va_list __args),vwprintf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32printf_unlocked,(char32_t const *__restrict __format, __builtin_va_list __args),vwprintf,(__format,__args))
#elif defined(__CRT_HAVE_KOS$vwprintf)
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32printf_unlocked,(char32_t const *__restrict __format, __builtin_va_list __args),vwprintf,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/vwprintf_unlocked.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vc32printf_unlocked)(char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwprintf_unlocked))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || ((defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || ((defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked) || defined(__CRT_HAVE__putwc_nolock) || defined(__CRT_HAVE__fputwc_nolock) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked) || (defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_putwc_nolock) || (defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fputwc_nolock) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc))
#include <libc/local/parts.uchar.stdio/vc32printf_unlocked.h>
/* >> wprintf(3), vwprintf(3), wprintf_unlocked(3), vwprintf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vc32printf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vc32printf_unlocked)(char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc32printf_unlocked))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16scanf_unlocked,(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwscanf_unlocked)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16scanf_unlocked,(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16scanf_unlocked,(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwscanf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwscanf)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc16scanf_unlocked,(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args),vfwscanf,(__stream,__format,__args))
#elif (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/vfwscanf_unlocked.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vfc16scanf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwscanf_unlocked))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif ((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc)) && ((defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked) || (defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_ungetwc_nolock) || (defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc))
#include <libc/local/parts.uchar.stdio/vfc16scanf_unlocked.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc16scanf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vfc16scanf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc16scanf_unlocked))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32scanf_unlocked,(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwscanf_unlocked)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32scanf_unlocked,(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwscanf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32scanf_unlocked,(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwscanf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwscanf)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SIZE_T,__THROWING,vfc32scanf_unlocked,(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args),vfwscanf,(__stream,__format,__args))
#elif (defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/vfwscanf_unlocked.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vfc32scanf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwscanf_unlocked))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif ((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc)) && ((defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked) || (defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_ungetwc_nolock) || (defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc))
#include <libc/local/parts.uchar.stdio/vfc32scanf_unlocked.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc32scanf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vfc32scanf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc32scanf_unlocked))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_vwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> vwscanf(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16scanf_unlocked,(char16_t const *__restrict __format, __builtin_va_list __args),vwscanf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_DOS$vwscanf_unlocked)
/* >> vwscanf(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16scanf_unlocked,(char16_t const *__restrict __format, __builtin_va_list __args),vwscanf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> vwscanf(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16scanf_unlocked,(char16_t const *__restrict __format, __builtin_va_list __args),vwscanf,(__format,__args))
#elif defined(__CRT_HAVE_DOS$vwscanf)
/* >> vwscanf(3) */
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc16scanf_unlocked,(char16_t const *__restrict __format, __builtin_va_list __args),vwscanf,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf_unlocked) || defined(__CRT_HAVE_vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/vwscanf_unlocked.h>
/* >> vwscanf(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vc16scanf_unlocked)(char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwscanf_unlocked))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc)) && ((defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked) || (defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_ungetwc_nolock) || (defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc))))
#include <libc/local/parts.uchar.stdio/vc16scanf_unlocked.h>
/* >> vwscanf(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vc16scanf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0) __STDC_INT_AS_SIZE_T (__LIBDCALL vc16scanf_unlocked)(char16_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc16scanf_unlocked))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> vwscanf(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32scanf_unlocked,(char32_t const *__restrict __format, __builtin_va_list __args),vwscanf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_KOS$vwscanf_unlocked)
/* >> vwscanf(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32scanf_unlocked,(char32_t const *__restrict __format, __builtin_va_list __args),vwscanf_unlocked,(__format,__args))
#elif defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> vwscanf(3) */
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32scanf_unlocked,(char32_t const *__restrict __format, __builtin_va_list __args),vwscanf,(__format,__args))
#elif defined(__CRT_HAVE_KOS$vwscanf)
/* >> vwscanf(3) */
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SIZE_T,__THROWING,vc32scanf_unlocked,(char32_t const *__restrict __format, __builtin_va_list __args),vwscanf,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf_unlocked) || defined(__CRT_HAVE_vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/vwscanf_unlocked.h>
/* >> vwscanf(3) */
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vc32scanf_unlocked)(char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwscanf_unlocked))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc)) && ((defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked) || (defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_ungetwc_nolock) || (defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc))))
#include <libc/local/parts.uchar.stdio/vc32scanf_unlocked.h>
/* >> vwscanf(3) */
__NAMESPACE_LOCAL_USING_OR_IMPL(vc32scanf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0) __STDC_INT_AS_SIZE_T (__LIBKCALL vc32scanf_unlocked)(char32_t const *__restrict __format, __builtin_va_list __args) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc32scanf_unlocked))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_fwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwscanf_unlocked");
#elif defined(__CRT_HAVE_DOS$fwscanf_unlocked)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("fwscanf_unlocked");
#elif defined(__CRT_HAVE_fwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwscanf");
#elif defined(__CRT_HAVE_DOS$fwscanf)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("fwscanf");
#elif (defined(__CRT_HAVE_vfwscanf_unlocked) || defined(__CRT_HAVE_vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/fwscanf_unlocked.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
#define fc16scanf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwscanf_unlocked))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc)) && ((defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked) || (defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_ungetwc_nolock) || (defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc)))
#include <libc/local/parts.uchar.stdio/fc16scanf_unlocked.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc16scanf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBDCALL fc16scanf_unlocked)(__FILE *__restrict __stream, char16_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16scanf_unlocked))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc16scanf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16scanf_unlocked))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_fwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwscanf_unlocked");
#elif defined(__CRT_HAVE_KOS$fwscanf_unlocked)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("fwscanf_unlocked");
#elif defined(__CRT_HAVE_fwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("fwscanf");
#elif defined(__CRT_HAVE_KOS$fwscanf)
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("fwscanf");
#elif (defined(__CRT_HAVE_vfwscanf_unlocked) || defined(__CRT_HAVE_vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/fwscanf_unlocked.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
#define fc32scanf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwscanf_unlocked))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc)) && ((defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked) || (defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_ungetwc_nolock) || (defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc)))
#include <libc/local/parts.uchar.stdio/fc32scanf_unlocked.h>
/* >> fwscanf(3), vfwscanf(3), fwscanf_unlocked(3), vfwscanf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc32scanf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SIZE_T (__VLIBKCALL fc32scanf_unlocked)(__FILE *__restrict __stream, char32_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32scanf_unlocked))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc32scanf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32scanf_unlocked))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_wscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf_unlocked)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wscanf_unlocked");
#elif defined(__CRT_HAVE_DOS$wscanf_unlocked)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf_unlocked)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("wscanf_unlocked");
#elif defined(__CRT_HAVE_wscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf_unlocked)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wscanf");
#elif defined(__CRT_HAVE_DOS$wscanf)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf_unlocked)(char16_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_DOS("wscanf");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwscanf_unlocked) || defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf_unlocked) || defined(__CRT_HAVE_vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)))))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/wscanf_unlocked.h>
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
#define c16scanf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wscanf_unlocked))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwscanf_unlocked) || (defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf_unlocked) || defined(__CRT_HAVE_vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc)) && ((defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked) || (defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_ungetwc_nolock) || (defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc)))))
#include <libc/local/parts.uchar.stdio/c16scanf_unlocked.h>
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c16scanf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBDCALL c16scanf_unlocked)(char16_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16scanf_unlocked))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c16scanf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16scanf_unlocked))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf_unlocked)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wscanf_unlocked");
#elif defined(__CRT_HAVE_KOS$wscanf_unlocked)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf_unlocked)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("wscanf_unlocked");
#elif defined(__CRT_HAVE_wscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf_unlocked)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME("wscanf");
#elif defined(__CRT_HAVE_KOS$wscanf)
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf_unlocked)(char32_t const *__restrict __format, ...) __THROWS(...) __CASMNAME_KOS("wscanf");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwscanf_unlocked) || defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf_unlocked) || defined(__CRT_HAVE_vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)))))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/wscanf_unlocked.h>
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
#define c32scanf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wscanf_unlocked))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwscanf_unlocked) || (defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf_unlocked) || defined(__CRT_HAVE_vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || ((defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked) || defined(__CRT_HAVE__getwc_nolock) || defined(__CRT_HAVE__fgetwc_nolock) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc)) && (defined(__CRT_HAVE_ungetwc_unlocked) || defined(__CRT_HAVE__ungetwc_nolock) || defined(__CRT_HAVE_ungetwc)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked) || (defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_getwc_nolock) || (defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fgetwc_nolock) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc)) && ((defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked) || (defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_ungetwc_nolock) || (defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc)))))
#include <libc/local/parts.uchar.stdio/c32scanf_unlocked.h>
/* >> wscanf(3), vwscanf(3), wscanf_unlocked(3), vwscanf_unlocked(3) */
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c32scanf_unlocked, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SIZE_T (__VLIBKCALL c32scanf_unlocked)(char32_t const *__restrict __format, ...) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32scanf_unlocked))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c32scanf_unlocked(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32scanf_unlocked))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#endif /* __USE_KOS */



/* uchar variants of DOS stdio functions */
#ifdef __USE_DOS
#if defined(__CRT_HAVE_wfopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c16fopen,(char16_t const *__filename, char16_t const *__mode),wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE_DOS$wfopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c16fopen,(char16_t const *__filename, char16_t const *__mode),wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE__wfopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c16fopen,(char16_t const *__filename, char16_t const *__mode),_wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE_DOS$_wfopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c16fopen,(char16_t const *__filename, char16_t const *__mode),_wfopen,(__filename,__mode))
#else /* ... */
#include <asm/os/oflags.h>
#if ((defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.stdio/wfopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBDCALL _c16fopen)(char16_t const *__filename, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfopen))((__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode); }
#elif ((defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c16fopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBDCALL _c16fopen)(char16_t const *__filename, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16fopen))(__filename, __mode); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wfopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c32fopen,(char32_t const *__filename, char32_t const *__mode),wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE_KOS$wfopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c32fopen,(char32_t const *__filename, char32_t const *__mode),wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE__wfopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c32fopen,(char32_t const *__filename, char32_t const *__mode),_wfopen,(__filename,__mode))
#elif defined(__CRT_HAVE_KOS$_wfopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c32fopen,(char32_t const *__filename, char32_t const *__mode),_wfopen,(__filename,__mode))
#else /* ... */
#include <asm/os/oflags.h>
#if ((defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.stdio/wfopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBKCALL _c32fopen)(char32_t const *__filename, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfopen))((__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode); }
#elif ((defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c32fopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBKCALL _c32fopen)(char32_t const *__filename, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32fopen))(__filename, __mode); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wfreopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,_c16freopen,(char16_t const *__filename, char16_t const *__mode, __FILE *__stream),wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE_DOS$wfreopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,_c16freopen,(char16_t const *__filename, char16_t const *__mode, __FILE *__stream),wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE__wfreopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,_c16freopen,(char16_t const *__filename, char16_t const *__mode, __FILE *__stream),_wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE_DOS$_wfreopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,_c16freopen,(char16_t const *__filename, char16_t const *__mode, __FILE *__stream),_wfreopen,(__filename,__mode,__stream))
#else /* ... */
#include <asm/os/oflags.h>
#if ((defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.stdio/wfreopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3) __FILE *__NOTHROW_NCX(__LIBDCALL _c16freopen)(char16_t const *__filename, char16_t const *__mode, __FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfreopen))((__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode, __stream); }
#elif ((defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c16freopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3) __FILE *__NOTHROW_NCX(__LIBDCALL _c16freopen)(char16_t const *__filename, char16_t const *__mode, __FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16freopen))(__filename, __mode, __stream); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wfreopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,_c32freopen,(char32_t const *__filename, char32_t const *__mode, __FILE *__stream),wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE_KOS$wfreopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,_c32freopen,(char32_t const *__filename, char32_t const *__mode, __FILE *__stream),wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE__wfreopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,_c32freopen,(char32_t const *__filename, char32_t const *__mode, __FILE *__stream),_wfreopen,(__filename,__mode,__stream))
#elif defined(__CRT_HAVE_KOS$_wfreopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3),__FILE *,__NOTHROW_NCX,_c32freopen,(char32_t const *__filename, char32_t const *__mode, __FILE *__stream),_wfreopen,(__filename,__mode,__stream))
#else /* ... */
#include <asm/os/oflags.h>
#if ((defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.stdio/wfreopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3) __FILE *__NOTHROW_NCX(__LIBKCALL _c32freopen)(char32_t const *__filename, char32_t const *__mode, __FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wfreopen))((__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode, __stream); }
#elif ((defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c32freopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_INOUT(3) __FILE *__NOTHROW_NCX(__LIBKCALL _c32freopen)(char32_t const *__filename, char32_t const *__mode, __FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32freopen))(__filename, __mode, __stream); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_getwchar_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,_fgetchar16,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_DOS$getwchar_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,_fgetchar16,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_getwchar) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,_fgetchar16,(void),getwchar,())
#elif defined(__CRT_HAVE_DOS$getwchar)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,_fgetchar16,(void),getwchar,())
#elif defined(__CRT_HAVE__fgetwchar) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,_fgetchar16,(void),_fgetwchar,())
#elif defined(__CRT_HAVE_DOS$_fgetwchar)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,_fgetchar16,(void),_fgetwchar,())
#elif defined(__CRT_HAVE_getwchar_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,_fgetchar16,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_DOS$getwchar_unlocked)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,_fgetchar16,(void),getwchar_unlocked,())
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/getwchar.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint16_t (__LIBDCALL _fgetchar16)(void) __THROWS(...) { return (__WINT16_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getwchar))(); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked))
#include <libc/local/parts.uchar.stdio/getchar16.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint16_t (__LIBDCALL _fgetchar16)(void) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getchar16))(); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_getwchar_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,_fgetchar32,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_KOS$getwchar_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,_fgetchar32,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_getwchar) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,_fgetchar32,(void),getwchar,())
#elif defined(__CRT_HAVE_KOS$getwchar)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,_fgetchar32,(void),getwchar,())
#elif defined(__CRT_HAVE__fgetwchar) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,_fgetchar32,(void),_fgetwchar,())
#elif defined(__CRT_HAVE_KOS$_fgetwchar)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,_fgetchar32,(void),_fgetwchar,())
#elif defined(__CRT_HAVE_getwchar_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,_fgetchar32,(void),getwchar_unlocked,())
#elif defined(__CRT_HAVE_KOS$getwchar_unlocked)
/* >> getwchar(3), getwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,_fgetchar32,(void),getwchar_unlocked,())
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/getwchar.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint32_t (__LIBKCALL _fgetchar32)(void) __THROWS(...) { return (__WINT32_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getwchar))(); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked))
#include <libc/local/parts.uchar.stdio/getchar32.h>
/* >> getwchar(3), getwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint32_t (__LIBKCALL _fgetchar32)(void) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(getchar32))(); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_putwchar_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,_fputchar16,(char16_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_DOS$putwchar_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,_fputchar16,(char16_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_putwchar) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,_fputchar16,(char16_t __wc),putwchar,(__wc))
#elif defined(__CRT_HAVE_DOS$putwchar)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,_fputchar16,(char16_t __wc),putwchar,(__wc))
#elif defined(__CRT_HAVE__fputwchar) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,_fputchar16,(char16_t __wc),_fputwchar,(__wc))
#elif defined(__CRT_HAVE_DOS$_fputwchar)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,_fputchar16,(char16_t __wc),_fputwchar,(__wc))
#elif defined(__CRT_HAVE_putwchar_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint16_t,__THROWING,_fputchar16,(char16_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_DOS$putwchar_unlocked)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_DOS(,wint16_t,__THROWING,_fputchar16,(char16_t __wc),putwchar_unlocked,(__wc))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/wchar/putwchar.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint16_t (__LIBDCALL _fputchar16)(char16_t __wc) __THROWS(...) { return (__WINT16_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putwchar))((__WCHAR_TYPE__)__wc); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/putchar16.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint16_t (__LIBDCALL _fputchar16)(char16_t __wc) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putchar16))(__wc); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_putwchar_unlocked) && defined(__USE_STDIO_UNLOCKED) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,_fputchar32,(char32_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_KOS$putwchar_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,_fputchar32,(char32_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_putwchar) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,_fputchar32,(char32_t __wc),putwchar,(__wc))
#elif defined(__CRT_HAVE_KOS$putwchar)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,_fputchar32,(char32_t __wc),putwchar,(__wc))
#elif defined(__CRT_HAVE__fputwchar) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,_fputchar32,(char32_t __wc),_fputwchar,(__wc))
#elif defined(__CRT_HAVE_KOS$_fputwchar)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,_fputchar32,(char32_t __wc),_fputwchar,(__wc))
#elif defined(__CRT_HAVE_putwchar_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT(,wint32_t,__THROWING,_fputchar32,(char32_t __wc),putwchar_unlocked,(__wc))
#elif defined(__CRT_HAVE_KOS$putwchar_unlocked)
/* >> putwchar(3), putwchar_unlocked(3) */
__CREDIRECT_KOS(,wint32_t,__THROWING,_fputchar32,(char32_t __wc),putwchar_unlocked,(__wc))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/wchar/putwchar.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint32_t (__LIBKCALL _fputchar32)(char32_t __wc) __THROWS(...) { return (__WINT32_TYPE__)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putwchar))((__WCHAR_TYPE__)__wc); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/putchar32.h>
/* >> putwchar(3), putwchar_unlocked(3) */
__FORCELOCAL __ATTR_ARTIFICIAL wint32_t (__LIBKCALL _fputchar32)(char32_t __wc) __THROWS(...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(putchar32))(__wc); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wpopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c16popen,(char16_t const *__command, char16_t const *__mode),wpopen,(__command,__mode))
#elif defined(__CRT_HAVE_DOS$wpopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c16popen,(char16_t const *__command, char16_t const *__mode),wpopen,(__command,__mode))
#elif defined(__CRT_HAVE__wpopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c16popen,(char16_t const *__command, char16_t const *__mode),_wpopen,(__command,__mode))
#elif defined(__CRT_HAVE_DOS$_wpopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c16popen,(char16_t const *__command, char16_t const *__mode),_wpopen,(__command,__mode))
#elif (defined(__CRT_HAVE_popen) || defined(__CRT_HAVE__popen) || defined(__CRT_HAVE__IO_popen)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/parts.wchar.stdio/wpopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBDCALL _c16popen)(char16_t const *__command, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wpopen))((__WCHAR_TYPE__ const *)__command, (__WCHAR_TYPE__ const *)__mode); }
#elif (defined(__CRT_HAVE_popen) || defined(__CRT_HAVE__popen) || defined(__CRT_HAVE__IO_popen)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c16popen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBDCALL _c16popen)(char16_t const *__command, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16popen))(__command, __mode); }
#endif /* ... */
#if defined(__CRT_HAVE_wpopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c32popen,(char32_t const *__command, char32_t const *__mode),wpopen,(__command,__mode))
#elif defined(__CRT_HAVE_KOS$wpopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c32popen,(char32_t const *__command, char32_t const *__mode),wpopen,(__command,__mode))
#elif defined(__CRT_HAVE__wpopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c32popen,(char32_t const *__command, char32_t const *__mode),_wpopen,(__command,__mode))
#elif defined(__CRT_HAVE_KOS$_wpopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),__FILE *,__NOTHROW_NCX,_c32popen,(char32_t const *__command, char32_t const *__mode),_wpopen,(__command,__mode))
#elif (defined(__CRT_HAVE_popen) || defined(__CRT_HAVE__popen) || defined(__CRT_HAVE__IO_popen)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/parts.wchar.stdio/wpopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBKCALL _c32popen)(char32_t const *__command, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wpopen))((__WCHAR_TYPE__ const *)__command, (__WCHAR_TYPE__ const *)__mode); }
#elif (defined(__CRT_HAVE_popen) || defined(__CRT_HAVE__popen) || defined(__CRT_HAVE__IO_popen)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/c32popen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __FILE *__NOTHROW_NCX(__LIBKCALL _c32popen)(char32_t const *__command, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32popen))(__command, __mode); }
#endif /* ... */
#if defined(__CRT_HAVE_wremove) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_RPC,_c16remove,(char16_t const *__filename),wremove,(__filename))
#elif defined(__CRT_HAVE_DOS$wremove)
__CREDIRECT_DOS(__ATTR_IN(1),int,__NOTHROW_RPC,_c16remove,(char16_t const *__filename),wremove,(__filename))
#elif defined(__CRT_HAVE__wremove) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_RPC,_c16remove,(char16_t const *__filename),_wremove,(__filename))
#elif defined(__CRT_HAVE_DOS$_wremove)
__CREDIRECT_DOS(__ATTR_IN(1),int,__NOTHROW_RPC,_c16remove,(char16_t const *__filename),_wremove,(__filename))
#else /* ... */
#include <asm/os/fcntl.h>
#include <asm/os/errno.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wremoveat) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_remove) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR)))))) || (defined(__EISDIR) && defined(__ENOTDIR) && (defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2)
#include <libc/local/parts.wchar.stdio/wremove.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) int __NOTHROW_RPC(__LIBDCALL _c16remove)(char16_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wremove))((__WCHAR_TYPE__ const *)__filename); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wremoveat) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$wremoveat) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_remove) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR)))))) || (defined(__EISDIR) && defined(__ENOTDIR) && (defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.stdio/c16remove.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) int __NOTHROW_RPC(__LIBDCALL _c16remove)(char16_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16remove))(__filename); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wremove) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_RPC,_c32remove,(char32_t const *__filename),wremove,(__filename))
#elif defined(__CRT_HAVE_KOS$wremove)
__CREDIRECT_KOS(__ATTR_IN(1),int,__NOTHROW_RPC,_c32remove,(char32_t const *__filename),wremove,(__filename))
#elif defined(__CRT_HAVE__wremove) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1),int,__NOTHROW_RPC,_c32remove,(char32_t const *__filename),_wremove,(__filename))
#elif defined(__CRT_HAVE_KOS$_wremove)
__CREDIRECT_KOS(__ATTR_IN(1),int,__NOTHROW_RPC,_c32remove,(char32_t const *__filename),_wremove,(__filename))
#else /* ... */
#include <asm/os/fcntl.h>
#include <asm/os/errno.h>
#if (defined(__AT_FDCWD) && (defined(__CRT_HAVE_wremoveat) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_remove) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR)))))) || (defined(__EISDIR) && defined(__ENOTDIR) && (defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4)
#include <libc/local/parts.wchar.stdio/wremove.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) int __NOTHROW_RPC(__LIBKCALL _c32remove)(char32_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wremove))((__WCHAR_TYPE__ const *)__filename); }
#elif (defined(__AT_FDCWD) && ((defined(__CRT_HAVE_wremoveat) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$wremoveat) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4) || ((defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR))))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))))) || ((defined(__CRT_HAVE_remove) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_removeat) || (defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat) && (defined(__AT_REMOVEREG) || (defined(__EISDIR) && defined(__ENOTDIR)))))) || (defined(__EISDIR) && defined(__ENOTDIR) && (defined(__CRT_HAVE_unlink) || defined(__CRT_HAVE__unlink) || defined(__CRT_HAVE___unlink) || defined(__CRT_HAVE___libc_unlink) || (defined(__AT_FDCWD) && defined(__CRT_HAVE_unlinkat))) && (defined(__CRT_HAVE_rmdir) || defined(__CRT_HAVE__rmdir) || defined(__CRT_HAVE___rmdir) || defined(__CRT_HAVE___libc_rmdir) || (defined(__AT_FDCWD) && defined(__AT_REMOVEDIR) && defined(__CRT_HAVE_unlinkat))))) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)))
#include <libc/local/parts.uchar.stdio/c32remove.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) int __NOTHROW_RPC(__LIBKCALL _c32remove)(char32_t const *__filename) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32remove))(__filename); }
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE_DOS$_getwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_DOS$_fgetwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_fgetc16_nolock,(__FILE *__restrict __stream),fgetwc,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE_KOS$_getwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_KOS$_fgetwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_fgetc32_nolock,(__FILE *__restrict __stream),fgetwc,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$_putwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$_fputwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_fputc16_nolock,(char16_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$_putwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$_fputwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_fputc32_nolock,(char32_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,_ungetc16_nolock,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),ungetwc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE_DOS$ungetwc_unlocked)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,_ungetc16_nolock,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),ungetwc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,_ungetc16_nolock,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),_ungetwc_nolock,(__ch,__stream))
#elif defined(__CRT_HAVE_DOS$_ungetwc_nolock)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,_ungetc16_nolock,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),_ungetwc_nolock,(__ch,__stream))
#elif defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,_ungetc16_nolock,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),ungetwc,(__ch,__stream))
#elif defined(__CRT_HAVE_DOS$ungetwc)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__NOTHROW_NCX,_ungetc16_nolock,(__WINT16_TYPE__ __ch, __FILE *__restrict __stream),ungetwc,(__ch,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,_ungetc32_nolock,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),ungetwc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE_KOS$ungetwc_unlocked)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,_ungetc32_nolock,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),ungetwc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE__ungetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,_ungetc32_nolock,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),_ungetwc_nolock,(__ch,__stream))
#elif defined(__CRT_HAVE_KOS$_ungetwc_nolock)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,_ungetc32_nolock,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),_ungetwc_nolock,(__ch,__stream))
#elif defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,_ungetc32_nolock,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),ungetwc,(__ch,__stream))
#elif defined(__CRT_HAVE_KOS$ungetwc)
/* >> ungetwc(3), ungetwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__NOTHROW_NCX,_ungetc32_nolock,(__WINT32_TYPE__ __ch, __FILE *__restrict __stream),ungetwc,(__ch,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE_DOS$_getwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_DOS$_fgetwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(1),__WINT16_TYPE__,__THROWING,_getc16_nolock,(__FILE *__restrict __stream),fgetwc,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),fgetwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc_unlocked)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),getwc_unlocked,(__stream))
#elif defined(__CRT_HAVE__getwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE_KOS$_getwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),_getwc_nolock,(__stream))
#elif defined(__CRT_HAVE__fgetwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_KOS$_fgetwc_nolock)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),_fgetwc_nolock,(__stream))
#elif defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_KOS$getwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_KOS$fgetwc)
/* >> fgetwc(3), getwc(3), fgetwc_unlocked(3), getwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(1),__WINT32_TYPE__,__THROWING,_getc32_nolock,(__FILE *__restrict __stream),fgetwc,(__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$_putwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$_fputwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_DOS(__ATTR_INOUT(2),__WINT16_TYPE__,__THROWING,_putc16_nolock,(char16_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),fputwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc_unlocked)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),putwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE__putwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$_putwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),_putwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE__fputwc_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$_fputwc_nolock)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),_fputwc_nolock,(__wc,__stream))
#elif defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$putwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),putwc,(__wc,__stream))
#elif defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#elif defined(__CRT_HAVE_KOS$fputwc)
/* >> fputwc(3), putwc(3), fputwc_unlocked(3), putwc_unlocked(3) */
__CREDIRECT_KOS(__ATTR_INOUT(2),__WINT32_TYPE__,__THROWING,_putc32_nolock,(char32_t __wc, __FILE *__restrict __stream),fputwc,(__wc,__stream))
#endif /* ... */
#if defined(__CRT_HAVE__wperror) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT_VOID(__ATTR_COLD __ATTR_IN_OPT(1),__THROWING,_c16perror,(char16_t const *__restrict __message),_wperror,(__message))
#elif defined(__CRT_HAVE_DOS$_wperror)
__CREDIRECT_VOID_DOS(__ATTR_COLD __ATTR_IN_OPT(1),__THROWING,_c16perror,(char16_t const *__restrict __message),_wperror,(__message))
#else /* ... */
#include <libc/template/stdstreams.h>
#include <libc/errno.h>
#if defined(__LOCAL_stderr) && defined(__libc_geterrno) && (defined(__CRT_HAVE_fprintf) || defined(__CRT_HAVE__IO_fprintf) || defined(__CRT_HAVE_fprintf_s) || defined(__CRT_HAVE_fprintf_unlocked) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wperror.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_COLD __ATTR_IN_OPT(1) void (__LIBDCALL _c16perror)(char16_t const *__restrict __message) __THROWS(...) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wperror))((__WCHAR_TYPE__ const *)__message); }
#elif defined(__LOCAL_stderr) && defined(__libc_geterrno) && (defined(__CRT_HAVE_fprintf) || defined(__CRT_HAVE__IO_fprintf) || defined(__CRT_HAVE_fprintf_s) || defined(__CRT_HAVE_fprintf_unlocked) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))
#include <libc/local/parts.uchar.stdio/_c16perror.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16perror, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_COLD __ATTR_IN_OPT(1) void (__LIBDCALL _c16perror)(char16_t const *__restrict __message) __THROWS(...) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16perror))(__message); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wperror) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT_VOID(__ATTR_COLD __ATTR_IN_OPT(1),__THROWING,_c32perror,(char32_t const *__restrict __message),_wperror,(__message))
#elif defined(__CRT_HAVE_KOS$_wperror)
__CREDIRECT_VOID_KOS(__ATTR_COLD __ATTR_IN_OPT(1),__THROWING,_c32perror,(char32_t const *__restrict __message),_wperror,(__message))
#else /* ... */
#include <libc/template/stdstreams.h>
#include <libc/errno.h>
#if defined(__LOCAL_stderr) && defined(__libc_geterrno) && (defined(__CRT_HAVE_fprintf) || defined(__CRT_HAVE__IO_fprintf) || defined(__CRT_HAVE_fprintf_s) || defined(__CRT_HAVE_fprintf_unlocked) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wperror.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_COLD __ATTR_IN_OPT(1) void (__LIBKCALL _c32perror)(char32_t const *__restrict __message) __THROWS(...) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wperror))((__WCHAR_TYPE__ const *)__message); }
#elif defined(__LOCAL_stderr) && defined(__libc_geterrno) && (defined(__CRT_HAVE_fprintf) || defined(__CRT_HAVE__IO_fprintf) || defined(__CRT_HAVE_fprintf_s) || defined(__CRT_HAVE_fprintf_unlocked) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))
#include <libc/local/parts.uchar.stdio/_c32perror.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32perror, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_COLD __ATTR_IN_OPT(1) void (__LIBKCALL _c32perror)(char32_t const *__restrict __message) __THROWS(...) { (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32perror))(__message); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wfsopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),FILE *,__NOTHROW_NCX,_c16fsopen,(char16_t const *__filename, char16_t const *__mode, __STDC_INT_AS_UINT_T __sh_flag),_wfsopen,(__filename,__mode,__sh_flag))
#elif defined(__CRT_HAVE_DOS$_wfsopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),FILE *,__NOTHROW_NCX,_c16fsopen,(char16_t const *__filename, char16_t const *__mode, __STDC_INT_AS_UINT_T __sh_flag),_wfsopen,(__filename,__mode,__sh_flag))
#else /* ... */
#include <asm/os/oflags.h>
#if (defined(__CRT_HAVE__fsopen) || (defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wfsopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) FILE *__NOTHROW_NCX(__LIBDCALL _c16fsopen)(char16_t const *__filename, char16_t const *__mode, __STDC_INT_AS_UINT_T __sh_flag) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wfsopen))((__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode, __sh_flag); }
#elif (defined(__CRT_HAVE__fsopen) || (defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/_c16fsopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16fsopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) FILE *__NOTHROW_NCX(__LIBDCALL _c16fsopen)(char16_t const *__filename, char16_t const *__mode, __STDC_INT_AS_UINT_T __sh_flag) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16fsopen))(__filename, __mode, __sh_flag); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wfsopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),FILE *,__NOTHROW_NCX,_c32fsopen,(char32_t const *__filename, char32_t const *__mode, __STDC_INT_AS_UINT_T __sh_flag),_wfsopen,(__filename,__mode,__sh_flag))
#elif defined(__CRT_HAVE_KOS$_wfsopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),FILE *,__NOTHROW_NCX,_c32fsopen,(char32_t const *__filename, char32_t const *__mode, __STDC_INT_AS_UINT_T __sh_flag),_wfsopen,(__filename,__mode,__sh_flag))
#else /* ... */
#include <asm/os/oflags.h>
#if (defined(__CRT_HAVE__fsopen) || (defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wfsopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) FILE *__NOTHROW_NCX(__LIBKCALL _c32fsopen)(char32_t const *__filename, char32_t const *__mode, __STDC_INT_AS_UINT_T __sh_flag) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wfsopen))((__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode, __sh_flag); }
#elif (defined(__CRT_HAVE__fsopen) || (defined(__CRT_HAVE_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || (defined(__CRT_HAVE__IO_fopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/_c32fsopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32fsopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) FILE *__NOTHROW_NCX(__LIBKCALL _c32fsopen)(char32_t const *__filename, char32_t const *__mode, __STDC_INT_AS_UINT_T __sh_flag) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32fsopen))(__filename, __mode, __sh_flag); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wfdopen) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2),FILE *,__NOTHROW_NCX,_c16fdopen,(__fd_t __fd, char16_t const *__mode),_wfdopen,(__fd,__mode))
#elif defined(__CRT_HAVE_DOS$_wfdopen)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(2),FILE *,__NOTHROW_NCX,_c16fdopen,(__fd_t __fd, char16_t const *__mode),_wfdopen,(__fd,__mode))
#elif (defined(__CRT_HAVE_fdopen) || defined(__CRT_HAVE__fdopen) || defined(__CRT_HAVE__IO_fdopen)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wfdopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) FILE *__NOTHROW_NCX(__LIBDCALL _c16fdopen)(__fd_t __fd, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wfdopen))(__fd, (__WCHAR_TYPE__ const *)__mode); }
#elif (defined(__CRT_HAVE_fdopen) || defined(__CRT_HAVE__fdopen) || defined(__CRT_HAVE__IO_fdopen)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/_c16fdopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16fdopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) FILE *__NOTHROW_NCX(__LIBDCALL _c16fdopen)(__fd_t __fd, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16fdopen))(__fd, __mode); })
#endif /* ... */
#if defined(__CRT_HAVE__wfdopen) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2),FILE *,__NOTHROW_NCX,_c32fdopen,(__fd_t __fd, char32_t const *__mode),_wfdopen,(__fd,__mode))
#elif defined(__CRT_HAVE_KOS$_wfdopen)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(2),FILE *,__NOTHROW_NCX,_c32fdopen,(__fd_t __fd, char32_t const *__mode),_wfdopen,(__fd,__mode))
#elif (defined(__CRT_HAVE_fdopen) || defined(__CRT_HAVE__fdopen) || defined(__CRT_HAVE__IO_fdopen)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wfdopen.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) FILE *__NOTHROW_NCX(__LIBKCALL _c32fdopen)(__fd_t __fd, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wfdopen))(__fd, (__WCHAR_TYPE__ const *)__mode); }
#elif (defined(__CRT_HAVE_fdopen) || defined(__CRT_HAVE__fdopen) || defined(__CRT_HAVE__IO_fdopen)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/_c32fdopen.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32fdopen, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) FILE *__NOTHROW_NCX(__LIBKCALL _c32fdopen)(__fd_t __fd, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32fdopen))(__fd, __mode); })
#endif /* ... */
#if defined(__CRT_HAVE__wfopen_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_IN(3) __ATTR_OUT(1),__errno_t,__NOTHROW_NCX,_c16fopen_s,(FILE **__pstream, char16_t const *__filename, char16_t const *__mode),_wfopen_s,(__pstream,__filename,__mode))
#elif defined(__CRT_HAVE_DOS$_wfopen_s)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_IN(3) __ATTR_OUT(1),__errno_t,__NOTHROW_NCX,_c16fopen_s,(FILE **__pstream, char16_t const *__filename, char16_t const *__mode),_wfopen_s,(__pstream,__filename,__mode))
#else /* ... */
#include <asm/os/oflags.h>
#if (defined(__CRT_HAVE_fopen_s) || (defined(__CRT_HAVE_fopen) && (!defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wfopen_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(3) __ATTR_OUT(1) __errno_t __NOTHROW_NCX(__LIBDCALL _c16fopen_s)(FILE **__pstream, char16_t const *__filename, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wfopen_s))(__pstream, (__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode); }
#elif (defined(__CRT_HAVE_fopen_s) || (defined(__CRT_HAVE_fopen) && (!defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/_c16fopen_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16fopen_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(3) __ATTR_OUT(1) __errno_t __NOTHROW_NCX(__LIBDCALL _c16fopen_s)(FILE **__pstream, char16_t const *__filename, char16_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16fopen_s))(__pstream, __filename, __mode); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wfopen_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_IN(3) __ATTR_OUT(1),__errno_t,__NOTHROW_NCX,_c32fopen_s,(FILE **__pstream, char32_t const *__filename, char32_t const *__mode),_wfopen_s,(__pstream,__filename,__mode))
#elif defined(__CRT_HAVE_KOS$_wfopen_s)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_IN(3) __ATTR_OUT(1),__errno_t,__NOTHROW_NCX,_c32fopen_s,(FILE **__pstream, char32_t const *__filename, char32_t const *__mode),_wfopen_s,(__pstream,__filename,__mode))
#else /* ... */
#include <asm/os/oflags.h>
#if (defined(__CRT_HAVE_fopen_s) || (defined(__CRT_HAVE_fopen) && (!defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wfopen_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(3) __ATTR_OUT(1) __errno_t __NOTHROW_NCX(__LIBKCALL _c32fopen_s)(FILE **__pstream, char32_t const *__filename, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wfopen_s))(__pstream, (__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode); }
#elif (defined(__CRT_HAVE_fopen_s) || (defined(__CRT_HAVE_fopen) && (!defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_fopen64)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/_c32fopen_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32fopen_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(3) __ATTR_OUT(1) __errno_t __NOTHROW_NCX(__LIBKCALL _c32fopen_s)(FILE **__pstream, char32_t const *__filename, char32_t const *__mode) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32fopen_s))(__pstream, __filename, __mode); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wfreopen_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_IN(3) __ATTR_INOUT_OPT(4) __ATTR_OUT(1),__errno_t,__NOTHROW_NCX,_c16freopen_s,(FILE **__pstream, char16_t const *__filename, char16_t const *__mode, FILE *__stream),_wfreopen_s,(__pstream,__filename,__mode,__stream))
#elif defined(__CRT_HAVE_DOS$_wfreopen_s)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_IN(3) __ATTR_INOUT_OPT(4) __ATTR_OUT(1),__errno_t,__NOTHROW_NCX,_c16freopen_s,(FILE **__pstream, char16_t const *__filename, char16_t const *__mode, FILE *__stream),_wfreopen_s,(__pstream,__filename,__mode,__stream))
#else /* ... */
#include <asm/os/oflags.h>
#if (defined(__CRT_HAVE_freopen_s) || (defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wfreopen_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(3) __ATTR_INOUT_OPT(4) __ATTR_OUT(1) __errno_t __NOTHROW_NCX(__LIBDCALL _c16freopen_s)(FILE **__pstream, char16_t const *__filename, char16_t const *__mode, FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wfreopen_s))(__pstream, (__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode, __stream); }
#elif (defined(__CRT_HAVE_freopen_s) || (defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 2) || defined(__CRT_HAVE_DOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/_c16freopen_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16freopen_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(3) __ATTR_INOUT_OPT(4) __ATTR_OUT(1) __errno_t __NOTHROW_NCX(__LIBDCALL _c16freopen_s)(FILE **__pstream, char16_t const *__filename, char16_t const *__mode, FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16freopen_s))(__pstream, __filename, __mode, __stream); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wfreopen_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_IN(3) __ATTR_INOUT_OPT(4) __ATTR_OUT(1),__errno_t,__NOTHROW_NCX,_c32freopen_s,(FILE **__pstream, char32_t const *__filename, char32_t const *__mode, FILE *__stream),_wfreopen_s,(__pstream,__filename,__mode,__stream))
#elif defined(__CRT_HAVE_KOS$_wfreopen_s)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_IN(3) __ATTR_INOUT_OPT(4) __ATTR_OUT(1),__errno_t,__NOTHROW_NCX,_c32freopen_s,(FILE **__pstream, char32_t const *__filename, char32_t const *__mode, FILE *__stream),_wfreopen_s,(__pstream,__filename,__mode,__stream))
#else /* ... */
#include <asm/os/oflags.h>
#if (defined(__CRT_HAVE_freopen_s) || (defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wfreopen_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(3) __ATTR_INOUT_OPT(4) __ATTR_OUT(1) __errno_t __NOTHROW_NCX(__LIBKCALL _c32freopen_s)(FILE **__pstream, char32_t const *__filename, char32_t const *__mode, FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wfreopen_s))(__pstream, (__WCHAR_TYPE__ const *)__filename, (__WCHAR_TYPE__ const *)__mode, __stream); }
#elif (defined(__CRT_HAVE_freopen_s) || (defined(__CRT_HAVE_freopen) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64) || (defined(__CRT_HAVE_freopen_unlocked) && (!defined(__USE_FILE_OFFSET64) || !defined(__O_LARGEFILE) || !__O_LARGEFILE)) || defined(__CRT_HAVE_freopen64_unlocked)) && ((defined(__CRT_HAVE_convert_wcstombs) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$convert_wcstombs) || (defined(__CRT_HAVE_convert_wcstombsn) && __SIZEOF_WCHAR_T__ == 4) || defined(__CRT_HAVE_KOS$convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <libc/local/parts.uchar.stdio/_c32freopen_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32freopen_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_IN(3) __ATTR_INOUT_OPT(4) __ATTR_OUT(1) __errno_t __NOTHROW_NCX(__LIBKCALL _c32freopen_s)(FILE **__pstream, char32_t const *__filename, char32_t const *__mode, FILE *__stream) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32freopen_s))(__pstream, __filename, __mode, __stream); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__getws) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_OUT(1),char16_t *,__NOTHROW_NCX,_getc16s,(char16_t *__buf),_getws,(__buf))
#elif defined(__CRT_HAVE_DOS$_getws)
__CREDIRECT_DOS(__ATTR_OUT(1),char16_t *,__NOTHROW_NCX,_getc16s,(char16_t *__buf),_getws,(__buf))
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__getws_s) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetws) || defined(__CRT_HAVE_fgetws_unlocked) || defined(__CRT_HAVE__fgetws_nolock) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)))))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_getws.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_OUT(1) char16_t *__NOTHROW_NCX(__LIBDCALL _getc16s)(char16_t *__buf) { return (__CHAR16_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getws))((__WCHAR_TYPE__ *)__buf); }
#elif (defined(__CRT_HAVE__getws_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_getws_s) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetws) || defined(__CRT_HAVE_fgetws_unlocked) || defined(__CRT_HAVE__fgetws_nolock) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_fgetws) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetws) || (defined(__CRT_HAVE_fgetws_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetws_unlocked) || (defined(__CRT_HAVE__fgetws_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fgetws_nolock) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)))))
#include <libc/local/parts.uchar.stdio/_getc16s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_getc16s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_OUT(1) char16_t *__NOTHROW_NCX(__LIBDCALL _getc16s)(char16_t *__buf) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getc16s))(__buf); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__getws) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_OUT(1),char32_t *,__NOTHROW_NCX,_getc32s,(char32_t *__buf),_getws,(__buf))
#elif defined(__CRT_HAVE_KOS$_getws)
__CREDIRECT_KOS(__ATTR_OUT(1),char32_t *,__NOTHROW_NCX,_getc32s,(char32_t *__buf),_getws,(__buf))
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__getws_s) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetws) || defined(__CRT_HAVE_fgetws_unlocked) || defined(__CRT_HAVE__fgetws_nolock) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)))))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_getws.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_OUT(1) char32_t *__NOTHROW_NCX(__LIBKCALL _getc32s)(char32_t *__buf) { return (__CHAR32_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getws))((__WCHAR_TYPE__ *)__buf); }
#elif (defined(__CRT_HAVE__getws_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_getws_s) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetws) || defined(__CRT_HAVE_fgetws_unlocked) || defined(__CRT_HAVE__fgetws_nolock) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_fgetws) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetws) || (defined(__CRT_HAVE_fgetws_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetws_unlocked) || (defined(__CRT_HAVE__fgetws_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fgetws_nolock) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)))))
#include <libc/local/parts.uchar.stdio/_getc32s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_getc32s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_OUT(1) char32_t *__NOTHROW_NCX(__LIBKCALL _getc32s)(char32_t *__buf) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getc32s))(__buf); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__getws_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_OUTS(1, 2),char16_t *,__NOTHROW_NCX,_getc16s_s,(char16_t *__buf, size_t __buflen),_getws_s,(__buf,__buflen))
#elif defined(__CRT_HAVE_DOS$_getws_s)
__CREDIRECT_DOS(__ATTR_OUTS(1, 2),char16_t *,__NOTHROW_NCX,_getc16s_s,(char16_t *__buf, size_t __buflen),_getws_s,(__buf,__buflen))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetws) || defined(__CRT_HAVE_fgetws_unlocked) || defined(__CRT_HAVE__fgetws_nolock) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_getws_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_OUTS(1, 2) char16_t *__NOTHROW_NCX(__LIBDCALL _getc16s_s)(char16_t *__buf, size_t __buflen) { return (__CHAR16_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getws_s))((__WCHAR_TYPE__ *)__buf, __buflen); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_fgetws) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetws) || (defined(__CRT_HAVE_fgetws_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetws_unlocked) || (defined(__CRT_HAVE__fgetws_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fgetws_nolock) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked))))
#include <libc/local/parts.uchar.stdio/_getc16s_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_getc16s_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_OUTS(1, 2) char16_t *__NOTHROW_NCX(__LIBDCALL _getc16s_s)(char16_t *__buf, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getc16s_s))(__buf, __buflen); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__getws_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_OUTS(1, 2),char32_t *,__NOTHROW_NCX,_getc32s_s,(char32_t *__buf, size_t __buflen),_getws_s,(__buf,__buflen))
#elif defined(__CRT_HAVE_KOS$_getws_s)
__CREDIRECT_KOS(__ATTR_OUTS(1, 2),char32_t *,__NOTHROW_NCX,_getc32s_s,(char32_t *__buf, size_t __buflen),_getws_s,(__buf,__buflen))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE_fgetws) || defined(__CRT_HAVE_fgetws_unlocked) || defined(__CRT_HAVE__fgetws_nolock) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_getws_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_OUTS(1, 2) char32_t *__NOTHROW_NCX(__LIBKCALL _getc32s_s)(char32_t *__buf, size_t __buflen) { return (__CHAR32_TYPE__ *)(__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getws_s))((__WCHAR_TYPE__ *)__buf, __buflen); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_fgetws) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetws) || (defined(__CRT_HAVE_fgetws_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetws_unlocked) || (defined(__CRT_HAVE__fgetws_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fgetws_nolock) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE__IO_ferror) || defined(__CRT_HAVE_ferror_unlocked))))
#include <libc/local/parts.uchar.stdio/_getc32s_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_getc32s_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_OUTS(1, 2) char32_t *__NOTHROW_NCX(__LIBKCALL _getc32s_s)(char32_t *__buf, size_t __buflen) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_getc32s_s))(__buf, __buflen); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__putws) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,_putc16s,(char16_t const *__str),_putws,(__str))
#elif defined(__CRT_HAVE_DOS$_putws)
__CREDIRECT_DOS(__ATTR_IN(1),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,_putc16s,(char16_t const *__str),_putws,(__str))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_fputws) || defined(__CRT_HAVE_fputws_unlocked) || defined(__CRT_HAVE__fputws_nolock) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_putws.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBDCALL _putc16s)(char16_t const *__str) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_putws))((__WCHAR_TYPE__ const *)__str); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_fputws) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputws) || (defined(__CRT_HAVE_fputws_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputws_unlocked) || (defined(__CRT_HAVE__fputws_nolock) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_fputws_nolock) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/_putc16s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_putc16s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBDCALL _putc16s)(char16_t const *__str) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_putc16s))(__str); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__putws) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,_putc32s,(char32_t const *__str),_putws,(__str))
#elif defined(__CRT_HAVE_KOS$_putws)
__CREDIRECT_KOS(__ATTR_IN(1),__STDC_INT_AS_SIZE_T,__NOTHROW_NCX,_putc32s,(char32_t const *__str),_putws,(__str))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_fputws) || defined(__CRT_HAVE_fputws_unlocked) || defined(__CRT_HAVE__fputws_nolock) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_putws.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBKCALL _putc32s)(char32_t const *__str) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_putws))((__WCHAR_TYPE__ const *)__str); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_fputws) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputws) || (defined(__CRT_HAVE_fputws_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputws_unlocked) || (defined(__CRT_HAVE__fputws_nolock) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_fputws_nolock) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/_putc32s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_putc32s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __STDC_INT_AS_SIZE_T __NOTHROW_NCX(__LIBKCALL _putc32s)(char32_t const *__str) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_putc32s))(__str); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wtempnam) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN_OPT(1) __ATTR_IN_OPT(2),char16_t *,__NOTHROW_NCX,_c16tempnam,(char16_t const *__directory, char16_t const *__file_prefix),_wtempnam,(__directory,__file_prefix))
#elif defined(__CRT_HAVE_DOS$_wtempnam)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN_OPT(1) __ATTR_IN_OPT(2),char16_t *,__NOTHROW_NCX,_c16tempnam,(char16_t const *__directory, char16_t const *__file_prefix),_wtempnam,(__directory,__file_prefix))
#endif /* ... */
#if defined(__CRT_HAVE__wtempnam) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN_OPT(1) __ATTR_IN_OPT(2),char32_t *,__NOTHROW_NCX,_c32tempnam,(char32_t const *__directory, char32_t const *__file_prefix),_wtempnam,(__directory,__file_prefix))
#elif defined(__CRT_HAVE_KOS$_wtempnam)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN_OPT(1) __ATTR_IN_OPT(2),char32_t *,__NOTHROW_NCX,_c32tempnam,(char32_t const *__directory, char32_t const *__file_prefix),_wtempnam,(__directory,__file_prefix))
#endif /* ... */
#if defined(__CRT_HAVE__wtmpnam_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_OUTS(1, 2),__errno_t,__NOTHROW_NCX,_c16tmpnam_s,(char16_t *__dst, size_t __wchar_count),_wtmpnam_s,(__dst,__wchar_count))
#elif defined(__CRT_HAVE_DOS$_wtmpnam_s)
__CREDIRECT_DOS(__ATTR_OUTS(1, 2),__errno_t,__NOTHROW_NCX,_c16tmpnam_s,(char16_t *__dst, size_t __wchar_count),_wtmpnam_s,(__dst,__wchar_count))
#endif /* ... */
#if defined(__CRT_HAVE__wtmpnam_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_OUTS(1, 2),__errno_t,__NOTHROW_NCX,_c32tmpnam_s,(char32_t *__dst, size_t __wchar_count),_wtmpnam_s,(__dst,__wchar_count))
#elif defined(__CRT_HAVE_KOS$_wtmpnam_s)
__CREDIRECT_KOS(__ATTR_OUTS(1, 2),__errno_t,__NOTHROW_NCX,_c32tmpnam_s,(char32_t *__dst, size_t __wchar_count),_wtmpnam_s,(__dst,__wchar_count))
#endif /* ... */
#if defined(__CRT_HAVE__wtmpnam) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(,char16_t *,__NOTHROW_NCX,_c16tmpnam,(char16_t *__buf),_wtmpnam,(__buf))
#elif defined(__CRT_HAVE_DOS$_wtmpnam)
__CREDIRECT_DOS(,char16_t *,__NOTHROW_NCX,_c16tmpnam,(char16_t *__buf),_wtmpnam,(__buf))
#endif /* ... */
#if defined(__CRT_HAVE__wtmpnam) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(,char32_t *,__NOTHROW_NCX,_c32tmpnam,(char32_t *__buf),_wtmpnam,(__buf))
#elif defined(__CRT_HAVE_KOS$_wtmpnam)
__CREDIRECT_KOS(,char32_t *,__NOTHROW_NCX,_c32tmpnam,(char32_t *__buf),_wtmpnam,(__buf))
#endif /* ... */
#if defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc16printf,(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf,(__options,__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc16printf,(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf,(__options,__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__stdio_common_vfwprintf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vfc16printf)(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfwprintf))(__options, __stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/__stdio_common_vfc16printf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vfc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vfc16printf)(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfc16printf))(__options, __stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc32printf,(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf,(__options,__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc32printf,(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf,(__options,__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__stdio_common_vfwprintf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vfc32printf)(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfwprintf))(__options, __stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/__stdio_common_vfc32printf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vfc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vfc32printf)(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfc32printf))(__options, __stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc16printf_s,(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf_s,(__options,__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_s)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc16printf_s,(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf_s,(__options,__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__stdio_common_vfwprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vfc16printf_s)(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfwprintf_s))(__options, __stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/__stdio_common_vfc16printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vfc16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vfc16printf_s)(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfc16printf_s))(__options, __stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc32printf_s,(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf_s,(__options,__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc32printf_s,(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf_s,(__options,__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__stdio_common_vfwprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vfc32printf_s)(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfwprintf_s))(__options, __stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/__stdio_common_vfc32printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vfc32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vfc32printf_s)(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfc32printf_s))(__options, __stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF_P(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc16printf_p,(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf_p,(__options,__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_p)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF_P(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc16printf_p,(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf_p,(__options,__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__stdio_common_vfwprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF_P(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vfc16printf_p)(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfwprintf_p))(__options, __stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/__stdio_common_vfc16printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vfc16printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16PRINTF_P(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vfc16printf_p)(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfc16printf_p))(__options, __stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF_P(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc32printf_p,(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf_p,(__options,__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_p)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF_P(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc32printf_p,(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwprintf_p,(__options,__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__stdio_common_vfwprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF_P(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vfc32printf_p)(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfwprintf_p))(__options, __stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/__stdio_common_vfc32printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vfc32printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32PRINTF_P(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vfc32printf_p)(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfc32printf_p))(__options, __stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE___stdio_common_vswprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc16printf,(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf,(__options,__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$__stdio_common_vswprintf)
__CREDIRECT_DOS(__ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc16printf,(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf,(__options,__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__stdio_common_vswprintf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vsc16printf)(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vswprintf))(__options, (__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__stdio_common_vsc16printf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vsc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vsc16printf)(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsc16printf))(__options, __buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE___stdio_common_vswprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc32printf,(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf,(__options,__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$__stdio_common_vswprintf)
__CREDIRECT_KOS(__ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc32printf,(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf,(__options,__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__stdio_common_vswprintf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vsc32printf)(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vswprintf))(__options, (__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__stdio_common_vsc32printf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vsc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vsc32printf)(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsc32printf))(__options, __buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE___stdio_common_vswprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc16printf_s,(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf_s,(__options,__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$__stdio_common_vswprintf_s)
__CREDIRECT_DOS(__ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc16printf_s,(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf_s,(__options,__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__stdio_common_vswprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vsc16printf_s)(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vswprintf_s))(__options, (__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__stdio_common_vsc16printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vsc16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vsc16printf_s)(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsc16printf_s))(__options, __buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE___stdio_common_vswprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc32printf_s,(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf_s,(__options,__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$__stdio_common_vswprintf_s)
__CREDIRECT_KOS(__ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc32printf_s,(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf_s,(__options,__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__stdio_common_vswprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vsc32printf_s)(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vswprintf_s))(__options, (__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__stdio_common_vsc32printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vsc32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vsc32printf_s)(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsc32printf_s))(__options, __buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE___stdio_common_vsnwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(5) __ATTR_LIBC_C16PRINTF(5, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsnc16printf_s,(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vsnwprintf_s,(__options,__buf,__bufsize,__maxsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$__stdio_common_vsnwprintf_s)
__CREDIRECT_DOS(__ATTR_IN(5) __ATTR_LIBC_C16PRINTF(5, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsnc16printf_s,(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vsnwprintf_s,(__options,__buf,__bufsize,__maxsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__stdio_common_vsnwprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(5) __ATTR_LIBC_C16PRINTF(5, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vsnc16printf_s)(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsnwprintf_s))(__options, (__WCHAR_TYPE__ *)__buf, __bufsize, __maxsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__stdio_common_vsnc16printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vsnc16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(5) __ATTR_LIBC_C16PRINTF(5, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vsnc16printf_s)(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsnc16printf_s))(__options, __buf, __bufsize, __maxsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE___stdio_common_vsnwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(5) __ATTR_LIBC_C32PRINTF(5, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsnc32printf_s,(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vsnwprintf_s,(__options,__buf,__bufsize,__maxsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$__stdio_common_vsnwprintf_s)
__CREDIRECT_KOS(__ATTR_IN(5) __ATTR_LIBC_C32PRINTF(5, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsnc32printf_s,(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vsnwprintf_s,(__options,__buf,__bufsize,__maxsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__stdio_common_vsnwprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(5) __ATTR_LIBC_C32PRINTF(5, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vsnc32printf_s)(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsnwprintf_s))(__options, (__WCHAR_TYPE__ *)__buf, __bufsize, __maxsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__stdio_common_vsnc32printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vsnc32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(5) __ATTR_LIBC_C32PRINTF(5, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vsnc32printf_s)(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsnc32printf_s))(__options, __buf, __bufsize, __maxsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE___stdio_common_vswprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_LIBC_C16PRINTF_P(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc16printf_p,(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf_p,(__options,__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$__stdio_common_vswprintf_p)
__CREDIRECT_DOS(__ATTR_IN(4) __ATTR_LIBC_C16PRINTF_P(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc16printf_p,(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf_p,(__options,__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__stdio_common_vswprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF_P(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vsc16printf_p)(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vswprintf_p))(__options, (__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__stdio_common_vsc16printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vsc16printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF_P(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vsc16printf_p)(__UINT64_TYPE__ __options, char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsc16printf_p))(__options, __buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE___stdio_common_vswprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_LIBC_C32PRINTF_P(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc32printf_p,(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf_p,(__options,__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$__stdio_common_vswprintf_p)
__CREDIRECT_KOS(__ATTR_IN(4) __ATTR_LIBC_C32PRINTF_P(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc32printf_p,(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswprintf_p,(__options,__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__stdio_common_vswprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF_P(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vsc32printf_p)(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vswprintf_p))(__options, (__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__stdio_common_vsc32printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vsc32printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF_P(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vsc32printf_p)(__UINT64_TYPE__ __options, char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsc32printf_p))(__options, __buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc16scanf,(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwscanf,(__options,__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc16scanf,(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwscanf,(__options,__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__stdio_common_vfwscanf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vfc16scanf)(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfwscanf))(__options, __stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/__stdio_common_vfc16scanf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vfc16scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C16SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vfc16scanf)(__UINT64_TYPE__ __options, FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfc16scanf))(__options, __stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc32scanf,(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwscanf,(__options,__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vfc32scanf,(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vfwscanf,(__options,__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__stdio_common_vfwscanf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vfc32scanf)(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfwscanf))(__options, __stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/__stdio_common_vfc32scanf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vfc32scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INOUT(2) __ATTR_LIBC_C32SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vfc32scanf)(__UINT64_TYPE__ __options, FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vfc32scanf))(__options, __stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE___stdio_common_vswscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_INS(2, 3) __ATTR_LIBC_C16SCANF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc16scanf,(__UINT64_TYPE__ __options, char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswscanf,(__options,__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$__stdio_common_vswscanf)
__CREDIRECT_DOS(__ATTR_IN(4) __ATTR_INS(2, 3) __ATTR_LIBC_C16SCANF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc16scanf,(__UINT64_TYPE__ __options, char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswscanf,(__options,__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__stdio_common_vswscanf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_INS(2, 3) __ATTR_LIBC_C16SCANF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vsc16scanf)(__UINT64_TYPE__ __options, char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vswscanf))(__options, (__WCHAR_TYPE__ const *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__stdio_common_vsc16scanf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vsc16scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_INS(2, 3) __ATTR_LIBC_C16SCANF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __stdio_common_vsc16scanf)(__UINT64_TYPE__ __options, char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsc16scanf))(__options, __buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE___stdio_common_vswscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_INS(2, 3) __ATTR_LIBC_C32SCANF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc32scanf,(__UINT64_TYPE__ __options, char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswscanf,(__options,__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$__stdio_common_vswscanf)
__CREDIRECT_KOS(__ATTR_IN(4) __ATTR_INS(2, 3) __ATTR_LIBC_C32SCANF(4, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__stdio_common_vsc32scanf,(__UINT64_TYPE__ __options, char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__stdio_common_vswscanf,(__options,__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__stdio_common_vswscanf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_INS(2, 3) __ATTR_LIBC_C32SCANF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vsc32scanf)(__UINT64_TYPE__ __options, char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vswscanf))(__options, (__WCHAR_TYPE__ const *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__stdio_common_vsc32scanf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__stdio_common_vsc32scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_INS(2, 3) __ATTR_LIBC_C32SCANF(4, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __stdio_common_vsc32scanf)(__UINT64_TYPE__ __options, char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__stdio_common_vsc32scanf))(__options, __buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16printf_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vsnwprintf_l)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16printf_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vsnwprintf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwprintf_l))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc16printf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc16printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc16printf_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32printf_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vsnwprintf_l)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32printf_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vsnwprintf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwprintf_l))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc32printf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc32printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc32printf_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_s_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_s_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vswprintf_s_l)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_s_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_s_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vswprintf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_s_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_s_l))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc16printf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc16printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_s_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc16printf_s_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_s_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_s_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vswprintf_s_l)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_s_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_s_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vswprintf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_s_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_s_l))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc32printf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc32printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_s_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc32printf_s_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_p_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_p_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vswprintf_p_l)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_p_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_p_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vswprintf_p_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_p_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_p_l))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc16printf_p_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc16printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_p_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc16printf_p_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_p_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_p_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vswprintf_p_l)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_p_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_p_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vswprintf_p_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_p_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_p_l))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc32printf_p_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc32printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_p_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc32printf_p_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vscwprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc16printf_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vscwprintf_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vscwprintf_l)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc16printf_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vscwprintf_l,(__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vscwprintf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vscc16printf_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscwprintf_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vscc16printf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vscc16printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vscc16printf_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscc16printf_l))(__format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vscwprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc32printf_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vscwprintf_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vscwprintf_l)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc32printf_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vscwprintf_l,(__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vscwprintf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vscc32printf_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscwprintf_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vscc32printf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vscc32printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vscc32printf_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscc32printf_l))(__format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vscwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc16printf_p_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vscwprintf_p_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vscwprintf_p_l)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc16printf_p_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vscwprintf_p_l,(__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vscwprintf_p_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vscc16printf_p_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscwprintf_p_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vscc16printf_p_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vscc16printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vscc16printf_p_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscc16printf_p_l))(__format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vscwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc32printf_p_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vscwprintf_p_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vscwprintf_p_l)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc32printf_p_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vscwprintf_p_l,(__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vscwprintf_p_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vscc32printf_p_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscwprintf_p_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vscc32printf_p_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vscc32printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vscc32printf_p_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscc32printf_p_l))(__format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_c_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vswprintf_l)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_c_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE__vswprintf_c_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_c_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_c_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vswprintf_c_l)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_c_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_c_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vswprintf_c_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_c_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_c_l))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc16printf_c_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc16printf_c_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_c_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc16printf_c_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_c_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vswprintf_l)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_c_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE__vswprintf_c_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_c_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_c_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vswprintf_c_l)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_c_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_c_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vswprintf_c_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_c_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_c_l))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc32printf_c_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc32printf_c_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_c_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc32printf_c_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16printf_s_l,(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwprintf_s_l,(__buf,__bufsize,__maxsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vsnwprintf_s_l)
__CREDIRECT_DOS(__ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16printf_s_l,(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwprintf_s_l,(__buf,__bufsize,__maxsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vsnwprintf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16printf_s_l)(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwprintf_s_l))((__WCHAR_TYPE__ *)__buf, __bufsize, __maxsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc16printf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc16printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16printf_s_l)(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc16printf_s_l))(__buf, __bufsize, __maxsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32printf_s_l,(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwprintf_s_l,(__buf,__bufsize,__maxsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vsnwprintf_s_l)
__CREDIRECT_KOS(__ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32printf_s_l,(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwprintf_s_l,(__buf,__bufsize,__maxsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vsnwprintf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32printf_s_l)(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwprintf_s_l))((__WCHAR_TYPE__ *)__buf, __bufsize, __maxsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc32printf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc32printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32printf_s_l)(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc32printf_s_l))(__buf, __bufsize, __maxsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16printf_s_l,(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_s_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vfwprintf_s_l)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16printf_s_l,(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_s_l,(__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vfwprintf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16printf_s_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwprintf_s_l))(__stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_vfc16printf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc16printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16printf_s_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc16printf_s_l))(__stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32printf_s_l,(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_s_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vfwprintf_s_l)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32printf_s_l,(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_s_l,(__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vfwprintf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32printf_s_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwprintf_s_l))(__stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_vfc32printf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc32printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32printf_s_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc32printf_s_l))(__stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16printf_p_l,(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_p_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vfwprintf_p_l)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16printf_p_l,(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_p_l,(__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vfwprintf_p_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16printf_p_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwprintf_p_l))(__stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_vfc16printf_p_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc16printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16printf_p_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc16printf_p_l))(__stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32printf_p_l,(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_p_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vfwprintf_p_l)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32printf_p_l,(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_p_l,(__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vfwprintf_p_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32printf_p_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwprintf_p_l))(__stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_vfc32printf_p_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc32printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32printf_p_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc32printf_p_l))(__stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vfwscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16scanf_l,(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwscanf_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vfwscanf_l)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16scanf_l,(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwscanf_l,(__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vfwscanf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16scanf_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwscanf_l))(__stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_vfc16scanf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc16scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16scanf_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc16scanf_l))(__stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vfwscanf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32scanf_l,(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwscanf_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vfwscanf_l)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32scanf_l,(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwscanf_l,(__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vfwscanf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32scanf_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwscanf_l))(__stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_vfc32scanf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc32scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32scanf_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc32scanf_l))(__stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16scanf_s_l,(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwscanf_s_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vfwscanf_s_l)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16scanf_s_l,(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwscanf_s_l,(__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vfwscanf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16scanf_s_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwscanf_s_l))(__stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_vfc16scanf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc16scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16scanf_s_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc16scanf_s_l))(__stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32scanf_s_l,(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwscanf_s_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vfwscanf_s_l)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32scanf_s_l,(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwscanf_s_l,(__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vfwscanf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32scanf_s_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwscanf_s_l))(__stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_vfc32scanf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc32scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32scanf_s_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc32scanf_s_l))(__stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vsnwscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16scanf_l,(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwscanf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vsnwscanf_l)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16scanf_l,(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwscanf_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vsnwscanf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16scanf_l)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwscanf_l))((__WCHAR_TYPE__ const *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc16scanf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc16scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16scanf_l)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc16scanf_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwscanf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32scanf_l,(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwscanf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vsnwscanf_l)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32scanf_l,(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwscanf_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vsnwscanf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32scanf_l)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwscanf_l))((__WCHAR_TYPE__ const *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc32scanf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc32scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32scanf_l)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc32scanf_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16scanf_s_l,(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwscanf_s_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vsnwscanf_s_l)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16scanf_s_l,(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwscanf_s_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vsnwscanf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16scanf_s_l)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwscanf_s_l))((__WCHAR_TYPE__ const *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc16scanf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc16scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16scanf_s_l)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc16scanf_s_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32scanf_s_l,(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwscanf_s_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vsnwscanf_s_l)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32scanf_s_l,(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vsnwscanf_s_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vsnwscanf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32scanf_s_l)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwscanf_s_l))((__WCHAR_TYPE__ const *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc32scanf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc32scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32scanf_s_l)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc32scanf_s_l))(__buf, __bufsize, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vwprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16printf_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vwprintf_l)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16printf_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_l,(__format,__locale,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwprintf) || defined(__CRT_HAVE_vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vwprintf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16printf_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwprintf_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwprintf) || (defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_vc16printf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc16printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16printf_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc16printf_l))(__format, __locale, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vwprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32printf_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vwprintf_l)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32printf_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_l,(__format,__locale,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwprintf) || defined(__CRT_HAVE_vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vwprintf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32printf_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwprintf_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwprintf) || (defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_vc32printf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc32printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32printf_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc32printf_l))(__format, __locale, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vfwprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16printf_l,(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vfwprintf_l)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16printf_l,(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_l,(__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vfwprintf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16printf_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwprintf_l))(__stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_vfc16printf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc16printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16printf_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc16printf_l))(__stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vfwprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32printf_l,(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_l,(__stream,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vfwprintf_l)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32printf_l,(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vfwprintf_l,(__stream,__format,__locale,__args))
#elif (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vfwprintf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32printf_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwprintf_l))(__stream, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_vfc32printf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc32printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32printf_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc32printf_l))(__stream, __format, __locale, __args); })
#endif /* ... */
#if defined(__CRT_HAVE___vswprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 0) __ATTR_OUT(1),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__vsc16printf_l,(char16_t *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__vswprintf_l,(__buf,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$__vswprintf_l)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 0) __ATTR_OUT(1),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__vsc16printf_l,(char16_t *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),__vswprintf_l,(__buf,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__vswprintf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 0) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __vsc16printf_l)(char16_t *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__vswprintf_l))((__WCHAR_TYPE__ *)__buf, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__vsc16printf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__vsc16printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 0) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL __vsc16printf_l)(char16_t *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__vsc16printf_l))(__buf, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE___vswprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 0) __ATTR_OUT(1),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__vsc32printf_l,(char32_t *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__vswprintf_l,(__buf,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$__vswprintf_l)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 0) __ATTR_OUT(1),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__vsc32printf_l,(char32_t *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),__vswprintf_l,(__buf,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__vswprintf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 0) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __vsc32printf_l)(char32_t *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__vswprintf_l))((__WCHAR_TYPE__ *)__buf, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/__vsc32printf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(__vsc32printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 0) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL __vsc32printf_l)(char32_t *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__vsc32printf_l))(__buf, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vwscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16scanf_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vwscanf_l)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16scanf_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_l,(__format,__locale,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vwscanf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16scanf_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwscanf_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))))
#include <libc/local/parts.uchar.stdio/_vc16scanf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc16scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16scanf_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc16scanf_l))(__format, __locale, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vwscanf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32scanf_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vwscanf_l)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32scanf_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_l,(__format,__locale,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vwscanf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32scanf_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwscanf_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif (defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))))
#include <libc/local/parts.uchar.stdio/_vc32scanf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc32scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32scanf_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc32scanf_l))(__format, __locale, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vswprintf_l)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE__vswprintf_c_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_c_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vswprintf_c_l)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_l,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_c_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vswprintf_c_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_c_l))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc16printf_c_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc16printf_c_l))(__buf, __bufsize, __format, __locale, __args); }
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vswprintf_l)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE__vswprintf_c_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_c_l,(__buf,__bufsize,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vswprintf_c_l)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_l,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswprintf_c_l,(__buf,__bufsize,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vswprintf_c_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_c_l))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc32printf_c_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc32printf_c_l))(__buf, __bufsize, __format, __locale, __args); }
#endif /* !... */
#if defined(__CRT_HAVE__vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16printf_p,(FILE *__stream, char16_t const *__format, __builtin_va_list __args),_vfwprintf_p,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$_vfwprintf_p)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc16printf_p,(FILE *__stream, char16_t const *__format, __builtin_va_list __args),_vfwprintf_p,(__stream,__format,__args))
#elif (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vfwprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16printf_p)(FILE *__stream, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwprintf_p))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_vfc16printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc16printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vfc16printf_p)(FILE *__stream, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc16printf_p))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32printf_p,(FILE *__stream, char32_t const *__format, __builtin_va_list __args),_vfwprintf_p,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$_vfwprintf_p)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vfc32printf_p,(FILE *__stream, char32_t const *__format, __builtin_va_list __args),_vfwprintf_p,(__stream,__format,__args))
#elif (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vfwprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32printf_p)(FILE *__stream, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfwprintf_p))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_vfc32printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vfc32printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vfc32printf_p)(FILE *__stream, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vfc32printf_p))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE__vsnwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16printf_s,(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __builtin_va_list __args),_vsnwprintf_s,(__buf,__bufsize,__maxsize,__format,__args))
#elif defined(__CRT_HAVE_DOS$_vsnwprintf_s)
__CREDIRECT_DOS(__ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16printf_s,(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __builtin_va_list __args),_vsnwprintf_s,(__buf,__bufsize,__maxsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vsnwprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16printf_s)(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwprintf_s))((__WCHAR_TYPE__ *)__buf, __bufsize, __maxsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc16printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16printf_s)(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc16printf_s))(__buf, __bufsize, __maxsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32printf_s,(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __builtin_va_list __args),_vsnwprintf_s,(__buf,__bufsize,__maxsize,__format,__args))
#elif defined(__CRT_HAVE_KOS$_vsnwprintf_s)
__CREDIRECT_KOS(__ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32printf_s,(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __builtin_va_list __args),_vsnwprintf_s,(__buf,__bufsize,__maxsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vsnwprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32printf_s)(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwprintf_s))((__WCHAR_TYPE__ *)__buf, __bufsize, __maxsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc32printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32printf_s)(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc32printf_s))(__buf, __bufsize, __maxsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16printf,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),_vsnwprintf,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_DOS$_vsnwprintf)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16printf,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),_vsnwprintf,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vsnwprintf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16printf)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwprintf))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc16printf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16printf)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc16printf))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32printf,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),_vsnwprintf,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_KOS$_vsnwprintf)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32printf,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),_vsnwprintf,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vsnwprintf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32printf)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwprintf))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc32printf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32printf)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc32printf))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_c) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_c,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),_vswprintf_c,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_DOS$_vswprintf_c)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_c,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),_vswprintf_c,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vswprintf_c.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_c)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_c))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc16printf_c.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc16printf_c, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_c)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc16printf_c))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_c) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_c,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),_vswprintf_c,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_KOS$_vswprintf_c)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_c,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),_vswprintf_c,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vswprintf_c.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_c)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_c))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc32printf_c.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc32printf_c, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_c)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc32printf_c))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 0) __ATTR_OUT(1),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf,(char16_t *__buf, char16_t const *__format, __builtin_va_list __args),_vswprintf,(__buf,__format,__args))
#elif defined(__CRT_HAVE_DOS$_vswprintf)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 0) __ATTR_OUT(1),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf,(char16_t *__buf, char16_t const *__format, __builtin_va_list __args),_vswprintf,(__buf,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vswprintf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 0) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf)(char16_t *__buf, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf))((__WCHAR_TYPE__ *)__buf, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc16printf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 0) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf)(char16_t *__buf, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc16printf))(__buf, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 0) __ATTR_OUT(1),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf,(char32_t *__buf, char32_t const *__format, __builtin_va_list __args),_vswprintf,(__buf,__format,__args))
#elif defined(__CRT_HAVE_KOS$_vswprintf)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 0) __ATTR_OUT(1),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf,(char32_t *__buf, char32_t const *__format, __builtin_va_list __args),_vswprintf,(__buf,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vswprintf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 0) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf)(char32_t *__buf, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf))((__WCHAR_TYPE__ *)__buf, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc32printf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 0) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf)(char32_t *__buf, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc32printf))(__buf, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16printf_p,(char16_t const *__format, __builtin_va_list __args),_vwprintf_p,(__format,__args))
#elif defined(__CRT_HAVE_DOS$_vwprintf_p)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16printf_p,(char16_t const *__format, __builtin_va_list __args),_vwprintf_p,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vwprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16printf_p)(char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwprintf_p))((__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE__vwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_vc16printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc16printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16printf_p)(char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc16printf_p))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32printf_p,(char32_t const *__format, __builtin_va_list __args),_vwprintf_p,(__format,__args))
#elif defined(__CRT_HAVE_KOS$_vwprintf_p)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32printf_p,(char32_t const *__format, __builtin_va_list __args),_vwprintf_p,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vwprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32printf_p)(char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwprintf_p))((__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE__vwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_vc32printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc32printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32printf_p)(char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc32printf_p))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_p,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),_vswprintf_p,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_DOS$_vswprintf_p)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16printf_p,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),_vswprintf_p,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vswprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_p)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_p))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc16printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc16printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16printf_p)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc16printf_p))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_p,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),_vswprintf_p,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_KOS$_vswprintf_p)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32printf_p,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),_vswprintf_p,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vswprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_p)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswprintf_p))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc32printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc32printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32printf_p)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc32printf_p))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vscwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc16printf,(char16_t const *__format, __builtin_va_list __args),_vscwprintf,(__format,__args))
#elif defined(__CRT_HAVE_DOS$_vscwprintf)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc16printf,(char16_t const *__format, __builtin_va_list __args),_vscwprintf,(__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vscwprintf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vscc16printf)(char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscwprintf))((__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vscc16printf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vscc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vscc16printf)(char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscc16printf))(__format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vscwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc32printf,(char32_t const *__format, __builtin_va_list __args),_vscwprintf,(__format,__args))
#elif defined(__CRT_HAVE_KOS$_vscwprintf)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc32printf,(char32_t const *__format, __builtin_va_list __args),_vscwprintf,(__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vscwprintf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vscc32printf)(char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscwprintf))((__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vscc32printf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vscc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vscc32printf)(char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscc32printf))(__format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vscwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc16printf_p,(char16_t const *__format, __builtin_va_list __args),_vscwprintf_p,(__format,__args))
#elif defined(__CRT_HAVE_DOS$_vscwprintf_p)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc16printf_p,(char16_t const *__format, __builtin_va_list __args),_vscwprintf_p,(__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vscwprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vscc16printf_p)(char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscwprintf_p))((__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vscc16printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vscc16printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vscc16printf_p)(char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscc16printf_p))(__format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vscwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc32printf_p,(char32_t const *__format, __builtin_va_list __args),_vscwprintf_p,(__format,__args))
#elif defined(__CRT_HAVE_KOS$_vscwprintf_p)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vscc32printf_p,(char32_t const *__format, __builtin_va_list __args),_vscwprintf_p,(__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vscwprintf_p.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vscc32printf_p)(char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscwprintf_p))((__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vscc32printf_p.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vscc32printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vscc32printf_p)(char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vscc32printf_p))(__format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16scanf_l,(char16_t const *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswscanf_l,(__buf,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vswscanf_l)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16scanf_l,(char16_t const *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswscanf_l,(__buf,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vswscanf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16scanf_l)(char16_t const *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswscanf_l))((__WCHAR_TYPE__ const *)__buf, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc16scanf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc16scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16scanf_l)(char16_t const *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc16scanf_l))(__buf, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswscanf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32scanf_l,(char32_t const *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswscanf_l,(__buf,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vswscanf_l)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32scanf_l,(char32_t const *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswscanf_l,(__buf,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vswscanf_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32scanf_l)(char32_t const *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswscanf_l))((__WCHAR_TYPE__ const *)__buf, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc32scanf_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc32scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32scanf_l)(char32_t const *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc32scanf_l))(__buf, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16scanf_s_l,(char16_t const *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswscanf_s_l,(__buf,__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vswscanf_s_l)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc16scanf_s_l,(char16_t const *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswscanf_s_l,(__buf,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vswscanf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16scanf_s_l)(char16_t const *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswscanf_s_l))((__WCHAR_TYPE__ const *)__buf, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc16scanf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc16scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsc16scanf_s_l)(char16_t const *__buf, char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc16scanf_s_l))(__buf, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vswscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32scanf_s_l,(char32_t const *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswscanf_s_l,(__buf,__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vswscanf_s_l)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsc32scanf_s_l,(char32_t const *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vswscanf_s_l,(__buf,__format,__locale,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vswscanf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32scanf_s_l)(char32_t const *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vswscanf_s_l))((__WCHAR_TYPE__ const *)__buf, (__WCHAR_TYPE__ const *)__format, __locale, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsc32scanf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsc32scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsc32scanf_s_l)(char32_t const *__buf, char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsc32scanf_s_l))(__buf, __format, __locale, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16scanf,(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),_vsnwscanf,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_DOS$_vsnwscanf)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16scanf,(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),_vsnwscanf,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vsnwscanf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16scanf)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwscanf))((__WCHAR_TYPE__ const *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc16scanf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc16scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16scanf)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc16scanf))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32scanf,(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),_vsnwscanf,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_KOS$_vsnwscanf)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32scanf,(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),_vsnwscanf,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vsnwscanf.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32scanf)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwscanf))((__WCHAR_TYPE__ const *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc32scanf.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc32scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32scanf)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc32scanf))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwscanf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16scanf_s,(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),_vsnwscanf_s,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_DOS$_vsnwscanf_s)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc16scanf_s,(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),_vsnwscanf_s,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vsnwscanf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16scanf_s)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwscanf_s))((__WCHAR_TYPE__ const *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc16scanf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc16scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vsnc16scanf_s)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc16scanf_s))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vsnwscanf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32scanf_s,(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),_vsnwscanf_s,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_KOS$_vsnwscanf_s)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vsnc32scanf_s,(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),_vsnwscanf_s,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vsnwscanf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32scanf_s)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnwscanf_s))((__WCHAR_TYPE__ const *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/_vsnc32scanf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vsnc32scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vsnc32scanf_s)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vsnc32scanf_s))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE__vwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16printf_s_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_s_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vwprintf_s_l)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16printf_s_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_s_l,(__format,__locale,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vwprintf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16printf_s_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwprintf_s_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/_vc16printf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc16printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16printf_s_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc16printf_s_l))(__format, __locale, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32printf_s_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_s_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vwprintf_s_l)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32printf_s_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_s_l,(__format,__locale,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vwprintf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32printf_s_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwprintf_s_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/_vc32printf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc32printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32printf_s_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc32printf_s_l))(__format, __locale, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16printf_p_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_p_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vwprintf_p_l)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16printf_p_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_p_l,(__format,__locale,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vwprintf_p_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16printf_p_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwprintf_p_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/_vc16printf_p_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc16printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16printf_p_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc16printf_p_l))(__format, __locale, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32printf_p_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_p_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vwprintf_p_l)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32printf_p_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_p_l,(__format,__locale,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vwprintf_p_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32printf_p_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwprintf_p_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/_vc32printf_p_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc32printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32printf_p_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc32printf_p_l))(__format, __locale, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16scanf_s_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_s_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_DOS$_vwscanf_s_l)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc16scanf_s_l,(char16_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_s_l,(__format,__locale,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_vwscanf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16scanf_s_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwscanf_s_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked))))
#include <libc/local/parts.uchar.stdio/_vc16scanf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc16scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL _vc16scanf_s_l)(char16_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc16scanf_s_l))(__format, __locale, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__vwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32scanf_s_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_s_l,(__format,__locale,__args))
#elif defined(__CRT_HAVE_KOS$_vwscanf_s_l)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,_vc32scanf_s_l,(char32_t const *__format, __locale_t __locale, __builtin_va_list __args),_vwscanf_s_l,(__format,__locale,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_vwscanf_s_l.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32scanf_s_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vwscanf_s_l))((__WCHAR_TYPE__ const *)__format, __locale, __args); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked))))
#include <libc/local/parts.uchar.stdio/_vc32scanf_s_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(_vc32scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL _vc32scanf_s_l)(char32_t const *__format, __locale_t __locale, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_vc32scanf_s_l))(__format, __locale, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__fwprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_fwprintf_l");
#elif defined(__CRT_HAVE_DOS$_fwprintf_l)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_fwprintf_l");
#elif (defined(__CRT_HAVE__vfwprintf_l) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_fwprintf_l.h>
#define _fc16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwprintf_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_l) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_fc16printf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc16printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16printf_l))(__stream, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16printf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__fwprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_fwprintf_l");
#elif defined(__CRT_HAVE_KOS$_fwprintf_l)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_fwprintf_l");
#elif (defined(__CRT_HAVE__vfwprintf_l) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_fwprintf_l.h>
#define _fc32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwprintf_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_l) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_fc32printf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc32printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32printf_l))(__stream, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32printf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__fwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_s_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_fwprintf_s_l");
#elif defined(__CRT_HAVE_DOS$_fwprintf_s_l)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_s_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_fwprintf_s_l");
#elif (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_fwprintf_s_l.h>
#define _fc16printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwprintf_s_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_fc16printf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc16printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_s_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16printf_s_l))(__stream, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc16printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16printf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__fwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_s_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_fwprintf_s_l");
#elif defined(__CRT_HAVE_KOS$_fwprintf_s_l)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_s_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_fwprintf_s_l");
#elif (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_fwprintf_s_l.h>
#define _fc32printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwprintf_s_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_fc32printf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc32printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_s_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32printf_s_l))(__stream, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc32printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32printf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__fwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_p_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_fwprintf_p_l");
#elif defined(__CRT_HAVE_DOS$_fwprintf_p_l)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_p_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_fwprintf_p_l");
#elif (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_fwprintf_p_l.h>
#define _fc16printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwprintf_p_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_fc16printf_p_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc16printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_p_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16printf_p_l))(__stream, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc16printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16printf_p_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__fwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_p_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_fwprintf_p_l");
#elif defined(__CRT_HAVE_KOS$_fwprintf_p_l)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_p_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_fwprintf_p_l");
#elif (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_fwprintf_p_l.h>
#define _fc32printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwprintf_p_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_fc32printf_p_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc32printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_p_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32printf_p_l))(__stream, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc32printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32printf_p_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__wprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_wprintf_l");
#elif defined(__CRT_HAVE_DOS$_wprintf_l)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_wprintf_l");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwprintf_l) || defined(__CRT_HAVE_vwprintf) || defined(__CRT_HAVE_vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wprintf_l.h>
#define _c16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wprintf_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vwprintf_l) || ((defined(__CRT_HAVE_vwprintf) || defined(__CRT_HAVE_vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwprintf) || (defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_c16printf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_l)(char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16printf_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16printf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_wprintf_l");
#elif defined(__CRT_HAVE_KOS$_wprintf_l)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_wprintf_l");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwprintf_l) || defined(__CRT_HAVE_vwprintf) || defined(__CRT_HAVE_vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wprintf_l.h>
#define _c32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wprintf_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vwprintf_l) || ((defined(__CRT_HAVE_vwprintf) || defined(__CRT_HAVE_vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwprintf) || (defined(__CRT_HAVE_vwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwprintf_unlocked) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_c32printf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_l)(char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32printf_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32printf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_s_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_wprintf_s_l");
#elif defined(__CRT_HAVE_DOS$_wprintf_s_l)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_s_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_wprintf_s_l");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwprintf_s_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wprintf_s_l.h>
#define _c16printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wprintf_s_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vwprintf_s_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_c16printf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_s_l)(char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16printf_s_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c16printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16printf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_s_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_wprintf_s_l");
#elif defined(__CRT_HAVE_KOS$_wprintf_s_l)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_s_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_wprintf_s_l");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwprintf_s_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wprintf_s_l.h>
#define _c32printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wprintf_s_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vwprintf_s_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_c32printf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_s_l)(char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32printf_s_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c32printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32printf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_p_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_wprintf_p_l");
#elif defined(__CRT_HAVE_DOS$_wprintf_p_l)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_p_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_wprintf_p_l");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wprintf_p_l.h>
#define _c16printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wprintf_p_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_c16printf_p_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_p_l)(char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16printf_p_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c16printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16printf_p_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_p_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_wprintf_p_l");
#elif defined(__CRT_HAVE_KOS$_wprintf_p_l)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_p_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_wprintf_p_l");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wprintf_p_l.h>
#define _c32printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wprintf_p_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_c32printf_p_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_p_l)(char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32printf_p_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c32printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32printf_p_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE___swprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 4) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL __sc16printf_l)(char16_t *__buf, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("__swprintf_l");
#elif defined(__CRT_HAVE_DOS$__swprintf_l)
__LIBC __ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 4) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL __sc16printf_l)(char16_t *__buf, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("__swprintf_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/__swprintf_l.h>
#define __sc16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__swprintf_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/__sc16printf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(__sc16printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 4) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL __sc16printf_l)(char16_t *__buf, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__sc16printf_l))(__buf, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define __sc16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__sc16printf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE___swprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 4) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL __sc32printf_l)(char32_t *__buf, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("__swprintf_l");
#elif defined(__CRT_HAVE_KOS$__swprintf_l)
__LIBC __ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 4) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL __sc32printf_l)(char32_t *__buf, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("__swprintf_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/__swprintf_l.h>
#define __sc32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__swprintf_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/__sc32printf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(__sc32printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 4) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL __sc32printf_l)(char32_t *__buf, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__sc32printf_l))(__buf, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define __sc32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(__sc32printf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__fwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_p)(FILE *__stream, char16_t const *__format, ...) __CASMNAME("_fwprintf_p");
#elif defined(__CRT_HAVE_DOS$_fwprintf_p)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_p)(FILE *__stream, char16_t const *__format, ...) __CASMNAME_DOS("_fwprintf_p");
#elif (defined(__CRT_HAVE__vfwprintf_p) || defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_fwprintf_p.h>
#define _fc16printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwprintf_p))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_p) || ((defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_fc16printf_p.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc16printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF_P(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16printf_p)(FILE *__stream, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16printf_p))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc16printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16printf_p))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__fwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_p)(FILE *__stream, char32_t const *__format, ...) __CASMNAME("_fwprintf_p");
#elif defined(__CRT_HAVE_KOS$_fwprintf_p)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_p)(FILE *__stream, char32_t const *__format, ...) __CASMNAME_KOS("_fwprintf_p");
#elif (defined(__CRT_HAVE__vfwprintf_p) || defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_fwprintf_p.h>
#define _fc32printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwprintf_p))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_p) || ((defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/_fc32printf_p.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc32printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF_P(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32printf_p)(FILE *__stream, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32printf_p))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc32printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32printf_p))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__wprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_p)(char16_t const *__format, ...) __CASMNAME("_wprintf_p");
#elif defined(__CRT_HAVE_DOS$_wprintf_p)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_p)(char16_t const *__format, ...) __CASMNAME_DOS("_wprintf_p");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwprintf_p) || defined(__CRT_HAVE__vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wprintf_p.h>
#define _c16printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wprintf_p))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vwprintf_p) || ((defined(__CRT_HAVE__vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE__vwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_c16printf_p.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16printf_p)(char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16printf_p))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c16printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16printf_p))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_p)(char32_t const *__format, ...) __CASMNAME("_wprintf_p");
#elif defined(__CRT_HAVE_KOS$_wprintf_p)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_p)(char32_t const *__format, ...) __CASMNAME_KOS("_wprintf_p");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwprintf_p) || defined(__CRT_HAVE__vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wprintf_p.h>
#define _c32printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wprintf_p))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vwprintf_p) || ((defined(__CRT_HAVE__vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE__vwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_p_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_p) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_c32printf_p.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32printf_p)(char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32printf_p))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c32printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32printf_p))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 3) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf)(char16_t *__buf, char16_t const *__format, ...) __CASMNAME("_swprintf");
#elif defined(__CRT_HAVE_DOS$_swprintf)
__LIBC __ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 3) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf)(char16_t *__buf, char16_t const *__format, ...) __CASMNAME_DOS("_swprintf");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_swprintf.h>
#define _sc16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc16printf.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C16PRINTF(2, 3) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf)(char16_t *__buf, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf))(__buf, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 3) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf)(char32_t *__buf, char32_t const *__format, ...) __CASMNAME("_swprintf");
#elif defined(__CRT_HAVE_KOS$_swprintf)
__LIBC __ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 3) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf)(char32_t *__buf, char32_t const *__format, ...) __CASMNAME_KOS("_swprintf");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_swprintf.h>
#define _sc32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc32printf.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_LIBC_C32PRINTF(2, 3) __ATTR_OUT(1) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf)(char32_t *__buf, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf))(__buf, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_l");
#elif defined(__CRT_HAVE_DOS$_swprintf_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_swprintf_l");
#elif defined(__CRT_HAVE__swprintf_c_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_c_l");
#elif defined(__CRT_HAVE_DOS$_swprintf_c_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_swprintf_c_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_swprintf_c_l.h>
#define _sc16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_c_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc16printf_c_l.h>
#define _sc16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_c_l))(__VA_ARGS__)
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_l");
#elif defined(__CRT_HAVE_KOS$_swprintf_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_swprintf_l");
#elif defined(__CRT_HAVE__swprintf_c_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_c_l");
#elif defined(__CRT_HAVE_KOS$_swprintf_c_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_swprintf_c_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_swprintf_c_l.h>
#define _sc32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_c_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc32printf_c_l.h>
#define _sc32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_c_l))(__VA_ARGS__)
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_s_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_s_l");
#elif defined(__CRT_HAVE_DOS$_swprintf_s_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_s_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_swprintf_s_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_swprintf_s_l.h>
#define _sc16printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_s_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc16printf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc16printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_s_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_s_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc16printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_s_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_s_l");
#elif defined(__CRT_HAVE_KOS$_swprintf_s_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_s_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_swprintf_s_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_swprintf_s_l.h>
#define _sc32printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_s_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc32printf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc32printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_s_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_s_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc32printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_p_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_p_l");
#elif defined(__CRT_HAVE_DOS$_swprintf_p_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_p_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_swprintf_p_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_swprintf_p_l.h>
#define _sc16printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_p_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc16printf_p_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc16printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_p_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_p_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc16printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_p_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_p_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_p_l");
#elif defined(__CRT_HAVE_KOS$_swprintf_p_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_p_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_swprintf_p_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_swprintf_p_l.h>
#define _sc32printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_p_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc32printf_p_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc32printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_p_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_p_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc32printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_p_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_c_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_l");
#elif defined(__CRT_HAVE_DOS$_swprintf_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_c_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_swprintf_l");
#elif defined(__CRT_HAVE__swprintf_c_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_c_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_c_l");
#elif defined(__CRT_HAVE_DOS$_swprintf_c_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_c_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_swprintf_c_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_swprintf_c_l.h>
#define _sc16printf_c_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_c_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc16printf_c_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc16printf_c_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_c_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_c_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc16printf_c_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_c_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_c_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_l");
#elif defined(__CRT_HAVE_KOS$_swprintf_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_c_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_swprintf_l");
#elif defined(__CRT_HAVE__swprintf_c_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_c_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_swprintf_c_l");
#elif defined(__CRT_HAVE_KOS$_swprintf_c_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_c_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_swprintf_c_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_swprintf_c_l.h>
#define _sc32printf_c_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_c_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc32printf_c_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc32printf_c_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_c_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_c_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc32printf_c_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_c_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_snwprintf_l");
#elif defined(__CRT_HAVE_DOS$_snwprintf_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_snwprintf_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_snwprintf_l.h>
#define _snc16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwprintf_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc16printf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc16printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf_l)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16printf_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16printf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_snwprintf_l");
#elif defined(__CRT_HAVE_KOS$_snwprintf_l)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_snwprintf_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_snwprintf_l.h>
#define _snc32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwprintf_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc32printf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc32printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf_l)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32printf_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32printf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 6) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf_s_l)(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_snwprintf_s_l");
#elif defined(__CRT_HAVE_DOS$_snwprintf_s_l)
__LIBC __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 6) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf_s_l)(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_snwprintf_s_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_snwprintf_s_l.h>
#define _snc16printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwprintf_s_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc16printf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc16printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 6) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf_s_l)(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16printf_s_l))(__buf, __bufsize, __maxsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc16printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16printf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 6) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf_s_l)(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_snwprintf_s_l");
#elif defined(__CRT_HAVE_KOS$_snwprintf_s_l)
__LIBC __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 6) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf_s_l)(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_snwprintf_s_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_snwprintf_s_l.h>
#define _snc32printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwprintf_s_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc32printf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc32printf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 6) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf_s_l)(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32printf_s_l))(__buf, __bufsize, __maxsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc32printf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32printf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_p)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME("_swprintf_p");
#elif defined(__CRT_HAVE_DOS$_swprintf_p)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_p)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME_DOS("_swprintf_p");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_swprintf_p.h>
#define _sc16printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_p))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc16printf_p.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc16printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF_P(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_p)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_p))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc16printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_p))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_p)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME("_swprintf_p");
#elif defined(__CRT_HAVE_KOS$_swprintf_p)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_p)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME_KOS("_swprintf_p");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_swprintf_p.h>
#define _sc32printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_p))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc32printf_p.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc32printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF_P(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_p)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_p))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc32printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_p))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_c) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_c)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME("_swprintf_c");
#elif defined(__CRT_HAVE_DOS$_swprintf_c)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_c)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME_DOS("_swprintf_c");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_swprintf_c.h>
#define _sc16printf_c(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_c))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc16printf_c.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc16printf_c, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16printf_c)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_c))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc16printf_c(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16printf_c))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swprintf_c) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_c)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME("_swprintf_c");
#elif defined(__CRT_HAVE_KOS$_swprintf_c)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_c)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME_KOS("_swprintf_c");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_swprintf_c.h>
#define _sc32printf_c(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swprintf_c))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc32printf_c.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc32printf_c, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32printf_c)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_c))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc32printf_c(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32printf_c))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME("_snwprintf");
#elif defined(__CRT_HAVE_DOS$_snwprintf)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME_DOS("_snwprintf");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_snwprintf.h>
#define _snc16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwprintf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc16printf.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16printf))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME("_snwprintf");
#elif defined(__CRT_HAVE_KOS$_snwprintf)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME_KOS("_snwprintf");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_snwprintf.h>
#define _snc32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwprintf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc32printf.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32printf))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf_s)(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, ...) __CASMNAME("_snwprintf_s");
#elif defined(__CRT_HAVE_DOS$_snwprintf_s)
__LIBC __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf_s)(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, ...) __CASMNAME_DOS("_snwprintf_s");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_snwprintf_s.h>
#define _snc16printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwprintf_s))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc16printf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C16PRINTF(4, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16printf_s)(char16_t *__buf, size_t __bufsize, size_t __maxsize, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16printf_s))(__buf, __bufsize, __maxsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc16printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16printf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf_s)(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, ...) __CASMNAME("_snwprintf_s");
#elif defined(__CRT_HAVE_KOS$_snwprintf_s)
__LIBC __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf_s)(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, ...) __CASMNAME_KOS("_snwprintf_s");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_snwprintf_s.h>
#define _snc32printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwprintf_s))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc32printf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(4) __ATTR_LIBC_C32PRINTF(4, 5) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32printf_s)(char32_t *__buf, size_t __bufsize, size_t __maxsize, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32printf_s))(__buf, __bufsize, __maxsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc32printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32printf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__scwprintf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_scwprintf_l");
#elif defined(__CRT_HAVE_DOS$_scwprintf_l)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_scwprintf_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_scwprintf_l.h>
#define _scc16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scwprintf_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_scc16printf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_scc16printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf_l)(char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc16printf_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _scc16printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc16printf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__scwprintf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_scwprintf_l");
#elif defined(__CRT_HAVE_KOS$_scwprintf_l)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_scwprintf_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_scwprintf_l.h>
#define _scc32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scwprintf_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_scc32printf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_scc32printf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf_l)(char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc32printf_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _scc32printf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc32printf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__scwprintf_p_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf_p_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_scwprintf_p_l");
#elif defined(__CRT_HAVE_DOS$_scwprintf_p_l)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf_p_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_scwprintf_p_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_scwprintf_p_l.h>
#define _scc16printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scwprintf_p_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_scc16printf_p_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_scc16printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf_p_l)(char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc16printf_p_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _scc16printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc16printf_p_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__scwprintf_p_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf_p_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_scwprintf_p_l");
#elif defined(__CRT_HAVE_KOS$_scwprintf_p_l)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf_p_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_scwprintf_p_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_scwprintf_p_l.h>
#define _scc32printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scwprintf_p_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_scc32printf_p_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_scc32printf_p_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf_p_l)(char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc32printf_p_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _scc32printf_p_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc32printf_p_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__scwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf)(char16_t const *__format, ...) __CASMNAME("_scwprintf");
#elif defined(__CRT_HAVE_DOS$_scwprintf)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf)(char16_t const *__format, ...) __CASMNAME_DOS("_scwprintf");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_scwprintf.h>
#define _scc16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scwprintf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_scc16printf.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_scc16printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf)(char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc16printf))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _scc16printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc16printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__scwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf)(char32_t const *__format, ...) __CASMNAME("_scwprintf");
#elif defined(__CRT_HAVE_KOS$_scwprintf)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf)(char32_t const *__format, ...) __CASMNAME_KOS("_scwprintf");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_scwprintf.h>
#define _scc32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scwprintf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_scc32printf.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_scc32printf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf)(char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc32printf))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _scc32printf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc32printf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__scwprintf_p) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf_p)(char16_t const *__format, ...) __CASMNAME("_scwprintf_p");
#elif defined(__CRT_HAVE_DOS$_scwprintf_p)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf_p)(char16_t const *__format, ...) __CASMNAME_DOS("_scwprintf_p");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_scwprintf_p.h>
#define _scc16printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scwprintf_p))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_scc16printf_p.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_scc16printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _scc16printf_p)(char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc16printf_p))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _scc16printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc16printf_p))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__scwprintf_p) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf_p)(char32_t const *__format, ...) __CASMNAME("_scwprintf_p");
#elif defined(__CRT_HAVE_KOS$_scwprintf_p)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf_p)(char32_t const *__format, ...) __CASMNAME_KOS("_scwprintf_p");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_scwprintf_p.h>
#define _scc32printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scwprintf_p))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_scc32printf_p.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_scc32printf_p, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF_P(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _scc32printf_p)(char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc32printf_p))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _scc32printf_p(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_scc32printf_p))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__fwscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16scanf_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_fwscanf_l");
#elif defined(__CRT_HAVE_DOS$_fwscanf_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16scanf_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_fwscanf_l");
#elif (defined(__CRT_HAVE__vfwscanf_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_fwscanf_l.h>
#define _fc16scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwscanf_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwscanf_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_fc16scanf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc16scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16scanf_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16scanf_l))(__stream, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc16scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16scanf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__fwscanf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32scanf_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_fwscanf_l");
#elif defined(__CRT_HAVE_KOS$_fwscanf_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32scanf_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_fwscanf_l");
#elif (defined(__CRT_HAVE__vfwscanf_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_fwscanf_l.h>
#define _fc32scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwscanf_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwscanf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwscanf_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_fc32scanf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc32scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32scanf_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32scanf_l))(__stream, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc32scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32scanf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__fwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16scanf_s_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_fwscanf_s_l");
#elif defined(__CRT_HAVE_DOS$_fwscanf_s_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16scanf_s_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_fwscanf_s_l");
#elif (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_fwscanf_s_l.h>
#define _fc16scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwscanf_s_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_fc16scanf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc16scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _fc16scanf_s_l)(FILE *__stream, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16scanf_s_l))(__stream, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc16scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc16scanf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__fwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32scanf_s_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_fwscanf_s_l");
#elif defined(__CRT_HAVE_KOS$_fwscanf_s_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32scanf_s_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_fwscanf_s_l");
#elif (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_fwscanf_s_l.h>
#define _fc32scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fwscanf_s_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/_fc32scanf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_fc32scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _fc32scanf_s_l)(FILE *__stream, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32scanf_s_l))(__stream, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _fc32scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_fc32scanf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE__wscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16scanf_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_wscanf_l");
#elif defined(__CRT_HAVE_DOS$_wscanf_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16scanf_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_wscanf_l");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwscanf_l) || defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wscanf_l.h>
#define _c16scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wscanf_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vwscanf_l) || ((defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))))
#include <libc/local/parts.uchar.stdio/_c16scanf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16scanf_l)(char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16scanf_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c16scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16scanf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wscanf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32scanf_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_wscanf_l");
#elif defined(__CRT_HAVE_KOS$_wscanf_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32scanf_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_wscanf_l");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwscanf_l) || defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wscanf_l.h>
#define _c32scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wscanf_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwscanf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vwscanf_l) || ((defined(__CRT_HAVE_vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwscanf) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))))
#include <libc/local/parts.uchar.stdio/_c32scanf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32scanf_l)(char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32scanf_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c32scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32scanf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16scanf_s_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_wscanf_s_l");
#elif defined(__CRT_HAVE_DOS$_wscanf_s_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16scanf_s_l)(char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_wscanf_s_l");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwscanf_s_l) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_wscanf_s_l.h>
#define _c16scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wscanf_s_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vwscanf_s_l) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))))
#include <libc/local/parts.uchar.stdio/_c16scanf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c16scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _c16scanf_s_l)(char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16scanf_s_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c16scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c16scanf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__wscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32scanf_s_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_wscanf_s_l");
#elif defined(__CRT_HAVE_KOS$_wscanf_s_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32scanf_s_l)(char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_wscanf_s_l");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE__vwscanf_s_l) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_wscanf_s_l.h>
#define _c32scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_wscanf_s_l))(__VA_ARGS__)
#elif (defined(__CRT_HAVE__vwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vwscanf_s_l) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))))
#include <libc/local/parts.uchar.stdio/_c32scanf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_c32scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _c32scanf_s_l)(char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32scanf_s_l))(__format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _c32scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_c32scanf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE__swscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16scanf_l)(char16_t const *__buf, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_swscanf_l");
#elif defined(__CRT_HAVE_DOS$_swscanf_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16scanf_l)(char16_t const *__buf, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_swscanf_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_swscanf_l.h>
#define _sc16scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swscanf_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc16scanf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc16scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16scanf_l)(char16_t const *__buf, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16scanf_l))(__buf, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc16scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16scanf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swscanf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32scanf_l)(char32_t const *__buf, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_swscanf_l");
#elif defined(__CRT_HAVE_KOS$_swscanf_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32scanf_l)(char32_t const *__buf, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_swscanf_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_swscanf_l.h>
#define _sc32scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swscanf_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc32scanf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc32scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32scanf_l)(char32_t const *__buf, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32scanf_l))(__buf, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc32scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32scanf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16scanf_s_l)(char16_t const *__buf, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_swscanf_s_l");
#elif defined(__CRT_HAVE_DOS$_swscanf_s_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16scanf_s_l)(char16_t const *__buf, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_swscanf_s_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_swscanf_s_l.h>
#define _sc16scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swscanf_s_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc16scanf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc16scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _sc16scanf_s_l)(char16_t const *__buf, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16scanf_s_l))(__buf, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc16scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc16scanf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__swscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32scanf_s_l)(char32_t const *__buf, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_swscanf_s_l");
#elif defined(__CRT_HAVE_KOS$_swscanf_s_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32scanf_s_l)(char32_t const *__buf, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_swscanf_s_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_swscanf_s_l.h>
#define _sc32scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_swscanf_s_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_sc32scanf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_sc32scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _sc32scanf_s_l)(char32_t const *__buf, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32scanf_s_l))(__buf, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _sc32scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_sc32scanf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwscanf_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf_l)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_snwscanf_l");
#elif defined(__CRT_HAVE_DOS$_snwscanf_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf_l)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_snwscanf_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_snwscanf_l.h>
#define _snc16scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwscanf_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc16scanf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc16scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf_l)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16scanf_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc16scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16scanf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwscanf_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf_l)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_snwscanf_l");
#elif defined(__CRT_HAVE_KOS$_snwscanf_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf_l)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_snwscanf_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_snwscanf_l.h>
#define _snc32scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwscanf_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc32scanf_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc32scanf_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf_l)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32scanf_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc32scanf_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32scanf_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME("_snwscanf");
#elif defined(__CRT_HAVE_DOS$_snwscanf)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME_DOS("_snwscanf");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_snwscanf.h>
#define _snc16scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwscanf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc16scanf.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc16scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16scanf))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc16scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16scanf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME("_snwscanf");
#elif defined(__CRT_HAVE_KOS$_snwscanf)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME_KOS("_snwscanf");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_snwscanf.h>
#define _snc32scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwscanf))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc32scanf.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc32scanf, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32scanf))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc32scanf(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32scanf))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf_s_l)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME("_snwscanf_s_l");
#elif defined(__CRT_HAVE_DOS$_snwscanf_s_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf_s_l)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) __CASMNAME_DOS("_snwscanf_s_l");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_snwscanf_s_l.h>
#define _snc16scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwscanf_s_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc16scanf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc16scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf_s_l)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16scanf_s_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc16scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16scanf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf_s_l)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME("_snwscanf_s_l");
#elif defined(__CRT_HAVE_KOS$_snwscanf_s_l)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf_s_l)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) __CASMNAME_KOS("_snwscanf_s_l");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_snwscanf_s_l.h>
#define _snc32scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwscanf_s_l))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc32scanf_s_l.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc32scanf_s_l, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 5) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf_s_l)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, __locale_t __locale, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32scanf_s_l))(__buf, __bufsize, __format, __locale, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc32scanf_s_l(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32scanf_s_l))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwscanf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf_s)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME("_snwscanf_s");
#elif defined(__CRT_HAVE_DOS$_snwscanf_s)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf_s)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME_DOS("_snwscanf_s");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/_snwscanf_s.h>
#define _snc16scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwscanf_s))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc16scanf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc16scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C16SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL _snc16scanf_s)(char16_t const *__buf, size_t __bufsize, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16scanf_s))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc16scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc16scanf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE__snwscanf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf_s)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME("_snwscanf_s");
#elif defined(__CRT_HAVE_KOS$_snwscanf_s)
__LIBC __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf_s)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME_KOS("_snwscanf_s");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/_snwscanf_s.h>
#define _snc32scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snwscanf_s))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/_snc32scanf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(_snc32scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(3) __ATTR_INS(1, 2) __ATTR_LIBC_C32SCANF(3, 4) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL _snc32scanf_s)(char32_t const *__buf, size_t __bufsize, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32scanf_s))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define _snc32scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(_snc32scanf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#ifdef __USE_DOS_SLIB
#if defined(__CRT_HAVE_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vfc16printf_s,(FILE *__stream, char16_t const *__format, __builtin_va_list __args),vfwprintf_s,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwprintf_s)
__CREDIRECT_DOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vfc16printf_s,(FILE *__stream, char16_t const *__format, __builtin_va_list __args),vfwprintf_s,(__stream,__format,__args))
#elif (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/vfwprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vfc16printf_s)(FILE *__stream, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwprintf_s))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/vfc16printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vfc16printf_s)(FILE *__stream, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc16printf_s))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vfc32printf_s,(FILE *__stream, char32_t const *__format, __builtin_va_list __args),vfwprintf_s,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwprintf_s)
__CREDIRECT_KOS(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vfc32printf_s,(FILE *__stream, char32_t const *__format, __builtin_va_list __args),vfwprintf_s,(__stream,__format,__args))
#elif (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/vfwprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vfc32printf_s)(FILE *__stream, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwprintf_s))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/vfc32printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vfc32printf_s)(FILE *__stream, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc32printf_s))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_vwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vc16printf_s,(char16_t const *__format, __builtin_va_list __args),vwprintf_s,(__format,__args))
#elif defined(__CRT_HAVE_DOS$vwprintf_s)
__CREDIRECT_DOS(__ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vc16printf_s,(char16_t const *__format, __builtin_va_list __args),vwprintf_s,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/vwprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vc16printf_s)(char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwprintf_s))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/vc16printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vc16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vc16printf_s)(char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc16printf_s))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vc32printf_s,(char32_t const *__format, __builtin_va_list __args),vwprintf_s,(__format,__args))
#elif defined(__CRT_HAVE_KOS$vwprintf_s)
__CREDIRECT_KOS(__ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vc32printf_s,(char32_t const *__format, __builtin_va_list __args),vwprintf_s,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/vwprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vc32printf_s)(char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwprintf_s))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked))
#include <libc/local/parts.uchar.stdio/vc32printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vc32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vc32printf_s)(char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc32printf_s))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vswprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vsc16printf_s,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),vswprintf_s,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_DOS$vswprintf_s)
__CREDIRECT_DOS(__ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vsc16printf_s,(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args),vswprintf_s,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/vswprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vsc16printf_s)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vswprintf_s))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/vsc16printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vsc16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vsc16printf_s)(char16_t *__buf, size_t __bufsize, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vsc16printf_s))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE_vswprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vsc32printf_s,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),vswprintf_s,(__buf,__bufsize,__format,__args))
#elif defined(__CRT_HAVE_KOS$vswprintf_s)
__CREDIRECT_KOS(__ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vsc32printf_s,(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args),vswprintf_s,(__buf,__bufsize,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/vswprintf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vsc32printf_s)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vswprintf_s))((__WCHAR_TYPE__ *)__buf, __bufsize, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/vsc32printf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vsc32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 0) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vsc32printf_s)(char32_t *__buf, size_t __bufsize, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vsc32printf_s))(__buf, __bufsize, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE_vfwscanf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vfc16scanf_s,(FILE *__stream, char16_t const *__format, __builtin_va_list __args),vfwscanf_s,(__stream,__format,__args))
#elif defined(__CRT_HAVE_DOS$vfwscanf_s)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vfc16scanf_s,(FILE *__stream, char16_t const *__format, __builtin_va_list __args),vfwscanf_s,(__stream,__format,__args))
#elif (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/vfwscanf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vfc16scanf_s)(FILE *__stream, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwscanf_s))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/vfc16scanf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc16scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vfc16scanf_s)(FILE *__stream, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc16scanf_s))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_vfwscanf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vfc32scanf_s,(FILE *__stream, char32_t const *__format, __builtin_va_list __args),vfwscanf_s,(__stream,__format,__args))
#elif defined(__CRT_HAVE_KOS$vfwscanf_s)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vfc32scanf_s,(FILE *__stream, char32_t const *__format, __builtin_va_list __args),vfwscanf_s,(__stream,__format,__args))
#elif (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/vfwscanf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vfc32scanf_s)(FILE *__stream, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwscanf_s))(__stream, (__WCHAR_TYPE__ const *)__format, __args); }
#elif (defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/vfc32scanf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vfc32scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vfc32scanf_s)(FILE *__stream, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfc32scanf_s))(__stream, __format, __args); })
#endif /* ... */
#if defined(__CRT_HAVE_vwscanf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vc16scanf_s,(char16_t const *__format, __builtin_va_list __args),vwscanf_s,(__format,__args))
#elif defined(__CRT_HAVE_DOS$vwscanf_s)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vc16scanf_s,(char16_t const *__format, __builtin_va_list __args),vwscanf_s,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/vwscanf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vc16scanf_s)(char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwscanf_s))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked))))
#include <libc/local/parts.uchar.stdio/vc16scanf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vc16scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vc16scanf_s)(char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc16scanf_s))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vwscanf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vc32scanf_s,(char32_t const *__format, __builtin_va_list __args),vwscanf_s,(__format,__args))
#elif defined(__CRT_HAVE_KOS$vwscanf_s)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vc32scanf_s,(char32_t const *__format, __builtin_va_list __args),vwscanf_s,(__format,__args))
#else /* ... */
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/vwscanf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vc32scanf_s)(char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vwscanf_s))((__WCHAR_TYPE__ const *)__format, __args); }
#elif defined(__LOCAL_stdin) && ((defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked))))
#include <libc/local/parts.uchar.stdio/vc32scanf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vc32scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vc32scanf_s)(char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vc32scanf_s))(__format, __args); })
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_vswscanf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vsc16scanf_s,(char16_t const *__buf, char16_t const *__format, __builtin_va_list __args),vswscanf_s,(__buf,__format,__args))
#elif defined(__CRT_HAVE_DOS$vswscanf_s)
__CREDIRECT_DOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vsc16scanf_s,(char16_t const *__buf, char16_t const *__format, __builtin_va_list __args),vswscanf_s,(__buf,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/vswscanf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vsc16scanf_s)(char16_t const *__buf, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vswscanf_s))((__WCHAR_TYPE__ const *)__buf, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/vsc16scanf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vsc16scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBDCALL vsc16scanf_s)(char16_t const *__buf, char16_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vsc16scanf_s))(__buf, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE_vswscanf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vsc32scanf_s,(char32_t const *__buf, char32_t const *__format, __builtin_va_list __args),vswscanf_s,(__buf,__format,__args))
#elif defined(__CRT_HAVE_KOS$vswscanf_s)
__CREDIRECT_KOS(__ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,vsc32scanf_s,(char32_t const *__buf, char32_t const *__format, __builtin_va_list __args),vswscanf_s,(__buf,__format,__args))
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/vswscanf_s.h>
__FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vsc32scanf_s)(char32_t const *__buf, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vswscanf_s))((__WCHAR_TYPE__ const *)__buf, (__WCHAR_TYPE__ const *)__format, __args); }
#else /* ... */
#include <libc/local/parts.uchar.stdio/vsc32scanf_s.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(vsc32scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 0) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__LIBKCALL vsc32scanf_s)(char32_t const *__buf, char32_t const *__format, __builtin_va_list __args) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vsc32scanf_s))(__buf, __format, __args); })
#endif /* !... */
#if defined(__CRT_HAVE_fwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL fc16printf_s)(FILE *__stream, char16_t const *__format, ...) __CASMNAME("fwprintf_s");
#elif defined(__CRT_HAVE_DOS$fwprintf_s)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL fc16printf_s)(FILE *__stream, char16_t const *__format, ...) __CASMNAME_DOS("fwprintf_s");
#elif (defined(__CRT_HAVE_vfwprintf_s) || defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/fwprintf_s.h>
#define fc16printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwprintf_s))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_s) || ((defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/fc16printf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16PRINTF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL fc16printf_s)(FILE *__stream, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16printf_s))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc16printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16printf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_fwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL fc32printf_s)(FILE *__stream, char32_t const *__format, ...) __CASMNAME("fwprintf_s");
#elif defined(__CRT_HAVE_KOS$fwprintf_s)
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL fc32printf_s)(FILE *__stream, char32_t const *__format, ...) __CASMNAME_KOS("fwprintf_s");
#elif (defined(__CRT_HAVE_vfwprintf_s) || defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/fwprintf_s.h>
#define fc32printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwprintf_s))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_s) || ((defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)
#include <libc/local/parts.uchar.stdio/fc32printf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32PRINTF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL fc32printf_s)(FILE *__stream, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32printf_s))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc32printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32printf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_wprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL c16printf_s)(char16_t const *__format, ...) __CASMNAME("wprintf_s");
#elif defined(__CRT_HAVE_DOS$wprintf_s)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL c16printf_s)(char16_t const *__format, ...) __CASMNAME_DOS("wprintf_s");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwprintf_s) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/wprintf_s.h>
#define c16printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wprintf_s))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwprintf_s) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/c16printf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C16PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL c16printf_s)(char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16printf_s))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c16printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16printf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL c32printf_s)(char32_t const *__format, ...) __CASMNAME("wprintf_s");
#elif defined(__CRT_HAVE_KOS$wprintf_s)
__LIBC __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL c32printf_s)(char32_t const *__format, ...) __CASMNAME_KOS("wprintf_s");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwprintf_s) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/wprintf_s.h>
#define c32printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wprintf_s))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwprintf_s) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_s_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdout) && ((defined(__CRT_HAVE__vfwprintf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwprintf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwprintf_s) || defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf_s) || ((defined(__CRT_HAVE___stdio_common_vfwprintf) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwprintf) || ((defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_vfwprintf_unlocked) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwprintf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf) || (defined(__CRT_HAVE_vfwprintf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwprintf_unlocked) || ((defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_file_wprinter) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter) || (defined(__CRT_HAVE_file_wprinter_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$file_wprinter_unlocked) || ((defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_fputwc_unlocked) || defined(__CRT_HAVE_putwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_fputwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc) || (defined(__CRT_HAVE_putwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc) || (defined(__CRT_HAVE_fputwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fputwc_unlocked) || (defined(__CRT_HAVE_putwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$putwc_unlocked)))
#include <libc/local/parts.uchar.stdio/c32printf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(1) __ATTR_LIBC_C32PRINTF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL c32printf_s)(char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32printf_s))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c32printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32printf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_swprintf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL sc16printf_s)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME("swprintf_s");
#elif defined(__CRT_HAVE_DOS$swprintf_s)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL sc16printf_s)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) __CASMNAME_DOS("swprintf_s");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/swprintf_s.h>
#define sc16printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(swprintf_s))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/sc16printf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(sc16printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C16PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL sc16printf_s)(char16_t *__buf, size_t __bufsize, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc16printf_s))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define sc16printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc16printf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE_swprintf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL sc32printf_s)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME("swprintf_s");
#elif defined(__CRT_HAVE_KOS$swprintf_s)
__LIBC __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL sc32printf_s)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) __CASMNAME_KOS("swprintf_s");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/swprintf_s.h>
#define sc32printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(swprintf_s))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/sc32printf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(sc32printf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_IN(3) __ATTR_LIBC_C32PRINTF(3, 4) __ATTR_OUTS(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL sc32printf_s)(char32_t *__buf, size_t __bufsize, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc32printf_s))(__buf, __bufsize, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define sc32printf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc32printf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE_fwscanf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL fc16scanf_s)(FILE *__stream, char16_t const *__format, ...) __CASMNAME("fwscanf_s");
#elif defined(__CRT_HAVE_DOS$fwscanf_s)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL fc16scanf_s)(FILE *__stream, char16_t const *__format, ...) __CASMNAME_DOS("fwscanf_s");
#elif (defined(__CRT_HAVE_vfwscanf_s) || defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/fwscanf_s.h>
#define fc16scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwscanf_s))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwscanf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_s) || ((defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/fc16scanf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc16scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL fc16scanf_s)(FILE *__stream, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16scanf_s))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc16scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc16scanf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_fwscanf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL fc32scanf_s)(FILE *__stream, char32_t const *__format, ...) __CASMNAME("fwscanf_s");
#elif defined(__CRT_HAVE_KOS$fwscanf_s)
__LIBC __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL fc32scanf_s)(FILE *__stream, char32_t const *__format, ...) __CASMNAME_KOS("fwscanf_s");
#elif (defined(__CRT_HAVE_vfwscanf_s) || defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/fwscanf_s.h>
#define fc32scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fwscanf_s))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vfwscanf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_s) || ((defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))
#include <libc/local/parts.uchar.stdio/fc32scanf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(fc32scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL fc32scanf_s)(FILE *__stream, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32scanf_s))(__stream, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define fc32scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(fc32scanf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#if defined(__CRT_HAVE_wscanf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL c16scanf_s)(char16_t const *__format, ...) __CASMNAME("wscanf_s");
#elif defined(__CRT_HAVE_DOS$wscanf_s)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL c16scanf_s)(char16_t const *__format, ...) __CASMNAME_DOS("wscanf_s");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwscanf_s) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/wscanf_s.h>
#define c16scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wscanf_s))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwscanf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vwscanf_s) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 2) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 2) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$ungetwc_unlocked)))))
#include <libc/local/parts.uchar.stdio/c16scanf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c16scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C16SCANF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL c16scanf_s)(char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16scanf_s))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c16scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c16scanf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_wscanf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL c32scanf_s)(char32_t const *__format, ...) __CASMNAME("wscanf_s");
#elif defined(__CRT_HAVE_KOS$wscanf_s)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL c32scanf_s)(char32_t const *__format, ...) __CASMNAME_KOS("wscanf_s");
#else /* ... */
#include <libc/template/stdstreams.h>
#if (defined(__CRT_HAVE_vwscanf_s) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))))) && __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/wscanf_s.h>
#define c32scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wscanf_s))(__VA_ARGS__)
#elif (defined(__CRT_HAVE_vwscanf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vwscanf_s) || (defined(__LOCAL_stdin) && (defined(__CRT_HAVE__vfwscanf_s_l) || defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__LOCAL_stdin) && ((defined(__CRT_HAVE__vfwscanf_s_l) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$_vfwscanf_s_l) || ((defined(__CRT_HAVE___stdio_common_vfwscanf) || defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE___stdio_common_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$__stdio_common_vfwscanf) || ((defined(__CRT_HAVE_vfwscanf) || defined(__CRT_HAVE_vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)))) && __SIZEOF_WCHAR_T__ == 4) || (defined(__CRT_HAVE_vfwscanf) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf) || (defined(__CRT_HAVE_vfwscanf_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$vfwscanf_unlocked) || ((defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc) || defined(__CRT_HAVE_fgetwc_unlocked) || defined(__CRT_HAVE_getwc_unlocked)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && __SIZEOF_WCHAR_T__ == 4) || (((defined(__CRT_HAVE_fgetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc) || (defined(__CRT_HAVE_getwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc) || (defined(__CRT_HAVE_fgetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$fgetwc_unlocked) || (defined(__CRT_HAVE_getwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$getwc_unlocked)) && ((defined(__CRT_HAVE_ungetwc) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc) || (defined(__CRT_HAVE_ungetwc_unlocked) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)) || defined(__CRT_HAVE_KOS$ungetwc_unlocked)))))
#include <libc/local/parts.uchar.stdio/c32scanf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(c32scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_LIBC_C32SCANF(1, 2) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL c32scanf_s)(char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32scanf_s))(__format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define c32scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(c32scanf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* ... */
#endif /* !... */
#if defined(__CRT_HAVE_swscanf_s) && __SIZEOF_WCHAR_T__ == 2 && defined(__VLIBCCALL_IS_VLIBDCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL sc16scanf_s)(char16_t const *__buf, char16_t const *__format, ...) __CASMNAME("swscanf_s");
#elif defined(__CRT_HAVE_DOS$swscanf_s)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL sc16scanf_s)(char16_t const *__buf, char16_t const *__format, ...) __CASMNAME_DOS("swscanf_s");
#elif __SIZEOF_WCHAR_T__ == 2
#include <libc/local/corecrt_wstdio/swscanf_s.h>
#define sc16scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(swscanf_s))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/sc16scanf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(sc16scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C16SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBDCALL sc16scanf_s)(char16_t const *__buf, char16_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc16scanf_s))(__buf, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define sc16scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc16scanf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#if defined(__CRT_HAVE_swscanf_s) && __SIZEOF_WCHAR_T__ == 4 && defined(__VLIBCCALL_IS_VLIBKCALL)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL sc32scanf_s)(char32_t const *__buf, char32_t const *__format, ...) __CASMNAME("swscanf_s");
#elif defined(__CRT_HAVE_KOS$swscanf_s)
__LIBC __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL sc32scanf_s)(char32_t const *__buf, char32_t const *__format, ...) __CASMNAME_KOS("swscanf_s");
#elif __SIZEOF_WCHAR_T__ == 4
#include <libc/local/corecrt_wstdio/swscanf_s.h>
#define sc32scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(swscanf_s))(__VA_ARGS__)
#else /* ... */
#include <libc/local/parts.uchar.stdio/sc32scanf_s.h>
#if defined(__cplusplus) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_USING_OR_IMPL(sc32scanf_s, __FORCELOCAL __ATTR_ARTIFICIAL __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) __ATTR_LIBC_C32SCANF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_NCX(__VLIBKCALL sc32scanf_s)(char32_t const *__buf, char32_t const *__format, ...) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc32scanf_s))(__buf, __format, __builtin_va_arg_pack()); })
#else /* __cplusplus && __has_builtin(__builtin_va_arg_pack) */
#define sc32scanf_s(...) (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(sc32scanf_s))(__VA_ARGS__)
#endif /* !__cplusplus || !__has_builtin(__builtin_va_arg_pack) */
#endif /* !... */
#endif /* __USE_DOS_SLIB */
#endif /* __USE_DOS */

__SYSDECL_END
#endif /* __CC__ */

#endif /* !_PARTS_UCHAR_STDIO_H */
