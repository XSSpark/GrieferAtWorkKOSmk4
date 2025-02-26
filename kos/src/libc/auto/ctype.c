/* HASH CRC-32:0x51051b6 */
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
#ifndef GUARD_LIBC_AUTO_CTYPE_C
#define GUARD_LIBC_AUTO_CTYPE_C 1

#include "../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include "../user/ctype.h"

DECL_BEGIN

#include "../libc/globals.h"
DEFINE_PUBLIC_ALIAS(__ctype_C_flags, libc___ctype_C_flags);
DEFINE_PUBLIC_ALIAS(__ctype_C_tolower, libc___ctype_C_tolower);
DEFINE_PUBLIC_ALIAS(__ctype_C_toupper, libc___ctype_C_toupper);
INTDEF __UINT8_TYPE__ const libc___ctype_C_flags[256];
INTERN_CONST ATTR_SECTION(".rodata.crt.unicode.static.ctype") __UINT8_TYPE__ const libc___ctype_C_flags[256] = {
	0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x3,0x3,0x3,0x3,0x3,0x1,0x1,
	0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
	0x82,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x28,0x28,0x28,0x28,0x28,0x28,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
	0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x40,0x40,0x40,0x40,0x40,
	0x40,0x24,0x24,0x24,0x24,0x24,0x24,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
	0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x40,0x40,0x40,0x40,0x1,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
};
INTDEF __INT8_TYPE__ const libc___ctype_C_tolower[256];
INTERN_CONST ATTR_SECTION(".rodata.crt.unicode.static.ctype") __INT8_TYPE__ const libc___ctype_C_tolower[256] = {
	0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf,
	0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
	0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
	0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
	0x40,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
	0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x5b,0x5c,0x5d,0x5e,0x5f,
	0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
	0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
	-0x80,-0x7f,-0x7e,-0x7d,-0x7c,-0x7b,-0x7a,-0x79,-0x78,-0x77,-0x76,-0x75,-0x74,-0x73,-0x72,-0x71,
	-0x70,-0x6f,-0x6e,-0x6d,-0x6c,-0x6b,-0x6a,-0x69,-0x68,-0x67,-0x66,-0x65,-0x64,-0x63,-0x62,-0x61,
	-0x60,-0x5f,-0x5e,-0x5d,-0x5c,-0x5b,-0x5a,-0x59,-0x58,-0x57,-0x56,-0x55,-0x54,-0x53,-0x52,-0x51,
	-0x50,-0x4f,-0x4e,-0x4d,-0x4c,-0x4b,-0x4a,-0x49,-0x48,-0x47,-0x46,-0x45,-0x44,-0x43,-0x42,-0x41,
	-0x40,-0x3f,-0x3e,-0x3d,-0x3c,-0x3b,-0x3a,-0x39,-0x38,-0x37,-0x36,-0x35,-0x34,-0x33,-0x32,-0x31,
	-0x30,-0x2f,-0x2e,-0x2d,-0x2c,-0x2b,-0x2a,-0x29,-0x28,-0x27,-0x26,-0x25,-0x24,-0x23,-0x22,-0x21,
	-0x20,-0x1f,-0x1e,-0x1d,-0x1c,-0x1b,-0x1a,-0x19,-0x18,-0x17,-0x16,-0x15,-0x14,-0x13,-0x12,-0x11,
	-0x10,-0xf,-0xe,-0xd,-0xc,-0xb,-0xa,-0x9,-0x8,-0x7,-0x6,-0x5,-0x4,-0x3,-0x2,-0x1,
};
INTDEF __INT8_TYPE__ const libc___ctype_C_toupper[256];
INTERN_CONST ATTR_SECTION(".rodata.crt.unicode.static.ctype") __INT8_TYPE__ const libc___ctype_C_toupper[256] = {
	0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf,
	0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
	0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
	0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
	0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
	0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,
	0x60,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
	0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x7b,0x7c,0x7d,0x7e,0x7f,
	-0x80,-0x7f,-0x7e,-0x7d,-0x7c,-0x7b,-0x7a,-0x79,-0x78,-0x77,-0x76,-0x75,-0x74,-0x73,-0x72,-0x71,
	-0x70,-0x6f,-0x6e,-0x6d,-0x6c,-0x6b,-0x6a,-0x69,-0x68,-0x67,-0x66,-0x65,-0x64,-0x63,-0x62,-0x61,
	-0x60,-0x5f,-0x5e,-0x5d,-0x5c,-0x5b,-0x5a,-0x59,-0x58,-0x57,-0x56,-0x55,-0x54,-0x53,-0x52,-0x51,
	-0x50,-0x4f,-0x4e,-0x4d,-0x4c,-0x4b,-0x4a,-0x49,-0x48,-0x47,-0x46,-0x45,-0x44,-0x43,-0x42,-0x41,
	-0x40,-0x3f,-0x3e,-0x3d,-0x3c,-0x3b,-0x3a,-0x39,-0x38,-0x37,-0x36,-0x35,-0x34,-0x33,-0x32,-0x31,
	-0x30,-0x2f,-0x2e,-0x2d,-0x2c,-0x2b,-0x2a,-0x29,-0x28,-0x27,-0x26,-0x25,-0x24,-0x23,-0x22,-0x21,
	-0x20,-0x1f,-0x1e,-0x1d,-0x1c,-0x1b,-0x1a,-0x19,-0x18,-0x17,-0x16,-0x15,-0x14,-0x13,-0x12,-0x11,
	-0x10,-0xf,-0xe,-0xd,-0xc,-0xb,-0xa,-0x9,-0x8,-0x7,-0x6,-0x5,-0x4,-0x3,-0x2,-0x1,
};
#ifndef __KERNEL__
#include <bits/crt/ctype.h>
/* >> iscntrl(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_iscntrl)(int ch) {

	return __crt_iscntrl(ch);



}
#include <bits/crt/ctype.h>
/* >> isspace(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_isspace)(int ch) {

	return __crt_isspace(ch);



}
#include <bits/crt/ctype.h>
/* >> isupper(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_isupper)(int ch) {

	return __crt_isupper(ch);



}
#include <bits/crt/ctype.h>
/* >> islower(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_islower)(int ch) {

	return __crt_islower(ch);



}
#include <bits/crt/ctype.h>
/* >> isalpha(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_isalpha)(int ch) {

	return __crt_isalpha(ch);



}
#include <bits/crt/ctype.h>
/* >> isdigit(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_isdigit)(int ch) {

	return __crt_isdigit(ch);



}
#include <bits/crt/ctype.h>
/* >> isxdigit(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_isxdigit)(int ch) {

	return __crt_isxdigit(ch);



}
#include <bits/crt/ctype.h>
/* >> isalnum(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_isalnum)(int ch) {

	return __crt_isalnum(ch);



}
#include <bits/crt/ctype.h>
/* >> ispunct(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_ispunct)(int ch) {

	return __crt_ispunct(ch);



}
#include <bits/crt/ctype.h>
/* >> isgraph(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_isgraph)(int ch) {

	return __crt_isgraph(ch);



}
#include <bits/crt/ctype.h>
/* >> isprint(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_isprint)(int ch) {

	return __crt_isprint(ch);



}
#include <bits/crt/ctype.h>
/* >> tolower(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_tolower)(int ch) {

	return __crt_tolower(ch);



}
#include <bits/crt/ctype.h>
/* >> toupper(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_toupper)(int ch) {

	return __crt_toupper(ch);



}
#include <bits/crt/ctype.h>
/* >> isblank(3) */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc_isblank)(int ch) {

	return __crt_isblank(ch);



}
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_iscntrl_l,libc_iscntrl,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> iscntrl_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_iscntrl_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_iscntrl(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_isspace_l,libc_isspace,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> isspace_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_isspace_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_isspace(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_isupper_l,libc_isupper,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> isupper_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_isupper_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_isupper(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_islower_l,libc_islower,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> islower_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_islower_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_islower(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_isalpha_l,libc_isalpha,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> isalpha_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_isalpha_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_isalpha(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_isdigit_l,libc_isdigit,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> isdigit_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_isdigit_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_isdigit(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_isxdigit_l,libc_isxdigit,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> isxdigit_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_isxdigit_l)(int ch,
                                      locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_isxdigit(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_isalnum_l,libc_isalnum,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> isalnum_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_isalnum_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_isalnum(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_ispunct_l,libc_ispunct,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> ispunct_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_ispunct_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_ispunct(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_isgraph_l,libc_isgraph,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> isgraph_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_isgraph_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_isgraph(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_isprint_l,libc_isprint,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> isprint_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_isprint_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_isprint(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_isblank_l,libc_isblank,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> isblank_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_isblank_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_isblank(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_tolower_l,libc_tolower,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> tolower_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_tolower_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_tolower(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc_toupper_l,libc_toupper,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
/* >> toupper_l(3) */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc_toupper_l)(int ch,
                                     locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc_toupper(ch);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
/* >> issymstrt(3)
 * Test if `ch' can appear at the start of a symbol/keyword/identifier */
INTERN ATTR_SECTION(".text.crt.dos.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc___iscsymf)(int ch) {
	return libc_isalpha(ch) || ch == '_' || ch == '$';
}
/* >> issymcont(3)
 * Test if `ch' can appear in the middle of a symbol/keyword/identifier */
INTERN ATTR_SECTION(".text.crt.dos.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc___iscsym)(int ch) {
	return libc_isalnum(ch) || ch == '_' || ch == '$';
}
/* Returns non-zero if `(C & ~0x7f) == 0' */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST int
NOTHROW(LIBCCALL libc_isascii)(int c) {
	return (c & ~0x7f) == 0;
}
/* Re-returns `C & 0x7f' */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST int
NOTHROW(LIBCCALL libc_toascii)(int c) {
	return c & 0x7f;
}
/* >> _tolower(3)
 * Same as `tolower(3)', but the caller must ensure that `isupper(ch)' */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc__tolower)(int ch) {
	return ch + 0x20;
}
/* >> _toupper(3)
 * Same as `toupper(3)', but the caller must ensure that `islower(ch)' */
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc__toupper)(int ch) {
	return ch - 0x20;
}
#include <libc/template/MB_CUR_MAX.h>
INTERN ATTR_SECTION(".text.crt.unicode.static.ctype") ATTR_CONST WUNUSED size_t
NOTHROW(LIBCCALL libc___ctype_get_mb_cur_max)(void) {
	return __LOCAL_MB_CUR_MAX;
}
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc____mb_cur_max_l_func,libc___ctype_get_mb_cur_max,,int,NOTHROW_NCX,LIBCCALL,(locale_t locale),(locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
#include <libc/template/MB_CUR_MAX.h>
INTERN ATTR_SECTION(".text.crt.dos.unicode.static.ctype") int
NOTHROW_NCX(LIBCCALL libc____mb_cur_max_l_func)(locale_t locale) {
	(void)locale;
	return __LOCAL_MB_CUR_MAX;
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
INTERN ATTR_SECTION(".text.crt.dos.unicode.static.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc__chvalidator_l)(locale_t locale,
                                          int ch,
                                          int mask) {
	return libc__isctype_l(ch, mask, locale);
}
INTERN ATTR_SECTION(".text.crt.dos.unicode.static.ctype") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc__isctype)(int ch,
                                int mask) {
	int result = 0;
	if ((mask & 0x0001) && libc_isupper(ch))
		result |= 0x0001;
	if ((mask & 0x0002) && libc_islower(ch))
		result |= 0x0002;
	if ((mask & 0x0004) && libc_isdigit(ch))
		result |= 0x0004;
	if ((mask & 0x0008) && libc_isspace(ch))
		result |= 0x0008;
	if ((mask & 0x0010) && libc_ispunct(ch))
		result |= 0x0010;
	if ((mask & 0x0020) && libc_iscntrl(ch))
		result |= 0x0020;
	if ((mask & 0x0040) && libc_isblank(ch))
		result |= 0x0040;
	if ((mask & 0x0080) && libc_isxdigit(ch) && !libc_isdigit(ch))
		result |= 0x0080;
	if ((mask & 0x8000) && ch >= 0xc0) /* NOTE: UTF-8 lead byte */
		result |= 0x8000;
	/*if ((mask & 0x0100) && isalpha(ch) && islower(ch) && isupper(ch))
		result |= 0x0100;*/
	return result;
}
#ifdef __LIBKCALL_CALLER_CLEANUP
DEFINE_INTERN_ALIAS_P(libc__isctype_l,libc__isctype,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, int mask, locale_t locale),(ch,mask,locale));
#else /* __LIBKCALL_CALLER_CLEANUP */
INTERN ATTR_SECTION(".text.crt.unicode.locale.ctype") ATTR_PURE WUNUSED int
NOTHROW_NCX(LIBCCALL libc__isctype_l)(int ch,
                                      int mask,
                                      locale_t locale) {
	COMPILER_IMPURE();
	(void)locale;
	return libc__isctype(ch, mask);
}
#endif /* !__LIBKCALL_CALLER_CLEANUP */
#endif /* !__KERNEL__ */

DECL_END

#ifndef __KERNEL__
DEFINE_PUBLIC_ALIAS_P(iscntrl,libc_iscntrl,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(isspace,libc_isspace,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(isupper,libc_isupper,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(islower,libc_islower,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(isalpha,libc_isalpha,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(isdigit,libc_isdigit,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(isxdigit,libc_isxdigit,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(isalnum,libc_isalnum,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(ispunct,libc_ispunct,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(isgraph,libc_isgraph,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(isprint,libc_isprint,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(tolower,libc_tolower,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(toupper,libc_toupper,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(isblank,libc_isblank,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_iscntrl_l,libc_iscntrl_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__iscntrl_l,libc_iscntrl_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(iscntrl_l,libc_iscntrl_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_isspace_l,libc_isspace_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__isspace_l,libc_isspace_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(isspace_l,libc_isspace_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_isupper_l,libc_isupper_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__isupper_l,libc_isupper_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(isupper_l,libc_isupper_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_islower_l,libc_islower_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__islower_l,libc_islower_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(islower_l,libc_islower_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_isalpha_l,libc_isalpha_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__isalpha_l,libc_isalpha_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(isalpha_l,libc_isalpha_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_isdigit_l,libc_isdigit_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__isdigit_l,libc_isdigit_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(isdigit_l,libc_isdigit_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_isxdigit_l,libc_isxdigit_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__isxdigit_l,libc_isxdigit_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(isxdigit_l,libc_isxdigit_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_isalnum_l,libc_isalnum_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__isalnum_l,libc_isalnum_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(isalnum_l,libc_isalnum_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_ispunct_l,libc_ispunct_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__ispunct_l,libc_ispunct_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(ispunct_l,libc_ispunct_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_isgraph_l,libc_isgraph_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__isgraph_l,libc_isgraph_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(isgraph_l,libc_isgraph_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_isprint_l,libc_isprint_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__isprint_l,libc_isprint_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(isprint_l,libc_isprint_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_isblank_l,libc_isblank_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__isblank_l,libc_isblank_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(isblank_l,libc_isblank_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_tolower_l,libc_tolower_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__tolower_l,libc_tolower_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(tolower_l,libc_tolower_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(_toupper_l,libc_toupper_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(__toupper_l,libc_toupper_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(toupper_l,libc_toupper_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, locale_t locale),(ch,locale));
DEFINE_PUBLIC_ALIAS_P(__iscsymf,libc___iscsymf,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(__iscsym,libc___iscsym,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(__isascii,libc_isascii,ATTR_CONST,int,NOTHROW,LIBCCALL,(int c),(c));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(isascii,libc_isascii,ATTR_CONST,int,NOTHROW,LIBCCALL,(int c),(c));
#ifdef __LIBCCALL_IS_LIBDCALL
DEFINE_PUBLIC_ALIAS_P(__toascii,libc_toascii,ATTR_CONST,int,NOTHROW,LIBCCALL,(int c),(c));
#endif /* __LIBCCALL_IS_LIBDCALL */
DEFINE_PUBLIC_ALIAS_P(toascii,libc_toascii,ATTR_CONST,int,NOTHROW,LIBCCALL,(int c),(c));
DEFINE_PUBLIC_ALIAS_P(_tolower,libc__tolower,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(_toupper,libc__toupper,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch),(ch));
DEFINE_PUBLIC_ALIAS_P(___mb_cur_max_func,libc___ctype_get_mb_cur_max,ATTR_CONST WUNUSED,size_t,NOTHROW,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P(__ctype_get_mb_cur_max,libc___ctype_get_mb_cur_max,ATTR_CONST WUNUSED,size_t,NOTHROW,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P(___mb_cur_max_l_func,libc____mb_cur_max_l_func,,int,NOTHROW_NCX,LIBCCALL,(locale_t locale),(locale));
DEFINE_PUBLIC_ALIAS_P(_chvalidator_l,libc__chvalidator_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(locale_t locale, int ch, int mask),(locale,ch,mask));
DEFINE_PUBLIC_ALIAS_P(_chvalidator,libc__isctype,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch, int mask),(ch,mask));
DEFINE_PUBLIC_ALIAS_P(_isctype,libc__isctype,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(int ch, int mask),(ch,mask));
DEFINE_PUBLIC_ALIAS_P(_isctype_l,libc__isctype_l,ATTR_PURE WUNUSED,int,NOTHROW_NCX,LIBCCALL,(int ch, int mask, locale_t locale),(ch,mask,locale));
#endif /* !__KERNEL__ */

#endif /* !GUARD_LIBC_AUTO_CTYPE_C */
