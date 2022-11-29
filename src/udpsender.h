#ifndef __UDPSENDER_H__
#define __UDPSENDER_H__

// #include <asio.hpp>
// using asio::ip::udp;

#include "PracticalSocket.h"

class UDPSender
{
    public:
    UDPSender();

    void send();

    private:
    //     asio::io_context io_context;
    //     udp::resolver resolver;
    //     udp::endpoint endpoint;
    //     udp::socket socket;
    UDPSocket sock;
};

#endif