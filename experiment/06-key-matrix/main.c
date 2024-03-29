#include <8052.h>

#include "lib/utils.h"

////////////////////////////////////////////////////////////
// digital tube
#define DIG_NUM 8
#define EMPTY 0x00
__code u8 shapeTable[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
                          0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

////////////////////////////////////////////////////////////
// matrix key
#define KEY           P1
#define KEY_ROW_MASK  0xf0
#define KEY_ROW_BIT   4
#define KEY_COL_MASK  0x0f
#define KEY_COL_BIT   0
#define initRow()     set(KEY, KEY_ROW_MASK)
#define initCol()     set(KEY, KEY_COL_MASK)
#define getKey(key)   (~get(KEY))  // reverse, 1101 -> 0010
#define getRowKey()   (initRow(), ((getKey(KEY) & KEY_ROW_MASK) >> KEY_ROW_BIT)) // eg. 0x20 -> 0x02 移动高四位
#define getColKey()   (initCol(), ((getKey(KEY) & KEY_COL_MASK) >> KEY_COL_BIT)) // eg. 0x02 -> 0x02 不变

void drawDigitalTube(u8 pos, u8 shape);
u8 transCode(u8 code);
void delay(u16 i);

void main() {
  u8 posX;
  u8 posY;
  u8 codeX; // 0x1, 0x2, 0x4, 0x8, 位置编码
  u8 codeY;
  u8 shape = 0;
  while (1) {
    codeX = getColKey();
    codeY = getRowKey();
    posX = 4 - transCode(codeX);     // [1 - 4] -> [3 - 0]
    posY = 4 - transCode(codeY);     // [1 - 4] -> [3 - 0]
    if (codeX != 0 && codeY != 0) {  // 判断是否有按键按下
      shape = posY * 4 + posX;
    }

    drawDigitalTube(7, shapeTable[shape]);
    delay(200);
    drawDigitalTube(7, 0);
  }
}

#define CHOOSE_A  P2_2
#define CHOOSE_B  P2_3
#define CHOOSE_C  P2_4
#define SHAPE     P0

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

u8 transCode(u8 code) {
  switch (code) {
    case 0x01:
      return 1;
    case 0x02:
      return 2;
    case 0x04:
      return 3;
    case 0x08:
      return 4;
  }
  return 0;
}

void delay(u16 i) {
  while (i--)
    ;
}