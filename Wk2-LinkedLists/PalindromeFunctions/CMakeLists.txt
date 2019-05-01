cmake_minimum_required(VERSION 3.14)
project(PalindromeFunctions)

set(CMAKE_CXX_STANDARD 14)

add_executable(PalindromeFunctions main.cpp src/Node.h src/Node.cpp src/SLList.cpp src/SLList.h)