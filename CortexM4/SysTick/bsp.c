#include "bsp.h"

void setupGPIO()
{
    SYSCTL->RCGC2 = 0x20;                                                       // enable port f
    GPIOF->DIR = (LED_RED | LED_BLUE | LED_GREEN);                              // output direction
    GPIOF->DEN = (LED_RED | LED_BLUE | LED_GREEN);                              // digital enable
    GPIOF->DATA &= 0;
}

void setupTimer()
{
    SysTick->CTRL = 0x7;                                                        // enable systick
    SysTick->LOAD = 5000000;                                                    // time to count
    SysTick->VAL  = 0;
}
void SysTick_Handler()
{
    GPIOF->DATA ^= LED_RED;
    GPIOF->DATA ^= LED_BLUE;
    GPIOF->DATA ^= LED_GREEN;
}
