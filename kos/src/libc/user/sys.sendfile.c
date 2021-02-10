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
#ifndef GUARD_LIBC_USER_SYS_SENDFILE_C
#define GUARD_LIBC_USER_SYS_SENDFILE_C 1

#include "../api.h"
#include "sys.sendfile.h"
#include <kos/syscalls.h>

DECL_BEGIN







/*[[[head:libc_sendfile,hash:CRC-32=0x4be9e70a]]]*/
INTERN ATTR_SECTION(".text.crt.fs.statfs.statfs") ssize_t
NOTHROW_NCX(LIBCCALL libc_sendfile)(fd_t out_fd,
                                    fd_t in_fd,
                                    off_t *offset,
                                    size_t count)
/*[[[body:libc_sendfile]]]*/
{
	ssize_t result;
	result = sys_sendfile(out_fd, in_fd, (syscall_ulong_t *)offset, count);
	return libc_seterrno_syserr(result);
}
/*[[[end:libc_sendfile]]]*/

/*[[[head:libc_sendfile64,hash:CRC-32=0x3a61efef]]]*/
#if __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__
DEFINE_INTERN_ALIAS(libc_sendfile64, libc_sendfile);
#else /* MAGIC:alias */
INTERN ATTR_SECTION(".text.crt.fs.statfs.statfs") ssize_t
NOTHROW_NCX(LIBCCALL libc_sendfile64)(fd_t out_fd,
                                      fd_t in_fd,
                                      off64_t *offset,
                                      size_t count)
/*[[[body:libc_sendfile64]]]*/
{
	ssize_t result;
	result = sys_sendfile64(out_fd, in_fd, (uint64_t *)offset, count);
	return libc_seterrno_syserr(result);
}
#endif /* MAGIC:alias */
/*[[[end:libc_sendfile64]]]*/





/*[[[start:exports,hash:CRC-32=0x7772fdfe]]]*/
DEFINE_PUBLIC_ALIAS(sendfile, libc_sendfile);
DEFINE_PUBLIC_ALIAS(sendfile64, libc_sendfile64);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_SYS_SENDFILE_C */
