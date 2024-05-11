#include "game.h"
#include "buttons.h"
#include "LED.h"
#include "LCD.h"

void setup() {
    setupLCD();
    pinSetup();
    setupButtons();
    initializeBoard();
}

const unsigned long gameOverDelay = 3000;
unsigned long lastGameOverTime = 0;

// Sample game.
void loop() {
currentTime = millis();

    if (firstRound) {
        initializeBoard();
        updateLEDs();
        printLCD("Player: %c", currentPlayer);
        firstRound = 0;
        win = 0;
    }

    // Blink the 'O' LEDs.
    blinkLEDforO();
    if (!win)
        blinkLEDforCursor();
    
    //updateLEDs();
    if (!gameOverFlag)
        moveMade = cursor();
    
    if (moveMade) {
        updateLEDs();
        win = lookForWin();
        if (win == 1 || win == 2) { 
            gameOverFlag = 1;
            gameOverStartTime = millis();
            moveMade = 0;
        } else {
            // Switch player after a successful move.
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            printLCD("Player: %c", currentPlayer);
        }
    }

    // Check if it's time to reset after game over.
    if (gameOverFlag == 1 && millis() - gameOverStartTime > gameOverDelay) {
        // Reset the game state
        if (win != 2)
            checkWinner();
        firstRound = 1;
        gameOverFlag = 0; 
        moveMade = 0;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}