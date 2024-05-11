#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("n: ");

    // If n is even
    // my initial thought was to do something like this: if (n / 2 = int)
    // but it didn't work
    // the % sign divides the number as low as it goes and scans for 0 or 1 remaining
    if (n % 2 == 0)
    {
        printf("even\n");
    }
    else
    {
        printf("odd\n");
    }
}