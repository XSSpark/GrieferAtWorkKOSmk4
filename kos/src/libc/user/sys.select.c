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
#ifndef GUARD_LIBC_USER_SYS_SELECT_C
#define GUARD_LIBC_USER_SYS_SELECT_C 1

#include "../api.h"
/**/

#include <bits/os/sigset_with_size.h>
#include <kos/syscalls.h>

#include "../libc/syscalls.h"
#include "sys.select.h"

DECL_BEGIN

/*[[[head:libc_select,hash:CRC-32=0x700edc6]]]*/
/* >> select(2), select64(2), pselect(2), pselect64(2)
 * Wait for read/write/other events to become possible (without blocking)
 * on the file descriptors within  any given non-NULL `fd_set'. Only  the
 * first `nfds'  elements of  the respective  sets are  considered,  thus
 * representing  the  upper limit  on how  much  memory the  kernel might
 * touch in the given sets.
 *
 * Upon return, all  bits from all  given fd sets  will be cleared,  except
 * for those which are associated with files where the respective condition
 * has become available.
 *
 * This system call is implemented in terms of `poll(2)', and individual
 * sets translate to `struct pollfd::events':
 *  - readfds:   POLLSELECT_READFDS    (POLLRDNORM | POLLRDBAND | POLLIN | POLLHUP | POLLERR)
 *  - writefds:  POLLSELECT_WRITEFDS   (POLLWRBAND | POLLWRNORM | POLLOUT | POLLERR)
 *  - exceptfds: POLLSELECT_EXCEPTFDS  (POLLPRI)
 *
 * @param: nfds:      The max fd index to probe in any of the given sets
 * @param: readfds:   [0..1] Files to test for reading (s.a. `POLLSELECT_READFDS')
 * @param: writefds:  [0..1] Files to test for writing (s.a. `POLLSELECT_WRITEFDS')
 * @param: exceptfds: [0..1] Files to test for exceptional conditions (s.a. `POLLSELECT_EXCEPTFDS')
 * @param: timeout:   [0..1] Timeout for how long to keep waiting
 * @param: sigmask:   [0..1] When non-NULL, set of signals that should _NOT_ be allowed to interrupt the system call
 *                           Semantically speaking, this mask is atomically  `SIG_SETMASK'd for the duration of  the
 *                           call being made.
 * @return: * : The # of distinct files for which a `1'-bit was written to at least one of the given sets
 * @return: 0 : The given `timeout' expired
 * @return: -1: [errno=EBADF]  One of the given sets contains an invalid file descriptor
 * @return: -1: [errno=EINTR]  The system call was interrupted
 * @return: -1: [errno=EINVAL] `timeout->tv_nsec' is invalid
 * @return: -1: [errno=ENOMEM] Insufficient kernel memory to form task connections */
INTERN ATTR_SECTION(".text.crt.io.poll") ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_INOUT_OPT(5) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc_select)(__STDC_INT_AS_SIZE_T nfds,
                                  fd_set *__restrict readfds,
                                  fd_set *__restrict writefds,
                                  fd_set *__restrict exceptfds,
                                  struct timeval *__restrict timeout)
/*[[[body:libc_select]]]*/
{
	ssize_t result;
	result = sys__newselect(nfds, readfds, writefds, exceptfds, timeout);
	return libc_seterrno_syserr(result);
}
/*[[[end:libc_select]]]*/


/*[[[head:libc_pselect,hash:CRC-32=0x938597d9]]]*/
/* >> select(2), select64(2), pselect(2), pselect64(2)
 * Wait for read/write/other events to become possible (without blocking)
 * on the file descriptors within  any given non-NULL `fd_set'. Only  the
 * first `nfds'  elements of  the respective  sets are  considered,  thus
 * representing  the  upper limit  on how  much  memory the  kernel might
 * touch in the given sets.
 *
 * Upon return, all  bits from all  given fd sets  will be cleared,  except
 * for those which are associated with files where the respective condition
 * has become available.
 *
 * This system call is implemented in terms of `poll(2)', and individual
 * sets translate to `struct pollfd::events':
 *  - readfds:   POLLSELECT_READFDS    (POLLRDNORM | POLLRDBAND | POLLIN | POLLHUP | POLLERR)
 *  - writefds:  POLLSELECT_WRITEFDS   (POLLWRBAND | POLLWRNORM | POLLOUT | POLLERR)
 *  - exceptfds: POLLSELECT_EXCEPTFDS  (POLLPRI)
 *
 * @param: nfds:      The max fd index to probe in any of the given sets
 * @param: readfds:   [0..1] Files to test for reading (s.a. `POLLSELECT_READFDS')
 * @param: writefds:  [0..1] Files to test for writing (s.a. `POLLSELECT_WRITEFDS')
 * @param: exceptfds: [0..1] Files to test for exceptional conditions (s.a. `POLLSELECT_EXCEPTFDS')
 * @param: timeout:   [0..1] Timeout for how long to keep waiting
 * @param: sigmask:   [0..1] When non-NULL, set of signals that should _NOT_ be allowed to interrupt the system call
 *                           Semantically speaking, this mask is atomically  `SIG_SETMASK'd for the duration of  the
 *                           call being made.
 * @return: * : The # of distinct files for which a `1'-bit was written to at least one of the given sets
 * @return: 0 : The given `timeout' expired
 * @return: -1: [errno=EBADF]  One of the given sets contains an invalid file descriptor
 * @return: -1: [errno=EINTR]  The system call was interrupted
 * @return: -1: [errno=EINVAL] `timeout->tv_nsec' is invalid
 * @return: -1: [errno=ENOMEM] Insufficient kernel memory to form task connections */
INTERN ATTR_SECTION(".text.crt.io.poll") ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_IN_OPT(5) ATTR_IN_OPT(6) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc_pselect)(__STDC_INT_AS_SIZE_T nfds,
                                   fd_set *__restrict readfds,
                                   fd_set *__restrict writefds,
                                   fd_set *__restrict exceptfds,
                                   struct timespec const *__restrict timeout,
                                   sigset_t const *__restrict sigmask)
/*[[[body:libc_pselect]]]*/
{
	ssize_t result;
	struct sigset_with_size ss;
	ss.sws_sigset = (sigset_t *)sigmask;
	ss.sws_sigsiz = sizeof(sigset_t);
	result = sys_pselect6(nfds, readfds, writefds, exceptfds, timeout, &ss);
	return libc_seterrno_syserr(result);
}
/*[[[end:libc_pselect]]]*/

/*[[[head:libc_select64,hash:CRC-32=0xdea6269e]]]*/
#if __SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__
DEFINE_INTERN_ALIAS(libc_select64, libc_select);
#else /* MAGIC:alias */
/* >> select(2), select64(2), pselect(2), pselect64(2)
 * Wait for read/write/other events to become possible (without blocking)
 * on the file descriptors within  any given non-NULL `fd_set'. Only  the
 * first `nfds'  elements of  the respective  sets are  considered,  thus
 * representing  the  upper limit  on how  much  memory the  kernel might
 * touch in the given sets.
 *
 * Upon return, all  bits from all  given fd sets  will be cleared,  except
 * for those which are associated with files where the respective condition
 * has become available.
 *
 * This system call is implemented in terms of `poll(2)', and individual
 * sets translate to `struct pollfd::events':
 *  - readfds:   POLLSELECT_READFDS    (POLLRDNORM | POLLRDBAND | POLLIN | POLLHUP | POLLERR)
 *  - writefds:  POLLSELECT_WRITEFDS   (POLLWRBAND | POLLWRNORM | POLLOUT | POLLERR)
 *  - exceptfds: POLLSELECT_EXCEPTFDS  (POLLPRI)
 *
 * @param: nfds:      The max fd index to probe in any of the given sets
 * @param: readfds:   [0..1] Files to test for reading (s.a. `POLLSELECT_READFDS')
 * @param: writefds:  [0..1] Files to test for writing (s.a. `POLLSELECT_WRITEFDS')
 * @param: exceptfds: [0..1] Files to test for exceptional conditions (s.a. `POLLSELECT_EXCEPTFDS')
 * @param: timeout:   [0..1] Timeout for how long to keep waiting
 * @param: sigmask:   [0..1] When non-NULL, set of signals that should _NOT_ be allowed to interrupt the system call
 *                           Semantically speaking, this mask is atomically  `SIG_SETMASK'd for the duration of  the
 *                           call being made.
 * @return: * : The # of distinct files for which a `1'-bit was written to at least one of the given sets
 * @return: 0 : The given `timeout' expired
 * @return: -1: [errno=EBADF]  One of the given sets contains an invalid file descriptor
 * @return: -1: [errno=EINTR]  The system call was interrupted
 * @return: -1: [errno=EINVAL] `timeout->tv_nsec' is invalid
 * @return: -1: [errno=ENOMEM] Insufficient kernel memory to form task connections */
INTERN ATTR_SECTION(".text.crt.io.poll") ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_INOUT_OPT(5) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc_select64)(__STDC_INT_AS_SIZE_T nfds,
                                    fd_set *__restrict readfds,
                                    fd_set *__restrict writefds,
                                    fd_set *__restrict exceptfds,
                                    struct timeval64 *__restrict timeout)
/*[[[body:libc_select64]]]*/
{
	ssize_t result;
	result = sys_select_time64(nfds, readfds, writefds, exceptfds, timeout);
	return libc_seterrno_syserr(result);
}
#endif /* MAGIC:alias */
/*[[[end:libc_select64]]]*/

/*[[[head:libc_pselect64,hash:CRC-32=0x3e11f0d6]]]*/
#if __SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__
DEFINE_INTERN_ALIAS(libc_pselect64, libc_pselect);
#else /* MAGIC:alias */
/* >> select(2), select64(2), pselect(2), pselect64(2)
 * Wait for read/write/other events to become possible (without blocking)
 * on the file descriptors within  any given non-NULL `fd_set'. Only  the
 * first `nfds'  elements of  the respective  sets are  considered,  thus
 * representing  the  upper limit  on how  much  memory the  kernel might
 * touch in the given sets.
 *
 * Upon return, all  bits from all  given fd sets  will be cleared,  except
 * for those which are associated with files where the respective condition
 * has become available.
 *
 * This system call is implemented in terms of `poll(2)', and individual
 * sets translate to `struct pollfd::events':
 *  - readfds:   POLLSELECT_READFDS    (POLLRDNORM | POLLRDBAND | POLLIN | POLLHUP | POLLERR)
 *  - writefds:  POLLSELECT_WRITEFDS   (POLLWRBAND | POLLWRNORM | POLLOUT | POLLERR)
 *  - exceptfds: POLLSELECT_EXCEPTFDS  (POLLPRI)
 *
 * @param: nfds:      The max fd index to probe in any of the given sets
 * @param: readfds:   [0..1] Files to test for reading (s.a. `POLLSELECT_READFDS')
 * @param: writefds:  [0..1] Files to test for writing (s.a. `POLLSELECT_WRITEFDS')
 * @param: exceptfds: [0..1] Files to test for exceptional conditions (s.a. `POLLSELECT_EXCEPTFDS')
 * @param: timeout:   [0..1] Timeout for how long to keep waiting
 * @param: sigmask:   [0..1] When non-NULL, set of signals that should _NOT_ be allowed to interrupt the system call
 *                           Semantically speaking, this mask is atomically  `SIG_SETMASK'd for the duration of  the
 *                           call being made.
 * @return: * : The # of distinct files for which a `1'-bit was written to at least one of the given sets
 * @return: 0 : The given `timeout' expired
 * @return: -1: [errno=EBADF]  One of the given sets contains an invalid file descriptor
 * @return: -1: [errno=EINTR]  The system call was interrupted
 * @return: -1: [errno=EINVAL] `timeout->tv_nsec' is invalid
 * @return: -1: [errno=ENOMEM] Insufficient kernel memory to form task connections */
INTERN ATTR_SECTION(".text.crt.io.poll") ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_IN_OPT(5) ATTR_IN_OPT(6) __STDC_INT_AS_SSIZE_T
NOTHROW_RPC(LIBCCALL libc_pselect64)(__STDC_INT_AS_SIZE_T nfds,
                                     fd_set *__restrict readfds,
                                     fd_set *__restrict writefds,
                                     fd_set *__restrict exceptfds,
                                     struct timespec64 const *__restrict timeout,
                                     sigset_t const *__restrict sigmask)
/*[[[body:libc_pselect64]]]*/
{
	ssize_t result;
	struct sigset_with_size ss;
	ss.sws_sigset = (sigset_t *)sigmask;
	ss.sws_sigsiz = sizeof(sigset_t);
	result = sys_pselect6_time64(nfds, readfds, writefds, exceptfds, timeout, &ss);
	return libc_seterrno_syserr(result);
}
#endif /* MAGIC:alias */
/*[[[end:libc_pselect64]]]*/





/*[[[start:exports,hash:CRC-32=0xdf755497]]]*/
DEFINE_PUBLIC_ALIAS_P(__select,libc_select,ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_INOUT_OPT(5),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(__STDC_INT_AS_SIZE_T nfds, fd_set *__restrict readfds, fd_set *__restrict writefds, fd_set *__restrict exceptfds, struct timeval *__restrict timeout),(nfds,readfds,writefds,exceptfds,timeout));
DEFINE_PUBLIC_ALIAS_P(select,libc_select,ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_INOUT_OPT(5),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(__STDC_INT_AS_SIZE_T nfds, fd_set *__restrict readfds, fd_set *__restrict writefds, fd_set *__restrict exceptfds, struct timeval *__restrict timeout),(nfds,readfds,writefds,exceptfds,timeout));
DEFINE_PUBLIC_ALIAS_P(__pselect,libc_pselect,ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_IN_OPT(5) ATTR_IN_OPT(6),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(__STDC_INT_AS_SIZE_T nfds, fd_set *__restrict readfds, fd_set *__restrict writefds, fd_set *__restrict exceptfds, struct timespec const *__restrict timeout, sigset_t const *__restrict sigmask),(nfds,readfds,writefds,exceptfds,timeout,sigmask));
DEFINE_PUBLIC_ALIAS_P(pselect,libc_pselect,ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_IN_OPT(5) ATTR_IN_OPT(6),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(__STDC_INT_AS_SIZE_T nfds, fd_set *__restrict readfds, fd_set *__restrict writefds, fd_set *__restrict exceptfds, struct timespec const *__restrict timeout, sigset_t const *__restrict sigmask),(nfds,readfds,writefds,exceptfds,timeout,sigmask));
#include <bits/types.h>
#if __SIZEOF_TIME32_T__ != __SIZEOF_TIME64_T__
DEFINE_PUBLIC_ALIAS_P(__select64,libc_select64,ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_INOUT_OPT(5),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(__STDC_INT_AS_SIZE_T nfds, fd_set *__restrict readfds, fd_set *__restrict writefds, fd_set *__restrict exceptfds, struct timeval64 *__restrict timeout),(nfds,readfds,writefds,exceptfds,timeout));
DEFINE_PUBLIC_ALIAS_P(select64,libc_select64,ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_INOUT_OPT(5),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(__STDC_INT_AS_SIZE_T nfds, fd_set *__restrict readfds, fd_set *__restrict writefds, fd_set *__restrict exceptfds, struct timeval64 *__restrict timeout),(nfds,readfds,writefds,exceptfds,timeout));
DEFINE_PUBLIC_ALIAS_P(__pselect64,libc_pselect64,ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_IN_OPT(5) ATTR_IN_OPT(6),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(__STDC_INT_AS_SIZE_T nfds, fd_set *__restrict readfds, fd_set *__restrict writefds, fd_set *__restrict exceptfds, struct timespec64 const *__restrict timeout, sigset_t const *__restrict sigmask),(nfds,readfds,writefds,exceptfds,timeout,sigmask));
DEFINE_PUBLIC_ALIAS_P(pselect64,libc_pselect64,ATTR_INOUT_OPT(2) ATTR_INOUT_OPT(3) ATTR_INOUT_OPT(4) ATTR_IN_OPT(5) ATTR_IN_OPT(6),__STDC_INT_AS_SSIZE_T,NOTHROW_RPC,LIBCCALL,(__STDC_INT_AS_SIZE_T nfds, fd_set *__restrict readfds, fd_set *__restrict writefds, fd_set *__restrict exceptfds, struct timespec64 const *__restrict timeout, sigset_t const *__restrict sigmask),(nfds,readfds,writefds,exceptfds,timeout,sigmask));
#endif /* __SIZEOF_TIME32_T__ != __SIZEOF_TIME64_T__ */
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_SYS_SELECT_C */
