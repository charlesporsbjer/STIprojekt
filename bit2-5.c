#include <stdio.h>

#define INT_SIZE sizeof(int) * 8
#define INT_BITS INT_SIZE - 1

int main() {
    int num, initNum, binary;
    printf("Enter number to convert: ");
    scanf("%d", &num);

    initNum = num;

    int binArr [INT_SIZE];

    int index = INT_BITS;

    for (int i = INT_SIZE; i > 0; i--) {
        binArr[index] = num & 1;
        index --;
        num = num >> 1;
    }

    printf("number %d in binary = ", initNum);
    for (int i = 0; i < INT_SIZE; i++) {
        printf("%d", binArr[i]);
    }

    return 0;
}