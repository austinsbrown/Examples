#include "CMSIS/tm4c_cmsis.h"

#ifndef BSP_H_
#define BSP_H_

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)
#define SW1       (1U << 4)
#define SW2       (1U)

void setup();
void checkForPress();

#endif
