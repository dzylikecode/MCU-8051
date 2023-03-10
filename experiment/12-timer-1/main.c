#include <8052.h>

#include "lib/utils.h"

/**
 * 0-9, A-F
*/
__code u8 shapeTable[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
                          0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

void drawDigitalTube(u8 pos, u8 shape);

#define setStartStrike(id, high, low) \
  TH##id = high;                      \
  TL##id = low

void timer1_init();

void main() {
  timer1_init();
  while (1)
    ;
}

void timer1_init() {
  TMOD |= 0X01;                       // 选择为定时器1模式，工作方式1，仅用TR1打开启动。
  setStartStrike(1, 0XFC, 0X18);      // 给定时器赋初值，定时1ms  
  ET1 = 1;                            // 打开定时器1中断允许
  EA  = 1;                            // 打开总中断
  TR1 = 1;                            // 打开定时器
}

void timer1_callback() __interrupt 3  // 定时器 1 的中断函数
{
  static u16 toggleTimes = 0;
  static u8  curNum      = 0;
  setStartStrike(1, 0XFC, 0X18);     // 给定时器赋初值，定时1ms
  toggleTimes++;
  if (toggleTimes == 1000) {
    toggleTimes = 0;
    drawDigitalTube(5, shapeTable[curNum]);
    curNum++;
    if (curNum == 16) {
      curNum = 0;
    }
  }
}

#define CHOOSE_A    P2_2
#define CHOOSE_B    P2_3
#define CHOOSE_C    P2_4
#define SHAPE       P0

/**
 * @param pos: position
 * @param shape: shape of digital tube
*/
void drawDigitalTube(u8 pos, u8 shape) {


// ! 重新映射了底层的 ABC
#define setABC(a, b, c) \
  set(CHOOSE_A, (c));   \
  set(CHOOSE_B, (b));   \
  set(CHOOSE_C, (a))

  // pos = 7 - pos;  // 与硬件有关, 映射顺序
  switch (pos) {
    case 0:
      setABC(0, 0, 0);
      break;
    case 1:
      setABC(0, 0, 1);
      break;
    case 2:
      setABC(0, 1, 0);
      break;
    case 3:
      setABC(0, 1, 1);
      break;
    case 4:
      setABC(1, 0, 0);
      break;
    case 5:
      setABC(1, 0, 1);
      break;
    case 6:
      setABC(1, 1, 0);
      break;
    case 7:
      setABC(1, 1, 1);
      break;
    default:
      break;
  }
  // setABC(1, 1, 0);
  set(SHAPE, shape);
}