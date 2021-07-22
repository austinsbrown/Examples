#include "bsp.h"

void Setup()
{
    SYSCTL->RCGC2 = 0x20;                                                       // enable port f
    GPIOF->DIR |= (LED_RED | LED_BLUE | LED_GREEN);                             // enable output direction on port 7 
    GPIOF->DEN |= (LED_RED | LED_BLUE | LED_GREEN);                             // digital enable
}


void Delay(void)                                                    
{
    int volatile counter = 0;
    while (counter < 1000000)                                              
        ++counter;
}


void ToggleLEDBlue()
{
    GPIOF->DATA ^= LED_BLUE;                                                    // set the LED to blue
}


void ToggleLEDRed()
{
    GPIOF->DATA ^= LED_RED;                                                     // set to red
}


void ToggleLEDGreen()
{
    GPIOF->DATA ^= LED_GREEN;                                                   // set to green
}
