#include <stdio.h>

int main() {
    unsigned char num1, num2, result;
    char operation;
    int temp;

    // Prompt user for first number
    printf("Enter first number (0-255): ");
    scanf("%c", &num1);

    // Clean the input buffer
    while ((temp = getchar()) != '\n' && temp != EOF) {}

    // Prompt user for second number
    printf("Enter second number (0-255): ");
    scanf("%c", &num2);

    // Clean the input buffer again
    while ((temp = getchar()) != '\n' && temp != EOF) {}

    // Ask for the operation to perform
    printf("Enter operation (+, -, *): ");
    scanf(" %c", &operation); // Note the space before %c to consume any newline character left in the input buffer

    // Perform the operation and print the result
    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%d * %d = %d\n", num1, num2, result);
            break;
        default:
            printf("Invalid operation.\n");
    }

    return 0;
}
