#include "game.h"

// Returns board pointer mapped with 1-9.
void initializeBoard() {
    char initialValue = '1';
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = initialValue++;
        }
    }
}

// Checks if board is full.
uint8_t lookForFull() {
    uint8_t slotsTaken = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O')
                slotsTaken++;
        }
    }
    if (slotsTaken == 9) {
        printLCD("It's a draw.", ' ');
        return 1;
    }
    return 0;
}

// Checks win and updates win counter.
void checkWinner() {
    if (winner == 'X') {
    winCounterX++;
    }
    else if (winner == 'O') {
        winCounterO++;
    }
}

// Looks for win. Returns X/O if win, 0 if no win yet.
uint8_t lookForWin() {
    // Check rows and columns for a win.
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            printLCD("Winner: %c", board[i][0]);
            winner = board[i][0];
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            printLCD("Winner: %c", board[0][i]);
            winner = board[0][i];
            return 1;
        }
    }

    // Check diagonals for a win.
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        printLCD("Winner: %c", board[0][0]);
        winner = board[0][0];
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        printLCD("Winner: %c", board[0][2]);
        winner = board[0][2];
        return 1;
    }
    
    // No win yet, see if board is full.
    if (lookForFull())
        return 2;
    return 0;
}
