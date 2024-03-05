#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not present in array
    return -1;
}

int main(void) {
    srand(time(0));

    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int numElements;
    printf("Enter the number of elements to search for: ");
    scanf("%d", &numElements);

    int x[numElements];
    for(int i = 0; i < numElements; i++) {
        printf("Enter element %d to search for: ", i+1);
        scanf("%d", &x[i]);
    }

    printf("Search Results: \n");
    for(int i = 0; i < numElements; i++) {
        int result = binarySearch(arr, 0, n - 1, x[i]);
        (result == -1) ? printf("Element %d is not present in array\n", x[i])
                       : printf("Element %d is present at index %d\n", x[i], result);
    }

    return 0;
}