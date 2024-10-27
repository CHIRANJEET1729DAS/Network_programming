#ifndef LISTENING_SOCKET_HPP
#define LISTENING_SOCKET_HPP

#include <iostream>
#include "/home/chiranjeet/c++_server/header_files/networking/binding_socket.hpp"
#include <stdio.h>

using namespace std;

class ListeningSocket : public BindingSocket {
public:
    ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int backlog)
        : BindingSocket(domain, service, protocol, port, interface, backlog) {}
};

#endif
