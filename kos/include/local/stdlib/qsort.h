/* HASH CRC-32:0xdf1f8773 */
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
#ifndef __local_qsort_defined
#define __local_qsort_defined 1
#include <__crt.h>
#include <kos/anno.h>
#ifndef __compar_d_fn_t_defined
#define __compar_d_fn_t_defined 1
typedef int (__LIBCCALL *__compar_d_fn_t)(void const *__a, void const *__b, void *__arg);
#endif /* !__compar_d_fn_t_defined */
/* Dependency: "qsort_r" from "stdlib" */
#ifndef ____localdep_qsort_r_defined
#define ____localdep_qsort_r_defined 1
#ifdef __CRT_HAVE_qsort_r
__CREDIRECT_VOID(__ATTR_NONNULL((1, 4)),__THROWING,__localdep_qsort_r,(void *__pbase, __SIZE_TYPE__ __item_count, __SIZE_TYPE__ __item_size, __compar_d_fn_t __cmp, void *__arg),qsort_r,(__pbase,__item_count,__item_size,__cmp,__arg))
#else /* LIBC: qsort_r */
#include <local/stdlib/qsort_r.h>
#define __localdep_qsort_r (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(qsort_r))
#endif /* qsort_r... */
#endif /* !____localdep_qsort_r_defined */

__NAMESPACE_LOCAL_BEGIN
#ifndef ____invoke_compare_helper_defined
#define ____invoke_compare_helper_defined 1
__LOCAL_LIBC(__invoke_compare_helper) int
(__LIBCCALL __invoke_compare_helper)(void const *__a, void const *__b, void *__arg) {
	return (*(__compar_fn_t)__arg)(__a, __b);
}
#endif /* !____invoke_compare_helper_defined */
__LOCAL_LIBC(qsort) __ATTR_NONNULL((1, 4)) void
(__LIBCCALL __LIBC_LOCAL_NAME(qsort))(void *__pbase,
                                      __SIZE_TYPE__ __item_count,
                                      __SIZE_TYPE__ __item_size,
                                      __compar_fn_t __cmp) __THROWS(...) {
#line 437 "kos/src/libc/magic/stdlib.c"
	__localdep_qsort_r(__pbase, __item_count, __item_size, &__invoke_compare_helper, (void *)__cmp);
}
__NAMESPACE_LOCAL_END
#endif /* !__local_qsort_defined */
