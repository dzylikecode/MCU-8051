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

u8 rowShape[] = {0x00, 0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00}; // 位选数据
u8 colShape[] = {1<<7, 1<<6, 1<<5, 1<<4, 1<<3, 1<<2, 1<<1, 1<<0}; // 段选数据

void main() {

  while (1) {
    setLEDMatrixCol(0x7f);
    for (int i = 0; i < 8; i++) {
      setLEDMatrixCol(colShape[i]);  
      setLEDMatrixRow(rowShape[i]);  
      delay(100);                    
      setLEDMatrixRow(0x00);         // 消隐
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