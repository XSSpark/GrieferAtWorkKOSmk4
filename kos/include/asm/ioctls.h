#ifndef _ASM_IOCTLS_H
#define _ASM_IOCTLS_H 1

/* DISCLAIMER: _STRONGLY_ Based on '/usr/include/asm-generic/ioctls.h'
 * NOTE: Do not add a license header to this file! */

#include <linux/ioctl.h>

#define TCGETS              _IO('T', 0x01) /* [struct termio *arg] Get terminal attributes */
#define TCSETS              _IO('T', 0x02) /* [struct termio const *arg] Set terminal attributes */
#define TCSETSW             _IO('T', 0x03) /* [struct termio const *arg] Wait for all unwritten data to be transmitted, discard all unread data, then set terminal attributes */
#define TCSETSF             _IO('T', 0x04) /* [struct termio const *arg] Wait for all unwritten data to be transmitted, then set terminal attributes */
#define TCGETA              _IO('T', 0x05) /* [struct termios *arg] Get terminal attributes */
#define TCSETA              _IO('T', 0x06) /* [struct termios const *arg] Set terminal attributes */
#define TCSETAW             _IO('T', 0x07) /* [struct termios const *arg] Wait for all unwritten data to be transmitted, discard all unread data, then set terminal attributes */
#define TCSETAF             _IO('T', 0x08) /* [struct termios const *arg] Wait for all unwritten data to be transmitted, then set terminal attributes */
#define TCSBRK              _IO('T', 0x09) /* [int arg] Send a break (arg should be 0 for portability, but is ignored when non-zero) */
#define TCXONC              _IO('T', 0x0a) /* [int arg = { TCOOFF, TCOON, TCIOFF, TCION }] */
#define TCFLSH              _IO('T', 0x0b) /* [int arg = { TCIFLUSH, TCOFLUSH, TCIOFLUSH }] */

#define TIOCEXCL            _IO('T', 0x0c)
#define TIOCNXCL            _IO('T', 0x0d)
#define TIOCSCTTY           _IO('T', 0x0e) /* [int steal_if_necessary]
                                            * @throws: E_INVALID_CONTEXT_NOT_SESSION_LEADER:    The calling process isn't the session leader
                                            * @throws: E_INVALID_CONTEXT_CTTY_ALREADY_ASSIGNED: The calling session already has a different CTTY assigned (use `TIOCNOTTY' to disconnect from it)
                                            * @throws: E_INSUFFICIENT_RIGHTS_CTTY_STEALING:     `steal_if_necessary' was zero, or the calling thread doesn't have `CAP_SYS_ADMIN' */
#define TIOCGPGRP           _IO('T', 0x0f) /* [pid_t *arg] Store the PID of the foreground process group in arg */
#define TIOCSPGRP           _IO('T', 0x10) /* [pid_t const *arg] Load the PID of the foreground process group from arg */
#define TIOCOUTQ            _IO('T', 0x11) /* [int *count] Save the number of pending output bytes */
#define TIOCSTI             _IO('T', 0x12) /* [char const *byte] Insert the given byte in the input queue. */
#define TIOCGWINSZ          _IO('T', 0x13) /* [struct winsize *arg] Get the window size */
#define TIOCSWINSZ          _IO('T', 0x14) /* [struct winsize const *arg] Set the window size */
#define TIOCMGET            _IO('T', 0x15)
#define TIOCMBIS            _IO('T', 0x16)
#define TIOCMBIC            _IO('T', 0x17)
#define TIOCMSET            _IO('T', 0x18)

#define TIOCGSOFTCAR        _IO('T', 0x19) /* [int *arg] Get the state of `termios::c_cflag::CLOCAL'. */
#define TIOCSSOFTCAR        _IO('T', 0x1a) /* [int const *arg] Set the state of `termios::c_cflag::CLOCAL'. */
#define FIONREAD            _IO('T', 0x1b) /* [int *count] Save the number of pending input bytes */
#define TIOCINQ            FIONREAD        /* [int *count] Save the number of pending input bytes */
#define TIOCLINUX           _IO('T', 0x1c)
#define TIOCCONS            _IO('T', 0x1d)
#define TIOCGSERIAL         _IO('T', 0x1e)
#define TIOCSSERIAL         _IO('T', 0x1f)
#define TIOCPKT             _IO('T', 0x20)
#define FIONBIO             _IO('T', 0x21) /* [int *arg] Set (*arg != 0) or clear (*arg == 0) O_NONBLOCK / IO_NONBLOCK */
#define TIOCNOTTY           _IO('T', 0x22) /* Given up control over this CTTY
                                            * @throws: E_INVALID_CONTEXT_NOT_SESSION_LEADER: The calling process isn't the session leader
                                            * @throws: E_INVALID_CONTEXT_CTTY_DIFFERS:       The calling session uses a different CTTY */
#define TIOCSETD            _IO('T', 0x23) /* [int const *ld] Set the terminal's line discipline to *ld */
#define TIOCGETD            _IO('T', 0x24) /* [int *result] Store the terminal's line discipline in *result */
#define TCSBRKP             _IO('T', 0x25) /* [int deciseconds] Needed for POSIX tcsendbreak() */
#define TIOCSBRK            _IO('T', 0x27) /* BSD compatibility */
#define TIOCCBRK            _IO('T', 0x28) /* BSD compatibility */
#define TIOCGSID            _IO('T', 0x29) /* [pid_t *arg] Return the session ID of FD */
#define TCGETS2            _IOR('T', 0x2a, struct termios2)
#define TCSETS2            _IOW('T', 0x2b, struct termios2)
#define TCSETSW2           _IOW('T', 0x2c, struct termios2)
#define TCSETSF2           _IOW('T', 0x2d, struct termios2)
#define TIOCGRS485          _IO('T', 0x2e)
#ifndef TIOCSRS485
#define TIOCSRS485          _IO('T', 0x2f)
#endif
#define TIOCGPTN           _IOR('T', 0x30, unsigned int) /* Get Pty Number (of pty-mux device) */
#define TIOCSPTLCK         _IOW('T', 0x31, int)  /* Lock/unlock Pty */
#define TIOCGDEV           _IOR('T', 0x32, unsigned int) /* Get primary device node of /dev/console */
#define TCGETX              _IO('T', 0x32) /* SYS5 TCGETX compatibility */
#define TCSETX              _IO('T', 0x33)
#define TCSETXF             _IO('T', 0x34)
#define TCSETXW             _IO('T', 0x35)
#define TIOCSIG            _IOW('T', 0x36, int) /* pty: generate signal */
#define TIOCVHANGUP         _IO('T', 0x37)
#define TIOCGPKT           _IOR('T', 0x38, int) /* Get packet mode state */
#define TIOCGPTLCK         _IOR('T', 0x39, int) /* Get Pty lock state */
#define TIOCGEXCL          _IOR('T', 0x40, int) /* Get exclusive mode state */

#define FIONCLEX            _IO('T', 0x50) /* Clear O_CLOEXEC / IO_CLOEXEC */
#define FIOCLEX             _IO('T', 0x51) /* Set O_CLOEXEC / IO_CLOEXEC */
#define FIOASYNC            _IO('T', 0x52) /* [int *arg] Set (*arg != 0) or clear (*arg == 0) O_ASYNC / IO_ASYNC */
#define TIOCSERCONFIG       _IO('T', 0x53)
#define TIOCSERGWILD        _IO('T', 0x54)
#define TIOCSERSWILD        _IO('T', 0x55)
#define TIOCGLCKTRMIOS      _IO('T', 0x56)
#define TIOCSLCKTRMIOS      _IO('T', 0x57)
#define TIOCSERGSTRUCT      _IO('T', 0x58) /* For debugging only */
#define TIOCSERGETLSR       _IO('T', 0x59) /* Get line status register */
#define TIOCSERGETMULTI     _IO('T', 0x5a) /* Get multiport config  */
#define TIOCSERSETMULTI     _IO('T', 0x5b) /* Set multiport config */
#define TIOCMIWAIT          _IO('T', 0x5c) /* wait for a change on serial input line(s) */
#define TIOCGICOUNT         _IO('T', 0x5d) /* read serial port inline interrupt counts */
#ifndef FIOQSIZE
#define FIOQSIZE            _IO('T', 0x60) /* [loff_t *arg] Return object data-size */
#endif /* !FIOQSIZE */

/* Used for packet mode */
#define TIOCPKT_DATA       0x0000
#define TIOCPKT_FLUSHREAD  0x0001
#define TIOCPKT_FLUSHWRITE 0x0002
#define TIOCPKT_STOP       0x0004
#define TIOCPKT_START      0x0008
#define TIOCPKT_NOSTOP     0x0010
#define TIOCPKT_DOSTOP     0x0020
#define TIOCPKT_IOCTL      0x0040

#define TIOCSER_TEMT       0x01 /* Transmitter physically empty */

#endif /* !_ASM_IOCTLS_H */
