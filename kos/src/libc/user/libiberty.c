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
#ifndef GUARD_LIBC_USER_LIBIBERTY_C
#define GUARD_LIBC_USER_LIBIBERTY_C 1

#include "../api.h"
/**/

#include <kos/syscalls.h>
#include <linux/kcmp.h>
#include <sys/stat.h>

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <syscall.h>
#include <unistd.h>

#include "../libc/dl.h"
#include "../libc/globals.h"
#include "libiberty.h"

DECL_BEGIN

PRIVATE ATTR_SECTION(".bss.crt.libiberty")
char const *libc_xmalloc_program_name = NULL;

/*[[[head:libc_xmalloc_set_program_name,hash:CRC-32=0x72744191]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") void
NOTHROW_NCX(LIBCCALL libc_xmalloc_set_program_name)(char const *progname)
/*[[[body:libc_xmalloc_set_program_name]]]*/
{
	libc_xmalloc_program_name = progname;
}
/*[[[end:libc_xmalloc_set_program_name]]]*/


DEFINE_PUBLIC_ALIAS(xmalloc_failed, libc_xmalloc_failed_fallback);
INTERN ATTR_NORETURN ATTR_SECTION(".text.crt.libiberty") void
(LIBCCALL libc_xmalloc_failed_fallback)(size_t num_bytes) THROWS(...) {
	struct mallinfo2 info = mallinfo2();
	char const *program_name = libc_xmalloc_program_name;
	/* KOS extension: if you never called `xmalloc_set_program_name(3)',
	 *                we just use the `program_invocation_short_name' as
	 *                exposed in <errno.h> and defined by libdl.so */
	if (program_name == NULL)
		program_name = program_invocation_short_name;
	if (program_name == NULL)
		program_name = "";
	fprintf(stderr,
	        "\n%s%sout of memory allocating %" PRIuSIZ " bytes after a total of %" PRIuSIZ " bytes\n",
	        program_name, *program_name ? ": " : "", num_bytes, info.uordblks);
	xexit(1);
}

/*[[[skip:libc_xmalloc_failed]]]*/
INTERN ATTR_NORETURN ATTR_SECTION(".text.crt.libiberty") void
(LIBCCALL libc_xmalloc_failed)(size_t num_bytes) THROWS(...) {
	void (LIBCCALL *pdyn_xmalloc_failed)(size_t num_bytes);
	/* Allow the hosting program to define its own `xmalloc_failed()'
	 * function  which  it could  then (theoretically)  implement by:
	 *
	 * Throwing an exception:
	 * >> THROW(E_BADALLOC_INSUFFICIENT_HEAP_MEMORY, num_bytes);
	 *
	 * longjmp-ing  up  the stack:
	 * >> longjmp(oom_handler, 1);
	 *
	 * Or doing something else entirely.
	 */
	*(void **)&pdyn_xmalloc_failed = dlsym(RTLD_DEFAULT, "xmalloc_failed");
	if unlikely(!pdyn_xmalloc_failed)
		pdyn_xmalloc_failed = &libc_xmalloc_failed_fallback; /* Shouldn't happen. */
	(*pdyn_xmalloc_failed)(num_bytes);

	/* Shouldn't get here, but if the user's override doesn't behave
	 * like it should, we just fallthru to the default  oom-handler. */
	libc_xmalloc_failed_fallback(num_bytes);
}



/*[[[head:libc_fdmatch,hash:CRC-32=0x15c5f790]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") WUNUSED ATTR_FDARG(1) ATTR_FDARG(2) int
NOTHROW_NCX(LIBCCALL libc_fdmatch)(fd_t fd1,
                                   fd_t fd2)
/*[[[body:libc_fdmatch]]]*/
{
#ifdef SYS_kcmp
	pid_t mypid = getpid();
	syscall_slong_t status;
	status = sys_kcmp(mypid, mypid, KCMP_FILE, fd1, fd2);
	if (status >= 0)
		return status == 0; /* 0: `KCMP_ORDER_EQUAL' */
	libc_seterrno_neg(status);
	return 0;
#else /* SYS_kcmp */
	struct stat st1, st2;
	if (fstat(fd1, &st1) == 0 && fstat(fd2, &st2) == 0) {
		return st1.st_dev == st2.st_dev &&
		       st1.st_ino == st2.st_ino;
	}
	return 0;
#endif /* !SYS_kcmp */
}
/*[[[end:libc_fdmatch]]]*/







/*[[[head:libc_make_relative_prefix,hash:CRC-32=0x6ed98811]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") ATTR_MALLOC ATTR_MALL_DEFAULT_ALIGNED WUNUSED char *
NOTHROW_NCX(LIBCCALL libc_make_relative_prefix)(char const *a,
                                                char const *b,
                                                char const *c)
/*[[[body:libc_make_relative_prefix]]]*/
/*AUTO*/{
	(void)a;
	(void)b;
	(void)c;
	CRT_UNIMPLEMENTEDF("make_relative_prefix(a: %q, b: %q, c: %q)", a, b, c); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_make_relative_prefix]]]*/

/*[[[head:libc_make_relative_prefix_ignore_links,hash:CRC-32=0x6c52f8c2]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") ATTR_MALLOC ATTR_MALL_DEFAULT_ALIGNED WUNUSED char *
NOTHROW_NCX(LIBCCALL libc_make_relative_prefix_ignore_links)(char const *a,
                                                             char const *b,
                                                             char const *c)
/*[[[body:libc_make_relative_prefix_ignore_links]]]*/
/*AUTO*/{
	(void)a;
	(void)b;
	(void)c;
	CRT_UNIMPLEMENTEDF("make_relative_prefix_ignore_links(a: %q, b: %q, c: %q)", a, b, c); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_make_relative_prefix_ignore_links]]]*/










/*[[[head:libc_pex_run,hash:CRC-32=0x6cc02eb9]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") char const *
NOTHROW_NCX(LIBCCALL libc_pex_run)(struct pex_obj *obj,
                                   int flags,
                                   char const *executable,
                                   char *const *argv,
                                   char const *outname,
                                   char const *errname,
                                   int *err)
/*[[[body:libc_pex_run]]]*/
/*AUTO*/{
	(void)obj;
	(void)flags;
	(void)executable;
	(void)argv;
	(void)outname;
	(void)errname;
	(void)err;
	CRT_UNIMPLEMENTEDF("pex_run(obj: %p, flags: %x, executable: %q, argv: %p, outname: %q, errname: %q, err: %p)", obj, flags, executable, argv, outname, errname, err); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_pex_run]]]*/

/*[[[head:libc_pex_run_in_environment,hash:CRC-32=0x5366e46b]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") char const *
NOTHROW_NCX(LIBCCALL libc_pex_run_in_environment)(struct pex_obj *obj,
                                                  int flags,
                                                  char const *executable,
                                                  char *const *argv,
                                                  char *const *env,
                                                  char const *outname,
                                                  char const *errname,
                                                  int *err)
/*[[[body:libc_pex_run_in_environment]]]*/
/*AUTO*/{
	(void)obj;
	(void)flags;
	(void)executable;
	(void)argv;
	(void)env;
	(void)outname;
	(void)errname;
	(void)err;
	CRT_UNIMPLEMENTEDF("pex_run_in_environment(obj: %p, flags: %x, executable: %q, argv: %p, env: %p, outname: %q, errname: %q, err: %p)", obj, flags, executable, argv, env, outname, errname, err); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_pex_run_in_environment]]]*/

/*[[[head:libc_pex_input_file,hash:CRC-32=0x434ac911]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") FILE *
NOTHROW_NCX(LIBCCALL libc_pex_input_file)(struct pex_obj *obj,
                                          int flags,
                                          char const *in_name)
/*[[[body:libc_pex_input_file]]]*/
/*AUTO*/{
	(void)obj;
	(void)flags;
	(void)in_name;
	CRT_UNIMPLEMENTEDF("pex_input_file(obj: %p, flags: %x, in_name: %q)", obj, flags, in_name); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_pex_input_file]]]*/

/*[[[head:libc_pex_input_pipe,hash:CRC-32=0x6b8b4300]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") FILE *
NOTHROW_NCX(LIBCCALL libc_pex_input_pipe)(struct pex_obj *obj,
                                          int binary)
/*[[[body:libc_pex_input_pipe]]]*/
/*AUTO*/{
	(void)obj;
	(void)binary;
	CRT_UNIMPLEMENTEDF("pex_input_pipe(obj: %p, binary: %x)", obj, binary); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_pex_input_pipe]]]*/

/*[[[head:libc_pex_read_output,hash:CRC-32=0x36027dcf]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") FILE *
NOTHROW_NCX(LIBCCALL libc_pex_read_output)(struct pex_obj *obj,
                                           int binary)
/*[[[body:libc_pex_read_output]]]*/
/*AUTO*/{
	(void)obj;
	(void)binary;
	CRT_UNIMPLEMENTEDF("pex_read_output(obj: %p, binary: %x)", obj, binary); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_pex_read_output]]]*/

/*[[[head:libc_pex_read_err,hash:CRC-32=0x994cafdd]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") FILE *
NOTHROW_NCX(LIBCCALL libc_pex_read_err)(struct pex_obj *obj,
                                        int binary)
/*[[[body:libc_pex_read_err]]]*/
/*AUTO*/{
	(void)obj;
	(void)binary;
	CRT_UNIMPLEMENTEDF("pex_read_err(obj: %p, binary: %x)", obj, binary); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_pex_read_err]]]*/

/*[[[head:libc_pex_get_status,hash:CRC-32=0x6f9bc095]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") int
NOTHROW_NCX(LIBCCALL libc_pex_get_status)(struct pex_obj *obj,
                                          int count,
                                          int *vector)
/*[[[body:libc_pex_get_status]]]*/
/*AUTO*/{
	(void)obj;
	(void)count;
	(void)vector;
	CRT_UNIMPLEMENTEDF("pex_get_status(obj: %p, count: %x, vector: %p)", obj, count, vector); /* TODO */
	return libc_seterrno(ENOSYS);
}
/*[[[end:libc_pex_get_status]]]*/

/*[[[head:libc_pex_init,hash:CRC-32=0x785d8055]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") struct pex_obj *
NOTHROW_NCX(LIBCCALL libc_pex_init)(int flags,
                                    char const *pname,
                                    char const *tempbase)
/*[[[body:libc_pex_init]]]*/
/*AUTO*/{
	(void)flags;
	(void)pname;
	(void)tempbase;
	CRT_UNIMPLEMENTEDF("pex_init(flags: %x, pname: %q, tempbase: %q)", flags, pname, tempbase); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_pex_init]]]*/

/*[[[head:libc_pex_get_times,hash:CRC-32=0xc9857d24]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") int
NOTHROW_NCX(LIBCCALL libc_pex_get_times)(struct pex_obj *obj,
                                         int count,
                                         struct pex_time *vector)
/*[[[body:libc_pex_get_times]]]*/
/*AUTO*/{
	(void)obj;
	(void)count;
	(void)vector;
	CRT_UNIMPLEMENTEDF("pex_get_times(obj: %p, count: %x, vector: %p)", obj, count, vector); /* TODO */
	return libc_seterrno(ENOSYS);
}
/*[[[end:libc_pex_get_times]]]*/

/*[[[head:libc_pex_free,hash:CRC-32=0xd0d99d0b]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") void
NOTHROW_NCX(LIBCCALL libc_pex_free)(struct pex_obj *obj)
/*[[[body:libc_pex_free]]]*/
/*AUTO*/{
	(void)obj;
	CRT_UNIMPLEMENTEDF("pex_free(obj: %p)", obj); /* TODO */
	libc_seterrno(ENOSYS);
}
/*[[[end:libc_pex_free]]]*/

/*[[[head:libc_pex_one,hash:CRC-32=0xeb3676ab]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") char const *
NOTHROW_NCX(LIBCCALL libc_pex_one)(int flags,
                                   char const *executable,
                                   char *const *argv,
                                   char const *pname,
                                   char const *outname,
                                   char const *errname,
                                   int *status,
                                   int *err)
/*[[[body:libc_pex_one]]]*/
/*AUTO*/{
	(void)flags;
	(void)executable;
	(void)argv;
	(void)pname;
	(void)outname;
	(void)errname;
	(void)status;
	(void)err;
	CRT_UNIMPLEMENTEDF("pex_one(flags: %x, executable: %q, argv: %p, pname: %q, outname: %q, errname: %q, status: %p, err: %p)", flags, executable, argv, pname, outname, errname, status, err); /* TODO */
	libc_seterrno(ENOSYS);
	return NULL;
}
/*[[[end:libc_pex_one]]]*/

/*[[[head:libc_pexecute,hash:CRC-32=0x33da2718]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") int
NOTHROW_NCX(LIBCCALL libc_pexecute)(char const *a,
                                    char *const *b,
                                    char const *c,
                                    char const *d,
                                    char **e,
                                    char **f,
                                    int g)
/*[[[body:libc_pexecute]]]*/
/*AUTO*/{
	(void)a;
	(void)b;
	(void)c;
	(void)d;
	(void)e;
	(void)f;
	(void)g;
	CRT_UNIMPLEMENTEDF("pexecute(a: %q, b: %p, c: %q, d: %q, e: %p, f: %p, g: %x)", a, b, c, d, e, f, g); /* TODO */
	return libc_seterrno(ENOSYS);
}
/*[[[end:libc_pexecute]]]*/

/*[[[head:libc_pwait,hash:CRC-32=0x2186d3db]]]*/
INTERN ATTR_SECTION(".text.crt.libiberty") int
NOTHROW_NCX(LIBCCALL libc_pwait)(int a,
                                 int *b,
                                 int c)
/*[[[body:libc_pwait]]]*/
/*AUTO*/{
	(void)a;
	(void)b;
	(void)c;
	CRT_UNIMPLEMENTEDF("pwait(a: %x, b: %p, c: %x)", a, b, c); /* TODO */
	return libc_seterrno(ENOSYS);
}
/*[[[end:libc_pwait]]]*/

/*[[[start:exports,hash:CRC-32=0x7cf05580]]]*/
DEFINE_PUBLIC_ALIAS_P_VOID(xmalloc_set_program_name,libc_xmalloc_set_program_name,,NOTHROW_NCX,LIBCCALL,(char const *progname),(progname));
DEFINE_PUBLIC_ALIAS_P(fdmatch,libc_fdmatch,WUNUSED ATTR_FDARG(1) ATTR_FDARG(2),int,NOTHROW_NCX,LIBCCALL,(fd_t fd1, fd_t fd2),(fd1,fd2));
DEFINE_PUBLIC_ALIAS_P(make_relative_prefix,libc_make_relative_prefix,ATTR_MALLOC ATTR_MALL_DEFAULT_ALIGNED WUNUSED,char *,NOTHROW_NCX,LIBCCALL,(char const *a, char const *b, char const *c),(a,b,c));
DEFINE_PUBLIC_ALIAS_P(make_relative_prefix_ignore_links,libc_make_relative_prefix_ignore_links,ATTR_MALLOC ATTR_MALL_DEFAULT_ALIGNED WUNUSED,char *,NOTHROW_NCX,LIBCCALL,(char const *a, char const *b, char const *c),(a,b,c));
DEFINE_PUBLIC_ALIAS_P(pex_run,libc_pex_run,,char const *,NOTHROW_NCX,LIBCCALL,(struct pex_obj *obj, int flags, char const *executable, char *const *argv, char const *outname, char const *errname, int *err),(obj,flags,executable,argv,outname,errname,err));
DEFINE_PUBLIC_ALIAS_P(pex_run_in_environment,libc_pex_run_in_environment,,char const *,NOTHROW_NCX,LIBCCALL,(struct pex_obj *obj, int flags, char const *executable, char *const *argv, char *const *env, char const *outname, char const *errname, int *err),(obj,flags,executable,argv,env,outname,errname,err));
DEFINE_PUBLIC_ALIAS_P(pex_input_file,libc_pex_input_file,,FILE *,NOTHROW_NCX,LIBCCALL,(struct pex_obj *obj, int flags, char const *in_name),(obj,flags,in_name));
DEFINE_PUBLIC_ALIAS_P(pex_input_pipe,libc_pex_input_pipe,,FILE *,NOTHROW_NCX,LIBCCALL,(struct pex_obj *obj, int binary),(obj,binary));
DEFINE_PUBLIC_ALIAS_P(pex_read_output,libc_pex_read_output,,FILE *,NOTHROW_NCX,LIBCCALL,(struct pex_obj *obj, int binary),(obj,binary));
DEFINE_PUBLIC_ALIAS_P(pex_read_err,libc_pex_read_err,,FILE *,NOTHROW_NCX,LIBCCALL,(struct pex_obj *obj, int binary),(obj,binary));
DEFINE_PUBLIC_ALIAS_P(pex_get_status,libc_pex_get_status,,int,NOTHROW_NCX,LIBCCALL,(struct pex_obj *obj, int count, int *vector),(obj,count,vector));
DEFINE_PUBLIC_ALIAS_P(pex_init,libc_pex_init,,struct pex_obj *,NOTHROW_NCX,LIBCCALL,(int flags, char const *pname, char const *tempbase),(flags,pname,tempbase));
DEFINE_PUBLIC_ALIAS_P(pex_get_times,libc_pex_get_times,,int,NOTHROW_NCX,LIBCCALL,(struct pex_obj *obj, int count, struct pex_time *vector),(obj,count,vector));
DEFINE_PUBLIC_ALIAS_P_VOID(pex_free,libc_pex_free,,NOTHROW_NCX,LIBCCALL,(struct pex_obj *obj),(obj));
DEFINE_PUBLIC_ALIAS_P(pex_one,libc_pex_one,,char const *,NOTHROW_NCX,LIBCCALL,(int flags, char const *executable, char *const *argv, char const *pname, char const *outname, char const *errname, int *status, int *err),(flags,executable,argv,pname,outname,errname,status,err));
DEFINE_PUBLIC_ALIAS_P(pexecute,libc_pexecute,,int,NOTHROW_NCX,LIBCCALL,(char const *a, char *const *b, char const *c, char const *d, char **e, char **f, int g),(a,b,c,d,e,f,g));
DEFINE_PUBLIC_ALIAS_P(pwait,libc_pwait,,int,NOTHROW_NCX,LIBCCALL,(int a, int *b, int c),(a,b,c));
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_LIBIBERTY_C */
