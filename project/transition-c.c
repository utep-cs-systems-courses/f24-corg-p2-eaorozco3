#include <msp430.h>
#include "switch.h"
#include "state_machines.h"

void first_transition() {
  (firstSw_transition >= 2) ? firstSw_transition = 1 : firstSw_transition++;
}

void second_transition() {
  (secondSw_transition >= 3) ? secondSw_transition = 1 : secondSw_transition++;
}

void third_transition() {
  (thirdSw_transition >= 3) ? thirdSw_transition = 1 : thirdSw_transition++; 
}

void fourth_transition() {
  (fourthSw_transition >= 7) ? fourthSw_transition = 1 : fourthSw_transition++;
}
