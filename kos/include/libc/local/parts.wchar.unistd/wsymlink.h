/* HASH CRC-32:0x96397f6b */
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
#ifndef __local_wsymlink_defined
#define __local_wsymlink_defined
#include <__crt.h>
#include <asm/os/fcntl.h>
#if defined(__AT_FDCWD) && (defined(__CRT_HAVE_wsymlinkat) || defined(__CRT_HAVE_fsymlinkat))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_wsymlinkat_defined
#define __local___localdep_wsymlinkat_defined
#ifdef __CRT_HAVE_wsymlinkat
__NAMESPACE_LOCAL_END
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,__localdep_wsymlinkat,(__WCHAR_TYPE__ const *__link_text, __fd_t __tofd, __WCHAR_TYPE__ const *__target_path),wsymlinkat,(__link_text,__tofd,__target_path))
#elif defined(__CRT_HAVE_fsymlinkat)
__NAMESPACE_LOCAL_END
#include <libc/local/parts.wchar.unistd/wsymlinkat.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wsymlinkat __LIBC_LOCAL_NAME(wsymlinkat)
#else /* ... */
#undef __local___localdep_wsymlinkat_defined
#endif /* !... */
#endif /* !__local___localdep_wsymlinkat_defined */
__LOCAL_LIBC(wsymlink) __ATTR_NONNULL((1, 2)) int
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(wsymlink))(__WCHAR_TYPE__ const *__link_text, __WCHAR_TYPE__ const *__target_path) {
	/* TODO: Header-implementation for `symlink()' on DOS (using the windows API) */
	return (__NAMESPACE_LOCAL_SYM __localdep_wsymlinkat)(__link_text, __AT_FDCWD, __target_path);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wsymlink_defined
#define __local___localdep_wsymlink_defined
#define __localdep_wsymlink __LIBC_LOCAL_NAME(wsymlink)
#endif /* !__local___localdep_wsymlink_defined */
#else /* __AT_FDCWD && (__CRT_HAVE_wsymlinkat || __CRT_HAVE_fsymlinkat) */
#undef __local_wsymlink_defined
#endif /* !__AT_FDCWD || (!__CRT_HAVE_wsymlinkat && !__CRT_HAVE_fsymlinkat) */
#endif /* !__local_wsymlink_defined */
