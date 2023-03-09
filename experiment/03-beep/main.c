#include <8052.h>

#include "lib/utils.h"

#define BEEP P2_5

void delay(u16 i);

void main() {
  while (1) {
    // using ~ on bit/bool/unsigned char variables
    // can give unexpected results due to promotion to int
    set(BEEP, !BEEP);
    delay(100);
  }
}

void delay(u16 i) {
  while (i--)
    ;
}