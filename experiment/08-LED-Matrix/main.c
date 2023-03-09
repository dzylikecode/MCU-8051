#include <8052.h>

#include "lib/utils.h"


////////////////////////////////////////////////////////////
// 74HC595

#define DELAY() \
  __asm         \
    nop;        \
    nop;        \
  __endasm

void sendByte74HC595(u8 data);

////////////////////////////////////////////////////////////
// LED 点阵

#define createVector          sendByte74HC595
#define clearVector()         createVector(0x00)
#define copyVectorTo(index)   set(P0, ~(index))

void delay(u16 i);

u8 vecs[] = {0x00, 0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00}; // 向量组

void main() {

  while (1) {
    for (int i = 0; i < 8; i++) {
      copyVectorTo(1 << i);
      createVector(vecs[i]);
      delay(100);
      clearVector();  // 消隐
    }
  }
}


/**
 * @brief 74HC595, 从高位开始写入
 * @param data
 */
void sendByte74HC595(u8 data) {

#define SRCLK P3_6 // 上升沿写入 Shift-register 
#define RCLK  P3_5 // 上升沿 stored in the storage register.
#define SER   P3_4 // serial data

/**
 * @brief 设置上升沿或下降沿
 * @param pin
 * @param edge 0: 下降沿(falling edge), 1: 上升沿(rising edge)
*/
#define setEdge(pin, edge) \
  set(pin, !edge);         \
  DELAY();                 \
  set(pin, edge)

  for (u8 i = 0; i < 8; i++) {
    set(SER, data & 0x80); // 取出最高位
    data <<= 1;
    setEdge(SRCLK, 1); // rising edge -> Shift-register
  }
  setEdge(RCLK, 1); // rising edge -> Storage-register
}

void delay(u16 i) {
  while (i--)
    ;
}