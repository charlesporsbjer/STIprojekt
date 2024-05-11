#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int grade_level(int letters, int words, int sentences);

int main(void)
{
    // ask for input and repeat input
    string text = get_string("Text: ");

    // return grade level
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = grade_level(letters, words, sentences);

    // Print grade according to conditions
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}


// count and return letters
int count_letters(string text)
{
    // Initialize letters
    int letters = 0;

    // Iterate through all chars
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Increment if alphabetical
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}


// count and return words
int count_words(string text)
{
    int words = 1;

    // Iterate through all chars
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Increment if ASCII 32 (" ")
        if (text[i] == 32)
        {
            words++;
        }
    }

    return words;
}


// count and return sentences
int count_sentences(string text)
{
    int sentences = 0;

    // Iterate through all chars
    for (int i = 0, n = strlen(text); i < n; i++)
    {

        // Increment if '.', '!' or '?'
        if ((text[i] == 33) || (text[i] == 46) || (text[i] == 63))
        {
            sentences++;
        }
    }

    return sentences;
}


// call letters, words and sentences and calculate grade level
int grade_level(int letters, int words, int sentences)
{
    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;

    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    return grade;
}