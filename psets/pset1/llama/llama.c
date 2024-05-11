#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int init;
    int goal;

    do
    {
        init = get_int("Initial llama population: ");

    }
    while (init < 9);

    do
    {
        goal = get_int("Target llama population: ");
    }
    while (goal < init);

    int year = 0;
    do
    {
        init = init + (init / 3) - (init / 4);
        year++;
    }
    while (init < goal);

    printf("It took your llamas %i years!", year);
}