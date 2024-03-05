#include <stdio.h>
#include <string.h>

#define EN_LONGEST_WORD 44

typedef struct intString {
    int num;
    char str[EN_LONGEST_WORD];    
} intString;

int main() {
    FILE* file = fopen("coding_qual_input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    // Count lines.
    int lineCount = 0;
    char cBuffer[EN_LONGEST_WORD];
    while (fgets(cBuffer, sizeof(cBuffer), file) != NULL) {
        lineCount++;
    }

    rewind(file);

    // Make dictionary and initialize it.
    intString dictionary[lineCount];
    intString isBuffer;
    for (int i = 0; i < lineCount; i++) {
        fscanf(file, "%d %43s", &isBuffer.num, isBuffer.str);
        // Entries are sorted.
        int index = isBuffer.num - 1;
        dictionary[index].num = isBuffer.num;
        strcpy(dictionary[index].str, isBuffer.str);
    }
    fclose(file);

    // Get key sequence.
    int pyramidSequence[(lineCount + 1) / 2], sequenceIndex = 0, currentEndLevel = 1,  increment = 2;
    for (int i = 0; i < lineCount; i ++) {
        if (dictionary[i].num == currentEndLevel) {
            pyramidSequence[sequenceIndex] = dictionary[i].num;
            sequenceIndex++;
            currentEndLevel += increment;
            increment++;
        }
    }

    // Print message.
    for (int i = 0; i < sequenceIndex; i++) {
        int printIndex = pyramidSequence[i] - 1;
        printf("%s ", dictionary[printIndex].str);
    }

    return 0;
}