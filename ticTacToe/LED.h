#ifndef LED_H
#define LED_H

#include "game.h"

#define BOARD_SIZE 3

// Declarations.
const uint8_t ledPins[BOARD_SIZE][BOARD_SIZE] = {
    {13, 12, 11},
    {10, 9, 8},
    {16, 15, 14}};
const unsigned long blinkInterval = 150; // 'O' LED.
const unsigned long blinkIntervalCursor = 750; // Cursor LED. 
uint8_t ledStates[BOARD_SIZE][BOARD_SIZE] = {0}; // Tracks (on/off) for each LED.
unsigned long lastToggleTime[BOARD_SIZE][BOARD_SIZE] = {0};

// Initializes LED pins as OUTPUT.
void pinSetup();

// Handles blinking for player 'O'.
void blinkLEDforO();

// Handles blinking for cursor.
void blinkLEDforCursor();

// Handless LEDs that do not blink.
void updateLEDs();


#endif