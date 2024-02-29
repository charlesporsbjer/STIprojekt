#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Addition
    printf("Sum: %d + %d = %d\n", num1, num2, num1 + num2);

    // Subtraction
    printf("Difference: %d - %d = %d\n", num1, num2, num1 - num2);

    // Multiplication
    printf("Product: %d x %d = %d\n", num1, num2, num1 * num2);

    // Division
    if (num2 == 0) {
        printf("Error: cannot divide by zero!\n");
    } else {
        printf("Quotient: %d / %d = %d\n", num1, num2, num1 / num2);
    }

    return 0;
}