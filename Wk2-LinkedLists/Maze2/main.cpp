/**
 *  Maze2/ main.cpp
 *  Author: Daniel Cender
 *  Date: 05/05/2019
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
        cout << endl; // ending a row
      }
    }
  }


  void solveMaze(const Maze *maze) {
    stack<Cell> backtrack;


}

int main() {
  int arrXSize, arrYSize;
  ifstream f;
//    readFile(f); // FOR DEBUGGING - Just displays file contents line per line

  Maze *new_maze = new Maze();
  new_maze->readFile("sample.txt");

  displayMaze(new_maze);

  // solveMaze(new_maze); // TODO

  return 0;
}