/**
 * C program to count flip all bits of a binary number using bitwise operator
 */

#include <stdio.h>

int main()
{
    int num, flippedNumber;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    flippedNumber = ~num;

    printf("Original number = %d (in decimal)\n", num);

    printf("Number after bits are flipped = %d (in decimal)\n", flippedNumber);

    return 0;
}