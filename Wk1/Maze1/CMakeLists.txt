cmake_minimum_required(VERSION 3.14)
project(Maze1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Maze1 main.cpp src/Point.cpp src/Point.h src/Maze.cpp src/Maze.h)