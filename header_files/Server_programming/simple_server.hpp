#ifndef SIMPLE_SERVER_HPP
#define SIMPLE_SERVER_HPP

#include <iostream>
#include <stdio.h>
#include "/home/chiranjeet/c++_server/header_files/networking/listening_socket.hpp"

using namespace std;

class simple_server {
private:
    ListeningSocket* socket;
    virtual void accepter() = 0;
    virtual void handler() = 0;
    virtual void responder() = 0;
public:
    simple_server(int domain, int service, int protocol, int port, u_long interface, int backlog) {
        socket = new ListeningSocket(domain, service, protocol, port, interface, backlog);
    }
    virtual void launch() = 0;
    ListeningSocket* get_socket() {
        return socket;
    }
};

#endif
