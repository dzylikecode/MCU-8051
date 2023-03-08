# 矩阵按键

## task

读取矩阵按键的状态, 显示在数码管上(十六进制).

## core

1. 对行赋值 0xf0 初始化
2. 读取端口值

   如果按键被按下, 则对应的行的值会变成 0.

   如 1111 0000 -> 1011 0000, 表示第二行被按下.

3. 处理数据

   1011 0000 -> 1011 -> 0100

> 没有按键按下, 得到的是 0x00

## resources

- [code](https://github.com/dzylikecode/MCU-8051/blob/master/experiment/06-key-matrix/main.c)
