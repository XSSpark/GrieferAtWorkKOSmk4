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
#ifndef GUARD_LIBC_USER_SYS_STATFS_C
#define GUARD_LIBC_USER_SYS_STATFS_C 1

#include "../api.h"
#include "sys.statfs.h"
#include <kos/syscalls.h>

DECL_BEGIN





/*[[[start:implementation]]]*/

/*[[[head:statfs,hash:0xea860f81]]]*/
/* Return information about the filesystem on which FILE resides */
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.statfs.statfs.statfs") int
NOTHROW_NCX(LIBCCALL libc_statfs)(char const *file,
                                  struct statfs *buf)
/*[[[body:statfs]]]*/
{
	errno_t result;
	result = sys_statfs(file, (struct __statfs32 *)buf);
	return libc_seterrno_syserr(result);
}
/*[[[end:statfs]]]*/

/*[[[head:fstatfs,hash:0x787fa7c1]]]*/
/* Return information about the filesystem containing the file FILDES refers to */
INTERN NONNULL((2))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.statfs.statfs.fstatfs") int
NOTHROW_NCX(LIBCCALL libc_fstatfs)(fd_t filedes,
                                   struct statfs *buf)
/*[[[body:fstatfs]]]*/
{
	errno_t result;
	result = sys_fstatfs(filedes, (struct __statfs32 *)buf);
	return libc_seterrno_syserr(result);
}
/*[[[end:fstatfs]]]*/

#if __SIZEOF_FSBLKCNT32_T__ == __SIZEOF_FSBLKCNT64_T__ && \
    __SIZEOF_FSFILCNT32_T__ == __SIZEOF_FSFILCNT64_T__
DEFINE_INTERN_ALIAS(libc_statfs64,libc_statfs);
DEFINE_INTERN_ALIAS(libc_fstatfs64,libc_fstatfs);
#else
/*[[[head:statfs64,hash:0x9c2fdae8]]]*/
/* Return information about the filesystem on which FILE resides */
#if __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__
DEFINE_INTERN_ALIAS(libc_statfs64, libc_statfs);
#else
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.statfs.statfs.statfs64") int
NOTHROW_NCX(LIBCCALL libc_statfs64)(const char *file,
                                    struct statfs64 *buf)
/*[[[body:statfs64]]]*/
{
	errno_t result;
	result = sys_statfs64(file, buf);
	return libc_seterrno_syserr(result);
}
#endif /* MAGIC:alias */
/*[[[end:statfs64]]]*/

/*[[[head:fstatfs64,hash:0xc0e66519]]]*/
/* Return information about the filesystem containing the file FILDES refers to */
#if __SIZEOF_OFF32_T__ == __SIZEOF_OFF64_T__
DEFINE_INTERN_ALIAS(libc_fstatfs64, libc_fstatfs);
#else
INTERN NONNULL((2))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.statfs.statfs.fstatfs64") int
NOTHROW_NCX(LIBCCALL libc_fstatfs64)(fd_t filedes,
                                     struct statfs64 *buf)
/*[[[body:fstatfs64]]]*/
{
	errno_t result;
	result = sys_fstatfs64(filedes, buf);
	return libc_seterrno_syserr(result);
}
#endif /* MAGIC:alias */
/*[[[end:fstatfs64]]]*/
#endif


/*[[[end:implementation]]]*/



/*[[[start:exports,hash:0xcdca887c]]]*/
DEFINE_PUBLIC_WEAK_ALIAS(statfs, libc_statfs);
DEFINE_PUBLIC_WEAK_ALIAS(fstatfs, libc_fstatfs);
DEFINE_PUBLIC_WEAK_ALIAS(statfs64, libc_statfs64);
DEFINE_PUBLIC_WEAK_ALIAS(fstatfs64, libc_fstatfs64);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_SYS_STATFS_C */
