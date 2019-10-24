/* HASH CRC-32:0x8c520eb7 */
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
#ifndef __local__byteswap_uint64_defined
#define __local__byteswap_uint64_defined 1
#include <hybrid/__byteswap.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_byteswap_uint64) __ATTR_CONST __ATTR_WUNUSED __UINT64_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_byteswap_uint64))(__UINT64_TYPE__ __val) {
#line 1848 "kos/src/libc/magic/stdlib.c"
	return __hybrid_bswap64(__val);
}
__NAMESPACE_LOCAL_END
#endif /* !__local__byteswap_uint64_defined */
