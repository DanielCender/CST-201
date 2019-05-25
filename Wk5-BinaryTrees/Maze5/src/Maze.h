/**
 *  Maze5/src Maze.h
 *  Author: Daniel Cender
 *  Date: 05/25/2019
 *  Description: This header file implements a 2-D array of doubly linked list to store the maze tiles.
 */

#include "Cell.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#ifndef MAZE5_SRC_MAZE_H_
#define MAZE5_SRC_MAZE_H_

class Maze {
 public:
  vector<Cell*> rows_array; // basic array is just too frustrating for this usage
  vector<Cell*> cols_array;
  Cell *start, *finish;
  // Pass in rows, cols, starting cell, ending, and maze array
  Maze(int r = 0, int c = 0, Cell *s = 0, Cell *f = 0, Cell (*maze_array) [] = 0);
  ~Maze();
  void readFile(char* path);
 private:
  int rows, cols; // cols is x, rows is y
};

#endif //MAZE5_SRC_MAZE_H_
