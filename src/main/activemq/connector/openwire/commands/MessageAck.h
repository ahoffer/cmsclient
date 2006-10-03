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

#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_MESSAGEACK_H_
#define _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_MESSAGEACK_H_

// Turn off warning message for ignored exception specification
#ifdef _MSC_VER
#pragma warning( disable : 4290 )
#endif

#include <activemq/connector/openwire/commands/BaseCommand.h>
#include <activemq/connector/openwire/commands/ActiveMQDestination.h>
#include <activemq/connector/openwire/commands/TransactionId.h>
#include <activemq/connector/openwire/commands/ConsumerId.h>
#include <activemq/connector/openwire/commands/MessageId.h>
#include <activemq/connector/openwire/commands/MessageId.h>
#include <vector>
#include <string>

namespace activemq{
namespace connector{
namespace openwire{
namespace commands{

    /*
     *
     *  Command and marshalling code for OpenWire format for ${className}
     *
     *
     *  NOTE!: This file is autogenerated - do not modify!
     *         if you need to make a change, please see the Java Classes
     *         in the activemq-openwire-generator module
     *
     */
    class MessageAck : public BaseCommand
    {
    protected:

        ActiveMQDestination* destination;
        TransactionId* transactionId;
        ConsumerId* consumerId;
        char ackType;
        MessageId* firstMessageId;
        MessageId* lastMessageId;
        int messageCount;

    public:

        const static unsigned char ID_MESSAGEACK = 22;

    public:

        MessageAck();
        virtual ~MessageAck();

        virtual unsigned char getDataStructureType() const;
        virtual const ActiveMQDestination* getDestination() const;
        virtual ActiveMQDestination* getDestination();
        virtual void setDestination( ActiveMQDestination* destination );

        virtual const TransactionId* getTransactionId() const;
        virtual TransactionId* getTransactionId();
        virtual void setTransactionId( TransactionId* transactionId );

        virtual const ConsumerId* getConsumerId() const;
        virtual ConsumerId* getConsumerId();
        virtual void setConsumerId( ConsumerId* consumerId );

        virtual const char getAckType() const;
        virtual char getAckType();
        virtual void setAckType( char ackType );

        virtual const MessageId* getFirstMessageId() const;
        virtual MessageId* getFirstMessageId();
        virtual void setFirstMessageId( MessageId* firstMessageId );

        virtual const MessageId* getLastMessageId() const;
        virtual MessageId* getLastMessageId();
        virtual void setLastMessageId( MessageId* lastMessageId );

        virtual const int getMessageCount() const;
        virtual int getMessageCount();
        virtual void setMessageCount( int messageCount );

    };

}}}}

#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_MESSAGEACK_H_*/
