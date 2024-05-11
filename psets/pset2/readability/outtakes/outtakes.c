    // how to calculate readability score:
    // L == number of letters
    // S == average number of sentences
    // index = 0.0588 * L - 0.296 * S - 15.8

// REMOVED int count_characters(string text);

// maybe comment out the below if you want to restore other counting functions

/* return no. of letters
    //int letters = count_letters(text);

    //printf("%i letters\n", letters);


// return no. of words
    //int words = count_words(text);

    //printf("%i words\n", words);


// return no. of sentences
    //int sentences = count_sentences(text);

    printf("%i sentences\n", sentences);
*/
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_characters(void);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    // how to calculate readability score:
    // L == number of letters
    // S == average number of sentences
    // index = 0.0588 * L - 0.296 * S - 15.8



    // printf("Text:  %text, s");


    // get string to calculate from

    //count number of letters (characters) (strlen, then isalpha)

   // count_characters


    //count number of words (any number of characters separated by spaces) (isspace)
    {
    // char c = get_char(string s);

    // if (isspace(c))
    {
        // printf("Your input is whitespace.\n");
    }
    // else
    {
        // printf("Your input is not whitespace.\n");
    }
    }
    //count number of sentences (indicated by !, ? or .)

    // int ispunct(int c);

    // printf("Grade x") as answer. If 16 or higher, show 16+

int character(text)
{
    char c = get_char("Input: ");
    if (isalpha(c))
    {

    }
    else
    {

    }
}

int count_letters(int text)
{
       string text = isalpha()
       int isaplha(char i)
}
   return int letters;
}

int count_sentences(str text)
{

}

int count_characters(int text)
{
    string text = get_string("Text: ");

    int tl = strlen(text);

        {
            printf("Text: %i", tl);
        }

    printf("\n");
}
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int count_letters(int text);
int count_words(int text);
int count_sentences(int text);
int main(void);


int count_characters(int text)
{
    string text = get_string("Text: ");

    int tl = strlen(text);

        {
            printf("Text: %i", tl);
        }

    printf("\n");
}
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_characters(void);
int count_letters(string text);
int count_words(int text);
int count_sentences(int text);
int main(void);

int count_letters(string text)
{
    int letters = isalpha(text);

    {
        printf("Text: %i", letters);
    }

    printf("\n");

    return;
}

// pasted from readtestmain

// sending characters (not letters) NEEDS WORKAROUND (isalpha should do it somehow)
//int count_letters(string text)
//{
    //int count_characters = strlen(text);

    //for (int i = 0; i < count_characters; i++)
    //{
    //    printf("%i letters\n", strlen(text)
    //}
//}
