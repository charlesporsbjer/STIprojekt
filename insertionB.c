#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i]; // Select the current element to be inserted
        j = i - 1; // Start with the previous element

        // Move elements of arr[0..i-1] that are greater than key
        // one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Place the selected element (key) at its correct position
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = n - i; // Initialize the array with values from n to 1
    }

    printf("Original array: \n");
    printArray(arr, n);

    char choice;
    printf("Do you want to sort and print the array? (y/n): ");
    scanf(" %c", &choice); // Note the leading space in the format string to ignore any whitespace characters

    if (choice == 'y' || choice == 'Y') {
        insertionSort(arr, n);
        printf("\nSorted array: \n");
        printArray(arr, n);
    } else {
        printf("Array sorting and printing skipped.\n");
    }

    return 0;
}