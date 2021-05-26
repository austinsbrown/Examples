#include "CMSIS/tm4c_cmsis.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)


void Setup();
void Delay(void);
void ToggleLEDBlue();
void ToggleLEDRed();
void ToggleLEDGreen();
