/* Copyright (c) 2019-2021 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2021 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_LIBC_USER_CRYPT_C
#define GUARD_LIBC_USER_CRYPT_C 1

#include "../api.h"
/**/

#include "crypt.h"

DECL_BEGIN







/*[[[head:libc_crypt,hash:CRC-32=0xb8be50d2]]]*/
INTERN ATTR_SECTION(".text.crt.string.encrypt") NONNULL((1, 2)) char *
NOTHROW_NCX(LIBCCALL libc_crypt)(char const *key,
                                 char const *salt)
/*[[[body:libc_crypt]]]*/
/*AUTO*/{
	(void)key;
	(void)salt;
	CRT_UNIMPLEMENTEDF("crypt(%q, %q)", key, salt); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_crypt]]]*/

/*[[[head:libc_setkey,hash:CRC-32=0x735e598b]]]*/
INTERN ATTR_SECTION(".text.crt.string.encrypt") NONNULL((1)) void
NOTHROW_NCX(LIBCCALL libc_setkey)(char const *key)
/*[[[body:libc_setkey]]]*/
/*AUTO*/{
	(void)key;
	CRT_UNIMPLEMENTEDF("setkey(%q)", key); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:libc_setkey]]]*/

/*[[[head:libc_encrypt,hash:CRC-32=0x69530dad]]]*/
INTERN ATTR_SECTION(".text.crt.string.encrypt") NONNULL((1)) void
NOTHROW_NCX(LIBCCALL libc_encrypt)(char *glibc_block,
                                   __STDC_INT_AS_UINT_T edflag)
/*[[[body:libc_encrypt]]]*/
/*AUTO*/{
	(void)glibc_block;
	(void)edflag;
	CRT_UNIMPLEMENTEDF("encrypt(%q, %x)", glibc_block, edflag); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:libc_encrypt]]]*/

/*[[[head:libc_crypt_r,hash:CRC-32=0x64d4ee6f]]]*/
INTERN ATTR_SECTION(".text.crt.string.encrypt") NONNULL((1, 2, 3)) char *
NOTHROW_NCX(LIBCCALL libc_crypt_r)(char const *key,
                                   char const *salt,
                                   struct crypt_data *__restrict data)
/*[[[body:libc_crypt_r]]]*/
/*AUTO*/{
	(void)key;
	(void)salt;
	(void)data;
	CRT_UNIMPLEMENTEDF("crypt_r(%q, %q, %p)", key, salt, data); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_crypt_r]]]*/

/*[[[head:libc_setkey_r,hash:CRC-32=0xfd5509b5]]]*/
INTERN ATTR_SECTION(".text.crt.string.encrypt") NONNULL((1, 2)) void
NOTHROW_NCX(LIBCCALL libc_setkey_r)(char const *key,
                                    struct crypt_data *__restrict data)
/*[[[body:libc_setkey_r]]]*/
/*AUTO*/{
	(void)key;
	(void)data;
	CRT_UNIMPLEMENTEDF("setkey_r(%q, %p)", key, data); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:libc_setkey_r]]]*/

/*[[[head:libc_encrypt_r,hash:CRC-32=0x8e402f36]]]*/
INTERN ATTR_SECTION(".text.crt.string.encrypt") NONNULL((1, 3)) void
NOTHROW_NCX(LIBCCALL libc_encrypt_r)(char *glibc_block,
                                     int edflag,
                                     struct crypt_data *__restrict data)
/*[[[body:libc_encrypt_r]]]*/
/*AUTO*/{
	(void)glibc_block;
	(void)edflag;
	(void)data;
	CRT_UNIMPLEMENTEDF("encrypt_r(%q, %x, %p)", glibc_block, edflag, data); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:libc_encrypt_r]]]*/





/*[[[start:exports,hash:CRC-32=0x31d221c2]]]*/
DEFINE_PUBLIC_ALIAS(setkey, libc_setkey);
DEFINE_PUBLIC_ALIAS(crypt, libc_crypt);
DEFINE_PUBLIC_ALIAS(encrypt, libc_encrypt);
DEFINE_PUBLIC_ALIAS(crypt_r, libc_crypt_r);
DEFINE_PUBLIC_ALIAS(setkey_r, libc_setkey_r);
DEFINE_PUBLIC_ALIAS(encrypt_r, libc_encrypt_r);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_CRYPT_C */
