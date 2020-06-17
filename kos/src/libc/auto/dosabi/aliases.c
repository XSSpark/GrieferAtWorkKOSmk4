/* HASH CRC-32:0x5493c169 */
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
#ifndef GUARD_LIBC_AUTO_DOSABI_ALIASES_C
#define GUARD_LIBC_AUTO_DOSABI_ALIASES_C 1

#include "../../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include "../../user/aliases.h"

DECL_BEGIN

/* Get the next entry from the alias data base and put it in RESULT_BUF */
INTERN ATTR_SECTION(".text.crt.dos.database.aliases") NONNULL((1, 2, 4)) int
NOTHROW_RPC_KOS(LIBDCALL libd_getaliasent_r)(struct aliasent *__restrict result_buf,
                                             char *__restrict buffer,
                                             size_t buflen,
                                             struct aliasent **__restrict result) {
	return libc_getaliasent_r(result_buf, buffer, buflen, result);
}
/* Get alias entry corresponding to NAME */
INTERN ATTR_SECTION(".text.crt.dos.database.aliases") NONNULL((1)) struct aliasent *
NOTHROW_RPC_KOS(LIBDCALL libd_getaliasbyname)(char const *name) {
	return libc_getaliasbyname(name);
}
/* Get alias entry corresponding to NAME and put it in RESULT_BUF */
INTERN ATTR_SECTION(".text.crt.dos.database.aliases") NONNULL((1, 2, 3, 5)) int
NOTHROW_RPC_KOS(LIBDCALL libd_getaliasbyname_r)(char const *__restrict name,
                                                struct aliasent *__restrict result_buf,
                                                char *__restrict buffer,
                                                size_t buflen,
                                                struct aliasent **__restrict result) {
	return libc_getaliasbyname_r(name, result_buf, buffer, buflen, result);
}

DECL_END

DEFINE_PUBLIC_ALIAS(DOS$getaliasent_r, libd_getaliasent_r);
DEFINE_PUBLIC_ALIAS(DOS$getaliasbyname, libd_getaliasbyname);
DEFINE_PUBLIC_ALIAS(DOS$getaliasbyname_r, libd_getaliasbyname_r);

#endif /* !GUARD_LIBC_AUTO_DOSABI_ALIASES_C */
