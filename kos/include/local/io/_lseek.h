/* HASH 0xf98c41d5 */
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
#ifndef __local__lseek_defined
#if (defined(__CRT_HAVE_lseek64) || defined(__CRT_HAVE__lseeki64))
#define __local__lseek_defined 1
#include <bits/types.h>
/* Dependency: "lseek64" from "unistd" */
#ifndef ____localdep_lseek64_defined
#define ____localdep_lseek64_defined 1
#if defined(__CRT_HAVE_lseek64)
/* >> lseek64(2)
 * Change the position of the file read/write pointer within a file referred to by `FD' */
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, int __whence),lseek64,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE_lseek) && (__SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
/* >> lseek64(2)
 * Change the position of the file read/write pointer within a file referred to by `FD' */
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, int __whence),lseek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE__lseeki64)
/* >> lseek64(2)
 * Change the position of the file read/write pointer within a file referred to by `FD' */
__CREDIRECT(,__off64_t,__NOTHROW_NCX,__localdep_lseek64,(__fd_t __fd, __off64_t __offset, int __whence),_lseeki64,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE_lseek) || defined(__CRT_HAVE__lseek)
#include <local/unistd/lseek64.h>
/* >> lseek64(2)
 * Change the position of the file read/write pointer within a file referred to by `FD' */
#define __localdep_lseek64 (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(lseek64))
#else /* CUSTOM: lseek64 */
#undef ____localdep_lseek64_defined
#endif /* lseek64... */
#endif /* !____localdep_lseek64_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_lseek) __LONG32_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_lseek))(__fd_t __fd,
                                                    __LONG32_TYPE__ __offset,
                                                    int __whence) {
#line 125 "kos/src/libc/magic/io.c"
	return __localdep_lseek64(__fd, (__off64_t)__offset, __whence);
}
__NAMESPACE_LOCAL_END
#endif /* (defined(__CRT_HAVE_lseek64) || defined(__CRT_HAVE__lseeki64)) */
#endif /* !__local__lseek_defined */
