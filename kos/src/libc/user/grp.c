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
#ifndef GUARD_LIBC_USER_GRP_C
#define GUARD_LIBC_USER_GRP_C 1

#include "../api.h"
#include "grp.h"

DECL_BEGIN





/*[[[start:implementation]]]*/

/*[[[head:getgrgid,hash:0xb7c85ee9]]]*/
/* Search for an entry with a matching group ID */
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.database.group.getgrgid") struct group *
NOTHROW_RPC(LIBCCALL libc_getgrgid)(gid_t gid)
/*[[[body:getgrgid]]]*/
{
	CRT_UNIMPLEMENTED("getgrgid"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:getgrgid]]]*/

/*[[[head:getgrnam,hash:0x7d71d679]]]*/
/* Search for an entry with a matching group name */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.database.group.getgrnam") struct group *
NOTHROW_RPC(LIBCCALL libc_getgrnam)(char const *__restrict name)
/*[[[body:getgrnam]]]*/
{
	CRT_UNIMPLEMENTED("getgrnam"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:getgrnam]]]*/

/*[[[head:setgrent,hash:0xa20e4f94]]]*/
/* Rewind the group-file stream */
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.database.group.setgrent") void
NOTHROW_RPC(LIBCCALL libc_setgrent)(void)
/*[[[body:setgrent]]]*/
{
	CRT_UNIMPLEMENTED("setgrent"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:setgrent]]]*/

/*[[[head:endgrent,hash:0x13edb166]]]*/
/* Close the group-file stream */
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.database.group.endgrent") void
NOTHROW_RPC_NOKOS(LIBCCALL libc_endgrent)(void)
/*[[[body:endgrent]]]*/
{
	CRT_UNIMPLEMENTED("endgrent"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:endgrent]]]*/

/*[[[head:getgrent,hash:0x34273083]]]*/
/* Read an entry from the group-file stream, opening it if necessary */
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.database.group.getgrent") struct group *
NOTHROW_RPC(LIBCCALL libc_getgrent)(void)
/*[[[body:getgrent]]]*/
{
	CRT_UNIMPLEMENTED("getgrent"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:getgrent]]]*/

/*[[[head:putgrent,hash:0x5bb7c31e]]]*/
/* Write the given entry onto the given stream */
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.database.group.putgrent") int
NOTHROW_RPC(LIBCCALL libc_putgrent)(struct group const *__restrict entry,
                                    FILE *__restrict stream)
/*[[[body:putgrent]]]*/
{
	CRT_UNIMPLEMENTED("putgrent"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:putgrent]]]*/

/*[[[head:getgrgid_r,hash:0x5d6ca359]]]*/
/* Search for an entry with a matching group ID */
INTERN NONNULL((2, 3, 5))
ATTR_WEAK ATTR_SECTION(".text.crt.database.group.getgrgid_r") int
NOTHROW_RPC(LIBCCALL libc_getgrgid_r)(gid_t gid,
                                      struct group *__restrict resultbuf,
                                      char *__restrict buffer,
                                      size_t buflen,
                                      struct group **__restrict result)
/*[[[body:getgrgid_r]]]*/
{
	CRT_UNIMPLEMENTED("getgrgid_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:getgrgid_r]]]*/

/*[[[head:getgrnam_r,hash:0x2dbdab00]]]*/
/* Search for an entry with a matching group name */
INTERN NONNULL((1, 2, 3, 5))
ATTR_WEAK ATTR_SECTION(".text.crt.database.group.getgrnam_r") int
NOTHROW_RPC(LIBCCALL libc_getgrnam_r)(char const *__restrict name,
                                      struct group *__restrict resultbuf,
                                      char *__restrict buffer,
                                      size_t buflen,
                                      struct group **__restrict result)
/*[[[body:getgrnam_r]]]*/
{
	CRT_UNIMPLEMENTED("getgrnam_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:getgrnam_r]]]*/

/*[[[head:getgrent_r,hash:0x2853dca5]]]*/
/* Read an entry from the group-file stream, opening it if necessary */
INTERN NONNULL((1, 2, 4))
ATTR_WEAK ATTR_SECTION(".text.crt.database.group.getgrent_r") int
NOTHROW_RPC(LIBCCALL libc_getgrent_r)(struct group *__restrict resultbuf,
                                      char *__restrict buffer,
                                      size_t buflen,
                                      struct group **__restrict result)
/*[[[body:getgrent_r]]]*/
{
	CRT_UNIMPLEMENTED("getgrent_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:getgrent_r]]]*/

/*[[[head:fgetgrent_r,hash:0x2a002dca]]]*/
/* Read a group entry from STREAM */
INTERN NONNULL((1, 2, 3, 5))
ATTR_WEAK ATTR_SECTION(".text.crt.database.group.fgetgrent_r") int
NOTHROW_RPC(LIBCCALL libc_fgetgrent_r)(FILE *__restrict stream,
                                       struct group *__restrict resultbuf,
                                       char *__restrict buffer,
                                       size_t buflen,
                                       struct group **__restrict result)
/*[[[body:fgetgrent_r]]]*/
{
	CRT_UNIMPLEMENTED("fgetgrent_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:fgetgrent_r]]]*/

/*[[[head:fgetgrent,hash:0x5a30c0a1]]]*/
/* Read a group entry from STREAM */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.database.group.fgetgrent") struct group *
NOTHROW_RPC(LIBCCALL libc_fgetgrent)(FILE *__restrict stream)
/*[[[body:fgetgrent]]]*/
{
	CRT_UNIMPLEMENTED("fgetgrent"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:fgetgrent]]]*/

/*[[[head:setgroups,hash:0x79acf470]]]*/
/* Set the group set for the current user to GROUPS (N of them) */
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.database.group.setgroups") int
NOTHROW_RPC(LIBCCALL libc_setgroups)(size_t count,
                                     gid_t const *groups)
/*[[[body:setgroups]]]*/
{
	CRT_UNIMPLEMENTED("setgroups"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:setgroups]]]*/

/*[[[head:getgrouplist,hash:0x5c308005]]]*/
/* Store at most *NGROUPS members of the group set for USER into
 * *GROUPS. Also include GROUP. The actual number of groups found is
 * returned in *NGROUPS.  Return -1 if the if *NGROUPS is too small */
INTERN NONNULL((1, 3, 4))
ATTR_WEAK ATTR_SECTION(".text.crt.database.group.getgrouplist") int
NOTHROW_RPC(LIBCCALL libc_getgrouplist)(char const *user,
                                        gid_t group,
                                        gid_t *groups,
                                        int *ngroups)
/*[[[body:getgrouplist]]]*/
{
	CRT_UNIMPLEMENTED("getgrouplist"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:getgrouplist]]]*/

/*[[[head:initgroups,hash:0xa01572c0]]]*/
/* Initialize the group set for the current user
 * by reading the group database and using all groups
 * of which USER is a member. Also include GROUP. */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.database.group.initgroups") int
NOTHROW_RPC(LIBCCALL libc_initgroups)(char const *user,
                                      gid_t group)
/*[[[body:initgroups]]]*/
{
	CRT_UNIMPLEMENTED("initgroups"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:initgroups]]]*/

/*[[[end:implementation]]]*/



/*[[[start:exports,hash:0xae5263df]]]*/
DEFINE_PUBLIC_WEAK_ALIAS(getgrgid, libc_getgrgid);
DEFINE_PUBLIC_WEAK_ALIAS(getgrnam, libc_getgrnam);
DEFINE_PUBLIC_WEAK_ALIAS(setgrent, libc_setgrent);
DEFINE_PUBLIC_WEAK_ALIAS(endgrent, libc_endgrent);
DEFINE_PUBLIC_WEAK_ALIAS(getgrent, libc_getgrent);
DEFINE_PUBLIC_WEAK_ALIAS(putgrent, libc_putgrent);
DEFINE_PUBLIC_WEAK_ALIAS(getgrgid_r, libc_getgrgid_r);
DEFINE_PUBLIC_WEAK_ALIAS(getgrnam_r, libc_getgrnam_r);
DEFINE_PUBLIC_WEAK_ALIAS(getgrent_r, libc_getgrent_r);
DEFINE_PUBLIC_WEAK_ALIAS(fgetgrent_r, libc_fgetgrent_r);
DEFINE_PUBLIC_WEAK_ALIAS(fgetgrent, libc_fgetgrent);
DEFINE_PUBLIC_WEAK_ALIAS(setgroups, libc_setgroups);
DEFINE_PUBLIC_WEAK_ALIAS(getgrouplist, libc_getgrouplist);
DEFINE_PUBLIC_WEAK_ALIAS(initgroups, libc_initgroups);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_GRP_C */
