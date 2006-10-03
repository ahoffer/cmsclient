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

#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_CONNECTIONINFO_H_
#define _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_CONNECTIONINFO_H_

// Turn off warning message for ignored exception specification
#ifdef _MSC_VER
#pragma warning( disable : 4290 )
#endif

#include <activemq/connector/openwire/commands/BaseCommand.h>
#include <activemq/connector/openwire/commands/ConnectionId.h>
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
    class ConnectionInfo : public BaseCommand
    {
    protected:

        ConnectionId* connectionId;
        std::string clientId;
        std::string password;
        std::string userName;
        std::vector<BrokerId*> brokerPath;
        bool brokerMasterConnector;
        bool manageable;

    public:

        const static unsigned char ID_CONNECTIONINFO = 3;

    public:

        ConnectionInfo();
        virtual ~ConnectionInfo();

        virtual unsigned char getDataStructureType() const;
        virtual const ConnectionId* getConnectionId() const;
        virtual ConnectionId* getConnectionId();
        virtual void setConnectionId( ConnectionId* connectionId );

        virtual const std::string& getClientId() const;
        virtual std::string& getClientId();
        virtual void setClientId( const std::string& clientId );

        virtual const std::string& getPassword() const;
        virtual std::string& getPassword();
        virtual void setPassword( const std::string& password );

        virtual const std::string& getUserName() const;
        virtual std::string& getUserName();
        virtual void setUserName( const std::string& userName );

        virtual const std::vector<BrokerId*> getBrokerPath() const;
        virtual std::vector<BrokerId*> getBrokerPath();
        virtual void setBrokerPath( std::vector<BrokerId*> brokerPath );

        virtual const bool getBrokerMasterConnector() const;
        virtual bool getBrokerMasterConnector();
        virtual void setBrokerMasterConnector( bool brokerMasterConnector );

        virtual const bool getManageable() const;
        virtual bool getManageable();
        virtual void setManageable( bool manageable );

    };

}}}}

#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_CONNECTIONINFO_H_*/
