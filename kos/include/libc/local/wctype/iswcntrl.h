/* HASH CRC-32:0x386ea60f */
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
#ifndef __local_iswcntrl_defined
#define __local_iswcntrl_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_iscntrl_defined
#define __local___localdep_iscntrl_defined
__NAMESPACE_LOCAL_END
#include <bits/crt/ctype.h>
__NAMESPACE_LOCAL_BEGIN
#if defined(__crt_iscntrl) && defined(__CRT_HAVE_iscntrl)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iscntrl,(int __ch),iscntrl,{ return __crt_iscntrl(__ch); })
#elif defined(__crt_iscntrl)
__LOCAL __ATTR_CONST __ATTR_WUNUSED int __NOTHROW(__LIBCCALL __localdep_iscntrl)(int __ch) { return __crt_iscntrl(__ch); }
#elif __has_builtin(__builtin_iscntrl) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_iscntrl)
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iscntrl,(int __ch),iscntrl,{ return __builtin_iscntrl(__ch); })
#elif defined(__CRT_HAVE_iscntrl)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iscntrl,(int __ch),iscntrl,(__ch))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/ctype/iscntrl.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_iscntrl __LIBC_LOCAL_NAME(iscntrl)
#endif /* !... */
#endif /* !__local___localdep_iscntrl_defined */
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
__LOCAL_LIBC(iswcntrl) __ATTR_CONST __ATTR_WUNUSED int
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(iswcntrl))(__WINT_TYPE__ __wc) {
#ifdef __crt_iswcntrl
	return __crt_iswcntrl(__wc);
#else /* __crt_iswcntrl */
	return (__NAMESPACE_LOCAL_SYM __localdep_iscntrl)((__NAMESPACE_LOCAL_SYM __localdep_wctob)(__wc));
#endif /* !__crt_iswcntrl */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_iswcntrl_defined
#define __local___localdep_iswcntrl_defined
#define __localdep_iswcntrl __LIBC_LOCAL_NAME(iswcntrl)
#endif /* !__local___localdep_iswcntrl_defined */
#endif /* !__local_iswcntrl_defined */
