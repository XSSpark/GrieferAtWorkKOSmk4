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
#ifndef GUARD_KERNEL_CORE_ARCH_I386_DEBUGGER_INPUT_C
#define GUARD_KERNEL_CORE_ARCH_I386_DEBUGGER_INPUT_C 1
#define _KOS_SOURCE 1
#define DISABLE_BRANCH_PROFILING 1

#include <kernel/compiler.h>

#include <kernel/debugger.h>

#ifndef CONFIG_NO_DEBUGGER
#include <kernel/panic.h>
#include <kernel/pic.h>
#include <kernel/printk.h>

#include <asm/intrin.h>
#include <kos/io/ps2.h>
#include <kos/keyboard.h>
#include <sys/io.h>

#include <ctype.h>
#include <string.h>
#include <unicode.h>

#include "ps2-keymaps.h"

DECL_BEGIN

LOCAL ATTR_DBGTEXT bool NOTHROW(KCALL ps2_write_cmd)(u8 cmd) {
	/* TODO: Add a timeout using PIT */
	while (inb_p(PS2_STATUS) & PS2_STATUS_INFULL)
		__pause();
	outb_p(PS2_CMD, cmd);
	/*while (inb_p(PS2_STATUS) & PS2_STATUS_INFULL);*/
	return true;
}

LOCAL ATTR_DBGTEXT int NOTHROW(KCALL ps2_read_cmddata)(void) {
	/* TODO: Add a timeout using PIT */
	while (!(inb_p(PS2_STATUS) & PS2_STATUS_OUTFULL))
		__pause();
	return inb_p(PS2_DATA);
}

LOCAL ATTR_DBGTEXT bool NOTHROW(KCALL ps2_write_cmddata)(u8 data) {
	/* TODO: Add a timeout using PIT */
	while (inb_p(PS2_STATUS) & PS2_STATUS_INFULL)
		__pause();
	outb_p(PS2_DATA, data);
	return true;
}

LOCAL ATTR_DBGTEXT bool KCALL ps2_write_data(u8 data) {
#if 0
	if (port == PS2_PORT2) {
		while (inb_p(PS2_STATUS) & PS2_STATUS_INFULL)
			__pause();
		outb_p(PS2_CMD, PS2_CONTROLLER_WRITE_PORT2_INPUT);
	}
#endif
	/* TODO: Add a timeout using PIT */
	while (inb_p(PS2_STATUS) & PS2_STATUS_INFULL)
		__pause();
	outb_p(PS2_DATA, data);
	return true;
}

#ifndef CONFIG_PS2_KEYBOARD_BUFFER_SIZE
#define CONFIG_PS2_KEYBOARD_BUFFER_SIZE 256
#endif

/* Buffer to pressed, but not read key codes. */
PRIVATE ATTR_DBGBSS u8 ps2_keyboard_buffer[CONFIG_PS2_KEYBOARD_BUFFER_SIZE] = { 0, };
PRIVATE ATTR_DBGBSS unsigned int ps2_keyboard_buffer_pos = 0; /* Index into `ps2_keyboard_buffer', where the next received by is stored */
PRIVATE ATTR_DBGBSS unsigned int ps2_keyboard_buffer_siz = 0; /* Amount of unread bytes in `ps2_keyboard_buffer' */

PRIVATE ATTR_DBGBSS u8 ps2_keyboard_scanset = 0;     /* The scanset used by the keyboard. */
PRIVATE ATTR_DBGBSS u8 old_ps2_controller_rram0 = 0; /* The old value of `PS2_CONTROLLER_RRAM(0)' */

PRIVATE ATTR_DBGBSS u8 ps2_keyboard_modifiers = 0;   /* Set of `PS2_KEYBOARD_MODIFIER_*' */
#define PS2_KEYBOARD_MODIFIER_SHIFT 0x01 /* The shift key is being held. */
#define PS2_KEYBOARD_MODIFIER_CTRL  0x02 /* The ctrl key is being held. */
#define PS2_KEYBOARD_MODIFIER_ALT   0x04 /* The alt key is being held. */
#define PS2_KEYBOARD_MODIFIER_ALTGR 0x08 /* The r-alt key is being held. */
#define PS2_KEYBOARD_MODIFIER_CAPS  0x10 /* The caps key is active. */

#define HOLDING_CTRL() \
	(ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_CTRL)
#define HOLDING_CTRL_AND_SHIFT()                                     \
	((ps2_keyboard_modifiers &                                       \
	  (PS2_KEYBOARD_MODIFIER_CTRL | PS2_KEYBOARD_MODIFIER_SHIFT)) == \
	 (PS2_KEYBOARD_MODIFIER_CTRL | PS2_KEYBOARD_MODIFIER_SHIFT))




/* Blocking read a single keyboard control byte. */
PRIVATE ATTR_DBGTEXT u8 KCALL ps2_keyboard_getbyte(void) {
	u8 result;
	unsigned int index;
	__cli();
	while (!ps2_keyboard_buffer_siz) {
		__asm__("sti\n\t"
		        "hlt\n\t"
		        "cli");
	}
	if (ps2_keyboard_buffer_pos >= ps2_keyboard_buffer_siz) {
		index = ps2_keyboard_buffer_pos - ps2_keyboard_buffer_siz;
	} else {
		index = ps2_keyboard_buffer_siz - ps2_keyboard_buffer_pos;
		index = CONFIG_PS2_KEYBOARD_BUFFER_SIZE - index;
	}
	result = ps2_keyboard_buffer[index];
	--ps2_keyboard_buffer_siz;
	COMPILER_READ_BARRIER();
	__sti();
	return result;
}

PRIVATE ATTR_DBGTEXT NOBLOCK u8
NOTHROW(KCALL ps2_keyboard_getbyte_nb)(void) {
	u8 result;
	unsigned int index;
	__cli();
	if (!ps2_keyboard_buffer_siz) {
		__sti();
		return 0;
	}
	if (ps2_keyboard_buffer_pos >= ps2_keyboard_buffer_siz) {
		index = ps2_keyboard_buffer_pos - ps2_keyboard_buffer_siz;
	} else {
		index = ps2_keyboard_buffer_siz - ps2_keyboard_buffer_pos;
		index = CONFIG_PS2_KEYBOARD_BUFFER_SIZE - index;
	}
	result = ps2_keyboard_buffer[index];
	--ps2_keyboard_buffer_siz;
	COMPILER_READ_BARRIER();
	__sti();
	return result;
}

PRIVATE ATTR_DBGTEXT void
NOTHROW(KCALL ps2_keyboard_ungetbyte)(u8 byte) {
	unsigned int index;
	__cli();
	if (ps2_keyboard_buffer_siz < CONFIG_PS2_KEYBOARD_BUFFER_SIZE) {
		if (ps2_keyboard_buffer_pos >= ps2_keyboard_buffer_siz) {
			index = ps2_keyboard_buffer_pos - ps2_keyboard_buffer_siz;
		} else {
			index = ps2_keyboard_buffer_siz - ps2_keyboard_buffer_pos;
			index = CONFIG_PS2_KEYBOARD_BUFFER_SIZE - index;
		}
		ps2_keyboard_buffer[index] = byte;
		++ps2_keyboard_buffer_siz;
	}
	COMPILER_WRITE_BARRIER();
	__sti();
}

PRIVATE ATTR_DBGTEXT void KCALL check_reset(u8 f12) {
	unsigned int prev;
	if (ps2_keyboard_buffer_siz < 2)
		return;
	prev = ps2_keyboard_buffer_pos;
	if (!prev)
		prev = CONFIG_PS2_KEYBOARD_BUFFER_SIZE;
	--prev;
	if (ps2_keyboard_buffer[prev] != f12)
		return;
	if (!prev)
		prev = CONFIG_PS2_KEYBOARD_BUFFER_SIZE;
	--prev;
	if (ps2_keyboard_buffer[prev] != f12)
		return;
	ps2_keyboard_buffer_pos = 0;
	ps2_keyboard_buffer_siz = 0;
	/* Acknowledge the current interrupt */
	outb(X86_PIC1_CMD, X86_PIC_CMD_EOI);
	dbg(); /* Reset the debugger. */
}

PRIVATE ATTR_DBGTEXT NOBLOCK void
NOTHROW(KCALL ps2_keyboard_putbyte)(u8 byte) {
	switch (ps2_keyboard_scanset) {
	case 1:
		if (byte == 0x58) /* F12 */
			check_reset(0x58);
		break;
	case 2:
		if (byte == 0x07) /* F12 */
			check_reset(0x07);
		break;
	case 3:
		if (byte == 0x5e) /* F12 */
			check_reset(0x5e);
		break;
	default: break;
	}
	if (ps2_keyboard_buffer_pos >= CONFIG_PS2_KEYBOARD_BUFFER_SIZE)
		ps2_keyboard_buffer_pos = 0;
	ps2_keyboard_buffer[ps2_keyboard_buffer_pos] = byte;
	++ps2_keyboard_buffer_pos;
	if (ps2_keyboard_buffer_siz < CONFIG_PS2_KEYBOARD_BUFFER_SIZE)
		++ps2_keyboard_buffer_siz;
}

INTERN ATTR_DBGTEXT NOBLOCK void
NOTHROW(KCALL x86_debug_ps2_interrupt)(void) {
	u8 data;
#if 1
	for (;;) {
		u8 status = inb(PS2_STATUS);
		if (!(status & PS2_STATUS_OUTFULL))
			break;
		data = inb(PS2_DATA);
		ps2_keyboard_putbyte(data);
	}
#else
	data = inb(PS2_DATA);
	ps2_keyboard_putbyte(data);
#endif
}




/* Process a given `key', returning the new key, or 0 if it should be swallowed. */
PRIVATE ATTR_DBGTEXT unsigned int KCALL
dbg_process_key(unsigned int key) {
	/* Update keyboard modifiers. */
	switch (key) {

	case KEYDOWN(KEY_LSHIFT):
	case KEYDOWN(KEY_RSHIFT):
		ps2_keyboard_modifiers |= PS2_KEYBOARD_MODIFIER_SHIFT;
		break;
	case KEYUP(KEY_LSHIFT):
	case KEYUP(KEY_RSHIFT):
		ps2_keyboard_modifiers &= ~PS2_KEYBOARD_MODIFIER_SHIFT;
		break;
	case KEYDOWN(KEY_LCTRL):
	case KEYDOWN(KEY_RCTRL):
		ps2_keyboard_modifiers |= PS2_KEYBOARD_MODIFIER_CTRL;
		break;
	case KEYUP(KEY_LCTRL):
	case KEYUP(KEY_RCTRL):
		ps2_keyboard_modifiers &= ~PS2_KEYBOARD_MODIFIER_CTRL;
		break;
	case KEYDOWN(KEY_LALT):
		ps2_keyboard_modifiers |= PS2_KEYBOARD_MODIFIER_ALT;
		break;
	case KEYUP(KEY_LALT):
		ps2_keyboard_modifiers &= ~PS2_KEYBOARD_MODIFIER_ALT;
		break;
	case KEYDOWN(KEY_ALTGR):
		ps2_keyboard_modifiers |= PS2_KEYBOARD_MODIFIER_ALTGR;
		break;
	case KEYUP(KEY_ALTGR):
		ps2_keyboard_modifiers &= ~PS2_KEYBOARD_MODIFIER_ALTGR;
		break;
	case KEYUP(KEY_CAPSLOCK):
		ps2_keyboard_modifiers ^= PS2_KEYBOARD_MODIFIER_CAPS;
		break;

	/* Translate keypad keys to regular keys. */
	case KEYDOWN(KEY_KP_0): key = KEYDOWN(KEY_INSERT); break;
	case KEYDOWN(KEY_KP_1): key = KEYDOWN(KEY_END); break;
	case KEYDOWN(KEY_KP_2): key = KEYDOWN(KEY_DOWN); break;
	case KEYDOWN(KEY_KP_3): key = KEYDOWN(KEY_PGDOWN); break;
	case KEYDOWN(KEY_KP_4): key = KEYDOWN(KEY_LEFT); break;
	case KEYDOWN(KEY_KP_6): key = KEYDOWN(KEY_RIGHT); break;
	case KEYDOWN(KEY_KP_7): key = KEYDOWN(KEY_HOME); break;
	case KEYDOWN(KEY_KP_8): key = KEYDOWN(KEY_UP); break;
	case KEYDOWN(KEY_KP_9): key = KEYDOWN(KEY_PGUP); break;
	case KEYDOWN(KEY_KP_DOT): key = KEYDOWN(KEY_DELETE); break;
	case KEYUP(KEY_KP_0): key = KEYUP(KEY_INSERT); break;
	case KEYUP(KEY_KP_1): key = KEYUP(KEY_END); break;
	case KEYUP(KEY_KP_2): key = KEYUP(KEY_DOWN); break;
	case KEYUP(KEY_KP_3): key = KEYUP(KEY_PGDOWN); break;
	case KEYUP(KEY_KP_4): key = KEYUP(KEY_LEFT); break;
	case KEYUP(KEY_KP_6): key = KEYUP(KEY_RIGHT); break;
	case KEYUP(KEY_KP_7): key = KEYUP(KEY_HOME); break;
	case KEYUP(KEY_KP_8): key = KEYUP(KEY_UP); break;
	case KEYUP(KEY_KP_9): key = KEYUP(KEY_PGUP); break;
	case KEYUP(KEY_KP_DOT): key = KEYUP(KEY_DELETE); break;

	default: break;
	}

	switch (key) {

	case KEY_UP:
		if (HOLDING_CTRL_AND_SHIFT()) {
			unsigned int pos;
			/* Scroll down */
			pos = dbg_scroll(DBG_SCROLL_CMD_GET, 0);
			dbg_scroll(DBG_SCROLL_CMD_SET, pos + 1);
			key = 0;
		}
		break;
	case KEY_DOWN:
		if (HOLDING_CTRL_AND_SHIFT()) {
			unsigned int pos;
			/* Scroll down */
			pos = dbg_scroll(DBG_SCROLL_CMD_GET, 0);
			if (pos)
				dbg_scroll(DBG_SCROLL_CMD_SET, pos - 1);
			key = 0;
		}
		break;

	case KEY_PGUP:
		if (HOLDING_CTRL_AND_SHIFT()) {
			unsigned int pos;
			/* Scroll down */
			pos = dbg_scroll(DBG_SCROLL_CMD_GET, 0);
			dbg_scroll(DBG_SCROLL_CMD_SET, pos + dbg_screen_height);
			key = 0;
		}
		break;
	case KEY_PGDOWN:
		if (HOLDING_CTRL_AND_SHIFT()) {
			unsigned int pos;
			/* Scroll down */
			pos = dbg_scroll(DBG_SCROLL_CMD_GET, 0);
			if (pos >= dbg_screen_height)
				pos -= dbg_screen_height;
			else
				pos = 0;
			dbg_scroll(DBG_SCROLL_CMD_SET, pos);
			key = 0;
		}
		break;
	case KEY_HOME:
		if (HOLDING_CTRL_AND_SHIFT()) {
			/* Scroll to top */
			dbg_scroll(DBG_SCROLL_CMD_SET, (unsigned int)-1);
			key = 0;
		}
		break;
	case KEY_END:
		if (HOLDING_CTRL_AND_SHIFT()) {
			/* Scroll to end */
			dbg_scroll(DBG_SCROLL_CMD_SET, 0);
			key = 0;
		}
		break;
#undef HOLDING_CTRL_AND_SHIFT
	default: break;
	}
	return key;
}


PRIVATE ATTR_DBGBSS u16 dbg_getkey_pending[16] = { 0  };
PRIVATE ATTR_DBGBSS u8 dbg_getkey_pending_cnt = 0;


/* Unget a key to be re-returned by `dbg_(try)getkey'
 * When ungetting multiple keys, the key last unget'ed will be returned last. */
PUBLIC ATTR_DBGTEXT NOBLOCK bool NOTHROW(KCALL dbg_ungetkey)(u16 key) {
	if (dbg_getkey_pending_cnt >= COMPILER_LENOF(dbg_getkey_pending))
		return false;
	dbg_getkey_pending[dbg_getkey_pending_cnt] = key;
	++dbg_getkey_pending_cnt;
	return true;
}



/* Wait for the user to press a key and return its keycode.
 * @return: * : One of `KEY_*' (from <kos/keyboard.h>) */
LOCAL ATTR_DBGTEXT u16
NOTHROW(KCALL dbg_getkey_impl)(bool blocking) {
	u16 result;
	u8 byte;
	if (dbg_getkey_pending_cnt) {
		result = dbg_getkey_pending[0];
		--dbg_getkey_pending_cnt;
		memmovew(dbg_getkey_pending,
		         dbg_getkey_pending + 1,
		         dbg_getkey_pending_cnt);
		return result;
	}
#define READ_BYTE()                       \
	(blocking                             \
	 ? (byte = ps2_keyboard_getbyte(), 1) \
	 : ((byte = ps2_keyboard_getbyte_nb()) != 0))
again:
	if (!READ_BYTE())
		goto nokey;
	switch (ps2_keyboard_scanset) {

	case 1:
		/* Scanset #1 */
		if (byte == 0xe0) {
			if (!READ_BYTE()) {
				ps2_keyboard_ungetbyte(0xe0);
				goto nokey;
			}
			if (byte == 0x2a) {
				if (!READ_BYTE()) {
					ps2_keyboard_ungetbyte(0x2a);
					ps2_keyboard_ungetbyte(0xe0);
					goto nokey;
				}
				if (byte == 0xe0) {
					if (!READ_BYTE()) {
						ps2_keyboard_ungetbyte(0xe0);
						ps2_keyboard_ungetbyte(0x2a);
						ps2_keyboard_ungetbyte(0xe0);
						goto nokey;
					}
					if (byte == 0x37) {
						result = KEY_PRINTSCREEN;
					} else {
						/* Unwind. */
						ps2_keyboard_ungetbyte(byte);
						ps2_keyboard_ungetbyte(0xe0);
						result = KEYMAP_GET_PS2_SCANSET1_E0(0x2a);
					}
				} else {
					ps2_keyboard_ungetbyte(byte);
					result = KEYMAP_GET_PS2_SCANSET1_E0(0x2a);
				}
			} else if (byte == 0xb7) {
				if (!READ_BYTE()) {
					ps2_keyboard_ungetbyte(0xb7);
					ps2_keyboard_ungetbyte(0xe0);
					goto nokey;
				}
				if (byte == 0xe0) {
					if (!READ_BYTE()) {
						ps2_keyboard_ungetbyte(0xe0);
						ps2_keyboard_ungetbyte(0xb7);
						ps2_keyboard_ungetbyte(0xe0);
						goto nokey;
					}
					if (byte == 0xaa) {
						result = KEY_FRELEASED | KEY_PRINTSCREEN;
					} else {
						/* Unwind. */
						result = KEYMAP_GET_PS2_SCANSET1_E0(0xb7);
						ps2_keyboard_ungetbyte(0xe0);
					}
				} else {
					/* Unwind. */
					result = KEYMAP_GET_PS2_SCANSET1_E0(0xb7);
				}
			} else {
				result = KEYMAP_GET_PS2_SCANSET1_E0(byte);
			}
		} else if (byte == 0xe1) {
			if (!READ_BYTE()) {
				ps2_keyboard_ungetbyte(0xe1);
				goto nokey;
			}
			if (byte == 0x1d) {
				if (!READ_BYTE()) {
					ps2_keyboard_ungetbyte(0x1d);
					ps2_keyboard_ungetbyte(0xe1);
					goto nokey;
				}
				if (byte == 0x45) {
					if (!READ_BYTE()) {
						ps2_keyboard_ungetbyte(0x45);
						ps2_keyboard_ungetbyte(0x1d);
						ps2_keyboard_ungetbyte(0xe1);
						goto nokey;
					}
					if (byte == 0xe1) {
						if (!READ_BYTE()) {
							ps2_keyboard_ungetbyte(0xe1);
							ps2_keyboard_ungetbyte(0x45);
							ps2_keyboard_ungetbyte(0x1d);
							ps2_keyboard_ungetbyte(0xe1);
							goto nokey;
						}
						if (byte == 0x9d) {
							if (!READ_BYTE()) {
								ps2_keyboard_ungetbyte(0x9d);
								ps2_keyboard_ungetbyte(0xe1);
								ps2_keyboard_ungetbyte(0x45);
								ps2_keyboard_ungetbyte(0x1d);
								ps2_keyboard_ungetbyte(0xe1);
								goto nokey;
							}
							if (byte == 0x9d) {
								result = KEY_PAUSE;
							} else {
								result = KEYMAP_GET_PS2_SCANSET1(0xe1);
								ps2_keyboard_ungetbyte(byte);
								ps2_keyboard_ungetbyte(0x1d);
								ps2_keyboard_ungetbyte(0x45);
								ps2_keyboard_ungetbyte(0xe1);
								ps2_keyboard_ungetbyte(0x9d);
							}
						} else {
							result = KEYMAP_GET_PS2_SCANSET1(0xe1);
							ps2_keyboard_ungetbyte(byte);
							ps2_keyboard_ungetbyte(0x1d);
							ps2_keyboard_ungetbyte(0x45);
							ps2_keyboard_ungetbyte(0xe1);
						}
					} else {
						result = KEYMAP_GET_PS2_SCANSET1(0xe1);
						ps2_keyboard_ungetbyte(byte);
						ps2_keyboard_ungetbyte(0x1d);
						ps2_keyboard_ungetbyte(0x45);
					}
				} else {
					result = KEYMAP_GET_PS2_SCANSET1(0xe1);
					ps2_keyboard_ungetbyte(byte);
					ps2_keyboard_ungetbyte(0x1d);
				}
			} else {
				ps2_keyboard_ungetbyte(byte);
				result = KEYMAP_GET_PS2_SCANSET1(0xe1);
			}
		} else {
			result = KEYMAP_GET_PS2_SCANSET1(byte);
		}
		break;

	case 2:
		if (byte == 0xf0) {
			if (!READ_BYTE()) {
				ps2_keyboard_ungetbyte(0xf0);
				goto nokey;
			}
			result = keymap_ps2_scanset_2[byte] | KEY_FRELEASED;
		} else if (byte == 0xe0) {
			if (!READ_BYTE()) {
				ps2_keyboard_ungetbyte(0xe0);
				goto nokey;
			}
			if (byte == 0xf0) {
				if (!READ_BYTE()) {
					ps2_keyboard_ungetbyte(0xf0);
					ps2_keyboard_ungetbyte(0xe0);
					goto nokey;
				}
				if (byte == 0x7c) {
					if (!READ_BYTE()) {
						ps2_keyboard_ungetbyte(0x7c);
						ps2_keyboard_ungetbyte(0xf0);
						ps2_keyboard_ungetbyte(0xe0);
						goto nokey;
					}
					if (byte == 0xe0) {
						if (!READ_BYTE()) {
							ps2_keyboard_ungetbyte(0xe0);
							ps2_keyboard_ungetbyte(0x7c);
							ps2_keyboard_ungetbyte(0xf0);
							ps2_keyboard_ungetbyte(0xe0);
							goto nokey;
						}
						if (byte == 0xf0) {
							if (!READ_BYTE()) {
								ps2_keyboard_ungetbyte(0xf0);
								ps2_keyboard_ungetbyte(0xe0);
								ps2_keyboard_ungetbyte(0x7c);
								ps2_keyboard_ungetbyte(0xf0);
								ps2_keyboard_ungetbyte(0xe0);
								goto nokey;
							}
							if (byte == 0x12) {
								result = KEY_FRELEASED | KEY_PRINTSCREEN;
							} else {
								result = keymap_ps2_scanset_2_e0[0x7c] | KEY_FRELEASED;
								ps2_keyboard_ungetbyte(byte);
								ps2_keyboard_ungetbyte(0xf0);
								ps2_keyboard_ungetbyte(0xe0);
							}
							break;
						} else {
							result = keymap_ps2_scanset_2_e0[0x7c] | KEY_FRELEASED;
							ps2_keyboard_ungetbyte(byte);
							ps2_keyboard_ungetbyte(0xe0);
						}
					} else {
						result = keymap_ps2_scanset_2_e0[0x7c] | KEY_FRELEASED;
						ps2_keyboard_ungetbyte(byte);
					}
				} else {
					result = keymap_ps2_scanset_2_e0[byte] | KEY_FRELEASED;
				}
			} else if (byte == 0x12) {
				if (!READ_BYTE()) {
					ps2_keyboard_ungetbyte(0x12);
					ps2_keyboard_ungetbyte(0xe0);
					goto nokey;
				}
				if (byte == 0xe0) {
					if (!READ_BYTE()) {
						ps2_keyboard_ungetbyte(0xe0);
						ps2_keyboard_ungetbyte(0x12);
						ps2_keyboard_ungetbyte(0xe0);
						goto nokey;
					}
					if (byte == 0x7c) {
						result = KEY_PRINTSCREEN;
					} else {
						result = keymap_ps2_scanset_2_e0[0x12];
						ps2_keyboard_ungetbyte(byte);
						ps2_keyboard_ungetbyte(0xe0);
					}
				} else {
					result = keymap_ps2_scanset_2_e0[0x12];
					ps2_keyboard_ungetbyte(byte);
				}
			} else {
				result = keymap_ps2_scanset_2_e0[byte];
			}
		} else if (byte == 0xe1) {
			if (!READ_BYTE()) {
				ps2_keyboard_ungetbyte(0xe1);
				goto nokey;
			}
			if (byte == 0x14) {
				if (!READ_BYTE()) {
					ps2_keyboard_ungetbyte(0x14);
					ps2_keyboard_ungetbyte(0xe1);
					goto nokey;
				}
				if (byte == 0x77) {
					if (!READ_BYTE()) {
						ps2_keyboard_ungetbyte(0x77);
						ps2_keyboard_ungetbyte(0x14);
						ps2_keyboard_ungetbyte(0xe1);
						goto nokey;
					}
					if (byte == 0xe1) {
						if (!READ_BYTE()) {
							ps2_keyboard_ungetbyte(0xe1);
							ps2_keyboard_ungetbyte(0x77);
							ps2_keyboard_ungetbyte(0x14);
							ps2_keyboard_ungetbyte(0xe1);
							goto nokey;
						}
						if (byte == 0xf0) {
							if (!READ_BYTE()) {
								ps2_keyboard_ungetbyte(0xf0);
								ps2_keyboard_ungetbyte(0xe1);
								ps2_keyboard_ungetbyte(0x77);
								ps2_keyboard_ungetbyte(0x14);
								ps2_keyboard_ungetbyte(0xe1);
								goto nokey;
							}
							if (byte == 0x14) {
								if (!READ_BYTE()) {
									ps2_keyboard_ungetbyte(0x14);
									ps2_keyboard_ungetbyte(0xf0);
									ps2_keyboard_ungetbyte(0xe1);
									ps2_keyboard_ungetbyte(0x77);
									ps2_keyboard_ungetbyte(0x14);
									ps2_keyboard_ungetbyte(0xe1);
									goto nokey;
								}
								if (byte == 0xf0) {
									if (!READ_BYTE()) {
										ps2_keyboard_ungetbyte(0xf0);
										ps2_keyboard_ungetbyte(0x14);
										ps2_keyboard_ungetbyte(0xf0);
										ps2_keyboard_ungetbyte(0xe1);
										ps2_keyboard_ungetbyte(0x77);
										ps2_keyboard_ungetbyte(0x14);
										ps2_keyboard_ungetbyte(0xe1);
										goto nokey;
									}
									if (byte == 0x12) {
										result = KEY_PAUSE;
									} else {
										result = keymap_ps2_scanset_2[0xe1];
										ps2_keyboard_ungetbyte(byte);
										ps2_keyboard_ungetbyte(0xf0);
										ps2_keyboard_ungetbyte(0x14);
										ps2_keyboard_ungetbyte(0xf0);
										ps2_keyboard_ungetbyte(0xe1);
										ps2_keyboard_ungetbyte(0x77);
										ps2_keyboard_ungetbyte(0x14);
									}
								} else {
									result = keymap_ps2_scanset_2[0xe1];
									ps2_keyboard_ungetbyte(byte);
									ps2_keyboard_ungetbyte(0x14);
									ps2_keyboard_ungetbyte(0xf0);
									ps2_keyboard_ungetbyte(0xe1);
									ps2_keyboard_ungetbyte(0x77);
									ps2_keyboard_ungetbyte(0x14);
								}
							} else {
								result = keymap_ps2_scanset_2[0xe1];
								ps2_keyboard_ungetbyte(byte);
								ps2_keyboard_ungetbyte(0xf0);
								ps2_keyboard_ungetbyte(0xe1);
								ps2_keyboard_ungetbyte(0x77);
								ps2_keyboard_ungetbyte(0x14);
							}
						} else {
							result = keymap_ps2_scanset_2[0xe1];
							ps2_keyboard_ungetbyte(byte);
							ps2_keyboard_ungetbyte(0xe1);
							ps2_keyboard_ungetbyte(0x77);
							ps2_keyboard_ungetbyte(0x14);
						}
					} else {
						result = keymap_ps2_scanset_2[0xe1];
						ps2_keyboard_ungetbyte(byte);
						ps2_keyboard_ungetbyte(0x77);
						ps2_keyboard_ungetbyte(0x14);
					}
				} else {
					result = keymap_ps2_scanset_2[0xe1];
					ps2_keyboard_ungetbyte(byte);
					ps2_keyboard_ungetbyte(0x14);
				}
			} else {
				result = keymap_ps2_scanset_2[0xe1];
				ps2_keyboard_ungetbyte(byte);
			}
		} else {
			result = keymap_ps2_scanset_2[byte];
		}
		break;

	case 3:
		if (byte == 0xf0) {
			if (!READ_BYTE()) {
				ps2_keyboard_ungetbyte(0xf0);
				goto nokey;
			}
			result = keymap_ps2_scanset_3[byte] | KEY_FRELEASED;
		} else {
			result = keymap_ps2_scanset_3[byte];
		}
		break;

	default:
		result = (unsigned int)byte;
		break;
	}
	result = dbg_process_key(result);
	if (!result)
		goto again;
	return result;
nokey:
	return 0;
#undef READ_BYTE
}


/* @return: 0: No keys available. */
PUBLIC ATTR_DBGTEXT u16
NOTHROW(KCALL dbg_trygetkey)(void) {
	return dbg_getkey_impl(false);
}

/* Wait for the user to press a key and return its keycode.
 * @return: * : One of `KEY_*' (from <kos/keyboard.h>) */
PUBLIC ATTR_DBGTEXT u16
NOTHROW(KCALL dbg_getkey)(void) {
	return dbg_getkey_impl(true);
}


struct keyboard_keymap {
	u8 km_press[128]; /* Regular key map. */
	u8 km_shift[128]; /* Key map while the shift-key is held. */
	u8 km_altgr[128]; /* Key map when RALT or CTRL+ALT is held down. */
};

PRIVATE ATTR_DBGDATA struct keyboard_keymap keymap = {
/*[[[deemon
#include "../../../../../../include/kos/keyboard.h"
#include <util>
local km_press = [0] * 128;
local km_shift = [0] * 128;
local km_altgr = [0] * 128;

function MAP(id, a, b = none, c = none) {
	km_press[id] = a;
	if (b !is none)
		km_shift[id] = b;
	if (c !is none)
		km_altgr[id] = c;
}
#define MAP(...) MAP(__VA_ARGS__);
MAP(KEY_DELETE,     '\x7f')
MAP(KEY_GRAVE_ACCENT,'^',  '�')
MAP(KEY_1,          '1',   '!')
MAP(KEY_2,          '2',   '\"',  '�')
MAP(KEY_3,          '3',   '�',   '�')
MAP(KEY_4,          '4',   '$')
MAP(KEY_5,          '5',   '%')
MAP(KEY_6,          '6',   '&')
MAP(KEY_7,          '7',   '/',   '{')
MAP(KEY_8,          '8',   '(',   '[')
MAP(KEY_9,          '9',   ')',   ']')
MAP(KEY_0,          '0',   '=',   '}')
MAP(KEY_MINUS,      '�',   '?',   '\\')
MAP(KEY_EQUALS,     '�',   '`')
MAP(KEY_BACKSPACE,  '\x8')

MAP(KEY_TAB,        '\t')
MAP(KEY_Q,          'q',   'Q',   '@')
MAP(KEY_W,          'w',   'W')
MAP(KEY_E,          'e',   'E',   '�')
MAP(KEY_R,          'r',   'R')
MAP(KEY_T,          't',   'T')
MAP(KEY_Y,          'z',   'Z')
MAP(KEY_U,          'u',   'U')
MAP(KEY_I,          'i',   'I')
MAP(KEY_O,          'o',   'O')
MAP(KEY_P,          'p',   'P')
MAP(KEY_LBRACKET,   '�',   '�')
MAP(KEY_RBRACKET,   '+',   '*',   '~')
MAP(KEY_ENTER,      '\n',  '\xc') // Form feed (New page)

MAP(KEY_A,          'a',   'A')
MAP(KEY_S,          's',   'S')
MAP(KEY_D,          'd',   'D')
MAP(KEY_F,          'f',   'F')
MAP(KEY_G,          'g',   'G')
MAP(KEY_H,          'h',   'H')
MAP(KEY_J,          'j',   'J')
MAP(KEY_K,          'k',   'K')
MAP(KEY_L,          'l',   'L')
MAP(KEY_SEMICOLON,  '�',   '�')
MAP(KEY_SINGLEQUOTE,'�',   '�')
MAP(KEY_NUMBERSIGN, '#',   '\'')

MAP(KEY_LESS,       '<',   '>',   '|')
MAP(KEY_Z,          'y',   'Y')
MAP(KEY_X,          'x',   'X')
MAP(KEY_C,          'c',   'C')
MAP(KEY_V,          'v',   'V')
MAP(KEY_B,          'b',   'B')
MAP(KEY_N,          'n',   'N')
MAP(KEY_M,          'm',   'M')
MAP(KEY_COMMA,      ',',   ';')
MAP(KEY_DOT,        '.',   ':')
MAP(KEY_SLASH,      '-',   '_')

MAP(KEY_SPACE,      ' ')

MAP(KEY_KP_SLASH,   '/')
MAP(KEY_KP_STAR,    '*')
MAP(KEY_KP_MINUS,   '-')
MAP(KEY_KP_7,       '7')
MAP(KEY_KP_8,       '8')
MAP(KEY_KP_9,       '9')
MAP(KEY_KP_PLUS,    '+')
MAP(KEY_KP_4,       '4')
MAP(KEY_KP_5,       '5')
MAP(KEY_KP_6,       '6')
MAP(KEY_KP_1,       '1')
MAP(KEY_KP_2,       '2')
MAP(KEY_KP_3,       '3')
MAP(KEY_KP_ENTER,   '\n')
MAP(KEY_KP_0,       '0')
MAP(KEY_KP_DOT,     ',')

function printmap(l,indent) {
	print indent,;
	for (local i,x: util.enumerate(l)) {
		if (i) {
			print ",",;
			if ((i % 16) == 0) {
				print;
				print indent,;
			}
		}
		print x,;
	}
}
print "\t{";
printmap(km_press,"\t\t");
print;
print "\t},{";
printmap(km_shift,"\t\t");
print;
print "\t},{";
printmap(km_altgr,"\t\t");
print;
print "\t}";
]]]*/
	{
		0,0,49,50,51,52,53,54,55,56,57,48,223,180,8,9,
		113,119,101,114,116,122,117,105,111,112,252,43,10,0,97,115,
		100,102,103,104,106,107,108,246,228,94,0,35,121,120,99,118,
		98,110,109,44,46,45,0,42,0,32,0,0,0,0,0,0,
		0,0,0,0,0,0,0,55,56,57,45,52,53,54,43,49,
		50,51,48,44,0,0,60,0,0,0,0,0,0,0,0,0,
		10,0,47,0,0,0,0,0,0,0,0,0,0,0,0,127,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
		0,0,33,34,167,36,37,38,47,40,41,61,63,96,0,0,
		81,87,69,82,84,90,85,73,79,80,220,42,12,0,65,83,
		68,70,71,72,74,75,76,214,196,176,0,39,89,88,67,86,
		66,78,77,59,58,95,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,62,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
		0,0,0,178,179,0,0,0,123,91,93,125,92,0,0,0,
		64,0,128,0,0,0,0,0,0,0,0,126,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,124,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	}
//[[[end]]]
};





PRIVATE ATTR_DBGBSS char32_t dbg_getuni_pending[16] = { 0, };
PRIVATE ATTR_DBGBSS u8 dbg_getuni_pending_cnt = 0;

#define ANSI_ESCAPE "\033"

PRIVATE ATTR_DBGTEXT NOBLOCK NONNULL((1)) char32_t
NOTHROW(KCALL dbg_getuni_setstring)(char const *__restrict text) {
	char32_t result = (char32_t)(u8)*text++;
	dbg_getuni_pending_cnt = 0;
	for (; *text; ++text) {
		dbg_getuni_pending[dbg_getuni_pending_cnt] = (char32_t)(u8)*text;
		++dbg_getuni_pending_cnt;
	}
	return result;
}

PUBLIC ATTR_DBGTEXT NOBLOCK bool NOTHROW(KCALL dbg_ungetuni)(/*utf-32*/ char32_t ch) {
	if (dbg_getuni_pending_cnt >= COMPILER_LENOF(dbg_getuni_pending))
		return false;
	dbg_getuni_pending[dbg_getuni_pending_cnt] = ch;
	++dbg_getuni_pending_cnt;
	return true;
}

PUBLIC ATTR_DBGTEXT NOBLOCK bool NOTHROW(KCALL dbg_hasuni)(void) {
	return dbg_getuni_pending_cnt != 0;
}

PUBLIC ATTR_DBGTEXT NOBLOCK void NOTHROW(KCALL dbg_purgeuni)(void) {
	dbg_getuni_pending_cnt = 0;
}

/* Wait for the user to press a key and return the pressed character.
 * NOTE: Modifier keys aren't returned by this function. */
PUBLIC ATTR_DBGTEXT /*utf-32*/ char32_t KCALL dbg_getuni(void) {
	u16 key;
	char32_t result;
	if (dbg_getuni_pending_cnt) {
		result = dbg_getuni_pending[0];
		--dbg_getuni_pending_cnt;
		memmovel(dbg_getuni_pending,
		         dbg_getuni_pending + 1,
		         dbg_getuni_pending_cnt);
		return result;
	} else {
again_getkey:
		key = dbg_getkey();
		if (key & KEY_FRELEASED)
			goto again_getkey;
		switch (key) {

		case KEY_UP:
			result = dbg_getuni_setstring(HOLDING_CTRL()
			                              ? ANSI_ESCAPE "OA"
			                              : ANSI_ESCAPE "[A");
			break;
		case KEY_DOWN:
			result = dbg_getuni_setstring(HOLDING_CTRL()
			                              ? ANSI_ESCAPE "OB"
			                              : ANSI_ESCAPE "[B");
			break;
		case KEY_RIGHT:
			result = dbg_getuni_setstring(HOLDING_CTRL()
			                              ? ANSI_ESCAPE "OC"
			                              : ANSI_ESCAPE "[C");
			break;
		case KEY_LEFT:
			result = dbg_getuni_setstring(HOLDING_CTRL()
			                              ? ANSI_ESCAPE "OD"
			                              : ANSI_ESCAPE "[D");
			break;
		case KEY_PGUP:
			result = dbg_getuni_setstring(ANSI_ESCAPE "[5~");
			break;
		case KEY_PGDOWN:
			result = dbg_getuni_setstring(ANSI_ESCAPE "[6~");
			break;
		case KEY_HOME:
			result = dbg_getuni_setstring(ANSI_ESCAPE "OH");
			break;
		case KEY_END:
			result = dbg_getuni_setstring(ANSI_ESCAPE "OF");
			break;
		case KEY_TAB:
			if (((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_SHIFT) != 0) !=
			    ((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_CAPS) != 0)) {
				result = dbg_getuni_setstring(ANSI_ESCAPE "[Z");
			} else {
				result = '\t';
			}
			break;

		case KEY_F1: result = dbg_getuni_setstring(ANSI_ESCAPE "[11~"); break;
		case KEY_F2: result = dbg_getuni_setstring(ANSI_ESCAPE "[12~"); break;
		case KEY_F3: result = dbg_getuni_setstring(ANSI_ESCAPE "[13~"); break;
		case KEY_F4: result = dbg_getuni_setstring(ANSI_ESCAPE "[14~"); break;
		case KEY_F5: result = dbg_getuni_setstring(ANSI_ESCAPE "[15~"); break;
		case KEY_F6: result = dbg_getuni_setstring(ANSI_ESCAPE "[17~"); break;
		case KEY_F7: result = dbg_getuni_setstring(ANSI_ESCAPE "[18~"); break;
		case KEY_F8: result = dbg_getuni_setstring(ANSI_ESCAPE "[19~"); break;
		case KEY_F9: result = dbg_getuni_setstring(ANSI_ESCAPE "[20~"); break;
		case KEY_F10: result = dbg_getuni_setstring(ANSI_ESCAPE "[21~"); break;
		case KEY_F11: result = dbg_getuni_setstring(ANSI_ESCAPE "[23~"); break;
		case KEY_F12: result = dbg_getuni_setstring(ANSI_ESCAPE "[24~"); break;
		case KEY_DELETE: result = dbg_getuni_setstring(ANSI_ESCAPE "[3~"); break;
		case KEY_ENTER: result = '\n'; break;

		default:
			if (key <= 0x7f) {
				if (((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_SHIFT) != 0) !=
				    ((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_CAPS) != 0)) {
					result = keymap.km_shift[key];
				} else if ((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_ALTGR) ||
				           (ps2_keyboard_modifiers & (PS2_KEYBOARD_MODIFIER_CTRL | PS2_KEYBOARD_MODIFIER_ALT)) ==
				           (PS2_KEYBOARD_MODIFIER_CTRL | PS2_KEYBOARD_MODIFIER_ALT)) {
					result = keymap.km_altgr[key];
				} else {
					result = keymap.km_press[key];
				}
				if (result) {
					if (HOLDING_CTRL() &&
					    (!(ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_ALT) ||
					     !keymap.km_altgr[key])) {
						/* Create control character (e.g.: CTRL+C --> '\03') */
						result = (u32)((u8)toupper((char)(u8)result) - '@');
					}
					return result;
				}
			}
			goto again_getkey;
		}
	}
	return result;
}

PUBLIC ATTR_DBGTEXT NOBLOCK bool NOTHROW(KCALL dbg_isholding_ctrl)(void) {
	return HOLDING_CTRL();
}
PUBLIC ATTR_DBGTEXT NOBLOCK bool NOTHROW(KCALL dbg_isholding_shift)(void) {
	return ((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_SHIFT) != 0) !=
	       ((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_CAPS) != 0);
}
PUBLIC ATTR_DBGTEXT NOBLOCK bool NOTHROW(KCALL dbg_isholding_alt)(void) {
	return ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_ALT;
}
PUBLIC ATTR_DBGTEXT NOBLOCK bool NOTHROW(KCALL dbg_isholding_altgr)(void) {
	return (ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_ALTGR) ||
	       (ps2_keyboard_modifiers & (PS2_KEYBOARD_MODIFIER_CTRL | PS2_KEYBOARD_MODIFIER_ALT)) ==
	       (PS2_KEYBOARD_MODIFIER_CTRL | PS2_KEYBOARD_MODIFIER_ALT);
}

PUBLIC ATTR_DBGTEXT /*utf-32*/ char32_t KCALL dbg_trygetuni(void) {
	u16 key;
	char32_t result;
	if (dbg_getuni_pending_cnt) {
		result = dbg_getuni_pending[0];
		--dbg_getuni_pending_cnt;
		memmovel(dbg_getuni_pending,
		         dbg_getuni_pending + 1,
		         dbg_getuni_pending_cnt);
		return result;
	} else {
again_getkey:
		key = dbg_trygetkey();
		if (key & KEY_FRELEASED)
			goto again_getkey;
		switch (key) {
		case 0: result = 0; break;

		case KEY_UP:
			result = dbg_getuni_setstring(HOLDING_CTRL()
			                              ? ANSI_ESCAPE "OA"
			                              : ANSI_ESCAPE "[A");
			break;
		case KEY_DOWN:
			result = dbg_getuni_setstring(HOLDING_CTRL()
			                              ? ANSI_ESCAPE "OB"
			                              : ANSI_ESCAPE "[B");
			break;
		case KEY_RIGHT:
			result = dbg_getuni_setstring(HOLDING_CTRL()
			                              ? ANSI_ESCAPE "OC"
			                              : ANSI_ESCAPE "[C");
			break;
		case KEY_LEFT:
			result = dbg_getuni_setstring(HOLDING_CTRL()
			                              ? ANSI_ESCAPE "OD"
			                              : ANSI_ESCAPE "[D");
			break;
		case KEY_PGUP:
			result = dbg_getuni_setstring(ANSI_ESCAPE "[5~");
			break;
		case KEY_PGDOWN:
			result = dbg_getuni_setstring(ANSI_ESCAPE "[6~");
			break;
		case KEY_HOME:
			result = dbg_getuni_setstring(ANSI_ESCAPE "OH");
			break;
		case KEY_END:
			result = dbg_getuni_setstring(ANSI_ESCAPE "OF");
			break;
		case KEY_TAB:
			if (((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_SHIFT) != 0) !=
			    ((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_CAPS) != 0)) {
				result = dbg_getuni_setstring(ANSI_ESCAPE "[Z");
			} else {
				result = '\t';
			}
			break;

		case KEY_F1: result = dbg_getuni_setstring(ANSI_ESCAPE "[11~"); break;
		case KEY_F2: result = dbg_getuni_setstring(ANSI_ESCAPE "[12~"); break;
		case KEY_F3: result = dbg_getuni_setstring(ANSI_ESCAPE "[13~"); break;
		case KEY_F4: result = dbg_getuni_setstring(ANSI_ESCAPE "[14~"); break;
		case KEY_F5: result = dbg_getuni_setstring(ANSI_ESCAPE "[15~"); break;
		case KEY_F6: result = dbg_getuni_setstring(ANSI_ESCAPE "[17~"); break;
		case KEY_F7: result = dbg_getuni_setstring(ANSI_ESCAPE "[18~"); break;
		case KEY_F8: result = dbg_getuni_setstring(ANSI_ESCAPE "[19~"); break;
		case KEY_F9: result = dbg_getuni_setstring(ANSI_ESCAPE "[20~"); break;
		case KEY_F10: result = dbg_getuni_setstring(ANSI_ESCAPE "[21~"); break;
		case KEY_F11: result = dbg_getuni_setstring(ANSI_ESCAPE "[23~"); break;
		case KEY_F12: result = dbg_getuni_setstring(ANSI_ESCAPE "[24~"); break;
		case KEY_DELETE: result = dbg_getuni_setstring(ANSI_ESCAPE "[3~"); break;
		case KEY_ENTER: result = '\n'; break;

		default:
			if (key <= 0x7f) {
				if (((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_SHIFT) != 0) !=
				    ((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_CAPS) != 0)) {
					result = keymap.km_shift[key];
				} else if ((ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_ALTGR) ||
				           (ps2_keyboard_modifiers & (PS2_KEYBOARD_MODIFIER_CTRL | PS2_KEYBOARD_MODIFIER_ALT)) ==
				           (PS2_KEYBOARD_MODIFIER_CTRL | PS2_KEYBOARD_MODIFIER_ALT)) {
					result = keymap.km_altgr[key];
				} else {
					result = keymap.km_press[key];
				}
				if (result) {
					if (HOLDING_CTRL() &&
					    (!(ps2_keyboard_modifiers & PS2_KEYBOARD_MODIFIER_ALT) ||
					     !keymap.km_altgr[key])) {
						/* Create control character (e.g.: CTRL+C --> '\03') */
						result = (u32)((u8)toupper((char)(u8)result) - '@');
					}
					return result;
				}
			}
			goto again_getkey;
		}
	}
	return result;
}





PRIVATE ATTR_DBGBSS uint8_t dbg_getc_pending_cnt = 0;
PRIVATE ATTR_DBGBSS uint8_t dbg_getc_pending[UNICODE_UTF8_CURLEN] = { 0, };

PUBLIC ATTR_DBGTEXT NOBLOCK bool
NOTHROW(KCALL dbg_ungetc)(/*utf-8*/ char ch) {
	if (dbg_getc_pending_cnt) {
		uint8_t reqlen;
		/* Unget a utf-8 sequence (continue) */
		reqlen = unicode_utf8seqlen[dbg_getc_pending[0]];
		dbg_getc_pending[dbg_getc_pending_cnt] = (u8)ch;
		++dbg_getc_pending_cnt;
		if (dbg_getc_pending_cnt >= reqlen) {
			u32 ch32;
			ch32 = unicode_readutf8((char const **)dbg_getc_pending);
			dbg_getc_pending_cnt = 0;
			return dbg_ungetuni(ch32);
		}
	} else if ((uint8_t)ch < 0xc0) {
		return dbg_ungetuni((u32)(u8)ch);
	} else {
		/* Unget a utf-8 sequence (start) */
		dbg_getc_pending[0]  = (u8)ch;
		dbg_getc_pending_cnt = 1;
	}
	return true;
}


PUBLIC ATTR_DBGTEXT /*utf-8*/ char KCALL dbg_getc(void) {
	/* Convert unicode characters to utf-8 */
again:
	if (dbg_getc_pending_cnt) {
		uint8_t result = dbg_getc_pending[0];
		--dbg_getc_pending_cnt;
		memmove(dbg_getc_pending,
		        dbg_getc_pending + 1,
		        dbg_getc_pending_cnt);
		return result;
	} else {
		uint32_t ch;
		ch = dbg_getuni();
		if (ch < 0xc0)
			return (char)(uint8_t)ch;
		dbg_getc_pending_cnt = (uint8_t)(unicode_writeutf8((char *)dbg_getc_pending, ch) -
		                                 (char *)dbg_getc_pending);
		goto again;
	}
}

PUBLIC ATTR_DBGTEXT /*utf-8*/ char KCALL dbg_trygetc(void) {
	/* Convert unicode characters to utf-8 */
again:
	if (dbg_getc_pending_cnt) {
		uint8_t result = dbg_getc_pending[0];
		--dbg_getc_pending_cnt;
		memmove(dbg_getc_pending,
		        dbg_getc_pending + 1,
		        dbg_getc_pending_cnt);
		return result;
	} else {
		uint32_t ch;
		ch = dbg_trygetuni();
		if (ch < 0xc0)
			return (char)(uint8_t)ch;
		dbg_getc_pending_cnt = (uint8_t)(unicode_writeutf8((char *)dbg_getc_pending, ch) -
		                                 (char *)dbg_getc_pending);
		goto again;
	}
}



INTERN ATTR_DBGTEXT void NOTHROW(KCALL x86_debug_initialize_ps2_keyboard)(void) {
	unsigned int position;
	int data;

	/* Acknowledge any pending interrupts so-as to
	 * ensure that we'll be able to receive input. */
	outb(X86_PIC2_CMD, X86_PIC_CMD_EOI);
	outb(X86_PIC1_CMD, X86_PIC_CMD_EOI);

	ps2_write_cmd(PS2_CONTROLLER_DISABLE_PORT1);
	ps2_write_cmd(PS2_CONTROLLER_DISABLE_PORT2);
	ps2_keyboard_buffer_pos = 0;
	ps2_keyboard_buffer_siz = 0;

	/* Read RAM #0 */
	position = __LINE__;
	if (!ps2_write_cmd(PS2_CONTROLLER_RRAM(0)))
		goto err_no_ps2;
	position = __LINE__;
	data     = ps2_read_cmddata();
	if (data < 0)
		goto err_no_ps2;
	old_ps2_controller_rram0 = (u8)data;

	/* Set up the PS/2 device configuration. */
	data |= (PS2_CONTROLLER_CFG_PORT1_IRQ | PS2_CONTROLLER_CFG_SYSTEMFLAG);
	data &= ~(PS2_CONTROLLER_CFG_PORT1_TRANSLATE | PS2_CONTROLLER_CFG_PORT2_IRQ);

	position = __LINE__;
	if (!ps2_write_cmd(PS2_CONTROLLER_WRAM(0)))
		goto err_no_ps2;
	position = __LINE__;
	if (!ps2_write_cmddata((u8)data))
		goto err_no_ps2;
	/* Enable the keyboard. */
	position = __LINE__;
	if (!ps2_write_cmd(PS2_CONTROLLER_ENABLE_PORT1))
		goto err_no_ps2;

	/* TODO: Restore keyboard configuration in `x86_debug_finalize_ps2_keyboard()'! */

	/* Reset the keyboard controller. */
	position = __LINE__;
	if (!ps2_write_data(PS2_KEYBOARD_CMD_RESET))
		goto err_no_ps2;
	position = __LINE__;
	if (ps2_keyboard_getbyte() != PS2_RSP_ACK)
		goto err_no_ps2;
	position = __LINE__;
	if (ps2_keyboard_getbyte() != 0xaa)
		goto err_no_ps2;

	/* Determine the scanset used by the keyboard, and try to set scanset #2. */
	position = __LINE__;
	if (!ps2_write_data(PS2_KEYBOARD_CMD_SCANSET))
		goto err_no_ps2;
	position = __LINE__;
	if (ps2_keyboard_getbyte() != PS2_RSP_ACK)
		goto err_no_ps2;
	position = __LINE__;
	if (!ps2_write_data(PS2_KEYBOARD_CMD_SCANSET_SET2))
		goto err_no_ps2;
	if (ps2_keyboard_getbyte() != PS2_RSP_ACK) {
		/* Try to re-initialize the keyboard (it may just be really
		 * old, or not capable of supporting multiple scansets...) */
		position = __LINE__;
		if (!ps2_write_data(PS2_KEYBOARD_CMD_RESET))
			goto err_no_ps2;
		position = __LINE__;
		if (ps2_keyboard_getbyte() != PS2_RSP_ACK)
			goto err_no_ps2;
		position = __LINE__;
		if (ps2_keyboard_getbyte() != 0xaa)
			goto err_no_ps2;
		position = __LINE__;
		if (!ps2_write_data(PS2_KEYBOARD_CMD_SETDEFAULT))
			goto err_no_ps2;
		position = __LINE__;
		if (ps2_keyboard_getbyte() != PS2_RSP_ACK)
			goto err_no_ps2;
	}

	/* Now read the newly set scanset! */
	position = __LINE__;
	if (!ps2_write_data(PS2_KEYBOARD_CMD_SCANSET))
		goto err_no_ps2;
	position = __LINE__;
	if (ps2_keyboard_getbyte() != PS2_RSP_ACK)
		goto err_no_ps2;
	position = __LINE__;
	if (!ps2_write_data(PS2_KEYBOARD_CMD_SCANSET_GET))
		goto err_no_ps2;
	position = __LINE__;
	if (ps2_keyboard_getbyte() != PS2_RSP_ACK)
		goto err_no_ps2;
	ps2_keyboard_scanset = ps2_keyboard_getbyte() & 3;
	if unlikely(!ps2_keyboard_scanset)
		ps2_keyboard_scanset = 1;

	/* Enable scanning */
	position = __LINE__;
	if (!ps2_write_data(PS2_KEYBOARD_CMD_ENABLE_SCANNING))
		goto err_no_ps2;
	position = __LINE__;
	if (ps2_keyboard_getbyte() != PS2_RSP_ACK)
		goto err_no_ps2;

	ps2_keyboard_modifiers = 0;
	dbg_getkey_pending_cnt = 0;
	dbg_getuni_pending_cnt = 0;
	dbg_getc_pending_cnt   = 0;
	return;
err_no_ps2:
	kernel_panic("Cannot enter debug mode: Failed to initialize "
	             "PS/2 at %d (is a keyboard connected?)",
	             position);
}

INTERN ATTR_DBGTEXT void KCALL
x86_debug_finalize_ps2_keyboard(void) {
	ps2_write_cmd(PS2_CONTROLLER_WRAM(0));
	ps2_write_cmddata(old_ps2_controller_rram0);
	ps2_write_cmd((old_ps2_controller_rram0 & PS2_CONTROLLER_CFG_PORT2_IRQ)
	              ? PS2_CONTROLLER_ENABLE_PORT2
	              : PS2_CONTROLLER_DISABLE_PORT2);
	ps2_write_cmd((old_ps2_controller_rram0 & PS2_CONTROLLER_CFG_PORT1_IRQ)
	              ? PS2_CONTROLLER_ENABLE_PORT1
	              : PS2_CONTROLLER_DISABLE_PORT1);
}


DECL_END
#endif /* !CONFIG_NO_DEBUGGER */

#endif /* !GUARD_KERNEL_CORE_ARCH_I386_DEBUGGER_INPUT_C */
