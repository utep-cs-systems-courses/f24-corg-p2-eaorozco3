#include <msp430.h>
#include "timerLib/libTimer.h"
#include "led.h"
#include "switch.h"

void led_init() {
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;
}
