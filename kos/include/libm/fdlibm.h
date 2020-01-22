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
#ifndef _LIBM_FDLIBM_H
#define _LIBM_FDLIBM_H 1

#include <__crt.h>

#include <hybrid/__byteorder.h>
#include <hybrid/typecore.h>

#include <bits/types.h>

#include <ieee754.h>

/* NOTE: These values must match the declarations from <math.h>! */
#define __LIBM_FP_NAN       0
#define __LIBM_FP_INFINITE  1
#define __LIBM_FP_ZERO      2
#define __LIBM_FP_SUBNORMAL 3
#define __LIBM_FP_NORMAL    4

#ifdef __CC__
__DECL_BEGIN

#define __LIBM_LOCAL_DECLARE_BEGIN __NAMESPACE_LOCAL_BEGIN
#define __LIBM_LOCAL_DECLARE_END __NAMESPACE_LOCAL_END
#define __LIBM_LOCAL_DECLARE(T, name, value) \
	__LOCAL_LIBC_CONST_DATA(libm_##name)     \
	T const __libm_##name = value;
#define __LIBM_LOCAL_DECLARE_ARRAY(T, name, n, ...) \
	__LOCAL_LIBC_CONST_DATA(libm_##name)            \
	T const __libm_##name[n] = __VA_ARGS__;
#define __LIBM_LOCAL_VALUE(name) \
	__NAMESPACE_LOCAL_SYM __libm_##name

/* NOTE: Heavy modifications were made to the original fdlibm! */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */


#ifdef __IEEE754_FLOAT_TYPE__

//#define __LIBM_HIGH_ORDER_BIT_IS_SET_FOR_SNAN 1 /* TODO: ??? */
//#define __LIBM_FLT_LARGEST_EXPONENT_IS_NORMAL 1 /* TODO: ??? */

#ifdef __LIBM_FLT_LARGEST_EXPONENT_IS_NORMAL
#define __LIBM_FLT_UWORD_IS_FINITE(x) 1
#define __LIBM_FLT_UWORD_IS_NAN(x) 0
#define __LIBM_FLT_UWORD_IS_INFINITE(x) 0
#define __LIBM_FLT_UWORD_MAX 0x7fffffff
#define __LIBM_FLT_UWORD_EXP_MAX 0x43010000
#define __LIBM_FLT_UWORD_LOG_MAX 0x42b2d4fc
#define __LIBM_FLT_UWORD_LOG_2MAX 0x42b437e0
#define __LIBM_HUGE ((__IEEE754_FLOAT_TYPE__)0X1.FFFFFEP128)
#else /* __LIBM_FLT_LARGEST_EXPONENT_IS_NORMAL */
#define __LIBM_FLT_UWORD_IS_FINITE(x) ((x) < 0x7f800000L)
#define __LIBM_FLT_UWORD_IS_NAN(x) ((x) > 0x7f800000L)
#define __LIBM_FLT_UWORD_IS_INFINITE(x) ((x) == 0x7f800000L)
#define __LIBM_FLT_UWORD_MAX 0x7f7fffffL
#define __LIBM_FLT_UWORD_EXP_MAX 0x43000000
#define __LIBM_FLT_UWORD_LOG_MAX 0x42b17217
#define __LIBM_FLT_UWORD_LOG_2MAX 0x42b2d4fc
#define __LIBM_HUGE ((__IEEE754_FLOAT_TYPE__)3.40282346638528860e+38)
#endif /* !__LIBM_FLT_LARGEST_EXPONENT_IS_NORMAL */

#define __LIBM_FLT_UWORD_HALF_MAX (__LIBM_FLT_UWORD_MAX - (1L << 23))
#define __LIBM_FLT_LARGEST_EXP (__LIBM_FLT_UWORD_MAX >> 23)


#if defined(_FLT_NO_DENORMALS) /* TODO: ??? */
#define __LIBM_FLT_UWORD_IS_ZERO(x) ((x) < 0x00800000L)
#define __LIBM_FLT_UWORD_IS_SUBNORMAL(x) 0
#define __LIBM_FLT_UWORD_MIN 0x00800000
#define __LIBM_FLT_UWORD_EXP_MIN 0x42fc0000
#define __LIBM_FLT_UWORD_LOG_MIN 0x42aeac50
#define __LIBM_FLT_SMALLEST_EXP 1
#else
#define __LIBM_FLT_UWORD_IS_ZERO(x) ((x) == 0)
#define __LIBM_FLT_UWORD_IS_SUBNORMAL(x) ((x) < 0x00800000L)
#define __LIBM_FLT_UWORD_MIN 0x00000001
#define __LIBM_FLT_UWORD_EXP_MIN 0x43160000
#define __LIBM_FLT_UWORD_LOG_MIN 0x42cff1b5
#define __LIBM_FLT_SMALLEST_EXP -22
#endif


/* A union which permits us to convert between a float and a 32 bit int.  */
typedef union {
	__IEEE754_FLOAT_TYPE__ __f_value;
	__uint32_t __f_word;
} __libm_ieee_float_shape_type;

/* Get a 32 bit int from a float.  */
#define __LIBM_GET_FLOAT_WORD(i, d)          \
	do {                                     \
		__libm_ieee_float_shape_type __gf_u; \
		__gf_u.__f_value = (d);              \
		(i)              = __gf_u.__f_word;  \
	}                                        \
	__WHILE0

/* Set a float from a 32 bit int.  */
#define __LIBM_SET_FLOAT_WORD(d, i)          \
	do {                                     \
		__libm_ieee_float_shape_type __sf_u; \
		__sf_u.__f_word = (i);               \
		(d)             = __sf_u.__f_value;  \
	}                                        \
	__WHILE0
#endif /* __IEEE754_FLOAT_TYPE__ */


#ifdef __IEEE754_DOUBLE_TYPE__
/* A union which permits us to convert between a double and two 32 bit ints. */
typedef union {
	__IEEE754_DOUBLE_TYPE__ __d_value;
	struct {
#if __FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__
		__uint32_t __d_msw;
		__uint32_t __d_lsw;
#elif __FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__
		__uint32_t __d_lsw;
		__uint32_t __d_msw;
#endif
	} __d_parts;
} __libm_ieee_double_shape_type;

/* Get two 32 bit ints from a double.  */
#define __LIBM_GET_DOUBLE_WORDS __LIBM_EXTRACT_WORDS
#define __LIBM_EXTRACT_WORDS(ix0, ix1, d)            \
	do {                                             \
		__libm_ieee_double_shape_type __ew_u;        \
		__ew_u.__d_value = (d);                      \
		(ix0)            = __ew_u.__d_parts.__d_msw; \
		(ix1)            = __ew_u.__d_parts.__d_lsw; \
	}                                                \
	__WHILE0

/* Get the more significant 32 bit int from a double.  */
#define __LIBM_GET_HIGH_WORD(i, d)                   \
	do {                                             \
		__libm_ieee_double_shape_type __gh_u;        \
		__gh_u.__d_value = (d);                      \
		(i)              = __gh_u.__d_parts.__d_msw; \
	}                                                \
	__WHILE0

/* Get the less significant 32 bit int from a double.  */
#define __LIBM_GET_LOW_WORD(i, d)                    \
	do {                                             \
		__libm_ieee_double_shape_type __gl_u;        \
		__gl_u.__d_value = (d);                      \
		(i)              = __gl_u.__d_parts.__d_lsw; \
	}                                                \
	__WHILE0

/* Set a double from two 32 bit ints.  */
#define __LIBM_INSERT_WORDS(d, ix0, ix1)             \
	do {                                             \
		__libm_ieee_double_shape_type __iw_u;        \
		__iw_u.__d_parts.__d_msw = (ix0);            \
		__iw_u.__d_parts.__d_lsw = (ix1);            \
		(d)                      = __iw_u.__d_value; \
	}                                                \
	__WHILE0

/* Set the more significant 32 bits of a double from an int.  */
#define __LIBM_SET_HIGH_WORD(d, v)                   \
	do {                                             \
		__libm_ieee_double_shape_type __sh_u;        \
		__sh_u.__d_value         = (d);              \
		__sh_u.__d_parts.__d_msw = (v);              \
		(d)                      = __sh_u.__d_value; \
	}                                                \
	__WHILE0

/* Set the less significant 32 bits of a double from an int.  */
#define __LIBM_SET_LOW_WORD(d, v)                    \
	do {                                             \
		__libm_ieee_double_shape_type __sl_u;        \
		__sl_u.__d_value         = (d);              \
		__sl_u.__d_parts.__d_lsw = (v);              \
		(d)                      = __sl_u.__d_value; \
	}                                                \
	__WHILE0
#endif /* __IEEE754_DOUBLE_TYPE__ */




#ifdef __IEEE854_LONG_DOUBLE_TYPE__
/*
 * ====================================================
 * Copyright (C) 2004 by Sun Microsystems, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

typedef union {
	__IEEE854_LONG_DOUBLE_TYPE__ __l_value;
	struct {
#if __FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__
		__int16_t __l_sign_exponent;
		__uint16_t __l_empty;
		__uint32_t __l_msw;
		__uint32_t __l_lsw;
#elif __FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__
		__uint32_t __l_lsw;
		__uint32_t __l_msw;
		__int16_t __l_sign_exponent;
		__uint16_t __l_empty;
#endif
#define __LIBM_SET_LDOUBLE_EMPTY(u) (u).__l_parts.__l_empty = 0
	} __l_parts;
} __libm_ieee_long_double_shape_type;

/* Get three 32 bit ints from a long double.  */
#define __LIBM_GET_LDOUBLE_WORDS(exp, ix0, ix1, d)  \
	do {                                            \
		__libm_ieee_long_double_shape_type __ew_u;  \
		__ew_u.__l_value = (d);                     \
		(exp) = __ew_u.__l_parts.__l_sign_exponent; \
		(ix0) = __ew_u.__l_parts.__l_msw;           \
		(ix1) = __ew_u.__l_parts.__l_lsw;           \
	} __WHILE0

/* Set a long double from two 32 bit ints.  */
#define __LIBM_SET_LDOUBLE_WORDS(d, exp, ix0, ix1)  \
	do {                                            \
		__libm_ieee_long_double_shape_type __iw_u;  \
		__iw_u.__l_parts.__l_sign_exponent = (exp); \
		__LIBM_SET_LDOUBLE_EMPTY(__iw_u);           \
		__iw_u.__l_parts.__l_msw = (ix0);           \
		__iw_u.__l_parts.__l_lsw = (ix1);           \
		(d) = __iw_u.__l_value;                     \
	} __WHILE0

/* Get the more significant 32 bits of a long double mantissa.  */
#define __LIBM_GET_LDOUBLE_MSW(v, d)               \
	do {                                           \
		__libm_ieee_long_double_shape_type __sh_u; \
		__sh_u.__l_value = (d);                    \
		(v) = __sh_u.__l_parts.__l_msw;            \
	} __WHILE0

/* Get the less significant 32 bits of a long double mantissa.  */
#define __LIBM_GET_LDOUBLE_LSW(v, d)               \
	do {                                           \
		__libm_ieee_long_double_shape_type __sh_u; \
		__sh_u.__l_value = (d);                    \
		(v) = __sh_u.__l_parts.__l_lsw;            \
	} __WHILE0

/* Set the more significant 32 bits of a long double mantissa from an int.  */
#define __LIBM_SET_LDOUBLE_MSW(d, v)               \
	do {                                           \
		__libm_ieee_long_double_shape_type __sh_u; \
		__sh_u.__l_value         = (d);            \
		__sh_u.__l_parts.__l_msw = (v);            \
		(d) = __sh_u.__l_value;                    \
	} __WHILE0

/* Set the less significant 32 bits of a long double mantissa from an int.  */
#define __LIBM_SET_LDOUBLE_LSW(d, v)               \
	do {                                           \
		__libm_ieee_long_double_shape_type __sh_u; \
		__sh_u.__l_value         = (d);            \
		__sh_u.__l_parts.__l_lsw = (v);            \
		(d) = __sh_u.__l_value;                    \
	} __WHILE0

/* Get int from the exponent of a long double.  */
#define __LIBM_GET_LDOUBLE_EXP(exp, d)              \
	do {                                            \
		__libm_ieee_long_double_shape_type __ge_u;  \
		__ge_u.__l_value = (d);                     \
		(exp) = __ge_u.__l_parts.__l_sign_exponent; \
	} __WHILE0

/* Set exponent of a long double from an int.  */
#define __LIBM_SET_LDOUBLE_EXP(d, exp)              \
	do {                                            \
		__libm_ieee_long_double_shape_type __se_u;  \
		__se_u.__l_value                   = (d);   \
		__se_u.__l_parts.__l_sign_exponent = (exp); \
		(d) = __se_u.__l_value;                     \
	} __WHILE0
#endif /* __IEEE854_LONG_DOUBLE_TYPE__ */



/* Macros to avoid undefined behavior that can arise if the amount
 * of a shift is exactly equal to the size of the shifted operand.  */
#define __LIBM_SAFE_LEFT_SHIFT(op, amt) \
	(((amt) < 8 * sizeof(op)) ? ((op) << (amt)) : 0)
#define __LIBM_SAFE_RIGHT_SHIFT(op, amt) \
	(((amt) < 8 * sizeof(op)) ? ((op) >> (amt)) : 0)


#ifndef __libm_math_opt_barrier
#ifdef __COMPILER_HAVE_GCC_ASM
#define __libm_math_opt_barrier(x, result) do { (result) = (x); __asm__("" : "+m" (result)); } __WHILE0
#define __libm_math_force_eval(x)          do { __asm__ __volatile__("" : : "m" (x)); } __WHILE0
#define __libm_math_force_eval_r(T, x)     do { T __x = (x); __asm__ __volatile__("" : : "m" (__x)); } __WHILE0
#else /* __COMPILER_HAVE_GCC_ASM */
#define __libm_math_opt_barrier(x, result) ((result) = (x))
#define __libm_math_force_eval(x)          (void)(x) /* XXX: May not get evaluated... */
#define __libm_math_force_eval_r(T, x)     (void)(T)(x) /* XXX: May not get evaluated... */
#endif /* !__COMPILER_HAVE_GCC_ASM */
#endif /* !__libm_math_opt_barrier */


__DECL_END
#else /* __CC__ */
#define __LIBM_LOCAL_DECLARE_BEGIN                      /* nothing */
#define __LIBM_LOCAL_DECLARE_END                        /* nothing */
#define __LIBM_LOCAL_DECLARE(T, name, value)            /* nothing */
#define __LIBM_LOCAL_DECLARE_ARRAY(T, name, array, ...) /* nothing */
#define __LIBM_LOCAL_VALUE(name)                        /* nothing */
#endif /* !__CC__ */

#endif /* !_LIBM_FDLIBM_H */
