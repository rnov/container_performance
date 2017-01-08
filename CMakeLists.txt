cmake_minimum_required(VERSION 3.3)
project(container_performance)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -stdlib=libc++ -lc++abi")

set(SOURCE_FILES cont_test.cpp container_test.h test.cpp)
add_executable(container_performance ${SOURCE_FILES})