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
#ifndef GUARD_LIBC_USER_STDLIB_C
#define GUARD_LIBC_USER_STDLIB_C 1

#include "../api.h"
#include "stdlib.h"

#include <fcntl.h>
#include <kos/syscalls.h>
#include <limits.h>
#include <unistd.h>

#include <parts/errno.h>

DECL_BEGIN


#undef __libc_geterrno_or
#define __libc_geterrno_or(alt) libc_geterrno()


DEFINE_PUBLIC_ALIAS(__cxa_atexit, libc___cxa_atexit);
INTERN int
NOTHROW_NCX(LIBCCALL libc___cxa_atexit)(void (LIBCCALL *func)(void *arg),
                                        void *arg, void *dso_handle) {
	/* NOTE: I don't really understand why this function is even necessary...
	 *       I mean sure: it allows c++ to register destructor callbacks lazily
	 *       for local statics, however the same effect could be achieved by using
	 *       an __attribute__((destructor)), where its callback checks some kind of
	 *       was-initialized flag and invokes that callback when this is true. */
	/* HINT: `dso_handle' is `NULL' for the primary module (in which case
	 *       the registered function must be called alongside atexit()), or
	 *       is some arbitrary pointer apart of the static image of the
	 *       associated binary (which can be resolved using `dlgethandle()') */
	/* TODO */
	return -1;
}





/*[[[start:implementation]]]*/




/*[[[head:getenv,hash:0x9bd48a8]]]*/
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.environ.getenv") char *
NOTHROW_NCX(LIBCCALL libc_getenv)(char const *varname)
/*[[[body:getenv]]]*/
{
	CRT_UNIMPLEMENTED("getenv"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:getenv]]]*/

/*[[[head:system,hash:0x61896818]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.exec.system.system") int
NOTHROW_RPC(LIBCCALL libc_system)(char const *__restrict command)
/*[[[body:system]]]*/
{
	CRT_UNIMPLEMENTED("system"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:system]]]*/

/*[[[head:abort,hash:0xb13d797a]]]*/
INTERN ATTR_NORETURN
ATTR_WEAK ATTR_SECTION(".text.crt.application.exit.abort") void
(LIBCCALL libc_abort)(void)
/*[[[body:abort]]]*/
{
	_Exit(EXIT_FAILURE);
}
/*[[[end:abort]]]*/

/*[[[head:exit,hash:0xa53cc82e]]]*/
INTERN ATTR_NORETURN
ATTR_WEAK ATTR_SECTION(".text.crt.application.exit.exit") void
(LIBCCALL libc_exit)(int status)
		__THROWS(...)
/*[[[body:exit]]]*/
{
	/* TODO: Run at-exit */
	/* TODO: Run library finalizers */
	_Exit(status);
}
/*[[[end:exit]]]*/

/*[[[head:atexit,hash:0x414aecc2]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.sched.process.atexit") int
NOTHROW_NCX(LIBCCALL libc_atexit)(__atexit_func_t func)
/*[[[body:atexit]]]*/
{
	CRT_UNIMPLEMENTED("atexit"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:atexit]]]*/

/*[[[head:quick_exit,hash:0xb6fbe839]]]*/
INTERN ATTR_NORETURN
ATTR_WEAK ATTR_SECTION(".text.crt.sched.process.quick_exit") void
(LIBCCALL libc_quick_exit)(int status)
		__THROWS(...)
/*[[[body:quick_exit]]]*/
{
	/* TODO: Run quick-at-exit */
	/* TODO: Run library finalizers */
	_Exit(status);
}
/*[[[end:quick_exit]]]*/

/*[[[head:at_quick_exit,hash:0x1132ede8]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.sched.process.at_quick_exit") int
NOTHROW_NCX(LIBCCALL libc_at_quick_exit)(__atexit_func_t func)
/*[[[body:at_quick_exit]]]*/
{
	CRT_UNIMPLEMENTED("at_quick_exit"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:at_quick_exit]]]*/

/*[[[head:_Exit,hash:0xd439933e]]]*/
INTERN ATTR_NORETURN
ATTR_WEAK ATTR_SECTION(".text.crt.application.exit._Exit") void
(LIBCCALL libc__Exit)(int status)
/*[[[body:_Exit]]]*/
{
	sys_exit_group((syscall_ulong_t)(unsigned int)status);
}
/*[[[end:_Exit]]]*/

/*[[[head:drand48_r,hash:0x70a1a080]]]*/
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.drand48_r") int
NOTHROW_NCX(LIBCCALL libc_drand48_r)(struct drand48_data *__restrict buffer,
                                     double *__restrict result)
/*[[[body:drand48_r]]]*/
{
	CRT_UNIMPLEMENTED("drand48_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:drand48_r]]]*/

/*[[[head:erand48_r,hash:0x7d82e492]]]*/
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.erand48_r") int
NOTHROW_NCX(LIBCCALL libc_erand48_r)(unsigned short xsubi[3],
                                     struct drand48_data *__restrict buffer,
                                     double *__restrict result)
/*[[[body:erand48_r]]]*/
{
	CRT_UNIMPLEMENTED("erand48_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:erand48_r]]]*/

/*[[[head:lrand48_r,hash:0x84c4e864]]]*/
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.lrand48_r") int
NOTHROW_NCX(LIBCCALL libc_lrand48_r)(struct drand48_data *__restrict buffer,
                                     long *__restrict result)
/*[[[body:lrand48_r]]]*/
{
	CRT_UNIMPLEMENTED("lrand48_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:lrand48_r]]]*/

/*[[[head:nrand48_r,hash:0xe2d02489]]]*/
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.nrand48_r") int
NOTHROW_NCX(LIBCCALL libc_nrand48_r)(unsigned short xsubi[3],
                                     struct drand48_data *__restrict buffer,
                                     long *__restrict result)
/*[[[body:nrand48_r]]]*/
{
	CRT_UNIMPLEMENTED("nrand48_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:nrand48_r]]]*/

/*[[[head:mrand48_r,hash:0x6133b7f3]]]*/
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.mrand48_r") int
NOTHROW_NCX(LIBCCALL libc_mrand48_r)(struct drand48_data *__restrict buffer,
                                     long *__restrict result)
/*[[[body:mrand48_r]]]*/
{
	CRT_UNIMPLEMENTED("mrand48_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:mrand48_r]]]*/

/*[[[head:jrand48_r,hash:0xd7ba040b]]]*/
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.jrand48_r") int
NOTHROW_NCX(LIBCCALL libc_jrand48_r)(unsigned short xsubi[3],
                                     struct drand48_data *__restrict buffer,
                                     long *__restrict result)
/*[[[body:jrand48_r]]]*/
{
	CRT_UNIMPLEMENTED("jrand48_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:jrand48_r]]]*/

/*[[[head:srand48_r,hash:0x1e247ac]]]*/
INTERN NONNULL((2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.srand48_r") int
NOTHROW_NCX(LIBCCALL libc_srand48_r)(long seedval,
                                     struct drand48_data *buffer)
/*[[[body:srand48_r]]]*/
{
	CRT_UNIMPLEMENTED("srand48_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:srand48_r]]]*/

/*[[[head:seed48_r,hash:0x39aa5d30]]]*/
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.seed48_r") int
NOTHROW_NCX(LIBCCALL libc_seed48_r)(unsigned short seed16v[3],
                                    struct drand48_data *buffer)
/*[[[body:seed48_r]]]*/
{
	CRT_UNIMPLEMENTED("seed48_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:seed48_r]]]*/

/*[[[head:lcong48_r,hash:0x9d415901]]]*/
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.lcong48_r") int
NOTHROW_NCX(LIBCCALL libc_lcong48_r)(unsigned short param[7],
                                     struct drand48_data *buffer)
/*[[[body:lcong48_r]]]*/
{
	CRT_UNIMPLEMENTED("lcong48_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:lcong48_r]]]*/

/*[[[head:random_r,hash:0x3f887c80]]]*/
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.random_r") int
NOTHROW_NCX(LIBCCALL libc_random_r)(struct random_data *__restrict buf,
                                    int32_t *__restrict result)
/*[[[body:random_r]]]*/
{
	CRT_UNIMPLEMENTED("random_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:random_r]]]*/

/*[[[head:srandom_r,hash:0x63a20660]]]*/
INTERN NONNULL((2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.srandom_r") int
NOTHROW_NCX(LIBCCALL libc_srandom_r)(unsigned int seed,
                                     struct random_data *buf)
/*[[[body:srandom_r]]]*/
{
	CRT_UNIMPLEMENTED("srandom_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:srandom_r]]]*/

/*[[[head:initstate_r,hash:0xa21c140c]]]*/
INTERN NONNULL((2, 4))
ATTR_WEAK ATTR_SECTION(".text.crt.random.initstate_r") int
NOTHROW_NCX(LIBCCALL libc_initstate_r)(unsigned int seed,
                                       char *__restrict statebuf,
                                       size_t statelen,
                                       struct random_data *__restrict buf)
/*[[[body:initstate_r]]]*/
{
	CRT_UNIMPLEMENTED("initstate_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:initstate_r]]]*/

/*[[[head:setstate_r,hash:0x4004ff3b]]]*/
INTERN NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.setstate_r") int
NOTHROW_NCX(LIBCCALL libc_setstate_r)(char *__restrict statebuf,
                                      struct random_data *__restrict buf)
/*[[[body:setstate_r]]]*/
{
	CRT_UNIMPLEMENTED("setstate_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:setstate_r]]]*/

/*[[[head:on_exit,hash:0x7d41b5ea]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.sched.process.on_exit") int
NOTHROW_NCX(LIBCCALL libc_on_exit)(__on_exit_func_t func,
                                   void *arg)
/*[[[body:on_exit]]]*/
{
	CRT_UNIMPLEMENTED("on_exit"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:on_exit]]]*/

/*[[[head:clearenv,hash:0x8aa6241c]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.fs.environ.clearenv") int
NOTHROW_NCX(LIBCCALL libc_clearenv)(void)
/*[[[body:clearenv]]]*/
{
	CRT_UNIMPLEMENTED("clearenv"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:clearenv]]]*/

/*[[[head:mkstemps,hash:0xd41d0c37]]]*/
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.utility.mkstemps") int
NOTHROW_NCX(LIBCCALL libc_mkstemps)(char *template_,
                                    int suffixlen)
/*[[[body:mkstemps]]]*/
{
	CRT_UNIMPLEMENTED("mkstemps"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:mkstemps]]]*/

/*[[[head:rpmatch,hash:0x37118ebb]]]*/
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.utility.rpmatch") int
NOTHROW_NCX(LIBCCALL libc_rpmatch)(char const *response)
/*[[[body:rpmatch]]]*/
{
	CRT_UNIMPLEMENTED("rpmatch"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:rpmatch]]]*/

/*[[[head:mkstemps64,hash:0xe5ebddf0]]]*/
#if !defined(__O_LARGEFILE) || (__O_LARGEFILE+0) == 0
DEFINE_INTERN_ALIAS(libc_mkstemps64, libc_mkstemps);
#else
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.utility.mkstemps64") int
NOTHROW_NCX(LIBCCALL libc_mkstemps64)(char *template_,
                                      int suffixlen)
/*[[[body:mkstemps64]]]*/
{
	CRT_UNIMPLEMENTED("mkstemps64"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
#endif /* MAGIC:alias */
/*[[[end:mkstemps64]]]*/

/*[[[head:getloadavg,hash:0x56fb5d1c]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.system.utility.getloadavg") int
NOTHROW_RPC(LIBCCALL libc_getloadavg)(double loadavg[],
                                      int nelem)
/*[[[body:getloadavg]]]*/
{
	CRT_UNIMPLEMENTED("getloadavg"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:getloadavg]]]*/

/*[[[head:drand48,hash:0xe476ef14]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.random.drand48") double
NOTHROW_NCX(LIBCCALL libc_drand48)(void)
/*[[[body:drand48]]]*/
{
	CRT_UNIMPLEMENTED("drand48"); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:drand48]]]*/

/*[[[head:lrand48,hash:0xba108c1c]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.random.lrand48") long
NOTHROW_NCX(LIBCCALL libc_lrand48)(void)
/*[[[body:lrand48]]]*/
{
	CRT_UNIMPLEMENTED("lrand48"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:lrand48]]]*/

/*[[[head:mrand48,hash:0xfc0d4bda]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.random.mrand48") long
NOTHROW_NCX(LIBCCALL libc_mrand48)(void)
/*[[[body:mrand48]]]*/
{
	CRT_UNIMPLEMENTED("mrand48"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:mrand48]]]*/

/*[[[head:erand48,hash:0x30cde7dc]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.random.erand48") double
NOTHROW_NCX(LIBCCALL libc_erand48)(unsigned short xsubi[3])
/*[[[body:erand48]]]*/
{
	CRT_UNIMPLEMENTED("erand48"); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:erand48]]]*/

/*[[[head:nrand48,hash:0xaaa8c45f]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.random.nrand48") long
NOTHROW_NCX(LIBCCALL libc_nrand48)(unsigned short xsubi[3])
/*[[[body:nrand48]]]*/
{
	CRT_UNIMPLEMENTED("nrand48"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:nrand48]]]*/

/*[[[head:jrand48,hash:0xcaf6275b]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.random.jrand48") long
NOTHROW_NCX(LIBCCALL libc_jrand48)(unsigned short xsubi[3])
/*[[[body:jrand48]]]*/
{
	CRT_UNIMPLEMENTED("jrand48"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:jrand48]]]*/

/*[[[head:srand48,hash:0xa1619c8a]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.random.srand48") void
NOTHROW_NCX(LIBCCALL libc_srand48)(long seedval)
/*[[[body:srand48]]]*/
{
	CRT_UNIMPLEMENTED("srand48"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:srand48]]]*/

/*[[[head:seed48,hash:0xf6762ed3]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.random.seed48") unsigned short *
NOTHROW_NCX(LIBCCALL libc_seed48)(unsigned short seed16v[3])
/*[[[body:seed48]]]*/
{
	CRT_UNIMPLEMENTED("seed48"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:seed48]]]*/

/*[[[head:lcong48,hash:0x48e9c2a]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.random.lcong48") void
NOTHROW_NCX(LIBCCALL libc_lcong48)(unsigned short param[7])
/*[[[body:lcong48]]]*/
{
	CRT_UNIMPLEMENTED("lcong48"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:lcong48]]]*/

/*[[[head:putenv,hash:0x67079b1a]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.environ.putenv") int
NOTHROW_NCX(LIBCCALL libc_putenv)(char *string)
/*[[[body:putenv]]]*/
{
	CRT_UNIMPLEMENTED("putenv"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:putenv]]]*/

/*[[[head:initstate,hash:0x8d6b3324]]]*/
INTERN NONNULL((2))
ATTR_WEAK ATTR_SECTION(".text.crt.random.initstate") char *
NOTHROW_NCX(LIBCCALL libc_initstate)(unsigned int seed,
                                     char *statebuf,
                                     size_t statelen)
/*[[[body:initstate]]]*/
{
	CRT_UNIMPLEMENTED("initstate"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:initstate]]]*/

/*[[[head:setstate,hash:0xe71e285c]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.random.setstate") char *
NOTHROW_NCX(LIBCCALL libc_setstate)(char *statebuf)
/*[[[body:setstate]]]*/
{
	CRT_UNIMPLEMENTED("setstate"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:setstate]]]*/

/*[[[head:l64a,hash:0xcca9b7d0]]]*/
INTERN WUNUSED
ATTR_WEAK ATTR_SECTION(".text.crt.string.encrypt.l64a") char *
NOTHROW_NCX(LIBCCALL libc_l64a)(long n)
/*[[[body:l64a]]]*/
{
	CRT_UNIMPLEMENTED("l64a"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:l64a]]]*/

/*[[[head:a64l,hash:0xd4ffa952]]]*/
INTERN WUNUSED ATTR_PURE NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.string.encrypt.a64l") long
NOTHROW_NCX(LIBCCALL libc_a64l)(char const *s)
/*[[[body:a64l]]]*/
{
	CRT_UNIMPLEMENTED("a64l"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:a64l]]]*/

/*[[[head:realpath,hash:0xd1600417]]]*/
/* Load the filesystem location of a given file handle.
 * This function behaves similar to `readlink()', but will also function for
 * non-symlink paths, as well as always return an absolute (unambiguous) path
 * @param: resolved: A buffer of `PATH_MAX' bytes to-be filled with the resulting
 *                   path, or NULL to automatically `malloc()'ate and return a
 *                   buffer of sufficient size. */
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.property.realpath") char *
NOTHROW_RPC(LIBCCALL libc_realpath)(char const *__restrict filename,
                                    char *resolved)
/*[[[body:realpath]]]*/
{
	return libc_frealpathat(AT_FDCWD, filename, resolved,
	                        resolved ? PATH_MAX : 0, 0);
}
/*[[[end:realpath]]]*/

/*[[[head:frealpath,hash:0xb5a7006d]]]*/
/* Load the filesystem location of a given file handle.
 * This function behaves similar to `readlink("/proc/self/fd/%d" % fd)'
 * NOTE: You may also pass `NULL' for `resolved' to have a buffer of `bufsize'
 *       bytes automatically allocated in the heap, optop of which you may also
 *       pass `0' for `bufsize' to automatically determine the required buffer size. */
INTERN WUNUSED
ATTR_WEAK ATTR_SECTION(".text.crt.fs.property.frealpath") char *
NOTHROW_RPC(LIBCCALL libc_frealpath)(fd_t fd,
                                     char *resolved,
                                     size_t bufsize)
/*[[[body:frealpath]]]*/
{
	return frealpath4(fd, resolved, bufsize, 0);
}
/*[[[end:frealpath]]]*/

/*[[[head:frealpath4,hash:0x2841565d]]]*/
/* Load the filesystem location of a given file handle.
 * This function behaves similar to `readlink("/proc/self/fd/%d" % fd)'
 * @param flags: Set of `0|AT_ALTPATH|AT_DOSPATH'
 * NOTE: You may also pass `NULL' for `resolved' to have a buffer of `bufsize'
 *       bytes automatically allocated in the heap, optop of which you may also
 *       pass `0' for `bufsize' to automatically determine the required buffer size. */
INTERN WUNUSED
ATTR_WEAK ATTR_SECTION(".text.crt.fs.property.frealpath4") char *
NOTHROW_RPC(LIBCCALL libc_frealpath4)(fd_t fd,
                                      char *resolved,
                                      size_t bufsize,
                                      atflag_t flags)
/*[[[body:frealpath4]]]*/
{
	ssize_t result;
	char *buffer = resolved;
	if unlikely(flags & AT_READLINK_REQSIZE) {
		libc_seterrno(EINVAL);
		return NULL;
	}
	if (!resolved) {
		if (!bufsize) {
			/* Automatically allocate + determine buffer size. */
			bufsize = PATH_MAX;
			buffer  = (char *)malloc(bufsize);
			if unlikely(!buffer)
				bufsize = 0;
			for (;;) {
				result = sys_frealpath4(fd,
				                        buffer,
				                        bufsize,
				                        flags | AT_READLINK_REQSIZE);
				if unlikely(E_ISERR(result))
					goto err_buffer_result_errno;
				if likely((size_t)result <= bufsize)
					break;
				/* Allocate the required amount of memory. */
				resolved = (char *)realloc(buffer, (size_t)result);
				if unlikely(!resolved) {
					free(buffer);
					return NULL;
				}
				bufsize = (size_t)result;
				buffer  = resolved;
			}
			if ((size_t)result != bufsize) {
				resolved = (char *)realloc(buffer, (size_t)result);
				if likely(resolved)
					buffer = resolved;
			}
			return buffer;
		}
		buffer = (char *)malloc(bufsize);
		if unlikely(!buffer)
			goto done;
	}
	result = sys_frealpath4(fd,
	                        buffer,
	                        bufsize,
	                        flags);
	if (E_ISERR(result)) {
		if (!resolved) {
err_buffer_result_errno:
			free(buffer);
		}
		libc_seterrno(-result);
		return NULL;
	}
done:
	return buffer;
}
/*[[[end:frealpath4]]]*/

/*[[[head:frealpathat,hash:0xe40b4589]]]*/
/* Returns the absolute filesystem path for the specified file
 * When `AT_SYMLINK_FOLLOW' is given, a final symlink is dereferenced,
 * causing the pointed-to file location to be retrieved. - Otherwise, the
 * location of the link is printed instead.
 * NOTE: You may also pass `NULL' for `resolved' to have a buffer of `bufsize'
 *       bytes automatically allocated in the heap, optop of which you may also
 *       pass `0' for `bufsize' to automatically determine the required buffer size.
 * @param flags: Set of `0|AT_ALTPATH|AT_SYMLINK_FOLLOW|AT_DOSPATH' */
INTERN WUNUSED NONNULL((2))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.property.frealpathat") char *
NOTHROW_RPC(LIBCCALL libc_frealpathat)(fd_t dirfd,
                                       char const *filename,
                                       char *resolved,
                                       size_t bufsize,
                                       atflag_t flags)
/*[[[body:frealpathat]]]*/
{
	ssize_t result;
	char *buffer = resolved;
	if unlikely(flags & AT_READLINK_REQSIZE) {
		libc_seterrno(EINVAL);
		return NULL;
	}
	if (!resolved) {
		if (!bufsize) {
			/* Automatically allocate + determine buffer size. */
			bufsize = PATH_MAX;
			buffer  = (char *)malloc(bufsize);
			if unlikely(!buffer)
				bufsize = 0;
			for (;;) {
				result = sys_frealpathat(dirfd,
				                         filename,
				                         buffer,
				                         bufsize,
				                         flags | AT_READLINK_REQSIZE);
				if unlikely(E_ISERR(result))
					goto err_buffer_result_errno;
				if
					likely((size_t)result <= bufsize)
				break;
				/* Allocate the required amount of memory. */
				resolved = (char *)realloc(buffer, (size_t)result);
				if unlikely(!resolved) {
					free(buffer);
					return NULL;
				}
				bufsize = (size_t)result;
				buffer  = resolved;
			}
			if ((size_t)result != bufsize) {
				resolved = (char *)realloc(buffer, (size_t)result);
				if likely(resolved)
					buffer = resolved;
			}
			return buffer;
		}
		buffer = (char *)malloc(bufsize);
		if unlikely(!buffer)
			goto done;
	}
	result = sys_frealpathat(dirfd,
	                         filename,
	                         buffer,
	                         bufsize,
	                         flags);
	if (E_ISERR(result)) {
		if (!resolved) {
err_buffer_result_errno:
			free(buffer);
		}
		libc_seterrno(-result);
		return NULL;
	}
done:
	return buffer;
}
/*[[[end:frealpathat]]]*/

/*[[[head:setenv,hash:0x9d1d37c1]]]*/
INTERN NONNULL((2))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.environ.setenv") int
NOTHROW_NCX(LIBCCALL libc_setenv)(char const *varname,
                                  char const *val,
                                  int replace)
/*[[[body:setenv]]]*/
{
	CRT_UNIMPLEMENTED("setenv"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:setenv]]]*/

/*[[[head:unsetenv,hash:0x661a2cdf]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.environ.unsetenv") int
NOTHROW_NCX(LIBCCALL libc_unsetenv)(char const *varname)
/*[[[body:unsetenv]]]*/
{
	CRT_UNIMPLEMENTED("unsetenv"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:unsetenv]]]*/

/*[[[head:mktemp,hash:0xad85424a]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.utility.mktemp") char *
NOTHROW_NCX(LIBCCALL libc_mktemp)(char *template_)
/*[[[body:mktemp]]]*/
{
	CRT_UNIMPLEMENTED("mktemp"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:mktemp]]]*/

/*[[[head:mkstemp,hash:0xaa913171]]]*/
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.utility.mkstemp") int
NOTHROW_NCX(LIBCCALL libc_mkstemp)(char *template_)
/*[[[body:mkstemp]]]*/
{
	CRT_UNIMPLEMENTED("mkstemp"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:mkstemp]]]*/

/*[[[head:mkdtemp,hash:0xf071272]]]*/
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.utility.mkdtemp") char *
NOTHROW_NCX(LIBCCALL libc_mkdtemp)(char *template_)
/*[[[body:mkdtemp]]]*/
{
	CRT_UNIMPLEMENTED("mkdtemp"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:mkdtemp]]]*/

/*[[[head:setkey,hash:0x35842a81]]]*/
INTERN NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.setkey") void
NOTHROW_NCX(LIBCCALL libc_setkey)(char const *key)
/*[[[body:setkey]]]*/
{
	CRT_UNIMPLEMENTED("setkey"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:setkey]]]*/

/*[[[head:grantpt,hash:0x484c4b1e]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.grantpt") int
NOTHROW_NCX(LIBCCALL libc_grantpt)(fd_t fd)
/*[[[body:grantpt]]]*/
{
	CRT_UNIMPLEMENTED("grantpt"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:grantpt]]]*/

/*[[[head:unlockpt,hash:0x96e570d6]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.unlockpt") int
NOTHROW_NCX(LIBCCALL libc_unlockpt)(fd_t fd)
/*[[[body:unlockpt]]]*/
{
	CRT_UNIMPLEMENTED("unlockpt"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:unlockpt]]]*/

/*[[[head:ptsname,hash:0x67dd8a98]]]*/
INTERN WUNUSED
ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.ptsname") char *
NOTHROW_NCX(LIBCCALL libc_ptsname)(fd_t fd)
/*[[[body:ptsname]]]*/
{
	CRT_UNIMPLEMENTED("ptsname"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:ptsname]]]*/

/*[[[head:posix_openpt,hash:0x1c0f70a9]]]*/
INTERN WUNUSED
ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.posix_openpt") int
NOTHROW_RPC(LIBCCALL libc_posix_openpt)(oflag_t oflag)
/*[[[body:posix_openpt]]]*/
{
	CRT_UNIMPLEMENTED("posix_openpt"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:posix_openpt]]]*/

/*[[[head:getpt,hash:0x9ff39e58]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.getpt") int
NOTHROW_RPC(LIBCCALL libc_getpt)(void)
/*[[[body:getpt]]]*/
{
	CRT_UNIMPLEMENTED("getpt"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:getpt]]]*/

/*[[[head:secure_getenv,hash:0x3d7d1988]]]*/
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.environ.secure_getenv") char *
NOTHROW_NCX(LIBCCALL libc_secure_getenv)(char const *varname)
/*[[[body:secure_getenv]]]*/
{
	CRT_UNIMPLEMENTED("secure_getenv"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:secure_getenv]]]*/

/*[[[head:ptsname_r,hash:0xf4cf98a0]]]*/
INTERN NONNULL((2))
ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.ptsname_r") int
NOTHROW_NCX(LIBCCALL libc_ptsname_r)(fd_t fd,
                                     char *buf,
                                     size_t buflen)
/*[[[body:ptsname_r]]]*/
{
	CRT_UNIMPLEMENTED("ptsname_r"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:ptsname_r]]]*/

/*[[[head:canonicalize_file_name,hash:0x145ba6eb]]]*/
/* Return the result of `realpath(filename)' as a `malloc()'-allocated buffer
 * Upon error, `NULL' is returned instead */
INTERN ATTR_MALLOC WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.property.canonicalize_file_name") char *
NOTHROW_RPC(LIBCCALL libc_canonicalize_file_name)(char const *filename)
/*[[[body:canonicalize_file_name]]]*/
{
	return realpath(filename, NULL);
}
/*[[[end:canonicalize_file_name]]]*/

/*[[[head:mkostemp,hash:0xfef7206]]]*/
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.utility.mkostemp") int
NOTHROW_RPC(LIBCCALL libc_mkostemp)(char *template_,
                                    int flags)
/*[[[body:mkostemp]]]*/
{
	CRT_UNIMPLEMENTED("mkostemp"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:mkostemp]]]*/

/*[[[head:mkostemps,hash:0xdf3fbd04]]]*/
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.utility.mkostemps") int
NOTHROW_RPC(LIBCCALL libc_mkostemps)(char *template_,
                                     int suffixlen,
                                     int flags)
/*[[[body:mkostemps]]]*/
{
	CRT_UNIMPLEMENTED("mkostemps"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:mkostemps]]]*/

/*[[[head:mkostemp64,hash:0xb0f34a33]]]*/
#if !defined(__O_LARGEFILE) || (__O_LARGEFILE+0) == 0
DEFINE_INTERN_ALIAS(libc_mkostemp64, libc_mkostemp);
#else
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.utility.mkostemp64") int
NOTHROW_RPC(LIBCCALL libc_mkostemp64)(char *template_,
                                      int flags)
/*[[[body:mkostemp64]]]*/
{
	CRT_UNIMPLEMENTED("mkostemp64"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
#endif /* MAGIC:alias */
/*[[[end:mkostemp64]]]*/

/*[[[head:mkostemps64,hash:0x6a60b22c]]]*/
#if !defined(__O_LARGEFILE) || (__O_LARGEFILE+0) == 0
DEFINE_INTERN_ALIAS(libc_mkostemps64, libc_mkostemps);
#else
INTERN WUNUSED NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.fs.utility.mkostemps64") int
NOTHROW_RPC(LIBCCALL libc_mkostemps64)(char *template_,
                                       int suffixlen,
                                       int flags)
/*[[[body:mkostemps64]]]*/
{
	CRT_UNIMPLEMENTED("mkostemps64"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
#endif /* MAGIC:alias */
/*[[[end:mkostemps64]]]*/

/* `__errno_location' is provided in libc/errno.c */
/*[[[skip:__errno_location]]]*/

/*[[[head:_putenv_s,hash:0xf663a84a]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.dos.fs.environ._putenv_s") errno_t
NOTHROW_NCX(LIBCCALL libc__putenv_s)(char const *varname,
                                     char const *val)
/*[[[body:_putenv_s]]]*/
/*AUTO*/{
	return libc_setenv(varname, val, 1) ? __libc_geterrno_or(__EINVAL) : 0;
}
/*[[[end:_putenv_s]]]*/

/*[[[head:__p___argv,hash:0xf082217c]]]*/
INTERN ATTR_RETNONNULL ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p___argv") char ***
NOTHROW_NCX(LIBCCALL libc___p___argv)(void)
/*[[[body:__p___argv]]]*/
{
	CRT_UNIMPLEMENTED("__p___argv"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:__p___argv]]]*/

/*[[[head:_aligned_malloc,hash:0xb16d473b]]]*/
INTERN WUNUSED ATTR_ALLOC_ALIGN(2) ATTR_ALLOC_SIZE((1)) ATTR_MALLOC
ATTR_WEAK ATTR_SECTION(".text.crt.dos.heap._aligned_malloc") void *
NOTHROW_NCX(LIBCCALL libc__aligned_malloc)(size_t num_bytes,
                                           size_t min_alignment)
/*[[[body:_aligned_malloc]]]*/
{
	CRT_UNIMPLEMENTED("_aligned_malloc"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:_aligned_malloc]]]*/

/*[[[head:DOS$__p__wenviron,hash:0xcd1d646e]]]*/
INTERN ATTR_RETNONNULL ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p__wenviron") char16_t ***
NOTHROW_NCX(LIBDCALL libd___p__wenviron)(void)
/*[[[body:DOS$__p__wenviron]]]*/
{
	CRT_UNIMPLEMENTED("__p__wenviron"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:DOS$__p__wenviron]]]*/

/*[[[head:DOS$__p___wargv,hash:0xd6c139e]]]*/
INTERN ATTR_RETNONNULL ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p___wargv") char16_t ***
NOTHROW_NCX(LIBDCALL libd___p___wargv)(void)
/*[[[body:DOS$__p___wargv]]]*/
{
	CRT_UNIMPLEMENTED("__p___wargv"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:DOS$__p___wargv]]]*/

/*[[[head:_dupenv_s,hash:0x2b71104c]]]*/
INTERN NONNULL((1, 2, 3))
ATTR_WEAK ATTR_SECTION(".text.crt.dos.utility._dupenv_s") errno_t
NOTHROW_NCX(LIBCCALL libc__dupenv_s)(char **__restrict pbuf,
                                     size_t *pbuflen,
                                     char const *varname)
/*[[[body:_dupenv_s]]]*/
{
	CRT_UNIMPLEMENTED("_dupenv_s"); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:_dupenv_s]]]*/

/*[[[head:__p___initenv,hash:0x1450f43c]]]*/
/* Access to the initial environment block */
INTERN ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p___initenv") char ***
NOTHROW_NCX(LIBCCALL libc___p___initenv)(void)
/*[[[body:__p___initenv]]]*/
{
	CRT_UNIMPLEMENTED("__p___initenv"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:__p___initenv]]]*/

/*[[[head:_fullpath,hash:0x56b2f4cd]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.dos.fs.utility._fullpath") char *
NOTHROW_RPC(LIBCCALL libc__fullpath)(char *buf,
                                     char const *path,
                                     size_t buflen)
/*[[[body:_fullpath]]]*/
{
	CRT_UNIMPLEMENTED("_fullpath"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:_fullpath]]]*/

/*[[[head:_aligned_free,hash:0xf713bed6]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.dos.heap._aligned_free") void
NOTHROW_NCX(LIBCCALL libc__aligned_free)(void *mptr)
/*[[[body:_aligned_free]]]*/
{
	CRT_UNIMPLEMENTED("_aligned_free"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:_aligned_free]]]*/

/*[[[head:DOS$__p___winitenv,hash:0xd9c82265]]]*/
/* Access to the initial environment block */
INTERN ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p___winitenv") char16_t ***
NOTHROW_NCX(LIBDCALL libd___p___winitenv)(void)
/*[[[body:DOS$__p___winitenv]]]*/
{
	CRT_UNIMPLEMENTED("__p___winitenv"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:DOS$__p___winitenv]]]*/

/*[[[head:_aligned_recalloc,hash:0xbf024c7e]]]*/
INTERN WUNUSED ATTR_ALLOC_ALIGN(4) ATTR_ALLOC_SIZE((2, 3))
ATTR_WEAK ATTR_SECTION(".text.crt.dos.heap._aligned_recalloc") void *
NOTHROW_NCX(LIBCCALL libc__aligned_recalloc)(void *mptr,
                                             size_t count,
                                             size_t num_bytes,
                                             size_t min_alignment)
/*[[[body:_aligned_recalloc]]]*/
{
	CRT_UNIMPLEMENTED("_aligned_recalloc"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:_aligned_recalloc]]]*/

/*[[[head:__doserrno,hash:0xa10d8627]]]*/
INTERN ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.errno.__doserrno") u32 *
NOTHROW_NCX(LIBCCALL libc___doserrno)(void)
/*[[[body:__doserrno]]]*/
{
	CRT_UNIMPLEMENTED("__doserrno"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:__doserrno]]]*/

/*[[[head:__p___argc,hash:0xc22beea3]]]*/
INTERN ATTR_RETNONNULL ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p___argc") int *
NOTHROW_NCX(LIBCCALL libc___p___argc)(void)
/*[[[body:__p___argc]]]*/
{
	CRT_UNIMPLEMENTED("__p___argc"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:__p___argc]]]*/

/*[[[head:__p___wargv,hash:0xec1d3872]]]*/
INTERN ATTR_RETNONNULL ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p___wargv") char32_t ***
NOTHROW_NCX(LIBCCALL libc___p___wargv)(void)
/*[[[body:__p___wargv]]]*/
{
	CRT_UNIMPLEMENTED("__p___wargv"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:__p___wargv]]]*/

/*[[[head:_get_doserrno,hash:0xa4504847]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.dos.errno._get_doserrno") errno_t
NOTHROW_NCX(LIBCCALL libc__get_doserrno)(u32 *perr)
/*[[[body:_get_doserrno]]]*/
{
	CRT_UNIMPLEMENTED("_get_doserrno"); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:_get_doserrno]]]*/

/*[[[head:_aligned_offset_malloc,hash:0x32f8a700]]]*/
INTERN WUNUSED ATTR_ALLOC_ALIGN(1) ATTR_MALLOC
ATTR_WEAK ATTR_SECTION(".text.crt.dos.heap._aligned_offset_malloc") void *
NOTHROW_NCX(LIBCCALL libc__aligned_offset_malloc)(size_t num_bytes,
                                                  size_t min_alignment,
                                                  size_t offset)
/*[[[body:_aligned_offset_malloc]]]*/
{
	CRT_UNIMPLEMENTED("_aligned_offset_malloc"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:_aligned_offset_malloc]]]*/

/*[[[head:getenv_s,hash:0x6e4da88a]]]*/
INTERN NONNULL((1, 2, 4))
ATTR_WEAK ATTR_SECTION(".text.crt.dos.utility.getenv_s") errno_t
NOTHROW_NCX(LIBCCALL libc_getenv_s)(size_t *psize,
                                    char *buf,
                                    rsize_t bufsize,
                                    char const *varname)
/*[[[body:getenv_s]]]*/
{
	CRT_UNIMPLEMENTED("getenv_s"); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:getenv_s]]]*/

/*[[[head:__p__pgmptr,hash:0x718aa545]]]*/
INTERN ATTR_RETNONNULL ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p__pgmptr") char **
NOTHROW_NCX(LIBCCALL libc___p__pgmptr)(void)
/*[[[body:__p__pgmptr]]]*/
{
	CRT_UNIMPLEMENTED("__p__pgmptr"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:__p__pgmptr]]]*/

/*[[[head:_aligned_offset_realloc,hash:0x68a149c5]]]*/
INTERN WUNUSED ATTR_ALLOC_SIZE((2))
ATTR_WEAK ATTR_SECTION(".text.crt.dos.heap._aligned_offset_realloc") void *
NOTHROW_NCX(LIBCCALL libc__aligned_offset_realloc)(void *mptr,
                                                   size_t newsize,
                                                   size_t min_alignment,
                                                   size_t offset)
/*[[[body:_aligned_offset_realloc]]]*/
{
	CRT_UNIMPLEMENTED("_aligned_offset_realloc"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:_aligned_offset_realloc]]]*/

/*[[[head:__p__wpgmptr,hash:0xe0747bc]]]*/
INTERN ATTR_RETNONNULL ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p__wpgmptr") char32_t **
NOTHROW_NCX(LIBCCALL libc___p__wpgmptr)(void)
/*[[[body:__p__wpgmptr]]]*/
{
	CRT_UNIMPLEMENTED("__p__wpgmptr"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:__p__wpgmptr]]]*/

/*[[[head:_aligned_offset_recalloc,hash:0x16f50052]]]*/
INTERN WUNUSED ATTR_ALLOC_SIZE((2, 3))
ATTR_WEAK ATTR_SECTION(".text.crt.dos.heap._aligned_offset_recalloc") void *
NOTHROW_NCX(LIBCCALL libc__aligned_offset_recalloc)(void *mptr,
                                                    size_t count,
                                                    size_t num_bytes,
                                                    size_t min_alignment,
                                                    size_t offset)
/*[[[body:_aligned_offset_recalloc]]]*/
{
	CRT_UNIMPLEMENTED("_aligned_offset_recalloc"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:_aligned_offset_recalloc]]]*/

/*[[[head:__p___winitenv,hash:0x886db8ef]]]*/
/* Access to the initial environment block */
INTERN ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p___winitenv") char32_t ***
NOTHROW_NCX(LIBCCALL libc___p___winitenv)(void)
/*[[[body:__p___winitenv]]]*/
{
	CRT_UNIMPLEMENTED("__p___winitenv"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:__p___winitenv]]]*/

/*[[[head:__p__wenviron,hash:0x4ac2f15b]]]*/
INTERN ATTR_RETNONNULL ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p__wenviron") char32_t ***
NOTHROW_NCX(LIBCCALL libc___p__wenviron)(void)
/*[[[body:__p__wenviron]]]*/
{
	CRT_UNIMPLEMENTED("__p__wenviron"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:__p__wenviron]]]*/

/*[[[head:_recalloc,hash:0xfd7e1c8a]]]*/
INTERN WUNUSED ATTR_MALL_DEFAULT_ALIGNED ATTR_ALLOC_SIZE((2, 3))
ATTR_WEAK ATTR_SECTION(".text.crt.dos.heap._recalloc") void *
NOTHROW_NCX(LIBCCALL libc__recalloc)(void *mptr,
                                     size_t count,
                                     size_t num_bytes)
/*[[[body:_recalloc]]]*/
{
	CRT_UNIMPLEMENTED("_recalloc"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:_recalloc]]]*/

/*[[[head:_set_doserrno,hash:0x2ec76865]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.dos.errno._set_doserrno") errno_t
NOTHROW_NCX(LIBCCALL libc__set_doserrno)(u32 err)
/*[[[body:_set_doserrno]]]*/
{
	CRT_UNIMPLEMENTED("_set_doserrno"); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:_set_doserrno]]]*/

/*[[[head:_set_error_mode,hash:0x63a2193b]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.dos.errno._set_error_mode") int
NOTHROW_NCX(LIBCCALL libc__set_error_mode)(int mode)
/*[[[body:_set_error_mode]]]*/
{
	CRT_UNIMPLEMENTED("_set_error_mode"); /* TODO */
	libc_seterrno(ENOSYS);
	return -1;
}
/*[[[end:_set_error_mode]]]*/

/*[[[head:DOS$__p__wpgmptr,hash:0x603c4710]]]*/
INTERN ATTR_RETNONNULL ATTR_CONST
ATTR_WEAK ATTR_SECTION(".text.crt.dos.application.init.__p__wpgmptr") char16_t **
NOTHROW_NCX(LIBDCALL libd___p__wpgmptr)(void)
/*[[[body:DOS$__p__wpgmptr]]]*/
{
	CRT_UNIMPLEMENTED("__p__wpgmptr"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:DOS$__p__wpgmptr]]]*/

/*[[[head:_aligned_realloc,hash:0x1c18121b]]]*/
INTERN WUNUSED ATTR_ALLOC_ALIGN(3) ATTR_ALLOC_SIZE((2))
ATTR_WEAK ATTR_SECTION(".text.crt.dos.heap._aligned_realloc") void *
NOTHROW_NCX(LIBCCALL libc__aligned_realloc)(void *mptr,
                                            size_t newsize,
                                            size_t min_alignment)
/*[[[body:_aligned_realloc]]]*/
{
	CRT_UNIMPLEMENTED("_aligned_realloc"); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:_aligned_realloc]]]*/

/*[[[head:onexit,hash:0x99712df6]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.unicode.static.convert.onexit") onexit_t
NOTHROW_NCX(LIBCCALL libc_onexit)(onexit_t func)
/*[[[body:onexit]]]*/
{
	CRT_UNIMPLEMENTED("onexit"); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:onexit]]]*/

/*[[[head:_wperror,hash:0xa960adb7]]]*/
INTERN ATTR_COLD
ATTR_WEAK ATTR_SECTION(".text.crt.dos.errno._wperror") void
NOTHROW_RPC(LIBCCALL libc__wperror)(char32_t const *errmsg)
/*[[[body:_wperror]]]*/
{
	CRT_UNIMPLEMENTED("_wperror"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:_wperror]]]*/

/*[[[head:_seterrormode,hash:0xbf3073c7]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.dos.errno._seterrormode") void
NOTHROW_NCX(LIBCCALL libc__seterrormode)(int mode)
/*[[[body:_seterrormode]]]*/
{
	CRT_UNIMPLEMENTED("_seterrormode"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:_seterrormode]]]*/

/*[[[head:_searchenv_s,hash:0x5b23e21d]]]*/
INTERN NONNULL((1, 2, 3))
ATTR_WEAK ATTR_SECTION(".text.crt.dos.fs.utility._searchenv_s") errno_t
NOTHROW_RPC(LIBCCALL libc__searchenv_s)(char const *file,
                                        char const *envvar,
                                        char *__restrict resultpath,
                                        size_t buflen)
/*[[[body:_searchenv_s]]]*/
{
	CRT_UNIMPLEMENTED("_searchenv_s"); /* TODO */
	libc_seterrno(ENOSYS);
	return 0;
}
/*[[[end:_searchenv_s]]]*/

/*[[[head:DOS$_wperror,hash:0x3d18c5f2]]]*/
INTERN ATTR_COLD
ATTR_WEAK ATTR_SECTION(".text.crt.dos.errno._wperror") void
NOTHROW_RPC(LIBDCALL libd__wperror)(char16_t const *errmsg)
/*[[[body:DOS$_wperror]]]*/
{
	CRT_UNIMPLEMENTED("_wperror"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:DOS$_wperror]]]*/

/*[[[head:_searchenv,hash:0x8f8c7cd2]]]*/
INTERN NONNULL((1, 2, 3))
ATTR_WEAK ATTR_SECTION(".text.crt.dos.fs.utility._searchenv") void
NOTHROW_RPC(LIBCCALL libc__searchenv)(char const *file,
                                      char const *envvar,
                                      char *__restrict resultpath)
/*[[[body:_searchenv]]]*/
/*AUTO*/{
	libc__searchenv_s(file, envvar, resultpath, (size_t)-1);
}
/*[[[end:_searchenv]]]*/

/*[[[head:_beep,hash:0x23e2d102]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.dos.system._beep") void
NOTHROW_NCX(LIBCCALL libc__beep)(unsigned int freq,
                                 unsigned int duration)
/*[[[body:_beep]]]*/
{
	CRT_UNIMPLEMENTED("_beep"); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:_beep]]]*/

/*[[[end:implementation]]]*/



/*[[[start:exports,hash:0x921d191d]]]*/
DEFINE_PUBLIC_WEAK_ALIAS(getenv, libc_getenv);
DEFINE_PUBLIC_WEAK_ALIAS(system, libc_system);
DEFINE_PUBLIC_WEAK_ALIAS(abort, libc_abort);
DEFINE_PUBLIC_WEAK_ALIAS(exit, libc_exit);
DEFINE_PUBLIC_WEAK_ALIAS(atexit, libc_atexit);
DEFINE_PUBLIC_WEAK_ALIAS(quick_exit, libc_quick_exit);
DEFINE_PUBLIC_WEAK_ALIAS(at_quick_exit, libc_at_quick_exit);
DEFINE_PUBLIC_WEAK_ALIAS(_Exit, libc__Exit);
DEFINE_PUBLIC_WEAK_ALIAS(_exit, libc__Exit);
DEFINE_PUBLIC_WEAK_ALIAS(drand48_r, libc_drand48_r);
DEFINE_PUBLIC_WEAK_ALIAS(erand48_r, libc_erand48_r);
DEFINE_PUBLIC_WEAK_ALIAS(lrand48_r, libc_lrand48_r);
DEFINE_PUBLIC_WEAK_ALIAS(nrand48_r, libc_nrand48_r);
DEFINE_PUBLIC_WEAK_ALIAS(mrand48_r, libc_mrand48_r);
DEFINE_PUBLIC_WEAK_ALIAS(jrand48_r, libc_jrand48_r);
DEFINE_PUBLIC_WEAK_ALIAS(srand48_r, libc_srand48_r);
DEFINE_PUBLIC_WEAK_ALIAS(seed48_r, libc_seed48_r);
DEFINE_PUBLIC_WEAK_ALIAS(lcong48_r, libc_lcong48_r);
DEFINE_PUBLIC_WEAK_ALIAS(random_r, libc_random_r);
DEFINE_PUBLIC_WEAK_ALIAS(srandom_r, libc_srandom_r);
DEFINE_PUBLIC_WEAK_ALIAS(initstate_r, libc_initstate_r);
DEFINE_PUBLIC_WEAK_ALIAS(setstate_r, libc_setstate_r);
DEFINE_PUBLIC_WEAK_ALIAS(on_exit, libc_on_exit);
DEFINE_PUBLIC_WEAK_ALIAS(clearenv, libc_clearenv);
DEFINE_PUBLIC_WEAK_ALIAS(mkstemps, libc_mkstemps);
DEFINE_PUBLIC_WEAK_ALIAS(rpmatch, libc_rpmatch);
DEFINE_PUBLIC_WEAK_ALIAS(mkstemps64, libc_mkstemps64);
DEFINE_PUBLIC_WEAK_ALIAS(getloadavg, libc_getloadavg);
DEFINE_PUBLIC_WEAK_ALIAS(drand48, libc_drand48);
DEFINE_PUBLIC_WEAK_ALIAS(lrand48, libc_lrand48);
DEFINE_PUBLIC_WEAK_ALIAS(mrand48, libc_mrand48);
DEFINE_PUBLIC_WEAK_ALIAS(erand48, libc_erand48);
DEFINE_PUBLIC_WEAK_ALIAS(nrand48, libc_nrand48);
DEFINE_PUBLIC_WEAK_ALIAS(jrand48, libc_jrand48);
DEFINE_PUBLIC_WEAK_ALIAS(srand48, libc_srand48);
DEFINE_PUBLIC_WEAK_ALIAS(seed48, libc_seed48);
DEFINE_PUBLIC_WEAK_ALIAS(lcong48, libc_lcong48);
DEFINE_PUBLIC_WEAK_ALIAS(putenv, libc_putenv);
DEFINE_PUBLIC_WEAK_ALIAS(_putenv, libc_putenv);
DEFINE_PUBLIC_WEAK_ALIAS(initstate, libc_initstate);
DEFINE_PUBLIC_WEAK_ALIAS(setstate, libc_setstate);
DEFINE_PUBLIC_WEAK_ALIAS(l64a, libc_l64a);
DEFINE_PUBLIC_WEAK_ALIAS(a64l, libc_a64l);
DEFINE_PUBLIC_WEAK_ALIAS(realpath, libc_realpath);
DEFINE_PUBLIC_WEAK_ALIAS(frealpath, libc_frealpath);
DEFINE_PUBLIC_WEAK_ALIAS(frealpath4, libc_frealpath4);
DEFINE_PUBLIC_WEAK_ALIAS(frealpathat, libc_frealpathat);
DEFINE_PUBLIC_WEAK_ALIAS(setenv, libc_setenv);
DEFINE_PUBLIC_WEAK_ALIAS(unsetenv, libc_unsetenv);
DEFINE_PUBLIC_WEAK_ALIAS(mktemp, libc_mktemp);
DEFINE_PUBLIC_WEAK_ALIAS(mkstemp, libc_mkstemp);
DEFINE_PUBLIC_WEAK_ALIAS(mkdtemp, libc_mkdtemp);
DEFINE_PUBLIC_WEAK_ALIAS(setkey, libc_setkey);
DEFINE_PUBLIC_WEAK_ALIAS(grantpt, libc_grantpt);
DEFINE_PUBLIC_WEAK_ALIAS(unlockpt, libc_unlockpt);
DEFINE_PUBLIC_WEAK_ALIAS(ptsname, libc_ptsname);
DEFINE_PUBLIC_WEAK_ALIAS(posix_openpt, libc_posix_openpt);
DEFINE_PUBLIC_WEAK_ALIAS(secure_getenv, libc_secure_getenv);
DEFINE_PUBLIC_WEAK_ALIAS(ptsname_r, libc_ptsname_r);
DEFINE_PUBLIC_WEAK_ALIAS(getpt, libc_getpt);
DEFINE_PUBLIC_WEAK_ALIAS(canonicalize_file_name, libc_canonicalize_file_name);
DEFINE_PUBLIC_WEAK_ALIAS(mkostemp, libc_mkostemp);
DEFINE_PUBLIC_WEAK_ALIAS(mkostemps, libc_mkostemps);
DEFINE_PUBLIC_WEAK_ALIAS(mkostemp64, libc_mkostemp64);
DEFINE_PUBLIC_WEAK_ALIAS(mkostemps64, libc_mkostemps64);
DEFINE_PUBLIC_WEAK_ALIAS(__doserrno, libc___doserrno);
DEFINE_PUBLIC_WEAK_ALIAS(_get_doserrno, libc__get_doserrno);
DEFINE_PUBLIC_WEAK_ALIAS(_set_doserrno, libc__set_doserrno);
DEFINE_PUBLIC_WEAK_ALIAS(__p___argc, libc___p___argc);
DEFINE_PUBLIC_WEAK_ALIAS(__p___argv, libc___p___argv);
DEFINE_PUBLIC_WEAK_ALIAS(__p__pgmptr, libc___p__pgmptr);
DEFINE_PUBLIC_WEAK_ALIAS(__p___wargv, libc___p___wargv);
DEFINE_PUBLIC_WEAK_ALIAS(DOS$__p___wargv, libd___p___wargv);
DEFINE_PUBLIC_WEAK_ALIAS(__p__wenviron, libc___p__wenviron);
DEFINE_PUBLIC_WEAK_ALIAS(DOS$__p__wenviron, libd___p__wenviron);
DEFINE_PUBLIC_WEAK_ALIAS(__p__wpgmptr, libc___p__wpgmptr);
DEFINE_PUBLIC_WEAK_ALIAS(DOS$__p__wpgmptr, libd___p__wpgmptr);
DEFINE_PUBLIC_WEAK_ALIAS(__p___initenv, libc___p___initenv);
DEFINE_PUBLIC_WEAK_ALIAS(__p___winitenv, libc___p___winitenv);
DEFINE_PUBLIC_WEAK_ALIAS(DOS$__p___winitenv, libd___p___winitenv);
DEFINE_PUBLIC_WEAK_ALIAS(getenv_s, libc_getenv_s);
DEFINE_PUBLIC_WEAK_ALIAS(_dupenv_s, libc__dupenv_s);
DEFINE_PUBLIC_WEAK_ALIAS(_recalloc, libc__recalloc);
DEFINE_PUBLIC_WEAK_ALIAS(_aligned_malloc, libc__aligned_malloc);
DEFINE_PUBLIC_WEAK_ALIAS(_aligned_offset_malloc, libc__aligned_offset_malloc);
DEFINE_PUBLIC_WEAK_ALIAS(_aligned_realloc, libc__aligned_realloc);
DEFINE_PUBLIC_WEAK_ALIAS(_aligned_recalloc, libc__aligned_recalloc);
DEFINE_PUBLIC_WEAK_ALIAS(_aligned_offset_realloc, libc__aligned_offset_realloc);
DEFINE_PUBLIC_WEAK_ALIAS(_aligned_offset_recalloc, libc__aligned_offset_recalloc);
DEFINE_PUBLIC_WEAK_ALIAS(_aligned_free, libc__aligned_free);
DEFINE_PUBLIC_WEAK_ALIAS(_fullpath, libc__fullpath);
DEFINE_PUBLIC_WEAK_ALIAS(_putenv_s, libc__putenv_s);
DEFINE_PUBLIC_WEAK_ALIAS(_searchenv, libc__searchenv);
DEFINE_PUBLIC_WEAK_ALIAS(_searchenv_s, libc__searchenv_s);
DEFINE_PUBLIC_WEAK_ALIAS(_seterrormode, libc__seterrormode);
DEFINE_PUBLIC_WEAK_ALIAS(_set_error_mode, libc__set_error_mode);
DEFINE_PUBLIC_WEAK_ALIAS(_beep, libc__beep);
DEFINE_PUBLIC_WEAK_ALIAS(_wperror, libc__wperror);
DEFINE_PUBLIC_WEAK_ALIAS(DOS$_wperror, libd__wperror);
DEFINE_PUBLIC_WEAK_ALIAS(onexit, libc_onexit);
DEFINE_PUBLIC_WEAK_ALIAS(_onexit, libc_onexit);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_STDLIB_C */
