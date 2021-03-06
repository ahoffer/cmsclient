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
#include <activemq/commands/BrokerError.h>
#include <activemq/state/CommandVisitor.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/exceptions/NullPointerException.h>
#include <decaf/util/StringTokenizer.h>
#include <string>

#include <cms/CMSException.h>
#include <cms/CMSSecurityException.h>
#include <cms/MessageEOFException.h>
#include <cms/MessageFormatException.h>
#include <cms/MessageNotReadableException.h>
#include <cms/MessageNotWriteableException.h>
#include <cms/InvalidClientIdException.h>
#include <cms/InvalidDestinationException.h>
#include <cms/InvalidSelectorException.h>
#include <cms/IllegalStateException.h>
#include <cms/ResourceAllocationException.h>
#include <cms/TransactionInProgressException.h>
#include <cms/TransactionRolledBackException.h>
#include <cms/UnsupportedOperationException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::commands;
using namespace decaf::util;
using namespace decaf::lang;
using namespace decaf::lang::exceptions;

////////////////////////////////////////////////////////////////////////////////
BrokerError::BrokerError() : BaseCommand(), message(), exceptionClass(), stackTraceElements(), cause(), exCause() {
}

////////////////////////////////////////////////////////////////////////////////
BrokerError::BrokerError(decaf::lang::Pointer<decaf::lang::Exception> exCause) :
     BaseCommand(), message(), exceptionClass(), stackTraceElements(), cause(), exCause(exCause) {
}

////////////////////////////////////////////////////////////////////////////////
BrokerError::~BrokerError() {
    this->stackTraceElements.clear();
}

////////////////////////////////////////////////////////////////////////////////
void BrokerError::copyDataStructure(const DataStructure* src) {

    const BrokerError* srcErr = dynamic_cast<const BrokerError*>(src);

    if (srcErr == NULL || src == NULL) {
        throw NullPointerException(__FILE__, __LINE__, "BrokerError::copyCommand - src is NULL or invalid");
    }

    this->setMessage(srcErr->getMessage());
    this->setExceptionClass(srcErr->getExceptionClass());
    this->setStackTraceElements(srcErr->getStackTraceElements());
    this->setCause(srcErr->getCause());
    this->setLocalException(srcErr->getLocalException());
}

////////////////////////////////////////////////////////////////////////////////
Pointer<commands::Command> BrokerError::visit(activemq::state::CommandVisitor* visitor) {
    return visitor->processBrokerError(this);
}

////////////////////////////////////////////////////////////////////////////////
decaf::lang::Exception BrokerError::createExceptionObject() {

    StringTokenizer tokenizer(this->exceptionClass);


    std::string exceptionClass = this->exceptionClass;

    while (tokenizer.hasMoreTokens()) {
        exceptionClass = tokenizer.nextToken();
    }

    cms::CMSException* cause = NULL;

    if (exceptionClass == "JMSException") {
        cause = new cms::CMSException(this->message);
    } else if (exceptionClass == "JMSSecurityException") {
        cause = new cms::CMSSecurityException(this->message);
    } else if (exceptionClass == "MessageEOFException") {
        cause = new cms::MessageEOFException(this->message);
    } else if (exceptionClass == "MessageFormatException") {
        cause = new cms::MessageFormatException(this->message);
    } else if (exceptionClass == "MessageNotReadableException") {
        cause = new cms::MessageNotReadableException(this->message);
    } else if (exceptionClass == "MessageNotWriteableException") {
        cause = new cms::MessageNotWriteableException(this->message);
    } else if (exceptionClass == "InvalidClientIdException") {
        cause = new cms::InvalidClientIdException(this->message);
    } else if (exceptionClass == "InvalidDestinationException") {
        cause = new cms::InvalidDestinationException(this->message);
    } else if (exceptionClass == "InvalidSelectorException") {
        cause = new cms::InvalidSelectorException(this->message);
    } else if (exceptionClass == "IllegalStateException") {
        cause = new cms::IllegalStateException(this->message);
    } else if (exceptionClass == "ResourceAllocationException") {
        cause = new cms::ResourceAllocationException(this->message);
    } else if (exceptionClass == "TransactionInProgressException") {
        cause = new cms::TransactionInProgressException(this->message);
    } else if (exceptionClass == "TransactionRolledBackException") {
        cause = new cms::TransactionRolledBackException(this->message);
    } else if (exceptionClass == "UnsupportedOperationException") {
        cause = new cms::UnsupportedOperationException(this->message);
    } else {
        if (exCause != NULL) {
            cause = new cms::CMSException(this->message);
        } else {
            cause = new cms::CMSException(this->exCause->getMessage());
        }
    }

    // Wrap in a Decaf exception to carry the pointer until it can be
    // thrown in a context that will convey the correct type to the client.
    Exception theCause(__FILE__, __LINE__, cause, this->getMessage().c_str());
    return theCause;
}
