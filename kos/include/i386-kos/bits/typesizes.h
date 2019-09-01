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
#ifndef _I386_KOS_BITS_TYPESIZES_H
#define _I386_KOS_BITS_TYPESIZES_H 1

#include <__stdinc.h>
#include <hybrid/host.h>

/* Override: Due to historical reasons, sizeof(socklen_t) == sizeof(int) */
#define __SIZEOF_SOCKLEN_T__        4

#define __SIZEOF_OFF32_T__          __SIZEOF_SYSCALL_LONG_T__
#define __SIZEOF_BLKCNT32_T__       __SIZEOF_SYSCALL_LONG_T__
#define __SIZEOF_FSBLKCNT32_T__     __SIZEOF_SYSCALL_LONG_T__
#define __SIZEOF_FSFILCNT32_T__     __SIZEOF_SYSCALL_LONG_T__
#define __SIZEOF_INO32_T__          __SIZEOF_SYSCALL_LONG_T__
#define __SIZEOF_RLIM32_T__         __SIZEOF_SYSCALL_LONG_T__
#define __SIZEOF_TIME32_T__         __SIZEOF_SYSCALL_LONG_T__
#define __SIZEOF_USECOND_T__        4
#define __SIZEOF_SUSECONDS_T__      __SIZEOF_SYSCALL_LONG_T__
#define __SIZEOF_CLOCKID_T__        4
#define __SIZEOF_CLOCK_T__          __SIZEOF_SYSCALL_LONG_T__
#ifdef __x86_64__
#define __SIZEOF_IOMODE_T__         4
#else /* __x86_64__ */
#define __SIZEOF_IOMODE_T__         2
#endif /* !__x86_64__ */


#endif /* !_I386_KOS_BITS_TYPESIZES_H */
