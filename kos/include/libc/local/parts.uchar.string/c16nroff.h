/* HASH CRC-32:0x4cc84694 */
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
#ifndef __local_c16nroff_defined
#define __local_c16nroff_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_c16nrchrnul_defined
#define __local___localdep_c16nrchrnul_defined
#if defined(__CRT_HAVE_wcsnrchrnul) && __SIZEOF_WCHAR_T__ == 2 && defined(__LIBCCALL_IS_LIBDCALL)
__CREDIRECT(__ATTR_PURE __ATTR_RETNONNULL __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_NONNULL((1)),__CHAR16_TYPE__ *,__NOTHROW_NCX,__localdep_c16nrchrnul,(__CHAR16_TYPE__ const *__restrict __haystack, __CHAR16_TYPE__ __needle, __SIZE_TYPE__ __maxlen),wcsnrchrnul,(__haystack,__needle,__maxlen))
#elif defined(__CRT_HAVE_DOS$wcsnrchrnul)
__CREDIRECT_DOS(__ATTR_PURE __ATTR_RETNONNULL __ATTR_WUNUSED __ATTR_INS(1, 3) __ATTR_NONNULL((1)),__CHAR16_TYPE__ *,__NOTHROW_NCX,__localdep_c16nrchrnul,(__CHAR16_TYPE__ const *__restrict __haystack, __CHAR16_TYPE__ __needle, __SIZE_TYPE__ __maxlen),wcsnrchrnul,(__haystack,__needle,__maxlen))
#elif __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wcsnrchrnul.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c16nrchrnul __NAMESPACE_LOCAL_TYPEHAX(__CHAR16_TYPE__ *(__LIBDCALL*)(__CHAR16_TYPE__ const *__restrict,__CHAR16_TYPE__,__SIZE_TYPE__),__CHAR16_TYPE__ *(__LIBDCALL&)(__CHAR16_TYPE__ const *__restrict,__CHAR16_TYPE__,__SIZE_TYPE__),wcsnrchrnul)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/parts.uchar.string/c16nrchrnul.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_c16nrchrnul __LIBC_LOCAL_NAME(c16nrchrnul)
#endif /* !... */
#endif /* !__local___localdep_c16nrchrnul_defined */
__LOCAL_LIBC(c16nroff) __ATTR_PURE __ATTR_WUNUSED __ATTR_IN(1) __SIZE_TYPE__
__NOTHROW_NCX(__LIBDCALL __LIBC_LOCAL_NAME(c16nroff))(__CHAR16_TYPE__ const *__restrict __haystack, __CHAR16_TYPE__ __needle, __SIZE_TYPE__ __maxlen) {
	return (__SIZE_TYPE__)((__NAMESPACE_LOCAL_SYM __localdep_c16nrchrnul)(__haystack, __needle, __maxlen) - __haystack);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c16nroff_defined
#define __local___localdep_c16nroff_defined
#define __localdep_c16nroff __LIBC_LOCAL_NAME(c16nroff)
#endif /* !__local___localdep_c16nroff_defined */
#endif /* !__local_c16nroff_defined */
