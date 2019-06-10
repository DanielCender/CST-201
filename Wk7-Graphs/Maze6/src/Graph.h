/**
 *  Maze6/src Graph.h
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


#ifndef MAZE6_SRC_GRAPH_H_
#define MAZE6_SRC_GRAPH_H_

class Graph {
 public:
  // Choosing to represent the list as a vector of nodes
  vector<GNode> *adjList;
  ~Graph();
  void readFile(char *path);
  bool solveMazeWithDFS(); // TODO
  bool solveMazeWithBFS(); // TODO
 private:
  GNode *start, *finish;
  vector<GNode*> maze;
};

#endif //MAZE6_SRC_GRAPH_H_
