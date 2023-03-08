#include <8052.h>

#include "lib/utils.h"

#define LED_ON  0
#define LED_OFF 1

#define LED P2

void delay(u16 i);

void main() {
  while (1) {
    for (int i = 0; i < 8; i++) {
      setBitEx(LED, i, LED_ON);
      delay(10000);
      setBitEx(LED, i, LED_OFF);
    }
  }
}

void delay(u16 i) {
  while (i--)
    ;
}