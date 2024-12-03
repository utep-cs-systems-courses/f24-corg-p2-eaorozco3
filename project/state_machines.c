#include <msp430.h>
#include "led.h"
#include "switch.h"
#include "buzzer.h"

int secCount = 0;

void light_pattern() {
   if(secCount >= 0 & secCount < 125) {
     P1OUT |= LED_GREEN;
   }

   else if(secCount >= 125 & secCount < 250) {
     P1OUT &= ~LED_GREEN;
     P1OUT |= LED_RED;
   }

   else if(secCount >= 250 & secCount < 375) {
     P1OUT |= LEDS;
   }

   else if(secCount >= 375 & secCount < 438) {
     P1OUT &= ~LEDS;
   }

   else if(secCount >= 438 & secCount < 500) {
     P1OUT |= LED_RED;
   }

   else if(secCount >= 500 & secCount < 563) {
     P1OUT &= ~LED_RED;
     P1OUT |= LED_GREEN;
   }

   else if(secCount >= 563 & secCount < 626) {
     P1OUT &= ~LED_GREEN;
     P1OUT |= LED_RED;
   }

   else if(secCount >= 626 & secCount < 689) {
     P1OUT &= ~LED_RED;
     P1OUT |= LED_GREEN;
   }

   else if(secCount >= 689 & secCount < 750) {
     P1OUT &= ~LED_GREEN;
     P1OUT |= LED_RED;
   }

   else if(secCount >= 750 & secCount < 875) {
     P1OUT &= ~LED_RED;
     P1OUT |= LED_GREEN;
   }

   else if(secCount >= 875 & secCount < 1000) {
     P1OUT &= ~LED_GREEN;
     P1OUT |= LED_RED;
   }

   else if(secCount >= 1000 & secCount < 1250) {
     P1OUT &= ~LEDS;
   }

   else if(secCount >= 1250) {
     secCount = 0;
   }
}

void sound_pattern() {
  if(secCount >= 0 & secCount < 125) {
    buzzer_set_period(1000);
  }

  else if(secCount >= 125 & secCount < 250) {
    buzzer_set_period(750);
  }

  else if(secCount >= 250 & secCount < 375) {
    buzzer_set_period(500);
  }

  else if(secCount >= 375 & secCount < 438) {
    buzzer_set_period(1250);
  }

  else if(secCount >= 438 & secCount < 500) {
    buzzer_set_period(800);
  }

  else if(secCount >= 500 & secCount < 563) {
    buzzer_set_period(1000);
  }

  else if(secCount >= 563 & secCount < 626) {
    buzzer_set_period(750);
  }

  else if(secCount >= 626 & secCount < 689) {
    buzzer_set_period(1000);
  }

  else if(secCount >= 689 & secCount < 750) {
    buzzer_set_period(750);
  }

  else if(secCount >= 750 & secCount < 875) {
    buzzer_set_period(1000);
  }

  else if(secCount >= 875 & secCount < 1000) {
    buzzer_set_period(750);
  }

  else if(secCount >= 1000 & secCount < 1250) {
    buzzer_set_period(0);
  }

  else if(secCount >= 1250) {
    secCount = 0;
  }
}

static char blinkLimit = 5;
static char blinkCount = 0;
static short highToLow = 250;
static short lowToHigh = 2000;

void bright_to_dim() {
  if(secCount >= 250) {
    secCount = 0;
    buzzer_set_period(highToLow);
    highToLow += 250;
    blinkLimit++;
    if(blinkLimit >= 8) {
      blinkLimit = 0;
      highToLow = 250;
    }
  }
}

void dim_to_bright() {
  if(secCount >= 250) {
    secCount = 0;
    buzzer_set_period(lowToHigh);
    lowToHigh -= 250;
    blinkLimit--;
    if(blinkLimit <= 0) {
      blinkLimit = 8;
      lowToHigh = 2000;
    }
  }
}

void flicker_green(char toggle) {
  blinkCount++;
  if(blinkCount >= blinkLimit) {
    blinkCount = 0;
    P1OUT |= LED_GREEN;
  }

  else {P1OUT &= ~LED_GREEN;}
  if(!toggle) {bright_to_dim();}
  else {dim_to_bright();}
}

void flicker_red(char toggle) {
  blinkCount++;
  if(blinkCount >= blinkLimit) {
    blinkCount = 0;
    P1OUT |= LED_RED;
  }

  else {P1OUT &= ~LED_RED;}
  if(!toggle) {bright_to_dim();}
  else {dim_to_bright();}
}

void flicker_all(char toggle) {
  blinkCount++;
  if(blinkCount >= blinkLimit) {
    blinkCount = 0;
    P1OUT |= LEDS;
  }

  else {P1OUT &= ~LEDS;}
  if(!toggle) {bright_to_dim();}
  else {dim_to_bright();}
}
