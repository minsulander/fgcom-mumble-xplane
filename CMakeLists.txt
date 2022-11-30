project(fgcom-mumble-xplane CXX)
cmake_minimum_required(VERSION 3.1)

cmake_policy(SET CMP0048 NEW)
set(SOCKPP_BUILD_SHARED OFF CACHE INTERNAL "" FORCE)
set(SOCKPP_BUILD_STATIC ON CACHE INTERNAL "" FORCE)
add_subdirectory(sockpp/)
include_directories(sockpp/include)
link_directories("${CMAKE_CURRENT_BINARY_DIR}/sockpp")

set(SOURCES
    src/udpsender.cpp
    src/datarefs.cpp
    src/fgcom-mumble-plugin.cpp
)

add_subdirectory(xplane_sdk/)
add_xplane_plugin(fgcom-mumble 301 ${SOURCES})
target_link_libraries(fgcom-mumble sockpp)

# add_executable(test_sockpp_udp test/test_sockpp_udp.cpp)
# target_link_libraries(test_sockpp_udp sockpp)
