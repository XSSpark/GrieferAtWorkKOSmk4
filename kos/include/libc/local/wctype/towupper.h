/* HASH CRC-32:0x90e68b4a */
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
#ifndef __local_towupper_defined
#define __local_towupper_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_btowc_defined
#define __local___localdep_btowc_defined
#ifdef __CRT_HAVE_btowc
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,__WINT_TYPE__,__NOTHROW,__localdep_btowc,(int __ch),btowc,(__ch))
#else /* __CRT_HAVE_btowc */
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/btowc.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_btowc __LIBC_LOCAL_NAME(btowc)
#endif /* !__CRT_HAVE_btowc */
#endif /* !__local___localdep_btowc_defined */
#ifndef __local___localdep_toupper_defined
#define __local___localdep_toupper_defined
__NAMESPACE_LOCAL_END
#include <bits/crt/ctype.h>
__NAMESPACE_LOCAL_BEGIN
#if defined(__crt_toupper) && defined(__CRT_HAVE_toupper)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_toupper,(int __ch),toupper,{ return __crt_toupper(__ch); })
#elif defined(__crt_toupper)
__LOCAL __ATTR_CONST __ATTR_WUNUSED int __NOTHROW(__LIBCCALL __localdep_toupper)(int __ch) { return __crt_toupper(__ch); }
#elif __has_builtin(__builtin_toupper) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_toupper)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_toupper,(int __ch),toupper,{ return __builtin_toupper(__ch); })
#elif defined(__CRT_HAVE_toupper)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_toupper,(int __ch),toupper,(__ch))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/ctype/toupper.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_toupper __LIBC_LOCAL_NAME(toupper)
#endif /* !... */
#endif /* !__local___localdep_toupper_defined */
#ifndef __local___localdep_wctob_defined
#define __local___localdep_wctob_defined
#ifdef __CRT_HAVE_wctob
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_wctob,(__WINT_TYPE__ __ch),wctob,(__ch))
#else /* __CRT_HAVE_wctob */
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wctob.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wctob __LIBC_LOCAL_NAME(wctob)
#endif /* !__CRT_HAVE_wctob */
#endif /* !__local___localdep_wctob_defined */
__NAMESPACE_LOCAL_END
#include <bits/crt/wctype.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(towupper) __ATTR_CONST __ATTR_WUNUSED __WINT_TYPE__
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(towupper))(__WINT_TYPE__ __wc) {
#ifdef __crt_towupper
	return __crt_towupper(__wc);
#else /* __crt_towupper */
	return (__NAMESPACE_LOCAL_SYM __localdep_btowc)((__NAMESPACE_LOCAL_SYM __localdep_toupper)((__NAMESPACE_LOCAL_SYM __localdep_wctob)(__wc)));
#endif /* !__crt_towupper */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_towupper_defined
#define __local___localdep_towupper_defined
#define __localdep_towupper __LIBC_LOCAL_NAME(towupper)
#endif /* !__local___localdep_towupper_defined */
#endif /* !__local_towupper_defined */
