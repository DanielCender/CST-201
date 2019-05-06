/**
 *  Maze2/src Point.h
 *  Author: Daniel Cender
 *  Date: 05/05/2019
 *  Description: This header implements a doubly linked node to store a map tile.
 */

#include <iostream>
using namespace std;

#ifndef MAZE2_SRC_POINT_H_
#define MAZE2_SRC_POINT_H_

template <typename T>
class Point {
 public:
  T data;
  Point *next, *prev;
  Point() {
    next = 0;
    prev = 0;
  }
  Point(T d, Point<T> *n = 0, Point<T> *p = 0) {
    this->data = d;
    this->next = n;
    this->prev = p;
  }
  int length()  {
    Point* n = this;
    int size;
    size = 0;
    while(n != NULL) {
      size++;
      n = n->next;
    }
    return (size);
  };
  static void print(Point* n) {
    while(n != NULL) { // While node isn't a null pointer
      cout << n->data << " ";
      n = n->next; // Iterate to next link
    }
    cout << endl;
  };
};

#endif //MAZE2_SRC_POINT_H_
