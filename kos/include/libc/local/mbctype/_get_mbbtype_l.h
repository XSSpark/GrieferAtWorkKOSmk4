/* HASH CRC-32:0xb788d65 */
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
#ifndef __local__get_mbbtype_l_defined
#define __local__get_mbbtype_l_defined
#include <__crt.h>
#if defined(__CRT_HAVE__mbctype) || defined(__CRT_HAVE___p__mbctype)
#include <libc/template/mbctype.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(_get_mbbtype_l) __ATTR_PURE __ATTR_WUNUSED unsigned char
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(_get_mbbtype_l))(unsigned char __ch, __locale_t __locale) {
	if (__locale == __NULLPTR)
		return (__LOCAL__mbctype + 1)[__ch];
	return 0; /* XXX: locale support */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep__get_mbbtype_l_defined
#define __local___localdep__get_mbbtype_l_defined
#define __localdep__get_mbbtype_l __LIBC_LOCAL_NAME(_get_mbbtype_l)
#endif /* !__local___localdep__get_mbbtype_l_defined */
#else /* __CRT_HAVE__mbctype || __CRT_HAVE___p__mbctype */
#undef __local__get_mbbtype_l_defined
#endif /* !__CRT_HAVE__mbctype && !__CRT_HAVE___p__mbctype */
#endif /* !__local__get_mbbtype_l_defined */
