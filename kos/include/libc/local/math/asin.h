/* HASH CRC-32:0x81391691 */
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
#ifndef __local_asin_defined
#define __local_asin_defined
#include <__crt.h>
#include <ieee754.h>
#if defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_feraiseexcept_defined
#define __local___localdep_feraiseexcept_defined
#ifdef __CRT_HAVE_feraiseexcept
__NAMESPACE_LOCAL_END
#include <kos/anno.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(,int,__THROWING(...),__localdep_feraiseexcept,(int __excepts),feraiseexcept,(__excepts))
#else /* __CRT_HAVE_feraiseexcept */
__NAMESPACE_LOCAL_END
#include <libc/local/fenv/feraiseexcept.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_feraiseexcept __LIBC_LOCAL_NAME(feraiseexcept)
#endif /* !__CRT_HAVE_feraiseexcept */
#endif /* !__local___localdep_feraiseexcept_defined */
__NAMESPACE_LOCAL_END
#include <libm/fcomp.h>
#include <libm/fabs.h>
#include <libm/matherr.h>
#include <libm/nan.h>
#include <libm/asin.h>
#include <bits/crt/fenv.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(asin) __ATTR_WUNUSED double
__NOTHROW(__LIBCCALL __LIBC_LOCAL_NAME(asin))(double __x) {
	if (__LIBM_LIB_VERSION != __LIBM_IEEE &&
	    __LIBM_MATHFUNI2(isgreaterequal, __LIBM_MATHFUN(fabs, __x), 1.0)) {
		(__NAMESPACE_LOCAL_SYM __localdep_feraiseexcept)(FE_INVALID); /* asin(|x|>1) */
		return __kernel_standard(__x, __x, __LIBM_MATHFUN1I(nan, ""), __LIBM_KMATHERR_ASIN);
	}
	return __LIBM_MATHFUN(asin, __x);
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_asin_defined
#define __local___localdep_asin_defined
#define __localdep_asin __LIBC_LOCAL_NAME(asin)
#endif /* !__local___localdep_asin_defined */
#else /* __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
#undef __local_asin_defined
#endif /* !__IEEE754_DOUBLE_TYPE_IS_DOUBLE__ && !__IEEE754_FLOAT_TYPE_IS_DOUBLE__ && !__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
#endif /* !__local_asin_defined */
