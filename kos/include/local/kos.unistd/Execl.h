/* HASH CRC-32:0x144eacd3 */
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
#ifndef __local_Execl_defined
#ifdef __CRT_HAVE_Execv
#define __local_Execl_defined 1
#include <__crt.h>
#include <kos/anno.h>
#include <parts/redirect-exec.h>
/* Dependency: "Execv" */
#ifndef ____localdep_Execv_defined
#define ____localdep_Execv_defined 1
#ifdef __CRT_HAVE_Execv
/* >> execv(3)
 * Replace the calling process with the application image referred to by `PATH' / `FILE'
 * and execute it's `main()' method, passing the given `ARGV', and setting `environ' to `ENVP' */
__CREDIRECT_VOID(__ATTR_NORETURN __ATTR_NONNULL((1, 2)),__THROWING,__localdep_Execv,(char const *__restrict __path, __TARGV),Execv,(__path,))
#else /* LIBC: Execv */
#undef ____localdep_Execv_defined
#endif /* Execv... */
#endif /* !____localdep_Execv_defined */

__NAMESPACE_LOCAL_BEGIN
/* >> execl(3)
 * Replace the calling process with the application image referred to by `PATH' / `FILE'
 * and execute it's `main()' method, passing the list of NULL-terminated `ARGS'-list */
__LOCAL_LIBC(Execl) __ATTR_NORETURN __ATTR_SENTINEL __ATTR_NONNULL((1)) void
(__VLIBCCALL __LIBC_LOCAL_NAME(Execl))(char const *__restrict __path,
                                       char const *__args,
                                       ... /*, (char *)NULL*/) __THROWS(...) {
#line 58 "kos/src/libc/magic/kos.unistd.c"
	__REDIRECT_XEXECL(char, __localdep_Execv, __path, __args)
}
__NAMESPACE_LOCAL_END
#endif /* __CRT_HAVE_Execv */
#endif /* !__local_Execl_defined */
