/* HASH CRC-32:0x6631f27e */
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
#ifndef __local_fgetc16s_defined
#if (defined(__CRT_HAVE_fgetwc) || defined(__CRT_HAVE_getwc)) && (defined(__CRT_HAVE_ungetwc) || defined(__CRT_HAVE_ungetwc_unlocked)) && (defined(__CRT_HAVE_ferror) || defined(__CRT_HAVE_ferror_unlocked) || defined(__CRT_HAVE__IO_ferror))
#define __local_fgetc16s_defined 1
#include <kos/anno.h>
#include <parts/errno.h>
/* Dependency: "fgetwc" */
#ifndef ____localdep_fgetc16_defined
#define ____localdep_fgetc16_defined 1
#if defined(__CRT_HAVE_fgetwc) && (__SIZEOF_WCHAR_T__ == 2)
__CREDIRECT(__ATTR_NONNULL((1)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_fgetc16,(__FILE *__restrict __stream),fgetwc,(__stream))
#elif defined(__CRT_HAVE_getwc) && (__SIZEOF_WCHAR_T__ == 2)
__CREDIRECT(__ATTR_NONNULL((1)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_fgetc16,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_DOS$getwc)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_fgetc16,(__FILE *__restrict __stream),getwc,(__stream))
#elif defined(__CRT_HAVE_DOS$fgetwc)
__CREDIRECT_DOS(__ATTR_NONNULL((1)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_fgetc16,(__FILE *__restrict __stream),fgetwc,(__stream))
#else /* LIBC: fgetc16 */
#undef ____localdep_fgetc16_defined
#endif /* fgetc16... */
#endif /* !____localdep_fgetc16_defined */

/* Dependency: "ferror" */
#ifndef ____localdep_ferror_defined
#define ____localdep_ferror_defined 1
#if defined(__CRT_HAVE_ferror_unlocked) && defined(__USE_STDIO_UNLOCKED)
/* Check if an I/O error occurred in `STREAM' */
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_NCX,__localdep_ferror,(__FILE __KOS_FIXED_CONST *__restrict __stream),ferror_unlocked,(__stream))
#elif defined(__CRT_HAVE_ferror)
/* Check if an I/O error occurred in `STREAM' */
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_NCX,__localdep_ferror,(__FILE __KOS_FIXED_CONST *__restrict __stream),ferror,(__stream))
#elif defined(__CRT_HAVE_ferror_unlocked)
/* Check if an I/O error occurred in `STREAM' */
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_NCX,__localdep_ferror,(__FILE __KOS_FIXED_CONST *__restrict __stream),ferror_unlocked,(__stream))
#elif defined(__CRT_HAVE__IO_ferror)
/* Check if an I/O error occurred in `STREAM' */
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)),int,__NOTHROW_NCX,__localdep_ferror,(__FILE __KOS_FIXED_CONST *__restrict __stream),_IO_ferror,(__stream))
#else /* LIBC: ferror */
#undef ____localdep_ferror_defined
#endif /* ferror... */
#endif /* !____localdep_ferror_defined */

/* Dependency: "ungetwc" */
#ifndef ____localdep_ungetc16_defined
#define ____localdep_ungetc16_defined 1
#if defined(__CRT_HAVE_ungetwc) && (__SIZEOF_WCHAR_T__ == 2)
__CREDIRECT(__ATTR_NONNULL((2)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_ungetc16,(__WINT_TYPE__ __wc, __FILE *__stream),ungetwc,(__wc,__stream))
#elif defined(__CRT_HAVE_ungetwc_unlocked) && defined(__USE_STDIO_UNLOCKED) && (__SIZEOF_WCHAR_T__ == 2)
__CREDIRECT(__ATTR_NONNULL((2)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_ungetc16,(__WINT_TYPE__ __wc, __FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$ungetwc_unlocked) && defined(__USE_STDIO_UNLOCKED)
__CREDIRECT_DOS(__ATTR_NONNULL((2)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_ungetc16,(__WINT_TYPE__ __wc, __FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_ungetwc_unlocked) && (__SIZEOF_WCHAR_T__ == 2)
__CREDIRECT(__ATTR_NONNULL((2)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_ungetc16,(__WINT_TYPE__ __wc, __FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$ungetwc_unlocked)
__CREDIRECT_DOS(__ATTR_NONNULL((2)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_ungetc16,(__WINT_TYPE__ __wc, __FILE *__stream),ungetwc_unlocked,(__wc,__stream))
#elif defined(__CRT_HAVE_DOS$ungetwc)
__CREDIRECT_DOS(__ATTR_NONNULL((2)),__WINT_TYPE__,__NOTHROW_NCX,__localdep_ungetc16,(__WINT_TYPE__ __wc, __FILE *__stream),ungetwc,(__wc,__stream))
#else /* LIBC: ungetc16 */
#undef ____localdep_ungetc16_defined
#endif /* ungetc16... */
#endif /* !____localdep_ungetc16_defined */

__NAMESPACE_LOCAL_BEGIN
#ifndef __WEOF
#if 2 == 4
#define __WEOF 0xffffffffu
#else /* __SIZEOF_WCHAR_T__ == 4 */
#define __WEOF (__CCAST(__WINT_TYPE__) 0xffff)
#endif /* __SIZEOF_WCHAR_T__ != 4 */
#endif /* !__WEOF */
__LOCAL_LIBC(fgetc16s) __ATTR_WUNUSED __ATTR_NONNULL((1, 3)) __CHAR16_TYPE__ *
(__LIBDCALL __LIBC_LOCAL_NAME(fgetc16s))(__CHAR16_TYPE__ *__restrict __buf,
                                         __STDC_INT_AS_SIZE_T __bufsize,
                                         __FILE *__restrict __stream) __THROWS(...) {
#line 535 "kos/src/libc/magic/wchar.c"
	__SIZE_TYPE__ __n;
	if __unlikely(!__buf || !__bufsize) {
		/* The buffer cannot be empty! */
#ifdef __ERANGE
		__libc_seterrno(__ERANGE);
#endif /* __ERANGE */
		return __NULLPTR;
	}
	for (__n = 0; __n < __bufsize - 1; ++__n) {
		__WINT_TYPE__ __ch = __localdep_fgetc16(__stream);
		if (__ch == __WEOF) {
			if (__n == 0 || __localdep_ferror(__stream))
				return __NULLPTR;
			break;
		}
		if (__ch == '\r') {
			/* Special handling to convert both `\r' and `\r\n' into `\n' */
			__buf[__n++] = '\n';
			__ch = __localdep_fgetc16(__stream);
			if (__ch == __WEOF) {
				if (__n == 0 || __localdep_ferror(__stream))
					return __NULLPTR;
				break;
			}
			if (__ch == '\r')
				continue;
			__localdep_ungetc16(__ch, __stream);
			break;
		}
		__buf[__n] = (__CHAR16_TYPE__)__ch;
		if (__ch == '\n')
			break;
	}
	__buf[__n] = '\0';
	return __buf;
}
__NAMESPACE_LOCAL_END
#endif /* (__CRT_HAVE_fgetwc || __CRT_HAVE_getwc) && (__CRT_HAVE_ungetwc || __CRT_HAVE_ungetwc_unlocked) && (__CRT_HAVE_ferror || __CRT_HAVE_ferror_unlocked || __CRT_HAVE__IO_ferror) */
#endif /* !__local_fgetc16s_defined */
