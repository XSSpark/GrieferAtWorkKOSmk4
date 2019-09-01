/* HASH 0xdda544cd */
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
#ifndef __local_memmem_defined
#define __local_memmem_defined 1
#ifdef __LIBC_BIND_OPTIMIZATIONS
#include <optimized/string.h>
#endif /* __LIBC_BIND_OPTIMIZATIONS */
/* Dependency: "memcmp" from "string" */
#ifndef ____localdep_memcmp_defined
#define ____localdep_memcmp_defined 1
#if defined(__fast_memcmp_defined)
/* Compare memory buffers and return the difference of the first non-matching byte */
#define __localdep_memcmp (__NAMESPACE_FAST_SYM __LIBC_FAST_NAME(memcmp))
#elif defined(__CRT_HAVE_memcmp)
/* Compare memory buffers and return the difference of the first non-matching byte */
__CREDIRECT(__ATTR_WUNUSED __ATTR_PURE __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_memcmp,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_bytes),memcmp,(__s1,__s2,__n_bytes))
#elif defined(__CRT_HAVE_bcmp)
/* Compare memory buffers and return the difference of the first non-matching byte */
__CREDIRECT(__ATTR_WUNUSED __ATTR_PURE __ATTR_NONNULL((1, 2)),int,__NOTHROW_NCX,__localdep_memcmp,(void const *__s1, void const *__s2, __SIZE_TYPE__ __n_bytes),bcmp,(__s1,__s2,__n_bytes))
#else /* LIBC: memcmp */
#include <local/string/memcmp.h>
/* Compare memory buffers and return the difference of the first non-matching byte */
#define __localdep_memcmp (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(memcmp))
#endif /* memcmp... */
#endif /* !____localdep_memcmp_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(memmem) __ATTR_WUNUSED __ATTR_PURE __ATTR_NONNULL((1, 3)) void *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(memmem))(void const *__haystack,
                                                    __SIZE_TYPE__ __haystacklen,
                                                    void const *__needle,
                                                    __SIZE_TYPE__ __needlelen) {
#line 614 "kos/src/libc/magic/string.c"
	__BYTE_TYPE__ *__iter = (__BYTE_TYPE__ *)__haystack;
	while (__haystacklen >= __needlelen) {
		if (__localdep_memcmp(__iter, __needle, __needlelen) == 0)
			return (void *)__iter;
		++__iter;
	}
	return __NULLPTR;
}
__NAMESPACE_LOCAL_END
#endif /* !__local_memmem_defined */
