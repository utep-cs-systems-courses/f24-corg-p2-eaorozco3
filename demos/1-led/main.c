//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  // Surgically turn on the red LED.
  P1OUT |= LED_RED;
  // Surgically turn on the green LED.
  P1OUT |= LED_GREEN;
  // Surgically turn off the red LED.
  P1OUT &= ~LED_RED;
  // Surgically turn off the green LED.
  P1OUT &= ~LED_GREEN;
  // Surgically turn on the red LED.
  P1OUT |= LED_RED;
  or_sr(0x18);		/* CPU off, GIE on */
}
