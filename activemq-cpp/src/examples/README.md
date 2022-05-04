# CPP Message Client

## Thing that could be passed in on the command line
1. Number of messages to generate
2. Instead of number of messages, how long to run
3. Broker URL (https://activemq.apache.org/components/cms/configuring)
4. Message size
5. Message Headers
6. Shared connections
7. Topics/queues (One? Multiple?)
8. Number of producers. Number of consumers.
(FYI: might make more sense to have ad meta program start up each one because they might need to each have a different configuration)
9. Transactions yes/not

    // SSL:
    // =========================
    // To use SSL you need to specify the location of the trusted Root CA or the
    // certificate for the broker you want to connect to.  Using the Root CA allows
    // you to use failover with multiple servers all using certificates signed by
    // the trusted root.  If using client authentication you also need to specify
    // the location of the client Certificate.
    //
    //     System::setProperty( "decaf.net.ssl.keyStore", "<path>/client.pem" );
    //     System::setProperty( "decaf.net.ssl.keyStorePassword", "password" );
    //     System::setProperty( "decaf.net.ssl.trustStore", "<path>/rootCA.pem" );
    //
    // The you just specify the ssl transport in the URI, for example:
    //
    //     ssl://localhost:61617