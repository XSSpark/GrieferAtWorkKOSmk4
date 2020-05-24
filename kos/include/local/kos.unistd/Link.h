/* HASH CRC-32:0x77ef5a3c */
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
#ifndef __local_Link_defined
#if defined(__CRT_AT_FDCWD) && defined(__CRT_HAVE_LinkAt)
#define __local_Link_defined 1
#include <__crt.h>
#include <kos/anno.h>
/* Dependency: "LinkAt" */
#ifndef ____localdep_LinkAt_defined
#define ____localdep_LinkAt_defined 1
#ifdef __CRT_HAVE_LinkAt
/* >> linkat(2)
 * Create a hard link from `FROMFD:FROM', leading to `TOFD:TO' */
__CREDIRECT_VOID(__ATTR_NONNULL((2, 4)),__THROWING,__localdep_LinkAt,(__fd_t __fromfd, char const *__from, __fd_t __tofd, char const *__to, __atflag_t __flags),LinkAt,(__fromfd,__from,__tofd,__to,__flags))
#else /* LIBC: LinkAt */
#undef ____localdep_LinkAt_defined
#endif /* LinkAt... */
#endif /* !____localdep_LinkAt_defined */

__NAMESPACE_LOCAL_BEGIN
/* >> link(2)
 * Create a hard link from `FROM', leading to `TO' */
__LOCAL_LIBC(Link) __ATTR_NONNULL((1, 2)) void
(__LIBCCALL __LIBC_LOCAL_NAME(Link))(char const *__from,
                                     char const *__to) __THROWS(...) {
#line 144 "kos/src/libc/magic/kos.unistd.c"
	__localdep_LinkAt(__CRT_AT_FDCWD, __from, __CRT_AT_FDCWD, __to, 0);
}
__NAMESPACE_LOCAL_END
#endif /* __CRT_AT_FDCWD && __CRT_HAVE_LinkAt */
#endif /* !__local_Link_defined */
