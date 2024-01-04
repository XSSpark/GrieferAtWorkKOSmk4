/* Copyright (c) 2019-2024 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2024 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef _KOS_CONFIG_TOOLCHAIN_H
#define _KOS_CONFIG_TOOLCHAIN_H 1

#include <__stdinc.h>
#include <hybrid/typecore.h>

#include <kos/config/_toolchain.h>


/* ----------------- Toolchain version of binutils
 * >> #define KOS_BUILD_CONFIG_TOOLCHAIN_BINUTILS_VERSION "2.38" */
#ifndef KOS_BUILD_CONFIG_TOOLCHAIN_BINUTILS_VERSION
#error "Missing macro: KOS_BUILD_CONFIG_TOOLCHAIN_BINUTILS_VERSION"
#endif /* !KOS_BUILD_CONFIG_TOOLCHAIN_BINUTILS_VERSION */


/* ----------------- Toolchain version of gcc
 * >> #define KOS_BUILD_CONFIG_TOOLCHAIN_GCC_VERSION "12.1.0" */
#ifndef KOS_BUILD_CONFIG_TOOLCHAIN_GCC_VERSION
#error "Missing macro: KOS_BUILD_CONFIG_TOOLCHAIN_GCC_VERSION"
#endif /* !KOS_BUILD_CONFIG_TOOLCHAIN_GCC_VERSION */


/* ----------------- `gcc  -dumpmachine`  from  toolchain   host
 * >> #define KOS_BUILD_CONFIG_TOOLCHAIN_HOST "x86_64-pc-cygwin" */
#ifndef KOS_BUILD_CONFIG_TOOLCHAIN_HOST
#error "Missing macro: KOS_BUILD_CONFIG_TOOLCHAIN_HOST"
#endif /* !KOS_BUILD_CONFIG_TOOLCHAIN_HOST */


/* ----------------- KOS toolchain build root directory
 * >> #define KOS_BUILD_CONFIG_TOOLCHAIN_HOST_ROOT  "/cygdrive/e/c/kls/kos" */
#ifndef KOS_BUILD_CONFIG_TOOLCHAIN_HOST_ROOT
#error "Missing macro: KOS_BUILD_CONFIG_TOOLCHAIN_HOST_ROOT"
#endif /* !KOS_BUILD_CONFIG_TOOLCHAIN_HOST_ROOT */


/* ----------------- KOS build configuration for toolchain
 * >> #define KOS_BUILD_CONFIG_TOOLCHAIN_BUILD "i386-kos" */
#ifndef KOS_BUILD_CONFIG_TOOLCHAIN_BUILD
#error "Missing macro: KOS_BUILD_CONFIG_TOOLCHAIN_BUILD"
#endif /* !KOS_BUILD_CONFIG_TOOLCHAIN_BUILD */


/* ----------------- Build   architecture   for  toolchain
 * >> #define KOS_BUILD_CONFIG_TOOLCHAIN_BUILD_ARCH "i386" */
#ifndef KOS_BUILD_CONFIG_TOOLCHAIN_BUILD_ARCH
#error "Missing macro: KOS_BUILD_CONFIG_TOOLCHAIN_BUILD_ARCH"
#endif /* !KOS_BUILD_CONFIG_TOOLCHAIN_BUILD_ARCH */


/* ----------------- Latest CPU  supported  by  toolchain
 * >> #define KOS_BUILD_CONFIG_TOOLCHAIN_BUILD_CPU "i686" */
#ifndef KOS_BUILD_CONFIG_TOOLCHAIN_BUILD_CPU
#error "Missing macro: KOS_BUILD_CONFIG_TOOLCHAIN_BUILD_CPU"
#endif /* !KOS_BUILD_CONFIG_TOOLCHAIN_BUILD_CPU */


#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETYEAR(year, month, day, hour, minute, second, nano)   year
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETMONTH(year, month, day, hour, minute, second, nano)  month
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETDAY(year, month, day, hour, minute, second, nano)    day
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETHOUR(year, month, day, hour, minute, second, nano)   hour
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETMINUTE(year, month, day, hour, minute, second, nano) minute
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETSECOND(year, month, day, hour, minute, second, nano) second
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETNANO(year, month, day, hour, minute, second, nano)   nano
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET2(cb, args) cb args
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(cb, tuple) _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET2(cb, tuple)
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETEPOCH(epoch, raw, padded)  epoch
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETRAW(epoch, raw, padded)    raw
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETPADDED(epoch, raw, padded) padded
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET2(cb, args) cb args
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(cb) _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET2(cb, KOS_BUILD_CONFIG_TOOLCHAIN_DATE_INFO)

#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_YEAR   _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETYEAR, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETPADDED))
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_MONTH  _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETMONTH, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETPADDED))
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_DAY    _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETDAY, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETPADDED))
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_HOUR   _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETHOUR, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETPADDED))
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_MINUTE _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETMINUTE, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETPADDED))
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_SECOND _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETSECOND, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETPADDED))
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_NANO   _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETNANO, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETPADDED))

#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_U64(x) __UINT64_C(x)
#define _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_EPOCH _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETEPOCH)

/* Toolchain build date components as preprocessor constant numbers. */
#define KOS_BUILD_CONFIG_TOOLCHAIN_DATE_EPOCH  _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_U64(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_EPOCH)
#define KOS_BUILD_CONFIG_TOOLCHAIN_DATE_YEAR   _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETYEAR, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETRAW))
#define KOS_BUILD_CONFIG_TOOLCHAIN_DATE_MONTH  _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETMONTH, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETRAW))
#define KOS_BUILD_CONFIG_TOOLCHAIN_DATE_DAY    _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETDAY, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETRAW))
#define KOS_BUILD_CONFIG_TOOLCHAIN_DATE_HOUR   _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETHOUR, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETRAW))
#define KOS_BUILD_CONFIG_TOOLCHAIN_DATE_MINUTE _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETMINUTE, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETRAW))
#define KOS_BUILD_CONFIG_TOOLCHAIN_DATE_SECOND _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETSECOND, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETRAW))
#define KOS_BUILD_CONFIG_TOOLCHAIN_DATE_NANO   _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_TUPLE_GETNANO, _KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GET(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_GETRAW))

/* Toolchain build date as string (e.g. "2022-06-05T16:49:40.276373700") */
#define KOS_BUILD_CONFIG_TOOLCHAIN_DATE                          \
	__PP_STR(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_YEAR)   "-" \
	__PP_STR(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_MONTH)  "-" \
	__PP_STR(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_DAY)    "T" \
	__PP_STR(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_HOUR)   ":" \
	__PP_STR(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_MINUTE) ":" \
	__PP_STR(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_SECOND) "." \
	__PP_STR(_KOS_BUILD_CONFIG_TOOLCHAIN_DATE_PADDED_NANO)

#endif /* !_KOS_CONFIG_TOOLCHAIN_H */
