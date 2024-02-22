#include <stdio.h>

int main() {
    
    int a, b, c, max;

    printf("Enter numbers a b & c:\n");
    scanf("%d%d%d", &a, &b, &c);

    max = (a > b && a > c) ? a : (b > c) ? b : c;
    
    printf("%d is greatest.", max);

    return 0;
}