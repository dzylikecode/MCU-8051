# rethink

## 观察与思考

![](assets/2023-03-09-23-33-00.png)

如图的一个现象, 我认为是两列点亮, 然后有一行熄灭. 我是这么观察的

`0x41`: 代表了两列点亮, 也就是 `0100 0001`

`~0x01`: 代表了一行熄灭, 也就是 `1111 1110`

这样的观察作用于我的思考, 于是我构造了相应的函数

- `setLEDMatrixCol`: 设置列, 两列点亮
- `setLEDMatrixRow`: 设置行, 一行熄灭

```c
#define setLEDMatrixRow       sendByte74HC595
#define setLEDMatrixCol(ch)   set(P0, ~ch)

void main() {
  setLEDMatrixCol(0x41);
  u8 rowShape = (u8)~0x01;
  while (1) {
    setLEDMatrixRow(rowShape);
    rowShape = RLC(rowShape, 1);
    delay(10000);
  }
}
```

- 详细代码<a class="Repos" target="_blank" href="./07-IO-74HC595.c">07-IO-74HC595</a>

然后在为了实现下面效果的时候

![](assets/2023-03-09-23-31-24.png)

根据上面的思考, 我写了下面的代码

> 先前的观察与表述影响了我的思考

```c
#define setLEDMatrixRow       sendByte74HC595
#define setLEDMatrixCol(ch)   set(P0, ~ch)

u8 rowShape[] = {0x00, 0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00}; // 位选数据
u8 colShape[] = {1<<7, 1<<6, 1<<5, 1<<4, 1<<3, 1<<2, 1<<1, 1<<0}; // 段选数据

void main() {

  while (1) {
    setLEDMatrixCol(0x7f);
    for (int i = 0; i < 8; i++) {
      setLEDMatrixCol(colShape[i]);
      setLEDMatrixRow(rowShape[i]);
      delay(100);
      setLEDMatrixRow(0x00);         // 消隐
    }
  }
}
```

- 详细代码<a class="Repos" target="_blank" href="./08-LED-Matrix.c">08-LED-Matrix</a>

这非常奇怪`0x00, 0x00, 0x3e`这些明明是一列一列观看地, 却写到了 rowShape 里面

仔细思考确实如此, 取出 0x3e 观察, 这是第三列, 而 0x3e 表达的是每一行开与关

![](assets/2023-03-10-00-50-52.png)

!> 这个关系有点绕

重新思考后, 我发现 row, col 针对的是坐标点, 而这里应该来说是向量. 有了列向量, 就不应该有 row 这样的东西, 使用下标代替 row 更好

重新描述:

`sendByte74HC595`是用来构造列向量的, 可以想象有一个全局的向量

```c
sendByte74HC595(0x3e);
```

表达了构造一个 0x3e 的全局的列向量

```c
P0 = 1 << 7;
```

表达了将全局的向量填补到 LED 矩阵的第 7 列

将代码重构了, 如下

```c
#define createVector          sendByte74HC595
#define clearVector()         createVector(0x00)
#define copyVectorTo(index)   set(P0, ~(index))

void delay(u16 i);

u8 vecs[] = {0x00, 0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00}; // 向量组

void main() {

  while (1) {
    for (int i = 0; i < 8; i++) {
      copyVectorTo(1 << i);
      createVector(vecs[i]);
      delay(100);
      clearVector();  // 消隐
    }
  }
}
```

同时, 这良好地表达了位选与段选. `copyVectorTo` 是位选, 速度快, 而 `createVector` 比较费力, 是段选
