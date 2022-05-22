/* HASH CRC-32:0x71e5a889 */
/* Copyright (c) 2019-2022 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2022 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_rawmemxlen_defined
#define __local_rawmemxlen_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_rawmemxchr_defined
#define __local___localdep_rawmemxchr_defined
#ifdef __CRT_HAVE_rawmemxchr
__CREDIRECT(__ATTR_PURE __ATTR_RETNONNULL __ATTR_WUNUSED __ATTR_IN(1),void *,__NOTHROW_NCX,__localdep_rawmemxchr,(void const *__restrict __haystack, int __needle),rawmemxchr,(__haystack,__needle))
#else /* __CRT_HAVE_rawmemxchr */
__NAMESPACE_LOCAL_END
#include <libc/local/string/rawmemxchr.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_rawmemxchr __LIBC_LOCAL_NAME(rawmemxchr)
#endif /* !__CRT_HAVE_rawmemxchr */
#endif /* !__local___localdep_rawmemxchr_defined */
__LOCAL_LIBC(rawmemxlen) __ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __SIZE_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(rawmemxlen))(void const *__restrict __haystack, int __needle) {
	return (__SIZE_TYPE__)((__BYTE_TYPE__ *)(__NAMESPACE_LOCAL_SYM __localdep_rawmemxchr)(__haystack, __needle) - (__BYTE_TYPE__ *)__haystack);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_rawmemxlen_defined
#define __local___localdep_rawmemxlen_defined
#define __localdep_rawmemxlen __LIBC_LOCAL_NAME(rawmemxlen)
#endif /* !__local___localdep_rawmemxlen_defined */
#endif /* !__local_rawmemxlen_defined */
