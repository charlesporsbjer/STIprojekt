#include <stdio.h>

void bubbleSort(int arr[], int n) {
  int i, j, temp;

  // loop through the array until no more swaps are needed
  for (i = 0; i < n - 1; i++) {
    // loop through the array from i to the end
    for (j = i + 1; j < n; j++) {
      // if the current element is greater than the next element, swap them
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {
  int arr[] = {5, 2, 8, 3, 1, 6, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  // print the original array
  printf("Original array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // sort the array using bubble sort
  bubbleSort(arr, n);

  // print the sorted array
  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}