/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _DECAF_UTIL_CONCURRENT_LOCKS_READWRITELOCK_H_
#define _DECAF_UTIL_CONCURRENT_LOCKS_READWRITELOCK_H_

#include <decaf/util/Config.h>
#include <decaf/util/concurrent/locks/Lock.h>

namespace decaf {
namespace util {
namespace concurrent {
namespace locks {

    /**
     * A ReadWriteLock maintains a pair of associated locks, one for read-only operations
     * and one for writing. The read lock may be held simultaneously by multiple reader
     * threads, so long as there are no writers. The write lock is exclusive.
     * <p>
     * All ReadWriteLock implementations must guarantee that the memory synchronization
     * effects of writeLock operations (as specified in the Lock interface) also hold with
     * respect to the associated readLock. That is, a thread successfully acquiring the read
     * lock will see all updates made upon previous release of the write lock.
     * <p>
     * A read-write lock allows for a greater level of concurrency in accessing shared data
     * than that permitted by a mutual exclusion lock. It exploits the fact that while only
     * a single thread at a time (a writer thread) can modify the shared data, in many cases
     * any number of threads can concurrently read the data (hence reader threads). In theory,
     * the increase in concurrency permitted by the use of a read-write lock will lead to
     * performance improvements over the use of a mutual exclusion lock. In practice this
     * increase in concurrency will only be fully realized on a multi-processor, and then
     * only if the access patterns for the shared data are suitable.
     * <p>
     * Whether or not a read-write lock will improve performance over the use of a mutual
     * exclusion lock depends on the frequency that the data is read compared to being
     * modified, the duration of the read and write operations, and the contention for the
     * data - that is, the number of threads that will try to read or write the data at the
     * same time. For example, a collection that is initially populated with data and
     * thereafter infrequently modified, while being frequently searched (such as a
     * directory of some kind) is an ideal candidate for the use of a read-write lock.
     * However, if updates become frequent then the data spends most of its time being
     * exclusively locked and there is little, if any increase in concurrency. Further, if
     * the read operations are too short the overhead of the read-write lock implementation
     * (which is inherently more complex than a mutual exclusion lock) can dominate the
     * execution cost, particularly as many read-write lock implementations still serialize
     * all threads through a small section of code. Ultimately, only profiling and
     * measurement will establish whether the use of a read-write lock is suitable for your
     * application.
     * <p>
     * Although the basic operation of a read-write lock is straight-forward, there are many
     * policy decisions that an implementation must make, which may affect the effectiveness
     * of the read-write lock in a given application. Examples of these policies include:
     *
     *  * Determining whether to grant the read lock or the write lock, when both readers and
     *    writers are waiting, at the time that a writer releases the write lock. Writer
     *    preference is common, as writes are expected to be short and infrequent. Reader
     *    preference is less common as it can lead to lengthy delays for a write if the
     *    readers are frequent and long-lived as expected. Fair, or "in-order" implementations
     *    are also possible.
     *  * Determining whether readers that request the read lock while a reader is active and
     *    a writer is waiting, are granted the read lock. Preference to the reader can delay
     *    the writer indefinitely, while preference to the writer can reduce the potential for
     *    concurrency.
     *  * Determining whether the locks are reentrant: can a thread with the write lock
     *    reacquire it? Can it acquire a read lock while holding the write lock? Is the read
     *    lock itself reentrant?
     *  * Can the write lock be downgraded to a read lock without allowing an intervening
     *    writer? Can a read lock be upgraded to a write lock, in preference to other waiting
     *    readers or writers?
     *
     * You should consider all of these things when evaluating the suitability of a given
     * implementation for your application.
     *
     * @since 1.0
     */
    class DECAF_API ReadWriteLock {
    public:

        virtual ~ReadWriteLock() {}

        /**
         * Returns the lock used for reading.
         * @returns the lock used for reading.
         */
        virtual Lock& readLock() = 0;

        /**
         * Returns the lock used for writing.
         * @returns the lock used for writing.
         */
        virtual Lock& writeLock() = 0;

    };

}}}}

#endif /*_DECAF_UTIL_CONCURRENT_LOCKS_READWRITELOCK_H_*/
