#include <8052.h>

#include "lib/utils.h"

#define LED_ON          0
#define LED_OFF         1

#define turnOnLED(led)  set(led, LED_ON)
#define turnOffLED(led) set(led, LED_OFF)

#define LED P2_0

void delay(u16 i);

void main() {
  while (1) {
    turnOnLED(LED);
    delay(50000);
    turnOffLED(LED);
    delay(50000);
  }
}

void delay(u16 i) {
  while (i--)
    ;
}