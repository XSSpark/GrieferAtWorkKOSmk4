/* HASH CRC-32:0x6c2e47b2 */
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
#ifndef __local_isdigit32_l_defined
#define __local_isdigit32_l_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_isdigit32_defined
#define __local___localdep_isdigit32_defined
__NAMESPACE_LOCAL_END
#include <bits/crt/wctype.h>
__NAMESPACE_LOCAL_BEGIN
#if defined(__crt_iswdigit) && defined(__CRT_HAVE_iswdigit) && __SIZEOF_WCHAR_T__ == 4
__COMPILER_CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__LIBKCALL,__localdep_isdigit32,(__WINT32_TYPE__ __wc),iswdigit,{ return __crt_iswdigit(__wc); })
#elif defined(__crt_iswdigit) && __SIZEOF_WCHAR_T__ == 4
__LOCAL __ATTR_CONST __ATTR_WUNUSED int __NOTHROW(__LIBKCALL __localdep_isdigit32)(__WINT32_TYPE__ __wc) { return __crt_iswdigit(__wc); }
#elif __has_builtin(__builtin_iswdigit) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_iswdigit) && __SIZEOF_WCHAR_T__ == 4
__COMPILER_CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__LIBKCALL,__localdep_isdigit32,(__WINT32_TYPE__ __wc),iswdigit,{ return __builtin_iswdigit(__wc); })
#elif defined(__CRT_HAVE_iswdigit) && __SIZEOF_WCHAR_T__ == 4 && defined(__LIBCCALL_IS_LIBKCALL)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isdigit32,(__WINT32_TYPE__ __wc),iswdigit,(__wc))
#elif defined(__CRT_HAVE_KOS$iswdigit)
__CREDIRECT_KOS(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isdigit32,(__WINT32_TYPE__ __wc),iswdigit,(__wc))
#elif __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <libc/local/wctype/iswdigit.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_isdigit32 __NAMESPACE_LOCAL_TYPEHAX(int(__LIBKCALL*)(__WINT32_TYPE__),int(__LIBKCALL&)(__WINT32_TYPE__),iswdigit)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.wctype/isdigit32.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_isdigit32 __LIBC_LOCAL_NAME(isdigit32)
#endif /* !... */
#endif /* !__local___localdep_isdigit32_defined */
__LOCAL_LIBC(isdigit32_l) __ATTR_PURE __ATTR_WUNUSED int
__NOTHROW_NCX(__LIBKCALL __LIBC_LOCAL_NAME(isdigit32_l))(__WINT32_TYPE__ __ch, __locale_t __locale) {
	__COMPILER_IMPURE();
	(void)__locale;
	return (__NAMESPACE_LOCAL_SYM __localdep_isdigit32)(__ch);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_isdigit32_l_defined
#define __local___localdep_isdigit32_l_defined
#define __localdep_isdigit32_l __LIBC_LOCAL_NAME(isdigit32_l)
#endif /* !__local___localdep_isdigit32_l_defined */
#endif /* !__local_isdigit32_l_defined */
