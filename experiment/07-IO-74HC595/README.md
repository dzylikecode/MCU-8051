# IO 扩展

74HC595: 8-BIT SHIFT REGISTER WITH 8-BIT OUTPUT REGISTER

> 详细功能查看手册的`Device Functional Modes`部分

## task

用 IO 扩展模块, 操作 8X8 点阵实现流水灯

## core

一位一位地将数据移入到 74HC595 中, 然后锁存

## resources

- <a class="Repos" target="_blank" href="main.c">code</a>
- [74HC595 instruments](https://www.ti.com/lit/ds/symlink/sn74hc595.pdf?ts=1663727421518&ref_url=https%253A%252F%252Fwww.google.com%252F)

  > 关注以下两个部分

  - Timing Diagram
  - Device Functional Modes
