/* HASH CRC-32:0x21aeed58 */
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

/* Enumerate known system calls by name */
#ifndef __SYSCALL
#define __SYSCALL(name) /* nothing */
#endif /* !__SYSCALL */

/* Enumerate unused system calls IDs */
#ifndef __SYSCALL_UNUSED
#define __SYSCALL_UNUSED(sysno) /* nothing */
#endif /* !__SYSCALL_UNUSED */

/* Enumerate used system calls */
#ifndef __TSYSCALL
#define __TSYSCALL(table_id, name, table_index, table_index_without_unused_leading) __SYSCALL(name)
#endif /* !__TSYSCALL */

/* Enumerate unused system calls */
#ifndef __TSYSCALL_UNUSED
#define __TSYSCALL_UNUSED(table_id, sysno, table_index, table_index_without_unused_leading) __SYSCALL_UNUSED(sysno)
#endif /* !__TSYSCALL_UNUSED */

/* Enumerate unused system calls at the start of a table */
#ifndef __TSYSCALL_UNUSED_LEADING
#define __TSYSCALL_UNUSED_LEADING(table_id, sysno, table_index) __SYSCALL_UNUSED(sysno)
#endif /* !__TSYSCALL_UNUSED_LEADING */

/* Enumerate unused system calls at the end of a table */
#ifndef __TSYSCALL_UNUSED_TRAILING
#define __TSYSCALL_UNUSED_TRAILING(table_id, sysno, table_index, table_index_without_unused_leading, index_in_unused_trailing) __SYSCALL_UNUSED(sysno)
#endif /* !__TSYSCALL_UNUSED_TRAILING */

/* Invoked at the start of a system call table */
#ifndef __TSYSCALL_TABLE_BEGIN
#define __TSYSCALL_TABLE_BEGIN(table_id, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) /* nothing */
#endif /* !__TSYSCALL_TABLE_BEGIN */

/* Invoked at the end of a system call table */
#ifndef __TSYSCALL_TABLE_END
#define __TSYSCALL_TABLE_END(table_id, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) /* nothing */
#endif /* !__TSYSCALL_TABLE_END */

/* Enumerate used system calls in the 1st system call */
#ifndef __TSYSCALL0
#define __TSYSCALL0(name, index, index_without_unused_leading) __TSYSCALL(0, name, index, index_without_unused_leading)
#endif /* !__TSYSCALL0 */

/* Enumerate unused system calls in the middle of the 1st system call table*/
#ifndef __TSYSCALL0_UNUSED
#define __TSYSCALL0_UNUSED(sysno, index, index_without_unused_leading) __TSYSCALL_UNUSED(0, sysno, index, index_without_unused_leading)
#endif /* !__TSYSCALL0_UNUSED */

/* Enumerate unused system calls at the start of the 1st system call table */
#ifndef __TSYSCALL0_UNUSED_LEADING
#define __TSYSCALL0_UNUSED_LEADING(sysno, index) __TSYSCALL_UNUSED_LEADING(0, sysno, index)
#endif /* !__TSYSCALL0_UNUSED_LEADING */

/* Enumerate unused system calls at the end of the 1st system call table */
#ifndef __TSYSCALL0_UNUSED_TRAILING
#define __TSYSCALL0_UNUSED_TRAILING(sysno, index, index_without_unused_leading, index_in_unused_trailing) __TSYSCALL_UNUSED_TRAILING(0, sysno, index, index_without_unused_leading, index_in_unused_trailing)
#endif /* !__TSYSCALL0_UNUSED_TRAILING */

/* Invoked at the start of the 1st system call table */
#ifndef __TSYSCALL0_TABLE_BEGIN
#define __TSYSCALL0_TABLE_BEGIN(minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) \
	__TSYSCALL_TABLE_BEGIN(0, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding)
#endif /* !__TSYSCALL0_TABLE_BEGIN */

/* Invoked at the end of the 1st system call table */
#ifndef __TSYSCALL0_TABLE_END
#define __TSYSCALL0_TABLE_END(minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) \
	__TSYSCALL_TABLE_END(0, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding)
#endif /* !__TSYSCALL0_TABLE_END */

/* Enumerate used system calls in the 2nd system call */
#ifndef __TSYSCALL1
#define __TSYSCALL1(name, index, index_without_unused_leading) __TSYSCALL(1, name, index, index_without_unused_leading)
#endif /* !__TSYSCALL1 */

/* Enumerate unused system calls in the middle of the 2nd system call table*/
#ifndef __TSYSCALL1_UNUSED
#define __TSYSCALL1_UNUSED(sysno, index, index_without_unused_leading) __TSYSCALL_UNUSED(1, sysno, index, index_without_unused_leading)
#endif /* !__TSYSCALL1_UNUSED */

/* Enumerate unused system calls at the start of the 2nd system call table */
#ifndef __TSYSCALL1_UNUSED_LEADING
#define __TSYSCALL1_UNUSED_LEADING(sysno, index) __TSYSCALL_UNUSED_LEADING(1, sysno, index)
#endif /* !__TSYSCALL1_UNUSED_LEADING */

/* Enumerate unused system calls at the end of the 2nd system call table */
#ifndef __TSYSCALL1_UNUSED_TRAILING
#define __TSYSCALL1_UNUSED_TRAILING(sysno, index, index_without_unused_leading, index_in_unused_trailing) __TSYSCALL_UNUSED_TRAILING(1, sysno, index, index_without_unused_leading, index_in_unused_trailing)
#endif /* !__TSYSCALL1_UNUSED_TRAILING */

/* Invoked at the start of the 2nd system call table */
#ifndef __TSYSCALL1_TABLE_BEGIN
#define __TSYSCALL1_TABLE_BEGIN(minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) \
	__TSYSCALL_TABLE_BEGIN(1, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding)
#endif /* !__TSYSCALL1_TABLE_BEGIN */

/* Invoked at the end of the 2nd system call table */
#ifndef __TSYSCALL1_TABLE_END
#define __TSYSCALL1_TABLE_END(minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding) \
	__TSYSCALL_TABLE_END(1, minsysno, maxsysno, sysnocnt, minsysno_without_unused_leading, maxsysno_without_unused_trailing, sysnocnt_without_unused_surrounding)
#endif /* !__TSYSCALL1_TABLE_END */

/************************************************************************/
/* Contents of the 1st table                                            */
/************************************************************************/
__TSYSCALL0_TABLE_BEGIN(0x0, 0x178, 0x179, 0x0, 0x178, 0x179)
__TSYSCALL0(restart_syscall, 0x0, 0x0)
__TSYSCALL0(exit, 0x1, 0x1)
__TSYSCALL0(fork, 0x2, 0x2)
__TSYSCALL0(read, 0x3, 0x3)
__TSYSCALL0(write, 0x4, 0x4)
__TSYSCALL0(open, 0x5, 0x5)
__TSYSCALL0(close, 0x6, 0x6)
__TSYSCALL0(waitpid, 0x7, 0x7)
__TSYSCALL0(creat, 0x8, 0x8)
__TSYSCALL0(link, 0x9, 0x9)
__TSYSCALL0(unlink, 0xa, 0xa)
__TSYSCALL0(execve, 0xb, 0xb)
__TSYSCALL0(chdir, 0xc, 0xc)
__TSYSCALL0(time, 0xd, 0xd)
__TSYSCALL0(mknod, 0xe, 0xe)
__TSYSCALL0(chmod, 0xf, 0xf)
__TSYSCALL0(lchown, 0x10, 0x10)
__TSYSCALL0(break, 0x11, 0x11)
__TSYSCALL0(linux_oldstat, 0x12, 0x12)
__TSYSCALL0(lseek, 0x13, 0x13)
__TSYSCALL0(getpid, 0x14, 0x14)
__TSYSCALL0(mount, 0x15, 0x15)
__TSYSCALL0(umount, 0x16, 0x16)
__TSYSCALL0(setuid, 0x17, 0x17)
__TSYSCALL0(getuid, 0x18, 0x18)
__TSYSCALL0(stime, 0x19, 0x19)
__TSYSCALL0(ptrace, 0x1a, 0x1a)
__TSYSCALL0(alarm, 0x1b, 0x1b)
__TSYSCALL0(linux_oldfstat, 0x1c, 0x1c)
__TSYSCALL0(pause, 0x1d, 0x1d)
__TSYSCALL0(utime, 0x1e, 0x1e)
__TSYSCALL0(stty, 0x1f, 0x1f)
__TSYSCALL0(gtty, 0x20, 0x20)
__TSYSCALL0(access, 0x21, 0x21)
__TSYSCALL0(nice, 0x22, 0x22)
__TSYSCALL0(ftime, 0x23, 0x23)
__TSYSCALL0(sync, 0x24, 0x24)
__TSYSCALL0(kill, 0x25, 0x25)
__TSYSCALL0(rename, 0x26, 0x26)
__TSYSCALL0(mkdir, 0x27, 0x27)
__TSYSCALL0(rmdir, 0x28, 0x28)
__TSYSCALL0(dup, 0x29, 0x29)
__TSYSCALL0(pipe, 0x2a, 0x2a)
__TSYSCALL0(times, 0x2b, 0x2b)
__TSYSCALL0(prof, 0x2c, 0x2c)
__TSYSCALL0(brk, 0x2d, 0x2d)
__TSYSCALL0(setgid, 0x2e, 0x2e)
__TSYSCALL0(getgid, 0x2f, 0x2f)
__TSYSCALL0(signal, 0x30, 0x30)
__TSYSCALL0(geteuid, 0x31, 0x31)
__TSYSCALL0(getegid, 0x32, 0x32)
__TSYSCALL0(acct, 0x33, 0x33)
__TSYSCALL0(umount2, 0x34, 0x34)
__TSYSCALL0(lock, 0x35, 0x35)
__TSYSCALL0(ioctl, 0x36, 0x36)
__TSYSCALL0(fcntl, 0x37, 0x37)
__TSYSCALL0(mpx, 0x38, 0x38)
__TSYSCALL0(setpgid, 0x39, 0x39)
__TSYSCALL0(ulimit, 0x3a, 0x3a)
__TSYSCALL0(oldolduname, 0x3b, 0x3b)
__TSYSCALL0(umask, 0x3c, 0x3c)
__TSYSCALL0(chroot, 0x3d, 0x3d)
__TSYSCALL0(ustat, 0x3e, 0x3e)
__TSYSCALL0(dup2, 0x3f, 0x3f)
__TSYSCALL0(getppid, 0x40, 0x40)
__TSYSCALL0(getpgrp, 0x41, 0x41)
__TSYSCALL0(setsid, 0x42, 0x42)
__TSYSCALL0(sigaction, 0x43, 0x43)
__TSYSCALL0(sgetmask, 0x44, 0x44)
__TSYSCALL0(ssetmask, 0x45, 0x45)
__TSYSCALL0(setreuid, 0x46, 0x46)
__TSYSCALL0(setregid, 0x47, 0x47)
__TSYSCALL0(sigsuspend, 0x48, 0x48)
__TSYSCALL0(sigpending, 0x49, 0x49)
__TSYSCALL0(sethostname, 0x4a, 0x4a)
__TSYSCALL0(setrlimit, 0x4b, 0x4b)
__TSYSCALL0(getrlimit, 0x4c, 0x4c)
__TSYSCALL0(getrusage, 0x4d, 0x4d)
__TSYSCALL0(gettimeofday, 0x4e, 0x4e)
__TSYSCALL0(settimeofday, 0x4f, 0x4f)
__TSYSCALL0(getgroups, 0x50, 0x50)
__TSYSCALL0(setgroups, 0x51, 0x51)
__TSYSCALL0(select, 0x52, 0x52)
__TSYSCALL0(symlink, 0x53, 0x53)
__TSYSCALL0(linux_oldlstat, 0x54, 0x54)
__TSYSCALL0(readlink, 0x55, 0x55)
__TSYSCALL0(uselib, 0x56, 0x56)
__TSYSCALL0(swapon, 0x57, 0x57)
__TSYSCALL0(reboot, 0x58, 0x58)
__TSYSCALL0(readdir, 0x59, 0x59)
__TSYSCALL0(mmap, 0x5a, 0x5a)
__TSYSCALL0(munmap, 0x5b, 0x5b)
__TSYSCALL0(truncate, 0x5c, 0x5c)
__TSYSCALL0(ftruncate, 0x5d, 0x5d)
__TSYSCALL0(fchmod, 0x5e, 0x5e)
__TSYSCALL0(fchown, 0x5f, 0x5f)
__TSYSCALL0(getpriority, 0x60, 0x60)
__TSYSCALL0(setpriority, 0x61, 0x61)
__TSYSCALL0(profil, 0x62, 0x62)
__TSYSCALL0(statfs, 0x63, 0x63)
__TSYSCALL0(fstatfs, 0x64, 0x64)
__TSYSCALL0(ioperm, 0x65, 0x65)
__TSYSCALL0(socketcall, 0x66, 0x66)
__TSYSCALL0(syslog, 0x67, 0x67)
__TSYSCALL0(setitimer, 0x68, 0x68)
__TSYSCALL0(getitimer, 0x69, 0x69)
__TSYSCALL0(linux_stat32, 0x6a, 0x6a)
__TSYSCALL0(linux_lstat32, 0x6b, 0x6b)
__TSYSCALL0(linux_fstat32, 0x6c, 0x6c)
__TSYSCALL0(olduname, 0x6d, 0x6d)
__TSYSCALL0(iopl, 0x6e, 0x6e)
__TSYSCALL0(vhangup, 0x6f, 0x6f)
__TSYSCALL0(idle, 0x70, 0x70)
__TSYSCALL0(vm86old, 0x71, 0x71)
__TSYSCALL0(wait4, 0x72, 0x72)
__TSYSCALL0(swapoff, 0x73, 0x73)
__TSYSCALL0(sysinfo, 0x74, 0x74)
__TSYSCALL0(ipc, 0x75, 0x75)
__TSYSCALL0(fsync, 0x76, 0x76)
__TSYSCALL0(sigreturn, 0x77, 0x77)
__TSYSCALL0(clone, 0x78, 0x78)
__TSYSCALL0(setdomainname, 0x79, 0x79)
__TSYSCALL0(uname, 0x7a, 0x7a)
__TSYSCALL0(modify_ldt, 0x7b, 0x7b)
__TSYSCALL0(adjtimex, 0x7c, 0x7c)
__TSYSCALL0(mprotect, 0x7d, 0x7d)
__TSYSCALL0(sigprocmask, 0x7e, 0x7e)
__TSYSCALL0(create_module, 0x7f, 0x7f)
__TSYSCALL0(init_module, 0x80, 0x80)
__TSYSCALL0(delete_module, 0x81, 0x81)
__TSYSCALL0(get_kernel_syms, 0x82, 0x82)
__TSYSCALL0(quotactl, 0x83, 0x83)
__TSYSCALL0(getpgid, 0x84, 0x84)
__TSYSCALL0(fchdir, 0x85, 0x85)
__TSYSCALL0(bdflush, 0x86, 0x86)
__TSYSCALL0(sysfs, 0x87, 0x87)
__TSYSCALL0(personality, 0x88, 0x88)
__TSYSCALL0(afs_syscall, 0x89, 0x89)
__TSYSCALL0(setfsuid, 0x8a, 0x8a)
__TSYSCALL0(setfsgid, 0x8b, 0x8b)
__TSYSCALL0(_llseek, 0x8c, 0x8c)
__TSYSCALL0(getdents, 0x8d, 0x8d)
__TSYSCALL0(_newselect, 0x8e, 0x8e)
__TSYSCALL0(flock, 0x8f, 0x8f)
__TSYSCALL0(msync, 0x90, 0x90)
__TSYSCALL0(readv, 0x91, 0x91)
__TSYSCALL0(writev, 0x92, 0x92)
__TSYSCALL0(getsid, 0x93, 0x93)
__TSYSCALL0(fdatasync, 0x94, 0x94)
__TSYSCALL0(_sysctl, 0x95, 0x95)
__TSYSCALL0(mlock, 0x96, 0x96)
__TSYSCALL0(munlock, 0x97, 0x97)
__TSYSCALL0(mlockall, 0x98, 0x98)
__TSYSCALL0(munlockall, 0x99, 0x99)
__TSYSCALL0(sched_setparam, 0x9a, 0x9a)
__TSYSCALL0(sched_getparam, 0x9b, 0x9b)
__TSYSCALL0(sched_setscheduler, 0x9c, 0x9c)
__TSYSCALL0(sched_getscheduler, 0x9d, 0x9d)
__TSYSCALL0(sched_yield, 0x9e, 0x9e)
__TSYSCALL0(sched_get_priority_max, 0x9f, 0x9f)
__TSYSCALL0(sched_get_priority_min, 0xa0, 0xa0)
__TSYSCALL0(sched_rr_get_interval, 0xa1, 0xa1)
__TSYSCALL0(nanosleep, 0xa2, 0xa2)
__TSYSCALL0(mremap, 0xa3, 0xa3)
__TSYSCALL0(setresuid, 0xa4, 0xa4)
__TSYSCALL0(getresuid, 0xa5, 0xa5)
__TSYSCALL0(vm86, 0xa6, 0xa6)
__TSYSCALL0(query_module, 0xa7, 0xa7)
__TSYSCALL0(poll, 0xa8, 0xa8)
__TSYSCALL0(nfsservctl, 0xa9, 0xa9)
__TSYSCALL0(setresgid, 0xaa, 0xaa)
__TSYSCALL0(getresgid, 0xab, 0xab)
__TSYSCALL0(prctl, 0xac, 0xac)
__TSYSCALL0(rt_sigreturn, 0xad, 0xad)
__TSYSCALL0(rt_sigaction, 0xae, 0xae)
__TSYSCALL0(rt_sigprocmask, 0xaf, 0xaf)
__TSYSCALL0(rt_sigpending, 0xb0, 0xb0)
__TSYSCALL0(rt_sigtimedwait, 0xb1, 0xb1)
__TSYSCALL0(rt_sigqueueinfo, 0xb2, 0xb2)
__TSYSCALL0(rt_sigsuspend, 0xb3, 0xb3)
__TSYSCALL0(pread64, 0xb4, 0xb4)
__TSYSCALL0(pwrite64, 0xb5, 0xb5)
__TSYSCALL0(chown, 0xb6, 0xb6)
__TSYSCALL0(getcwd, 0xb7, 0xb7)
__TSYSCALL0(capget, 0xb8, 0xb8)
__TSYSCALL0(capset, 0xb9, 0xb9)
__TSYSCALL0(sigaltstack, 0xba, 0xba)
__TSYSCALL0(sendfile, 0xbb, 0xbb)
__TSYSCALL0(getpmsg, 0xbc, 0xbc)
__TSYSCALL0(putpmsg, 0xbd, 0xbd)
__TSYSCALL0(vfork, 0xbe, 0xbe)
__TSYSCALL0(ugetrlimit, 0xbf, 0xbf)
__TSYSCALL0(mmap2, 0xc0, 0xc0)
__TSYSCALL0(truncate64, 0xc1, 0xc1)
__TSYSCALL0(ftruncate64, 0xc2, 0xc2)
__TSYSCALL0(linux_stat64, 0xc3, 0xc3)
__TSYSCALL0(linux_lstat64, 0xc4, 0xc4)
__TSYSCALL0(linux_fstat64, 0xc5, 0xc5)
__TSYSCALL0(lchown32, 0xc6, 0xc6)
__TSYSCALL0(getuid32, 0xc7, 0xc7)
__TSYSCALL0(getgid32, 0xc8, 0xc8)
__TSYSCALL0(geteuid32, 0xc9, 0xc9)
__TSYSCALL0(getegid32, 0xca, 0xca)
__TSYSCALL0(setreuid32, 0xcb, 0xcb)
__TSYSCALL0(setregid32, 0xcc, 0xcc)
__TSYSCALL0(getgroups32, 0xcd, 0xcd)
__TSYSCALL0(setgroups32, 0xce, 0xce)
__TSYSCALL0(fchown32, 0xcf, 0xcf)
__TSYSCALL0(setresuid32, 0xd0, 0xd0)
__TSYSCALL0(getresuid32, 0xd1, 0xd1)
__TSYSCALL0(setresgid32, 0xd2, 0xd2)
__TSYSCALL0(getresgid32, 0xd3, 0xd3)
__TSYSCALL0(chown32, 0xd4, 0xd4)
__TSYSCALL0(setuid32, 0xd5, 0xd5)
__TSYSCALL0(setgid32, 0xd6, 0xd6)
__TSYSCALL0(setfsuid32, 0xd7, 0xd7)
__TSYSCALL0(setfsgid32, 0xd8, 0xd8)
__TSYSCALL0(pivot_root, 0xd9, 0xd9)
__TSYSCALL0(mincore, 0xda, 0xda)
__TSYSCALL0(madvise, 0xdb, 0xdb)
__TSYSCALL0(getdents64, 0xdc, 0xdc)
__TSYSCALL0(fcntl64, 0xdd, 0xdd)
__TSYSCALL0_UNUSED(0xde, 0xde, 0xde)
__TSYSCALL0_UNUSED(0xdf, 0xdf, 0xdf)
__TSYSCALL0(gettid, 0xe0, 0xe0)
__TSYSCALL0(readahead, 0xe1, 0xe1)
__TSYSCALL0(setxattr, 0xe2, 0xe2)
__TSYSCALL0(lsetxattr, 0xe3, 0xe3)
__TSYSCALL0(fsetxattr, 0xe4, 0xe4)
__TSYSCALL0(getxattr, 0xe5, 0xe5)
__TSYSCALL0(lgetxattr, 0xe6, 0xe6)
__TSYSCALL0(fgetxattr, 0xe7, 0xe7)
__TSYSCALL0(listxattr, 0xe8, 0xe8)
__TSYSCALL0(llistxattr, 0xe9, 0xe9)
__TSYSCALL0(flistxattr, 0xea, 0xea)
__TSYSCALL0(removexattr, 0xeb, 0xeb)
__TSYSCALL0(lremovexattr, 0xec, 0xec)
__TSYSCALL0(fremovexattr, 0xed, 0xed)
__TSYSCALL0(tkill, 0xee, 0xee)
__TSYSCALL0(sendfile64, 0xef, 0xef)
__TSYSCALL0(futex, 0xf0, 0xf0)
__TSYSCALL0(sched_setaffinity, 0xf1, 0xf1)
__TSYSCALL0(sched_getaffinity, 0xf2, 0xf2)
__TSYSCALL0(set_thread_area, 0xf3, 0xf3)
__TSYSCALL0(get_thread_area, 0xf4, 0xf4)
__TSYSCALL0(io_setup, 0xf5, 0xf5)
__TSYSCALL0(io_destroy, 0xf6, 0xf6)
__TSYSCALL0(io_getevents, 0xf7, 0xf7)
__TSYSCALL0(io_submit, 0xf8, 0xf8)
__TSYSCALL0(io_cancel, 0xf9, 0xf9)
__TSYSCALL0(fadvise64, 0xfa, 0xfa)
__TSYSCALL0_UNUSED(0xfb, 0xfb, 0xfb)
__TSYSCALL0(exit_group, 0xfc, 0xfc)
__TSYSCALL0(lookup_dcookie, 0xfd, 0xfd)
__TSYSCALL0(epoll_create, 0xfe, 0xfe)
__TSYSCALL0(epoll_ctl, 0xff, 0xff)
__TSYSCALL0(epoll_wait, 0x100, 0x100)
__TSYSCALL0(remap_file_pages, 0x101, 0x101)
__TSYSCALL0(set_tid_address, 0x102, 0x102)
__TSYSCALL0(timer_create, 0x103, 0x103)
__TSYSCALL0(timer_settime, 0x104, 0x104)
__TSYSCALL0(timer_gettime, 0x105, 0x105)
__TSYSCALL0(timer_getoverrun, 0x106, 0x106)
__TSYSCALL0(timer_delete, 0x107, 0x107)
__TSYSCALL0(clock_settime, 0x108, 0x108)
__TSYSCALL0(clock_gettime, 0x109, 0x109)
__TSYSCALL0(clock_getres, 0x10a, 0x10a)
__TSYSCALL0(clock_nanosleep, 0x10b, 0x10b)
__TSYSCALL0(statfs64, 0x10c, 0x10c)
__TSYSCALL0(fstatfs64, 0x10d, 0x10d)
__TSYSCALL0(tgkill, 0x10e, 0x10e)
__TSYSCALL0(utimes, 0x10f, 0x10f)
__TSYSCALL0(fadvise64_64, 0x110, 0x110)
__TSYSCALL0(vserver, 0x111, 0x111)
__TSYSCALL0(mbind, 0x112, 0x112)
__TSYSCALL0(get_mempolicy, 0x113, 0x113)
__TSYSCALL0(set_mempolicy, 0x114, 0x114)
__TSYSCALL0(mq_open, 0x115, 0x115)
__TSYSCALL0(mq_unlink, 0x116, 0x116)
__TSYSCALL0(mq_timedsend, 0x117, 0x117)
__TSYSCALL0(mq_timedreceive, 0x118, 0x118)
__TSYSCALL0(mq_notify, 0x119, 0x119)
__TSYSCALL0(mq_getsetattr, 0x11a, 0x11a)
__TSYSCALL0(kexec_load, 0x11b, 0x11b)
__TSYSCALL0(waitid, 0x11c, 0x11c)
__TSYSCALL0_UNUSED(0x11d, 0x11d, 0x11d)
__TSYSCALL0(add_key, 0x11e, 0x11e)
__TSYSCALL0(request_key, 0x11f, 0x11f)
__TSYSCALL0(keyctl, 0x120, 0x120)
__TSYSCALL0(ioprio_set, 0x121, 0x121)
__TSYSCALL0(ioprio_get, 0x122, 0x122)
__TSYSCALL0(inotify_init, 0x123, 0x123)
__TSYSCALL0(inotify_add_watch, 0x124, 0x124)
__TSYSCALL0(inotify_rm_watch, 0x125, 0x125)
__TSYSCALL0(migrate_pages, 0x126, 0x126)
__TSYSCALL0(openat, 0x127, 0x127)
__TSYSCALL0(mkdirat, 0x128, 0x128)
__TSYSCALL0(mknodat, 0x129, 0x129)
__TSYSCALL0(fchownat, 0x12a, 0x12a)
__TSYSCALL0(futimesat, 0x12b, 0x12b)
__TSYSCALL0(linux_fstatat64, 0x12c, 0x12c)
__TSYSCALL0(unlinkat, 0x12d, 0x12d)
__TSYSCALL0(renameat, 0x12e, 0x12e)
__TSYSCALL0(linkat, 0x12f, 0x12f)
__TSYSCALL0(symlinkat, 0x130, 0x130)
__TSYSCALL0(readlinkat, 0x131, 0x131)
__TSYSCALL0(fchmodat, 0x132, 0x132)
__TSYSCALL0(faccessat, 0x133, 0x133)
__TSYSCALL0(pselect6, 0x134, 0x134)
__TSYSCALL0(ppoll, 0x135, 0x135)
__TSYSCALL0(unshare, 0x136, 0x136)
__TSYSCALL0(set_robust_list, 0x137, 0x137)
__TSYSCALL0(get_robust_list, 0x138, 0x138)
__TSYSCALL0(splice, 0x139, 0x139)
__TSYSCALL0(sync_file_range, 0x13a, 0x13a)
__TSYSCALL0(tee, 0x13b, 0x13b)
__TSYSCALL0(vmsplice, 0x13c, 0x13c)
__TSYSCALL0(move_pages, 0x13d, 0x13d)
__TSYSCALL0(getcpu, 0x13e, 0x13e)
__TSYSCALL0(epoll_pwait, 0x13f, 0x13f)
__TSYSCALL0(utimensat, 0x140, 0x140)
__TSYSCALL0(signalfd, 0x141, 0x141)
__TSYSCALL0(timerfd_create, 0x142, 0x142)
__TSYSCALL0(eventfd, 0x143, 0x143)
__TSYSCALL0(fallocate, 0x144, 0x144)
__TSYSCALL0(timerfd_settime, 0x145, 0x145)
__TSYSCALL0(timerfd_gettime, 0x146, 0x146)
__TSYSCALL0(signalfd4, 0x147, 0x147)
__TSYSCALL0(eventfd2, 0x148, 0x148)
__TSYSCALL0(epoll_create1, 0x149, 0x149)
__TSYSCALL0(dup3, 0x14a, 0x14a)
__TSYSCALL0(pipe2, 0x14b, 0x14b)
__TSYSCALL0(inotify_init1, 0x14c, 0x14c)
__TSYSCALL0(preadv, 0x14d, 0x14d)
__TSYSCALL0(pwritev, 0x14e, 0x14e)
__TSYSCALL0(rt_tgsigqueueinfo, 0x14f, 0x14f)
__TSYSCALL0(perf_event_open, 0x150, 0x150)
__TSYSCALL0(recvmmsg, 0x151, 0x151)
__TSYSCALL0(fanotify_init, 0x152, 0x152)
__TSYSCALL0(fanotify_mark, 0x153, 0x153)
__TSYSCALL0(prlimit64, 0x154, 0x154)
__TSYSCALL0(name_to_handle_at, 0x155, 0x155)
__TSYSCALL0(open_by_handle_at, 0x156, 0x156)
__TSYSCALL0(clock_adjtime, 0x157, 0x157)
__TSYSCALL0(syncfs, 0x158, 0x158)
__TSYSCALL0(sendmmsg, 0x159, 0x159)
__TSYSCALL0(setns, 0x15a, 0x15a)
__TSYSCALL0(process_vm_readv, 0x15b, 0x15b)
__TSYSCALL0(process_vm_writev, 0x15c, 0x15c)
__TSYSCALL0(kcmp, 0x15d, 0x15d)
__TSYSCALL0(finit_module, 0x15e, 0x15e)
__TSYSCALL0(sched_setattr, 0x15f, 0x15f)
__TSYSCALL0(sched_getattr, 0x160, 0x160)
__TSYSCALL0(renameat2, 0x161, 0x161)
__TSYSCALL0(seccomp, 0x162, 0x162)
__TSYSCALL0(getrandom, 0x163, 0x163)
__TSYSCALL0(memfd_create, 0x164, 0x164)
__TSYSCALL0(bpf, 0x165, 0x165)
__TSYSCALL0(execveat, 0x166, 0x166)
__TSYSCALL0(socket, 0x167, 0x167)
__TSYSCALL0(socketpair, 0x168, 0x168)
__TSYSCALL0(bind, 0x169, 0x169)
__TSYSCALL0(connect, 0x16a, 0x16a)
__TSYSCALL0(listen, 0x16b, 0x16b)
__TSYSCALL0(accept4, 0x16c, 0x16c)
__TSYSCALL0(getsockopt, 0x16d, 0x16d)
__TSYSCALL0(setsockopt, 0x16e, 0x16e)
__TSYSCALL0(getsockname, 0x16f, 0x16f)
__TSYSCALL0(getpeername, 0x170, 0x170)
__TSYSCALL0(sendto, 0x171, 0x171)
__TSYSCALL0(sendmsg, 0x172, 0x172)
__TSYSCALL0(recvfrom, 0x173, 0x173)
__TSYSCALL0(recvmsg, 0x174, 0x174)
__TSYSCALL0(shutdown, 0x175, 0x175)
__TSYSCALL0(userfaultfd, 0x176, 0x176)
__TSYSCALL0(membarrier, 0x177, 0x177)
__TSYSCALL0(mlock2, 0x178, 0x178)
__TSYSCALL0_TABLE_END(0x0, 0x178, 0x179, 0x0, 0x178, 0x179)

/************************************************************************/
/* Contents of the 2nd table                                            */
/************************************************************************/
__TSYSCALL1_TABLE_BEGIN(0x80000001, 0x80000151, 0x151, 0x80000001, 0x80000151, 0x151)
__TSYSCALL1(hop, 0x0, 0x0)
__TSYSCALL1(hopf, 0x1, 0x1)
__TSYSCALL1(readf, 0x2, 0x2)
__TSYSCALL1(writef, 0x3, 0x3)
__TSYSCALL1(detach, 0x4, 0x4)
__TSYSCALL1(getdrives, 0x5, 0x5)
__TSYSCALL1(frealpath4, 0x6, 0x6)
__TSYSCALL1(frealpathat, 0x7, 0x7)
__TSYSCALL1(rpc_schedule, 0x8, 0x8)
__TSYSCALL1(ksysctl, 0x9, 0x9)
__TSYSCALL1(openpty, 0xa, 0xa)
__TSYSCALL1(fchdirat, 0xb, 0xb)
__TSYSCALL1(time64, 0xc, 0xc)
__TSYSCALL1(set_exception_handler, 0xd, 0xd)
__TSYSCALL1(get_exception_handler, 0xe, 0xe)
__TSYSCALL1(set_library_listdef, 0xf, 0xf)
__TSYSCALL1(debugtrap, 0x10, 0x10)
__TSYSCALL1(lfutex, 0x11, 0x11)
__TSYSCALL1(lseek64, 0x12, 0x12)
__TSYSCALL1(lfutexexpr, 0x13, 0x13)
__TSYSCALL1(lfutexlockexpr, 0x14, 0x14)
__TSYSCALL1(mktty, 0x15, 0x15)
__TSYSCALL1(raiseat, 0x16, 0x16)
__TSYSCALL1(coredump, 0x17, 0x17)
__TSYSCALL1(stime64, 0x18, 0x18)
__TSYSCALL1_UNUSED(0x8000001a, 0x19, 0x19)
__TSYSCALL1_UNUSED(0x8000001b, 0x1a, 0x1a)
__TSYSCALL1_UNUSED(0x8000001c, 0x1b, 0x1b)
__TSYSCALL1_UNUSED(0x8000001d, 0x1c, 0x1c)
__TSYSCALL1(utime64, 0x1d, 0x1d)
__TSYSCALL1_UNUSED(0x8000001f, 0x1e, 0x1e)
__TSYSCALL1_UNUSED(0x80000020, 0x1f, 0x1f)
__TSYSCALL1_UNUSED(0x80000021, 0x20, 0x20)
__TSYSCALL1_UNUSED(0x80000022, 0x21, 0x21)
__TSYSCALL1_UNUSED(0x80000023, 0x22, 0x22)
__TSYSCALL1_UNUSED(0x80000024, 0x23, 0x23)
__TSYSCALL1_UNUSED(0x80000025, 0x24, 0x24)
__TSYSCALL1_UNUSED(0x80000026, 0x25, 0x25)
__TSYSCALL1_UNUSED(0x80000027, 0x26, 0x26)
__TSYSCALL1_UNUSED(0x80000028, 0x27, 0x27)
__TSYSCALL1_UNUSED(0x80000029, 0x28, 0x28)
__TSYSCALL1_UNUSED(0x8000002a, 0x29, 0x29)
__TSYSCALL1_UNUSED(0x8000002b, 0x2a, 0x2a)
__TSYSCALL1_UNUSED(0x8000002c, 0x2b, 0x2b)
__TSYSCALL1_UNUSED(0x8000002d, 0x2c, 0x2c)
__TSYSCALL1_UNUSED(0x8000002e, 0x2d, 0x2d)
__TSYSCALL1_UNUSED(0x8000002f, 0x2e, 0x2e)
__TSYSCALL1_UNUSED(0x80000030, 0x2f, 0x2f)
__TSYSCALL1_UNUSED(0x80000031, 0x30, 0x30)
__TSYSCALL1_UNUSED(0x80000032, 0x31, 0x31)
__TSYSCALL1_UNUSED(0x80000033, 0x32, 0x32)
__TSYSCALL1_UNUSED(0x80000034, 0x33, 0x33)
__TSYSCALL1_UNUSED(0x80000035, 0x34, 0x34)
__TSYSCALL1(ioctlf, 0x35, 0x35)
__TSYSCALL1_UNUSED(0x80000037, 0x36, 0x36)
__TSYSCALL1_UNUSED(0x80000038, 0x37, 0x37)
__TSYSCALL1_UNUSED(0x80000039, 0x38, 0x38)
__TSYSCALL1_UNUSED(0x8000003a, 0x39, 0x39)
__TSYSCALL1_UNUSED(0x8000003b, 0x3a, 0x3a)
__TSYSCALL1(fsmode, 0x3b, 0x3b)
__TSYSCALL1_UNUSED(0x8000003d, 0x3c, 0x3c)
__TSYSCALL1_UNUSED(0x8000003e, 0x3d, 0x3d)
__TSYSCALL1_UNUSED(0x8000003f, 0x3e, 0x3e)
__TSYSCALL1_UNUSED(0x80000040, 0x3f, 0x3f)
__TSYSCALL1_UNUSED(0x80000041, 0x40, 0x40)
__TSYSCALL1_UNUSED(0x80000042, 0x41, 0x41)
__TSYSCALL1_UNUSED(0x80000043, 0x42, 0x42)
__TSYSCALL1_UNUSED(0x80000044, 0x43, 0x43)
__TSYSCALL1_UNUSED(0x80000045, 0x44, 0x44)
__TSYSCALL1_UNUSED(0x80000046, 0x45, 0x45)
__TSYSCALL1_UNUSED(0x80000047, 0x46, 0x46)
__TSYSCALL1_UNUSED(0x80000048, 0x47, 0x47)
__TSYSCALL1_UNUSED(0x80000049, 0x48, 0x48)
__TSYSCALL1_UNUSED(0x8000004a, 0x49, 0x49)
__TSYSCALL1_UNUSED(0x8000004b, 0x4a, 0x4a)
__TSYSCALL1_UNUSED(0x8000004c, 0x4b, 0x4b)
__TSYSCALL1_UNUSED(0x8000004d, 0x4c, 0x4c)
__TSYSCALL1(gettimeofday64, 0x4d, 0x4d)
__TSYSCALL1(settimeofday64, 0x4e, 0x4e)
__TSYSCALL1_UNUSED(0x80000050, 0x4f, 0x4f)
__TSYSCALL1_UNUSED(0x80000051, 0x50, 0x50)
__TSYSCALL1(select64, 0x51, 0x51)
__TSYSCALL1_UNUSED(0x80000053, 0x52, 0x52)
__TSYSCALL1_UNUSED(0x80000054, 0x53, 0x53)
__TSYSCALL1_UNUSED(0x80000055, 0x54, 0x54)
__TSYSCALL1(maplibrary, 0x55, 0x55)
__TSYSCALL1_UNUSED(0x80000057, 0x56, 0x56)
__TSYSCALL1_UNUSED(0x80000058, 0x57, 0x57)
__TSYSCALL1_UNUSED(0x80000059, 0x58, 0x58)
__TSYSCALL1_UNUSED(0x8000005a, 0x59, 0x59)
__TSYSCALL1_UNUSED(0x8000005b, 0x5a, 0x5a)
__TSYSCALL1_UNUSED(0x8000005c, 0x5b, 0x5b)
__TSYSCALL1_UNUSED(0x8000005d, 0x5c, 0x5c)
__TSYSCALL1_UNUSED(0x8000005e, 0x5d, 0x5d)
__TSYSCALL1_UNUSED(0x8000005f, 0x5e, 0x5e)
__TSYSCALL1_UNUSED(0x80000060, 0x5f, 0x5f)
__TSYSCALL1_UNUSED(0x80000061, 0x60, 0x60)
__TSYSCALL1_UNUSED(0x80000062, 0x61, 0x61)
__TSYSCALL1_UNUSED(0x80000063, 0x62, 0x62)
__TSYSCALL1_UNUSED(0x80000064, 0x63, 0x63)
__TSYSCALL1_UNUSED(0x80000065, 0x64, 0x64)
__TSYSCALL1_UNUSED(0x80000066, 0x65, 0x65)
__TSYSCALL1_UNUSED(0x80000067, 0x66, 0x66)
__TSYSCALL1(setitimer64, 0x67, 0x67)
__TSYSCALL1(getitimer64, 0x68, 0x68)
__TSYSCALL1_UNUSED(0x8000006a, 0x69, 0x69)
__TSYSCALL1_UNUSED(0x8000006b, 0x6a, 0x6a)
__TSYSCALL1_UNUSED(0x8000006c, 0x6b, 0x6b)
__TSYSCALL1_UNUSED(0x8000006d, 0x6c, 0x6c)
__TSYSCALL1_UNUSED(0x8000006e, 0x6d, 0x6d)
__TSYSCALL1_UNUSED(0x8000006f, 0x6e, 0x6e)
__TSYSCALL1_UNUSED(0x80000070, 0x6f, 0x6f)
__TSYSCALL1_UNUSED(0x80000071, 0x70, 0x70)
__TSYSCALL1_UNUSED(0x80000072, 0x71, 0x71)
__TSYSCALL1_UNUSED(0x80000073, 0x72, 0x72)
__TSYSCALL1_UNUSED(0x80000074, 0x73, 0x73)
__TSYSCALL1_UNUSED(0x80000075, 0x74, 0x74)
__TSYSCALL1_UNUSED(0x80000076, 0x75, 0x75)
__TSYSCALL1_UNUSED(0x80000077, 0x76, 0x76)
__TSYSCALL1_UNUSED(0x80000078, 0x77, 0x77)
__TSYSCALL1_UNUSED(0x80000079, 0x78, 0x78)
__TSYSCALL1_UNUSED(0x8000007a, 0x79, 0x79)
__TSYSCALL1_UNUSED(0x8000007b, 0x7a, 0x7a)
__TSYSCALL1_UNUSED(0x8000007c, 0x7b, 0x7b)
__TSYSCALL1_UNUSED(0x8000007d, 0x7c, 0x7c)
__TSYSCALL1_UNUSED(0x8000007e, 0x7d, 0x7d)
__TSYSCALL1_UNUSED(0x8000007f, 0x7e, 0x7e)
__TSYSCALL1_UNUSED(0x80000080, 0x7f, 0x7f)
__TSYSCALL1_UNUSED(0x80000081, 0x80, 0x80)
__TSYSCALL1_UNUSED(0x80000082, 0x81, 0x81)
__TSYSCALL1_UNUSED(0x80000083, 0x82, 0x82)
__TSYSCALL1_UNUSED(0x80000084, 0x83, 0x83)
__TSYSCALL1_UNUSED(0x80000085, 0x84, 0x84)
__TSYSCALL1_UNUSED(0x80000086, 0x85, 0x85)
__TSYSCALL1_UNUSED(0x80000087, 0x86, 0x86)
__TSYSCALL1_UNUSED(0x80000088, 0x87, 0x87)
__TSYSCALL1_UNUSED(0x80000089, 0x88, 0x88)
__TSYSCALL1_UNUSED(0x8000008a, 0x89, 0x89)
__TSYSCALL1_UNUSED(0x8000008b, 0x8a, 0x8a)
__TSYSCALL1_UNUSED(0x8000008c, 0x8b, 0x8b)
__TSYSCALL1(kreaddir, 0x8c, 0x8c)
__TSYSCALL1_UNUSED(0x8000008e, 0x8d, 0x8d)
__TSYSCALL1_UNUSED(0x8000008f, 0x8e, 0x8e)
__TSYSCALL1_UNUSED(0x80000090, 0x8f, 0x8f)
__TSYSCALL1(readvf, 0x90, 0x90)
__TSYSCALL1(writevf, 0x91, 0x91)
__TSYSCALL1_UNUSED(0x80000093, 0x92, 0x92)
__TSYSCALL1_UNUSED(0x80000094, 0x93, 0x93)
__TSYSCALL1_UNUSED(0x80000095, 0x94, 0x94)
__TSYSCALL1_UNUSED(0x80000096, 0x95, 0x95)
__TSYSCALL1_UNUSED(0x80000097, 0x96, 0x96)
__TSYSCALL1_UNUSED(0x80000098, 0x97, 0x97)
__TSYSCALL1_UNUSED(0x80000099, 0x98, 0x98)
__TSYSCALL1_UNUSED(0x8000009a, 0x99, 0x99)
__TSYSCALL1_UNUSED(0x8000009b, 0x9a, 0x9a)
__TSYSCALL1_UNUSED(0x8000009c, 0x9b, 0x9b)
__TSYSCALL1_UNUSED(0x8000009d, 0x9c, 0x9c)
__TSYSCALL1(rpc_service, 0x9d, 0x9d)
__TSYSCALL1_UNUSED(0x8000009f, 0x9e, 0x9e)
__TSYSCALL1_UNUSED(0x800000a0, 0x9f, 0x9f)
__TSYSCALL1(sched_rr_get_interval64, 0xa0, 0xa0)
__TSYSCALL1(nanosleep64, 0xa1, 0xa1)
__TSYSCALL1_UNUSED(0x800000a3, 0xa2, 0xa2)
__TSYSCALL1_UNUSED(0x800000a4, 0xa3, 0xa3)
__TSYSCALL1_UNUSED(0x800000a5, 0xa4, 0xa4)
__TSYSCALL1_UNUSED(0x800000a6, 0xa5, 0xa5)
__TSYSCALL1_UNUSED(0x800000a7, 0xa6, 0xa6)
__TSYSCALL1_UNUSED(0x800000a8, 0xa7, 0xa7)
__TSYSCALL1_UNUSED(0x800000a9, 0xa8, 0xa8)
__TSYSCALL1_UNUSED(0x800000aa, 0xa9, 0xa9)
__TSYSCALL1_UNUSED(0x800000ab, 0xaa, 0xaa)
__TSYSCALL1_UNUSED(0x800000ac, 0xab, 0xab)
__TSYSCALL1_UNUSED(0x800000ad, 0xac, 0xac)
__TSYSCALL1_UNUSED(0x800000ae, 0xad, 0xad)
__TSYSCALL1_UNUSED(0x800000af, 0xae, 0xae)
__TSYSCALL1_UNUSED(0x800000b0, 0xaf, 0xaf)
__TSYSCALL1(rt_sigtimedwait64, 0xb0, 0xb0)
__TSYSCALL1_UNUSED(0x800000b2, 0xb1, 0xb1)
__TSYSCALL1_UNUSED(0x800000b3, 0xb2, 0xb2)
__TSYSCALL1(pread64f, 0xb3, 0xb3)
__TSYSCALL1(pwrite64f, 0xb4, 0xb4)
__TSYSCALL1_UNUSED(0x800000b6, 0xb5, 0xb5)
__TSYSCALL1_UNUSED(0x800000b7, 0xb6, 0xb6)
__TSYSCALL1_UNUSED(0x800000b8, 0xb7, 0xb7)
__TSYSCALL1_UNUSED(0x800000b9, 0xb8, 0xb8)
__TSYSCALL1_UNUSED(0x800000ba, 0xb9, 0xb9)
__TSYSCALL1_UNUSED(0x800000bb, 0xba, 0xba)
__TSYSCALL1_UNUSED(0x800000bc, 0xbb, 0xbb)
__TSYSCALL1_UNUSED(0x800000bd, 0xbc, 0xbc)
__TSYSCALL1_UNUSED(0x800000be, 0xbd, 0xbd)
__TSYSCALL1_UNUSED(0x800000bf, 0xbe, 0xbe)
__TSYSCALL1_UNUSED(0x800000c0, 0xbf, 0xbf)
__TSYSCALL1_UNUSED(0x800000c1, 0xc0, 0xc0)
__TSYSCALL1_UNUSED(0x800000c2, 0xc1, 0xc1)
__TSYSCALL1(kstat, 0xc2, 0xc2)
__TSYSCALL1(klstat, 0xc3, 0xc3)
__TSYSCALL1(kfstat, 0xc4, 0xc4)
__TSYSCALL1_UNUSED(0x800000c6, 0xc5, 0xc5)
__TSYSCALL1_UNUSED(0x800000c7, 0xc6, 0xc6)
__TSYSCALL1_UNUSED(0x800000c8, 0xc7, 0xc7)
__TSYSCALL1_UNUSED(0x800000c9, 0xc8, 0xc8)
__TSYSCALL1_UNUSED(0x800000ca, 0xc9, 0xc9)
__TSYSCALL1_UNUSED(0x800000cb, 0xca, 0xca)
__TSYSCALL1_UNUSED(0x800000cc, 0xcb, 0xcb)
__TSYSCALL1_UNUSED(0x800000cd, 0xcc, 0xcc)
__TSYSCALL1_UNUSED(0x800000ce, 0xcd, 0xcd)
__TSYSCALL1_UNUSED(0x800000cf, 0xce, 0xce)
__TSYSCALL1_UNUSED(0x800000d0, 0xcf, 0xcf)
__TSYSCALL1_UNUSED(0x800000d1, 0xd0, 0xd0)
__TSYSCALL1_UNUSED(0x800000d2, 0xd1, 0xd1)
__TSYSCALL1_UNUSED(0x800000d3, 0xd2, 0xd2)
__TSYSCALL1_UNUSED(0x800000d4, 0xd3, 0xd3)
__TSYSCALL1_UNUSED(0x800000d5, 0xd4, 0xd4)
__TSYSCALL1_UNUSED(0x800000d6, 0xd5, 0xd5)
__TSYSCALL1_UNUSED(0x800000d7, 0xd6, 0xd6)
__TSYSCALL1_UNUSED(0x800000d8, 0xd7, 0xd7)
__TSYSCALL1_UNUSED(0x800000d9, 0xd8, 0xd8)
__TSYSCALL1_UNUSED(0x800000da, 0xd9, 0xd9)
__TSYSCALL1_UNUSED(0x800000db, 0xda, 0xda)
__TSYSCALL1(kreaddirf, 0xdb, 0xdb)
__TSYSCALL1_UNUSED(0x800000dd, 0xdc, 0xdc)
__TSYSCALL1_UNUSED(0x800000de, 0xdd, 0xdd)
__TSYSCALL1_UNUSED(0x800000df, 0xde, 0xde)
__TSYSCALL1_UNUSED(0x800000e0, 0xdf, 0xdf)
__TSYSCALL1_UNUSED(0x800000e1, 0xe0, 0xe0)
__TSYSCALL1_UNUSED(0x800000e2, 0xe1, 0xe1)
__TSYSCALL1_UNUSED(0x800000e3, 0xe2, 0xe2)
__TSYSCALL1_UNUSED(0x800000e4, 0xe3, 0xe3)
__TSYSCALL1_UNUSED(0x800000e5, 0xe4, 0xe4)
__TSYSCALL1_UNUSED(0x800000e6, 0xe5, 0xe5)
__TSYSCALL1_UNUSED(0x800000e7, 0xe6, 0xe6)
__TSYSCALL1_UNUSED(0x800000e8, 0xe7, 0xe7)
__TSYSCALL1_UNUSED(0x800000e9, 0xe8, 0xe8)
__TSYSCALL1_UNUSED(0x800000ea, 0xe9, 0xe9)
__TSYSCALL1_UNUSED(0x800000eb, 0xea, 0xea)
__TSYSCALL1_UNUSED(0x800000ec, 0xeb, 0xeb)
__TSYSCALL1_UNUSED(0x800000ed, 0xec, 0xec)
__TSYSCALL1_UNUSED(0x800000ee, 0xed, 0xed)
__TSYSCALL1_UNUSED(0x800000ef, 0xee, 0xee)
__TSYSCALL1_UNUSED(0x800000f0, 0xef, 0xef)
__TSYSCALL1_UNUSED(0x800000f1, 0xf0, 0xf0)
__TSYSCALL1_UNUSED(0x800000f2, 0xf1, 0xf1)
__TSYSCALL1_UNUSED(0x800000f3, 0xf2, 0xf2)
__TSYSCALL1_UNUSED(0x800000f4, 0xf3, 0xf3)
__TSYSCALL1_UNUSED(0x800000f5, 0xf4, 0xf4)
__TSYSCALL1_UNUSED(0x800000f6, 0xf5, 0xf5)
__TSYSCALL1_UNUSED(0x800000f7, 0xf6, 0xf6)
__TSYSCALL1_UNUSED(0x800000f8, 0xf7, 0xf7)
__TSYSCALL1_UNUSED(0x800000f9, 0xf8, 0xf8)
__TSYSCALL1_UNUSED(0x800000fa, 0xf9, 0xf9)
__TSYSCALL1_UNUSED(0x800000fb, 0xfa, 0xfa)
__TSYSCALL1_UNUSED(0x800000fc, 0xfb, 0xfb)
__TSYSCALL1_UNUSED(0x800000fd, 0xfc, 0xfc)
__TSYSCALL1_UNUSED(0x800000fe, 0xfd, 0xfd)
__TSYSCALL1_UNUSED(0x800000ff, 0xfe, 0xfe)
__TSYSCALL1_UNUSED(0x80000100, 0xff, 0xff)
__TSYSCALL1_UNUSED(0x80000101, 0x100, 0x100)
__TSYSCALL1_UNUSED(0x80000102, 0x101, 0x101)
__TSYSCALL1_UNUSED(0x80000103, 0x102, 0x102)
__TSYSCALL1(timer_settime64, 0x103, 0x103)
__TSYSCALL1(timer_gettime64, 0x104, 0x104)
__TSYSCALL1_UNUSED(0x80000106, 0x105, 0x105)
__TSYSCALL1_UNUSED(0x80000107, 0x106, 0x106)
__TSYSCALL1(clock_settime64, 0x107, 0x107)
__TSYSCALL1(clock_gettime64, 0x108, 0x108)
__TSYSCALL1(clock_getres64, 0x109, 0x109)
__TSYSCALL1(clock_nanosleep64, 0x10a, 0x10a)
__TSYSCALL1_UNUSED(0x8000010c, 0x10b, 0x10b)
__TSYSCALL1_UNUSED(0x8000010d, 0x10c, 0x10c)
__TSYSCALL1_UNUSED(0x8000010e, 0x10d, 0x10d)
__TSYSCALL1(utimes64, 0x10e, 0x10e)
__TSYSCALL1_UNUSED(0x80000110, 0x10f, 0x10f)
__TSYSCALL1_UNUSED(0x80000111, 0x110, 0x110)
__TSYSCALL1_UNUSED(0x80000112, 0x111, 0x111)
__TSYSCALL1_UNUSED(0x80000113, 0x112, 0x112)
__TSYSCALL1_UNUSED(0x80000114, 0x113, 0x113)
__TSYSCALL1_UNUSED(0x80000115, 0x114, 0x114)
__TSYSCALL1_UNUSED(0x80000116, 0x115, 0x115)
__TSYSCALL1(mq_timedsend64, 0x116, 0x116)
__TSYSCALL1(mq_timedreceive64, 0x117, 0x117)
__TSYSCALL1_UNUSED(0x80000119, 0x118, 0x118)
__TSYSCALL1_UNUSED(0x8000011a, 0x119, 0x119)
__TSYSCALL1_UNUSED(0x8000011b, 0x11a, 0x11a)
__TSYSCALL1_UNUSED(0x8000011c, 0x11b, 0x11b)
__TSYSCALL1_UNUSED(0x8000011d, 0x11c, 0x11c)
__TSYSCALL1_UNUSED(0x8000011e, 0x11d, 0x11d)
__TSYSCALL1_UNUSED(0x8000011f, 0x11e, 0x11e)
__TSYSCALL1_UNUSED(0x80000120, 0x11f, 0x11f)
__TSYSCALL1_UNUSED(0x80000121, 0x120, 0x120)
__TSYSCALL1_UNUSED(0x80000122, 0x121, 0x121)
__TSYSCALL1_UNUSED(0x80000123, 0x122, 0x122)
__TSYSCALL1_UNUSED(0x80000124, 0x123, 0x123)
__TSYSCALL1_UNUSED(0x80000125, 0x124, 0x124)
__TSYSCALL1_UNUSED(0x80000126, 0x125, 0x125)
__TSYSCALL1_UNUSED(0x80000127, 0x126, 0x126)
__TSYSCALL1(fmkdirat, 0x127, 0x127)
__TSYSCALL1(fmknodat, 0x128, 0x128)
__TSYSCALL1_UNUSED(0x8000012a, 0x129, 0x129)
__TSYSCALL1(futimesat64, 0x12a, 0x12a)
__TSYSCALL1(kfstatat, 0x12b, 0x12b)
__TSYSCALL1_UNUSED(0x8000012d, 0x12c, 0x12c)
__TSYSCALL1(frenameat, 0x12d, 0x12d)
__TSYSCALL1_UNUSED(0x8000012f, 0x12e, 0x12e)
__TSYSCALL1(fsymlinkat, 0x12f, 0x12f)
__TSYSCALL1(freadlinkat, 0x130, 0x130)
__TSYSCALL1_UNUSED(0x80000132, 0x131, 0x131)
__TSYSCALL1_UNUSED(0x80000133, 0x132, 0x132)
__TSYSCALL1(pselect6_64, 0x133, 0x133)
__TSYSCALL1(ppoll64, 0x134, 0x134)
__TSYSCALL1_UNUSED(0x80000136, 0x135, 0x135)
__TSYSCALL1_UNUSED(0x80000137, 0x136, 0x136)
__TSYSCALL1_UNUSED(0x80000138, 0x137, 0x137)
__TSYSCALL1_UNUSED(0x80000139, 0x138, 0x138)
__TSYSCALL1_UNUSED(0x8000013a, 0x139, 0x139)
__TSYSCALL1_UNUSED(0x8000013b, 0x13a, 0x13a)
__TSYSCALL1_UNUSED(0x8000013c, 0x13b, 0x13b)
__TSYSCALL1_UNUSED(0x8000013d, 0x13c, 0x13c)
__TSYSCALL1_UNUSED(0x8000013e, 0x13d, 0x13d)
__TSYSCALL1_UNUSED(0x8000013f, 0x13e, 0x13e)
__TSYSCALL1(utimensat64, 0x13f, 0x13f)
__TSYSCALL1_UNUSED(0x80000141, 0x140, 0x140)
__TSYSCALL1_UNUSED(0x80000142, 0x141, 0x141)
__TSYSCALL1_UNUSED(0x80000143, 0x142, 0x142)
__TSYSCALL1(fallocate64, 0x143, 0x143)
__TSYSCALL1(timerfd_settime64, 0x144, 0x144)
__TSYSCALL1(timerfd_gettime64, 0x145, 0x145)
__TSYSCALL1_UNUSED(0x80000147, 0x146, 0x146)
__TSYSCALL1_UNUSED(0x80000148, 0x147, 0x147)
__TSYSCALL1_UNUSED(0x80000149, 0x148, 0x148)
__TSYSCALL1_UNUSED(0x8000014a, 0x149, 0x149)
__TSYSCALL1_UNUSED(0x8000014b, 0x14a, 0x14a)
__TSYSCALL1_UNUSED(0x8000014c, 0x14b, 0x14b)
__TSYSCALL1(preadvf, 0x14c, 0x14c)
__TSYSCALL1(pwritevf, 0x14d, 0x14d)
__TSYSCALL1_UNUSED(0x8000014f, 0x14e, 0x14e)
__TSYSCALL1_UNUSED(0x80000150, 0x14f, 0x14f)
__TSYSCALL1(recvmmsg64, 0x150, 0x150)
__TSYSCALL1_TABLE_END(0x80000001, 0x80000151, 0x151, 0x80000001, 0x80000151, 0x151)

#undef __TSYSCALL1_TABLE_END
#undef __TSYSCALL1_TABLE_BEGIN
#undef __TSYSCALL1_UNUSED_TRAILING
#undef __TSYSCALL1_UNUSED_LEADING
#undef __TSYSCALL1_UNUSED
#undef __TSYSCALL1
#undef __TSYSCALL0_TABLE_END
#undef __TSYSCALL0_TABLE_BEGIN
#undef __TSYSCALL0_UNUSED_TRAILING
#undef __TSYSCALL0_UNUSED_LEADING
#undef __TSYSCALL0_UNUSED
#undef __TSYSCALL0
#undef __TSYSCALL_TABLE_END
#undef __TSYSCALL_TABLE_BEGIN
#undef __TSYSCALL_UNUSED_TRAILING
#undef __TSYSCALL_UNUSED_LEADING
#undef __TSYSCALL_UNUSED
#undef __TSYSCALL
#undef __SYSCALL_UNUSED
#undef __SYSCALL
