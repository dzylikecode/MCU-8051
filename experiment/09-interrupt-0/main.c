
#include <8052.h>

#include "lib/utils.h"

#define LED             P2_2
#define reverseLED(led) set(led, !get(led))

#define KEY3            P3_2
#define KEY_DOWN        0
#define KEY_UP          1
#define isKeyDown(key)  (KEY_DOWN == get(key))

void delay(u16 i);
void int0_init();

void main() {
  int0_init();
  while (1)
    ;
}

void int0_init() {
  IT0 = 1;   // 跳变沿出发方式（下降沿）
  EX0 = 1;   // 打开 INT0 的中断允许
  EA  = 1;   // 打开总中断
}

void int0_callback() __interrupt 0  // 外部中断 0 的中断函数
{
  delay(1000);  // 延时消抖
  if (isKeyDown(KEY3)) {
    reverseLED(LED);
  }
}

void delay(u16 i) {
  while (i--)
    ;
}