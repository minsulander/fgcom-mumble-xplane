#ifndef __UDPSENDER_H__
#define __UDPSENDER_H__

#include <sockpp/udp_socket.h>

class UDPSender
{
    public:
    UDPSender();
    void send();

    private:
    sockpp::udp_socket socket;
};

#endif