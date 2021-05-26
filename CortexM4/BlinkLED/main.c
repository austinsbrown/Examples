#include "bsp.h"

int main() 
{
    Setup();
    for(;;)
    {
        ToggleLEDBlue();
        Delay();
    }
}
