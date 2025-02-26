/* HASH CRC-32:0xcf8bbf81 */
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
#ifndef __local_lchmod_defined
#define __local_lchmod_defined
#include <__crt.h>
#include <asm/os/fcntl.h>
#if defined(__AT_FDCWD) && defined(__AT_SYMLINK_NOFOLLOW) && defined(__CRT_HAVE_fchmodat)
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_fchmodat_defined
#define __local___localdep_fchmodat_defined
__CREDIRECT(__ATTR_IN(2),int,__NOTHROW_RPC,__localdep_fchmodat,(__fd_t __dirfd, char const *__filename, __mode_t __mode, __atflag_t __flags),fchmodat,(__dirfd,__filename,__mode,__flags))
#endif /* !__local___localdep_fchmodat_defined */
__LOCAL_LIBC(lchmod) __ATTR_IN(1) int
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(lchmod))(char const *__filename, __mode_t __mode) {
	return (__NAMESPACE_LOCAL_SYM __localdep_fchmodat)(__AT_FDCWD, __filename, __mode, __AT_SYMLINK_NOFOLLOW);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_lchmod_defined
#define __local___localdep_lchmod_defined
#define __localdep_lchmod __LIBC_LOCAL_NAME(lchmod)
#endif /* !__local___localdep_lchmod_defined */
#else /* __AT_FDCWD && __AT_SYMLINK_NOFOLLOW && __CRT_HAVE_fchmodat */
#undef __local_lchmod_defined
#endif /* !__AT_FDCWD || !__AT_SYMLINK_NOFOLLOW || !__CRT_HAVE_fchmodat */
#endif /* !__local_lchmod_defined */
