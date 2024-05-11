#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for x, now long instead of int
    long x = get_long("x: ");

    // prompt user for y
    long y = get_long("y: ");

    // perform calculation and introduce y
    long z = x + y;

    // present y as answer
    printf("%li\n", z);
}