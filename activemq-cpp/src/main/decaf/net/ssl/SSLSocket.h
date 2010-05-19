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

#ifndef _DECAF_NET_SSL_SSLSOCKET_H_
#define _DECAF_NET_SSL_SSLSOCKET_H_

#include <decaf/util/Config.h>

#include <decaf/net/Socket.h>
#include <decaf/net/ssl/SSLParameters.h>

namespace decaf {
namespace net {
namespace ssl {

    /**
     *
     * @since 1.0
     */
    class DECAF_API SSLSocket : public Socket {
    public:

        SSLSocket();

        virtual ~SSLSocket();

    public:

        /**
         * Gets a vector containing the names of all the cipher suites that are supported by this
         * SSLSocket.  Normally not all of these cipher suites will be enabled on the Socket.
         *
         * @returns a vector containing the names of all the supported cipher suites.
         */
        virtual std::vector<std::string> getSupportedCipherSuites() const = 0;

        /**
         * Gets a vector containing the names of all the protocols that could be enabled for
         * this SSLSocket instance.
         *
         * @returns a vector containing the names of all the supported protocols.
         */
        virtual std::vector<std::string> getSupportedProtocols() const = 0;

        /**
         * Returns a vector containing the names of all the currently enabled Cipher Suites for
         * this SSL Socket.
         *
         * @return vector of the names of all enabled Cipher Suites.
         */
        virtual std::vector<std::string> getEnabledCipherSuites() const = 0;

        /**
         * Sets the Cipher Suites that are to be enabled on the SSL Socket connection.  Each of the
         * named Cipher Suites must appear in the list of supported cipher suites for this connection
         * or an exception will be thrown.
         *
         * @param suites
         *      An Vector of names for all the Cipher Suites that are to be enabled.
         *
         * @throws IllegalArgumentException if the vector is empty or one of the names is invalid.
         */
        virtual void setEnabledCipherSuites( const std::vector<std::string>& suites ) = 0;

        /**
         * Returns a vector containing the names of all the currently enabled Protocols for
         * this SSL Socket.
         *
         * @return vector of the names of all enabled Protocols.
         */
        virtual std::vector<std::string> getEnabledProtocols() const = 0;

        /**
         * Sets the Protocols that are to be enabled on the SSL Socket connection.  Each of the
         * named Protocols must appear in the list of supported protocols suites for this connection
         * or an exception will be thrown.
         *
         * @param protocols
         *      An Vector of names for all the Protocols that are to be enabled.
         *
         * @throws IllegalArgumentException if the vector is empty or one of the names is invalid.
         */
        virtual void setEnabledProtocols( const std::vector<std::string>& protocols ) = 0;

        /**
         * Returns an SSLParameters object for this SSLSocket instance.
         *
         * The cipherSuites and protocols vectors in the returned SSLParameters reference will
         * never be empty.
         *
         * @returns an SSLParameters object with the settings in use for the SSLSocket.
         */
        virtual SSLParameters getSSLParameters() const;

        /**
         * Sets the SSLParameters for this SSLSocket using the supplied SSLParameters instance.
         *
         * If the cipherSutes vector in the SSLParameters instance is not empty them the
         * setEnabledCipherSuites method is called with that vector, if the protocols vector in
         * the SSLParameters instance is not empty then the setEnabledProtocols method is called
         * with that vector.  If the needClientAuth value or the wantClientAuth value is true then
         * the setNeedClientAuth and setWantClientAuth methods are called respectively with a
         * value of true, otherwise the setWantClientAuth method is called with a value of false.
         *
         * @param value
         *      The SSLParameters instance that is used to update this SSLSocket's settings.
         *
         * @throws IllegalArgumentException if an error occurs while calling setEnabledCipherSuites
         *         or setEnabledProtocols.
         */
        virtual void setSSLParameters( const SSLParameters& value );

    };

}}}

#endif /* _DECAF_NET_SSL_SSLSOCKET_H_ */
