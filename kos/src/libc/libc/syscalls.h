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
#ifndef GUARD_LIBC_LIBC_SYSCALLS_H
#define GUARD_LIBC_LIBC_SYSCALLS_H 1

/* Keep this one the first */
#include "../api.h"
/**/

#include <kos/syscalls.h>

#include <fcntl.h>
#include <syscall.h>

#if (!defined(__NRFEAT_DEFINED_SYSCALL_ARGUMENT_TYPES) || \
     !defined(__NRFEAT_DEFINED_SYSCALL_ARGUMENT_COUNT))
#undef __WANT_SYSCALL_ARGUMENT_TYPES
#define __WANT_SYSCALL_ARGUMENT_TYPES
#undef __WANT_SYSCALL_ARGUMENT_COUNT
#define __WANT_SYSCALL_ARGUMENT_COUNT
#include <asm/syscalls-proto.h>
#endif /* !... */

#define SYSCALL_ARG_TYPE_OF3(a, b)      b
#define SYSCALL_ARG_TYPE_OF2(x)         SYSCALL_ARG_TYPE_OF3 x
#define SYSCALL_ARG_TYPE_OF(name, argi) SYSCALL_ARG_TYPE_OF2(__NRAT##argi##_##name)


/* Substitute basic system calls with advanced variants. */
#ifndef SYS_unlink
#define sys_unlink(file) sys_unlinkat(AT_FDCWD, file, 0)
#endif /* !SYS_unlink */
#ifndef SYS_chdir
#define sys_chdir(path) sys_fchdirat(AT_FDCWD, path, 0)
#endif /* !SYS_chdir */
#ifndef SYS_rmdir
#define sys_rmdir(path) sys_unlinkat(AT_FDCWD, path, AT_REMOVEDIR)
#endif /* !SYS_rmdir */
#ifndef SYS_pipe
#define sys_pipe(fds) sys_pipe2(fds, 0)
#endif /* !SYS_pipe */
#ifndef SYS_execve
#define sys_execve(path, argv, envp) sys_execveat(AT_FDCWD, path, argv, envp, 0)
#endif /* !SYS_execve */
#ifndef SYS_fexecve
#define sys_fexecve(execfd, argv, envp) sys_execveat(execfd, "", argv, envp, AT_EMPTY_PATH)
#endif /* !SYS_fexecve */
#ifndef SYS_symlink
#define sys_symlink(link_text, target_path) sys_symlinkat(link_text, AT_FDCWD, target_path)
#endif /* !SYS_symlink */
#ifndef SYS_symlinkat
#define sys_symlinkat(link_text, tofd, target_path) sys_fsymlinkat(link_text, tofd, target_path, 0)
#endif /* !SYS_symlinkat */
#ifndef SYS_readlink
#define sys_readlink(path, buf, buflen) sys_readlinkat(AT_FDCWD, path, buf, buflen)
#endif /* !SYS_readlink */
#ifndef SYS_readlinkat
#define sys_readlinkat(dfd, path, buf, buflen) sys_freadlinkat(dfd, path, buf, buflen, 0)
#endif /* !SYS_readlinkat */
#ifndef SYS_fchdir
#define sys_fchdir(fd) sys_dup2(fd, AT_FDCWD)
#endif /* !SYS_fchdir */



/* Fix uid/gid sizes */
#if __SIZEOF_UID_T__ != 4 && __SIZEOF_GID_T__ != 4
#ifdef SYS_getuid
#undef SYS_getuid32
#endif /* SYS_getuid */
#ifdef SYS_geteuid
#undef SYS_geteuid32
#endif /* SYS_geteuid */
#ifdef SYS_getgid
#undef SYS_getgid32
#endif /* SYS_getgid */
#ifdef SYS_getegid
#undef SYS_getegid32
#endif /* SYS_getegid */
#ifdef SYS_setgroups
#undef SYS_setgroups32
#endif /* SYS_setgroups */
#ifdef SYS_setuid
#undef SYS_setuid32
#endif /* SYS_setuid */
#ifdef SYS_setgid
#undef SYS_setgid32
#endif /* SYS_setgid */
#ifdef SYS_chown
#undef SYS_chown32
#endif /* SYS_chown */
#ifdef SYS_lchown
#undef SYS_lchown32
#endif /* SYS_lchown */
#ifdef SYS_fchownat
#undef SYS_fchownat32
#endif /* SYS_fchownat */
#ifdef SYS_getresuid
#undef SYS_getresuid32
#endif /* SYS_getresuid */
#ifdef SYS_getresgid
#undef SYS_getresgid32
#endif /* SYS_getresgid */
#ifdef SYS_setresuid
#undef SYS_setresuid32
#endif /* SYS_setresuid */
#ifdef SYS_setresgid
#undef SYS_setresgid32
#endif /* SYS_setresgid */
#ifdef SYS_fchown
#undef SYS_fchown32
#endif /* SYS_fchown */
#ifdef SYS_setreuid
#undef SYS_setreuid32
#endif /* SYS_setreuid */
#ifdef SYS_setregid
#undef SYS_setregid32
#endif /* SYS_setregid */
#endif /* __SIZEOF_UID_T__ != 4 && __SIZEOF_GID_T__ != 4 */

#ifdef SYS_getuid32
#define _sys_getuid() (uid_t)sys_getuid32()
#else /* SYS_getuid32 */
#define _sys_getuid() (uid_t)sys_getuid()
#endif /* SYS_getuid32 */
#ifdef SYS_geteuid32
#define _sys_geteuid() (uid_t)sys_geteuid32()
#else /* SYS_geteuid32 */
#define _sys_geteuid() (uid_t)sys_geteuid()
#endif /* !SYS_geteuid32 */
#ifdef SYS_getgid32
#define _sys_getgid() (gid_t)sys_getgid32()
#else /* SYS_getgid32 */
#define _sys_getgid() (gid_t)sys_getgid()
#endif /* !SYS_getgid32 */
#ifdef SYS_getegid32
#define _sys_getegid() (gid_t)sys_getegid32()
#else /* SYS_getegid32 */
#define _sys_getegid() (gid_t)sys_getegid()
#endif /* !SYS_getegid32 */
#ifdef SYS_setgroups32
#define _sys_getgroups(size, list) sys_getgroups32(size, (uint32_t *)(list))
#else /* SYS_setgroups32 */
#define _sys_getgroups(size, list) sys_getgroups(size, (SYSCALL_ARG_TYPE_OF(getgroups, 1))(list))
#endif /* !SYS_setgroups32 */
#ifdef SYS_setuid32
#define _sys_setuid(uid) sys_setuid32((uint32_t)(uid))
#else /* SYS_setuid32 */
#define _sys_setuid(uid) sys_setuid((SYSCALL_ARG_TYPE_OF(setuid, 0))(uid))
#endif /* !SYS_setuid32 */
#ifdef SYS_setgid32
#define _sys_setgid(gid) sys_setgid32((uint32_t)(gid))
#else /* SYS_setgid32 */
#define _sys_setgid(gid) sys_setgid((SYSCALL_ARG_TYPE_OF(setgid, 0))(gid))
#endif /* !SYS_setgid32 */
#ifdef SYS_fchownat32
#define _sys_fchownat(dirfd, file, owner, group, flags) \
	sys_fchownat32(dirfd, file, (uint32_t)(owner), (uint32_t)(group), flags)
#else /* SYS_fchownat32 */
#define _sys_fchownat(dirfd, file, owner, group, flags) \
	sys_fchownat(dirfd, file, (SYSCALL_ARG_TYPE_OF(fchownat, 2))(owner), (SYSCALL_ARG_TYPE_OF(fchownat, 3))(group), flags)
#endif /* !SYS_fchownat32 */
#ifdef SYS_chown32
#define _sys_chown(file, owner, group) \
	sys_chown32(file, (uint32_t)(owner), (uint32_t)(group))
#elif defined(SYS_chown)
#define _sys_chown(file, owner, group) \
	sys_chown(file, (SYSCALL_ARG_TYPE_OF(chown, 1))(owner), (SYSCALL_ARG_TYPE_OF(chown, 2))(group))
#else /* ... */
#define _sys_chown(file, owner, group) \
	_sys_fchownat(AT_FDCWD, file, owner, group, 0)
#endif /* !... */
#ifdef SYS_lchown32
#define _sys_lchown(file, owner, group) \
	sys_lchown32(file, (uint32_t)(owner), (uint32_t)(group))
#elif defined(SYS_lchown)
#define _sys_lchown(file, owner, group) \
	sys_lchown(file, (SYSCALL_ARG_TYPE_OF(lchown, 1))(owner), (SYSCALL_ARG_TYPE_OF(lchown, 2))(group))
#else /* ... */
#define _sys_lchown(file, owner, group) \
	_sys_fchownat(AT_FDCWD, file, owner, group, AT_SYMLINK_NOFOLLOW)
#endif /* !... */
#ifdef SYS_getresuid32
#define _sys_getresuid(ruid, euid, suid) \
	sys_getresuid32((uint32_t *)(ruid), (uint32_t *)(euid), (uint32_t *)(suid))
#else /* SYS_getresuid32 */
#define _sys_getresuid(ruid, euid, suid)                     \
	sys_getresuid((SYSCALL_ARG_TYPE_OF(getresuid, 0))(ruid), \
	              (SYSCALL_ARG_TYPE_OF(getresuid, 1))(euid), \
	              (SYSCALL_ARG_TYPE_OF(getresuid, 2))(suid))
#endif /* !SYS_getresuid32 */
#ifdef SYS_getresgid32
#define _sys_getresgid(rgid, egid, sgid) \
	sys_getresgid32((uint32_t *)(rgid), (uint32_t *)(egid), (uint32_t *)(sgid))
#else /* SYS_getresgid32 */
#define _sys_getresgid(rgid, egid, sgid)                     \
	sys_getresgid((SYSCALL_ARG_TYPE_OF(getresgid, 0))(rgid), \
	              (SYSCALL_ARG_TYPE_OF(getresgid, 1))(egid), \
	              (SYSCALL_ARG_TYPE_OF(getresgid, 2))(sgid))
#endif /* !SYS_getresuid32 */
#ifdef SYS_setresuid32
#define _sys_setresuid(ruid, euid, suid) \
	sys_setresuid32((uint32_t)(ruid), (uint32_t)(euid), (uint32_t)(suid))
#else /* SYS_setresuid32 */
#define _sys_setresuid(ruid, euid, suid)                     \
	sys_setresuid((SYSCALL_ARG_TYPE_OF(setresuid, 0))(ruid), \
	              (SYSCALL_ARG_TYPE_OF(setresuid, 1))(euid), \
	              (SYSCALL_ARG_TYPE_OF(setresuid, 2))(suid))
#endif /* !SYS_setresuid32 */
#ifdef SYS_setresgid32
#define _sys_setresgid(rgid, egid, sgid) \
	sys_setresgid32((uint32_t)(rgid), (uint32_t)(egid), (uint32_t)(sgid))
#else /* SYS_setresgid32 */
#define _sys_setresgid(rgid, egid, sgid)                     \
	sys_setresgid((SYSCALL_ARG_TYPE_OF(setresgid, 0))(rgid), \
	              (SYSCALL_ARG_TYPE_OF(setresgid, 1))(egid), \
	              (SYSCALL_ARG_TYPE_OF(setresgid, 2))(sgid))
#endif /* !SYS_setresgid32 */
#ifdef SYS_fchown32
#define _sys_fchown(fd, owner, group) \
	sys_fchown32(fd, (uint32_t)(owner), (uint32_t)(group))
#else /* SYS_fchown32 */
#define _sys_fchown(fd, owner, group) \
	sys_fchown(fd, (SYSCALL_ARG_TYPE_OF(fchown, 1))(owner), (SYSCALL_ARG_TYPE_OF(fchown, 2))(group))
#endif /* !SYS_fchown32 */
#ifdef SYS_setreuid32
#define _sys_setreuid(ruid, euid) \
	sys_setreuid32((uint32_t)(ruid), (uint32_t)(euid))
#else /* SYS_setreuid32 */
#define _sys_setreuid(ruid, euid) \
	sys_setreuid((SYSCALL_ARG_TYPE_OF(setreuid, 0))(ruid), (SYSCALL_ARG_TYPE_OF(setreuid, 1))(euid))
#endif /* !SYS_setreuid32 */
#ifdef SYS_setregid32
#define _sys_setregid(rgid, egid) \
	sys_setregid32((uint32_t)(rgid), (uint32_t)(egid))
#else /* SYS_setregid32 */
#define _sys_setregid(rgid, egid) \
	sys_setregid((SYSCALL_ARG_TYPE_OF(setregid, 0))(rgid), (SYSCALL_ARG_TYPE_OF(setregid, 1))(egid))
#endif /* !SYS_setreuid32 */

#if defined(SYS_clock_getres64) && !defined(SYS_clock_getres_time64)
#define SYS_clock_getres_time64 SYS_clock_getres64
#define sys_clock_getres_time64 sys_clock_getres64
#endif /* SYS_clock_getres64 && SYS_clock_getres_time64 */

#if defined(SYS_clock_nanosleep64) && !defined(SYS_clock_nanosleep_time64)
#define SYS_clock_nanosleep_time64 SYS_clock_nanosleep64
#define sys_clock_nanosleep_time64 sys_clock_nanosleep64
#endif /* SYS_clock_nanosleep64 && SYS_clock_nanosleep_time64 */

#if defined(SYS_select64) && !defined(SYS_select_time64)
#define SYS_select_time64 SYS_select64
#define sys_select_time64 sys_select64
#endif /* SYS_select64 && SYS_select_time64 */

#if defined(SYS_pselect6_64) && !defined(SYS_pselect6_time64)
#define SYS_pselect6_time64 SYS_pselect6_64
#define sys_pselect6_time64 sys_pselect6_64
#endif /* SYS_pselect6_64 && SYS_pselect6_time64 */

#if !defined(SYS__newselect) && defined(SYS_select)
#if __NRAC_select == 5
#define sys__newselect(nfds, readfds, writefds, exceptfds, timeout) \
	sys_select(nfds, readfds, writefds, exceptfds, timeout)
#elif __NRAC_select == 1
#include <kos/compat/linux-oldselect.h>
#define sys__newselect(nfds, readfds, writefds, exceptfds, timeout) \
	({                                                              \
		struct sel_arg_struct _arg;                                 \
		_arg.n    = (ulongptr_t)(nfds);                             \
		_arg.inp  = readfds;                                        \
		_arg.outp = writefds;                                       \
		_arg.exp  = exceptfds;                                      \
		_arg.tvp  = timeout;                                        \
		sys_select(&_arg);                                          \
	})
#endif /* __NRAC_select == ... */
#endif /* !SYS__newselect && SYS_select */

#ifndef SYS_recv
#ifdef SYS_recvfrom
#define sys_recv(sockfd, buf, bufsize, msg_flags) \
	sys_recvfrom(sockfd, buf, bufsize, msg_flags, NULL, 0)
#elif defined(SYS_recvmsg)
#define sys_recv(sockfd, buf, bufsize, msg_flags) \
	({                                            \
		struct msghdr _msg;                       \
		struct iovec _iov[1];                     \
		_msg.msg_name       = NULL;               \
		_msg.msg_namelen    = 0;                  \
		_msg.msg_iov        = _iov;               \
		_msg.msg_iovlen     = 1;                  \
		_iov[0].iov_base    = buf;                \
		_iov[0].iov_len     = bufsize;            \
		_msg.msg_control    = NULL;               \
		_msg.msg_controllen = 0;                  \
		sys_recvmsg(sockfd, &_msg, msg_flags);    \
	})
#elif defined(SYS_recvmmsg)
#define sys_recv(sockfd, buf, bufsize, msg_flags)                  \
	({                                                             \
		ssize_t _result;                                           \
		struct mmsghdr _msg;                                       \
		struct iovec _iov[1];                                      \
		_msg.msg_hdr.msg_name       = NULL;                        \
		_msg.msg_hdr.msg_namelen    = 0;                           \
		_msg.msg_hdr.msg_iov        = _iov;                        \
		_msg.msg_hdr.msg_iovlen     = 1;                           \
		_iov[0].iov_base            = buf;                         \
		_iov[0].iov_len             = bufsize;                     \
		_msg.msg_hdr.msg_control    = NULL;                        \
		_msg.msg_hdr.msg_controllen = 0;                           \
		_result = sys_recvmmsg(sockfd, &_msg, 1, msg_flags, NULL); \
		if (_result >= 1)                                          \
			_result = _msg.msg_len;                                \
		_result;                                                   \
	})
#endif /* ... */
#endif /* !SYS_recv */

#ifndef SYS_recvfrom
#ifdef SYS_recvmsg
#define sys_recvfrom(sockfd, buf, bufsize, msg_flags, addr, addr_len) \
	({                                                                \
		ssize_t _result;                                              \
		struct msghdr _msg;                                           \
		struct iovec _iov[1];                                         \
		_msg.msg_name       = (struct sockaddr *)(addr);              \
		_msg.msg_namelen    = (addr_len) ? *(addr_len) : 0;           \
		_msg.msg_iov        = _iov;                                   \
		_msg.msg_iovlen     = 1;                                      \
		_iov[0].iov_base    = buf;                                    \
		_iov[0].iov_len     = bufsize;                                \
		_msg.msg_control    = NULL;                                   \
		_msg.msg_controllen = 0;                                      \
		_result = sys_recvmsg(sockfd, &_msg, msg_flags);              \
		if (_result >= 0 && addr_len)                                 \
			*addr_len = _msg.msg_namelen;                             \
		_result;                                                      \
	})
#elif defined(SYS_recvmmsg)
#define sys_recvfrom(sockfd, buf, bufsize, msg_flags, addr, addr_len) \
	({                                                                \
		ssize_t _result;                                              \
		struct mmsghdr _msg;                                          \
		struct iovec _iov[1];                                         \
		_msg.msg_hdr.msg_name       = (struct sockaddr *)(addr);      \
		_msg.msg_hdr.msg_namelen    = (addr_len) ? *(addr_len) : 0;   \
		_msg.msg_hdr.msg_iov        = _iov;                           \
		_msg.msg_hdr.msg_iovlen     = 1;                              \
		_iov[0].iov_base            = buf;                            \
		_iov[0].iov_len             = bufsize;                        \
		_msg.msg_hdr.msg_control    = NULL;                           \
		_msg.msg_hdr.msg_controllen = 0;                              \
		_result = sys_recvmmsg(sockfd, &_msg, 1, msg_flags, NULL);    \
		if (_result >= 1) {                                           \
			if (addr_len)                                             \
				*(addr_len) = _msg.msg_hdr.msg_namelen;               \
			_result = _msg.msg_len;                                   \
		}                                                             \
		_result;                                                      \
	})
#endif /* ... */
#endif /* !SYS_recvfrom */

#if !defined(SYS_recvmsg) && defined(SYS_recvmmsg)
#define sys_recvfrom(sockfd, message, msg_flags_)                   \
	({                                                              \
		ssize_t _result;                                            \
		struct mmsghdr _msg;                                        \
		_msg.msg_hdr                = *(message);                   \
		_msg.msg_hdr.msg_control    = NULL;                         \
		_msg.msg_hdr.msg_controllen = 0;                            \
		_result = sys_recvmmsg(sockfd, &_msg, 1, msg_flags_, NULL); \
		(message)->msg_namelen      = _msg.msg_hdr.msg_namelen;     \
		(message)->msg_controllen   = _msg.msg_hdr.msg_controllen;  \
		(message)->msg_flags        = _msg.msg_hdr.msg_flags;       \
		if (_result >= 1)                                           \
			_result = _msg.msg_len;                                 \
		_result;                                                    \
	})
#endif /* !SYS_recvmsg && SYS_recvmmsg */

#ifndef SYS_send
#ifdef SYS_sendto
#define sys_send(sockfd, buf, bufsize, msg_flags) \
	sys_sendto(sockfd, buf, bufsize, msg_flags, NULL, 0)
#elif defined(SYS_sendmsg)
#define sys_send(sockfd, buf, bufsize, msg_flags) \
	({                                            \
		struct msghdr _msg;                       \
		struct iovec _iov[1];                     \
		_msg.msg_name       = NULL;               \
		_msg.msg_namelen    = 0;                  \
		_msg.msg_iov        = _iov;               \
		_msg.msg_iovlen     = 1;                  \
		_iov[0].iov_base    = (void *)buf;        \
		_iov[0].iov_len     = bufsize;            \
		_msg.msg_control    = NULL;               \
		_msg.msg_controllen = 0;                  \
		sys_sendmsg(sockfd, &_msg, msg_flags);    \
	})
#elif defined(SYS_sendmmsg)
#define sys_send(sockfd, buf, bufsize, msg_flags)            \
	({                                                       \
		ssize_t _result;                                     \
		struct mmsghdr _msg;                                 \
		struct iovec _iov[1];                                \
		_msg.msg_hdr.msg_name       = NULL;                  \
		_msg.msg_hdr.msg_namelen    = 0;                     \
		_msg.msg_hdr.msg_iov        = _iov;                  \
		_msg.msg_hdr.msg_iovlen     = 1;                     \
		_iov[0].iov_base            = (void *)(buf);         \
		_iov[0].iov_len             = bufsize;               \
		_msg.msg_hdr.msg_control    = NULL;                  \
		_msg.msg_hdr.msg_controllen = 0;                     \
		_result = sys_sendmmsg(sockfd, &_msg, 1, msg_flags); \
		if (_result >= 1)                                    \
			_result = _msg.msg_len;                          \
		_result;                                             \
	})
#endif /* ... */
#endif /* !SYS_send */

#ifndef SYS_sendto
#ifdef SYS_sendmsg
#define sys_sendto(sockfd, buf, bufsize, msg_flags, addr, addr_len) \
	({                                                              \
		struct msghdr _msg;                                         \
		struct iovec _iov[1];                                       \
		_msg.msg_name       = (struct sockaddr *)addr;              \
		_msg.msg_namelen    = addr_len;                             \
		_msg.msg_iov        = _iov;                                 \
		_msg.msg_iovlen     = 1;                                    \
		_iov[0].iov_base    = (void *)buf;                          \
		_iov[0].iov_len     = bufsize;                              \
		_msg.msg_control    = NULL;                                 \
		_msg.msg_controllen = 0;                                    \
		sys_sendmsg(sockfd, &_msg, msg_flags);                      \
	})
#elif defined(SYS_sendmmsg)
#define sys_sendto(sockfd, buf, bufsize, msg_flags, addr, addr_len) \
	({                                                              \
		ssize_t _result;                                            \
		struct mmsghdr _msg;                                        \
		struct iovec _iov[1];                                       \
		_msg.msg_hdr.msg_name       = (struct sockaddr *)addr;      \
		_msg.msg_hdr.msg_namelen    = addr_len;                     \
		_msg.msg_hdr.msg_iov        = _iov;                         \
		_msg.msg_hdr.msg_iovlen     = 1;                            \
		_iov[0].iov_base            = (void *)buf;                  \
		_iov[0].iov_len             = bufsize;                      \
		_msg.msg_hdr.msg_control    = NULL;                         \
		_msg.msg_hdr.msg_controllen = 0;                            \
		_result = sys_sendmmsg(sockfd, &_msg, 1, msg_flags);        \
		if (_result >= 1)                                           \
			_result = _msg.msg_len;                                 \
		_result;                                                    \
	})
#endif /* ... */
#endif /* !SYS_sendto */

#if !defined(SYS_sendmsg) && defined(SYS_sendmmsg)
#define sys_sendmsg(sockfd, message, msg_flags_)              \
	({                                                        \
		ssize_t _result;                                      \
		struct mmsghdr _msg;                                  \
		_msg.msg_hdr                = *(message);             \
		_msg.msg_hdr.msg_control    = NULL;                   \
		_msg.msg_hdr.msg_controllen = 0;                      \
		_result = sys_sendmmsg(sockfd, &_msg, 1, msg_flags_); \
		if (_result >= 1)                                     \
			_result = _msg.msg_len;                           \
		_result;                                              \
	})
#endif /* !SYS_sendto && SYS_sendmmsg */

#if !defined(SYS_accept) && defined(SYS_accept4)
#define sys_accept(sockfd, addr, addr_len) \
	sys_accept4(sockfd, addr, addr_len, 0)
#endif /* !SYS_accept && SYS_accept4 */


#if defined(SYS_sync_file_range2) && !defined(SYS_sync_file_range)
#define sys_sync_file_range(fd, offset, count, flags) \
	sys_sync_file_range2(fd, flags, offset, count)
#endif /* SYS_sync_file_range2 && !SYS_sync_file_range */


#endif /* !GUARD_LIBC_LIBC_SYSCALLS_H */
