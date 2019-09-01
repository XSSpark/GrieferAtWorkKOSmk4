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
#ifndef _STDALIGN_H
#define _STDALIGN_H 1

#include "__stdinc.h"

#ifndef __cplusplus /* TODO: Also define is not provided by the c++ compiler! */

#ifndef __alignas_is_defined
#define __alignas_is_defined 1
#define alignas __ATTR_ALIGNED
#endif /* !__alignas_is_defined */

#ifndef __alignof_is_defined
#define __alignof_is_defined 1
#define __alignof_is_defined 1
#define alignof __COMPILER_ALIGNOF
#endif /* !__alignof_is_defined */

#endif


#endif /* !_STDALIGN_H */
