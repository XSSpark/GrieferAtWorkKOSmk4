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
#ifndef GUARD_APPS_SYSTEM_TEST_TEST_EPOLL_C
#define GUARD_APPS_SYSTEM_TEST_TEST_EPOLL_C 1
#define _KOS_SOURCE 1
#undef NDEBUG

#include <hybrid/compiler.h>

#include <kos/ksysctl.h>
#include <kos/personality.h>
#include <kos/types.h>
#include <sys/epoll.h>
#include <system-test/ctest.h>

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

DECL_BEGIN

DEFINE_TEST(epoll) {
	fd_t epfd;
	fd_t pipes[2];
	struct epoll_event ee;
	struct epoll_event events[8];

	NEd(-1, (epfd = epoll_create1(0)));
	EQd(0, close(epfd));
	NEd(-1, (epfd = epoll_create1(EPOLL_CLOEXEC)));
	EQd(0, close(epfd));
	NEd(-1, (epfd = epoll_create1(EPOLL_CLOFORK)));
	EQd(0, close(epfd));
	NEd(-1, (epfd = epoll_create1(EPOLL_CLOEXEC | EPOLL_CLOFORK)));
	EQd(0, close(epfd));

	NEd(-1, (epfd = epoll_create(42)));

	EQd(0, pipe(pipes));

	ee.events   = EPOLLIN;
	ee.data.u64 = 1234;
	EQd(0, epoll_ctl(epfd, EPOLL_CTL_ADD, pipes[0], &ee));

	ee.events   = EPOLLOUT;
	ee.data.u64 = 4321;
	EQd(0, epoll_ctl(epfd, EPOLL_CTL_ADD, pipes[1], &ee));

	/* Both pipes registered. At this point, epfd should indicate writable. */
	EQss(1, epoll_wait(epfd, events, 8, 0));
	EQx32(events[0].events, EPOLLOUT);
	EQu64(events[0].data.u64, 4321);
	EQss(1, epoll_wait(epfd, events, 8, 0));
	EQx32(events[0].events, EPOLLOUT);
	EQu64(events[0].data.u64, 4321);

	/* Now write some data, which should cause readable to become set. */
	EQss(3, write(pipes[1], "foo", 3));

	/* Now both readable and writable should be set. */
	for (int i = 0; i < 2; ++i) {
		EQss(2, epoll_wait(epfd, events, 8, 0));
		if (events[0].data.u64 == 4321) {
			/* Swap the events */
			struct epoll_event temp;
			temp      = events[0];
			events[0] = events[1];
			events[1] = temp;
		}
		EQx32(events[0].events, EPOLLIN);
		EQu64(events[0].data.u64, 1234);
		EQx32(events[1].events, EPOLLOUT);
		EQu64(events[1].data.u64, 4321);
	}

	/* Modify the controller. */
	ee.events   = EPOLLIN | EPOLLONESHOT;
	ee.data.u64 = 8888;
	EQd(0, epoll_ctl(epfd, EPOLL_CTL_MOD, pipes[0], &ee));
	EQd(0, epoll_ctl(epfd, EPOLL_CTL_DEL, pipes[1], NULL));

	/* Readable should still be set, but writable was removed. */
	EQss(1, epoll_wait(epfd, events, 8, 0));
	EQx32(events[0].events, EPOLLIN);
	EQu64(events[0].data.u64, 8888);

	/* Without `KP_EPOLL_DELETE_ONESHOT', we  must manually  delete
	 * monitors after they've become dormant. Note that by default,
	 * this personality is off, but  as a kos-specific program,  we
	 * also want to ensure that we can test all cases! */
	if (!KSysctlGetPersonality(KP_EPOLL_DELETE_ONESHOT))
		EQd(0, epoll_ctl(epfd, EPOLL_CTL_DEL, pipes[0], NULL));
	else {
		/* Automatically deleted. */
	}
	EQd(-1, epoll_ctl(epfd, EPOLL_CTL_DEL, pipes[0], NULL));
	EQd(errno, ENOENT);

	/* Because of the one-shot, readable should not longer appear now! */
	EQss(0, epoll_wait(epfd, events, 8, 0));

	/* Re-add both pipes to the controller, so they are left dangling. */
	ee.events   = EPOLLIN;
	ee.data.u64 = 1234;
	EQd(0, epoll_ctl(epfd, EPOLL_CTL_ADD, pipes[0], &ee));
	ee.events   = EPOLLOUT;
	ee.data.u64 = 4321;
	EQd(0, epoll_ctl(epfd, EPOLL_CTL_ADD, pipes[1], &ee));

	/* Close everything */
	EQd(0, close(pipes[1]));
	EQd(0, close(pipes[0]));
	EQd(0, close(epfd));
}

DEFINE_TEST(epoll_et) {
	fd_t epfd;
	fd_t pipes[2];
	struct epoll_event ee;
	struct epoll_event events[8];
	char buf[64];

	NEd(-1, (epfd = epoll_create1(0)));
	EQd(0, pipe(pipes));
	/* Make the reader pipe non-blocking. */
	EQd(0, fcntl(pipes[0], F_SETFL, fcntl(pipes[0], F_GETFL) | O_NONBLOCK));

	ee.events   = EPOLLIN | EPOLLET;
	ee.data.u64 = 9999;
	EQd(0, epoll_ctl(epfd, EPOLL_CTL_ADD, pipes[0], &ee));


	EQss(0, epoll_wait(epfd, events, 8, 0)); /* Nothing should be ready, yet */
	EQss(3, write(pipes[1], "foo", 3));      /* Write some data. */
	EQss(1, epoll_wait(epfd, events, 8, 0)); /* That should have triggered EPOLLET! */
	EQx32(events[0].events, EPOLLIN);
	EQu64(events[0].data.u64, 9999);
	EQss(0, epoll_wait(epfd, events, 8, 0)); /* EPOLLET should only trigger once! */
	EQss(0, epoll_wait(epfd, events, 8, 0)); /* EPOLLET should only trigger once! */
	EQss(0, epoll_wait(epfd, events, 8, 0)); /* EPOLLET should only trigger once! */

	/* Now consume the data */
	EQss(3, read(pipes[0], buf, sizeof(buf)));
	assertf(memcmp(buf, "foo", 3) == 0, "buf = %$[hex]", 3, buf);

	EQss(0, epoll_wait(epfd, events, 8, 0)); /* Reading should still not be possible */
	EQss(0, epoll_wait(epfd, events, 8, 0)); /* Reading should still not be possible */
	EQss(0, epoll_wait(epfd, events, 8, 0)); /* Reading should still not be possible */

	/* Reading now should fail with EAGAIN because there is no data. */
	EQss(-1, read(pipes[0], buf, sizeof(buf)));
	EQd(errno, EAGAIN);

	EQss(0, epoll_wait(epfd, events, 8, 0)); /* Reading should still not be possible */
	EQss(0, epoll_wait(epfd, events, 8, 0)); /* Reading should still not be possible */
	EQss(0, epoll_wait(epfd, events, 8, 0)); /* Reading should still not be possible */

	EQss(3, write(pipes[1], "bar", 3)); /* Write some data. */

	/* The appearance of new data should have once again caused an edge trigger! */
	EQss(1, epoll_wait(epfd, events, 8, 0));
	EQx32(events[0].events, EPOLLIN);
	EQu64(events[0].data.u64, 9999);
	EQss(0, epoll_wait(epfd, events, 8, 0)); /* EPOLLET should only trigger once! */
	EQss(0, epoll_wait(epfd, events, 8, 0)); /* EPOLLET should only trigger once! */
	EQss(0, epoll_wait(epfd, events, 8, 0)); /* EPOLLET should only trigger once! */

	EQss(3, write(pipes[1], "bar", 3)); /* Write even more data. */

	/* Because the pipe was already non-empty, the second write should not trigger
	 * EPOLLET again (although it doing so would technically be allowed, since the
	 * kernel is allowed to trigger a sporadic signal internally, but knowing  how
	 * the backend of pipes  is implemented under KOS,  I can say with  certainty,
	 * that at least in the  case of pipes, no sporadic  signal should be able  to
	 * happen)
	 * For reference, look at the internal pipe buffer-backend used by the kernel,
	 * as implemented in /kos/src/libbuffer/ringbuffer.c
	 *
	 * Fun fact: My linux machine  (4.4.0-186-generic) sends  a second  edge-event
	 *           when  I try to run this test,  even though the write only further
	 *           extended an already non-empty pipe, so the is-readable  condition
	 *           of the monitored file didn't actually become raised, meaning that
	 *           there wasn't actually an edge to talk about.
	 */
#ifdef __linux__
	{
		ssize_t n = epoll_wait(epfd, events, 8, 0);
		LEss(0, n);
		if (n > 1)
			printf("warn: Writing to a non-empty pipe causes a secondary edge-event\n");
	}
#endif /* __linux__ */
	EQss(0, epoll_wait(epfd, events, 8, 0));
	EQss(0, epoll_wait(epfd, events, 8, 0));
	EQss(0, epoll_wait(epfd, events, 8, 0));


	ee.events   = EPOLLIN | EPOLLET;
	ee.data.u64 = 9999;
	/* Also throw in a test for `EPOLL_CTL_MOD' on deleted objects... */
	EQd(0, epoll_ctl(epfd, EPOLL_CTL_MOD, pipes[0], &ee));
	EQd(0, epoll_ctl(epfd, EPOLL_CTL_DEL, pipes[0], NULL));
	EQd(-1, epoll_ctl(epfd, EPOLL_CTL_MOD, pipes[0], &ee)); /* We've just deleted `pipes[0]'! */
	EQd(errno, ENOENT);
	errno = 0;

	EQd(-1, epoll_ctl(epfd, EPOLL_CTL_DEL, pipes[1], NULL)); /* The writer was never added! */
	EQd(errno, ENOENT);

	EQd(0, close(pipes[0]));
	EQd(0, close(pipes[1]));
	EQd(0, close(epfd));
}


DECL_END

#endif /* !GUARD_APPS_SYSTEM_TEST_TEST_EPOLL_C */
