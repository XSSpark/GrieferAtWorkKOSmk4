/* HASH CRC-32:0xafa8de5e */
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
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_iswgraph_defined
#define __local_iswgraph_defined 1
/* Dependency: "isgraph" from "ctype" */
#ifndef ____localdep_isgraph_defined
#define ____localdep_isgraph_defined 1
#if __has_builtin(__builtin_isgraph) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_isgraph)
__EXTERNINLINE __ATTR_CONST __ATTR_WUNUSED int __NOTHROW(__LIBCCALL __localdep_isgraph)(int __ch) { return __builtin_isgraph(__ch); }
#elif defined(__CRT_HAVE_isgraph)
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_isgraph,(int __ch),isgraph,(__ch))
#else /* LIBC: isgraph */
#include <local/ctype/isgraph.h>
#define __localdep_isgraph (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(isgraph))
#endif /* isgraph... */
#endif /* !____localdep_isgraph_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(iswgraph) __ATTR_CONST __ATTR_WUNUSED int
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(iswgraph))(__WINT_TYPE__ __wc) {
#line 135 "kos/src/libc/magic/wctype.c"
	return __localdep_isgraph((int)__wc);
}
__NAMESPACE_LOCAL_END
#endif /* !__local_iswgraph_defined */
