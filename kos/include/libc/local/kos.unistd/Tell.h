/* HASH CRC-32:0xaff8eaec */
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
#ifndef __local_Tell_defined
#define __local_Tell_defined
#include <__crt.h>
#include <asm/os/stdio.h>
#include <features.h>
#include <bits/types.h>
#if (defined(__CRT_HAVE_LSeek64) || defined(__CRT_HAVE_LSeek)) && defined(__SEEK_CUR)
#include <kos/anno.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_LSeek_defined
#define __local___localdep_LSeek_defined
#if defined(__CRT_HAVE_LSeek) && (!defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT(__ATTR_FDARG(1),__pos_t,__THROWING(...),__localdep_LSeek,(__fd_t __fd, __off_t __offset, int __whence),LSeek,(__fd,__offset,__whence))
#elif defined(__CRT_HAVE_LSeek64) && (defined(__USE_FILE_OFFSET64) || __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__)
__CREDIRECT(__ATTR_FDARG(1),__pos_t,__THROWING(...),__localdep_LSeek,(__fd_t __fd, __off_t __offset, int __whence),LSeek64,(__fd,__offset,__whence))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/kos.unistd/LSeek.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_LSeek __LIBC_LOCAL_NAME(LSeek)
#endif /* !... */
#endif /* !__local___localdep_LSeek_defined */
__LOCAL_LIBC(Tell) __ATTR_WUNUSED __ATTR_FDARG(1) __pos_t
(__LIBCCALL __LIBC_LOCAL_NAME(Tell))(__fd_t __fd) __THROWS(...) {
	return (__NAMESPACE_LOCAL_SYM __localdep_LSeek)(__fd, 0, __SEEK_CUR);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_Tell_defined
#define __local___localdep_Tell_defined
#define __localdep_Tell __LIBC_LOCAL_NAME(Tell)
#endif /* !__local___localdep_Tell_defined */
#else /* (__CRT_HAVE_LSeek64 || __CRT_HAVE_LSeek) && __SEEK_CUR */
#undef __local_Tell_defined
#endif /* (!__CRT_HAVE_LSeek64 && !__CRT_HAVE_LSeek) || !__SEEK_CUR */
#endif /* !__local_Tell_defined */
