#include <msp430.h>
#include "switch.h"

void __interrupt_vec(PORT2_VECTOR) PORT2() {
  if(P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}
