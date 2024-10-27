# Network_programming (C++)

This project is a C++-based server application that operates similarly to a basic HTTP server, handling incoming client connections, processing requests, and sending responses. The project, currently in development, showcases core server functionalities, including socket management, multi-step request handling, and connection handling.

# Project Overview

The server is implemented in C++ and is built using raw socket programming principles, including the following core components:

1) Socket Initialization and Binding: The server initializes a listening socket using user-defined configuration parameters, such as domain, protocol, and port.
2) Connection Management: A customized test_Server class extends a base simple_server class to handle incoming connections. It manages both the accepting of new 
                          connections and the allocation of resources per connection.
3) Request-Response Workflow:
   1) Accepter: Waits for incoming client connections and reads data into a buffer. Detailed error handling ensures that any issues during connection acceptance are 
                captured and logged.
   2) Handler: Processes the incoming request and outputs the data received from the client, simulating request processing.
   3) Responder: Prepares and sends a simple response message back to the client and closes the connection, completing the request-response cycle.

