/* HASH CRC-32:0xc788ce2 */
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
#ifndef __local_copylist64_defined
#define __local_copylist64_defined
#include <__crt.h>
#include <features.h>
#include <asm/os/oflags.h>
#include <asm/os/fcntl.h>
#if (defined(__CRT_HAVE_open64) || defined(__CRT_HAVE___open64) || defined(__CRT_HAVE_open) || defined(__CRT_HAVE__open) || defined(__CRT_HAVE___open) || defined(__CRT_HAVE___libc_open) || (defined(__AT_FDCWD) && (defined(__CRT_HAVE_openat64) || defined(__CRT_HAVE_openat)))) && (defined(__CRT_HAVE_read) || defined(__CRT_HAVE__read) || defined(__CRT_HAVE___read) || defined(__CRT_HAVE___libc_read)) && (defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc))
#include <bits/types.h>
#ifndef __PIO_OFFSET
#ifdef __USE_KOS_ALTERATIONS
#define __PIO_OFFSET   __pos_t
#define __PIO_OFFSET64 __pos64_t
#else /* __USE_KOS_ALTERATIONS */
#define __PIO_OFFSET   __off_t
#define __PIO_OFFSET64 __off64_t
#endif /* !__USE_KOS_ALTERATIONS */
#endif /* !__PIO_OFFSET */
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_copylist_sz_defined
#define __local___localdep_copylist_sz_defined
__NAMESPACE_LOCAL_END
#include <libc/local/libgen/copylist_sz.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_copylist_sz __LIBC_LOCAL_NAME(copylist_sz)
#endif /* !__local___localdep_copylist_sz_defined */
__LOCAL_LIBC(copylist64) __ATTR_WUNUSED __ATTR_IN(1) __ATTR_OUT(2) char *
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(copylist64))(char const *__filename, __PIO_OFFSET64 *__p_filesize) {
#if __SIZEOF_OFF64_T__ == __SIZEOF_SIZE_T__
	return (__NAMESPACE_LOCAL_SYM __localdep_copylist_sz)(__filename, (__SIZE_TYPE__ *)__p_filesize);
#else /* __SIZEOF_OFF64_T__ == __SIZEOF_SIZE_T__ */
	char *__result;
	__SIZE_TYPE__ __size;
	__result = (__NAMESPACE_LOCAL_SYM __localdep_copylist_sz)(__filename, &__size);
	*__p_filesize = (__PIO_OFFSET64)__size;
	return __result;
#endif /* __SIZEOF_OFF64_T__ != __SIZEOF_SIZE_T__ */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_copylist64_defined
#define __local___localdep_copylist64_defined
#define __localdep_copylist64 __LIBC_LOCAL_NAME(copylist64)
#endif /* !__local___localdep_copylist64_defined */
#else /* (__CRT_HAVE_open64 || __CRT_HAVE___open64 || __CRT_HAVE_open || __CRT_HAVE__open || __CRT_HAVE___open || __CRT_HAVE___libc_open || (__AT_FDCWD && (__CRT_HAVE_openat64 || __CRT_HAVE_openat))) && (__CRT_HAVE_read || __CRT_HAVE__read || __CRT_HAVE___read || __CRT_HAVE___libc_read) && (__CRT_HAVE_realloc || __CRT_HAVE___libc_realloc) */
#undef __local_copylist64_defined
#endif /* (!__CRT_HAVE_open64 && !__CRT_HAVE___open64 && !__CRT_HAVE_open && !__CRT_HAVE__open && !__CRT_HAVE___open && !__CRT_HAVE___libc_open && (!__AT_FDCWD || (!__CRT_HAVE_openat64 && !__CRT_HAVE_openat))) || (!__CRT_HAVE_read && !__CRT_HAVE__read && !__CRT_HAVE___read && !__CRT_HAVE___libc_read) || (!__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc) */
#endif /* !__local_copylist64_defined */
