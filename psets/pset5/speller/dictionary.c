// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Choose number of buckets in hash table
const unsigned short N = 3001;

// Keeps track of words loaded into table
unsigned int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false, case insensitive
bool check(const char *word)
{
    // Call hash function to get index
    unsigned int hash_index = hash(word);
    struct node *tmp_ptr;

    if (table[hash_index] == NULL)
    {
        // Word is not in dictionary
        return false;
    }

    else
    {
        tmp_ptr = table[hash_index];

        while (tmp_ptr != NULL && (strcasecmp(word, tmp_ptr->word) == 0))
        {
            // Word found in dictionary
            return true;
        }
        tmp_ptr = tmp_ptr->next;
    }
    // Word not found in dictionary
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Return number between 0 and N using a prime number multiplier
    unsigned short multiplier = 601;
    unsigned int hash_nr = 0;

    // Iterate through word until new row
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Look for uppercase letters and lowercase them
        char lwrcase_char = word[i];
        if (isupper(word[i]))
        {
            lwrcase_char = tolower(word[i]);
        }
        // Add sum of lowercase ASCII characters
        hash_nr += lwrcase_char;
    }
    // Multiply first for BIGGer while loop
    //hash_nr = hash_nr * multiplier;

    // Multiply and reduce ;) while sum is greater than bucket size
    while (hash_nr >= N)
    {
        hash_nr = hash_nr * multiplier;
        hash_nr = hash_nr % N;
    }

    return hash_nr;
}
// Loads dictionary into hash table,
// Returns true if successful; else false
bool load(const char *dictionary)
{
    FILE *dic_ptr = fopen(dictionary, "r");
    if (dic_ptr == NULL)
    {
        // Failed to open dictionary
        return false;
    }

    char buffer[LENGTH + 1];

    // Iterate through strings
    while (fscanf(dic_ptr, "%s", buffer) != EOF)
    {
        // Increment word count
        word_count++;

        // Allocate memory for temp node
        struct node *temp = malloc(sizeof(*temp));

        if (temp == NULL)
        {
            // Failed to allocate
            return false;
        }
        // Set nodes next pointer to NULL
        temp->next = NULL;

        // Copy word from buffer into node
        strcpy(temp->word, buffer);

        // Call hash to compute hash index for word
        int hash_idx = hash(temp->word);

        // If there is no word in bucket; insert word
        if (table[hash_idx] == NULL)
        {
            table[hash_idx] = temp;
        }
        // Else insert node in beginning of list
        // Point next to current index which is occupied
        // Then update index to point to temp
        else
        {
            temp->next = table[hash_idx];
            table[hash_idx] = temp;
        }
    }
    // Close file and return true
    fclose(dic_ptr);
    return true;
}

// Returns number of words in dictionary
unsigned int size(void)
{
    // return global variable word_count that is incremented in load
    return word_count;
}

// Unloads dictionary from memory,
// Returns true if successful
bool unload(void)
{
    // Iterate through buckets in table
    for (int i = 0; i < N; i++)
    {
        // Temps to point at current bucket
        struct node *current = table[i];
        struct node *next_node;

        while (current != NULL)
        {
            // Store next node in list
            next_node = current->next;
            // Free current node
            free(current);
            // Move to next node
            current = next_node;
        }
    }
    // Unload successful
    return true;
}