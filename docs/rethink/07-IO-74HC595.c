// ! deprecated, just for example

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

#define setLEDMatrixRow       sendByte74HC595
#define setLEDMatrixCol(ch)   set(P0, ~ch)

void delay(u16 i);

void main() {
  setLEDMatrixCol(0x41);
  u8 rowShape = (u8)~0x01; 
  while (1) {
    setLEDMatrixRow(rowShape);
    rowShape = RLC(rowShape, 1);
    delay(10000);
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