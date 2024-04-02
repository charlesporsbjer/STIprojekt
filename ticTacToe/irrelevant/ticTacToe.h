#ifndef TICTACTOE_H
#define TICTACTOE_H

/*
HOW TO USE:
    Board* board = createBoard();

    runGame(board);

    free(board);

USEFUL FUNCTIONS FOR USER:
    createBoard
    printBoard
    runGame
*/

#define BOARD_SIZE 3

// Struct isn't strictly neccessary for the code to work.
typedef struct Board {
    char xy[BOARD_SIZE][BOARD_SIZE];
} Board;

// Helper function for scanf inside makeMove.
void clearInputBuffer();

// Use this to create a board pointer.
Board* createBoard();

// Helper function for runGame.
void printBoard(Board* board);

// Helper function for runGame.
void makeMove(Board* board, char player);

// Helper function for runGame.
char lookForWin(Board* board);

// Runs the game.
void runGame(Board* board);

#endif