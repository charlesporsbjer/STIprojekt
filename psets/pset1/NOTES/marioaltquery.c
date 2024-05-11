#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    while (true)
    {
        n = get_int("Size: ");
        if (n > 0)
        {
            break;
        }
    }
}