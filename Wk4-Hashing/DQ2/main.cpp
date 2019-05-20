#include <iostream>
#include <map>
using namespace std;


template <typename T>
void insertNoCollision(T map[], T data) {
  // First try at inserting at (data mod TSize)
  int key = 0;
  while(!map[key]) {
    // Keep moving through the possible mod Table spaces
    key = (key + 1) % (sizeof(map) / sizeof(T));
  }
  map[key] = data;
}

int main() {
  map<int, char> sampleMap = map<int, char>();
  sampleMap.insert(pair<int, char>(0, 'A'));
  sampleMap.insert(pair<int, char>(1, 'B'));
  sampleMap.insert(pair<int, char>(2, 'C'));
  sampleMap.insert(pair<int, char>(3, 'D'));

  // Attempt to insert

  std::cout << "Hello, World!" << std::endl;
  return 0;
}