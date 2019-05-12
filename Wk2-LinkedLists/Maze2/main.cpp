/**
 *  Maze2/ main.cpp
 *  Author: Daniel Cender
 *  Date: 05/05/2019
 *  Description: This program reads from a file and creates a maze represented as a linked list.
 */
#include <iostream>
#include <fstream>
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

int main() {
  int arrXSize, arrYSize;
  ifstream f;
//    readFile(f); // FOR DEBUGGING - Just displays file contents line per line

  Maze *new_maze = new Maze();
  new_maze->readFile("sample.txt");

  displayMaze(new_maze);

  // solveMaze(new_maze); // TODO


  f.open("sample.txt");
  string line;
  string delimiter = ", ";
  getline(f, line);
  if(f) {
    Maze *maze_list = new Maze(); // Create linked list for maze nodes

    Cell *start_position = new Cell();
    Cell *end_position = new Cell();

    char eatChar;
    f >> arrXSize >> eatChar >> arrYSize >> eatChar; // Read first values

    cout << "x size: " << arrXSize << endl;
    cout << "y size: " << arrYSize << endl;

    int start, end [2]; // Start and end tiles of maze
    int startX, startY, endX, endY;
    f >> eatChar >> startX >> eatChar >> endX >> eatChar >> eatChar;
    cout << "Begin: " << startX << " " << endX << " " << eatChar << endl;

    f >> eatChar >> startY >> eatChar >> endY >> eatChar >> eatChar;
    cout << "End: " << startY << " " << endY << " " << eatChar << endl;

    bool maze [arrXSize][arrYSize]; // 2-d array of indicators whether tile is closed or open




    // Initialize array as unblocked cells
    for(int x = 0; x < (sizeof(maze) / sizeof(maze[0])); x++) {
      for(int y = 0; y < (sizeof(maze[0]) / sizeof(int)); y++) {
        maze[x][y] = false;
      }
    }

    int x,y;
    while(f >> eatChar >> x >> eatChar >> y >> eatChar >> eatChar) {
      maze[x][y] = true;
    }

    x = 0;
    y = 0;

//    for(int x = 0; x < sizeof(maze); x++) {
//      for (int y = 0; y < sizeof(maze[0]); y++) {
//        if (startX == x && startY == y) {
//          // Is the starting piece
//          // Define starting position
//          cout << "S";
//        } else if (endX == x && endY == y) {
//          // Is the ending piece
//        //   end_position = CHANGE POINT Structure to accept x-y coordinates or a pointer to the list node
//          maze_list->push(true);
//          cout << "F";
//        } else if (maze[x][y] == true) {
//          // Maze wall tile
//          maze_list->push(true);
//          cout << "X";
//        } else {
//          // Unblocked tile
//          maze_list->push(false);
//          cout << ".";
//        }
//      }
//      cout << endl;
//    }
//
//    // non functioning version of the above loop. Only prints out four columns. Should iterate over every row 3 times, printing out the complete 3x3 block indicating the wall/starting/ending/open tile.
//        for(int i = 0; i < sizeof(maze) / sizeof(maze[0]); i++) {
//            int rowsPrinted = 0;
//            while(rowsPrinted < 3) { // Prints three rows of each
//                for (int y = 0; y < (sizeof(maze[0]) / sizeof(int)); y++) {
//                    if (startX == i && startY == y) {
//                        // Is the starting piece
//                        cout << (rowsPrinted == 1) ? ".S." : "...";
//                    } else if (endX == i && endY == y) {
//                        // Is the ending piece
//                        cout << (rowsPrinted == 1) ? ".F." : "..."; // Checks if this is middle row
//                    } else if (maze[i][y] == true) {
//                        // Maze wall tile
//                        cout << "XXX";
//                    } else {
//                        // Unblocked tile
//                        cout << "...";
//                    }
//                }
//                cout << endl;
//                ++rowsPrinted;
//            }
//        }
//
  }
  cout << endl;
  f.close();

  return 0;
}