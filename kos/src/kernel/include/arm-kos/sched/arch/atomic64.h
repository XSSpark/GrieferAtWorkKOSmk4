/* Copyright (c) 2019-2022 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2022 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_KERNEL_INCLUDE_ARM_KOS_SCHED_ARCH_ATOMIC64_H
#define GUARD_KERNEL_INCLUDE_ARM_KOS_SCHED_ARCH_ATOMIC64_H 1

/* ARM always supports 64-bit atomics (s.a. <arm-kos/README.md>) */
#undef ARCH_HAVE_ATOMIC64_SUPPORT_NEVER
#undef ARCH_HAVE_ATOMIC64_SUPPORT_ALWAYS
#undef ARCH_HAVE_ATOMIC64_SUPPORT_DYNAMIC
#define ARCH_HAVE_ATOMIC64_SUPPORT_ALWAYS

#endif /* !GUARD_KERNEL_INCLUDE_ARM_KOS_SCHED_ARCH_ATOMIC64_H */
