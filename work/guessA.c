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
    printf("Choose your difficulty:\n");
    printf("1. Easy: 10 attempts\n");
    printf("2. Medium: 7 attempts\n");
    printf("3. Hard: 5 attempts\n");
    printf("Enter your choice (1-3): ");
    int difficulty;
    scanf("%d", &difficulty);

    switch(difficulty) {
        case 1:
            max_attempts = 10;
            break;
        case 2:
            max_attempts = 7;
            break;
        case 3:
            max_attempts = 5;
            break;
        default:
            printf("Invalid choice. Using Easy mode.\n");
            max_attempts = 10;
            break;
    }

    do {
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
        }
    } while (guess != number && attempts < max_attempts);

    if (attempts == max_attempts) {
        printf("You ran out of attempts. The number was %d.\n", number);
    }

    return 0;
}