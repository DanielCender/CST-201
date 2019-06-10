/**
 *  Maze7/src Graph.cpp
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



// ****** Searches for a path to the finish via breadth-first algorithm *****
bool Graph::solveMazeWithBFS() {
  list<GNode*> queue;
  GNode *tmp = this->start;
  // Set start as visited
  this->mazeArr[tmp->y][tmp->x] = 4;

  // Check for end case here, just in case of edge scenario where (start == finish)
  if(tmp->x == this->finish->x && tmp->y == this->finish->y) { // Finish is found
    cout << "Path to finish has been found!" << endl;
    return true;
  }

  queue.push_back(tmp);

  while(!queue.empty()) {
    tmp = queue.front();
    cout << "Dequeued Item: " << tmp->x << "," << tmp->y << endl;
    queue.pop_front();

    this->display(); // print to console to show path

    // Check for end case here
    if(tmp->x == this->finish->x && tmp->y == this->finish->y) { // Finish is found
      cout << "Path to finish has been found!" << endl;
      return true;
    }

    // Get all neighbors and enqueue if not yet visited
    // Find item in maze vector
    int i = 0;
    for(GNode *elem = this->maze[i]; i < this->maze.size(); i++, elem = this->maze[i]) { // Search for list node matching neighbor
      if(elem->x == tmp->x && elem->y == tmp->y) {
        tmp = elem;
      }
    }
    // Then mark as visited and enqueue
    for(GNode *i = tmp; i->next != NULL; i = i->next) {
      if(this->mazeArr[i->y][i->x] != 4) { // If not already traversed, AKA 4
        this->mazeArr[i->y][i->x] = 4;
        queue.push_back(i);
    }
  }
  }
  cout << "Path not found for graph maze!" << endl;
  return false;

}


// Helper that calls a recursive search
void Graph::DFS(GNode *n) {
//  visited[n->x][n->y] = true;

  // Set to Traversed for sake of displaying path traversal to console
  if(n->x == this->start->x && n->y == this->start->y) this->mazeArr[n->x][n->y] = 4; // AKA, traversed

  this->display(); // print to console to show path

  if(n->x == this->finish->x && n->y == this->finish->y) {
    // completed maze
    cout << "Successfully navigated maze!!!" << endl;
  }

  // iterate over list items
  for(GNode *i = n; i->next != NULL; i = i->next) {
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