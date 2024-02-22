#include <stdio.h>

int main() {
    
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    (a > b) 
    ? printf("first is bigger.") 
    : printf("second is bigger.");
    
    return 0;
}