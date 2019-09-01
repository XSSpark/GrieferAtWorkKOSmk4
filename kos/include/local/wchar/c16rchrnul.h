/* HASH 0x8b8337ff */
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
#ifndef __local_c16rchrnul_defined
#define __local_c16rchrnul_defined 1
__NAMESPACE_LOCAL_BEGIN
/* Same as `c16rchr', but return `STR-1', rather than `NULL' if `NEEDLE' wasn't found. */
__LOCAL_LIBC(c16rchrnul) __ATTR_WUNUSED __ATTR_PURE __ATTR_RETNONNULL __ATTR_NONNULL((1)) __CHAR16_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(c16rchrnul))(__CHAR16_TYPE__ const *__restrict __haystack,
                                                        __CHAR16_TYPE__ __needle) {
#line 2113 "kos/src/libc/magic/string.c"
	__CHAR16_TYPE__ const *__result = __haystack - 1;
	do {
		if __unlikely((__CHAR16_TYPE__)*__haystack == (__CHAR16_TYPE__)__needle)
			__result = __haystack;
	} while (*__haystack++);
	return (__CHAR16_TYPE__ *)__result;
}
__NAMESPACE_LOCAL_END
#endif /* !__local_c16rchrnul_defined */
