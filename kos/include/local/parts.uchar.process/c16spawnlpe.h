/* HASH CRC-32:0x5018a879 */
/* Copyright (c) 2019-2020 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2020 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_c16spawnlpe_defined
#define __local_c16spawnlpe_defined 1
#include <__crt.h>
#if (defined(__CRT_HAVE_wspawnvpe) && (__SIZEOF_WCHAR_T__ == 2) && defined(__LIBCCALL_IS_LIBDCALL)) || defined(__CRT_HAVE_DOS$_wspawnvpe)
#include <parts/redirect-exec.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(c16spawnlpe) __ATTR_SENTINEL_O(1) __ATTR_NONNULL((2)) __pid_t
__NOTHROW_RPC(__VLIBDCALL __LIBC_LOCAL_NAME(c16spawnlpe))(int __mode, __CHAR16_TYPE__ const *__restrict __file, __CHAR16_TYPE__ const *__args, ...) {
	__REDIRECT_SPAWNLE(__CHAR16_TYPE__, __c16spawnvpe, __mode, __file, __args)
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_c16spawnlpe_defined
#define __local___localdep_c16spawnlpe_defined 1
#define __localdep_c16spawnlpe __LIBC_LOCAL_NAME(c16spawnlpe)
#endif /* !__local___localdep_c16spawnlpe_defined */
#else /* (__CRT_HAVE_wspawnvpe && (__SIZEOF_WCHAR_T__ == 2) && __LIBCCALL_IS_LIBDCALL) || __CRT_HAVE_DOS$_wspawnvpe */
#undef __local_c16spawnlpe_defined
#endif /* (!__CRT_HAVE_wspawnvpe || !(__SIZEOF_WCHAR_T__ == 2) || !__LIBCCALL_IS_LIBDCALL) && !__CRT_HAVE_DOS$_wspawnvpe */
#endif /* !__local_c16spawnlpe_defined */
