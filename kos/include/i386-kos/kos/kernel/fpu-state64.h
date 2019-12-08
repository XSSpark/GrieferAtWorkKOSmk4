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
#ifndef _I386_KOS_KOS_KERNEL_FPU_STATE64_H
#define _I386_KOS_KOS_KERNEL_FPU_STATE64_H 1

#include <__stdinc.h>

#include <bits/types.h>

#include <ieee754.h>

#include "fpu-sstate.h"

__SYSDECL_BEGIN

#ifdef __x86_64__
#define OFFSET_XFPUSTATE_FCW        OFFSET_XFPUSTATE64_FCW
#define OFFSET_XFPUSTATE_FSW        OFFSET_XFPUSTATE64_FSW
#define OFFSET_XFPUSTATE_FTW        OFFSET_XFPUSTATE64_FTW
#define OFFSET_XFPUSTATE_FOP        OFFSET_XFPUSTATE64_FOP
#define OFFSET_XFPUSTATE_FPUIP      OFFSET_XFPUSTATE64_FPUIP
#define OFFSET_XFPUSTATE_FPUDP      OFFSET_XFPUSTATE64_FPUDP
#define OFFSET_XFPUSTATE_MXCSR      OFFSET_XFPUSTATE64_MXCSR
#define OFFSET_XFPUSTATE_MXCSR_MASK OFFSET_XFPUSTATE64_MXCSR_MASK
#define OFFSET_XFPUSTATE_ST         OFFSET_XFPUSTATE64_ST
#define OFFSET_XFPUSTATE_MM         OFFSET_XFPUSTATE64_MM
#define OFFSET_XFPUSTATE_XMM        OFFSET_XFPUSTATE64_XMM
#define SIZEOF_XFPUSTATE            SIZEOF_XFPUSTATE64
#define ALIGNOF_XFPUSTATE           ALIGNOF_XFPUSTATE64
#define xfpustate64                 xfpustate

#define SIZEOF_FPUSTATE    SIZEOF_FPUSTATE64
#define ALIGNOF_FPUSTATE   ALIGNOF_FPUSTATE64
#define fpustate64         fpustate
#endif /* __x86_64__ */

#define OFFSET_XFPUSTATE64_FCW        0
#define OFFSET_XFPUSTATE64_FSW        2
#define OFFSET_XFPUSTATE64_FTW        4
#define OFFSET_XFPUSTATE64_FOP        6
#define OFFSET_XFPUSTATE64_FPUIP      8
#define OFFSET_XFPUSTATE64_FPUDP      16
#define OFFSET_XFPUSTATE64_MXCSR      24
#define OFFSET_XFPUSTATE64_MXCSR_MASK 28
#define OFFSET_XFPUSTATE64_ST(i)      (32 + (i) * 16)
#define OFFSET_XFPUSTATE64_MM(i)      (32 + (i) * 16)
#define OFFSET_XFPUSTATE64_XMM(i)     (160 + (i) * 16)
#define SIZEOF_XFPUSTATE64            512
#define ALIGNOF_XFPUSTATE64           16
#ifdef __CC__
struct __ATTR_ALIGNED(ALIGNOF_XFPUSTATE64) xfpustate64 /*[PREFIX(fx_)]*/ {
	/* FPU context structure, as described here:
	 *   - http://asm.inightmare.org/opcodelst/index.php?op=FXSAVE
	 *   - http://x86.renejeschke.de/html/file_module_x86_id_128.html */
	__u16                     fx_fcw;        /* Floating point control word. (Set of `FCW_*') */
	__u16                     fx_fsw;        /* Floating point status word. (Set of `FSW_*') */
	__u8                      fx_ftw;        /* Compressed floating point tag word. (0 << i: FTW_EMPTY(i), 1 << i: FTW_(VALID|ZERO|SPEC)(i) (based on actually loaded value)) */
	__u8                    __fx_pad1;       /* ... */
	__u16                     fx_fop;        /* Lower 11-bit f.p. opcode. */
	__u64                     fx_fpuip;      /* FPU instruction pointer. */
	__u64                     fx_fpudp;      /* FPU data pointer. */
	__u32                     fx_mxcsr;      /* MXCSR (SSE only) (Set of `MXCSR_') */
	__u32                     fx_mxcsr_mask; /* MXCSR mask (SSE only) (Set of `MXCSR_', used to identify available features -- 11.6.6) */
	union ieee854_long_double fx_regs[8];    /* ST(i) / MMi */
	union ieee854_long_double fx_xmm[16];    /* XMMi */
	__u8                    __fx_pad4[96];
};
#endif /* __CC__ */


#define SIZEOF_FPUSTATE64   512
#define ALIGNOF_FPUSTATE64  16
#ifdef __CC__
#undef f_ssave
#undef f_xsave
struct __ATTR_ALIGNED(ALIGNOF_FPUSTATE64) fpustate64 /*[PREFIX(f_)]*/ {
	union {
		struct sfpustate   f_ssave; /* State saved by `fsave' / `fnsave' */
		struct xfpustate64 f_xsave; /* State saved by `fxsave' */
	}
#ifndef __COMPILER_HAVE_TRANSPARENT_UNION
	_f_kind
#define f_ssave _f_kind.f_ssave
#define f_xsave _f_kind.f_xsave
#endif /* !__COMPILER_HAVE_TRANSPARENT_UNION */
	;
};
#endif /* __CC__ */

__SYSDECL_END

#endif /* !_I386_KOS_KOS_KERNEL_FPU_STATE64_H */
