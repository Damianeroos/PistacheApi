cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project("PistacheApi")

# Tell CMake to add support for pkg-config, then use it to find the library...
include(FindPkgConfig)
pkg_search_module(PISTACHE REQUIRED libpistache>=0.0.2)

add_library(hhandler HelloHandler.cpp)


include_directories(${PISTACHE_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PISTACHE_LIBRARIES})

