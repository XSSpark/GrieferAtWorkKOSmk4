/* HASH 0xca6aaf4a */
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
#ifndef __local_strtou64_l_defined
#define __local_strtou64_l_defined 1
/* Dependency: "strtou64" from "stdlib" */
#ifndef ____localdep_strtou64_defined
#define ____localdep_strtou64_defined 1
#if defined(__CRT_HAVE_strtou64)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINT64_TYPE__,__NOTHROW_NCX,__localdep_strtou64,(char const *__restrict __nptr, char **__endptr, int __base),strtou64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE__strtoui64)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINT64_TYPE__,__NOTHROW_NCX,__localdep_strtou64,(char const *__restrict __nptr, char **__endptr, int __base),_strtoui64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtoul) && (__SIZEOF_LONG__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINT64_TYPE__,__NOTHROW_NCX,__localdep_strtou64,(char const *__restrict __nptr, char **__endptr, int __base),strtoul,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtoull) && (__SIZEOF_LONG_LONG__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINT64_TYPE__,__NOTHROW_NCX,__localdep_strtou64,(char const *__restrict __nptr, char **__endptr, int __base),strtoull,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtouq) && (__SIZEOF_LONG_LONG__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINT64_TYPE__,__NOTHROW_NCX,__localdep_strtou64,(char const *__restrict __nptr, char **__endptr, int __base),strtouq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtoumax) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINT64_TYPE__,__NOTHROW_NCX,__localdep_strtou64,(char const *__restrict __nptr, char **__endptr, int __base),strtoumax,(__nptr,__endptr,__base))
#else /* LIBC: strtou64 */
#include <local/stdlib/strtou64.h>
#define __localdep_strtou64 (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strtou64))
#endif /* strtou64... */
#endif /* !____localdep_strtou64_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(strtou64_l) __ATTR_NONNULL((1)) __UINT64_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(strtou64_l))(char const *__restrict __nptr,
                                                        char **__endptr,
                                                        int __base,
                                                        __locale_t __locale) {
#line 2605 "kos/src/libc/magic/stdlib.c"
	(void)__locale;
	return __localdep_strtou64(__nptr, __endptr, __base);
}
__NAMESPACE_LOCAL_END
#endif /* !__local_strtou64_l_defined */
