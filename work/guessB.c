#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed random number generator
    int number = rand() % 500 + 1; // generate random number between 1 and 500
    int guess;
    int attempts = 0;
    int max_attempts;

    printf("Welcome to the guessing game!\n");
    printf("I'm thinking of a number between 1 and 500.\n");
    printf("Choose your difficulty level:\n");
    printf("1. Easy (10 attempts)\n");
    printf("2. Medium (8 attempts)\n");
    printf("3. Hard (6 attempts)\n");
    printf("Enter your choice (1-3): ");
    int difficulty;
    scanf("%d", &difficulty);

    switch(difficulty) {
        case 1: // Easy
            max_attempts = 10;
            break;
        case 2: // Medium
            max_attempts = 8;
            break;
        case 3: // Hard
            max_attempts = 6;
            break;
        default:
            printf("Invalid difficulty level. Choose 1, 2, or 3.\n");
            return 1;
    }

    while(attempts < max_attempts) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        printf("Attempts left: %d\n", max_attempts - attempts);

        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You found the number in %d attempts.\n", attempts);
            return 0;
        }
    }

    printf("Sorry, you didn't guess the number in %d attempts.\n", max_attempts);
    printf("The number was %d.\n", number);

    return 0;
}