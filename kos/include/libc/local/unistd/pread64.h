/* HASH CRC-32:0x698d4338 */
/* Copyright (c) 2019-2021 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2021 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_pread64_defined
#define __local_pread64_defined
#include <__crt.h>
#include <asm/os/stdio.h>
#include <features.h>
#include <bits/types.h>
#if defined(__CRT_HAVE_pread) || ((defined(__CRT_HAVE_lseek64) || defined(__CRT_HAVE__lseeki64) || defined(__CRT_HAVE_llseek) || defined(__CRT_HAVE___llseek) || defined(__CRT_HAVE_lseek) || defined(__CRT_HAVE__lseek) || defined(__CRT_HAVE___lseek) || defined(__CRT_HAVE___libc_lseek)) && (defined(__CRT_HAVE_read) || defined(__CRT_HAVE__read) || defined(__CRT_HAVE___read) || defined(__CRT_HAVE___libc_read)) && defined(__SEEK_CUR) && defined(__SEEK_SET))
#ifndef __PIO_OFFSET
#ifdef __USE_KOS_ALTERATIONS
#define __PIO_OFFSET   __FS_TYPE(pos)
#define __PIO_OFFSET64 __pos64_t
#else /* __USE_KOS_ALTERATIONS */
#define __PIO_OFFSET   __FS_TYPE(off)
#define __PIO_OFFSET64 __off64_t
#endif /* !__USE_KOS_ALTERATIONS */
#endif /* !__PIO_OFFSET */
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_lseek32_defined
#define __local___localdep_lseek32_defined
#ifdef __CRT_HAVE_lseek
__CREDIRECT(,__off32_t,__NOTHROW_NCX,__localdep_lseek32,(__fd_t __fd, __off32_t __offset, __STDC_INT_AS_UINT_T __whence),lseek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE__lseek)
__CREDIRECT(,__off32_t,__NOTHROW_NCX,__localdep_lseek32,(__fd_t __fd, __off32_t __offset, __STDC_INT_AS_UINT_T __whence),_lseek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE___lseek)
__CREDIRECT(,__off32_t,__NOTHROW_NCX,__localdep_lseek32,(__fd_t __fd, __off32_t __offset, __STDC_INT_AS_UINT_T __whence),__lseek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE___libc_lseek)
__CREDIRECT(,__off32_t,__NOTHROW_NCX,__localdep_lseek32,(__fd_t __fd, __off32_t __offset, __STDC_INT_AS_UINT_T __whence),__libc_lseek,(__fd,__offset,__whence))
#else /* ... */
#undef __local___localdep_lseek32_defined
#endif /* !... */
#endif /* !__local___localdep_lseek32_defined */
#ifndef __local___localdep_lseek64_defined
#define __local___localdep_lseek64_defined
#if defined(__CRT_HAVE_lseek) && __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, __STDC_INT_AS_UINT_T __whence),lseek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE__lseek) && __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, __STDC_INT_AS_UINT_T __whence),_lseek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE___lseek) && __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, __STDC_INT_AS_UINT_T __whence),__lseek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE___libc_lseek) && __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, __STDC_INT_AS_UINT_T __whence),__libc_lseek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE_lseek64)
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, __STDC_INT_AS_UINT_T __whence),lseek64,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE__lseeki64)
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, __STDC_INT_AS_UINT_T __whence),_lseeki64,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE_llseek)
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, __STDC_INT_AS_UINT_T __whence),llseek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE___llseek)
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, __STDC_INT_AS_UINT_T __whence),__llseek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE_lseek) || defined(__CRT_HAVE__lseek) || defined(__CRT_HAVE___lseek) || defined(__CRT_HAVE___libc_lseek)
__NAMESPACE_LOCAL_END
#include <libc/local/unistd/lseek64.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_lseek64 __LIBC_LOCAL_NAME(lseek64)
#else /* ... */
#undef __local___localdep_lseek64_defined
#endif /* !... */
#endif /* !__local___localdep_lseek64_defined */
#if !defined(__local___localdep_pread32_defined) && defined(__CRT_HAVE_pread)
#define __local___localdep_pread32_defined
__CREDIRECT(__ATTR_NONNULL((2)),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_pread32,(__fd_t __fd, void *__buf, __SIZE_TYPE__ __bufsize, __pos32_t __offset),pread,(__fd,__buf,__bufsize,__offset))
#endif /* !__local___localdep_pread32_defined && __CRT_HAVE_pread */
#ifndef __local___localdep_read_defined
#define __local___localdep_read_defined
#ifdef __CRT_HAVE_read
__CREDIRECT(__ATTR_NONNULL((2)),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_read,(__fd_t __fd, void *__buf, __SIZE_TYPE__ __bufsize),read,(__fd,__buf,__bufsize))
#elif defined(__CRT_HAVE__read)
__CREDIRECT(__ATTR_NONNULL((2)),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_read,(__fd_t __fd, void *__buf, __SIZE_TYPE__ __bufsize),_read,(__fd,__buf,__bufsize))
#elif defined(__CRT_HAVE___read)
__CREDIRECT(__ATTR_NONNULL((2)),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_read,(__fd_t __fd, void *__buf, __SIZE_TYPE__ __bufsize),__read,(__fd,__buf,__bufsize))
#elif defined(__CRT_HAVE___libc_read)
__CREDIRECT(__ATTR_NONNULL((2)),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_read,(__fd_t __fd, void *__buf, __SIZE_TYPE__ __bufsize),__libc_read,(__fd,__buf,__bufsize))
#else /* ... */
#undef __local___localdep_read_defined
#endif /* !... */
#endif /* !__local___localdep_read_defined */
__LOCAL_LIBC(pread64) __ATTR_NONNULL((2)) __SSIZE_TYPE__
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(pread64))(__fd_t __fd, void *__buf, __SIZE_TYPE__ __bufsize, __PIO_OFFSET64 __offset) {
#ifdef __CRT_HAVE_pread
	return (__NAMESPACE_LOCAL_SYM __localdep_pread32)(__fd, __buf, __bufsize, (__pos32_t)__offset);
#elif defined(__CRT_HAVE_lseek64) || defined(__CRT_HAVE__lseeki64) || defined(__CRT_HAVE_llseek) || defined(__CRT_HAVE___llseek) || defined(__CRT_HAVE_lseek) || defined(__CRT_HAVE__lseek) || defined(__CRT_HAVE___lseek) || defined(__CRT_HAVE___libc_lseek)
	/* It may not be quick, and it may not be SMP-safe, but it'll still do the job! */
	__off64_t __oldpos;
	__SSIZE_TYPE__ __result;
	__oldpos = (__NAMESPACE_LOCAL_SYM __localdep_lseek64)(__fd, 0, __SEEK_CUR);
	if __unlikely(__oldpos < 0)
		return -1;
	if __unlikely((__NAMESPACE_LOCAL_SYM __localdep_lseek64)(__fd, (__off64_t)__offset, __SEEK_SET) < 0)
		return -1;
	__result = (__NAMESPACE_LOCAL_SYM __localdep_read)(__fd, __buf, __bufsize);
	(__NAMESPACE_LOCAL_SYM __localdep_lseek64)(__fd, __oldpos, __SEEK_SET);
	return __result;
#else /* ... */
	/* It may not be quick, and it may not be SMP-safe, but it'll still do the job! */
	__off32_t __oldpos;
	__SSIZE_TYPE__ __result;
	__oldpos = (__NAMESPACE_LOCAL_SYM __localdep_lseek32)(__fd, 0, __SEEK_CUR);
	if __unlikely(__oldpos < 0)
		return -1;
	if __unlikely((__NAMESPACE_LOCAL_SYM __localdep_lseek32)(__fd, (__off32_t)__offset, __SEEK_SET) < 0)
		return -1;
	__result = (__NAMESPACE_LOCAL_SYM __localdep_read)(__fd, __buf, __bufsize);
	(__NAMESPACE_LOCAL_SYM __localdep_lseek32)(__fd, __oldpos, __SEEK_SET);
	return __result;
#endif /* !... */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_pread64_defined
#define __local___localdep_pread64_defined
#define __localdep_pread64 __LIBC_LOCAL_NAME(pread64)
#endif /* !__local___localdep_pread64_defined */
#else /* __CRT_HAVE_pread || ((__CRT_HAVE_lseek64 || __CRT_HAVE__lseeki64 || __CRT_HAVE_llseek || __CRT_HAVE___llseek || __CRT_HAVE_lseek || __CRT_HAVE__lseek || __CRT_HAVE___lseek || __CRT_HAVE___libc_lseek) && (__CRT_HAVE_read || __CRT_HAVE__read || __CRT_HAVE___read || __CRT_HAVE___libc_read) && __SEEK_CUR && __SEEK_SET) */
#undef __local_pread64_defined
#endif /* !__CRT_HAVE_pread && ((!__CRT_HAVE_lseek64 && !__CRT_HAVE__lseeki64 && !__CRT_HAVE_llseek && !__CRT_HAVE___llseek && !__CRT_HAVE_lseek && !__CRT_HAVE__lseek && !__CRT_HAVE___lseek && !__CRT_HAVE___libc_lseek) || (!__CRT_HAVE_read && !__CRT_HAVE__read && !__CRT_HAVE___read && !__CRT_HAVE___libc_read) || !__SEEK_CUR || !__SEEK_SET) */
#endif /* !__local_pread64_defined */
