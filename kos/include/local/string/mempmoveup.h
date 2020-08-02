/* HASH CRC-32:0x864a32e5 */
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
#ifndef __local_mempmoveup_defined
#define __local_mempmoveup_defined 1
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: memmoveup from string */
#ifndef __local___localdep_memmoveup_defined
#define __local___localdep_memmoveup_defined 1
#ifdef __CRT_HAVE_memmoveup
/* Move memory between potentially overlapping memory blocks (assumes that `DST >= SRC || !N_BYTES')
 * @return: * : Always re-returns `dst' */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_memmoveup,(void *__dst, void const *__src, __SIZE_TYPE__ __n_bytes),memmoveup,(__dst,__src,__n_bytes))
#elif defined(__CRT_HAVE_memmove)
/* Move memory between potentially overlapping memory blocks (assumes that `DST >= SRC || !N_BYTES')
 * @return: * : Always re-returns `dst' */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_memmoveup,(void *__dst, void const *__src, __SIZE_TYPE__ __n_bytes),memmove,(__dst,__src,__n_bytes))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <local/string/memmoveup.h>
__NAMESPACE_LOCAL_BEGIN
/* Move memory between potentially overlapping memory blocks (assumes that `DST >= SRC || !N_BYTES')
 * @return: * : Always re-returns `dst' */
#define __localdep_memmoveup __LIBC_LOCAL_NAME(memmoveup)
#endif /* !... */
#endif /* !__local___localdep_memmoveup_defined */
/* Same as `memmoveup', but return `DST + N_BYTES', rather than `DST' (assumes that `DST >= SRC || !N_BYTES') */
__LOCAL_LIBC(mempmoveup) __ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) void *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(mempmoveup))(void *__dst, void const *__src, __SIZE_TYPE__ __n_bytes) {
	return (void *)((__BYTE_TYPE__ *)__localdep_memmoveup(__dst, __src, __n_bytes) + __n_bytes);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_mempmoveup_defined
#define __local___localdep_mempmoveup_defined 1
#define __localdep_mempmoveup __LIBC_LOCAL_NAME(mempmoveup)
#endif /* !__local___localdep_mempmoveup_defined */
#endif /* !__local_mempmoveup_defined */
