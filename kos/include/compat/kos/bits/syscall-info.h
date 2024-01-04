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
#ifndef _COMPAT_KOS_BITS_FUTEX_EXPR_H
#define _COMPAT_KOS_BITS_FUTEX_EXPR_H 1

#include <compat/config.h>
#ifdef __ARCH_HAVE_COMPAT
#include <kos/bits/syscall-info.h>
#define OFFSET_COMPAT_RPC_SYSCALL_INFO_FLAGS OFFSET_RPC_SYSCALL_INFO_FLAGS
#define OFFSET_COMPAT_RPC_SYSCALL_INFO_SYSNO OFFSET_RPC_SYSCALL_INFO_SYSNO
#define OFFSET_COMPAT_RPC_SYSCALL_INFO_REG   OFFSET_RPC_SYSCALL_INFO_REG
#define SIZEOF_COMPAT_RPC_SYSCALL_INFO       SIZEOF_RPC_SYSCALL_INFO
#define compat_rpc_syscall_info              rpc_syscall_info
#endif /* __ARCH_HAVE_COMPAT */

#endif /* !_COMPAT_KOS_BITS_FUTEX_EXPR_H */
