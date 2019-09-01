/* HASH 0x50510b6a */
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
#ifndef __local_memcpyq_defined
#define __local_memcpyq_defined 1
__NAMESPACE_LOCAL_BEGIN
/* Copy memory between non-overlapping memory blocks. */
__LOCAL_LIBC(memcpyq) __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)) __UINT64_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(memcpyq))(void *__restrict __dst,
                                                     void const *__restrict __src,
                                                     __SIZE_TYPE__ __n_qwords) {
#line 1331 "kos/src/libc/magic/string.c"
#if __SIZEOF_POINTER__ >= 8
	__UINT64_TYPE__ *__pdst = (__UINT64_TYPE__ *)__dst;
	__UINT64_TYPE__ *__psrc = (__UINT64_TYPE__ *)__src;
	while (__n_qwords--)
		*__pdst++ = *__psrc++;
#else
	__UINT32_TYPE__ *__pdst = (__UINT32_TYPE__ *)__dst;
	__UINT32_TYPE__ *__psrc = (__UINT32_TYPE__ *)__src;
	while (__n_qwords--) {
		*__pdst++ = *__psrc++;
		*__pdst++ = *__psrc++;
	}
#endif
	return (__UINT64_TYPE__ *)__dst;
}
__NAMESPACE_LOCAL_END
#endif /* !__local_memcpyq_defined */
