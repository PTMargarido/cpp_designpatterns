cmake_minimum_required (VERSION 2.6)
project (cpp_designpatterns)

set(DP_BUILDER builder)
set(DP_FACTORY factory)
set(DP_PROTOTYPE prototype)
set(DP_SINGLETON singleton)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
add_subdirectory(${DP_BUILDER})
add_subdirectory(${DP_FACTORY})
add_subdirectory(${DP_PROTOTYPE})
add_subdirectory(${DP_SINGLETON})
