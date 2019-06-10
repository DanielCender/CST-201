/**
 *  Maze6/src Graph.cpp
 *  Author: Daniel Cender
 *  Date: 06/9/2019
 *  Description: This source file implements the methods and structures outlined for a Graph maze.
 */

#include "Graph.h"
#include "GNode.h"
#include <iostream>
#include <fstream>
using namespace std;

void Graph::readFile(char *path) {
  ifstream f;
  vector<GNode*> maze;
  f.open(path);
  string line;
  int col_pos, row_pos, cols, rows;

  char eatChar;
  f >> cols >> eatChar >> rows >> eatChar; // Read first values
//  f >> rows >> eatChar >> cols >> eatChar;
  cout << "x size: " << cols << endl;
  cout << "y size: " << rows << endl;

  int mazeArr[rows][cols];

  // Start and end tiles of maze
  int startX, startY, endX, endY;
  f >> eatChar >> startX >> eatChar >> startY >> eatChar >> eatChar;
  cout << "Begin: " << startX << " " << startY << " " << eatChar << endl;

  f >> eatChar >> endX >> eatChar >> endY >> eatChar >> eatChar;
  cout << "End: " << endX << " " << endY << " " << eatChar << endl;

  // Instantiate array
  for(int i = 0; i < rows; i++) {
    for(int o = 0; o < cols; o++) {
      mazeArr[i][o] = 1;
    }
  }

  cout << "Sizeof rows: " << sizeof(mazeArr) / sizeof(mazeArr[0]) << endl;
  cout << "Sizeof cols: " << sizeof(mazeArr[0]) / sizeof(int) << endl;

  // For debugging
  for(int i = 0; i < rows; i++) {
    cout << " ";
    for(int o = 0; o < cols; o++) {
      cout << " " << mazeArr[i][o] << " ";
    }
    cout << " " << endl;
  }
  cout << endl;

  while(f >> eatChar >> col_pos >> eatChar >> row_pos >> eatChar >> eatChar) {
    // Wall has been found, flip the bit in maze
    mazeArr[row_pos][col_pos] = 0;
  }

  // For debugging
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
          cout << mazeArr[i+1][o] << endl;
          tmp->next = new GNode(o, i+1);
          tmp = tmp->next;
        }
        // right
        if(mazeArr[i][o+1] && mazeArr[i][o+1] == 1) {
          cout << mazeArr[i][o+1] << endl;
          tmp->next = new GNode(o+1, i);
          tmp = tmp->next;
        }
        // bottom
        if(mazeArr[i - 1][o] && mazeArr[i - 1][o] == 1) {
          cout << mazeArr[i - 1][o] << endl;
          tmp->next = new GNode(o, i - 1);
          tmp = tmp->next;
        }
        // left
        if(mazeArr[i][o - 1] && mazeArr[i][o - 1] == 1) {
          cout << mazeArr[i][o - 1] << endl;
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
        cout << " -> " << t->x << "," << t->y << endl;
      }
      cout << endl;
  }

  this->maze = maze;



  // Switch all designated blocks to Walls, not Open
//  while(f >> eatChar >> col_pos >> eatChar >> row_pos >> eatChar >> eatChar) {
//    Cell *curr = cols_array[col_pos];
//    for(int i = 0; i < row_pos;i++) {
//      curr = curr->bottom;
//    }
//    curr->type = Wall;
//  }
//
//  // Set beginning and end blocks
//  Cell *start = cols_array[startX];
//  for(int i = 0; i < startY;i++) {
//    start = start->bottom;
//  }
//  start->type = Begin;
//  this->start = start;
//
//  Cell *end = cols_array[endX];
//  for(int i = 0; i < endY; i++) {
//    end = end->bottom;
//  }
//  end->type = End;
//  this->finish = end;

  cout << endl;
  f.close();
}

