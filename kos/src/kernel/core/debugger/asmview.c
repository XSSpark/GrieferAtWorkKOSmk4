/*[[[magic
local gcc_opt = options.setdefault("GCC.options", []);
if (gcc_opt.remove("-O3"))
	gcc_opt.append("-Os");
]]]*/
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
#ifndef GUARD_KERNEL_SRC_DEBUGGER_ASMVIEW_C
#define GUARD_KERNEL_SRC_DEBUGGER_ASMVIEW_C 1
#define DISABLE_BRANCH_PROFILING 1

#include <kernel/compiler.h>

#include <kernel/debugger.h>
#ifndef CONFIG_NO_DEBUGGER

#undef CONFIG_ASMVIEW_INSTRLEN_USE_DISASM_PRINTER

/* Use the disassembly printer to determine the length
 * of instructions, rather than making use of libdisasm.
 * In theory, this shouldn't really make a difference, but
 * in practice, there can easily occur cases where the length
 * of an instruction determined by libdisasm will differ from
 * the length determined for the same instruction by libinstrlen.
 * So to prevent inconsistencies during disassembly printing, we
 * instead always make use of the disassembly printer to provide
 * us with information about the length of an instruction. */
#define CONFIG_ASMVIEW_INSTRLEN_USE_DISASM_PRINTER 1


#include <kos/keyboard.h>
#include <kernel/paging.h>
#include <kernel/vm.h>
#include <kernel/except.h>
#include <kernel/driver.h>
#include <stddef.h>
#include <alloca.h>
#include <string.h>
#include <libdisasm/disassembler.h>
#include <libdisasm/format.h>
#include <libdebuginfo/addr2line.h>
#include <libdebuginfo/debug_info.h>

#ifndef CONFIG_ASMVIEW_INSTRLEN_USE_DISASM_PRINTER
#include <libinstrlen/instrlen.h>
#endif /* !CONFIG_ASMVIEW_INSTRLEN_USE_DISASM_PRINTER */

DECL_BEGIN


#ifdef CONFIG_ASMVIEW_INSTRLEN_USE_DISASM_PRINTER

/* # of instructions to unwind for the purpose of
 * verifying the program counter when walking backwards. */
#define AV_VERIFY_DISTANCE 8

PRIVATE NOBLOCK ssize_t
NOTHROW(KCALL stub_printer)(void *UNUSED(arg),
                            /*utf-8*/ char const *__restrict UNUSED(data),
                            size_t UNUSED(datalen)) {
	return 0;
}

PRIVATE NOBLOCK ssize_t
NOTHROW(LIBDISASM_CC stub_symbol_printer)(struct disassembler *__restrict UNUSED(self),
                                          void *UNUSED(symbol_addr)) {
	return 0;
}

PRIVATE ATTR_DBGDATA struct disassembler av_instrlen_da = {
	.d_pc         = NULL,            /* Fill in as-needed */
	.d_baseoff    = 0,
	.d_printer    = &stub_printer,
	.d_arg        = NULL,
	.d_result     = 0,
	.d_symbol     = &stub_symbol_printer,
	.d_format     = NULL,
	.d_target     = DISASSEMBLER_TARGET_CURRENT,
	.d_flags      = DISASSEMBLER_FNOADDR | DISASSEMBLER_FNOBYTES,
	.d_maxbytes   = 0,
};

PRIVATE ATTR_DBGTEXT void *
NOTHROW(FCALL av_core_instr_trysucc)(void *addr) {
	av_instrlen_da.d_pc = (byte_t *)addr;
	TRY {
		disasm_print_instruction(&av_instrlen_da);
	} EXCEPT {
		return (byte_t *)addr + 1;
	}
	return av_instrlen_da.d_pc;
}

PRIVATE ATTR_DBGTEXT void *
NOTHROW(FCALL av_core_instr_trypred)(void *addr) {
	byte_t *result;
	unsigned int i = 15; /* 15 is the max instruction length on X86 */
	do {
		result = (byte_t *)addr - i;
		if (av_core_instr_trysucc(result) == addr)
			goto done;
	} while (--i);
done:
	return result;
}

PRIVATE ATTR_DBGTEXT void *
NOTHROW(FCALL av_core_instr_trypred_n)(void *addr, unsigned int n) {
	while (n--) {
		addr = av_core_instr_trypred(addr);
	}
	return addr;
}



#define av_instr_succ(addr) av_core_instr_trysucc(addr)

PRIVATE ATTR_DBGTEXT void *
NOTHROW(FCALL av_instr_pred)(void *addr) {
	void *baseline, *result;
	baseline = av_core_instr_trypred_n(addr, AV_VERIFY_DISTANCE);
	for (;;) {
		result = baseline;
		baseline = av_instr_succ(baseline);
		if (baseline >= addr)
			break;
	}
	return result;
}

PRIVATE ATTR_DBGTEXT void *
NOTHROW(FCALL av_instr_pred_n)(void *addr, unsigned int n) {
	if (n > 1)
		addr = av_core_instr_trypred_n(addr, n - 1);
	if (n > 0)
		addr = av_instr_pred(addr);
	return addr;
}

#else

#define av_instr_succ(addr) ((void *)instruction_trysucc(addr))
#define av_instr_pred(addr) ((void *)instruction_trypred(addr))

PRIVATE ATTR_DBGTEXT void *
NOTHROW(FCALL av_instr_pred_n)(void *addr, unsigned int n) {
	while (n--) {
		addr = (void *)instruction_trypred(addr);
	}
	return addr;
}

#endif



PRIVATE NONNULL((1)) ssize_t LIBDISASM_CC
av_format(struct disassembler *__restrict UNUSED(self), unsigned int format_option) {
	switch (format_option) {

	case DISASSEMBLER_FORMAT_REGISTER_PREFIX:
		dbg_setfgcolor(DBG_COLOR_TEAL);
		break;

	case DISASSEMBLER_FORMAT_IMMEDIATE_PREFIX:
	case DISASSEMBLER_FORMAT_OFFSET_PREFIX:
	case DISASSEMBLER_FORMAT_SCALE_PREFIX:
		dbg_setfgcolor(DBG_COLOR_RED);
		break;

	case DISASSEMBLER_FORMAT_SYMBOL_PREFIX:
		dbg_setfgcolor(DBG_COLOR_WHITE);
		break;

	case DISASSEMBLER_FORMAT_PSEUDOOP_PREFIX:
		dbg_setfgcolor(DBG_COLOR_DARK_GRAY);
		break;

	case DISASSEMBLER_FORMAT_MNEMONIC_PREFIX:
		dbg_setfgcolor(DBG_COLOR_PURPLE);
		break;

	default:
		dbg_attr = dbg_default_attr;
		break;
	}
	return 0;
}

PRIVATE ATTR_DBGTEXT bool
NOTHROW(FCALL av_getbyte)(void *addr, byte_t *pvalue) {
	TRY {
		*pvalue = *(byte_t *)addr;
		return true;
	} EXCEPT {
	}
	{
		vm_vpage_t page;
		page = VM_ADDR2PAGE((vm_virt_t)addr);
		/* Try to force write-access to the associated page by directly
		 * accessing the underlying physical memory (if there is any). */
		if (pagedir_ismapped(page)) {
			vm_phys_t phys;
			phys = pagedir_translate((vm_virt_t)addr);
			vm_copyfromphys(pvalue, phys, 1);
			return true;
		}
	}
	return false;
}


struct av_symbol {
	char const *s_name;  /* [1..1] Symbol name (set to (char const *)-1 if unknown). (Set to NULL if entry is used) */
	uintptr_t   s_start; /* Symbol start address. */
	size_t      s_end;   /* Symbol end address. */
};

struct av_sections_lock {
	REF struct driver     *sl_driver; /* [1..1] The associated driver. (Set to NULL if entry is used) */
	di_dl_debug_sections_t sl_dlsect; /* DL sections data */
	di_debug_sections_t    sl_dbsect; /* Debug sections data */
};

PRIVATE struct av_symbol av_symbol_cache[128];
PRIVATE struct av_sections_lock av_sections_cache[8];

DEFINE_DBG_FINI(finalize_av_symbol_cache);
INTERN ATTR_DBGTEXT void NOTHROW(KCALL finalize_av_symbol_cache)(void) {
	unsigned int i;
	for (i = 0; i < COMPILER_LENOF(av_sections_cache); ++i) {
		if (!av_sections_cache[i].sl_driver)
			continue;
		debug_dlunlocksections(&av_sections_cache[i].sl_dlsect);
		decref_unlikely(av_sections_cache[i].sl_driver);
	}
	memset(av_symbol_cache, 0, sizeof(av_symbol_cache));
	memset(av_sections_cache, 0, sizeof(av_sections_cache));
}

PRIVATE ATTR_DBGTEXT bool
NOTHROW(FCALL av_do_lock_sections)(struct av_sections_lock *__restrict info,
                                   uintptr_t symbol_addr) {
	REF struct driver *symbol_module;
	symbol_module = driver_at_address((void *)symbol_addr);
	if (!symbol_module)
		return false;
	if (debug_dllocksections(symbol_module,
	                         &info->sl_dbsect,
	                         &info->sl_dlsect) != DEBUG_INFO_ERROR_SUCCESS)
		return false;
	info->sl_driver = symbol_module;
	return true;
}

PRIVATE ATTR_DBGTEXT struct av_sections_lock *
NOTHROW(FCALL av_lock_sections)(uintptr_t symbol_addr) {
	unsigned int i;
	struct av_sections_lock *resent = NULL;
	for (i = 0; i < COMPILER_LENOF(av_sections_cache); ++i) {
		if (!av_sections_cache[i].sl_driver) {
			if (!resent)
				resent = &av_sections_cache[i];
			continue;
		}
		if (symbol_addr < av_sections_cache[i].sl_driver->d_loadstart)
			continue;
		if (symbol_addr >= av_sections_cache[i].sl_driver->d_loadend)
			continue;
		return &av_sections_cache[i];
	}
	if (!resent) {
		if (av_sections_cache[0].sl_driver) {
			debug_dlunlocksections(&av_sections_cache[0].sl_dlsect);
			decref_unlikely(av_sections_cache[0].sl_driver);
			memmove(&av_sections_cache[0], &av_sections_cache[1],
			        sizeof(av_sections_cache) - sizeof(av_sections_cache[0]));
		}
		resent = COMPILER_ENDOF(av_sections_cache) - 1;
	}
	resent->sl_driver = NULL;
	if (!av_do_lock_sections(resent, symbol_addr))
		return NULL;
	return resent;
}


PRIVATE ATTR_DBGTEXT bool
NOTHROW(FCALL av_do_lookup_symbol)(struct av_symbol *__restrict info,
                                   uintptr_t symbol_addr) {
	di_debug_addr2line_t a2l_info;
	struct av_sections_lock *sections;
	sections = av_lock_sections(symbol_addr);
	if (!sections)
		return false;
	if (debug_sections_addr2line(&sections->sl_dbsect, &a2l_info,
	                             (uintptr_t)symbol_addr - (uintptr_t)sections->sl_driver->d_loadaddr,
	                             DEBUG_ADDR2LINE_LEVEL_SOURCE,
	                             DEBUG_ADDR2LINE_FNORMAL) != DEBUG_INFO_ERROR_SUCCESS)
		return false;
	if (!a2l_info.al_rawname)
		a2l_info.al_rawname = a2l_info.al_name;
	if (!a2l_info.al_rawname)
		a2l_info.al_rawname = (char *)-1;
	info->s_name  = a2l_info.al_rawname;
	info->s_start = a2l_info.al_symstart;
	info->s_end   = a2l_info.al_symend;
	return true;
}

PRIVATE ATTR_DBGTEXT struct av_symbol *
NOTHROW(FCALL av_lookup_symbol)(uintptr_t symbol_addr) {
	unsigned int i;
	struct av_symbol *resent = NULL;
	for (i = 0; i < COMPILER_LENOF(av_symbol_cache); ++i) {
		if (!av_symbol_cache[i].s_name) {
			if (!resent)
				resent = &av_symbol_cache[i];
			continue;
		}
		if (symbol_addr < av_symbol_cache[i].s_start)
			continue;
		if (symbol_addr >= av_symbol_cache[i].s_end)
			continue;
		if (av_symbol_cache[i].s_name == (char *)-2)
			return NULL;
		return &av_symbol_cache[i];
	}
	if (!resent) {
		if (av_symbol_cache[0].s_name) {
			memmove(&av_symbol_cache[0], &av_symbol_cache[1],
			        sizeof(av_symbol_cache) - sizeof(av_symbol_cache[0]));
		}
		resent = COMPILER_ENDOF(av_symbol_cache) - 1;
	}
	resent->s_name = NULL;
	if (!av_do_lookup_symbol(resent, symbol_addr)) {
		/* Cache the fact that the given address is unknown. */
		resent->s_name  = (char *)-2;
		resent->s_start = symbol_addr;
		resent->s_end   = symbol_addr + 1;
		return NULL;
	}
	return resent;
}


PRIVATE ATTR_DBGTEXT NONNULL((1)) ssize_t
NOTHROW(LIBDISASM_CC av_symbol_printer)(struct disassembler *__restrict self,
                                        void *symbol_addr) {
	struct av_symbol *sym;
	sym = av_lookup_symbol((uintptr_t)symbol_addr);
	if (sym) {
		uintptr_t symbol_offset;
		dbg_putc('<');
		if (sym->s_name != (char *)-1) {
			dbg_print(sym->s_name);
		} else {
			/* If we can't determine the symbol's name, generate one using its address. */
			dbg_printf(DBGSTR("sym_%p"), sym->s_start);
		}
		/* Include the symbol offset (if non-zero) */
		symbol_offset = (uintptr_t)symbol_addr - sym->s_start;
		if (symbol_offset != 0)
			disasm_printf(self, "+%#Ix", symbol_offset);
		disasm_print(self, ">", 1);
	} else {
		disasm_printf(self, "0x%p", symbol_addr);
	}
	return 0;
}


PRIVATE ATTR_DBGTEXT void *
NOTHROW(FCALL av_printscreen)(void *start_addr, void **psel_addr) {
	struct disassembler da;
	unsigned int line;
	byte_t *current_line_base = NULL;
	size_t current_line_size = 0;
	void *sel_addr = *psel_addr;
	size_t maxbytes;
	maxbytes = disasm_default_maxbytes(DISASSEMBLER_TARGET_CURRENT);
	disasm_init(&da, &dbg_printer, NULL, start_addr,
	            DISASSEMBLER_TARGET_CURRENT,
	            DISASSEMBLER_FNOADDR | DISASSEMBLER_FNOBYTES, 0);
	da.d_format = &av_format;
	da.d_symbol = &av_symbol_printer;
	dbg_setcur_visible(DBG_SETCUR_VISIBLE_HIDE);
	for (line = 0; line < dbg_screen_height - 1; ++line) {
		void *line_endaddr;
		size_t i, ilen;
		bool is_current_line;
		dbg_attr_t old_default_attr;
		byte_t *line_start = da.d_pc;
		line_endaddr = av_instr_succ(line_start);
		ilen = (size_t)((byte_t *)line_endaddr - line_start);
		is_current_line = sel_addr >= line_start && sel_addr < line_endaddr;
		if (is_current_line) /* Fix a potential address drift. */
			*psel_addr = sel_addr = line_start;
		old_default_attr = dbg_default_attr;
		dbg_attr = old_default_attr;
		if (is_current_line) {
			current_line_base = line_start;
			current_line_size = ilen;
			dbg_setcolor(DBG_COLOR_BLACK, DBG_COLOR_LIGHT_GRAY);
		} else {
			dbg_setbgcolor(DBG_COLOR_BLACK);
		}
		dbg_default_attr = dbg_attr;
		dbg_setcur(0, line);
		dbg_printf(DBGSTR("%p "), line_start);
		if (ilen > maxbytes) {
			for (i = 0; i < maxbytes - 1; ++i) {
				byte_t value;
				if (av_getbyte(da.d_pc + i, &value))
					dbg_printf(DBGSTR("%.2I8x "), value);
				else {
					dbg_print(DBGSTR("?? "));
				}
			}
			dbg_print(DBGSTR(".. "));
		} else {
			for (i = 0; i < ilen; ++i) {
				byte_t value;
				if (av_getbyte(da.d_pc + i, &value))
					dbg_printf(DBGSTR("%.2I8x "), value);
				else {
					dbg_print(DBGSTR("?? "));
				}
			}
			for (; i < maxbytes; ++i)
				dbg_print(DBGSTR("   "));
		}
		TRY {
			disasm_print_instruction(&da);
		} EXCEPT {
			dbg_print(DBGSTR("??"));
			da.d_pc = (byte_t *)line_endaddr;
		}
		dbg_default_attr = old_default_attr;
		dbg_attr = old_default_attr;
		{
			unsigned int x;
			for (x = dbg_getcur_x(); x < dbg_screen_width; ++x)
				dbg_putuni(' ');
		}
	}
	dbg_setcolor(DBG_COLOR_BLACK, DBG_COLOR_LIGHT_GRAY);
	dbg_hline(0, dbg_screen_height - 1, dbg_screen_width, ' ');
	dbg_pprint(dbg_screen_width - 7, dbg_screen_height - 1, DBGSTR("F1:help"));
	if (current_line_size) {
		size_t i;
		dbg_setcur(0, dbg_screen_height - 1);
		dbg_printf(DBGSTR("%p:"), current_line_base);
		for (i = 0; i < current_line_size; ++i) {
			byte_t value;
			if (i != 0)
				dbg_putc(' ');
			if (av_getbyte(current_line_base + i, &value))
				dbg_printf(DBGSTR("%.2I8x"), value);
			else {
				dbg_print(DBGSTR("??"));
			}
		}
	}
	return da.d_pc;
}


/* Re-use the address dialog from hexedit. */
INTDEF ATTR_DBGTEXT bool
NOTHROW(FCALL dbg_hd_addrdiag)(uintptr_t *paddr);



PRIVATE ATTR_DBGRODATA char const av_help[] =
"Esc:        Exit        F1:           Help\n"
"Arrow Keys: Navigate    Pg-Up/Down:   Navigate\n"
"Ctrl+Pg-Up: Go to top   Ctrl+Pg-Down: Go to bottom\n"
"Esc/F1:     Close Help  F2:           Go to address\n"
"E:          Open Hexedit"
;

PRIVATE ATTR_DBGTEXT void *
NOTHROW(FCALL av_main)(void *addr) {
	void *start_addr, *end_addr = (void *)-1;
	start_addr = av_instr_pred_n(addr, (dbg_screen_height - 1) / 2);
	for (;;) {
		unsigned int key;
		if (start_addr > addr)
			start_addr = addr;
		end_addr = av_printscreen(start_addr, &addr);
		if (addr >= end_addr) {
			unsigned int n = dbg_screen_height;
			while (n) {
				/* Slowly move the screen upwards until the start-address is displayed on-screen. */
				start_addr = av_instr_pred_n(addr, n);
				end_addr   = av_printscreen(start_addr, &addr);
				if (addr < end_addr)
					break;
				--n;
			}
		}
		do {
			key = dbg_getkey();
		} while (key & KEY_FRELEASED);
		switch (key) {

		case KEY_E:
			/* Edit the current address in the hex editor.
			 * NOTE: Disable read-only by default, since the user may
			 *       with to keep switching back and forth to look at
			 *       the generated assembly (in case they choose to use
			 *       this mechanism to re-write assembly code) */
			addr = dbg_hexedit(addr, false);
			break;

		case KEY_ESC:
			goto done;

		case KEY_UP:
			if (dbg_isholding_ctrl()) {
				start_addr = av_instr_pred(start_addr);
			} else {
				addr = av_instr_pred(addr);
				if (addr < start_addr)
					start_addr = addr;
			}
			continue;

		case KEY_DOWN:
			if (dbg_isholding_ctrl()) {
				start_addr = av_instr_succ(start_addr);
			} else {
				addr = av_instr_succ(addr);
				if (addr >= end_addr)
					start_addr = av_instr_succ(start_addr);
			}
			continue;

		case KEY_PAGEUP:
			if (dbg_isholding_ctrl()) {
				addr = start_addr;
			} else {
				unsigned int n, start_addr_offset;
				n = dbg_screen_height - 1;
				start_addr_offset = 0;
				while (n) {
					if (addr > start_addr)
						++start_addr_offset;
					addr = av_instr_pred(addr);
					--n;
				}
				start_addr = addr;
				while (start_addr_offset--)
					start_addr = av_instr_pred(start_addr);
			}
			continue;

		case KEY_PAGEDOWN:
			if (dbg_isholding_ctrl()) {
				addr = av_instr_pred(end_addr);
			} else {
				unsigned int n;
				n = dbg_screen_height - 1;
				while (n--) {
					start_addr = av_instr_succ(start_addr);
					addr       = av_instr_succ(addr);
				}
			}
			break;

		case KEY_F1:
			dbg_setcolor(DBG_COLOR_BLACK, DBG_COLOR_LIGHT_GRAY);
			dbg_messagebox(DBGSTR("Help"), av_help);
			/* Wait until the user presses ESC or F1 */
			do {
				key = dbg_getkey();
			} while (key != KEY_F1 && key != KEY_ESC);
			continue;

		case KEY_F2: {
			uintptr_t newaddr;
			if (dbg_hd_addrdiag(&newaddr))
				addr = (void *)newaddr;
		}	continue;

		default:
			break;
		}
	}
done:
	return addr;
}





/* Open an interactive assembly viewer at `addr'
 * @return: * : The final selected address when the viewer was closed. */
PUBLIC void *NOTHROW(FCALL dbg_asmview)(void *addr) {
	bool was_cursor_visible;
	void *buf, *result;
	u32 oldcur;
	dbg_attr_t oldattr;
	/* Save terminal settings and display contents. */
	was_cursor_visible = dbg_setcur_visible(DBG_SETCUR_VISIBLE_TEST);
	buf = alloca(dbg_screen_width * dbg_screen_height * dbg_screen_cellsize);
	oldcur = dbg_getcur();
	oldattr = dbg_attr;
	dbg_getscreendata(0, 0, dbg_screen_width, dbg_screen_height, buf);

	result = av_main(addr);

	/* Restore display contents and terminal settings. */
	dbg_setscreendata(0, 0, dbg_screen_width, dbg_screen_height, buf);
	dbg_attr = oldattr;
	dbg_setcur(DBG_GETCUR_X(oldcur), DBG_GETCUR_Y(oldcur));
	if (was_cursor_visible)
		dbg_setcur_visible(DBG_SETCUR_VISIBLE_SHOW);
	return result;
}


DEFINE_DEBUG_FUNCTION(
		"a",
		"a [ADDR=pc]\n"
		"\tOpen an interactive assembly view at ADDR\n",
		argc, argv) {
	void *addr = (void *)FCPUSTATE_PC(dbg_viewstate);
	if (argc >= 2) {
		if (!dbg_evaladdr(argv[1], (uintptr_t *)&addr))
			return DBG_FUNCTION_INVALID_ARGUMENTS;
	}
	dbg_asmview(addr);
	return 0;
}


DECL_END
#endif /* !CONFIG_NO_DEBUGGER */

#endif /* !GUARD_KERNEL_SRC_DEBUGGER_ASMVIEW_C */
