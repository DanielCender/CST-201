#include <iostream>
#include <math.h>
#include <map>
#include <set>
using namespace std;


// Insertion sort inspiration from: https://www.geeksforgeeks.org/insertion-sort/
// Array pointer and n size
void insertionSort(int *arr, int n) {
  for(int i = 1; i < n; i++) {
    int el = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > el) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = el;
  }

}


int main() {
  int A[10] = {25, 13, 25, 10, 13, 8, 25, 13, 10, 25};
  int n = sizeof(A) / sizeof(A[0]);
  int kNum = 4; // sqrt(n); // sqrt(n) is the max number of unique items
  int B[kNum];

  set<int> s; // Use a set to test for duplicates

  // initialize B to -1
  for(int i = 0; i < kNum; i++) {
    B[i] = -1;
  }


  int arrayBIter = 0;
  for(int i = 0; i < n; i++) {
    if(s.find(A[i]) == s.end()) { // Means item wasn't found in set
      s.insert(A[i]);
      B[arrayBIter] = A[i]; // Store in table and B array
      arrayBIter++;
    }
  }

// Sort B with insertion sort
insertionSort(B, kNum);

  cout << "Array B: ";
  for(int p = 0; p < kNum; p++) {
    cout << B[p] << " ";
  }


  return 0;
}
