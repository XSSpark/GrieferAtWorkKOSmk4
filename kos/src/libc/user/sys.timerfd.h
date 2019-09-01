/* HASH 0x5d6f53 */
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
#ifndef GUARD_LIBC_USER_SYS_TIMERFD_H
#define GUARD_LIBC_USER_SYS_TIMERFD_H 1

#include "../api.h"
#include <hybrid/typecore.h>
#include <kos/types.h>
#include <sys/timerfd.h>

DECL_BEGIN

/* Return file descriptor for new interval timer source */
INTDEF fd_t NOTHROW(LIBCCALL libc_timerfd_create)(clockid_t clock_id, int flags);
/* Set next expiration time of interval timer source UFD to UTMR.
 * If FLAGS has the TFD_TIMER_ABSTIME flag set the timeout utmr
 * is absolute. Optionally return the old expiration time in OTMR */
INTDEF NONNULL((3)) int NOTHROW_NCX(LIBCCALL libc_timerfd_settime)(fd_t ufd, int flags, struct itimerspec const *utmr, struct itimerspec *otmr);
/* Return the next expiration time of UFD */
INTDEF NONNULL((2)) NONNULL((2)) int NOTHROW_NCX(LIBCCALL libc_timerfd_gettime)(fd_t ufd, struct itimerspec *__restrict otmr);
/* Set next expiration time of interval timer source UFD to UTMR.
 * If FLAGS has the TFD_TIMER_ABSTIME flag set the timeout utmr
 * is absolute. Optionally return the old expiration time in OTMR */
INTDEF NONNULL((3)) int NOTHROW_NCX(LIBCCALL libc_timerfd_settime64)(fd_t ufd, int flags, struct itimerspec64 const *utmr, struct itimerspec64 *otmr);
/* Return the next expiration time of UFD */
INTDEF NONNULL((2)) int NOTHROW_NCX(LIBCCALL libc_timerfd_gettime64)(fd_t ufd, struct itimerspec64 *__restrict otmr);

DECL_END

#endif /* !GUARD_LIBC_USER_SYS_TIMERFD_H */
