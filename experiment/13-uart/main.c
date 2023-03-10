#include <8052.h>

#include "lib/utils.h"

#define setStartStrike(id, high, low) \
  TH##id = high;                      \
  TL##id = low

void UART_init();
void UART_txChar(char ch);


int main() {
  char greeting[] = {" Welcome to 8051 Serial Comm, Type the char to be echoed: \n"};

  UART_init();
  for (int i = 0; greeting[i] != 0; i++) {
    UART_txChar(greeting[i]);     // Transmit predefined string
  }

  while (1) {
  }
}

void UART_init() {
  PCON &= 0x7F;                   // 波特率不倍速
  SCON = 0x50;                    // 8位数据,仅用于发送
  TMOD &= 0x0F;                   // 清除定时器1模式位
  TMOD |= 0x20;                   // 设定定时器1为8位自动重装方式
  setStartStrike(1, 0xFA, 0xFA);  // 4800bps@11.0592MHz
  ET1 = 0;                        // 禁止定时器1中断
  TR1 = 1;                        // 启动定时器1
  ES = 1;                         // 启动串口中断
  EA = 1;                         // 总中断控制
}

void UART_txChar(char ch) {
  SBUF = ch;                // Load the data to be transmitted
  while (TI == 0)           // Wait till the data is trasmitted
    ;                       
  TI = 0;                   // Clear the Tx flag for next cycle.
}

void UART_routine() __interrupt 4 {
  if (RI == 1) {
    UART_txChar(SBUF);
    RI = 0;                // 复位
  }
}

char UART_rxChar(void) {
  while (RI == 0)
    ;                       // Wait till the data is received
  RI = 0;                   // Clear Receive Interrupt Flag for next cycle
  return (SBUF);            // return the received char
}