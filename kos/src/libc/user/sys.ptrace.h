/* HASH CRC-32:0xa4427b0c */
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
#ifndef GUARD_LIBC_USER_SYS_PTRACE_H
#define GUARD_LIBC_USER_SYS_PTRACE_H 1

#include "../api.h"

#include <hybrid/typecore.h>
#include <kos/types.h>
#include <sys/ptrace.h>

DECL_BEGIN

#if !defined(__LIBCCALL_IS_LIBDCALL) && !defined(__KERNEL__)
/* Perform process tracing functions. REQUEST is one of
 * the values above, and determines the action to be taken.
 * For all requests except PTRACE_TRACEME, PID specifies the process to be traced.
 *
 * PID and the other arguments described above for the various requests should
 * appear (those that are used for the particular request) as:
 *     pid_t PID, void *ADDR, int DATA, void *ADDR2
 * after REQUEST */
INTDEF longptr_t NOTHROW_NCX(VLIBDCALL libd_ptrace)(__ptrace_request_t request, ...);
#endif /* !__LIBCCALL_IS_LIBDCALL && !__KERNEL__ */
#ifndef __KERNEL__
/* Perform process tracing functions. REQUEST is one of
 * the values above, and determines the action to be taken.
 * For all requests except PTRACE_TRACEME, PID specifies the process to be traced.
 *
 * PID and the other arguments described above for the various requests should
 * appear (those that are used for the particular request) as:
 *     pid_t PID, void *ADDR, int DATA, void *ADDR2
 * after REQUEST */
INTDEF longptr_t NOTHROW_NCX(VLIBCCALL libc_ptrace)(__ptrace_request_t request, ...);
#endif /* !__KERNEL__ */

DECL_END

#endif /* !GUARD_LIBC_USER_SYS_PTRACE_H */
