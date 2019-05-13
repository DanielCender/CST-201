/**
 *  Maze3/src Cell.h
 *  Author: Daniel Cender
 *  Date: 05/12/2019
 *  Description: This header implements a doubly linked node to store a map tile.
 */

#include <iostream>
using namespace std;


#ifndef MAZE3_SRC_CELL_H_
#define MAZE3_SRC_CELL_H_

enum Cell_Type { Wall, Open, Begin, End, Und, Traversed };


class Cell {
 public:
  Cell_Type type;
  Cell *top, *right, *bottom, *left;
  Cell *prev, *next; // For storing in linked lists
  int x, y;
  // No empty param constructor, since this one handles all cases
  // Receives type, position, and any side nodes, in CSS-style ordering (top, right, bottom, left)
  Cell(Cell_Type c_t = Und, int col_pos = NULL, int row_pos = NULL, Cell *t = 0, Cell *r = 0, Cell *b = 0, Cell *l = 0) {
    type = c_t;
    top = t;
    right = r;
    bottom = b;
    left = l;
    prev = next = 0;
    x = col_pos;
    y = row_pos;
  }
  // Prints node connections from calling object
  void print() {
    // Top node
    cout << "Top: " << (typeid(this->top) == typeid(Cell) ? this->top->type : Cell_Type(Und)) << endl;
    cout << "Right: " << (typeid(this->right) == typeid(Cell) ? this->right->type : Cell_Type(Und)) << endl;
    cout << "Bottom: " << (typeid(this->bottom) == typeid(Cell) ? this->bottom->type : Cell_Type(Und)) << endl;
    cout << "Left: " << (typeid(this->left) == typeid(Cell) ? this->left->type : Cell_Type(Und)) << endl;
    cout << endl;
  };
};

#endif //MAZE3_SRC_CELL_H_
