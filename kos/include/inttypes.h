/* HASH CRC-32:0xb2fb2df2 */
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
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef _INTTYPES_H
#define _INTTYPES_H 1

#ifdef _CXX_STDONLY_CINTTYPES
#ifdef __CXX_SYSTEM_HEADER
#undef _INTTYPES_H /* Allow the C-header to be re-included to import all std::-symbols into the global namespace. */
#else /* __CXX_SYSTEM_HEADER */
/* Import all symbols into the global namespace when re-including "inttypes.h" after "cinttypes" */
#ifndef __imaxdiv_t_defined
#define __imaxdiv_t_defined 1
__NAMESPACE_STD_USING(imaxdiv_t)
#endif /* !__imaxdiv_t_defined */
__NAMESPACE_STD_USING(imaxabs)
__NAMESPACE_STD_USING(imaxdiv)
__NAMESPACE_STD_USING(strtoimax)
__NAMESPACE_STD_USING(strtoumax)
__NAMESPACE_STD_USING(wcstoimax)
__NAMESPACE_STD_USING(wcstoumax)
#undef _CXX_STDONLY_CINTTYPES
#endif /* !__CXX_SYSTEM_HEADER */
#else /* _CXX_STDONLY_CINTTYPES */
#include "__stdinc.h"
#include "__crt.h"

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#include <stdint.h>
#include <hybrid/typecore.h>
#include <hybrid/__va_size.h>
#ifdef __USE_DOS
#include <xlocale.h>
#endif /* __USE_DOS */

__SYSDECL_BEGIN

#ifndef ____gwchar_t_defined
#define ____gwchar_t_defined 1
#define __gwchar_t __WCHAR_TYPE__
#endif /* !____gwchar_t_defined */

/* Since `__VA_SIZE >= sizeof(int)', and `sizeof(int) != 0',
 * we also know that `sizeof(int) >= 1', meaning that any 8-bit
 * data word will _always_ be promoted to an int, meaning in order
 * to print an 8-bit data word we never need any sort of prefix! */
#ifndef __PRI1_PREFIX
#define __PRI1_PREFIX /* nothing */
#endif /* !__PRI1_PREFIX */

#ifndef __PRI2_PREFIX
#if __VA_SIZE >= 2
#define __PRI2_PREFIX /* nothing */
#elif __SIZEOF_LONG__ == 2
#define __PRI2_PREFIX "l"
#elif __SIZEOF_POINTER__ == 2 && \
     (defined(__CRT_KOS) || defined(__CRT_DOS))
#define __PRI2_PREFIX "I"
#elif __SIZEOF_LONG_LONG__ == 2
#define __PRI2_PREFIX "ll"
#else
#define __PRI2_PREFIX "I16"
#endif
#endif /* !__PRI2_PREFIX */

#ifndef __PRI4_PREFIX
#if __VA_SIZE >= 4
#define __PRI4_PREFIX /* nothing */
#elif __SIZEOF_LONG__ == 4
#define __PRI4_PREFIX "l"
#elif __SIZEOF_POINTER__ == 4 && \
     (defined(__CRT_KOS) || defined(__CRT_DOS))
#define __PRI4_PREFIX "I"
#elif __SIZEOF_LONG_LONG__ == 4
#define __PRI4_PREFIX "ll"
#else
#define __PRI4_PREFIX "I32"
#endif
#endif /* !__PRI4_PREFIX */

#ifndef __PRI8_PREFIX
#if __VA_SIZE >= 8
#define __PRI8_PREFIX /* nothing */
#elif __SIZEOF_LONG__ == 8
#define __PRI8_PREFIX "l"
#elif __SIZEOF_INTMAX_T__ == 8
#define __PRI8_PREFIX "j"
#elif __SIZEOF_POINTER__ == 8 && \
     (defined(__CRT_KOS) || defined(__CRT_DOS))
#define __PRI8_PREFIX "I"
#elif __SIZEOF_LONG_LONG__ == 8
#define __PRI8_PREFIX "ll"
#else
#define __PRI8_PREFIX "I64"
#endif
#endif /* !__PRI8_PREFIX */

#ifndef __PRIP_PREFIX
#if __VA_SIZE >= __SIZEOF_POINTER__
#define __PRIP_PREFIX /* nothing */
#elif __SIZEOF_LONG__ == __SIZEOF_POINTER__
#define __PRIP_PREFIX "l"
#elif __SIZEOF_INTMAX_T__ == __SIZEOF_POINTER__
#define __PRIP_PREFIX "j"
#else
#define __PRIP_PREFIX "I"
#endif
#endif /* !__PRIP_PREFIX */

#define __PRIN2_PREFIX(n) __PRI##n##_PREFIX
#define __PRIN_PREFIX(n) __PRIN2_PREFIX(n)
#define __PRIL1_PREFIX __PRIN_PREFIX(__SIZEOF_INT_LEAST8_T__)
#define __PRIL2_PREFIX __PRIN_PREFIX(__SIZEOF_INT_LEAST16_T__)
#define __PRIL4_PREFIX __PRIN_PREFIX(__SIZEOF_INT_LEAST32_T__)
#define __PRIL8_PREFIX __PRIN_PREFIX(__SIZEOF_INT_LEAST64_T__)
#define __PRIF1_PREFIX __PRIN_PREFIX(__SIZEOF_INT_FAST8_T__)
#define __PRIF2_PREFIX __PRIN_PREFIX(__SIZEOF_INT_FAST16_T__)
#define __PRIF4_PREFIX __PRIN_PREFIX(__SIZEOF_INT_FAST32_T__)
#define __PRIF8_PREFIX __PRIN_PREFIX(__SIZEOF_INT_FAST64_T__)


#ifndef __SCA1_PREFIX
#if __SIZEOF_INT__ == 1
#define __SCA1_PREFIX /* nothing */
#elif __SIZEOF_SHORT__ == 1
#define __SCA1_PREFIX "h"
#elif __SIZEOF_CHAR__ == 1
#define __SCA1_PREFIX "hh"
#else
#define __SCA1_PREFIX "I8"
#endif
#endif /* !__SCA1_PREFIX */

#ifndef __SCA2_PREFIX
#if __SIZEOF_INT__ == 2
#define __SCA2_PREFIX /* nothing */
#elif __SIZEOF_SHORT__ == 2
#define __SCA2_PREFIX "h"
#elif __SIZEOF_LONG__ == 2
#define __SCA2_PREFIX "l"
#elif __SIZEOF_POINTER__ == 2
#define __SCA2_PREFIX "I"
#else
#define __SCA2_PREFIX "I16"
#endif
#endif /* !__SCA2_PREFIX */

#ifndef __SCA4_PREFIX
#if __SIZEOF_INT__ == 4
#define __SCA4_PREFIX /* nothing */
#elif __SIZEOF_SHORT__ == 4
#define __SCA4_PREFIX "h"
#elif __SIZEOF_LONG__ == 4
#define __SCA4_PREFIX "l"
#elif __SIZEOF_POINTER__ == 4 && \
     (defined(__CRT_KOS) || defined(__CRT_DOS))
#define __SCA4_PREFIX "I"
#elif __SIZEOF_LONG_LONG__ == 4
#define __SCA4_PREFIX "ll"
#else
#define __SCA4_PREFIX "I32"
#endif
#endif /* !__SCA4_PREFIX */

#ifndef __SCA8_PREFIX
#if __SIZEOF_INT__ == 8
#define __SCA8_PREFIX /* nothing */
#elif __SIZEOF_SHORT__ == 8
#define __SCA8_PREFIX "h"
#elif __SIZEOF_LONG__ == 8
#define __SCA8_PREFIX "l"
#elif __SIZEOF_POINTER__ == 8 && \
     (defined(__CRT_KOS) || defined(__CRT_DOS))
#define __SCA8_PREFIX "I"
#elif __SIZEOF_LONG_LONG__ == 8
#define __SCA8_PREFIX "ll"
#else
#define __SCA8_PREFIX "I64"
#endif
#endif /* !__SCA8_PREFIX */

#ifndef __SCAP_PREFIX
#if __SIZEOF_INT__ == __SIZEOF_POINTER__
#define __SCAP_PREFIX /* nothing */
#elif __SIZEOF_LONG__ == __SIZEOF_POINTER__
#define __SCAP_PREFIX "l"
#elif __SIZEOF_INTMAX_T__ == __SIZEOF_POINTER__
#define __SCAP_PREFIX "j"
#else
#define __SCAP_PREFIX "I"
#endif
#endif /* !__SCAP_PREFIX */

#define __SCAN2_PREFIX(n) __SCA##n##_PREFIX
#define __SCAN_PREFIX(n) __SCAN2_PREFIX(n)
#define __SCAL1_PREFIX __SCAN_PREFIX(__SIZEOF_INT_LEAST8_T__)
#define __SCAL2_PREFIX __SCAN_PREFIX(__SIZEOF_INT_LEAST16_T__)
#define __SCAL4_PREFIX __SCAN_PREFIX(__SIZEOF_INT_LEAST32_T__)
#define __SCAL8_PREFIX __SCAN_PREFIX(__SIZEOF_INT_LEAST64_T__)
#define __SCAF1_PREFIX __SCAN_PREFIX(__SIZEOF_INT_FAST8_T__)
#define __SCAF2_PREFIX __SCAN_PREFIX(__SIZEOF_INT_FAST16_T__)
#define __SCAF4_PREFIX __SCAN_PREFIX(__SIZEOF_INT_FAST32_T__)
#define __SCAF8_PREFIX __SCAN_PREFIX(__SIZEOF_INT_FAST64_T__)



/* printf(): (u)int8_t */
#define PRId8          __PRI1_PREFIX "d"
#define PRIi8          __PRI1_PREFIX "i"
#define PRIo8          __PRI1_PREFIX "o"
#define PRIu8          __PRI1_PREFIX "u"
#define PRIx8          __PRI1_PREFIX "x"
#define PRIX8          __PRI1_PREFIX "X"

/* printf(): (u)int16_t */
#define PRId16         __PRI2_PREFIX "d"
#define PRIi16         __PRI2_PREFIX "i"
#define PRIo16         __PRI2_PREFIX "o"
#define PRIu16         __PRI2_PREFIX "u"
#define PRIx16         __PRI2_PREFIX "x"
#define PRIX16         __PRI2_PREFIX "X"

/* printf(): (u)int32_t */
#define PRId32         __PRI4_PREFIX "d"
#define PRIi32         __PRI4_PREFIX "i"
#define PRIo32         __PRI4_PREFIX "o"
#define PRIu32         __PRI4_PREFIX "u"
#define PRIx32         __PRI4_PREFIX "x"
#define PRIX32         __PRI4_PREFIX "X"

/* printf(): (u)int64_t */
#define PRId64         __PRI8_PREFIX "d"
#define PRIi64         __PRI8_PREFIX "i"
#define PRIo64         __PRI8_PREFIX "o"
#define PRIu64         __PRI8_PREFIX "u"
#define PRIx64         __PRI8_PREFIX "x"
#define PRIX64         __PRI8_PREFIX "X"

/* printf(): (u)int_least8_t */
#define PRIdLEAST8     __PRIL1_PREFIX "d"
#define PRIiLEAST8     __PRIL1_PREFIX "i"
#define PRIoLEAST8     __PRIL1_PREFIX "o"
#define PRIuLEAST8     __PRIL1_PREFIX "u"
#define PRIxLEAST8     __PRIL1_PREFIX "x"
#define PRIXLEAST8     __PRIL1_PREFIX "X"

/* printf(): (u)int_least16_t */
#define PRIdLEAST16    __PRIL2_PREFIX "d"
#define PRIiLEAST16    __PRIL2_PREFIX "i"
#define PRIoLEAST16    __PRIL2_PREFIX "o"
#define PRIuLEAST16    __PRIL2_PREFIX "u"
#define PRIxLEAST16    __PRIL2_PREFIX "x"
#define PRIXLEAST16    __PRIL2_PREFIX "X"

/* printf(): (u)int_least32_t */
#define PRIdLEAST32    __PRIL4_PREFIX "d"
#define PRIiLEAST32    __PRIL4_PREFIX "i"
#define PRIoLEAST32    __PRIL4_PREFIX "o"
#define PRIuLEAST32    __PRIL4_PREFIX "u"
#define PRIxLEAST32    __PRIL4_PREFIX "x"
#define PRIXLEAST32    __PRIL4_PREFIX "X"

/* printf(): (u)int_least64_t */
#define PRIdLEAST64    __PRIL8_PREFIX "d"
#define PRIiLEAST64    __PRIL8_PREFIX "i"
#define PRIoLEAST64    __PRIL8_PREFIX "o"
#define PRIuLEAST64    __PRIL8_PREFIX "u"
#define PRIxLEAST64    __PRIL8_PREFIX "x"
#define PRIXLEAST64    __PRIL8_PREFIX "X"

/* printf(): (u)int_fast8_t */
#define PRIdFAST8      __PRIF1_PREFIX "d"
#define PRIiFAST8      __PRIF1_PREFIX "i"
#define PRIoFAST8      __PRIF1_PREFIX "o"
#define PRIuFAST8      __PRIF1_PREFIX "u"
#define PRIxFAST8      __PRIF1_PREFIX "x"
#define PRIXFAST8      __PRIF1_PREFIX "X"

/* printf(): (u)int_fast16_t */
#define PRIdFAST16     __PRIF2_PREFIX "d"
#define PRIiFAST16     __PRIF2_PREFIX "i"
#define PRIoFAST16     __PRIF2_PREFIX "o"
#define PRIuFAST16     __PRIF2_PREFIX "u"
#define PRIxFAST16     __PRIF2_PREFIX "x"
#define PRIXFAST16     __PRIF2_PREFIX "X"

/* printf(): (u)int_fast32_t */
#define PRIdFAST32     __PRIF4_PREFIX "d"
#define PRIiFAST32     __PRIF4_PREFIX "i"
#define PRIoFAST32     __PRIF4_PREFIX "o"
#define PRIuFAST32     __PRIF4_PREFIX "u"
#define PRIxFAST32     __PRIF4_PREFIX "x"
#define PRIXFAST32     __PRIF4_PREFIX "X"

/* printf(): (u)int_fast64_t */
#define PRIdFAST64     __PRIF8_PREFIX "d"
#define PRIiFAST64     __PRIF8_PREFIX "i"
#define PRIoFAST64     __PRIF8_PREFIX "o"
#define PRIuFAST64     __PRIF8_PREFIX "u"
#define PRIxFAST64     __PRIF8_PREFIX "x"
#define PRIXFAST64     __PRIF8_PREFIX "X"

/* printf(): (u)intmax_t */
#define PRIdMAX        __PRI8_PREFIX "d"
#define PRIiMAX        __PRI8_PREFIX "i"
#define PRIoMAX        __PRI8_PREFIX "o"
#define PRIuMAX        __PRI8_PREFIX "u"
#define PRIxMAX        __PRI8_PREFIX "x"
#define PRIXMAX        __PRI8_PREFIX "X"

/* printf(): (u)intptr_t / void * */
#define PRIdPTR        __PRIP_PREFIX "d"
#define PRIiPTR        __PRIP_PREFIX "i"
#define PRIoPTR        __PRIP_PREFIX "o"
#define PRIuPTR        __PRIP_PREFIX "u"
#define PRIxPTR        __PRIP_PREFIX "x"
#define PRIXPTR        __PRIP_PREFIX "X"

#ifdef __USE_KOS
/* printf(): (s)size_t */
#define PRIdSIZ        __PRIP_PREFIX "d"
#define PRIiSIZ        __PRIP_PREFIX "i"
#define PRIoSIZ        __PRIP_PREFIX "o"
#define PRIuSIZ        __PRIP_PREFIX "u"
#define PRIxSIZ        __PRIP_PREFIX "x"
#define PRIXSIZ        __PRIP_PREFIX "X"
#endif /* __USE_KOS */




/* scanf(): (u)int8_t */
#define SCNd8          __SCA1_PREFIX "d"
#define SCNi8          __SCA1_PREFIX "i"
#define SCNu8          __SCA1_PREFIX "u"
#define SCNo8          __SCA1_PREFIX "o"
#define SCNx8          __SCA1_PREFIX "x"

/* scanf(): (u)int16_t */
#define SCNd16         __SCA2_PREFIX "d"
#define SCNi16         __SCA2_PREFIX "i"
#define SCNu16         __SCA2_PREFIX "u"
#define SCNo16         __SCA2_PREFIX "o"
#define SCNx16         __SCA2_PREFIX "x"

/* scanf(): (u)int32_t */
#define SCNd32         __SCA4_PREFIX "d"
#define SCNi32         __SCA4_PREFIX "i"
#define SCNu32         __SCA4_PREFIX "u"
#define SCNo32         __SCA4_PREFIX "o"
#define SCNx32         __SCA4_PREFIX "x"

/* scanf(): (u)int64_t */
#define SCNd64         __SCA8_PREFIX "d"
#define SCNi64         __SCA8_PREFIX "i"
#define SCNu64         __SCA8_PREFIX "u"
#define SCNo64         __SCA8_PREFIX "o"
#define SCNx64         __SCA8_PREFIX "x"

/* scanf(): (u)int_least8_t */
#define SCNdLEAST8     __SCAL1_PREFIX "d"
#define SCNiLEAST8     __SCAL1_PREFIX "i"
#define SCNuLEAST8     __SCAL1_PREFIX "u"
#define SCNoLEAST8     __SCAL1_PREFIX "o"
#define SCNxLEAST8     __SCAL1_PREFIX "x"

/* scanf(): (u)int_least16_t */
#define SCNdLEAST16    __SCAL2_PREFIX "d"
#define SCNiLEAST16    __SCAL2_PREFIX "i"
#define SCNuLEAST16    __SCAL2_PREFIX "u"
#define SCNoLEAST16    __SCAL2_PREFIX "o"
#define SCNxLEAST16    __SCAL2_PREFIX "x"

/* scanf(): (u)int_least32_t */
#define SCNdLEAST32    __SCAL4_PREFIX "d"
#define SCNiLEAST32    __SCAL4_PREFIX "i"
#define SCNuLEAST32    __SCAL4_PREFIX "u"
#define SCNoLEAST32    __SCAL4_PREFIX "o"
#define SCNxLEAST32    __SCAL4_PREFIX "x"

/* scanf(): (u)int_least64_t */
#define SCNdLEAST64    __SCAL8_PREFIX "d"
#define SCNiLEAST64    __SCAL8_PREFIX "i"
#define SCNuLEAST64    __SCAL8_PREFIX "u"
#define SCNoLEAST64    __SCAL8_PREFIX "o"
#define SCNxLEAST64    __SCAL8_PREFIX "x"

/* scanf(): (u)int_fast8_t */
#define SCNdFAST8      __SCAF1_PREFIX "d"
#define SCNiFAST8      __SCAF1_PREFIX "i"
#define SCNuFAST8      __SCAF1_PREFIX "u"
#define SCNoFAST8      __SCAF1_PREFIX "o"
#define SCNxFAST8      __SCAF1_PREFIX "x"

/* scanf(): (u)int_fast16_t */
#define SCNdFAST16     __SCAF2_PREFIX "d"
#define SCNiFAST16     __SCAF2_PREFIX "i"
#define SCNuFAST16     __SCAF2_PREFIX "u"
#define SCNoFAST16     __SCAF2_PREFIX "o"
#define SCNxFAST16     __SCAF2_PREFIX "x"

/* scanf(): (u)int_fast32_t */
#define SCNdFAST32     __SCAF4_PREFIX "d"
#define SCNiFAST32     __SCAF4_PREFIX "i"
#define SCNuFAST32     __SCAF4_PREFIX "u"
#define SCNoFAST32     __SCAF4_PREFIX "o"
#define SCNxFAST32     __SCAF4_PREFIX "x"

/* scanf(): (u)int_fast64_t */
#define SCNdFAST64     __SCAF8_PREFIX "d"
#define SCNiFAST64     __SCAF8_PREFIX "i"
#define SCNuFAST64     __SCAF8_PREFIX "u"
#define SCNoFAST64     __SCAF8_PREFIX "o"
#define SCNxFAST64     __SCAF8_PREFIX "x"

/* scanf(): (u)intmax_t */
#define SCNdMAX        __SCA8_PREFIX "d"
#define SCNiMAX        __SCA8_PREFIX "i"
#define SCNuMAX        __SCA8_PREFIX "u"
#define SCNoMAX        __SCA8_PREFIX "o"
#define SCNxMAX        __SCA8_PREFIX "x"

/* scanf(): (u)intptr_t / void * */
#define SCNdPTR        __SCAP_PREFIX "d"
#define SCNiPTR        __SCAP_PREFIX "i"
#define SCNuPTR        __SCAP_PREFIX "u"
#define SCNoPTR        __SCAP_PREFIX "o"
#define SCNxPTR        __SCAP_PREFIX "x"

#ifdef __USE_KOS
/* scanf(): (s)size_t */
#define SCNdSIZ        __SCAP_PREFIX "d"
#define SCNiSIZ        __SCAP_PREFIX "i"
#define SCNuSIZ        __SCAP_PREFIX "u"
#define SCNoSIZ        __SCAP_PREFIX "o"
#define SCNxSIZ        __SCAP_PREFIX "x"
#endif /* __USE_KOS */



#ifdef __CC__

#ifdef __COMPILER_HAVE_PRAGMA_PUSHMACRO
#pragma push_macro("quot")
#pragma push_macro("rem")
#endif /* __COMPILER_HAVE_PRAGMA_PUSHMACRO */
#undef quot
#undef rem
struct __imaxdiv_struct {
	__INTMAX_TYPE__ quot; /* Quotient. */
	__INTMAX_TYPE__ rem;  /* Remainder. */
};
#ifdef __COMPILER_HAVE_PRAGMA_PUSHMACRO
#pragma pop_macro("rem")
#pragma pop_macro("quot")
#endif /* __COMPILER_HAVE_PRAGMA_PUSHMACRO */

#ifndef __std_imaxdiv_t_defined
#define __std_imaxdiv_t_defined 1
__NAMESPACE_STD_BEGIN
typedef struct __imaxdiv_struct imaxdiv_t;
__NAMESPACE_STD_END
#endif /* !__std_imaxdiv_t_defined */

#ifndef __CXX_SYSTEM_HEADER
#ifndef __imaxdiv_t_defined
#define __imaxdiv_t_defined 1
__NAMESPACE_STD_USING(imaxdiv_t)
#endif /* !__imaxdiv_t_defined */
#endif /* !__CXX_SYSTEM_HEADER */

__NAMESPACE_STD_BEGIN
#if __has_builtin(__builtin_imaxabs) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_imaxabs)
__FORCELOCAL __ATTR_CONST __INTMAX_TYPE__ __NOTHROW(__LIBCCALL imaxabs)(__INTMAX_TYPE__ __x) { return __builtin_imaxabs(__x); }
#elif defined(__CRT_HAVE_imaxabs)
__CDECLARE(__ATTR_CONST,__INTMAX_TYPE__,__NOTHROW,imaxabs,(__INTMAX_TYPE__ __x),(__x))
#elif defined(__CRT_HAVE_abs) && (__SIZEOF_INTMAX_T__ == __SIZEOF_INT__)
__CREDIRECT(__ATTR_CONST,__INTMAX_TYPE__,__NOTHROW,imaxabs,(__INTMAX_TYPE__ __x),abs,(__x))
#elif defined(__CRT_HAVE_labs) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_CONST,__INTMAX_TYPE__,__NOTHROW,imaxabs,(__INTMAX_TYPE__ __x),labs,(__x))
#elif defined(__CRT_HAVE_llabs) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_CONST,__INTMAX_TYPE__,__NOTHROW,imaxabs,(__INTMAX_TYPE__ __x),llabs,(__x))
#else /* LIBC: imaxabs */
__NAMESPACE_STD_END
#include <local/inttypes/imaxabs.h>
__NAMESPACE_STD_BEGIN
__NAMESPACE_LOCAL_USING_OR_IMPL(imaxabs, __FORCELOCAL __ATTR_CONST __INTMAX_TYPE__ __NOTHROW(__LIBCCALL imaxabs)(__INTMAX_TYPE__ __x) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(imaxabs))(__x); })
#endif /* imaxabs... */
#ifdef __CRT_HAVE_imaxdiv
__CDECLARE(__ATTR_CONST,imaxdiv_t,__NOTHROW,imaxdiv,(__INTMAX_TYPE__ __numer, __INTMAX_TYPE__ __denom),(__numer,__denom))
#else /* LIBC: imaxdiv */
__NAMESPACE_STD_END
#include <local/inttypes/imaxdiv.h>
__NAMESPACE_STD_BEGIN
__NAMESPACE_LOCAL_USING_OR_IMPL(imaxdiv, __FORCELOCAL __ATTR_CONST imaxdiv_t __NOTHROW(__LIBCCALL imaxdiv)(__INTMAX_TYPE__ __numer, __INTMAX_TYPE__ __denom) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(imaxdiv))(__numer, __denom); })
#endif /* imaxdiv... */
#ifdef __CRT_HAVE_strtoimax
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax,(char const *__restrict __nptr, char **__endptr, int __base),(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtol) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax,(char const *__restrict __nptr, char **__endptr, int __base),strtol,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtoll) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax,(char const *__restrict __nptr, char **__endptr, int __base),strtoll,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtoq) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax,(char const *__restrict __nptr, char **__endptr, int __base),strtoq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strto64) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax,(char const *__restrict __nptr, char **__endptr, int __base),strto64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE__strtoi64) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax,(char const *__restrict __nptr, char **__endptr, int __base),_strtoi64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strto32) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax,(char const *__restrict __nptr, char **__endptr, int __base),strto32,(__nptr,__endptr,__base))
#else /* LIBC: strtoimax */
__NAMESPACE_STD_END
#include <local/inttypes/strtoimax.h>
__NAMESPACE_STD_BEGIN
__NAMESPACE_LOCAL_USING_OR_IMPL(strtoimax, __FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __INTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL strtoimax)(char const *__restrict __nptr, char **__endptr, int __base) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strtoimax))(__nptr, __endptr, __base); })
#endif /* strtoimax... */
#ifdef __CRT_HAVE_strtoumax
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax,(char const *__restrict __nptr, char **__endptr, int __base),(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtoul) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax,(char const *__restrict __nptr, char **__endptr, int __base),strtoul,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtoull) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax,(char const *__restrict __nptr, char **__endptr, int __base),strtoull,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtouq) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax,(char const *__restrict __nptr, char **__endptr, int __base),strtouq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtou64) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax,(char const *__restrict __nptr, char **__endptr, int __base),strtou64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE__strtoui64) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax,(char const *__restrict __nptr, char **__endptr, int __base),_strtoui64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_strtou32) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax,(char const *__restrict __nptr, char **__endptr, int __base),strtou32,(__nptr,__endptr,__base))
#else /* LIBC: strtoumax */
__NAMESPACE_STD_END
#include <local/inttypes/strtoumax.h>
__NAMESPACE_STD_BEGIN
__NAMESPACE_LOCAL_USING_OR_IMPL(strtoumax, __FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __UINTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL strtoumax)(char const *__restrict __nptr, char **__endptr, int __base) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strtoumax))(__nptr, __endptr, __base); })
#endif /* strtoumax... */
#ifdef __CRT_HAVE_wcstoimax
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstol) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstol,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstoll) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstoll,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstoq) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstoq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcsto64) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcsto64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE__wcstoi64) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),_wcstoi64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcsto32) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcsto32,(__nptr,__endptr,__base))
#else /* LIBC: wcstoimax */
__NAMESPACE_STD_END
#include <local/inttypes/wcstoimax.h>
__NAMESPACE_STD_BEGIN
__NAMESPACE_LOCAL_USING_OR_IMPL(wcstoimax, __FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __INTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL wcstoimax)(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcstoimax))(__nptr, __endptr, __base); })
#endif /* wcstoimax... */
#ifdef __CRT_HAVE_wcstoumax
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstoul) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstoul,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstoull) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstoull,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstouq) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstouq,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstou64) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstou64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE__wcstoui64) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),_wcstoui64,(__nptr,__endptr,__base))
#elif defined(__CRT_HAVE_wcstou32) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base),wcstou32,(__nptr,__endptr,__base))
#else /* LIBC: wcstoumax */
__NAMESPACE_STD_END
#include <local/inttypes/wcstoumax.h>
__NAMESPACE_STD_BEGIN
__NAMESPACE_LOCAL_USING_OR_IMPL(wcstoumax, __FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __UINTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL wcstoumax)(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcstoumax))(__nptr, __endptr, __base); })
#endif /* wcstoumax... */
__NAMESPACE_STD_END
#ifndef __CXX_SYSTEM_HEADER
__NAMESPACE_STD_USING(imaxabs)
__NAMESPACE_STD_USING(imaxdiv)
__NAMESPACE_STD_USING(strtoimax)
__NAMESPACE_STD_USING(strtoumax)
__NAMESPACE_STD_USING(wcstoimax)
__NAMESPACE_STD_USING(wcstoumax)
#endif /* !__CXX_SYSTEM_HEADER */




#ifdef __USE_KOS
#ifdef __USE_XOPEN2K8
#ifdef __CRT_HAVE_strtoimax_l
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___strtol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),__strtol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___strtoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),__strtoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strto64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strto64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoi64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoi64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strto32_l) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strto32_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoimax_l)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoimax_l,(__nptr,__endptr,__base,__locale))
#else /* LIBC: strtoimax_l */
#include <local/inttypes/strtoimax_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(strtoimax_l, __FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __INTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL strtoimax_l)(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strtoimax_l))(__nptr, __endptr, __base, __locale); })
#endif /* strtoimax_l... */
#ifdef __CRT_HAVE_strtoumax_l
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___strtoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),__strtoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___strtoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),__strtoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtou64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtou64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoui64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoui64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtou32_l) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtou32_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoumax_l)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoumax_l,(__nptr,__endptr,__base,__locale))
#else /* LIBC: strtoumax_l */
#include <local/inttypes/strtoumax_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(strtoumax_l, __FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __UINTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL strtoumax_l)(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strtoumax_l))(__nptr, __endptr, __base, __locale); })
#endif /* strtoumax_l... */
#ifdef __CRT_HAVE_wcstoimax_l
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___wcstol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),__wcstol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___wcstoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),__wcstoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcsto64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcsto64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoi64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoi64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcsto32_l) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcsto32_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoimax_l)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoimax_l,(__nptr,__endptr,__base,__locale))
#else /* LIBC: wcstoimax_l */
#include <local/inttypes/wcstoimax_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(wcstoimax_l, __FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __INTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL wcstoimax_l)(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcstoimax_l))(__nptr, __endptr, __base, __locale); })
#endif /* wcstoimax_l... */
#ifdef __CRT_HAVE_wcstoumax_l
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___wcstoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),__wcstoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___wcstoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),__wcstoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstou64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstou64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoui64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoui64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstou32_l) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstou32_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoumax_l)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoumax_l,(__nptr,__endptr,__base,__locale))
#else /* LIBC: wcstoumax_l */
#include <local/inttypes/wcstoumax_l.h>
__NAMESPACE_LOCAL_USING_OR_IMPL(wcstoumax_l, __FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __UINTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL wcstoumax_l)(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcstoumax_l))(__nptr, __endptr, __base, __locale); })
#endif /* wcstoumax_l... */
#endif /* __USE_XOPEN2K8 */
#endif /* __USE_KOS */



#ifdef __USE_DOS
#ifdef __CRT_HAVE_strtoimax_l
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtoimax_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___strtol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),__strtol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___strtoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),__strtoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strto64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strto64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoi64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoi64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strto32_l) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strto32_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoimax_l)
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_strtoimax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),(__nptr,__endptr,__base,__locale))
#else /* LIBC: strtoimax_l */
#include <local/inttypes/strtoimax_l.h>
__FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __INTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL _strtoimax_l)(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strtoimax_l))(__nptr, __endptr, __base, __locale); }
#endif /* _strtoimax_l... */
#ifdef __CRT_HAVE_strtoumax_l
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtoumax_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___strtoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),__strtoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___strtoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),__strtoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtou64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtou64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoui64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),_strtoui64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_strtou32_l) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),strtou32_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__strtoumax_l)
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_strtoumax_l,(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale),(__nptr,__endptr,__base,__locale))
#else /* LIBC: strtoumax_l */
#include <local/inttypes/strtoumax_l.h>
__FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __UINTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL _strtoumax_l)(char const *__restrict __nptr, char **__endptr, int __base, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(strtoumax_l))(__nptr, __endptr, __base, __locale); }
#endif /* _strtoumax_l... */
#ifdef __CRT_HAVE_wcstoimax_l
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstoimax_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___wcstol_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),__wcstol_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___wcstoll_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),__wcstoll_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcsto64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcsto64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoi64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoi64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcsto32_l) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcsto32_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoimax_l)
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__INTMAX_TYPE__,__NOTHROW_NCX,_wcstoimax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),(__nptr,__endptr,__base,__locale))
#else /* LIBC: wcstoimax_l */
#include <local/inttypes/wcstoimax_l.h>
__FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __INTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL _wcstoimax_l)(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcstoimax_l))(__nptr, __endptr, __base, __locale); }
#endif /* _wcstoimax_l... */
#ifdef __CRT_HAVE_wcstoumax_l
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstoumax_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___wcstoul_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),__wcstoul_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE___wcstoull_l) && (__SIZEOF_INTMAX_T__ == __SIZEOF_LONG_LONG__)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),__wcstoull_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstou64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstou64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoui64_l) && (__SIZEOF_INTMAX_T__ == 8)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),_wcstoui64_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE_wcstou32_l) && (__SIZEOF_INTMAX_T__ == 4)
__CREDIRECT(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),wcstou32_l,(__nptr,__endptr,__base,__locale))
#elif defined(__CRT_HAVE__wcstoumax_l)
__CDECLARE(__ATTR_LEAF __ATTR_NONNULL((1)),__UINTMAX_TYPE__,__NOTHROW_NCX,_wcstoumax_l,(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale),(__nptr,__endptr,__base,__locale))
#else /* LIBC: wcstoumax_l */
#include <local/inttypes/wcstoumax_l.h>
__FORCELOCAL __ATTR_LEAF __ATTR_NONNULL((1)) __UINTMAX_TYPE__ __NOTHROW_NCX(__LIBCCALL _wcstoumax_l)(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr, int __base, __locale_t __locale) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(wcstoumax_l))(__nptr, __endptr, __base, __locale); }
#endif /* _wcstoumax_l... */
#endif /* __USE_DOS */

#endif /* __CC__ */

__SYSDECL_END

#ifdef __USE_UTF
#if defined(_UCHAR_H) && !defined(_PARTS_UCHAR_INTTYPES_H)
#include <parts/uchar/inttypes.h>
#endif /* _UCHAR_H && !_PARTS_UCHAR_INTTYPES_H */
#endif /* __USE_UTF */

#ifdef __CXX_SYSTEM_HEADER
#define _CXX_STDONLY_CINTTYPES 1
#undef _INTTYPES_H
#endif /* __CXX_SYSTEM_HEADER */
#endif /* !_CXX_STDONLY_CINTTYPES */
#endif /* !_INTTYPES_H */
