#include "CMSIS/tm4c_cmsis.h"

#ifndef BSP_H_
#define BSP_H_

#define RED_BIT     (1U << 1)
#define BLUE_BIT    (1U << 2)
#define GREEN_BIT   (1U << 3)
#define BIT0        (1U)
#define BIT1        (1U << 1)
#define BIT2        (1U << 2)
#define BIT3        (1U << 3)
#define BIT4        (1U << 4)
#define BIT5        (1U << 5)
#define BIT8        (1U << 8)
#define BIT9        (1U << 9)


void setupGPIO();
void ledRed();
void ledGreen();
void ledBlue();
void ledOff();
void setupUART();
void printChar(char c);
void printString(char *string);
char readChar();

#endif
