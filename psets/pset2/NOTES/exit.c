#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n")
        // return other than 0 to main == something went wrong, abort.
        return 1;
    }
    // else is redundant since you can only qualify for one of these paths.
    else
    {
        printf("hello, %s\n", argv[1]);
        // returning 0 to main == all is well, proceed.
        return 0;
    }
}