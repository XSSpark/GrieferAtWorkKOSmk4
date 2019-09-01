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
#ifndef GUARD_LIBC_USER_TERMIOS_C
#define GUARD_LIBC_USER_TERMIOS_C 1

#include "../api.h"
#include "termios.h"
#include <sys/ioctl.h>

DECL_BEGIN





/*[[[start:implementation]]]*/

/*[[[head:tcgetattr,hash:0x4261f975]]]*/
INTERN NONNULL((2))
ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.tcgetattr") int
NOTHROW_NCX(LIBCCALL libc_tcgetattr)(fd_t fd,
                                     struct termios *__restrict termios_p)
/*[[[body:tcgetattr]]]*/
{
	return (int)ioctl(fd, TCGETA, termios_p);
}
/*[[[end:tcgetattr]]]*/

/*[[[head:tcsetattr,hash:0xfaa3833f]]]*/
INTERN NONNULL((3))
ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.tcsetattr") int
NOTHROW_NCX(LIBCCALL libc_tcsetattr)(fd_t fd,
                                     int optional_actions,
                                     struct termios const *__restrict termios_p)
/*[[[body:tcsetattr]]]*/
{
	int cmd;
	switch (optional_actions) {

	case TCSANOW:
		cmd = TCSETA;
		break;

	case TCSADRAIN:
		cmd = TCSETAW;
		break;

	case TCSAFLUSH:
		cmd = TCSETAF;
		break;

	default:
		libc_seterrno(EINVAL);
		return -1;
	}
	return (int)ioctl(fd, cmd, termios_p);
}
/*[[[end:tcsetattr]]]*/

/*[[[head:tcsendbreak,hash:0xdcd2cc46]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.tcsendbreak") int
NOTHROW_NCX(LIBCCALL libc_tcsendbreak)(fd_t fd,
                                       int duration)
/*[[[body:tcsendbreak]]]*/
{
	return (int)ioctl(fd, TCSBRKP, duration);
}
/*[[[end:tcsendbreak]]]*/

/*[[[head:tcdrain,hash:0x3f72c60c]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.tcdrain") int
NOTHROW_RPC(LIBCCALL libc_tcdrain)(fd_t fd)
/*[[[body:tcdrain]]]*/
{
	return (int)ioctl(fd, TCSBRK, 1);
}
/*[[[end:tcdrain]]]*/

/*[[[head:tcflush,hash:0xaf0f4c7]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.tcflush") int
NOTHROW_NCX(LIBCCALL libc_tcflush)(fd_t fd,
                                   int queue_selector)
/*[[[body:tcflush]]]*/
{
	return (int)ioctl(fd, TCFLSH, queue_selector);
}
/*[[[end:tcflush]]]*/

/*[[[head:tcflow,hash:0x587f9b1c]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.tcflow") int
NOTHROW_NCX(LIBCCALL libc_tcflow)(fd_t fd,
                                  int action)
/*[[[body:tcflow]]]*/
{
	return (int)ioctl(fd, TCXONC, action);
}
/*[[[end:tcflow]]]*/

/*[[[head:tcgetsid,hash:0x7e226d94]]]*/
INTERN ATTR_WEAK ATTR_SECTION(".text.crt.io.tty.tcgetsid") pid_t
NOTHROW_NCX(LIBCCALL libc_tcgetsid)(fd_t fd)
/*[[[body:tcgetsid]]]*/
{
	pid_t result;
	if (ioctl(fd, TIOCGSID, &result) < 0)
		result = -1;
	return result;
}
/*[[[end:tcgetsid]]]*/

/*[[[end:implementation]]]*/



/*[[[start:exports,hash:0xf67cac85]]]*/
DEFINE_PUBLIC_WEAK_ALIAS(tcgetattr, libc_tcgetattr);
DEFINE_PUBLIC_WEAK_ALIAS(tcsetattr, libc_tcsetattr);
DEFINE_PUBLIC_WEAK_ALIAS(tcsendbreak, libc_tcsendbreak);
DEFINE_PUBLIC_WEAK_ALIAS(tcdrain, libc_tcdrain);
DEFINE_PUBLIC_WEAK_ALIAS(tcflush, libc_tcflush);
DEFINE_PUBLIC_WEAK_ALIAS(tcflow, libc_tcflow);
DEFINE_PUBLIC_WEAK_ALIAS(tcgetsid, libc_tcgetsid);
/*[[[end:exports]]]*/

DECL_END

#endif /* !GUARD_LIBC_USER_TERMIOS_C */
