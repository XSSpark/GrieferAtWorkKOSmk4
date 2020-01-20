/* HASH CRC-32:0xc50061f1 */
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
#ifndef __local_rawmemrlenw_defined
#define __local_rawmemrlenw_defined 1
/* Dependency: "rawmemrchrw" from "string" */
#ifndef ____localdep_rawmemrchrw_defined
#define ____localdep_rawmemrchrw_defined 1
#ifdef __CRT_HAVE_rawmemrchrw
/* Same as `memrchrw' without a search limit, starting at `(byte_t *)HAYSTACK-2' */
__CREDIRECT(__ATTR_PURE __ATTR_RETNONNULL __ATTR_WUNUSED __ATTR_NONNULL((1)),__UINT16_TYPE__ *,__NOTHROW_NCX,__localdep_rawmemrchrw,(/*aligned(2)*/ void const *__restrict __haystack, __UINT16_TYPE__ __word),rawmemrchrw,(__haystack,__word))
#else /* LIBC: rawmemrchrw */
#include <local/string/rawmemrchrw.h>
/* Same as `memrchrw' without a search limit, starting at `(byte_t *)HAYSTACK-2' */
#define __localdep_rawmemrchrw (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(rawmemrchrw))
#endif /* rawmemrchrw... */
#endif /* !____localdep_rawmemrchrw_defined */

__NAMESPACE_LOCAL_BEGIN
/* Same as `rawmemrchrw', but return the offset from `HAYSTACK', rather than the actual address. */
__LOCAL_LIBC(rawmemrlenw) __ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)) __SIZE_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(rawmemrlenw))(/*aligned(2)*/ void const *__restrict __haystack,
                                                         __UINT16_TYPE__ __word) {
#line 1571 "kos/src/libc/magic/string.c"
	return (__SIZE_TYPE__)(__localdep_rawmemrchrw(__haystack, __word) - (__UINT16_TYPE__ *)__haystack);
}
__NAMESPACE_LOCAL_END
#endif /* !__local_rawmemrlenw_defined */
