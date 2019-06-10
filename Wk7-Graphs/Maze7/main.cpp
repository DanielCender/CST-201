/**
 *  Maze7/ main.cpp
 *  Author: Daniel Cender
 *  Date: 06/9//2019
 *  Description: This program reads from a file and creates a maze represented as a matrix via an adjacency list.
 */

#include <iostream>
#include <fstream>
#include "src/Graph.h"

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

  Graph *new_maze = new Graph();
  new_maze->readFile("sample.txt");
//  new_maze->solveMazeWithDFS();
  new_maze->solveMazeWithBFS();
  new_maze->display();

  return 0;
}