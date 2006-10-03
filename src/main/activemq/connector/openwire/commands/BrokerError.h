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

#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_BROKERERROR_H_
#define _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_BROKERERROR_H_

#include <activemq/connector/openwire/commands/BaseCommand.h>

#include <string>
#include <vector>

namespace activemq{
namespace connector{
namespace openwire{
namespace commands{
           
    /**
     * This class represents an Exception sent from the Broker.  The Broker
     * sends java Throwables, so we must mimic its structure here.
     */
    class BrokerError : public BaseCommand
    {
    public:

        struct StackTraceElement
        {
            std::string ClassName;
            std::string FileName;
            std::string MethodName;
            int LineNumber;
        };

    public:

        BrokerError() {}
        virtual ~BrokerError() {}
        
        /**
         * Gets the string holding the error message
         * @returns String Message
         */
        virtual const std::string& getMessage() const {
            return message;
        }
        
        /**
         * Sets the string that contains the error Message
         * @param message - String Error Message
         */
        virtual void setMessage( const std::string& message ) {
            this->message = message;
        }

        /**
         * Gets the string holding the Exception Class name
         * @returns Exception Class name
         */
        virtual const std::string& getExceptionClass() const {
            return exceptionClass;
        }

        /**
         * Sets the string that contains the Exception Class name
         * @param exceptionClass - String Exception Class name
         */
        virtual void setExceptionClass( const std::string& exceptionClass ) {
            this->exceptionClass = exceptionClass;
        }

        /**
         * Gets the Broker Error that caused this exception
         * @returns Broker Error Pointer
         */
        virtual BrokerError* getCause() const {
            return cause;
        }
        
        /**
         * Sets the Broker Error that caused this exception
         * @param cause - Broker Error
         */
        virtual void setCause( BrokerError* cause ) {
            this->cause = cause;
        }

        /**
         * Gets the Stack Trace Elemtns for the Exception
         * @returns Stack Trace Elements
         */
        virtual const std::vector<StackTraceElement*>& getStackTraceElements() const {
            return stackTraceElements;
        }
        
        /**
         * Sets the Stack Trace Elements for this Exception
         * @param stackTraceElements - Stack Trace Elements
         */
        virtual void setCause( const std::vector<StackTraceElement*>& stackTraceElements ) {
            this->stackTraceElements = stackTraceElements;
        }

    private:

        std::string message;
        std::string exceptionClass;
        std::vector<StackTraceElement*> stackTraceElements;
        BrokerError* cause;

    };

}}}}

#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_BROKERERROR_H_*/