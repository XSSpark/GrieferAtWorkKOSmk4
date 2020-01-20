/* HASH CRC-32:0x8770319d */
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
#ifndef __local_vstrdupf_defined
#if ((defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE_format_aprintf_pack)) && (defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_format_aprintf_printer)) && (defined(__CRT_HAVE_free) || defined(__CRT_HAVE_cfree))) || defined(__CRT_HAVE_vasprintf)
#define __local_vstrdupf_defined 1
/* Dependency: "vasprintf" from "stdio" */
#ifndef ____localdep_vasprintf_defined
#define ____localdep_vasprintf_defined 1
#ifdef __CRT_HAVE_vasprintf
/* Print the given `FORMAT' into a newly allocated, heap-allocated string which is then stored in `*PSTR' */
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)) __ATTR_LIBC_PRINTF(2, 3),__STDC_INT_AS_SSIZE_T,__NOTHROW_NCX,__localdep_vasprintf,(char **__restrict __pstr, char const *__restrict __format, __builtin_va_list __args),vasprintf,(__pstr,__format,__args))
#elif (defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE_format_aprintf_pack)) && (defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_format_aprintf_printer)) && (defined(__CRT_HAVE_free) || defined(__CRT_HAVE_cfree))
#include <local/stdio/vasprintf.h>
/* Print the given `FORMAT' into a newly allocated, heap-allocated string which is then stored in `*PSTR' */
#define __localdep_vasprintf (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(vasprintf))
#else /* CUSTOM: vasprintf */
#undef ____localdep_vasprintf_defined
#endif /* vasprintf... */
#endif /* !____localdep_vasprintf_defined */

__NAMESPACE_LOCAL_BEGIN
/* Print the given `FORMAT' into a newly allocated, heap-allocated string */
__LOCAL_LIBC(vstrdupf) __ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_LIBC_PRINTF(1, 0) char *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(vstrdupf))(char const *__restrict __format,
                                                      __builtin_va_list __args) {
#line 4035 "kos/src/libc/magic/string.c"
	char *__result;
	return __localdep_vasprintf(&__result, __format, __args) >= 0 ? __result : 0;
}
__NAMESPACE_LOCAL_END
#endif /* ((__CRT_HAVE_realloc || __CRT_HAVE_format_aprintf_pack) && (__CRT_HAVE_realloc || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_format_aprintf_printer) && (__CRT_HAVE_free || __CRT_HAVE_cfree)) || __CRT_HAVE_vasprintf */
#endif /* !__local_vstrdupf_defined */
