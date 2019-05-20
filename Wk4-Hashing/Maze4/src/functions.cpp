/**
 *  Maze4/src functions.cpp
 *  Author: Daniel Cender
 *  Date: 05/19/2019
 *  Description: This cpp file includes functions to solve the maze puzzle with a stack and queue.
 */
#include "Cell.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "Maze.h"
using namespace std;

enum Direction { Top = 0, Right = 1, Bottom = 2, Left = 3 };


bool solveMaze(const Maze *maze) {
  // Heavily drawing from this example here:
  // https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-using-stack/
  stack<Cell*> s;
  Direction direction = Top; // top, 1 is right, 2: bottom, 3: left
  int dir = 0;
  int x, y;
  Cell *temp;

  s.push(maze->start);

  while(!s.empty()) {
    // pop node off stack and try all directions
    temp = s.top(); // look at top, don't pop yet
    direction = (Direction) ++dir; // increment direction enum
    x = temp->x;
    y = temp->y;

    switch(direction) {
      case Top:
        temp = temp->top;
        break;
      case Right:
        temp = temp->right;
        break;
      case Bottom:
        temp = temp->bottom;
        break;
      case Left:
        temp = temp->left;
        break;
      default:
        cout << "Something wrong" << endl;
        break;
    }

    s.pop();
    s.push(temp);

    if(x == maze->finish->x and y == maze->finish->y) {
      cout << "Result Found" << endl;
      return true;
    }

    // Check up direction
    if(direction == Top) {
      // If not to go off map, and that node hasn't already been traversed
      if(y - 1 >= 0 and temp->top != NULL and temp->top->type != Traversed) {
        Cell *temp1 = temp->top;
        temp->type = Traversed;
        s.push(temp1);
      }
    } else if (direction == Right) { // Check right direction
      if(x + 1 < maze->cols_array.size() and temp->right != NULL and temp->right->type != Traversed) {
        Cell *temp2 = temp->right;
        temp->type = Traversed;
        s.push(temp2);
      }
    } else if (direction == Bottom) { // Check bottom direction
      if(y + 1 < maze->rows_array.size() and temp->bottom and temp->bottom->type != Traversed) {
        Cell *temp3 = temp->bottom;
        temp->bottom->type = Traversed;
        s.push(temp3);
      }
    } else if(direction == Left) {
      if(x - 1 >= 0 and temp->left and temp->left->type != Traversed) {
        Cell *temp4 = temp->left;
        temp->left->type = Traversed;
        s.push(temp4);
      }
    } else { // Retrace path
      temp->type = Traversed;
      s.pop();
    }

  }
  return false;
}