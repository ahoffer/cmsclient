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

#ifndef _DECAF_INTERNAL_NET_SSL_OPENSSL_OPENSSLSOCKET_H_
#define _DECAF_INTERNAL_NET_SSL_OPENSSL_OPENSSLSOCKET_H_

#include <decaf/util/Config.h>

#include <decaf/net/ssl/SSLSocket.h>

#include <decaf/io/InputStream.h>
#include <decaf/io/OutputStream.h>

namespace decaf {
namespace internal {
namespace net {
namespace ssl {
namespace openssl {

    class SocketData;

    /**
     * Wraps a a Normal Socket object and extends or overrides functions in that class to make
     * use of the OpenSSL Socket API.
     *
     * @since 1.0
     */
    class DECAF_API OpenSSLSocket : public decaf::net::ssl::SSLSocket {
    private:

        // Private data related to the OpenSSL Socket impl.
        SocketData* data;

        // The InputStream owned by this Socket
        decaf::io::InputStream* input;

        // The OutputStream owned by this Socket
        decaf::io::OutputStream* output;

    public:

        OpenSSLSocket( void* ssl );

        virtual ~OpenSSLSocket();

    public:  // Socket Overrides.

        /**
         * {@inheritDoc}
         */
        virtual void connect( const std::string& host, int port, int timeout )
            throw( decaf::io::IOException,
                   decaf::lang::exceptions::IllegalArgumentException );

        /**
         * {@inheritDoc}
         */
        virtual void close() throw( decaf::io::IOException );

        /**
         * {@inheritDoc}
         */
        virtual decaf::io::InputStream* getInputStream() throw( decaf::io::IOException );

        /**
         * {@inheritDoc}
         */
        virtual decaf::io::OutputStream* getOutputStream() throw( decaf::io::IOException );

        /**
         * {@inheritDoc}
         */
        virtual void shutdownInput() throw( decaf::io::IOException );

        /**
         * {@inheritDoc}
         */
        virtual void shutdownOutput() throw( decaf::io::IOException );

        /**
         * {@inheritDoc}
         */
        virtual void setOOBInline( bool value ) throw( decaf::net::SocketException );

        /**
         * {@inheritDoc}
         */
        virtual void sendUrgentData( int data ) throw( decaf::io::IOException );

    public:  // SSLSocket Overrides

        /**
         * {@inheritDoc}
         */
        virtual std::vector<std::string> getSupportedCipherSuites() const;

        /**
         * {@inheritDoc}
         */
        virtual std::vector<std::string> getSupportedProtocols() const;

        /**
         * {@inheritDoc}
         */
        virtual std::vector<std::string> getEnabledCipherSuites() const;

        /**
         * {@inheritDoc}
         */
        virtual void setEnabledCipherSuites( const std::vector<std::string>& suites );

        /**
         * {@inheritDoc}
         */
        virtual std::vector<std::string> getEnabledProtocols() const;

        /**
         * {@inheritDoc}
         */
        virtual void setEnabledProtocols( const std::vector<std::string>& protocols );

    public:

        /**
         * Reads the requested data from the Socket and write it into the passed in buffer.
         *
         * @param buffer
         *      The buffer to read into
         * @param size
         *      The size of the specified buffer
         * @param offset
         *      The offset into the buffer where reading should start filling.
         * @param length
         *      The number of bytes past offset to fill with data.
         *
         * @return the actual number of bytes read or -1 if at EOF.
         *
         * @throw IOException if an I/O error occurs during the read.
         * @throw NullPointerException if buffer is Null.
         * @throw IndexOutOfBoundsException if offset + length is greater than buffer size.
         */
        int read( unsigned char* buffer, int size, int offset, int length );

        /**
         * Writes the specified data in the passed in buffer to the Socket.
         *
         * @param buffer
         *      The buffer to write to the socket.
         * @param size
         *      The size of the specified buffer.
         * @param offset
         *      The offset into the buffer where the data to write starts at.
         * @param length
         *      The number of bytes past offset to write.
         *
         * @throw IOException if an I/O error occurs during the write.
         * @throw NullPointerException if buffer is Null.
         * @throw IndexOutOfBoundsException if offset + length is greater than buffer size.
         */
        void write( const unsigned char* buffer, int size, int offset, int length );

        /**
         * Gets the number of bytes in the Socket buffer that can be read without blocking.
         *
         * @returns the number of bytes that can be read from the Socket without blocking.
         *
         * @throws IOException if an I/O error occurs while performing this operation.
         */
        int available();

    private:

        // Perform some additional checks on the Server's Certificate to ensure that
        // its really valid.
        void verifyServerCert( const std::string& serverName );

    };

}}}}}

#endif /* _DECAF_INTERNAL_NET_SSL_OPENSSL_OPENSSLSOCKET_H_ */
