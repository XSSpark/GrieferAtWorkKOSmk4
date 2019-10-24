/* HASH CRC-32:0x3fd52852 */
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
#ifndef __local_wcstof_l_defined
#define __local_wcstof_l_defined 1
/* Dependency: "wcstof" from "wchar" */
#ifndef ____localdep_wcstof_defined
#define ____localdep_wcstof_defined 1
#ifdef __std___localdep_wcstof_defined
__NAMESPACE_STD_USING(__localdep_wcstof)
#elif defined(__CRT_HAVE_wcstof)
__CREDIRECT(__ATTR_PURE __ATTR_NONNULL((1)),float,__NOTHROW_NCX,__localdep_wcstof,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr),wcstof,(__nptr,__endptr))
#else /* LIBC: wcstof */
#include <local/wchar/wcstof.h>
#define __localdep_wcstof (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcstof))
#endif /* wcstof... */
#endif /* !____localdep_wcstof_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(wcstof_l) __ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)) float
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wcstof_l))(__WCHAR_TYPE__ const *__restrict __nptr,
                                                      __WCHAR_TYPE__ **__endptr,
                                                      __locale_t __locale) {
#line 1532 "kos/src/libc/magic/stdlib.c"
	(void)__locale;
	return __localdep_wcstof(__nptr, __endptr);
}
__NAMESPACE_LOCAL_END
#endif /* !__local_wcstof_l_defined */
