/* HASH CRC-32:0x647350ab */
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
#ifndef __local_c16rlen_defined
#define __local_c16rlen_defined 1
#include <__crt.h>
#include <bits/mbstate.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: uchar_mbrtoc16 from uchar */
#ifndef __local___localdep_uchar_mbrtoc16_defined
#define __local___localdep_uchar_mbrtoc16_defined 1
#if defined(__CRT_HAVE_mbrtowc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_uchar_mbrtoc16,(__CHAR16_TYPE__ *__pwc, char const *__restrict __str, __SIZE_TYPE__ __maxlen, __mbstate_t *__mbs),mbrtowc,(__pwc,__str,__maxlen,__mbs))
#elif defined(__CRT_HAVE_DOS$mbrtowc)
__CREDIRECT_DOS(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_uchar_mbrtoc16,(__CHAR16_TYPE__ *__pwc, char const *__restrict __str, __SIZE_TYPE__ __maxlen, __mbstate_t *__mbs),mbrtowc,(__pwc,__str,__maxlen,__mbs))
#elif defined(__CRT_HAVE___mbrtowc) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_uchar_mbrtoc16,(__CHAR16_TYPE__ *__pwc, char const *__restrict __str, __SIZE_TYPE__ __maxlen, __mbstate_t *__mbs),__mbrtowc,(__pwc,__str,__maxlen,__mbs))
#elif defined(__CRT_HAVE_DOS$__mbrtowc)
__CREDIRECT_DOS(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_uchar_mbrtoc16,(__CHAR16_TYPE__ *__pwc, char const *__restrict __str, __SIZE_TYPE__ __maxlen, __mbstate_t *__mbs),__mbrtowc,(__pwc,__str,__maxlen,__mbs))
#elif defined(__CRT_HAVE_mbrtoc16) && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_uchar_mbrtoc16,(__CHAR16_TYPE__ *__pwc, char const *__restrict __str, __SIZE_TYPE__ __maxlen, __mbstate_t *__mbs),mbrtoc16,(__pwc,__str,__maxlen,__mbs))
#elif defined(__CRT_HAVE_DOS$mbrtoc16)
__CREDIRECT_DOS(,__SIZE_TYPE__,__NOTHROW_NCX,__localdep_uchar_mbrtoc16,(__CHAR16_TYPE__ *__pwc, char const *__restrict __str, __SIZE_TYPE__ __maxlen, __mbstate_t *__mbs),mbrtoc16,(__pwc,__str,__maxlen,__mbs))
#elif __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <local/wchar/mbrtowc.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_uchar_mbrtoc16 (*(__SIZE_TYPE__(__LIBDCALL *)(__CHAR16_TYPE__ *, char const *__restrict, __SIZE_TYPE__, __mbstate_t *))&__LIBC_LOCAL_NAME(mbrtowc))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/uchar/uchar_mbrtoc16.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_uchar_mbrtoc16 __LIBC_LOCAL_NAME(uchar_mbrtoc16)
#endif /* !... */
#endif /* !__local___localdep_uchar_mbrtoc16_defined */
__LOCAL_LIBC(c16rlen) __ATTR_WUNUSED __SIZE_TYPE__
__NOTHROW_NCX(__LIBDCALL __LIBC_LOCAL_NAME(c16rlen))(char const *__restrict __str, __SIZE_TYPE__ __maxlen, __mbstate_t *__mbs) {
	__CHAR16_TYPE__ __wc;
	return __localdep_uchar_mbrtoc16(&__wc, __str, __maxlen, __mbs);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c16rlen_defined
#define __local___localdep_c16rlen_defined 1
#define __localdep_c16rlen __LIBC_LOCAL_NAME(c16rlen)
#endif /* !__local___localdep_c16rlen_defined */
#endif /* !__local_c16rlen_defined */
