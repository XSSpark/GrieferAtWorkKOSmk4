/* HASH CRC-32:0xb2ab4365 */
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
#ifndef __local_dyn_string_copy_defined
#define __local_dyn_string_copy_defined
#include <__crt.h>
#if defined(__CRT_HAVE_dyn_string_resize) || ((defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_xrealloc) || defined(__CRT_HAVE_xmalloc_failed)))
#include <features.h>
#include <bits/crt/dyn-string.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_dyn_string_resize_defined
#define __local___localdep_dyn_string_resize_defined
#ifdef __CRT_HAVE_dyn_string_resize
__CREDIRECT(__ATTR_RETNONNULL __ATTR_INOUT(1),struct dyn_string *,__NOTHROW_NCX,__localdep_dyn_string_resize,(struct dyn_string *__self, __STDC_INT_AS_SIZE_T __min_chars),dyn_string_resize,(__self,__min_chars))
#elif (defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_xrealloc) || defined(__CRT_HAVE_xmalloc_failed))
__NAMESPACE_LOCAL_END
#include <libc/local/dyn-string/dyn_string_resize.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_dyn_string_resize __LIBC_LOCAL_NAME(dyn_string_resize)
#else /* ... */
#undef __local___localdep_dyn_string_resize_defined
#endif /* !... */
#endif /* !__local___localdep_dyn_string_resize_defined */
#ifndef __local___localdep_memcpyc_defined
#define __local___localdep_memcpyc_defined
#ifdef __CRT_HAVE_memcpyc
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_LEAF __ATTR_IN(2) __ATTR_OUT(1),void *,__NOTHROW_NCX,__localdep_memcpyc,(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __elem_count, __SIZE_TYPE__ __elem_size),memcpyc,(__dst,__src,__elem_count,__elem_size))
#else /* __CRT_HAVE_memcpyc */
__NAMESPACE_LOCAL_END
#include <libc/local/string/memcpyc.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_memcpyc __LIBC_LOCAL_NAME(memcpyc)
#endif /* !__CRT_HAVE_memcpyc */
#endif /* !__local___localdep_memcpyc_defined */
__LOCAL_LIBC(dyn_string_copy) __ATTR_IN(2) __ATTR_INOUT(1) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(dyn_string_copy))(struct dyn_string *__dst, struct dyn_string __KOS_FIXED_CONST *__src) {
	__dst = (__NAMESPACE_LOCAL_SYM __localdep_dyn_string_resize)(__dst, __src->length);
	__dst->length = __src->length;
	(__NAMESPACE_LOCAL_SYM __localdep_memcpyc)(__dst->s, __src->s, __src->length + 1, sizeof(char));
	return 1;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_dyn_string_copy_defined
#define __local___localdep_dyn_string_copy_defined
#define __localdep_dyn_string_copy __LIBC_LOCAL_NAME(dyn_string_copy)
#endif /* !__local___localdep_dyn_string_copy_defined */
#else /* __CRT_HAVE_dyn_string_resize || ((__CRT_HAVE_realloc || __CRT_HAVE___libc_realloc) && (__CRT_HAVE_xrealloc || __CRT_HAVE_xmalloc_failed)) */
#undef __local_dyn_string_copy_defined
#endif /* !__CRT_HAVE_dyn_string_resize && ((!__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc) || (!__CRT_HAVE_xrealloc && !__CRT_HAVE_xmalloc_failed)) */
#endif /* !__local_dyn_string_copy_defined */
