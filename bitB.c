#include <stdio.h>

int main() {
    int num1, num2, result;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    result = num1 ^ num2; // use bitwise XOR to add numbers
    result += (num1 & num2) << 1; // add carry bit

    printf("Result: %d\n", result);

    return 0;
}