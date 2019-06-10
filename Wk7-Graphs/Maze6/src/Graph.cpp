/**
 *  Maze6/src Graph.cpp
 *  Author: Daniel Cender
 *  Date: 06/9/2019
 *  Description: This source file implements the methods and structures outlined for a Graph maze.
 */

#include "Graph.h"
#include "GNode.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void Graph::readFile(char *path) {
  ifstream f;
  vector<GNode*> maze;
//  vector<vector<int>> mazeArr;
  f.open(path);
  string line;
  int col_pos, row_pos, cols, rows;

  char eatChar;
  f >> cols >> eatChar >> rows >> eatChar; // Read first values
//  f >> rows >> eatChar >> cols >> eatChar;

  vector<int>arr1(cols, 1);
  vector<vector<int>>mazeArr(rows, arr1);

  for(int i = 0; i < mazeArr.size(); i++) {
    cout << mazeArr.size();
    for(int o = 0; o < mazeArr[0].size(); o++) {
      cout << mazeArr[i][o] << " ";
    }
  }

  // Start and end tiles of maze
  int startX, startY, endX, endY;
  f >> eatChar >> startX >> eatChar >> startY >> eatChar >> eatChar;
  cout << "Begin: " << startX << " " << startY << " " << eatChar << endl;

  f >> eatChar >> endX >> eatChar >> endY >> eatChar >> eatChar;
  cout << "End: " << endX << " " << endY << " " << eatChar << endl;

  // Instantiate array
//  for(int i = 0; i < rows; i++) {
//    for(int o = 0; o < cols; o++) {
//      mazeArr[i][o] = 1;
//    }
//  }

  cout << "Sizeof rows: " << sizeof(mazeArr) / sizeof(mazeArr[0]) << endl;
  cout << "Sizeof cols: " << sizeof(mazeArr[0]) / sizeof(int) << endl;

  // For debugging
//  for(int i = 0; i < rows; i++) {
//    cout << " ";
//    for(int o = 0; o < cols; o++) {
//      cout << " " << mazeArr[i][o] << " ";
//    }
//    cout << " " << endl;
//  }
//  cout << endl;

  while(f >> eatChar >> col_pos >> eatChar >> row_pos >> eatChar >> eatChar) {
    // Wall has been found, flip the bit in maze
    mazeArr[row_pos][col_pos] = 0;
  }

//   For debugging
  for(int i = 0; i < rows; i++) {
    cout << " ";
    for(int o = 0; o < cols; o++) {
      cout << " " << mazeArr[i][o] << " ";
    }
    cout << " " << endl;
  }

  // Build out adjacency list, i * o long
  for(int i = 0; i < rows; i++) {
    for(int o = 0; o < cols; o++) {
      if(mazeArr[i][o] && mazeArr[i][o] == 1) {
        GNode *tmp = new GNode(o, i);
        maze.push_back(tmp);
        tmp->x = i;
        tmp->y = o;
        //**** Check adjacent nodes

        // top
        if(mazeArr[i+1][o] && mazeArr[i+1][o] == 1) {
          tmp->next = new GNode(o, i+1);
          tmp = tmp->next;
        }
        // right
        if(o < mazeArr[0].size() && mazeArr[i][o+1] && mazeArr[i][o+1] == 1) {
          tmp->next = new GNode(o+1, i);
          tmp = tmp->next;
        }
        // bottom
        if(i > 0 && mazeArr[i - 1][o] && mazeArr[i - 1][o] == 1) {
          tmp->next = new GNode(o, i - 1);
          tmp = tmp->next;
        }
        // left
        if(o > 0 && mazeArr[i][o - 1] && mazeArr[i][o - 1] == 1) {
          tmp->next = new GNode(o - 1, i);
          tmp = tmp->next;
        }
      }
    }
  }

  for(int i = 0; i < maze.size(); i++) {
    cout << " ";
      cout << "List [" << i << "]: ";
      for(GNode *t = maze[i]; t->next != NULL; t = t->next) {
        cout << " -> " << t->x << "," << t->y;
      }
      cout << endl;
  }

  this->maze = maze;
  this->start = new GNode(startX, startY);
  this->finish = new GNode(endX, endY);
  this->col_size = cols;
  this->row_size = rows;

  cout << endl;
  f.close();
}


//void Graph::display() {
//  Graph *maze = this;
//  int begin = 0;
//  int end = maze->maze.size();
//  Cell *current_row_node;
//  for (; begin < end; begin++) {
//    // iterating through rows currently
//    if (begin == 0) { // Print top line of col numbers
//      cout << " " << " " << "  " << 0 << " ";
//      for (int x = 1; x < maze->cols_array.size(); x++) {
//        cout << " " << x << " ";
//      }
//      cout << endl; // end top row
//    }
//    // iterate over each row 3 times
//    for (int i = 0; i < 3; i++) {
//      current_row_node = maze->rows_array[begin]; // reset
//      if (i == 1) {
//        if(begin == 10) {
//          cout << begin << " ";
//        } else {
//          cout << begin << " " << " ";
//        }
//
//      } else {
//        cout << " " << " " << " ";
//      }
//      for (int allCols = 0; allCols < maze->cols_array.size(); allCols++) {
//
//        switch (current_row_node->type) {
//          case Und:
//            cout << "UUU";
//            break;
//          case Wall:cout << "XXX";
//            break;
//          case Open:cout << "...";
//            break;
//          case Begin:
//            if (i == 1) {
//              cout << ".S.";
//            } else {
//              cout << "...";
//            }
//            break;
//          case End:
//            if (i == 1) {
//              cout << ".F.";
//            } else {
//              cout << "...";
//            }
//            break;
//          case Traversed:
//            if(i == 1) {
//              cout << ".o.";
//            } else {
//              cout << "...";
//            }
//            break;
//          default:cout << "UUU";
//        }
//        // increment to next column
//        current_row_node = current_row_node->right;
//      }
//      cout << endl;
//    }
//  }
//}



bool Graph::solveMazeWithBFS() {

}


// Helper that calls a recursive search
void DFS(GNode *n, bool *visited[], GNode *start, GNode *end) {
  visited[n->x][n->y] = true;


  // iterate over list items
  for(GNode *i = n; i->next != NULL; i = i->next) {
    if(i->x == start->)
    if(!visited[i->x][i->y])
  }
}

bool Graph::solveMazeWithDFS() {
  int rows = this->row_size;
  int cols = this->col_size;
  bool visited[rows][cols];

  for(int i = 0; i < sizeof(visited) / sizeof(visited[0]); i++) {
    for(int o = 0; i < sizeof(visited[0]) / sizeof(bool); o++)  {
      visited[i][o] = false;
    }
  }

  // Call recursive helper
  DFS(this->maze.front(), *visited, this->start, this->finish);
}