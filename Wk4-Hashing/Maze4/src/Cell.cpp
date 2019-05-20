//
// Created by Daniel Cender on 2019-05-20.
//

#include "Cell.h"
#include <iostream>
using namespace std;

Cell::Cell(Cell_Type c_t, int col_pos, int row_pos, Cell *t, Cell *r, Cell *b, Cell *l) {
  type = c_t;
  top = t;
  right = r;
  bottom = b;
  left = l;
  prev = next = 0;
  x = col_pos;
  y = row_pos;
};


void Cell::print() {
    // Top node
    cout << "Top: " << (typeid(this->top) == typeid(Cell) ? this->top->type : Cell_Type(Und)) << endl;
    cout << "Right: " << (typeid(this->right) == typeid(Cell) ? this->right->type : Cell_Type(Und)) << endl;
    cout << "Bottom: " << (typeid(this->bottom) == typeid(Cell) ? this->bottom->type : Cell_Type(Und)) << endl;
    cout << "Left: " << (typeid(this->left) == typeid(Cell) ? this->left->type : Cell_Type(Und)) << endl;
    cout << endl;
  };