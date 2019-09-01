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
#ifndef GUARD_KERNEL_INCLUDE_KERNEL_SYSCALL_H
#define GUARD_KERNEL_INCLUDE_KERNEL_SYSCALL_H 1

/* If <sym/unistd.h> was already included, reset its guard
 * if we didn't get everything we needed the previous time. */
#ifdef _ASM_UNISTD_H
#if !defined(__WANT_SYSCALL_ARGUMENT_COUNT) || \
    !defined(__WANT_SYSCALL_ARGUMENT_TYPES) || \
    !defined(__WANT_SYSCALL_RETURN_TYPES)
#undef _ASM_UNISTD_H
#endif /* !... */
#endif /* _ASM_UNISTD_H */
#define __WANT_SYSCALL_ARGUMENT_COUNT 1
#define __WANT_SYSCALL_ARGUMENT_TYPES 1
#define __WANT_SYSCALL_RETURN_TYPES 1

#include <__crt.h>
#include <kernel/compiler.h>

#include <kernel/arch/syscall.h>
#include <kernel/types.h>

#include <bits/format-printer.h>
#include <kos/syscalls.h>

DECL_BEGIN

#ifndef ATTR_SECTION_SYSCALL
#define ATTR_SECTION_SYSCALL(name) /* nothing */
#endif /* !ATTR_SECTION_SYSCALL */

#ifndef __ARCH_SYSCALLCC
#define __ARCH_SYSCALLCC KCALL
#endif
#ifndef __ARCH_DEFINE_SYSCALL_COMMON
#define __ARCH_DEFINE_SYSCALL_COMMON(name) /* nothing */
#endif /* !__ARCH_DEFINE_SYSCALL_COMMON */

#ifdef __CC__

#ifdef CONFIG_BUILDING_KERNEL_CORE
#define DEFINE_SYSCALL0(return_type, name)                                           \
	STATIC_ASSERT(__NRAC_##name == 0);                                               \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRRT_##name, return_type));         \
	__ARCH_DEFINE_SYSCALL_COMMON(name)                                               \
	FUNDEF return_type __ARCH_SYSCALLCC impl_sys_##name(void) ASMNAME("sys_" #name); \
	PUBLIC ATTR_SECTION_SYSCALL(name) return_type __ARCH_SYSCALLCC impl_sys_##name(void)
#define DEFINE_SYSCALL1(return_type, name, T0, N0)                                    \
	STATIC_ASSERT(__NRAC_##name == 1);                                                \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRRT_##name, return_type));          \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT0_##name, T0));                  \
	__ARCH_DEFINE_SYSCALL_COMMON(name)                                                \
	FUNDEF return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0) ASMNAME("sys_" #name); \
	PUBLIC ATTR_SECTION_SYSCALL(name) return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0)
#define DEFINE_SYSCALL2(return_type, name, T0, N0, T1, N1)                                   \
	STATIC_ASSERT(__NRAC_##name == 2);                                                       \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRRT_##name, return_type));                 \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT0_##name, T0));                         \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT1_##name, T1));                         \
	__ARCH_DEFINE_SYSCALL_COMMON(name)                                                       \
	FUNDEF return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0, T1 N1) ASMNAME("sys_" #name); \
	PUBLIC ATTR_SECTION_SYSCALL(name) return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0, T1 N1)
#define DEFINE_SYSCALL3(return_type, name, T0, N0, T1, N1, T2, N2)                                  \
	STATIC_ASSERT(__NRAC_##name == 3);                                                              \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRRT_##name, return_type));                        \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT0_##name, T0));                                \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT1_##name, T1));                                \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT2_##name, T2));                                \
	__ARCH_DEFINE_SYSCALL_COMMON(name)                                                              \
	FUNDEF return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0, T1 N1, T2 N2) ASMNAME("sys_" #name); \
	PUBLIC ATTR_SECTION_SYSCALL(name) return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0, T1 N1, T2 N2)
#define DEFINE_SYSCALL4(return_type, name, T0, N0, T1, N1, T2, N2, T3, N3)                                 \
	STATIC_ASSERT(__NRAC_##name == 4);                                                                     \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRRT_##name, return_type));                               \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT0_##name, T0));                                       \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT1_##name, T1));                                       \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT2_##name, T2));                                       \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT3_##name, T3));                                       \
	__ARCH_DEFINE_SYSCALL_COMMON(name)                                                                     \
	FUNDEF return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0, T1 N1, T2 N2, T3 N3) ASMNAME("sys_" #name); \
	PUBLIC ATTR_SECTION_SYSCALL(name) return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0, T1 N1, T2 N2, T3 N3)
#define DEFINE_SYSCALL5(return_type, name, T0, N0, T1, N1, T2, N2, T3, N3, T4, N4)                                \
	STATIC_ASSERT(__NRAC_##name == 5);                                                                            \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRRT_##name, return_type));                                      \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT0_##name, T0));                                              \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT1_##name, T1));                                              \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT2_##name, T2));                                              \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT3_##name, T3));                                              \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT4_##name, T4));                                              \
	__ARCH_DEFINE_SYSCALL_COMMON(name)                                                                            \
	FUNDEF return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0, T1 N1, T2 N2, T3 N3, T4 N4) ASMNAME("sys_" #name); \
	PUBLIC ATTR_SECTION_SYSCALL(name) return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0, T1 N1, T2 N2, T3 N3, T4 N4)
#define DEFINE_SYSCALL6(return_type, name, T0, N0, T1, N1, T2, N2, T3, N3, T4, N4, T5, N5)                               \
	STATIC_ASSERT(__NRAC_##name == 6);                                                                                   \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRRT_##name, return_type));                                             \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT0_##name, T0));                                                     \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT1_##name, T1));                                                     \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT2_##name, T2));                                                     \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT3_##name, T3));                                                     \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT4_##name, T4));                                                     \
	STATIC_ASSERT(__builtin_types_compatible_p(__NRAT5_##name, T5));                                                     \
	__ARCH_DEFINE_SYSCALL_COMMON(name)                                                                                   \
	FUNDEF return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0, T1 N1, T2 N2, T3 N3, T4 N4, T5 N5) ASMNAME("sys_" #name); \
	PUBLIC ATTR_SECTION_SYSCALL(name) return_type __ARCH_SYSCALLCC impl_sys_##name(T0 N0, T1 N1, T2 N2, T3 N3, T4 N4, T5 N5)
#endif /* CONFIG_BUILDING_KERNEL_CORE */


#ifndef CONFIG_NO_SYSCALL_TRACING
/* Enable/disable system call tracing.
 * @return: true:  Successfully changed the current tracing state.
 * @return: false: Tracing was already enabled/disabled. */
FUNDEF bool (KCALL syscall_tracing_setenabled)(bool enable);
/* Check if system call tracing is enabled. */
FUNDEF WUNUSED bool NOTHROW(KCALL syscall_tracing_getenabled)(void);


struct syscall_trace_args {
	syscall_ulong_t ta_sysno;
	syscall_ulong_t ta_arg0;
	syscall_ulong_t ta_arg1;
	syscall_ulong_t ta_arg2;
	syscall_ulong_t ta_arg3;
	syscall_ulong_t ta_arg4;
	syscall_ulong_t ta_arg5;
};

FUNDEF void FCALL syscall_trace(struct syscall_trace_args const *__restrict args);
FUNDEF ssize_t KCALL
syscall_printtrace(__pformatprinter printer, void *arg,
                   struct syscall_trace_args const *__restrict args);
#else /* !CONFIG_NO_SYSCALL_TRACING */
#define syscall_tracing_getenabled()  false
#endif /* CONFIG_NO_SYSCALL_TRACING */

struct icpustate;

/* Emulate a system call invocation, with arguments passed via the
 * standard argument passage mechanism, using the given `regs'.
 * On i386, this means that arguments are found in `regs->ics_irregs_u.ir_esp'
 * @param: regs:          The user-space register context from which to
 *                        take arguments to-be passed to the system call.
 * @param: sysno:         The system call ID that is being invoked.
 * @param: enable_except: When true, enable support for exceptions.
 *                        Otherwise, translate exceptions to errno codes,
 *                        and write them into the return register of `regs'. */
FUNDEF struct icpustate *FCALL
syscall_emulate_callback(struct icpustate *__restrict regs,
                         uintptr_t sysno,
                         bool enable_except);

struct rpc_syscall_info;
/* Emulate a system call, given its all possible information about it.
 * @param: regs:    The user-space register context in which the
 *                  system call should be executed.
 * @param: sc_info: Information about the system call that should be emulated. */
FUNDEF struct icpustate *FCALL
syscall_emulate(struct icpustate *__restrict regs,
                struct rpc_syscall_info *__restrict sc_info);

#endif /* !__CC__ */




DECL_END

#endif /* !GUARD_KERNEL_INCLUDE_KERNEL_SYSCALL_H */
