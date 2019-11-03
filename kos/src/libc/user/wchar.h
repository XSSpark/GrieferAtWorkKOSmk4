/* HASH CRC-32:0xb586026 */
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
#ifndef GUARD_LIBC_USER_WCHAR_H
#define GUARD_LIBC_USER_WCHAR_H 1

#include "../api.h"
#include "../auto/wchar.h"
#include <kos/anno.h>
#include <hybrid/typecore.h>
#include <kos/types.h>
#include <wchar.h>

DECL_BEGIN

INTDEF wint_t (LIBCCALL libc_getwchar)(void) __THROWS(...);
INTDEF wint_t (LIBDCALL libd_getwchar)(void) __THROWS(...);
INTDEF NONNULL((1)) wint_t (LIBCCALL libc_fgetwc)(FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((1)) wint_t (LIBDCALL libd_fgetwc)(FILE *__restrict stream) __THROWS(...);
INTDEF wint_t (LIBCCALL libc_putwchar)(char32_t wc) __THROWS(...);
INTDEF wint_t (LIBDCALL libd_putwchar)(char16_t wc) __THROWS(...);
INTDEF NONNULL((2)) wint_t (LIBCCALL libc_fputwc)(char32_t wc, FILE *stream) __THROWS(...);
INTDEF NONNULL((2)) wint_t (LIBDCALL libd_fputwc)(char16_t wc, FILE *stream) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 3)) char32_t *(LIBCCALL libc_fgetws)(char32_t *__restrict buf, __STDC_INT_AS_SIZE_T bufsize, FILE *__restrict stream) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 3)) char16_t *(LIBDCALL libd_fgetws)(char16_t *__restrict buf, __STDC_INT_AS_SIZE_T bufsize, FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SIZE_T (LIBCCALL libc_fputws)(char32_t const *__restrict string, FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SIZE_T (LIBDCALL libd_fputws)(char16_t const *__restrict string, FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((2)) wint_t NOTHROW_NCX(LIBCCALL libc_ungetwc)(wint_t wc, FILE *stream);
INTDEF NONNULL((2)) wint_t NOTHROW_NCX(LIBDCALL libd_ungetwc)(wint_t wc, FILE *stream);
INTDEF NONNULL((1, 2)) ATTR_LIBC_WPRINTF(2, 3) __STDC_INT_AS_SIZE_T (VLIBCCALL libc_fwprintf)(FILE *__restrict stream, char32_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1, 2)) ATTR_LIBC_WPRINTF(2, 3) __STDC_INT_AS_SIZE_T (VLIBDCALL libd_fwprintf)(FILE *__restrict stream, char16_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1, 2)) ATTR_LIBC_WPRINTF(2, 0) __STDC_INT_AS_SIZE_T (LIBCCALL libc_vfwprintf)(FILE *__restrict stream, char32_t const *__restrict format, va_list args) __THROWS(...);
INTDEF NONNULL((1, 2)) ATTR_LIBC_WPRINTF(2, 0) __STDC_INT_AS_SIZE_T (LIBDCALL libd_vfwprintf)(FILE *__restrict stream, char16_t const *__restrict format, va_list args) __THROWS(...);
INTDEF NONNULL((1)) ATTR_LIBC_WPRINTF(1, 2) __STDC_INT_AS_SIZE_T (VLIBCCALL libc_wprintf)(char32_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1)) ATTR_LIBC_WPRINTF(1, 2) __STDC_INT_AS_SIZE_T (VLIBDCALL libd_wprintf)(char16_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1)) ATTR_LIBC_WPRINTF(1, 0) __STDC_INT_AS_SIZE_T (LIBCCALL libc_vwprintf)(char32_t const *__restrict format, va_list args) __THROWS(...);
INTDEF NONNULL((1)) ATTR_LIBC_WPRINTF(1, 0) __STDC_INT_AS_SIZE_T (LIBDCALL libd_vwprintf)(char16_t const *__restrict format, va_list args) __THROWS(...);
INTDEF NONNULL((1, 2)) ATTR_LIBC_WSCANF(2, 3) __STDC_INT_AS_SIZE_T (VLIBCCALL libc_fwscanf)(FILE *__restrict stream, char32_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1, 2)) ATTR_LIBC_WSCANF(2, 3) __STDC_INT_AS_SIZE_T (VLIBDCALL libd_fwscanf)(FILE *__restrict stream, char16_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1)) ATTR_LIBC_WSCANF(1, 2) __STDC_INT_AS_SIZE_T (VLIBCCALL libc_wscanf)(char32_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1)) ATTR_LIBC_WSCANF(1, 2) __STDC_INT_AS_SIZE_T (VLIBDCALL libd_wscanf)(char16_t const *__restrict format, ...) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) ATTR_LIBC_WSCANF(2, 0) __STDC_INT_AS_SIZE_T (LIBCCALL libc_vfwscanf)(FILE *__restrict stream, char32_t const *__restrict format, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) ATTR_LIBC_WSCANF(2, 0) __STDC_INT_AS_SIZE_T (LIBDCALL libd_vfwscanf)(FILE *__restrict stream, char16_t const *__restrict format, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1)) ATTR_LIBC_WSCANF(1, 0) __STDC_INT_AS_SIZE_T (LIBCCALL libc_vwscanf)(char32_t const *__restrict format, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1)) ATTR_LIBC_WSCANF(1, 0) __STDC_INT_AS_SIZE_T (LIBDCALL libd_vwscanf)(char16_t const *__restrict format, va_list args) __THROWS(...);
INTDEF NONNULL((2)) size_t NOTHROW_NCX(LIBCCALL libc_mbsnrtowcs)(char32_t *dst, char const **__restrict psrc, size_t nmc, size_t len, mbstate_t *ps);
INTDEF NONNULL((2)) size_t NOTHROW_NCX(LIBDCALL libd_mbsnrtowcs)(char16_t *dst, char const **__restrict psrc, size_t nmc, size_t len, mbstate_t *ps);
INTDEF NONNULL((2)) size_t NOTHROW_NCX(LIBCCALL libc_wcsnrtombs)(char *dst, char32_t const **__restrict psrc, size_t nwc, size_t len, mbstate_t *ps);
INTDEF NONNULL((2)) size_t NOTHROW_NCX(LIBDCALL libd_wcsnrtombs)(char *dst, char16_t const **__restrict psrc, size_t nwc, size_t len, mbstate_t *ps);
INTDEF FILE *NOTHROW_NCX(LIBCCALL libc_open_wmemstream)(char32_t **bufloc, size_t *sizeloc);
INTDEF FILE *NOTHROW_NCX(LIBDCALL libd_open_wmemstream)(char16_t **bufloc, size_t *sizeloc);
INTDEF ATTR_MALLOC ATTR_MALL_DEFAULT_ALIGNED WUNUSED NONNULL((1)) char32_t *NOTHROW_NCX(LIBCCALL libc_wcsdup)(char32_t const *__restrict string);
INTDEF ATTR_MALLOC ATTR_MALL_DEFAULT_ALIGNED WUNUSED NONNULL((1)) char16_t *NOTHROW_NCX(LIBDCALL libd_wcsdup)(char16_t const *__restrict string);
INTDEF WUNUSED int NOTHROW_NCX(LIBCCALL libc_wcwidth)(char32_t ch);
INTDEF WUNUSED int NOTHROW_NCX(LIBDCALL libd_wcwidth)(char16_t ch);
INTDEF WUNUSED NONNULL((1)) int NOTHROW_NCX(LIBCCALL libc_wcswidth)(char32_t const *__restrict string, size_t num_chars);
INTDEF WUNUSED NONNULL((1)) int NOTHROW_NCX(LIBDCALL libd_wcswidth)(char16_t const *__restrict string, size_t num_chars);
INTDEF wint_t (LIBCCALL libc_getwchar_unlocked)(void) __THROWS(...);
INTDEF wint_t (LIBDCALL libd_getwchar_unlocked)(void) __THROWS(...);
INTDEF wint_t (LIBCCALL libc_putwchar_unlocked)(char32_t wc) __THROWS(...);
INTDEF wint_t (LIBDCALL libd_putwchar_unlocked)(char16_t wc) __THROWS(...);
INTDEF NONNULL((1)) wint_t (LIBCCALL libc_fgetwc_unlocked)(FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((1)) wint_t (LIBDCALL libd_fgetwc_unlocked)(FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((2)) wint_t (LIBCCALL libc_fputwc_unlocked)(char32_t wc, FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((2)) wint_t (LIBDCALL libd_fputwc_unlocked)(char16_t wc, FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((1, 3)) char32_t *(LIBCCALL libc_fgetws_unlocked)(char32_t *__restrict buf, __STDC_INT_AS_SIZE_T bufsize, FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((1, 3)) char16_t *(LIBDCALL libd_fgetws_unlocked)(char16_t *__restrict buf, __STDC_INT_AS_SIZE_T bufsize, FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SIZE_T (LIBCCALL libc_fputws_unlocked)(char32_t const *__restrict string, FILE *__restrict stream) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SIZE_T (LIBDCALL libd_fputws_unlocked)(char16_t const *__restrict string, FILE *__restrict stream) __THROWS(...);
/* For use with `format_printf()' and friends: Prints to a `FILE *' closure argument */
INTDEF NONNULL((1, 2)) ssize_t (LIBCCALL libc_file_wprinter)(void *arg, char32_t const *__restrict data, size_t datalen) __THROWS(...);
/* For use with `format_printf()' and friends: Prints to a `FILE *' closure argument */
INTDEF NONNULL((1, 2)) ssize_t (LIBDCALL libd_file_wprinter)(void *arg, char16_t const *__restrict data, size_t datalen) __THROWS(...);
/* Same as `file_wprinter()', but performs I/O without acquiring a lock to `($FILE *)ARG' */
INTDEF NONNULL((1, 2)) ssize_t (LIBCCALL libc_file_wprinter_unlocked)(void *arg, char32_t const *__restrict data, size_t datalen) __THROWS(...);
/* Same as `file_wprinter()', but performs I/O without acquiring a lock to `($FILE *)ARG' */
INTDEF NONNULL((1, 2)) ssize_t (LIBDCALL libd_file_wprinter_unlocked)(void *arg, char16_t const *__restrict data, size_t datalen) __THROWS(...);
INTDEF NONNULL((2)) wint_t NOTHROW_NCX(LIBCCALL libc_ungetwc_unlocked)(wint_t ch, FILE *__restrict stream);
INTDEF NONNULL((2)) wint_t NOTHROW_NCX(LIBDCALL libd_ungetwc_unlocked)(wint_t ch, FILE *__restrict stream);
INTDEF NONNULL((1, 2)) ATTR_LIBC_WPRINTF(2, 0) __STDC_INT_AS_SIZE_T (LIBCCALL libc_vfwprintf_unlocked)(FILE *__restrict stream, char32_t const *__restrict format, va_list args) __THROWS(...);
INTDEF NONNULL((1, 2)) ATTR_LIBC_WPRINTF(2, 0) __STDC_INT_AS_SIZE_T (LIBDCALL libd_vfwprintf_unlocked)(FILE *__restrict stream, char16_t const *__restrict format, va_list args) __THROWS(...);
INTDEF NONNULL((1, 2)) ATTR_LIBC_WPRINTF(2, 3) __STDC_INT_AS_SIZE_T (VLIBCCALL libc_fwprintf_unlocked)(FILE *__restrict stream, char32_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1, 2)) ATTR_LIBC_WPRINTF(2, 3) __STDC_INT_AS_SIZE_T (VLIBDCALL libd_fwprintf_unlocked)(FILE *__restrict stream, char16_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1)) ATTR_LIBC_WPRINTF(1, 2) __STDC_INT_AS_SIZE_T (VLIBCCALL libc_wprintf_unlocked)(char32_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1)) ATTR_LIBC_WPRINTF(1, 2) __STDC_INT_AS_SIZE_T (VLIBDCALL libd_wprintf_unlocked)(char16_t const *__restrict format, ...) __THROWS(...);
INTDEF NONNULL((1)) ATTR_LIBC_WPRINTF(1, 0) __STDC_INT_AS_SIZE_T (LIBCCALL libc_vwprintf_unlocked)(char32_t const *__restrict format, va_list args) __THROWS(...);
INTDEF NONNULL((1)) ATTR_LIBC_WPRINTF(1, 0) __STDC_INT_AS_SIZE_T (LIBDCALL libd_vwprintf_unlocked)(char16_t const *__restrict format, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) ATTR_LIBC_WSCANF(2, 0) __STDC_INT_AS_SIZE_T (LIBCCALL libc_vfwscanf_unlocked)(FILE *__restrict stream, char32_t const *__restrict format, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) ATTR_LIBC_WSCANF(2, 0) __STDC_INT_AS_SIZE_T (LIBDCALL libd_vfwscanf_unlocked)(FILE *__restrict stream, char16_t const *__restrict format, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1)) ATTR_LIBC_SCANF(1, 0) __STDC_INT_AS_SIZE_T (LIBCCALL libc_vwscanf_unlocked)(char32_t const *__restrict format, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1)) ATTR_LIBC_SCANF(1, 0) __STDC_INT_AS_SIZE_T (LIBDCALL libd_vwscanf_unlocked)(char16_t const *__restrict format, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) ATTR_LIBC_SCANF(2, 3) __STDC_INT_AS_SIZE_T (VLIBCCALL libc_fwscanf_unlocked)(FILE *__restrict stream, char32_t const *__restrict format, ...) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) ATTR_LIBC_SCANF(2, 3) __STDC_INT_AS_SIZE_T (VLIBDCALL libd_fwscanf_unlocked)(FILE *__restrict stream, char16_t const *__restrict format, ...) __THROWS(...);
INTDEF WUNUSED NONNULL((1)) ATTR_LIBC_SCANF(1, 2) __STDC_INT_AS_SIZE_T (VLIBCCALL libc_wscanf_unlocked)(char32_t const *__restrict format, ...) __THROWS(...);
INTDEF WUNUSED NONNULL((1)) ATTR_LIBC_SCANF(1, 2) __STDC_INT_AS_SIZE_T (VLIBDCALL libd_wscanf_unlocked)(char16_t const *__restrict format, ...) __THROWS(...);
INTDEF ATTR_MALLOC ATTR_MALL_DEFAULT_ALIGNED WUNUSED NONNULL((1)) char32_t *NOTHROW_NCX(LIBCCALL libc_wcsndup)(char32_t const *__restrict string, size_t max_chars);
INTDEF ATTR_MALLOC ATTR_MALL_DEFAULT_ALIGNED WUNUSED NONNULL((1)) char16_t *NOTHROW_NCX(LIBDCALL libd_wcsndup)(char16_t const *__restrict string, size_t max_chars);
INTDEF char32_t *NOTHROW_NCX(LIBCCALL libc__wcserror)(int errno_value);
INTDEF char16_t *NOTHROW_NCX(LIBDCALL libd__wcserror)(int errno_value);
INTDEF errno_t NOTHROW_NCX(LIBCCALL libc__wcserror_s)(char32_t *buf, size_t bufsize, int errno_value);
INTDEF errno_t NOTHROW_NCX(LIBDCALL libd__wcserror_s)(char16_t *buf, size_t bufsize, int errno_value);
INTDEF char32_t *NOTHROW_NCX(LIBCCALL libc___wcserror)(char32_t const *message);
INTDEF char16_t *NOTHROW_NCX(LIBDCALL libd___wcserror)(char16_t const *message);
INTDEF errno_t NOTHROW_NCX(LIBCCALL libc___wcserror_s)(char32_t *buf, size_t bufsize, char32_t const *message);
INTDEF errno_t NOTHROW_NCX(LIBDCALL libd___wcserror_s)(char16_t *buf, size_t bufsize, char16_t const *message);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (LIBCCALL libc__vwprintf_p)(char32_t const *format, va_list args) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (LIBDCALL libd__vwprintf_p)(char16_t const *format, va_list args) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (VLIBCCALL libc__wprintf_p)(char32_t const *format, ...) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (VLIBDCALL libd__wprintf_p)(char16_t const *format, ...) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (LIBCCALL libc__vwprintf_l)(char32_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (LIBDCALL libd__vwprintf_l)(char16_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (VLIBCCALL libc__wprintf_l)(char32_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (VLIBDCALL libd__wprintf_l)(char16_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (LIBCCALL libc__vwprintf_p_l)(char32_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (LIBDCALL libd__vwprintf_p_l)(char16_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (VLIBCCALL libc__wprintf_p_l)(char32_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (VLIBDCALL libd__wprintf_p_l)(char16_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (LIBCCALL libc__vwprintf_s_l)(char32_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (LIBDCALL libd__vwprintf_s_l)(char16_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (VLIBCCALL libc__wprintf_s_l)(char32_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF NONNULL((1)) __STDC_INT_AS_SSIZE_T (VLIBDCALL libd__wprintf_s_l)(char16_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (LIBCCALL libc__vfwprintf_l)(FILE *stream, char32_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (LIBDCALL libd__vfwprintf_l)(FILE *stream, char16_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (VLIBCCALL libc__fwprintf_l)(FILE *stream, char32_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (VLIBDCALL libd__fwprintf_l)(FILE *stream, char16_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (LIBCCALL libc__vfwprintf_s_l)(FILE *stream, char32_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (LIBDCALL libd__vfwprintf_s_l)(FILE *stream, char16_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (VLIBCCALL libc__fwprintf_s_l)(FILE *stream, char32_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (VLIBDCALL libd__fwprintf_s_l)(FILE *stream, char16_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (LIBCCALL libc__vfwscanf_l)(FILE *stream, char32_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (LIBDCALL libd__vfwscanf_l)(FILE *stream, char16_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (VLIBCCALL libc__fwscanf_l)(FILE *stream, char32_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) __STDC_INT_AS_SSIZE_T (VLIBDCALL libd__fwscanf_l)(FILE *stream, char16_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF WUNUSED NONNULL((1)) __STDC_INT_AS_SSIZE_T (LIBCCALL libc__vwscanf_l)(char32_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1)) __STDC_INT_AS_SSIZE_T (LIBDCALL libd__vwscanf_l)(char16_t const *format, locale_t locale, va_list args) __THROWS(...);
INTDEF WUNUSED NONNULL((1)) __STDC_INT_AS_SSIZE_T (VLIBCCALL libc__wscanf_l)(char32_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF WUNUSED NONNULL((1)) __STDC_INT_AS_SSIZE_T (VLIBDCALL libd__wscanf_l)(char16_t const *format, locale_t locale, ...) __THROWS(...);
INTDEF WUNUSED NONNULL((1, 2)) FILE *NOTHROW_NCX(LIBCCALL libc__wfsopen)(char32_t const *filename, char32_t const *mode, int sh_flag);
INTDEF WUNUSED NONNULL((1, 2)) FILE *NOTHROW_NCX(LIBDCALL libd__wfsopen)(char16_t const *filename, char16_t const *mode, int sh_flag);
INTDEF WUNUSED NONNULL((2)) FILE *NOTHROW_NCX(LIBCCALL libc__wfdopen)(fd_t fd, char32_t const *mode);
INTDEF WUNUSED NONNULL((2)) FILE *NOTHROW_NCX(LIBDCALL libd__wfdopen)(fd_t fd, char16_t const *mode);
INTDEF NONNULL((1, 2, 3)) errno_t NOTHROW_NCX(LIBCCALL libc__wfopen_s)(FILE **pstream, char32_t const *filename, char32_t const *mode);
INTDEF NONNULL((1, 2, 3)) errno_t NOTHROW_NCX(LIBDCALL libd__wfopen_s)(FILE **pstream, char16_t const *filename, char16_t const *mode);
INTDEF NONNULL((1, 2, 3)) errno_t NOTHROW_NCX(LIBCCALL libc__wfreopen_s)(FILE **pstream, char32_t const *filename, char32_t const *mode, FILE *stream);
INTDEF NONNULL((1, 2, 3)) errno_t NOTHROW_NCX(LIBDCALL libd__wfreopen_s)(FILE **pstream, char16_t const *filename, char16_t const *mode, FILE *stream);
INTDEF char32_t *NOTHROW_NCX(LIBCCALL libc__getws_s)(char32_t *buf, size_t buflen);
INTDEF char16_t *NOTHROW_NCX(LIBDCALL libd__getws_s)(char16_t *buf, size_t buflen);
INTDEF NONNULL((1)) __STDC_INT_AS_SIZE_T NOTHROW_NCX(LIBCCALL libc__putws)(char32_t const *string);
INTDEF NONNULL((1)) __STDC_INT_AS_SIZE_T NOTHROW_NCX(LIBDCALL libd__putws)(char16_t const *string);
INTDEF WUNUSED char32_t *NOTHROW_NCX(LIBCCALL libc__wtempnam)(char32_t const *directory, char32_t const *file_prefix);
INTDEF WUNUSED char16_t *NOTHROW_NCX(LIBDCALL libd__wtempnam)(char16_t const *directory, char16_t const *file_prefix);
INTDEF void NOTHROW_NCX(LIBCCALL libc__wperror)(char32_t const *errmsg);
INTDEF void NOTHROW_NCX(LIBDCALL libd__wperror)(char16_t const *errmsg);
INTDEF NONNULL((1)) errno_t NOTHROW_NCX(LIBCCALL libc__wtmpnam_s)(char32_t *dst, size_t wchar_count);
INTDEF NONNULL((1)) errno_t NOTHROW_NCX(LIBDCALL libd__wtmpnam_s)(char16_t *dst, size_t wchar_count);

DECL_END

#endif /* !GUARD_LIBC_USER_WCHAR_H */
