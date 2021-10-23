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
#ifndef GUARD_MODFAT_FAT_C
#define GUARD_MODFAT_FAT_C 1
#define _KOS_SOURCE        1
#define _GNU_SOURCE        1

#include "fat.h"
/**/

#include <kernel/compiler.h>

#ifdef CONFIG_USE_NEW_FS
#include <kernel/driver-callbacks.h>
#include <kernel/fs/blkdev.h>
#include <kernel/fs/dirent.h>
#include <kernel/fs/dirnode.h>
#include <kernel/fs/filesys.h>
#include <kernel/fs/lnknode.h>
#include <kernel/fs/node.h>
#include <kernel/fs/regnode.h>
#include <kernel/fs/super.h>
#include <kernel/malloc.h>
#include <kernel/mman.h>
#include <kernel/mman/kram.h>
#include <kernel/mman/map.h>
#include <kernel/mman/phys.h>
#include <kernel/printk.h>
#include <sched/task.h>

#include <hybrid/align.h>
#include <hybrid/atomic.h>
#include <hybrid/bit.h>
#include <hybrid/byteorder.h>
#include <hybrid/byteswap.h>
#include <hybrid/overflow.h>

#include <kos/dev.h>
#include <kos/except.h>
#include <linux/magic.h>
#include <sys/stat.h>

#include <alloca.h>
#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <unicode.h>

DECL_BEGIN

#if !defined(NDEBUG) && !defined(NDEBUG_FINI)
#define DBG_memset memset
#else /* !NDEBUG && !NDEBUG_FINI */
#define DBG_memset(...) (void)0
#endif /* NDEBUG || NDEBUG_FINI */

#define FAT_ISSPACE(c) (isspace(c) || iscntrl(c) /* || isblank(c)*/)

/************************************************************************/
/* FAT Timestamp encode/decode functions                                */
/************************************************************************/
#define UNIX_TIME_START_YEAR 1970
#define SECONDS_PER_DAY      86400
#define DAYS2YEARS(n_days)   __daystoyears(n_days)
#define YEARS2DAYS(n_years)  __yearstodays(n_years)
#define ISLEAPYEAR(year)     __isleap(year)

PRIVATE time_t const time_monthstart_yday[2][13] = {
	{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
	{ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
};

#define MONTH_STARTING_DAY_OF_YEAR(leap_year, month) \
	time_monthstart_yday[!!(leap_year)][month]

PRIVATE ATTR_PURE WUNUSED NONNULL((1)) time_t
NOTHROW(FCALL FatFileDate_Decode)(struct fat_filedate const *__restrict self) {
	time_t result;
	unsigned int year;
	year   = self->fd_year + 1980;
	result = YEARS2DAYS(year) - YEARS2DAYS(UNIX_TIME_START_YEAR);
	result += MONTH_STARTING_DAY_OF_YEAR(ISLEAPYEAR(year), (self->fd_month - 1) % 12);
	result += self->fd_day - 1;
	return result * SECONDS_PER_DAY;
}

PRIVATE NONNULL((1)) void
NOTHROW(KCALL FatFileDate_Encode)(struct fat_filedate *__restrict self,
                                  time_t tmt) {
	unsigned int year;
	u8 i;
	time_t const *monthvec;
	tmt /= SECONDS_PER_DAY;
	tmt += YEARS2DAYS(UNIX_TIME_START_YEAR);
	year     = DAYS2YEARS(tmt);
	monthvec = time_monthstart_yday[ISLEAPYEAR(year)];
	tmt -= YEARS2DAYS(year);
	self->fd_year = year > 1980 ? year - 1980 : 0;
	/* Find the appropriate month. */
	for (i = 1; i < 12; ++i)
		if (monthvec[i] >= tmt)
			break;
	self->fd_month = i;
	self->fd_day   = (tmt - monthvec[i - 1]) + 1;
}

PRIVATE ATTR_PURE WUNUSED NONNULL((1)) time_t
NOTHROW(KCALL FatFileTime_Decode)(struct fat_filetime const *__restrict self) {
	return ((time_t)self->ft_hour * 60 * 60) +
	       ((time_t)self->ft_min * 60) +
	       ((time_t)self->ft_sec * 2);
}

PRIVATE NONNULL((1)) void
NOTHROW(KCALL FatFileTime_Encode)(struct fat_filetime *__restrict self,
                                  time_t tmt) {
	self->ft_sec  = (tmt % 60) / 2;
	self->ft_min  = ((tmt / 60) % 60);
	self->ft_hour = ((tmt / (60 * 60)) % 24);
}

PRIVATE NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL FatFileCTime_Encode)(struct fat_filectime *__restrict self,
                                   struct timespec const *__restrict value) {
	FatFileDate_Encode(&self->fc_date, value->tv_sec);
	FatFileTime_Encode(&self->fc_time, value->tv_sec);
	self->fc_sectenth = (u8)(value->tv_nsec / (1000000000ul / 200ul));
}

PRIVATE NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL FatFileCTime_Decode)(struct fat_filectime const *__restrict self,
                                   struct timespec *__restrict result) {
	result->tv_sec  = FatFileDate_Decode(&self->fc_date);
	result->tv_sec += FatFileTime_Decode(&self->fc_time);
	result->tv_nsec = (syscall_ulong_t)self->fc_sectenth * (1000000000ul / 200ul);
}

PRIVATE NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL FatFileMTime_Encode)(struct fat_filemtime *__restrict self,
                                   struct timespec const *__restrict value) {
	FatFileDate_Encode(&self->fc_date, value->tv_sec);
	FatFileTime_Encode(&self->fc_time, value->tv_sec);
}

PRIVATE NOBLOCK NONNULL((1, 2)) void
NOTHROW(FCALL FatFileMTime_Decode)(struct fat_filemtime const *__restrict self,
                                   struct timespec *__restrict result) {
	result->tv_sec = FatFileDate_Decode(&self->fc_date);
	result->tv_sec += FatFileTime_Decode(&self->fc_time);
	result->tv_nsec = 0;
}
#define FatFileATime_Encode(self, value) \
	FatFileDate_Encode(self, (value)->tv_sec)
#define FatFileATime_Decode(self, result) \
	((result)->tv_sec = FatFileDate_Decode(self), (result)->tv_nsec = 0)




/************************************************************************/
/* FAT directory entry helper functions                                 */
/************************************************************************/
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(KCALL fatdirent_v_destroy)(struct fdirent *__restrict self) {
	struct fatdirent *me;
	me = fdirent_asfat(self);
	_fatdirent_free(me);
}
DEFINE_REFCOUNT_FUNCTIONS(struct fatdirent, fad_ent.fde_ent.fd_refcnt, fatdirent_v_destroy)
PRIVATE struct fdirent_ops const fatdirent_ops = {
	.fdo_destroy  = &fatdirent_v_destroy,
	.fdo_opennode = &fflatdirent_v_opennode,
};





/************************************************************************/
/* FAT Cluster helper functions                                         */
/************************************************************************/
PRIVATE WUNUSED NONNULL((1)) FatClusterIndex KCALL
Fat_FindFreeCluster(FatSuperblock *__restrict self) {
	FatClusterIndex result;
	assert(FatSuper_FatLockReading(self));
	result = self->ft_free_pos;
	for (; result < self->ft_cluster_eof; ++result) {
		if (Fat_GetFatIndirection(self, result) == FAT_CLUSTER_UNUSED)
			goto found_one;
	}
	/* Scan everything before our previous location. */
	STATIC_ASSERT(FAT_CLUSTER_UNUSED == 0);
	result = 1; /* 1: Don't allow use of `FAT_CLUSTER_UNUSED' (which is `0') */
	for (; result < self->ft_free_pos; ++result) {
		if (Fat_GetFatIndirection(self, result) == FAT_CLUSTER_UNUSED)
			goto found_one;
	}
	/* Disk is full... */
	THROW(E_FSERROR_DISK_FULL);
found_one:
	self->ft_free_pos = result;
	return result;
}

INTERN NONNULL((1)) void KCALL
Fat_DeleteClusterChain(FatSuperblock *__restrict self,
                       FatClusterIndex first_delete_index) {
	FatSuper_FatLockWrite(self);
	TRY {
		while (first_delete_index < self->ft_cluster_eof &&
		       first_delete_index != FAT_CLUSTER_UNUSED) {
			FatClusterIndex next = Fat_GetFatIndirection(self, first_delete_index);
			Fat_SetFatIndirection(self, first_delete_index, FAT_CLUSTER_UNUSED);
			first_delete_index = next;
		}
	} EXCEPT {
		FatSuper_FatLockEndWrite(self);
		RETHROW();
	}
	FatSuper_FatLockEndWrite(self);
}


PRIVATE NONNULL((1, 2, 3)) void KCALL
preallocate_cluster_vector_entries(struct fnode *__restrict node,
                                   FatNodeData *__restrict data,
                                   FatSuperblock *__restrict fat,
                                   size_t min_num_clusters)
		THROWS(...) {
	size_t new_alloc, old_alloc;
	FatClusterIndex *newvec;
	assert(min_num_clusters >= data->fn_clusterc);
	new_alloc = (size_t)CEILDIV(atomic64_read(&node->mf_filesize), fat->ft_clustersize);
	if (new_alloc < min_num_clusters)
		new_alloc = min_num_clusters;
	if unlikely(new_alloc <= 0)
		new_alloc = 2;
	old_alloc = kmalloc_usable_size(data->fn_clusterv) / sizeof(FatClusterIndex);
	assert(old_alloc >= 1);
	if unlikely(new_alloc <= old_alloc)
		return; /* nothing to do here... */
	newvec = (FatClusterIndex *)krealloc_nx(data->fn_clusterv,
	                                        new_alloc * sizeof(FatClusterIndex),
	                                        GFP_NORMAL);
	if (!newvec) {
		new_alloc = min_num_clusters;
		if unlikely(new_alloc <= 0)
			new_alloc = 2;
		if unlikely(new_alloc <= old_alloc)
			return; /* nothing to do here... */
		newvec = (FatClusterIndex *)krealloc(data->fn_clusterv,
		                                     new_alloc * sizeof(FatClusterIndex),
		                                     GFP_NORMAL);
	}
	data->fn_clusterv = newvec;
}

LOCAL NONNULL((1)) void KCALL
zero_initialize_cluster(FatSuperblock *__restrict fat,
                        FatClusterIndex cluster)
		THROWS(...) {
	/* XXX: Implement me? */
	(void)fat;
	(void)cluster;
}


/* Flags for `Fat_GetFileCluster::mode' */
#define FAT_GETCLUSTER_MODE_FNORMAL 0x0000 /* If that cluster hasn't been  loaded yet, load it now.  If
                                            * the cluster doesn't exist, return `ft_cluster_eof_marker' */
#define FAT_GETCLUSTER_MODE_FCREATE 0x0001 /* Allocate missing clusters. */
#define FAT_GETCLUSTER_MODE_FNCHNGE 0x0002 /* Don't mark the node as changed if the initial cluster was allocated. */
#define FAT_GETCLUSTER_MODE_WRLOCK  0x0004 /* Caller is holding a write-lock to `self->fn_fsdata->fn_lock' */

/* Special return value for `Fat_GetFileCluster()' */
#define FAT_GETFILECLUSTER_NEED_WRLOCK FAT_CLUSTER_UNUSED

/* Returns the cluster index of the `nth_cluster' cluster that is allocated for `self'.
 * NOTE: The caller must be holding at least a read-lock to `self->fn_fsdata->fn_lock'
 * @param: mode: Set of `FAT_GETCLUSTER_MODE_F*'
 * @return: * : The value of the `nth_cluster' cluster.
 * @return: FAT_GETFILECLUSTER_NEED_WRLOCK: `FAT_GETCLUSTER_MODE_WRLOCK' isn't  given,
 *                                          and  a read-lock could  not be upgraded to
 *                                          a write-lock. - Release read-lock and wait
 *                                          for write to become available. Then retry. */
PRIVATE NONNULL((1)) FatClusterIndex KCALL
Fat_GetFileCluster(struct fnode *__restrict self,
                   size_t nth_cluster, unsigned int mode) {
	FatClusterIndex result;
	FatNodeData *dat     = self->fn_fsdata;
	FatSuperblock *super = fsuper_asfat(self->fn_super);
	assert(FatNodeData_Reading(dat));
	assert(dat->fn_clusterc != 0);
	if (nth_cluster < dat->fn_clusterc) {
		result = dat->fn_clusterv[nth_cluster];
		assert(result != FAT_CLUSTER_UNUSED);
		if (result < super->ft_cluster_eof)
			return result; /* Simple case: cluster already cached. */
		assert(nth_cluster == dat->fn_clusterc - 1);
	} else {
		result = dat->fn_clusterv[dat->fn_clusterc - 1];
		assert(result != FAT_CLUSTER_UNUSED);
		if (result < super->ft_cluster_eof) {
			/* Not all clusters have been loaded, yet. -> load more now. */
			if (!(mode & FAT_GETCLUSTER_MODE_WRLOCK)) {
				if (!FatNodeData_TryUpgrade(dat))
					return FAT_GETFILECLUSTER_NEED_WRLOCK;
			}
			TRY {
				preallocate_cluster_vector_entries(self, dat, super, nth_cluster + 1);
				for (;;) {
					result = Fat_GetFatIndirection(super, result);
					if unlikely(result == FAT_CLUSTER_UNUSED)
						THROW(E_FSERROR_CORRUPTED_FILE_SYSTEM);
					dat->fn_clusterv[dat->fn_clusterc] = result;
					++dat->fn_clusterc;
					if (result >= super->ft_cluster_eof) {
						FatClusterIndex *new_vector;
						/* EOF reached before `nth_cluster' */
						if (mode & FAT_GETCLUSTER_MODE_FCREATE)
							goto create_more_clusters_already_locked;
						/* Try to free unused memory. */
						new_vector = (FatClusterIndex *)krealloc_nx(dat->fn_clusterv,
						                                            dat->fn_clusterc * sizeof(FatClusterIndex),
						                                            GFP_NORMAL);
						if likely(new_vector)
							dat->fn_clusterv = new_vector;
						if (!(mode & FAT_GETCLUSTER_MODE_WRLOCK))
							FatNodeData_Downgrade(dat);
						return result;
					}
					if (nth_cluster < dat->fn_clusterc) {
						/* The requested cluster was reached */
						assert(nth_cluster == dat->fn_clusterc - 1);
						assert(result == dat->fn_clusterv[nth_cluster]);
						assert(result != FAT_CLUSTER_UNUSED);
						break;
					}
				}
			} EXCEPT {
				if (!(mode & FAT_GETCLUSTER_MODE_WRLOCK))
					FatNodeData_Downgrade(dat);
				RETHROW();
			}
			if (!(mode & FAT_GETCLUSTER_MODE_WRLOCK))
				FatNodeData_Downgrade(dat);
			return result;
		}
	}

	/* All clusters are loaded, and the file potentially needs to be expanded. */
	assert(dat->fn_clusterv[dat->fn_clusterc - 1] >= super->ft_cluster_eof);
	if (!(mode & FAT_GETCLUSTER_MODE_FCREATE))
		return super->ft_cluster_eof_marker; /* EOF */

	/* Not all clusters have been loaded, yet. -> load more now. */
	if (!(mode & FAT_GETCLUSTER_MODE_WRLOCK)) {
		if (!FatNodeData_TryUpgrade(dat))
			return FAT_GETFILECLUSTER_NEED_WRLOCK;
	}
create_more_clusters_already_locked:
	TRY {
		preallocate_cluster_vector_entries(self, dat, super, nth_cluster + 1);
		FatSuper_FatLockWrite(super);
		TRY {
			assert(dat->fn_clusterv[dat->fn_clusterc - 1] >= super->ft_cluster_eof);
			assert((kmalloc_usable_size(dat->fn_clusterv) / sizeof(FatClusterIndex)) >= nth_cluster + 1);
			/* Create more clusters. */
			for (;;) {
				result = Fat_FindFreeCluster(super);
				assert(result != FAT_CLUSTER_UNUSED);
				/* Mark the new cluster as allocated. */
				Fat_SetFatIndirection(super, result,
				                      super->ft_cluster_eof_marker);
				TRY {
					/* Initialize new clusters with all zeroes for new files. */
					if (fnode_isreg(self))
						zero_initialize_cluster(super, result);
					assert(super->ft_cluster_eof_marker != FAT_CLUSTER_UNUSED);
					dat->fn_clusterv[dat->fn_clusterc - 1] = result;
					dat->fn_clusterv[dat->fn_clusterc] = super->ft_cluster_eof_marker;
					++dat->fn_clusterc;
					TRY {
						if (dat->fn_clusterc == 2) {
							/* The pointer  to  the  first  cluster is  stored  in  the  INode.
							 * Since we've just written that pointer, mark the node as changed. */
							if (!(mode & FAT_GETCLUSTER_MODE_FNCHNGE))
								mfile_changed(self, MFILE_F_ATTRCHANGED);
						} else {
							/* Link the previous cluster onto the new one */
							assert(dat->fn_clusterc >= 3);
							/* -3: PREV_CLUSTER */
							/* -2: THIS_CLUSTER */
							/* -1: fat->ft_cluster_eof_marker */
							Fat_SetFatIndirection(super,
							                      dat->fn_clusterv[dat->fn_clusterc - 3],
							                      result);
						}
					} EXCEPT {
						--dat->fn_clusterc;
						assert(dat->fn_clusterv[dat->fn_clusterc - 1] == result);
						assert(super->ft_cluster_eof_marker != FAT_CLUSTER_UNUSED);
						dat->fn_clusterv[dat->fn_clusterc - 1] = super->ft_cluster_eof_marker;
						RETHROW();
					}
				} EXCEPT {
					/* Free the new cluster on error. */
					{
						NESTED_EXCEPTION;
						Fat_SetFatIndirection(super, result, FAT_CLUSTER_UNUSED);
					}
					RETHROW();
				}
				if (nth_cluster < dat->fn_clusterc - 1) {
					/* The requested cluster was reached */
					assert(nth_cluster == dat->fn_clusterc - 2);
					assert(result == dat->fn_clusterv[nth_cluster]);
					break;
				}
			}
		} EXCEPT {
			FatSuper_FatLockEndWrite(super);
			RETHROW();
		}
		FatSuper_FatLockEndWrite(super);
	} EXCEPT {
		if (!(mode & FAT_GETCLUSTER_MODE_WRLOCK))
			FatNodeData_Downgrade(dat);
		RETHROW();
	}
	assert(result == dat->fn_clusterv[nth_cluster]);
	assert(result < super->ft_cluster_eof);
	assert(result != FAT_CLUSTER_UNUSED);
	sync_endwrite(&super->ft_fat_lock);
	if (!(mode & FAT_GETCLUSTER_MODE_WRLOCK))
		FatNodeData_Downgrade(dat);
	return result;
}



/* Returns the absolute on-disk (read: on-partition) position of `pos' in `self'
 * Caller  must be  holding at  least a  read-lock to `self->fn_fsdata->fn_lock'
 * @return: 0 : s.a. `FAT_GETFILECLUSTER_NEED_WRLOCK' */
PRIVATE NONNULL((1)) pos_t KCALL
Fat_GetAbsDiskPosWithClusters(struct fnode *__restrict self, pos_t pos,
                              unsigned int mode = FAT_GETCLUSTER_MODE_FCREATE) THROWS(...) {
	pos_t diskpos;
	FatSuperblock *super = fsuper_asfat(self->fn_super);
	FatClusterIndex cluster;
	size_t cluster_number = (size_t)(pos / super->ft_clustersize);
	size_t cluster_offset = (size_t)(pos % super->ft_clustersize);
	cluster = Fat_GetFileCluster(self, cluster_number, mode);
	if (cluster == FAT_GETFILECLUSTER_NEED_WRLOCK)
		return 0;
	diskpos = FAT_CLUSTERADDR(super, cluster);
	diskpos += cluster_offset;
	return diskpos;
}
#define fnode_has_fat_clusters(self) \
	(!fnode_issuper(self) || fnode_asfatsup(self)->ft_type == FAT32)
#define Fat_GetAbsDiskPosWithoutFatClusters(self, pos) \
	((pos) + fnode_asfatsup(self)->ft_fdat.fn16_root.r16_rootpos)

PRIVATE NONNULL((1)) pos_t KCALL
Fat_GetAbsDiskPos(struct fnode *__restrict self, pos_t pos,
                  unsigned int mode = FAT_GETCLUSTER_MODE_FCREATE) THROWS(...) {
	if (fnode_has_fat_clusters(self))
		return Fat_GetAbsDiskPosWithClusters(self, pos, mode);
	return Fat_GetAbsDiskPosWithoutFatClusters(self, pos);
}





/************************************************************************/
/* FAT operator implementations.                                        */
/************************************************************************/
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL FatNodeData_Fini)(FatNodeData *__restrict self) {
	xdecref(self->fn_ent);
	xdecref(self->fn_dir);
	kfree(self->fn_clusterv);
}

PRIVATE NONNULL((1, 5)) void KCALL
Fat_LoadBlocks(struct mfile *__restrict self, pos_t addr,
               physaddr_t buf, size_t num_bytes,
               struct aio_multihandle *__restrict aio) {
	struct fnode *me     = mfile_asnode(self);
	FatNodeData *dat     = me->fn_fsdata;
	FatSuperblock *super = fsuper_asfat(me->fn_super);
	struct blkdev *dev   = super->ft_super.ffs_super.fs_dev;
	if unlikely(!num_bytes)
		return;
again:
	FatNodeData_Read(dat);
	TRY {
		for (;;) {
			FatClusterIndex cluster;
			pos_t diskpos;
			size_t cluster_number = (size_t)(addr / super->ft_clustersize);
			size_t cluster_offset = (size_t)(addr % super->ft_clustersize);
			size_t max_io;
			cluster = Fat_GetFileCluster(me, cluster_number, FAT_GETCLUSTER_MODE_FNORMAL);
			if unlikely(cluster == FAT_GETFILECLUSTER_NEED_WRLOCK)
				goto waitfor_write_lock;
			if (cluster >= super->ft_cluster_eof) {
				/* Read all ZEROes after EOF. */
				memsetphys(buf, 0, num_bytes);
				return;
			}
			diskpos = FAT_CLUSTERADDR(super, cluster);
			diskpos += cluster_offset;
			max_io = super->ft_clustersize - cluster_offset;
			/* Optimization: When reading  large amounts  of data,  check if  the
			 *               underlying disk chunks were allocated consecutively.
			 *               If they were, then we  can simply do one  continuous
			 *               read, processing more  than one cluster  at a  time. */
			while (max_io < num_bytes) {
				FatClusterIndex next_cluster;
				next_cluster = Fat_GetFileCluster(me, cluster_number + 1, FAT_GETCLUSTER_MODE_FNORMAL);
				if (next_cluster != cluster + 1) {
					if unlikely(next_cluster == FAT_GETFILECLUSTER_NEED_WRLOCK)
						goto waitfor_write_lock;
					break;
				}
				max_io += super->ft_clustersize;
				++cluster_number;
				++cluster;
			}
			if (max_io > num_bytes)
				max_io = num_bytes;
			if likely(dev->mf_blockshift <= super->ft_sectorshift) {
				/* Can use unbuffered I/O */
				blkdev_rdsectors_async(dev, diskpos, buf, max_io, aio);
			} else {
				/* Have to use buffered I/O */
				mfile_readall_p(dev, buf, max_io, diskpos);
			}
			if (max_io >= num_bytes)
				break;
			num_bytes -= max_io;
			addr += max_io;
			buf += max_io;
		}
	} EXCEPT {
		FatNodeData_EndRead(dat);
		RETHROW();
	}
	FatNodeData_EndRead(dat);
	return;
waitfor_write_lock:
	FatNodeData_EndRead(dat);
	FatNodeData_Write(dat);
	FatNodeData_EndWrite(dat);
	goto again;
}

PRIVATE NONNULL((1, 5)) void KCALL
Fat_SaveBlocks(struct mfile *__restrict self, pos_t addr,
               physaddr_t buf, size_t num_bytes,
               struct aio_multihandle *__restrict aio) {
	struct fnode *me     = mfile_asnode(self);
	FatNodeData *dat     = me->fn_fsdata;
	FatSuperblock *super = fsuper_asfat(me->fn_super);
	struct blkdev *dev   = super->ft_super.ffs_super.fs_dev;
	if unlikely(!num_bytes)
		return;
again:
	/* Yes: We only need a read-lock  here since this lock isn't  used
	 *      to guard the actual file-contents, but only the vector  of
	 *      cluster indices (if said vector needs to be modified, this
	 *      lock is later upgraded as necessary) */
	FatNodeData_Read(dat);
	TRY {
		for (;;) {
			FatClusterIndex cluster;
			pos_t diskpos;
			size_t cluster_number = (size_t)(addr / super->ft_clustersize);
			size_t cluster_offset = (size_t)(addr % super->ft_clustersize);
			size_t max_io;
			cluster = Fat_GetFileCluster(me, cluster_number, FAT_GETCLUSTER_MODE_FCREATE);
			if unlikely(cluster == FAT_GETFILECLUSTER_NEED_WRLOCK)
				goto waitfor_write_lock;
			diskpos = FAT_CLUSTERADDR(super, cluster);
			diskpos += cluster_offset;
			max_io = super->ft_clustersize - cluster_offset;
			/* Optimization: When reading  large amounts  of data,  check if  the
			 *               underlying disk chunks were allocated consecutively.
			 *               If they were, then we  can simply do one  continuous
			 *               read, processing more  than one cluster  at a  time. */
			while (max_io < num_bytes) {
				FatClusterIndex next_cluster;
				next_cluster = Fat_GetFileCluster(me, cluster_number + 1, FAT_GETCLUSTER_MODE_FCREATE);
				if (next_cluster != cluster + 1) {
					if unlikely(next_cluster == FAT_GETFILECLUSTER_NEED_WRLOCK)
						goto waitfor_write_lock;
					break;
				}
				max_io += super->ft_clustersize;
				++cluster_number;
				++cluster;
			}
			if (max_io > num_bytes)
				max_io = num_bytes;
			if likely(dev->mf_blockshift <= super->ft_sectorshift) {
				/* Can use unbuffered I/O */
				blkdev_wrsectors_async(dev, diskpos, buf, max_io, aio);
			} else {
				/* Have to use buffered I/O */
				mfile_write_p(dev, buf, max_io, diskpos);
			}
			if (max_io >= num_bytes)
				break;
			num_bytes -= max_io;
			addr += max_io;
			buf += max_io;
		}
	} EXCEPT {
		FatNodeData_EndRead(dat);
		RETHROW();
	}
	FatNodeData_EndRead(dat);
	return;
waitfor_write_lock:
	FatNodeData_EndRead(dat);
	FatNodeData_Write(dat);
	FatNodeData_EndWrite(dat);
	goto again;
}

PRIVATE NONNULL((1)) void KCALL
Fat_WrAttr(struct fnode *__restrict self)
		THROWS(E_IOERROR, ...) {
	FatNodeData *dat     = self->fn_fsdata;
	FatSuperblock *super = fsuper_asfat(self->fn_super);
	REF struct fatdirent *ent;
	REF FatDirNode *dir;
again:
	mfile_tslock_acquire(self);
	assert(dat->fn_ent && dat->fn_dir);
	dir = dat->fn_dir;
	ent = dat->fn_ent;
	incref(dir);
	incref(ent);
	mfile_tslock_release(self);
	FINALLY_DECREF_UNLIKELY(dir);
	FINALLY_DECREF_UNLIKELY(ent);

	/* Acquire a lock to the directory stream buffer. */
	fflatdirnode_write(dir);
	TRY {
		if likely(!fflatdirent_wasdeleted(&ent->fad_ent)) {
			FatClusterIndex first_cluster;
			mode_t fmode;
			struct timespec atm, mtm, ctm;
			gid_t gid;
			uid_t uid;

			/* Load file attributes */
			mfile_tslock_acquire(self);
			fmode = self->fn_mode;
			atm   = self->mf_atime;
			mtm   = self->mf_mtime;
			ctm   = self->mf_ctime;
			gid   = self->fn_gid;
			uid   = self->fn_uid;
			mfile_tslock_release(self);

			/* Check if loaded attributes are valid */
			if unlikely(ATOMIC_READ(self->mf_flags) & MFILE_F_DELETED)
				goto endwrite_and_return;

			/* Update the contents of `ent->fad_dos' */
			first_cluster = dat->fn_clusterv[0];

			/* Copy basic file data. */
			ent->fad_dos.f_clusterlo = HTOLE16(first_cluster & 0xffff);
			if (super->ft_features & FAT_FEATURE_ARB) {
				u16 arb = 0;
				/* Use the ARB to implement unix file permissions. */
				if (!(fmode & S_IXUSR))
					arb |= FAT_ARB_NO_OX; /* Disable: Execute by owner */
				if (!(fmode & S_IWUSR))
					arb |= FAT_ARB_NO_OW; /* Disable: Write by owner */
				if (!(fmode & S_IRUSR))
					arb |= FAT_ARB_NO_OR; /* Disable: Read by owner */

				if (!(fmode & S_IXGRP))
					arb |= FAT_ARB_NO_GX; /* Disable: Execute by group */
				if (!(fmode & S_IWGRP))
					arb |= FAT_ARB_NO_GW; /* Disable: Write by group */
				if (!(fmode & S_IRGRP))
					arb |= FAT_ARB_NO_GR; /* Disable: Read by group */

				if (!(fmode & S_IXOTH))
					arb |= FAT_ARB_NO_WX; /* Disable: Execute by world */
				if (!(fmode & S_IWOTH))
					arb |= FAT_ARB_NO_WW; /* Disable: Write by world */
				if (!(fmode & S_IROTH))
					arb |= FAT_ARB_NO_WR; /* Disable: Read by world */
				if (!(fmode & 0222)) {
					/* Preserve ARB flags  for write permissions  if those  can
					 * already be represented through use of the READONLY flag. */
					arb &= ~(FAT_ARB_NO_OW | FAT_ARB_NO_GW | FAT_ARB_NO_WW);
					arb |= LETOH16(ent->fad_dos.f_arb) & (FAT_ARB_NO_OW | FAT_ARB_NO_GW | FAT_ARB_NO_WW);
				}
				ent->fad_dos.f_arb = HTOLE16(arb);
			} else {
				/* 32-bit clusters */
				ent->fad_dos.f_clusterhi = HTOLE16((u16)(first_cluster >> 16));
			}
			ent->fad_dos.f_size = HTOLE32((u32)atomic64_read(&self->mf_filesize));
			/* Implement the read-only attribute. */
			if (!(fmode & 0222))
				ent->fad_dos.f_attr |= FAT_ATTR_READONLY;

			if (super->ft_features & FAT_FEATURE_UGID) {
				/* UID/GID support */
				ent->fad_dos.f_uid = (u8)uid;
				ent->fad_dos.f_gid = (u8)gid;
			} else {
				/* Last-access timestamp support */
				FatFileATime_Encode(&ent->fad_dos.f_atime, &atm);
			}

			/* Convert timestamps. */
			FatFileMTime_Encode(&ent->fad_dos.f_mtime, &mtm);
			FatFileCTime_Encode(&ent->fad_dos.f_ctime, &ctm);

			/* Set the ARCHIVE flag to indicate a file that has been modified. */
			ent->fad_dos.f_attr |= FAT_ATTR_ARCHIVE;

			/* Write `ent->fad_dos' back into the directory stream. */
			mfile_write(dir, &ent->fad_dos, sizeof(struct fat_dirent),
			            fatdirent_dosaddr(ent));
		}
	} EXCEPT {
		fflatdirnode_endwrite(dir);
		RETHROW();
	}
endwrite_and_return:
	fflatdirnode_endwrite(dir);
}


PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(KCALL FatReg_Destroy)(struct mfile *__restrict self) {
	FatRegNode *me = mfile_asfatreg(self);
	FatNodeData_Fini(&me->frn_fdat);
	fflatdirnode_v_destroy(self);
}

PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(KCALL FatDir_Destroy)(struct mfile *__restrict self) {
	FatDirNode *me = mfile_asfatdir(self);
	FatNodeData_Fini(&me->fdn_fdat);
	fflatdirnode_v_destroy(self);
}

#ifdef CONFIG_FAT_CYGWIN_SYMLINKS
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(KCALL FatLnk_Destroy)(struct mfile *__restrict self) {
	FatLnkNode *me = mfile_asfatlnk(self);
	FatNodeData_Fini(&me->fln_fdat);
	fflatdirnode_v_destroy(self);
}

PRIVATE byte_t const Fat_CygwinSymlinkMagic[] = { '!', '<', 's', 'y', 'm', 'l', 'i', 'n', 'k', '>' };

/* Minimum size requirement for symbolic links. */
#define FAT_SYMLINK_FILE_TEXTOFF          (sizeof(Fat_CygwinSymlinkMagic))
#define FAT_SYMLINK_FILE_MINSIZE          (sizeof(Fat_CygwinSymlinkMagic) + 1)
#define FAT_SYMLINK_FILE_TEXTLEN(filesiz) ((filesiz) - FAT_SYMLINK_FILE_MINSIZE)

PRIVATE WUNUSED NONNULL((1)) size_t KCALL
FatLnk_ReadLink(struct flnknode *__restrict self,
                USER CHECKED /*utf-8*/ char *buf,
                size_t bufsize)
		THROWS(E_SEGFAULT, E_IOERROR, ...) {
	size_t result;
	FatLnkNode *me = flnknode_asfat(self);
	result = (size_t)__atomic64_val(self->mf_filesize);
	assert(result >= FAT_SYMLINK_FILE_MINSIZE);
	result = FAT_SYMLINK_FILE_TEXTLEN(result);
	if (bufsize > result)
		bufsize = result;
	/* Read file contents */
	mfile_readall(self, buf, bufsize, (pos_t)FAT_SYMLINK_FILE_TEXTOFF);
	return result;
}

PRIVATE NONNULL((1)) void KCALL
FatLnk_Stat(struct mfile *__restrict self,
            USER CHECKED struct stat *result)
		THROWS(...) {
	FatLnkNode *me  = flnknode_asfat(self);
	result->st_size = __atomic64_val(me->mf_filesize) -
	                  (sizeof(Fat_CygwinSymlinkMagic) + 1);
}
#endif /* CONFIG_FAT_CYGWIN_SYMLINKS */

PRIVATE NONNULL((1)) void
NOTHROW(FCALL strlwrz)(char *__restrict str, size_t len) {
	size_t i;
	for (i = 0; i < len; ++i)
		str[i] = tolower(str[i]);
}

PRIVATE u8 const dos8dot3_valid[256 / 8] = {
/*[[[deemon
import * from deemon;
function is_valid(ch) {
	if (ch <= 31 || ch == 127)
		return false;
	return string.chr(ch) !in "\"*+,/:;<=>?\\[]|.";
}
local valid_chars = [false] * 256;
for (local x: [:256])
	valid_chars[x] = is_valid(x);
local valid_bits = [0] * (256 / 8);
for (local x: [:256/8]) {
	local mask = 0;
	for (local y: [:8]) {
		if (valid_chars[x*8+y])
			mask = mask | (1 << y);
	}
	valid_bits[x] = mask;
}
for (local x: [:256/8]) {
	if ((x % 8) == 0)
		print("\t"),;
	print("0x%.2I8x," % valid_bits[x]),;
	if ((x % 8) == 7)
		print;
	else {
		print(" "),;
	}
}
]]]*/
	0x00, 0x00, 0x00, 0x00, 0xfb, 0x23, 0xff, 0x03,
	0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xff, 0x6f,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/*[[[end]]]*/
};
#define dos8dot3_chok(ch) \
	(dos8dot3_valid[((u8)(ch)) / 8] & (1 << (((u8)(ch)) % 8)))


/* Check if the given string is a valid DOS 8.3 filename. */
PRIVATE NONNULL((1)) bool
NOTHROW(FCALL dos8dot3_dirent_strok)(char const *__restrict str, size_t len) {
	size_t i;
	for (i = 0; i < len; ++i) {
		char ch = str[i];
		if (!dos8dot3_chok(ch) && ch != '.')
			return false;
	}
	return true;
}


PRIVATE WUNUSED struct fflatdirent *KCALL
FatDir_ReadDir(struct fflatdirnode *__restrict self, pos_t pos)
		THROWS(E_BADALLOC, E_IOERROR) {
	struct fatdirent *result;
	struct fat_dirent ent;
	FatDirNode *me = fflatdirnode_asfat(self);
	assert((pos % sizeof(struct fat_dirent)) == 0);

	/* Read the next entry from disk. */
readnext:
	mfile_readall(self, &ent, sizeof(struct fat_dirent), pos);

	/* Check for special markers. */
	if (ent.f_marker == MARKER_DIREND)
		return NULL; /* End of directory */
	if (ent.f_marker == MARKER_UNUSED) {
		pos += sizeof(struct fat_dirent);
		goto readnext;
	}

	/* Check for LFN entries. */
	if (ent.f_attr == FAT_ATTR_LONGFILENAME) {
		char lfn_name[LFN_SEQNUM_MAXCOUNT * UNICODE_16TO8_MAXBUF(LFN_NAME)];
		u32 lfn_valid   = 0;
		pos_t lfn_start = pos;
		pos += sizeof(struct fat_dirent);
		do {
			unsigned int index = (ent.lfn_seqnum & 0x1f) - 1;
			char *dst = lfn_name + index * UNICODE_16TO8_MAXBUF(LFN_NAME);
			char *end = dst + UNICODE_16TO8_MAXBUF(LFN_NAME);
			char16_t *textend;
			lfn_valid |= 1 << index;
#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
			{
				unsigned int i;
				for (i = 0; i < LFN_NAME1; ++i)
					ent.lfn_name_1[i] = HTOLE16((u16)ent.lfn_name_1[i]);
				for (i = 0; i < LFN_NAME2; ++i)
					ent.lfn_name_2[i] = HTOLE16((u16)ent.lfn_name_2[i]);
				for (i = 0; i < LFN_NAME3; ++i)
					ent.lfn_name_3[i] = HTOLE16((u16)ent.lfn_name_3[i]);
			}
#endif /* __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__ */
			textend = (char16_t *)memchrw(ent.lfn_name_1, 0xffff, LFN_NAME1);
			if (textend) {
				dst = unicode_16to8(dst, (char16_t *)ent.lfn_name_1,
				                    textend - (char16_t *)ent.lfn_name_1);
			} else {
				dst     = unicode_16to8(dst, (char16_t *)ent.lfn_name_1, LFN_NAME1);
				textend = (char16_t *)memchrw(ent.lfn_name_2, 0xffff, LFN_NAME2);
				if (textend) {
					dst = unicode_16to8(dst, (char16_t *)ent.lfn_name_2,
					                    textend - (char16_t *)ent.lfn_name_2);
				} else {
					dst = unicode_16to8(dst, (char16_t *)ent.lfn_name_2, LFN_NAME2);
					dst = unicode_16to8(dst, (char16_t *)ent.lfn_name_3,
					                    memlenw(ent.lfn_name_3, 0xffff, LFN_NAME3));
				}
			}
			assert(dst <= end);
			memset(dst, 0, (size_t)(end - dst));
			do {
				mfile_readall(self, &ent, sizeof(struct fat_dirent), pos);
				pos += sizeof(struct fat_dirent);
			} while (ent.f_marker == MARKER_UNUSED);

			/* This really shouldn't  happen, but also  deal
			 * with end-of-directory inside of LFN sequence. */
			if unlikely(ent.f_marker == MARKER_DIREND)
				return NULL;
		} while (ent.f_attr == FAT_ATTR_LONGFILENAME);

		if unlikely(lfn_valid & (lfn_valid + 1)) {
			/* `lfn_valid' isn't  a complete  mask.  (some part  of  the
			 * name might have been corrupted, or accidentally deleted?)
			 * Anyways: don't raise hell about this one and just  delete
			 *          the string portions that were affected (that way
			 *          we  at  least preserve  whatever portion  of the
			 *          filename can still be recovered) */
			unsigned int index = 0;
			u32 mask;
			while ((mask = 1 << index, lfn_valid >= mask)) {
				if (lfn_valid & mask) {
					++index;
					continue;
				}
				memmovedown(lfn_name, lfn_name + UNICODE_16TO8_MAXBUF(LFN_NAME),
				            (size_t)(LFN_SEQNUM_MAXCOUNT - 1) - index,
				            UNICODE_16TO8_MAXBUF(LFN_NAME) * sizeof(char));
				lfn_valid |= mask;
				lfn_valid >>= 1;
			}
		}
		/* Merge LFN filename segments. */
		{
			char *dst, *src, *end;
			size_t len;
			dst = src = lfn_name;
			end = src + POPCOUNT(lfn_valid) * UNICODE_16TO8_MAXBUF(LFN_NAME);
			for (; src < end;) {
				size_t off = strnlen(src, (size_t)(end - src));
				if (dst != src)
					memcpy(dst, src, off, sizeof(char));
				dst += off;
				/* Skip ahead to the next segment. */
				off += (size_t)(src - lfn_name);
				off += UNICODE_16TO8_MAXBUF(LFN_NAME) - 1;
				off = off - (off % UNICODE_16TO8_MAXBUF(LFN_NAME));
				src = lfn_name + off;
			}

			/* Safety check: if the LFN filename ends up empty, use the 8.3 name instead! */
			if unlikely(dst <= lfn_name)
				goto dos_8dot3;

			/* Allocate the directory entry. */
			len    = (size_t)(dst - lfn_name);
			result = _fatdirent_alloc(len);
			result->fad_ent.fde_ent.fd_namelen = (u16)len;
			*(char *)mempcpy(result->fad_ent.fde_ent.fd_name, lfn_name, len, sizeof(char)) = '\0';
			result->fad_ent.fde_pos  = lfn_start;
			result->fad_ent.fde_size = (size_t)(pos - lfn_start);
		}

		/* Use the position of the DOS file entry as INode number. */
		pos -= sizeof(struct fat_dirent);
	} else {
		uint8_t usedname_len;
		char usedname[13], *dstptr;
		char fixedname[11], *srcptr;
dos_8dot3:
		memcpy(fixedname, ent.f_nameext, 11);

		/* Fix lowercase filenames. */
		if (ent.f_ntflags & NTFLAG_LOWBASE)
			strlwrz(fixedname, 8);
		if (ent.f_ntflags & NTFLAG_LOWEXT)
			strlwrz(fixedname + 8, 3);
		/* Deal with this one... */
		if unlikely(ent.f_marker == MARKER_IS0XE5)
			fixedname[0] = 0xe5;

		/* Construct the proper, human-readable filename. */
		dstptr = usedname;
		srcptr = fixedname;
		while (srcptr < fixedname + 8 && isspace(*srcptr))
			++srcptr;
		dstptr = (char *)mempcpy(dstptr, srcptr,
		                         (size_t)((fixedname + 8) - srcptr),
		                         sizeof(char));
		while (dstptr > usedname && isspace(dstptr[-1]))
			--dstptr;
		*dstptr++ = '.';
		srcptr = fixedname + 8;
		while (srcptr < fixedname + 11 && isspace(*srcptr))
			++srcptr;
		dstptr = (char *)mempcpy(dstptr, srcptr,
		                         (size_t)((fixedname + 11) - srcptr),
		                         sizeof(char));
		while (dstptr > usedname && isspace(dstptr[-1]))
			--dstptr;
		if (dstptr > usedname && dstptr[-1] == '.')
			--dstptr;
		*dstptr = 0;
		usedname_len = (uint8_t)(dstptr - usedname);

		/* Make sure there aren't any illegal characters */
		if unlikely(!dos8dot3_dirent_strok(usedname, usedname_len)) {
			printk(KERN_ERR "[fat] Illegal character in filename %$q (skipping entry)\n",
			       (size_t)usedname_len, usedname);
			goto readnext;
		}

		/* Check for entries that we're _supposed_ to skip over. */
		if (usedname_len <= 2) {
			if unlikely(!usedname_len) {
				/* Empty name? (well... this shouldn't happen!) */
				printk(KERN_ERR "[fat] Unnamed directory entry at "
				                "ino:%#" PRIxN(__SIZEOF_INO_T__) ","
				                "off=%" PRIuN(__SIZEOF_POS_T__) "\n",
				       self->fn_ino, pos - sizeof(struct fat_dirent));
				goto readnext;
			}
			if (usedname[0] == '.') {
				/* The kernel implements these itself, so
				 * we don't actually  want to emit  them! */

				/* XXX: Remember the address of special entries? (so `FatDir_WriteDir' can avoid them?) */
				if (usedname_len == 1)
					goto readnext; /* Directory-self-reference. */
				if (usedname[1] == '.')
					goto readnext; /* Directory-parent-reference. */
			}
		}

		/* Create a short-directory entry. */
		result = _fatdirent_alloc(usedname_len);

		/* Fill in remaining. */
		result->fad_ent.fde_ent.fd_ops  = &fatdirent_ops;
		memcpy(result->fad_ent.fde_ent.fd_name, usedname, usedname_len + 1, sizeof(char));
		result->fad_ent.fde_ent.fd_namelen = usedname_len;
		result->fad_ent.fde_pos  = pos;
		result->fad_ent.fde_size = sizeof(struct fat_dirent);
	}

	/* Use the absolute on-disk position of the file's struct fat_dirent as INode number. */
	TRY {
		result->fad_ent.fde_ent.fd_ino = (ino_t)Fat_GetAbsDiskPos(self, pos);
	} EXCEPT {
		_fatdirent_free(result);
		RETHROW();
	}

	/* Fill in generic fields. */
	result->fad_ent.fde_ent.fd_ops = &fatdirent_ops;
	memcpy(&result->fad_dos, &ent, sizeof(struct fat_dirent));
	if (ent.f_attr & FAT_ATTR_DIRECTORY) {
		result->fad_ent.fde_ent.fd_type = DT_DIR;
	} else {
		result->fad_ent.fde_ent.fd_type = DT_REG;

#ifdef CONFIG_FAT_CYGWIN_SYMLINKS
		/* Check if this is actually a symbolic link. */
		if ((ent.f_attr & FAT_ATTR_SYSTEM) &&
		    LETOH32(ent.f_size) >= FAT_SYMLINK_FILE_MINSIZE) {
			FatSuperblock *super = fsuper_asfat(me->fn_super);
			if (!(super->ft_features & FAT_FEATURE_NO_CYGWIN_SYMLINK)) {
				FatClusterIndex cluster = LETOH16(ent.f_clusterlo);
				if (!(super->ft_features & FAT_FEATURE_ARB))
					cluster |= (u32)LETOH16(ent.f_clusterhi) << 16;
				if (cluster < super->ft_cluster_eof) {
					byte_t hdr[sizeof(Fat_CygwinSymlinkMagic)];
					pos_t diskpos = FAT_CLUSTERADDR(super, cluster);
					TRY {
						/* XXX: This  read kind-of pollutes the device cache, especially
						 *      considering that `FatLnk_ReadLink()' doesn't make use of
						 *      this same cache! */
						mfile_readall(super->ft_super.ffs_super.fs_dev, hdr, sizeof(hdr), diskpos);
					} EXCEPT {
						kfree(result);
						RETHROW();
					}
					if (memcmp(hdr, Fat_CygwinSymlinkMagic, sizeof(hdr)) == 0) {
						/* Jup! It sure looks like a symlink to me :) */
						result->fad_ent.fde_ent.fd_type = DT_LNK;
					}
				}
			}
		}
#endif /* CONFIG_FAT_CYGWIN_SYMLINKS */
	}

	return &result->fad_ent;
}

PRIVATE WUNUSED NONNULL((1, 2, 3)) bool KCALL
FatDir_WriteDir(struct fflatdirnode *__restrict self,
                struct fflatdirent *__restrict ent,
                struct fnode *__restrict file,
                bool at_end_of_dir)
		THROWS(E_IOERROR, E_FSERROR_DISK_FULL, E_FSERROR_ILLEGAL_PATH) {
	FatDirNode *me = fflatdirnode_asfat(self);
	/* TODO: Write directory entries. */
	/* TODO: Set `file->fn_ino = ABSOLUTE_ON_DISK_POS(ent);'. (also update the INO field of `ent') */
	/* TODO: Set `file->fn_fsdata->fn_ent = ent' (possibly decref() the old value). */
	/* TODO: Fill in `ent->fad_dos' */
}

PRIVATE NONNULL((1, 2)) void KCALL
FatDir_DeleteEnt(struct fflatdirnode *__restrict self,
                 struct fflatdirent const *__restrict ent_,
                 bool at_end_of_dir)
		THROWS(E_IOERROR) {
	pos_t ptr, end;
	FatDirNode *me              = fflatdirnode_asfat(self);
	struct fatdirent const *ent = fflatdirent_asfat(ent_);
	assert((ent->fad_ent.fde_size % sizeof(struct fat_dirent)) == 0);
	ptr = fflatdirent_basaddr(&ent->fad_ent);
	end = fflatdirent_endaddr(&ent->fad_ent);

	/* Mark directory entries as deleted. */
	for (; ptr < end; ptr += sizeof(struct fat_dirent)) {
		static byte_t const marker[] = { MARKER_UNUSED };
		mfile_write(self, marker, sizeof(marker), ptr);
	}
}

PRIVATE ATTR_RETNONNULL WUNUSED NONNULL((1, 2)) struct fnode *KCALL
FatDir_MkFile(struct fflatdirnode *__restrict self,
              struct fmkfile_info const *__restrict info)
		THROWS(E_BADALLOC, E_IOERROR, E_FSERROR_UNSUPPORTED_OPERATION);

PRIVATE ATTR_RETNONNULL WUNUSED NONNULL((1, 2, 3)) struct fflatdirent *KCALL
FatDir_MkEnt(struct fflatdirnode *__restrict UNUSED(self),
             struct fmkfile_info const *__restrict info,
             struct fnode *__restrict UNUSED(file))
		THROWS(E_BADALLOC, E_IOERROR) {
	/* Allocate the new entry (the dos entry will be initialized by `FatDir_WriteDir') */
	struct fatdirent *result;
	result = _fatdirent_alloc(info->mkf_namelen);
	result->fad_ent.fde_ent.fd_ops = &fatdirent_ops;
	DBG_memset(&result->fad_dos, 0xcc, sizeof(result->fad_dos));
	return &result->fad_ent;
}

PRIVATE struct fat_dirent const new_directory_pattern[3] = {
#ifndef __INTELLISENSE__
	[0] = { /* '.' */
		{{{{{.f_name    = { '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }},
			.f_ext     = { ' ', ' ', ' ' }}},
			.f_attr    = FAT_ATTR_DIRECTORY,
			.f_ntflags = NTFLAG_NONE }}},
	[1] = { /* '..' */
		{{{{{.f_name    = { '.', '.', ' ', ' ', ' ', ' ', ' ', ' ' }},
			.f_ext      = { ' ', ' ', ' ' }}},
			.f_attr     = FAT_ATTR_DIRECTORY,
			.f_ntflags  = NTFLAG_NONE }}},
	[2] = {{{{{{ .f_marker  = MARKER_DIREND }}}}}}
#endif /* !__INTELLISENSE__ */
};

PRIVATE NONNULL((1)) FatClusterIndex KCALL
FatNode_GetFirstCluster(struct fnode *__restrict self)
		THROWS(E_BADALLOC, E_IOERROR) {
	FatNodeData *dat = self->fn_fsdata;
	FatClusterIndex result;
	for (;;) {
		FatNodeData_Read(dat);
		TRY {
			result = Fat_GetFileCluster(self, 0, FAT_GETCLUSTER_MODE_FCREATE);
		} EXCEPT {
			FatNodeData_EndRead(dat);
			RETHROW();
		}
		FatNodeData_EndRead(dat);
		if likely(result != FAT_GETFILECLUSTER_NEED_WRLOCK)
			break;
		FatNodeData_Write(dat);
		FatNodeData_EndWrite(dat);
	}
	return result;
}

PRIVATE NONNULL((1, 2, 3, 4)) void KCALL
FatDir_AllocFile(struct fflatdirnode *__restrict self,
                 struct fflatdirent *__restrict ent,
                 struct fnode *__restrict file,
                 struct fmkfile_info const *__restrict info)
		THROWS(E_BADALLOC, E_IOERROR) {
	FatDirNode *me       = fflatdirnode_asfat(self);
	FatNodeData *dat     = file->fn_fsdata;
	FatSuperblock *super = fsuper_asfat(file->fn_super);
	assert(dat->fn_dir == self);
	assert(dat->fn_ent == fflatdirent_asfat(ent));
	if (fnode_isdir(file)) {
		/* Allocate template for `file'. */
		struct fat_dirent hdr[3];
		FatClusterIndex fil_cluster;

		/* Determine the initial cluster of `file' */
		fil_cluster = FatNode_GetFirstCluster(file);

		/* Initialize the header template. */
		memcpy(hdr, new_directory_pattern, sizeof(hdr));
		hdr[0].f_clusterlo = HTOLE16(fil_cluster & 0xffff);
		if (!(super->ft_features & FAT_FEATURE_ARB))
			hdr[0].f_clusterhi = HTOLE16((u16)(fil_cluster >> 16));
		if (fnode_has_fat_clusters(me)) {
			FatClusterIndex par_cluster;
			par_cluster = FatNode_GetFirstCluster(me);
			hdr[1].f_clusterlo = HTOLE16(par_cluster & 0xffff);
			if (!(super->ft_features & FAT_FEATURE_ARB))
				hdr[1].f_clusterhi = HTOLE16((u16)(par_cluster >> 16));
		} else {
			/* 0x0000 -- Free Cluster; also used by DOS to refer to the parent directory starting cluster
			 *           in ".." entries of subdirectories of  the root directory on FAT12/FAT16  volumes
			 *           https://en.wikipedia.org/wiki/Design_of_the_FAT_file_system */
		}

		mfile_tslock_acquire(file);
		if (super->ft_features & FAT_FEATURE_UGID) {
			/* UID/GID support */
			hdr[0].f_uid = (u8)file->fn_uid;
			hdr[0].f_gid = (u8)file->fn_gid;
		} else {
			/* Last-access timestamp support */
			FatFileATime_Encode(&hdr[0].f_atime, &file->mf_atime);
		}
		FatFileMTime_Encode(&hdr[0].f_mtime, &file->mf_mtime);
		FatFileCTime_Encode(&hdr[0].f_ctime, &file->mf_ctime);
		mfile_tslock_release(file);
		hdr[1].f_atime             = hdr[0].f_atime;
		hdr[1].f_mtime.fc_date     = hdr[0].f_mtime.fc_date;
		hdr[1].f_mtime.fc_time     = hdr[0].f_mtime.fc_time;
		hdr[1].f_ctime.fc_date     = hdr[0].f_ctime.fc_date;
		hdr[1].f_ctime.fc_time     = hdr[0].f_ctime.fc_time;
		hdr[1].f_ctime.fc_sectenth = hdr[0].f_ctime.fc_sectenth;

		/* Write the directory header into the directory stream file. */
		mfile_write(file, hdr, sizeof(hdr), 0);
	}
#ifdef CONFIG_FAT_CYGWIN_SYMLINKS
	else if (fnode_islnk(file)) {
		/* Write the link's file contents (the string from `info'). */
		pos_t ptr = 0;
		mfile_write(file, Fat_CygwinSymlinkMagic, sizeof(Fat_CygwinSymlinkMagic), ptr);
		ptr += sizeof(Fat_CygwinSymlinkMagic);
		mfile_write(file, info->mkf_creat.c_symlink.s_text, info->mkf_creat.c_symlink.s_size, ptr);
		ptr += info->mkf_creat.c_symlink.s_size;
		mfile_write(file, "", 1, ptr); /* Trailing NUL */
	}
#endif /* CONFIG_FAT_CYGWIN_SYMLINKS */
}

PRIVATE NONNULL((1, 2, 3)) void KCALL
FatDir_DeleteFile(struct fflatdirnode *__restrict self,
                  struct fflatdirent *__restrict deleted_ent,
                  struct fnode *__restrict file)
		THROWS(E_IOERROR) {
	FatDirNode *me       = fflatdirnode_asfat(self);
	FatNodeData *dat     = me->fn_fsdata;
	FatSuperblock *super = fsuper_asfat(me->fn_super);
	FatClusterIndex *newvec;
	assert(dat->fn_dir == self);
	assert(dat->fn_ent == fflatdirent_asfat(deleted_ent));
	FatNodeData_Write(dat);
	assert(dat->fn_clusterc >= 1);
	if (dat->fn_clusterv[0] < super->ft_cluster_eof) {
		/* Delete the cluster chain. */
		TRY {
			Fat_DeleteClusterChain(super, dat->fn_clusterv[0]);
		} EXCEPT {
			FatNodeData_EndWrite(dat);
			RETHROW();
		}
	}

	/* Truncate unused vector space. */
	newvec = (FatClusterIndex *)krealloc_nx(dat->fn_clusterv,
	                                        1 * sizeof(FatClusterIndex),
	                                        GFP_NORMAL);
	if likely(newvec != NULL)
		dat->fn_clusterv = newvec;

	/* Modify cluster information of `self' to indicate no allocation */
	dat->fn_clusterv[0] = super->ft_cluster_eof_marker;
	dat->fn_clusterc    = 1;
	FatNodeData_EndWrite(dat);

	/* Technically, we'd have to do `mfile_changed(me, MFILE_F_ATTRCHANGED)'
	 * at this point, but this operator is  only called to deal with a  file
	 * being deleted as result of its NLINK counter hitting 0. iow: once  we
	 * get here, there's nowhere the file could (or should) be synced  _TO_. */
}

PRIVATE NONNULL((1, 2, 3, 4, 5)) void KCALL
FatDir_DirentChanged(struct fnode *__restrict self,
                     struct fflatdirnode *oldparent,
                     struct fflatdirnode *newparent,
                     struct fflatdirent *__restrict old_ent,
                     struct fflatdirent *__restrict new_ent)
		THROWS(E_IOERROR) {
	FatNodeData *dat = self->fn_fsdata;
	assert(dat->fn_ent == fflatdirent_asfat(old_ent));
	assert(dat->fn_dir == fflatdirnode_asfat(oldparent));

	/* Update saved meta-data values. */
	incref(new_ent);
	incref(newparent);
	mfile_tslock_acquire(self);
	dat->fn_ent = fflatdirent_asfat(new_ent);    /* Inherit reference */
	dat->fn_dir = fflatdirnode_asfat(newparent); /* Inherit reference */
	mfile_tslock_release(self);
	decref_nokill(fflatdirent_asfat(old_ent)); /* Old value of `dat->fn_ent' */
	decref_nokill(oldparent);                  /* Old value of `dat->fn_dir' */

	if (fnode_isdir(self) && oldparent != newparent) {
		/* TODO: Re-write the parent-cluster value within the directory header (the ".." entry) */
	}
}




/************************************************************************/
/* FAT operator tables.                                                 */
/************************************************************************/
PRIVATE struct fregnode_ops const Fat_RegOps = {
	.rno_node = {
		.no_file = {
			.mo_destroy    = &FatDir_Destroy,
			.mo_loadblocks = &Fat_LoadBlocks,
			.mo_saveblocks = &Fat_SaveBlocks,
			.mo_changed    = &fnode_v_changed,
			.mo_stream     = NULL,
		},
		.no_wrattr = &Fat_WrAttr,
	},
};
PRIVATE struct fflatdirnode_ops const Fat_DirOps = {
	.fdno_dir = {
		.dno_node = {
			.no_file = {
				.mo_destroy    = &FatDir_Destroy,
				.mo_loadblocks = &Fat_LoadBlocks,
				.mo_saveblocks = &Fat_SaveBlocks,
				.mo_changed    = &fnode_v_changed,
				.mo_stream     = &fdirnode_v_stream_ops,
			},
			.no_wrattr = &Fat_WrAttr,
		},
		.dno_lookup = &fflatdirnode_v_lookup,
		.dno_enum   = &fflatdirnode_v_enum,
		.dno_mkfile = &fflatdirnode_v_mkfile,
		.dno_unlink = &fflatdirnode_v_unlink,
		.dno_rename = &fflatdirnode_v_rename,
	},
	.fdno_flat = {
		.fdnx_readdir       = &FatDir_ReadDir,
		.fdnx_writedir      = &FatDir_WriteDir,
		.fdnx_deleteent     = &FatDir_DeleteEnt,
		.fdnx_mkfile        = &FatDir_MkFile,
		.fdnx_mkent         = &FatDir_MkEnt,
		.fdnx_allocfile     = &FatDir_AllocFile,
		.fdnx_deletefile    = &FatDir_DeleteFile,
		.fdnx_direntchanged = &FatDir_DirentChanged,
	},
};
#ifdef CONFIG_FAT_CYGWIN_SYMLINKS
PRIVATE struct mfile_stream_ops const Fat_LnkStreamOps = {
	.mso_stat = &FatLnk_Stat,
};
PRIVATE struct flnknode_ops const Fat_LnkOps = {
	.lno_node = {
		.no_file = {
			.mo_destroy    = &FatLnk_Destroy,
			.mo_loadblocks = &Fat_LoadBlocks,
			.mo_saveblocks = &Fat_SaveBlocks,
			.mo_changed    = &fnode_v_changed,
			.mo_stream     = &Fat_LnkStreamOps,
		},
		.no_wrattr = &Fat_WrAttr,
	},
	.lno_readlink = &FatLnk_ReadLink,
};
#endif /* CONFIG_FAT_CYGWIN_SYMLINKS */


/************************************************************************/
/* FAT Superblock operators.                                            */
/************************************************************************/
PRIVATE NONNULL((1, 5)) void KCALL
Fat16Root_LoadBlocks(struct mfile *__restrict self, pos_t addr,
                     physaddr_t buf, size_t num_bytes,
                     struct aio_multihandle *__restrict aio) {
	size_t maxio;
	FatSuperblock *me  = mfile_asfatsup(self);
	struct blkdev *dev = me->ft_super.ffs_super.fs_dev;
	/* Adjust for absolute on-disk addresses. */
	if (OVERFLOW_USUB(me->ft_fdat.fn16_root.r16_rootsiz, addr, &maxio))
		maxio = 0;
	if unlikely(num_bytes > maxio) {
		/* Some part of the tail cannot be read. Instead, initialize to 0 */
		memsetphys(buf + maxio, 0, num_bytes - maxio);
		num_bytes = maxio;
	}
	addr += me->ft_fdat.fn16_root.r16_rootpos;
	if likely(dev->mf_blockshift <= me->ft_sectorshift) {
		if unlikely(dev->mf_flags & MFILE_F_READONLY)
			THROW(E_FSERROR_READONLY);
		/* Can use unbuffered I/O */
		blkdev_rdsectors_async(dev, addr, buf, num_bytes, aio);
	} else {
		/* Must use sync I/O due to alignment constraints */
		mfile_readall_p(dev, buf, num_bytes, addr);
	}
}

PRIVATE NONNULL((1, 5)) void KCALL
Fat16Root_SaveBlocks(struct mfile *__restrict self, pos_t addr,
                     physaddr_t buf, size_t num_bytes,
                     struct aio_multihandle *__restrict aio) {
	size_t maxio;
	FatSuperblock *me  = mfile_asfatsup(self);
	struct blkdev *dev = me->ft_super.ffs_super.fs_dev;
	/* Adjust for absolute on-disk addresses. */
	if (OVERFLOW_USUB(me->ft_fdat.fn16_root.r16_rootsiz, addr, &maxio))
		maxio = 0;
	if unlikely(num_bytes > maxio)
		num_bytes = maxio; /* Some part of the tail cannot be written. */
	addr += me->ft_fdat.fn16_root.r16_rootpos;
	if likely(dev->mf_blockshift <= me->ft_sectorshift) {
		if unlikely(dev->mf_flags & MFILE_F_READONLY)
			THROW(E_FSERROR_READONLY);
		/* Can use unbuffered I/O */
		blkdev_wrsectors_async(dev, addr, buf, num_bytes, aio);
	} else {
		/* Must use sync I/O due to alignment constraints */
		mfile_write_p(dev, buf, num_bytes, addr);
	}
}

PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(KCALL FatSuper_Destroy)(struct mfile *__restrict self) {
	FatSuperblock *me = mfile_asfatsup(self);
	if (me->ft_type == FAT32)
		kfree(me->ft_fdat.fn_clusterv);
	mman_unmap_kram_and_kfree(me->ft_fat_table,
	                          me->ft_fat_size,
	                          me->ft_freefat);
	fflatsuper_v_destroy(self);
}

PRIVATE ATTR_RETNONNULL WUNUSED NONNULL((1, 2)) struct fnode *KCALL
FatDir_MkFile(struct fflatdirnode *__restrict self,
              struct fmkfile_info const *__restrict info)
		THROWS(E_BADALLOC, E_IOERROR, E_FSERROR_UNSUPPORTED_OPERATION) {
	struct fnode *result;
	FatSuperblock *super = fsuper_asfat(self->fn_super);
	FatDirNode *me       = fflatdirnode_asfat(self);
	FatNodeData *dat;

	/* Allocate a new file-node with FAT operators */
	switch (info->mkf_fmode & S_IFMT) {

	case S_IFREG: {
		FatRegNode *node;
		node = (FatRegNode *)kmalloc(sizeof(FatRegNode), GFP_NORMAL);
		node->mf_ops   = &Fat_RegOps.rno_node.no_file;
		node->mf_flags = MFILE_F_NORMAL;
		atomic64_init(&node->mf_filesize, 0);
		node->fn_fsdata = &node->frn_fdat;
		result = node;
	}	break;

	case S_IFDIR: {
		FatDirNode *node;
		node = (FatDirNode *)kmalloc(sizeof(FatDirNode), GFP_NORMAL);
		node->mf_ops   = &Fat_DirOps.fdno_dir.dno_node.no_file;
		node->mf_flags = MFILE_F_NOUSRIO | MFILE_F_NOUSRMMAP;
		atomic64_init(&node->mf_filesize, (uint64_t)-1);
		node->fn_fsdata = &node->fdn_fdat;
		fflatdirdata_init(&node->fdn_data);
		result = node;
	}	break;

#ifdef CONFIG_FAT_CYGWIN_SYMLINKS
	case S_IFLNK: {
		FatLnkNode *node;
		node = (FatLnkNode *)kmalloc(sizeof(FatLnkNode), GFP_NORMAL);
		node->mf_ops   = &Fat_LnkOps.lno_node.no_file;
		node->mf_flags = MFILE_F_NOUSRIO | MFILE_F_NOUSRMMAP;
		atomic64_init(&node->mf_filesize, 0);
		node->fn_fsdata = &node->fln_fdat;
		result = node;
	}	break;
#endif /* CONFIG_FAT_CYGWIN_SYMLINKS */

	default:
		THROW(E_FSERROR_UNSUPPORTED_OPERATION);
		break;
	}
	dat = result->fn_fsdata;
	TRY {
		dat->fn_clusterv = (FatClusterIndex *)kmalloc(sizeof(FatClusterIndex), GFP_NORMAL);
	} EXCEPT {
		kfree(result);
		RETHROW();
	}
	dat->fn_clusterc    = 1;
	dat->fn_clusterv[0] = super->ft_cluster_eof_marker;
	dat->fn_ent = NULL; /* Initialized by `FatDir_WriteDir()' */
	dat->fn_dir = mfile_asfatdir(incref(me));
	shared_rwlock_init(&dat->fn_lock);

	result->mf_parts      = NULL;
	result->mf_blockshift = self->mf_blockshift;
	result->fn_ino        = 0; /* Allocated later. */
	return result;
}

PRIVATE ATTR_RETNONNULL WUNUSED NONNULL((1)) struct fnode *KCALL
FatSuper_MakeNode(struct fflatsuper *__restrict self,
                  struct fflatdirent *__restrict ent_,
                  struct fflatdirnode *__restrict dir_)
		THROWS(E_BADALLOC, E_IOERROR) {
	struct fnode *result;
	struct fatdirent *ent = fflatdirent_asfat(ent_);
	FatDirNode *dir       = fflatdirnode_asfat(dir_);
	FatSuperblock *super  = fflatsuper_asfat(self);
	FatNodeData *dat;
	ino_t ino;

	/* FAT uses the absolute on-disk position of file entries as INode number */
	if (fnode_has_fat_clusters(dir)) {
		for (;;) {
			FatNodeData_Read(&dir->fdn_fdat);
			TRY {
				ino = (ino_t)Fat_GetAbsDiskPosWithClusters(dir, ent->fad_ent.fde_pos);
			} EXCEPT {
				FatNodeData_EndRead(&dir->fdn_fdat);
				RETHROW();
			}
			FatNodeData_EndRead(&dir->fdn_fdat);
			if (ino != 0)
				break;
			/* Wait for writing to become possible. */
			FatNodeData_Write(&dir->fdn_fdat);
			FatNodeData_EndWrite(&dir->fdn_fdat);
		}
	} else {
		ino = (ino_t)Fat_GetAbsDiskPosWithoutFatClusters(dir, ent->fad_ent.fde_pos);
	}

	/* Allocate a new file-node with FAT operators */
	switch (ent->fad_ent.fde_ent.fd_type) {

	case DT_REG: {
		FatRegNode *node;
		node = (FatRegNode *)kmalloc(sizeof(FatRegNode), GFP_NORMAL);
		node->mf_ops        = &Fat_RegOps.rno_node.no_file;
		node->mf_flags      = MFILE_F_NORMAL;
		node->fn_fsdata = &node->frn_fdat;
		result = node;
	}	break;

	case DT_DIR: {
		FatDirNode *node;
		node = (FatDirNode *)kmalloc(sizeof(FatDirNode), GFP_NORMAL);
		node->mf_ops   = &Fat_DirOps.fdno_dir.dno_node.no_file;
		node->mf_flags = MFILE_F_NOUSRIO | MFILE_F_NOUSRMMAP;
		node->fn_fsdata = &node->fdn_fdat;
		fflatdirdata_init(&node->fdn_data);
		result = node;
	}	break;

#ifdef CONFIG_FAT_CYGWIN_SYMLINKS
	case DT_LNK: {
		FatLnkNode *node;
		node = (FatLnkNode *)kmalloc(sizeof(FatLnkNode), GFP_NORMAL);
		node->mf_ops   = &Fat_LnkOps.lno_node.no_file;
		node->mf_flags = MFILE_F_NOUSRIO | MFILE_F_NOUSRMMAP;
		node->fn_fsdata = &node->fln_fdat;
		result = node;
	}	break;
#endif /* CONFIG_FAT_CYGWIN_SYMLINKS */

	default: __builtin_unreachable();
	}
	dat = result->fn_fsdata;
	TRY {
		dat->fn_clusterv = (FatClusterIndex *)kmalloc(sizeof(FatClusterIndex), GFP_NORMAL);
	} EXCEPT {
		kfree(result);
		RETHROW();
	}

	/* Load file cluster number. */
	dat->fn_clusterc    = 1;
	dat->fn_clusterv[0] = LETOH16(ent->fad_dos.f_clusterlo);

	/* Fill in common fields from the DOS directory entry. */
	atomic64_init(&result->mf_filesize, LETOH32(ent->fad_dos.f_size));
	if (ent->fad_ent.fde_ent.fd_type == DT_DIR)
		atomic64_init(&result->mf_filesize, (uint64_t)-1);
	result->fn_mode = DTTOIF(ent->fad_ent.fde_ent.fd_type);
	if (super->ft_features & FAT_FEATURE_ARB) {
		u16 arb = LETOH16(ent->fad_dos.f_arb);
		mode_t unix_perm = 0777;
		/* Use the ARB to implement unix file permissions. */
		if (arb & FAT_ARB_NO_OX)
			unix_perm &= ~S_IXUSR; /* Disable: Execute by owner */
		if (arb & FAT_ARB_NO_OW)
			unix_perm &= ~S_IWUSR; /* Disable: Write by owner */
		if (arb & FAT_ARB_NO_OR)
			unix_perm &= ~S_IRUSR; /* Disable: Read by owner */

		if (arb & FAT_ARB_NO_GX)
			unix_perm &= ~S_IXGRP; /* Disable: Execute by group */
		if (arb & FAT_ARB_NO_GW)
			unix_perm &= ~S_IWGRP; /* Disable: Write by group */
		if (arb & FAT_ARB_NO_GR)
			unix_perm &= ~S_IRGRP; /* Disable: Read by group */

		if (arb & FAT_ARB_NO_WX)
			unix_perm &= ~S_IXOTH; /* Disable: Execute by world */
		if (arb & FAT_ARB_NO_WW)
			unix_perm &= ~S_IWOTH; /* Disable: Write by world */
		if (arb & FAT_ARB_NO_WR)
			unix_perm &= ~S_IROTH; /* Disable: Read by world */
		result->fn_mode |= unix_perm;
	} else {
		assert(!(super->ft_mode & ~0777));
		/* 32-bit clusters */
		dat->fn_clusterv[0] |= (u32)LETOH16(ent->fad_dos.f_clusterhi) << 16;
		result->fn_mode |= 0222 | (super->ft_mode & 0555);
	}

	/* Implement the read-only attribute via unix permissions. */
	if (ent->fad_dos.f_attr & FAT_ATTR_READONLY)
		result->fn_mode &= ~0222;

	/* FAT files always have exactly 1 link (unless they've been deleted) */
	result->fn_nlink = 1;

	/* Convert timestamps. */
	FatFileMTime_Decode(&ent->fad_dos.f_mtime, &result->mf_mtime);
	FatFileCTime_Decode(&ent->fad_dos.f_ctime, &result->mf_ctime);
	if (super->ft_features & FAT_FEATURE_UGID) {
		/* In-built user/group ID support */
		result->fn_uid = (uid_t)ent->fad_dos.f_uid;
		result->fn_gid = (gid_t)ent->fad_dos.f_gid;
		/* Re-use the last-modified timestamp for access time. */
		result->mf_atime.tv_sec  = result->mf_mtime.tv_sec;
		result->mf_atime.tv_nsec = result->mf_mtime.tv_nsec;
	} else {
		result->fn_uid = super->ft_uid;
		result->fn_gid = super->ft_gid;
		FatFileATime_Decode(&ent->fad_dos.f_atime,
		                    &result->mf_atime);
	}

	/* Fill in remaining fields w. */
	result->mf_parts = NULL;
	dat->fn_ent      = incref(ent);
	dat->fn_dir      = mfile_asfatdir(incref(dir));
	result->fn_ino   = ino;
	shared_rwlock_init(&dat->fn_lock);
	result->mf_blockshift = dir->mf_blockshift;
	return result;
}

PRIVATE WUNUSED NONNULL((1)) bool
NOTHROW(KCALL FatSuper_ValidUid)(struct fsuper *__restrict self, uid_t uid) {
	FatSuperblock *me = fsuper_asfat(self);
	if (me->ft_features & FAT_FEATURE_UGID)
		return uid >= 0 && uid <= 0xff;
	return uid == me->ft_uid;
}

PRIVATE WUNUSED NONNULL((1)) bool
NOTHROW(KCALL FatSuper_ValidGid)(struct fsuper *__restrict self, gid_t gid) {
	FatSuperblock *me = fsuper_asfat(self);
	if (me->ft_features & FAT_FEATURE_UGID)
		return gid >= 0 && gid <= 0xff;
	return gid == me->ft_gid;
}

PRIVATE NONNULL((1, 2)) void
NOTHROW(KCALL FatSuper_TruncateATime)(struct fsuper *__restrict UNUSED(self),
                                      /*in|out*/ struct timespec *__restrict tms) {
	struct fat_fileatime ts;
	/* TODO: atime only exists when `FAT_FEATURE_ATIME' is available.
	 *       Otherwise, we set it equal to mtime.
	 * To support something  like this, all  timestamps
	 * must be truncated at the same time by a singular
	 * operator! */
	FatFileATime_Encode(&ts, tms);
	FatFileATime_Decode(&ts, tms);
}

PRIVATE NONNULL((1, 2)) void
NOTHROW(KCALL FatSuper_TruncateMTime)(struct fsuper *__restrict UNUSED(self),
                                      /*in|out*/ struct timespec *__restrict tms) {
	struct fat_filemtime ts;
	FatFileMTime_Encode(&ts, tms);
	FatFileMTime_Decode(&ts, tms);
}

PRIVATE NONNULL((1, 2)) void
NOTHROW(KCALL FatSuper_TruncateCTime)(struct fsuper *__restrict UNUSED(self),
                                      /*in|out*/ struct timespec *__restrict tms) {
	struct fat_filectime ts;
	FatFileCTime_Encode(&ts, tms);
	FatFileCTime_Decode(&ts, tms);
}

PRIVATE struct fflatsuper_ops const Fat16_SuperOps = {
	.ffso_makenode = &FatSuper_MakeNode,
	.ffso_super = {
		.so_validuid       = &FatSuper_ValidUid,
		.so_validgid       = &FatSuper_ValidGid,
		.so_truncate_atime = &FatSuper_TruncateATime,
		.so_truncate_mtime = &FatSuper_TruncateMTime,
		.so_truncate_ctime = &FatSuper_TruncateCTime,
		.so_fdir = {
			.dno_node = {
				.no_file = {
					.mo_destroy    = &FatSuper_Destroy,
					.mo_loadblocks = &Fat16Root_LoadBlocks,
					.mo_saveblocks = &Fat16Root_SaveBlocks,
					.mo_changed    = &fnode_v_changed,
					.mo_stream     = &fdirnode_v_stream_ops,
				},
				.no_wrattr = &fnode_v_wrattr_noop,
			},
			.dno_lookup = &fflatdirnode_v_lookup,
			.dno_enum   = &fflatdirnode_v_enum,
			.dno_mkfile = &fflatdirnode_v_mkfile,
			.dno_unlink = &fflatdirnode_v_unlink,
			.dno_rename = &fflatdirnode_v_rename,
		},
	},
	.ffso_flat = {
		.fdnx_readdir    = &FatDir_ReadDir,
		.fdnx_writedir   = &FatDir_WriteDir,
		.fdnx_deleteent  = &FatDir_DeleteEnt,
		.fdnx_mkfile     = &FatDir_MkFile,
		.fdnx_mkent      = &FatDir_MkEnt,
		.fdnx_allocfile  = &FatDir_AllocFile,
		.fdnx_deletefile = &FatDir_DeleteFile,
	},
};
PRIVATE struct fflatsuper_ops const Fat32_SuperOps = {
	.ffso_makenode = &FatSuper_MakeNode,
	.ffso_super = {
		.so_validuid       = &FatSuper_ValidUid,
		.so_validgid       = &FatSuper_ValidGid,
		.so_truncate_atime = &FatSuper_TruncateATime,
		.so_truncate_mtime = &FatSuper_TruncateMTime,
		.so_truncate_ctime = &FatSuper_TruncateCTime,
		.so_fdir = {
			.dno_node = {
				.no_file = {
					.mo_destroy    = &FatSuper_Destroy,
					.mo_loadblocks = &Fat_LoadBlocks,
					.mo_saveblocks = &Fat_SaveBlocks,
					.mo_changed    = &fnode_v_changed,
					.mo_stream     = &fdirnode_v_stream_ops,
				},
				.no_wrattr = &fnode_v_wrattr_noop,
			},
			.dno_lookup = &fflatdirnode_v_lookup,
			.dno_enum   = &fflatdirnode_v_enum,
			.dno_mkfile = &fflatdirnode_v_mkfile,
			.dno_unlink = &fflatdirnode_v_unlink,
			.dno_rename = &fflatdirnode_v_rename,
		},
	},
	.ffso_flat = {
		.fdnx_readdir    = &FatDir_ReadDir,
		.fdnx_writedir   = &FatDir_WriteDir,
		.fdnx_deleteent  = &FatDir_DeleteEnt,
		.fdnx_mkfile     = &FatDir_MkFile,
		.fdnx_mkent      = &FatDir_MkEnt,
		.fdnx_allocfile  = &FatDir_AllocFile,
		.fdnx_deletefile = &FatDir_DeleteFile,
	},
};







/************************************************************************/
/* The FAT get/set implementation for different table sizes.            */
/************************************************************************/
PRIVATE NOBLOCK ATTR_PURE WUNUSED NONNULL((1)) FatClusterIndex
NOTHROW(FCALL Fat12_GetFatIndirection)(FatSuperblock const *__restrict self,
                                       FatClusterIndex index) {
	u16 val;
	assertf(index < self->ft_fat_length,
	        "Out-of-bounds FAT index: %" PRIu32 " >= %" PRIu32 "",
	        index, self->ft_fat_length);
	val = *(u16 const *)((byte_t const *)self->ft_fat_table + (index + (index >> 1)));
	if (index & 1) {
		val >>= 4;
	} else {
		val &= 0x0fff;
	}
	return val;
}

PRIVATE NOBLOCK ATTR_PURE WUNUSED NONNULL((1)) FatClusterIndex
NOTHROW(FCALL Fat16_GetFatIndirection)(FatSuperblock const *__restrict self,
                                       FatClusterIndex index) {
	assertf(index < self->ft_fat_length,
	        "Out-of-bounds FAT index: %" PRIu32 " >= %" PRIu32 "",
	        index, self->ft_fat_length);
	return ((u16 const *)self->ft_fat_table)[index];
}

PRIVATE NOBLOCK ATTR_PURE WUNUSED NONNULL((1)) FatClusterIndex
NOTHROW(FCALL Fat32_GetFatIndirection)(FatSuperblock const *__restrict self,
                                       FatClusterIndex index) {
	assertf(index < self->ft_fat_length,
	        "Out-of-bounds FAT index: %" PRIu32 " >= %" PRIu32 "",
	        index, self->ft_fat_length);
	return ((u32 const *)self->ft_fat_table)[index];
}

PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL Fat12_SetFatIndirection)(FatSuperblock *__restrict self,
                                       FatClusterIndex index,
                                       FatClusterIndex indirection_target) {
	u16 *pval;
	assertf(index < self->ft_fat_length,
	        "Out-of-bounds FAT index: %" PRIu32 " >= %" PRIu32 "",
	        index, self->ft_fat_length);
	pval = ((u16 *)((byte_t *)self->ft_fat_table + (index + (index / 2))));
	if (index & 1) {
		*pval = (*pval & 0xf) | (indirection_target << 4);
	} else {
		*pval |= indirection_target & 0xfff;
	}
}

PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL Fat16_SetFatIndirection)(FatSuperblock *__restrict self,
                                       FatClusterIndex index,
                                       FatClusterIndex indirection_target) {
	assertf(index < self->ft_fat_length,
	        "Out-of-bounds FAT index: %" PRIu32 " >= %" PRIu32 "",
	        index, self->ft_fat_length);
	((u16 *)self->ft_fat_table)[index] = (u16)indirection_target;
}

PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL Fat32_SetFatIndirection)(FatSuperblock *__restrict self,
                                       FatClusterIndex index,
                                       FatClusterIndex indirection_target) {
	assertf(index < self->ft_fat_length,
	        "Out-of-bounds FAT index: %" PRIu32 " >= %" PRIu32 "",
	        index, self->ft_fat_length);
	((u32 *)self->ft_fat_table)[index] = indirection_target;
}





/************************************************************************/
/* FAT Superblock: Open Filesystem                                      */
/************************************************************************/

PRIVATE NONNULL((1)) void KCALL
trimspecstring(char *__restrict buf, size_t size) {
	while (size && FAT_ISSPACE(*buf)) {
		--size;
		memmovedown(buf, buf + 1, size, sizeof(char));
		buf[size] = '\0';
	}
	while (size && FAT_ISSPACE(buf[size - 1])) {
		--size;
		buf[size] = '\0';
	}
}



PRIVATE WUNUSED NONNULL((1)) struct fsuper *KCALL
Fat_OpenFileSystem(struct ffilesys *__restrict filesys,
                   struct blkdev *dev, UNCHECKED USER char *args) {
	FatSuperblock *result;
	FatDiskHeader *disk;
	u16 sector_size;

	(void)args; /* XXX: User-arguments. */
	assert(dev);

	/* Read the FAT disk header. */
	if (blkdev_getsectorsize(dev) == sizeof(FatDiskHeader)) {
		disk = (FatDiskHeader *)aligned_alloca(sizeof(FatDiskHeader),
		                                       sizeof(FatDiskHeader));
		blkdev_rdsectors(dev, 0, pagedir_translate(disk), sizeof(FatDiskHeader));
	} else {
		disk = (FatDiskHeader *)alloca(sizeof(FatDiskHeader));
		mfile_readall(dev, disk, sizeof(FatDiskHeader), 0);
	}

	/* Validate the boot signature. */
	if unlikely(disk->fat32.f32_bootsig[0] != 0x55 ||
	            disk->fat32.f32_bootsig[1] != 0xAA)
		return NULL;

	if (!disk->bpb.bpb_sectors_per_cluster ||
	    !disk->bpb.bpb_reserved_sectors) /* What's the first sector, then? */
		return NULL;

	sector_size = LETOH16(disk->bpb.bpb_bytes_per_sector);
	if unlikely(!IS_POWER_OF_TWO(sector_size))
		return NULL;
	if unlikely(!sector_size)
		return NULL;

	/* Allocate the FAT superblock controller. */
	result = (FatSuperblock *)kmalloc(sizeof(FatSuperblock), GFP_NORMAL);
	TRY {
		result->ft_sectorshift = CTZ(sector_size);

		/* Fill in filesystem info. */
		result->ft_sectorsize = sector_size;
		result->ft_uid        = 0;
		result->ft_gid        = 0;
		result->ft_mode       = 0755; /* Read/Execute permissions for everyone. */
		result->ft_features   = 0;
		shared_rwlock_init(&result->ft_fat_lock);
		result->ft_free_pos = 0;

		/* Extract some common information. */
		result->ft_fat_start   = (FatSectorIndex)LETOH16(disk->bpb.bpb_reserved_sectors);
		result->ft_sec4clus    = (size_t)disk->bpb.bpb_sectors_per_cluster;
		result->ft_fat_count   = (u32)disk->bpb.bpb_fatc;
		result->ft_clustersize = (size_t)result->ft_sec4clus << result->ft_sectorshift;

		/* Figure out what kind of FAT filesystem this is. */
		if (!disk->bpb.bpb_sectors_per_fat || !disk->bpb.bpb_maxrootsize) {
			result->ft_dat_start = result->ft_fat_start + (LETOH32(disk->fat32.f32_sectors_per_fat) *
			                                               disk->bpb.bpb_fatc);
			result->ft_type      = FAT32;
		} else {
			u32 fat_size, root_sectors;
			u32 data_sectors, total_clusters;
			root_sectors = (LETOH16(disk->bpb.bpb_maxrootsize) * sizeof(struct fat_dirent) +
			                (result->ft_sectorsize - 1)) >>
			               result->ft_sectorshift;
			fat_size             = (disk->bpb.bpb_fatc * LETOH16(disk->bpb.bpb_sectors_per_fat));
			result->ft_dat_start = LETOH16(disk->bpb.bpb_reserved_sectors);
			result->ft_dat_start += fat_size;
			result->ft_dat_start += root_sectors;
			/* Calculate the total number of data sectors. */
			if (disk->bpb.bpb_shortsectorc) {
				data_sectors = LETOH16(disk->bpb.bpb_shortsectorc);
			} else {
				data_sectors = LETOH32(disk->bpb.bpb_longsectorc);
			}
			if (OVERFLOW_USUB(data_sectors, LETOH16(disk->bpb.bpb_reserved_sectors), &data_sectors))
				THROW(E_FSERROR_CORRUPTED_FILE_SYSTEM);
			if (OVERFLOW_USUB(data_sectors, fat_size, &data_sectors))
				THROW(E_FSERROR_CORRUPTED_FILE_SYSTEM);
			if (OVERFLOW_USUB(data_sectors, root_sectors, &data_sectors))
				THROW(E_FSERROR_CORRUPTED_FILE_SYSTEM);
			/* Calculate the total number of data clusters. */
			total_clusters = data_sectors / disk->bpb.bpb_sectors_per_cluster;
			if (total_clusters > FAT16_MAXCLUSTERS)
				result->ft_type = FAT32;
			else if (total_clusters > FAT12_MAXCLUSTERS)
				result->ft_type = FAT16;
			else {
				result->ft_type = FAT12;
			}
		}

		if (result->ft_type == FAT32) {
			if (disk->fat32.f32_signature != 0x28 &&
			    disk->fat32.f32_signature != 0x29)
				THROW(E_FSERROR_WRONG_FILE_SYSTEM);
			result->ft_volid = LETOH32(disk->fat32.f32_volid);
			memcpy(result->ft_label, disk->fat32.f32_label, sizeof(disk->fat32.f32_label));
			memcpy(result->ft_sysname, disk->fat32.f32_sysname, sizeof(disk->fat32.f32_sysname));
			result->ft_sec4fat            = LETOH32(disk->fat32.f32_sectors_per_fat);
			result->ft_cluster_eof        = (result->ft_sec4fat << result->ft_sectorshift) / 4;
			result->ft_cluster_eof_marker = 0xffffffff;
			/* Must lookup the cluster of the root directory. */
			shared_rwlock_init(&result->ft_fdat.fn_lock);
			result->ft_fdat.fn_clusterc    = 1;
			result->ft_fdat.fn_clusterv    = (FatClusterIndex *)kmalloc(sizeof(FatClusterIndex), GFP_NORMAL);
			result->ft_fdat.fn_clusterv[0] = LETOH32(disk->fat32.f32_root_cluster);
			result->ft_fat_get = &Fat32_GetFatIndirection;
			result->ft_fat_set = &Fat32_SetFatIndirection;
		} else {
			if (result->ft_type == FAT12) {
				result->ft_cluster_eof_marker = 0xfff;
				result->ft_fat_get = &Fat12_GetFatIndirection;
				result->ft_fat_set = &Fat12_SetFatIndirection;
			} else {
				result->ft_cluster_eof_marker = 0xffff;
				result->ft_fat_get = &Fat16_GetFatIndirection;
				result->ft_fat_set = &Fat16_SetFatIndirection;
			}
			if (disk->fat16.f16_signature != 0x28 &&
			    disk->fat16.f16_signature != 0x29)
				THROW(E_FSERROR_WRONG_FILE_SYSTEM);
			result->ft_volid = LETOH32(disk->fat16.f16_volid);
			memcpy(result->ft_label, disk->fat16.f16_label, sizeof(disk->fat16.f16_label));
			memcpy(result->ft_sysname, disk->fat16.f16_sysname, sizeof(disk->fat16.f16_sysname));
			result->ft_fdat.fn16_root.r16_rootpos = (pos_t)LETOH16(disk->bpb.bpb_reserved_sectors);
			result->ft_fdat.fn16_root.r16_rootpos += (disk->bpb.bpb_fatc * LETOH16(disk->bpb.bpb_sectors_per_fat));
			result->ft_fdat.fn16_root.r16_rootpos <<= result->ft_sectorshift;
			result->ft_sec4fat                    = LETOH16(disk->bpb.bpb_sectors_per_fat);
			result->ft_fdat.fn16_root.r16_rootsiz = (u32)LETOH16(disk->bpb.bpb_maxrootsize);
			result->ft_fdat.fn16_root.r16_rootsiz *= sizeof(struct fat_dirent);
			result->ft_cluster_eof = (result->ft_sec4fat << result->ft_sectorshift) / 2;
			/* It is possible  to create  a FAT16 filesystem  with 0x10000  sectors.
			 * This is a special case since sector 0xffff still needs to be reserved
			 * as the special sector used for marking file EOF.
			 * Because of this, make sure not to allocate sectors above the EOF marker */
			if (result->ft_cluster_eof > result->ft_cluster_eof_marker)
				result->ft_cluster_eof = result->ft_cluster_eof_marker;
		}
		if (result->ft_cluster_eof <= 0xffff)
			result->ft_features |= FAT_FEATURE_ARB; /* 16-bit clusters --> high 16 bits are the ARB mask. */
		if (result->ft_cluster_eof_marker < result->ft_cluster_eof)
			result->ft_cluster_eof_marker = result->ft_cluster_eof;
		/* XXX: Detect `FAT_FEATURE_UGID' */

		memcpy(&result->ft_oem, disk->bpb.bpb_oem, 8, sizeof(char));
		result->ft_fat_size = (size_t)result->ft_sec4fat << result->ft_sectorshift;
		trimspecstring(result->ft_oem, 8);
		trimspecstring(result->ft_label, 11);
		trimspecstring(result->ft_sysname, 8);

		/* Map the FAT table into memory. */
		TRY {
			result->ft_freefat = (struct mman_unmap_kram_job *)kmalloc(sizeof(struct mman_unmap_kram_job), GFP_NORMAL);
			TRY {
				result->ft_fat_table = mman_map(/* self:        */ &mman_kernel,
				                                /* hint:        */ MHINT_GETADDR(KERNEL_MHINT_DEVICE),
				                                /* num_bytes:   */ result->ft_fat_size,
				                                /* prot:        */ PROT_READ | PROT_WRITE | PROT_SHARED,
				                                /* flags:       */ MHINT_GETMODE(KERNEL_MHINT_DEVICE),
				                                /* file:        */ dev,
				                                /* file_fspath: */ NULL,
				                                /* file_fsname: */ NULL,
				                                /* file_pos:    */ FAT_SECTORADDR(result, result->ft_fat_start));
				/* TODO: This file mapping only syncs to a single FAT!
				 *       As such, syncing will appear inconsistent in other OSes when `self->ft_fat_count > 1'
				 * The best solution for that scenario is probably to create a private struct mfile that
				 * dispatches loadparts to the device,  and saveparts to each  of the FATs in  sequence. */
			} EXCEPT {
				kfree(result->ft_freefat);
				RETHROW();
			}
		} EXCEPT {
			if (result->ft_type == FAT32)
				kfree(result->ft_fdat.fn_clusterv);
			RETHROW();
		}

		/* Fill in mandatory superblock fields. */
		/*result->ft_super.ffs_super.fs_root.mf_blockshift       = result->ft_sectorshift;*/ /* It's the same field! */
		result->ft_super.ffs_super.fs_root.mf_parts              = NULL;
		result->ft_super.ffs_super.fs_root.mf_flags              = MFILE_F_NORMAL;
		result->ft_super.ffs_super.fs_root.fn_ino                = 0;
		result->ft_super.ffs_super.fs_feat.sf_filesize_max       = (pos_t)UINT32_MAX;
		result->ft_super.ffs_super.fs_feat.sf_uid_max            = 0;
		result->ft_super.ffs_super.fs_feat.sf_gid_max            = 0;
		result->ft_super.ffs_super.fs_feat.sf_symlink_max        = 0;
		result->ft_super.ffs_super.fs_feat.sf_link_max           = 1;
		result->ft_super.ffs_super.fs_feat.sf_magic              = MSDOS_SUPER_MAGIC;
		result->ft_super.ffs_super.fs_feat.sf_rec_incr_xfer_size = result->ft_sectorsize;
		result->ft_super.ffs_super.fs_feat.sf_rec_max_xfer_size  = result->ft_sectorsize;
		result->ft_super.ffs_super.fs_feat.sf_rec_min_xfer_size  = result->ft_sectorsize;
		result->ft_super.ffs_super.fs_feat.sf_rec_xfer_align     = result->ft_sectorsize;
		result->ft_super.ffs_super.fs_feat.sf_name_max           = LFN_SEQNUM_MAXCOUNT * LFN_NAME;
		result->ft_super.ffs_super.fs_feat.sf_filesizebits       = 32;
		result->ft_super.ffs_super.fs_root.fn_fsdata             = &result->ft_fdat;

		/* Special case for when uid/gid support is available. */
		if (result->ft_features & FAT_FEATURE_UGID) {
			result->ft_super.ffs_super.fs_feat.sf_uid_max = (uid_t)0xff;
			result->ft_super.ffs_super.fs_feat.sf_gid_max = (gid_t)0xff;
		}
#ifdef CONFIG_FAT_CYGWIN_SYMLINKS
		if (!(result->ft_features & FAT_FEATURE_NO_CYGWIN_SYMLINK))
			result->ft_super.ffs_super.fs_feat.sf_symlink_max = (pos_t)FAT_SYMLINK_FILE_TEXTLEN(UINT32_MAX);
#endif /* CONFIG_FAT_CYGWIN_SYMLINKS */


		/* Select root directory operators. */
		result->ft_super.ffs_super.fs_root.mf_ops = result->ft_type == FAT32
		                                            ? &Fat32_SuperOps.ffso_super.so_fdir.dno_node.no_file
		                                            : &Fat16_SuperOps.ffso_super.so_fdir.dno_node.no_file;

		/* Fill in fields relating to `fflatsuper' */
		result->ft_super.ffs_features = FFLATSUPER_FEAT_WRITEDIR_CHANGES_INO;
		fflatdirdata_init(&result->ft_super.ffs_rootdata);
	} EXCEPT {
		kfree(result);
		RETHROW();
	}
	printk(KERN_INFO "[fat] Load FAT%u-filesystem on "
	                 "%.2" PRIxN(__SIZEOF_MAJOR_T__) ":"
	                 "%.2" PRIxN(__SIZEOF_MINOR_T__) " "
	                 "[oem=%q] [label=%q] [sysname=%q]\n",
	       result->ft_type == FAT12 ? 12 : result->ft_type == FAT16 ? 16 : 32,
	       MAJOR(dev->dn_devno), MINOR(dev->dn_devno),
	       result->ft_oem, result->ft_label, result->ft_sysname);
	return &result->ft_super.ffs_super;
}



/************************************************************************/
/* FAT Filesystem Type                                                  */
/************************************************************************/
PRIVATE struct ffilesys Fat_Filesys = {
	.ffs_drv = &drv_self,
	{ .ffs_open = &Fat_OpenFileSystem },
	.ffs_flags = FFILESYS_F_NORMAL,
	.ffs_name  = "fat",
};

STATIC_ASSERT((offsetof(FatSuperblock, ft_super.ffs_rootdata) -
               offsetof(FatSuperblock, ft_super.ffs_super.fs_root)) ==
              offsetof(FatDirNode, fdn_data));
STATIC_ASSERT((offsetof(FatSuperblock, ft_fdat) -
               offsetof(FatSuperblock, ft_super.ffs_super.fs_root)) ==
              offsetof(FatDirNode, fdn_fdat));



/************************************************************************/
/* Filesystem Type register/unregister                                  */
/************************************************************************/
#ifdef CONFIG_BUILDING_KERNEL_CORE
INTERN ATTR_FREETEXT void KCALL kernel_initialize_fat_driver(void)
#else  /* CONFIG_BUILDING_KERNEL_CORE */
PRIVATE DRIVER_INIT ATTR_FREETEXT void KCALL Fat_Init(void)
#endif /* !CONFIG_BUILDING_KERNEL_CORE */
{
	ffilesys_register(&Fat_Filesys);
}

#ifndef CONFIG_BUILDING_KERNEL_CORE
PRIVATE DRIVER_FINI void KCALL Fat_Fini(void) {
	ffilesys_unregister(&Fat_Filesys);
}
#endif /* !CONFIG_BUILDING_KERNEL_CORE */

DECL_END

#endif /* CONFIG_USE_NEW_FS */

#endif /* !GUARD_MODFAT_FAT_C */
