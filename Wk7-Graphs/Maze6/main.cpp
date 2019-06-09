/**
 *  Maze6/ main.cpp
 *  Author: Daniel Cender
 *  Date: 06/9//2019
 *  Description: This program reads from a file and creates a maze represented as a linked list.
 */

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
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

int main() {
//  ifstream f;  // FOR DEBUGGING - Just displays file contents line per line
//    readFile(f);

  Maze *new_maze = new Maze();
  new_maze->readFile("sample.txt");

  new_maze->display();

//  bool result = new_maze->solveMazeStack();

//  bool result = solveMazeQueue(new_maze);
//  bool result = new_maze->solveMazeQueue();
  bool result = new_maze->solveMazeHeap();
  new_maze->display();

  return 0;
}