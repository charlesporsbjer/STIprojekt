#include "LCD.h"

// Sets up LCD.
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

// Prints scores to LCD.
void showScores() {
    lcd.setCursor(0,1);
    lcd.print("Wins: ");
    lcd.print("X:");
    lcd.print(winCounterX);
    lcd.print(" O:");
    lcd.print(winCounterO);
}