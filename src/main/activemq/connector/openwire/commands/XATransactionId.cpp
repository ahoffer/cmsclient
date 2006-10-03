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
#include <activemq/connector/openwire/commands/XATransactionId.h>

using namespace std;
using namespace activemq;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshalling code for OpenWire format for XATransactionId
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
XATransactionId::XATransactionId()
{
    this->formatId = 0;
}

////////////////////////////////////////////////////////////////////////////////
XATransactionId::~XATransactionId()
{
}

////////////////////////////////////////////////////////////////////////////////
unsigned char XATransactionId::getDataStructureType() const
{
    return XATransactionId::ID_XATRANSACTIONID; 
}

////////////////////////////////////////////////////////////////////////////////
const int XATransactionId::getFormatId() const {
    return formatId;
}

////////////////////////////////////////////////////////////////////////////////
int XATransactionId::getFormatId() {
    return formatId;
}

////////////////////////////////////////////////////////////////////////////////
void XATransactionId::setFormatId(int formatId ) {
    this->formatId = formatId;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<char> XATransactionId::getGlobalTransactionId() const {
    return globalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<char> XATransactionId::getGlobalTransactionId() {
    return globalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
void XATransactionId::setGlobalTransactionId(std::vector<char> globalTransactionId ) {
    this->globalTransactionId = globalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<char> XATransactionId::getBranchQualifier() const {
    return branchQualifier;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<char> XATransactionId::getBranchQualifier() {
    return branchQualifier;
}

////////////////////////////////////////////////////////////////////////////////
void XATransactionId::setBranchQualifier(std::vector<char> branchQualifier ) {
    this->branchQualifier = branchQualifier;
}
