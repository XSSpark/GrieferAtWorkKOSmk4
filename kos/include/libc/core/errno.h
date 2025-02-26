/* HASH CRC-32:0x93d1e183 */
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
#ifndef _LIBC_CORE_ERRNO_H
#define _LIBC_CORE_ERRNO_H 1

#include <__stdinc.h>

#ifdef __CC__
#include <__crt.h>
#include <hybrid/typecore.h>

__SYSDECL_BEGIN

#ifndef ____libc_core___errno_location_defined
#define ____libc_core___errno_location_defined
#ifdef __CRT_HAVE___errno_location
#include <bits/types.h>
/* >> __errno_location(3) */
__CREDIRECT(__ATTR_CONST __ATTR_RETNONNULL __ATTR_WUNUSED,__errno_t *,__NOTHROW,__libc_core___errno_location,(void),__errno_location,())
#elif defined(__CRT_HAVE__errno)
#include <bits/types.h>
/* >> __errno_location(3) */
__CREDIRECT(__ATTR_CONST __ATTR_RETNONNULL __ATTR_WUNUSED,__errno_t *,__NOTHROW,__libc_core___errno_location,(void),_errno,())
#elif defined(__CRT_HAVE___errno)
#include <bits/types.h>
/* >> __errno_location(3) */
__CREDIRECT(__ATTR_CONST __ATTR_RETNONNULL __ATTR_WUNUSED,__errno_t *,__NOTHROW,__libc_core___errno_location,(void),__errno,())
#else /* ... */
#undef ____libc_core___errno_location_defined
#endif /* !... */
#endif /* !____libc_core___errno_location_defined */

__SYSDECL_END

#endif /* __CC__ */

#endif /* !_LIBC_CORE_ERRNO_H */
