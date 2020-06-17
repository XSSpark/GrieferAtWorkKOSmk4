/* HASH CRC-32:0x92f4ff45 */
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
#ifndef GUARD_LIBC_AUTO_DOSABI_ENVZ_C
#define GUARD_LIBC_AUTO_DOSABI_ENVZ_C 1

#include "../../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include "../envz.h"

DECL_BEGIN

/* Returns a pointer to the entry in `ENVZ' for `NAME', or `NULL' if there is none
 * Note that if `name' contains a `=' character, only characters leading up to this
 * position are actually compared! */
INTERN ATTR_SECTION(".text.crt.dos.string.envz") ATTR_PURE WUNUSED NONNULL((3)) char *
NOTHROW_NCX(LIBDCALL libd_envz_entry)(char const *__restrict envz,
                                      size_t envz_len,
                                      char const *__restrict name) {
	return libc_envz_entry(envz, envz_len, name);
}
/* Returns a pointer to the value portion of the entry
 * in `ENVZ' for `NAME', or `NULL' if there is none. */
INTERN ATTR_SECTION(".text.crt.dos.string.envz") ATTR_PURE WUNUSED NONNULL((3)) char *
NOTHROW_NCX(LIBDCALL libd_envz_get)(char const *__restrict envz,
                                    size_t envz_len,
                                    char const *__restrict name) {
	return libc_envz_get(envz, envz_len, name);
}
/* Adds an entry for `NAME' with value `VALUE' to `ENVZ & ENVZ_LEN'. If an entry
 * with the same name already exists in `ENVZ', it is removed. If `VALUE' is
 * `NULL', then the new entry will not have a value portion, meaning that `envz_get()'
 * will return `NULL', although `envz_entry()' will still return an entry. This is handy
 * because when merging with another envz, the null entry can override an
 * entry in the other one. Such entries can be removed with `envz_strip()' */
INTERN ATTR_SECTION(".text.crt.dos.string.envz") NONNULL((1, 2, 3)) error_t
NOTHROW_NCX(LIBDCALL libd_envz_add)(char **__restrict penvz,
                                    size_t *__restrict penvz_len,
                                    char const *__restrict name,
                                    char const *value) {
	return libc_envz_add(penvz, penvz_len, name, value);
}
/* Adds each entry in `ENVZ2' to `ENVZ & ENVZ_LEN', as if with `envz_add()'.
 * If `OVERRIDE' is true, then values in `ENVZ2' will supersede those
 * with the same name in `ENV', otherwise they don't */
INTERN ATTR_SECTION(".text.crt.dos.string.envz") NONNULL((1, 2, 3)) error_t
NOTHROW_NCX(LIBDCALL libd_envz_merge)(char **__restrict penvz,
                                      size_t *__restrict penvz_len,
                                      char const *__restrict envz2,
                                      size_t envz2_len,
                                      int override_) {
	return libc_envz_merge(penvz, penvz_len, envz2, envz2_len, override_);
}
/* Remove the entry for `NAME' from `ENVZ & ENVZ_LEN', if any */
INTERN ATTR_SECTION(".text.crt.dos.string.envz") NONNULL((1, 2, 3)) void
NOTHROW_NCX(LIBDCALL libd_envz_remove)(char **__restrict penvz,
                                       size_t *__restrict penvz_len,
                                       char const *__restrict name) {
	libc_envz_remove(penvz, penvz_len, name);
}
/* Remove entries that have no value attached */
INTERN ATTR_SECTION(".text.crt.dos.string.envz") NONNULL((1, 2)) void
NOTHROW_NCX(LIBDCALL libd_envz_strip)(char **__restrict penvz,
                                      size_t *__restrict penvz_len) {
	libc_envz_strip(penvz, penvz_len);
}

DECL_END

DEFINE_PUBLIC_ALIAS(DOS$envz_entry, libd_envz_entry);
DEFINE_PUBLIC_ALIAS(DOS$envz_get, libd_envz_get);
DEFINE_PUBLIC_ALIAS(DOS$envz_add, libd_envz_add);
DEFINE_PUBLIC_ALIAS(DOS$envz_merge, libd_envz_merge);
DEFINE_PUBLIC_ALIAS(DOS$envz_remove, libd_envz_remove);
DEFINE_PUBLIC_ALIAS(DOS$envz_strip, libd_envz_strip);

#endif /* !GUARD_LIBC_AUTO_DOSABI_ENVZ_C */
