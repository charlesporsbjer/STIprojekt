#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fac = 1, i;
    for(i = 2; i <= n; i++) {
        fac *= i;
    }
    return fac;
}

int main() {
    int number, result;
    
    printf("Enter a number to find its factorial: ");
    scanf("%d", &number);
    
    result = factorial(number);
    printf("The factorial of %d is: %d\n", number, result);
    
    return 0;
}