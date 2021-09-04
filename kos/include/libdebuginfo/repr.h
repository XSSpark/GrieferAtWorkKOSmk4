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
#ifndef _LIBDEBUGINFO_DEBUG_REPR_H
#define _LIBDEBUGINFO_DEBUG_REPR_H 1

#include "api.h"
/**/

#include <bits/crt/format-printer.h>
#include <bits/types.h>

#include <libunwind/dwarf.h>

#ifdef __CC__
__DECL_BEGIN

#ifndef __KERNEL__
/* Return the name of a given constant, or NULL if the constant isn't recognized.
 *  - debug_repr_DW_TAG():   Returns the `*' portion for one of `DW_TAG_*' (iow. excluding the `DW_TAG_' prefix)
 *  - debug_repr_DW_AT():    Returns the `*' portion for one of `DW_AT_*' (iow. excluding the `DW_AT_' prefix)
 *  - debug_repr_DW_FORM():  Returns the `*' portion for one of `DW_FORM_*' (iow. excluding the `DW_FORM_' prefix)
 *  - debug_repr_DW_ATE():   Returns the `*' portion for one of `DW_ATE_*' (iow. excluding the `DW_ATE_' prefix)
 *  - debug_repr_DW_OP():    Returns the `*' portion for one of `DW_OP_*' (iow. excluding the `DW_OP_' prefix)
 *  - debug_repr_DW_CFA():   Returns the `*' portion for one of `DW_CFA_*' (iow. excluding the `DW_CFA_' prefix)
 *  - debug_repr_DW_EH_PE(): Returns the `*' portion for one of `DW_EH_PE_*' (iow. excluding the `DW_EH_PE_' prefix)
 */
typedef __ATTR_CONST __ATTR_WUNUSED char const *(LIBDEBUGINFO_CC *PDEBUG_REPR_DW_TAG)(dwarf_uleb128_t value);
typedef __ATTR_CONST __ATTR_WUNUSED char const *(LIBDEBUGINFO_CC *PDEBUG_REPR_DW_AT)(dwarf_uleb128_t value);
typedef __ATTR_CONST __ATTR_WUNUSED char const *(LIBDEBUGINFO_CC *PDEBUG_REPR_DW_FORM)(dwarf_uleb128_t value);
typedef __ATTR_CONST __ATTR_WUNUSED char const *(LIBDEBUGINFO_CC *PDEBUG_REPR_DW_ATE)(dwarf_uleb128_t value);
typedef __ATTR_CONST __ATTR_WUNUSED char const *(LIBDEBUGINFO_CC *PDEBUG_REPR_DW_OP)(__uint8_t value);
typedef __ATTR_CONST __ATTR_WUNUSED char const *(LIBDEBUGINFO_CC *PDEBUG_REPR_DW_CFA)(__uint8_t value);
typedef __ATTR_CONST __ATTR_WUNUSED char const *(LIBDEBUGINFO_CC *PDEBUG_REPR_DW_EH_PE)(__uint8_t value);
#ifdef LIBDEBUGINFO_WANT_PROTOTYPES
LIBDEBUGINFO_DECL __ATTR_CONST __ATTR_WUNUSED char const *__NOTHROW(LIBDEBUGINFO_CC debug_repr_DW_TAG)(dwarf_uleb128_t value);
LIBDEBUGINFO_DECL __ATTR_CONST __ATTR_WUNUSED char const *__NOTHROW(LIBDEBUGINFO_CC debug_repr_DW_AT)(dwarf_uleb128_t value);
LIBDEBUGINFO_DECL __ATTR_CONST __ATTR_WUNUSED char const *__NOTHROW(LIBDEBUGINFO_CC debug_repr_DW_FORM)(dwarf_uleb128_t value);
LIBDEBUGINFO_DECL __ATTR_CONST __ATTR_WUNUSED char const *__NOTHROW(LIBDEBUGINFO_CC debug_repr_DW_ATE)(dwarf_uleb128_t value);
LIBDEBUGINFO_DECL __ATTR_CONST __ATTR_WUNUSED char const *__NOTHROW(LIBDEBUGINFO_CC debug_repr_DW_OP)(__uint8_t value);
LIBDEBUGINFO_DECL __ATTR_CONST __ATTR_WUNUSED char const *__NOTHROW(LIBDEBUGINFO_CC debug_repr_DW_CFA)(__uint8_t value);
LIBDEBUGINFO_DECL __ATTR_CONST __ATTR_WUNUSED char const *__NOTHROW(LIBDEBUGINFO_CC debug_repr_DW_EH_PE)(__uint8_t value);
#endif /* LIBDEBUGINFO_WANT_PROTOTYPES */

/* Dump the given debug information in a human-readable format to `printer':
 * >> void *dump_module = dlgetmodule("libc");
 * >> size_t debug_info_size, debug_abbrev_size, debug_str_size, debug_loc_size;
 * >> byte_t const *debug_info_data, *debug_abbrev_data, *debug_str_data, *debug_loc_data;
 * >> PDEBUG_REPR_DUMP debug_repr_dump;
 * >> *(void **)&debug_repr_dump = dlsym(dlopen(LIBDEBUGINFO_LIBRARY_NAME, RTLD_LOCAL), "debug_repr_dump");
 * >> debug_info_data   = (byte_t const *)dlinflatesection(dllocksection(dump_module, ".debug_info"), &debug_info_size);
 * >> debug_abbrev_data = (byte_t const *)dlinflatesection(dllocksection(dump_module, ".debug_abbrev"), &debug_abbrev_size);
 * >> debug_str_data    = (byte_t const *)dlinflatesection(dllocksection(dump_module, ".debug_str"), &debug_str_size);
 * >> debug_loc_data    = (byte_t const *)dlinflatesection(dllocksection(dump_module, ".debug_loc"), &debug_loc_size);
 * >> debug_repr_dump(&file_printer, stdout,
 * >>                 debug_info_data, debug_info_data + debug_info_size,
 * >>                 debug_abbrev_data, debug_abbrev_data + debug_abbrev_size,
 * >>                 debug_loc_data, debug_loc_data + debug_loc_size,
 * >>                 debug_str_data, debug_str_data + debug_str_size); */
typedef __ATTR_NONNULL((1)) __ssize_t
(LIBDEBUGINFO_CC *PDEBUG_REPR_DUMP)(__pformatprinter printer, void *arg,
                                    __byte_t const *debug_info_start, __byte_t const *debug_info_end,
                                    __byte_t const *debug_abbrev_start, __byte_t const *debug_abbrev_end,
                                    __byte_t const *debug_loc_start, __byte_t const *debug_loc_end,
                                    __byte_t const *debug_str_start, __byte_t const *debug_str_end);
#ifdef LIBDEBUGINFO_WANT_PROTOTYPES
LIBDEBUGINFO_DECL __ATTR_NONNULL((1)) __ssize_t
(LIBDEBUGINFO_CC debug_repr_dump)(__pformatprinter printer, void *arg,
                                  __byte_t const *debug_info_start, __byte_t const *debug_info_end,
                                  __byte_t const *debug_abbrev_start, __byte_t const *debug_abbrev_end,
                                  __byte_t const *debug_loc_start, __byte_t const *debug_loc_end,
                                  __byte_t const *debug_str_start, __byte_t const *debug_str_end);
#endif /* LIBDEBUGINFO_WANT_PROTOTYPES */

#endif /* __KERNEL__ */


__DECL_END
#endif /* __CC__ */

#endif /* !_LIBDEBUGINFO_DEBUG_REPR_H */
