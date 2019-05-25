#include <iostream>


int binarysearch(int *arr, int value, int left, int right) {
  while(left <= right) {
    int middle = (left + right) / 2;
    if(arr[middle] == value) {
      return middle;
    } else if(arr[middle] > value) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
}


int main() {
  std::cout << "Hello, World!" << std::endl;
  int arr[3] = {0, 1, 56};
  int size = sizeof(arr) / sizeof(arr[0]);
  int result = binarysearch(arr, 56, 0, size);
  std::cout << "Result: " << result;
  return 0;
}