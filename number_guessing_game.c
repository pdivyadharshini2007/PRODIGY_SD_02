#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playGame() {
    int lower = 1, upper = 100;
    int secretNumber = (rand() % (upper - lower + 1)) + lower;
    int guess, attempts = 0;

    printf("I'm thinking of a number between %d and %d.\n", lower, upper);

    while (1) {
        printf("Enter your guess: ");

        if (scanf("%d", &guess) != 1) {
            printf("That's not a valid number. Try again.\n");
            // clear bad input from the buffer
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        if (guess < lower || guess > upper) {
            printf("Please guess a number between %d and %d.\n", lower, upper);
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("\nCorrect! The number was %d.\n", secretNumber);
            printf("You guessed it in %d attempts.\n", attempts);
            break;
        }
    }

    return attempts;
}

int main() {
    char playAgain = 'y';

    srand((unsigned int)time(NULL));

    printf("========================================\n");
    printf("Welcome to the Number Guessing Game!\n");
    printf("========================================\n");

    while (playAgain == 'y' || playAgain == 'Y') {
        playGame();
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("Thanks for playing!\n");
    return 0;
}
