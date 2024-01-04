/* HASH CRC-32:0x1ae64195 */
/* Copyright (c) 2019-2024 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2024 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_LIBC_AUTO_TIMEVAL_UTILS_H
#define GUARD_LIBC_AUTO_TIMEVAL_UTILS_H 1

#include "../api.h"

#include <hybrid/typecore.h>
#include <kos/types.h>
#include <timeval-utils.h>

DECL_BEGIN

#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTDEF ATTR_IN(2) ATTR_IN(3) ATTR_OUT(1) void NOTHROW_NCX(LIBDCALL libd_timeval_add)(struct timeval *result, struct timeval const *lhs, struct timeval const *rhs);
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTDEF ATTR_IN(2) ATTR_IN(3) ATTR_OUT(1) void NOTHROW_NCX(LIBCCALL libc_timeval_add)(struct timeval *result, struct timeval const *lhs, struct timeval const *rhs);
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTDEF ATTR_IN(2) ATTR_IN(3) ATTR_OUT(1) void NOTHROW_NCX(LIBDCALL libd_timeval_sub)(struct timeval *result, struct timeval const *lhs, struct timeval const *rhs);
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTDEF ATTR_IN(2) ATTR_IN(3) ATTR_OUT(1) void NOTHROW_NCX(LIBCCALL libc_timeval_sub)(struct timeval *result, struct timeval const *lhs, struct timeval const *rhs);
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTDEF ATTR_IN(2) ATTR_IN(3) ATTR_OUT(1) void NOTHROW_NCX(LIBDCALL libd_timeval_add64)(struct timeval64 *result, struct timeval64 const *lhs, struct timeval64 const *rhs);
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTDEF ATTR_IN(2) ATTR_IN(3) ATTR_OUT(1) void NOTHROW_NCX(LIBCCALL libc_timeval_add64)(struct timeval64 *result, struct timeval64 const *lhs, struct timeval64 const *rhs);
#endif /* !__KERNEL__ */
#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
INTDEF ATTR_IN(2) ATTR_IN(3) ATTR_OUT(1) void NOTHROW_NCX(LIBDCALL libd_timeval_sub64)(struct timeval64 *result, struct timeval64 const *lhs, struct timeval64 const *rhs);
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
INTDEF ATTR_IN(2) ATTR_IN(3) ATTR_OUT(1) void NOTHROW_NCX(LIBCCALL libc_timeval_sub64)(struct timeval64 *result, struct timeval64 const *lhs, struct timeval64 const *rhs);
#endif /* !__KERNEL__ */

DECL_END

#endif /* !GUARD_LIBC_AUTO_TIMEVAL_UTILS_H */
