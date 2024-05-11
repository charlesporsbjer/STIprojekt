#include <stdio.h>
#include <string.h>

int isLegalTriad(char* note1, char* note2, char* note3) {
    char* naturalNotes[] = {"A", "B", "C", "D", "E", "F", "G"};
    int note1Index = -1, note2Index = -1, note3Index = -1;

    for(int i = 0; i < 7; i++) {
        if(strcmp(note1, naturalNotes[i]) == 0) {
            note1Index = i;
        }
        if(strcmp(note2, naturalNotes[i]) == 0) {
            note2Index = i;
        }
        if(strcmp(note3, naturalNotes[i]) == 0) {
            note3Index = i;
        }
    }

    if(note1Index == -1 || note2Index == -1 || note3Index == -1) {
        return 0;
    }

    int interval1 = (note2Index - note1Index + 7) % 7;
    int interval2 = (note3Index - note2Index + 7) % 7;

    if(interval1 == 2 && interval2 == 2) {
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