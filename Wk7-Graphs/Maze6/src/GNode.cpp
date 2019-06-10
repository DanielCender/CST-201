/**
 *  Maze6/src GNode.cpp
 *  Author: Daniel Cender
 *  Date: 06/9/2019
 *  Description: This source file implements the methods on GNode.h
 */

#include "GNode.h"
#include <iostream>
using namespace std;


GNode::GNode(int x, int y) {
  this->x = x;
  this->y = y;
  this->next = NULL;
}