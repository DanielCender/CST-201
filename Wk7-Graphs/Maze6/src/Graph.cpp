/**
 *  Maze6/src Graph.cpp
 *  Author: Daniel Cender
 *  Date: 06/9/2019
 *  Description: This source file implements the methods and structures outlined for a Graph maze.
 */

#include "Graph.h"
#include "GNode.h"
#include <vector>
#include <queue>
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
//  for(int i = 0; i < rows; i++) {
//    cout << " ";
//    for(int o = 0; o < cols; o++) {
//      cout << " " << mazeArr[i][o] << " ";
//    }
//    cout << " " << endl;
//  }

  // Build out adjacency list, i * o long
  for(int i = 0; i < rows; i++) {
    for(int o = 0; o < cols; o++) {
      if(mazeArr[i][o] && mazeArr[i][o] == 1) {
        GNode *tmp = new GNode(o, i);
        maze.push_back(tmp);
        tmp->x = i;
        tmp->y = o;
        // Store start and finish references to list nodes
        if(tmp->x == startX && tmp->y == startY) {
          this->start = tmp;
          mazeArr[i][o] = 2; // signifies start
        }
        if(tmp->x == endX && tmp->y == endY) {
          this->finish = tmp;
          mazeArr[i][o] = 3; // signifies finish
        }
        //**** Check adjacent nodes

        if(i == 10) {
          cout << "";
        }
        // bottom
        if(i + 1 < rows) {
          if(mazeArr[i+1][o] && mazeArr[i+1][o] > 0) {
            tmp->next = new GNode(o, i+1);
            tmp = tmp->next;
          }
        }

        // right
        if(o + 1 < cols) {
          if (mazeArr[i][o + 1] && mazeArr[i][o + 1] > 0) {
            tmp->next = new GNode(o + 1, i);
            tmp = tmp->next;
          }
        }
        // top
        if(i > 0 && mazeArr[i - 1][o] && mazeArr[i - 1][o] > 0) {
          tmp->next = new GNode(o, i - 1);
          tmp = tmp->next;
        }
        // left
        if(o > 0 && mazeArr[i][o - 1] && mazeArr[i][o - 1] > 0) {
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
  this->mazeArr = mazeArr;
  this->start = new GNode(startX, startY);
  this->finish = new GNode(endX, endY);
  this->col_size = cols;
  this->row_size = rows;

  cout << endl;
  f.close();
}


void Graph::display() {
  Graph *maze = this;
  int begin = 0;
  int end = maze->mazeArr.size();
  int current_row_node;
  for (; begin < end; begin++) {
    // iterating through rows currently
    if (begin == 0) { // Print top line of col numbers
      cout << " " << " " << "  " << 0 << " ";
      for (int x = 1; x < this->col_size; x++) {
        cout << " " << x << " ";
      }
      cout << endl; // end top row
    }
    // iterate over each row 3 times
    for (int i = 0; i < 3; i++) {
      current_row_node = this->mazeArr[begin][i]; // reset
      if (i == 1) {
        if(begin == 10) {
          cout << begin << " ";
        } else {
          cout << begin << " " << " ";
        }

      } else {
        cout << " " << " " << " ";
      }
      for (int allCols = 0; allCols < this->col_size; allCols++) {

        switch (current_row_node) {
          case -1:
            cout << "UUU";
            break;
          case 0:cout << "XXX";
            break;
          case 1:cout << "...";
            break;
          case 2:
            if (i == 1) {
              cout << ".S.";
            } else {
              cout << "...";
            }
            break;
          case 3:
            if (i == 1) {
              cout << ".F.";
            } else {
              cout << "...";
            }
            break;
          case 4:
            if(i == 1) {
              cout << ".o.";
            } else {
              cout << "...";
            }
            break;
          default:cout << "UUU";
        }
        // increment to next column
        current_row_node = this->mazeArr[begin][allCols];
      }
      cout << endl;
    }
  }
}



bool Graph::solveMazeWithBFS() {

}


// Helper that calls a recursive search
void Graph::DFS(GNode *n) {
//  visited[n->x][n->y] = true;

  // Set to Traversed for sake of displaying path traversal to console
  this->mazeArr[n->x][n->y] = 4; // AKA, traversed

  this->display(); // print to console to show path

  if(n->x == this->finish->x && n->y == this->finish->y) {
    // completed maze
    cout << "Successfully navigated maze!!!" << endl;
  }

  GNode *iter;
  for(auto & elem : this->maze) { // Search for list node matching neighbor
    if(elem->x == n->x && elem->y == n->y) {
      iter = elem;
    }
  }
  // iterate over list items
  for(GNode *i = iter; i->next != NULL; i = i->next) {
    if(this->mazeArr[i->x][i->y] != 4) { // has not been visited before, or !visited[i->x][i->y] version
      // Find item in maze vector
      GNode *tmp;
      for(auto & elem : this->maze) { // Search for list node matching neighbor
        if(elem->x == i->x && elem->y == i->y) {
          tmp = elem;
        }
      }
      DFS(tmp);
    }
  }
}

bool Graph::solveMazeWithDFS() {
  // Call recursive helper on start node, which is in this->maze
  DFS(this->start);
}