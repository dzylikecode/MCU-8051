# MCU

- [online docs](https://dzylikecode.github.io/MCU-8051/)

## hardware

- type: stc89C51
- office: [普中科技](http://www.prechin.cn/index.html)

## tool chain

- SDCC + VSCode + Makefile

  WSLg Ubuntu 平台

## file struct

- `.vscode/`: vscode 环境配置
  - `c_pp_properties.json`: c/c++ 配置
  - `*.code-snippets`: 代码片段
- `asset/`: docsify
- `index.html`: docsify
- `command.sh`: 一些命令
- `experiment/`: 编程的实验
  - `lib`: 公共的头文件
  - `**/assets/`: `README.md`的资源文件, eg 图片
  - `command.sh`: 编译命令
  - `<name>`: 项目名称
    - `README.md`: 实验报告
    - `Makefile`: 编译, 生成 hex 文件
    - `main.c`: 主程序
- `aid/`: 存放烧录的 exe, ignored
- `draft/`: 一些想法和提案
- `docs/`: 文档

## usage

### preparation

使用一些快捷的命令

```bash
source ./command.sh
```

### install

```bash
repos-install
```

!> remember to `source`

### uninstall

```bash
repos-uninstall
```

### build

read [experiment](/experiment/README.md#usage)

## tutorial

- [Chapter: Introduction to Embedded Systems with 8051 Micro Controller using Embedded C-Tutorial 1](https://www.youtube.com/watch?v=iQcr_8W3KXg&list=PLE1qlkmzXrwRQ2S4BBVkkqbd42E0ArZ9l&index=1)

## reference

- [8051-examples](https://github.com/hungtcs-lab/8051-examples)
- video: [怎么用 linux 操作系统开发 51 单片机程序](https://www.bilibili.com/video/BV1bp411d7Mg?spm_id_from=333.999.0.0&vd_source=cde057b41a3232ef25412548ec4ac354)
- [51 单片机(STC89C52)在 Ubuntu 下的开发](https://www.cnblogs.com/milton/p/14994533.html)
- [SDCC 與 Keil C 的差異](http://blog.chinaunix.net/uid-24203478-id-3062737.html)
- [SDCC 编译器 + VSCode 开发 8 位微控制器](https://blog.csdn.net/qq_42992084/article/details/109375443)
- example: http://www.colecovision.eu/mcs51/STC89%20DEMO%20BOARD%20LED.shtml
- example: http://www.colecovision.eu/mcs51/STC89%20DEMO%20BOARD%20Serial.shtml
- wiki: https://sourceforge.net/p/sdcc/wiki/Home/
- [每周更新开源项目](https://github.com/mcutree/Project-update-weekly)

  看上去挺不错的
