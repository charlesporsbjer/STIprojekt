#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("How many scores? ");

    int scores[n];

    for (int i = 0; i < n; i++)
    {
        // solve this
       scores[i] = get_int("Score: ");
    }

        {
            // and solve this
            printf("Average: %f\n", s / n);
        }
}