#include <stdio.h>
#include <string.h>

void generateWords(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            char newWord[100];
            strcpy(newWord, word1);
            newWord[i] = word2[j];
            strcat(newWord, &word1[i+1]);
            printf("%s\n", newWord);
        }
    }

    for (int i = 0; i < len2; i++) {
        for (int j = 0; j < len1; j++) {
            char newWord[100];
            strcpy(newWord, word2);
            newWord[i] = word1[j];
            strcat(newWord, &word2[i+1]);
            printf("%s\n", newWord);
        }
    }
}

int main() {
    char word1[100], word2[100];

    printf("Enter first word: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strlen(word1) - 1] = '\0'; // remove newline character

    printf("Enter second word: ");
    fgets(word2, sizeof(word2), stdin);
    word2[strlen(word2) - 1] = '\0'; // remove newline character

    generateWords(word1, word2);

    return 0;
}