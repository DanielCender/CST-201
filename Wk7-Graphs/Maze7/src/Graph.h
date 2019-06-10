/**
 *  Maze7/src Graph.h
 *  Author: Daniel Cender
 *  Date: 06/9/2019
 *  Description: This header file implements graph representation of a maze.
 */


#include "GNode.h"
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
using namespace std;

#ifndef MAZE7_SRC_GRAPH_H_
#define MAZE7_SRC_GRAPH_H_

class Graph {
 public:
  // Choosing to represent the list as a vector of nodes
  ~Graph();
  void readFile(char *path);
  void display();
  bool solveMazeWithDFS();
  bool solveMazeWithBFS(); // TODO
  void DFS(GNode *n);
 private:
  GNode *start, *finish;
  int col_size, row_size;
  vector<GNode*> maze;
  vector<vector<int>> mazeArr;
};

#endif //MAZE7_SRC_GRAPH_H_
