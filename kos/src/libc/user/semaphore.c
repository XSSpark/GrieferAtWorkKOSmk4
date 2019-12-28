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
#ifndef GUARD_LIBC_USER_SEMAPHORE_C
#define GUARD_LIBC_USER_SEMAPHORE_C 1

#include "../api.h"
/**/

#include <kos/syscalls.h>
#include <kos/futex.h>
#include <sys/mman.h>

#include <fcntl.h>
#include <malloca.h>
#include <string.h>
#include <unistd.h>
#include <hybrid/atomic.h>

#include "semaphore.h"

DECL_BEGIN

struct sem {
	lfutex_t s_count; /* Number of available tickets (optionally or'd with `LFUTEX_WAIT_LOCK_WAITERS') */
};

/*[[[start:implementation]]]*/

/*[[[head:sem_init,hash:CRC-32=0x9b49de17]]]*/
/* Initialize semaphore object SEM to VALUE.
 * If PSHARED then share it with other processes */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_init") int
NOTHROW_NCX(LIBCCALL libc_sem_init)(sem_t *sem,
                                    int pshared,
                                    unsigned int value)
/*[[[body:sem_init]]]*/
{
	struct sem *self;
	(void)pshared;
	self = (struct sem *)sem;
#if __SIZEOF_INT__ >= __SIZEOF_POINTER__
	if (value > LFUTEX_WAIT_LOCK_TIDMASK) {
		libc_seterrno(EOVERFLOW);
		return -1;
	}
#endif /* __SIZEOF_INT__ >= __SIZEOF_POINTER__ */
	self->s_count = value;
	return 0;
}
/*[[[end:sem_init]]]*/

/*[[[head:sem_destroy,hash:CRC-32=0xbc662e37]]]*/
/* Free resources associated with semaphore object SEM */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_destroy") int
NOTHROW_NCX(LIBCCALL libc_sem_destroy)(sem_t *sem)
/*[[[body:sem_destroy]]]*/
{
	COMPILER_IMPURE();
	(void)sem;
	/* Nothing to do here... */
	return 0;
}
/*[[[end:sem_destroy]]]*/


PRIVATE ATTR_SECTION(".rodata.crt.sched.semaphore.named_prefix")
char const named_prefix[] = "/dev/shm/sem.";


/*[[[head:sem_open,hash:CRC-32=0x39b93373]]]*/
/* Open a named semaphore NAME with open flags OFLAGS */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_open") sem_t *
NOTHROW_RPC_KOS(VLIBCCALL libc_sem_open)(char const *name,
                                         oflag_t oflags,
                                         ...)
/*[[[body:sem_open]]]*/
{
	char *filename;
	size_t name_length;
	fd_t fd;
	va_list args;
	mode_t mode;
	struct sem *result;
	while (*name == '/')
		++name;
	va_start(args, oflags);
	mode = va_arg(args, mode_t);
	va_end(args);
	name_length = strlen(name);
	if unlikely(!name_length) {
		libc_seterrno(EINVAL);
		goto err;
	}
	filename = (char *)malloca((COMPILER_STRLEN(named_prefix) + name_length + 1) *
	                           sizeof(char));
	if unlikely(!filename)
		goto err;
	memcpy(filename, named_prefix, sizeof(named_prefix) - sizeof(char));
	memcpy(filename + COMPILER_STRLEN(named_prefix),
	       name, name_length + 1, sizeof(char));
	fd = open(filename, oflags, mode);
	freea(filename);
	if unlikely(fd < 0)
		goto err;
	result = (struct sem *)mmap(NULL, sizeof(struct sem),
	                            PROT_READ | PROT_WRITE,
	                            MAP_FILE | MAP_SHARED,
	                            fd, 0);
	sys_close(fd);
	if unlikely(result == (struct sem *)MAP_FAILED)
		goto err;
	return (sem_t *)result;
err:
	return NULL;
}
/*[[[end:sem_open]]]*/

/*[[[head:sem_close,hash:CRC-32=0xbe535676]]]*/
/* Close descriptor for named semaphore SEM */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_close") int
NOTHROW_NCX(LIBCCALL libc_sem_close)(sem_t *sem)
/*[[[body:sem_close]]]*/
{
	return munmap(sem, sizeof(struct sem));
}
/*[[[end:sem_close]]]*/

/*[[[head:sem_unlink,hash:CRC-32=0xb789d603]]]*/
/* Remove named semaphore NAME */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_unlink") int
NOTHROW_RPC_KOS(LIBCCALL libc_sem_unlink)(const char *name)
/*[[[body:sem_unlink]]]*/
{
	int result;
	char *filename;
	size_t name_length;
	while (*name == '/')
		++name;
	name_length = strlen(name);
	if unlikely(!name_length) {
		libc_seterrno(EINVAL);
		goto err;
	}
	filename = (char *)malloca((COMPILER_STRLEN(named_prefix) + name_length + 1) *
	                           sizeof(char));
	if unlikely(!filename)
		goto err;
	memcpy(filename, named_prefix, sizeof(named_prefix) - sizeof(char));
	memcpy(filename + COMPILER_STRLEN(named_prefix),
	       name, name_length + 1, sizeof(char));
	result = unlink(filename);
	freea(filename);
	return result;
err:
	return -1;
}
/*[[[end:sem_unlink]]]*/

/*[[[head:sem_wait,hash:CRC-32=0x57284335]]]*/
/* Wait for SEM being posted */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_wait") int
NOTHROW_RPC(LIBCCALL libc_sem_wait)(sem_t *sem)
/*[[[body:sem_wait]]]*/
{
	struct sem *self;
	self = (struct sem *)sem;
	for (;;) {
		int error;
		lfutex_t oldval;
		oldval = ATOMIC_READ(self->s_count);
		if (oldval & LFUTEX_WAIT_LOCK_TIDMASK) {
			if (!ATOMIC_CMPXCH_WEAK(self->s_count, oldval, oldval - 1))
				continue;
			return 0; /* Success! */
		}
		/* Set the is-waiting bit the first time around. */
		if (!(oldval & LFUTEX_WAIT_LOCK_WAITERS)) {
			if (!ATOMIC_CMPXCH_WEAK(self->s_count,
			                        oldval,
			                        oldval | LFUTEX_WAIT_LOCK_WAITERS))
				continue;
		}
		/* Wait until `LFUTEX_WAIT_LOCK_TIDMASK' becomes non-zero. */
		error = futex_waitwhile_exactbits(&self->s_count,
		                                  LFUTEX_WAIT_LOCK_WAITERS,
		                                  0);
		if (error < 0)
			return error;
	}
	return 0;
}
/*[[[end:sem_wait]]]*/

/*[[[head:sem_timedwait,hash:CRC-32=0xe2bd3d49]]]*/
/* Similar to `sem_wait' but wait only until ABSTIME */
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_timedwait") int
NOTHROW_RPC(LIBCCALL libc_sem_timedwait)(sem_t *__restrict sem,
                                         struct timespec const *__restrict abstime)
/*[[[body:sem_timedwait]]]*/
{
	struct sem *self;
	self = (struct sem *)sem;
	for (;;) {
		int error;
		lfutex_t oldval;
		oldval = ATOMIC_READ(self->s_count);
		if (oldval & LFUTEX_WAIT_LOCK_TIDMASK) {
			if (!ATOMIC_CMPXCH_WEAK(self->s_count, oldval, oldval - 1))
				continue;
			return 0; /* Success! */
		}
		/* Set the is-waiting bit the first time around. */
		if (!(oldval & LFUTEX_WAIT_LOCK_WAITERS)) {
			if (!ATOMIC_CMPXCH_WEAK(self->s_count,
			                        oldval,
			                        oldval | LFUTEX_WAIT_LOCK_WAITERS))
				continue;
		}
		/* Wait until `LFUTEX_WAIT_LOCK_TIDMASK' becomes non-zero. */
		error = lfutex(&self->s_count,
		               LFUTEX_WAIT_WHILE_BITMASK |
		               LFUTEX_WAIT_FLAG_TIMEOUT_REALTIME,
		               (lfutex_t)LFUTEX_WAIT_LOCK_WAITERS,
		               abstime, (lfutex_t)0);
		if (error < 0)
			return error;
	}
	return 0;
}
/*[[[end:sem_timedwait]]]*/

/*[[[head:sem_timedwait64,hash:CRC-32=0x77a1bf9b]]]*/
/* Similar to `sem_wait' but wait only until ABSTIME */
#if __SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__
DEFINE_INTERN_ALIAS(libc_sem_timedwait64, libc_sem_timedwait);
#else
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_timedwait64") int
NOTHROW_RPC(LIBCCALL libc_sem_timedwait64)(sem_t *__restrict sem,
                                           struct timespec64 const *__restrict abstime)
/*[[[body:sem_timedwait64]]]*/
{
	struct sem *self;
	self = (struct sem *)sem;
	for (;;) {
		int error;
		lfutex_t oldval;
		oldval = ATOMIC_READ(self->s_count);
		if (oldval & LFUTEX_WAIT_LOCK_TIDMASK) {
			if (!ATOMIC_CMPXCH_WEAK(self->s_count, oldval, oldval - 1))
				continue;
			return 0; /* Success! */
		}
		/* Set the is-waiting bit the first time around. */
		if (!(oldval & LFUTEX_WAIT_LOCK_WAITERS)) {
			if (!ATOMIC_CMPXCH_WEAK(self->s_count,
			                        oldval,
			                        oldval | LFUTEX_WAIT_LOCK_WAITERS))
				continue;
		}
		/* Wait until `LFUTEX_WAIT_LOCK_TIDMASK' becomes non-zero. */
		error = lfutex64(&self->s_count,
		                 LFUTEX_WAIT_WHILE_BITMASK |
		                 LFUTEX_WAIT_FLAG_TIMEOUT_REALTIME,
		                 (lfutex_t)LFUTEX_WAIT_LOCK_WAITERS,
		                 abstime, (lfutex_t)0);
		if (error < 0)
			return error;
	}
	return 0;
}
#endif /* MAGIC:alias */
/*[[[end:sem_timedwait64]]]*/

/*[[[head:sem_trywait,hash:CRC-32=0x8c0b11f3]]]*/
/* Test whether SEM is posted */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_trywait") int
NOTHROW_NCX(LIBCCALL libc_sem_trywait)(sem_t *sem)
/*[[[body:sem_trywait]]]*/
{
	struct sem *self;
	lfutex_t oldval;
	self = (struct sem *)sem;
again:
	oldval = ATOMIC_READ(self->s_count);
	if (oldval & LFUTEX_WAIT_LOCK_TIDMASK) {
		if (!ATOMIC_CMPXCH_WEAK(self->s_count, oldval, oldval - 1))
			goto again;
		return 0; /* Success! */
	}
	/* No tickets available... */
	libc_seterrno(EAGAIN);
	return -1;
}
/*[[[end:sem_trywait]]]*/

/*[[[head:sem_post,hash:CRC-32=0xb4a241a8]]]*/
/* Post SEM */
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_post") int
NOTHROW_NCX(LIBCCALL libc_sem_post)(sem_t *sem)
/*[[[body:sem_post]]]*/
{
	struct sem *self;
	lfutex_t oldval;
	self = (struct sem *)sem;
again:
	oldval = ATOMIC_READ(self->s_count);
	if unlikely((oldval & LFUTEX_WAIT_LOCK_TIDMASK) == LFUTEX_WAIT_LOCK_TIDMASK) {
		libc_seterrno(EOVERFLOW);
		return -1;
	}
	if (!ATOMIC_CMPXCH_WEAK(self->s_count,
	                        oldval,
	                        oldval + 1))
		goto again;
	/* If there are waiting threads, wake one of them. */
	if (oldval & LFUTEX_WAIT_LOCK_WAITERS) {
		/* NOTE: Make use of `LFUTEX_WAKEMASK' to do the equivalent of:
		 * >> if (!sys_lfutex(&self->s_count, LFUTEX_WAKE, 1, NULL, 0)) {
		 * >>     ATOMIC_FETCHAND(&self->s_count, ~LFUTEX_WAIT_LOCK_WAITERS);
		 * >>     sys_lfutex(&self->s_count, LFUTEX_WAKE, (size_t)-1, NULL, 0);
		 * >> } */
		sys_lfutex(&self->s_count, LFUTEX_WAKEMASK, 1,
		           (struct timespec64 const *)(uintptr_t)~LFUTEX_WAIT_LOCK_WAITERS, 0);
	}
	return 0;
}
/*[[[end:sem_post]]]*/

/*[[[head:sem_getvalue,hash:CRC-32=0x80176003]]]*/
/* Get current value of SEM and store it in *SVAL */
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.semaphore.sem_getvalue") int
NOTHROW_NCX(LIBCCALL libc_sem_getvalue)(sem_t *__restrict sem,
                                        int *__restrict sval)
/*[[[body:sem_getvalue]]]*/
{
	struct sem *self;
	self = (struct sem *)sem;
	/* XXX: This can overflow when `sizeof(lfutex_t) > sizeof(int)' */
	*sval = (int)(unsigned int)(lfutex_t)(ATOMIC_READ(self->s_count) &
	                                      LFUTEX_WAIT_LOCK_TIDMASK);
	return 0;
}
/*[[[end:sem_getvalue]]]*/

/*[[[end:implementation]]]*/



/*[[[start:exports,hash:CRC-32=0x5d60f078]]]*/
#undef sem_open
DEFINE_PUBLIC_WEAK_ALIAS(sem_init, libc_sem_init);
DEFINE_PUBLIC_WEAK_ALIAS(sem_destroy, libc_sem_destroy);
DEFINE_PUBLIC_WEAK_ALIAS(sem_open, libc_sem_open);
DEFINE_PUBLIC_WEAK_ALIAS(sem_close, libc_sem_close);
DEFINE_PUBLIC_WEAK_ALIAS(sem_unlink, libc_sem_unlink);
DEFINE_PUBLIC_WEAK_ALIAS(sem_wait, libc_sem_wait);
DEFINE_PUBLIC_WEAK_ALIAS(sem_timedwait, libc_sem_timedwait);
DEFINE_PUBLIC_WEAK_ALIAS(sem_timedwait64, libc_sem_timedwait64);
DEFINE_PUBLIC_WEAK_ALIAS(sem_trywait, libc_sem_trywait);
DEFINE_PUBLIC_WEAK_ALIAS(sem_post, libc_sem_post);
DEFINE_PUBLIC_WEAK_ALIAS(sem_getvalue, libc_sem_getvalue);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_SEMAPHORE_C */
