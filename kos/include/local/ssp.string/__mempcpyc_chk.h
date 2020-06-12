/* HASH CRC-32:0x916003fe */
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
#ifndef __local___mempcpyc_chk_defined
#define __local___mempcpyc_chk_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: mempcpyc from string */
#ifndef __local___localdep_mempcpyc_defined
#define __local___localdep_mempcpyc_defined 1
#ifdef __CRT_HAVE_mempcpyc
/* Same as `memcpyc', but return `DST + (ELEM_COUNT * ELEM_SIZE)', rather than `DST' */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_mempcpyc,(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __elem_count, __SIZE_TYPE__ __elem_size),mempcpyc,(__dst,__src,__elem_count,__elem_size))
#else /* __CRT_HAVE_mempcpyc */
__NAMESPACE_LOCAL_END
#include <local/string/mempcpyc.h>
__NAMESPACE_LOCAL_BEGIN
/* Same as `memcpyc', but return `DST + (ELEM_COUNT * ELEM_SIZE)', rather than `DST' */
#define __localdep_mempcpyc __LIBC_LOCAL_NAME(mempcpyc)
#endif /* !__CRT_HAVE_mempcpyc */
#endif /* !__local___localdep_mempcpyc_defined */
__NAMESPACE_LOCAL_END
#include <ssp/chk.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(__mempcpyc_chk) __ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) void *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(__mempcpyc_chk))(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __elem_count, __SIZE_TYPE__ __elem_size, __SIZE_TYPE__ __dst_objsize) {
	__ssp_chk_dstbuf("mempcpyc", __dst, __elem_count * __elem_size, __dst_objsize);
	return __localdep_mempcpyc(__dst, __src, __elem_count, __elem_size);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep___mempcpyc_chk_defined
#define __local___localdep___mempcpyc_chk_defined 1
#define __localdep___mempcpyc_chk __LIBC_LOCAL_NAME(__mempcpyc_chk)
#endif /* !__local___localdep___mempcpyc_chk_defined */
#endif /* !__local___mempcpyc_chk_defined */
