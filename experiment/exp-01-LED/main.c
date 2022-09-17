#include "lib/utils.h"
#include <8052.h>
#define LED P2_0

void main()
{
    SetBit(LED, 0);
    while(1);
}