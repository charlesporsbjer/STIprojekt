#include <stdio.h>

int main() {
    double fundamentalFrequency;
    int numberOfOvertones = 10; // Change this to calculate more or fewer overtones

    // Prompt the user to enter the fundamental frequency
    printf("Enter the fundamental frequency in Hz: ");
    scanf("%lf", &fundamentalFrequency);

    // Calculate and display the overtones
    printf("The first %d overtones are:\n", numberOfOvertones);
    for (int i = 1; i <= numberOfOvertones; i++) {
        double overtoneFrequency = fundamentalFrequency * i;
        printf("Overtone %d: %.2f Hz\n", i, overtoneFrequency);
    }

    return 0;
}