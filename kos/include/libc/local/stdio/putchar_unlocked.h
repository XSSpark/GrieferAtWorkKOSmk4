/* HASH CRC-32:0x6fb53b99 */
/* Copyright (c) 2019-2025 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2025 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_putchar_unlocked_defined
#define __local_putchar_unlocked_defined
#include <__crt.h>
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stdout) && (defined(__CRT_HAVE_putc_unlocked) || defined(__CRT_HAVE_fputc_unlocked) || defined(__CRT_HAVE__putc_nolock) || defined(__CRT_HAVE__fputc_nolock) || (defined(__CRT_HAVE_putc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__flsbuf) && !defined(__CRT_HAVE___swbuf)))) || (defined(__CRT_HAVE_fputc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__flsbuf) && !defined(__CRT_HAVE___swbuf)))) || (defined(__CRT_HAVE__IO_putc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__flsbuf) && !defined(__CRT_HAVE___swbuf)))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_fputc_unlocked_defined
#define __local___localdep_fputc_unlocked_defined
#if __has_builtin(__builtin_fputc_unlocked) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_fputc_unlocked)
__CEIREDIRECT(__ATTR_INOUT(2),int,__NOTHROW_CB_NCX,__localdep_fputc_unlocked,(int __ch, __FILE *__restrict __stream),fputc_unlocked,{ return __builtin_fputc_unlocked(__ch, __stream); })
#elif defined(__CRT_HAVE_putc_unlocked)
__CREDIRECT(__ATTR_INOUT(2),int,__NOTHROW_CB_NCX,__localdep_fputc_unlocked,(int __ch, __FILE *__restrict __stream),putc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE_fputc_unlocked)
__CREDIRECT(__ATTR_INOUT(2),int,__NOTHROW_CB_NCX,__localdep_fputc_unlocked,(int __ch, __FILE *__restrict __stream),fputc_unlocked,(__ch,__stream))
#elif defined(__CRT_HAVE__putc_nolock)
__CREDIRECT(__ATTR_INOUT(2),int,__NOTHROW_CB_NCX,__localdep_fputc_unlocked,(int __ch, __FILE *__restrict __stream),_putc_nolock,(__ch,__stream))
#elif defined(__CRT_HAVE__fputc_nolock)
__CREDIRECT(__ATTR_INOUT(2),int,__NOTHROW_CB_NCX,__localdep_fputc_unlocked,(int __ch, __FILE *__restrict __stream),_fputc_nolock,(__ch,__stream))
#elif defined(__CRT_HAVE_putc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__flsbuf) && !defined(__CRT_HAVE___swbuf)))
__CREDIRECT(__ATTR_INOUT(2),int,__NOTHROW_CB_NCX,__localdep_fputc_unlocked,(int __ch, __FILE *__restrict __stream),putc,(__ch,__stream))
#elif defined(__CRT_HAVE_fputc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__flsbuf) && !defined(__CRT_HAVE___swbuf)))
__CREDIRECT(__ATTR_INOUT(2),int,__NOTHROW_CB_NCX,__localdep_fputc_unlocked,(int __ch, __FILE *__restrict __stream),fputc,(__ch,__stream))
#elif defined(__CRT_HAVE__IO_putc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__flsbuf) && !defined(__CRT_HAVE___swbuf)))
__CREDIRECT(__ATTR_INOUT(2),int,__NOTHROW_CB_NCX,__localdep_fputc_unlocked,(int __ch, __FILE *__restrict __stream),_IO_putc,(__ch,__stream))
#elif (defined(__CRT_DOS) && (defined(__CRT_HAVE__flsbuf) || defined(__CRT_HAVE___swbuf))) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock)
__NAMESPACE_LOCAL_END
#include <libc/local/stdio/fputc_unlocked.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_fputc_unlocked __LIBC_LOCAL_NAME(fputc_unlocked)
#else /* ... */
#undef __local___localdep_fputc_unlocked_defined
#endif /* !... */
#endif /* !__local___localdep_fputc_unlocked_defined */
__LOCAL_LIBC(putchar_unlocked) int
__NOTHROW_CB_NCX(__LIBCCALL __LIBC_LOCAL_NAME(putchar_unlocked))(int __ch) {
	return (__NAMESPACE_LOCAL_SYM __localdep_fputc_unlocked)(__ch, __LOCAL_stdout);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_putchar_unlocked_defined
#define __local___localdep_putchar_unlocked_defined
#define __localdep_putchar_unlocked __LIBC_LOCAL_NAME(putchar_unlocked)
#endif /* !__local___localdep_putchar_unlocked_defined */
#else /* __LOCAL_stdout && (__CRT_HAVE_putc_unlocked || __CRT_HAVE_fputc_unlocked || __CRT_HAVE__putc_nolock || __CRT_HAVE__fputc_nolock || (__CRT_HAVE_putc && (!__CRT_DOS || (!__CRT_HAVE__flsbuf && !__CRT_HAVE___swbuf))) || (__CRT_HAVE_fputc && (!__CRT_DOS || (!__CRT_HAVE__flsbuf && !__CRT_HAVE___swbuf))) || (__CRT_HAVE__IO_putc && (!__CRT_DOS || (!__CRT_HAVE__flsbuf && !__CRT_HAVE___swbuf))) || (__CRT_DOS && (__CRT_HAVE__flsbuf || __CRT_HAVE___swbuf)) || __CRT_HAVE_fwrite || __CRT_HAVE__IO_fwrite || __CRT_HAVE_fwrite_s || __CRT_HAVE_fwrite_unlocked || __CRT_HAVE__fwrite_nolock) */
#undef __local_putchar_unlocked_defined
#endif /* !__LOCAL_stdout || (!__CRT_HAVE_putc_unlocked && !__CRT_HAVE_fputc_unlocked && !__CRT_HAVE__putc_nolock && !__CRT_HAVE__fputc_nolock && !__CRT_HAVE_putc && !__CRT_HAVE_fputc && !__CRT_HAVE__IO_putc && (!__CRT_DOS || (!__CRT_HAVE__flsbuf && !__CRT_HAVE___swbuf)) && !__CRT_HAVE_fwrite && !__CRT_HAVE__IO_fwrite && !__CRT_HAVE_fwrite_s && !__CRT_HAVE_fwrite_unlocked && !__CRT_HAVE__fwrite_nolock) */
#endif /* !__local_putchar_unlocked_defined */
