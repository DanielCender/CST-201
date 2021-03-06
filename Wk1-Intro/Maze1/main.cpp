#include <iostream>
#include <fstream>
using namespace std;

/*
 *  Name: Maze1
 *  Author: Daniel Cender
 *  Date: 04/28/2019
 *  Description: This program reads in a 2-dimensional maze from a file and then displays the maze.
 */


// Read from file into array
void readFile(fstream& f) {
    f.open("sample.txt");
    string line;
    bool isOpen = f.is_open();
    if(isOpen) {
        while (getline(f, line)) {
            cout << line << endl;
        }
    }
    cout << endl;
    f.close();
}


// Display Maze
void displayMaze() {

}

int main() {
    int arrXSize, arrYSize;
    ifstream f;
//    readFile(inFile);
    f.open("sample.txt");
    string line;
    string delimiter = ", ";
    bool isOpen = f.is_open();
    if(isOpen) {
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

    for(int x = 0; x < sizeof(maze); x++) {
        for (int y = 0; y < sizeof(maze[0]); y++) {
            if (startX == x && startY == y) {
                        // Is the starting piece
                        cout << "S";
                    } else if (endX == x && endY == y) {
                        // Is the ending piece
                        cout << "F";
                    } else if (maze[x][y] == true) {
                        // Maze wall tile
                        cout << "X";
                    } else {
                        // Unblocked tile
                        cout << ".";
                    }
        }
        cout << endl;
    }

    // non functioning version of the above loop. Only prints out four columns. Should iterate over every row 3 times, printing out the complete 3x3 block indicating the wall/starting/ending/open tile.
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

    }
    cout << endl;
    f.close();

    return 0;
}