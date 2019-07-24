cmake_minimum_required (VERSION 2.6)
project (cpp_designpatterns)

set(DP_BUILDER builder)
set(DP_FACTORY factory)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
add_subdirectory(${DP_BUILDER})
add_subdirectory(${DP_FACTORY})
