/* HASH CRC-32:0x2ac6f3b9 */
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
#ifndef __local_bzeroq_defined
#define __local_bzeroq_defined 1
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: bzerol from string */
#ifndef __local___localdep_bzerol_defined
#define __local___localdep_bzerol_defined 1
#ifdef __CRT_HAVE_bzerol
__CREDIRECT_VOID(__ATTR_LEAF __ATTR_NONNULL((1)),__NOTHROW_NCX,__localdep_bzerol,(void *__restrict __dst, __SIZE_TYPE__ __num_dwords),bzerol,(__dst,__num_dwords))
#else /* __CRT_HAVE_bzerol */
__NAMESPACE_LOCAL_END
#include <local/string/bzerol.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_bzerol __LIBC_LOCAL_NAME(bzerol)
#endif /* !__CRT_HAVE_bzerol */
#endif /* !__local___localdep_bzerol_defined */
/* Dependency: memsetq from string */
#ifndef __local___localdep_memsetq_defined
#define __local___localdep_memsetq_defined 1
#ifdef __CRT_HAVE_memsetq
/* Fill memory with a given qword */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1)),__UINT64_TYPE__ *,__NOTHROW_NCX,__localdep_memsetq,(void *__restrict __dst, __UINT64_TYPE__ __qword, __SIZE_TYPE__ __n_qwords),memsetq,(__dst,__qword,__n_qwords))
#else /* __CRT_HAVE_memsetq */
__NAMESPACE_LOCAL_END
#include <local/string/memsetq.h>
__NAMESPACE_LOCAL_BEGIN
/* Fill memory with a given qword */
#define __localdep_memsetq __LIBC_LOCAL_NAME(memsetq)
#endif /* !__CRT_HAVE_memsetq */
#endif /* !__local___localdep_memsetq_defined */
__LOCAL_LIBC(bzeroq) __ATTR_LEAF __ATTR_NONNULL((1)) void
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(bzeroq))(void *__restrict __dst, __SIZE_TYPE__ __num_qwords) {
#ifdef __UINT64_TYPE__
	__localdep_memsetq(__dst, 0, __num_qwords);
#else /* __UINT64_TYPE__ */
	__localdep_bzerol(__dst, __num_qwords * 2);
#endif /* !__UINT64_TYPE__ */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_bzeroq_defined
#define __local___localdep_bzeroq_defined 1
#define __localdep_bzeroq __LIBC_LOCAL_NAME(bzeroq)
#endif /* !__local___localdep_bzeroq_defined */
#endif /* !__local_bzeroq_defined */
