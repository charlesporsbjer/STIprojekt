#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Board {
    char xy[BOARD_SIZE][BOARD_SIZE];
} Board;


// Clears input buffer for scanf in makeMove.
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

// Returns board pointer mapped with 1-9 and allocates memory for it.
Board* createBoard() {
    Board* board = (Board*)malloc(sizeof(Board));
    if (board == NULL) {
        return NULL;
    }
    char initialValue = '1';
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->xy[i][j] = initialValue++;
        }
    }
    return board;
}

// Prints board.
void printBoard(Board* board) {
    printf("+-----------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("| %c ", board->xy[i][j]);
        }
        printf("|\n");
        if (i < BOARD_SIZE - 1) {
            printf("|---|---|---|\n");
        }
    }
    printf("+-----------+\n");
}

// Handles user input and updates board.
void makeMove(Board* board, char player) {
    int input;
    printf("Pick a square (1-9): \n");
    printBoard(board);
    if (scanf("%d", &input) != 1) {
        printf("Invalid input. \n");
        clearInputBuffer();
        return makeMove(board, player);
    }
    clearInputBuffer();
    
    int row = (input - 1) / BOARD_SIZE;
    int col = (input - 1) % BOARD_SIZE;
    if (input < 1 || input > 9 || board->xy[row][col] == 'X' || board->xy[row][col] == 'O') {
        printf("Invalid move. Try again.\n");
        return makeMove(board, player);
    }

    board->xy[row][col] = player;
}

// Looks for winner. Returns X/O if winner, 0 if no winner yet.
char lookForWin(Board* board) {
    // Check rows and columns for a win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->xy[i][0] == board->xy[i][1] && board->xy[i][1] == board->xy[i][2]) {
            printf("Winner is player %c\n", board->xy[i][0]);
            return board->xy[i][0];
        }
        if (board->xy[0][i] == board->xy[1][i] && board->xy[1][i] == board->xy[2][i]) {
            printf("Winner is player %c\n", board->xy[0][i]);
            return board->xy[0][i];
        }
    }

    // Check diagonals for a win
    if (board->xy[0][0] == board->xy[1][1] && board->xy[1][1] == board->xy[2][2]) {
        printf("Winner is player %c\n", board->xy[0][0]);
        return board->xy[0][0];
    }
    if (board->xy[0][2] == board->xy[1][1] && board->xy[1][1] == board->xy[2][0]) {
        printf("Winner is player %c\n", board->xy[0][2]);
        return board->xy[0][2];
    }

    // No winner yet
    return '0';
}

// Runs game and alternates player.
void runGame(Board* board) {
    char currentPlayer = 'X';
    while (1) {
        printf("Player %c's move:\n", currentPlayer);
        makeMove(board, currentPlayer);
        char winner = lookForWin(board);
        if (winner == 'X' || winner == 'O') {
            printBoard(board);
            return;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}


// Sample game.
int main() {
    
    Board* board = createBoard();
    
    runGame(board);

    free(board);
}