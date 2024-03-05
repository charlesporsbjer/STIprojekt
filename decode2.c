#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 512
#define MAX_WORD_LENGTH 64
#define MAX_MESSAGE_LENGTH 2048

typedef struct {
    int number;
    char word[MAX_WORD_LENGTH];
} Entry;

// Reads all entries into an array and returns the count of entries read.
int readEntries(const char* message_file, Entry* entries) {
    FILE *file = fopen(message_file, "r");
    if (!file) {
        perror("Error opening file");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%d %63s", &entries[count].number, entries[count].word) == 2) {
        count++;
        if (count >= MAX_ENTRIES) break; // Prevent overflow
    }

    fclose(file);
    return count;
}

// Constructs the decoded message based on the pyramid structure.
void constructMessage(Entry* entries, int count, char* decodedMessage) {
    int currentLevel = 1, currentLevelEndNumber = 1, increment = 2;

    decodedMessage[0] = '\0'; // Initialize the string to be empty

    for (int i = 0; i < count; i++) {
        if (entries[i].number == currentLevelEndNumber) {
            if (decodedMessage[0] != '\0') {
                strcat(decodedMessage, " "); // Add a space before appending the next word
            }
            strcat(decodedMessage, entries[i].word); // Append the word to the message

            currentLevel++; // Move to the next level in the pyramid
            currentLevelEndNumber += increment; // Calculate the next level's ending number
            increment++;
        }
    }
}

int main() {
    const char* filename = "coding_qual_input.txt";
    Entry entries[MAX_ENTRIES];
    char decodedMessage[MAX_MESSAGE_LENGTH]; // Allocate space for the decoded message

    int count = readEntries(filename, entries);
    constructMessage(entries, count, decodedMessage);

    if (decodedMessage[0] != '\0') {
        printf("Decoded message: %s\n", decodedMessage);
    } else {
        printf("Failed to decode the message.\n");
    }

    return 0;
}