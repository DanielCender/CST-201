/**
 *  Maze3/ main.cpp
 *  Author: Daniel Cender
 *  Date: 05/12/2019
 *  Description: This program reads from a file and creates a maze represented as a linked list.
 */
#include <iostream>
#include <fstream>
#include <stack>
#include "src/Maze.h"
#include "src/Cell.h"
using namespace std;


// Read from file into array
void readFile(ifstream& f) {
  f.open("sample.txt");
  string line;
  if(f) {
    while (getline(f, line)) {
      cout << line << endl;
    }
  }
  cout << endl;
  f.close();
}


// Display Maze
void displayMaze(const Maze* maze) {
  int begin = 0;
  int end = maze->rows_array.size();
  Cell *current_row_node;
  for (; begin < end; begin++) {
    // iterating through rows currently
    if (begin == 0) { // Print top line of col numbers
      cout << " " << " " << " " << 0 << " ";
      for (int x = 1; x < maze->cols_array.size(); x++) {
        cout << " " << x << " ";
      }
      cout << endl; // end top row
    }
    // iterate over each row 3 times
    for (int i = 0; i < 3; i++) {
      current_row_node = maze->rows_array[begin]; // reset
      if (i == 1) {
        cout << begin << " ";
      } else {
        cout << " " << " ";
      }
      for (int allCols = 0; allCols < maze->cols_array.size(); allCols++) {

        switch (current_row_node->type) {
          case Und:
            cout << "UUU";
            break;
          case Wall:cout << "XXX";
            break;
          case Open:cout << "...";
            break;
          case Begin:
            if (i == 1) {
              cout << ".S.";
            } else {
              cout << "...";
            }
            break;
          case End:
            if (i == 1) {
              cout << ".F.";
            } else {
              cout << "...";
            }
            break;
          default:cout << "UUU";
        }
        // increment to next column
        current_row_node = current_row_node->right;
      }
      cout << endl;
    }
  }
}

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

int main() {
//  ifstream f;  // FOR DEBUGGING - Just displays file contents line per line
//    readFile(f);

  Maze *new_maze = new Maze();
  new_maze->readFile("sample.txt");

  displayMaze(new_maze);

  bool result = solveMaze(new_maze); // TODO

  return 0;
}