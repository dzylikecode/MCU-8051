#include "lib/utils.h"
#include <8052.h>

#define DIG_NUM 8
#define CHOOSE_A P2_2
#define CHOOSE_B P2_3
#define CHOOSE_C P2_4
#define SHAPE P0
#define EMPTY 0x00
__code u8 shapeTalbe[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
                          0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
void drawDigitalTube(u8 pos, u8 shape)
{
    pos = 7 - pos; // 与硬件有关, 映射顺序
    switch (pos)
    {
    case 0:
        set(CHOOSE_A, 0);
        set(CHOOSE_B, 0);
        set(CHOOSE_C, 0);
        break;
    case 1:
        set(CHOOSE_A, 1);
        set(CHOOSE_B, 0);
        set(CHOOSE_C, 0);
        break;
    case 2:
        set(CHOOSE_A, 0);
        set(CHOOSE_B, 1);
        set(CHOOSE_C, 0);
        break;
    case 3:
        set(CHOOSE_A, 1);
        set(CHOOSE_B, 1);
        set(CHOOSE_C, 0);
        break;
    case 4:
        set(CHOOSE_A, 0);
        set(CHOOSE_B, 0);
        set(CHOOSE_C, 1);
        break;
    case 5:
        set(CHOOSE_A, 1);
        set(CHOOSE_B, 0);
        set(CHOOSE_C, 1);
        break;
    case 6:
        set(CHOOSE_A, 0);
        set(CHOOSE_B, 1);
        set(CHOOSE_C, 1);
        break;
    case 7:
        set(CHOOSE_A, 1);
        set(CHOOSE_B, 1);
        set(CHOOSE_C, 1);
        break;
    default:
        break;
    }
    set(SHAPE, shape);
}

void delay(u16 i)
{
    while (i--)
        ;
}

void main()
{

    while (1)
    {
        for (int i = 0; i < DIG_NUM; i++)
        {
            drawDigitalTube(i, shapeTalbe[i]);
            delay(200);
            drawDigitalTube(i, EMPTY);
        }
    }
}
