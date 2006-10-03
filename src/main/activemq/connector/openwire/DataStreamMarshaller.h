/**
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

#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_DATASTREAMMARSHALLER_H_
#define _ACTIVEMQ_CONNECTOR_OPENWIRE_DATASTREAMMARSHALLER_H_

#include <activemq/io/DataInputStream.h>
#include <activemq/io/DataOutputStream.h>
#include <activemq/io/IOException.h>
#include <activemq/connector/openwire/commands/DataStructure.h>
#include <activemq/connector/openwire/utils/BooleanStream.h>
#include <activemq/connector/openwire/OpenWireFormat.h>

namespace activemq{
namespace connector{
namespace openwire{
    
    /**
     * Base class for all classes that marshal commands for Openwire
     */
    class DataStreamMarshaller
    {
    public:
    
        DataStreamMarshaller() {}
        virtual ~DataStreamMarshaller() {}
    
        /**
         * Gets the DataStructureType that this class marshals/unmarshals
         * @returns byte Id of this classes DataStructureType
         */
        virtual unsigned char getDataStructureType() = 0;
        
        /**
         * Creates a new instance of the class that this class is a marshaling
         * director for.
         * @returns newly allocated Command
         */
        virtual commands::DataStructure* createObject() = 0;
    
        /**
         * Tight Marhsal to the given stream
         * @param format - The OpenwireFormat properties 
         * @param command -  the object to Marshal
         * @param bs - boolean stream to marshal to.
         * @throws IOException if an error occurs.
         */
        virtual int tightMarshal1( OpenWireFormat* format, 
                                   commands::DataStructure* command, 
                                   utils::BooleanStream* bs ) 
                                       throw ( io::IOException ) = 0;

        /**
         * Tight Marhsal to the given stream
         * @param format - The OpenwireFormat properties 
         * @param command -  the object to Marshal
         * @param ds - the DataOutputStream to Marshal to
         * @param bs - boolean stream to marshal to.
         * @throws IOException if an error occurs.
         */
        virtual void tightMarshal2( OpenWireFormat* format, 
                                    commands::DataStructure* command, 
                                    io::DataOutputStream* ds, 
                                    utils::BooleanStream* bs ) 
                                        throw ( io::IOException ) = 0;

        /**
         * Tight Un-marhsal to the given stream
         * @param format - The OpenwireFormat properties 
         * @param command -  the object to Un-Marshal
         * @param dis - the DataInputStream to Un-Marshal from
         * @param bs - boolean stream to unmarshal from.
         * @throws IOException if an error occurs.
         */
        virtual void tightUnmarshal( OpenWireFormat* format, 
                                     commands::DataStructure* command, 
                                     io::DataInputStream* dis, 
                                     utils::BooleanStream* bs ) 
                                        throw ( io::IOException ) = 0;
    
        /**
         * Tight Marhsal to the given stream
         * @param format - The OpenwireFormat properties 
         * @param command -  the object to Marshal
         * @param ds - DataOutputStream to marshal to
         * @throws IOException if an error occurs.
         */
        virtual void looseMarshal( OpenWireFormat* format, 
                                   commands::DataStructure* command, 
                                   io::DataOutputStream* ds ) 
                                       throw ( io::IOException ) = 0;

        /**
         * Loose Un-marhsal to the given stream
         * @param format - The OpenwireFormat properties 
         * @param command -  the object to Un-Marshal
         * @param dis - the DataInputStream to Un-Marshal from
         * @throws IOException if an error occurs.
         */
        virtual void looseUnmarshal( OpenWireFormat* format, 
                                     commands::DataStructure* command, 
                                     io::DataInputStream* dis ) 
                                        throw ( io::IOException ) = 0;

    };

}}}

#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_DATASTREAMMARSHALLER_H_*/