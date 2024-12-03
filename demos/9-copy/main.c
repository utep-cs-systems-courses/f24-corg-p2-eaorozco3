#include <msp430.h>
#include "libTimer.h"

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (LED_RED | LED_GREEN)

#define S1 1		        /* switch1 is p1.3 */
#define S2 2
#define S3 4
#define S4 8
#define SWITCHES (S1 | S2 | S3 | S4)		/* only 1 switch on this board */

void switch_init() {
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
}

void led_init() {
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;		/* leds initially off */
}

void wdt_init() {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
}

void main(void) 
{  
  switch_init();
  led_init();
  wdt_init();
    
  or_sr(0x18);  // CPU off, GIE on
} 

void
switch_interrupt_handler()
{
  static unsigned char alternate = 0;
  char p2val = P2IN;		/* switch is in P1 */

/* update switch interrupt sense to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */

  if (!(p2val & S1)) {		/* button up */
    P1OUT |= LED_GREEN;
    alternate = ~alternate;
  }

  else if(!(p2val & S2)) {
    P1OUT |= LED_RED;
    alternate = ~alternate;
  }

  else if(!(p2val & S4)) {
    P1OUT |= LEDS;
    alternate = ~alternate;
  }

  if(alternate) {			/* button down */
    P1OUT &= ~LEDS;
  }
}


/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  static int blink_count = 0;
  switch (blink_count) { 
  case 6: 
    blink_count = 0;
    //P1OUT |= LED_RED;
    break;
  default:
    blink_count ++; /* don't blink off if button is down */
  }
} 
