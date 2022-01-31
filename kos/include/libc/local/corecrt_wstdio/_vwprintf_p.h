/* HASH CRC-32:0xc5a10dd5 */
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
#ifndef __local__vwprintf_p_defined
#define __local__vwprintf_p_defined
#include <__crt.h>
#include <libc/template/stdstreams.h>
#include <features.h>
#if defined(__CRT_HAVE__vwprintf_p_l) || (defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc)))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__vwprintf_p_l_defined
#define __local___localdep__vwprintf_p_l_defined
#ifdef __CRT_HAVE__vwprintf_p_l
__CREDIRECT(__ATTR_NONNULL((1)),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep__vwprintf_p_l,(__WCHAR_TYPE__ const *__format, __locale_t __locale, __builtin_va_list __args),_vwprintf_p_l,(__format,__locale,__args))
#elif defined(__LOCAL_stdout) && (defined(__CRT_HAVE__vfwprintf_p_l) || defined(__CRT_HAVE___stdio_common_vfwprintf_p) || defined(__CRT_HAVE_vfwprintf) || defined(__CRT_HAVE_file_wprinter) || defined(__CRT_HAVE_file_wprinter_unlocked) || defined(__CRT_HAVE_fputwc) || defined(__CRT_HAVE_putwc))
__NAMESPACE_LOCAL_END
#include <libc/local/corecrt_wstdio/_vwprintf_p_l.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep__vwprintf_p_l __LIBC_LOCAL_NAME(_vwprintf_p_l)
#else /* ... */
#undef __local___localdep__vwprintf_p_l_defined
#endif /* !... */
#endif /* !__local___localdep__vwprintf_p_l_defined */
__LOCAL_LIBC(_vwprintf_p) __ATTR_NONNULL((1)) __STDC_INT_AS_SSIZE_T
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_vwprintf_p))(__WCHAR_TYPE__ const *__format, __builtin_va_list __args) {
	return (__NAMESPACE_LOCAL_SYM __localdep__vwprintf_p_l)(__format, __NULLPTR, __args);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__vwprintf_p_defined
#define __local___localdep__vwprintf_p_defined
#define __localdep__vwprintf_p __LIBC_LOCAL_NAME(_vwprintf_p)
#endif /* !__local___localdep__vwprintf_p_defined */
#else /* __CRT_HAVE__vwprintf_p_l || (__LOCAL_stdout && (__CRT_HAVE__vfwprintf_p_l || __CRT_HAVE___stdio_common_vfwprintf_p || __CRT_HAVE_vfwprintf || __CRT_HAVE_file_wprinter || __CRT_HAVE_file_wprinter_unlocked || __CRT_HAVE_fputwc || __CRT_HAVE_putwc)) */
#undef __local__vwprintf_p_defined
#endif /* !__CRT_HAVE__vwprintf_p_l && (!__LOCAL_stdout || (!__CRT_HAVE__vfwprintf_p_l && !__CRT_HAVE___stdio_common_vfwprintf_p && !__CRT_HAVE_vfwprintf && !__CRT_HAVE_file_wprinter && !__CRT_HAVE_file_wprinter_unlocked && !__CRT_HAVE_fputwc && !__CRT_HAVE_putwc)) */
#endif /* !__local__vwprintf_p_defined */
