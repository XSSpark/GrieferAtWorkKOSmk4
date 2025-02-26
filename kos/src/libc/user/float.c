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
#ifndef GUARD_LIBC_USER_FLOAT_C
#define GUARD_LIBC_USER_FLOAT_C 1

#include "../api.h"
#include "float.h"

DECL_BEGIN

/*[[[head:libc__clearfp,hash:CRC-32=0xeee4346e]]]*/
INTERN ATTR_SECTION(".text.crt.math.float") uint32_t
NOTHROW_NCX(LIBCCALL libc__clearfp)(void)
/*[[[body:libc__clearfp]]]*/
/*AUTO*/{
	CRT_UNIMPLEMENTED("_clearfp"); /* TODO */
	return (uint32_t)libc_seterrno(ENOSYS);
}
/*[[[end:libc__clearfp]]]*/

/*[[[head:libc__statusfp,hash:CRC-32=0x3a5b5b50]]]*/
INTERN ATTR_SECTION(".text.crt.math.float") uint32_t
NOTHROW_NCX(LIBCCALL libc__statusfp)(void)
/*[[[body:libc__statusfp]]]*/
/*AUTO*/{
	CRT_UNIMPLEMENTED("_statusfp"); /* TODO */
	return (uint32_t)libc_seterrno(ENOSYS);
}
/*[[[end:libc__statusfp]]]*/


/*[[[head:libc__statusfp2,hash:CRC-32=0xf4584c17]]]*/
INTERN ATTR_SECTION(".text.crt.math.float") void
NOTHROW_NCX(LIBCCALL libc__statusfp2)(uint32_t *x86_stat,
                                      uint32_t *sse2_stat)
/*[[[body:libc__statusfp2]]]*/
/*AUTO*/{
	(void)x86_stat;
	(void)sse2_stat;
	CRT_UNIMPLEMENTEDF("_statusfp2(x86_stat: %p, sse2_stat: %p)", x86_stat, sse2_stat); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:libc__statusfp2]]]*/


/*[[[head:libc___control87_2,hash:CRC-32=0x1dbbbb5e]]]*/
INTERN ATTR_SECTION(".text.crt.math.float") int
NOTHROW_NCX(LIBCCALL libc___control87_2)(uint32_t newval,
                                         uint32_t mask,
                                         uint32_t *x86_control_word,
                                         uint32_t *sse2_control_word)
/*[[[body:libc___control87_2]]]*/
/*AUTO*/{
	(void)newval;
	(void)mask;
	(void)x86_control_word;
	(void)sse2_control_word;
	CRT_UNIMPLEMENTEDF("__control87_2(newval: %" PRIx32 ", mask: %" PRIx32 ", x86_control_word: %p, sse2_control_word: %p)", newval, mask, x86_control_word, sse2_control_word); /* TODO */
	return libc_seterrno(ENOSYS);
}
/*[[[end:libc___control87_2]]]*/

/*[[[head:libc___fpecode,hash:CRC-32=0x367981b7]]]*/
INTERN ATTR_SECTION(".text.crt.math.float") int *
NOTHROW_NCX(LIBCCALL libc___fpecode)(void)
/*[[[body:libc___fpecode]]]*/
/*AUTO*/{
	CRT_UNIMPLEMENTED("__fpecode"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc___fpecode]]]*/








/*[[[head:libc__fpclass,hash:CRC-32=0x793f4ef4]]]*/
/* >> _fpclass(3)
 * @return: * : Set of `_FPCLASS_*' */
INTERN ATTR_SECTION(".text.crt.math.float") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc__fpclass)(double x)
/*[[[body:libc__fpclass]]]*/
/*AUTO*/{
	(void)x;
	CRT_UNIMPLEMENTEDF("_fpclass(x: %f)", x); /* TODO */
	return libc_seterrno(ENOSYS);
}
/*[[[end:libc__fpclass]]]*/

/*[[[head:libc__fpclassf,hash:CRC-32=0xe8d33159]]]*/
INTERN ATTR_SECTION(".text.crt.math.float") ATTR_CONST WUNUSED int
NOTHROW(LIBCCALL libc__fpclassf)(float x)
/*[[[body:libc__fpclassf]]]*/
/*AUTO*/{
	(void)x;
	CRT_UNIMPLEMENTEDF("_fpclassf(x: %f)", x); /* TODO */
	return libc_seterrno(ENOSYS);
}
/*[[[end:libc__fpclassf]]]*/


/*[[[head:libc_fpreset,hash:CRC-32=0xa8470258]]]*/
INTERN ATTR_SECTION(".text.crt.math.float") void
NOTHROW_NCX(LIBCCALL libc_fpreset)(void)
/*[[[body:libc_fpreset]]]*/
/*AUTO*/{
	CRT_UNIMPLEMENTED("fpreset"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:libc_fpreset]]]*/





/*[[[start:exports,hash:CRC-32=0x3862d1d4]]]*/
DEFINE_PUBLIC_ALIAS_P(_clearfp,libc__clearfp,,uint32_t,NOTHROW_NCX,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P(_statusfp,libc__statusfp,,uint32_t,NOTHROW_NCX,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P_VOID(_statusfp2,libc__statusfp2,,NOTHROW_NCX,LIBCCALL,(uint32_t *x86_stat, uint32_t *sse2_stat),(x86_stat,sse2_stat));
DEFINE_PUBLIC_ALIAS_P(__control87_2,libc___control87_2,,int,NOTHROW_NCX,LIBCCALL,(uint32_t newval, uint32_t mask, uint32_t *x86_control_word, uint32_t *sse2_control_word),(newval,mask,x86_control_word,sse2_control_word));
DEFINE_PUBLIC_ALIAS_P(__fpecode,libc___fpecode,,int *,NOTHROW_NCX,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P(_fpclass,libc__fpclass,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(double x),(x));
DEFINE_PUBLIC_ALIAS_P(_fpclassf,libc__fpclassf,ATTR_CONST WUNUSED,int,NOTHROW,LIBCCALL,(float x),(x));
DEFINE_PUBLIC_ALIAS_P_VOID(_fpreset,libc_fpreset,,NOTHROW_NCX,LIBCCALL,(void),());
DEFINE_PUBLIC_ALIAS_P_VOID(fpreset,libc_fpreset,,NOTHROW_NCX,LIBCCALL,(void),());
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_FLOAT_C */
