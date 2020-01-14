/* HASH CRC-32:0x38400e9f */
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
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local__strupr_s_l_defined
#define __local__strupr_s_l_defined 1
/* Dependency: "strnlen" from "string" */
#ifndef ____localdep_strnlen_defined
#define ____localdep_strnlen_defined 1
#if __has_builtin(__builtin_strnlen) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_strnlen)
/* Same as `strlen', but don't exceed `MAX_CHARS' characters (Same as `memlen[...](STR, '\0', MAX_CHARS)´) */
__EXTERNINLINE __ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)) __SIZE_TYPE__ __NOTHROW_NCX(__LIBCCALL __localdep_strnlen)(char const *__restrict __string, __SIZE_TYPE__ __maxlen) { return __builtin_strnlen(__string, __maxlen); }
#elif defined(__CRT_HAVE_strnlen)
/* Same as `strlen', but don't exceed `MAX_CHARS' characters (Same as `memlen[...](STR, '\0', MAX_CHARS)´) */
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_strnlen,(char const *__restrict __string, __SIZE_TYPE__ __maxlen),strnlen,(__string,__maxlen))
#else /* LIBC: strnlen */
#include <local/string/strnlen.h>
/* Same as `strlen', but don't exceed `MAX_CHARS' characters (Same as `memlen[...](STR, '\0', MAX_CHARS)´) */
#define __localdep_strnlen (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strnlen))
#endif /* strnlen... */
#endif /* !____localdep_strnlen_defined */

/* Dependency: "toupper_l" from "ctype" */
#ifndef ____localdep_toupper_l_defined
#define ____localdep_toupper_l_defined 1
#ifdef __CRT_HAVE_toupper_l
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED,int,__NOTHROW_NCX,__localdep_toupper_l,(int __ch, __locale_t __locale),toupper_l,(__ch,__locale))
#elif defined(__CRT_HAVE__toupper_l)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED,int,__NOTHROW_NCX,__localdep_toupper_l,(int __ch, __locale_t __locale),_toupper_l,(__ch,__locale))
#elif defined(__CRT_HAVE___toupper_l)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED,int,__NOTHROW_NCX,__localdep_toupper_l,(int __ch, __locale_t __locale),__toupper_l,(__ch,__locale))
#else /* LIBC: toupper_l */
#include <local/ctype/toupper_l.h>
#define __localdep_toupper_l (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(toupper_l))
#endif /* toupper_l... */
#endif /* !____localdep_toupper_l_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_strupr_s_l) __ATTR_LEAF __errno_t
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_strupr_s_l))(char *__buf,
                                                         __SIZE_TYPE__ __buflen,
                                                         __locale_t __locale) {
#line 5071 "kos/src/libc/magic/string.c"
	char *__iter, __ch;
	if (__buf == __NULLPTR)
		return __EINVAL;
	if (__localdep_strnlen(__buf, __buflen) >= __buflen)
		return __EINVAL;
	for (__iter = __buf; (__ch = *__iter) != '\0'; ++__iter)
		*__iter = __localdep_toupper_l(__ch, __locale);
	return 0;
}
__NAMESPACE_LOCAL_END
#endif /* !__local__strupr_s_l_defined */
