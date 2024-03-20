#include <stdio.h>

int main() {
    int n = 500;
    double sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    double E = (1.0 / 2.0) * sum;

    printf("The average number of guesses is: %.2f\n", E);

    return 0;
}