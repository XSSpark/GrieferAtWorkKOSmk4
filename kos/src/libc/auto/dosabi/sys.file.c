/* HASH CRC-32:0x60320f1 */
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
#ifndef GUARD_LIBC_AUTO_DOSABI_SYS_FILE_C
#define GUARD_LIBC_AUTO_DOSABI_SYS_FILE_C 1

#include "../../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include "../../user/sys.file.h"

DECL_BEGIN

/* Apply or remove an advisory lock, according to OPERATION, on the file FD refers to */
INTERN ATTR_SECTION(".text.crt.dos.unsorted") int
NOTHROW_RPC(LIBDCALL libd_flock)(fd_t fd,
                                 __STDC_INT_AS_UINT_T operation) {
	return libc_flock(fd, operation);
}

DECL_END

DEFINE_PUBLIC_ALIAS(DOS$flock, libd_flock);

#endif /* !GUARD_LIBC_AUTO_DOSABI_SYS_FILE_C */
