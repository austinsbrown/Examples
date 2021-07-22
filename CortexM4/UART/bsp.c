#include "bsp.h"

void setupGPIO()
{
    SYSCTL->RCGC2 = 0x20;
    GPIOF->DIR    |= (RED_BIT | BLUE_BIT | GREEN_BIT);
    GPIOF->DEN    |= (RED_BIT | BLUE_BIT | GREEN_BIT);
    GPIOF->DATA   = 0;
}

void ledRed()
{
    GPIOF->DATA ^= RED_BIT;
}

void ledGreen()
{
    GPIOF->DATA ^= GREEN_BIT;
}

void ledBlue()
{
    GPIOF->DATA ^= BLUE_BIT;
}

void ledOff()
{
    GPIOF->DATA &= ~(RED_BIT | GREEN_BIT | BLUE_BIT);
}

void setupUART()
{
    SYSCTL->RCGC1 |= 1;                                                         // enable UART 0
    SYSCTL->RCGC2 |= 1;                                                         // enable port A
    GPIOA->AFSEL  |= (BIT0 | BIT1);
    GPIOA->PCTL   |= (BIT0 | BIT4);                                             // encoding for UART
    GPIOA->DEN    |= (BIT0 | BIT1);
    UART0->CTL    &= ~BIT0;                                                     // disable UART
    UART0->IBRD   =  104;                                                       // integer portion of baud rate
    UART0->FBRD   =  11;                                                        // fraction portion of baud rate
    UART0->LCRH   =  (0x3 << 5);                                                // settings for UART
    //UART0->CC     =  0;                                                       // clk source
    UART0->CTL    =  (BIT0 | BIT8 | BIT9);                                      // reactivate UART
}

void printChar(char c)
{
    while((UART0->FR & BIT5) != 0);                                             // wait until transmit is not full
    UART0->DR = c;                                                              // send char to data reg

}


void printString(char *string)
{
    while (*string)
    {
        printChar(*(string++));
    }
}

char readChar()
{
    while((UART0->FR & BIT4) != 0);                                             // wait until recieve is not full
    char c = UART0->DR;                                                         // set c to what is in the data reg
    printChar(c);
    return c;
}
