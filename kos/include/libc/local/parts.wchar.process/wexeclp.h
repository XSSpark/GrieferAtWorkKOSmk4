/* HASH CRC-32:0xee4fff86 */
/* Copyright (c) 2019-2022 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2022 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_wexeclp_defined
#define __local_wexeclp_defined
#include <__crt.h>
#include <libc/template/environ.h>
#include <hybrid/__alloca.h>
#if defined(__CRT_HAVE_wexecvp) || defined(__CRT_HAVE__wexecvp) || ((defined(__CRT_HAVE_execvp) || defined(__CRT_HAVE__execvp) || ((defined(__CRT_HAVE_execvpe) || defined(__CRT_HAVE__execvpe) || ((defined(__CRT_HAVE_execve) || defined(__CRT_HAVE__execve) || defined(__CRT_HAVE___execve) || defined(__CRT_HAVE___libc_execve)) && defined(__hybrid_alloca))) && defined(__LOCAL_environ))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_convert_wcstombsv) || defined(__CRT_HAVE_convert_wcstombsvn) || defined(__CRT_HAVE_malloc) || defined(__CRT_HAVE___libc_malloc) || defined(__CRT_HAVE_calloc) || defined(__CRT_HAVE___libc_calloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc) || defined(__CRT_HAVE_memalign) || defined(__CRT_HAVE_aligned_alloc) || defined(__CRT_HAVE___libc_memalign) || defined(__CRT_HAVE_posix_memalign)))
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_wexecvp_defined
#define __local___localdep_wexecvp_defined
#ifdef __CRT_HAVE_wexecvp
__NAMESPACE_LOCAL_END
#include <features.h>
#ifndef __TARGV
#ifdef __USE_DOS_ALTERATIONS
#define __TARGV char const *const *___argv
#define __TENVP char const *const *___envp
#else /* __USE_DOS_ALTERATIONS */
#define __TARGV char *const ___argv[__restrict_arr]
#define __TENVP char *const ___envp[__restrict_arr]
#endif /* !__USE_DOS_ALTERATIONS */
#endif /* !__TARGV */
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,__localdep_wexecvp,(__WCHAR_TYPE__ const *__restrict __file, __TWARGV),wexecvp,(__path,___argv))
#elif defined(__CRT_HAVE__wexecvp)
__NAMESPACE_LOCAL_END
#include <features.h>
#ifndef __TARGV
#ifdef __USE_DOS_ALTERATIONS
#define __TARGV char const *const *___argv
#define __TENVP char const *const *___envp
#else /* __USE_DOS_ALTERATIONS */
#define __TARGV char *const ___argv[__restrict_arr]
#define __TENVP char *const ___envp[__restrict_arr]
#endif /* !__USE_DOS_ALTERATIONS */
#endif /* !__TARGV */
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_NONNULL((1, 2)),int,__NOTHROW_RPC,__localdep_wexecvp,(__WCHAR_TYPE__ const *__restrict __file, __TWARGV),_wexecvp,(__path,___argv))
#elif (defined(__CRT_HAVE_execvp) || defined(__CRT_HAVE__execvp) || ((defined(__CRT_HAVE_execvpe) || defined(__CRT_HAVE__execvpe) || ((defined(__CRT_HAVE_execve) || defined(__CRT_HAVE__execve) || defined(__CRT_HAVE___execve) || defined(__CRT_HAVE___libc_execve)) && defined(__hybrid_alloca))) && defined(__LOCAL_environ))) && (defined(__CRT_HAVE_convert_wcstombs) || defined(__CRT_HAVE_convert_wcstombsn) || defined(__CRT_HAVE_format_aprintf_printer) || defined(__CRT_HAVE_format_aprintf_alloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc)) && (defined(__CRT_HAVE_convert_wcstombsv) || defined(__CRT_HAVE_convert_wcstombsvn) || defined(__CRT_HAVE_malloc) || defined(__CRT_HAVE___libc_malloc) || defined(__CRT_HAVE_calloc) || defined(__CRT_HAVE___libc_calloc) || defined(__CRT_HAVE_realloc) || defined(__CRT_HAVE___libc_realloc) || defined(__CRT_HAVE_memalign) || defined(__CRT_HAVE_aligned_alloc) || defined(__CRT_HAVE___libc_memalign) || defined(__CRT_HAVE_posix_memalign))
__NAMESPACE_LOCAL_END
#include <libc/local/parts.wchar.process/wexecvp.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_wexecvp __LIBC_LOCAL_NAME(wexecvp)
#else /* ... */
#undef __local___localdep_wexecvp_defined
#endif /* !... */
#endif /* !__local___localdep_wexecvp_defined */
__NAMESPACE_LOCAL_END
#include <parts/redirect-exec.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(wexeclp) __ATTR_SENTINEL __ATTR_NONNULL((1)) int
__NOTHROW_RPC(__VLIBCCALL __LIBC_LOCAL_NAME(wexeclp))(__WCHAR_TYPE__ const *__restrict __file, __WCHAR_TYPE__ const *__args, ...) {
	__REDIRECT_EXECL(__WCHAR_TYPE__, (__NAMESPACE_LOCAL_SYM __localdep_wexecvp), __file, __args)
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wexeclp_defined
#define __local___localdep_wexeclp_defined
#define __localdep_wexeclp __LIBC_LOCAL_NAME(wexeclp)
#endif /* !__local___localdep_wexeclp_defined */
#else /* __CRT_HAVE_wexecvp || __CRT_HAVE__wexecvp || ((__CRT_HAVE_execvp || __CRT_HAVE__execvp || ((__CRT_HAVE_execvpe || __CRT_HAVE__execvpe || ((__CRT_HAVE_execve || __CRT_HAVE__execve || __CRT_HAVE___execve || __CRT_HAVE___libc_execve) && __hybrid_alloca)) && __LOCAL_environ)) && (__CRT_HAVE_convert_wcstombs || __CRT_HAVE_convert_wcstombsn || __CRT_HAVE_format_aprintf_printer || __CRT_HAVE_format_aprintf_alloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc) && (__CRT_HAVE_convert_wcstombsv || __CRT_HAVE_convert_wcstombsvn || __CRT_HAVE_malloc || __CRT_HAVE___libc_malloc || __CRT_HAVE_calloc || __CRT_HAVE___libc_calloc || __CRT_HAVE_realloc || __CRT_HAVE___libc_realloc || __CRT_HAVE_memalign || __CRT_HAVE_aligned_alloc || __CRT_HAVE___libc_memalign || __CRT_HAVE_posix_memalign)) */
#undef __local_wexeclp_defined
#endif /* !__CRT_HAVE_wexecvp && !__CRT_HAVE__wexecvp && ((!__CRT_HAVE_execvp && !__CRT_HAVE__execvp && ((!__CRT_HAVE_execvpe && !__CRT_HAVE__execvpe && ((!__CRT_HAVE_execve && !__CRT_HAVE__execve && !__CRT_HAVE___execve && !__CRT_HAVE___libc_execve) || !__hybrid_alloca)) || !__LOCAL_environ)) || (!__CRT_HAVE_convert_wcstombs && !__CRT_HAVE_convert_wcstombsn && !__CRT_HAVE_format_aprintf_printer && !__CRT_HAVE_format_aprintf_alloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc) || (!__CRT_HAVE_convert_wcstombsv && !__CRT_HAVE_convert_wcstombsvn && !__CRT_HAVE_malloc && !__CRT_HAVE___libc_malloc && !__CRT_HAVE_calloc && !__CRT_HAVE___libc_calloc && !__CRT_HAVE_realloc && !__CRT_HAVE___libc_realloc && !__CRT_HAVE_memalign && !__CRT_HAVE_aligned_alloc && !__CRT_HAVE___libc_memalign && !__CRT_HAVE_posix_memalign)) */
#endif /* !__local_wexeclp_defined */
