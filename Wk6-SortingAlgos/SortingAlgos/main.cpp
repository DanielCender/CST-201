#include <iostream>
using namespace std;



int main() {

  // Setup array for sorting tests
  int arr[1000];
  int n = sizeof(arr)/sizeof(arr[0]);

  for(int i = 0; i < n; i++) {
    arr[i] = (rand()%1000);
    cout << arr[i] << endl;
  }

  sort(arr, arr+n, greater<int>());

  cout << "Sorted!!!!!" << endl;

  for(int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }




  std::cout << "Hello, World!" << std::endl;
  return 0;
}