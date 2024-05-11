#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    string plain = get_string("Plaintext:  ");

    printf("Ciphertext: ");

    for (int j = 0; j < strlen(plain); j++)

    if (isupper(plain[j]))
    {
        printf("%c", (plain[j] - 65 + key) % 26 + 65);
    }

    else if (islower(plain[j]))
    {
        printf("%c", (plain[j] - 97 + key) % 26 + 97);
    }

    else
    {
        printf("%c", plain[j]);
    }
    printf("\n");
}




    // make sure program can run with just one command line argument

    // make sure every char in argv[1] is a digit

    // FOR BETA ask for plaintext

    // convert argv[1] from a string into an int



    // for each character in plaintext:

    // rotate every character IF it is a LETTER

    // Output encrypted message

// char i = p * (i + k) %26mk