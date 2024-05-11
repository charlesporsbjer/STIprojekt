#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for x
    int x = get_int("x: ");

    // prompt user for y
    int y = get_int("y: ");

    // divide x by y here doing what's called "casting" y to a float.
    float z = (float) x / (float) y;

    // perform addition
    printf("%.3f\n", z);
}