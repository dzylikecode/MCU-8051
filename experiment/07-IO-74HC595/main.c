#include "lib/utils.h"
#include <8052.h>

void delay(u16 i)
{
    while (i--)
        ;
}

////////////////////////////////////////////////////////////
// 74HC595
#define SRCLK P3_6
#define RCLK P3_5
#define SER P3_4

#define DELAY() __asm nop nop __endasm

/**
 * @brief 74HC595, 从高位开始写入
 * @param dat
 */
void sendByte74HC595(u8 data)
{
    for (u8 i = 0; i < 8; i++)
    {
        set(SRCLK, 0);
        set(SER, data & 0x80);
        set(SRCLK, 1); // 产生一个上升沿, 数据被写入
        data <<= 1;
    }
    set(RCLK, 0);
    DELAY();
    set(RCLK, 1); // 上升沿 -> 锁存
}
////////////////////////////////////////////////////////////
// LED
#define LED P0_7

void main()
{

    while (1)
    {
    }
}
