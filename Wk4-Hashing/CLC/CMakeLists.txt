cmake_minimum_required(VERSION 3.14)
project(CLC)

set(CMAKE_CXX_STANDARD 14)

add_executable(CLC main.cpp src/HashMap.cpp src/HashMap.h)