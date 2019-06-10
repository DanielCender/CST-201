cmake_minimum_required(VERSION 3.14)
project(Maze6)

set(CMAKE_CXX_STANDARD 14)

add_executable(Maze6 main.cpp src/Cell.cpp src/Cell.h src/Maze.cpp src/Maze.h src/Graph.cpp src/Graph.h src/GNode.cpp src/GNode.h)