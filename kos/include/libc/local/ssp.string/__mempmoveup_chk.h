/* HASH CRC-32:0xcccc3f2d */
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
#ifndef __local___mempmoveup_chk_defined
#define __local___mempmoveup_chk_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_mempmoveup_defined
#define __local___localdep_mempmoveup_defined
#ifdef __CRT_HAVE_mempmoveup
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_INS(2, 3) __ATTR_OUTS(1, 3) __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_mempmoveup,(void *__dst, void const *__src, __SIZE_TYPE__ __n_bytes),mempmoveup,(__dst,__src,__n_bytes))
#elif defined(__CRT_HAVE_mempmove)
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_INS(2, 3) __ATTR_OUTS(1, 3) __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_mempmoveup,(void *__dst, void const *__src, __SIZE_TYPE__ __n_bytes),mempmove,(__dst,__src,__n_bytes))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/mempmoveup.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_mempmoveup __LIBC_LOCAL_NAME(mempmoveup)
#endif /* !... */
#endif /* !__local___localdep_mempmoveup_defined */
__NAMESPACE_LOCAL_END
#include <ssp/chk.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(__mempmoveup_chk) __ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) void *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(__mempmoveup_chk))(void *__dst, void const *__src, __SIZE_TYPE__ __n_bytes, __SIZE_TYPE__ __dst_objsize) {
	__ssp_chk_dstbuf("mempmoveup", __dst, __n_bytes, __dst_objsize);
	return (__NAMESPACE_LOCAL_SYM __localdep_mempmoveup)(__dst, __src, __n_bytes);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep___mempmoveup_chk_defined
#define __local___localdep___mempmoveup_chk_defined
#define __localdep___mempmoveup_chk __LIBC_LOCAL_NAME(__mempmoveup_chk)
#endif /* !__local___localdep___mempmoveup_chk_defined */
#endif /* !__local___mempmoveup_chk_defined */
