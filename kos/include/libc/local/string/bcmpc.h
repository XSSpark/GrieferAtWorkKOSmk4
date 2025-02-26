/* HASH CRC-32:0x9a89f420 */
/* Copyright (c) 2019-2025 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2025 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_bcmpc_defined
#define __local_bcmpc_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_bcmp_defined
#define __local___localdep_bcmp_defined
#ifdef __CRT_HAVE_bcmp
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_bcmp,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_bytes),bcmp,(__s1,__s2,__n_bytes))
#elif defined(__CRT_HAVE_memcmp)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_INS(2, 3) __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_bcmp,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_bytes),memcmp,(__s1,__s2,__n_bytes))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/memcmp.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_bcmp __LIBC_LOCAL_NAME(memcmp)
#endif /* !... */
#endif /* !__local___localdep_bcmp_defined */
#ifndef __local___localdep_bcmpl_defined
#define __local___localdep_bcmpl_defined
#ifdef __CRT_HAVE_bcmpl
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_bcmpl,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_dwords),bcmpl,(__s1,__s2,__n_dwords))
#elif defined(__CRT_HAVE_memcmpl)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_bcmpl,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_dwords),memcmpl,(__s1,__s2,__n_dwords))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/memcmpl.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_bcmpl __LIBC_LOCAL_NAME(memcmpl)
#endif /* !... */
#endif /* !__local___localdep_bcmpl_defined */
#ifndef __local___localdep_bcmpq_defined
#define __local___localdep_bcmpq_defined
#ifdef __CRT_HAVE_bcmpq
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_bcmpq,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_qwords),bcmpq,(__s1,__s2,__n_qwords))
#elif defined(__CRT_HAVE_memcmpq)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_bcmpq,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_qwords),memcmpq,(__s1,__s2,__n_qwords))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/memcmpq.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_bcmpq __LIBC_LOCAL_NAME(memcmpq)
#endif /* !... */
#endif /* !__local___localdep_bcmpq_defined */
#ifndef __local___localdep_bcmpw_defined
#define __local___localdep_bcmpw_defined
#ifdef __CRT_HAVE_bcmpw
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_bcmpw,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_words),bcmpw,(__s1,__s2,__n_words))
#elif defined(__CRT_HAVE_memcmpw)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2),int,__NOTHROW_NCX,__localdep_bcmpw,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_words),memcmpw,(__s1,__s2,__n_words))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/memcmpw.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_bcmpw __LIBC_LOCAL_NAME(memcmpw)
#endif /* !... */
#endif /* !__local___localdep_bcmpw_defined */
__NAMESPACE_LOCAL_END
#include <hybrid/host.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(bcmpc) __ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __ATTR_IN(2) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(bcmpc))(void const *__s1, void const *__s2, __SIZE_TYPE__ __elem_count, __SIZE_TYPE__ __elem_size) {
#ifdef __ARCH_HAVE_UNALIGNED_MEMORY_ACCESS
	switch (__elem_size) {

	case 1:
		return (__NAMESPACE_LOCAL_SYM __localdep_bcmp)(__s1, __s2, __elem_count);

	case 2:
		return (__NAMESPACE_LOCAL_SYM __localdep_bcmpw)(__s1, __s2, __elem_count);

	case 4:
		return (__NAMESPACE_LOCAL_SYM __localdep_bcmpl)(__s1, __s2, __elem_count);

#ifdef __UINT64_TYPE__
	case 8:
		return (__NAMESPACE_LOCAL_SYM __localdep_bcmpq)(__s1, __s2, __elem_count);
#endif /* __UINT64_TYPE__ */

	default:
		break;
	}
#endif /* __ARCH_HAVE_UNALIGNED_MEMORY_ACCESS */
	return (__NAMESPACE_LOCAL_SYM __localdep_bcmp)(__s1, __s2, __elem_count * __elem_size);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_bcmpc_defined
#define __local___localdep_bcmpc_defined
#define __localdep_bcmpc __LIBC_LOCAL_NAME(bcmpc)
#endif /* !__local___localdep_bcmpc_defined */
#endif /* !__local_bcmpc_defined */
