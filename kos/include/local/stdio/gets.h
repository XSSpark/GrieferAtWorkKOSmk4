/* HASH 0x1f952c47 */
/* Copyright (c) 2019 Griefer@Work                                            *
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
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_gets_defined
#include <__crt.h>
#if !defined(__NO_STDSTREAMS) && (defined(__CRT_HAVE_fgets) || defined(__CRT_HAVE_fgets_unlocked))
#define __local_gets_defined 1
#include <kos/anno.h>
#include <local/stdstreams.h>

#include <hybrid/typecore.h>
/* Dependency: "fgets" */
#ifndef ____localdep_fgets_defined
#define ____localdep_fgets_defined 1
#if defined(__CRT_HAVE_fgets_unlocked) && (defined(__USE_STDIO_UNLOCKED))
/* Read up to `BUFSIZE - 1' bytes of data from `STREAM', storing them into `BUF'
 * stopped when the buffer is full or a line-feed was read (in this case, the
 * line-feed is also written to `BUF')
 * Afterwards, append a trailing NUL-character and re-return `BUF', or return
 * `NULL' if an error occurred. */
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 3)),char *,,__localdep_fgets,(char *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgets_unlocked,(__buf,__bufsize,__stream)) __THROWS(...)
#elif defined(__CRT_HAVE_fgets)
/* Read up to `BUFSIZE - 1' bytes of data from `STREAM', storing them into `BUF'
 * stopped when the buffer is full or a line-feed was read (in this case, the
 * line-feed is also written to `BUF')
 * Afterwards, append a trailing NUL-character and re-return `BUF', or return
 * `NULL' if an error occurred. */
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 3)),char *,,__localdep_fgets,(char *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgets,(__buf,__bufsize,__stream)) __THROWS(...)
#elif defined(__CRT_HAVE_fgets_unlocked)
/* Read up to `BUFSIZE - 1' bytes of data from `STREAM', storing them into `BUF'
 * stopped when the buffer is full or a line-feed was read (in this case, the
 * line-feed is also written to `BUF')
 * Afterwards, append a trailing NUL-character and re-return `BUF', or return
 * `NULL' if an error occurred. */
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 3)),char *,,__localdep_fgets,(char *__restrict __buf, __STDC_INT_AS_SIZE_T __bufsize, __FILE *__restrict __stream),fgets_unlocked,(__buf,__bufsize,__stream)) __THROWS(...)
#else /* LIBC: fgets */
#undef ____localdep_fgets_defined
#endif /* fgets... */
#endif /* !____localdep_fgets_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(gets) __ATTR_WUNUSED __ATTR_DEPRECATED("No buffer size checks (use `fgets' instead)") __ATTR_NONNULL((1)) char *
(__LIBCCALL __LIBC_LOCAL_NAME(gets))(char *__restrict __buf) __THROWS(...) {
#line 842 "kos/src/libc/magic/stdio.c"
	return __localdep_fgets(__buf, __INT_MAX__, __LOCAL_stdin);
}
__NAMESPACE_LOCAL_END
#endif /* !defined(__NO_STDSTREAMS) && (defined(__CRT_HAVE_fgets) || defined(__CRT_HAVE_fgets_unlocked)) */
#endif /* !__local_gets_defined */
