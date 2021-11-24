/* HASH CRC-32:0x34287c17 */
/* Copyright (c) 2019-2021 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2021 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef _KOS_HOP_API_H
#define _KOS_HOP_API_H 1

#include <__stdinc.h>
#include <__crt.h>

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <hybrid/typecore.h>

#include <bits/types.h>
#include <kos/anno.h>
#include <kos/kernel/handle.h>

#ifndef HOP_CMD
#define HOP_CMD(handle_type, cmd) (__CCAST(__uint32_t)(handle_type) << 16 | __CCAST(__uint32_t)(cmd))
#endif /* !HOP_CMD */

#if defined(__KERNEL__) && __SIZEOF_SIZE_T__ < 8
#define __HOP_SIZE64_FIELD(name) union { __size_t name; __uint64_t __##name##64; }
#else /* __KERNEL__ */
/* For compatibility, user-space must always write the full 64-bit field,
 * while  the  kernel   will  only  ever   read  a  size_t-sized   field.
 * This is required when a 32-bit application is running under a 64-bit kernel,
 * allowing the  kernel to  not have  to  look out  for user-space  running  in
 * compatibility  mode,  but can  instead always  read  the full  64-bit value,
 * which is simply zero-extended from 32-bit by user-space. */
#define __HOP_SIZE64_FIELD(name) __uint64_t name
#endif /* !__KERNEL__ */

#ifndef __HOP_PAD_POINTER
#if __SIZEOF_POINTER__ < 8
#define __HOP_PAD_POINTER(name) __uint32_t name;
#else /* __SIZEOF_POINTER__ < 8 */
#define __HOP_PAD_POINTER(name) /* nothing */
#endif /* __SIZEOF_POINTER__ >= 8 */
#endif /* !__HOP_PAD_POINTER */

#ifdef __CC__
__SYSDECL_BEGIN

#if !defined(__hop_defined) && defined(__CRT_HAVE_hop)
#define __hop_defined
/* Perform a handle operation specified by `cmd'
 * @param: cmd: One of `HOP_<type>_<command>' */
__LIBC __syscall_slong_t __NOTHROW_NCX(__VLIBCCALL hop)(__fd_t __fd, __ioctl_t __cmd, ...) __CASMNAME_SAME("hop");
#endif /* !__hop_defined && __CRT_HAVE_hop */
#if !defined(__hopf_defined) && defined(__CRT_HAVE_hopf)
#define __hopf_defined
/* Perform a handle operation specified by `cmd'
 * @param: cmd: One of `HOP_<type>_<command>' */
__LIBC __syscall_slong_t __NOTHROW_NCX(__VLIBCCALL hopf)(__fd_t __fd, __ioctl_t __cmd, __iomode_t __mode, ...) __CASMNAME_SAME("hopf");
#endif /* !__hopf_defined && __CRT_HAVE_hopf */



/* Exception-enabled variants */

#if !defined(__Hop_defined) && defined(__CRT_HAVE_Hop)
#define __Hop_defined
/* Perform a handle operation specified by `cmd'
 * @param: cmd: One of `HOP_<type>_<command>' */
__LIBC __syscall_slong_t (__VLIBCCALL Hop)(__fd_t __fd, __ioctl_t __cmd, ...) __THROWS(...) __CASMNAME_SAME("Hop");
#endif /* !__Hop_defined && __CRT_HAVE_Hop */
#if !defined(__Hopf_defined) && defined(__CRT_HAVE_Hopf)
#define __Hopf_defined
/* Perform a handle operation specified by `cmd'
 * @param: cmd: One of `HOP_<type>_<command>' */
__LIBC __syscall_slong_t (__VLIBCCALL Hopf)(__fd_t __fd, __ioctl_t __cmd, __iomode_t __mode, ...) __THROWS(...) __CASMNAME_SAME("Hopf");
#endif /* !__Hopf_defined && __CRT_HAVE_Hopf */

__SYSDECL_END
#endif /* __CC__ */

#endif /* !_KOS_HOP_API_H */
