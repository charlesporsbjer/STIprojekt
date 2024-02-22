#include <stdio.h>

#define INT_SIZE sizeof(int) * 8
#define INT_BITS INT_SIZE - 1

int main() {
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    num1 ^= num2;

    num2 ^= num1;

    num1 ^= num2;

    printf("first number is now %d\n", num1);
    printf("second number is now %d\n", num2);

    return 0;
}