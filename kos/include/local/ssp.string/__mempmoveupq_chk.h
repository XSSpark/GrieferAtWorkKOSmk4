/* HASH CRC-32:0xf88f0c8b */
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
#ifndef __local___mempmoveupq_chk_defined
#define __local___mempmoveupq_chk_defined 1
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: mempmoveupq from string */
#ifndef __local___localdep_mempmoveupq_defined
#define __local___localdep_mempmoveupq_defined 1
#ifdef __CRT_HAVE_mempmoveupq
/* Same as `memmovew', but return `DST + N_QWORDS', rather than `DST' (assumes that `DST >= SRC || !N_QWORDS') */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),__UINT64_TYPE__ *,__NOTHROW_NCX,__localdep_mempmoveupq,(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __n_qwords),mempmoveupq,(__dst,__src,__n_qwords))
#elif defined(__CRT_HAVE_mempmoveq)
/* Same as `memmovew', but return `DST + N_QWORDS', rather than `DST' (assumes that `DST >= SRC || !N_QWORDS') */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),__UINT64_TYPE__ *,__NOTHROW_NCX,__localdep_mempmoveupq,(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __n_qwords),mempmoveq,(__dst,__src,__n_qwords))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/string/mempmoveupq.h>
__NAMESPACE_LOCAL_BEGIN
/* Same as `memmovew', but return `DST + N_QWORDS', rather than `DST' (assumes that `DST >= SRC || !N_QWORDS') */
#define __localdep_mempmoveupq __LIBC_LOCAL_NAME(mempmoveupq)
#endif /* !... */
#endif /* !__local___localdep_mempmoveupq_defined */
__NAMESPACE_LOCAL_END
#include <ssp/chk.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(__mempmoveupq_chk) __ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) __UINT64_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(__mempmoveupq_chk))(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __n_qwords, __SIZE_TYPE__ __dst_objsize) {
	__ssp_chk_dstbuf("mempmoveupq", __dst, __n_qwords * 8, __dst_objsize);
	return __localdep_mempmoveupq(__dst, __src, __n_qwords);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep___mempmoveupq_chk_defined
#define __local___localdep___mempmoveupq_chk_defined 1
#define __localdep___mempmoveupq_chk __LIBC_LOCAL_NAME(__mempmoveupq_chk)
#endif /* !__local___localdep___mempmoveupq_chk_defined */
#endif /* !__local___mempmoveupq_chk_defined */
