/* HASH CRC-32:0xb5edf636 */
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
#ifndef __local__mbsicmp_defined
#define __local__mbsicmp_defined
#include <__crt.h>
#ifdef __CRT_HAVE__mbsicmp_l
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep__mbsicmp_l_defined
#define __local___localdep__mbsicmp_l_defined
__CREDIRECT(__ATTR_WUNUSED __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep__mbsicmp_l,(unsigned char const *__lhs, unsigned char const *__rhs, __locale_t __locale),_mbsicmp_l,(__lhs,__rhs,__locale))
#endif /* !__local___localdep__mbsicmp_l_defined */
__LOCAL_LIBC(_mbsicmp) __ATTR_WUNUSED __ATTR_NONNULL((1, 2)) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_mbsicmp))(unsigned char const *__lhs, unsigned char const *__rhs) {
	return (__NAMESPACE_LOCAL_SYM __localdep__mbsicmp_l)(__lhs, __rhs, __NULLPTR);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__mbsicmp_defined
#define __local___localdep__mbsicmp_defined
#define __localdep__mbsicmp __LIBC_LOCAL_NAME(_mbsicmp)
#endif /* !__local___localdep__mbsicmp_defined */
#else /* __CRT_HAVE__mbsicmp_l */
#undef __local__mbsicmp_defined
#endif /* !__CRT_HAVE__mbsicmp_l */
#endif /* !__local__mbsicmp_defined */
