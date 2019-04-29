#include <iostream>
#include <fstream>
using namespace std;


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

        for(bool x: maze){
            for(bool cell : maze[x]) {
                cout << cell << endl;
            }

        }
    x = 0;
    y = 0;
        for(int i = 0; i < sizeof(maze) / sizeof(maze[0]); i++) {
            int rowsPrinted = 0;
            while(rowsPrinted < 3) { // Prints three rows of each
                for (int y = 0; y < (sizeof(maze[0]) / sizeof(int)); y++) {
                    if (startX == i && startY == y) {
                        // Is the starting piece
                        cout << (rowsPrinted == 1) ? ".S." : "...";
                    } else if (endX == i && endY == y) {
                        // Is the ending piece
                        cout << (rowsPrinted == 1) ? ".F." : "..."; // Checks if this is middle row
                    } else if (maze[i][y] == true) {
                        // Maze wall tile
                        cout << "XXX";
                    } else {
                        // Unblocked tile
                        cout << "...";
                    }
                }
                cout << endl;
                ++rowsPrinted;
            }
        }

    }
    cout << endl;
    f.close();

    return 0;
}