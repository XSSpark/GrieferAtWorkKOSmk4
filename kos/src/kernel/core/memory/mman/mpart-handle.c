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
#ifndef GUARD_KERNEL_SRC_MEMORY_MMAN_MPART_HANDLE_C
#define GUARD_KERNEL_SRC_MEMORY_MMAN_MPART_HANDLE_C 1
#define _KOS_SOURCE 1

#include <kernel/compiler.h>

#include <dev/block.h>
#include <fs/node.h>
#include <kernel/aio.h>
#include <kernel/except.h>
#include <kernel/handle-proto.h>
#include <kernel/handle.h>
#include <kernel/iovec.h>
#include <kernel/mman/mpart.h>
#include <kernel/user.h>
#include <sched/cred.h>

#include <hybrid/align.h>
#include <hybrid/atomic.h>

#include <kos/except/reason/inval.h>
#include <kos/hop/mpart.h>
#include <sys/stat.h>

#include <assert.h>
#include <errno.h>
#include <stdint.h> /* SIZE_MAX */
#include <string.h>

DECL_BEGIN

/* Mem-part handle operation. */
DEFINE_HANDLE_REFCNT_FUNCTIONS(mpart, struct mpart);

INTERN NONNULL((1)) REF void *KCALL
handle_mpart_tryas(struct mpart *__restrict self,
                   uintptr_half_t wanted_type) {
	switch (wanted_type) {

	case HANDLE_TYPE_MFILE: {
		REF struct mfile *result;
		mpart_lock_acquire(self);
		result = incref(self->mp_file);
		mpart_lock_release(self);
		return result;
	}	break;

	default:
		break;
	}
	return NULL;
}



//INTERN pos_t KCALL /* TODO: Pre-initialize specified reanges. */
//handle_mpart_allocate(struct     mpart     *__restrict     self,
//                      fallocate_mode_t mode, pos_t start, pos_t length) {
//}

INTERN void KCALL
handle_mpart_sync(struct mpart *__restrict self) {
	mpart_sync(self);
}

DEFINE_INTERN_ALIAS(handle_mpart_datasync, handle_mpart_sync);

INTERN void KCALL
handle_mpart_stat(struct mpart *__restrict self,
                  USER CHECKED struct stat *result) {
	REF struct mfile *file;
	size_t size;
	mpart_lock_acquire(self);
	file = incref(self->mp_file);
	size = mpart_getsize(self);
	mpart_lock_release(self);
	FINALLY_DECREF_UNLIKELY(file);

	if (mfile_isnode(file)) {
		dev_t devno = 0;
		struct fnode *node = (struct fnode *)file;
		struct mfile *dev;
		dev = node->fn_super->fs_dev;
		if (dev && mfile_isdevnode(dev))
			devno = mfile_asdevnode(dev)->dn_devno;

		result->st_dev   = (typeof(result->st_dev))devno;
		result->st_ino   = (typeof(result->st_ino))node->i_fileino;
		result->st_mode  = (typeof(result->st_mode))node->i_filemode;
		result->st_nlink = (typeof(result->st_nlink))node->i_filenlink;
		result->st_uid   = (typeof(result->st_uid))node->i_fileuid;
		result->st_gid   = (typeof(result->st_gid))node->i_filegid;
		result->st_rdev  = (typeof(result->st_rdev))devno;
#ifdef __TIMESPEC64_HAVE_TV_PAD
		/* Don't accidentally leak kernel data! */
		{
			struct timespec temp;
			temp.tv_sec   = node->i_fileatime.tv_sec;
			temp.tv_nsec  = node->i_fileatime.tv_nsec;
			temp.__tv_pad = 0;
			COMPILER_WRITE_BARRIER();
			result->st_atimespec = temp;

			temp.tv_sec   = node->i_filemtime.tv_sec;
			temp.tv_nsec  = node->i_filemtime.tv_nsec;
			temp.__tv_pad = 0;
			COMPILER_WRITE_BARRIER();
			result->st_mtimespec = temp;

			temp.tv_sec   = node->i_filectime.tv_sec;
			temp.tv_nsec  = node->i_filectime.tv_nsec;
			temp.__tv_pad = 0;
			COMPILER_WRITE_BARRIER();
			result->st_ctimespec = temp;
		}
#else /* __TIMESPEC64_HAVE_TV_PAD */
		result->st_atimespec = node->i_fileatime;
		result->st_mtimespec = node->i_filemtime;
		result->st_ctimespec = node->i_filectime;
#endif /* !__TIMESPEC64_HAVE_TV_PAD */
	} else {
		result->st_dev   = 0;
		result->st_ino   = 0;
		result->st_mode  = 0;
		result->st_nlink = 0;
		result->st_uid   = 0;
		result->st_gid   = 0;
		result->st_rdev  = 0;
		memset(&result->st_atimespec, 0, sizeof(result->st_atimespec));
		memset(&result->st_mtimespec, 0, sizeof(result->st_mtimespec));
		memset(&result->st_ctimespec, 0, sizeof(result->st_ctimespec));
	}
	result->st_size    = (__FS_TYPE(pos))size;
	result->st_blksize = (__blksize_t)mfile_getblocksize(file);
	result->st_blocks  = (__FS_TYPE(blkcnt))(size >> file->mf_blockshift);
}

INTERN syscall_slong_t KCALL
handle_mpart_hop(struct mpart *__restrict self, syscall_ulong_t cmd,
                 USER UNCHECKED void *arg, iomode_t mode) {
	switch (cmd) {

	case HOP_MPART_OPEN_DATABLOCK: {
		struct handle hnd;
		cred_require_sysadmin(); /* TODO: More finely grained access! */
		hnd.h_type = HANDLE_TYPE_MFILE;
		hnd.h_mode = mode;
		mpart_lock_acquire(self);
		hnd.h_data = incref(self->mp_file);
		mpart_lock_release(self);
		FINALLY_DECREF_UNLIKELY((struct mfile *)hnd.h_data);
		return handle_installhop((USER UNCHECKED struct hop_openfd *)arg, hnd);
	}	break;

	default:
		THROW(E_INVALID_ARGUMENT_UNKNOWN_COMMAND,
		      E_INVALID_ARGUMENT_CONTEXT_HOP_COMMAND,
		      cmd);
		break;
	}
	return 0;
}


DECL_END

#endif /* !GUARD_KERNEL_SRC_MEMORY_MMAN_MPART_HANDLE_C */
