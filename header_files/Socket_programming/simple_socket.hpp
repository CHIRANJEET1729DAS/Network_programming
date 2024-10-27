#ifndef SIMPLE_SOCKET_HPP
#define SIMPLE_SOCKET_HPP

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <cstring>
#include <cerrno> // For errno

using namespace std;

class Socket {
private:
    struct sockaddr_in address;
    int sock_connection;

public:
    Socket(int domain, int service, int protocol, int port, u_long interface) {
        sock_connection = socket(domain, service, protocol);
        if (sock_connection < 0) {
            cerr << "Socket creation failed: " << strerror(errno) << " (errno: " << errno << ")" << endl;
            exit(EXIT_FAILURE);
        }

        address.sin_family = domain;
        address.sin_port = htons(port);
        address.sin_addr.s_addr = htonl(interface);
    }

    void test_connection() {
        if (sock_connection < 0) {
            exit(EXIT_FAILURE);
        }
    }

    int get_sock_connection() {
        return sock_connection;
    }

    struct sockaddr_in get_address() {
        return address;
    }
};

#endif
