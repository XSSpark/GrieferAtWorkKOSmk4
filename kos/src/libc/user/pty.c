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
#ifndef GUARD_LIBC_USER_PTY_C
#define GUARD_LIBC_USER_PTY_C 1

#include "../api.h"
/**/

#include <kos/syscalls.h>

#include <stdlib.h>
#include <unistd.h>
#include <utmp.h>

#include "pty.h"

DECL_BEGIN

/*[[[head:libc_openpty,hash:CRC-32=0x874698f6]]]*/
/* Create pseudo tty master slave pair with NAME and set terminal
 * attributes according to TERMP and WINP and return handles for
 * both ends in AMASTER and ASLAVE */
INTERN ATTR_SECTION(".text.crt.io.tty") NONNULL((1, 2)) int
NOTHROW_NCX(LIBCCALL libc_openpty)(fd_t *amaster,
                                   fd_t *aslave,
                                   char *name,
                                   struct termios const *termp,
                                   struct winsize const *winp)
/*[[[body:libc_openpty]]]*/
{
	errno_t result;
	result = sys_openpty(amaster,
	                     aslave,
	                     name,
	                     termp,
	                     winp);
	return libc_seterrno_syserr(result);
}
/*[[[end:libc_openpty]]]*/



/*[[[start:exports,hash:CRC-32=0x624b46dc]]]*/
DEFINE_PUBLIC_ALIAS(openpty, libc_openpty);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_PTY_C */
