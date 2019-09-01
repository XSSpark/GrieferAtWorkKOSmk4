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
#ifndef _KOS_KERNEL_HANDLE_H
#define _KOS_KERNEL_HANDLE_H 1

#include <__stdinc.h>

#ifndef __KOS__
#error "KOS-only system header"
#endif /* !__KOS__ */

/* Special values which may be used to refer to specific handles. */
#define HANDLE_SYMBOLIC_FDCWD              __CCAST(unsigned int)(-100) /* HANDLE_TYPE_PATH (writable) */
#define HANDLE_SYMBOLIC_FDROOT             __CCAST(unsigned int)(-101) /* HANDLE_TYPE_PATH (writable) */
#define HANDLE_SYMBOLIC_THISTASK           __CCAST(unsigned int)(-180) /* HANDLE_TYPE_TASK (readonly, Equivalent of `gettid()') */
#define HANDLE_SYMBOLIC_THISPROCESS        __CCAST(unsigned int)(-181) /* HANDLE_TYPE_TASK (writable, Equivalent of `getpid()') */
#define HANDLE_SYMBOLIC_PARENTPROCESS      __CCAST(unsigned int)(-182) /* HANDLE_TYPE_TASK (writable, Equivalent of `getppid()') */
#define HANDLE_SYMBOLIC_GROUPLEADER        __CCAST(unsigned int)(-183) /* HANDLE_TYPE_TASK (writable, Equivalent of `getpgid(0)') */
#define HANDLE_SYMBOLIC_SESSIONLEADER      __CCAST(unsigned int)(-184) /* HANDLE_TYPE_TASK (writable, Equivalent of `getsid(0)') */
#define HANDLE_SYMBOLIC_THISVM             HANDLE_SYMBOLIC_THISTASK
#define HANDLE_SYMBOLIC_THISFS             HANDLE_SYMBOLIC_THISTASK
#define HANDLE_SYMBOLIC_THISVFS            HANDLE_SYMBOLIC_THISTASK
#define HANDLE_SYMBOLIC_THISPIDNS          HANDLE_SYMBOLIC_THISTASK

/* Symbolic handles for DOS drives */
#define HANDLE_SYMBOLIC_DDRIVECWD(drivechar)  __CCAST(unsigned int)((-350)+((drivechar)-'A')) /* HANDLE_TYPE_PATH (writable) */
#define HANDLE_SYMBOLIC_DDRIVEROOT(drivechar) __CCAST(unsigned int)((-300)+((drivechar)-'A')) /* HANDLE_TYPE_PATH (writable) */
#define HANDLE_SYMBOLIC_DDRIVEMIN            'A' /* Min valid DDrive letter */
#define HANDLE_SYMBOLIC_DDRIVEMAX            'Z' /* Max valid DDrive letter */


/* KOS Handle type codes.
 * NOTE: Changes to this list must be updated with:
 * $ deemon -F src/kernel/core/user/handle-router.c
 */
#define HANDLE_TYPE_UNDEFINED       0x0000 /* Undefined/unused handle */
#define HANDLE_TYPE_DATABLOCK       0x0001 /* `struct vm_datablock' (also includes `struct inode') */
#define HANDLE_TYPE_BLOCKDEVICE     0x0002 /* `struct basic_block_device' */
#define HANDLE_TYPE_DIRECTORYENTRY  0x0003 /* `struct directory_entry' */
#define HANDLE_TYPE_FILE            0x0004 /* `struct file'
                                            * Castable into: HANDLE_TYPE_PATH, HANDLE_TYPE_DATABLOCK, HANDLE_TYPE_DIRECTORYENTRY */
#define HANDLE_TYPE_ONESHOT_DIRECTORY_FILE 0x0005 /* `struct oneshot_directory_file'
                                            * Castable into: HANDLE_TYPE_PATH, HANDLE_TYPE_DATABLOCK, HANDLE_TYPE_DIRECTORYENTRY */
#define HANDLE_TYPE_PATH            0x0006 /* `struct path' (also includes `struct vfs')
                                            * Castable into: HANDLE_TYPE_DATABLOCK, HANDLE_TYPE_DIRECTORYENTRY */
#define HANDLE_TYPE_FS              0x0007 /* `struct fs' */
#define HANDLE_TYPE_VM              0x0008 /* `struct vm' */
#define HANDLE_TYPE_TASK            0x0009 /* `struct taskpid' */
#define HANDLE_TYPE_CLOCK           0x000a /* `struct wall_clock' (TODO) */
#define HANDLE_TYPE_DRIVER          0x000b /* `struct driver' */
#define HANDLE_TYPE_PIPE            0x000c /* `struct pipe' */
#define HANDLE_TYPE_PIPE_READER     0x000d /* `struct pipe_reader' */
#define HANDLE_TYPE_PIPE_WRITER     0x000e /* `struct pipe_writer' */
#define HANDLE_TYPE_PIDNS           0x000f /* `struct pidns' */
#define HANDLE_TYPE_DRIVER_STATE    0x0010 /* `struct driver_state' */
#define HANDLE_TYPE_CHARACTERDEVICE 0x0011 /* `struct character_device'
                                            * Castable into: HANDLE_TYPE_DATABLOCK (if supported) */
#define HANDLE_TYPE_COUNT           0x0012 /* # of recognized handle types */

/* Handle type-kind codes (used to identify special sub-classes of handle types). */
#define HANDLE_TYPEKIND_GENERIC     0x0000 /* Generic catch-all handle-type kind */

/* Handle kinds for `HANDLE_TYPE_DATABLOCK' */
#define HANDLE_TYPEKIND_DATABLOCK_GENERIC     0x0000 /* The handle refers to a `struct vm_datablock' */
#define HANDLE_TYPEKIND_DATABLOCK_INODE       0x0001 /* The handle refers to a `struct inode' */
#define HANDLE_TYPEKIND_DATABLOCK_REGULARNODE 0x0002 /* The handle refers to a `struct regular_node' */
#define HANDLE_TYPEKIND_DATABLOCK_DIRECTORY   0x0003 /* The handle refers to a `struct directory_node' */
#define HANDLE_TYPEKIND_DATABLOCK_SYMLINKNODE 0x0004 /* The handle refers to a `struct symlink_node' */
#define HANDLE_TYPEKIND_DATABLOCK_SUPERBLOCK  0x0005 /* The handle refers to a `struct superblock' */
/* Handle kinds for `HANDLE_TYPE_BLOCKDEVICE' */
#define HANDLE_TYPEKIND_BLOCKDEVICE_GENERIC   0x0000 /* The handle refers to a `struct basic_block_device' */
#define HANDLE_TYPEKIND_BLOCKDEVICE_PARTITION 0x0001 /* The handle refers to a `struct block_device_partition' */
#define HANDLE_TYPEKIND_BLOCKDEVICE_DRIVEROOT 0x0002 /* The handle refers to a `struct block_device' */
/* Handle kinds for `HANDLE_TYPE_CHARACTERDEVICE' */
#define HANDLE_TYPEKIND_CHARACTERDEVICE_GENERIC  0x0000 /* The handle refers to a `struct character_device' */
#define HANDLE_TYPEKIND_CHARACTERDEVICE_TTYBASE  0x0001 /* The handle refers to a `struct ttybase_device' */
#define HANDLE_TYPEKIND_CHARACTERDEVICE_TTY      0x0002 /* The handle refers to a `struct tty_device' and `struct ttybase_device' */
#define HANDLE_TYPEKIND_CHARACTERDEVICE_PTY      0x0003 /* The handle refers to a `struct pty_master' and `struct ttybase_device' */
#define HANDLE_TYPEKIND_CHARACTERDEVICE_KEYBOARD 0x0004 /* The handle refers to a `struct keyboard_device' */
#define HANDLE_TYPEKIND_CHARACTERDEVICE_MOUSE    0x0005 /* The handle refers to a `struct mouse_device' */
/* Handle kinds for `HANDLE_TYPE_PATH' */
#define HANDLE_TYPEKIND_PATH_GENERIC          0x0000 /* The handle refers to a `struct path' */
#define HANDLE_TYPEKIND_PATH_VFSROOT          0x0001 /* The handle refers to a `struct vfs' */


#endif /* !_KOS_KERNEL_HANDLE_H */
