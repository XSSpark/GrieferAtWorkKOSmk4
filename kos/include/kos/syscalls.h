/* HASH CRC-32:0x7c099e90 */
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
#ifndef _KOS_SYSCALL_H
#define _KOS_SYSCALL_H 1

#include <__stdinc.h>
#include <kos/asm/syscall.h>

#include <bits/iovec-struct.h>
#include <bits/itimerspec.h>
#include <bits/itimerval.h>
#include <bits/rusage-struct.h>
#include <bits/sigaction-struct.h>
#include <bits/siginfo-struct.h>
#include <bits/statfs.h>
#include <bits/timespec.h>
#include <bits/timeval.h>
#include <bits/types.h>
#include <kos/compat/linux-stat.h>
#include <kos/kernel/cpu-state.h>
#include <kos/kernel/fpu-state.h>
#include <librpc/bits/syscall-info.h>
#include <librt/bits/mqueue.h>


#ifndef __CDECLARE_SC
#include <__crt.h>
#if 1 /* TODO: cancellation_point-system calls aren't nothrow! - All others are. */
#define __CDECLARE_SC(attr, Treturn, name, param, args)  __CDECLARE(attr,Treturn,,sys_##name,param,args)
#define __CDECLARE_VOID_SC(attr, name, param, args)      __CDECLARE_VOID(attr,,sys_##name,param,args)
#else
#define __CDECLARE_SC(attr, Treturn, name, param, args)  __CDECLARE(attr,Treturn,__NOTHROW,sys_##name,param,args)
#define __CDECLARE_VOID_SC(attr, name, param, args)      __CDECLARE_VOID(attr,__NOTHROW,sys_##name,param,args)
#endif
#define __CDECLARE_XSC(attr, Treturn, name, param, args) __CDECLARE(attr,Treturn,,sys_X##name,param,args)
#define __CDECLARE_VOID_XSC(attr, name, param, args)     __CDECLARE_VOID(attr,,sys_X##name,param,args)
#define __PRIVATE_CRT_HAVE_PLACEHOLDER_1         ,
#define __PRIVATE_CRT_HAVE_ARG_IMPL(x, val, ...) val
#define __PRIVATE_CRT_HAVE_ARG(x)  __PRIVATE_CRT_HAVE_ARG_IMPL x
#define __PRIVATE_CRT_HAVE3(...)   __PRIVATE_CRT_HAVE_ARG((__VA_ARGS__ 1,0))
#define __PRIVATE_CRT_HAVE2(x)     __PRIVATE_CRT_HAVE3(__PRIVATE_CRT_HAVE_PLACEHOLDER_##x)
#define __PRIVATE_CRT_ISDEFINED(x) __PRIVATE_CRT_HAVE2(x)
#define __CRT_HAVE_SC(name)        __PRIVATE_CRT_ISDEFINED(__CRT_HAVE_sys_##name)
#define __CRT_HAVE_XSC(name)       __PRIVATE_CRT_ISDEFINED(__CRT_HAVE_sys_X##name)
#endif /* !__CDECLARE_SC */

#ifdef __CC__
__SYSDECL_BEGIN

#ifdef __COMPILER_HAVE_PRAGMA_PUSHMACRO
#pragma push_macro("timezone")
#endif /* __COMPILER_HAVE_PRAGMA_PUSHMACRO */
#undef timezone

struct __cpu_set_struct;
struct __fd_set_struct;
struct __siginfo_struct;
struct __sigset_struct;
struct __timespec;
struct epoll_event;
struct file_handle;
struct fpustate;
struct getcpu_cache;
struct iovec;
struct itimerspec;
struct itimerval;
struct linux64_stat32;
struct linux_dirent;
struct linux_dirent64;
struct linux_stat;
struct mmsghdr;
struct mq_attr;
struct msghdr;
struct pollfd;
struct rlimit;
struct rlimit64;
struct rpc_syscall_info;
struct rusage;
struct sched_param;
struct sigaction;
struct sigaltstack;
struct sigevent;
struct sockaddr;
struct statfs;
struct sysinfo;
struct timespec;
struct timeval;
struct timezone;
struct tms;
struct ucpustate;
struct ustat;
struct utimbuf;
struct utsname;

#if __CRT_HAVE_SC(_sysctl)
__CDECLARE_SC(,__errno_t,_sysctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(_sysctl) */
#if __CRT_HAVE_SC(accept)
__CDECLARE_SC(,__errno_t,accept,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(accept) */
#if __CRT_HAVE_SC(accept4)
__CDECLARE_SC(,__fd_t,accept4,(__fd_t __sockfd, struct sockaddr *__addr, __socklen_t *__addr_len, __syscall_ulong_t __flags),(__sockfd,__addr,__addr_len,__flags))
#endif /* __CRT_HAVE_SC(accept4) */
#if __CRT_HAVE_SC(access)
/* @param: type: Set of `R_OK|W_OK|X_OK' or `F_OK' */
__CDECLARE_SC(,__errno_t,access,(char const *__filename, __syscall_ulong_t __type),(__filename,__type))
#endif /* __CRT_HAVE_SC(access) */
#if __CRT_HAVE_SC(acct)
__CDECLARE_SC(,__errno_t,acct,(char const *__filename),(__filename))
#endif /* __CRT_HAVE_SC(acct) */
#if __CRT_HAVE_SC(add_key)
__CDECLARE_SC(,__errno_t,add_key,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(add_key) */
#if __CRT_HAVE_SC(adjtimex)
__CDECLARE_SC(,__errno_t,adjtimex,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(adjtimex) */
#if __CRT_HAVE_SC(alarm)
__CDECLARE_SC(,__syscall_ulong_t,alarm,(__syscall_ulong_t __seconds),(__seconds))
#endif /* __CRT_HAVE_SC(alarm) */
#if __CRT_HAVE_SC(bdflush)
__CDECLARE_SC(,__errno_t,bdflush,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(bdflush) */
#if __CRT_HAVE_SC(bind)
__CDECLARE_SC(,__errno_t,bind,(__fd_t __sockfd, struct sockaddr const *__addr, __socklen_t __addr_len),(__sockfd,__addr,__addr_len))
#endif /* __CRT_HAVE_SC(bind) */
#if __CRT_HAVE_SC(bpf)
__CDECLARE_SC(,__errno_t,bpf,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(bpf) */
#if __CRT_HAVE_SC(brk)
__CDECLARE_SC(,__errno_t,brk,(void *__addr),(__addr))
#endif /* __CRT_HAVE_SC(brk) */
#if __CRT_HAVE_SC(capget)
__CDECLARE_SC(,__errno_t,capget,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(capget) */
#if __CRT_HAVE_SC(capset)
__CDECLARE_SC(,__errno_t,capset,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(capset) */
#if __CRT_HAVE_SC(chdir)
__CDECLARE_SC(,__errno_t,chdir,(char const *__path),(__path))
#endif /* __CRT_HAVE_SC(chdir) */
#if __CRT_HAVE_SC(chmod)
__CDECLARE_SC(,__errno_t,chmod,(char const *__filename, __mode_t __mode),(__filename,__mode))
#endif /* __CRT_HAVE_SC(chmod) */
#if __CRT_HAVE_SC(chown)
__CDECLARE_SC(,__errno_t,chown,(char const *__filename, __uid_t __owner, __gid_t __group),(__filename,__owner,__group))
#endif /* __CRT_HAVE_SC(chown) */
#if __CRT_HAVE_SC(chroot)
__CDECLARE_SC(,__errno_t,chroot,(char const *__path),(__path))
#endif /* __CRT_HAVE_SC(chroot) */
#if __CRT_HAVE_SC(clock_adjtime)
__CDECLARE_SC(,__errno_t,clock_adjtime,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(clock_adjtime) */
#if __CRT_HAVE_SC(clock_getres)
__CDECLARE_SC(,__errno_t,clock_getres,(__clockid_t __clock_id, struct timespec *__res),(__clock_id,__res))
#endif /* __CRT_HAVE_SC(clock_getres) */
#if __CRT_HAVE_SC(clock_gettime)
__CDECLARE_SC(,__errno_t,clock_gettime,(__clockid_t __clock_id, struct timespec *__tp),(__clock_id,__tp))
#endif /* __CRT_HAVE_SC(clock_gettime) */
#if __CRT_HAVE_SC(clock_nanosleep)
__CDECLARE_SC(,__errno_t,clock_nanosleep,(__clockid_t __clock_id, __syscall_ulong_t __flags, struct timespec const *__requested_time, struct timespec *__remaining),(__clock_id,__flags,__requested_time,__remaining))
#endif /* __CRT_HAVE_SC(clock_nanosleep) */
#if __CRT_HAVE_SC(clock_settime)
__CDECLARE_SC(,__errno_t,clock_settime,(__clockid_t __clock_id, struct timespec const *__tp),(__clock_id,__tp))
#endif /* __CRT_HAVE_SC(clock_settime) */
#if __CRT_HAVE_SC(clone)
__CDECLARE_SC(,__pid_t,clone,(__syscall_ulong_t __flags, void *__child_stack, __pid_t *__ptid, __uintptr_t __newtls, __pid_t *__ctid),(__flags,__child_stack,__ptid,__newtls,__ctid))
#endif /* __CRT_HAVE_SC(clone) */
#if __CRT_HAVE_SC(close)
/* Close a given file descriptor/handle `FD' */
__CDECLARE_SC(,__errno_t,close,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_SC(close) */
#if __CRT_HAVE_SC(connect)
__CDECLARE_SC(,__errno_t,connect,(__fd_t __sockfd, struct sockaddr const *__addr, __socklen_t __addr_len),(__sockfd,__addr,__addr_len))
#endif /* __CRT_HAVE_SC(connect) */
#if __CRT_HAVE_SC(creat)
__CDECLARE_SC(,__fd_t,creat,(char const *__filename, __mode_t __mode),(__filename,__mode))
#endif /* __CRT_HAVE_SC(creat) */
#if __CRT_HAVE_SC(delete_module)
__CDECLARE_SC(,__errno_t,delete_module,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(delete_module) */
#if __CRT_HAVE_SC(dup)
__CDECLARE_SC(,__fd_t,dup,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_SC(dup) */
#if __CRT_HAVE_SC(dup2)
__CDECLARE_SC(,__fd_t,dup2,(__fd_t __oldfd, __fd_t __newfd),(__oldfd,__newfd))
#endif /* __CRT_HAVE_SC(dup2) */
#if __CRT_HAVE_SC(dup3)
/* @param: flags:  Set of `O_CLOEXEC|O_CLOFORK' */
__CDECLARE_SC(,__fd_t,dup3,(__fd_t __oldfd, __fd_t __newfd, __oflag_t __flags),(__oldfd,__newfd,__flags))
#endif /* __CRT_HAVE_SC(dup3) */
#if __CRT_HAVE_SC(epoll_create)
__CDECLARE_SC(,__fd_t,epoll_create,(__syscall_ulong_t __size),(__size))
#endif /* __CRT_HAVE_SC(epoll_create) */
#if __CRT_HAVE_SC(epoll_create1)
__CDECLARE_SC(,__fd_t,epoll_create1,(__syscall_ulong_t __flags),(__flags))
#endif /* __CRT_HAVE_SC(epoll_create1) */
#if __CRT_HAVE_SC(epoll_ctl)
__CDECLARE_SC(,__errno_t,epoll_ctl,(__fd_t __epfd, __syscall_ulong_t __op, __fd_t __fd, struct epoll_event *__event),(__epfd,__op,__fd,__event))
#endif /* __CRT_HAVE_SC(epoll_ctl) */
#if __CRT_HAVE_SC(epoll_pwait)
__CDECLARE_SC(,__errno_t,epoll_pwait,(__fd_t __epfd, struct epoll_event *__events, __syscall_ulong_t __maxevents, __syscall_slong_t __timeout, struct __sigset_struct const *__ss),(__epfd,__events,__maxevents,__timeout,__ss))
#endif /* __CRT_HAVE_SC(epoll_pwait) */
#if __CRT_HAVE_SC(epoll_wait)
__CDECLARE_SC(,__errno_t,epoll_wait,(__fd_t __epfd, struct epoll_event *__events, __syscall_ulong_t __maxevents, __syscall_slong_t __timeout),(__epfd,__events,__maxevents,__timeout))
#endif /* __CRT_HAVE_SC(epoll_wait) */
#if __CRT_HAVE_SC(eventfd)
__CDECLARE_SC(,__fd_t,eventfd,(__syscall_ulong_t __initval),(__initval))
#endif /* __CRT_HAVE_SC(eventfd) */
#if __CRT_HAVE_SC(eventfd2)
__CDECLARE_SC(,__fd_t,eventfd2,(__syscall_ulong_t __initval, __syscall_ulong_t __flags),(__initval,__flags))
#endif /* __CRT_HAVE_SC(eventfd2) */
#if __CRT_HAVE_SC(execve)
__CDECLARE_SC(,__errno_t,execve,(char const *__path, char const *const *__argv, char const *const *__envp),(__path,__argv,__envp))
#endif /* __CRT_HAVE_SC(execve) */
#if __CRT_HAVE_SC(execveat)
/* @param: flags: Set of `0 | AT_EMPTY_PATH|AT_SYMLINK_NOFOLLOW | AT_DOSPATH' */
__CDECLARE_SC(,__errno_t,execveat,(__fd_t __dirfd, char const *__pathname, char const *const *__argv, char const *const *__envp, __atflag_t __flags),(__dirfd,__pathname,__argv,__envp,__flags))
#endif /* __CRT_HAVE_SC(execveat) */
#if __CRT_HAVE_SC(exit)
__CDECLARE_VOID_SC(__ATTR_NORETURN,exit,(__syscall_ulong_t __status),(__status))
#endif /* __CRT_HAVE_SC(exit) */
#if __CRT_HAVE_SC(exit_group)
__CDECLARE_VOID_SC(__ATTR_NORETURN,exit_group,(__syscall_ulong_t __exit_code),(__exit_code))
#endif /* __CRT_HAVE_SC(exit_group) */
#if __CRT_HAVE_SC(faccessat)
/* @param: type: Set of `R_OK|W_OK|X_OK' or `F_OK'
 * @param: flags: Set of `0 | AT_SYMLINK_NOFOLLOW|AT_EACCESS | AT_DOSPATH' */
__CDECLARE_SC(,__errno_t,faccessat,(__fd_t __dirfd, char const *__filename, __syscall_ulong_t __type, __atflag_t __flags),(__dirfd,__filename,__type,__flags))
#endif /* __CRT_HAVE_SC(faccessat) */
#if __CRT_HAVE_SC(fadvise64)
__CDECLARE_SC(,__errno_t,fadvise64,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(fadvise64) */
#if __CRT_HAVE_SC(fallocate)
__CDECLARE_SC(,__errno_t,fallocate,(__fd_t __fd, __syscall_ulong_t __mode, __syscall_ulong_t __offset, __syscall_ulong_t __length),(__fd,__mode,__offset,__length))
#endif /* __CRT_HAVE_SC(fallocate) */
#if __CRT_HAVE_SC(fanotify_init)
__CDECLARE_SC(,__errno_t,fanotify_init,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(fanotify_init) */
#if __CRT_HAVE_SC(fanotify_mark)
__CDECLARE_SC(,__errno_t,fanotify_mark,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(fanotify_mark) */
#if __CRT_HAVE_SC(fchdir)
__CDECLARE_SC(,__errno_t,fchdir,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_SC(fchdir) */
#if __CRT_HAVE_SC(fchmod)
__CDECLARE_SC(,__errno_t,fchmod,(__fd_t __fd, __mode_t __mode),(__fd,__mode))
#endif /* __CRT_HAVE_SC(fchmod) */
#if __CRT_HAVE_SC(fchmodat)
/* @param: flags: Set of `0 | AT_SYMLINK_NOFOLLOW | AT_DOSPATH' */
__CDECLARE_SC(,__errno_t,fchmodat,(__fd_t __dirfd, char const *__filename, __mode_t __mode, __atflag_t __flags),(__dirfd,__filename,__mode,__flags))
#endif /* __CRT_HAVE_SC(fchmodat) */
#if __CRT_HAVE_SC(fchown)
__CDECLARE_SC(,__errno_t,fchown,(__fd_t __fd, __uid_t __owner, __gid_t __group),(__fd,__owner,__group))
#endif /* __CRT_HAVE_SC(fchown) */
#if __CRT_HAVE_SC(fchownat)
/* @param: flags: Set of `0 | AT_SYMLINK_NOFOLLOW | AT_DOSPATH' */
__CDECLARE_SC(,__errno_t,fchownat,(__fd_t __dirfd, char const *__filename, __uid_t __owner, __gid_t __group, __atflag_t __flags),(__dirfd,__filename,__owner,__group,__flags))
#endif /* __CRT_HAVE_SC(fchownat) */
#if __CRT_HAVE_SC(fcntl)
__CDECLARE_SC(,__syscall_slong_t,fcntl,(__fd_t __fd, __syscall_ulong_t __cmd, void *__arg),(__fd,__cmd,__arg))
#endif /* __CRT_HAVE_SC(fcntl) */
#if __CRT_HAVE_SC(fdatasync)
__CDECLARE_SC(,__errno_t,fdatasync,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_SC(fdatasync) */
#if __CRT_HAVE_SC(fgetxattr)
__CDECLARE_SC(,__ssize_t,fgetxattr,(__fd_t __fd, char const *__name, void *__buf, __size_t __bufsize),(__fd,__name,__buf,__bufsize))
#endif /* __CRT_HAVE_SC(fgetxattr) */
#if __CRT_HAVE_SC(finit_module)
__CDECLARE_SC(,__errno_t,finit_module,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(finit_module) */
#if __CRT_HAVE_SC(flistxattr)
__CDECLARE_SC(,__ssize_t,flistxattr,(__fd_t __fd, char *__listbuf, __size_t __listbufsize),(__fd,__listbuf,__listbufsize))
#endif /* __CRT_HAVE_SC(flistxattr) */
#if __CRT_HAVE_SC(flock)
__CDECLARE_SC(,__errno_t,flock,(__fd_t __fd, __syscall_ulong_t __operation),(__fd,__operation))
#endif /* __CRT_HAVE_SC(flock) */
#if __CRT_HAVE_SC(fork)
__CDECLARE_SC(,__pid_t,fork,(void),())
#endif /* __CRT_HAVE_SC(fork) */
#if __CRT_HAVE_SC(fremovexattr)
__CDECLARE_SC(,__errno_t,fremovexattr,(int __fd, char const *__name),(__fd,__name))
#endif /* __CRT_HAVE_SC(fremovexattr) */
#if __CRT_HAVE_SC(fsetxattr)
__CDECLARE_SC(,__errno_t,fsetxattr,(__fd_t __fd, char const *__name, void const *__buf, __size_t __bufsize, __syscall_ulong_t __flags),(__fd,__name,__buf,__bufsize,__flags))
#endif /* __CRT_HAVE_SC(fsetxattr) */
#if __CRT_HAVE_SC(fstatfs)
__CDECLARE_SC(,__errno_t,fstatfs,(__fd_t __file, struct statfs *__buf),(__file,__buf))
#endif /* __CRT_HAVE_SC(fstatfs) */
#if __CRT_HAVE_SC(fsync)
__CDECLARE_SC(,__errno_t,fsync,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_SC(fsync) */
#if __CRT_HAVE_SC(ftruncate)
__CDECLARE_SC(,__errno_t,ftruncate,(__fd_t __fd, __syscall_ulong_t __length),(__fd,__length))
#endif /* __CRT_HAVE_SC(ftruncate) */
#if __CRT_HAVE_SC(futex)
__CDECLARE_SC(,__syscall_slong_t,futex,(__uint32_t *__uaddr, __syscall_ulong_t __futex_op, __uint32_t __val, struct timespec const *__timeout_or_val2, __uint32_t *__uaddr2, __uint32_t __val3),(__uaddr,__futex_op,__val,__timeout_or_val2,__uaddr2,__val3))
#endif /* __CRT_HAVE_SC(futex) */
#if __CRT_HAVE_SC(futimesat)
__CDECLARE_SC(,__errno_t,futimesat,(__fd_t __dirfd, __const char *__filename, struct timeval const *__times),(__dirfd,__filename,__times))
#endif /* __CRT_HAVE_SC(futimesat) */
#if __CRT_HAVE_SC(get_mempolicy)
__CDECLARE_SC(,__errno_t,get_mempolicy,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(get_mempolicy) */
#if __CRT_HAVE_SC(get_robust_list)
__CDECLARE_SC(,__errno_t,get_robust_list,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(get_robust_list) */
#if __CRT_HAVE_SC(getcpu)
__CDECLARE_SC(,__errno_t,getcpu,(__uint32_t *__cpu, __uint32_t *__node, struct getcpu_cache *__tcache),(__cpu,__node,__tcache))
#endif /* __CRT_HAVE_SC(getcpu) */
#if __CRT_HAVE_SC(getcwd)
__CDECLARE_SC(,__ssize_t,getcwd,(char *__buf, __size_t __size),(__buf,__size))
#endif /* __CRT_HAVE_SC(getcwd) */
#if __CRT_HAVE_SC(getdents)
__CDECLARE_SC(,__ssize_t,getdents,(__fd_t __fd, struct linux_dirent *__dirp, __size_t __count),(__fd,__dirp,__count))
#endif /* __CRT_HAVE_SC(getdents) */
#if __CRT_HAVE_SC(getdents64)
__CDECLARE_SC(,__ssize_t,getdents64,(__fd_t __fd, struct linux_dirent64 *__dirp, __size_t __count),(__fd,__dirp,__count))
#endif /* __CRT_HAVE_SC(getdents64) */
#if __CRT_HAVE_SC(getegid)
__CDECLARE_SC(,__gid_t,getegid,(void),())
#endif /* __CRT_HAVE_SC(getegid) */
#if __CRT_HAVE_SC(geteuid)
__CDECLARE_SC(,__uid_t,geteuid,(void),())
#endif /* __CRT_HAVE_SC(geteuid) */
#if __CRT_HAVE_SC(getgid)
__CDECLARE_SC(,__gid_t,getgid,(void),())
#endif /* __CRT_HAVE_SC(getgid) */
#if __CRT_HAVE_SC(getgroups)
__CDECLARE_SC(,__errno_t,getgroups,(__size_t __size, __gid_t *__list),(__size,__list))
#endif /* __CRT_HAVE_SC(getgroups) */
#if __CRT_HAVE_SC(getitimer)
__CDECLARE_SC(,__errno_t,getitimer,(__syscall_ulong_t __which, struct itimerval *__curr_value),(__which,__curr_value))
#endif /* __CRT_HAVE_SC(getitimer) */
#if __CRT_HAVE_SC(getpeername)
__CDECLARE_SC(,__errno_t,getpeername,(__fd_t __sockfd, struct sockaddr *__addr, __socklen_t *__addr_len),(__sockfd,__addr,__addr_len))
#endif /* __CRT_HAVE_SC(getpeername) */
#if __CRT_HAVE_SC(getpgid)
__CDECLARE_SC(,__pid_t,getpgid,(__pid_t __pid),(__pid))
#endif /* __CRT_HAVE_SC(getpgid) */
#if __CRT_HAVE_SC(getpgrp)
__CDECLARE_SC(,__pid_t,getpgrp,(void),())
#endif /* __CRT_HAVE_SC(getpgrp) */
#if __CRT_HAVE_SC(getpid)
__CDECLARE_SC(,__pid_t,getpid,(void),())
#endif /* __CRT_HAVE_SC(getpid) */
#if __CRT_HAVE_SC(getppid)
__CDECLARE_SC(,__pid_t,getppid,(void),())
#endif /* __CRT_HAVE_SC(getppid) */
#if __CRT_HAVE_SC(getpriority)
__CDECLARE_SC(,__syscall_slong_t,getpriority,(__syscall_ulong_t __which, __id_t __who),(__which,__who))
#endif /* __CRT_HAVE_SC(getpriority) */
#if __CRT_HAVE_SC(getrandom)
__CDECLARE_SC(,__errno_t,getrandom,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(getrandom) */
#if __CRT_HAVE_SC(getresgid)
__CDECLARE_SC(,__errno_t,getresgid,(__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid),(__rgid,__egid,__sgid))
#endif /* __CRT_HAVE_SC(getresgid) */
#if __CRT_HAVE_SC(getresuid)
__CDECLARE_SC(,__errno_t,getresuid,(__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid),(__ruid,__euid,__suid))
#endif /* __CRT_HAVE_SC(getresuid) */
#if __CRT_HAVE_SC(getrlimit)
__CDECLARE_SC(,__errno_t,getrlimit,(__syscall_ulong_t __resource, struct rlimit *__rlimits),(__resource,__rlimits))
#endif /* __CRT_HAVE_SC(getrlimit) */
#if __CRT_HAVE_SC(getrusage)
__CDECLARE_SC(,__errno_t,getrusage,(__syscall_slong_t __who, struct rusage *__usage),(__who,__usage))
#endif /* __CRT_HAVE_SC(getrusage) */
#if __CRT_HAVE_SC(getsid)
__CDECLARE_SC(,__pid_t,getsid,(__pid_t __pid),(__pid))
#endif /* __CRT_HAVE_SC(getsid) */
#if __CRT_HAVE_SC(getsockname)
__CDECLARE_SC(,__errno_t,getsockname,(__fd_t __sockfd, struct sockaddr *__addr, __socklen_t *__addr_len),(__sockfd,__addr,__addr_len))
#endif /* __CRT_HAVE_SC(getsockname) */
#if __CRT_HAVE_SC(getsockopt)
/* @param: level:   One of `SOL_*' (e.g.: `SOL_SOCKET')
 * @param: optname: Dependent on `level' */
__CDECLARE_SC(,__errno_t,getsockopt,(__fd_t __sockfd, __syscall_ulong_t __level, __syscall_ulong_t __optname, void *__optval, __socklen_t *__optlen),(__sockfd,__level,__optname,__optval,__optlen))
#endif /* __CRT_HAVE_SC(getsockopt) */
#if __CRT_HAVE_SC(gettid)
__CDECLARE_SC(,__pid_t,gettid,(void),())
#endif /* __CRT_HAVE_SC(gettid) */
#if __CRT_HAVE_SC(gettimeofday)
__CDECLARE_SC(,__errno_t,gettimeofday,(struct timeval *__tv, struct timezone *__tz),(__tv,__tz))
#endif /* __CRT_HAVE_SC(gettimeofday) */
#if __CRT_HAVE_SC(getuid)
__CDECLARE_SC(,__uid_t,getuid,(void),())
#endif /* __CRT_HAVE_SC(getuid) */
#if __CRT_HAVE_SC(getxattr)
__CDECLARE_SC(,__ssize_t,getxattr,(char const *__path, char const *__name, void *__buf, __size_t __bufsize),(__path,__name,__buf,__bufsize))
#endif /* __CRT_HAVE_SC(getxattr) */
#if __CRT_HAVE_SC(init_module)
__CDECLARE_SC(,__errno_t,init_module,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(init_module) */
#if __CRT_HAVE_SC(inotify_add_watch)
__CDECLARE_SC(,__errno_t,inotify_add_watch,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(inotify_add_watch) */
#if __CRT_HAVE_SC(inotify_init)
__CDECLARE_SC(,__errno_t,inotify_init,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(inotify_init) */
#if __CRT_HAVE_SC(inotify_init1)
__CDECLARE_SC(,__errno_t,inotify_init1,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(inotify_init1) */
#if __CRT_HAVE_SC(inotify_rm_watch)
__CDECLARE_SC(,__errno_t,inotify_rm_watch,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(inotify_rm_watch) */
#if __CRT_HAVE_SC(io_cancel)
__CDECLARE_SC(,__errno_t,io_cancel,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(io_cancel) */
#if __CRT_HAVE_SC(io_destroy)
__CDECLARE_SC(,__errno_t,io_destroy,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(io_destroy) */
#if __CRT_HAVE_SC(io_getevents)
__CDECLARE_SC(,__errno_t,io_getevents,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(io_getevents) */
#if __CRT_HAVE_SC(io_setup)
__CDECLARE_SC(,__errno_t,io_setup,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(io_setup) */
#if __CRT_HAVE_SC(io_submit)
__CDECLARE_SC(,__errno_t,io_submit,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(io_submit) */
#if __CRT_HAVE_SC(ioctl)
__CDECLARE_SC(,__syscall_slong_t,ioctl,(__fd_t __fd, __syscall_ulong_t __request, void *__arg),(__fd,__request,__arg))
#endif /* __CRT_HAVE_SC(ioctl) */
#if __CRT_HAVE_SC(ioprio_get)
__CDECLARE_SC(,__errno_t,ioprio_get,(__syscall_ulong_t __which, __syscall_ulong_t __who),(__which,__who))
#endif /* __CRT_HAVE_SC(ioprio_get) */
#if __CRT_HAVE_SC(ioprio_set)
__CDECLARE_SC(,__errno_t,ioprio_set,(__syscall_ulong_t __which, __syscall_ulong_t __who, __syscall_ulong_t __ioprio),(__which,__who,__ioprio))
#endif /* __CRT_HAVE_SC(ioprio_set) */
#if __CRT_HAVE_SC(kcmp)
__CDECLARE_SC(,__syscall_slong_t,kcmp,(__pid_t __pid1, __pid_t __pid2, __syscall_ulong_t __type, __syscall_ulong_t __idx1, __syscall_ulong_t __idx2),(__pid1,__pid2,__type,__idx1,__idx2))
#endif /* __CRT_HAVE_SC(kcmp) */
#if __CRT_HAVE_SC(kexec_load)
__CDECLARE_SC(,__errno_t,kexec_load,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(kexec_load) */
#if __CRT_HAVE_SC(keyctl)
__CDECLARE_SC(,__errno_t,keyctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(keyctl) */
#if __CRT_HAVE_SC(kill)
/* @param: signo: One of `SIG*' */
__CDECLARE_SC(,__errno_t,kill,(__pid_t __pid, __syscall_ulong_t __signo),(__pid,__signo))
#endif /* __CRT_HAVE_SC(kill) */
#if __CRT_HAVE_SC(lchown)
__CDECLARE_SC(,__errno_t,lchown,(char const *__filename, __uid_t __owner, __gid_t __group),(__filename,__owner,__group))
#endif /* __CRT_HAVE_SC(lchown) */
#if __CRT_HAVE_SC(lgetxattr)
__CDECLARE_SC(,__ssize_t,lgetxattr,(char const *__path, char const *__name, void *__buf, __size_t __bufsize),(__path,__name,__buf,__bufsize))
#endif /* __CRT_HAVE_SC(lgetxattr) */
#if __CRT_HAVE_SC(link)
__CDECLARE_SC(,__errno_t,link,(char const *__existing_file, char const *__link_file),(__existing_file,__link_file))
#endif /* __CRT_HAVE_SC(link) */
#if __CRT_HAVE_SC(linkat)
/* @param: flags: Set of `0 | AT_EMPTY_PATH|AT_SYMLINK_FOLLOW | AT_DOSPATH' */
__CDECLARE_SC(,__errno_t,linkat,(__fd_t __fromfd, char const *__existing_file, __fd_t __tofd, char const *__target_path, __atflag_t __flags),(__fromfd,__existing_file,__tofd,__target_path,__flags))
#endif /* __CRT_HAVE_SC(linkat) */
#if __CRT_HAVE_SC(linux_fstat)
__CDECLARE_SC(,__errno_t,linux_fstat,(__fd_t __fd, struct linux_stat *__statbuf),(__fd,__statbuf))
#endif /* __CRT_HAVE_SC(linux_fstat) */
#if __CRT_HAVE_SC(linux_lstat)
__CDECLARE_SC(,__errno_t,linux_lstat,(char const *__filename, struct linux_stat *__statbuf),(__filename,__statbuf))
#endif /* __CRT_HAVE_SC(linux_lstat) */
#if __CRT_HAVE_SC(linux_newfstatat)
__CDECLARE_SC(,__errno_t,linux_newfstatat,(__fd_t __dirfd, char const *__filename, struct linux64_stat32 *__statbuf, __atflag_t __flags),(__dirfd,__filename,__statbuf,__flags))
#endif /* __CRT_HAVE_SC(linux_newfstatat) */
#if __CRT_HAVE_SC(linux_stat)
__CDECLARE_SC(,__errno_t,linux_stat,(char const *__filename, struct linux_stat *__statbuf),(__filename,__statbuf))
#endif /* __CRT_HAVE_SC(linux_stat) */
#if __CRT_HAVE_SC(listen)
__CDECLARE_SC(,__errno_t,listen,(__fd_t __sockfd, __syscall_ulong_t __max_backlog),(__sockfd,__max_backlog))
#endif /* __CRT_HAVE_SC(listen) */
#if __CRT_HAVE_SC(listxattr)
__CDECLARE_SC(,__ssize_t,listxattr,(char const *__path, char *__listbuf, __size_t __listbufsize),(__path,__listbuf,__listbufsize))
#endif /* __CRT_HAVE_SC(listxattr) */
#if __CRT_HAVE_SC(llistxattr)
__CDECLARE_SC(,__ssize_t,llistxattr,(char const *__path, char *__listbuf, __size_t __listbufsize),(__path,__listbuf,__listbufsize))
#endif /* __CRT_HAVE_SC(llistxattr) */
#if __CRT_HAVE_SC(lookup_dcookie)
__CDECLARE_SC(,__errno_t,lookup_dcookie,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(lookup_dcookie) */
#if __CRT_HAVE_SC(lremovexattr)
__CDECLARE_SC(,__errno_t,lremovexattr,(char const *__path, char const *__name),(__path,__name))
#endif /* __CRT_HAVE_SC(lremovexattr) */
#if __CRT_HAVE_SC(lseek)
__CDECLARE_SC(,__syscall_slong_t,lseek,(__fd_t __fd, __syscall_slong_t __offset, __syscall_ulong_t __whence),(__fd,__offset,__whence))
#endif /* __CRT_HAVE_SC(lseek) */
#if __CRT_HAVE_SC(lsetxattr)
__CDECLARE_SC(,__errno_t,lsetxattr,(char const *__path, char const *__name, void const *__buf, __size_t __bufsize, __syscall_ulong_t __flags),(__path,__name,__buf,__bufsize,__flags))
#endif /* __CRT_HAVE_SC(lsetxattr) */
#if __CRT_HAVE_SC(madvise)
__CDECLARE_SC(,__errno_t,madvise,(void *__addr, __size_t __len, __syscall_ulong_t __advice),(__addr,__len,__advice))
#endif /* __CRT_HAVE_SC(madvise) */
#if __CRT_HAVE_SC(mbind)
__CDECLARE_SC(,__errno_t,mbind,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(mbind) */
#if __CRT_HAVE_SC(membarrier)
__CDECLARE_SC(,__errno_t,membarrier,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(membarrier) */
#if __CRT_HAVE_SC(memfd_create)
__CDECLARE_SC(,__errno_t,memfd_create,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(memfd_create) */
#if __CRT_HAVE_SC(migrate_pages)
__CDECLARE_SC(,__errno_t,migrate_pages,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(migrate_pages) */
#if __CRT_HAVE_SC(mincore)
__CDECLARE_SC(,__errno_t,mincore,(void *__start, __size_t __len, __uint8_t *__vec),(__start,__len,__vec))
#endif /* __CRT_HAVE_SC(mincore) */
#if __CRT_HAVE_SC(mkdir)
__CDECLARE_SC(,__errno_t,mkdir,(char const *__pathname, __mode_t __mode),(__pathname,__mode))
#endif /* __CRT_HAVE_SC(mkdir) */
#if __CRT_HAVE_SC(mkdirat)
__CDECLARE_SC(,__errno_t,mkdirat,(__fd_t __dirfd, char const *__pathname, __mode_t __mode),(__dirfd,__pathname,__mode))
#endif /* __CRT_HAVE_SC(mkdirat) */
#if __CRT_HAVE_SC(mknod)
__CDECLARE_SC(,__errno_t,mknod,(char const *__nodename, __mode_t __mode, __dev_t __dev),(__nodename,__mode,__dev))
#endif /* __CRT_HAVE_SC(mknod) */
#if __CRT_HAVE_SC(mknodat)
__CDECLARE_SC(,__errno_t,mknodat,(__fd_t __dirfd, char const *__nodename, __mode_t __mode, __dev_t __dev),(__dirfd,__nodename,__mode,__dev))
#endif /* __CRT_HAVE_SC(mknodat) */
#if __CRT_HAVE_SC(mlock)
__CDECLARE_SC(,__errno_t,mlock,(void const *__addr, __size_t __len),(__addr,__len))
#endif /* __CRT_HAVE_SC(mlock) */
#if __CRT_HAVE_SC(mlock2)
__CDECLARE_SC(,__errno_t,mlock2,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(mlock2) */
#if __CRT_HAVE_SC(mlockall)
__CDECLARE_SC(,__errno_t,mlockall,(__syscall_ulong_t __flags),(__flags))
#endif /* __CRT_HAVE_SC(mlockall) */
#if __CRT_HAVE_SC(mmap)
/* @param: prot:  Either `PROT_NONE', or set of `PROT_EXEC|PROT_WRITE|PROT_READ|PROT_SEM|PROT_LOOSE|PROT_SHARED'
 * @param: flags: One of `MAP_SHARED`, 'MAP_SHARED_VALIDATE' or `MAP_PRIVATE', optionally or'd
 *               with a set of `MAP_ANONYMOUS|MAP_FIXED|MAP_GROWSDOWN|MAP_LOCKED|
 *               MAP_NONBLOCK|MAP_NORESERVE|MAP_POPULATE|MAP_STACK|MAP_SYNC|
 *               MAP_UNINITIALIZED|MAP_DONT_MAP|MAP_DONT_OVERRIDE|MAP_OFFSET64_POINTER' */
__CDECLARE_SC(,void *,mmap,(void *__addr, __size_t __len, __syscall_ulong_t __prot, __syscall_ulong_t __flags, __fd_t __fd, __syscall_ulong_t __offset),(__addr,__len,__prot,__flags,__fd,__offset))
#endif /* __CRT_HAVE_SC(mmap) */
#if __CRT_HAVE_SC(mount)
__CDECLARE_SC(,__errno_t,mount,(char const *__special_file, char const *__dir, char const *__fstype, __syscall_ulong_t __rwflag, void const *__data),(__special_file,__dir,__fstype,__rwflag,__data))
#endif /* __CRT_HAVE_SC(mount) */
#if __CRT_HAVE_SC(move_pages)
__CDECLARE_SC(,__errno_t,move_pages,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(move_pages) */
#if __CRT_HAVE_SC(mprotect)
/* @param: prot: Either `PROT_NONE', or set of `PROT_EXEC|PROT_WRITE|PROT_READ|PROT_SEM|PROT_LOOSE|PROT_SHARED' */
__CDECLARE_SC(,__errno_t,mprotect,(void *__addr, __size_t __len, __syscall_ulong_t __prot),(__addr,__len,__prot))
#endif /* __CRT_HAVE_SC(mprotect) */
#if __CRT_HAVE_SC(mq_getsetattr)
__CDECLARE_SC(,__errno_t,mq_getsetattr,(__fd_t __mqdes, struct mq_attr const *__newattr, struct mq_attr *__oldattr),(__mqdes,__newattr,__oldattr))
#endif /* __CRT_HAVE_SC(mq_getsetattr) */
#if __CRT_HAVE_SC(mq_notify)
__CDECLARE_SC(,__errno_t,mq_notify,(__fd_t __mqdes, struct sigevent const *__notification),(__mqdes,__notification))
#endif /* __CRT_HAVE_SC(mq_notify) */
#if __CRT_HAVE_SC(mq_open)
__CDECLARE_SC(,__fd_t,mq_open,(char const *__name, __oflag_t __oflags, __mode_t __mode),(__name,__oflags,__mode))
#endif /* __CRT_HAVE_SC(mq_open) */
#if __CRT_HAVE_SC(mq_timedreceive)
__CDECLARE_SC(,__ssize_t,mq_timedreceive,(__fd_t __mqdes, char *__msg_ptr, __size_t __msg_len, __uint32_t *__pmsg_prio, struct timespec const *__abs_timeout),(__mqdes,__msg_ptr,__msg_len,__pmsg_prio,__abs_timeout))
#endif /* __CRT_HAVE_SC(mq_timedreceive) */
#if __CRT_HAVE_SC(mq_timedsend)
__CDECLARE_SC(,__errno_t,mq_timedsend,(__fd_t __mqdes, char const *__msg_ptr, __size_t __msg_len, __uint32_t __msg_prio, struct timespec const *__abs_timeout),(__mqdes,__msg_ptr,__msg_len,__msg_prio,__abs_timeout))
#endif /* __CRT_HAVE_SC(mq_timedsend) */
#if __CRT_HAVE_SC(mq_unlink)
__CDECLARE_SC(,__errno_t,mq_unlink,(char const *__name),(__name))
#endif /* __CRT_HAVE_SC(mq_unlink) */
#if __CRT_HAVE_SC(mremap)
/* @param: flags: Set of `MREMAP_MAYMOVE|MREMAP_FIXED' */
__CDECLARE_SC(,void *,mremap,(void *__addr, __size_t __old_len, __size_t __new_len, __syscall_ulong_t __flags, void *__new_address),(__addr,__old_len,__new_len,__flags,__new_address))
#endif /* __CRT_HAVE_SC(mremap) */
#if __CRT_HAVE_SC(msgctl)
__CDECLARE_SC(,__errno_t,msgctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(msgctl) */
#if __CRT_HAVE_SC(msgget)
__CDECLARE_SC(,__errno_t,msgget,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(msgget) */
#if __CRT_HAVE_SC(msgrcv)
__CDECLARE_SC(,__errno_t,msgrcv,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(msgrcv) */
#if __CRT_HAVE_SC(msgsnd)
__CDECLARE_SC(,__errno_t,msgsnd,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(msgsnd) */
#if __CRT_HAVE_SC(msync)
__CDECLARE_SC(,__errno_t,msync,(void *__addr, __size_t __len, __syscall_ulong_t __flags),(__addr,__len,__flags))
#endif /* __CRT_HAVE_SC(msync) */
#if __CRT_HAVE_SC(munlock)
__CDECLARE_SC(,__errno_t,munlock,(void const *__addr, __size_t __len),(__addr,__len))
#endif /* __CRT_HAVE_SC(munlock) */
#if __CRT_HAVE_SC(munlockall)
__CDECLARE_SC(,__errno_t,munlockall,(void),())
#endif /* __CRT_HAVE_SC(munlockall) */
#if __CRT_HAVE_SC(munmap)
__CDECLARE_SC(,__errno_t,munmap,(void *__addr, __size_t __len),(__addr,__len))
#endif /* __CRT_HAVE_SC(munmap) */
#if __CRT_HAVE_SC(name_to_handle_at)
__CDECLARE_SC(,__errno_t,name_to_handle_at,(__fd_t __dirfd, char const *__name, struct file_handle *__handle, __int32_t *__mnt_id, __syscall_ulong_t __flags),(__dirfd,__name,__handle,__mnt_id,__flags))
#endif /* __CRT_HAVE_SC(name_to_handle_at) */
#if __CRT_HAVE_SC(nanosleep)
__CDECLARE_SC(,__errno_t,nanosleep,(struct timespec const *__req, struct timespec *__rem),(__req,__rem))
#endif /* __CRT_HAVE_SC(nanosleep) */
#if __CRT_HAVE_SC(nfsservctl)
__CDECLARE_SC(,__errno_t,nfsservctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(nfsservctl) */
#if __CRT_HAVE_SC(oldwait4)
__CDECLARE_SC(,__pid_t,oldwait4,(__pid_t __pid, __int32_t *__stat_loc, __syscall_ulong_t __options, struct rusage *__usage),(__pid,__stat_loc,__options,__usage))
#endif /* __CRT_HAVE_SC(oldwait4) */
#if __CRT_HAVE_SC(open)
__CDECLARE_SC(,__fd_t,open,(char const *__filename, __oflag_t __oflags, __mode_t __mode),(__filename,__oflags,__mode))
#endif /* __CRT_HAVE_SC(open) */
#if __CRT_HAVE_SC(open_by_handle_at)
__CDECLARE_SC(,__fd_t,open_by_handle_at,(__fd_t __mountdirfd, struct file_handle *__handle, __syscall_ulong_t __flags),(__mountdirfd,__handle,__flags))
#endif /* __CRT_HAVE_SC(open_by_handle_at) */
#if __CRT_HAVE_SC(openat)
__CDECLARE_SC(,__fd_t,openat,(__fd_t __dirfd, char const *__filename, __oflag_t __oflags, __mode_t __mode),(__dirfd,__filename,__oflags,__mode))
#endif /* __CRT_HAVE_SC(openat) */
#if __CRT_HAVE_SC(pause)
__CDECLARE_SC(,__errno_t,pause,(void),())
#endif /* __CRT_HAVE_SC(pause) */
#if __CRT_HAVE_SC(perf_event_open)
__CDECLARE_SC(,__errno_t,perf_event_open,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(perf_event_open) */
#if __CRT_HAVE_SC(personality)
__CDECLARE_SC(,__errno_t,personality,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(personality) */
#if __CRT_HAVE_SC(pipe)
__CDECLARE_SC(,__errno_t,pipe,(__fd_t *__pipedes),(__pipedes))
#endif /* __CRT_HAVE_SC(pipe) */
#if __CRT_HAVE_SC(pipe2)
__CDECLARE_SC(,__errno_t,pipe2,(__fd_t *__pipedes, __oflag_t __flags),(__pipedes,__flags))
#endif /* __CRT_HAVE_SC(pipe2) */
#if __CRT_HAVE_SC(pivot_root)
__CDECLARE_SC(,__errno_t,pivot_root,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(pivot_root) */
#if __CRT_HAVE_SC(poll)
__CDECLARE_SC(,__ssize_t,poll,(struct pollfd *__fds, __size_t __nfds, __syscall_slong_t __timeout),(__fds,__nfds,__timeout))
#endif /* __CRT_HAVE_SC(poll) */
#if __CRT_HAVE_SC(ppoll)
__CDECLARE_SC(,__ssize_t,ppoll,(struct pollfd *__fds, __size_t __nfds, struct timespec const *__timeout_ts, struct __sigset_struct const *__sigmask, __size_t __sigsetsize),(__fds,__nfds,__timeout_ts,__sigmask,__sigsetsize))
#endif /* __CRT_HAVE_SC(ppoll) */
#if __CRT_HAVE_SC(prctl)
__CDECLARE_SC(,__errno_t,prctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(prctl) */
#if __CRT_HAVE_SC(pread64)
__CDECLARE_SC(,__ssize_t,pread64,(__fd_t __fd, void *__buf, __size_t __bufsize, __uint64_t __offset),(__fd,__buf,__bufsize,__offset))
#endif /* __CRT_HAVE_SC(pread64) */
#if __CRT_HAVE_SC(preadv)
__CDECLARE_SC(,__ssize_t,preadv,(__fd_t __fd, struct iovec const *__iovec, __size_t __count, __uint64_t __offset),(__fd,__iovec,__count,__offset))
#endif /* __CRT_HAVE_SC(preadv) */
#if __CRT_HAVE_SC(prlimit64)
/* @param: resource: One of `RLIMIT_*' from <bits/resource.h> */
__CDECLARE_SC(,__errno_t,prlimit64,(__pid_t __pid, __syscall_ulong_t __resource, struct rlimit64 const *__new_limit, struct rlimit64 *__old_limit),(__pid,__resource,__new_limit,__old_limit))
#endif /* __CRT_HAVE_SC(prlimit64) */
#if __CRT_HAVE_SC(process_vm_readv)
__CDECLARE_SC(,__ssize_t,process_vm_readv,(__pid_t __pid, struct iovec const *__lvec, __size_t __liovcnt, struct iovec const *__rvec, __size_t __riovcnt, __syscall_ulong_t __flags),(__pid,__lvec,__liovcnt,__rvec,__riovcnt,__flags))
#endif /* __CRT_HAVE_SC(process_vm_readv) */
#if __CRT_HAVE_SC(process_vm_writev)
__CDECLARE_SC(,__ssize_t,process_vm_writev,(__pid_t __pid, struct iovec const *__lvec, __size_t __liovcnt, struct iovec const *__rvec, __size_t __riovcnt, __syscall_ulong_t __flags),(__pid,__lvec,__liovcnt,__rvec,__riovcnt,__flags))
#endif /* __CRT_HAVE_SC(process_vm_writev) */
#if __CRT_HAVE_SC(pselect6)
__CDECLARE_SC(,__ssize_t,pselect6,(__size_t __nfds, struct __fd_set_struct *__readfds, struct __fd_set_struct *__writefds, struct __fd_set_struct *__exceptfds, struct timespec const *__timeout, void const *__sigmask_sigset_and_len),(__nfds,__readfds,__writefds,__exceptfds,__timeout,__sigmask_sigset_and_len))
#endif /* __CRT_HAVE_SC(pselect6) */
#if __CRT_HAVE_SC(ptrace)
__CDECLARE_SC(,__syscall_slong_t,ptrace,(__syscall_ulong_t __request, __pid_t __pid, void *__addr, void *__data),(__request,__pid,__addr,__data))
#endif /* __CRT_HAVE_SC(ptrace) */
#if __CRT_HAVE_SC(pwrite64)
__CDECLARE_SC(,__ssize_t,pwrite64,(__fd_t __fd, void const *__buf, __size_t __bufsize, __uint64_t __offset),(__fd,__buf,__bufsize,__offset))
#endif /* __CRT_HAVE_SC(pwrite64) */
#if __CRT_HAVE_SC(pwritev)
__CDECLARE_SC(,__ssize_t,pwritev,(__fd_t __fd, struct iovec const *__iovec, __size_t __count, __uint64_t __offset),(__fd,__iovec,__count,__offset))
#endif /* __CRT_HAVE_SC(pwritev) */
#if __CRT_HAVE_SC(quotactl)
__CDECLARE_SC(,__errno_t,quotactl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(quotactl) */
#if __CRT_HAVE_SC(read)
__CDECLARE_SC(,__ssize_t,read,(__fd_t __fd, void *__buf, __size_t __bufsize),(__fd,__buf,__bufsize))
#endif /* __CRT_HAVE_SC(read) */
#if __CRT_HAVE_SC(readahead)
__CDECLARE_SC(,__ssize_t,readahead,(__fd_t __fd, __uint64_t __offset, __size_t __count),(__fd,__offset,__count))
#endif /* __CRT_HAVE_SC(readahead) */
#if __CRT_HAVE_SC(readlink)
__CDECLARE_SC(,__ssize_t,readlink,(char const *__path, char *__buf, __size_t __buflen),(__path,__buf,__buflen))
#endif /* __CRT_HAVE_SC(readlink) */
#if __CRT_HAVE_SC(readlinkat)
__CDECLARE_SC(,__ssize_t,readlinkat,(__fd_t __dirfd, char const *__path, char *__buf, __size_t __buflen),(__dirfd,__path,__buf,__buflen))
#endif /* __CRT_HAVE_SC(readlinkat) */
#if __CRT_HAVE_SC(readv)
__CDECLARE_SC(,__ssize_t,readv,(__fd_t __fd, struct iovec const *__iovec, __size_t __count),(__fd,__iovec,__count))
#endif /* __CRT_HAVE_SC(readv) */
#if __CRT_HAVE_SC(reboot)
/* @param: how: One of the `RB_*' constants from <sys/reboot.h> */
__CDECLARE_SC(,__errno_t,reboot,(__syscall_ulong_t __how),(__how))
#endif /* __CRT_HAVE_SC(reboot) */
#if __CRT_HAVE_SC(recv)
__CDECLARE_SC(,__ssize_t,recv,(__fd_t __sockfd, void *__buf, __size_t __bufsize, __syscall_ulong_t __flags),(__sockfd,__buf,__bufsize,__flags))
#endif /* __CRT_HAVE_SC(recv) */
#if __CRT_HAVE_SC(recvfrom)
__CDECLARE_SC(,__ssize_t,recvfrom,(__fd_t __sockfd, void *__buf, __size_t __bufsize, __syscall_ulong_t __flags, struct sockaddr *__addr, __socklen_t *__addr_len),(__sockfd,__buf,__bufsize,__flags,__addr,__addr_len))
#endif /* __CRT_HAVE_SC(recvfrom) */
#if __CRT_HAVE_SC(recvmmsg)
__CDECLARE_SC(,__ssize_t,recvmmsg,(__fd_t __sockfd, struct mmsghdr *__vmessages, __size_t __vlen, __syscall_ulong_t __flags, struct timespec *__tmo),(__sockfd,__vmessages,__vlen,__flags,__tmo))
#endif /* __CRT_HAVE_SC(recvmmsg) */
#if __CRT_HAVE_SC(recvmsg)
__CDECLARE_SC(,__ssize_t,recvmsg,(__fd_t __sockfd, struct msghdr *__message, __syscall_ulong_t __flags),(__sockfd,__message,__flags))
#endif /* __CRT_HAVE_SC(recvmsg) */
#if __CRT_HAVE_SC(remap_file_pages)
__CDECLARE_SC(,__errno_t,remap_file_pages,(void *__start, __size_t __size, __syscall_ulong_t __prot, __size_t __pgoff, __syscall_ulong_t __flags),(__start,__size,__prot,__pgoff,__flags))
#endif /* __CRT_HAVE_SC(remap_file_pages) */
#if __CRT_HAVE_SC(removexattr)
__CDECLARE_SC(,__errno_t,removexattr,(char const *__path, char const *__name),(__path,__name))
#endif /* __CRT_HAVE_SC(removexattr) */
#if __CRT_HAVE_SC(rename)
__CDECLARE_SC(,__errno_t,rename,(char const *__oldname, char const *__newname_or_path),(__oldname,__newname_or_path))
#endif /* __CRT_HAVE_SC(rename) */
#if __CRT_HAVE_SC(renameat)
__CDECLARE_SC(,__errno_t,renameat,(__fd_t __oldfd, char const *__oldname, __fd_t __newfd, char const *__newname_or_path),(__oldfd,__oldname,__newfd,__newname_or_path))
#endif /* __CRT_HAVE_SC(renameat) */
#if __CRT_HAVE_SC(renameat2)
/* @param: flags: Set of `RENAME_EXCHANGE,RENAME_NOREPLACE,RENAME_WHITEOUT' */
__CDECLARE_SC(,__errno_t,renameat2,(__fd_t __olddirfd, char const *__oldpath, __fd_t __newdirfd, char const *__newpath, __syscall_ulong_t __flags),(__olddirfd,__oldpath,__newdirfd,__newpath,__flags))
#endif /* __CRT_HAVE_SC(renameat2) */
#if __CRT_HAVE_SC(request_key)
__CDECLARE_SC(,__errno_t,request_key,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(request_key) */
#if __CRT_HAVE_SC(restart_syscall)
__CDECLARE_SC(,__errno_t,restart_syscall,(void),())
#endif /* __CRT_HAVE_SC(restart_syscall) */
#if __CRT_HAVE_SC(rmdir)
__CDECLARE_SC(,__errno_t,rmdir,(char const *__path),(__path))
#endif /* __CRT_HAVE_SC(rmdir) */
#if __CRT_HAVE_SC(rt_sigaction)
/* @param: signo: One of `SIG*' */
__CDECLARE_SC(,__errno_t,rt_sigaction,(__syscall_ulong_t __signo, struct sigaction const *__act, struct sigaction *__oact, __size_t __sigsetsize),(__signo,__act,__oact,__sigsetsize))
#endif /* __CRT_HAVE_SC(rt_sigaction) */
#if __CRT_HAVE_SC(rt_sigpending)
__CDECLARE_SC(,__errno_t,rt_sigpending,(struct __sigset_struct *__set, __size_t __sigsetsize),(__set,__sigsetsize))
#endif /* __CRT_HAVE_SC(rt_sigpending) */
#if __CRT_HAVE_SC(rt_sigprocmask)
/* @param: how: One of `SIG_BLOCK', `SIG_UNBLOCK' or `SIG_SETMASK' */
__CDECLARE_SC(,__errno_t,rt_sigprocmask,(__syscall_ulong_t __how, struct __sigset_struct const *__set, struct __sigset_struct *__oset, __size_t __sigsetsize),(__how,__set,__oset,__sigsetsize))
#endif /* __CRT_HAVE_SC(rt_sigprocmask) */
#if __CRT_HAVE_SC(rt_sigqueueinfo)
/* @param: signo: One of `SIG*' */
__CDECLARE_SC(,__errno_t,rt_sigqueueinfo,(__pid_t __tgid, __syscall_ulong_t __signo, struct __siginfo_struct const *__uinfo),(__tgid,__signo,__uinfo))
#endif /* __CRT_HAVE_SC(rt_sigqueueinfo) */
#if __CRT_HAVE_SC(rt_sigreturn)
__CDECLARE_VOID_SC(,rt_sigreturn,(struct fpustate const *__restore_fpu, struct __sigset_struct const *__restore_sigmask, struct rpc_syscall_info *__sc_info, struct ucpustate const *__restore_cpu),(__restore_fpu,__restore_sigmask,__sc_info,__restore_cpu))
#endif /* __CRT_HAVE_SC(rt_sigreturn) */
#if __CRT_HAVE_SC(rt_sigsuspend)
__CDECLARE_SC(,__errno_t,rt_sigsuspend,(struct __sigset_struct const *__set, __size_t __sigsetsize),(__set,__sigsetsize))
#endif /* __CRT_HAVE_SC(rt_sigsuspend) */
#if __CRT_HAVE_SC(rt_sigtimedwait)
__CDECLARE_SC(,__syscall_slong_t,rt_sigtimedwait,(struct __sigset_struct const *__set, struct __siginfo_struct *__info, struct timespec const *__timeout, __size_t __sigsetsize),(__set,__info,__timeout,__sigsetsize))
#endif /* __CRT_HAVE_SC(rt_sigtimedwait) */
#if __CRT_HAVE_SC(rt_tgsigqueueinfo)
/* @param: signo: One of `SIG*' */
__CDECLARE_SC(,__errno_t,rt_tgsigqueueinfo,(__pid_t __tgid, __pid_t __tid, __syscall_ulong_t __signo, struct __siginfo_struct const *__uinfo),(__tgid,__tid,__signo,__uinfo))
#endif /* __CRT_HAVE_SC(rt_tgsigqueueinfo) */
#if __CRT_HAVE_SC(sched_get_priority_max)
__CDECLARE_SC(,__syscall_slong_t,sched_get_priority_max,(__syscall_ulong_t __algorithm),(__algorithm))
#endif /* __CRT_HAVE_SC(sched_get_priority_max) */
#if __CRT_HAVE_SC(sched_get_priority_min)
__CDECLARE_SC(,__syscall_slong_t,sched_get_priority_min,(__syscall_ulong_t __algorithm),(__algorithm))
#endif /* __CRT_HAVE_SC(sched_get_priority_min) */
#if __CRT_HAVE_SC(sched_getaffinity)
__CDECLARE_SC(,__errno_t,sched_getaffinity,(__pid_t __pid, __size_t __cpusetsize, struct __cpu_set_struct *__cpuset),(__pid,__cpusetsize,__cpuset))
#endif /* __CRT_HAVE_SC(sched_getaffinity) */
#if __CRT_HAVE_SC(sched_getattr)
__CDECLARE_SC(,__errno_t,sched_getattr,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(sched_getattr) */
#if __CRT_HAVE_SC(sched_getparam)
__CDECLARE_SC(,__errno_t,sched_getparam,(__pid_t __pid, struct sched_param *__param),(__pid,__param))
#endif /* __CRT_HAVE_SC(sched_getparam) */
#if __CRT_HAVE_SC(sched_getscheduler)
__CDECLARE_SC(,__syscall_slong_t,sched_getscheduler,(__pid_t __pid),(__pid))
#endif /* __CRT_HAVE_SC(sched_getscheduler) */
#if __CRT_HAVE_SC(sched_rr_get_interval)
__CDECLARE_SC(,__errno_t,sched_rr_get_interval,(__pid_t __pid, struct __timespec *__tms),(__pid,__tms))
#endif /* __CRT_HAVE_SC(sched_rr_get_interval) */
#if __CRT_HAVE_SC(sched_setaffinity)
__CDECLARE_SC(,__errno_t,sched_setaffinity,(__pid_t __pid, __size_t __cpusetsize, struct __cpu_set_struct const *__cpuset),(__pid,__cpusetsize,__cpuset))
#endif /* __CRT_HAVE_SC(sched_setaffinity) */
#if __CRT_HAVE_SC(sched_setattr)
__CDECLARE_SC(,__errno_t,sched_setattr,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(sched_setattr) */
#if __CRT_HAVE_SC(sched_setparam)
__CDECLARE_SC(,__errno_t,sched_setparam,(__pid_t __pid, struct sched_param const *__param),(__pid,__param))
#endif /* __CRT_HAVE_SC(sched_setparam) */
#if __CRT_HAVE_SC(sched_setscheduler)
__CDECLARE_SC(,__errno_t,sched_setscheduler,(__pid_t __pid, __syscall_ulong_t __policy, struct sched_param const *__param),(__pid,__policy,__param))
#endif /* __CRT_HAVE_SC(sched_setscheduler) */
#if __CRT_HAVE_SC(sched_yield)
__CDECLARE_SC(,__errno_t,sched_yield,(void),())
#endif /* __CRT_HAVE_SC(sched_yield) */
#if __CRT_HAVE_SC(seccomp)
__CDECLARE_SC(,__errno_t,seccomp,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(seccomp) */
#if __CRT_HAVE_SC(select)
__CDECLARE_SC(,__ssize_t,select,(__size_t __nfds, struct __fd_set_struct *__readfds, struct __fd_set_struct *__writefds, struct __fd_set_struct *__exceptfds, struct timeval *__timeout),(__nfds,__readfds,__writefds,__exceptfds,__timeout))
#endif /* __CRT_HAVE_SC(select) */
#if __CRT_HAVE_SC(semctl)
__CDECLARE_SC(,__errno_t,semctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(semctl) */
#if __CRT_HAVE_SC(semget)
__CDECLARE_SC(,__errno_t,semget,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(semget) */
#if __CRT_HAVE_SC(semop)
__CDECLARE_SC(,__errno_t,semop,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(semop) */
#if __CRT_HAVE_SC(semtimedop)
__CDECLARE_SC(,__errno_t,semtimedop,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(semtimedop) */
#if __CRT_HAVE_SC(send)
/* param flags: Set of `MSG_CONFIRM | MSG_DONTROUTE | MSG_DONTWAIT | MSG_EOR | MSG_MORE | MSG_NOSIGNAL | MSG_OOB' */
__CDECLARE_SC(,__ssize_t,send,(__fd_t __sockfd, void const *__buf, __size_t __bufsize, __syscall_ulong_t __flags),(__sockfd,__buf,__bufsize,__flags))
#endif /* __CRT_HAVE_SC(send) */
#if __CRT_HAVE_SC(sendfile)
__CDECLARE_SC(,__ssize_t,sendfile,(__fd_t __out_fd, __fd_t __in_fd, __syscall_ulong_t *__offset, __size_t __count),(__out_fd,__in_fd,__offset,__count))
#endif /* __CRT_HAVE_SC(sendfile) */
#if __CRT_HAVE_SC(sendmmsg)
__CDECLARE_SC(,__ssize_t,sendmmsg,(__fd_t __sockfd, struct mmsghdr *__vmessages, __size_t __vlen, __syscall_ulong_t __flags),(__sockfd,__vmessages,__vlen,__flags))
#endif /* __CRT_HAVE_SC(sendmmsg) */
#if __CRT_HAVE_SC(sendmsg)
__CDECLARE_SC(,__ssize_t,sendmsg,(__fd_t __sockfd, struct msghdr const *__message, __syscall_ulong_t __flags),(__sockfd,__message,__flags))
#endif /* __CRT_HAVE_SC(sendmsg) */
#if __CRT_HAVE_SC(sendto)
/* param flags: Set of `MSG_CONFIRM | MSG_DONTROUTE | MSG_DONTWAIT | MSG_EOR | MSG_MORE | MSG_NOSIGNAL | MSG_OOB' */
__CDECLARE_SC(,__ssize_t,sendto,(__fd_t __sockfd, void const *__buf, __size_t __bufsize, __syscall_ulong_t __flags, struct sockaddr const *__addr, __socklen_t __addr_len),(__sockfd,__buf,__bufsize,__flags,__addr,__addr_len))
#endif /* __CRT_HAVE_SC(sendto) */
#if __CRT_HAVE_SC(set_mempolicy)
__CDECLARE_SC(,__errno_t,set_mempolicy,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(set_mempolicy) */
#if __CRT_HAVE_SC(set_robust_list)
__CDECLARE_SC(,__errno_t,set_robust_list,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(set_robust_list) */
#if __CRT_HAVE_SC(set_tid_address)
__CDECLARE_SC(,__pid_t,set_tid_address,(__pid_t *__tidptr),(__tidptr))
#endif /* __CRT_HAVE_SC(set_tid_address) */
#if __CRT_HAVE_SC(setdomainname)
__CDECLARE_SC(,__errno_t,setdomainname,(char const *__name, __size_t __len),(__name,__len))
#endif /* __CRT_HAVE_SC(setdomainname) */
#if __CRT_HAVE_SC(setfsgid)
__CDECLARE_SC(,__errno_t,setfsgid,(__gid_t __gid),(__gid))
#endif /* __CRT_HAVE_SC(setfsgid) */
#if __CRT_HAVE_SC(setfsuid)
__CDECLARE_SC(,__errno_t,setfsuid,(__uid_t __uid),(__uid))
#endif /* __CRT_HAVE_SC(setfsuid) */
#if __CRT_HAVE_SC(setgid)
__CDECLARE_SC(,__errno_t,setgid,(__gid_t __gid),(__gid))
#endif /* __CRT_HAVE_SC(setgid) */
#if __CRT_HAVE_SC(setgroups)
__CDECLARE_SC(,__errno_t,setgroups,(__size_t __count, __gid_t const *__groups),(__count,__groups))
#endif /* __CRT_HAVE_SC(setgroups) */
#if __CRT_HAVE_SC(sethostname)
__CDECLARE_SC(,__errno_t,sethostname,(char const *__name, __size_t __len),(__name,__len))
#endif /* __CRT_HAVE_SC(sethostname) */
#if __CRT_HAVE_SC(setitimer)
__CDECLARE_SC(,__errno_t,setitimer,(__syscall_ulong_t __which, struct itimerval const *__newval, struct itimerval *__oldval),(__which,__newval,__oldval))
#endif /* __CRT_HAVE_SC(setitimer) */
#if __CRT_HAVE_SC(setns)
__CDECLARE_SC(,__errno_t,setns,(__fd_t __fd, __syscall_ulong_t __nstype),(__fd,__nstype))
#endif /* __CRT_HAVE_SC(setns) */
#if __CRT_HAVE_SC(setpgid)
__CDECLARE_SC(,__errno_t,setpgid,(__pid_t __pid, __pid_t __pgid),(__pid,__pgid))
#endif /* __CRT_HAVE_SC(setpgid) */
#if __CRT_HAVE_SC(setpriority)
__CDECLARE_SC(,__errno_t,setpriority,(__syscall_ulong_t __which, __id_t __who, __syscall_ulong_t __value),(__which,__who,__value))
#endif /* __CRT_HAVE_SC(setpriority) */
#if __CRT_HAVE_SC(setregid)
__CDECLARE_SC(,__errno_t,setregid,(__gid_t __rgid, __gid_t __egid),(__rgid,__egid))
#endif /* __CRT_HAVE_SC(setregid) */
#if __CRT_HAVE_SC(setresgid)
__CDECLARE_SC(,__errno_t,setresgid,(__gid_t __rgid, __gid_t __egid, __gid_t __sgid),(__rgid,__egid,__sgid))
#endif /* __CRT_HAVE_SC(setresgid) */
#if __CRT_HAVE_SC(setresuid)
__CDECLARE_SC(,__errno_t,setresuid,(__uid_t __ruid, __uid_t __euid, __uid_t __suid),(__ruid,__euid,__suid))
#endif /* __CRT_HAVE_SC(setresuid) */
#if __CRT_HAVE_SC(setreuid)
__CDECLARE_SC(,__errno_t,setreuid,(__uid_t __ruid, __uid_t __euid),(__ruid,__euid))
#endif /* __CRT_HAVE_SC(setreuid) */
#if __CRT_HAVE_SC(setrlimit)
__CDECLARE_SC(,__errno_t,setrlimit,(__syscall_ulong_t __resource, struct rlimit const *__rlimits),(__resource,__rlimits))
#endif /* __CRT_HAVE_SC(setrlimit) */
#if __CRT_HAVE_SC(setsid)
__CDECLARE_SC(,__pid_t,setsid,(void),())
#endif /* __CRT_HAVE_SC(setsid) */
#if __CRT_HAVE_SC(setsockopt)
/* @param: level:   One of `SOL_*' (e.g.: `SOL_SOCKET')
 * @param: optname: Dependent on `level' */
__CDECLARE_SC(,__errno_t,setsockopt,(__fd_t __sockfd, __syscall_ulong_t __level, __syscall_ulong_t __optname, void const *__optval, __socklen_t __optlen),(__sockfd,__level,__optname,__optval,__optlen))
#endif /* __CRT_HAVE_SC(setsockopt) */
#if __CRT_HAVE_SC(settimeofday)
__CDECLARE_SC(,__errno_t,settimeofday,(struct timeval const *__tv, struct timezone const *__tz),(__tv,__tz))
#endif /* __CRT_HAVE_SC(settimeofday) */
#if __CRT_HAVE_SC(setuid)
__CDECLARE_SC(,__errno_t,setuid,(__uid_t __uid),(__uid))
#endif /* __CRT_HAVE_SC(setuid) */
#if __CRT_HAVE_SC(setxattr)
__CDECLARE_SC(,__errno_t,setxattr,(char const *__path, char const *__name, void const *__buf, __size_t __bufsize, __syscall_ulong_t __flags),(__path,__name,__buf,__bufsize,__flags))
#endif /* __CRT_HAVE_SC(setxattr) */
#if __CRT_HAVE_SC(shmat)
__CDECLARE_SC(,__errno_t,shmat,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(shmat) */
#if __CRT_HAVE_SC(shmctl)
__CDECLARE_SC(,__errno_t,shmctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(shmctl) */
#if __CRT_HAVE_SC(shmdt)
__CDECLARE_SC(,__errno_t,shmdt,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(shmdt) */
#if __CRT_HAVE_SC(shmget)
__CDECLARE_SC(,__errno_t,shmget,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(shmget) */
#if __CRT_HAVE_SC(shutdown)
/* @param: how: One of `SHUT_RD', `SHUT_WR' or `SHUT_RDWR' */
__CDECLARE_SC(,__errno_t,shutdown,(__fd_t __sockfd, __syscall_ulong_t __how),(__sockfd,__how))
#endif /* __CRT_HAVE_SC(shutdown) */
#if __CRT_HAVE_SC(sigaltstack)
__CDECLARE_SC(,__errno_t,sigaltstack,(struct sigaltstack const *__ss, struct sigaltstack *__oss),(__ss,__oss))
#endif /* __CRT_HAVE_SC(sigaltstack) */
#if __CRT_HAVE_SC(signalfd)
__CDECLARE_SC(,__errno_t,signalfd,(__fd_t __fd, struct __sigset_struct const *__sigmask, __size_t __sigsetsize),(__fd,__sigmask,__sigsetsize))
#endif /* __CRT_HAVE_SC(signalfd) */
#if __CRT_HAVE_SC(signalfd4)
__CDECLARE_SC(,__errno_t,signalfd4,(__fd_t __fd, struct __sigset_struct const *__sigmask, __size_t __sigsetsize, __syscall_ulong_t __flags),(__fd,__sigmask,__sigsetsize,__flags))
#endif /* __CRT_HAVE_SC(signalfd4) */
#if __CRT_HAVE_SC(socket)
__CDECLARE_SC(,__fd_t,socket,(__syscall_ulong_t __domain, __syscall_ulong_t __type, __syscall_ulong_t __protocol),(__domain,__type,__protocol))
#endif /* __CRT_HAVE_SC(socket) */
#if __CRT_HAVE_SC(socketpair)
__CDECLARE_SC(,__errno_t,socketpair,(__syscall_ulong_t __domain, __syscall_ulong_t __type, __syscall_ulong_t __protocol, __fd_t *__fds),(__domain,__type,__protocol,__fds))
#endif /* __CRT_HAVE_SC(socketpair) */
#if __CRT_HAVE_SC(splice)
__CDECLARE_SC(,__ssize_t,splice,(__fd_t __fdin, __uint64_t *__offin, __fd_t __fdout, __uint64_t *__offout, __size_t __length, __syscall_ulong_t __flags),(__fdin,__offin,__fdout,__offout,__length,__flags))
#endif /* __CRT_HAVE_SC(splice) */
#if __CRT_HAVE_SC(statfs)
__CDECLARE_SC(,__errno_t,statfs,(char const *__file, struct statfs *__buf),(__file,__buf))
#endif /* __CRT_HAVE_SC(statfs) */
#if __CRT_HAVE_SC(swapoff)
__CDECLARE_SC(,__errno_t,swapoff,(char const *__pathname),(__pathname))
#endif /* __CRT_HAVE_SC(swapoff) */
#if __CRT_HAVE_SC(swapon)
/* @param: swapflags: Set of `SWAP_FLAG_*' */
__CDECLARE_SC(,__errno_t,swapon,(char const *__pathname, __syscall_ulong_t __swapflags),(__pathname,__swapflags))
#endif /* __CRT_HAVE_SC(swapon) */
#if __CRT_HAVE_SC(symlink)
__CDECLARE_SC(,__errno_t,symlink,(char const *__link_text, char const *__target_path),(__link_text,__target_path))
#endif /* __CRT_HAVE_SC(symlink) */
#if __CRT_HAVE_SC(symlinkat)
__CDECLARE_SC(,__errno_t,symlinkat,(char const *__link_text, __fd_t __tofd, char const *__target_path),(__link_text,__tofd,__target_path))
#endif /* __CRT_HAVE_SC(symlinkat) */
#if __CRT_HAVE_SC(sync)
__CDECLARE_SC(,__errno_t,sync,(void),())
#endif /* __CRT_HAVE_SC(sync) */
#if __CRT_HAVE_SC(sync_file_range)
__CDECLARE_SC(,__errno_t,sync_file_range,(__fd_t __fd, __uint64_t __offset, __uint64_t __count, __syscall_ulong_t __flags),(__fd,__offset,__count,__flags))
#endif /* __CRT_HAVE_SC(sync_file_range) */
#if __CRT_HAVE_SC(syncfs)
__CDECLARE_SC(,__errno_t,syncfs,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_SC(syncfs) */
#if __CRT_HAVE_SC(sysinfo)
__CDECLARE_SC(,__errno_t,sysinfo,(struct sysinfo *__info),(__info))
#endif /* __CRT_HAVE_SC(sysinfo) */
#if __CRT_HAVE_SC(syslog)
__CDECLARE_SC(,__ssize_t,syslog,(__syscall_ulong_t __level, char const *__str, __size_t __len),(__level,__str,__len))
#endif /* __CRT_HAVE_SC(syslog) */
#if __CRT_HAVE_SC(tee)
__CDECLARE_SC(,__ssize_t,tee,(__fd_t __fdin, __fd_t __fdout, __size_t __length, __syscall_ulong_t __flags),(__fdin,__fdout,__length,__flags))
#endif /* __CRT_HAVE_SC(tee) */
#if __CRT_HAVE_SC(tgkill)
__CDECLARE_SC(,__errno_t,tgkill,(__pid_t __tgid, __pid_t __tid, __syscall_ulong_t __signo),(__tgid,__tid,__signo))
#endif /* __CRT_HAVE_SC(tgkill) */
#if __CRT_HAVE_SC(time)
__CDECLARE_SC(,__time32_t,time,(__time32_t *__timer),(__timer))
#endif /* __CRT_HAVE_SC(time) */
#if __CRT_HAVE_SC(timer_create)
__CDECLARE_SC(,__errno_t,timer_create,(__clockid_t __clock_id, struct sigevent *__evp, __timer_t *__timerid),(__clock_id,__evp,__timerid))
#endif /* __CRT_HAVE_SC(timer_create) */
#if __CRT_HAVE_SC(timer_delete)
__CDECLARE_SC(,__errno_t,timer_delete,(__timer_t __timerid),(__timerid))
#endif /* __CRT_HAVE_SC(timer_delete) */
#if __CRT_HAVE_SC(timer_getoverrun)
__CDECLARE_SC(,__syscall_slong_t,timer_getoverrun,(__timer_t __timerid),(__timerid))
#endif /* __CRT_HAVE_SC(timer_getoverrun) */
#if __CRT_HAVE_SC(timer_gettime)
__CDECLARE_SC(,__errno_t,timer_gettime,(__timer_t __timerid, struct itimerspec *__value),(__timerid,__value))
#endif /* __CRT_HAVE_SC(timer_gettime) */
#if __CRT_HAVE_SC(timer_settime)
__CDECLARE_SC(,__errno_t,timer_settime,(__timer_t __timerid, __syscall_ulong_t __flags, struct itimerspec const *__value, struct itimerspec *__ovalue),(__timerid,__flags,__value,__ovalue))
#endif /* __CRT_HAVE_SC(timer_settime) */
#if __CRT_HAVE_SC(timerfd_create)
/* Return file descriptor for new interval timer source */
__CDECLARE_SC(,__fd_t,timerfd_create,(__clockid_t __clock_id, __syscall_ulong_t __flags),(__clock_id,__flags))
#endif /* __CRT_HAVE_SC(timerfd_create) */
#if __CRT_HAVE_SC(timerfd_gettime)
/* Return the next expiration time of UFD */
__CDECLARE_SC(,__errno_t,timerfd_gettime,(__fd_t __ufd, struct itimerspec *__otmr),(__ufd,__otmr))
#endif /* __CRT_HAVE_SC(timerfd_gettime) */
#if __CRT_HAVE_SC(timerfd_settime)
/* Set next expiration time of interval timer source UFD to UTMR.
 * If FLAGS has the TFD_TIMER_ABSTIME flag set the timeout value
 * is absolute. Optionally return the old expiration time in OTMR */
__CDECLARE_SC(,__errno_t,timerfd_settime,(__fd_t __ufd, __syscall_ulong_t __flags, struct itimerspec const *__utmr, struct itimerspec *__otmr),(__ufd,__flags,__utmr,__otmr))
#endif /* __CRT_HAVE_SC(timerfd_settime) */
#if __CRT_HAVE_SC(times)
__CDECLARE_SC(,__clock_t,times,(struct tms *__buf),(__buf))
#endif /* __CRT_HAVE_SC(times) */
#if __CRT_HAVE_SC(tkill)
__CDECLARE_SC(,__errno_t,tkill,(__pid_t __tid, __syscall_ulong_t __signo),(__tid,__signo))
#endif /* __CRT_HAVE_SC(tkill) */
#if __CRT_HAVE_SC(truncate)
__CDECLARE_SC(,__errno_t,truncate,(char const *__filename, __syscall_ulong_t __length),(__filename,__length))
#endif /* __CRT_HAVE_SC(truncate) */
#if __CRT_HAVE_SC(umask)
__CDECLARE_SC(,__mode_t,umask,(__mode_t __mode),(__mode))
#endif /* __CRT_HAVE_SC(umask) */
#if __CRT_HAVE_SC(umount)
__CDECLARE_SC(,__errno_t,umount,(char const *__special_file),(__special_file))
#endif /* __CRT_HAVE_SC(umount) */
#if __CRT_HAVE_SC(umount2)
__CDECLARE_SC(,__errno_t,umount2,(char const *__special_file, __syscall_ulong_t __flags),(__special_file,__flags))
#endif /* __CRT_HAVE_SC(umount2) */
#if __CRT_HAVE_SC(uname)
__CDECLARE_SC(,__errno_t,uname,(struct utsname *__name),(__name))
#endif /* __CRT_HAVE_SC(uname) */
#if __CRT_HAVE_SC(unlink)
__CDECLARE_SC(,__errno_t,unlink,(char const *__filename),(__filename))
#endif /* __CRT_HAVE_SC(unlink) */
#if __CRT_HAVE_SC(unlinkat)
/* @param: flags: Set of `0 | AT_REMOVEDIR|AT_REMOVEREG | AT_DOSPATH' */
__CDECLARE_SC(,__errno_t,unlinkat,(__fd_t __dirfd, char const *__name, __atflag_t __flags),(__dirfd,__name,__flags))
#endif /* __CRT_HAVE_SC(unlinkat) */
#if __CRT_HAVE_SC(unshare)
/* param flags: Set of `CLONE_*' */
__CDECLARE_SC(,__errno_t,unshare,(__syscall_ulong_t __flags),(__flags))
#endif /* __CRT_HAVE_SC(unshare) */
#if __CRT_HAVE_SC(uselib)
__CDECLARE_SC(,__errno_t,uselib,(char const *__library),(__library))
#endif /* __CRT_HAVE_SC(uselib) */
#if __CRT_HAVE_SC(userfaultfd)
__CDECLARE_SC(,__errno_t,userfaultfd,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_SC(userfaultfd) */
#if __CRT_HAVE_SC(ustat)
__CDECLARE_SC(,__errno_t,ustat,(__dev_t __dev, struct ustat *__ubuf),(__dev,__ubuf))
#endif /* __CRT_HAVE_SC(ustat) */
#if __CRT_HAVE_SC(utime)
__CDECLARE_SC(,__errno_t,utime,(char const *__filename, struct utimbuf const *__times),(__filename,__times))
#endif /* __CRT_HAVE_SC(utime) */
#if __CRT_HAVE_SC(utimensat)
/* @param: flags: Set of `0 | AT_SYMLINK_NOFOLLOW | AT_CHANGE_CTIME | AT_DOSPATH' */
__CDECLARE_SC(,__errno_t,utimensat,(__fd_t __dirfd, char const *__filename, struct timespec const *__times, __atflag_t __flags),(__dirfd,__filename,__times,__flags))
#endif /* __CRT_HAVE_SC(utimensat) */
#if __CRT_HAVE_SC(utimes)
__CDECLARE_SC(,__errno_t,utimes,(char const *__filename, struct timeval const *__times),(__filename,__times))
#endif /* __CRT_HAVE_SC(utimes) */
#if __CRT_HAVE_SC(vfork)
__CDECLARE_SC(,__pid_t,vfork,(void),())
#endif /* __CRT_HAVE_SC(vfork) */
#if __CRT_HAVE_SC(vhangup)
__CDECLARE_SC(,__errno_t,vhangup,(void),())
#endif /* __CRT_HAVE_SC(vhangup) */
#if __CRT_HAVE_SC(vmsplice)
__CDECLARE_SC(,__ssize_t,vmsplice,(__fd_t __fdout, struct iovec const *__iov, __size_t __count, __syscall_ulong_t __flags),(__fdout,__iov,__count,__flags))
#endif /* __CRT_HAVE_SC(vmsplice) */
#if __CRT_HAVE_SC(wait4)
/* Same as `waitpid(pid,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param: options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CDECLARE_SC(,__pid_t,wait4,(__pid_t __pid, __int32_t *__stat_loc, __syscall_ulong_t __options, struct rusage *__usage),(__pid,__stat_loc,__options,__usage))
#endif /* __CRT_HAVE_SC(wait4) */
#if __CRT_HAVE_SC(waitid)
/* @param: options: At least one of `WEXITED | WSTOPPED | WCONTINUED', optionally or'd with `WNOHANG | WNOWAIT' */
__CDECLARE_SC(,__errno_t,waitid,(__syscall_ulong_t __idtype, __id_t __id, struct __siginfo_struct *__infop, __syscall_ulong_t __options, struct rusage *__ru),(__idtype,__id,__infop,__options,__ru))
#endif /* __CRT_HAVE_SC(waitid) */
#if __CRT_HAVE_SC(write)
__CDECLARE_SC(,__ssize_t,write,(__fd_t __fd, void const *__buf, __size_t __bufsize),(__fd,__buf,__bufsize))
#endif /* __CRT_HAVE_SC(write) */
#if __CRT_HAVE_SC(writev)
__CDECLARE_SC(,__ssize_t,writev,(__fd_t __fd, struct iovec const *__iovec, __size_t __count),(__fd,__iovec,__count))
#endif /* __CRT_HAVE_SC(writev) */
#if __CRT_HAVE_XSC(_sysctl)
__CDECLARE_XSC(,__errno_t,_sysctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(_sysctl) */
#if __CRT_HAVE_XSC(accept)
__CDECLARE_XSC(,__errno_t,accept,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(accept) */
#if __CRT_HAVE_XSC(accept4)
__CDECLARE_XSC(,__fd_t,accept4,(__fd_t __sockfd, struct sockaddr *__addr, __socklen_t *__addr_len, __syscall_ulong_t __flags),(__sockfd,__addr,__addr_len,__flags))
#endif /* __CRT_HAVE_XSC(accept4) */
#if __CRT_HAVE_XSC(access)
/* @param: type: Set of `R_OK|W_OK|X_OK' or `F_OK' */
__CDECLARE_XSC(,__errno_t,access,(char const *__filename, __syscall_ulong_t __type),(__filename,__type))
#endif /* __CRT_HAVE_XSC(access) */
#if __CRT_HAVE_XSC(acct)
__CDECLARE_XSC(,__errno_t,acct,(char const *__filename),(__filename))
#endif /* __CRT_HAVE_XSC(acct) */
#if __CRT_HAVE_XSC(add_key)
__CDECLARE_XSC(,__errno_t,add_key,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(add_key) */
#if __CRT_HAVE_XSC(adjtimex)
__CDECLARE_XSC(,__errno_t,adjtimex,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(adjtimex) */
#if __CRT_HAVE_XSC(alarm)
__CDECLARE_XSC(,__syscall_ulong_t,alarm,(__syscall_ulong_t __seconds),(__seconds))
#endif /* __CRT_HAVE_XSC(alarm) */
#if __CRT_HAVE_XSC(bdflush)
__CDECLARE_XSC(,__errno_t,bdflush,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(bdflush) */
#if __CRT_HAVE_XSC(bind)
__CDECLARE_XSC(,__errno_t,bind,(__fd_t __sockfd, struct sockaddr const *__addr, __socklen_t __addr_len),(__sockfd,__addr,__addr_len))
#endif /* __CRT_HAVE_XSC(bind) */
#if __CRT_HAVE_XSC(bpf)
__CDECLARE_XSC(,__errno_t,bpf,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(bpf) */
#if __CRT_HAVE_XSC(brk)
__CDECLARE_XSC(,__errno_t,brk,(void *__addr),(__addr))
#endif /* __CRT_HAVE_XSC(brk) */
#if __CRT_HAVE_XSC(capget)
__CDECLARE_XSC(,__errno_t,capget,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(capget) */
#if __CRT_HAVE_XSC(capset)
__CDECLARE_XSC(,__errno_t,capset,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(capset) */
#if __CRT_HAVE_XSC(chdir)
__CDECLARE_XSC(,__errno_t,chdir,(char const *__path),(__path))
#endif /* __CRT_HAVE_XSC(chdir) */
#if __CRT_HAVE_XSC(chmod)
__CDECLARE_XSC(,__errno_t,chmod,(char const *__filename, __mode_t __mode),(__filename,__mode))
#endif /* __CRT_HAVE_XSC(chmod) */
#if __CRT_HAVE_XSC(chown)
__CDECLARE_XSC(,__errno_t,chown,(char const *__filename, __uid_t __owner, __gid_t __group),(__filename,__owner,__group))
#endif /* __CRT_HAVE_XSC(chown) */
#if __CRT_HAVE_XSC(chroot)
__CDECLARE_XSC(,__errno_t,chroot,(char const *__path),(__path))
#endif /* __CRT_HAVE_XSC(chroot) */
#if __CRT_HAVE_XSC(clock_adjtime)
__CDECLARE_XSC(,__errno_t,clock_adjtime,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(clock_adjtime) */
#if __CRT_HAVE_XSC(clock_getres)
__CDECLARE_XSC(,__errno_t,clock_getres,(__clockid_t __clock_id, struct timespec *__res),(__clock_id,__res))
#endif /* __CRT_HAVE_XSC(clock_getres) */
#if __CRT_HAVE_XSC(clock_gettime)
__CDECLARE_XSC(,__errno_t,clock_gettime,(__clockid_t __clock_id, struct timespec *__tp),(__clock_id,__tp))
#endif /* __CRT_HAVE_XSC(clock_gettime) */
#if __CRT_HAVE_XSC(clock_nanosleep)
__CDECLARE_XSC(,__errno_t,clock_nanosleep,(__clockid_t __clock_id, __syscall_ulong_t __flags, struct timespec const *__requested_time, struct timespec *__remaining),(__clock_id,__flags,__requested_time,__remaining))
#endif /* __CRT_HAVE_XSC(clock_nanosleep) */
#if __CRT_HAVE_XSC(clock_settime)
__CDECLARE_XSC(,__errno_t,clock_settime,(__clockid_t __clock_id, struct timespec const *__tp),(__clock_id,__tp))
#endif /* __CRT_HAVE_XSC(clock_settime) */
#if __CRT_HAVE_XSC(clone)
__CDECLARE_XSC(,__pid_t,clone,(__syscall_ulong_t __flags, void *__child_stack, __pid_t *__ptid, __uintptr_t __newtls, __pid_t *__ctid),(__flags,__child_stack,__ptid,__newtls,__ctid))
#endif /* __CRT_HAVE_XSC(clone) */
#if __CRT_HAVE_XSC(close)
/* Close a given file descriptor/handle `FD' */
__CDECLARE_XSC(,__errno_t,close,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_XSC(close) */
#if __CRT_HAVE_XSC(connect)
__CDECLARE_XSC(,__errno_t,connect,(__fd_t __sockfd, struct sockaddr const *__addr, __socklen_t __addr_len),(__sockfd,__addr,__addr_len))
#endif /* __CRT_HAVE_XSC(connect) */
#if __CRT_HAVE_XSC(creat)
__CDECLARE_XSC(,__fd_t,creat,(char const *__filename, __mode_t __mode),(__filename,__mode))
#endif /* __CRT_HAVE_XSC(creat) */
#if __CRT_HAVE_XSC(delete_module)
__CDECLARE_XSC(,__errno_t,delete_module,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(delete_module) */
#if __CRT_HAVE_XSC(dup)
__CDECLARE_XSC(,__fd_t,dup,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_XSC(dup) */
#if __CRT_HAVE_XSC(dup2)
__CDECLARE_XSC(,__fd_t,dup2,(__fd_t __oldfd, __fd_t __newfd),(__oldfd,__newfd))
#endif /* __CRT_HAVE_XSC(dup2) */
#if __CRT_HAVE_XSC(dup3)
/* @param: flags:  Set of `O_CLOEXEC|O_CLOFORK' */
__CDECLARE_XSC(,__fd_t,dup3,(__fd_t __oldfd, __fd_t __newfd, __oflag_t __flags),(__oldfd,__newfd,__flags))
#endif /* __CRT_HAVE_XSC(dup3) */
#if __CRT_HAVE_XSC(epoll_create)
__CDECLARE_XSC(,__fd_t,epoll_create,(__syscall_ulong_t __size),(__size))
#endif /* __CRT_HAVE_XSC(epoll_create) */
#if __CRT_HAVE_XSC(epoll_create1)
__CDECLARE_XSC(,__fd_t,epoll_create1,(__syscall_ulong_t __flags),(__flags))
#endif /* __CRT_HAVE_XSC(epoll_create1) */
#if __CRT_HAVE_XSC(epoll_ctl)
__CDECLARE_XSC(,__errno_t,epoll_ctl,(__fd_t __epfd, __syscall_ulong_t __op, __fd_t __fd, struct epoll_event *__event),(__epfd,__op,__fd,__event))
#endif /* __CRT_HAVE_XSC(epoll_ctl) */
#if __CRT_HAVE_XSC(epoll_pwait)
__CDECLARE_XSC(,__errno_t,epoll_pwait,(__fd_t __epfd, struct epoll_event *__events, __syscall_ulong_t __maxevents, __syscall_slong_t __timeout, struct __sigset_struct const *__ss),(__epfd,__events,__maxevents,__timeout,__ss))
#endif /* __CRT_HAVE_XSC(epoll_pwait) */
#if __CRT_HAVE_XSC(epoll_wait)
__CDECLARE_XSC(,__errno_t,epoll_wait,(__fd_t __epfd, struct epoll_event *__events, __syscall_ulong_t __maxevents, __syscall_slong_t __timeout),(__epfd,__events,__maxevents,__timeout))
#endif /* __CRT_HAVE_XSC(epoll_wait) */
#if __CRT_HAVE_XSC(eventfd)
__CDECLARE_XSC(,__fd_t,eventfd,(__syscall_ulong_t __initval),(__initval))
#endif /* __CRT_HAVE_XSC(eventfd) */
#if __CRT_HAVE_XSC(eventfd2)
__CDECLARE_XSC(,__fd_t,eventfd2,(__syscall_ulong_t __initval, __syscall_ulong_t __flags),(__initval,__flags))
#endif /* __CRT_HAVE_XSC(eventfd2) */
#if __CRT_HAVE_XSC(execve)
__CDECLARE_XSC(,__errno_t,execve,(char const *__path, char const *const *__argv, char const *const *__envp),(__path,__argv,__envp))
#endif /* __CRT_HAVE_XSC(execve) */
#if __CRT_HAVE_XSC(execveat)
/* @param: flags: Set of `0 | AT_EMPTY_PATH|AT_SYMLINK_NOFOLLOW | AT_DOSPATH' */
__CDECLARE_XSC(,__errno_t,execveat,(__fd_t __dirfd, char const *__pathname, char const *const *__argv, char const *const *__envp, __atflag_t __flags),(__dirfd,__pathname,__argv,__envp,__flags))
#endif /* __CRT_HAVE_XSC(execveat) */
#if __CRT_HAVE_XSC(exit)
__CDECLARE_VOID_XSC(__ATTR_NORETURN,exit,(__syscall_ulong_t __status),(__status))
#endif /* __CRT_HAVE_XSC(exit) */
#if __CRT_HAVE_XSC(exit_group)
__CDECLARE_VOID_XSC(__ATTR_NORETURN,exit_group,(__syscall_ulong_t __exit_code),(__exit_code))
#endif /* __CRT_HAVE_XSC(exit_group) */
#if __CRT_HAVE_XSC(faccessat)
/* @param: type: Set of `R_OK|W_OK|X_OK' or `F_OK'
 * @param: flags: Set of `0 | AT_SYMLINK_NOFOLLOW|AT_EACCESS | AT_DOSPATH' */
__CDECLARE_XSC(,__errno_t,faccessat,(__fd_t __dirfd, char const *__filename, __syscall_ulong_t __type, __atflag_t __flags),(__dirfd,__filename,__type,__flags))
#endif /* __CRT_HAVE_XSC(faccessat) */
#if __CRT_HAVE_XSC(fadvise64)
__CDECLARE_XSC(,__errno_t,fadvise64,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(fadvise64) */
#if __CRT_HAVE_XSC(fallocate)
__CDECLARE_XSC(,__errno_t,fallocate,(__fd_t __fd, __syscall_ulong_t __mode, __syscall_ulong_t __offset, __syscall_ulong_t __length),(__fd,__mode,__offset,__length))
#endif /* __CRT_HAVE_XSC(fallocate) */
#if __CRT_HAVE_XSC(fanotify_init)
__CDECLARE_XSC(,__errno_t,fanotify_init,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(fanotify_init) */
#if __CRT_HAVE_XSC(fanotify_mark)
__CDECLARE_XSC(,__errno_t,fanotify_mark,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(fanotify_mark) */
#if __CRT_HAVE_XSC(fchdir)
__CDECLARE_XSC(,__errno_t,fchdir,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_XSC(fchdir) */
#if __CRT_HAVE_XSC(fchmod)
__CDECLARE_XSC(,__errno_t,fchmod,(__fd_t __fd, __mode_t __mode),(__fd,__mode))
#endif /* __CRT_HAVE_XSC(fchmod) */
#if __CRT_HAVE_XSC(fchmodat)
/* @param: flags: Set of `0 | AT_SYMLINK_NOFOLLOW | AT_DOSPATH' */
__CDECLARE_XSC(,__errno_t,fchmodat,(__fd_t __dirfd, char const *__filename, __mode_t __mode, __atflag_t __flags),(__dirfd,__filename,__mode,__flags))
#endif /* __CRT_HAVE_XSC(fchmodat) */
#if __CRT_HAVE_XSC(fchown)
__CDECLARE_XSC(,__errno_t,fchown,(__fd_t __fd, __uid_t __owner, __gid_t __group),(__fd,__owner,__group))
#endif /* __CRT_HAVE_XSC(fchown) */
#if __CRT_HAVE_XSC(fchownat)
/* @param: flags: Set of `0 | AT_SYMLINK_NOFOLLOW | AT_DOSPATH' */
__CDECLARE_XSC(,__errno_t,fchownat,(__fd_t __dirfd, char const *__filename, __uid_t __owner, __gid_t __group, __atflag_t __flags),(__dirfd,__filename,__owner,__group,__flags))
#endif /* __CRT_HAVE_XSC(fchownat) */
#if __CRT_HAVE_XSC(fcntl)
__CDECLARE_XSC(,__syscall_slong_t,fcntl,(__fd_t __fd, __syscall_ulong_t __cmd, void *__arg),(__fd,__cmd,__arg))
#endif /* __CRT_HAVE_XSC(fcntl) */
#if __CRT_HAVE_XSC(fdatasync)
__CDECLARE_XSC(,__errno_t,fdatasync,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_XSC(fdatasync) */
#if __CRT_HAVE_XSC(fgetxattr)
__CDECLARE_XSC(,__ssize_t,fgetxattr,(__fd_t __fd, char const *__name, void *__buf, __size_t __bufsize),(__fd,__name,__buf,__bufsize))
#endif /* __CRT_HAVE_XSC(fgetxattr) */
#if __CRT_HAVE_XSC(finit_module)
__CDECLARE_XSC(,__errno_t,finit_module,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(finit_module) */
#if __CRT_HAVE_XSC(flistxattr)
__CDECLARE_XSC(,__ssize_t,flistxattr,(__fd_t __fd, char *__listbuf, __size_t __listbufsize),(__fd,__listbuf,__listbufsize))
#endif /* __CRT_HAVE_XSC(flistxattr) */
#if __CRT_HAVE_XSC(flock)
__CDECLARE_XSC(,__errno_t,flock,(__fd_t __fd, __syscall_ulong_t __operation),(__fd,__operation))
#endif /* __CRT_HAVE_XSC(flock) */
#if __CRT_HAVE_XSC(fork)
__CDECLARE_XSC(,__pid_t,fork,(void),())
#endif /* __CRT_HAVE_XSC(fork) */
#if __CRT_HAVE_XSC(fremovexattr)
__CDECLARE_XSC(,__errno_t,fremovexattr,(int __fd, char const *__name),(__fd,__name))
#endif /* __CRT_HAVE_XSC(fremovexattr) */
#if __CRT_HAVE_XSC(fsetxattr)
__CDECLARE_XSC(,__errno_t,fsetxattr,(__fd_t __fd, char const *__name, void const *__buf, __size_t __bufsize, __syscall_ulong_t __flags),(__fd,__name,__buf,__bufsize,__flags))
#endif /* __CRT_HAVE_XSC(fsetxattr) */
#if __CRT_HAVE_XSC(fstatfs)
__CDECLARE_XSC(,__errno_t,fstatfs,(__fd_t __file, struct statfs *__buf),(__file,__buf))
#endif /* __CRT_HAVE_XSC(fstatfs) */
#if __CRT_HAVE_XSC(fsync)
__CDECLARE_XSC(,__errno_t,fsync,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_XSC(fsync) */
#if __CRT_HAVE_XSC(ftruncate)
__CDECLARE_XSC(,__errno_t,ftruncate,(__fd_t __fd, __syscall_ulong_t __length),(__fd,__length))
#endif /* __CRT_HAVE_XSC(ftruncate) */
#if __CRT_HAVE_XSC(futex)
__CDECLARE_XSC(,__syscall_slong_t,futex,(__uint32_t *__uaddr, __syscall_ulong_t __futex_op, __uint32_t __val, struct timespec const *__timeout_or_val2, __uint32_t *__uaddr2, __uint32_t __val3),(__uaddr,__futex_op,__val,__timeout_or_val2,__uaddr2,__val3))
#endif /* __CRT_HAVE_XSC(futex) */
#if __CRT_HAVE_XSC(futimesat)
__CDECLARE_XSC(,__errno_t,futimesat,(__fd_t __dirfd, __const char *__filename, struct timeval const *__times),(__dirfd,__filename,__times))
#endif /* __CRT_HAVE_XSC(futimesat) */
#if __CRT_HAVE_XSC(get_mempolicy)
__CDECLARE_XSC(,__errno_t,get_mempolicy,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(get_mempolicy) */
#if __CRT_HAVE_XSC(get_robust_list)
__CDECLARE_XSC(,__errno_t,get_robust_list,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(get_robust_list) */
#if __CRT_HAVE_XSC(getcpu)
__CDECLARE_XSC(,__errno_t,getcpu,(__uint32_t *__cpu, __uint32_t *__node, struct getcpu_cache *__tcache),(__cpu,__node,__tcache))
#endif /* __CRT_HAVE_XSC(getcpu) */
#if __CRT_HAVE_XSC(getcwd)
__CDECLARE_XSC(,__ssize_t,getcwd,(char *__buf, __size_t __size),(__buf,__size))
#endif /* __CRT_HAVE_XSC(getcwd) */
#if __CRT_HAVE_XSC(getdents)
__CDECLARE_XSC(,__ssize_t,getdents,(__fd_t __fd, struct linux_dirent *__dirp, __size_t __count),(__fd,__dirp,__count))
#endif /* __CRT_HAVE_XSC(getdents) */
#if __CRT_HAVE_XSC(getdents64)
__CDECLARE_XSC(,__ssize_t,getdents64,(__fd_t __fd, struct linux_dirent64 *__dirp, __size_t __count),(__fd,__dirp,__count))
#endif /* __CRT_HAVE_XSC(getdents64) */
#if __CRT_HAVE_XSC(getegid)
__CDECLARE_XSC(,__gid_t,getegid,(void),())
#endif /* __CRT_HAVE_XSC(getegid) */
#if __CRT_HAVE_XSC(geteuid)
__CDECLARE_XSC(,__uid_t,geteuid,(void),())
#endif /* __CRT_HAVE_XSC(geteuid) */
#if __CRT_HAVE_XSC(getgid)
__CDECLARE_XSC(,__gid_t,getgid,(void),())
#endif /* __CRT_HAVE_XSC(getgid) */
#if __CRT_HAVE_XSC(getgroups)
__CDECLARE_XSC(,__errno_t,getgroups,(__size_t __size, __gid_t *__list),(__size,__list))
#endif /* __CRT_HAVE_XSC(getgroups) */
#if __CRT_HAVE_XSC(getitimer)
__CDECLARE_XSC(,__errno_t,getitimer,(__syscall_ulong_t __which, struct itimerval *__curr_value),(__which,__curr_value))
#endif /* __CRT_HAVE_XSC(getitimer) */
#if __CRT_HAVE_XSC(getpeername)
__CDECLARE_XSC(,__errno_t,getpeername,(__fd_t __sockfd, struct sockaddr *__addr, __socklen_t *__addr_len),(__sockfd,__addr,__addr_len))
#endif /* __CRT_HAVE_XSC(getpeername) */
#if __CRT_HAVE_XSC(getpgid)
__CDECLARE_XSC(,__pid_t,getpgid,(__pid_t __pid),(__pid))
#endif /* __CRT_HAVE_XSC(getpgid) */
#if __CRT_HAVE_XSC(getpgrp)
__CDECLARE_XSC(,__pid_t,getpgrp,(void),())
#endif /* __CRT_HAVE_XSC(getpgrp) */
#if __CRT_HAVE_XSC(getpid)
__CDECLARE_XSC(,__pid_t,getpid,(void),())
#endif /* __CRT_HAVE_XSC(getpid) */
#if __CRT_HAVE_XSC(getppid)
__CDECLARE_XSC(,__pid_t,getppid,(void),())
#endif /* __CRT_HAVE_XSC(getppid) */
#if __CRT_HAVE_XSC(getpriority)
__CDECLARE_XSC(,__syscall_slong_t,getpriority,(__syscall_ulong_t __which, __id_t __who),(__which,__who))
#endif /* __CRT_HAVE_XSC(getpriority) */
#if __CRT_HAVE_XSC(getrandom)
__CDECLARE_XSC(,__errno_t,getrandom,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(getrandom) */
#if __CRT_HAVE_XSC(getresgid)
__CDECLARE_XSC(,__errno_t,getresgid,(__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid),(__rgid,__egid,__sgid))
#endif /* __CRT_HAVE_XSC(getresgid) */
#if __CRT_HAVE_XSC(getresuid)
__CDECLARE_XSC(,__errno_t,getresuid,(__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid),(__ruid,__euid,__suid))
#endif /* __CRT_HAVE_XSC(getresuid) */
#if __CRT_HAVE_XSC(getrlimit)
__CDECLARE_XSC(,__errno_t,getrlimit,(__syscall_ulong_t __resource, struct rlimit *__rlimits),(__resource,__rlimits))
#endif /* __CRT_HAVE_XSC(getrlimit) */
#if __CRT_HAVE_XSC(getrusage)
__CDECLARE_XSC(,__errno_t,getrusage,(__syscall_slong_t __who, struct rusage *__usage),(__who,__usage))
#endif /* __CRT_HAVE_XSC(getrusage) */
#if __CRT_HAVE_XSC(getsid)
__CDECLARE_XSC(,__pid_t,getsid,(__pid_t __pid),(__pid))
#endif /* __CRT_HAVE_XSC(getsid) */
#if __CRT_HAVE_XSC(getsockname)
__CDECLARE_XSC(,__errno_t,getsockname,(__fd_t __sockfd, struct sockaddr *__addr, __socklen_t *__addr_len),(__sockfd,__addr,__addr_len))
#endif /* __CRT_HAVE_XSC(getsockname) */
#if __CRT_HAVE_XSC(getsockopt)
/* @param: level:   One of `SOL_*' (e.g.: `SOL_SOCKET')
 * @param: optname: Dependent on `level' */
__CDECLARE_XSC(,__errno_t,getsockopt,(__fd_t __sockfd, __syscall_ulong_t __level, __syscall_ulong_t __optname, void *__optval, __socklen_t *__optlen),(__sockfd,__level,__optname,__optval,__optlen))
#endif /* __CRT_HAVE_XSC(getsockopt) */
#if __CRT_HAVE_XSC(gettid)
__CDECLARE_XSC(,__pid_t,gettid,(void),())
#endif /* __CRT_HAVE_XSC(gettid) */
#if __CRT_HAVE_XSC(gettimeofday)
__CDECLARE_XSC(,__errno_t,gettimeofday,(struct timeval *__tv, struct timezone *__tz),(__tv,__tz))
#endif /* __CRT_HAVE_XSC(gettimeofday) */
#if __CRT_HAVE_XSC(getuid)
__CDECLARE_XSC(,__uid_t,getuid,(void),())
#endif /* __CRT_HAVE_XSC(getuid) */
#if __CRT_HAVE_XSC(getxattr)
__CDECLARE_XSC(,__ssize_t,getxattr,(char const *__path, char const *__name, void *__buf, __size_t __bufsize),(__path,__name,__buf,__bufsize))
#endif /* __CRT_HAVE_XSC(getxattr) */
#if __CRT_HAVE_XSC(init_module)
__CDECLARE_XSC(,__errno_t,init_module,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(init_module) */
#if __CRT_HAVE_XSC(inotify_add_watch)
__CDECLARE_XSC(,__errno_t,inotify_add_watch,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(inotify_add_watch) */
#if __CRT_HAVE_XSC(inotify_init)
__CDECLARE_XSC(,__errno_t,inotify_init,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(inotify_init) */
#if __CRT_HAVE_XSC(inotify_init1)
__CDECLARE_XSC(,__errno_t,inotify_init1,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(inotify_init1) */
#if __CRT_HAVE_XSC(inotify_rm_watch)
__CDECLARE_XSC(,__errno_t,inotify_rm_watch,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(inotify_rm_watch) */
#if __CRT_HAVE_XSC(io_cancel)
__CDECLARE_XSC(,__errno_t,io_cancel,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(io_cancel) */
#if __CRT_HAVE_XSC(io_destroy)
__CDECLARE_XSC(,__errno_t,io_destroy,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(io_destroy) */
#if __CRT_HAVE_XSC(io_getevents)
__CDECLARE_XSC(,__errno_t,io_getevents,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(io_getevents) */
#if __CRT_HAVE_XSC(io_setup)
__CDECLARE_XSC(,__errno_t,io_setup,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(io_setup) */
#if __CRT_HAVE_XSC(io_submit)
__CDECLARE_XSC(,__errno_t,io_submit,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(io_submit) */
#if __CRT_HAVE_XSC(ioctl)
__CDECLARE_XSC(,__syscall_slong_t,ioctl,(__fd_t __fd, __syscall_ulong_t __request, void *__arg),(__fd,__request,__arg))
#endif /* __CRT_HAVE_XSC(ioctl) */
#if __CRT_HAVE_XSC(ioprio_get)
__CDECLARE_XSC(,__errno_t,ioprio_get,(__syscall_ulong_t __which, __syscall_ulong_t __who),(__which,__who))
#endif /* __CRT_HAVE_XSC(ioprio_get) */
#if __CRT_HAVE_XSC(ioprio_set)
__CDECLARE_XSC(,__errno_t,ioprio_set,(__syscall_ulong_t __which, __syscall_ulong_t __who, __syscall_ulong_t __ioprio),(__which,__who,__ioprio))
#endif /* __CRT_HAVE_XSC(ioprio_set) */
#if __CRT_HAVE_XSC(kcmp)
__CDECLARE_XSC(,__syscall_slong_t,kcmp,(__pid_t __pid1, __pid_t __pid2, __syscall_ulong_t __type, __syscall_ulong_t __idx1, __syscall_ulong_t __idx2),(__pid1,__pid2,__type,__idx1,__idx2))
#endif /* __CRT_HAVE_XSC(kcmp) */
#if __CRT_HAVE_XSC(kexec_load)
__CDECLARE_XSC(,__errno_t,kexec_load,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(kexec_load) */
#if __CRT_HAVE_XSC(keyctl)
__CDECLARE_XSC(,__errno_t,keyctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(keyctl) */
#if __CRT_HAVE_XSC(kill)
/* @param: signo: One of `SIG*' */
__CDECLARE_XSC(,__errno_t,kill,(__pid_t __pid, __syscall_ulong_t __signo),(__pid,__signo))
#endif /* __CRT_HAVE_XSC(kill) */
#if __CRT_HAVE_XSC(lchown)
__CDECLARE_XSC(,__errno_t,lchown,(char const *__filename, __uid_t __owner, __gid_t __group),(__filename,__owner,__group))
#endif /* __CRT_HAVE_XSC(lchown) */
#if __CRT_HAVE_XSC(lgetxattr)
__CDECLARE_XSC(,__ssize_t,lgetxattr,(char const *__path, char const *__name, void *__buf, __size_t __bufsize),(__path,__name,__buf,__bufsize))
#endif /* __CRT_HAVE_XSC(lgetxattr) */
#if __CRT_HAVE_XSC(link)
__CDECLARE_XSC(,__errno_t,link,(char const *__existing_file, char const *__link_file),(__existing_file,__link_file))
#endif /* __CRT_HAVE_XSC(link) */
#if __CRT_HAVE_XSC(linkat)
/* @param: flags: Set of `0 | AT_EMPTY_PATH|AT_SYMLINK_FOLLOW | AT_DOSPATH' */
__CDECLARE_XSC(,__errno_t,linkat,(__fd_t __fromfd, char const *__existing_file, __fd_t __tofd, char const *__target_path, __atflag_t __flags),(__fromfd,__existing_file,__tofd,__target_path,__flags))
#endif /* __CRT_HAVE_XSC(linkat) */
#if __CRT_HAVE_XSC(linux_fstat)
__CDECLARE_XSC(,__errno_t,linux_fstat,(__fd_t __fd, struct linux_stat *__statbuf),(__fd,__statbuf))
#endif /* __CRT_HAVE_XSC(linux_fstat) */
#if __CRT_HAVE_XSC(linux_lstat)
__CDECLARE_XSC(,__errno_t,linux_lstat,(char const *__filename, struct linux_stat *__statbuf),(__filename,__statbuf))
#endif /* __CRT_HAVE_XSC(linux_lstat) */
#if __CRT_HAVE_XSC(linux_newfstatat)
__CDECLARE_XSC(,__errno_t,linux_newfstatat,(__fd_t __dirfd, char const *__filename, struct linux64_stat32 *__statbuf, __atflag_t __flags),(__dirfd,__filename,__statbuf,__flags))
#endif /* __CRT_HAVE_XSC(linux_newfstatat) */
#if __CRT_HAVE_XSC(linux_stat)
__CDECLARE_XSC(,__errno_t,linux_stat,(char const *__filename, struct linux_stat *__statbuf),(__filename,__statbuf))
#endif /* __CRT_HAVE_XSC(linux_stat) */
#if __CRT_HAVE_XSC(listen)
__CDECLARE_XSC(,__errno_t,listen,(__fd_t __sockfd, __syscall_ulong_t __max_backlog),(__sockfd,__max_backlog))
#endif /* __CRT_HAVE_XSC(listen) */
#if __CRT_HAVE_XSC(listxattr)
__CDECLARE_XSC(,__ssize_t,listxattr,(char const *__path, char *__listbuf, __size_t __listbufsize),(__path,__listbuf,__listbufsize))
#endif /* __CRT_HAVE_XSC(listxattr) */
#if __CRT_HAVE_XSC(llistxattr)
__CDECLARE_XSC(,__ssize_t,llistxattr,(char const *__path, char *__listbuf, __size_t __listbufsize),(__path,__listbuf,__listbufsize))
#endif /* __CRT_HAVE_XSC(llistxattr) */
#if __CRT_HAVE_XSC(lookup_dcookie)
__CDECLARE_XSC(,__errno_t,lookup_dcookie,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(lookup_dcookie) */
#if __CRT_HAVE_XSC(lremovexattr)
__CDECLARE_XSC(,__errno_t,lremovexattr,(char const *__path, char const *__name),(__path,__name))
#endif /* __CRT_HAVE_XSC(lremovexattr) */
#if __CRT_HAVE_XSC(lseek)
__CDECLARE_XSC(,__syscall_slong_t,lseek,(__fd_t __fd, __syscall_slong_t __offset, __syscall_ulong_t __whence),(__fd,__offset,__whence))
#endif /* __CRT_HAVE_XSC(lseek) */
#if __CRT_HAVE_XSC(lsetxattr)
__CDECLARE_XSC(,__errno_t,lsetxattr,(char const *__path, char const *__name, void const *__buf, __size_t __bufsize, __syscall_ulong_t __flags),(__path,__name,__buf,__bufsize,__flags))
#endif /* __CRT_HAVE_XSC(lsetxattr) */
#if __CRT_HAVE_XSC(madvise)
__CDECLARE_XSC(,__errno_t,madvise,(void *__addr, __size_t __len, __syscall_ulong_t __advice),(__addr,__len,__advice))
#endif /* __CRT_HAVE_XSC(madvise) */
#if __CRT_HAVE_XSC(mbind)
__CDECLARE_XSC(,__errno_t,mbind,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(mbind) */
#if __CRT_HAVE_XSC(membarrier)
__CDECLARE_XSC(,__errno_t,membarrier,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(membarrier) */
#if __CRT_HAVE_XSC(memfd_create)
__CDECLARE_XSC(,__errno_t,memfd_create,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(memfd_create) */
#if __CRT_HAVE_XSC(migrate_pages)
__CDECLARE_XSC(,__errno_t,migrate_pages,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(migrate_pages) */
#if __CRT_HAVE_XSC(mincore)
__CDECLARE_XSC(,__errno_t,mincore,(void *__start, __size_t __len, __uint8_t *__vec),(__start,__len,__vec))
#endif /* __CRT_HAVE_XSC(mincore) */
#if __CRT_HAVE_XSC(mkdir)
__CDECLARE_XSC(,__errno_t,mkdir,(char const *__pathname, __mode_t __mode),(__pathname,__mode))
#endif /* __CRT_HAVE_XSC(mkdir) */
#if __CRT_HAVE_XSC(mkdirat)
__CDECLARE_XSC(,__errno_t,mkdirat,(__fd_t __dirfd, char const *__pathname, __mode_t __mode),(__dirfd,__pathname,__mode))
#endif /* __CRT_HAVE_XSC(mkdirat) */
#if __CRT_HAVE_XSC(mknod)
__CDECLARE_XSC(,__errno_t,mknod,(char const *__nodename, __mode_t __mode, __dev_t __dev),(__nodename,__mode,__dev))
#endif /* __CRT_HAVE_XSC(mknod) */
#if __CRT_HAVE_XSC(mknodat)
__CDECLARE_XSC(,__errno_t,mknodat,(__fd_t __dirfd, char const *__nodename, __mode_t __mode, __dev_t __dev),(__dirfd,__nodename,__mode,__dev))
#endif /* __CRT_HAVE_XSC(mknodat) */
#if __CRT_HAVE_XSC(mlock)
__CDECLARE_XSC(,__errno_t,mlock,(void const *__addr, __size_t __len),(__addr,__len))
#endif /* __CRT_HAVE_XSC(mlock) */
#if __CRT_HAVE_XSC(mlock2)
__CDECLARE_XSC(,__errno_t,mlock2,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(mlock2) */
#if __CRT_HAVE_XSC(mlockall)
__CDECLARE_XSC(,__errno_t,mlockall,(__syscall_ulong_t __flags),(__flags))
#endif /* __CRT_HAVE_XSC(mlockall) */
#if __CRT_HAVE_XSC(mmap)
/* @param: prot:  Either `PROT_NONE', or set of `PROT_EXEC|PROT_WRITE|PROT_READ|PROT_SEM|PROT_LOOSE|PROT_SHARED'
 * @param: flags: One of `MAP_SHARED`, 'MAP_SHARED_VALIDATE' or `MAP_PRIVATE', optionally or'd
 *               with a set of `MAP_ANONYMOUS|MAP_FIXED|MAP_GROWSDOWN|MAP_LOCKED|
 *               MAP_NONBLOCK|MAP_NORESERVE|MAP_POPULATE|MAP_STACK|MAP_SYNC|
 *               MAP_UNINITIALIZED|MAP_DONT_MAP|MAP_DONT_OVERRIDE|MAP_OFFSET64_POINTER' */
__CDECLARE_XSC(,void *,mmap,(void *__addr, __size_t __len, __syscall_ulong_t __prot, __syscall_ulong_t __flags, __fd_t __fd, __syscall_ulong_t __offset),(__addr,__len,__prot,__flags,__fd,__offset))
#endif /* __CRT_HAVE_XSC(mmap) */
#if __CRT_HAVE_XSC(mount)
__CDECLARE_XSC(,__errno_t,mount,(char const *__special_file, char const *__dir, char const *__fstype, __syscall_ulong_t __rwflag, void const *__data),(__special_file,__dir,__fstype,__rwflag,__data))
#endif /* __CRT_HAVE_XSC(mount) */
#if __CRT_HAVE_XSC(move_pages)
__CDECLARE_XSC(,__errno_t,move_pages,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(move_pages) */
#if __CRT_HAVE_XSC(mprotect)
/* @param: prot: Either `PROT_NONE', or set of `PROT_EXEC|PROT_WRITE|PROT_READ|PROT_SEM|PROT_LOOSE|PROT_SHARED' */
__CDECLARE_XSC(,__errno_t,mprotect,(void *__addr, __size_t __len, __syscall_ulong_t __prot),(__addr,__len,__prot))
#endif /* __CRT_HAVE_XSC(mprotect) */
#if __CRT_HAVE_XSC(mq_getsetattr)
__CDECLARE_XSC(,__errno_t,mq_getsetattr,(__fd_t __mqdes, struct mq_attr const *__newattr, struct mq_attr *__oldattr),(__mqdes,__newattr,__oldattr))
#endif /* __CRT_HAVE_XSC(mq_getsetattr) */
#if __CRT_HAVE_XSC(mq_notify)
__CDECLARE_XSC(,__errno_t,mq_notify,(__fd_t __mqdes, struct sigevent const *__notification),(__mqdes,__notification))
#endif /* __CRT_HAVE_XSC(mq_notify) */
#if __CRT_HAVE_XSC(mq_open)
__CDECLARE_XSC(,__fd_t,mq_open,(char const *__name, __oflag_t __oflags, __mode_t __mode),(__name,__oflags,__mode))
#endif /* __CRT_HAVE_XSC(mq_open) */
#if __CRT_HAVE_XSC(mq_timedreceive)
__CDECLARE_XSC(,__ssize_t,mq_timedreceive,(__fd_t __mqdes, char *__msg_ptr, __size_t __msg_len, __uint32_t *__pmsg_prio, struct timespec const *__abs_timeout),(__mqdes,__msg_ptr,__msg_len,__pmsg_prio,__abs_timeout))
#endif /* __CRT_HAVE_XSC(mq_timedreceive) */
#if __CRT_HAVE_XSC(mq_timedsend)
__CDECLARE_XSC(,__errno_t,mq_timedsend,(__fd_t __mqdes, char const *__msg_ptr, __size_t __msg_len, __uint32_t __msg_prio, struct timespec const *__abs_timeout),(__mqdes,__msg_ptr,__msg_len,__msg_prio,__abs_timeout))
#endif /* __CRT_HAVE_XSC(mq_timedsend) */
#if __CRT_HAVE_XSC(mq_unlink)
__CDECLARE_XSC(,__errno_t,mq_unlink,(char const *__name),(__name))
#endif /* __CRT_HAVE_XSC(mq_unlink) */
#if __CRT_HAVE_XSC(mremap)
/* @param: flags: Set of `MREMAP_MAYMOVE|MREMAP_FIXED' */
__CDECLARE_XSC(,void *,mremap,(void *__addr, __size_t __old_len, __size_t __new_len, __syscall_ulong_t __flags, void *__new_address),(__addr,__old_len,__new_len,__flags,__new_address))
#endif /* __CRT_HAVE_XSC(mremap) */
#if __CRT_HAVE_XSC(msgctl)
__CDECLARE_XSC(,__errno_t,msgctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(msgctl) */
#if __CRT_HAVE_XSC(msgget)
__CDECLARE_XSC(,__errno_t,msgget,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(msgget) */
#if __CRT_HAVE_XSC(msgrcv)
__CDECLARE_XSC(,__errno_t,msgrcv,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(msgrcv) */
#if __CRT_HAVE_XSC(msgsnd)
__CDECLARE_XSC(,__errno_t,msgsnd,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(msgsnd) */
#if __CRT_HAVE_XSC(msync)
__CDECLARE_XSC(,__errno_t,msync,(void *__addr, __size_t __len, __syscall_ulong_t __flags),(__addr,__len,__flags))
#endif /* __CRT_HAVE_XSC(msync) */
#if __CRT_HAVE_XSC(munlock)
__CDECLARE_XSC(,__errno_t,munlock,(void const *__addr, __size_t __len),(__addr,__len))
#endif /* __CRT_HAVE_XSC(munlock) */
#if __CRT_HAVE_XSC(munlockall)
__CDECLARE_XSC(,__errno_t,munlockall,(void),())
#endif /* __CRT_HAVE_XSC(munlockall) */
#if __CRT_HAVE_XSC(munmap)
__CDECLARE_XSC(,__errno_t,munmap,(void *__addr, __size_t __len),(__addr,__len))
#endif /* __CRT_HAVE_XSC(munmap) */
#if __CRT_HAVE_XSC(name_to_handle_at)
__CDECLARE_XSC(,__errno_t,name_to_handle_at,(__fd_t __dirfd, char const *__name, struct file_handle *__handle, __int32_t *__mnt_id, __syscall_ulong_t __flags),(__dirfd,__name,__handle,__mnt_id,__flags))
#endif /* __CRT_HAVE_XSC(name_to_handle_at) */
#if __CRT_HAVE_XSC(nanosleep)
__CDECLARE_XSC(,__errno_t,nanosleep,(struct timespec const *__req, struct timespec *__rem),(__req,__rem))
#endif /* __CRT_HAVE_XSC(nanosleep) */
#if __CRT_HAVE_XSC(nfsservctl)
__CDECLARE_XSC(,__errno_t,nfsservctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(nfsservctl) */
#if __CRT_HAVE_XSC(oldwait4)
__CDECLARE_XSC(,__pid_t,oldwait4,(__pid_t __pid, __int32_t *__stat_loc, __syscall_ulong_t __options, struct rusage *__usage),(__pid,__stat_loc,__options,__usage))
#endif /* __CRT_HAVE_XSC(oldwait4) */
#if __CRT_HAVE_XSC(open)
__CDECLARE_XSC(,__fd_t,open,(char const *__filename, __oflag_t __oflags, __mode_t __mode),(__filename,__oflags,__mode))
#endif /* __CRT_HAVE_XSC(open) */
#if __CRT_HAVE_XSC(open_by_handle_at)
__CDECLARE_XSC(,__fd_t,open_by_handle_at,(__fd_t __mountdirfd, struct file_handle *__handle, __syscall_ulong_t __flags),(__mountdirfd,__handle,__flags))
#endif /* __CRT_HAVE_XSC(open_by_handle_at) */
#if __CRT_HAVE_XSC(openat)
__CDECLARE_XSC(,__fd_t,openat,(__fd_t __dirfd, char const *__filename, __oflag_t __oflags, __mode_t __mode),(__dirfd,__filename,__oflags,__mode))
#endif /* __CRT_HAVE_XSC(openat) */
#if __CRT_HAVE_XSC(pause)
__CDECLARE_XSC(,__errno_t,pause,(void),())
#endif /* __CRT_HAVE_XSC(pause) */
#if __CRT_HAVE_XSC(perf_event_open)
__CDECLARE_XSC(,__errno_t,perf_event_open,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(perf_event_open) */
#if __CRT_HAVE_XSC(personality)
__CDECLARE_XSC(,__errno_t,personality,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(personality) */
#if __CRT_HAVE_XSC(pipe)
__CDECLARE_XSC(,__errno_t,pipe,(__fd_t *__pipedes),(__pipedes))
#endif /* __CRT_HAVE_XSC(pipe) */
#if __CRT_HAVE_XSC(pipe2)
__CDECLARE_XSC(,__errno_t,pipe2,(__fd_t *__pipedes, __oflag_t __flags),(__pipedes,__flags))
#endif /* __CRT_HAVE_XSC(pipe2) */
#if __CRT_HAVE_XSC(pivot_root)
__CDECLARE_XSC(,__errno_t,pivot_root,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(pivot_root) */
#if __CRT_HAVE_XSC(poll)
__CDECLARE_XSC(,__ssize_t,poll,(struct pollfd *__fds, __size_t __nfds, __syscall_slong_t __timeout),(__fds,__nfds,__timeout))
#endif /* __CRT_HAVE_XSC(poll) */
#if __CRT_HAVE_XSC(ppoll)
__CDECLARE_XSC(,__ssize_t,ppoll,(struct pollfd *__fds, __size_t __nfds, struct timespec const *__timeout_ts, struct __sigset_struct const *__sigmask, __size_t __sigsetsize),(__fds,__nfds,__timeout_ts,__sigmask,__sigsetsize))
#endif /* __CRT_HAVE_XSC(ppoll) */
#if __CRT_HAVE_XSC(prctl)
__CDECLARE_XSC(,__errno_t,prctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(prctl) */
#if __CRT_HAVE_XSC(pread64)
__CDECLARE_XSC(,__ssize_t,pread64,(__fd_t __fd, void *__buf, __size_t __bufsize, __uint64_t __offset),(__fd,__buf,__bufsize,__offset))
#endif /* __CRT_HAVE_XSC(pread64) */
#if __CRT_HAVE_XSC(preadv)
__CDECLARE_XSC(,__ssize_t,preadv,(__fd_t __fd, struct iovec const *__iovec, __size_t __count, __uint64_t __offset),(__fd,__iovec,__count,__offset))
#endif /* __CRT_HAVE_XSC(preadv) */
#if __CRT_HAVE_XSC(prlimit64)
/* @param: resource: One of `RLIMIT_*' from <bits/resource.h> */
__CDECLARE_XSC(,__errno_t,prlimit64,(__pid_t __pid, __syscall_ulong_t __resource, struct rlimit64 const *__new_limit, struct rlimit64 *__old_limit),(__pid,__resource,__new_limit,__old_limit))
#endif /* __CRT_HAVE_XSC(prlimit64) */
#if __CRT_HAVE_XSC(process_vm_readv)
__CDECLARE_XSC(,__ssize_t,process_vm_readv,(__pid_t __pid, struct iovec const *__lvec, __size_t __liovcnt, struct iovec const *__rvec, __size_t __riovcnt, __syscall_ulong_t __flags),(__pid,__lvec,__liovcnt,__rvec,__riovcnt,__flags))
#endif /* __CRT_HAVE_XSC(process_vm_readv) */
#if __CRT_HAVE_XSC(process_vm_writev)
__CDECLARE_XSC(,__ssize_t,process_vm_writev,(__pid_t __pid, struct iovec const *__lvec, __size_t __liovcnt, struct iovec const *__rvec, __size_t __riovcnt, __syscall_ulong_t __flags),(__pid,__lvec,__liovcnt,__rvec,__riovcnt,__flags))
#endif /* __CRT_HAVE_XSC(process_vm_writev) */
#if __CRT_HAVE_XSC(pselect6)
__CDECLARE_XSC(,__ssize_t,pselect6,(__size_t __nfds, struct __fd_set_struct *__readfds, struct __fd_set_struct *__writefds, struct __fd_set_struct *__exceptfds, struct timespec const *__timeout, void const *__sigmask_sigset_and_len),(__nfds,__readfds,__writefds,__exceptfds,__timeout,__sigmask_sigset_and_len))
#endif /* __CRT_HAVE_XSC(pselect6) */
#if __CRT_HAVE_XSC(ptrace)
__CDECLARE_XSC(,__syscall_slong_t,ptrace,(__syscall_ulong_t __request, __pid_t __pid, void *__addr, void *__data),(__request,__pid,__addr,__data))
#endif /* __CRT_HAVE_XSC(ptrace) */
#if __CRT_HAVE_XSC(pwrite64)
__CDECLARE_XSC(,__ssize_t,pwrite64,(__fd_t __fd, void const *__buf, __size_t __bufsize, __uint64_t __offset),(__fd,__buf,__bufsize,__offset))
#endif /* __CRT_HAVE_XSC(pwrite64) */
#if __CRT_HAVE_XSC(pwritev)
__CDECLARE_XSC(,__ssize_t,pwritev,(__fd_t __fd, struct iovec const *__iovec, __size_t __count, __uint64_t __offset),(__fd,__iovec,__count,__offset))
#endif /* __CRT_HAVE_XSC(pwritev) */
#if __CRT_HAVE_XSC(quotactl)
__CDECLARE_XSC(,__errno_t,quotactl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(quotactl) */
#if __CRT_HAVE_XSC(read)
__CDECLARE_XSC(,__ssize_t,read,(__fd_t __fd, void *__buf, __size_t __bufsize),(__fd,__buf,__bufsize))
#endif /* __CRT_HAVE_XSC(read) */
#if __CRT_HAVE_XSC(readahead)
__CDECLARE_XSC(,__ssize_t,readahead,(__fd_t __fd, __uint64_t __offset, __size_t __count),(__fd,__offset,__count))
#endif /* __CRT_HAVE_XSC(readahead) */
#if __CRT_HAVE_XSC(readlink)
__CDECLARE_XSC(,__ssize_t,readlink,(char const *__path, char *__buf, __size_t __buflen),(__path,__buf,__buflen))
#endif /* __CRT_HAVE_XSC(readlink) */
#if __CRT_HAVE_XSC(readlinkat)
__CDECLARE_XSC(,__ssize_t,readlinkat,(__fd_t __dirfd, char const *__path, char *__buf, __size_t __buflen),(__dirfd,__path,__buf,__buflen))
#endif /* __CRT_HAVE_XSC(readlinkat) */
#if __CRT_HAVE_XSC(readv)
__CDECLARE_XSC(,__ssize_t,readv,(__fd_t __fd, struct iovec const *__iovec, __size_t __count),(__fd,__iovec,__count))
#endif /* __CRT_HAVE_XSC(readv) */
#if __CRT_HAVE_XSC(reboot)
/* @param: how: One of the `RB_*' constants from <sys/reboot.h> */
__CDECLARE_XSC(,__errno_t,reboot,(__syscall_ulong_t __how),(__how))
#endif /* __CRT_HAVE_XSC(reboot) */
#if __CRT_HAVE_XSC(recv)
__CDECLARE_XSC(,__ssize_t,recv,(__fd_t __sockfd, void *__buf, __size_t __bufsize, __syscall_ulong_t __flags),(__sockfd,__buf,__bufsize,__flags))
#endif /* __CRT_HAVE_XSC(recv) */
#if __CRT_HAVE_XSC(recvfrom)
__CDECLARE_XSC(,__ssize_t,recvfrom,(__fd_t __sockfd, void *__buf, __size_t __bufsize, __syscall_ulong_t __flags, struct sockaddr *__addr, __socklen_t *__addr_len),(__sockfd,__buf,__bufsize,__flags,__addr,__addr_len))
#endif /* __CRT_HAVE_XSC(recvfrom) */
#if __CRT_HAVE_XSC(recvmmsg)
__CDECLARE_XSC(,__ssize_t,recvmmsg,(__fd_t __sockfd, struct mmsghdr *__vmessages, __size_t __vlen, __syscall_ulong_t __flags, struct timespec *__tmo),(__sockfd,__vmessages,__vlen,__flags,__tmo))
#endif /* __CRT_HAVE_XSC(recvmmsg) */
#if __CRT_HAVE_XSC(recvmsg)
__CDECLARE_XSC(,__ssize_t,recvmsg,(__fd_t __sockfd, struct msghdr *__message, __syscall_ulong_t __flags),(__sockfd,__message,__flags))
#endif /* __CRT_HAVE_XSC(recvmsg) */
#if __CRT_HAVE_XSC(remap_file_pages)
__CDECLARE_XSC(,__errno_t,remap_file_pages,(void *__start, __size_t __size, __syscall_ulong_t __prot, __size_t __pgoff, __syscall_ulong_t __flags),(__start,__size,__prot,__pgoff,__flags))
#endif /* __CRT_HAVE_XSC(remap_file_pages) */
#if __CRT_HAVE_XSC(removexattr)
__CDECLARE_XSC(,__errno_t,removexattr,(char const *__path, char const *__name),(__path,__name))
#endif /* __CRT_HAVE_XSC(removexattr) */
#if __CRT_HAVE_XSC(rename)
__CDECLARE_XSC(,__errno_t,rename,(char const *__oldname, char const *__newname_or_path),(__oldname,__newname_or_path))
#endif /* __CRT_HAVE_XSC(rename) */
#if __CRT_HAVE_XSC(renameat)
__CDECLARE_XSC(,__errno_t,renameat,(__fd_t __oldfd, char const *__oldname, __fd_t __newfd, char const *__newname_or_path),(__oldfd,__oldname,__newfd,__newname_or_path))
#endif /* __CRT_HAVE_XSC(renameat) */
#if __CRT_HAVE_XSC(renameat2)
/* @param: flags: Set of `RENAME_EXCHANGE,RENAME_NOREPLACE,RENAME_WHITEOUT' */
__CDECLARE_XSC(,__errno_t,renameat2,(__fd_t __olddirfd, char const *__oldpath, __fd_t __newdirfd, char const *__newpath, __syscall_ulong_t __flags),(__olddirfd,__oldpath,__newdirfd,__newpath,__flags))
#endif /* __CRT_HAVE_XSC(renameat2) */
#if __CRT_HAVE_XSC(request_key)
__CDECLARE_XSC(,__errno_t,request_key,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(request_key) */
#if __CRT_HAVE_XSC(restart_syscall)
__CDECLARE_XSC(,__errno_t,restart_syscall,(void),())
#endif /* __CRT_HAVE_XSC(restart_syscall) */
#if __CRT_HAVE_XSC(rmdir)
__CDECLARE_XSC(,__errno_t,rmdir,(char const *__path),(__path))
#endif /* __CRT_HAVE_XSC(rmdir) */
#if __CRT_HAVE_XSC(rt_sigaction)
/* @param: signo: One of `SIG*' */
__CDECLARE_XSC(,__errno_t,rt_sigaction,(__syscall_ulong_t __signo, struct sigaction const *__act, struct sigaction *__oact, __size_t __sigsetsize),(__signo,__act,__oact,__sigsetsize))
#endif /* __CRT_HAVE_XSC(rt_sigaction) */
#if __CRT_HAVE_XSC(rt_sigpending)
__CDECLARE_XSC(,__errno_t,rt_sigpending,(struct __sigset_struct *__set, __size_t __sigsetsize),(__set,__sigsetsize))
#endif /* __CRT_HAVE_XSC(rt_sigpending) */
#if __CRT_HAVE_XSC(rt_sigprocmask)
/* @param: how: One of `SIG_BLOCK', `SIG_UNBLOCK' or `SIG_SETMASK' */
__CDECLARE_XSC(,__errno_t,rt_sigprocmask,(__syscall_ulong_t __how, struct __sigset_struct const *__set, struct __sigset_struct *__oset, __size_t __sigsetsize),(__how,__set,__oset,__sigsetsize))
#endif /* __CRT_HAVE_XSC(rt_sigprocmask) */
#if __CRT_HAVE_XSC(rt_sigqueueinfo)
/* @param: signo: One of `SIG*' */
__CDECLARE_XSC(,__errno_t,rt_sigqueueinfo,(__pid_t __tgid, __syscall_ulong_t __signo, struct __siginfo_struct const *__uinfo),(__tgid,__signo,__uinfo))
#endif /* __CRT_HAVE_XSC(rt_sigqueueinfo) */
#if __CRT_HAVE_XSC(rt_sigsuspend)
__CDECLARE_XSC(,__errno_t,rt_sigsuspend,(struct __sigset_struct const *__set, __size_t __sigsetsize),(__set,__sigsetsize))
#endif /* __CRT_HAVE_XSC(rt_sigsuspend) */
#if __CRT_HAVE_XSC(rt_sigtimedwait)
__CDECLARE_XSC(,__syscall_slong_t,rt_sigtimedwait,(struct __sigset_struct const *__set, struct __siginfo_struct *__info, struct timespec const *__timeout, __size_t __sigsetsize),(__set,__info,__timeout,__sigsetsize))
#endif /* __CRT_HAVE_XSC(rt_sigtimedwait) */
#if __CRT_HAVE_XSC(rt_tgsigqueueinfo)
/* @param: signo: One of `SIG*' */
__CDECLARE_XSC(,__errno_t,rt_tgsigqueueinfo,(__pid_t __tgid, __pid_t __tid, __syscall_ulong_t __signo, struct __siginfo_struct const *__uinfo),(__tgid,__tid,__signo,__uinfo))
#endif /* __CRT_HAVE_XSC(rt_tgsigqueueinfo) */
#if __CRT_HAVE_XSC(sched_get_priority_max)
__CDECLARE_XSC(,__syscall_slong_t,sched_get_priority_max,(__syscall_ulong_t __algorithm),(__algorithm))
#endif /* __CRT_HAVE_XSC(sched_get_priority_max) */
#if __CRT_HAVE_XSC(sched_get_priority_min)
__CDECLARE_XSC(,__syscall_slong_t,sched_get_priority_min,(__syscall_ulong_t __algorithm),(__algorithm))
#endif /* __CRT_HAVE_XSC(sched_get_priority_min) */
#if __CRT_HAVE_XSC(sched_getaffinity)
__CDECLARE_XSC(,__errno_t,sched_getaffinity,(__pid_t __pid, __size_t __cpusetsize, struct __cpu_set_struct *__cpuset),(__pid,__cpusetsize,__cpuset))
#endif /* __CRT_HAVE_XSC(sched_getaffinity) */
#if __CRT_HAVE_XSC(sched_getattr)
__CDECLARE_XSC(,__errno_t,sched_getattr,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(sched_getattr) */
#if __CRT_HAVE_XSC(sched_getparam)
__CDECLARE_XSC(,__errno_t,sched_getparam,(__pid_t __pid, struct sched_param *__param),(__pid,__param))
#endif /* __CRT_HAVE_XSC(sched_getparam) */
#if __CRT_HAVE_XSC(sched_getscheduler)
__CDECLARE_XSC(,__syscall_slong_t,sched_getscheduler,(__pid_t __pid),(__pid))
#endif /* __CRT_HAVE_XSC(sched_getscheduler) */
#if __CRT_HAVE_XSC(sched_rr_get_interval)
__CDECLARE_XSC(,__errno_t,sched_rr_get_interval,(__pid_t __pid, struct __timespec *__tms),(__pid,__tms))
#endif /* __CRT_HAVE_XSC(sched_rr_get_interval) */
#if __CRT_HAVE_XSC(sched_setaffinity)
__CDECLARE_XSC(,__errno_t,sched_setaffinity,(__pid_t __pid, __size_t __cpusetsize, struct __cpu_set_struct const *__cpuset),(__pid,__cpusetsize,__cpuset))
#endif /* __CRT_HAVE_XSC(sched_setaffinity) */
#if __CRT_HAVE_XSC(sched_setattr)
__CDECLARE_XSC(,__errno_t,sched_setattr,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(sched_setattr) */
#if __CRT_HAVE_XSC(sched_setparam)
__CDECLARE_XSC(,__errno_t,sched_setparam,(__pid_t __pid, struct sched_param const *__param),(__pid,__param))
#endif /* __CRT_HAVE_XSC(sched_setparam) */
#if __CRT_HAVE_XSC(sched_setscheduler)
__CDECLARE_XSC(,__errno_t,sched_setscheduler,(__pid_t __pid, __syscall_ulong_t __policy, struct sched_param const *__param),(__pid,__policy,__param))
#endif /* __CRT_HAVE_XSC(sched_setscheduler) */
#if __CRT_HAVE_XSC(sched_yield)
__CDECLARE_XSC(,__errno_t,sched_yield,(void),())
#endif /* __CRT_HAVE_XSC(sched_yield) */
#if __CRT_HAVE_XSC(seccomp)
__CDECLARE_XSC(,__errno_t,seccomp,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(seccomp) */
#if __CRT_HAVE_XSC(select)
__CDECLARE_XSC(,__ssize_t,select,(__size_t __nfds, struct __fd_set_struct *__readfds, struct __fd_set_struct *__writefds, struct __fd_set_struct *__exceptfds, struct timeval *__timeout),(__nfds,__readfds,__writefds,__exceptfds,__timeout))
#endif /* __CRT_HAVE_XSC(select) */
#if __CRT_HAVE_XSC(semctl)
__CDECLARE_XSC(,__errno_t,semctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(semctl) */
#if __CRT_HAVE_XSC(semget)
__CDECLARE_XSC(,__errno_t,semget,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(semget) */
#if __CRT_HAVE_XSC(semop)
__CDECLARE_XSC(,__errno_t,semop,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(semop) */
#if __CRT_HAVE_XSC(semtimedop)
__CDECLARE_XSC(,__errno_t,semtimedop,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(semtimedop) */
#if __CRT_HAVE_XSC(send)
/* param flags: Set of `MSG_CONFIRM | MSG_DONTROUTE | MSG_DONTWAIT | MSG_EOR | MSG_MORE | MSG_NOSIGNAL | MSG_OOB' */
__CDECLARE_XSC(,__ssize_t,send,(__fd_t __sockfd, void const *__buf, __size_t __bufsize, __syscall_ulong_t __flags),(__sockfd,__buf,__bufsize,__flags))
#endif /* __CRT_HAVE_XSC(send) */
#if __CRT_HAVE_XSC(sendfile)
__CDECLARE_XSC(,__ssize_t,sendfile,(__fd_t __out_fd, __fd_t __in_fd, __syscall_ulong_t *__offset, __size_t __count),(__out_fd,__in_fd,__offset,__count))
#endif /* __CRT_HAVE_XSC(sendfile) */
#if __CRT_HAVE_XSC(sendmmsg)
__CDECLARE_XSC(,__ssize_t,sendmmsg,(__fd_t __sockfd, struct mmsghdr *__vmessages, __size_t __vlen, __syscall_ulong_t __flags),(__sockfd,__vmessages,__vlen,__flags))
#endif /* __CRT_HAVE_XSC(sendmmsg) */
#if __CRT_HAVE_XSC(sendmsg)
__CDECLARE_XSC(,__ssize_t,sendmsg,(__fd_t __sockfd, struct msghdr const *__message, __syscall_ulong_t __flags),(__sockfd,__message,__flags))
#endif /* __CRT_HAVE_XSC(sendmsg) */
#if __CRT_HAVE_XSC(sendto)
/* param flags: Set of `MSG_CONFIRM | MSG_DONTROUTE | MSG_DONTWAIT | MSG_EOR | MSG_MORE | MSG_NOSIGNAL | MSG_OOB' */
__CDECLARE_XSC(,__ssize_t,sendto,(__fd_t __sockfd, void const *__buf, __size_t __bufsize, __syscall_ulong_t __flags, struct sockaddr const *__addr, __socklen_t __addr_len),(__sockfd,__buf,__bufsize,__flags,__addr,__addr_len))
#endif /* __CRT_HAVE_XSC(sendto) */
#if __CRT_HAVE_XSC(set_mempolicy)
__CDECLARE_XSC(,__errno_t,set_mempolicy,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(set_mempolicy) */
#if __CRT_HAVE_XSC(set_robust_list)
__CDECLARE_XSC(,__errno_t,set_robust_list,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(set_robust_list) */
#if __CRT_HAVE_XSC(set_tid_address)
__CDECLARE_XSC(,__pid_t,set_tid_address,(__pid_t *__tidptr),(__tidptr))
#endif /* __CRT_HAVE_XSC(set_tid_address) */
#if __CRT_HAVE_XSC(setdomainname)
__CDECLARE_XSC(,__errno_t,setdomainname,(char const *__name, __size_t __len),(__name,__len))
#endif /* __CRT_HAVE_XSC(setdomainname) */
#if __CRT_HAVE_XSC(setfsgid)
__CDECLARE_XSC(,__errno_t,setfsgid,(__gid_t __gid),(__gid))
#endif /* __CRT_HAVE_XSC(setfsgid) */
#if __CRT_HAVE_XSC(setfsuid)
__CDECLARE_XSC(,__errno_t,setfsuid,(__uid_t __uid),(__uid))
#endif /* __CRT_HAVE_XSC(setfsuid) */
#if __CRT_HAVE_XSC(setgid)
__CDECLARE_XSC(,__errno_t,setgid,(__gid_t __gid),(__gid))
#endif /* __CRT_HAVE_XSC(setgid) */
#if __CRT_HAVE_XSC(setgroups)
__CDECLARE_XSC(,__errno_t,setgroups,(__size_t __count, __gid_t const *__groups),(__count,__groups))
#endif /* __CRT_HAVE_XSC(setgroups) */
#if __CRT_HAVE_XSC(sethostname)
__CDECLARE_XSC(,__errno_t,sethostname,(char const *__name, __size_t __len),(__name,__len))
#endif /* __CRT_HAVE_XSC(sethostname) */
#if __CRT_HAVE_XSC(setitimer)
__CDECLARE_XSC(,__errno_t,setitimer,(__syscall_ulong_t __which, struct itimerval const *__newval, struct itimerval *__oldval),(__which,__newval,__oldval))
#endif /* __CRT_HAVE_XSC(setitimer) */
#if __CRT_HAVE_XSC(setns)
__CDECLARE_XSC(,__errno_t,setns,(__fd_t __fd, __syscall_ulong_t __nstype),(__fd,__nstype))
#endif /* __CRT_HAVE_XSC(setns) */
#if __CRT_HAVE_XSC(setpgid)
__CDECLARE_XSC(,__errno_t,setpgid,(__pid_t __pid, __pid_t __pgid),(__pid,__pgid))
#endif /* __CRT_HAVE_XSC(setpgid) */
#if __CRT_HAVE_XSC(setpriority)
__CDECLARE_XSC(,__errno_t,setpriority,(__syscall_ulong_t __which, __id_t __who, __syscall_ulong_t __value),(__which,__who,__value))
#endif /* __CRT_HAVE_XSC(setpriority) */
#if __CRT_HAVE_XSC(setregid)
__CDECLARE_XSC(,__errno_t,setregid,(__gid_t __rgid, __gid_t __egid),(__rgid,__egid))
#endif /* __CRT_HAVE_XSC(setregid) */
#if __CRT_HAVE_XSC(setresgid)
__CDECLARE_XSC(,__errno_t,setresgid,(__gid_t __rgid, __gid_t __egid, __gid_t __sgid),(__rgid,__egid,__sgid))
#endif /* __CRT_HAVE_XSC(setresgid) */
#if __CRT_HAVE_XSC(setresuid)
__CDECLARE_XSC(,__errno_t,setresuid,(__uid_t __ruid, __uid_t __euid, __uid_t __suid),(__ruid,__euid,__suid))
#endif /* __CRT_HAVE_XSC(setresuid) */
#if __CRT_HAVE_XSC(setreuid)
__CDECLARE_XSC(,__errno_t,setreuid,(__uid_t __ruid, __uid_t __euid),(__ruid,__euid))
#endif /* __CRT_HAVE_XSC(setreuid) */
#if __CRT_HAVE_XSC(setrlimit)
__CDECLARE_XSC(,__errno_t,setrlimit,(__syscall_ulong_t __resource, struct rlimit const *__rlimits),(__resource,__rlimits))
#endif /* __CRT_HAVE_XSC(setrlimit) */
#if __CRT_HAVE_XSC(setsid)
__CDECLARE_XSC(,__pid_t,setsid,(void),())
#endif /* __CRT_HAVE_XSC(setsid) */
#if __CRT_HAVE_XSC(setsockopt)
/* @param: level:   One of `SOL_*' (e.g.: `SOL_SOCKET')
 * @param: optname: Dependent on `level' */
__CDECLARE_XSC(,__errno_t,setsockopt,(__fd_t __sockfd, __syscall_ulong_t __level, __syscall_ulong_t __optname, void const *__optval, __socklen_t __optlen),(__sockfd,__level,__optname,__optval,__optlen))
#endif /* __CRT_HAVE_XSC(setsockopt) */
#if __CRT_HAVE_XSC(settimeofday)
__CDECLARE_XSC(,__errno_t,settimeofday,(struct timeval const *__tv, struct timezone const *__tz),(__tv,__tz))
#endif /* __CRT_HAVE_XSC(settimeofday) */
#if __CRT_HAVE_XSC(setuid)
__CDECLARE_XSC(,__errno_t,setuid,(__uid_t __uid),(__uid))
#endif /* __CRT_HAVE_XSC(setuid) */
#if __CRT_HAVE_XSC(setxattr)
__CDECLARE_XSC(,__errno_t,setxattr,(char const *__path, char const *__name, void const *__buf, __size_t __bufsize, __syscall_ulong_t __flags),(__path,__name,__buf,__bufsize,__flags))
#endif /* __CRT_HAVE_XSC(setxattr) */
#if __CRT_HAVE_XSC(shmat)
__CDECLARE_XSC(,__errno_t,shmat,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(shmat) */
#if __CRT_HAVE_XSC(shmctl)
__CDECLARE_XSC(,__errno_t,shmctl,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(shmctl) */
#if __CRT_HAVE_XSC(shmdt)
__CDECLARE_XSC(,__errno_t,shmdt,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(shmdt) */
#if __CRT_HAVE_XSC(shmget)
__CDECLARE_XSC(,__errno_t,shmget,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(shmget) */
#if __CRT_HAVE_XSC(shutdown)
/* @param: how: One of `SHUT_RD', `SHUT_WR' or `SHUT_RDWR' */
__CDECLARE_XSC(,__errno_t,shutdown,(__fd_t __sockfd, __syscall_ulong_t __how),(__sockfd,__how))
#endif /* __CRT_HAVE_XSC(shutdown) */
#if __CRT_HAVE_XSC(sigaltstack)
__CDECLARE_XSC(,__errno_t,sigaltstack,(struct sigaltstack const *__ss, struct sigaltstack *__oss),(__ss,__oss))
#endif /* __CRT_HAVE_XSC(sigaltstack) */
#if __CRT_HAVE_XSC(signalfd)
__CDECLARE_XSC(,__errno_t,signalfd,(__fd_t __fd, struct __sigset_struct const *__sigmask, __size_t __sigsetsize),(__fd,__sigmask,__sigsetsize))
#endif /* __CRT_HAVE_XSC(signalfd) */
#if __CRT_HAVE_XSC(signalfd4)
__CDECLARE_XSC(,__errno_t,signalfd4,(__fd_t __fd, struct __sigset_struct const *__sigmask, __size_t __sigsetsize, __syscall_ulong_t __flags),(__fd,__sigmask,__sigsetsize,__flags))
#endif /* __CRT_HAVE_XSC(signalfd4) */
#if __CRT_HAVE_XSC(socket)
__CDECLARE_XSC(,__fd_t,socket,(__syscall_ulong_t __domain, __syscall_ulong_t __type, __syscall_ulong_t __protocol),(__domain,__type,__protocol))
#endif /* __CRT_HAVE_XSC(socket) */
#if __CRT_HAVE_XSC(socketpair)
__CDECLARE_XSC(,__errno_t,socketpair,(__syscall_ulong_t __domain, __syscall_ulong_t __type, __syscall_ulong_t __protocol, __fd_t *__fds),(__domain,__type,__protocol,__fds))
#endif /* __CRT_HAVE_XSC(socketpair) */
#if __CRT_HAVE_XSC(splice)
__CDECLARE_XSC(,__ssize_t,splice,(__fd_t __fdin, __uint64_t *__offin, __fd_t __fdout, __uint64_t *__offout, __size_t __length, __syscall_ulong_t __flags),(__fdin,__offin,__fdout,__offout,__length,__flags))
#endif /* __CRT_HAVE_XSC(splice) */
#if __CRT_HAVE_XSC(statfs)
__CDECLARE_XSC(,__errno_t,statfs,(char const *__file, struct statfs *__buf),(__file,__buf))
#endif /* __CRT_HAVE_XSC(statfs) */
#if __CRT_HAVE_XSC(swapoff)
__CDECLARE_XSC(,__errno_t,swapoff,(char const *__pathname),(__pathname))
#endif /* __CRT_HAVE_XSC(swapoff) */
#if __CRT_HAVE_XSC(swapon)
/* @param: swapflags: Set of `SWAP_FLAG_*' */
__CDECLARE_XSC(,__errno_t,swapon,(char const *__pathname, __syscall_ulong_t __swapflags),(__pathname,__swapflags))
#endif /* __CRT_HAVE_XSC(swapon) */
#if __CRT_HAVE_XSC(symlink)
__CDECLARE_XSC(,__errno_t,symlink,(char const *__link_text, char const *__target_path),(__link_text,__target_path))
#endif /* __CRT_HAVE_XSC(symlink) */
#if __CRT_HAVE_XSC(symlinkat)
__CDECLARE_XSC(,__errno_t,symlinkat,(char const *__link_text, __fd_t __tofd, char const *__target_path),(__link_text,__tofd,__target_path))
#endif /* __CRT_HAVE_XSC(symlinkat) */
#if __CRT_HAVE_XSC(sync)
__CDECLARE_XSC(,__errno_t,sync,(void),())
#endif /* __CRT_HAVE_XSC(sync) */
#if __CRT_HAVE_XSC(sync_file_range)
__CDECLARE_XSC(,__errno_t,sync_file_range,(__fd_t __fd, __uint64_t __offset, __uint64_t __count, __syscall_ulong_t __flags),(__fd,__offset,__count,__flags))
#endif /* __CRT_HAVE_XSC(sync_file_range) */
#if __CRT_HAVE_XSC(syncfs)
__CDECLARE_XSC(,__errno_t,syncfs,(__fd_t __fd),(__fd))
#endif /* __CRT_HAVE_XSC(syncfs) */
#if __CRT_HAVE_XSC(sysinfo)
__CDECLARE_XSC(,__errno_t,sysinfo,(struct sysinfo *__info),(__info))
#endif /* __CRT_HAVE_XSC(sysinfo) */
#if __CRT_HAVE_XSC(syslog)
__CDECLARE_XSC(,__ssize_t,syslog,(__syscall_ulong_t __level, char const *__str, __size_t __len),(__level,__str,__len))
#endif /* __CRT_HAVE_XSC(syslog) */
#if __CRT_HAVE_XSC(tee)
__CDECLARE_XSC(,__ssize_t,tee,(__fd_t __fdin, __fd_t __fdout, __size_t __length, __syscall_ulong_t __flags),(__fdin,__fdout,__length,__flags))
#endif /* __CRT_HAVE_XSC(tee) */
#if __CRT_HAVE_XSC(tgkill)
__CDECLARE_XSC(,__errno_t,tgkill,(__pid_t __tgid, __pid_t __tid, __syscall_ulong_t __signo),(__tgid,__tid,__signo))
#endif /* __CRT_HAVE_XSC(tgkill) */
#if __CRT_HAVE_XSC(time)
__CDECLARE_XSC(,__time32_t,time,(__time32_t *__timer),(__timer))
#endif /* __CRT_HAVE_XSC(time) */
#if __CRT_HAVE_XSC(timer_create)
__CDECLARE_XSC(,__errno_t,timer_create,(__clockid_t __clock_id, struct sigevent *__evp, __timer_t *__timerid),(__clock_id,__evp,__timerid))
#endif /* __CRT_HAVE_XSC(timer_create) */
#if __CRT_HAVE_XSC(timer_delete)
__CDECLARE_XSC(,__errno_t,timer_delete,(__timer_t __timerid),(__timerid))
#endif /* __CRT_HAVE_XSC(timer_delete) */
#if __CRT_HAVE_XSC(timer_getoverrun)
__CDECLARE_XSC(,__syscall_slong_t,timer_getoverrun,(__timer_t __timerid),(__timerid))
#endif /* __CRT_HAVE_XSC(timer_getoverrun) */
#if __CRT_HAVE_XSC(timer_gettime)
__CDECLARE_XSC(,__errno_t,timer_gettime,(__timer_t __timerid, struct itimerspec *__value),(__timerid,__value))
#endif /* __CRT_HAVE_XSC(timer_gettime) */
#if __CRT_HAVE_XSC(timer_settime)
__CDECLARE_XSC(,__errno_t,timer_settime,(__timer_t __timerid, __syscall_ulong_t __flags, struct itimerspec const *__value, struct itimerspec *__ovalue),(__timerid,__flags,__value,__ovalue))
#endif /* __CRT_HAVE_XSC(timer_settime) */
#if __CRT_HAVE_XSC(timerfd_create)
/* Return file descriptor for new interval timer source */
__CDECLARE_XSC(,__fd_t,timerfd_create,(__clockid_t __clock_id, __syscall_ulong_t __flags),(__clock_id,__flags))
#endif /* __CRT_HAVE_XSC(timerfd_create) */
#if __CRT_HAVE_XSC(timerfd_gettime)
/* Return the next expiration time of UFD */
__CDECLARE_XSC(,__errno_t,timerfd_gettime,(__fd_t __ufd, struct itimerspec *__otmr),(__ufd,__otmr))
#endif /* __CRT_HAVE_XSC(timerfd_gettime) */
#if __CRT_HAVE_XSC(timerfd_settime)
/* Set next expiration time of interval timer source UFD to UTMR.
 * If FLAGS has the TFD_TIMER_ABSTIME flag set the timeout value
 * is absolute. Optionally return the old expiration time in OTMR */
__CDECLARE_XSC(,__errno_t,timerfd_settime,(__fd_t __ufd, __syscall_ulong_t __flags, struct itimerspec const *__utmr, struct itimerspec *__otmr),(__ufd,__flags,__utmr,__otmr))
#endif /* __CRT_HAVE_XSC(timerfd_settime) */
#if __CRT_HAVE_XSC(times)
__CDECLARE_XSC(,__clock_t,times,(struct tms *__buf),(__buf))
#endif /* __CRT_HAVE_XSC(times) */
#if __CRT_HAVE_XSC(tkill)
__CDECLARE_XSC(,__errno_t,tkill,(__pid_t __tid, __syscall_ulong_t __signo),(__tid,__signo))
#endif /* __CRT_HAVE_XSC(tkill) */
#if __CRT_HAVE_XSC(truncate)
__CDECLARE_XSC(,__errno_t,truncate,(char const *__filename, __syscall_ulong_t __length),(__filename,__length))
#endif /* __CRT_HAVE_XSC(truncate) */
#if __CRT_HAVE_XSC(umask)
__CDECLARE_XSC(,__mode_t,umask,(__mode_t __mode),(__mode))
#endif /* __CRT_HAVE_XSC(umask) */
#if __CRT_HAVE_XSC(umount)
__CDECLARE_XSC(,__errno_t,umount,(char const *__special_file),(__special_file))
#endif /* __CRT_HAVE_XSC(umount) */
#if __CRT_HAVE_XSC(umount2)
__CDECLARE_XSC(,__errno_t,umount2,(char const *__special_file, __syscall_ulong_t __flags),(__special_file,__flags))
#endif /* __CRT_HAVE_XSC(umount2) */
#if __CRT_HAVE_XSC(uname)
__CDECLARE_XSC(,__errno_t,uname,(struct utsname *__name),(__name))
#endif /* __CRT_HAVE_XSC(uname) */
#if __CRT_HAVE_XSC(unlink)
__CDECLARE_XSC(,__errno_t,unlink,(char const *__filename),(__filename))
#endif /* __CRT_HAVE_XSC(unlink) */
#if __CRT_HAVE_XSC(unlinkat)
/* @param: flags: Set of `0 | AT_REMOVEDIR|AT_REMOVEREG | AT_DOSPATH' */
__CDECLARE_XSC(,__errno_t,unlinkat,(__fd_t __dirfd, char const *__name, __atflag_t __flags),(__dirfd,__name,__flags))
#endif /* __CRT_HAVE_XSC(unlinkat) */
#if __CRT_HAVE_XSC(unshare)
/* param flags: Set of `CLONE_*' */
__CDECLARE_XSC(,__errno_t,unshare,(__syscall_ulong_t __flags),(__flags))
#endif /* __CRT_HAVE_XSC(unshare) */
#if __CRT_HAVE_XSC(uselib)
__CDECLARE_XSC(,__errno_t,uselib,(char const *__library),(__library))
#endif /* __CRT_HAVE_XSC(uselib) */
#if __CRT_HAVE_XSC(userfaultfd)
__CDECLARE_XSC(,__errno_t,userfaultfd,(int __TODO_PROTOTYPE),(__TODO_PROTOTYPE))
#endif /* __CRT_HAVE_XSC(userfaultfd) */
#if __CRT_HAVE_XSC(ustat)
__CDECLARE_XSC(,__errno_t,ustat,(__dev_t __dev, struct ustat *__ubuf),(__dev,__ubuf))
#endif /* __CRT_HAVE_XSC(ustat) */
#if __CRT_HAVE_XSC(utime)
__CDECLARE_XSC(,__errno_t,utime,(char const *__filename, struct utimbuf const *__times),(__filename,__times))
#endif /* __CRT_HAVE_XSC(utime) */
#if __CRT_HAVE_XSC(utimensat)
/* @param: flags: Set of `0 | AT_SYMLINK_NOFOLLOW | AT_CHANGE_CTIME | AT_DOSPATH' */
__CDECLARE_XSC(,__errno_t,utimensat,(__fd_t __dirfd, char const *__filename, struct timespec const *__times, __atflag_t __flags),(__dirfd,__filename,__times,__flags))
#endif /* __CRT_HAVE_XSC(utimensat) */
#if __CRT_HAVE_XSC(utimes)
__CDECLARE_XSC(,__errno_t,utimes,(char const *__filename, struct timeval const *__times),(__filename,__times))
#endif /* __CRT_HAVE_XSC(utimes) */
#if __CRT_HAVE_XSC(vfork)
__CDECLARE_XSC(,__pid_t,vfork,(void),())
#endif /* __CRT_HAVE_XSC(vfork) */
#if __CRT_HAVE_XSC(vhangup)
__CDECLARE_XSC(,__errno_t,vhangup,(void),())
#endif /* __CRT_HAVE_XSC(vhangup) */
#if __CRT_HAVE_XSC(vmsplice)
__CDECLARE_XSC(,__ssize_t,vmsplice,(__fd_t __fdout, struct iovec const *__iov, __size_t __count, __syscall_ulong_t __flags),(__fdout,__iov,__count,__flags))
#endif /* __CRT_HAVE_XSC(vmsplice) */
#if __CRT_HAVE_XSC(wait4)
/* Same as `waitpid(pid,STAT_LOC,OPTIONS)', though also fills in `USAGE' when non-NULL
 * @param: options: Set of `WNOHANG|WUNTRACED|WCONTINUED' (as a KOS extension, `WNOWAIT' is also accepted) */
__CDECLARE_XSC(,__pid_t,wait4,(__pid_t __pid, __int32_t *__stat_loc, __syscall_ulong_t __options, struct rusage *__usage),(__pid,__stat_loc,__options,__usage))
#endif /* __CRT_HAVE_XSC(wait4) */
#if __CRT_HAVE_XSC(waitid)
/* @param: options: At least one of `WEXITED | WSTOPPED | WCONTINUED', optionally or'd with `WNOHANG | WNOWAIT' */
__CDECLARE_XSC(,__errno_t,waitid,(__syscall_ulong_t __idtype, __id_t __id, struct __siginfo_struct *__infop, __syscall_ulong_t __options, struct rusage *__ru),(__idtype,__id,__infop,__options,__ru))
#endif /* __CRT_HAVE_XSC(waitid) */
#if __CRT_HAVE_XSC(write)
__CDECLARE_XSC(,__ssize_t,write,(__fd_t __fd, void const *__buf, __size_t __bufsize),(__fd,__buf,__bufsize))
#endif /* __CRT_HAVE_XSC(write) */
#if __CRT_HAVE_XSC(writev)
__CDECLARE_XSC(,__ssize_t,writev,(__fd_t __fd, struct iovec const *__iovec, __size_t __count),(__fd,__iovec,__count))
#endif /* __CRT_HAVE_XSC(writev) */

#ifdef __COMPILER_HAVE_PRAGMA_PUSHMACRO
#pragma pop_macro("timezone")
#endif /* __COMPILER_HAVE_PRAGMA_PUSHMACRO */


__SYSDECL_END
#endif /* __CC__ */

#endif /* !_KOS_SYSCALL_H */
