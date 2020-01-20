/* HASH CRC-32:0x8eba57b1 */
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
#ifndef __local_wctob_defined
#define __local_wctob_defined 1
__NAMESPACE_LOCAL_BEGIN
#ifndef __EOF
#ifdef EOF
#define __EOF  EOF
#else /* EOF */
#define __EOF (-1)
#endif /* !EOF */
#endif /* !__EOF */
__LOCAL_LIBC(wctob) __ATTR_CONST __ATTR_WUNUSED int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wctob))(__WINT_TYPE__ __ch) {
#line 214 "kos/src/libc/magic/wchar.c"
	if (__ch >= 0 && __ch <= 0x7f)
		return (int)__ch;
	return __EOF;
}
__NAMESPACE_LOCAL_END
#endif /* !__local_wctob_defined */
