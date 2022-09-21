# 小工具

方便创建目录, 文件等等

## 想法

### project template

- 自己创建目录 -> dz_project_template

  在 experiment 和 docs 下创建对应的目录和文件

  - [x] experiment 创建 04, 同时 docs 创建 experiment/04
  - [x] experiment 创建 makefile 和 main 文件
  - [x] docs 创建 README.md
  - [x] 接受输入参数
  - [x] 修改目录

#### 使用方式

> 进入相应的 python 环境

- python

  ```bash
  python dz_project_template.py 04-hello
  ```

- make

  ```bash
  make ini n=[name]
  ```
