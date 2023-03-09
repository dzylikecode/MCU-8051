#include <8052.h>

#include "lib/utils.h"

////////////////////////////////////////////////////////////////
// LED
#define LED             P2_0
// LED function
#define reverseLED(LED) set(LED, !get(LED))

////////////////////////////////////////////////////////////////
// KEY
#define KEY         P3_1
#define KEY_DOWN    0
#define KEY_UP      1

#define waitUntilKeyUp() while (KEY_DOWN == readKey())
////////////////////////////////////////////////////////////////

void delay(u16 i);
u8 readKey();

void main() {
  while (1) {
    u8 keyState = readKey();
    if (keyState == KEY_DOWN) {
      reverseLED(LED);
      waitUntilKeyUp();
    }
  }
}

// KEY function
u8 readKey() {
  u8 keyState1 = get(KEY);
  delay(300);  // 消抖
  u8 keyState2 = get(KEY);
  return keyState2;
}

void delay(u16 i) {
  while (i--)
    ;
}