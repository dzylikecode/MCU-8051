# issue

## 烧录失败

- 型号选择错误

  应该是`STC89Cxx(new)` 而不是`STC89Cxx`

- 线不对

  有充电线和数据线之分

## 代码错误

```c
#define copyVectorTo(index)   set(P0, ~index)
copyVectorTo(1 << i);
```

宏展开后, 优先级不对

```c
#define copyVectorTo(index)   set(P0, ~(index))
```
