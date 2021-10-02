/* HASH CRC-32:0xcf9d3c71 */
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
#ifndef __NR3264COMPAT__sysctl
#define __NR3264COMPAT__sysctl                  1(_sysctl)
#define __NR3264COMPAT_accept4                  1(accept4)
#define __NR3264COMPAT_access                   1(access)
#define __NR3264COMPAT_acct                     1(acct)
#define __NR3264COMPAT_add_key                  1(add_key)
#define __NR3264COMPAT_afs_syscall              1(afs_syscall)
#define __NR3264COMPAT_alarm                    1(alarm)
#define __NR3264COMPAT_arch_prctl               1(arch_prctl)
#define __NR3264COMPAT_bind                     1(bind)
#define __NR3264COMPAT_bpf                      1(bpf)
#define __NR3264COMPAT_brk                      1(brk)
#define __NR3264COMPAT_capget                   1(capget)
#define __NR3264COMPAT_capset                   1(capset)
#define __NR3264COMPAT_chdir                    1(chdir)
#define __NR3264COMPAT_chmod                    1(chmod)
#define __NR3264COMPAT_chown                    2(chown,chown32)
#define __NR3264COMPAT_chroot                   1(chroot)
#define __NR3264COMPAT_clock_adjtime            1(clock_adjtime)
#define __NR3264COMPAT_clone3                   1(clone3)
#define __NR3264COMPAT_close                    1(close)
#define __NR3264COMPAT_close_range              1(close_range)
#define __NR3264COMPAT_connect                  1(connect)
#define __NR3264COMPAT_copy_file_range          1(copy_file_range)
#define __NR3264COMPAT_creat                    1(creat)
#define __NR3264COMPAT_create_module            1(create_module)
#define __NR3264COMPAT_delete_module            1(delete_module)
#define __NR3264COMPAT_detach                   1(detach)
#define __NR3264COMPAT_dup                      1(dup)
#define __NR3264COMPAT_dup2                     1(dup2)
#define __NR3264COMPAT_dup3                     1(dup3)
#define __NR3264COMPAT_epoll_create             1(epoll_create)
#define __NR3264COMPAT_epoll_create1            1(epoll_create1)
#define __NR3264COMPAT_epoll_ctl                1(epoll_ctl)
#define __NR3264COMPAT_epoll_pwait              1(epoll_pwait)
#define __NR3264COMPAT_epoll_wait               1(epoll_wait)
#define __NR3264COMPAT_eventfd                  1(eventfd)
#define __NR3264COMPAT_eventfd2                 1(eventfd2)
#define __NR3264COMPAT_exit                     1(exit)
#define __NR3264COMPAT_exit_group               1(exit_group)
#define __NR3264COMPAT_faccessat                1(faccessat)
#define __NR3264COMPAT_faccessat2               1(faccessat2)
#define __NR3264COMPAT_fadvise64                1(fadvise64)
#define __NR3264COMPAT_fallocate                2(fallocate,fallocate64)
#define __NR3264COMPAT_fanotify_init            1(fanotify_init)
#define __NR3264COMPAT_fanotify_mark            1(fanotify_mark)
#define __NR3264COMPAT_fchdir                   1(fchdir)
#define __NR3264COMPAT_fchdirat                 1(fchdirat)
#define __NR3264COMPAT_fchmod                   1(fchmod)
#define __NR3264COMPAT_fchmodat                 1(fchmodat)
#define __NR3264COMPAT_fchown                   2(fchown,fchown32)
#define __NR3264COMPAT_fchownat                 1(fchownat)
#define __NR3264COMPAT_fcntl                    1(fcntl)
#define __NR3264COMPAT_fdatasync                1(fdatasync)
#define __NR3264COMPAT_fgetxattr                1(fgetxattr)
#define __NR3264COMPAT_finit_module             1(finit_module)
#define __NR3264COMPAT_flistxattr               1(flistxattr)
#define __NR3264COMPAT_flock                    1(flock)
#define __NR3264COMPAT_fmkdirat                 1(fmkdirat)
#define __NR3264COMPAT_fmknodat                 1(fmknodat)
#define __NR3264COMPAT_fork                     1(fork)
#define __NR3264COMPAT_freadlinkat              1(freadlinkat)
#define __NR3264COMPAT_frealpath4               1(frealpath4)
#define __NR3264COMPAT_frealpathat              1(frealpathat)
#define __NR3264COMPAT_fremovexattr             1(fremovexattr)
#define __NR3264COMPAT_frenameat                1(frenameat)
#define __NR3264COMPAT_fsconfig                 1(fsconfig)
#define __NR3264COMPAT_fsetxattr                1(fsetxattr)
#define __NR3264COMPAT_fsmode                   1(fsmode)
#define __NR3264COMPAT_fsmount                  1(fsmount)
#define __NR3264COMPAT_fsopen                   1(fsopen)
#define __NR3264COMPAT_fspick                   1(fspick)
#define __NR3264COMPAT_fsymlinkat               1(fsymlinkat)
#define __NR3264COMPAT_fsync                    1(fsync)
#define __NR3264COMPAT_ftruncate                2(ftruncate,ftruncate64)
#define __NR3264COMPAT_get_kernel_syms          1(get_kernel_syms)
#define __NR3264COMPAT_get_mempolicy            1(get_mempolicy)
#define __NR3264COMPAT_get_robust_list          1(get_robust_list)
#define __NR3264COMPAT_get_thread_area          1(get_thread_area)
#define __NR3264COMPAT_getcwd                   1(getcwd)
#define __NR3264COMPAT_getdents64               1(getdents64)
#define __NR3264COMPAT_getdrives                1(getdrives)
#define __NR3264COMPAT_getegid                  2(getegid,getegid32)
#define __NR3264COMPAT_geteuid                  2(geteuid,geteuid32)
#define __NR3264COMPAT_getgid                   2(getgid,getgid32)
#define __NR3264COMPAT_getgroups                1(getgroups32)
#define __NR3264COMPAT_getpeername              1(getpeername)
#define __NR3264COMPAT_getpgid                  1(getpgid)
#define __NR3264COMPAT_getpgrp                  1(getpgrp)
#define __NR3264COMPAT_getpid                   1(getpid)
#define __NR3264COMPAT_getpmsg                  1(getpmsg)
#define __NR3264COMPAT_getppid                  1(getppid)
#define __NR3264COMPAT_getpriority              1(getpriority)
#define __NR3264COMPAT_getrandom                1(getrandom)
#define __NR3264COMPAT_getresgid                1(getresgid32)
#define __NR3264COMPAT_getresuid                1(getresuid32)
#define __NR3264COMPAT_getsid                   1(getsid)
#define __NR3264COMPAT_getsockname              1(getsockname)
#define __NR3264COMPAT_getsockopt               1(getsockopt)
#define __NR3264COMPAT_gettid                   1(gettid)
#define __NR3264COMPAT_getuid                   2(getuid,getuid32)
#define __NR3264COMPAT_getxattr                 1(getxattr)
#define __NR3264COMPAT_hop                      1(hop)
#define __NR3264COMPAT_hopf                     1(hopf)
#define __NR3264COMPAT_init_module              1(init_module)
#define __NR3264COMPAT_inotify_add_watch        1(inotify_add_watch)
#define __NR3264COMPAT_inotify_init             1(inotify_init)
#define __NR3264COMPAT_inotify_init1            1(inotify_init1)
#define __NR3264COMPAT_inotify_rm_watch         1(inotify_rm_watch)
#define __NR3264COMPAT_io_cancel                1(io_cancel)
#define __NR3264COMPAT_io_destroy               1(io_destroy)
#define __NR3264COMPAT_io_getevents             1(io_getevents)
#define __NR3264COMPAT_io_pgetevents            1(io_pgetevents)
#define __NR3264COMPAT_io_setup                 1(io_setup)
#define __NR3264COMPAT_io_submit                1(io_submit)
#define __NR3264COMPAT_io_uring_enter           1(io_uring_enter)
#define __NR3264COMPAT_io_uring_register        1(io_uring_register)
#define __NR3264COMPAT_io_uring_setup           1(io_uring_setup)
#define __NR3264COMPAT_ioctl                    1(ioctl)
#define __NR3264COMPAT_ioctlf                   1(ioctlf)
#define __NR3264COMPAT_ioperm                   1(ioperm)
#define __NR3264COMPAT_iopl                     1(iopl)
#define __NR3264COMPAT_ioprio_get               1(ioprio_get)
#define __NR3264COMPAT_ioprio_set               1(ioprio_set)
#define __NR3264COMPAT_kcmp                     1(kcmp)
#define __NR3264COMPAT_kexec_load               1(kexec_load)
#define __NR3264COMPAT_keyctl                   1(keyctl)
#define __NR3264COMPAT_kill                     1(kill)
#define __NR3264COMPAT_kreaddir                 1(kreaddir)
#define __NR3264COMPAT_kreaddirf                1(kreaddirf)
#define __NR3264COMPAT_ksysctl                  1(ksysctl)
#define __NR3264COMPAT_lchown                   2(lchown,lchown32)
#define __NR3264COMPAT_lgetxattr                1(lgetxattr)
#define __NR3264COMPAT_link                     1(link)
#define __NR3264COMPAT_linkat                   1(linkat)
#define __NR3264COMPAT_listen                   1(listen)
#define __NR3264COMPAT_listxattr                1(listxattr)
#define __NR3264COMPAT_llistxattr               1(llistxattr)
#define __NR3264COMPAT_lookup_dcookie           1(lookup_dcookie)
#define __NR3264COMPAT_lremovexattr             1(lremovexattr)
#define __NR3264COMPAT_lseek                    2(lseek,lseek64)
#define __NR3264COMPAT_lsetxattr                1(lsetxattr)
#define __NR3264COMPAT_madvise                  1(madvise)
#define __NR3264COMPAT_mbind                    1(mbind)
#define __NR3264COMPAT_membarrier               1(membarrier)
#define __NR3264COMPAT_memfd_create             1(memfd_create)
#define __NR3264COMPAT_migrate_pages            1(migrate_pages)
#define __NR3264COMPAT_mincore                  1(mincore)
#define __NR3264COMPAT_mkdir                    1(mkdir)
#define __NR3264COMPAT_mkdirat                  1(mkdirat)
#define __NR3264COMPAT_mknod                    1(mknod)
#define __NR3264COMPAT_mknodat                  1(mknodat)
#define __NR3264COMPAT_mktty                    1(mktty)
#define __NR3264COMPAT_mlock                    1(mlock)
#define __NR3264COMPAT_mlock2                   1(mlock2)
#define __NR3264COMPAT_mlockall                 1(mlockall)
#define __NR3264COMPAT_mmap                     1(mmap)
#define __NR3264COMPAT_modify_ldt               1(modify_ldt)
#define __NR3264COMPAT_mount                    1(mount)
#define __NR3264COMPAT_move_mount               1(move_mount)
#define __NR3264COMPAT_move_pages               1(move_pages)
#define __NR3264COMPAT_mprotect                 1(mprotect)
#define __NR3264COMPAT_mq_open                  1(mq_open)
#define __NR3264COMPAT_mq_unlink                1(mq_unlink)
#define __NR3264COMPAT_mremap                   1(mremap)
#define __NR3264COMPAT_msgctl                   1(msgctl)
#define __NR3264COMPAT_msgget                   1(msgget)
#define __NR3264COMPAT_msgrcv                   1(msgrcv)
#define __NR3264COMPAT_msgsnd                   1(msgsnd)
#define __NR3264COMPAT_msync                    1(msync)
#define __NR3264COMPAT_munlock                  1(munlock)
#define __NR3264COMPAT_munlockall               1(munlockall)
#define __NR3264COMPAT_munmap                   1(munmap)
#define __NR3264COMPAT_nfsservctl               1(nfsservctl)
#define __NR3264COMPAT_open                     1(open)
#define __NR3264COMPAT_open_tree                1(open_tree)
#define __NR3264COMPAT_openat                   1(openat)
#define __NR3264COMPAT_openat2                  1(openat2)
#define __NR3264COMPAT_openpty                  1(openpty)
#define __NR3264COMPAT_pause                    1(pause)
#define __NR3264COMPAT_perf_event_open          1(perf_event_open)
#define __NR3264COMPAT_personality              1(personality)
#define __NR3264COMPAT_pidfd_getfd              1(pidfd_getfd)
#define __NR3264COMPAT_pidfd_open               1(pidfd_open)
#define __NR3264COMPAT_pipe                     1(pipe)
#define __NR3264COMPAT_pipe2                    1(pipe2)
#define __NR3264COMPAT_pivot_root               1(pivot_root)
#define __NR3264COMPAT_pkey_alloc               1(pkey_alloc)
#define __NR3264COMPAT_pkey_free                1(pkey_free)
#define __NR3264COMPAT_pkey_mprotect            1(pkey_mprotect)
#define __NR3264COMPAT_poll                     1(poll)
#define __NR3264COMPAT_prctl                    1(prctl)
#define __NR3264COMPAT_pread64                  1(pread64)
#define __NR3264COMPAT_pread64f                 1(pread64f)
#define __NR3264COMPAT_preadv2                  1(preadv2)
#define __NR3264COMPAT_ptrace                   1(ptrace)
#define __NR3264COMPAT_putpmsg                  1(putpmsg)
#define __NR3264COMPAT_pwrite64                 1(pwrite64)
#define __NR3264COMPAT_pwrite64f                1(pwrite64f)
#define __NR3264COMPAT_pwritev2                 1(pwritev2)
#define __NR3264COMPAT_query_module             1(query_module)
#define __NR3264COMPAT_quotactl                 1(quotactl)
#define __NR3264COMPAT_read                     1(read)
#define __NR3264COMPAT_readahead                1(readahead)
#define __NR3264COMPAT_readf                    1(readf)
#define __NR3264COMPAT_readlink                 1(readlink)
#define __NR3264COMPAT_readlinkat               1(readlinkat)
#define __NR3264COMPAT_reboot                   1(reboot)
#define __NR3264COMPAT_recvfrom                 1(recvfrom)
#define __NR3264COMPAT_remap_file_pages         1(remap_file_pages)
#define __NR3264COMPAT_removexattr              1(removexattr)
#define __NR3264COMPAT_rename                   1(rename)
#define __NR3264COMPAT_renameat                 1(renameat)
#define __NR3264COMPAT_renameat2                1(renameat2)
#define __NR3264COMPAT_request_key              1(request_key)
#define __NR3264COMPAT_restart_syscall          1(restart_syscall)
#define __NR3264COMPAT_rmdir                    1(rmdir)
#define __NR3264COMPAT_rpc_serve                1(rpc_serve)
#define __NR3264COMPAT_rseq                     1(rseq)
#define __NR3264COMPAT_rt_sigpending            1(rt_sigpending)
#define __NR3264COMPAT_rt_sigprocmask           1(rt_sigprocmask)
#define __NR3264COMPAT_rt_sigsuspend            1(rt_sigsuspend)
#define __NR3264COMPAT_rtm_abort                1(rtm_abort)
#define __NR3264COMPAT_rtm_begin                1(rtm_begin)
#define __NR3264COMPAT_rtm_end                  1(rtm_end)
#define __NR3264COMPAT_rtm_test                 1(rtm_test)
#define __NR3264COMPAT_sched_get_priority_max   1(sched_get_priority_max)
#define __NR3264COMPAT_sched_get_priority_min   1(sched_get_priority_min)
#define __NR3264COMPAT_sched_getattr            1(sched_getattr)
#define __NR3264COMPAT_sched_getscheduler       1(sched_getscheduler)
#define __NR3264COMPAT_sched_setattr            1(sched_setattr)
#define __NR3264COMPAT_sched_yield              1(sched_yield)
#define __NR3264COMPAT_seccomp                  1(seccomp)
#define __NR3264COMPAT_semctl                   1(semctl)
#define __NR3264COMPAT_semget                   1(semget)
#define __NR3264COMPAT_sendfile                 1(sendfile64)
#define __NR3264COMPAT_sendto                   1(sendto)
#define __NR3264COMPAT_set_exception_handler    1(set_exception_handler)
#define __NR3264COMPAT_set_mempolicy            1(set_mempolicy)
#define __NR3264COMPAT_set_robust_list          1(set_robust_list)
#define __NR3264COMPAT_set_thread_area          1(set_thread_area)
#define __NR3264COMPAT_set_tid_address          1(set_tid_address)
#define __NR3264COMPAT_set_userprocmask_address 1(set_userprocmask_address)
#define __NR3264COMPAT_setdomainname            1(setdomainname)
#define __NR3264COMPAT_setfsgid                 2(setfsgid,setfsgid32)
#define __NR3264COMPAT_setfsuid                 2(setfsuid,setfsuid32)
#define __NR3264COMPAT_setgid                   2(setgid,setgid32)
#define __NR3264COMPAT_setgroups                1(setgroups32)
#define __NR3264COMPAT_sethostname              1(sethostname)
#define __NR3264COMPAT_setns                    1(setns)
#define __NR3264COMPAT_setpgid                  1(setpgid)
#define __NR3264COMPAT_setpriority              1(setpriority)
#define __NR3264COMPAT_setregid                 2(setregid,setregid32)
#define __NR3264COMPAT_setresgid                2(setresgid,setresgid32)
#define __NR3264COMPAT_setresuid                2(setresuid,setresuid32)
#define __NR3264COMPAT_setreuid                 2(setreuid,setreuid32)
#define __NR3264COMPAT_setsid                   1(setsid)
#define __NR3264COMPAT_setsockopt               1(setsockopt)
#define __NR3264COMPAT_setuid                   2(setuid,setuid32)
#define __NR3264COMPAT_setxattr                 1(setxattr)
#define __NR3264COMPAT_shmat                    1(shmat)
#define __NR3264COMPAT_shmdt                    1(shmdt)
#define __NR3264COMPAT_shmget                   1(shmget)
#define __NR3264COMPAT_shutdown                 1(shutdown)
#define __NR3264COMPAT_signalfd                 1(signalfd)
#define __NR3264COMPAT_signalfd4                1(signalfd4)
#define __NR3264COMPAT_socket                   1(socket)
#define __NR3264COMPAT_socketpair               1(socketpair)
#define __NR3264COMPAT_splice                   1(splice)
#define __NR3264COMPAT_statx                    1(statx)
#define __NR3264COMPAT_swapoff                  1(swapoff)
#define __NR3264COMPAT_swapon                   1(swapon)
#define __NR3264COMPAT_symlink                  1(symlink)
#define __NR3264COMPAT_symlinkat                1(symlinkat)
#define __NR3264COMPAT_sync                     1(sync)
#define __NR3264COMPAT_sync_file_range          1(sync_file_range)
#define __NR3264COMPAT_syncfs                   1(syncfs)
#define __NR3264COMPAT_sysfs                    1(sysfs)
#define __NR3264COMPAT_syslog                   1(syslog)
#define __NR3264COMPAT_tee                      1(tee)
#define __NR3264COMPAT_tgkill                   1(tgkill)
#define __NR3264COMPAT_time                     1(time64)
#define __NR3264COMPAT_timer_delete             1(timer_delete)
#define __NR3264COMPAT_timer_getoverrun         1(timer_getoverrun)
#define __NR3264COMPAT_timerfd_create           1(timerfd_create)
#define __NR3264COMPAT_tkill                    1(tkill)
#define __NR3264COMPAT_truncate                 2(truncate,truncate64)
#define __NR3264COMPAT_umask                    1(umask)
#define __NR3264COMPAT_umount2                  1(umount2)
#define __NR3264COMPAT_uname                    1(uname)
#define __NR3264COMPAT_unlink                   1(unlink)
#define __NR3264COMPAT_unlinkat                 1(unlinkat)
#define __NR3264COMPAT_unshare                  1(unshare)
#define __NR3264COMPAT_uselib                   1(uselib)
#define __NR3264COMPAT_userfaultfd              1(userfaultfd)
#define __NR3264COMPAT_userviofd                1(userviofd)
#define __NR3264COMPAT_utime                    1(utime64)
#define __NR3264COMPAT_vfork                    1(vfork)
#define __NR3264COMPAT_vhangup                  1(vhangup)
#define __NR3264COMPAT_vserver                  1(vserver)
#define __NR3264COMPAT_write                    1(write)
#define __NR3264COMPAT_writef                   1(writef)
#endif /* !__NR3264COMPAT__sysctl */
