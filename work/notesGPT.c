#include <stdio.h>
#include <string.h>

// Simplify note by removing flat or sharp, returning the base note's position in the scale.
int simplifyNoteIndex(char note) {
    // Assuming notes A, B, C, D, E, F, G without regard to flats or sharps.
    if (note >= 'A' && note <= 'G') {
        return note - 'A';
    }
    // Default case should not happen with valid input.
    return -1;
}

int isLegalTriad(char* note1, char* note2, char* note3) {
    int index1 = simplifyNoteIndex(note1[0]);
    int index2 = simplifyNoteIndex(note2[0]);
    int index3 = simplifyNoteIndex(note3[0]);

    // Normalizing the indices to ensure they are in ascending order for comparison.
    int indices[3] = {index1, index2, index3};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (indices[i] > indices[j]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    // Checking if the normalized indices follow the pattern of a legal triad.
    if ((indices[1] - indices[0] == 2) && (indices[2] - indices[1] == 2)) {
        return 1;
    }

    return 0;
}

int main() {
    char note1[3], note2[3], note3[3];
    printf("Enter three notes: ");
    scanf("%s %s %s", note1, note2, note3);

    if(isLegalTriad(note1, note2, note3)) {
        printf("The notes form a legal triad.\n");
    } else {
        printf("The notes do not form a legal triad.\n");
    }

    return 0;
}