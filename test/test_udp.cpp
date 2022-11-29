#include <iostream>
#include <asio.hpp>

// Just a little test. Listen with:
// nc -kul 16661

using asio::ip::udp;

int main() {
    std::cout << "hello world" << std::endl;
    asio::io_context io_context;
    udp::resolver resolver(io_context);
    udp::endpoint endpoint = *resolver.resolve(udp::v4(), "localhost", "16661").begin();
    udp::socket socket(io_context);
    socket.open(udp::v4());
    socket.send_to(asio::buffer("hello world\n"), endpoint);
    std::cout << "sent stuff" << std::endl;
    return 0;
}
