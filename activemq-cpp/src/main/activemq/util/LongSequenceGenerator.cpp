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

#include "LongSequenceGenerator.h"
#include <decaf/util/concurrent/Concurrent.h>

using namespace activemq;
using namespace activemq::util;
using namespace decaf::util::concurrent;

////////////////////////////////////////////////////////////////////////////////
LongSequenceGenerator::LongSequenceGenerator() : lastSequenceId(0), mutex() {
}

////////////////////////////////////////////////////////////////////////////////
LongSequenceGenerator::~LongSequenceGenerator() {
}

////////////////////////////////////////////////////////////////////////////////
long long LongSequenceGenerator::getNextSequenceId() {

    synchronized(&mutex) {
        return this->lastSequenceId++;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
long long LongSequenceGenerator::getLastSequenceId() {

    synchronized(&mutex) {
        return this->lastSequenceId;
    }

    return 0;
}
