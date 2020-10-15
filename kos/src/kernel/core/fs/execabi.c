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
#ifndef GUARD_KERNEL_SRC_FS_EXECABI_C
#define GUARD_KERNEL_SRC_FS_EXECABI_C 1
#define _KOS_SOURCE 1

#include <kernel/compiler.h>

#include <fs/node.h>
#include <fs/vfs.h>
#include <kernel/driver.h>
#include <kernel/except.h>
#include <kernel/execabi.h>
#include <kernel/malloc.h>

#include <assert.h>
#include <stddef.h>
#include <string.h>

#ifdef CONFIG_EXECABI_HAVE_BUILTIN_ELF
#include "../../modelfexec/elf.h"
#endif /* CONFIG_EXECABI_HAVE_BUILTIN_ELF */

#ifdef CONFIG_EXECABI_HAVE_BUILTIN_SHEBANG
#include "../../modshebang/shebang.h"
#endif /* CONFIG_EXECABI_HAVE_BUILTIN_SHEBANG */

DECL_BEGIN

enum {
	DEFAULT_EXECABIS_COUNT = (0
#ifdef CONFIG_EXECABI_HAVE_BUILTIN_ELF
	                          + 1
#endif /* CONFIG_EXECABI_HAVE_BUILTIN_ELF */
#ifdef CONFIG_EXECABI_HAVE_BUILTIN_SHEBANG
	                          + 1
#endif /* CONFIG_EXECABI_HAVE_BUILTIN_SHEBANG */
	                          )
};

/* Define execution ABIs built into the kernel core. */
PRIVATE struct execabis_struct default_execabis = {
	/* .eas_refcnt = */ 2, /* +1: default_execabis, +1: execabis */
	/* .eas_count  = */ DEFAULT_EXECABIS_COUNT,
	/* .eas_abis   = */ {
#ifdef CONFIG_EXECABI_HAVE_BUILTIN_ELF
		EXECABI_INIT_ELF,
#endif /* CONFIG_EXECABI_HAVE_BUILTIN_ELF */
#ifdef CONFIG_EXECABI_HAVE_BUILTIN_SHEBANG
		EXECABI_INIT_SHEBANG,
#endif /* CONFIG_EXECABI_HAVE_BUILTIN_SHEBANG */
	}
};

/* [1..1] Currently defined exec-ABIs */
PUBLIC ATOMIC_REF(struct execabis_struct)
execabis = ATOMIC_REF_INIT(&default_execabis);

/* Destroy a given exec-ABIs listing. */
PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(FCALL execabis_destroy)(struct execabis_struct *__restrict self) {
	size_t i;
	for (i = 0; i < self->eas_count; ++i)
		weakdecref(self->eas_abis[i].ea_driver);
	kfree(self);
}


/* Finalize the given set of exec() arguments. */
PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(FCALL execargs_fini)(struct execargs *__restrict self) {
	if unlikely(self->ea_argc_inject) {
		size_t i;
		for (i = 0; i < self->ea_argc_inject; ++i)
			kfree(self->ea_argv_inject[i]);
		kfree(self->ea_argv_inject);
	}
	decref_unlikely(self->ea_xpath);
	decref_unlikely(self->ea_xdentry);
	decref_unlikely(self->ea_xnode);
}



/* Register a given exec-ABI. Note that the only way to unregister
 * an ABI is to unload the associated driver (in which case the ABI
 * is automatically unregistered)
 * @return: true:  Successfully registered the given `abi'.
 * @return: false: The given `abi' had already been registered. */
PUBLIC NONNULL((1)) bool FCALL
execabis_register(struct execabi const *__restrict abi)
		THROWS(E_BADALLOC, E_WOULDBLOCK) {
	size_t i;
	REF struct execabis_struct *old_abis;
	REF struct execabis_struct *new_abis;
again:
	old_abis = execabis.get();
	/* Check if this ABI has already been defined. */
	for (i = 0; i < old_abis->eas_count; ++i) {
		struct execabi *other_abi;
		other_abi = &old_abis->eas_abis[i];
		if (other_abi->ea_exec != abi->ea_exec)
			continue;
		if (other_abi->ea_driver != abi->ea_driver)
			continue;
		if (other_abi->ea_magsiz != abi->ea_magsiz)
			continue;
		if (memcmp(other_abi->ea_magic, abi->ea_magic, other_abi->ea_magsiz) != 0)
			continue;
		/* Already defined... */
		decref_unlikely(old_abis);
		return false;
	}
	/* Extend the list of supported ABIs. */
	TRY {
		new_abis = (REF struct execabis_struct *)kmalloc(offsetof(struct execabis_struct, eas_abis) +
		                                                 (old_abis->eas_count + 1) * sizeof(struct execabi),
		                                                 GFP_NORMAL);
	} EXCEPT {
		decref_unlikely(old_abis);
		RETHROW();
	}
	/* Copy existing ABIs. */
	memcpy(new_abis->eas_abis, old_abis->eas_abis,
	       old_abis->eas_count, sizeof(struct execabi));
	for (i = 0; i < old_abis->eas_count; ++i)
		weakincref(new_abis->eas_abis[i].ea_driver);
	new_abis->eas_count  = old_abis->eas_count + 1;
	new_abis->eas_refcnt = 1;
	/* Fill in the new ABI. */
	memcpy(&new_abis->eas_abis[old_abis->eas_count],
	       abi, sizeof(struct execabi));
	weakincref(abi->ea_driver);

	/* Atomically load the new ABI descriptor. */
	if (!execabis.cmpxch_inherit_new(old_abis, new_abis)) {
		decref_unlikely(old_abis);
		destroy(new_abis);
		goto again;
	}
	decref_unlikely(old_abis);
	return true;
}

INTERN NONNULL((1)) bool FCALL
driver_clear_execabis(struct driver *__restrict self)
		THROWS(E_BADALLOC, E_WOULDBLOCK) {
	REF struct execabis_struct *old_abis;
	REF struct execabis_struct *new_abis;
	size_t i, j, abi_count;
again:
	abi_count = 0;
	old_abis  = execabis.get();
	/* Search for ABIs defined by the given driver. */
	for (i = 0; i < old_abis->eas_count; ++i) {
		if (old_abis->eas_abis[i].ea_driver == self)
			++abi_count;
	}
	if (abi_count == 0) {
		/* No ABIs defined by this driver. */
		decref_unlikely(old_abis);
		return false;
	}
	TRY {
		new_abis = (REF struct execabis_struct *)kmalloc((old_abis->eas_count - abi_count) *
		                                                 sizeof(struct execabi),
		                                                 GFP_NORMAL);
	} EXCEPT {
		decref_unlikely(old_abis);
		RETHROW();
	}
	new_abis->eas_refcnt = 1;
	new_abis->eas_count  = old_abis->eas_count - abi_count;
	/* Copy only ABIs defined by other drivers into `new_abis' */
	for (i = j = 0; i < old_abis->eas_count; ++i) {
		if (old_abis->eas_abis[i].ea_driver == self)
			continue;
		memcpy(&new_abis->eas_abis[j],
		       &old_abis->eas_abis[i],
		       sizeof(struct execabi));
		weakincref(new_abis->eas_abis[j].ea_driver);
		++j;
	}
	assert(j == new_abis->eas_count);

	/* Check for special case: re-use the default set of ABIs. */
	if (new_abis->eas_count == DEFAULT_EXECABIS_COUNT &&
	    memcmp(default_execabis.eas_abis, new_abis->eas_abis,
	           DEFAULT_EXECABIS_COUNT * sizeof(struct execabi)) == 0) {
		destroy(new_abis);
		new_abis = incref(&default_execabis);
	}

	/* Atomically load the new ABI descriptor. */
	if (!execabis.cmpxch_inherit_new(old_abis, new_abis)) {
		decref_unlikely(old_abis);
		destroy(new_abis);
		goto again;
	}
	decref_unlikely(old_abis);
	return true;
}



DECL_END

#endif /* !GUARD_KERNEL_SRC_FS_EXECABI_C */
