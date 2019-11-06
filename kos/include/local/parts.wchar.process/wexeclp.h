/* HASH CRC-32:0x54398f04 */
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
#ifndef __local_wexeclp_defined
#if defined(__CRT_HAVE_wexecvp) || defined(__CRT_HAVE__wexecvp)
#define __local_wexeclp_defined 1
#include <parts/redirect-exec.h>
/* Dependency: "wexecvp" */
#ifndef ____localdep_wexecvp_defined
#define ____localdep_wexecvp_defined 1
#ifdef __CRT_HAVE_wexecvp
__CREDIRECT(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,__localdep_wexecvp,(__WCHAR_TYPE__ const *__restrict __file, __TWARGV),wexecvp,(__file,____TWARGV))
#elif defined(__CRT_HAVE__wexecvp)
__CREDIRECT(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,__localdep_wexecvp,(__WCHAR_TYPE__ const *__restrict __file, __TWARGV),_wexecvp,(__file,____TWARGV))
#else /* LIBC: wexecvp */
#undef ____localdep_wexecvp_defined
#endif /* wexecvp... */
#endif /* !____localdep_wexecvp_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(wexeclp) __ATTR_SENTINEL __ATTR_NONNULL((1)) int
__NOTHROW_RPC(__VLIBCCALL __LIBC_LOCAL_NAME(wexeclp))(__WCHAR_TYPE__ const *__restrict __file,
                                                      __WCHAR_TYPE__ const *__args,
                                                      ... /*, (wchar_t *)NULL*/) {
#line 89 "kos/src/libc/magic/parts.wchar.process.c"
	__REDIRECT_EXECL(__WCHAR_TYPE__, __localdep_wexecvp, __file, __args)
}
__NAMESPACE_LOCAL_END
#endif /* defined(__CRT_HAVE_wexecvp) || defined(__CRT_HAVE__wexecvp) */
#endif /* !__local_wexeclp_defined */
