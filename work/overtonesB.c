#include <stdio.h>

int main() {
    double note;
    int n = 5;
    char* intervals[] = {"octave", "perfect fifth above octave", "second octave", "major third above second octave", "perfect fifth above second octave"};

    printf("Enter the frequency of the note (in Hz): ");
    scanf("%lf", &note);

    printf("The first %d overtones of %lf Hz are:\n", n, note);

    for(int i = 0; i < n; i++) {
        printf("%-30s: %6.2lf Hz\n", intervals[i], note * (i+2));
    }

    return 0;
}