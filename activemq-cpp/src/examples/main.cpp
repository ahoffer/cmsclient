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

// START SNIPPET: demo

#include <activemq/library/ActiveMQCPP.h>
#include <decaf/lang/Thread.h>
#include <decaf/lang/Runnable.h>
#include <decaf/util/concurrent/CountDownLatch.h>
#include <decaf/lang/Integer.h>
#include <decaf/lang/Long.h>
#include <decaf/lang/System.h>
#include <activemq/core/ActiveMQConnectionFactory.h>
#include <activemq/util/Config.h>
#include <cms/Connection.h>
#include <cms/Session.h>
#include <cms/TextMessage.h>
#include <cms/BytesMessage.h>
#include <cms/MapMessage.h>
#include <cms/ExceptionListener.h>
#include <cms/MessageListener.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <memory>
#include "getopt.h"

using namespace activemq::core;
using namespace decaf::util::concurrent;
using namespace decaf::util;
using namespace decaf::lang;
using namespace cms;
using namespace std;

class HelloWorldProducer : public Runnable {
private:

    Connection *connection;
    Session *session;
    Destination *destination;
    MessageProducer *producer;
    int numMessages;
    bool useTopic;
    bool sessionTransacted;
    std::string brokerURI;

private:

    HelloWorldProducer(const HelloWorldProducer &);

    HelloWorldProducer &operator=(const HelloWorldProducer &);

public:

    HelloWorldProducer(const std::string &brokerURI, int numMessages, bool useTopic = false,
                       bool sessionTransacted = false) : connection(NULL), session(NULL), destination(NULL),
                                                         producer(NULL), numMessages(numMessages), useTopic(useTopic),
                                                         sessionTransacted(sessionTransacted), brokerURI(brokerURI) {
    }

    virtual ~HelloWorldProducer() {
        cleanup();
    }

    void close() {
        this->cleanup();
    }

    virtual void run() {

        try {

            // Create a ConnectionFactory
            auto_ptr<ConnectionFactory> connectionFactory(ConnectionFactory::createCMSConnectionFactory(brokerURI));

            // Create a Connection
            connection = connectionFactory->createConnection();

            // Start the connection
            connection->start();

            // Create a Session
            if (this->sessionTransacted) {
                session = connection->createSession(Session::SESSION_TRANSACTED);
            } else {
                session = connection->createSession(Session::AUTO_ACKNOWLEDGE);
            }

            // Create the destination (Topic or Queue)
            if (useTopic) {
                destination = session->createTopic("TEST.FOO");
            } else {
                destination = session->createQueue("TEST.FOO");
            }

            // Create a MessageProducer from the Session to the Topic or Queue
            producer = session->createProducer(destination);
            producer->setDeliveryMode(DeliveryMode::NON_PERSISTENT);

            // Create the Thread Id String
            string threadIdStr = Long::toString(Thread::currentThread()->getId());

            // Create a messages
            string text = (string) "Hello world! from thread " + threadIdStr;

            for (int ix = 0; ix < numMessages; ++ix) {
                std::auto_ptr<TextMessage> message(session->createTextMessage(text));
                message->setIntProperty("Integer", ix);
                printf("Sent message #%d from thread %s\n", ix + 1, threadIdStr.c_str());
                producer->send(message.get());
            }

        } catch (CMSException &e) {
            e.printStackTrace();
        }
    }

private:

    void cleanup() {

        if (connection != NULL) {
            try {
                connection->close();
            } catch (cms::CMSException &ex) {
                ex.printStackTrace();
            }
        }

        // Destroy resources.
        try {
            delete destination;
            destination = NULL;
            delete producer;
            producer = NULL;
            delete session;
            session = NULL;
            delete connection;
            connection = NULL;
        } catch (CMSException &e) {
            e.printStackTrace();
        }
    }
};

class HelloWorldConsumer : public ExceptionListener, public MessageListener, public Runnable {

private:
    CountDownLatch latch;
    CountDownLatch doneLatch;
    Connection *connection;
    Session *session;
    Destination *destination;
    MessageConsumer *consumer;
    long waitMillis;
    bool useTopic;
    bool sessionTransacted;
    std::string brokerURI;

private:

    HelloWorldConsumer(const HelloWorldConsumer &);

    HelloWorldConsumer &operator=(const HelloWorldConsumer &);

public:

    HelloWorldConsumer(const std::string &brokerURI, int numMessages, bool useTopic = false,
                       bool sessionTransacted = false, int waitMillis = 30000) : latch(1), doneLatch(numMessages),
                                                                                 connection(NULL), session(NULL),
                                                                                 destination(NULL), consumer(NULL),
                                                                                 waitMillis(waitMillis),
                                                                                 useTopic(useTopic),
                                                                                 sessionTransacted(sessionTransacted),
                                                                                 brokerURI(brokerURI) {
    }

    virtual ~HelloWorldConsumer() {
        cleanup();
    }

    void close() {
        this->cleanup();
    }

    void waitUntilReady() {
        latch.await();
    }

    virtual void run() {

        try {

            // Create a ConnectionFactory
            auto_ptr<ConnectionFactory> connectionFactory(ConnectionFactory::createCMSConnectionFactory(brokerURI));

            // Create a Connection
            connection = connectionFactory->createConnection();
            connection->start();
            connection->setExceptionListener(this);

            // Create a Session
            if (this->sessionTransacted == true) {
                session = connection->createSession(Session::SESSION_TRANSACTED);
            } else {
                session = connection->createSession(Session::AUTO_ACKNOWLEDGE);
            }

            // Create the destination (Topic or Queue)
            if (useTopic) {
                destination = session->createTopic("TEST.FOO");
            } else {
                destination = session->createQueue("TEST.FOO");
            }

            // Create a MessageConsumer from the Session to the Topic or Queue
            consumer = session->createConsumer(destination);

            consumer->setMessageListener(this);

            std::cout.flush();
            std::cerr.flush();

            // Indicate we are ready for messages.
            latch.countDown();

            // Wait while asynchronous messages come in.
            doneLatch.await(waitMillis);

        } catch (CMSException &e) {
            // Indicate we are ready for messages.
            latch.countDown();
            e.printStackTrace();
        }
    }

    // Called from the consumer since this class is a registered MessageListener.
    virtual void onMessage(const Message *message) {

        static int count = 0;

        try {
            count++;
            const TextMessage *textMessage = dynamic_cast<const TextMessage *> (message);
            string text = "";

            if (textMessage != NULL) {
                text = textMessage->getText();
            } else {
                text = "NOT A TEXTMESSAGE!";
            }

            printf("Message #%d Received: %s\n", count, text.c_str());

        } catch (CMSException &e) {
            e.printStackTrace();
        }

        // Commit all messages.
        if (this->sessionTransacted) {
            session->commit();
        }

        // No matter what, tag the count down latch until done.
        doneLatch.countDown();
    }

    // If something bad happens you see it here as this class is also been
    // registered as an ExceptionListener with the connection.
    virtual void onException(const CMSException &ex AMQCPP_UNUSED) {
        printf("CMS Exception occurred.  Shutting down client.\n");
        ex.printStackTrace();
        exit(1);
    }

private:

    void cleanup() {
        if (connection != NULL) {
            try {
                connection->close();
            } catch (cms::CMSException &ex) {
                ex.printStackTrace();
            }
        }

        // Destroy resources.
        try {
            delete destination;
            destination = NULL;
            delete consumer;
            consumer = NULL;
            delete session;
            session = NULL;
            delete connection;
            connection = NULL;
        } catch (CMSException &e) {
            e.printStackTrace();
        }
    }
};

int main(int argc, char *argv[] AMQCPP_UNUSED) {

    // Register all the things
    activemq::library::ActiveMQCPP::initializeLibrary();

    // BROKER URL
    // For a description of options, see https://activemq.apache.org/components/cms/configuring
    std::string brokerURI = "tcp://127.0.0.1:5672?username=admin&password=admin";


    // Create connection factory
    std::auto_ptr<cms::ConnectionFactory> connectionFactory(
            cms::ConnectionFactory::createCMSConnectionFactory(brokerURI));


    // TODO: Print out all arguments
    std::cout << "=====================================================\n";
    std::cout << "Broker URI: " << brokerURI << std::endl;
    std::cout << "-----------------------------------------------------\n";

    //============================================================
    // set to true to use topics instead of queues
    // Note in the code above that this causes createTopic or
    // createQueue to be used in both consumer an producer.
    //============================================================
    bool useTopics = true;
    bool sessionTransacted = false;
    int numMessages = 2000;

    long long startTime = System::currentTimeMillis();

    HelloWorldProducer producer(brokerURI, numMessages, useTopics);
    HelloWorldConsumer consumer(brokerURI, numMessages, useTopics, sessionTransacted);

    // Start the consumer thread.
    Thread consumerThread(&consumer);
    consumerThread.start();

    // Wait for the consumer to indicate that its ready to go.
    consumer.waitUntilReady();

    // Start the producer thread.
    Thread producerThread(&producer);
    producerThread.start();

    // Wait for the threads to complete.
    producerThread.join();
    consumerThread.join();

    long long endTime = System::currentTimeMillis();
    double totalTime = (double) (endTime - startTime) / 1000.0;

    consumer.close();
    producer.close();

    std::cout << "Time to completion = " << totalTime << " seconds." << std::endl;
    std::cout << "-----------------------------------------------------\n";

    // TODO The call to shutdownLibrary was causing a seg fault.
    //activemq::library::ActiveMQCPP::shutdownLibrary();
}
