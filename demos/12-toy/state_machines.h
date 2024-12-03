#include <msp430.h>

int secCount;
void first_transition();
void second_transition();
void fourth_transition();
void light_pattern();
void sound_pattern();
static char blinkLimit;
static char blinkCount;
static short highToLow;
static short lowToHigh;
void bright_to_dim();
void dim_to_bright();
void flicker_green(char toggle);
void flicker_red(char toggle);
void flicker_all(char toggle);
