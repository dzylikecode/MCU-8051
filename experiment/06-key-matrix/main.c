#include <8052.h>

#include "lib/utils.h"

void delay(u16 i) {
  while (i--)
    ;
}

////////////////////////////////////////////////////////////
// digital tube
#define DIG_NUM 8
#define CHOOSE_A P2_2
#define CHOOSE_B P2_3
#define CHOOSE_C P2_4
#define SHAPE P0
#define EMPTY 0x00
__code u8 shapeTable[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
                          0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
void drawDigitalTube(u8 pos, u8 shape) {
  pos = 7 - pos;  // 与硬件有关, 映射顺序
  switch (pos) {
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
////////////////////////////////////////////////////////////
// matrix key
#define KEY P1
#define KEY_ROW_MASK 0xf0
#define KEY_ROW_BIT 4
#define KEY_COL_MASK 0x0f
#define KEY_COL_BIT 0
#define initRow() set(KEY, KEY_ROW_MASK)
#define initCol() set(KEY, KEY_COL_MASK)
#define getKey(key) (~get(KEY))  // reverse, 1101 -> 0010
#define getRowKey() (initRow(), ((getKey(KEY) & KEY_ROW_MASK) >> KEY_ROW_BIT))
#define getColKey() (initCol(), ((getKey(KEY) & KEY_COL_MASK) >> KEY_COL_BIT))

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

void main() {
  u8 posX;
  u8 posY;
  u8 codeX;
  u8 codeY;
  u8 shape;
  while (1) {
    codeX = getColKey();
    codeY = getRowKey();
    posX = 4 - transCode(codeX);     // [1 - 4] -> [3 - 0]
    posY = 4 - transCode(codeY);     // [1 - 4] -> [3 - 0]
    if (codeX != 0 && codeY != 0) {  // 判断是否有按键按下
      shape = posY * 4 + posX;
    }

    drawDigitalTube(0, shapeTable[shape]);
    delay(200);
    drawDigitalTube(0, 0);
  }
}
