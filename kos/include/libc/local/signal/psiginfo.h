/* HASH CRC-32:0x4948a387 */
/* Copyright (c) 2019-2023 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2023 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_psiginfo_defined
#define __local_psiginfo_defined
#include <__crt.h>
#include <libc/template/stdstreams.h>
#if defined(__LOCAL_stderr) && (defined(__CRT_HAVE_fprintf_unlocked) || defined(__CRT_HAVE_fprintf_s) || defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__filbuf) && !defined(__CRT_HAVE___uflow) && !defined(__CRT_HAVE___underflow) && !defined(__CRT_HAVE___srget)))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__filbuf) && !defined(__CRT_HAVE___uflow) && !defined(__CRT_HAVE___underflow) && !defined(__CRT_HAVE___srget)))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__filbuf) && !defined(__CRT_HAVE___uflow) && !defined(__CRT_HAVE___underflow) && !defined(__CRT_HAVE___srget)))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow) || defined(__CRT_HAVE___srget))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock))
#include <bits/os/siginfo.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_flockfile_defined
#define __local___localdep_flockfile_defined
#ifdef __CRT_HAVE_flockfile
__CREDIRECT_VOID(__ATTR_INOUT(1),__NOTHROW_RPC,__localdep_flockfile,(__FILE *__restrict __stream),flockfile,(__stream))
#elif defined(__CRT_HAVE__lock_file)
__CREDIRECT_VOID(__ATTR_INOUT(1),__NOTHROW_RPC,__localdep_flockfile,(__FILE *__restrict __stream),_lock_file,(__stream))
#elif defined(__CRT_HAVE__IO_flockfile)
__CREDIRECT_VOID(__ATTR_INOUT(1),__NOTHROW_RPC,__localdep_flockfile,(__FILE *__restrict __stream),_IO_flockfile,(__stream))
#else /* ... */
#undef __local___localdep_flockfile_defined
#endif /* !... */
#endif /* !__local___localdep_flockfile_defined */
#ifndef __local___localdep_fprintf_unlocked_defined
#define __local___localdep_fprintf_unlocked_defined
#if __has_builtin(__builtin_fprintf_unlocked) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_fprintf_unlocked) && __has_builtin(__builtin_va_arg_pack)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_PRINTF(2, 3),__STDC_INT_AS_SSIZE_T,__NOTHROW_CB_NCX,__localdep_fprintf_unlocked,(__FILE *__restrict __stream, char const *__restrict __format, ...),fprintf_unlocked,{ return __builtin_fprintf_unlocked(__stream, __format, __builtin_va_arg_pack()); })
#elif defined(__CRT_HAVE_fprintf_unlocked)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_PRINTF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_CB_NCX(__VLIBCCALL __localdep_fprintf_unlocked)(__FILE *__restrict __stream, char const *__restrict __format, ...) __CASMNAME("fprintf_unlocked");
#elif defined(__CRT_HAVE_fprintf_s)
__NAMESPACE_LOCAL_END
#include <features.h>
__NAMESPACE_LOCAL_BEGIN
__LIBC __ATTR_IN(2) __ATTR_INOUT(1) __ATTR_LIBC_PRINTF(2, 3) __STDC_INT_AS_SSIZE_T __NOTHROW_CB_NCX(__VLIBCCALL __localdep_fprintf_unlocked)(__FILE *__restrict __stream, char const *__restrict __format, ...) __CASMNAME("fprintf_s");
#elif defined(__CRT_HAVE_vfprintf_unlocked) || defined(__CRT_HAVE_vfprintf) || defined(__CRT_HAVE_vfprintf_s) || defined(__CRT_HAVE__IO_vfprintf) || defined(__CRT_HAVE_file_printer_unlocked) || defined(__CRT_HAVE_file_printer) || defined(__CRT_HAVE_fwrite_unlocked) || defined(__CRT_HAVE__fwrite_nolock) || defined(__CRT_HAVE_fwrite) || defined(__CRT_HAVE__IO_fwrite) || defined(__CRT_HAVE_fwrite_s) || defined(__CRT_HAVE_fgetc_unlocked) || defined(__CRT_HAVE_getc_unlocked) || defined(__CRT_HAVE__getc_nolock) || defined(__CRT_HAVE__fgetc_nolock) || (defined(__CRT_HAVE_getc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__filbuf) && !defined(__CRT_HAVE___uflow) && !defined(__CRT_HAVE___underflow) && !defined(__CRT_HAVE___srget)))) || (defined(__CRT_HAVE_fgetc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__filbuf) && !defined(__CRT_HAVE___uflow) && !defined(__CRT_HAVE___underflow) && !defined(__CRT_HAVE___srget)))) || (defined(__CRT_HAVE__IO_getc) && (!defined(__CRT_DOS) || (!defined(__CRT_HAVE__filbuf) && !defined(__CRT_HAVE___uflow) && !defined(__CRT_HAVE___underflow) && !defined(__CRT_HAVE___srget)))) || (defined(__CRT_DOS) && (defined(__CRT_HAVE__filbuf) || defined(__CRT_HAVE___uflow) || defined(__CRT_HAVE___underflow) || defined(__CRT_HAVE___srget))) || defined(__CRT_HAVE_fread) || defined(__CRT_HAVE__IO_fread) || defined(__CRT_HAVE_fread_unlocked) || defined(__CRT_HAVE__fread_nolock)
__NAMESPACE_LOCAL_END
#include <libc/local/stdio/fprintf_unlocked.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_fprintf_unlocked __LIBC_LOCAL_NAME(fprintf_unlocked)
#else /* ... */
#undef __local___localdep_fprintf_unlocked_defined
#endif /* !... */
#endif /* !__local___localdep_fprintf_unlocked_defined */
#ifndef __local___localdep_funlockfile_defined
#define __local___localdep_funlockfile_defined
#ifdef __CRT_HAVE_funlockfile
__CREDIRECT_VOID(__ATTR_INOUT(1),__NOTHROW_NCX,__localdep_funlockfile,(__FILE *__restrict __stream),funlockfile,(__stream))
#elif defined(__CRT_HAVE__unlock_file)
__CREDIRECT_VOID(__ATTR_INOUT(1),__NOTHROW_NCX,__localdep_funlockfile,(__FILE *__restrict __stream),_unlock_file,(__stream))
#elif defined(__CRT_HAVE__IO_funlockfile)
__CREDIRECT_VOID(__ATTR_INOUT(1),__NOTHROW_NCX,__localdep_funlockfile,(__FILE *__restrict __stream),_IO_funlockfile,(__stream))
#else /* ... */
#undef __local___localdep_funlockfile_defined
#endif /* !... */
#endif /* !__local___localdep_funlockfile_defined */
#ifndef __local___localdep_sigabbrev_np_defined
#define __local___localdep_sigabbrev_np_defined
#ifdef __CRT_HAVE_sigabbrev_np
__NAMESPACE_LOCAL_END
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,char const *,__NOTHROW,__localdep_sigabbrev_np,(__signo_t __signo),sigabbrev_np,(__signo))
#elif defined(__CRT_HAVE_signalname)
__NAMESPACE_LOCAL_END
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,char const *,__NOTHROW,__localdep_sigabbrev_np,(__signo_t __signo),signalname,(__signo))
#elif defined(__CRT_HAVE_strsigno)
__NAMESPACE_LOCAL_END
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,char const *,__NOTHROW,__localdep_sigabbrev_np,(__signo_t __signo),strsigno,(__signo))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/string/sigabbrev_np.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_sigabbrev_np __LIBC_LOCAL_NAME(sigabbrev_np)
#endif /* !... */
#endif /* !__local___localdep_sigabbrev_np_defined */
#ifndef __local___localdep_sigcodedesc_np_defined
#define __local___localdep_sigcodedesc_np_defined
#ifdef __CRT_HAVE_sigcodedesc_np
__NAMESPACE_LOCAL_END
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,char const *,__NOTHROW,__localdep_sigcodedesc_np,(__signo_t __signo, int __code),sigcodedesc_np,(__signo,__code))
#else /* __CRT_HAVE_sigcodedesc_np */
__NAMESPACE_LOCAL_END
#include <libc/local/signal/sigcodedesc_np.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_sigcodedesc_np __LIBC_LOCAL_NAME(sigcodedesc_np)
#endif /* !__CRT_HAVE_sigcodedesc_np */
#endif /* !__local___localdep_sigcodedesc_np_defined */
__NAMESPACE_LOCAL_END
#include <asm/os/signal.h>
#include <bits/crt/inttypes.h>
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(psiginfo) __ATTR_IN(1) __ATTR_IN_OPT(2) void
__NOTHROW_CB_NCX(__LIBCCALL __LIBC_LOCAL_NAME(psiginfo))(struct __siginfo_struct const *__pinfo, char const *__s) {
	char const *__text;
	__text = (__NAMESPACE_LOCAL_SYM __localdep_sigabbrev_np)(__pinfo->si_signo);
#if (defined(__CRT_HAVE_flockfile) || defined(__CRT_HAVE__lock_file) || defined(__CRT_HAVE__IO_flockfile)) && (defined(__CRT_HAVE_funlockfile) || defined(__CRT_HAVE__unlock_file) || defined(__CRT_HAVE__IO_funlockfile))
	(__NAMESPACE_LOCAL_SYM __localdep_flockfile)(__LOCAL_stderr);
#endif /* (__CRT_HAVE_flockfile || __CRT_HAVE__lock_file || __CRT_HAVE__IO_flockfile) && (__CRT_HAVE_funlockfile || __CRT_HAVE__unlock_file || __CRT_HAVE__IO_funlockfile) */
	if (__s && *__s)
		(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr, "%s: ", __s);
	if (__text) {
		(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr, "SIG%s (", __text);
#if defined(__SIGRTMIN) && defined(__SIGRTMAX)
	} else if (__pinfo->si_signo >= __SIGRTMIN &&
	           __pinfo->si_signo <= __SIGRTMAX) {
		unsigned int __offset;
		__offset = (unsigned int)(__pinfo->si_signo - __SIGRTMIN);
		if (__offset != 0) {
			(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr, "SIGRTMIN+%u (", __offset);
		} else {
			(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr, "SIGRTMIN (");
		}
#endif /* __SIGRTMIN && __SIGRTMAX */
	} else {
		(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr, "Unknown signal %d (", __pinfo->si_signo);
	}
	__text = (__NAMESPACE_LOCAL_SYM __localdep_sigcodedesc_np)(__pinfo->si_signo, __pinfo->si_code);
	if (__text) {
		(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr, "%s ", __text);
	} else {
		(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr, "%u ", (unsigned int)__pinfo->si_code);
	}
#if defined(__SIGILL) || defined(__SIGFPE) || defined(__SIGSEGV) || defined(__SIGBUS)
	if (0
#ifdef __SIGILL
	    || __pinfo->si_signo == __SIGILL
#endif /* __SIGILL */
#ifdef __SIGFPE
	    || __pinfo->si_signo == __SIGFPE
#endif /* __SIGFPE */
#ifdef __SIGSEGV
	    || __pinfo->si_signo == __SIGSEGV
#endif /* __SIGSEGV */
#ifdef __SIGBUS
	    || __pinfo->si_signo == __SIGBUS
#endif /* __SIGBUS */
	    ) {
		(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr, "[%p])\n", __pinfo->si_addr);
	} else
#endif /* __SIGILL || __SIGFPE || __SIGSEGV || __SIGBUS */
#ifdef __SIGCHLD
	if (__pinfo->si_signo == __SIGCHLD) {
		(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr,
		                 "%" __PRIN_PREFIX(__SIZEOF_PID_T__) "d %d "
		                 "%" __PRIN_PREFIX(__SIZEOF_UID_T__) "d)\n",
		                 (__pid_t)__pinfo->si_pid,
		                 (int)__pinfo->si_status,
		                 (__uid_t)__pinfo->si_uid);
	} else
#endif /* __SIGCHLD */
#ifdef __SIGPOLL
	if (__pinfo->si_signo == __SIGPOLL) {
		(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr, "%" __PRIN_PREFIX(__SIZEOF_POINTER__) "d)\n",
		                 (__LONGPTR_TYPE__)__pinfo->si_band);
	} else
#endif /* __SIGPOLL */
	{
		(__NAMESPACE_LOCAL_SYM __localdep_fprintf_unlocked)(__LOCAL_stderr,
		                 "%" __PRIN_PREFIX(__SIZEOF_PID_T__) "d "
		                 "%" __PRIN_PREFIX(__SIZEOF_UID_T__) "d)\n",
		                 (__pid_t)__pinfo->si_pid,
		                 (__uid_t)__pinfo->si_uid);
	}
#if (defined(__CRT_HAVE_flockfile) || defined(__CRT_HAVE__lock_file) || defined(__CRT_HAVE__IO_flockfile)) && (defined(__CRT_HAVE_funlockfile) || defined(__CRT_HAVE__unlock_file) || defined(__CRT_HAVE__IO_funlockfile))
	(__NAMESPACE_LOCAL_SYM __localdep_funlockfile)(__LOCAL_stderr);
#endif /* (__CRT_HAVE_flockfile || __CRT_HAVE__lock_file || __CRT_HAVE__IO_flockfile) && (__CRT_HAVE_funlockfile || __CRT_HAVE__unlock_file || __CRT_HAVE__IO_funlockfile) */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_psiginfo_defined
#define __local___localdep_psiginfo_defined
#define __localdep_psiginfo __LIBC_LOCAL_NAME(psiginfo)
#endif /* !__local___localdep_psiginfo_defined */
#else /* __LOCAL_stderr && (__CRT_HAVE_fprintf_unlocked || __CRT_HAVE_fprintf_s || __CRT_HAVE_vfprintf_unlocked || __CRT_HAVE_vfprintf || __CRT_HAVE_vfprintf_s || __CRT_HAVE__IO_vfprintf || __CRT_HAVE_file_printer_unlocked || __CRT_HAVE_file_printer || __CRT_HAVE_fwrite_unlocked || __CRT_HAVE__fwrite_nolock || __CRT_HAVE_fwrite || __CRT_HAVE__IO_fwrite || __CRT_HAVE_fwrite_s || __CRT_HAVE_fgetc_unlocked || __CRT_HAVE_getc_unlocked || __CRT_HAVE__getc_nolock || __CRT_HAVE__fgetc_nolock || (__CRT_HAVE_getc && (!__CRT_DOS || (!__CRT_HAVE__filbuf && !__CRT_HAVE___uflow && !__CRT_HAVE___underflow && !__CRT_HAVE___srget))) || (__CRT_HAVE_fgetc && (!__CRT_DOS || (!__CRT_HAVE__filbuf && !__CRT_HAVE___uflow && !__CRT_HAVE___underflow && !__CRT_HAVE___srget))) || (__CRT_HAVE__IO_getc && (!__CRT_DOS || (!__CRT_HAVE__filbuf && !__CRT_HAVE___uflow && !__CRT_HAVE___underflow && !__CRT_HAVE___srget))) || (__CRT_DOS && (__CRT_HAVE__filbuf || __CRT_HAVE___uflow || __CRT_HAVE___underflow || __CRT_HAVE___srget)) || __CRT_HAVE_fread || __CRT_HAVE__IO_fread || __CRT_HAVE_fread_unlocked || __CRT_HAVE__fread_nolock) */
#undef __local_psiginfo_defined
#endif /* !__LOCAL_stderr || (!__CRT_HAVE_fprintf_unlocked && !__CRT_HAVE_fprintf_s && !__CRT_HAVE_vfprintf_unlocked && !__CRT_HAVE_vfprintf && !__CRT_HAVE_vfprintf_s && !__CRT_HAVE__IO_vfprintf && !__CRT_HAVE_file_printer_unlocked && !__CRT_HAVE_file_printer && !__CRT_HAVE_fwrite_unlocked && !__CRT_HAVE__fwrite_nolock && !__CRT_HAVE_fwrite && !__CRT_HAVE__IO_fwrite && !__CRT_HAVE_fwrite_s && !__CRT_HAVE_fgetc_unlocked && !__CRT_HAVE_getc_unlocked && !__CRT_HAVE__getc_nolock && !__CRT_HAVE__fgetc_nolock && !__CRT_HAVE_getc && !__CRT_HAVE_fgetc && !__CRT_HAVE__IO_getc && (!__CRT_DOS || (!__CRT_HAVE__filbuf && !__CRT_HAVE___uflow && !__CRT_HAVE___underflow && !__CRT_HAVE___srget)) && !__CRT_HAVE_fread && !__CRT_HAVE__IO_fread && !__CRT_HAVE_fread_unlocked && !__CRT_HAVE__fread_nolock) */
#endif /* !__local_psiginfo_defined */
