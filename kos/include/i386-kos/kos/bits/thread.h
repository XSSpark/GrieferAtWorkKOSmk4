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
#ifndef _I386_KOS_KOS_BITS_THREAD_H
#define _I386_KOS_KOS_BITS_THREAD_H 1

#include <__stdinc.h>
#include <hybrid/host.h>
#include <asm/intrin.h>

#ifdef __x86_64__
#define RD_TLS_BASE_REGISTER()   __rdgsptr(0)
#define RD_TLS_BASE_REGISTER_S() __rdgsbase()
#define WR_TLS_BASE_REGISTER(v)  __wrgsbase(v)
#else /* __x86_64__ */
#define RD_TLS_BASE_REGISTER()   __rdfsptr(0)
#define RD_TLS_BASE_REGISTER_S() __rdfsbase()
#define WR_TLS_BASE_REGISTER(v)  __wrfsbase(v)
#endif /* !__x86_64__ */

#endif /* !_I386_KOS_KOS_BITS_THREAD_H */
