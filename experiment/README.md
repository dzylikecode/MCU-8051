# 实例程序

## 便捷命令

### 创建环境

- 激活虚拟环境

  ```bash
  conda activate MCU-8051
  ```

- source 文件

  ```bash
  source ./simple_command.sh
  ```

> 每次打开 terminal 都需要执行

### 编译

```bash
run [path/to/project]
```

会编译指定工程下的文件, 然后在当前目录生成一个指向生成文件的软链接, 以便于烧录.

### 创建模板

```bash
ini [name]
```

> `docs/experiment/summary.md`需要自己进一步改进
