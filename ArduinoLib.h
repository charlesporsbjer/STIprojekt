#ifndef ArduinoLib_H
#define ArduinoLib_h

#include <avr/io.h>

#ifdef __cplusplus
extern "C" {
#endif

// Function prototypes

/**
 * Initializes an LED connected to a specific port and pin.
 * This function will set the pin as an output.
 * 
 * @param port The port register (e.g., &PORTB for port B)
 * @param ddr The data direction register for the port (e.g., &DDRB for port B)
 * @param pin The pin number (0-7) within the port
 */
void initLED(volatile uint8_t* port, volatile uint8_t* ddr, uint8_t pin);

/**
 * Turns the LED on.
 * 
 * @param port The port register where the LED is connected
 * @param pin The pin number (0-7) within the port
 */
void turnLEDOn(volatile uint8_t* port, uint8_t pin);

/**
 * Turns the LED off.
 * 
 * @param port The port register where the LED is connected
 * @param pin The pin number (0-7) within the port
 */
void turnLEDOff(volatile uint8_t* port, uint8_t pin);

/**
 * Toggles the LED state.
 * 
 * @param pin The pin number (0-7) within the port
 * @param port The port input register (e.g., &PINB for port B) used for toggling
 */
void toggleLED(volatile uint8_t* port, uint8_t pin);

#ifdef __cplusplus
}
#endif

#endif /* ExampleLibrary_h */