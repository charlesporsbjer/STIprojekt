#include <stdio.h>

#define INT_SIZE sizeof(int) * 8


int main() {
        int num, count, msb, i;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    count = 0;
    msb = 1 << (INT_SIZE - 1);

    /* Iterate over each bit of the number */
    for(i = 0; i < INT_SIZE; i++)
    {
        /* If set bit is found the terminate from loop*/
        if((num << i ) & msb)
        {
            /* Terminate from loop */
            break;
        }


        /* Increment trailing zeros count */
        count++;
    }

    printf("Total number of leading zeros in %d is %d.", num, count);

    return 0;
}