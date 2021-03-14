/* HASH CRC-32:0xdac614af */
/* Copyright (c) 2019-2021 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2021 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef __local_strto64_defined
#define __local_strto64_defined 1
#include <__crt.h>
#include <features.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
/* Dependency: strto64_r from stdlib */
#ifndef __local___localdep_strto64_r_defined
#define __local___localdep_strto64_r_defined 1
#ifdef __CRT_HAVE_strto64_r
__NAMESPACE_LOCAL_END
#include <bits/types.h>
__NAMESPACE_LOCAL_BEGIN
/* >> strto32_r(3), strtou32_r(3), strto64_r(3), strtou64_r(3)
 * Safely parse & return an integer from `nptr', and store any potential
 * errors in `*error' (if non-NULL). The following errors are defined:
 *  - 0:         Success
 *  - ECANCELED: Nothing was parsed.
 *               In this case, `*endptr' is set to original `nptr' (iow:
 *               leading spaces are _not_ skipped in `*endptr'), and the
 *               returned integer is `0'
 *  - ERANGE:    Integer over- or under-flow while parsing.
 *               In this case, `*endptr' is still updated correctly, and
 *               the returned integer is closest representable value to
 *               the integer given in `nptr' (U?INTn_(MIN|MAX))
 *               This error supercedes `EINVAL' if both conditions apply.
 *  - EINVAL:    Only when `endptr == NULL': The parsed number is followed
 *               by at least 1 additional non-whitespace character.
 *               The returned integer value is not affected by this error. */
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INT64_TYPE__,__NOTHROW_NCX,__localdep_strto64_r,(char const *__restrict __nptr, char **__endptr, __STDC_INT_AS_UINT_T __base, __errno_t *__error),strto64_r,(__nptr,__endptr,__base,__error))
#else /* __CRT_HAVE_strto64_r */
__NAMESPACE_LOCAL_END
#include <libc/local/stdlib/strto64_r.h>
__NAMESPACE_LOCAL_BEGIN
/* >> strto32_r(3), strtou32_r(3), strto64_r(3), strtou64_r(3)
 * Safely parse & return an integer from `nptr', and store any potential
 * errors in `*error' (if non-NULL). The following errors are defined:
 *  - 0:         Success
 *  - ECANCELED: Nothing was parsed.
 *               In this case, `*endptr' is set to original `nptr' (iow:
 *               leading spaces are _not_ skipped in `*endptr'), and the
 *               returned integer is `0'
 *  - ERANGE:    Integer over- or under-flow while parsing.
 *               In this case, `*endptr' is still updated correctly, and
 *               the returned integer is closest representable value to
 *               the integer given in `nptr' (U?INTn_(MIN|MAX))
 *               This error supercedes `EINVAL' if both conditions apply.
 *  - EINVAL:    Only when `endptr == NULL': The parsed number is followed
 *               by at least 1 additional non-whitespace character.
 *               The returned integer value is not affected by this error. */
#define __localdep_strto64_r __LIBC_LOCAL_NAME(strto64_r)
#endif /* !__CRT_HAVE_strto64_r */
#endif /* !__local___localdep_strto64_r_defined */
__NAMESPACE_LOCAL_END
#include <libc/errno.h>
__NAMESPACE_LOCAL_BEGIN
/* >> strto32(3), strto64(3), strtou32(3), strtou64(3)
 * Convert a string (radix=`base') from `nptr' into an integer,
 * and store a pointer to the end of the number in `*endptr'.
 * If `errno(3)' support is available, integer overflow is handled
 * by setting `errno=ERANGE', and returning the greatest or lowest
 * valid integer (`U?INTn_(MIN|MAX))'. (though note that
 * `endptr' (if non-NULL) is still updated in this case!)
 * Upon success, `errno' is left unchanged, and the integer repr
 * of the parsed number is returned. When no integer was parsed,
 * then `0' is returned, `*endptr' is set to `nptr', but `errno'
 * will not have been modified.
 * @return: * :         Success: The parsed integer
 * @return: 0 :         [*endptr=nptr] error: Nothing was parsed
 * @return: INTn_MIN:   [errno=ERANGE] error: Value to low to represent
 * @return: U?INTn_MAX: [errno=ERANGE] error: Value to great to represent */
__LOCAL_LIBC(strto64) __ATTR_LEAF __ATTR_NONNULL((1)) __INT64_TYPE__
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(strto64))(char const *__restrict __nptr, char **__endptr, __STDC_INT_AS_UINT_T __base) {
#if defined(__libc_geterrno) && defined(__ERANGE)
	__INT64_TYPE__ __result;
	__errno_t __error;
	__result = __localdep_strto64_r(__nptr, __endptr, __base, &__error);
	if (__error == __ERANGE)
		__libc_seterrno(__ERANGE);
	return __result;
#else /* __libc_geterrno && __ERANGE */
	return __localdep_strto64_r(__nptr, __endptr, __base, __NULLPTR);
#endif /* !__libc_geterrno || !__ERANGE */
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_strto64_defined
#define __local___localdep_strto64_defined 1
#define __localdep_strto64 __LIBC_LOCAL_NAME(strto64)
#endif /* !__local___localdep_strto64_defined */
#endif /* !__local_strto64_defined */
