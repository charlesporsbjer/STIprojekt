#include <stdio.h> 

int main() {
    int num1, num2;
    char operator;

    printf("\nWelcome to the Simple Calculator Program!\n\n");
    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &operator);

    printf("\nEnter the first number: ");
    scanf("%d", &num1);

    printf("\nEnter the second number: ");
    scanf("%d", &num2);

    printf("\n------------------------\n");

    switch(operator) {
        case '+':
            printf("\nResult: %d + %d = %d\n", num1, num2, num1+num2);
            break;
        case '-':
            printf("\nResult: %d - %d = %d\n", num1, num2, num1-num2);
            break;
        case '*':
            printf("\nResult: %d * %d = %d\n", num1, num2, num1*num2);
            break;
        case '/':
            if(num2 != 0)
                printf("\nResult: %d / %d = %f\n", num1, num2, (float)num1/num2);
            else
                printf("\nError! Division by zero is not allowed.\n");
            break;
        case '%':
            if(num2 != 0)
                printf("\nResult: %d %% %d = %d\n", num1, num2, num1%num2);
            else
                printf("\nError! Division by zero is not allowed.\n");
            break;
        default:
            printf("\nError! Invalid operator.\n");
            break;
    }

    printf("\n------------------------\n");

    return 0;
}