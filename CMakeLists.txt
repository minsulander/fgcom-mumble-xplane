project(fgcom-mumble-xplane CXX)
cmake_minimum_required(VERSION 3.1)

set(SOURCES
    src/fgcom-mumble-plugin.cpp
)

add_subdirectory(xplane_sdk/)
add_xplane_plugin(fgcom-mumble 301 ${SOURCES})
