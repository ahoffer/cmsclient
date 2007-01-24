/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_ACTIVEMQMESSAGEBASE_H_
#define _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_ACTIVEMQMESSAGEBASE_H_

#include <activemq/connector/openwire/commands/Message.h>
#include <activemq/core/ActiveMQMessage.h>
#include <activemq/connector/openwire/marshal/BaseDataStreamMarshaller.h>
#include <activemq/connector/openwire/marshal/PrimitiveMapMarshaller.h>
#include <activemq/core/ActiveMQAckHandler.h>
#include <activemq/util/Date.h>
#include <activemq/util/PrimitiveMap.h>

namespace activenq{
namespace connector{
namespace openwire{
namespace commands{
    
    /**
     * Base class for all Messages tagged with the ActiveMQXXXMessage 
     * type.  The class implements the basic wrapper around the generated
     * Message class as well as satisfying the contract of the 
     * core::ActiveMQMessage interface and the cms::Message method of which
     * T must be a derviation of.
     */
    template< typename T>
    class ActiveMQMessageBase : public T,
                                public Message, 
                                public core::ActiveMQMessage {
    
    public:
    
        ActiveMQMessageBase() {}
        virtual ~ActiveMQMessageBase() {}
        
        /**
         * Copy the contents of the passed object into this objects
         * members, overwriting any existing data.
         * @return src - Source Object
         */
        virtual void copyDataStructure( const DataStructure* src ) {        
            Message::copyDataStructure( src );
        }

        /**
         * Indicates that this command is aware of Marshalling, and needs
         * to have its Marshalling methods invoked.
         * @returns boolean indicating desire to be in marshalling stages
         */
        virtual bool IsMarshallAware() {
            return true;
        }
        
        /**
         * Handles the marshalling of the objects properties into the 
         * internal byte array before the object is marshalled to the
         * wire
         * @param wireFormat - the wireformatting controller
         */
        virtual void beforeMarshall( OpenWireFormat* wireFormat ) {
            try{
                    
                marshalledProperties.clear();
                if( !properties.isEmpty() )
                {
                    PrimitiveMapMarshaller::marshal( 
                        &properties, marshalledProperties );
                }
            }
            AMQ_CATCH_RETHROW( exceptions::ActiveMQException )
            AMQ_CATCHALL_THROW( exceptions::ActiveMQException )
        }

    public:   // core::ActiveMQMessage
    
        /**
         * Sets the Acknowledgement Handler that this Message will use
         * when the Acknowledge method is called.
         * @param handler ActiveMQAckHandler to call
         */
        virtual void setAckHandler( core::ActiveMQAckHandler* handler ) {
            this->ackHandler = handler;
        }
        
        /**
         * Gets the Acknowledgement Handler that this Message will use
         * when the Acknowledge method is called.
         * @returns handler ActiveMQAckHandler to call or NULL if not set
         */
        virtual core::ActiveMQAckHandler* getAckHandler() const {
            return this->ackHandler;
        }

        /**
         * Gets the number of times this message has been redelivered.
         * @return redelivery count
         */
        virtual int getRedeliveryCount(void) const {
            return redeliveryCount;
        }
        
        /**
         * Sets the count of the number of times this message has been 
         * redelivered
         * @param count the redelivery count
         */
        virtual void setRedeliveryCount( int count ) {
            this->redeliveryCount = count;
        }

        /**
         * Returns if this message has expired, meaning that its
         * Expiration time has elapsed.
         * @returns true if message is expired.
         */
        virtual bool isExpired() const {
            return false;
        }

    public:   // CMS Message          

        /**
         * Acknowledges all consumed messages of the session 
         * of this consumed message.
         */
        virtual void acknowledge(void) const throw( cms::CMSException ) {
            try{
                this->getAckHandler()->acknowledgeMessage( this );
            }
            AMQ_CATCH_RETHROW( exceptions::ActiveMQException )
            AMQ_CATCHALL_THROW( exceptions::ActiveMQException )
        }

        /**
         * Clears out the body of the message.  This does not clear the
         * headers or properties.
         */
        virtual void clearBody() {
            this->setContent( std::vector<unsigned char>() );
        }
        
        /**
         * Clears the message properties.  Does not clear the body or
         * header values.
         */
        virtual void clearProperties() {}
        
        /**
         * Retrieves the propery names.
         * @return The complete set of property names currently in this
         * message.
         */
        virtual std::vector<std::string> getPropertyNames() const ;
        
        /**
         * Indicates whether or not a given property exists.
         * @param name The name of the property to look up.
         * @return True if the property exists in this message.
         */
        virtual bool propertyExists( const std::string& name ) const;
        
        /**
         * Gets a boolean property.
         * @param name The name of the property to retrieve.
         * @return The value for the named property.
         * @throws CMSException if the property does not exist.
         */
        virtual bool getBooleanProperty( const std::string& name ) const 
            throw( cms::CMSException );
            
        /**
         * Gets a byte property.
         * @param name The name of the property to retrieve.
         * @return The value for the named property.
         * @throws CMSException if the property does not exist.
         */
        virtual unsigned char getByteProperty( const std::string& name ) const 
            throw( cms::CMSException );
            
        /**
         * Gets a double property.
         * @param name The name of the property to retrieve.
         * @return The value for the named property.
         * @throws CMSException if the property does not exist.
         */
        virtual double getDoubleProperty( const std::string& name ) const 
            throw( cms::CMSException );
            
        /**
         * Gets a float property.
         * @param name The name of the property to retrieve.
         * @return The value for the named property.
         * @throws CMSException if the property does not exist.
         */
        virtual float getFloatProperty( const std::string& name ) const 
            throw( cms::CMSException );
            
        /**
         * Gets a int property.
         * @param name The name of the property to retrieve.
         * @return The value for the named property.
         * @throws CMSException if the property does not exist.
         */
        virtual int getIntProperty( const std::string& name ) const 
            throw( cms::CMSException );
            
        /**
         * Gets a long property.
         * @param name The name of the property to retrieve.
         * @return The value for the named property.
         * @throws CMSException if the property does not exist.
         */
        virtual long long getLongProperty( const std::string& name ) const 
            throw( cms::CMSException );
            
        /**
         * Gets a short property.
         * @param name The name of the property to retrieve.
         * @return The value for the named property.
         * @throws CMSException if the property does not exist.
         */
        virtual short getShortProperty( const std::string& name ) const 
            throw( cms::CMSException );
            
        /**
         * Gets a string property.
         * @param name The name of the property to retrieve.
         * @return The value for the named property.
         * @throws CMSException if the property does not exist.
         */
        virtual std::string getStringProperty( const std::string& name ) const 
            throw( cms::CMSException );
        
        /**
         * Sets a boolean property.
         * @param name The name of the property to retrieve.
         * @param value The value for the named property.
         * @throws CMSException
         */
        virtual void setBooleanProperty( const std::string& name,
            bool value ) throw( cms::CMSException );
            
        /**
         * Sets a byte property.
         * @param name The name of the property to retrieve.
         * @param value The value for the named property.
         * @throws CMSException
         */
        virtual void setByteProperty( const std::string& name,
            unsigned char value ) throw( cms::CMSException );
            
        /**
         * Sets a double property.
         * @param name The name of the property to retrieve.
         * @param value The value for the named property.
         * @throws CMSException
         */
        virtual void setDoubleProperty( const std::string& name,
            double value ) throw( cms::CMSException );
            
        /**
         * Sets a float property.
         * @param name The name of the property to retrieve.
         * @param value The value for the named property.
         * @throws CMSException
         */
        virtual void setFloatProperty( const std::string& name,
            float value ) throw( cms::CMSException );
            
        /**
         * Sets a int property.
         * @param name The name of the property to retrieve.
         * @param value The value for the named property.
         * @throws CMSException
         */
        virtual void setIntProperty( const std::string& name,
            int value ) throw( cms::CMSException );
            
        /**
         * Sets a long property.
         * @param name The name of the property to retrieve.
         * @param value The value for the named property.
         * @throws CMSException
         */
        virtual void setLongProperty( const std::string& name,
            long long value ) throw( cms::CMSException );
            
        /**
         * Sets a short property.
         * @param name The name of the property to retrieve.
         * @param value The value for the named property.
         * @throws CMSException
         */
        virtual void setShortProperty( const std::string& name,
            short value ) throw( cms::CMSException );
            
        /**
         * Sets a string property.
         * @param name The name of the property to retrieve.
         * @param value The value for the named property.
         * @throws CMSException
         */
        virtual void setStringProperty( const std::string& name,
            const std::string& value ) throw( cms::CMSException );
      
        /**
         * Get the Correlation Id for this message
         * @return string representation of the correlation Id
         */
        virtual std::string getCMSCorrelationId(void) const {
            return this->getCorrelationId();
        }

        /**
         * Sets the Correlation Id used by this message
         * @param correlationId - String representing the correlation id.
         */
        virtual void setCMSCorrelationId( const std::string& correlationId ) {
            this->setCorrelationId( correlationId );
        }

        /**
         * Gets the DeliveryMode for this message
         * @return DeliveryMode enumerated value.
         */
        virtual int getCMSDeliveryMode(void) const {
            return this->isPersistent();
        }

        /**
         * Sets the DeliveryMode for this message
         * @param mode - DeliveryMode enumerated value.
         */
        virtual void setCMSDeliveryMode( int mode ) {
            this->setPersistent( mode != 0 );
        }
      
        /**
         * Gets the Destination for this Message, returns a
         * @return Destination object
         */
        virtual const cms::Destination* getCMSDestination(void) const {
            return dynamic_cast<const cms::Destination*>(
                this->getDestination() );
        }
      
        /**
         * Sets the Destination for this message
         * @param destination - Destination Object
         */
        virtual void setCMSDestination( const cms::Destination* destination ) {
            this->setDestination( destination );
        }
      
        /**
         * Gets the Expiration Time for this Message
         * @return time value
         */
        virtual long long getCMSExpiration(void) const {
            return this->getExpiration();
        }
      
        /**
         * Sets the Expiration Time for this message
         * @param expireTime - time value
         */
        virtual void setCMSExpiration( long long expireTime ) {
            this->setExpiration( expireTime );
        }
      
        /**
         * Gets the CMS Message Id for this Message
         * @return time value
         */
        virtual std::string getCMSMessageId(void) const {
            return marshal::BaseDataStreamMarshaller::toString( this->getMessageId() );
        }
      
        /**
         * Sets the CMS Message Id for this message
         * @param id - time value
         */
        virtual void setCMSMessageId( const std::string& id AMQCPP_UNUSED) {}
      
        /**
         * Gets the Priority Value for this Message
         * @return priority value
         */
        virtual int getCMSPriority(void) const {
            return this->getPriority();
        }
      
        /**
         * Sets the Priority Value for this message
         * @param priority - priority value for this message
         */
        virtual void setCMSPriority( int priority ) {
            this->setPriority( priority );
        }

        /**
         * Gets the Redelivered Flag for this Message
         * @return redelivered value
         */
        virtual bool getCMSRedelivered(void) const {
            return this->getRedeliveryCounter() != 0;
        }
      
        /**
         * Sets the Redelivered Flag for this message
         * @param redelivered - boolean redelivered value
         */
        virtual void setCMSRedelivered( bool redelivered AMQCPP_UNUSED) {}

        /**
         * Gets the CMS Reply To Address for this Message
         * @return Reply To Value
         */
        virtual const cms::Destination* getCMSReplyTo(void) const {
            return this->getReplyTo();
        }
      
        /**
         * Sets the CMS Reply To Address for this message
         * @param id - Reply To value
         */
        virtual void setCMSReplyTo( const cms::Destination* destination ) {
            this->setRepyTo( destination );
        }

        /**
         * Gets the Time Stamp for this Message
         * @return time stamp value
         */
        virtual long long getCMSTimeStamp(void) const {
            return this->getTimestamp();
        }
      
        /**
         * Sets the Time Stamp for this message
         * @param timeStamp - integer time stamp value
         */
        virtual void setCMSTimeStamp( long long timeStamp ) {
            this->setTimestamp( timeStamp );
        }

        /**
         * Gets the CMS Message Type for this Message
         * @return type value
         */
        virtual std::string getCMSMessageType(void) const {
            return this->getType();
        }
      
        /**
         * Sets the CMS Message Type for this message
         * @param type - message type value string
         */
        virtual void setCMSMessageType( const std::string& type ) {
            this->setType( type );
        }

    private:
   
        core::ActiveMQAckHandler* ackHandler;
        int redeliveryCount;
        util::PrimitiveMap properties;

    };

}}}}

#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_ACTIVEMQMESSAGEBASE_H_*/