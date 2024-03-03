#include <stdio.h> 

int main() {
    int num1, num2;
    char operator;

    printf("\nWelcome to the Simple Calculator Program!\n");
    printf("---------------------------------\n\n");
    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &operator);
    printf("\nEnter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("\n---------------------------------\n");
    printf("Result:\n");

    switch(operator) {
        case '+':
            printf("  %d + %d = %d\n", num1, num2, num1+num2);
            break;
        case '-':
            printf("  %d - %d = %d\n", num1, num2, num1-num2);
            break;
        case '*':
            printf("  %d * %d = %d\n", num1, num2, num1*num2);
            break;
        case '/':
            if(num2 != 0)
                printf("  %d / %d = %f\n", num1, num2, (float)num1/num2);
            else
                printf("Error! Division by zero is not allowed.\n");
            break;
        case '%':
            if(num2 != 0)
                printf("  %d %% %d = %d\n", num1, num2, num1%num2);
            else
                printf("Error! Division by zero is not allowed.\n");
            break;
        default:
            printf("Error! Invalid operator.\n");
            break;
    }

    printf("\n---------------------------------\n");

    return 0;
}