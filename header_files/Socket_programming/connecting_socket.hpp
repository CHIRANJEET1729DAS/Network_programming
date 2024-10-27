#ifndef CONNECTING_SOCKET_HPP
#define CONNECTING_SOCKET_HPP

#include <iostream>
#include "/home/chiranjeet/c++_server/header_files/networking/simple_socket.hpp"
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

class ConnectingSocket : public Socket {
public:
    ConnectingSocket(int domain, int service, int protocol, int port, u_long interface)
        : Socket(domain, service, protocol, port, interface) {}

    int connect_to_network() {
        struct sockaddr_in address = get_address();
        return connect(get_sock_connection(), (struct sockaddr*)&address, sizeof(address));
    }
};

#endif
