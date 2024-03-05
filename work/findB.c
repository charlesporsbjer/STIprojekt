#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target;
    int i;

    printf("Enter the number to search for: ");
    scanf("%d", &target);

    for (i = 0; i < 10; i++) {
        if (arr[i] == target) {
            printf("Found at index %d\n", i);
            return 0;
        }
    }

    printf("Not found\n");

    return 0;
}