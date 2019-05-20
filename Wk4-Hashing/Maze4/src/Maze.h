/**
 *  Maze4/src Maze.h
 *  Author: Daniel Cender
 *  Date: 05/19/2019
 *  Description: This header implements a 2-D array of doubly linked list to store the maze tiles.
 */
#include "Cell.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#ifndef MAZE4_SRC_MAZE_H_
#define MAZE4_SRC_MAZE_H_

class Maze {
 public:
  vector<Cell*> rows_array; // basic array is just too frustrating for this usage
  vector<Cell*> cols_array;
  Cell *start, *finish;
//  Maze() {
//    start = finish = 0;
//    rows = cols = 0;
//  }
  // Pass in rows, cols, starting cell, ending, and maze array
  Maze(int r = 0, int c = 0, Cell *s = 0, Cell *f = 0, Cell (*maze_array) [] = 0) {
    rows = r;
    cols = c;
  }
  ~Maze()  {
    rows_array.empty(); // Remove all maze elements
    cols_array.empty(); // Almost unnecessary
  };
  void readFile(char* path) {
    ifstream f;
    f.open(path);
    string line;
    int col_pos, row_pos;

    char eatChar;
    f >> cols >> eatChar >> rows >> eatChar; // Read first values

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
 private:
  int rows, cols; // cols is x, rows is y
};

#endif //MAZE4_SRC_MAZE_H_
