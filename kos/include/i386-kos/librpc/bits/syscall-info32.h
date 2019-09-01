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
#ifndef _I386_KOS_LIBRPC_BITS_SYSCALL_INFO32_H
#define _I386_KOS_LIBRPC_BITS_SYSCALL_INFO32_H 1

#include <__stdinc.h>
#include <hybrid/typecore.h>
#include <hybrid/host.h>

__DECL_BEGIN

#ifndef __x86_64__
#ifndef __rpc_syscall_info_defined
#define __rpc_syscall_info_defined 1
#define OFFSET_RPC_SYSCALL_INFO_FLAGS OFFSET_RPC_SYSCALL_INFO32_FLAGS
#define OFFSET_RPC_SYSCALL_INFO_SYSNO OFFSET_RPC_SYSCALL_INFO32_SYSNO
#define OFFSET_RPC_SYSCALL_INFO_ARG   OFFSET_RPC_SYSCALL_INFO32_ARG
#define SIZEOF_RPC_SYSCALL_INFO       SIZEOF_RPC_SYSCALL_INFO32
#define rpc_syscall_info32            rpc_syscall_info
#endif /* !__rpc_syscall_info_defined */
#endif /* !__x86_64__ */


#define OFFSET_RPC_SYSCALL_INFO32_FLAGS      0
#define OFFSET_RPC_SYSCALL_INFO32_SYSNO      4
#define OFFSET_RPC_SYSCALL_INFO32_ARG(i)  (((i) + 2) * 4)
#define SIZEOF_RPC_SYSCALL_INFO32            32
#ifdef __CC__
struct rpc_syscall_info32 /*[PREFIX(rsi_)]*/ {
	/* Structure pushed by `RPC_PROGRAM_OP_psh_sys' */
	__UINT32_TYPE__  rsi_flags;   /* System call invocation flags (Set of `RPC_SYSCALL_INFO_F*') */
	__UINT32_TYPE__  rsi_sysno;   /* The system call vector that got invoked. */
	__UINT32_TYPE__  rsi_args[6]; /* Arguments passed to the system call.
	                               * NOTE: You may validate any argument by testing for `RPC_SYSCALL_INFO_FARGVALID(i)' */
};
#endif /* __CC__ */

__DECL_END

#endif /* !_I386_KOS_LIBRPC_BITS_SYSCALL_INFO32_H */
