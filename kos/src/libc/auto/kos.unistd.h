/* HASH CRC-32:0x9365daae */
/* Copyright (c) 2019-2022 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2022 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_LIBC_AUTO_KOS_UNISTD_H
#define GUARD_LIBC_AUTO_KOS_UNISTD_H 1

#include "../api.h"

#include <hybrid/typecore.h>
#include <kos/types.h>
#include <kos/unistd.h>

DECL_BEGIN

#ifndef __KERNEL__
/* >> execl(3)
 * Replace the calling process with the application image referred to by `path' / `file'
 * and execute it's  `main()' method,  passing the list  of NULL-terminated  `args'-list */
INTDEF ATTR_NORETURN ATTR_SENTINEL ATTR_IN(1) ATTR_IN_OPT(2) void (VLIBCCALL libc_Execl)(char const *__restrict path, char const *args, ...) THROWS(...);
/* >> execle(3)
 * Replace the calling process with the application image referred to by `path' / `file'
 * and  execute it's `main()'  method, passing the  list of NULL-terminated `args'-list,
 * and setting `environ' to a `char **' passed after the NULL sentinel */
INTDEF ATTR_NORETURN ATTR_IN(1) ATTR_IN_OPT(2) ATTR_SENTINEL_O(1) void (VLIBCCALL libc_Execle)(char const *__restrict path, char const *args, ...) THROWS(...);
/* >> execlp(3)
 * Replace the calling process with the application image referred to by `path' / `file'
 * and execute it's  `main()' method,  passing the list  of NULL-terminated  `args'-list */
INTDEF ATTR_NORETURN ATTR_SENTINEL ATTR_IN(1) ATTR_IN_OPT(2) void (VLIBCCALL libc_Execpl)(char const *__restrict file, char const *args, ...) THROWS(...);
/* >> execle(3)
 * Replace the calling process with the application image referred to by `path' / `file'
 * and  execute it's `main()'  method, passing the  list of NULL-terminated `args'-list,
 * and setting `environ' to a `char **' passed after the NULL sentinel */
INTDEF ATTR_NORETURN ATTR_IN(1) ATTR_IN_OPT(2) ATTR_SENTINEL_O(1) void (VLIBCCALL libc_Execlpe)(char const *__restrict file, char const *args, ...) THROWS(...);
#endif /* !__KERNEL__ */

DECL_END

#endif /* !GUARD_LIBC_AUTO_KOS_UNISTD_H */
