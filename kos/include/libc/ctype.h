/* HASH 0xd8ba581 */
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
#ifndef _LIBC_CTYPE_H
#define _LIBC_CTYPE_H 1

#include <__stdinc.h>
#include <__crt.h>
#include "slow/ctype.h"

#define __libc_iscntrl __libc_slow_iscntrl
#define __libc_isspace __libc_slow_isspace
#define __libc_isupper __libc_slow_isupper
#define __libc_islower __libc_slow_islower
#define __libc_isalpha __libc_slow_isalpha
#define __libc_isdigit __libc_slow_isdigit
#define __libc_isxdigit __libc_slow_isxdigit
#define __libc_isalnum __libc_slow_isalnum
#define __libc_ispunct __libc_slow_ispunct
#define __libc_isgraph __libc_slow_isgraph
#define __libc_isprint __libc_slow_isprint
#define __libc_tolower __libc_slow_tolower
#define __libc_toupper __libc_slow_toupper
#define __libc_isblank __libc_slow_isblank

#endif /* !_LIBC_CTYPE_H */
