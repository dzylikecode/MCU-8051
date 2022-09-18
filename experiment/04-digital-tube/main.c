#include "lib/utils.h"
#include "led.h"
#include <8052.h>

#define LED P2_0

void delay(u16 i)
{
    while (i--)
        ;
}

void main()
{

    while (1)
    {
        turnOnLED(LED);
        delay(50000);
        turnOffLED(LED);
        delay(50000);
    }
}
