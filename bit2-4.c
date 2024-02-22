#include <stdio.h>

#define INT_SIZE sizeof(int) * 8
#define INT_BITS INT_SIZE - 1

int main() {
    int num, initNum, amount, msb, lsb;
    char direction;

    printf("Number to rotate: ");
    scanf("%d", &num);
    printf("You entered %d\n", num);

    initNum = num;

    while ((getchar()) != '\n') {}

    printf("Rotate l or r: ");
    scanf("%c", &direction);
    printf("You entered %c\n", direction);

    while ((getchar()) != '\n') {}

    printf("Amount to rotate: ");
    scanf("%d", &amount);
    printf("You entered %d\n", amount);
    amount %= INT_BITS;

    if (direction == 'l') {
        for (int i = 0; i < amount; i++) {
            msb = (num >> INT_BITS) & 1;
            num = (num << 1) | msb; 
        }
    }
    else {
        for (int i = 0; i < amount; i++) {
            lsb = num & 1;
            num = (num >> 1);
            num = num & (~(1 << INT_BITS));
            num = num | (lsb << INT_BITS);
        }
    }

     /* Print rotated number */
    if (direction == 'l')
        printf("%d rotated left %d times and new number is %d", initNum, amount, num);
    else
        printf("%d rotated right %d times and new number is %d", initNum, amount, num);

    return 0;
}