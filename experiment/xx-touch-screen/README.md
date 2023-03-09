# touch screen

## font

## main

```c
void main() {
  init();
Start:
  drawGUI();

  while (1) {
    if (Touch_RST) {
      Touch_RST = 0;
      LCD_Clear(BACK_COLOR);
      goto Start;
    }

    TOUCH_Test(); // control Touch_RST
  }
}
```

## reference

- [STM32-----TFTLCD 驱动原理](https://blog.csdn.net/liu112125/article/details/118461356)
- [UART 串口协议详解](https://zhuanlan.zhihu.com/p/150504364)
