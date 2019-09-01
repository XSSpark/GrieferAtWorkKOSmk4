/* HASH 0x13628af6 */
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
#ifndef _KOS_FUTEXEXPR_H
#define _KOS_FUTEXEXPR_H 1

#include <__stdinc.h>
#include <__crt.h>

#ifdef __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER
#pragma GCC system_header
#endif /* __COMPILER_HAVE_PRAGMA_GCC_SYSTEM_HEADER */

#include <features.h>
#include <kos/bits/futex.h>
#include <kos/bits/futex-expr.h>
#include <bits/types.h>
#include <bits/timespec.h>
#include <hybrid/__atomic.h>
#ifndef __cplusplus
#include <hybrid/pp/__va_nargs.h>
#endif /* !__cplusplus */

__SYSDECL_BEGIN

#ifdef __CC__

#ifndef __lfutex_t_defined
#define __lfutex_t_defined 1
typedef __uintptr_t lfutex_t;
#endif /* !__lfutex_t_defined */

/* Initializers for futex expressions. */
#define LFUTEXEXPR_EQUAL(offset, value)                     LFUTEXEXPR_INIT(offset, LFUTEX_WAIT_WHILE, value, 0) /* x == value */
#define LFUTEXEXPR_NOT_EQUAL(offset, value)                 LFUTEXEXPR_INIT(offset, LFUTEX_WAIT_UNTIL, value, 0) /* x != value */
#define LFUTEXEXPR_ABOVE(offset, value)                     LFUTEXEXPR_INIT(offset, LFUTEX_WAIT_WHILE_ABOVE, value, 0) /* x > value */
#define LFUTEXEXPR_BELOW(offset, value)                     LFUTEXEXPR_INIT(offset, LFUTEX_WAIT_WHILE_BELOW, value, 0) /* x < value */
#define LFUTEXEXPR_ABOVE_EQUAL(offset, value)               LFUTEXEXPR_INIT(offset, (value) ? LFUTEX_WAIT_WHILE_ABOVE : LFUTEX_WAIT, (value)-1, 0) /* x >= value */
#define LFUTEXEXPR_BELOW_EQUAL(offset, value)               LFUTEXEXPR_INIT(offset, ((value)!=(lfutex_t)-1) ? LFUTEX_WAIT_WHILE_BELOW : LFUTEX_WAIT, (value)+1, 0) /* x <= value */
#define LFUTEXEXPR_ANYBIT(offset, bitmask)                  LFUTEXEXPR_INIT(offset, LFUTEX_WAIT_UNTIL_BITMASK, bitmask, 0)       /* (x & bitmask) != 0 */
#define LFUTEXEXPR_ALLBITS(offset, bitmask)                 LFUTEXEXPR_INIT(offset, LFUTEX_WAIT_WHILE_BITMASK, bitmask, bitmask) /* (x & bitmask) == bitmask */
#define LFUTEXEXPR_EXACT_BITS(offset, bitmask, setmask)     LFUTEXEXPR_INIT(offset, LFUTEX_WAIT_WHILE_BITMASK, bitmask, setmask) /* (x & bitmask) == setmask */
#define LFUTEXEXPR_NOT_EXACT_BITS(offset, bitmask, setmask) LFUTEXEXPR_INIT(offset, LFUTEX_WAIT_UNTIL_BITMASK, bitmask, setmask) /* (x & bitmask) != setmask */

/* Initializers for futex expressions (helpers for struct types). */
#define LFUTEXEXPR_TEQUAL(Type, Field, value)                     LFUTEXEXPR_EQUAL(__builtin_offsetof(Type, Field), value)
#define LFUTEXEXPR_TNOT_EQUAL(Type, Field, value)                 LFUTEXEXPR_NOT_EQUAL(__builtin_offsetof(Type, Field), value)
#define LFUTEXEXPR_TABOVE(Type, Field, value)                     LFUTEXEXPR_ABOVE(__builtin_offsetof(Type, Field), value)
#define LFUTEXEXPR_TBELOW(Type, Field, value)                     LFUTEXEXPR_BELOW(__builtin_offsetof(Type, Field), value)
#define LFUTEXEXPR_TABOVE_EQUAL(Type, Field, value)               LFUTEXEXPR_ABOVE_EQUAL(__builtin_offsetof(Type, Field), value)
#define LFUTEXEXPR_TBELOW_EQUAL(Type, Field, value)               LFUTEXEXPR_BELOW_EQUAL(__builtin_offsetof(Type, Field), value)
#define LFUTEXEXPR_TANYBIT(Type, Field, bitmask)                  LFUTEXEXPR_INIT(__builtin_offsetof(Type, Field), LFUTEX_WAIT_UNTIL_BITMASK, bitmask, 0)       /* (x & bitmask) != 0 */
#define LFUTEXEXPR_TALLBITS(Type, Field, bitmask)                 LFUTEXEXPR_INIT(__builtin_offsetof(Type, Field), LFUTEX_WAIT_WHILE_BITMASK, bitmask, bitmask) /* (x & bitmask) == bitmask */
#define LFUTEXEXPR_TEXACT_BITS(Type, Field, bitmask, setmask)     LFUTEXEXPR_INIT(__builtin_offsetof(Type, Field), LFUTEX_WAIT_WHILE_BITMASK, bitmask, setmask) /* (x & bitmask) == setmask */
#define LFUTEXEXPR_TNOT_EXACT_BITS(Type, Field, bitmask, setmask) LFUTEXEXPR_INIT(__builtin_offsetof(Type, Field), LFUTEX_WAIT_UNTIL_BITMASK, bitmask, setmask) /* (x & bitmask) != setmask */

#ifdef __cplusplus
__NAMESPACE_INT_BEGIN
extern "C++" {

/* Syntax-sugar  */
class __LFutexExprOffsetMask {
private:
	__ptrdiff_t       __m_offset;
	__syscall_ulong_t __m_bitmask;
public:
	__CXX_CLASSMEMBER __LFutexExprOffsetMask(__ptrdiff_t __offset, __syscall_ulong_t __bitmask) __CXX_NOEXCEPT
	    : __m_offset(__offset)
	    , __m_bitmask(__bitmask) {}
	__CXX_CLASSMEMBER struct lfutexexpr operator==(__syscall_ulong_t __setmask) const __CXX_NOEXCEPT {
		struct lfutexexpr __res;
		__res.fe_offset    = __m_offset;
		__res.fe_condition = LFUTEX_WAIT_WHILE_BITMASK;
		__res.fe_val       = __m_bitmask;
		__res.fe_val2      = __setmask;
		return __res;
	}
	__CXX_CLASSMEMBER struct lfutexexpr operator!=(__syscall_ulong_t __setmask) const __CXX_NOEXCEPT {
		struct lfutexexpr __res;
		__res.fe_offset    = __m_offset;
		__res.fe_condition = LFUTEX_WAIT_UNTIL_BITMASK;
		__res.fe_val       = __m_bitmask;
		__res.fe_val2      = __setmask;
		return __res;
	}
};

class __LFutexExprOffset {
private:
	__ptrdiff_t __m_offset;
public:
	__CXX_CLASSMEMBER __LFutexExprOffset(__ptrdiff_t __offset) __CXX_NOEXCEPT
	    : __m_offset(__offset) {}
	__CXX_CLASSMEMBER struct lfutexexpr operator==(__syscall_ulong_t __val) const __CXX_NOEXCEPT {
		struct lfutexexpr __res;
		__res.fe_offset    = __m_offset;
		__res.fe_condition = LFUTEX_WAIT_WHILE;
		__res.fe_val       = __val;
		__res.fe_val2      = 0;
		return __res;
	}
	__CXX_CLASSMEMBER struct lfutexexpr operator!=(__syscall_ulong_t __val) const __CXX_NOEXCEPT {
		struct lfutexexpr __res;
		__res.fe_offset    = __m_offset;
		__res.fe_condition = LFUTEX_WAIT_UNTIL;
		__res.fe_val       = __val;
		__res.fe_val2      = 0;
		return __res;
	}
	__CXX_CLASSMEMBER struct lfutexexpr operator<(__syscall_ulong_t __val) const __CXX_NOEXCEPT {
		struct lfutexexpr __res;
		__res.fe_offset    = __m_offset;
		__res.fe_condition = LFUTEX_WAIT_WHILE_BELOW;
		__res.fe_val       = __val;
		__res.fe_val2      = 0;
		return __res;
	}
	__CXX_CLASSMEMBER struct lfutexexpr operator>(__syscall_ulong_t __val) const __CXX_NOEXCEPT {
		struct lfutexexpr __res;
		__res.fe_offset    = __m_offset;
		__res.fe_condition = LFUTEX_WAIT_WHILE_ABOVE;
		__res.fe_val       = __val;
		__res.fe_val2      = 0;
		return __res;
	}
	__CXX_CLASSMEMBER struct lfutexexpr operator<=(__syscall_ulong_t __val) const __CXX_NOEXCEPT {
		struct lfutexexpr __res;
		__res.fe_offset    = __m_offset;
		__res.fe_condition = __val != (lfutex_t)-1 ? LFUTEX_WAIT_WHILE_BELOW : LFUTEX_WAIT;
		__res.fe_val       = __val + 1;
		__res.fe_val2      = 0;
		return __res;
	}
	__CXX_CLASSMEMBER struct lfutexexpr operator>=(__syscall_ulong_t __val) const __CXX_NOEXCEPT {
		struct lfutexexpr __res;
		__res.fe_offset    = __m_offset;
		__res.fe_condition = __val ? LFUTEX_WAIT_WHILE_ABOVE : LFUTEX_WAIT;
		__res.fe_val       = __val - 1;
		__res.fe_val2      = 0;
		return __res;
	}
	__CXX_CLASSMEMBER __LFutexExprOffsetMask operator&(__syscall_ulong_t __bitmask) const __CXX_NOEXCEPT {
		return __LFutexExprOffsetMask(__m_offset, __bitmask);
	}
};
}
__NAMESPACE_INT_END

#define LFUTEXEXPR_FIELD(Type, Field) \
	(__NAMESPACE_INT_SYM __LFutexExprOffset(__builtin_offsetof(Type, Field)))
#define LFUTEXEXPR_OFFSET(offset) \
	(__NAMESPACE_INT_SYM __LFutexExprOffset(offset))
#endif /* __cplusplus */

#if defined(__CRT_HAVE_lfutexexpr64) && (defined(__USE_TIME_BITS64))
/* >> lfutexexpr(2)
 * High-level wrapper around the lfutexexpr system call
 * The lfutexexpr() system call can be used to specify arbitrarily complex
 * expressions that must atomically (in relation to other futex operations)
 * hold true before the scheduler will suspend the calling thread.
 * @param: uaddr:         The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__CREDIRECT(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,lfutexexpr,(lfutex_t *__uaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec const *__timeout, unsigned int __timeout_flags),lfutexexpr64,(__uaddr,__base,__exprv,__exprc,__timeout,__timeout_flags))
#elif defined(__CRT_HAVE_lfutexexpr) && (!defined(__USE_TIME_BITS64))
/* >> lfutexexpr(2)
 * High-level wrapper around the lfutexexpr system call
 * The lfutexexpr() system call can be used to specify arbitrarily complex
 * expressions that must atomically (in relation to other futex operations)
 * hold true before the scheduler will suspend the calling thread.
 * @param: uaddr:         The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__CDECLARE(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,lfutexexpr,(lfutex_t *__uaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec const *__timeout, unsigned int __timeout_flags),(__uaddr,__base,__exprv,__exprc,__timeout,__timeout_flags))
#elif (defined(__CRT_HAVE_lfutexexpr) || defined(__CRT_HAVE_lfutexexpr64))
#include <local/kos.futexexpr/lfutexexpr.h>
/* >> lfutexexpr(2)
 * High-level wrapper around the lfutexexpr system call
 * The lfutexexpr() system call can be used to specify arbitrarily complex
 * expressions that must atomically (in relation to other futex operations)
 * hold true before the scheduler will suspend the calling thread.
 * @param: uaddr:         The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__NAMESPACE_LOCAL_USING_OR_IMPL(lfutexexpr, __FORCELOCAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBCCALL lfutexexpr)(lfutex_t *__uaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec const *__timeout, unsigned int __timeout_flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(lfutexexpr))(__uaddr, __base, __exprv, __exprc, __timeout, __timeout_flags); })
#endif /* lfutexexpr... */
#if defined(__CRT_HAVE_lfutexlockexpr64) && (defined(__USE_TIME_BITS64))
/* >> lfutexlockexpr(2)
 * Same as `lfutexlock()' is for `lfutex()', but instead implemented for `lfutexexpr()'
 * @param: ulockaddr:     Address of the futex lock to-be used / The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__CREDIRECT(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,lfutexlockexpr,(lfutex_t *__ulockaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec const *__timeout, unsigned int __timeout_flags),lfutexlockexpr64,(__ulockaddr,__base,__exprv,__exprc,__timeout,__timeout_flags))
#elif defined(__CRT_HAVE_lfutexlockexpr) && (!defined(__USE_TIME_BITS64))
/* >> lfutexlockexpr(2)
 * Same as `lfutexlock()' is for `lfutex()', but instead implemented for `lfutexexpr()'
 * @param: ulockaddr:     Address of the futex lock to-be used / The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__CDECLARE(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,lfutexlockexpr,(lfutex_t *__ulockaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec const *__timeout, unsigned int __timeout_flags),(__ulockaddr,__base,__exprv,__exprc,__timeout,__timeout_flags))
#elif (defined(__CRT_HAVE_lfutexlockexpr) || defined(__CRT_HAVE_lfutexlockexpr64))
#include <local/kos.futexexpr/lfutexlockexpr.h>
/* >> lfutexlockexpr(2)
 * Same as `lfutexlock()' is for `lfutex()', but instead implemented for `lfutexexpr()'
 * @param: ulockaddr:     Address of the futex lock to-be used / The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__NAMESPACE_LOCAL_USING_OR_IMPL(lfutexlockexpr, __FORCELOCAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBCCALL lfutexlockexpr)(lfutex_t *__ulockaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec const *__timeout, unsigned int __timeout_flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(lfutexlockexpr))(__ulockaddr, __base, __exprv, __exprc, __timeout, __timeout_flags); })
#endif /* lfutexlockexpr... */

#ifdef __USE_TIME64
#if defined(__CRT_HAVE_lfutexexpr64)
/* >> lfutexexpr(2)
 * High-level wrapper around the lfutexexpr system call
 * The lfutexexpr() system call can be used to specify arbitrarily complex
 * expressions that must atomically (in relation to other futex operations)
 * hold true before the scheduler will suspend the calling thread.
 * @param: uaddr:         The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__CDECLARE(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,lfutexexpr64,(lfutex_t *__uaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec64 const *__timeout, unsigned int __timeout_flags),(__uaddr,__base,__exprv,__exprc,__timeout,__timeout_flags))
#elif defined(__CRT_HAVE_lfutexexpr) && (__SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__)
/* >> lfutexexpr(2)
 * High-level wrapper around the lfutexexpr system call
 * The lfutexexpr() system call can be used to specify arbitrarily complex
 * expressions that must atomically (in relation to other futex operations)
 * hold true before the scheduler will suspend the calling thread.
 * @param: uaddr:         The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__CREDIRECT(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,lfutexexpr64,(lfutex_t *__uaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec64 const *__timeout, unsigned int __timeout_flags),lfutexexpr,(__uaddr,__base,__exprv,__exprc,__timeout,__timeout_flags))
#elif defined(__CRT_HAVE_lfutexexpr)
#include <local/kos.futexexpr/lfutexexpr64.h>
/* >> lfutexexpr(2)
 * High-level wrapper around the lfutexexpr system call
 * The lfutexexpr() system call can be used to specify arbitrarily complex
 * expressions that must atomically (in relation to other futex operations)
 * hold true before the scheduler will suspend the calling thread.
 * @param: uaddr:         The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__NAMESPACE_LOCAL_USING_OR_IMPL(lfutexexpr64, __FORCELOCAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBCCALL lfutexexpr64)(lfutex_t *__uaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec64 const *__timeout, unsigned int __timeout_flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(lfutexexpr64))(__uaddr, __base, __exprv, __exprc, __timeout, __timeout_flags); })
#endif /* lfutexexpr64... */
#if defined(__CRT_HAVE_lfutexlockexpr64)
/* >> lfutexlockexpr(2)
 * Same as `lfutexlock()' is for `lfutex()', but instead implemented for `lfutexexpr()'
 * @param: ulockaddr:     Address of the futex lock to-be used / The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__CDECLARE(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,lfutexlockexpr64,(lfutex_t *__ulockaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec64 const *__timeout, unsigned int __timeout_flags),(__ulockaddr,__base,__exprv,__exprc,__timeout,__timeout_flags))
#elif defined(__CRT_HAVE_lfutexlockexpr) && (__SIZEOF_TIME32_T__ == __SIZEOF_TIME64_T__)
/* >> lfutexlockexpr(2)
 * Same as `lfutexlock()' is for `lfutex()', but instead implemented for `lfutexexpr()'
 * @param: ulockaddr:     Address of the futex lock to-be used / The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__CREDIRECT(__ATTR_NONNULL((1, 3)),int,__NOTHROW_RPC,lfutexlockexpr64,(lfutex_t *__ulockaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec64 const *__timeout, unsigned int __timeout_flags),lfutexlockexpr,(__ulockaddr,__base,__exprv,__exprc,__timeout,__timeout_flags))
#elif defined(__CRT_HAVE_lfutexlockexpr)
#include <local/kos.futexexpr/lfutexlockexpr64.h>
/* >> lfutexlockexpr(2)
 * Same as `lfutexlock()' is for `lfutex()', but instead implemented for `lfutexexpr()'
 * @param: ulockaddr:     Address of the futex lock to-be used / The futex on which to wait
 * @param: base:          Base pointer added to the `fe_offset' fields of given expressions
 * @param: exprv:         Vector of expressions for which to check
 * @param: exprc:         Number of expressions given in `exprv'
 * @param: timeout:       Timeout for wait operations (s.a. `LFUTEX_WAIT_FLAG_TIMEOUT_*')
 * @param: timeout_flags: Set of `LFUTEX_WAIT_FLAG_TIMEOUT_*'
 * @return: * : Depending on `command'
 * @return: -1:EFAULT:    A faulty pointer was given
 * @return: -1:EINVAL:    One of the given commands is invalid
 * @return: -1:EINTR:     A blocking futex-wait operation was interrupted
 * @return: -1:ETIMEDOUT: A blocking futex-wait operation has timed out */
__NAMESPACE_LOCAL_USING_OR_IMPL(lfutexlockexpr64, __FORCELOCAL __ATTR_NONNULL((1, 3)) int __NOTHROW_RPC(__LIBCCALL lfutexlockexpr64)(lfutex_t *__ulockaddr, void *__base, struct lfutexexpr const *__exprv, __SIZE_TYPE__ __exprc, struct timespec64 const *__timeout, unsigned int __timeout_flags) { return (__NAMESPACE_LOCAL_SYM __LIBC_LOCAL_NAME(lfutexlockexpr64))(__ulockaddr, __base, __exprv, __exprc, __timeout, __timeout_flags); })
#endif /* lfutexlockexpr64... */
#endif /* __USE_TIME64 */


#endif /* __CC__ */

__SYSDECL_END

#endif /* !_KOS_FUTEXEXPR_H */
