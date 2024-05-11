#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int prompt;
    do
    {
        // prompt user for height
        prompt = get_int("Set height, 1-8: ");
    }
    // prompt again until answer is reasonable
    while (prompt > 8 || prompt < 1);

    // height starts at 0 and counts up, print new row if height is less than prompt answer (p).
    for (int height = 0; height < prompt; height++)
    {
        // alignment dots starts at prompt - 1 and counts down, print more dots if (a) is more than 0.
        for (int spacers = prompt - 1; spacers > height; spacers--)
        {
            printf(" ");
        }
        // width is set to 1 and counts up, print more # if width is less than height.
        for (int width = - 1; width < height; width++)
        {
            printf("#");
        }
        printf("\n");
    }
}