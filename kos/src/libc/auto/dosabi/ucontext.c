/* HASH CRC-32:0xd0a908d2 */
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
#ifndef GUARD_LIBC_AUTO_DOSABI_UCONTEXT_C
#define GUARD_LIBC_AUTO_DOSABI_UCONTEXT_C 1

#include "../../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include "../../user/ucontext.h"

DECL_BEGIN

/* Get user context and store it in variable pointed to by UCP */
INTERN ATTR_SECTION(".text.crt.dos.unsorted") NONNULL((1)) int
NOTHROW_NCX(LIBDCALL libd_getcontext)(ucontext_t *__restrict ucp) {
	return libc_getcontext(ucp);
}
/* Set user context from information of variable pointed to by UCP */
INTERN ATTR_SECTION(".text.crt.dos.unsorted") NONNULL((1)) int
NOTHROW_NCX(LIBDCALL libd_setcontext)(ucontext_t const *__restrict ucp) {
	return libc_setcontext(ucp);
}
/* Save current context in context variable pointed to by OUCP and set
 * context from variable pointed to by UCP */
INTERN ATTR_SECTION(".text.crt.dos.unsorted") NONNULL((1, 2)) int
NOTHROW_NCX(LIBDCALL libd_swapcontext)(ucontext_t *__restrict oucp,
                                       ucontext_t const *__restrict ucp) {
	return libc_swapcontext(oucp, ucp);
}

DECL_END

DEFINE_PUBLIC_ALIAS(DOS$getcontext, libd_getcontext);
DEFINE_PUBLIC_ALIAS(DOS$setcontext, libd_setcontext);
DEFINE_PUBLIC_ALIAS(DOS$swapcontext, libd_swapcontext);

#endif /* !GUARD_LIBC_AUTO_DOSABI_UCONTEXT_C */
