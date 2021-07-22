#include "bsp.h"

int main()
{
    setupGPIO();
    setupUART();
    for(;;)
    {
        char c;
        printString("Enter r, g or b\n\r");
        c = readChar();
        printString("\n\r");

        switch(c)
        {
            case 'r':
                ledRed();
                break;
            case 'g':
                ledGreen();
                break;
            case 'b':
                ledBlue();
                break;
            default:
                ledOff();
                break;
        }
    }
}
