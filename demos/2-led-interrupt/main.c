//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}

unsigned char wcount = 0;

everySecond() {
  static unsigned char led_on = 0;
  led_on = !led_on;
  if(led_on) {
    P1OUT |= LED_GREEN;
  }

  else {P1OUT &= ~LED_GREEN;}
}

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  wcount++;
  if(wcount == 250) {
    everySecond();
    wcount = 0;
  }
} 

