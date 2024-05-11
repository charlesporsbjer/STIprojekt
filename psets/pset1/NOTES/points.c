#include <cs50.h>
#include <stdio.h>

int main(void)
{
   // constant (often in caps) so that i cannot mess this up later in the code
const int MINE = 2;

int points = get_int("How many pounts did you lose? ");

if (points < MINE)
{
    printf("You lost fewer points than me.\n");
}
else if (points > MINE)
{
    printf("You lost more points than me.\n");
}
    // no need to use: else if (points == MINE), since there is logically only one option left.
else
{
    printf("You lost the same number of points as me.\n");
}
}
