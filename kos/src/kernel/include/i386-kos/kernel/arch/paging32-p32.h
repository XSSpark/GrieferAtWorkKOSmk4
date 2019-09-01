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
#ifndef GUARD_KERNEL_INCLUDE_I386_KOS_KERNEL_ARCH_PAGING32_P32_H
#define GUARD_KERNEL_INCLUDE_I386_KOS_KERNEL_ARCH_PAGING32_P32_H 1

#include <kernel/compiler.h>

#include <kernel/types.h>

#include <kos/kernel/paging.h>

#include <stdbool.h>

#ifndef CONFIG_NO_PAGING_P32

DECL_BEGIN

/* To differentiate between hints and allocated, but non-present pages, we use this:
 *                       P32_PAGE_FPREPARED
 *                       |
 *                       |         P32_PAGE_FISAHINT
 *                       |         |
 *                       |         |P32_PAGE_FPRESENT
 *                       |         ||
 * E XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX1: Page:  4KiB-page (P32_PAGE_FADDR_4KIB)
 * 1 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX10: Hint:  DATA & P32_PAGE_FHINT
 *   00000000000000000000XXXXXXXXXX00: Unused with meta-data (e.g. `P32_PAGE_FPREPARED')
 *   00000000000000000000000000000000: Unused (P32_PAGE_ABSENT)
 *    3 2 2 2 2 2 1 1 1 1 1 8 6 4 2 0
 *    0 8 6 4 2 0 8 6 4 2 0
 *
 *                           P32_PAGE_F4MIB
 *                           |
 *                           |      P32_PAGE_FPRESENT
 *                           |      |
 * E XXXXXXXXXXXXXXXXXXXXXXXX1XXXXXX1: Page:  Large page mapping P32_PAGE_FADDR_4MIB
 * 2 XXXXXXXXXXXXXXXXXXXXXXXX0XXXXXX1: Owned: page_freeone(DATA & P32_PAGE_FVECTOR) (present)
 *   00000000000000000000000000000000: Unused (P32_PAGE_ABSENT)
 *    3 2 2 2 2 2 1 1 1 1 1 8 6 4 2 0
 *    0 8 6 4 2 0 8 6 4 2 0
 *
 * NOTE: All entires of E2 >= 768 are always allocated (these are the ones
 *       responsible for mapping kernel-space at 0xc0000000-0xffffffff), and
 *       always point to E1-vectors, or [const] and present 4MiB pages that
 *       will never go away for the entire duration of KOS running (these pages
 *       may contain the kernel core itself, which is done as an optimization
 *       to simplify management of the core itself by allowing the CPU to cache
 *       the entire kernel core using only 1 or 2 TLB entires.
 *    -> Since only 2 indirections exist (`struct p32_pdir::p_e2' and `union p32_pdir_e2::p_e1'),
 *       both of which are always pre-allocated/or const-initialized for addresses >= 0xc0000000,
 *       there is no need to prepare kernel-space memory for paging before mapping memory. I.e.:
 *       when PAE integration is disabled, `paging32.h' can `#undef CONFIG_PAGEDIR_NEED_PERPARE_FOR_KERNELSPACE'
 *
 */

/* The minimum alignment required for pointers passed to `pagedir_maphint()' */
#define P32_PAGEDIR_MAPHINT_ALIGNMENT  4

#define P32_PAGE_SHIFT      12 /* Shift to convert between pages and addresses. */
#define P32_PAGE_ALIGN      __UINT32_C(0x00001000) /* Required page alignment. */
#define P32_PAGE_SIZE       __UINT32_C(0x00001000) /* Required page size. */
#define P32_PAGE_FVECTOR    __UINT32_C(0xfffff000) /* [bit(12:31)] Mask of an inner vector. */
#define P32_PAGE_FHINT      __UINT32_C(0xfffffffe) /* Mask of page hints. */
#define P32_PAGE_FADDR_4KIB __UINT32_C(0xfffff000) /* Mask of the page address for 1KiB pages. */
#define P32_PAGE_OFFST_4KIB __UINT32_C(0x00000fff) /* Offset mask for 1KiB pages. */
#define P32_PAGE_FADDR_4MIB __UINT32_C(0xffc00000) /* Mask of the page address for 4MiB pages. */
#define P32_PAGE_OFFST_4MIB __UINT32_C(0x003fffff) /* Offset mask for 4MiB pages. */
#define P32_PAGE_FMASK      __UINT32_C(0x00000fff) /* Mask of page flag bits. */
#define P32_PAGE_ABSENT     __UINT32_C(0x00000000) /* Value found in E2 (`union p32_pdir_e2::p_word') to indicate that the E1-vector hasn't been allocated. */

#define P32_PAGE_FPRESENT   __UINT32_C(0x00000001) /* [bit(0)] The page is present (When not set, cause a PAGEFAULT that may be used for allocate/load-on-read). */
#define P32_PAGE_FISAHINT   __UINT32_C(0x00000002) /* [bit(1)][valid_if(!P32_PAGE_FPRESENT)] The page has been hinted. */
#define P32_PAGE_FWRITE     __UINT32_C(0x00000002) /* [bit(1)] The page is writable. */
#define P32_PAGE_FUSER      __UINT32_C(0x00000004) /* [bit(2)] User-space may access this page (read, or write). */
#define P32_PAGE_FPWT       __UINT32_C(0x00000008) /* [bit(3)] Page-level write-through. */
#define P32_PAGE_FPCD       __UINT32_C(0x00000010) /* [bit(4)] Page-level cache disable. */
#define P32_PAGE_FACCESSED  __UINT32_C(0x00000020) /* [bit(5)] The page has been read from, or written to. */
#define P32_PAGE_FDIRTY     __UINT32_C(0x00000040) /* [bit(6)] The page has been written to. (only valid in entries that map physical memory, rather than point to other vectors) */
#define P32_PAGE_F4MIB      __UINT32_C(0x00000080) /* [bit(7)] Directly map a physical address on level #2 (for use in `union p32_pdir_e2::p_word'). */
#define P32_PAGE_FGLOBAL    __UINT32_C(0x00000100) /* [bit(8)] Set to optimize mappings that appear at the same location in all
                                                    *          directories it appears inside of (aka: Kernel-allocated stack/memory). */
#define P32_PAGE_FPREPARED  __UINT32_C(0x00000800) /* [bit(11)][KOS_SPECIFIC] Prevent the associated mapping from being flattened. (May only appear in E1-entries)
                                                    * This flag is used to indicate that the associated page is currently prepared,
                                                    * and that its containing vectors shouldn't be merged before it becomes unprepared. */
#define P32_PAGE_FPAT_4KIB  __UINT32_C(0x00000080) /* [bit(7)] Indirectly determines the memory type used to access the 4-KByte page referenced by this entry. */
#define P32_PAGE_FPAT_4MIB  __UINT32_C(0x00001000) /* [bit(12)] Indirectly determines the memory type used to access the 4-MByte page referenced by this entry. */


#define P32_PDIR_VEC1INDEX(ptr)  ((__CCAST(u32)(ptr) >> 12) & 0x3ff) /* For `struct p32_pdir::p_e2' */
#define P32_PDIR_VEC2INDEX(ptr)   (__CCAST(u32)(ptr) >> 22)          /* For `union p32_pdir_e2::p_e1' */

#define P32_PDIR_VEC1INDEX_VPAGE(vpage)   (__CCAST(u32)(vpage) & 0x3ff) /* For `struct p32_pdir::p_e2' */
#define P32_PDIR_VEC2INDEX_VPAGE(vpage)   (__CCAST(u32)(vpage) >> 10)   /* For `union p32_pdir_e2::p_e1' */
#define P32_PDIR_VECADDR(vec2, vec1)      ((__CCAST(u32)(vec2) << 22) | (__CCAST(u32)(vec1) << 12))

/* Pagesizes of different page directory levels. */
#define P32_PDIR_E1_SIZE     __UINT32_C(0x00001000) /* 4 KiB (Same as `PAGESIZE') */
#define P32_PDIR_E2_SIZE     __UINT32_C(0x00400000) /* 4 MiB */

#define P32_IS_4KIB_ALIGNED(addr) (((addr) & __UINT32_C(0x00000fff)) == 0)
#define P32_IS_4MIB_ALIGNED(addr) (((addr) & __UINT32_C(0x003fffff)) == 0)

/* Return the in-page offset of a regular pointer mapping,
 * or one that has been mapped within a 4MiB page. */
#define P32_PDIR_PAGEINDEX_4KIB(ptr) (__CCAST(unsigned int)(__CCAST(vm_virt_t)(ptr) & P32_PAGE_OFFST_4KIB))
#define P32_PDIR_PAGEINDEX_4MIB(ptr) (__CCAST(unsigned int)(__CCAST(vm_virt_t)(ptr) & P32_PAGE_OFFST_4MIB))

#define P32_PDIR_ALIGN  4096 /* Alignment required for instances of `struct p32_pdir' */
#define P32_PDIR_SIZE   4096 /* The total size of `struct p32_pdir' in bytes. */


#ifdef __CC__
union p32_pdir_e1 {
	/* Lowest-level page-directory entry. */
	u32                 p_word;      /* Mapping data. */
	PHYS u32            p_addr;      /* [MASK(P32_PAGE_FADDR_4KIB)]
	                                  * [valid_if(c_PAGE_FPRESENT)] _Physical_ page address. */
#define P32_PDIR_E1_IS1KIB(e1_word)    ((e1_word) & P32_PAGE_FPRESENT)
#define P32_PDIR_E1_ISHINT(e1_word)    (((e1_word) & (P32_PAGE_FPRESENT | P32_PAGE_FISAHINT)) == P32_PAGE_FISAHINT)
#define P32_PDIR_E1_ISUNUSED(e1_word)  (((e1_word) & (P32_PAGE_FPRESENT | P32_PAGE_FISAHINT)) == 0)
	struct {
		u32          d_present : 1;      /* P32_PAGE_FPRESENT */
		u32          d_writable : 1;     /* [valid_if(d_present)] P32_PAGE_FWRITE */
		u32          d_user : 1;         /* [valid_if(d_present)] P32_PAGE_FUSER */
		u32          d_pwt : 1;          /* [valid_if(d_present)] P32_PAGE_FPWT */
		u32          d_pcd : 1;          /* [valid_if(d_present)] P32_PAGE_FPCD */
		u32          d_accessed : 1;     /* [valid_if(d_present)] P32_PAGE_FACCESSED */
		u32          d_dirty : 1;        /* [valid_if(d_present)] P32_PAGE_FDIRTY */
		u32          d_pat : 1;          /* [valid_if(d_present)] P32_PAGE_FPAT_4KIB */
		u32          d_global : 1;       /* [valid_if(d_present)] P32_PAGE_FGLOBAL */
		u32          d_unused1_ign : 2;  /* [valid_if(d_present)] Ignored...  (0x200, 0x400) */
		u32          d_prepared : 1;     /* [valid_if(d_present)] P32_PAGE_FPREPARED */
		u32          d_addr : 20;        /* [valid_if(d_present)] P32_PAGE_FADDR_4KIB */
	} p_4kib;
};

union p32_pdir_e2 {
	/* TIER#2 page-directory entry. */
	u32                      p_word;      /* Mapping data. */
	PHYS u32                 p_addr;      /* [MASK(P32_PAGE_FADDR_4MIB)]
	                                       * [valid_if(P32_PDIR_E2_IS4MIB(p_word))]
	                                       * _Physical_ page address of a 4MiB page. */
#define P32_PDIR_E2_ISVEC1(e2_word)       (((e2_word) & (P32_PAGE_FPRESENT | P32_PAGE_F4MIB)) == P32_PAGE_FPRESENT)
#define P32_PDIR_E2_IS4MIB(e2_word)       (((e2_word) & (P32_PAGE_FPRESENT | P32_PAGE_F4MIB)) == (P32_PAGE_FPRESENT | P32_PAGE_F4MIB))
#define P32_PDIR_E2_ISUNUSED(e2_word)     ((e2_word) == P32_PAGE_ABSENT)
	PHYS union p32_pdir_e1 (*p_e1)[1024]; /* [MASK(P32_PAGE_FVECTOR)]
	                                       * [owned_if(P32_PDIR_E2_ISVEC1_OWNED(p_word) &&
	                                       *         ((self - :p_e2) < P32_PDIR_VEC2INDEX(KERNEL_BASE)))]
	                                       * [const_if((self - :p_e2) >= P32_PDIR_VEC2INDEX(KERNEL_BASE))]
	                                       * [valid_if(P32_PDIR_E2_ISVEC1(p_word))]
	                                       * _Physical_ pointer to a level #1 paging vector. */
	struct ATTR_PACKED {
		u32          v_present : 1;      /* P32_PAGE_FPRESENT */
		u32          v_writable : 1;     /* [valid_if(v_present)] P32_PAGE_FWRITE */
		u32          v_user : 1;         /* [valid_if(v_present)] P32_PAGE_FUSER */
		u32          v_pwt : 1;          /* [valid_if(v_present)] P32_PAGE_FPWT */
		u32          v_pcd : 1;          /* [valid_if(v_present)] P32_PAGE_FPCD */
		u32          v_accessed : 1;     /* [valid_if(v_present)] P32_PAGE_FACCESSED */
		u32          v_dirty_ign : 1;    /* [valid_if(v_present)] Ignored...  (P32_PAGE_FDIRTY) */
		u32          v_4mib_0 : 1;       /* [valid_if(v_present)] Must be 0  (P32_PAGE_F4MIB) */
		u32          v_global_ign : 1;   /* [valid_if(v_present)] Ignored...  (P32_PAGE_FGLOBAL) */
		u32          v_unused1_ign : 3;  /* [valid_if(v_present)] Ignored...  (0x200, 0x400, 0x800) */
		u32          v_e1 : 20;          /* [valid_if(v_present)][TYPE(union pae_pdir_e1(*)[1024])][owned] P32_PAGE_FVECTOR */
	} p_vec1;
	struct ATTR_PACKED {
		u32          d_present : 1;      /* P32_PAGE_FPRESENT */
		u32          d_writable : 1;     /* [valid_if(d_present)] P32_PAGE_FWRITE */
		u32          d_user : 1;         /* [valid_if(d_present)] P32_PAGE_FUSER */
		u32          d_pwt : 1;          /* [valid_if(d_present)] P32_PAGE_FPWT */
		u32          d_pcd : 1;          /* [valid_if(d_present)] P32_PAGE_FPCD */
		u32          d_accessed : 1;     /* [valid_if(d_present)] P32_PAGE_FACCESSED */
		u32          d_dirty : 1;        /* [valid_if(d_present)] P32_PAGE_FDIRTY */
		u32          d_4mib_1 : 1;       /* [valid_if(d_present)] Must be 1  (P32_PAGE_F4MIB) */
		u32          d_global : 1;       /* [valid_if(d_present)] P32_PAGE_FGLOBAL */
		u32          d_unused1_ign : 3;  /* [valid_if(v_present)] Ignored...  (0x200, 0x400, 0x800) */
		u32          d_pat : 1;          /* [valid_if(d_present)] P32_PAGE_FPAT_4MIB */
		u32          d_reserved1_0 : 8;  /* [valid_if(d_present)] Must be 0  (Reserved...) */
		u32          d_addr : 11;        /* [valid_if(d_present)] P32_PAGE_FADDR_4MIB */
	} p_4mib;
};
#endif /* __CC__ */



#ifdef __CC__
struct p32_pdir {
	union p32_pdir_e2   p_e2[1024];  /* Level#2 page directory mappings. */
};
#endif /* __CC__ */



#define P32_VM_KERNEL_PDIR_IDENTITY_BASE __UINT32_C(0xffc00000) /* E1 vectors are mapped here. */
#define P32_VM_KERNEL_PDIR_IDENTITY_SIZE __UINT32_C(0x00400000) /* 4MiB */
#define P32_VM_KERNEL_PDIR_RESERVED_BASE __UINT32_C(0xffc00000) /* Start of the address range reserved for page-directory self-modifications. */
#define P32_VM_KERNEL_PDIR_RESERVED_SIZE __UINT32_C(0x00400000) /* 4MiB */

#define P32_PDIR_E1_IDENTITY_BASE    __UINT32_C(0xffc00000) /* E1 vectors are mapped here. */
#define P32_PDIR_E2_IDENTITY_BASE    __UINT32_C(0xfffff000) /* The `p32_pdir::p_e2' vector is mapped here. */
#if 0
/* These are the actual addresses, as well as how they are calculated.
 * However, for clarity and compilation speed, we use the pre-computed versions above instead.
 * Still though, these versions are statically asserted to be equal to the pre-computed ones above! */
#define P32_PDIR_E2_IDENTITY_BASE (P32_PDIR_E1_IDENTITY_BASE + (P32_PDIR_VEC2INDEX(P32_PDIR_E1_IDENTITY_BASE) * P32_PDIR_E1_SIZE))
#endif

#ifdef __CC__
typedef union p32_pdir_e1
p32_pdir_e1_identity_t[1024 /* P32_PDIR_VEC2INDEX(pointer) */]
                      [1024 /* P32_PDIR_VEC1INDEX(pointer) */];
typedef union p32_pdir_e2
p32_pdir_e2_identity_t[1024 /* P32_PDIR_VEC2INDEX(pointer) */];

/* E1 identity mapping access for the current page directory.
 *    Index #0: VEC2 -- The same index as used in `p32_pdir::p_e2'
 *    Index #1: VEC1 -- The same index as used in `p32_pdir_e2::p_e1'
 * Example:
 * >> VIRT void *pointer = get_pointer();
 * >> union p32_pdir_e1 *desc;
 * >> unsigned int vec2 = P32_PDIR_VEC2INDEX(pointer);
 * >> unsigned int vec1 = P32_PDIR_VEC1INDEX(pointer);
 * >> if (!(P32_PDIR_E2_IDENTITY[vec2].p_flag & P32_PAGE_FPRESENT)) {
 * >>     ...; // Pointer isn't mapped.
 * >> } else if (P32_PDIR_E2_IDENTITY[vec2].p_flag & P32_PAGE_F4MIB) {
 * >>     ...; // Pointer is mapped as a 4MiB mapping
 * >> } else {
 * >>     // Load the descriptor
 * >>     desc = &P32_PDIR_E1_IDENTITY[vec2][vec1];
 * >>     if (!(desc->p_flag & X86_PAGE_FPRESENT)) {
 * >>         ...; // Pointer isn't mapped.
 * >>     } else {
 * >>         ...; // `desc' now points to the descriptor for the `pointer'
 * >>     }
 * >> }
 */
#define P32_PDIR_E1_IDENTITY  (*(p32_pdir_e1_identity_t *)P32_PDIR_E1_IDENTITY_BASE)
#define P32_PDIR_E2_IDENTITY  (*(p32_pdir_e2_identity_t *)P32_PDIR_E2_IDENTITY_BASE)

#else /* __CC__ */

#define P32_PDIR_E1_IDENTITY  P32_PDIR_E1_IDENTITY_BASE
#define P32_PDIR_E2_IDENTITY  P32_PDIR_E2_IDENTITY_BASE

#endif /* !__CC__ */



#if defined(__CC__) && defined(CONFIG_BUILDING_KERNEL_CORE)
/* Initialize the given page directory.
 * The caller is required to allocate the page directory
 * controller itself, which must be aligned and sized
 * according to `PAGEDIR_ALIGN' and `PAGEDIR_SIZE'. */
INTDEF NOBLOCK NONNULL((1)) void
NOTHROW(FCALL p32_pagedir_init)(VIRT struct p32_pdir *__restrict self,
                                PHYS vm_phys_t phys_self);

/* Finalize a given page directory. */
INTDEF NOBLOCK NONNULL((1)) void
NOTHROW(FCALL p32_pagedir_fini)(VIRT struct p32_pdir *__restrict self);


/* Prepare the page directory for a future map() operation.
 * The full cycle of a single mapping then looks like this:
 * >> p32_pagedir_prepare_map(...);
 * >> p32_pagedir_map(...);
 * >> p32_pagedir_unmap(...);
 * >> p32_pagedir_unprepare_map(...);
 * NOTE: `p32_pagedir_prepare_map_keep()' is the same as `p32_pagedir_prepare_map()', but
 *        will not undo already successfully made preparations after a later one fails.
 *        This will include the undoing of redundant preparations of the given range that
 *        were made in prior calls.
 * @return: true:  Successfully allocated structures required for creating mappings.
 * @return: false: Insufficient physical memory to change mappings. */
INTDEF NOBLOCK WUNUSED bool NOTHROW(FCALL p32_pagedir_prepare_mapone)(VIRT vm_vpage_t virt_page);
INTDEF NOBLOCK WUNUSED bool NOTHROW(FCALL p32_pagedir_prepare_map)(VIRT vm_vpage_t virt_page, size_t num_pages);
INTDEF NOBLOCK WUNUSED bool NOTHROW(FCALL p32_pagedir_prepare_map_keep)(VIRT vm_vpage_t virt_page, size_t num_pages);
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_unprepare_mapone)(VIRT vm_vpage_t virt_page);
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_unprepare_map)(VIRT vm_vpage_t virt_page, size_t num_pages);


/* Set a mapping hint for pages apart of the given virtual memory range.
 * Mapping hints are overwritten once a page has been mapped, and when
 * not specified, will default to `NULL'.
 * Their main purpose is to be accessible through atomic means, allowing
 * them to be used by the PAGE_FAULT handler, while still ensuring that
 * access remains non-blocking. */
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_maphintone)(VIRT vm_vpage_t virt_page, VIRT /*ALIGNED(P32_PAGEDIR_MAPHINT_ALIGNMENT)*/void *hint);
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_maphint)(VIRT vm_vpage_t virt_page, size_t num_pages, VIRT /*ALIGNED(P32_PAGEDIR_MAPHINT_ALIGNMENT)*/void *hint);

/* Return the given of the given page, or NULL if no hint has been mapped. */
INTDEF NOBLOCK WUNUSED void *NOTHROW(FCALL p32_pagedir_gethint)(VIRT vm_vpage_t virt_page);

/* Create/delete a page-directory mapping.
 * @param: perm: A set of `PAGEDIR_MAP_F*' detailing how memory should be mapped. */
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_mapone)(VIRT vm_vpage_t virt_page, PHYS vm_ppage_t phys_page, u16 perm);
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_map)(VIRT vm_vpage_t virt_page, size_t num_pages, PHYS vm_ppage_t phys_page, u16 perm);

/* Special variants of `pagedir_mapone()' that should be used to
 * temporary override the mapping of a single, prepared page.
 * These functions are mainly intended for use with `_this_trampoline_page', allowing
 * each thread to push/pop its trampoline page, with doing so actually being an atomic
 * operation in the sense that the data is entirely thread-private, while modifications
 * do not require any kind of lock.
 * NOTE: If the page had been mapped, `pagedir_pop_mapone()' will automatically sync the page. */
INTDEF NOBLOCK WUNUSED uintptr_t NOTHROW(FCALL p32_pagedir_push_mapone)(VIRT vm_vpage_t virt_page, PHYS vm_ppage_t phys_page, u16 perm);
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_pop_mapone)(VIRT vm_vpage_t virt_page, uintptr_t backup);

/* Unmap pages from the given address range. (requires that the given area be prepared) */
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_unmapone)(VIRT vm_vpage_t virt_page);
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_unmap)(VIRT vm_vpage_t virt_page, size_t num_pages);

/* Remove write-permissions from the given address range. (requires that the given area be prepared) */
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_unwriteone)(VIRT vm_vpage_t virt_page);
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_unwrite)(VIRT vm_vpage_t virt_page, size_t num_pages);

/* Unmap the entirety of user-space.
 * NOTE: Unlike all other unmap() functions, this one guaranties that it
 *       can perform the task without needing to allocate more memory! */
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_unmap_userspace)(struct vm *__restrict sync_vm);
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_unmap_userspace_nosync)(void);

/* Translate a virtual address into its physical counterpart. */
INTDEF NOBLOCK WUNUSED PHYS vm_phys_t NOTHROW(FCALL p32_pagedir_translate)(VIRT vm_virt_t virt_addr);

/* Check if the given page is mapped. */
INTDEF NOBLOCK WUNUSED bool NOTHROW(FCALL p32_pagedir_ismapped)(VIRT vm_vpage_t vpage);
INTDEF NOBLOCK WUNUSED bool NOTHROW(FCALL p32_pagedir_iswritable)(VIRT vm_vpage_t vpage);
INTDEF NOBLOCK WUNUSED bool NOTHROW(FCALL p32_pagedir_isuseraccessible)(VIRT vm_vpage_t vpage);
INTDEF NOBLOCK WUNUSED bool NOTHROW(FCALL p32_pagedir_isuserwritable)(VIRT vm_vpage_t vpage);

/* TODO: Figure out a better design for these functions
 *       The current system is written under the assumption that 4MiB pages don't exist... */
INTDEF NOBLOCK WUNUSED bool NOTHROW(FCALL p32_pagedir_haschanged)(VIRT vm_vpage_t vpage);
INTDEF NOBLOCK void NOTHROW(FCALL p32_pagedir_unsetchanged)(VIRT vm_vpage_t vpage);

#endif /* __CC__ && CONFIG_BUILDING_KERNEL_CORE */

DECL_END

#endif /* !CONFIG_NO_PAGING_P32 */

#endif /* !GUARD_KERNEL_INCLUDE_I386_KOS_KERNEL_ARCH_PAGING32_P32_H */
