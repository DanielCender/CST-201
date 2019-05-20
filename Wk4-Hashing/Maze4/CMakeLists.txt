cmake_minimum_required(VERSION 3.14)
project(Maze4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Maze4 main.cpp src/Cell.cpp src/Cell.h src/Maze.cpp src/Maze.h)