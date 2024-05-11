#include <stdio.h>
#include <string.h>

int isLegalTriad(char* note1, char* note2, char* note3) {
    char* naturalNotes[] = {"A", "B", "C", "D", "E", "F", "G"};
    char* note1Accidental = strchr(note1, '#') ? "#" : strchr(note1, 'b') ? "b" : "";
    char* note2Accidental = strchr(note2, '#') ? "#" : strchr(note2, 'b') ? "b" : "";
    char* note3Accidental = strchr(note3, '#') ? "#" : strchr(note3, 'b') ? "b" : "";

    char note1Base[2] = {note1[0], '\0'};
    char note2Base[2] = {note2[0], '\0'};
    char note3Base[2] = {note3[0], '\0'};

    int note1Index = -1, note2Index = -1, note3Index = -1;

    for(int i = 0; i < 7; i++) {
        if(strcmp(note1Base, naturalNotes[i]) == 0) {
            note1Index = i;
        }
        if(strcmp(note2Base, naturalNotes[i]) == 0) {
            note2Index = i;
        }
        if(strcmp(note3Base, naturalNotes[i]) == 0) {
            note3Index = i;
        }
    }

    if(note1Index == -1 || note2Index == -1 || note3Index == -1) {
        return 0;
    }

    if((note2Index - note1Index) % 7 == 2 && (note3Index - note2Index) % 7 == 2) {
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