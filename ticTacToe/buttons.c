#include "buttons.h"

// Set button pins as input with pullup.
void setupButtons() {
  	pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
    pinMode(buttonPin3, INPUT_PULLUP);
}

// Manage different button presses.
uint8_t debounceButton(int buttonPin, unsigned long *lastPressTime) {
    static uint8_t lastButtonState = HIGH; 
    static uint8_t buttonPressed = 0; 
    const unsigned long debounceDelay = 15; 
    const unsigned long holdThreshold = 500;
    const unsigned long rapidPressInterval = 50;

    uint8_t currentButtonState = digitalRead(buttonPin);
    unsigned long currentTime = millis();
    uint8_t actionTaken = 0;

    // Button change detection.
    if (currentButtonState != lastButtonState) {
        if (currentTime - *lastPressTime > debounceDelay) {
            if (currentButtonState == LOW && !buttonPressed) {
                // Check if rapid successive press or new press.
                if (currentTime - *lastPressTime > rapidPressInterval) {
                    actionTaken = 1;
                }
                buttonPressed = 1;
                *lastPressTime = currentTime;
            }
            else if (currentButtonState == HIGH && buttonPressed) {
                buttonPressed = 0;
            }
        }
    }
    
    // Extend press interval if held.
    if (buttonPressed && (currentTime - *lastPressTime > holdThreshold)) {
        *lastPressTime = currentTime - rapidPressInterval + debounceDelay; 
    }

    lastButtonState = currentButtonState;
    return actionTaken;
}

// Changes to the next LED.
void changeLED() {
    win = lookForWin();
    if (!win) {
        uint8_t foundEmptySpot = 0;

        int startRow = currentRow;
        int startCol = currentCol + 1;
        if (startCol >= BOARD_SIZE) {
            startCol = 0; // Wrap tostart of next row.
            startRow = (startRow + 1) % BOARD_SIZE; // Move to next row, wrap around if necessary.
        }

        for (int i = startRow; !foundEmptySpot && i < BOARD_SIZE; i++) {
            for (int j = (i == startRow ? startCol : 0); j < BOARD_SIZE; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    currentRow = i;
                    currentCol = j;
                    foundEmptySpot = 1;
                    break;
                }
            }
            if (foundEmptySpot) break;
            if (i == BOARD_SIZE - 1 && !foundEmptySpot) { // If end of board reached, start from beginning.
                i = -1;
            }
        }
        updateLEDs();
    }
}

// Handles cursor mechanics.
uint8_t cursor() {
	currentTime = millis();
    uint8_t moveMade = 0;

    if (board[currentRow][currentCol] == 'X' || board[currentRow][currentCol] == 'O')
        changeLED();
        
    blinkLEDforCursor();

    // Button 1: Mark X or O.
    if (debounceButton(buttonPin1, &lastDebounceTime1)) {
        if (board[currentRow][currentCol] != 'X' && board[currentRow][currentCol] != 'O') {
            board[currentRow][currentCol] = currentPlayer;
            moveMade = 1;
            changeLED();
        }
        
    }
    // Button 2: Change LED.
    if (debounceButton(buttonPin2, &lastDebounceTime2)) {
        changeLED();
    }

    
    // Button 3: Display score.
    if (debounceButton(buttonPin3, &lastDebounceTime3)) {
        showScores();
    }
    return moveMade;
}
