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

#include <activemq/connector/openwire/marshal/v2/TransactionInfoMarshaller.h>

#include <activemq/connector/openwire/commands/TransactionInfo.h>

//
//     NOTE!: This file is autogenerated - do not modify!
//            if you need to make a change, please see the Java Classes in the
//            activemq-core module
//

using namespace std;
using namespace activemq;
using namespace activemq::io;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace activemq::connector::openwire::marshal;
using namespace activemq::connector::openwire::util;
using namespace activemq::connector::openwire::marshal::v2;

///////////////////////////////////////////////////////////////////////////////
DataStructure* TransactionInfoMarshaller::createObject() const {
    return new TransactionInfo();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char TransactionInfoMarshaller::getDataStructureType() const {
    return TransactionInfo::ID_TRANSACTIONINFO;
}

///////////////////////////////////////////////////////////////////////////////
void TransactionInfoMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) {
   BaseCommandMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

    TransactionInfo* info =
        dynamic_cast<TransactionInfo*>( dataStructure );
    info->setConnectionId( dynamic_cast< ConnectionId* >(
        tightUnmarsalCachedObject( wireFormat, dataIn, bs ) );
    info->setTransactionId( dynamic_cast< TransactionId* >(
        tightUnmarsalCachedObject( wireFormat, dataIn, bs ) );
    info->setType( dataIn->readByte() );
}

///////////////////////////////////////////////////////////////////////////////
int TransactionInfoMarshaller::tightMarshal1( OpenWireFormat& wireFormat, DataStructure* dataStructure, BooleanStream& bs ) {

    TransactionInfo* info =
        dynamic_cast<TransactionInfo*>( dataStructure );

    int rc = BaseCommandMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
    DataStructure* data = 
        dynamic_cast< DataStructure* >( info->getConnectionId() );

    rc += tightMarshalCachedObject1( wireFormat, data, bs );
    DataStructure* data = 
        dynamic_cast< DataStructure* >( info->getTransactionId() );

    rc += tightMarshalCachedObject1( wireFormat, data, bs );

    return rc + 1;
}

///////////////////////////////////////////////////////////////////////////////
void TransactionInfoMarshaller::tightMarshal2( OpenWireFormat& wireFormat, DataStructure* dataStructure, DataOutputStream& dataOut, BooleanStream& bs ) {

    BaseCommandMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

    TransactionInfo* info =
        dynamic_cast<TransactionInfo*>( dataStructure );
    DataStructure* data = 
        dynamic_cast< DataStructure* >( info->getConnectionId() );

    tightMarshalCachedObject2( wireFormat, data, dataOut, bs );
    DataStructure* data = 
        dynamic_cast< DataStructure* >( info->getTransactionId() );

    tightMarshalCachedObject2( wireFormat, data, dataOut, bs );
    dataOut->write( info->getType() );
}

///////////////////////////////////////////////////////////////////////////////
void TransactionInfoMarshaller::looseUnmarshal( OpenWireFormat& wireFormat, DataStructure* dataStructure, DataInputStream& dataIn ) {
    BaseCommandMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
    TransactionInfo* info = 
        dynamic_cast<TransactionInfo*>( dataStructure );
   info->setConnectionId( dynamic_cast<ConnectionId* >( 
       looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
   info->setTransactionId( dynamic_cast<TransactionId* >( 
       looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
    info->setType( dataIn->readByte() );
}

///////////////////////////////////////////////////////////////////////////////
void TransactionInfoMarshaller::looseMarshal( OpenWireFormat& wireFormat, DataStructure* dataStructure, DataOutputStream& dataOut ) {
    TransactionInfo* info =
        dynamic_cast<TransactionInfo*>( dataStructure );
    BaseCommandMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

    DataStructure* data = 
        dynamic_cast< DataStructure* >( info->getConnectionId() );

    looseMarshalCachedObject( wireFormat, data, dataOut );
    DataStructure* data = 
        dynamic_cast< DataStructure* >( info->getTransactionId() );

    looseMarshalCachedObject( wireFormat, data, dataOut );
    dataOut->write( info->getType() );
}
