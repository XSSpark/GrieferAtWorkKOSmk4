/* HASH CRC-32:0x4fb49aa3 */
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
#ifndef __local__vfwprintf_l_defined
#if defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_vfwprintf)
#define __local__vfwprintf_l_defined 1
#include <__crt.h>
#include <kos/anno.h>
/* Dependency: "vfwprintf" from "wchar" */
#ifndef ____localdep_vfwprintf_defined
#define ____localdep_vfwprintf_defined 1
#ifdef __std___localdep_vfwprintf_defined
__NAMESPACE_STD_USING(__localdep_vfwprintf)
#elif defined(__CRT_HAVE_vfwprintf)
__CREDIRECT(__ATTR_LIBC_WPRINTF(2, 0) __ATTR_NONNULL((1, 2)),__STDC_INT_AS_SIZE_T,__THROWING,__localdep_vfwprintf,(__FILE *__restrict __stream, __WCHAR_TYPE__ const *__restrict __format, __builtin_va_list __args),vfwprintf,(__stream,__format,__args))
#elif defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked)
#include <local/wchar/vfwprintf.h>
#define __localdep_vfwprintf (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vfwprintf))
#else /* CUSTOM: vfwprintf */
#undef ____localdep_vfwprintf_defined
#endif /* vfwprintf... */
#endif /* !____localdep_vfwprintf_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_vfwprintf_l) __ATTR_NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T
(__LIBCCALL __LIBC_LOCAL_NAME(_vfwprintf_l))(__FILE *__stream,
                                             __WCHAR_TYPE__ const *__format,
                                             __locale_t __locale,
                                             __builtin_va_list __args) __THROWS(...) {
#line 1990 "kos/src/libc/magic/wchar.c"
	(void)__locale;
	return __localdep_vfwprintf(__stream, __format, __args);
}
__NAMESPACE_LOCAL_END
#endif /* __CRT_HAVE_fputwc || __CRT_HAVE_putwc || __CRT_HAVE_file_wprinter || __CRT_HAVE_file_wprinter_unlocked || __CRT_HAVE_vfwprintf */
#endif /* !__local__vfwprintf_l_defined */
