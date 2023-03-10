# UART

## code

### synchronous

```c
void UART_TxChar(char ch) {
  SBUF = ch;                // Load the data to be transmitted
  while (TI == 0)
    ;                       // Wait till the data is trasmitted
  TI = 0;                   // Clear the Tx flag for next cycle.
}
```

阻塞式发送, MCU 等待发送完

```c
char UART_RxChar(void) {
  while (RI == 0)
    ;                       // Wait till the data is received
  RI = 0;                   // Clear Receive Interrupt Flag for next cycle
  return (SBUF);            // return the received char
}
```

阻塞式接收, MCU 等待接收完

> 可以类比 js 的 `await`

### asynchronous

```c
// 串口中断
void UART_Routine() interrupt 4 {
  if (TI == 1) {
    function();
    TI = 0;               // 复位
  }
}
```

非阻塞式发送

```c
// 串口中断
void UART_Routine() interrupt 4 {
  if (RI == 1) {
    globalBuf = SBUF;     // 接受数据
    function();
    RI = 0;               // 复位
  }
}
```

非阻塞式接收

> 类比 js, 回调

## resources

- <a class="Repos" target="_blank" href="main.c">code</a>
- [UART Registers](https://exploreembedded.com/wiki/A4.8051_Communication_Protocols:UART,_RS232)
- [51 单片机之串口通信详解及代码示例](https://blog.csdn.net/didi_ya/article/details/124289688)
