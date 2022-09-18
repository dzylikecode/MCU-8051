#include "lib/utils.h"
#include "led.h"
#include <8052.h>

#define LED P2

void delay(u16 i)
{
    while (i--)
        ;
}

void main()
{
    while (1)
    {
        for (int i = 0; i < 8; i++)
        {
            setBitEx(LED, i, LED_ON);
            delay(10000);
            setBitEx(LED, i, LED_OFF);
        }
    }
}
