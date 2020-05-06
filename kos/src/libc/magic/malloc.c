/* Copyright (c) 2019-2020 Griefer@Work                                       *
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
 *    Portions Copyright (c) 2019-2020 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */

%[default_impl_section(.text.crt.heap.malloc)]

%(libc_fast){
#include "stdlib.h"
}
%(libc_core){
#include "stdlib.h"
}

%{
#include <features.h>
#if defined(__USE_KOS) && defined(__USE_STRING_OVERLOADS)
#include <hybrid/__overflow.h>
#ifndef __cplusplus
#include <hybrid/pp/__va_nargs.h>
#endif /* !__cplusplus */
#endif /* __USE_KOS && __USE_STRING_OVERLOADS */

__SYSDECL_BEGIN

#if (defined(__CRT_KOS) || defined(__CRT_GLC))
/* malloc behavior attributes. */
#define __MALLOC_ZERO_IS_NONNULL  1
#define __REALLOC_ZERO_IS_NONNULL 1
#endif /* ... */

#define M_TRIM_THRESHOLD     (-1)
#define M_GRANULARITY        (-2)
#define M_MMAP_THRESHOLD     (-3)

#ifdef __CC__

#ifndef __size_t_defined
#define __size_t_defined 1
typedef __SIZE_TYPE__ size_t;
#endif /* !__size_t_defined */

}

%[insert:std]
%[insert:extern(malloc)]
%[insert:extern(calloc)]
%[insert:extern(realloc)]
%[insert:extern(free)]



@@@EXCEPT: `realloc_in_place()' will return `NULL' if the reallocation isn't
@@          possible due to the requested memory above `MALLPTR' already being
@@          in use. However, an `E_BADALLOC' exception is thrown if insufficient
@@          memory (for internal control structures) is available to complete
@@          the operation
[alias(_expand)][ATTR_MALL_DEFAULT_ALIGNED][ATTR_ALLOC_SIZE((2))]
[section(.text.crt.heap.helpers)]
realloc_in_place:(void *__restrict mallptr, size_t n_bytes) -> void *;

[section(.text.crt.heap.rare_helpers)]
crt_posix_memalign:([nonnull] void **__restrict pp, size_t alignment, size_t n_bytes) -> int = posix_memalign?;

%
[ATTR_WUNUSED][ATTR_ALLOC_ALIGN(1)][ATTR_ALLOC_SIZE((2))]
[ATTR_MALLOC][alias(aligned_alloc)]
[requires(defined(__CRT_HAVE_posix_memalign))]
memalign:(size_t alignment, size_t n_bytes) -> void * {
	void *result;
	if (crt_posix_memalign(&result, alignment, n_bytes))
		return NULL;
	return result;
}


%
[ATTR_WUNUSED][ATTR_MALL_PAGEALIGNED][ATTR_ALLOC_SIZE((1))][ATTR_MALLOC]
[section(.text.crt.heap.rare_helpers)]
pvalloc:(size_t n_bytes) -> void *;

[noexport][guard]
[ATTR_WUNUSED][ATTR_MALL_PAGEALIGNED][ATTR_ALLOC_SIZE((1))]
[requires($has_function(memalign))]
[section(.text.crt.heap.rare_helpers)]
valloc:($size_t n_bytes) -> void * {
	return memalign(getpagesize(), n_bytes);
}

[dependency_include(<parts/errno.h>)]
[requires($has_function(memalign))][noexport][guard]
[section(.text.crt.heap.rare_helpers)][crtbuiltin]
posix_memalign:([nonnull] void **__restrict pp, $size_t alignment, $size_t n_bytes) -> int {
	void *result;
	size_t d = alignment / sizeof(void *);
	size_t r = alignment % sizeof(void *);
	if (r != 0 || !d || (d & (d - 1)) != 0) {
#ifdef EINVAL
		return EINVAL;
#else /* EINVAL */
		return 1;
#endif /* !EINVAL */
	}
	result = memalign(alignment, n_bytes);
	if (!result) {
#ifdef ENOMEM
		return ENOMEM;
#else /* ENOMEM */
		return 1;
#endif /* !ENOMEM */
	}
	*pp = result;
	return 0;
}

[guard][preferred_alias(free)]
[section(.text.crt.heap.rare_helpers)]
cfree:(void *__restrict mallptr);

%
[section(.text.crt.dos.heap)][ignore]
[section(.text.crt.heap.utility)][userimpl]
_heapmin:() -> int;

[section(.text.crt.heap.utility)]
[userimpl][user_impl({
	/* NO-OP (indicate failure to release memory) */
	COMPILER_IMPURE();
	(void)pad;
	return 0;
})] malloc_trim:(size_t pad) -> int {
@@if_has_function(_heapmin)@@
	(void)pad;
	return _heapmin() ? 1 : 0;
@@else_has_function(_heapmin)@@
	/* NO-OP (indicate failure to release memory) */
	COMPILER_IMPURE();
	(void)pad;
	return 0;
@@endif_has_function(_heapmin)@@
}

%
[ATTR_PURE][ATTR_WUNUSED][alias(_msize)]
[section(.text.crt.heap.helpers)][userimpl]
malloc_usable_size:(void *__restrict mallptr) -> size_t;

[section(.text.crt.heap.utility)][userimpl]
mallopt:(int parameter_number, int parameter_value) -> int {
	/* NO-OP */
	COMPILER_IMPURE();
	(void)parameter_number;
	(void)parameter_value;
	return 0;
}

[ATTR_WUNUSED][ATTR_MALL_DEFAULT_ALIGNED][ATTR_ALLOC_SIZE((2))]
[ATTR_MALLOC][section(.text.crt.heap.rare_helpers)]
__memdup:([nonnull] void const *__restrict ptr, size_t n_bytes) -> void * = memdup;

[ATTR_WUNUSED][ATTR_MALL_DEFAULT_ALIGNED][ATTR_ALLOC_SIZE((2))]
[ATTR_MALLOC][section(.text.crt.heap.rare_helpers)]
__memcdup:([nonnull] void const *__restrict ptr, int needle, size_t n_bytes) -> void * = memcdup;

%
%#ifdef __USE_KOS
[ATTR_WUNUSED][ATTR_MALL_DEFAULT_ALIGNED][ATTR_ALLOC_SIZE((2))]
[ATTR_MALLOC][alias(__memdup)][requires($has_function(malloc))]
[section(.text.crt.heap.rare_helpers)][userimpl]
memdup:([nonnull] void const *__restrict ptr, size_t n_bytes) -> void * {
	void *result;
	result = malloc(n_bytes);
	if likely(result)
		memcpy(result, ptr, n_bytes);
	return result;
}

[ATTR_WUNUSED][ATTR_MALL_DEFAULT_ALIGNED][ATTR_ALLOC_SIZE((2))]
[ATTR_MALLOC][alias(__memcdup)][requires($has_function(memdup))]
[section(.text.crt.heap.rare_helpers)][userimpl]
memcdup:([nonnull] void const *__restrict ptr, int needle, size_t n_bytes) -> void * {
	if likely(n_bytes) {
		void const *endaddr;
		endaddr = memchr(ptr, needle, n_bytes - 1);
		if (endaddr)
			n_bytes = ((uintptr_t)endaddr - (uintptr_t)ptr) + 1;
	}
	return memdup(ptr, n_bytes);
}

[ATTR_WUNUSED][ATTR_MALL_DEFAULT_ALIGNED][ATTR_ALLOC_SIZE((2))]
[section(.text.crt.heap.rare_helpers)]
[requires($has_function(realloc))][guard]
[dependency_include(<hybrid/__overflow.h>)][userimpl]
reallocarray:(void *ptr, size_t elem_count, size_t elem_size)
		-> [realloc(mallptr, elem_count * elem_size)] void * {
	size_t total_bytes;
	if (__hybrid_overflow_umul(elem_count, elem_size, &total_bytes))
		total_bytes = (size_t)-1; /* Force down-stream failure */
	return realloc(ptr, total_bytes);
}

[section(.text.crt.heap.rare_helpers)]
[attribute(*)][guard][nocrt]
reallocv:(*) = reallocarray;

[userimpl][guard][section(.text.crt.heap.rare_helpers)]
[requires($has_function(realloc) && $has_function(malloc_usable_size))]
recalloc:(void *mallptr, $size_t num_bytes)
		-> [realloc(mallptr, num_bytes)] void * {
	void *result;
	size_t oldsize;
	oldsize = malloc_usable_size(mallptr);
	result  = realloc(mallptr, num_bytes);
	if likely(result) {
		if (num_bytes > oldsize)
			memset((byte_t *)result + oldsize, 0, num_bytes - oldsize);
	}
	return result;
}


[section(.text.crt.heap.rare_helpers)]
[requires($has_function(realloc) && $has_function(malloc_usable_size))][guard]
[dependency_include(<hybrid/__overflow.h>)][userimpl][export_alias(_recalloc)]
recallocv:(void *mallptr, $size_t elem_count, $size_t elem_size)
		-> [realloc(mallptr, elem_count * elem_size)] void * {
	void *result;
	size_t total_bytes, oldsize;
	oldsize = malloc_usable_size(mallptr);
	if unlikely(__hybrid_overflow_umul(elem_count, elem_size, &total_bytes))
		total_bytes = (size_t)-1; /* Force down-stream failure */
	result = realloc(mallptr, total_bytes);
	if likely(result) {
		if (total_bytes > oldsize)
			memset((byte_t *)result + oldsize, 0, total_bytes - oldsize);
	}
	return result;
}


%
%
%#ifdef __USE_STRING_OVERLOADS
%#ifndef __MALLOC_OVERLOADS_DEFINED
%#define __MALLOC_OVERLOADS_DEFINED 1
%{
#ifdef __malloc_defined
__NAMESPACE_LOCAL_BEGIN
__FORCELOCAL __ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_ALLOC_SIZE((1, 2))
void *__NOTHROW_NCX(__LIBCCALL __LIBC_LOCAL_NAME(mallocv))(size_t __elem_count, size_t __elem_size) {
	size_t __total_size;
	if (__hybrid_overflow_umul(__elem_count, __elem_size, &__total_size))
		__total_size = (size_t)-1; /* Force down-stream failure */
	return (malloc)(__total_size);
}
__NAMESPACE_LOCAL_END
#endif /* __malloc_defined */
}
%#ifdef __cplusplus
%extern "C++" {
%{
#ifdef __malloc_defined
__FORCELOCAL __ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_ALLOC_SIZE((1, 2))
void *__NOTHROW_NCX(__LIBCCALL malloc)(size_t __elem_count, size_t __elem_size) { return __NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(mallocv)(__elem_count, __elem_size); }
#endif /* __malloc_defined */
#ifdef __calloc_defined
__FORCELOCAL __ATTR_MALLOC __ATTR_MALL_DEFAULT_ALIGNED __ATTR_WUNUSED __ATTR_ALLOC_SIZE((1))
void *__NOTHROW_NCX(__LIBCCALL calloc)(size_t __num_bytes) { return (calloc)(1, __num_bytes); }
#endif /* __calloc_defined */
}
[overload_alias] realloc:(*) = reallocarray;
[overload_alias] recalloc:(*) = recallocv;
%}
%#else /* __cplusplus */
%{
#ifdef __malloc_defined
#define __PRIVATE_malloc_1 (malloc)
#define __PRIVATE_malloc_2 __NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(mallocv)
#undef malloc
#define malloc(...) __HYBRID_PP_VA_OVERLOAD(__PRIVATE_malloc_, (__VA_ARGS__))(__VA_ARGS__)
#endif /* __malloc_defined */
#ifdef __calloc_defined
#define __PRIVATE_calloc_1(num_bytes) (calloc)(1, num_bytes)
#define __PRIVATE_calloc_2            (calloc)
#undef calloc
#define calloc(...) __HYBRID_PP_VA_OVERLOAD(__PRIVATE_calloc_, (__VA_ARGS__))(__VA_ARGS__)
#endif /* __calloc_defined */
#if defined(__realloc_defined) && defined(__reallocarray_defined)
#define __PRIVATE_realloc_2 (realloc)
#define __PRIVATE_realloc_3 (reallocarray)
#undef realloc
#define realloc(...) __HYBRID_PP_VA_OVERLOAD(__PRIVATE_realloc_, (__VA_ARGS__))(__VA_ARGS__)
#endif /* __realloc_defined && __reallocarray_defined */
#if defined(__recalloc_defined) && defined(__recallocv_defined)
#define __PRIVATE_recalloc_2 (recalloc)
#define __PRIVATE_recalloc_3 (recallocv)
#undef recalloc
#define recalloc(...) __HYBRID_PP_VA_OVERLOAD(__PRIVATE_recalloc_, (__VA_ARGS__))(__VA_ARGS__)
#endif /* __recalloc_defined && __recallocv_defined */
}
%#endif /* !__cplusplus */
%#endif /* !__MALLOC_OVERLOADS_DEFINED */
%#endif /* __USE_STRING_OVERLOADS */
%#endif /* __USE_KOS */



%#ifdef __USE_DOS
[ATTR_PURE][ATTR_WUNUSED][section(.text.crt.dos.heap)]
[section(.text.crt.heap.rare_helpers)]
_msize:(void *__restrict mallptr) -> size_t = malloc_usable_size;
%#endif /* __USE_DOS */

%{

#endif /* __CC__ */

__SYSDECL_END

}