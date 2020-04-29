/* HASH CRC-32:0x96e00ced */
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
 *    in a product, an acknowledgement (see the following) in the product     *
 *    documentation is required:                                              *
 *    Portions Copyright (c) 2019-2020 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_futime64_defined
#if defined(__CRT_HAVE_futime) || defined(__CRT_HAVE__futime32)
#define __local_futime64_defined 1
/* Dependency: "crt_futime32" from "utime" */
#ifndef ____localdep_crt_futime32_defined
#define ____localdep_crt_futime32_defined 1
#ifdef __CRT_HAVE_futime
__CREDIRECT(,int,__NOTHROW_RPC,__localdep_crt_futime32,(__fd_t __fd, struct __utimbuf32 const *__file_times),futime,(__fd,__file_times))
#elif defined(__CRT_HAVE__futime32)
__CREDIRECT(,int,__NOTHROW_RPC,__localdep_crt_futime32,(__fd_t __fd, struct __utimbuf32 const *__file_times),_futime32,(__fd,__file_times))
#else /* LIBC: futime */
#undef ____localdep_crt_futime32_defined
#endif /* crt_futime32... */
#endif /* !____localdep_crt_futime32_defined */

__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(futime64) int
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(futime64))(__fd_t __fd,
                                                      struct utimbuf64 const *__file_times) {
#line 171 "kos/src/libc/magic/utime.c"
#ifdef __COMPILER_HAVE_PRAGMA_PUSHMACRO
#pragma push_macro("actime")
#pragma push_macro("modtime")
#endif /* __COMPILER_HAVE_PRAGMA_PUSHMACRO */
#undef actime
#undef modtime
	struct __utimbuf32 __buf32;
	if (!__file_times)
		return __localdep_crt_futime32(__fd, __NULLPTR);
	__buf32.actime  = (__time32_t)__file_times->actime;
	__buf32.modtime = (__time32_t)__file_times->modtime;
	return __localdep_crt_futime32(__fd, &__buf32);
#ifdef __COMPILER_HAVE_PRAGMA_PUSHMACRO
#pragma pop_macro("modtime")
#pragma pop_macro("actime")
#endif /* __COMPILER_HAVE_PRAGMA_PUSHMACRO */
}
__NAMESPACE_LOCAL_END
#endif /* __CRT_HAVE_futime || __CRT_HAVE__futime32 */
#endif /* !__local_futime64_defined */
