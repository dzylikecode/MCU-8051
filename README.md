# MCU

- [online docs](https://dzylikecode.github.io/MCU-8051/)

- 8051

## file struct

- `.vscode/`: vscode 环境配置
  - `c_pp_properties.json`: c/c++ 配置
- `asset/`: docsify
- `index.html`: docsify
- `command.sh`: 一些命令
- `experiment/`: 编程的实验
  - `<name>`: 项目名称
    - `README.md`: 实验报告
    - `Makefile`: 编译, 生成 hex 文件
    - `main.c`: 主程序
- `aid/`: 存放烧录的 exe, ignored
- `draft/`: 一些想法和提案

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
