#include <iostream>
#include <sockpp/udp_socket.h>

// Just a little test. Listen with:
// nc -kul 16661

int main() {
    std::cout << "hello world" << std::endl;
    sockpp::socket_initializer sockinit;
    sockpp::udp_socket socket;
    if (!socket.connect(sockpp::inet_address("localhost", 16661))) {
        std::cerr << "Failed to connect" << std::endl;
        return 1;
    }
    socket.send("hello world\n");
    std::cout << "sent stuff" << std::endl;
    return 0;
}
