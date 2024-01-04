/* HASH CRC-32:0xec6291bd */
/* Copyright (c) 2019-2024 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2024 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_setpassent_defined
#define __local_setpassent_defined
#include <__crt.h>
#ifdef __CRT_HAVE_setpwent
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_setpwent_defined
#define __local___localdep_setpwent_defined
__CREDIRECT_VOID(,__NOTHROW_RPC,__localdep_setpwent,(void),setpwent,())
#endif /* !__local___localdep_setpwent_defined */
__LOCAL_LIBC(setpassent) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(setpassent))(int __keep_open) {
	(void)__keep_open;
	(__NAMESPACE_LOCAL_SYM __localdep_setpwent)();
	return 0;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_setpassent_defined
#define __local___localdep_setpassent_defined
#define __localdep_setpassent __LIBC_LOCAL_NAME(setpassent)
#endif /* !__local___localdep_setpassent_defined */
#else /* __CRT_HAVE_setpwent */
#undef __local_setpassent_defined
#endif /* !__CRT_HAVE_setpwent */
#endif /* !__local_setpassent_defined */
