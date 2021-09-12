/* HASH CRC-32:0x873a7e6d */
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
#ifndef __local_tcsendbreak_defined
#define __local_tcsendbreak_defined 1
#include <__crt.h>
#include <asm/os/tty.h>
#if defined(__CRT_HAVE_ioctl) && defined(__TCSBRKP)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_ioctl_defined
#define __local___localdep_ioctl_defined 1
__NAMESPACE_LOCAL_END
#include <features.h>
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
__CVREDIRECT(,__STDC_INT_AS_SSIZE_T,__NOTHROW_RPC,__localdep_ioctl,(__fd_t __fd, __ULONGPTR_TYPE__ __request),ioctl,(__fd,__request),__request,1,(void *))
#endif /* !__local___localdep_ioctl_defined */
__LOCAL_LIBC(tcsendbreak) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(tcsendbreak))(__fd_t __fd, int __duration) {
	return (int)__NAMESPACE_LOCAL_SYM __localdep_ioctl(__fd, __TCSBRKP, __duration);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_tcsendbreak_defined
#define __local___localdep_tcsendbreak_defined 1
#define __localdep_tcsendbreak __LIBC_LOCAL_NAME(tcsendbreak)
#endif /* !__local___localdep_tcsendbreak_defined */
#else /* __CRT_HAVE_ioctl && __TCSBRKP */
#undef __local_tcsendbreak_defined
#endif /* !__CRT_HAVE_ioctl || !__TCSBRKP */
#endif /* !__local_tcsendbreak_defined */
