#ifndef switch_included
#define switch_included
#include <msp430.h>

#define S1 BIT0
#define S2 BIT1
#define S3 BIT2
#define S4 BIT3

#define SWITCHES (S1 | S2 | S3 | S4)

unsigned char selector;
unsigned char firstSw_transition;
unsigned char secondSw_transition;
unsigned char thirdSw_transition;
unsigned char fourthSw_transition;
static char switch_update_interrupt_sense();
void switch_init();
void switch_interrupt_handler();

#endif
