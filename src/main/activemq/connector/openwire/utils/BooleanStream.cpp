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
 
#include <activemq/connector/openwire/utils/BooleanStream.h>

using namespace std;
using namespace activemq;
using namespace activemq::io;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::utils;

///////////////////////////////////////////////////////////////////////////////
BooleanStream::BooleanStream()
{
    this->arrayLimit = 0;    
    this->arrayPos = 0;
    this->bytePos = 0;

    // Reserve 1K
    this->data.resize( 1000, 0 );
}

///////////////////////////////////////////////////////////////////////////////
BooleanStream::~BooleanStream()
{}

///////////////////////////////////////////////////////////////////////////////
bool BooleanStream::readBoolean() throw ( IOException ) {
    //assert arrayPos <= arrayLimit;
    unsigned char b = data[arrayPos];
    bool rc = ( ( b >> bytePos ) & 0x01 ) != 0;
    bytePos++;
    if( bytePos >= 8 ) {
        bytePos = 0;
        arrayPos++;
    }
    return rc;
}

///////////////////////////////////////////////////////////////////////////////
void BooleanStream::writeBoolean( bool value ) throw ( IOException ) {
    if( bytePos == 0 ) {
        arrayLimit++;
        
        if( (size_t)arrayLimit >= data.capacity() ) {
            // re-grow the array if necessary
            data.resize( data.size() * 2 );
        }
    }
    
    if( value ) {
        data[arrayPos] |= ( 0x01 << bytePos ); 
    }
    
    bytePos++;
    
    // Wrap around when we hit the next byte
    if( bytePos >= 8 ) {
        bytePos=0;
        arrayPos++;
    }
}

///////////////////////////////////////////////////////////////////////////////    
void BooleanStream::marshal( DataOutputStream* dataOut ) throw ( IOException ) {
    if( arrayLimit < 64 ) {
        dataOut->writeByte( arrayLimit );
    } else if( arrayLimit < 256 ) { // max value of unsigned char
        dataOut->writeByte( 0xC0 );
        dataOut->writeByte( arrayLimit );            
    } else {
        dataOut->writeByte( 0x80 );
        dataOut->writeShort( arrayLimit );            
    }
    
    // Dump the payload
    dataOut->write( &data[0], arrayLimit );
    clear();
}

///////////////////////////////////////////////////////////////////////////////    
void BooleanStream::marshal( std::vector< unsigned char >& dataOut ) {
    if( arrayLimit < 64 ) {
        dataOut.push_back( ( unsigned char ) arrayLimit );
    } else if( arrayLimit < 256 ) { // max value of unsigned byte
        dataOut.push_back( ( unsigned char ) 0xC0 );
        dataOut.push_back( ( unsigned char ) arrayLimit );            
    } else {
        dataOut.push_back( ( unsigned char ) 0x80 );
        dataOut.push_back( arrayLimit >> 8 );   // High Byte
        dataOut.push_back( arrayLimit & 0xFF ); // Low Byte 
    }
    
    // Insert all data from data into the passed buffer
    dataOut.insert( dataOut.end(), &data[0], &data[arrayLimit] );
}

///////////////////////////////////////////////////////////////////////////////    
void BooleanStream::unmarshal( DataInputStream* dataIn ) throw ( IOException ) {
    
    arrayLimit = (short)( dataIn->readByte() & 0xFF );
    
    if ( arrayLimit == 0xC0 ) {
        arrayLimit = (short)( dataIn->readByte() & 0xFF );
    } else if( arrayLimit == 0x80 ) {
        arrayLimit = dataIn->readShort();
    } 
    
    // Reserve space all at once if needed.
    if( data.capacity() < (size_t)arrayLimit ) {
        data.reserve( arrayLimit );
    }
    
    // Make sure we can accomodate all the data.
    data.resize( arrayLimit );

    // Make sure we get all the data we are expecting
    dataIn->readFully( &data[0], 0, arrayLimit );
    
    clear();
}

///////////////////////////////////////////////////////////////////////////////    
void BooleanStream::clear() {
    arrayPos = 0;
    bytePos = 0;
}

///////////////////////////////////////////////////////////////////////////////    
int BooleanStream::marshalledSize() {
    if( arrayLimit < 64 ) {
        return 1 + arrayLimit;
    } else if( arrayLimit < 256 ) {
        return 2 + arrayLimit;
    } else {
        return 3 + arrayLimit;
    }
}