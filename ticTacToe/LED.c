#include "LED.h"


// Initializes LED pins as OUTPUT.
void pinSetup() {
    for (uint8_t i = 0; i < BOARD_SIZE; i++) {
        for (uint8_t j = 0; j < BOARD_SIZE; j++) {
        pinMode(ledPins[i][j], OUTPUT);
        }
    }
}

// Handles blinking for player 'O'.
void blinkLEDforO() {
    currentTime = millis();
    for (uint8_t i = 0; i < BOARD_SIZE; i++) {
        for (uint8_t j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'O') {
                if (currentTime - lastToggleTime[i][j] >= blinkInterval) {
                    ledStates[i][j] = !ledStates[i][j]; 
                    digitalWrite(ledPins[i][j], ledStates[i][j] ? HIGH : LOW);
                    lastToggleTime[i][j] = currentTime; 
                }        
            }
        }
    }
}

// Handles blinking for cursor.
void blinkLEDforCursor() {
    currentTime = millis();

    if (currentTime - lastToggleTime[currentRow][currentCol] >= blinkIntervalCursor) {
        ledStates[currentRow][currentCol] = !ledStates[currentRow][currentCol]; 
        digitalWrite(ledPins[currentRow][currentCol], ledStates[currentRow][currentCol] ? HIGH : LOW);
        lastToggleTime[currentRow][currentCol] = currentTime; 
    }        
}

// Handless LEDs that do not blink.
void updateLEDs() {
    currentTime = millis();
    for (uint8_t i = 0; i < BOARD_SIZE; i++) {
        for (uint8_t j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'X') {
                digitalWrite(ledPins[i][j], HIGH); // Turn on the LED for 'X'.
                ledStates[i][j] = 1;
            }
            else {
                if (board[i][j] != board[currentRow][currentCol])
                    digitalWrite(ledPins[i][j], LOW); // Turn off the LED for numbers 1-9.
            }
        }
    }
}
