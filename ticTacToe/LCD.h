#ifndef LCD_H
#define LCD_H

#include "game.h"
#include <LiquidCrystal.h>

// Declare LCD variable.
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // RS, EN, D4, D5, D6, D7

// Sets up LCD.
void setupLCD();

// Shortens printing to the LCD. Second argument is for player.
void printLCD(const char* format, char c);

// Prints scores to LCD.
void showScores();

#endif