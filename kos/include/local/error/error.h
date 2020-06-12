/* HASH CRC-32:0xd909923a */
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
#ifndef __local_error_defined
#define __local_error_defined 1
#include <__crt.h>
#include <local/program_invocation_name.h>
#if !defined(__NO_STDSTREAMS) && (defined(__CRT_HAVE_exit) || defined(__CRT_HAVE_quick_exit) || defined(__CRT_HAVE__exit) || defined(__CRT_HAVE__Exit)) && (defined(__CRT_HAVE_fprintf) || defined(__CRT_HAVE__IO_fprintf) || defined(__CRT_HAVE_fprintf_s) || defined(__CRT_HAVE_fprintf_unlocked) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE_putc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock) || defined(__CRT_HAVE__IO_fwrite)) && (defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE_putc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock) || defined(__CRT_HAVE__IO_fwrite)) && (defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE_putc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock) || defined(__CRT_HAVE__IO_fwrite)) && defined(__LOCAL_program_invocation_short_name)
#include <kos/anno.h>
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: fprintf from stdio */
#ifndef __local___localdep_fprintf_defined
#define __local___localdep_fprintf_defined 1
#if __has_builtin(__builtin_fprintf) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_fprintf) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__CEIREDIRECT(__ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)),__STDC_INT_AS_SSIZE_T,__THROWING,__localdep_fprintf,(__FILE *__restrict __stream, char const *__restrict __format, ...),fprintf,{ return __builtin_fprintf(__stream, __format, __builtin_va_arg_pack()); })
#elif defined(__CRT_HAVE_fprintf_unlocked) && defined(__USE_STDIO_UNLOCKED)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__LIBC __ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (__VLIBCCALL __localdep_fprintf)(__FILE *__restrict __stream, char const *__restrict __format, ...) __THROWS(...) __CASMNAME("fprintf_unlocked");
#elif defined(__CRT_HAVE_fprintf)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__LIBC __ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (__VLIBCCALL __localdep_fprintf)(__FILE *__restrict __stream, char const *__restrict __format, ...) __THROWS(...) __CASMNAME("fprintf");
#elif defined(__CRT_HAVE__IO_fprintf)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__LIBC __ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (__VLIBCCALL __localdep_fprintf)(__FILE *__restrict __stream, char const *__restrict __format, ...) __THROWS(...) __CASMNAME("_IO_fprintf");
#elif defined(__CRT_HAVE_fprintf_s)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__LIBC __ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (__VLIBCCALL __localdep_fprintf)(__FILE *__restrict __stream, char const *__restrict __format, ...) __THROWS(...) __CASMNAME("fprintf_s");
#elif defined(__CRT_HAVE_fprintf_unlocked)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__LIBC __ATTR_LIBC_PRINTF(2, 3) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (__VLIBCCALL __localdep_fprintf)(__FILE *__restrict __stream, char const *__restrict __format, ...) __THROWS(...) __CASMNAME("fprintf_unlocked");
#elif defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE_putc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock) || defined(__CRT_HAVE__IO_fwrite)
__NAMESPACE_LOCAL_END
#include <local/stdio/fprintf.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
#define __localdep_fprintf __LIBC_LOCAL_NAME(fprintf)
#else /* ... */
#undef __local___localdep_fprintf_defined
#endif /* !... */
#endif /* !__local___localdep_fprintf_defined */
/* Dependency: fputc from stdio */
#ifndef __local___localdep_fputc_defined
#define __local___localdep_fputc_defined 1
#if __has_builtin(__builtin_fputc) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_fputc)
/* Write a single character `CH' to `STREAM' */
__CEIREDIRECT(__ATTR_NONNULL((2)),int,__THROWING,__localdep_fputc,(int __ch, __FILE *__restrict __stream),fputc,{ return __builtin_fputc(__ch, __stream); })
#elif defined(__CRT_HAVE_fputc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* Write a single character `CH' to `STREAM' */
__CREDIRECT(__ATTR_NONNULL((2)),int,__THROWING,__localdep_fputc,(int __ch, __FILE *__restrict __stream),fputc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE_putc_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* Write a single character `CH' to `STREAM' */
__CREDIRECT(__ATTR_NONNULL((2)),int,__THROWING,__localdep_fputc,(int __ch, __FILE *__restrict __stream),putc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE_fputc)
/* Write a single character `CH' to `STREAM' */
__CREDIRECT(__ATTR_NONNULL((2)),int,__THROWING,__localdep_fputc,(int __ch, __FILE *__restrict __stream),fputc,(__ch,__stream))
#elif defined(__CRT_HAVE_putc)
/* Write a single character `CH' to `STREAM' */
__CREDIRECT(__ATTR_NONNULL((2)),int,__THROWING,__localdep_fputc,(int __ch, __FILE *__restrict __stream),putc,(__ch,__stream))
#elif defined(__CRT_HAVE__IO_putc)
/* Write a single character `CH' to `STREAM' */
__CREDIRECT(__ATTR_NONNULL((2)),int,__THROWING,__localdep_fputc,(int __ch, __FILE *__restrict __stream),_IO_putc,(__ch,__stream))
#elif defined(__CRT_HAVE_fputc_unlocked)
/* Write a single character `CH' to `STREAM' */
__CREDIRECT(__ATTR_NONNULL((2)),int,__THROWING,__localdep_fputc,(int __ch, __FILE *__restrict __stream),fputc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE_putc_unlocked)
/* Write a single character `CH' to `STREAM' */
__CREDIRECT(__ATTR_NONNULL((2)),int,__THROWING,__localdep_fputc,(int __ch, __FILE *__restrict __stream),putc_unlocked,(__ch,__stream))
#elif (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock) || defined(__CRT_HAVE__IO_fwrite)
__NAMESPACE_LOCAL_END
#include <local/stdio/fputc.h>
__NAMESPACE_LOCAL_BEGIN
/* Write a single character `CH' to `STREAM' */
#define __localdep_fputc __LIBC_LOCAL_NAME(fputc)
#else /* ... */
#undef __local___localdep_fputc_defined
#endif /* !... */
#endif /* !__local___localdep_fputc_defined */
/* Dependency: strerror from string */
#ifndef __local___localdep_strerror_defined
#define __local___localdep_strerror_defined 1
#ifdef __CRT_HAVE_strerror
__CREDIRECT(__ATTR_COLD __ATTR_RETNONNULL __ATTR_WUNUSED,char *,__NOTHROW_NCX,__localdep_strerror,(int __errnum),strerror,(__errnum))
#else /* __CRT_HAVE_strerror */
__NAMESPACE_LOCAL_END
#include <local/string/strerror.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_strerror __LIBC_LOCAL_NAME(strerror)
#endif /* !__CRT_HAVE_strerror */
#endif /* !__local___localdep_strerror_defined */
/* Dependency: vfprintf from stdio */
#ifndef __local___localdep_vfprintf_defined
#define __local___localdep_vfprintf_defined 1
#if __has_builtin(__builtin_vfprintf) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_vfprintf)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__CEIREDIRECT(__ATTR_LIBC_PRINTF(2, 0) __ATTR_NONNULL((1, 2)),__STDC_INT_AS_SSIZE_T,__THROWING,__localdep_vfprintf,(__FILE *__restrict __stream, char const *__restrict __format, __builtin_va_list __args),vfprintf,{ return __builtin_vfprintf(__stream, __format, __args); })
#elif defined(__CRT_HAVE_vfprintf_unlocked) && defined(__USE_STDIO_UNLOCKED)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__CREDIRECT(__ATTR_LIBC_PRINTF(2, 0) __ATTR_NONNULL((1, 2)),__STDC_INT_AS_SSIZE_T,__THROWING,__localdep_vfprintf,(__FILE *__restrict __stream, char const *__restrict __format, __builtin_va_list __args),vfprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfprintf)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__CREDIRECT(__ATTR_LIBC_PRINTF(2, 0) __ATTR_NONNULL((1, 2)),__STDC_INT_AS_SSIZE_T,__THROWING,__localdep_vfprintf,(__FILE *__restrict __stream, char const *__restrict __format, __builtin_va_list __args),vfprintf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfprintf_s)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__CREDIRECT(__ATTR_LIBC_PRINTF(2, 0) __ATTR_NONNULL((1, 2)),__STDC_INT_AS_SSIZE_T,__THROWING,__localdep_vfprintf,(__FILE *__restrict __stream, char const *__restrict __format, __builtin_va_list __args),vfprintf_s,(__stream,__format,__args))
#elif defined(__CRT_HAVE__IO_vfprintf)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__CREDIRECT(__ATTR_LIBC_PRINTF(2, 0) __ATTR_NONNULL((1, 2)),__STDC_INT_AS_SSIZE_T,__THROWING,__localdep_vfprintf,(__FILE *__restrict __stream, char const *__restrict __format, __builtin_va_list __args),_IO_vfprintf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_vfprintf_unlocked)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
__CREDIRECT(__ATTR_LIBC_PRINTF(2, 0) __ATTR_NONNULL((1, 2)),__STDC_INT_AS_SSIZE_T,__THROWING,__localdep_vfprintf,(__FILE *__restrict __stream, char const *__restrict __format, __builtin_va_list __args),vfprintf_unlocked,(__stream,__format,__args))
#elif defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fputc) || defined(__CRT_HAVE_putc) || defined(__CRT_HAVE__IO_putc) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE_putc_unlocked) || (defined(__CRT_DOS) && defined(__CRT_HAVE__flsbuf)) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock) || defined(__CRT_HAVE__IO_fwrite)
__NAMESPACE_LOCAL_END
#include <local/stdio/vfprintf.h>
__NAMESPACE_LOCAL_BEGIN
/* Print data to `STREAM', following `FORMAT'
 * Return the number of successfully printed bytes */
#define __localdep_vfprintf __LIBC_LOCAL_NAME(vfprintf)
#else /* ... */
#undef __local___localdep_vfprintf_defined
#endif /* !... */
#endif /* !__local___localdep_vfprintf_defined */
/* Dependency: fflush from stdio */
#ifndef __local___localdep_fflush_defined
#define __local___localdep_fflush_defined 1
#if defined(__CRT_HAVE_fflush_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* Flush any unwritten data from `STREAM' to the underlying filesystem/TTY */
__CREDIRECT(,int,__THROWING,__localdep_fflush,(__FILE *__stream),fflush_unlocked,(__stream))
#elif defined(__CRT_HAVE__fflush_nolock) && defined(__USE_STDIO_UNLOCKED)
/* Flush any unwritten data from `STREAM' to the underlying filesystem/TTY */
__CREDIRECT(,int,__THROWING,__localdep_fflush,(__FILE *__stream),_fflush_nolock,(__stream))
#elif defined(__CRT_HAVE_fflush)
/* Flush any unwritten data from `STREAM' to the underlying filesystem/TTY */
__CREDIRECT(,int,__THROWING,__localdep_fflush,(__FILE *__stream),fflush,(__stream))
#elif defined(__CRT_HAVE__IO_fflush)
/* Flush any unwritten data from `STREAM' to the underlying filesystem/TTY */
__CREDIRECT(,int,__THROWING,__localdep_fflush,(__FILE *__stream),_IO_fflush,(__stream))
#elif defined(__CRT_HAVE_fflush_unlocked)
/* Flush any unwritten data from `STREAM' to the underlying filesystem/TTY */
__CREDIRECT(,int,__THROWING,__localdep_fflush,(__FILE *__stream),fflush_unlocked,(__stream))
#elif defined(__CRT_HAVE__fflush_nolock)
/* Flush any unwritten data from `STREAM' to the underlying filesystem/TTY */
__CREDIRECT(,int,__THROWING,__localdep_fflush,(__FILE *__stream),_fflush_nolock,(__stream))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/stdio/fflush.h>
__NAMESPACE_LOCAL_BEGIN
/* Flush any unwritten data from `STREAM' to the underlying filesystem/TTY */
#define __localdep_fflush __LIBC_LOCAL_NAME(fflush)
#endif /* !... */
#endif /* !__local___localdep_fflush_defined */
/* Dependency: exit from stdlib */
#ifndef __local___localdep_exit_defined
#define __local___localdep_exit_defined 1
#if __has_builtin(__builtin_exit) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_exit)
__CEIREDIRECT(__ATTR_NORETURN,void,__THROWING,__localdep_exit,(int __status),exit,{ return __builtin_exit(__status); })
#elif defined(__CRT_HAVE_exit)
__CREDIRECT_VOID(__ATTR_NORETURN,__THROWING,__localdep_exit,(int __status),exit,(__status))
#elif defined(__CRT_HAVE_quick_exit)
__CREDIRECT_VOID(__ATTR_NORETURN,__THROWING,__localdep_exit,(int __status),quick_exit,(__status))
#elif defined(__CRT_HAVE__exit)
__CREDIRECT_VOID(__ATTR_NORETURN,__THROWING,__localdep_exit,(int __status),_exit,(__status))
#elif defined(__CRT_HAVE__Exit)
__CREDIRECT_VOID(__ATTR_NORETURN,__THROWING,__localdep_exit,(int __status),_Exit,(__status))
#else /* ... */
#undef __local___localdep_exit_defined
#endif /* !... */
#endif /* !__local___localdep_exit_defined */
__NAMESPACE_LOCAL_END
#include <local/stdstreams.h>
#ifndef __LOCAL_error_print_progname
#ifdef __error_print_progname
#define __LOCAL_error_print_progname __error_print_progname
#elif defined(__CRT_HAVE_error_print_progname)
#ifdef __NO_ASMNAME
__LIBC void (__LIBCCALL *__LOCAL_error_print_progname)(void) __ASMNAME("error_print_progname");
#else /* __NO_ASMNAME */
__LIBC void (__LIBCCALL *__error_print_progname)(void);
#ifndef __cplusplus
#define __error_print_progname         __error_print_progname
#endif /* !__cplusplus */
#define __LOCAL_error_print_progname __error_print_progname
#endif /* !__NO_ASMNAME */
#endif /* __CRT_HAVE_error_print_progname */
#endif
#ifndef __LOCAL_error_message_count
#ifdef __error_message_count
#define __LOCAL_error_message_count __error_message_count
#elif defined(__CRT_HAVE_error_message_count)
#ifdef __NO_ASMNAME
__LIBC unsigned int __LOCAL_error_message_count __ASMNAME("error_message_count");
#else /* __NO_ASMNAME */
__LIBC unsigned int __error_message_count;
#ifndef __cplusplus
#define __error_message_count         __error_message_count
#endif /* !__cplusplus */
#define __LOCAL_error_message_count __error_message_count
#endif /* !__NO_ASMNAME */
#endif /* __CRT_HAVE_error_message_count */
#endif
__NAMESPACE_LOCAL_BEGIN
/* Helper function for printing an error message to `stderr' and possibly exiting the program
 * The message is printed as: `<program_invocation_short_name>: <format...>[: <strerror(errnum)>]\n'
 * Also note that `stdout' is flushed before the message is printed.
 * If `STATUS' is non-zero, follow up with a call to `exit(status)' */
__LOCAL_LIBC(error) __ATTR_LIBC_PRINTF(3, 4) void
(__VLIBCCALL __LIBC_LOCAL_NAME(error))(int __status, __errno_t __errnum, const char *__format, ...) __THROWS(...) {
#ifdef __LOCAL_error_print_progname
	if (__LOCAL_error_print_progname) {
		(*__LOCAL_error_print_progname)();
	} else
#endif /* __LOCAL_error_print_progname */
	{
		__localdep_fflush(__LOCAL_stdout);
		__localdep_fprintf(__LOCAL_stderr, "%s: ", __LOCAL_program_invocation_short_name);
	}
	if (__format) {
		__builtin_va_list __args;
		__builtin_va_start(__args, __format);
		__localdep_vfprintf(__LOCAL_stderr, __format, __args);
		__builtin_va_end(__args);
	}
#ifdef __LOCAL_error_message_count
	++__LOCAL_error_message_count;
#endif /* __LOCAL_error_message_count */
	if (__errnum != 0)
		__localdep_fprintf(__LOCAL_stderr, ": %s", __localdep_strerror(__errnum));
	__localdep_fputc('\n', __LOCAL_stderr);
	if (__status != 0)
		__localdep_exit(__status);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_error_defined
#define __local___localdep_error_defined 1
#define __localdep_error __LIBC_LOCAL_NAME(error)
#endif /* !__local___localdep_error_defined */
#else /* !__NO_STDSTREAMS && (__CRT_HAVE_exit || __CRT_HAVE_quick_exit || __CRT_HAVE__exit || __CRT_HAVE__Exit) && (__CRT_HAVE_fprintf || __CRT_HAVE__IO_fprintf || __CRT_HAVE_fprintf_s || __CRT_HAVE_fprintf_unlocked || __CRT_HAVE_vfprintf || __CRT_HAVE_vfprintf_s || __CRT_HAVE__IO_vfprintf || __CRT_HAVE_vfprintf_unlocked || __CRT_HAVE_file_printer || __CRT_HAVE_file_printer_unlocked || __CRT_HAVE_fwrite || __CRT_HAVE_fwrite_s || __CRT_HAVE_fputc || __CRT_HAVE_putc || __CRT_HAVE__IO_putc || __CRT_HAVE_fputc_unlocked || __CRT_HAVE_putc_unlocked || (__CRT_DOS && __CRT_HAVE__flsbuf) || __CRT_HAVE_fwrite_unlocked || __CRT_HAVE__fwrite_nolock || __CRT_HAVE__IO_fwrite) && (__CRT_HAVE_vfprintf || __CRT_HAVE_vfprintf_s || __CRT_HAVE__IO_vfprintf || __CRT_HAVE_vfprintf_unlocked || __CRT_HAVE_file_printer || __CRT_HAVE_file_printer_unlocked || __CRT_HAVE_fwrite || __CRT_HAVE_fwrite_s || __CRT_HAVE_fputc || __CRT_HAVE_putc || __CRT_HAVE__IO_putc || __CRT_HAVE_fputc_unlocked || __CRT_HAVE_putc_unlocked || (__CRT_DOS && __CRT_HAVE__flsbuf) || __CRT_HAVE_fwrite_unlocked || __CRT_HAVE__fwrite_nolock || __CRT_HAVE__IO_fwrite) && (__CRT_HAVE_fputc || __CRT_HAVE_putc || __CRT_HAVE__IO_putc || __CRT_HAVE_fputc_unlocked || __CRT_HAVE_putc_unlocked || (__CRT_DOS && __CRT_HAVE__flsbuf) || __CRT_HAVE_fwrite || __CRT_HAVE_fwrite_s || __CRT_HAVE_fwrite_unlocked || __CRT_HAVE__fwrite_nolock || __CRT_HAVE__IO_fwrite) && __LOCAL_program_invocation_short_name */
#undef __local_error_defined
#endif /* __NO_STDSTREAMS || (!__CRT_HAVE_exit && !__CRT_HAVE_quick_exit && !__CRT_HAVE__exit && !__CRT_HAVE__Exit) || (!__CRT_HAVE_fprintf && !__CRT_HAVE__IO_fprintf && !__CRT_HAVE_fprintf_s && !__CRT_HAVE_fprintf_unlocked && !__CRT_HAVE_vfprintf && !__CRT_HAVE_vfprintf_s && !__CRT_HAVE__IO_vfprintf && !__CRT_HAVE_vfprintf_unlocked && !__CRT_HAVE_file_printer && !__CRT_HAVE_file_printer_unlocked && !__CRT_HAVE_fwrite && !__CRT_HAVE_fwrite_s && !__CRT_HAVE_fputc && !__CRT_HAVE_putc && !__CRT_HAVE__IO_putc && !__CRT_HAVE_fputc_unlocked && !__CRT_HAVE_putc_unlocked && (!__CRT_DOS || !__CRT_HAVE__flsbuf) && !__CRT_HAVE_fwrite_unlocked && !__CRT_HAVE__fwrite_nolock && !__CRT_HAVE__IO_fwrite) || (!__CRT_HAVE_vfprintf && !__CRT_HAVE_vfprintf_s && !__CRT_HAVE__IO_vfprintf && !__CRT_HAVE_vfprintf_unlocked && !__CRT_HAVE_file_printer && !__CRT_HAVE_file_printer_unlocked && !__CRT_HAVE_fwrite && !__CRT_HAVE_fwrite_s && !__CRT_HAVE_fputc && !__CRT_HAVE_putc && !__CRT_HAVE__IO_putc && !__CRT_HAVE_fputc_unlocked && !__CRT_HAVE_putc_unlocked && (!__CRT_DOS || !__CRT_HAVE__flsbuf) && !__CRT_HAVE_fwrite_unlocked && !__CRT_HAVE__fwrite_nolock && !__CRT_HAVE__IO_fwrite) || (!__CRT_HAVE_fputc && !__CRT_HAVE_putc && !__CRT_HAVE__IO_putc && !__CRT_HAVE_fputc_unlocked && !__CRT_HAVE_putc_unlocked && (!__CRT_DOS || !__CRT_HAVE__flsbuf) && !__CRT_HAVE_fwrite && !__CRT_HAVE_fwrite_s && !__CRT_HAVE_fwrite_unlocked && !__CRT_HAVE__fwrite_nolock && !__CRT_HAVE__IO_fwrite) || !__LOCAL_program_invocation_short_name */
#endif /* !__local_error_defined */
