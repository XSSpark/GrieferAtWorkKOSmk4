/* HASH CRC-32:0xcd3705ea */
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
#ifndef __local_wcstod_defined
#define __local_wcstod_defined
#include <__crt.h>
__NAMESPACE_LOCAL_BEGIN
#ifndef __local___localdep_iswalnum_defined
#define __local___localdep_iswalnum_defined
__NAMESPACE_LOCAL_END
#include <bits/crt/wctype.h>
__NAMESPACE_LOCAL_BEGIN
#if defined(__crt_iswalnum) && defined(__CRT_HAVE_iswalnum)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iswalnum,(__WINT_TYPE__ __wc),iswalnum,{ return __crt_iswalnum(__wc); })
#elif defined(__crt_iswalnum)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL __ATTR_CONST __ATTR_WUNUSED int __NOTHROW(__LIBCCALL __localdep_iswalnum)(__WINT_TYPE__ __wc) { return __crt_iswalnum(__wc); }
#elif __has_builtin(__builtin_iswalnum) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_iswalnum)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iswalnum,(__WINT_TYPE__ __wc),iswalnum,{ return __builtin_iswalnum(__wc); })
#elif defined(__CRT_HAVE_iswalnum)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iswalnum,(__WINT_TYPE__ __wc),iswalnum,(__wc))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/wctype/iswalnum.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_iswalnum __LIBC_LOCAL_NAME(iswalnum)
#endif /* !... */
#endif /* !__local___localdep_iswalnum_defined */
#ifndef __local___localdep_iswdigit_defined
#define __local___localdep_iswdigit_defined
__NAMESPACE_LOCAL_END
#include <bits/crt/wctype.h>
__NAMESPACE_LOCAL_BEGIN
#if defined(__crt_iswdigit) && defined(__CRT_HAVE_iswdigit)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iswdigit,(__WINT_TYPE__ __wc),iswdigit,{ return __crt_iswdigit(__wc); })
#elif defined(__crt_iswdigit)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL __ATTR_CONST __ATTR_WUNUSED int __NOTHROW(__LIBCCALL __localdep_iswdigit)(__WINT_TYPE__ __wc) { return __crt_iswdigit(__wc); }
#elif __has_builtin(__builtin_iswdigit) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_iswdigit)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iswdigit,(__WINT_TYPE__ __wc),iswdigit,{ return __builtin_iswdigit(__wc); })
#elif defined(__CRT_HAVE_iswdigit)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iswdigit,(__WINT_TYPE__ __wc),iswdigit,(__wc))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/wctype/iswdigit.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_iswdigit __LIBC_LOCAL_NAME(iswdigit)
#endif /* !... */
#endif /* !__local___localdep_iswdigit_defined */
#ifndef __local___localdep_iswspace_defined
#define __local___localdep_iswspace_defined
__NAMESPACE_LOCAL_END
#include <bits/crt/wctype.h>
__NAMESPACE_LOCAL_BEGIN
#if defined(__crt_iswspace) && defined(__CRT_HAVE_iswspace)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iswspace,(__WINT_TYPE__ __wc),iswspace,{ return __crt_iswspace(__wc); })
#elif defined(__crt_iswspace)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL __ATTR_CONST __ATTR_WUNUSED int __NOTHROW(__LIBCCALL __localdep_iswspace)(__WINT_TYPE__ __wc) { return __crt_iswspace(__wc); }
#elif __has_builtin(__builtin_iswspace) && defined(__LIBC_BIND_CRTBUILTINS) && defined(__CRT_HAVE_iswspace)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CEIREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iswspace,(__WINT_TYPE__ __wc),iswspace,{ return __builtin_iswspace(__wc); })
#elif defined(__CRT_HAVE_iswspace)
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_CONST __ATTR_WUNUSED,int,__NOTHROW,__localdep_iswspace,(__WINT_TYPE__ __wc),iswspace,(__wc))
#else /* ... */
__NAMESPACE_LOCAL_END
#include <libc/local/wctype/iswspace.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_iswspace __LIBC_LOCAL_NAME(iswspace)
#endif /* !... */
#endif /* !__local___localdep_iswspace_defined */
#ifndef __local___localdep_unicode_readutf16_defined
#define __local___localdep_unicode_readutf16_defined
#ifdef __CRT_HAVE_unicode_readutf16
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_INOUT(1),__CHAR32_TYPE__,__NOTHROW_NCX,__localdep_unicode_readutf16,(__CHAR16_TYPE__ const **__restrict __ptext),unicode_readutf16,(__ptext))
#else /* __CRT_HAVE_unicode_readutf16 */
__NAMESPACE_LOCAL_END
#include <libc/local/unicode/unicode_readutf16.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_unicode_readutf16 __LIBC_LOCAL_NAME(unicode_readutf16)
#endif /* !__CRT_HAVE_unicode_readutf16 */
#endif /* !__local___localdep_unicode_readutf16_defined */
#ifndef __local___localdep_unicode_readutf16_rev_defined
#define __local___localdep_unicode_readutf16_rev_defined
#ifdef __CRT_HAVE_unicode_readutf16_rev
__NAMESPACE_LOCAL_END
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__CREDIRECT(__ATTR_INOUT(1),__CHAR32_TYPE__,__NOTHROW_NCX,__localdep_unicode_readutf16_rev,(__CHAR16_TYPE__ const **__restrict __ptext),unicode_readutf16_rev,(__ptext))
#else /* __CRT_HAVE_unicode_readutf16_rev */
__NAMESPACE_LOCAL_END
#include <libc/local/unicode/unicode_readutf16_rev.h>
__NAMESPACE_LOCAL_BEGIN
#define __localdep_unicode_readutf16_rev __LIBC_LOCAL_NAME(unicode_readutf16_rev)
#endif /* !__CRT_HAVE_unicode_readutf16_rev */
#endif /* !__local___localdep_unicode_readutf16_rev_defined */
__NAMESPACE_LOCAL_END
#include <ieee754.h>
#include <libm/inf.h>
#include <libm/nan.h>
#include <libc/unicode.h>
#include <hybrid/typecore.h>
__NAMESPACE_LOCAL_BEGIN
__LOCAL_LIBC(wcstod) __ATTR_LEAF __ATTR_IN(1) __ATTR_OUT_OPT(2) double
__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(wcstod))(__WCHAR_TYPE__ const *__restrict __nptr, __WCHAR_TYPE__ **__endptr) {
	__WCHAR_TYPE__ __sign, __ch = *__nptr;
	double __float_extension_mult;
	double __fltval = 0.0;
	__UINT8_TYPE__ __numsys, __digit;
	while ((__NAMESPACE_LOCAL_SYM __localdep_iswspace)((__WCHAR_TYPE__)__ch))
		__ch = *++__nptr;
	__sign = __ch;
	if (__sign == '+' || __sign == '-')
		__ch = *++__nptr;
	if (__ch == '0') {
		__ch = *++__nptr;
		if (__ch == 'x' || __ch == 'X') {
			__ch = *++__nptr;
			__numsys = 16;
		} else if (__ch == 'b' || __ch == 'B') {
			__ch = *++__nptr;
			__numsys = 2;
		} else if (__ch == '.') {
			__numsys = 10;
		} else if (!(__NAMESPACE_LOCAL_SYM __localdep_iswdigit)((__WCHAR_TYPE__)__ch)) {
			goto __done;
		} else {
			/*numsys = 8;*/ /* Would be non-conforming */
			__numsys = 10;
		}
	} else {
#if defined(__IEEE754_DOUBLE_TYPE_IS_DOUBLE__) || defined(__IEEE754_FLOAT_TYPE_IS_DOUBLE__) || defined(__IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__)
		if ((__ch == 'i' || __ch == 'I') &&
		    (__nptr[1] == 'n' || __nptr[1] == 'N') &&
		    (__nptr[2] == 'f' || __nptr[2] == 'F') &&
		    !(__NAMESPACE_LOCAL_SYM __localdep_iswalnum)((__WCHAR_TYPE__)__nptr[3])) {
			__nptr += 3;
			if (__endptr)
				*__endptr = (__WCHAR_TYPE__ *)__nptr;
			return __sign == '-' ? -__LIBM_MATHFUN0(inf)
			                   : +__LIBM_MATHFUN0(inf);
		}
		if ((__ch == 'n' || __ch == 'N') &&
		    (__nptr[1] == 'a' || __nptr[1] == 'A') &&
		    (__nptr[2] == 'n' || __nptr[2] == 'N') &&
		    !(__NAMESPACE_LOCAL_SYM __localdep_iswalnum)((__WCHAR_TYPE__)__nptr[3])) {
			__nptr += 3;
			if (*__nptr == '(') {
				++__nptr;
				while (*__nptr != ')')
					++__nptr;
				++__nptr;
				/* XXX: Custom nan-tag? */
			}
			if (__endptr)
				*__endptr = (__WCHAR_TYPE__ *)__nptr;
			return __sign == '-' ? -__LIBM_MATHFUN1I(nan, __NULLPTR)
			                   : +__LIBM_MATHFUN1I(nan, __NULLPTR);
		}
#endif /* __IEEE754_DOUBLE_TYPE_IS_DOUBLE__ || __IEEE754_FLOAT_TYPE_IS_DOUBLE__ || __IEEE854_LONG_DOUBLE_TYPE_IS_DOUBLE__ */
		__numsys = 10;
	}

	__float_extension_mult = 0.0;
__next:
	switch (__ch) {
	case 'p':
	case 'P':
		if (__numsys == 10)
			goto __done;
		goto __flt_exp;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		__digit = __ch - '0';
		break;

	case 'e':
		if (__numsys == 10)
			goto __flt_exp;
		__ATTR_FALLTHROUGH
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'f':
		__digit = 10 + __ch - 'a';
		break;

	case 'E':
		if (__numsys == 10)
			goto __flt_exp;
		__ATTR_FALLTHROUGH
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'F':
		__digit = 10 + __ch - 'A';
		break;

	case '.':
		if (__float_extension_mult != 0.0)
			goto __done;
		__float_extension_mult = (double)__numsys;
		__ch = *++__nptr;
		goto __next;

	default: {
#if __SIZEOF_WCHAR_T__ == 1
		__WCHAR_TYPE__ const *__new_nptr;
		__CHAR32_TYPE__ __uni;
#ifndef __OPTIMIZE_SIZE__
		if ((__WCHAR_TYPE__)__ch < 0x80)
			goto __done;
#endif /* !__OPTIMIZE_SIZE__ */
		__new_nptr = __nptr;
		__uni = __libc_unicode_readutf8(&__new_nptr);
		if (__libc_unicode_asdigit(__uni, __numsys, &__digit)) {
			__nptr = __new_nptr;
		} else
#elif __SIZEOF_WCHAR_T__ == 2
		__CHAR16_TYPE__ const *__new_nptr;
		__CHAR32_TYPE__ __uni;
		__new_nptr = (__CHAR16_TYPE__ const *)__nptr;
		__uni = __libc_unicode_readutf16(&__new_nptr);
		if (__libc_unicode_asdigit(__uni, __numsys, &__digit)) {
			__nptr = __new_nptr;
		} else
#else /* ... */
		if (__libc_unicode_asdigit(__ch, __numsys, &__digit)) {
			++__nptr;
		} else
#endif /* !... */
		{
			goto __done;
		}
	}	break;

	}
	if __unlikely(__digit >= __numsys)
		goto __done;
	__ch = *++__nptr;
	if (__float_extension_mult != 0.0) {
		__fltval += (double)__digit / __float_extension_mult;
		__float_extension_mult *= __numsys;
	} else {
		__fltval = __fltval * __numsys + __digit;
	}
	goto __next;
	{
#define __float_extension_pos __digit
		unsigned int __float_extension_off;
		__WCHAR_TYPE__ __float_exp_mode;
__flt_exp:
		__float_exp_mode = __ch;
		__float_extension_pos = 1;
		__float_extension_off = 0;
		__ch = *++__nptr;
		if (__ch == '-' || __ch == '+') {
			__float_extension_pos = (__ch == '+');
			__ch = *++__nptr;
		}
		while (__ch >= '0' && __ch <= '9') {
			__float_extension_off *= 10;
			__float_extension_off += __ch - '0';
			__ch = *++__nptr;
		}
		__float_extension_mult = 1.0;
		if (__float_exp_mode == 'e' || __float_exp_mode == 'E') {
			while (__float_extension_off != 0) {
				__float_extension_mult *= 10.0;
				--__float_extension_off;
			}
		} else {
			while (__float_extension_off != 0) {
				__float_extension_mult *= 2.0;
				--__float_extension_off;
			}
		}
		if (__float_extension_pos) {
			__fltval *= __float_extension_mult;
		} else {
			__fltval /= __float_extension_mult;
		}
#undef __float_extension_pos
		/* FALLTHRU to "done" */
	}
__done:
	if (__endptr)
		*__endptr = (__WCHAR_TYPE__ *)__nptr;
	if (__sign == '-')
		__fltval = -__fltval;
	return __fltval;
}
__NAMESPACE_LOCAL_END
#ifndef __local___localdep_wcstod_defined
#define __local___localdep_wcstod_defined
#define __localdep_wcstod __LIBC_LOCAL_NAME(wcstod)
#endif /* !__local___localdep_wcstod_defined */
#endif /* !__local_wcstod_defined */
