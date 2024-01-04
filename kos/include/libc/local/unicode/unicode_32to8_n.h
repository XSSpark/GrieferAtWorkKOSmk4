/* HASH CRC-32:0xdc2a6f5f */
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
#ifndef __local_unicode_32to8_n_defined
#define __local_unicode_32to8_n_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_unicode_writeutf8_n_defined
#define __local___localdep_unicode_writeutf8_n_defined
#ifdef __CRT_HAVE_unicode_writeutf8_n
__CREDIRECT(__ATTR_RETNONNULL __ATTR_OUTS(1, 3),char *,__NOTHROW_NCX,__localdep_unicode_writeutf8_n,(char *__restrict __dst, __CHAR32_TYPE__ __ch, __SIZE_TYPE__ __dst_maxbytes),unicode_writeutf8_n,(__dst,__ch,__dst_maxbytes))
#else /* __CRT_HAVE_unicode_writeutf8_n */
__NAMESPACE_LOCAL_END
#include <libc/local/unicode/unicode_writeutf8_n.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_unicode_writeutf8_n __LIBC_LOCAL_NAME(unicode_writeutf8_n)
#endif /* !__CRT_HAVE_unicode_writeutf8_n */
#endif /* !__local___localdep_unicode_writeutf8_n_defined */
__LOCAL_LIBC(unicode_32to8_n) __ATTR_RETNONNULL __ATTR_INS(3, 4) __ATTR_OUTS(1, 2) char *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(unicode_32to8_n))(char *__restrict __utf8_dst, __SIZE_TYPE__ __utf8_maxbytes, __CHAR32_TYPE__ const *__restrict __utf32_text, __SIZE_TYPE__ __utf32_dwords) {
	char *__utf8_bufend = __utf8_dst + __utf8_maxbytes;
	while (__utf32_dwords-- && __utf8_dst < __utf8_bufend) {
		__utf8_dst = (__NAMESPACE_LOCAL_SYM __localdep_unicode_writeutf8_n)(__utf8_dst, *__utf32_text++,
		                               (__SIZE_TYPE__)(__utf8_bufend - __utf8_dst));
	}
	return __utf8_dst;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_unicode_32to8_n_defined
#define __local___localdep_unicode_32to8_n_defined
#define __localdep_unicode_32to8_n __LIBC_LOCAL_NAME(unicode_32to8_n)
#endif /* !__local___localdep_unicode_32to8_n_defined */
#endif /* !__local_unicode_32to8_n_defined */
