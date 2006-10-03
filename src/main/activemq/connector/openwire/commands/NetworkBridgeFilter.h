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

#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_NETWORKBRIDGEFILTER_H_
#define _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_NETWORKBRIDGEFILTER_H_

// Turn off warning message for ignored exception specification
#ifdef _MSC_VER
#pragma warning( disable : 4290 )
#endif

#include <activemq/connector/openwire/commands/BaseDataStructure.h>
#include <activemq/connector/openwire/commands/BrokerId.h>
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
    class NetworkBridgeFilter : public BaseDataStructure
    {
    protected:

        int networkTTL;
        BrokerId* networkBrokerId;

    public:

        const static unsigned char ID_NETWORKBRIDGEFILTER = 91;

    public:

        NetworkBridgeFilter();
        virtual ~NetworkBridgeFilter();

        virtual unsigned char getDataStructureType() const;
        virtual const int getNetworkTTL() const;
        virtual int getNetworkTTL();
        virtual void setNetworkTTL( int networkTTL );

        virtual const BrokerId* getNetworkBrokerId() const;
        virtual BrokerId* getNetworkBrokerId();
        virtual void setNetworkBrokerId( BrokerId* networkBrokerId );

    };

}}}}

#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_NETWORKBRIDGEFILTER_H_*/
