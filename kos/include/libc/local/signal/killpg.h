/* HASH CRC-32:0x33c0f35b */
/* Copyright (c) 2019-2025 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2025 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_killpg_defined
#define __local_killpg_defined
#include <__crt.h>
#if defined(__CRT_HAVE_kill) || defined(__CRT_HAVE___kill) || defined(__CRT_HAVE___libc_kill)
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_kill_defined
#define __local___localdep_kill_defined
#ifdef __CRT_HAVE_kill
__CREDIRECT(,int,__NOTHROW_NCX,__localdep_kill,(__pid_t __pid, __signo_t __signo),kill,(__pid,__signo))
#elif defined(__CRT_HAVE___kill)
__CREDIRECT(,int,__NOTHROW_NCX,__localdep_kill,(__pid_t __pid, __signo_t __signo),__kill,(__pid,__signo))
#elif defined(__CRT_HAVE___libc_kill)
__CREDIRECT(,int,__NOTHROW_NCX,__localdep_kill,(__pid_t __pid, __signo_t __signo),__libc_kill,(__pid,__signo))
#else /* ... */
#undef __local___localdep_kill_defined
#endif /* !... */
#endif /* !__local___localdep_kill_defined */
__LOCAL_LIBC(killpg) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(killpg))(__pid_t __pgrp, __signo_t __signo) {
	return (__NAMESPACE_LOCAL_SYM __localdep_kill)(-__pgrp, __signo);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_killpg_defined
#define __local___localdep_killpg_defined
#define __localdep_killpg __LIBC_LOCAL_NAME(killpg)
#endif /* !__local___localdep_killpg_defined */
#else /* __CRT_HAVE_kill || __CRT_HAVE___kill || __CRT_HAVE___libc_kill */
#undef __local_killpg_defined
#endif /* !__CRT_HAVE_kill && !__CRT_HAVE___kill && !__CRT_HAVE___libc_kill */
#endif /* !__local_killpg_defined */
