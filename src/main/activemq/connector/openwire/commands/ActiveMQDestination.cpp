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
#include <activemq/connector/openwire/commands/ActiveMQDestination.h>

using namespace std;
using namespace activemq;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination::ActiveMQDestination()
{
    this->physicalName = "";
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination::~ActiveMQDestination()
{
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ActiveMQDestination::getDataStructureType() const
{
    return ActiveMQDestination::ID_ACTIVEMQDESTINATION; 
}

////////////////////////////////////////////////////////////////////////////////
const std::string& ActiveMQDestination::getPhysicalName() const {
    return physicalName;
}

////////////////////////////////////////////////////////////////////////////////
std::string& ActiveMQDestination::getPhysicalName() {
    return physicalName;
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQDestination::setPhysicalName(const std::string& physicalName ) {
    this->physicalName = physicalName;
}
