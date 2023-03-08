# 独立按键

体现单片机的输入功能

## 任务

按下一个独立按键, 然后点亮一个 LED

## bug record

```c
while (1)
{
    u8 keyState = readKey();
    if (keyState == KEY_DOWN)
    {
        reverseLED(LED);
    }
    waitKeyUp();
}
```

!> `waitKeyUp();`的位置不对, 可能按键按下是命中的正是 waitKeyUp()的判断, 导致程序卡在这个地方, 而不是进入按键按下的逻辑

## resources

- <a class="Repos" target="_blank" href="main.c">code</a>
