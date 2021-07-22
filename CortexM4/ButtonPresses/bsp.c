#include "bsp.h"

void setup()
{
    SYSCTL->RCGC2    = 0x20;                                                    // enable port f
    GPIOF->LOCK      = 0x4C4F434B;                                              // unlock CC
    GPIOF->CR        = 0xFF;                                                    // enable pullup resistors
    GPIOF->DIR       = 0x0E;                                                    // enable output direction on port 7
    GPIOF->DEN       = 0x1F;                                                    // digital enable
    GPIOF->PUR       = 0x11;                                                    // set pullup resistors

    GPIOF->DATA &= ~(LED_RED | LED_GREEN | LED_BLUE);
}


void checkForPress()
{
    switch(GPIOF->DATA & 0x11)
    {
        case 0x00:                                                              // both buttons are pressed
            GPIOF->DATA = LED_RED;
            break;
        case 0x01:
            GPIOF->DATA = LED_GREEN;
            break;
        case 0x10:
            GPIOF->DATA = LED_BLUE;
            break;
        default:
            GPIOF->DATA &= ~(LED_RED | LED_GREEN | LED_BLUE);                   // no buttons are pressed
  }
}
