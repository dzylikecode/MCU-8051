# SDCC 语法

## 变量

- pin 形式

  eg. `P1_3`

- 位定义

### 存储类型

`__data` :这是小内存模式的默认(通用)地址空间，声明的变量将被放在 8051 内核的直接寻址 RAM 中

`__idata` :这个地址空间中的变量将被分配到 8051 的内部 RAM 的间接可寻址部分

`__pdata `:存储类型 pdata 用于访问分页的外部数据存储器

`__xdata` :这个地址空间中的变量将被放在外部 RAM 中

`__code` :存放程序代码的内存地址空间

- example

  ```c
  __data unsigned char test_data;
  ```

## 位操作

> using ~ on bit/bool/unsigned char variables can give unexpected results due to promotion to int

- bit

  使用`!`代替`~`

## 函数

- 一些有用的函数

  > 没有看懂

  SDCC Manual 中的 Code generation 部分(使用 `ctrl+f` 全局搜索`rotate`定位)

## interrupt

```c
void INT0_ISR (void) __interrupt 0{
    // interrupt code
}
```

## reference

- [51 单片机(STC89C52)在 Ubuntu 下的开发](https://www.cnblogs.com/milton/p/14994533.html)
- [SDCC 與 Keil C 的差異](http://blog.chinaunix.net/uid-24203478-id-3062737.html)
- [SDCC 编译器 + VSCode 开发 8 位微控制器](https://blog.csdn.net/qq_42992084/article/details/109375443)
- [SDCC Manual (pdf)](http://sdcc.sourceforge.net/doc/sdccman.pdf)

  3.5 SDCC Language Extensions
