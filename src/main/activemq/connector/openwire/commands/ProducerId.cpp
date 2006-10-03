/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <activemq/connector/openwire/commands/ProducerId.h>

using namespace std;
using namespace activemq;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshalling code for OpenWire format for ProducerId
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
ProducerId::ProducerId()
{
    this->connectionId = "";
    this->value = 0;
    this->sessionId = 0;
}

////////////////////////////////////////////////////////////////////////////////
ProducerId::~ProducerId()
{
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ProducerId::getDataStructureType() const
{
    return ProducerId::ID_PRODUCERID; 
}

////////////////////////////////////////////////////////////////////////////////
const std::string& ProducerId::getConnectionId() const {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
std::string& ProducerId::getConnectionId() {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
void ProducerId::setConnectionId(const std::string& connectionId ) {
    this->connectionId = connectionId;
}

////////////////////////////////////////////////////////////////////////////////
const long long ProducerId::getValue() const {
    return value;
}

////////////////////////////////////////////////////////////////////////////////
long long ProducerId::getValue() {
    return value;
}

////////////////////////////////////////////////////////////////////////////////
void ProducerId::setValue(long long value ) {
    this->value = value;
}

////////////////////////////////////////////////////////////////////////////////
const long long ProducerId::getSessionId() const {
    return sessionId;
}

////////////////////////////////////////////////////////////////////////////////
long long ProducerId::getSessionId() {
    return sessionId;
}

////////////////////////////////////////////////////////////////////////////////
void ProducerId::setSessionId(long long sessionId ) {
    this->sessionId = sessionId;
}
