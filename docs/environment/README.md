# 环境的搭建

- win11: WSLg
- OS: ubuntu 20.04

## tool chain

## 编译

- 官网: [sdcc](http://sdcc.sourceforge.net/)

- install

  ```bash
  sudo apt-get install sdcc
  ```

- command

  - compile

    ```bash
    sdcc main.c -o main.ihx
    ```

  - convert to hex file

    ```bash
    packihx main.ihx > main.hex
    ```

    !> sdcc 生成的是`ihx`文件, 而烧录的一般是`hex`文件, 需要转化

### manual

- [ubuntu-sdcc](https://manpages.ubuntu.com/manpages/bionic/man1/sdcc.1.html)

- [sdcc-manual](https://sdcc.sourceforge.net/doc/sdccman.pdf)

## 烧录

- 采用普中科技自带的烧录软件

  可以

  > 联系售后要一份

- [stcgal](https://github.com/grigorig/stcgal)

  不能行

- [stcflash](https://github.com/laborer/stcflash)

  也不能行

  > 觉得是芯片的问题,

- 无法烧录的原因: [stcgal 烧录，卡在 waiting for MCU](https://discuss.em-ide.com/d/237-stcgalwaiting-for-mcu)

### issue

- Permission denied

  - 使用 sudo 提过命令的权限

    - sudo command not found

      - 使用 which 查看命名的所在路径

      - 将 command 替换成 command 的绝对路径

        ```bash
        sudo /path/to/command
        ```

  - 对串口进行授权(推荐)

    ```bash
    sudo chmod a+rw /dev/ttyUSB0
    ```

## debug

可以先学习 uart, 然后用 uart 进行调试

在网上找一些串口助手, 或着 GitHub 找代码

## vscode

- 头文件

  path: `/usr/share/sdcc/include/**`

### highlight

- [request to support sdcc mcs51 declarations (**sfr, **sbit, etc)](https://github.com/microsoft/vscode-cpptools/issues/2499)

  还没支持

- 个人解决方法

  1. 将位操作用宏封装起来

     - example

       ```c
       #define SetBit(bit, res) ((bit) = (res))
       ```

  2. 封装的宏放入`utils.h`文件当中

     ```c
     #ifndef DZ_UTILS_H
     #define DZ_UTILS_H

     #ifndef VSCODE_C_PP_PROPERTIES_JSON
     #define SetBit(bit, res) ((bit) = (res))

     #else // for vscode

     #define SetBit(bit, res)

     #define P2_0 1

     #endif // end of VSCODE_C_PP_PROPERTIES_JSON


     #endif
     ```

  3. `main.c`文件包含`utils.h`文件
  4. `.vscode/c_cpp_properties.json`文件配置

     定义宏`VSCODE_C_PP_PROPERTIES_JSON`

## makfile

[](Makefile ":include :type=code makefile")

## 仿真器

- [ ] 等待补充

## 总结

### IDE

> 没试过

- [How To Install mcu8051ide on Ubuntu 21.04](https://installati.one/ubuntu/21.04/mcu8051ide/)

- install

  ```bash
  sudo apt-get -y install mcu8051ide
  ```

### EIDE

VSCode 插件

- [Visual Studio Code + SDCC 开发 51 单片机 1 - 环境安装](https://blog.csdn.net/pq113_6/article/details/120922369)

  官方文档: [em-ide](https://em-ide.com/zh-cn/docs/modules/flasher/#stcgal)

!> 烧录的芯片有些不支持, 原因在于工具`stcgal`作者不更新了

### platformIO

- [Ubuntu 下使用 PlatformIO 开发 STC89/STC12/Arduino](https://blog.csdn.net/michaelchain/article/details/119776690)

  > 问题与 EIDE 相同
