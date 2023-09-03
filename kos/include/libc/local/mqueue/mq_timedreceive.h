/* HASH CRC-32:0xbde1a188 */
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
#ifndef __local_mq_timedreceive_defined
#define __local_mq_timedreceive_defined
#include <__crt.h>
#include <bits/types.h>
#if defined(__CRT_HAVE_mq_timedreceive64) || defined(__CRT_HAVE___mq_timedreceive_time64) || defined(__CRT_HAVE_mq_timedreceive)
#include <bits/os/timespec.h>
#include <bits/os/mqueue.h>
__NAMESPACE_LOCAL_BEGIN
#if !defined(__local___localdep_mq_timedreceive32_defined) && defined(__CRT_HAVE_mq_timedreceive)
#define __local___localdep_mq_timedreceive32_defined
__CREDIRECT(__ATTR_IN(5) __ATTR_OUTS(2, 3),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_mq_timedreceive32,(__mqd_t __mqdes, char *__restrict __msg_ptr, __SIZE_TYPE__ __msg_len, unsigned int *__pmsg_prio, struct __timespec32 const *__restrict __abs_timeout),mq_timedreceive,(__mqdes,__msg_ptr,__msg_len,__pmsg_prio,__abs_timeout))
#endif /* !__local___localdep_mq_timedreceive32_defined && __CRT_HAVE_mq_timedreceive */
#ifndef __local___localdep_mq_timedreceive64_defined
#define __local___localdep_mq_timedreceive64_defined
#if defined(__CRT_HAVE_mq_timedreceive) && __SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__
__CREDIRECT(__ATTR_IN(5) __ATTR_OUTS(2, 3),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_mq_timedreceive64,(__mqd_t __mqdes, char *__restrict __msg_ptr, __SIZE_TYPE__ __msg_len, unsigned int *__pmsg_prio, struct __timespec64 const *__restrict __abs_timeout),mq_timedreceive,(__mqdes,__msg_ptr,__msg_len,__pmsg_prio,__abs_timeout))
#elif defined(__CRT_HAVE_mq_timedreceive64)
__CREDIRECT(__ATTR_IN(5) __ATTR_OUTS(2, 3),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_mq_timedreceive64,(__mqd_t __mqdes, char *__restrict __msg_ptr, __SIZE_TYPE__ __msg_len, unsigned int *__pmsg_prio, struct __timespec64 const *__restrict __abs_timeout),mq_timedreceive64,(__mqdes,__msg_ptr,__msg_len,__pmsg_prio,__abs_timeout))
#elif defined(__CRT_HAVE___mq_timedreceive_time64)
__CREDIRECT(__ATTR_IN(5) __ATTR_OUTS(2, 3),__SSIZE_TYPE__,__NOTHROW_RPC,__localdep_mq_timedreceive64,(__mqd_t __mqdes, char *__restrict __msg_ptr, __SIZE_TYPE__ __msg_len, unsigned int *__pmsg_prio, struct __timespec64 const *__restrict __abs_timeout),__mq_timedreceive_time64,(__mqdes,__msg_ptr,__msg_len,__pmsg_prio,__abs_timeout))
#elif defined(__CRT_HAVE_mq_timedreceive)
__NAMESPACE_LOCAL_END
#include <libc/local/mqueue/mq_timedreceive64.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_mq_timedreceive64 __LIBC_LOCAL_NAME(mq_timedreceive64)
#else /* ... */
#undef __local___localdep_mq_timedreceive64_defined
#endif /* !... */
#endif /* !__local___localdep_mq_timedreceive64_defined */
__LOCAL_LIBC(mq_timedreceive) __ATTR_IN(5) __ATTR_OUTS(2, 3) __ATTR_OUT_OPT(4) __SSIZE_TYPE__
__NOTHROW_RPC(__LIBCCALL __LIBC_LOCAL_NAME(mq_timedreceive))(__mqd_t __mqdes, char *__restrict __msg_ptr, __SIZE_TYPE__ __msg_len, unsigned int *__pmsg_prio, struct timespec const *__restrict __abs_timeout) {
#ifdef __CRT_HAVE_mq_timedreceive
	struct __timespec32 __abs_timeout32;
	__abs_timeout32.tv_sec  = (__time32_t)__abs_timeout->tv_sec;
	__abs_timeout32.tv_nsec = __abs_timeout->tv_nsec;
	return (__NAMESPACE_LOCAL_SYM __localdep_mq_timedreceive32)(__mqdes, __msg_ptr, __msg_len, __pmsg_prio, &__abs_timeout32);
#else /* __CRT_HAVE_mq_timedreceive */
	struct __timespec64 __abs_timeout64;
	__abs_timeout64.tv_sec  = (__time64_t)__abs_timeout->tv_sec;
	__abs_timeout64.tv_nsec = __abs_timeout->tv_nsec;
	return (__NAMESPACE_LOCAL_SYM __localdep_mq_timedreceive64)(__mqdes, __msg_ptr, __msg_len, __pmsg_prio, &__abs_timeout64);
#endif /* !__CRT_HAVE_mq_timedreceive */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_mq_timedreceive_defined
#define __local___localdep_mq_timedreceive_defined
#define __localdep_mq_timedreceive __LIBC_LOCAL_NAME(mq_timedreceive)
#endif /* !__local___localdep_mq_timedreceive_defined */
#else /* __CRT_HAVE_mq_timedreceive64 || __CRT_HAVE___mq_timedreceive_time64 || __CRT_HAVE_mq_timedreceive */
#undef __local_mq_timedreceive_defined
#endif /* !__CRT_HAVE_mq_timedreceive64 && !__CRT_HAVE___mq_timedreceive_time64 && !__CRT_HAVE_mq_timedreceive */
#endif /* !__local_mq_timedreceive_defined */
