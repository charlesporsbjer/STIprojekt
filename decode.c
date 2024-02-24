#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 2048
#define MAX_WORD_LENGTH 64

int countEntries(void) {
    FILE *file = fopen(message_file, "r");
    if (!file) {
        perror("Error opening file");
        return 0;
    }

    int count = 0;
    char buffer[64];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        count++;
    }

    fclose(file);
    return count;
}

char* decode(const char* message_file, char* decodedMessage) {
    FILE *file = fopen(message_file, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    
    int number;
    char word[MAX_WORD_LENGTH];
    decodedMessage[0] = '\0'; // Initialize the string to be empty
    int currentLevel = 1, currentLevelEndNumber = 1, increment = 2;
    int count = countEntries();
    for (int i = 0; i < count; i++) {
        while (fscanf(file, "%d %63s", &number, word) == 2) {
            if (number == currentLevelEndNumber) {
                if (decodedMessage[0] != '\0') {
                    strcat(decodedMessage, " "); // Add a space before appending the next word
                }
                strcat(decodedMessage, word); // Append the word to the message

                currentLevel++; // Move to the next level in the pyramid
                currentLevelEndNumber += increment; // Calculate the next level's ending number
                increment++;
            }
        }
    }

    fclose(file);
    return decodedMessage;
}

int main() {
    const char* filename = "coding_qual_input.txt";
    char decodedMessage[MAX_MESSAGE_LENGTH]; // Allocate space for the decoded message

    if (decode(filename, decodedMessage)) {
        printf("Decoded message: %s\n", decodedMessage);
    } else {
        printf("Failed to decode the message.\n");
    }

    return 0;
}