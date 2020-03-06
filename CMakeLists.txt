cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project("MyPistacheProject")

add_library(hellohandler HelloHandler.cpp)
set_target_properties(hellohandler
                      PROPERTIES LINKER_LANGUAGE CXX)
# Tell CMake to add support for pkg-config, then use it to find the library...
include(FindPkgConfig)
pkg_search_module(PISTACHE REQUIRED libpistache>=0.0.2)

include_directories(${PISTACHE_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME}  PUBLIC hellohandler pistache pthread)
