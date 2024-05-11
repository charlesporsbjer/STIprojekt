#ifndef GAME_H
#define GAME_H

#include <stdint.h>

#define BOARD_SIZE 3

// Declarations. 
char board[BOARD_SIZE][BOARD_SIZE];
uint8_t currentRow = 0;
uint8_t currentCol = 0;
char currentPlayer = 'X';
uint8_t win = 0;
uint8_t moveMade = 0;
static uint8_t firstRound = 1;
unsigned long currentTime = 0;
uint8_t gameOverFlag = 0; // Flag to indicate the game is over. 0: Game ongoing, 1: Game over
unsigned long gameOverStartTime = 0; // Time when the game was over
uint8_t winCounterX = 0;
uint8_t winCounterO = 0;
char winner;

// Returns board pointer mapped with 1-9.
void initializeBoard();

// Checks if board is full.
uint8_t lookForFull();

// Checks win and updates win counter.
void checkWinner();

// Looks for win. Returns X/O if win, 0 if no win yet.
uint8_t lookForWin();

#endif