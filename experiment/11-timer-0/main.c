#include <8052.h>

#include "lib/utils.h"

#define LED             P2_0
#define reverseLED(led) set(led, !get(led))

void timer0_init();

void main() {
  timer0_init();
  while (1)
    ;
}

void timer0_init() {
  TMOD |= 0X01;   // 选择为定时器0模式，工作方式1，仅用TR0打开启动。

  TH0 = 0XFC;     // 给定时器赋初值，定时1ms
  TL0 = 0X18;
  ET0 = 1;        // 打开定时器0中断允许
  EA  = 1;        // 打开总中断
  TR0 = 1;        // 打开定时器
}

void timer0_callback() __interrupt 1  // 定时器 0 的中断函数
{

#define setStartStrike(id, high, low) \
  TH##id = high;                      \
  TL##id = low

  static u16 toggleTimes;
  setStartStrike(0, 0XFC, 0X18);     // 给定时器赋初值，定时1ms     
  toggleTimes++;
  if (toggleTimes == 1000) {
    toggleTimes = 0;
    reverseLED(LED);
  }
}

