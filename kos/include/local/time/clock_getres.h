/* HASH CRC-32:0xf9106806 */
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
#ifndef __local_clock_getres_defined
#if (defined(__CRT_HAVE_clock_getres) || defined(__CRT_HAVE_clock_getres64))
#define __local_clock_getres_defined 1
/* Dependency: "clock_getres32" from "time" */
#ifndef ____localdep_clock_getres32_defined
#define ____localdep_clock_getres32_defined 1
#if defined(__CRT_HAVE_clock_getres)
/* Get resolution of clock CLOCK_ID */
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_NCX,__localdep_clock_getres32,(__clockid_t __clock_id, struct __timespec32 *__res),clock_getres,(__clock_id,__res))
#elif defined(__CRT_HAVE___clock_getres)
/* Get resolution of clock CLOCK_ID */
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_NCX,__localdep_clock_getres32,(__clockid_t __clock_id, struct __timespec32 *__res),__clock_getres,(__clock_id,__res))
#else /* LIBC: clock_getres */
#undef ____localdep_clock_getres32_defined
#endif /* clock_getres32... */
#endif /* !____localdep_clock_getres32_defined */

/* Dependency: "clock_getres64" from "time" */
#ifndef ____localdep_clock_getres64_defined
#define ____localdep_clock_getres64_defined 1
#if defined(__CRT_HAVE_clock_getres64)
/* Get resolution of clock CLOCK_ID */
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_NCX,__localdep_clock_getres64,(__clockid_t __clock_id, struct __timespec64 *__res),clock_getres64,(__clock_id,__res))
#elif defined(__CRT_HAVE_clock_getres) && (__SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__)
/* Get resolution of clock CLOCK_ID */
__CREDIRECT(__ATTR_NONNULL((2)),int,__NOTHROW_NCX,__localdep_clock_getres64,(__clockid_t __clock_id, struct __timespec64 *__res),clock_getres,(__clock_id,__res))
#elif defined(__CRT_HAVE_clock_getres) || defined(__CRT_HAVE___clock_getres)
#include <local/time/clock_getres64.h>
/* Get resolution of clock CLOCK_ID */
#define __localdep_clock_getres64 (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(clock_getres64))
#else /* CUSTOM: clock_getres64 */
#undef ____localdep_clock_getres64_defined
#endif /* clock_getres64... */
#endif /* !____localdep_clock_getres64_defined */

__NAMESPACE_LOCAL_BEGIN
/* Get resolution of clock CLOCK_ID */
__LOCAL_LIBC(clock_getres) __ATTR_NONNULL((2)) int
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(clock_getres))(__clockid_t __clock_id,
                                                          struct __TM_TYPE(timespec) *__res) {
#line 1063 "kos/src/libc/magic/time.c"
#ifdef __CRT_HAVE_clock_getres
	int __result;
	struct __timespec32 __res32;
	__result = __localdep_clock_getres32(__clock_id, &__res32);
	if (!__result) {
		__res->tv_sec  = (__time64_t)__res32.tv_sec;
		__res->tv_nsec = __res32.tv_nsec;
	}
	return __result;
#else
	int __result;
	struct __timespec64 __res64;
	__result = __localdep_clock_getres64(__clock_id, &__res64);
	if (!__result) {
		__res->tv_sec  = (__time32_t)__res64.tv_sec;
		__res->tv_nsec = __res64.tv_nsec;
	}
	return __result;
#endif
}
__NAMESPACE_LOCAL_END
#endif /* (defined(__CRT_HAVE_clock_getres) || defined(__CRT_HAVE_clock_getres64)) */
#endif /* !__local_clock_getres_defined */
