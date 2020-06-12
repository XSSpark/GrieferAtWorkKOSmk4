/* HASH CRC-32:0x459eae70 */
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
#ifndef __local_argz_insert_defined
#define __local_argz_insert_defined 1
#include <__crt.h>
#ifdef __CRT_HAVE_realloc
__NAMESPACE_LOCAL_BEGIN
/* Dependency: strlen from string */
#ifndef __local___localdep_strlen_defined
#define __local___localdep_strlen_defined 1
#ifdef __CRT_HAVE_strlen
/* Return the length of the string in characters (Same as `rawmemlen[...](STR, '\0')') */
__CREDIRECT(__ATTR_PURE __ATTR_WUNUSED __ATTR_NONNULL((1)),__SIZE_TYPE__,__NOTHROW_NCX,__localdep_strlen,(char const *__restrict __string),strlen,(__string))
#else /* __CRT_HAVE_strlen */
__NAMESPACE_LOCAL_END
#include <local/string/strlen.h>
__NAMESPACE_LOCAL_BEGIN
/* Return the length of the string in characters (Same as `rawmemlen[...](STR, '\0')') */
#define __localdep_strlen __LIBC_LOCAL_NAME(strlen)
#endif /* !__CRT_HAVE_strlen */
#endif /* !__local___localdep_strlen_defined */
/* Dependency: memcpyc from string */
#ifndef __local___localdep_memcpyc_defined
#define __local___localdep_memcpyc_defined 1
#ifdef __CRT_HAVE_memcpyc
/* Copy memory between non-overlapping memory blocks.
 * @return: * : Always re-returns `dst' */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_memcpyc,(void *__restrict __dst, void const *__restrict __src, __SIZE_TYPE__ __elem_count, __SIZE_TYPE__ __elem_size),memcpyc,(__dst,__src,__elem_count,__elem_size))
#else /* __CRT_HAVE_memcpyc */
__NAMESPACE_LOCAL_END
#include <local/string/memcpyc.h>
__NAMESPACE_LOCAL_BEGIN
/* Copy memory between non-overlapping memory blocks.
 * @return: * : Always re-returns `dst' */
#define __localdep_memcpyc __LIBC_LOCAL_NAME(memcpyc)
#endif /* !__CRT_HAVE_memcpyc */
#endif /* !__local___localdep_memcpyc_defined */
/* Dependency: realloc from stdlib */
#ifndef __local___localdep_realloc_defined
#define __local___localdep_realloc_defined 1
#if __has_builtin(__builtin_realloc) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_realloc)
__CEIREDIRECT(__ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_ALLOC_SIZE((2)),void *,__NOTHROW_NCX,__localdep_realloc,(void *__mallptr, __SIZE_TYPE__ __num_bytes),realloc,{ return __builtin_realloc(__mallptr, __num_bytes); })
#elif defined(__CRT_HAVE_realloc)
__CREDIRECT(__ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_ALLOC_SIZE((2)),void *,__NOTHROW_NCX,__localdep_realloc,(void *__mallptr, __SIZE_TYPE__ __num_bytes),realloc,(__mallptr,__num_bytes))
#else /* ... */
#undef __local___localdep_realloc_defined
#endif /* !... */
#endif /* !__local___localdep_realloc_defined */
/* Dependency: argz_add from argz */
#ifndef __local___localdep_argz_add_defined
#define __local___localdep_argz_add_defined 1
#ifdef __CRT_HAVE_argz_add
/* Append `STR' to the argz vector in `PARGZ & PARGZ_LEN' */
__CREDIRECT(__ATTR_NONNULL((1, 2, 3)),__errno_t,__NOTHROW_NCX,__localdep_argz_add,(char **__restrict __pargz, __SIZE_TYPE__ *__restrict __pargz_len, char const *__restrict __str),argz_add,(__pargz,__pargz_len,__str))
#elif defined(__CRT_HAVE___argz_add)
/* Append `STR' to the argz vector in `PARGZ & PARGZ_LEN' */
__CREDIRECT(__ATTR_NONNULL((1, 2, 3)),__errno_t,__NOTHROW_NCX,__localdep_argz_add,(char **__restrict __pargz, __SIZE_TYPE__ *__restrict __pargz_len, char const *__restrict __str),__argz_add,(__pargz,__pargz_len,__str))
#elif defined(__CRT_HAVE_argz_append) || defined(__CRT_HAVE___argz_create_sep) || defined(__CRT_HAVE_realloc)
__NAMESPACE_LOCAL_END
#include <local/argz/argz_add.h>
__NAMESPACE_LOCAL_BEGIN
/* Append `STR' to the argz vector in `PARGZ & PARGZ_LEN' */
#define __localdep_argz_add __LIBC_LOCAL_NAME(argz_add)
#else /* ... */
#undef __local___localdep_argz_add_defined
#endif /* !... */
#endif /* !__local___localdep_argz_add_defined */
/* Dependency: memmoveupc from string */
#ifndef __local___localdep_memmoveupc_defined
#define __local___localdep_memmoveupc_defined 1
#ifdef __CRT_HAVE_memmoveupc
/* Move memory between potentially overlapping memory blocks (assumes that `DST >= SRC || !ELEM_COUNT || !ELEM_SIZE')
 * @return: * : Always re-returns `dst' */
__CREDIRECT(__ATTR_LEAF __ATTR_RETNONNULL __ATTR_NONNULL((1, 2)),void *,__NOTHROW_NCX,__localdep_memmoveupc,(void *__dst, void const *__src, __SIZE_TYPE__ __elem_count, __SIZE_TYPE__ __elem_size),memmoveupc,(__dst,__src,__elem_count,__elem_size))
#else /* __CRT_HAVE_memmoveupc */
__NAMESPACE_LOCAL_END
#include <local/string/memmoveupc.h>
__NAMESPACE_LOCAL_BEGIN
/* Move memory between potentially overlapping memory blocks (assumes that `DST >= SRC || !ELEM_COUNT || !ELEM_SIZE')
 * @return: * : Always re-returns `dst' */
#define __localdep_memmoveupc __LIBC_LOCAL_NAME(memmoveupc)
#endif /* !__CRT_HAVE_memmoveupc */
#endif /* !__local___localdep_memmoveupc_defined */
__NAMESPACE_LOCAL_END
#include <parts/errno.h>
__NAMESPACE_LOCAL_BEGIN
/* Insert `ENTRY' into `ARGZ & ARGZ_LEN' before `BEFORE', which should be an
 * existing entry in `ARGZ'; if `BEFORE' is `NULL', `ENTRY' is appended to the end.
 * Since `ARGZ's first entry is the same as `ARGZ', `argz_insert(ARGZ, ARGZ_LEN, ARGZ, ENTRY)'
 * will insert `ENTRY' at the beginning of `ARGZ'. If `BEFORE' is not in `ARGZ', `EINVAL'
 * is returned, else if memory can't be allocated for the new `ARGZ', `ENOMEM' is returned.
 * On success, `0' is returned */
__LOCAL_LIBC(argz_insert) __ATTR_NONNULL((1, 2, 4)) __errno_t
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(argz_insert))(char **__restrict __pargz, __SIZE_TYPE__ *__restrict __pargz_len, char *__before, char const *__restrict __entry) {
	char *__argz;
	__SIZE_TYPE__ __argz_len;
	__SIZE_TYPE__ __entry_len;
	__SIZE_TYPE__ __insert_offset;
	if (!__before)
		return __localdep_argz_add(__pargz, __pargz_len, __entry);
	__argz     = *__pargz;
	__argz_len = *__pargz_len;
	if (__before < __argz || __before >= __argz + __argz_len) {
#ifdef EINVAL
		return __EINVAL;
#else /* EINVAL */
		return 1;
#endif /* !EINVAL */
	}
	/* Adjust `before' to point to the start of an entry
	 * Note that GLibc has a bug here that causes it to accessed
	 * memory before `*pargz' when `before' points into the first
	 * element of the argz vector.
	 * -> That bug is fixed here!
	 * As such, GLibc's version would only work when `((char *)malloc(N))[-1] == 0'
	 * for an arbitrary N that results in `malloc()' returning non-NULL.
	 * Glibc's version of this:
	 * >> if (before > *argz)
	 * >>   while (before[-1]) // <<< Right here!
	 * >>     before--;
	 */
	while (__before > __argz && __before[-1])
		--__before;
	__entry_len = __localdep_strlen(__entry) + 1;
	__argz_len += __entry_len;
	__insert_offset = (__SIZE_TYPE__)(__before - __argz);
	__argz = (char *)__localdep_realloc(__argz, __argz_len * sizeof(char));
	if __unlikely(!__argz) {
#ifdef ENOMEM
		return __ENOMEM;
#else /* ENOMEM */
		return 1;
#endif /* !ENOMEM */
	}
	/* Update ARGZ pointers. */
	*__pargz     = __argz;
	*__pargz_len = __argz_len;
	/* Make space for the new entry. */
	__localdep_memmoveupc(__argz + __insert_offset + __entry_len,
	           __argz + __insert_offset,
	           (__argz_len - (__insert_offset + __entry_len)),
	           sizeof(char));
	/* Insert the new entry. */
	__localdep_memcpyc(__argz + __insert_offset,
	        __entry, __entry_len,
	        sizeof(char));
	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_argz_insert_defined
#define __local___localdep_argz_insert_defined 1
#define __localdep_argz_insert __LIBC_LOCAL_NAME(argz_insert)
#endif /* !__local___localdep_argz_insert_defined */
#else /* __CRT_HAVE_realloc */
#undef __local_argz_insert_defined
#endif /* !__CRT_HAVE_realloc */
#endif /* !__local_argz_insert_defined */
