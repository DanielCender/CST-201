/**
 *  Maze7/src GNode.h
 *  Author: Daniel Cender
 *  Date: 06/9/2019
 *  Description: This header file implements a 2-D array of doubly linked list to store the maze tiles.
 */

#include <iostream>
using namespace std;

#ifndef MAZE7_SRC_GNODE_H_
#define MAZE7_SRC_GNODE_H_

// Needs no concept of "neighbors" besides next, that'll be left to the Graph list
class GNode {
 public:
  int x, y;
  GNode *next;
  GNode(int x = NULL, int y = NULL);
  ~GNode();

};

#endif //MAZE7_SRC_GNODE_H_
