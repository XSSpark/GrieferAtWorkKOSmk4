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
#ifndef GUARD_KERNEL_SRC_MEMORY_MMAN_MPART_TRIM_C
#define GUARD_KERNEL_SRC_MEMORY_MMAN_MPART_TRIM_C 1
#define __WANT_MPART__mp_nodlsts
#define __WANT_MPART__mp_trmlop
#define _KOS_SOURCE 1

#include <kernel/compiler.h>

#include <kernel/mman.h>
#include <kernel/mman/mfile.h>
#include <kernel/mman/mnode.h>
#include <kernel/mman/mpart.h>
#include <kernel/mman/mpartmeta.h>
#include <kernel/swap.h>

#include <hybrid/atomic.h>

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>



/* Alongside mpart_merge(), there should also be a function `mpart_trim()'
 * that will look at what's actually being mapped about the part, and will
 * try to trim/split the part, such  that unmapped portions are no  longer
 * being represented.
 *
 * Without special handling, the following will actually keep backing memory allocated:
 *
 * >> mmap(0x01234000, PAGESIZE, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANON, -1, 0);
 * >> mmap(0x01235000, PAGESIZE, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANON, -1, 0); // Automatically merged
 * >> mmap(0x01236000, PAGESIZE, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANON, -1, 0); // Automatically merged
 * >> munmap(0x01235000, PAGESIZE); // Automatically cases a split, but only within mem-nodes (mpart is unaffected)
 *
 * The idea here is that  the munmap() calls `mpart_trim()', which  will
 * (asynchronously, and only in case the part is anonymous) look at  the
 * part's set of mapped nodes and figure out which parts of the part (if
 * any)  are actually in use. Any part that's not in use from the part's
 * edges  is then simply  trimmed, and unused holes  from the middle are
 * handled by trying to split the part, such that each consecutive chunk
 * of used memory has its own mpart, and thus doesn't require the entire
 * region to be kept in-core all at once. */

DECL_BEGIN

#ifndef NDEBUG
#define DBG_memset(dst, byte, num_bytes) memset(dst, byte, num_bytes)
#else /* !NDEBUG */
#define DBG_memset(dst, byte, num_bytes) (void)0
#endif /* NDEBUG */

STATIC_ASSERT_MSG(offsetof(struct mpart, _mp_trmlop_mp.olo_func) == offsetof(struct mpart, _mp_trmlop_mm.olo_func) &&
                  offsetafter(struct mpart, _mp_trmlop_mp.olo_func) == offsetafter(struct mpart, _mp_trmlop_mm.olo_func) &&
                  offsetof(struct mpart, _mp_trmlop_mp.olo_func) == offsetof(struct mpart, _mp_trmplop_mm.oplo_func) &&
                  offsetafter(struct mpart, _mp_trmlop_mp.olo_func) == offsetafter(struct mpart, _mp_trmplop_mm.oplo_func) &&
                  offsetof(struct mpart, _mp_trmlop_mp.olo_func) == offsetof(struct mpart, _mp_trmplop_mp.oplo_func) &&
                  offsetafter(struct mpart, _mp_trmlop_mp.olo_func) == offsetafter(struct mpart, _mp_trmplop_mp.oplo_func) &&
                  offsetof(struct mpart, _mp_trmlop_mp.olo_func) == offsetof(struct mpart, mp_filent.rb_rhs) &&
                  offsetafter(struct mpart, _mp_trmlop_mp.olo_func) == offsetafter(struct mpart, mp_filent.rb_rhs),
                  "This is assumed by `_mpart_init_asanon()', which fills in `rb_rhs' as NULL "
                  "when called, which in turn must cause the `olo_func' of the lockops used to "
                  "be initialized to `NULL' as well.\n"
                  "Calls to `mpart_trim()' will then do an ATOMIC_CMPXCH on `olo_func' to start "
                  "an async trim operation of the mem-part!");



/* Detach the given mem-futex from its associated mem-part,
 * by clearing the futex's `mfu_part' field. - This must be
 * called  when deallocating the  backing part's range that
 * is occupied by `self'
 * NOTE: This function can safely  be called, even when  `self'
 *       has already been destroyed (i.w. `wasdestroyed(self)') */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mfutex_detach)(struct mfutex *__restrict self) {
	awref_clear(&self->mfu_part);
}


/* Indicate that the async mpart-trim operation has completed.
 * Once this function has been called, other threads can  once
 * again call `mpart_trim()' in order to initiate yet  another
 * async trim operation! */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mpart_trim_complete)(struct mpart *__restrict self) {
	ATOMIC_WRITE(self->_mp_trmlop_mp.olo_func, NULL);
}



/* Sort the given mem-node list by each node's `mn_partoff' */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mnode_list_sort_by_partoff)(struct mnode_list *__restrict self) {
	/* TODO */
	COMPILER_IMPURE();
	(void)self;
}


/* Trim `self' whilst holding all relevant locks:
 *   - mpart_lock_acquired(self);
 *   - !self->mp_meta || mpartmeta_ftxlock_writing(self->mp_meta);
 *   - mman_lock_acquired(self->mp_copy.each->mn_mman.filter(!wasdestroyed($)));
 *   - mman_lock_acquired(self->mp_share.each->mn_mman.filter(!wasdestroyed($)));
 */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mpart_trim_with_all_locks)(struct mpart *__restrict self) {
	/* Check  if `self' might possibly contain gaps that
	 * aren't being referenced by any of the part's mem-
	 * nodes.
	 *
	 * In order to find gaps, we can do this:
	 *  - Sort  the mem-node lists  by their `mn_partoff', and
	 *    use an iterator abstraction with 2 mem-node pointers
	 *    into each of the  lists that offsets a  next_after()
	 *    function to enumerate them in order.
	 *  - Then, enumerate all mem-nodes in order and look for
	 *    adjacent nodes with gaps in-between.
	 *
	 * For  leading/trailing  gaps, directly  trim  `self'. For
	 * leading gaps, also update the `mn_partoff' of all nodes.
	 *
	 * For gaps found elsewhere, punch a hole into the part,
	 * similar to  `mpart_split()'. -  However, since  we're
	 * already holding all of  the relevant locks, our  impl
	 * of that function's behavior would only require us  to
	 * alloc 1 additional mem-part  for every hole we  find.
	 *
	 * For every hole found like this, set-up a new mpart to  fill
	 * in the hole, and have it take the place of the range  below
	 * the  gap. - Then release locks to all mmans associated with
	 * the lopart, that aren't also  present in `self'; this  way,
	 * we, and our caller will still be holding locks to all mmans
	 * associated with nodes from `self' */

	/* Step #1: Since this isn't normally a  requirement,
	 *          make sure that mem-node lists are sorted. */
	mnode_list_sort_by_partoff(&self->mp_share);
	mnode_list_sort_by_partoff(&self->mp_copy);

	/* TODO */

	/* Indicate that the trim operation has completed. */
	mpart_trim_complete(self);
}





/* Detach all futex objects reachable from `self' */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mfutex_tree_detachall)(struct mfutex *__restrict self) {
	struct mfutex *lhs, *rhs;
again:
	mfutex_detach(self);
	lhs = self->mfu_mtaent.rb_lhs;
	rhs = self->mfu_mtaent.rb_rhs;
	DBG_memset(&self->mfu_mtaent, 0xcc, sizeof(self->mfu_mtaent));
	if (lhs) {
		if (rhs)
			mfutex_tree_detachall(rhs);
		self = lhs;
		goto again;
	}
	if (rhs) {
		self = rhs;
		goto again;
	}
}


/************************************************************************/
/* Cleanup helper functions                                             */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mchunk_freemem)(struct mchunk *__restrict self) {
	page_free(self->mc_start, self->mc_size);
}

PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mchunk_freeswp)(struct mchunk *__restrict self) {
	swap_free(self->mc_start, self->mc_size);
}

PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mchunkvec_freemem)(struct mchunk *__restrict vec, size_t count) {
	size_t i;
	for (i = 0; i < count; ++i)
		mchunk_freemem(&vec[i]);
}

PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mchunkvec_freeswp)(struct mchunk *__restrict vec, size_t count) {
	size_t i;
	for (i = 0; i < count; ++i)
		mchunk_freeswp(&vec[i]);
}
/************************************************************************/


/* Set the effective size of `self' to `0', and free all backing storage. */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mpart_clear)(struct mpart *__restrict self) {
	struct mpartmeta *meta;
	if ((meta = self->mp_meta) != NULL) {
		/* Detach all futex objects by clearing their `mfu_part' pointers. */
		if (meta->mpm_ftx) {
			mfutex_tree_detachall(meta->mpm_ftx);
			meta->mpm_ftx = NULL;
		}
	}

	/* Free backing memory/swap. */
	switch (self->mp_state) {

	case MPART_ST_SWP:
		if (!(self->mp_flags & MPART_F_NOFREE))
			mchunk_freeswp(&self->mp_swp);
		break;

	case MPART_ST_MEM:
		if (!(self->mp_flags & MPART_F_NOFREE))
			mchunk_freemem(&self->mp_mem);
		break;

	case MPART_ST_SWP_SC:
		if (!(self->mp_flags & MPART_F_NOFREE))
			mchunkvec_freeswp(self->mp_swp_sc.ms_v, self->mp_swp_sc.ms_c);
		kfree(self->mp_swp_sc.ms_v);
		break;

	case MPART_ST_MEM_SC:
		if (!(self->mp_flags & MPART_F_NOFREE))
			mchunkvec_freemem(self->mp_mem_sc.ms_v, self->mp_mem_sc.ms_c);
		kfree(self->mp_mem_sc.ms_v);
		break;

	default:
		break;
	}

	/* Deallocate a dynamically allocated block-status-bitset. */
	if (self->mp_blkst_ptr != NULL && !(self->mp_flags & MPART_F_BLKST_INL)) {
		kfree(self->mp_blkst_ptr);
		self->mp_blkst_ptr = NULL;
	}

	/* Change the part into a void-state. */
	self->mp_state = MPART_ST_VOID;

	/* Set mp_minaddr/mp_maxaddr to indicate an empty part. */
	self->mp_minaddr = (pos_t)PAGESIZE;
	self->mp_maxaddr = (pos_t)PAGESIZE - 1;

	/* If not already referencing one of the generic anon-files,
	 * change  the part's  associated file  to one  of them now! */
	if (!(self->mp_file >= mfile_anon &&
	      self->mp_file < COMPILER_ENDOF(mfile_anon))) {
		REF struct mfile *newfile, *oldfile;
		oldfile       = self->mp_file;
		newfile       = incref(&mfile_anon[oldfile->mf_blockshift]);
		self->mp_file = newfile;
		decref_unlikely(oldfile);
	}

	/* Clear the `MPART_F_GLOBAL_REF' bit. */
	if (ATOMIC_FETCHAND(self->mp_flags, ~MPART_F_GLOBAL_REF) & MPART_F_GLOBAL_REF)
		decref_nokill(self);
}




/* Increment the reference counter of every (not already-destroyed)
 * mman that can be reached via the `mp_copy' and `mp_share' chains
 * of `self'.
 * @return: true:  At least 1 mman was incref'd.
 * @return: false: No, or only dead mmans referenced. */
PRIVATE NOBLOCK NONNULL((1)) bool
NOTHROW(FCALL mpart_foreach_mmans_incref)(struct mpart *__restrict self) {
	bool result = false;
	unsigned int i;
	for (i = 0; i < COMPILER_LENOF(self->_mp_nodlsts); ++i) {
		struct mnode *node;
		LIST_FOREACH (node, &self->_mp_nodlsts[i], mn_link)
			result |= tryincref(node->mn_mman);
	}
	return result;
}

/* Decref all mmans of `self' (skipping those that were already destroyed) */
PRIVATE NOBLOCK WUNUSED NONNULL((1)) void
NOTHROW(FCALL mpart_decref_all_mmans)(struct mpart const *__restrict self) {
	unsigned int i;
	for (i = 0; i < COMPILER_LENOF(self->_mp_nodlsts); ++i) {
		struct mnode *node;
		LIST_FOREACH (node, &self->_mp_nodlsts[i], mn_link) {
			if likely(!wasdestroyed(node->mn_mman))
				decref_unlikely(node->mn_mman);
		}
	}
}


/* Like `mpart_mappedby_mman()', but stop checking nodes when `stop'
 * is reached. Additionally, `stop' isn't considered to be apart  of
 * the list of nodes to test for mapping `mm' */
PRIVATE NOBLOCK ATTR_PURE WUNUSED NONNULL((1, 3)) bool
NOTHROW(FCALL mpart_mappedby_mman_before)(struct mpart const *__restrict self,
                                          struct mnode const *stop,
                                          struct mman const *__restrict mm) {
	unsigned int i;
	for (i = 0; i < COMPILER_LENOF(self->_mp_nodlsts); ++i) {
		struct mnode *node;
		LIST_FOREACH (node, &self->_mp_nodlsts[i], mn_link) {
			if (node == stop)
				return false;
			if (node->mn_mman == mm)
				return true;
		}
	}
	return false;
}


/* Release locks to every unique mman with nodes that map `self'.
 * For every mman, only a single lock is released, and only locks
 * to mmans to nodes before `stop' are released (unless `stop' is
 * given as `NULL', in which case _all_ locks are released) */
PRIVATE NOBLOCK WUNUSED NONNULL((1)) void
NOTHROW(FCALL mpart_unlock_all_mmans)(struct mpart const *__restrict self,
                                      struct mnode const *stop DFL(NULL)) {
	struct mnode *node;
	unsigned int i;
	for (i = 0; i < COMPILER_LENOF(self->_mp_nodlsts); ++i) {
		LIST_FOREACH (node, &self->_mp_nodlsts[i], mn_link) {
			if (node == stop)
				return; /* Stop on this node! */
			if unlikely(wasdestroyed(node->mn_mman))
				continue; /* Skip destroyed mmans */
			if (mpart_mappedby_mman_before(self, node, node->mn_mman))
				continue; /* Already unlocked before... */
			mman_lock_release(node->mn_mman);
		}
	}
}


/* Try to acquire locks to all of the mmans of `self'. (skipping dead mmans)
 * If doing so would block for one  of the mmans, release all locks  already
 * acquired, and return a pointer to the blocking mman. */
PRIVATE NOBLOCK WUNUSED NONNULL((1)) struct mman *
NOTHROW(FCALL mpart_lock_all_mmans)(struct mpart const *__restrict self) {
	struct mnode *node;
	unsigned int i;
	for (i = 0; i < COMPILER_LENOF(self->_mp_nodlsts); ++i) {
		LIST_FOREACH (node, &self->_mp_nodlsts[i], mn_link) {
			if unlikely(wasdestroyed(node->mn_mman))
				continue; /* Skip destroyed mmans */
			if (mman_lock_tryacquire(node->mn_mman))
				continue; /* Successfully locked the mman */
			if (mpart_mappedby_mman_before(self, node, node->mn_mman))
				continue; /* We've already acquired a lock to this mman in the part. */
			/* Oops... We've got a blocking one here! */
			mpart_unlock_all_mmans(self, node);
			return node->mn_mman;
		}
	}
	return NULL;
}



/* NOTE: This function inherits a reference to `container_of(_lop, struct mpart, _mp_trmplop_mm)' */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mpart_trim_mmplop)(Tobpostlockop(mman) *__restrict _lop,
                                 struct mman *__restrict UNUSED(mm));

/* NOTE: This function inherits a reference to `container_of(_lop, struct mpart, _mp_trmlop_mm)' */
PRIVATE NOBLOCK NONNULL((1)) Tobpostlockop(mman) *
NOTHROW(FCALL mpart_trim_mmlop)(Toblockop(mman) *__restrict _lop,
                                struct mman *__restrict UNUSED(mm)) {
	REF struct mpart *self;
	self = container_of(_lop, struct mpart, _mp_trmlop_mm);
	ATOMIC_WRITE(self->_mp_trmplop_mm.oplo_func, &mpart_trim_mmplop);
	return &self->_mp_trmplop_mm;
}


/* Same  as  `mpart_trim_locked()', but  the caller
 * is also holding a lock to the part's futex-tree. */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mpart_trim_locked_ftx)(struct mpart *__restrict self) {

	/* Try to incref() all alive mmans, thus keeping them alive and allowing
	 * us  to try to acquire locks to each of them, without some (or all) of
	 * them suddenly being destroyed while we're still busy.
	 *
	 * If we don't find any alive mmans, then we know that the effective area
	 * mapped by mem-nodes of `self' is empty, meaning that we can clear  the
	 * mem-part in its entirety! */
	if unlikely(!mpart_foreach_mmans_incref(self)) {
		mpart_clear(self);
		/* Indicate that the async mpart-trim operation has completed. */
		mpart_trim_complete(self);
		return;
	}

	/* Try to acquire locks to  all of the mmans  that are mapping this  part.
	 * This is needed so we can get piece together a consistent (non-volatile)
	 * view of all of the regions of `self' that are actually used. */
	{
		struct mman *blocking_mm;
		blocking_mm = mpart_lock_all_mmans(self);
		if unlikely(blocking_mm) {
			incref(blocking_mm);
			mpart_decref_all_mmans(self);
			/* asynchronously wait for the lock of this mman to become available. */
			ATOMIC_WRITE(self->_mp_trmlop_mm.olo_func, &mpart_trim_mmlop);
			SLIST_ATOMIC_INSERT(&FORMMAN(blocking_mm, thismman_lockops),
			                    &self->_mp_trmlop_mm, olo_link);
			_mman_lockops_reap(blocking_mm);
			decref_unlikely(blocking_mm);
			return;
		}
	}

	/* Continue the trim operation now that we're holding  locks
	 * to the part itself, as well as all of the relevant mmans. */
	mpart_trim_with_all_locks(self);

	/* Release locks & references acquired above. */
	mpart_unlock_all_mmans(self);
	mpart_decref_all_mmans(self);
}



/* We can re-use  the mman-post-lock function  for the  async-futex-lock-
 * acquired code-path. Technically, we could also write a more  optimized
 * version  that could  then make assumptions  based on the  fact that it
 * knows  that the  mem-part being  trimmed can't  possibly get destroyed
 * while it's working (since the reap-caller will be holding a reference,
 * but  givent hat  the async-futex-lock  code-path is  quite rare as-is,
 * that's  not  really necessary,  given  that the  more  general version
 * already quired for mman-locks works just as well!) */
#define mpart_trim_ftxplop (*(Tobpostlockop_callback_t(mpart))&mpart_trim_mmplop)

PRIVATE NOBLOCK NONNULL((1)) Tobpostlockop(mpart) *
NOTHROW(FCALL mpart_trim_ftxlop)(Toblockop(mpart) *__restrict _lop,
                                 REF struct mpart *__restrict self) {
	assert(_lop == &self->_mp_trmlop_mp);
	ATOMIC_WRITE(self->_mp_trmplop_mp.oplo_func, &mpart_trim_ftxplop);
	return &self->_mp_trmplop_mp;
}


/* Same as `mpart_trim()', but  don't inherit a refernece,  and
 * assume that the caller is currently holding a lock to `self'
 * NOTE: This function also assumes that `_mp_trmlop*.olo_func'
 *       is non-NULL upon entry! */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mpart_trim_locked)(struct mpart *__restrict self) {
	struct mpartmeta *meta;
	assertf(mpart_isanon(self),
	        "We've already checked this earlier, and once a part "
	        "has become anon, it must never become non-anon!");
	/* If necessary, acquire yet another lock to the meta-data controller of `self' */
	if likely((meta = self->mp_meta) == NULL) {
		mpart_trim_locked_ftx(self);
	} else if (mpartmeta_ftxlock_trywrite(meta)) {
		mpart_trim_locked_ftx(self);
		mpartmeta_ftxlock_endwrite(meta, self);
	} else {
		/* Must acquire the futex-lock asynchronously. */
		incref(self); /* The reference inherited by `mpart_trim_ftxlop' */
		ATOMIC_WRITE(self->_mp_trmlop_mp.olo_func, &mpart_trim_ftxlop);
		/* NOTE: No need for a 2nd incref(self) to prevent `self' from being
		 *       destroyed before we get to  reap it! Our caller is  already
		 *       holding that reference! */
		SLIST_ATOMIC_INSERT(&meta->mpm_ftxlops, &self->_mp_trmlop_mp, olo_link);
		_mpartmeta_ftxlock_reap(meta, self);
	}
}


PRIVATE NOBLOCK NONNULL((1)) Tobpostlockop(mpart) *
NOTHROW(FCALL mpart_trim_mplop)(Toblockop(mpart) *__restrict _lop,
                                REF struct mpart *__restrict self) {
	assert_assume(_lop == &self->_mp_trmlop_mp);
	(void)_lop;
	mpart_trim_locked(self);
	/* *_nokill, because the caller must also be holding a reference to `self'! */
	decref_nokill(self);
	return NULL;
}


/* NOTE: This function inherits a reference to `container_of(_lop, struct mpart, _mp_trmplop_mm)' */
PRIVATE NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mpart_trim_mmplop)(Tobpostlockop(mman) *__restrict _lop,
                                 struct mman *__restrict UNUSED(mm)) {
	REF struct mpart *self;
	self = container_of(_lop, struct mpart, _mp_trmplop_mm);
	if (ATOMIC_CMPXCH(self->mp_refcnt, 1, 0))
		goto do_destroy;

	/* The lock to  `mm' did become  available at one  point.
	 * As such, re-attempt the async `mpart_trim()' operation
	 * by trying to get a new lock for `self' again. If  this
	 * fails, then simply enqueue `mpart_trim_mplop()'! */
	if (mpart_lock_tryacquire(self)) {
		/* Do the actual trimming! */
		mpart_trim_locked(self);
		mpart_lock_release(self);
	} else {
		/* The part lock isn't available.
		 * As such, we muss use `mpart_trim_mplop()' in order
		 * to asynchronously  wait for  a lock  to the  part! */
		ATOMIC_WRITE(self->_mp_trmlop_mp.olo_func, &mpart_trim_mplop);

		/* Prevent the part from dying while in `_mpart_lockops_reap()'
		 * This reference is dropped further down below. */
		incref(self);
		SLIST_ATOMIC_INSERT(&self->mp_lockops, &self->_mp_trmlop_mp, olo_link);
		_mpart_lockops_reap(self);
	}
	/* Drop the reference to the part.
	 * Note that this may result in the part dying, since
	 * we get here via an mman-lock, as opposed to a lock
	 * to the part itself (meaning our caller may not  be
	 * holding a reference to `self' at this point!)
	 *
	 * Note that this  decref() is  unlikely to  actually
	 * destroy  the part, because we've already attempted
	 * to ATOMIC_CMPXCH() the reference counter to 0, and
	 * it didn't work back then. */
	decref_unlikely(self);
	return;
do_destroy:
	mpart_destroy(self);
}




/* If `self' is an anonymous mem-part, asynchronously acquire a
 * lock to `self' and compare the min/max-addr bounds of `self'
 * against the portions that are actually mapped by  mem-nodes.
 * If it is found that leading/trailing portions of `self'  are
 * not mapped by  any mem-node, trim  those parts from  `self'.
 * If there are holes within `self' of pages not mapped by  any
 * mem-nodes,  asynchronously split `self', and update nodes in
 * order to get rid of the relevant ranges.
 * This function should  be called  whenever mem-node  mappings
 * of `self' have been removed, in order to drop the references
 * that were originally held by those nodes.
 * NOTE: When `self' isn't anonymous, simply `decref(self)'!
 * NOTE: This function usually doesn't need to be called directly.
 *       Instead, it is  called from  `mnode_destroy()' to  decref
 *       the associated part after the node has been removed  from
 *       the list of node-mappings of `self' */
PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(FCALL mpart_trim)(/*inherit(always)*/ REF struct mpart *__restrict self) {

	/* Check for special case: can we destroy the part immediately! */
	if (ATOMIC_CMPXCH(self->mp_refcnt, 1, 0))
		goto do_destroy;

	/* Check for special case: the part isn't anonymous. */
	if (!mpart_isanon_atomic(self))
		goto do_normal_decref;

	/* Try to get a lock to the part. */
	if (mpart_lock_tryacquire(self)) {
		/* Deal with the (very unlikely) race condition of another thread enqueuing
		 * yet another async `mpart_trim()' operation after we've acquired our lock
		 * to `self'. - It can happen, and if it does, then  `mpart_lock_release()'
		 * will reaping once we  release the lock ~should~  cause the lockop to  be
		 * serviced. */
		if unlikely(!ATOMIC_CMPXCH(self->_mp_trmlop_mp.olo_func,
		                           NULL, &mpart_trim_mplop)) {
			mpart_lock_release_f(self);
			goto reap_and_normal_decref;
		}

		/* Do the actual trimming! */
		mpart_trim_locked(self);
		mpart_lock_release(self);
	} else {
		/* Schedule an async lock-op.
		 * If such an operation is already in-progress, then don't do anything,
		 * since someone else will already end up doing what our caller  wanted
		 * us to kick-start! */
		if (!ATOMIC_CMPXCH(self->_mp_trmlop_mp.olo_func, NULL, &mpart_trim_mplop))
			goto do_normal_decref;

		/* Get another reference so `self' is kept alive, even
		 * if reaping the part  below ends up succeeding,  and
		 * would otherwise cause the part to be destroyed. */
		incref(self);

		/* We've just kick-started the async-trim process. - Now we need to
		 * commit and enqueue the part into its own lock-op list. Also note
		 * that  by doing this, `mpart_trim_mplop' essentially inherits our
		 * caller-given reference to the mem-part! */
		SLIST_ATOMIC_INSERT(&self->mp_lockops, &self->_mp_trmlop_mp, olo_link);

		/* With the new lockop added, reap in case the lock became available. */
reap_and_normal_decref:
		_mpart_lockops_reap(self);
	}
do_normal_decref:
	/* Finally, drop the reference given by our caller. */
	decref_unlikely(self);
	return;
do_destroy:
	mpart_destroy(self);
}


DECL_END

#endif /* !GUARD_KERNEL_SRC_MEMORY_MMAN_MPART_TRIM_C */
