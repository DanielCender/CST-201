cmake_minimum_required(VERSION 3.14)
project(Maze7)

set(CMAKE_CXX_STANDARD 14)

add_executable(Maze7 main.cpp src/Graph.cpp src/Graph.h src/GNode.cpp src/GNode.h)