cmake_minimum_required(VERSION 3.14)
project(DQ2)

set(CMAKE_CXX_STANDARD 14)

add_executable(DQ2 main.cpp src/Node.h src/SLList.h src/DNode.h src/DLList.h)