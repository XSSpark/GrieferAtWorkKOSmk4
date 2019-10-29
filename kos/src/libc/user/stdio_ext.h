/* HASH CRC-32:0x9e4aae3c */
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
#ifndef GUARD_LIBC_USER_STDIO_EXT_H
#define GUARD_LIBC_USER_STDIO_EXT_H 1

#include "../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include <stdio_ext.h>

DECL_BEGIN

/* Return the size of the buffer of FP in bytes currently in use by the given stream */
INTDEF ATTR_PURE WUNUSED NONNULL((1)) size_t NOTHROW_NCX(LIBCCALL libc___fbufsize)(FILE *fp);
/* Return non-zero value iff the stream FP is opened readonly,
 * or if the last operation on the stream was a read operation */
INTDEF ATTR_PURE WUNUSED NONNULL((1)) int NOTHROW_NCX(LIBCCALL libc___freading)(FILE *fp);
/* Return non-zero value iff the stream FP is opened write-only or
 * append-only, or if the last operation on the stream was a write
 * operation */
INTDEF ATTR_PURE WUNUSED NONNULL((1)) int NOTHROW_NCX(LIBCCALL libc___fwriting)(FILE *fp);
/* Return non-zero value iff stream FP is not opened write-only or append-only */
INTDEF ATTR_PURE WUNUSED NONNULL((1)) int NOTHROW_NCX(LIBCCALL libc___freadable)(FILE *fp);
/* Return non-zero value iff stream FP is not opened read-only */
INTDEF ATTR_PURE WUNUSED NONNULL((1)) int NOTHROW_NCX(LIBCCALL libc___fwritable)(FILE *fp);
/* Return non-zero value iff the stream FP is line-buffered */
INTDEF ATTR_PURE WUNUSED NONNULL((1)) int NOTHROW_NCX(LIBCCALL libc___flbf)(FILE *fp);
/* Discard all pending buffered I/O on the stream FP */
INTDEF NONNULL((1)) void NOTHROW_NCX(LIBCCALL libc___fpurge)(FILE *fp);
/* Return amount of output in bytes pending on a stream FP */
INTDEF ATTR_PURE WUNUSED NONNULL((1)) size_t NOTHROW_NCX(LIBCCALL libc___fpending)(FILE *fp);
/* Flush all line-buffered files */
INTDEF void NOTHROW_NCX(LIBCCALL libc__flushlbf)(void);
/* Set locking status of stream FP to TYPE */
INTDEF NONNULL((1)) int NOTHROW_NCX(LIBCCALL libc___fsetlocking)(FILE *fp, int type);

DECL_END

#endif /* !GUARD_LIBC_USER_STDIO_EXT_H */
