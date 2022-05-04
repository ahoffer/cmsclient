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

#include <activemq/wireformat/openwire/marshal/generated/NetworkBridgeFilterMarshaller.h>

#include <activemq/commands/NetworkBridgeFilter.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/Pointer.h>

//
//     NOTE!: This file is autogenerated - do not modify!
//            if you need to make a change, please see the Java Classes in the
//            activemq-core module
//

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::commands;
using namespace activemq::wireformat;
using namespace activemq::wireformat::openwire;
using namespace activemq::wireformat::openwire::marshal;
using namespace activemq::wireformat::openwire::utils;
using namespace activemq::wireformat::openwire::marshal::generated;
using namespace decaf;
using namespace decaf::io;
using namespace decaf::lang;

///////////////////////////////////////////////////////////////////////////////
DataStructure* NetworkBridgeFilterMarshaller::createObject() const {
    return new NetworkBridgeFilter();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char NetworkBridgeFilterMarshaller::getDataStructureType() const {
    return NetworkBridgeFilter::ID_NETWORKBRIDGEFILTER;
}

///////////////////////////////////////////////////////////////////////////////
void NetworkBridgeFilterMarshaller::tightUnmarshal(OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs) {

    try {

        BaseDataStreamMarshaller::tightUnmarshal(wireFormat, dataStructure, dataIn, bs);

        NetworkBridgeFilter* info =
            dynamic_cast<NetworkBridgeFilter*>(dataStructure);

        int wireVersion = wireFormat->getVersion();

        info->setNetworkBrokerId(Pointer<BrokerId>(dynamic_cast<BrokerId* >(
            tightUnmarshalCachedObject(wireFormat, dataIn, bs))));
        if (wireVersion >= 10) {
            info->setMessageTTL(dataIn->readInt());
        }
        if (wireVersion >= 10) {
            info->setConsumerTTL(dataIn->readInt());
        }
    }
    AMQ_CATCH_RETHROW(decaf::io::IOException)
    AMQ_CATCH_EXCEPTION_CONVERT(exceptions::ActiveMQException, decaf::io::IOException)
    AMQ_CATCHALL_THROW(decaf::io::IOException)
}

///////////////////////////////////////////////////////////////////////////////
int NetworkBridgeFilterMarshaller::tightMarshal1(OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs) {

    try {

        NetworkBridgeFilter* info =
            dynamic_cast<NetworkBridgeFilter*>(dataStructure);

        int rc = BaseDataStreamMarshaller::tightMarshal1(wireFormat, dataStructure, bs);

        int wireVersion = wireFormat->getVersion();

        rc += tightMarshalCachedObject1(wireFormat, info->getNetworkBrokerId().get(), bs);
        if (wireVersion >= 10) {
        }
        if (wireVersion >= 10) {
        }

        return rc + 8;
    }
    AMQ_CATCH_RETHROW(decaf::io::IOException)
    AMQ_CATCH_EXCEPTION_CONVERT(exceptions::ActiveMQException, decaf::io::IOException)
    AMQ_CATCHALL_THROW(decaf::io::IOException)
}

///////////////////////////////////////////////////////////////////////////////
void NetworkBridgeFilterMarshaller::tightMarshal2(OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs) {

    try {

        BaseDataStreamMarshaller::tightMarshal2(wireFormat, dataStructure, dataOut, bs );

        NetworkBridgeFilter* info =
            dynamic_cast<NetworkBridgeFilter*>(dataStructure);

        int wireVersion = wireFormat->getVersion();

        tightMarshalCachedObject2(wireFormat, info->getNetworkBrokerId().get(), dataOut, bs);
        if (wireVersion >= 10) {
            dataOut->writeInt(info->getMessageTTL());
        }
        if (wireVersion >= 10) {
            dataOut->writeInt(info->getConsumerTTL());
        }
    }
    AMQ_CATCH_RETHROW(decaf::io::IOException)
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException)
    AMQ_CATCHALL_THROW(decaf::io::IOException)
}

///////////////////////////////////////////////////////////////////////////////
void NetworkBridgeFilterMarshaller::looseUnmarshal(OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn) {

    try {

        BaseDataStreamMarshaller::looseUnmarshal(wireFormat, dataStructure, dataIn);
        NetworkBridgeFilter* info =
            dynamic_cast<NetworkBridgeFilter*>(dataStructure);

        int wireVersion = wireFormat->getVersion();

        info->setNetworkBrokerId(Pointer<BrokerId>(dynamic_cast<BrokerId*>(
            looseUnmarshalCachedObject(wireFormat, dataIn))));
        if (wireVersion >= 10) {
            info->setMessageTTL(dataIn->readInt());
        }
        if (wireVersion >= 10) {
            info->setConsumerTTL(dataIn->readInt());
        }
    }
    AMQ_CATCH_RETHROW(decaf::io::IOException)
    AMQ_CATCH_EXCEPTION_CONVERT(exceptions::ActiveMQException, decaf::io::IOException)
    AMQ_CATCHALL_THROW(decaf::io::IOException)
}

///////////////////////////////////////////////////////////////////////////////
void NetworkBridgeFilterMarshaller::looseMarshal(OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut) {

    try {

        NetworkBridgeFilter* info =
            dynamic_cast<NetworkBridgeFilter*>(dataStructure);
        BaseDataStreamMarshaller::looseMarshal(wireFormat, dataStructure, dataOut);

        int wireVersion = wireFormat->getVersion();

        looseMarshalCachedObject(wireFormat, info->getNetworkBrokerId().get(), dataOut);
        if (wireVersion >= 10) {
            dataOut->writeInt(info->getMessageTTL());
        }
        if (wireVersion >= 10) {
            dataOut->writeInt(info->getConsumerTTL());
        }
    }
    AMQ_CATCH_RETHROW(decaf::io::IOException)
    AMQ_CATCH_EXCEPTION_CONVERT(exceptions::ActiveMQException, decaf::io::IOException)
    AMQ_CATCHALL_THROW(decaf::io::IOException)
}
