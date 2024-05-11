#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for x
    float x = get_float("x: ");

    // prompt user for y
    float y = get_float("y: ");

    // divide x by y
    float z = x / y;

    // perform addition
    printf("%.3f\n", z);
}