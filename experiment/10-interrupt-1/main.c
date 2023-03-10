
#include <8052.h>

#include "lib/utils.h"

#define LED             P2_0
#define reverseLED(led) set(led, !get(led))

#define KEY3            P3_3
#define KEY_DOWN        0
#define KEY_UP          1
#define isKeyDown(key)  (KEY_DOWN == get(key))

void delay(u16 i);
void int1_init();

void main() {
  int1_init();
  while (1)
    ;
}

void int1_init() {
  IT1 = 1;   // 跳变沿出发方式（下降沿）
  EX1 = 1;   // 打开 INT1 的中断允许
  EA  = 1;   // 打开总中断
}

void int1_callback() __interrupt 2  // 外部中断 1 的中断函数
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