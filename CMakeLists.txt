project(fgcom-mumble-xplane CXX)
cmake_minimum_required(VERSION 3.1)

include_directories(asio/include)

set(SOURCES
    src/PracticalSocket.cpp
    src/udpsender.cpp
    src/datarefs.cpp
    src/fgcom-mumble-plugin.cpp
)

add_subdirectory(xplane_sdk/)
add_xplane_plugin(fgcom-mumble 301 ${SOURCES})

add_executable(test_udp test/test_udp.cpp)
