// BOT B
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 1024

int main() {
    // Open the input file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open the output file
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    // Read words from input file into an array
    char words[MAX_WORD_LEN][MAX_WORD_LEN];
    int num_words = 0;
    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, input_file) != NULL) {
        char *word = strtok(line, "\n");
        strcpy(words[num_words], word);
        num_words++;
    }

    // Sort the words
    qsort(words, num_words, sizeof(words[0]), compare_words);

    // Write sorted words to output file
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s\n", words[i]);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

// Comparison function for qsort
int compare_words(const void *a, const void *b) {
    char *word1 = *(char **)a;
    char *word2 = *(char **)b;
    return strcmp(word1, word2);
}