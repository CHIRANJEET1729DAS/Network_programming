#ifndef TEST_SERVER_HPP
#define TEST_SERVER_HPP

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include "/home/chiranjeet/c++_server/header_files/server_network/simple_server.hpp"
#include <unistd.h>
#include <cerrno>

using namespace std;

class test_Server : public simple_server {
private:
    char buffer[30000] = {0};
    int new_socket; // Declare new_socket
    struct sockaddr_in address; // Declare address

    void accepter() {
        socklen_t address_len = sizeof(address);
        cout << "[DEBUG] Waiting to accept connection..." << endl;
        new_socket = accept(get_socket()->get_sock_connection(), (struct sockaddr*)&address, &address_len);

        if (new_socket < 0) {
            cerr << "[ERROR] Accept failed: " << strerror(errno) << " (errno: " << errno << ")" << endl;
            return;
        } else {
            cout << "[DEBUG] Accepted connection on socket: " << new_socket << endl;
        }

        ssize_t bytes_read = read(new_socket, buffer, sizeof(buffer));
        if (bytes_read < 0) {
            cerr << "[ERROR] Read failed: " << strerror(errno) << " (errno: " << errno << ")" << endl;
        } else {
            cout << "[DEBUG] Read " << bytes_read << " bytes from socket." << endl;
        }
    }

    void handler() {
        cout << "[DEBUG] Handling request..." << endl;
        cout << "[REQUEST] " << buffer << endl;
    }

    void responder() {
        const char* hello = "Hello from server";
        ssize_t bytes_written = write(new_socket, hello, strlen(hello));

        if (bytes_written < 0) {
            cerr << "[ERROR] Write failed: " << strerror(errno) << " (errno: " << errno << ")" << endl;
        } else {
            cout << "[DEBUG] Sent response: " << hello << " (" << bytes_written << " bytes written)" << endl;
        }

        close(new_socket);
        cout << "[DEBUG] Connection closed." << endl;
    }

public:
    test_Server(int domain, int service, int protocol, int port, u_long interface, int backlog) 
        : simple_server(domain, service, protocol, port, interface, backlog) {
        cout << "[DEBUG] Server initialized on port " << port << endl;
        launch();
    }

    void launch() {
        while (true) {
            cout << "++++++++Waiting for a new connection++++++++" << endl;
            accepter();
            if (new_socket >= 0) { // Only handle if a connection was successfully accepted
                handler();
                responder();
            }
            cout << "++++++++Done processing the request++++++++" << endl;
        }
    }
};

#endif