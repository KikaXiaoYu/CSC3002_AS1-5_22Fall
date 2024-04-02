
/* Q2:
 * File: MergeSort.cpp
 * -------------------
 * This file implements the merge sort algorithm using arrays rather
 * than vectors.
 */

#include <iostream>
#include "csc300222fall/assignment4/MergeSort.h"    // for OJ
using namespace std;

/*
 * Function: sort
 * Usage: sort(array, n);
 * ----------------------
 * Sorts the first n elements of the vector into increasing order using
 * the merge sort algorithm, which consists of the following steps:
 *
 * 1. Copy the array into an array allocated on the stack.
 * 2. Divide the new array into two halves by manipulating the indices.
 * 3. Sort each half of the array recursively
 * 4. Merge the two halves back into the original one.
 */

void merge(int array[], int lstart, int rstart, int end, int store[]) {
    int lpos = lstart;
    int lend = rstart-1;
    int rpos = rstart;
    int rend = end;
    int curpos = lstart;
    while (lpos <= lend && rpos <= rend) {
      if (array[lpos] <= array[rpos]) {
         store[curpos++] = array[lpos++];
      } else {
         store[curpos++] = array[rpos++];
      }
    }
    while (lpos <= lend) {
      store[curpos++] = array[lpos++];
    }
    while (rpos <= rend) {
      store[curpos++] = array[rpos++];
    }
    for (int i = lstart; i <= end; i++) {
      array[i] = store[i];
    }

}

void helpSort(int array[], int start, int end, int store[]) {
    if (end == start) { return; }
    int mid = (end+start) / 2;
    helpSort(array, start, mid, store);
    helpSort(array, mid+1, end, store);
    merge(array, start, mid+1, end, store);
}


void sort(int array[], int n) {
    // TODO
    int store[n];
    helpSort(array, 0, n-1, store);
}

/*
 * Function: printArray
 * Usage: printArray(array, n);
 * ----------------------------
 * Prints the elements of the array on a single line with the elements
 * enclosed in braces and separated by commas.
 */

void printArray(int array[], int n) {
   cout << "{ ";
   for (int i = 0; i < n; i++) {
      if (i > 0) cout << ", ";
      cout << array[i];
   }
   cout << " }" << endl;
}

/* DO NOT modify the main() part */
int main() {
   int n;
   cin>>n;
   int array[200010];
   for(int i=0;i<n;i++) cin>>array[i];
   sort(array, n);
   printArray(array, n);
   return 0;
}
