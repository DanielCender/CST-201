#include <iostream>
#include <algorithm>
using namespace std;
#define N 100
// Using as reference for concepts: https://www.geeksforgeeks.org/c-qsort-vs-c-sort/

int main() {
    // Create array of unsorted integers
    int unsorted[N], largest;
    // Clock vars to check the time each process takes
    clock_t begin, end;
    double time_spent = 0.0;

    // Initialize arr
    for(int i = 0; i < N; i++) {
        unsorted[i] = rand();
    }

    // Without sorting, just checking all vars
    begin = clock();
    for(int i = 0; i < N; i++) {
        if(largest < unsorted[i]) {
            largest = unsorted[i];
        }
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Manual: Largest array elem: " << largest << " - Total Time: " << fixed << time_spent << endl;

    begin = clock();
    std::sort(unsorted, unsorted+N);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Largest element in array: " << unsorted[N - 1] << " - Total Time: " << fixed << time_spent << endl;
}