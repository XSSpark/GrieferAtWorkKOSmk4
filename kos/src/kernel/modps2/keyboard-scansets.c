/*[[[magic
// Because g++ is dumb and refuses to parse array
// initializers, compile this file as C, rather than C++
options["COMPILE.language"] = "c";
local gcc_opt = options.setdefault("GCC.options", []);
gcc_opt.remove("-fno-rtti");
gcc_opt.append("-fexceptions");
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
#ifndef GUARD_MODPS2_KEYBOARD_SCANSETS_C
#define GUARD_MODPS2_KEYBOARD_SCANSETS_C 1

#include <kernel/compiler.h>

#include <kernel/types.h>
#include <kos/keyboard.h>
#include <sched/task.h>

#include "keyboard-scansets.h"

DECL_BEGIN

#pragma GCC diagnostic ignored "-Woverride-init"


INTERN_CONST u16 const ps2_keyboard_ss1[128] = {
	[0 ... 127] = KEY_UNKNOWN,

	[0x01] = KEY_ESC,
	[0x02] = KEY_1,
	[0x03] = KEY_2,
	[0x04] = KEY_3,
	[0x05] = KEY_4,
	[0x06] = KEY_5,
	[0x07] = KEY_6,
	[0x08] = KEY_7,
	[0x09] = KEY_8,
	[0x0a] = KEY_9,
	[0x0b] = KEY_0,
	[0x0c] = KEY_MINUS,
	[0x0d] = KEY_EQUALS,
	[0x0e] = KEY_BACKSPACE,
	[0x0f] = KEY_TAB,
	[0x10] = KEY_Q,
	[0x11] = KEY_W,
	[0x12] = KEY_E,
	[0x13] = KEY_R,
	[0x14] = KEY_T,
	[0x15] = KEY_Y,
	[0x16] = KEY_U,
	[0x17] = KEY_I,
	[0x18] = KEY_O,
	[0x19] = KEY_P,
	[0x1a] = KEY_LBRACKET,
	[0x1b] = KEY_RBRACKET,
	[0x1c] = KEY_ENTER,
	[0x1d] = KEY_LCTRL,
	[0x1e] = KEY_A,
	[0x1f] = KEY_S,
	[0x20] = KEY_D,
	[0x21] = KEY_F,
	[0x22] = KEY_G,
	[0x23] = KEY_H,
	[0x24] = KEY_J,
	[0x25] = KEY_K,
	[0x26] = KEY_L,
	[0x27] = KEY_SEMICOLON,
	[0x28] = KEY_APOSTROPHE,
	[0x29] = KEY_GRAVE_ACCENT,
	[0x2a] = KEY_LSHIFT,
	[0x2b] = KEY_BACKSLASH,
	[0x2c] = KEY_Z,
	[0x2d] = KEY_X,
	[0x2e] = KEY_C,
	[0x2f] = KEY_V,
	[0x30] = KEY_B,
	[0x31] = KEY_N,
	[0x32] = KEY_M,
	[0x33] = KEY_COMMA,
	[0x34] = KEY_DOT,
	[0x35] = KEY_SLASH,
	[0x36] = KEY_RSHIFT,
	[0x37] = KEY_KP_MULTIPLY,
	[0x38] = KEY_LALT,
	[0x39] = KEY_SPACE,
	[0x3a] = KEY_CAPSLOCK,
	[0x3b] = KEY_F1,
	[0x3c] = KEY_F2,
	[0x3d] = KEY_F3,
	[0x3e] = KEY_F4,
	[0x3f] = KEY_F5,
	[0x40] = KEY_F6,
	[0x41] = KEY_F7,
	[0x42] = KEY_F8,
	[0x43] = KEY_F9,
	[0x44] = KEY_F10,
	[0x45] = KEY_NUMLOCK,
	[0x46] = KEY_SCROLLLOCK,
	[0x47] = KEY_KP_7,
	[0x48] = KEY_KP_8,
	[0x49] = KEY_KP_9,
	[0x4a] = KEY_KP_SUBTRACT,
	[0x4b] = KEY_KP_4,
	[0x4c] = KEY_KP_5,
	[0x4d] = KEY_KP_6,
	[0x4e] = KEY_KP_ADD,
	[0x4f] = KEY_KP_1,
	[0x50] = KEY_KP_2,
	[0x51] = KEY_KP_3,
	[0x52] = KEY_KP_0,
	[0x53] = KEY_KP_DECIMAL,
	[0x54] = KEY_SYSRQ,
	[0x56] = KEY_LESS,
	[0x57] = KEY_F11,
	[0x58] = KEY_F12,
	[0x73] = KEY_RO,
	[0x7e] = KEY_KP_COMMA,
};


INTERN_CONST u16 const ps2_keyboard_ss1_e0[128] = {
	[0 ... 127] = KEY_UNKNOWN,

	[0x10] = KEY_MM_PREVIOUS_TRACK,
	[0x19] = KEY_MM_NEXT_TRACK,
	[0x1c] = KEY_KP_ENTER,
	[0x1d] = KEY_RCTRL,
	[0x20] = KEY_VOLUME_MUTE,
	[0x21] = KEY_CALCULATOR,
	[0x22] = KEY_MM_PLAY_PAUSE,
	[0x24] = KEY_MM_STOP,
	[0x2e] = KEY_VOLUME_DOWN,
	[0x30] = KEY_VOLUME_UP,
	[0x32] = KEY_WWW_HOME,
	[0x35] = KEY_KP_DIVIDE,
	[0x37] = KEY_PRINTSCREEN, /* CTRL+PRINT */
	[0x38] = KEY_RALT,
	[0x46] = KEY_BREAK, /* CTRL+BREAK */
	[0x47] = KEY_HOME,
	[0x48] = KEY_UP,
	[0x49] = KEY_PGUP,
	[0x4b] = KEY_LEFT,
	[0x4d] = KEY_RIGHT,
	[0x4f] = KEY_END,
	[0x50] = KEY_DOWN,
	[0x51] = KEY_PGDOWN,
	[0x52] = KEY_INSERT,
	[0x53] = KEY_DELETE,
	[0x5b] = KEY_LGUI,
	[0x5c] = KEY_RGUI,
	[0x5d] = KEY_MENU,
	[0x5e] = KEY_APIC_POWER,
	[0x5f] = KEY_APIC_SLEEP,
	[0x63] = KEY_APIC_WAKE,
	[0x65] = KEY_WWW_SEARCH,
	[0x66] = KEY_WWW_FAVORITES,
	[0x67] = KEY_WWW_REFRESH,
	[0x68] = KEY_WWW_STOP,
	[0x69] = KEY_WWW_FORWARD,
	[0x6a] = KEY_WWW_BACK,
	[0x6b] = KEY_MY_COMPUTER,
	[0x6c] = KEY_EMAIL_CLIENT,
	[0x6d] = KEY_MM_SELECT,
};


INTERN_CONST u16 const ps2_keyboard_ss2[133] = {
	[0 ... 132] = KEY_UNKNOWN,

	[0x01] = KEY_F9,
	[0x03] = KEY_F5,
	[0x04] = KEY_F3,
	[0x05] = KEY_F1,
	[0x06] = KEY_F2,
	[0x07] = KEY_F12,
	[0x08] = KEY_RALT, /* LALTGR */
	[0x09] = KEY_F10,
	[0x0a] = KEY_F8,
	[0x0b] = KEY_F6,
	[0x0c] = KEY_F4,
	[0x0d] = KEY_TAB,
	[0x0e] = KEY_GRAVE_ACCENT,
	[0x11] = KEY_LALT,
	[0x12] = KEY_LSHIFT,
	[0x14] = KEY_LCTRL,
	[0x15] = KEY_Q,
	[0x16] = KEY_1,
	[0x1a] = KEY_Z,
	[0x1b] = KEY_S,
	[0x1c] = KEY_A,
	[0x1d] = KEY_W,
	[0x1e] = KEY_2,
	[0x21] = KEY_C,
	[0x22] = KEY_X,
	[0x23] = KEY_D,
	[0x24] = KEY_E,
	[0x25] = KEY_4,
	[0x26] = KEY_3,
	[0x29] = KEY_SPACE,
	[0x2a] = KEY_V,
	[0x2b] = KEY_F,
	[0x2c] = KEY_T,
	[0x2d] = KEY_R,
	[0x2e] = KEY_5,
	[0x31] = KEY_N,
	[0x32] = KEY_B,
	[0x33] = KEY_H,
	[0x34] = KEY_G,
	[0x35] = KEY_Y,
	[0x36] = KEY_6,
	[0x3a] = KEY_M,
	[0x3b] = KEY_J,
	[0x3c] = KEY_U,
	[0x3d] = KEY_7,
	[0x3e] = KEY_8,
	[0x41] = KEY_COMMA,
	[0x42] = KEY_K,
	[0x43] = KEY_I,
	[0x44] = KEY_O,
	[0x45] = KEY_0,
	[0x46] = KEY_9,
	[0x49] = KEY_DOT,
	[0x4a] = KEY_SLASH,
	[0x4b] = KEY_L,
	[0x4c] = KEY_SEMICOLON,
	[0x4d] = KEY_P,
	[0x4e] = KEY_MINUS,
	[0x51] = KEY_RO,
	[0x52] = KEY_APOSTROPHE,
	[0x54] = KEY_LBRACKET,
	[0x55] = KEY_EQUALS,
	[0x58] = KEY_CAPSLOCK,
	[0x59] = KEY_RSHIFT,
	[0x5a] = KEY_ENTER,
	[0x5b] = KEY_RBRACKET,
	[0x5d] = KEY_BACKSLASH,
	[0x61] = KEY_LESS,
	[0x66] = KEY_BACKSPACE,
	[0x69] = KEY_KP_1,
	[0x6b] = KEY_KP_4,
	[0x6c] = KEY_KP_7,
	[0x6d] = KEY_KP_COMMA,
	[0x70] = KEY_KP_0,
	[0x71] = KEY_KP_DECIMAL,
	[0x72] = KEY_KP_2,
	[0x73] = KEY_KP_5,
	[0x74] = KEY_KP_6,
	[0x75] = KEY_KP_8,
	[0x76] = KEY_ESC,
	[0x77] = KEY_NUMLOCK,
	[0x78] = KEY_F11,
	[0x79] = KEY_KP_ADD,
	[0x7a] = KEY_KP_3,
	[0x7b] = KEY_KP_SUBTRACT,
	[0x7c] = KEY_KP_MULTIPLY,
	[0x7d] = KEY_KP_9,
	[0x7e] = KEY_SCROLLLOCK,
	[0x7f] = KEY_SYSRQ,
	[0x83] = KEY_F7,
	[0x84] = KEY_SYSRQ, /* Alt+SYSRQ */
};

INTERN_CONST u16 const ps2_keyboard_ss2_e0[128] = {
	[0 ... 127] = KEY_UNKNOWN,

	[0x08] = KEY_RALT, /* RALTGR */
	[0x10] = KEY_WWW_SEARCH,
	[0x11] = KEY_RALT,
	[0x14] = KEY_RCTRL,
	[0x15] = KEY_MM_PREVIOUS_TRACK,
	[0x18] = KEY_WWW_FAVORITES,
	[0x1f] = KEY_LGUI,
	[0x20] = KEY_WWW_REFRESH,
	[0x21] = KEY_VOLUME_DOWN,
	[0x23] = KEY_VOLUME_MUTE,
	[0x27] = KEY_RGUI,
	[0x28] = KEY_WWW_STOP,
	[0x2b] = KEY_CALCULATOR,
	[0x2f] = KEY_MENU,
	[0x30] = KEY_WWW_FORWARD,
	[0x32] = KEY_VOLUME_UP,
	[0x34] = KEY_MM_PLAY_PAUSE,
	[0x37] = KEY_APIC_POWER,
	[0x38] = KEY_WWW_BACK,
	[0x3a] = KEY_WWW_HOME,
	[0x3b] = KEY_MM_STOP,
	[0x3f] = KEY_APIC_SLEEP,
	[0x40] = KEY_MY_COMPUTER,
	[0x48] = KEY_EMAIL_CLIENT,
	[0x4a] = KEY_KP_DIVIDE,
	[0x4d] = KEY_MM_NEXT_TRACK,
	[0x50] = KEY_MM_SELECT,
	[0x5a] = KEY_KP_ENTER,
	[0x5e] = KEY_APIC_WAKE,
	[0x69] = KEY_END,
	[0x6b] = KEY_LEFT,
	[0x6c] = KEY_HOME,
	[0x70] = KEY_INSERT,
	[0x71] = KEY_DELETE,
	[0x72] = KEY_DOWN,
	[0x74] = KEY_RIGHT,
	[0x75] = KEY_UP,
	[0x7a] = KEY_PGDOWN,
	[0x7c] = KEY_PRINTSCREEN,
	[0x7d] = KEY_PGUP,
	[0x7e] = KEY_BREAK, /* CTRL+BREAK */
};


INTERN_CONST u16 const ps2_keyboard_ss3[256] = {
	[0 ... 255] = KEY_UNKNOWN,

	[0x07] = KEY_F1,
	[0x08] = KEY_ESC,
	[0x0d] = KEY_TAB,
	[0x0e] = KEY_GRAVE_ACCENT,
	[0x0f] = KEY_F2,
	[0x11] = KEY_LCTRL,
	[0x12] = KEY_LSHIFT,
	[0x14] = KEY_CAPSLOCK,
	[0x15] = KEY_Q,
	[0x16] = KEY_1,
	[0x17] = KEY_F3,
	[0x19] = KEY_LALT,
	[0x1a] = KEY_Z,
	[0x1b] = KEY_S,
	[0x1c] = KEY_A,
	[0x1d] = KEY_W,
	[0x1e] = KEY_2,
	[0x1f] = KEY_F4,
	[0x21] = KEY_C,
	[0x22] = KEY_X,
	[0x23] = KEY_D,
	[0x24] = KEY_E,
	[0x25] = KEY_4,
	[0x26] = KEY_3,
	[0x27] = KEY_F5,
	[0x29] = KEY_SPACE,
	[0x2a] = KEY_V,
	[0x2b] = KEY_F,
	[0x2c] = KEY_T,
	[0x2d] = KEY_R,
	[0x2e] = KEY_5,
	[0x2f] = KEY_F6,
	[0x31] = KEY_N,
	[0x32] = KEY_B,
	[0x33] = KEY_H,
	[0x34] = KEY_G,
	[0x35] = KEY_Y,
	[0x36] = KEY_6,
	[0x37] = KEY_F7,
	[0x39] = KEY_RALT,
	[0x3a] = KEY_M,
	[0x3b] = KEY_J,
	[0x3c] = KEY_U,
	[0x3d] = KEY_7,
	[0x3e] = KEY_8,
	[0x3f] = KEY_F8,
	[0x41] = KEY_COMMA,
	[0x42] = KEY_K,
	[0x43] = KEY_I,
	[0x44] = KEY_O,
	[0x45] = KEY_0,
	[0x46] = KEY_9,
	[0x47] = KEY_F9,
	[0x49] = KEY_DOT,
	[0x4a] = KEY_SLASH,
	[0x4b] = KEY_L,
	[0x4c] = KEY_SEMICOLON,
	[0x4d] = KEY_P,
	[0x4e] = KEY_KP_SUBTRACT,
	[0x4e] = KEY_MINUS,
	[0x4f] = KEY_F10,
	[0x52] = KEY_APOSTROPHE,
	[0x54] = KEY_LBRACKET,
	[0x55] = KEY_EQUALS,
	[0x56] = KEY_F11,
	[0x57] = KEY_PRINTSCREEN,
	[0x58] = KEY_RCTRL,
	[0x59] = KEY_RSHIFT,
	[0x5a] = KEY_ENTER,
	[0x5b] = KEY_RBRACKET,
	[0x5c] = KEY_BACKSLASH,
	[0x5e] = KEY_F12,
	[0x5f] = KEY_SCROLLLOCK,
	[0x60] = KEY_DOWN,
	[0x61] = KEY_LEFT,
	[0x62] = KEY_PAUSE,
	[0x63] = KEY_UP,
	[0x64] = KEY_DELETE,
	[0x65] = KEY_END,
	[0x66] = KEY_BACKSPACE,
	[0x67] = KEY_INSERT,
	[0x69] = KEY_KP_1,
	[0x6a] = KEY_RIGHT,
	[0x6b] = KEY_KP_4,
	[0x6c] = KEY_KP_7,
	[0x6d] = KEY_PGDOWN,
	[0x6e] = KEY_HOME,
	[0x6f] = KEY_PGUP,
	[0x70] = KEY_KP_0,
	[0x71] = KEY_KP_DECIMAL,
	[0x72] = KEY_KP_2,
	[0x73] = KEY_KP_5,
	[0x74] = KEY_KP_6,
	[0x75] = KEY_KP_8,
	[0x76] = KEY_NUMLOCK,
	[0x79] = KEY_KP_ENTER,
	[0x7a] = KEY_KP_3,
	[0x7c] = KEY_KP_ADD,
	[0x7d] = KEY_KP_9,
	[0x7e] = KEY_KP_MULTIPLY,
	[0x8b] = KEY_LGUI,
	[0x8c] = KEY_RGUI,
	[0x8d] = KEY_MENU,
};


DECL_END

#endif /* !GUARD_MODPS2_KEYBOARD_SCANSETS_C */
