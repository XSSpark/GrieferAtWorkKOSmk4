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
#ifndef GUARD_LIBC_USER_FORMAT_PRINTER_C
#define GUARD_LIBC_USER_FORMAT_PRINTER_C 1

#include "../api.h"
#include "format-printer.h"
#include "malloc.h"
#include <string.h>

DECL_BEGIN





/*[[[start:implementation]]]*/

/*[[[head:format_aprintf_pack,hash:0x3f711b2d]]]*/
/* Pack and finalize a given aprintf format printer
 * Together with `format_aprintf_printer()', the aprintf
 * format printer sub-system should be used as follows:
 * >> char *result; ssize_t error;
 * >> struct format_aprintf_data p = FORMAT_APRINTF_DATA_INIT;
 * >> error = format_printf(&format_aprintf_printer, &p, "%s %s", "Hello", "World");
 * >> if unlikely(error < 0) {
 * >>     format_aprintf_data_fini(&p);
 * >>     return NULL;
 * >> }
 * >> result = format_aprintf_pack(&p, NULL);
 * >> return result;
 * WARNING: Note that `format_aprintf_pack()' is able to return `NULL' as well,
 *          but will finalize the given aprintf printer an all cases.
 * NOTE:    The caller must destroy the returned string by passing it to `free()'
 * @param: pstrlen: When non-NULL, store the length of the constructed string here
 *                  Note that this is the actual length if the constructed string,
 *                  but may differ from `strlen(return)' when NUL characters were
 *                  printed to the aprintf-printer at one point.
 *                  (e.g. `format_aprintf_printer(&my_printer, "\0", 1)') */
INTERN WUNUSED ATTR_MALL_DEFAULT_ALIGNED ATTR_MALLOC NONNULL((1))
ATTR_WEAK ATTR_SECTION(".text.crt.string.format.format_aprintf_pack") char *
NOTHROW_NCX(LIBCCALL libc_format_aprintf_pack)(struct format_aprintf_data *__restrict self,
                                               size_t *pstrlen)
/*[[[body:format_aprintf_pack]]]*/
/*AUTO*/{
	/* Free unused buffer memory. */
	char *result;
	if (self->ap_avail != 0) {
		char *newbuf;
		newbuf = (char *)libc_realloc(self->ap_base,
		                         (self->ap_used + 1) * sizeof(char));
		if likely(newbuf)
			self->ap_base = newbuf;
	} else {
		if unlikely(!self->ap_used) {
			/* Special case: Nothing was printed. */
			__hybrid_assert(!self->ap_base);
#ifdef __CRT_HAVE_malloc
			self->ap_base = (char *)libc_malloc(1 * sizeof(char));
#else /* __CRT_HAVE_malloc */
			self->ap_base = (char *)libc_realloc(NULL, 1 * sizeof(char));
#endif /* !__CRT_HAVE_malloc */
			if unlikely(!self->ap_base)
				return NULL;
		}
	}
	result = self->ap_base;
	__hybrid_assert(result);
	result[self->ap_used] = '\0'; /* NUL-terminate */
	if (pstrlen)
		*pstrlen = self->ap_used;
#ifndef NDEBUG
#if __SIZEOF_POINTER__ == 4
	self->ap_base  = (char *)__UINT32_C(0xcccccccc);
	self->ap_avail = __UINT32_C(0xcccccccc);
	self->ap_used  = __UINT32_C(0xcccccccc);
#elif __SIZEOF_POINTER__ == 8
	self->ap_base  = (char *)__UINT64_C(0xcccccccccccccccc);
	self->ap_avail = __UINT64_C(0xcccccccccccccccc);
	self->ap_used  = __UINT64_C(0xcccccccccccccccc);
#endif /* __SIZEOF_POINTER__ == ... */
#endif /* !NDEBUG */
	return result;
}
/*[[[end:format_aprintf_pack]]]*/

/*[[[head:format_aprintf_printer,hash:0xdc590d6a]]]*/
/* Print data to a dynamically allocated heap buffer. On error, -1 is returned */
INTERN WUNUSED NONNULL((1, 2))
ATTR_WEAK ATTR_SECTION(".text.crt.string.format.format_aprintf_printer") ssize_t
NOTHROW_NCX(LIBCCALL libc_format_aprintf_printer)(/*struct format_aprintf_data **/void *arg,
                                                  /*utf-8*/char const *__restrict data,
                                                  size_t datalen)
/*[[[body:format_aprintf_printer]]]*/
/*AUTO*/{
	struct __format_aprintf_data {
		char         *ap_base;  /* [0..ap_used|ALLOC(ap_used+ap_avail)][owend] Buffer */
		__SIZE_TYPE__ ap_avail; /* Unused buffer size */
		__SIZE_TYPE__ ap_used;  /* Used buffer size */
	};
	struct __format_aprintf_data *buf;
	buf = (struct __format_aprintf_data *)arg;
	if (buf->ap_avail < datalen) {
		char *newbuf;
		size_t min_alloc = buf->ap_used + datalen;
		size_t new_alloc = buf->ap_used + buf->ap_avail;
		if (!new_alloc)
			new_alloc = 8;
		while (new_alloc < min_alloc)
			new_alloc *= 2;
		newbuf = (char *)libc_realloc(buf->ap_base, (new_alloc + 1) * sizeof(char));
		if unlikely(!newbuf) {
			new_alloc = min_alloc;
			newbuf    = (char *)libc_realloc(buf->ap_base, (new_alloc + 1) * sizeof(char));
			if unlikely(!newbuf)
				return -1;
		}
		__hybrid_assert(new_alloc >= buf->ap_used + datalen);
		buf->ap_base  = newbuf;
		buf->ap_avail = new_alloc - buf->ap_used;
	}
	memcpy(buf->ap_base + buf->ap_used, data, datalen * sizeof(char));
	buf->ap_avail -= datalen;
	buf->ap_used  += datalen;
	return (ssize_t)datalen;
}
/*[[[end:format_aprintf_printer]]]*/

/*[[[end:implementation]]]*/



/*[[[start:exports,hash:0x1409b12c]]]*/
DEFINE_PUBLIC_WEAK_ALIAS(format_aprintf_pack, libc_format_aprintf_pack);
DEFINE_PUBLIC_WEAK_ALIAS(format_aprintf_printer, libc_format_aprintf_printer);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_FORMAT_PRINTER_C */
