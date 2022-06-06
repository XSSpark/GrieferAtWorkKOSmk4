/* HASH CRC-32:0xf3d20ffe */
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
#ifndef __local_wcspncpy_defined
#define __local_wcspncpy_defined
#include <__crt.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_wcsnlen_defined
#define __local___localdep_wcsnlen_defined
#ifdef __CRT_HAVE_wcsnlen
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 2) __ATTR_NONNULL((1)),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_wcsnlen,(__WCHAR_TYPE__ const *__restrict __str, __SIZE_TYPE__ __maxlen),wcsnlen,(__str,__maxlen))
#elif defined(__CRT_HAVE___wcsncnt)
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_INS(1, 2) __ATTR_NONNULL((1)),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_wcsnlen,(__WCHAR_TYPE__ const *__restrict __str, __SIZE_TYPE__ __maxlen),__wcsncnt,(__str,__maxlen))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wcsnlen.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wcsnlen __LIBC_LOCAL_NAME(wcsnlen)
#endif /* !... */
#endif /* !__local___localdep_wcsnlen_defined */
#ifndef __local___localdep_wmempcpy_defined
#define __local___localdep_wmempcpy_defined
#ifdef __CRT_HAVE_wmempcpy
__CREDIRECT(__ATTR_RETNONNULL __ATTR_INS(2, 3) __ATTR_OUTS(1, 3),__WCHAR_TYPE__ *,__NOTHROW_NCX,__localdep_wmempcpy,(__WCHAR_TYPE__ *__restrict __dst, __WCHAR_TYPE__ const *__restrict __src, __SIZE_TYPE__ __num_chars),wmempcpy,(__dst,__src,__num_chars))
#elif defined(__CRT_HAVE_mempcpyw) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT(__ATTR_RETNONNULL __ATTR_INS(2, 3) __ATTR_OUTS(1, 3),__WCHAR_TYPE__ *,__NOTHROW_NCX,__localdep_wmempcpy,(__WCHAR_TYPE__ *__restrict __dst, __WCHAR_TYPE__ const *__restrict __src, __SIZE_TYPE__ __num_chars),mempcpyw,(__dst,__src,__num_chars))
#elif defined(__CRT_HAVE_mempcpyl) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT(__ATTR_RETNONNULL __ATTR_INS(2, 3) __ATTR_OUTS(1, 3),__WCHAR_TYPE__ *,__NOTHROW_NCX,__localdep_wmempcpy,(__WCHAR_TYPE__ *__restrict __dst, __WCHAR_TYPE__ const *__restrict __src, __SIZE_TYPE__ __num_chars),mempcpyl,(__dst,__src,__num_chars))
#elif __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/string/mempcpyw.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wmempcpy __NAMESPACE_LOCAL_TYPEHAX(__WCHAR_TYPE__ *(__LIBCCALL*)(__WCHAR_TYPE__ *__restrict,__WCHAR_TYPE__ const *__restrict,__SIZE_TYPE__),__WCHAR_TYPE__ *(__LIBCCALL&)(__WCHAR_TYPE__ *__restrict,__WCHAR_TYPE__ const *__restrict,__SIZE_TYPE__),mempcpyw)
#elif __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <libc/local/string/mempcpyl.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wmempcpy __NAMESPACE_LOCAL_TYPEHAX(__WCHAR_TYPE__ *(__LIBCCALL*)(__WCHAR_TYPE__ *__restrict,__WCHAR_TYPE__ const *__restrict,__SIZE_TYPE__),__WCHAR_TYPE__ *(__LIBCCALL&)(__WCHAR_TYPE__ *__restrict,__WCHAR_TYPE__ const *__restrict,__SIZE_TYPE__),mempcpyl)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wmempcpy.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wmempcpy __LIBC_LOCAL_NAME(wmempcpy)
#endif /* !... */
#endif /* !__local___localdep_wmempcpy_defined */
#ifndef __local___localdep_wmempset_defined
#define __local___localdep_wmempset_defined
#ifdef __CRT_HAVE_wmempset
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_OUTS(1, 3) __ATTR_NONNULL((1)),__WCHAR_TYPE__ *,__NOTHROW_NCX,__localdep_wmempset,(__WCHAR_TYPE__ *__dst, __WCHAR_TYPE__ __filler, __SIZE_TYPE__ __num_chars),wmempset,(__dst,__filler,__num_chars))
#elif defined(__CRT_HAVE_mempsetw) && __SIZEOF_WCHAR_T__ == 2
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_OUTS(1, 3) __ATTR_NONNULL((1)),__WCHAR_TYPE__ *,__NOTHROW_NCX,__localdep_wmempset,(__WCHAR_TYPE__ *__dst, __WCHAR_TYPE__ __filler, __SIZE_TYPE__ __num_chars),mempsetw,(__dst,__filler,__num_chars))
#elif defined(__CRT_HAVE_mempsetl) && __SIZEOF_WCHAR_T__ == 4
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_OUTS(1, 3) __ATTR_NONNULL((1)),__WCHAR_TYPE__ *,__NOTHROW_NCX,__localdep_wmempset,(__WCHAR_TYPE__ *__dst, __WCHAR_TYPE__ __filler, __SIZE_TYPE__ __num_chars),mempsetl,(__dst,__filler,__num_chars))
#elif __SIZEOF_WCHAR_T__ == 2
__NAMESPACE_LOCAL_END
#include <libc/local/string/mempsetw.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wmempset __NAMESPACE_LOCAL_TYPEHAX(__WCHAR_TYPE__ *(__LIBCCALL*)(__WCHAR_TYPE__ *,__WCHAR_TYPE__,__SIZE_TYPE__),__WCHAR_TYPE__ *(__LIBCCALL&)(__WCHAR_TYPE__ *,__WCHAR_TYPE__,__SIZE_TYPE__),mempsetw)
#elif __SIZEOF_WCHAR_T__ == 4
__NAMESPACE_LOCAL_END
#include <libc/local/string/mempsetl.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wmempset __NAMESPACE_LOCAL_TYPEHAX(__WCHAR_TYPE__ *(__LIBCCALL*)(__WCHAR_TYPE__ *,__WCHAR_TYPE__,__SIZE_TYPE__),__WCHAR_TYPE__ *(__LIBCCALL&)(__WCHAR_TYPE__ *,__WCHAR_TYPE__,__SIZE_TYPE__),mempsetl)
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/wchar/wmempset.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wmempset __LIBC_LOCAL_NAME(wmempset)
#endif /* !... */
#endif /* !__local___localdep_wmempset_defined */
__LOCAL_LIBC(wcspncpy) __ATTR_LEAF __ATTR_RETNONNULL __ATTR_INS(2, 3) __ATTR_OUTS(1, 3) __ATTR_NONNULL((1, 2)) __WCHAR_TYPE__ *
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wcspncpy))(__WCHAR_TYPE__ *__restrict __buf, __WCHAR_TYPE__ const *__restrict __src, __SIZE_TYPE__ __buflen) {
	__SIZE_TYPE__ __srclen = (__NAMESPACE_LOCAL_SYM __localdep_wcsnlen)(__src, __buflen);
	__buf = (__NAMESPACE_LOCAL_SYM __localdep_wmempcpy)(__buf, __src, __srclen);
	__buf = (__NAMESPACE_LOCAL_SYM __localdep_wmempset)(__buf, (__WCHAR_TYPE__)'\0', __buflen - __srclen);
	return __buf;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wcspncpy_defined
#define __local___localdep_wcspncpy_defined
#define __localdep_wcspncpy __LIBC_LOCAL_NAME(wcspncpy)
#endif /* !__local___localdep_wcspncpy_defined */
#endif /* !__local_wcspncpy_defined */
