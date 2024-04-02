#ifndef BUTTONS_H
#define BUTTONS_H

#include "game.h"

// Declarations.
const uint8_t buttonPin1 = 17; // Marks X or O.
const uint8_t buttonPin2 = 18; // Changes LED.
const uint8_t buttonPin3 = 19; // Displays scores.
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;

// Set button pins as input with pullup.
void setupButtons();

// Manage different button presses.
uint8_t debounceButton(int buttonPin, unsigned long *lastPressTime);

// Changes to the next LED.
void changeLED();

// Handles cursor mechanics.
uint8_t cursor();

#endif