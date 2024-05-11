#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
        // if (s[i] >= 'a' && s[i] <= 'z')
        {
            // toupper actually makes this whole if else block irrelevant since it has all the functions built in.
            printf("%c", toupper(s[i]));
            // printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}