project(fgcom-mumble-xplane CXX)
cmake_minimum_required(VERSION 3.1)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-fPIC -std=gnu++0x)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_definitions(-fPIC -stdlib=libc++ -std=c++11)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT /std:c++17 /wd4267")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /std:c++17 /wd4267")
    add_definitions(-D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_WINSOCK_DEPRECATED_NO_WARNINGS)
endif()

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
add_dependencies(fgcom-mumble sockpp-static)
if(WIN32)
  target_link_libraries(fgcom-mumble PRIVATE sockpp-static)
else()
  target_link_libraries(fgcom-mumble PRIVATE sockpp)
endif()

# add_executable(test_sockpp_udp test/test_sockpp_udp.cpp)
# target_link_libraries(test_sockpp_udp sockpp)

# TODO place fgcom-mumble.xpl in lin_x64 mac_x64 win_x64 folders
