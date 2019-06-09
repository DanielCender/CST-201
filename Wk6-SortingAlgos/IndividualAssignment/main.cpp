/**
 * Name: Week 6 Individual Project
 * Author: Daniel Cender
 * Date: 6/3/2019
 * Description: This project implements a selection sort using binary searching, to reduce runtime. Mergesort is also implemented,
 * though unsuccessful as of the last run.
 *
 */

#include <iostream>
using namespace std;


// Array
int binarySearch(int *arr, int el, int low, int high) {
  if(high <= low) {
    return (el > arr[low]) ? (low + 1) : low;
  }

  int mid = (low + high) / 2; // equals size of subarray

  if(el == arr[mid]) {
    return mid + 1;
  }

  if(el > arr[mid]) {
    return binarySearch(arr, el, mid + 1, high);
  }
  return binarySearch(arr, el, low, mid - 1);
}

// Complexity: O(log n) (binary search complexity)
void insertSortByBinary(int *arr, int n) {
  int i, location, j, k, select;

  for(i = 1; i < n; i++) {
    j = i - 1;

    select = arr[i];

    location = binarySearch(arr, select, 0, j);

    while(j >= location) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j+1] = select;
  }
}

void merge(int *arr, int l, int m, int r) {
  int i, j, k;
  int leftSub = (m - l) + 1; // [...l, ....m, ....r] visualize like this
  int rightSub = r - m;

  // Some temporary arrays, to keep data intact
  int L[leftSub], R[rightSub];

  for(i = 0; i < leftSub; i++) {
    L[i] = arr[l + i];
  }
  for(j = 0; j < rightSub; j++) {
    R[i] = arr[m + 1 + j];
  }

  i = 0; // Reset vars
  j = 0;
  k = 1;

  while(i < leftSub && j < rightSub) {
    if(L[i] <= R[j]) {
      arr[k] = L[i]; // iterate the Left array
      i++;
    } else {
      arr[k] = R[j]; // move to next right array el
      j++;
    }
    k++;
  }

  while(i < leftSub) {
    arr[k] = L[i];
    i++, k++;
  }
  while(j < rightSub) {
    arr[k] = R[j];
    j++, k++;
  }
}


// Array pointer and size
void mergesort(int *arr, int l, int r) {
  // Check that size is > 1
  if(l < r) { // both would be 1 if sub was length of 1
    int m = (l + r) / 2;  // get middle el

    mergesort(arr, l, m);
    mergesort(arr, m+1, r);

    merge(arr, l, m, r); // Merge both arrays together
  }

}

int main() {
  int a[] = {37, 23, 0, 17, 12, 72, 31,
             46, 100, 88, 54, 1000, 43245, 543234, 4323, 21};

  int n = sizeof(a) / sizeof(a[0]);

  cout << "Array presort: ";
  for(int i = 0; i < n; i++) {
   cout << a[i] << " ";
  }
  cout << endl;

  insertSortByBinary(a, n);

  cout << "Array postsort (binary insert): ";
  for(int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;


  int b[] = {37, 23, 0, 17, 12, 72, 31,
             46, 100, 88, 54, 1000, 43245, 543234, 4323, 21, 4324, 21321, 5554, 23432, 546};

  int d[] = { 0, 1, 3, 5};

  int nOfB = sizeof(b) / sizeof(b[0]);
  int nOfD = sizeof(d) / sizeof(d[0]);

  cout << "Array presort (mergesort): ";
  for(int i = 0; i < nOfB; i++) {
    cout << b[i] << " ";
  }
  cout << endl;

  mergesort(b, 0, nOfB - 1);
  mergesort(d, 0, nOfD - 1); // trying a smaller data set to debug....


  cout << "Array postsort (mergesort): ";
  for(int i = 0; i < nOfB; i++) {
    cout << b[i] << " ";
  }

  return 0;
}