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

#include "PrimitiveMap.h"

using namespace activemq::util;
using namespace activemq::exceptions;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
PrimitiveMap::PrimitiveMap()
{
}

////////////////////////////////////////////////////////////////////////////////
PrimitiveMap::~PrimitiveMap()
{
}

////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::clear()
{
    valueNodeMap.clear();
}

////////////////////////////////////////////////////////////////////////////////
bool PrimitiveMap::contains( const string& key ) const{
    
    return valueNodeMap.contains( key );
}

////////////////////////////////////////////////////////////////////////////////
int PrimitiveMap::count() const{
    
    return valueNodeMap.count();
}

////////////////////////////////////////////////////////////////////////////////
bool PrimitiveMap::getBool( const string& key ) const 
    throw(NoSuchElementException){
        
    ValueNode node = valueNodeMap.getValue( key );
    return node.getBool();
}
    
////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::setBool( const string& key, bool value ){
    
    ValueNode node;
    node.setBool( value );
    
    valueNodeMap.setValue( key, node );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char PrimitiveMap::getByte( const string& key ) const 
    throw(NoSuchElementException){
        
    ValueNode node = valueNodeMap.getValue( key );
    return node.getByte();
}

////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::setByte( const string& key, unsigned char value ){
    ValueNode node;
    node.setByte( value );
    
    valueNodeMap.setValue( key, node );
}

////////////////////////////////////////////////////////////////////////////////
char PrimitiveMap::getChar( const string& key ) const 
    throw(NoSuchElementException){
        
    ValueNode node = valueNodeMap.getValue( key );
    return node.getChar();
}

////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::setChar( const string& key, char value ){
    ValueNode node;
    node.setChar( value );
    
    valueNodeMap.setValue( key, node );
}

////////////////////////////////////////////////////////////////////////////////
short PrimitiveMap::getShort( const string& key ) const 
    throw(NoSuchElementException){
        
    ValueNode node = valueNodeMap.getValue( key );
    return node.getShort();
}

////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::setShort( const string& key, short value ){
    ValueNode node;
    node.setShort( value );
    
    valueNodeMap.setValue( key, node );
}

////////////////////////////////////////////////////////////////////////////////
int PrimitiveMap::getInt( const string& key ) const 
    throw(NoSuchElementException){
        
    ValueNode node = valueNodeMap.getValue( key );
    return node.getInt();
}

////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::setInt( const string& key, int value ){
    ValueNode node;
    node.setInt( value );
    
    valueNodeMap.setValue( key, node );
}

////////////////////////////////////////////////////////////////////////////////
long long PrimitiveMap::getLong( const string& key ) const 
    throw(NoSuchElementException){
        
    ValueNode node = valueNodeMap.getValue( key );
    return node.getLong();
}

////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::setLong( const string& key, long long value ){
    ValueNode node;
    node.setLong( value );
    
    valueNodeMap.setValue( key, node );
}

////////////////////////////////////////////////////////////////////////////////
double PrimitiveMap::getDouble( const string& key ) const 
    throw(NoSuchElementException){
        
    ValueNode node = valueNodeMap.getValue( key );
    return node.getDouble();
}

////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::setDouble( const string& key, double value ){
    ValueNode node;
    node.setDouble( value );
    
    valueNodeMap.setValue( key, node );
}

////////////////////////////////////////////////////////////////////////////////
float PrimitiveMap::getFloat( const string& key ) const 
    throw(NoSuchElementException){
        
    ValueNode node = valueNodeMap.getValue( key );
    return node.getFloat();
}

////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::setFloat( const string& key, float value ){
    ValueNode node;
    node.setFloat( value );
    
    valueNodeMap.setValue( key, node );
}

////////////////////////////////////////////////////////////////////////////////
string PrimitiveMap::getString( const string& key ) const 
    throw(NoSuchElementException){
        
    ValueNode node = valueNodeMap.getValue( key );
    return node.getString();        
}

////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::setString( const string& key, const string& value ){
    ValueNode node;
    node.setString( value );
    
    valueNodeMap.setValue( key, node );
}

////////////////////////////////////////////////////////////////////////////////
void PrimitiveMap::remove( const string& key ){
    valueNodeMap.remove( key );
}

////////////////////////////////////////////////////////////////////////////////
vector<string> PrimitiveMap::getKeys() const{
    
    return valueNodeMap.getKeys();
}

////////////////////////////////////////////////////////////////////////////////
vector<PrimitiveMap::ValueNode> PrimitiveMap::getValues() const{
    
    return valueNodeMap.getValues();
}

