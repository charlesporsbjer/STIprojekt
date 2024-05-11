#include <LiquidCrystal.h>

#include <stdint.h>

#define BOARD_SIZE 3


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


// LED SECTION

const uint8_t ledPins[BOARD_SIZE][BOARD_SIZE] = {
    {13, 12, 11},
    {10, 9, 8},
    {16, 15, 14}};
const unsigned long blinkInterval = 150; // 'O' LED.
const unsigned long blinkIntervalCursor = 750; // Cursor LED. 
uint8_t ledStates[BOARD_SIZE][BOARD_SIZE] = {0}; // Tracks the current state (on/off) of each LED
unsigned long lastToggleTime[BOARD_SIZE][BOARD_SIZE] = {0}; // Tracks last toggle time for each LED

// Initializes LED pins as OUTPUT.
void pinSetup() {
    for (uint8_t i = 0; i < BOARD_SIZE; i++) {
        for (uint8_t j = 0; j < BOARD_SIZE; j++) {
        pinMode(ledPins[i][j], OUTPUT);
        }
    }
}

void blinkLEDforO() {
    currentTime = millis();
    for (uint8_t i = 0; i < BOARD_SIZE; i++) {
        for (uint8_t j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'O') {
                if (currentTime - lastToggleTime[i][j] >= blinkInterval) {
                    ledStates[i][j] = !ledStates[i][j]; // Toggle state
                    digitalWrite(ledPins[i][j], ledStates[i][j] ? HIGH : LOW);
                    lastToggleTime[i][j] = currentTime; // Update last toggle time
                }        
            }
        }
    }
}

void blinkLEDforCursor() {
    currentTime = millis();

    if (currentTime - lastToggleTime[currentRow][currentCol] >= blinkIntervalCursor) {
        ledStates[currentRow][currentCol] = !ledStates[currentRow][currentCol]; // Toggle state
        digitalWrite(ledPins[currentRow][currentCol], ledStates[currentRow][currentCol] ? HIGH : LOW);
        lastToggleTime[currentRow][currentCol] = currentTime; // Update last toggle time
    }        
}

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


// BUTTON SECTION

const uint8_t buttonPin1 = 17; // Marks X or O.
const uint8_t buttonPin2 = 18; // Changes LED.
const uint8_t buttonPin3 = 19; // Displays scores.

void setupButtons() {
  	// Set button pins as input
  	pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
    pinMode(buttonPin3, INPUT_PULLUP);
}

// Function to manage button presses, distinguishing between single, hold, and rapid successive presses.
uint8_t debounceButton(int buttonPin, unsigned long *lastPressTime) {
    static uint8_t lastButtonState = HIGH; // Last state of the button
    static uint8_t buttonPressed = 0; // Whether the button has been pressed (action taken)
    const unsigned long debounceDelay = 15; // Short delay to debounce
    const unsigned long holdThreshold = 500; // Threshold to differentiate between press and hold
    const unsigned long rapidPressInterval = 50; // Allow rapid presses within this interval

    uint8_t currentButtonState = digitalRead(buttonPin);
    unsigned long currentTime = millis();
    uint8_t actionTaken = 0;

    // Button state change detection (rising or falling edge)
    if (currentButtonState != lastButtonState) {
        if (currentTime - *lastPressTime > debounceDelay) {
            // Button press recognized
            if (currentButtonState == LOW && !buttonPressed) {
                // Check if it's a rapid successive press or a new single press
                if (currentTime - *lastPressTime > rapidPressInterval) {
                    // This is considered a new press, or a rapid press distinct from the previous
                    actionTaken = 1;
                }
                buttonPressed = 1; // Mark that the button press action has been taken
                *lastPressTime = currentTime; // Update the last press time
            }
            else if (currentButtonState == HIGH && buttonPressed) {
                // Button release recognized, reset the button press state if it was previously pressed
                buttonPressed = 0;
            }
        }
    }
    
    // Extend the press interval if it's considered a hold
    if (buttonPressed && (currentTime - *lastPressTime > holdThreshold)) {
        // Holding the button, so extend the interval before recognizing another action
        *lastPressTime = currentTime - rapidPressInterval + debounceDelay; // Prepare for next rapid press
    }

    lastButtonState = currentButtonState; // Update last button state for next check
    return actionTaken;
}

unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;

void changeLED() {
    win = lookForWin();
    if (!win) {
        uint8_t foundEmptySpot = 0;

        // Attempt to move right from the current position, wrapping to the next row if at the end of a row.
        int startRow = currentRow;
        int startCol = currentCol + 1;
        if (startCol >= BOARD_SIZE) {
            startCol = 0; // Wrap to the start of the next row
            startRow = (startRow + 1) % BOARD_SIZE; // Move to the next row, wrapping around if necessary
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
            if (i == BOARD_SIZE - 1 && !foundEmptySpot) { // If end of board is reached, start from the beginning
                i = -1; // This will become 0 at the next iteration of the loop
            }
        }
        updateLEDs();
    }
}

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


// LCD SECTION

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // RS, EN, D4, D5, D6, D7

void setupLCD() {
    lcd.begin(16, 2);
}

// Shortens printing to the LCD. Second argument is for player.
void printLCD(const char* format, char c) {
    char buffer[32];
    if (c != 0) {
        snprintf(buffer, sizeof(buffer), format, c);
    } else {
        snprintf(buffer, sizeof(buffer), "%s", format);
    }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(buffer);
}

void showScores() {
    lcd.setCursor(0,1);
    lcd.print("Wins: ");
    lcd.print("X: ");
    lcd.print(winCounterX);
    lcd.print(" O: ");
    lcd.print(winCounterO);
}

// GAME SECTION

// Returns board pointer mapped with 1-9.
void initializeBoard() {
    char initialValue = '1';
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = initialValue++;
        }
    }
}

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

// Checks win for win counter.
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

// MAIN SECTION

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

    // Check if it's time to reset after game over
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