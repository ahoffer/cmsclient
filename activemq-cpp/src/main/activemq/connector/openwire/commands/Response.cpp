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
#include <activemq/connector/openwire/commands/Response.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshaling code for OpenWire format for Response
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
Response::Response()
{
    this->correlationId = 0;
}

////////////////////////////////////////////////////////////////////////////////
Response::~Response()
{
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* Response::cloneDataStructure() const {
    Response* response = new Response();

    // Copy the data from the base class or classes
    response->copyDataStructure( this );

    return response;
}

////////////////////////////////////////////////////////////////////////////////
void Response::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand<transport::Response>::copyDataStructure( src );

    const Response* srcPtr = dynamic_cast<const Response*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "Response::copyDataStructure - src is NULL or invalid" );
    }
    this->setCorrelationId( srcPtr->getCorrelationId() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char Response::getDataStructureType() const {
    return Response::ID_RESPONSE; 
}

////////////////////////////////////////////////////////////////////////////////
std::string Response::toString() const {

    ostringstream stream;

    stream << "Begin Class = Response" << std::endl;
    stream << " Value of Response::ID_RESPONSE = 30" << std::endl; 
    stream << " Value of CorrelationId = " << this->getCorrelationId() << std::endl;
    // Copy the data of the base class or classes
    stream << BaseCommand<transport::Response>::toString();
    stream << "End Class = Response" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool Response::equals( const DataStructure* value ) const {
    const Response* valuePtr = dynamic_cast<const Response*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
int Response::getCorrelationId() const {
    return correlationId;
}

////////////////////////////////////////////////////////////////////////////////
void Response::setCorrelationId(int correlationId ) {
    this->correlationId = correlationId;
}

