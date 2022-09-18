# 编程规范

- [编程规范（代码规范）](http://www.codebaoku.com/specification/specification-index.html)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [15 Ways to Write Beautiful Code](https://dzone.com/articles/15-ways-to-write-beautiful-code)

## 用宏描述行为

```c
#define LED_ON 1
#define turnOnLED(led) SetBit(led, LED_ON)
```

## 可读性

将任务分解为直观的基本步骤, 而不是晦涩, 然后将晦涩的操作封装为函数

- example

  流水灯

  需要一位一位地点亮灯, 直观的想法是希望有一个函数

  ```c
  setBitEx(LED, i, LED_ON);
  delay(10000);
  setBitEx(LED, i, LED_OFF);
  ```

## 文档先行

在 docs 当中描述自己的需求, 给出解决方法, 最后再敲代码

> think twice, code once
