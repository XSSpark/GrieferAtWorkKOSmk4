/* HASH CRC-32:0x70714bd4 */
/* Copyright (c) 2019-2024 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2024 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_wmemcasecmp_defined
#define __local_wmemcasecmp_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_towlower_defined
#define __local___localdep_towlower_defined
__NAMESPACE_LOCAL_END
#include <bits/crt/wctype.h>
__NAMESPACE_LOCAL_BEGIN
#if defined(__crt_towlower) && defined(__CRT_HAVE_towlower)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__WINT_TYPE__,__NOTHROW,__localdep_towlower,(__WINT_TYPE__ __wc),towlower,{ return __crt_towlower(__wc); })
#elif defined(__crt_towlower)
__LOCAL __ATTR_CONST __ATTR_WUNUSED __WINT_TYPE__ __NOTHROW(__LIBCCALL __localdep_towlower)(__WINT_TYPE__ __wc) { return __crt_towlower(__wc); }
#elif __has_builtin(__builtin_towlower) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_towlower)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__WINT_TYPE__,__NOTHROW,__localdep_towlower,(__WINT_TYPE__ __wc),towlower,{ return __builtin_towlower(__wc); })
#elif defined(__CRT_HAVE_towlower)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__WINT_TYPE__,__NOTHROW,__localdep_towlower,(__WINT_TYPE__ __wc),towlower,(__wc))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/wctype/towlower.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_towlower __LIBC_LOCAL_NAME(towlower)
#endif /* !... */
#endif /* !__local___localdep_towlower_defined */
__LOCAL_LIBC(wmemcasecmp) __ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wmemcasecmp))(void const *__s1, void const *__s2, __SIZE_TYPE__ __num_chars) {
	__WCHAR_TYPE__ const *__p1 = (__WCHAR_TYPE__ const *)__s1;
	__WCHAR_TYPE__ const *__p2 = (__WCHAR_TYPE__ const *)__s2;
	__WCHAR_TYPE__ __v1, __v2;
	__v1 = 0;
	__v2 = 0;
	while (__num_chars--) {
		__v1 = *__p1++;
		__v2 = *__p2++;
		if (__v1 != __v2) {
			__v1 = (__WCHAR_TYPE__)(__NAMESPACE_LOCAL_SYM __localdep_towlower)(__v1);
			__v2 = (__WCHAR_TYPE__)(__NAMESPACE_LOCAL_SYM __localdep_towlower)(__v2);
			if (__v1 != __v2)
				break;
		}
	}
#if __SIZEOF_WCHAR_T__ < __SIZEOF_INT__
	return (int)__v1 - (int)__v2;
#else /* __SIZEOF_WCHAR_T__ < __SIZEOF_INT__ */
	if (__v1 < __v2)
		return -1;
	if (__v1 > __v2)
		return 1;
	return 0;
#endif /* __SIZEOF_WCHAR_T__ >= __SIZEOF_INT__ */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wmemcasecmp_defined
#define __local___localdep_wmemcasecmp_defined
#define __localdep_wmemcasecmp __LIBC_LOCAL_NAME(wmemcasecmp)
#endif /* !__local___localdep_wmemcasecmp_defined */
#endif /* !__local_wmemcasecmp_defined */
