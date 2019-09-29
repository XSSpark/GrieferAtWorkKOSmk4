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


/* @param: files: Space-seperated list of:
 *                  `F(parent_id, name, type, id)'
 *                Terminated by `F_END'
 *                The specified `parent_id' must match the `id' argument
 *                passed to the surrounding `MKDIR()' invocation. */
#ifndef MKDIR
#define MKDIR(id, mode, files)
#endif /* !MKDIR */

#ifndef MKREG_RO
#define MKREG_RO(id, mode, printer)
#endif /* !MKREG_RO */

#ifndef DYNAMIC_SYMLINK
#define DYNAMIC_SYMLINK(id, mode, readlink)
#endif /* !DYNAMIC_SYMLINK */

#ifndef CUSTOM
#define CUSTOM(id, mode, inode_type)
#endif /* !CUSTOM */

#ifndef PERPROC_DIRECTORY_ENTRY
#define PERPROC_DIRECTORY_ENTRY(name, type, id)
#endif /* !PERPROC_DIRECTORY_ENTRY */


PERPROC_DIRECTORY_ENTRY("attr", DT_DIR, attr)
MKDIR(attr, 0333,
      F(attr, "current", DT_REG, attr_current)
      F_END)

MKREG_RO(attr_current, 0666, ProcFS_PerProc_Attr_Current_Printer)

PERPROC_DIRECTORY_ENTRY("exe", DT_LNK, exe)
DYNAMIC_SYMLINK(exe, 0777, ProcFS_PerProc_Exe_Printer)

PERPROC_DIRECTORY_ENTRY("cwd", DT_LNK, cwd)
DYNAMIC_SYMLINK(cwd, 0777, ProcFS_PerProc_Cwd_Printer)

PERPROC_DIRECTORY_ENTRY("root", DT_LNK, root)
DYNAMIC_SYMLINK(root, 0777, ProcFS_PerProc_Root_Printer)

PERPROC_DIRECTORY_ENTRY("cmdline", DT_REG, cmdline)
MKREG_RO(cmdline, 0222, ProcFS_PerProc_Cmdline_Printer)

PERPROC_DIRECTORY_ENTRY("fd", DT_DIR, fd)
CUSTOM(fd, S_IFDIR | 0300, ProcFS_PerProc_Fd_Type)

PERPROC_DIRECTORY_ENTRY("kos", DT_DIR, kos)
MKDIR(kos, 0333,
      F(attr, "drives", DT_DIR, kos_drives)
      F(attr, "dcwd", DT_DIR, kos_dcwd)
      F_END)
CUSTOM(kos_drives, S_IFDIR | 0300, ProcFS_PerProc_Kos_Drives_Type)
CUSTOM(kos_dcwd, S_IFDIR | 0300, ProcFS_PerProc_Kos_DrivesCwd_Type)

//#define PROCFS_PERPROC_NO_CUSTOM 1 /* Delete if we ever get CUSTOM() entries */

#undef PERPROC_DIRECTORY_ENTRY
#undef CUSTOM
#undef DYNAMIC_SYMLINK
#undef MKREG_RO
#undef MKDIR
