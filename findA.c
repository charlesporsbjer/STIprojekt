#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num, i, found = 0;

    printf("Enter the number to search for: ");
    scanf("%d", &num);

    for (i = 0; i < 10; i++) {
        if (arr[i] == num) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("The number %d is found at index %d.\n", num, i);
    } else {
        printf("The number %d is not found in the array.\n", num);
    }

    return 0;
}