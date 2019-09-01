/* HASH 0x5adb6d1 */
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
#ifndef GUARD_LIBC_USER_SYS_EVENTFD_H
#define GUARD_LIBC_USER_SYS_EVENTFD_H 1

#include "../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include <sys/eventfd.h>

DECL_BEGIN

/* Return file descriptor for generic event channel. Set initial value to COUNT */
INTDEF WUNUSED fd_t NOTHROW_NCX(LIBCCALL libc_eventfd)(unsigned int count, int flags);
/* Read event counter and possibly wait for events */
INTDEF int NOTHROW_RPC(LIBCCALL libc_eventfd_read)(fd_t fd, eventfd_t *value);
/* Increment event counter */
INTDEF int NOTHROW_RPC(LIBCCALL libc_eventfd_write)(fd_t fd, eventfd_t value);

DECL_END

#endif /* !GUARD_LIBC_USER_SYS_EVENTFD_H */
