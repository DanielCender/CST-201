/**
 *  Maze6/src Maze.h
 *  Author: Daniel Cender
 *  Date: 06/9/2019
 *  Description: This cpp file implements a 2-D array of doubly linked list to store the maze tiles.
 */


#include "Cell.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include "Maze.h"
using namespace std;

enum Direction { Top = 0, Right = 1, Bottom = 2, Left = 3 };


Maze::Maze(int r, int c, Cell *s, Cell *f, Cell (*maze_array) []) {
  rows = r;
  cols = c;
}

Maze::~Maze()  {
  rows_array.empty(); // Remove all maze elements
  cols_array.empty(); // Almost unnecessary
};


void Maze::readFile(char *path) {
  ifstream f;
  f.open(path);
  string line;
  int col_pos, row_pos;

  char eatChar;
  f >> cols >> eatChar >> rows >> eatChar; // Read first values
//  f >> rows >> eatChar >> cols >> eatChar;
  cout << "x size: " << cols << endl;
  cout << "y size: " << rows << endl;

  // Start and end tiles of maze
  int startX, startY, endX, endY;
  f >> eatChar >> startX >> eatChar >> startY >> eatChar >> eatChar;
  cout << "Begin: " << startX << " " << startY << " " << eatChar << endl;

  f >> eatChar >> endX >> eatChar >> endY >> eatChar >> eatChar;
  cout << "End: " << endX << " " << endY << " " << eatChar << endl;

  // Reserve max space needed for maze
  rows_array.reserve(rows);
  cols_array.reserve(cols);

  // START ADDING ROWS
  for(int i = 0; i < rows; i++) {
    rows_array.push_back(new Cell(Open));
    // craft linked list off row
    Cell *instantiater = rows_array[i];

    // Build lists for columns
    for(int atCol = 0; atCol < cols; atCol++) {
      Cell *topNode;
      // START COLUMNS VECTOR

      // Set top node above root
      if(rows_array.size() > 1) { // has O(n), I know, I'll have to revisit this piece
        topNode = rows_array[i - 1];
        for(int gettingNode = 0; gettingNode < atCol; gettingNode++) {
          topNode = topNode->right;
        }
      } else {
        topNode = NULL;
      }

      if(i != 0) { // isn't top row
        instantiater->top = topNode;
        topNode->bottom = instantiater;
      }
//        if(rows_array[i - 1] and i != rows - 1) { // isn't last row
//          rows_array[i - 1]->bottom = instantiater;
//          instantiater->top = rows_array[i - 1];
//        }

      if(cols_array.size() != cols) {
        cols_array.push_back(instantiater);
      }

      if(atCol != 0) { // isn't leftmost node
        cols_array[atCol]->left = cols_array[atCol - 1];
        cols_array[atCol - 1]->right = cols_array[atCol];
      }

      Cell *nextNode = new Cell(Open);
      // Next and prev nodes - a left-right movement
      instantiater->next = nextNode;
      nextNode->prev = instantiater;

      // left and right - HANDLE THIS ABOVE
      nextNode->left = instantiater;
      instantiater->right = nextNode;

      // your x's and y's
      instantiater->x = atCol;
      instantiater->y = i;

      instantiater = instantiater->next;
    }

  }

  // Switch all designated blocks to Walls, not Open
  while(f >> eatChar >> col_pos >> eatChar >> row_pos >> eatChar >> eatChar) {
    Cell *curr = cols_array[col_pos];
    for(int i = 0; i < row_pos;i++) {
      curr = curr->bottom;
    }
    curr->type = Wall;
  }

  // Set beginning and end blocks
  Cell *start = cols_array[startX];
  for(int i = 0; i < startY;i++) {
    start = start->bottom;
  }
  start->type = Begin;
  this->start = start;

  Cell *end = cols_array[endX];
  for(int i = 0; i < endY; i++) {
    end = end->bottom;
  }
  end->type = End;
  this->finish = end;

  cout << endl;
  f.close();
}

void Maze::display() {
  Maze *maze = this;
  int begin = 0;
  int end = maze->rows_array.size();
  Cell *current_row_node;
  for (; begin < end; begin++) {
    // iterating through rows currently
    if (begin == 0) { // Print top line of col numbers
      cout << " " << " " << "  " << 0 << " ";
      for (int x = 1; x < maze->cols_array.size(); x++) {
        cout << " " << x << " ";
      }
      cout << endl; // end top row
    }
    // iterate over each row 3 times
    for (int i = 0; i < 3; i++) {
      current_row_node = maze->rows_array[begin]; // reset
      if (i == 1) {
        if(begin == 10) {
          cout << begin << " ";
        } else {
          cout << begin << " " << " ";
        }

      } else {
        cout << " " << " " << " ";
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
          case Traversed:
            if(i == 1) {
              cout << ".o.";
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

bool Maze::solveMazeStack() {
  // Heavily drawing from this example here:
  // https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-using-stack/
  Maze *maze = this;
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

bool Maze::solveMazeQueue() {
  Maze *maze = this;
  std::queue<Cell*> q;

  Direction dir;
  int x, y;
  Cell *temp;
  int col_size = maze->cols_array.size();
  int row_size = maze->rows_array.size();

  int seen[col_size][row_size];

  for(int i = 0; i < maze->rows_array.size(); i++) {
    for(int o = 0; o < maze->cols_array.size(); o++) {
      seen[i][o] = 1; // 1 is NOT SEEN
    }
  }

  q.push(maze->start);

  while(!q.empty()) { // While queue has items
    int qSize = q.size();
    cout << "Queue Size: " << q.size() << endl;
    if(q.size() == 1) {
      cout << "stop here" << endl;
    }
    temp = q.front(); // deque the first item
    q.pop();

    // Check if popped el is finish
    if(maze->finish == temp) {
      cout << "Successfully navigated maze!!!" << endl;
      return true;
    }

    // Enque the directions of the item's neighbors, if not seen yet

    if(temp->top && temp->top->type != Wall  && seen[temp->top->x][temp->top->y]) {
      seen[temp->top->x][temp->top->y] = 0;
      temp->top->type = Traversed;
      q.push(temp->top);
    }
    if(temp->right && temp->right->type != Wall  && seen[temp->right->x][temp->right->y]){
      seen[temp->right->x][temp->right->y] = 0;
      temp->right->type = Traversed;
      q.push(temp->right);
    }
    if (temp->bottom && temp->bottom->type != Wall && seen[temp->bottom->x][temp->bottom->y]) {
      seen[temp->bottom->x][temp->bottom->y] = 0;
      temp->bottom->type = Traversed;
      q.push(temp->bottom);
    }
    if(temp->left && temp->left->type != Wall  && seen[temp->left->x][temp->left->y]) {
      seen[temp->left->x][temp->left->y] = 0;
      temp->left->type = Traversed;
      q.push(temp->left);
    }

    // Set the dequed item's "seen" bit to seen (0)
//    seen[temp->x][temp->y] = 0;
    // Set the node to traversed
//    temp->type = Traversed;

    // I'm sure I'm missing a piece or two here
    this->display(); // show progress
  }
  return false; // If no end is found
}

// For max-heap
struct greaters {
  bool operator()(const Cell* a,const Cell* b) const {
    return a->mhDist < b->mhDist;
  }
};

/**
 * Uses Manhatten distance formula: | cellx - exitx | + | celly - exity |
 * @return bool
 */
bool Maze::solveMazeHeap() {
  Maze *maze = this;

  std::vector<Cell*> vi;



  Direction dir;
  int x, y;
  Cell *temp;
  int col_size = maze->cols_array.size();
  int row_size = maze->rows_array.size();

//  int seen[row_size][col_size]; // Don't do this, this breaks everything!
  int seen[col_size][row_size];
  for(int i = 0; i < row_size; i++) {
    for(int o = 0; o < col_size; o++) {
      seen[i][o] = 1; // 1 is NOT SEEN
      cout << "Seen: [" << i << "][" << o << "]: " << seen[i][o] << endl;
    };
  }

  // Calc mh of
  float xVal = abs(maze->start->x - maze->finish->x);
  float yVal = abs(maze->start->y - maze->finish->y);
  maze->start->mhDist = xVal + yVal;

  vi.push_back(maze->start);
  push_heap(vi.begin(), vi.end()); // Transform vector into heap

  while(!vi.empty()) { // While queue has items
    int viSize = vi.capacity();
    cout << "Queue Size: " << vi.size() << endl;

    temp = vi.back(); // deque the first item
    vi.pop_back();
    // Check if popped el is finish
    if(maze->finish == temp) {
      cout << "Successfully navigated maze!!!" << endl;
      return true;
    }

    // Enque the directions of the item's neighbors, if not seen yet

    if(temp->top && temp->top->type != Wall  && seen[temp->top->x][temp->top->y]) {
      seen[temp->top->x][temp->top->y] = 0;
//      temp->top->type = Traversed;
      // Calc mh between temp and finish
      float xVal = abs(temp->top->x - maze->finish->x);
      float yVal = abs(temp->top->y - maze->finish->y);
      temp->top->mhDist = xVal + yVal;
      vi.push_back(temp->top);
    }
    if(temp->right && temp->right->type != Wall  && seen[temp->right->x][temp->right->y]){
      seen[temp->right->x][temp->right->y] = 0;
//      temp->right->type = Traversed;
      // Calc mh between temp and finish
      float xVal = abs(temp->right->x - maze->finish->x);
      float yVal = abs(temp->right->y - maze->finish->y);
      temp->right->mhDist = xVal + yVal;
      vi.push_back(temp->right);
    }
    if(temp->bottom && temp->bottom->type != Wall && seen[temp->bottom->x][temp->bottom->y]) {
      seen[temp->bottom->x][temp->bottom->y] = 0;
//      temp->bottom->type = Traversed;
      // Calc mh between temp and finish
      float xVal = abs(temp->bottom->x - maze->finish->x);
      float yVal = abs(temp->bottom->y - maze->finish->y);
      temp->bottom->mhDist = xVal + yVal;
      vi.push_back(temp->bottom);
    }
    if(temp->left && temp->left->type != Wall && seen[temp->left->x][temp->left->y]) {
      seen[temp->left->x][temp->left->y] = 0;
//      temp->left->type = Traversed;
      // Calc mh between temp and finish
      float xVal = abs(temp->left->x - maze->finish->x);
      float yVal = abs(temp->left->y - maze->finish->y);
      temp->left->mhDist = xVal + yVal;
      vi.push_back(temp->left);
    }

    push_heap(vi.begin(), vi.end()); // Transform vector into heap....again

    // Set the dequed item's "seen" bit to seen (0)
//    seen[temp->x][temp->y] = 0;
    // Set the node to traversed
    temp->type = Traversed;

    // I'm sure I'm missing a piece or two here
    this->display(); // show progress
    cout << "******************" << endl;
  }
  return false; // If no end is found
}


// Method that converts this object to a graph format - matrix and adjacency list
Graph Maze::convertToGraph() {
  // Create a matrix of nodes
  // For all rows and

}