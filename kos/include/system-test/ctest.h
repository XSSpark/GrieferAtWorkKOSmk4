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
#ifndef _SYSTEM_TEST_CTEST_H
#define _SYSTEM_TEST_CTEST_H 1
#undef NDEBUG /* We can't have assertions be disabled! */

#include "api.h"
#include <assert.h>

#ifndef __INSIDE_LIBTEST
#error "Only include this file from within *.ctest files that are apart of /bin/system-test"
#endif /* __INSIDE_LIBTEST */


#define ASSERT_COMPARE(a, cmp, b) \
	__assertf((a) cmp (b), #a "(%Iu) " #cmp " " #b "(%Iu)", (__UINTPTR_TYPE__)(a), (__UINTPTR_TYPE__)(b))

#define ASSERT_EQUAL(a, b)      ASSERT_COMPARE(a, ==, b)
#define ASSERT_STREQUAL(a, b)   __assertf(strcmp(a, b) == 0, #a "(%q) == " #b "(%q)", a, b)
#define ASSERT_NOT_EQUAL(a, b)  ASSERT_COMPARE(a, !=, b)



#ifdef __CC__
__DECL_BEGIN

struct testdecl {
	char const  *td_name;         /* [1..1] Test name */
	char const  *td_file;         /* [1..1] Test filename */
	unsigned int td_line;         /* Test line number */
	void       (*td_func)(void);  /* [1..1] Test function */
};

#define DEFINE_TEST(name)                                                                        \
	__PRIVATE __ATTR_USED void test_##name(void);                                                \
	__PRIVATE __ATTR_USED __ATTR_SECTION(".data.system_tests") struct testdecl __decl_##name = { \
		.td_name = #name,                                                                        \
		.td_file = __FILE__,                                                                     \
		.td_line = __LINE__,                                                                     \
		.td_func = &test_##name,                                                                 \
	};                                                                                           \
	__PRIVATE __ATTR_USED void test_##name(void)


__DECL_END
#endif /* __CC__ */


#endif /* !_SYSTEM_TEST_CTEST_H */
