#include <msp430.h>
#include "libTimer.h"
#include "switch.h"
#include "state_machines.h"
#include "led.h"
#include "buzzer.h"

static char switch_update_interrupt_sense() {
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init() {
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
}

unsigned char selector = 0;

unsigned char firstSw_transition = 0;
unsigned char secondSw_transition = 0;
unsigned char thirdSw_transition = 0;
unsigned char fourthSw_transition = 0;

void switch_interrupt_handler() {
  char p2val = switch_update_interrupt_sense();
  
  if(!(p2val & S1)) {
    selector = 1;
    first_transition();
  }

  if(!(p2val & S2)) {
    selector = 2;
    second_transition();
  }

  if(!(p2val & S3)) {
    selector = 3;
    third_transition();
  }

  if(!(p2val & S4)) {
    selector = 4;
    fourth_transition();
  }
}

void __interrupt_vec(WDT_VECTOR) WDT() {
  secCount++;
  switch(selector) {
  case 1:
    buzzer_set_period(0);
    switch(firstSw_transition) {
    case 1:
      light_pattern();
      break;
    case 2:
      P1OUT &= ~LEDS;
      break;
    default:
      break;
    }
    
    break;
    
  case 2:
    P1OUT &= ~LEDS;
    switch(secondSw_transition) {
    case 1:
      sound_pattern();
      break;
    case 2:
      light_pattern();
      sound_pattern();
      break;
    case 3:
      P1OUT &= ~LEDS;
      buzzer_set_period(0);
      break;
    default:
      break;
    }

    break;

  case 3:
    buzzer_set_period(0);
    switch(thirdSw_transition) {
    case 1:
      P1OUT ^= LED_GREEN;
      buzzer_set_period(500);
      break;
    case 2:
      P1OUT ^= LED_RED;
      buzzer_set_period(1000);
      break;
    case 3:
      P1OUT &= ~LEDS;
      buzzer_set_period(0);
      break;
    default:
      break;
    }
   
  case 4:
    switch(fourthSw_transition) {
    case 1:
      flicker_green(0);
      break;
    case 2:
      flicker_green(1);
      break;
    case 3:
      flicker_red(0);
      break;
    case 4:
      flicker_red(1);
      break;
    case 5:
      flicker_all(0);
      break;
    case 6:
      flicker_all(1);
      break;
    case 7:
      P1OUT &= ~LEDS;
      buzzer_set_period(0);
      break;
    default:
      break;
    }
    
    break;
    
  default:
    break;
  }
}
