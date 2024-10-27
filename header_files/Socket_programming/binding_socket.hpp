#ifndef BINDING_SOCKET_HPP
#define BINDING_SOCKET_HPP

#include <iostream>
#include "/home/chiranjeet/c++_server/header_files/networking/simple_socket.hpp"
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

class BindingSocket : public Socket {
private:
    int listening;
    int backlog;

public:
    BindingSocket(int domain, int service, int protocol, int port, u_long interface, int backlog)
        : Socket(domain, service, protocol, port, interface), backlog(backlog) {
        listening = listen(get_sock_connection(), backlog);
        if (listening < 0) {
            cerr << "Listen failed: " << strerror(errno) << endl;
            exit(EXIT_FAILURE);
        }
    }

    int bind_to_network() {
        struct sockaddr_in address = get_address();
        int result = bind(get_sock_connection(), (struct sockaddr*)&address, sizeof(address));
        return result;
    }
};

#endif
