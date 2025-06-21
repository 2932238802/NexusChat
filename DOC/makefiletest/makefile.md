# Makefile learning

## 安装环境

```shell
sudo apt install build-essentia
make -v                         # 验证版本信息
gcc -v                          # 验证版本信息
```

## 使用

### make(shell)

- 在Linux环境下，当我们输入make命令时，它就在当前目录查找一个名为Makefile的文件，然后，根据这个文件定义的规则，自动化地执行任意命令，包括编译命令

```makefile
m.txt: a.txt b.txt
    cat a.txt b.txt > m.txt
```

### 语法规范

- 命令必须以Tab开头


### clean(shell)

- 这个是一个伪目标 

```shell
.PHONY: clean
clean:
    rm -f m.txt
    rm -f x.txt
```

### .PHONY: clean

- 这样make  就不会把clean 视为一个文件了

### 独立的shell

这是因为make针对每条命令，都会创建一个独立的Shell环境，类似cd ..这样的命令，并不会影响当前目录

```shell
cd_ok:
    pwd; \
    cd ..; \
    pwd -->
```

### 控制打印

- 默认情况下，make会打印出它执行的每一条命令。
- 如果我们不想打印某一条命令，可以在命令前加上@，表示不打印命令（但是仍然会执行）

- 有些时候，我们想忽略错误，继续执行后续命令，可以在需要忽略错误的命令前加上-

```shell

ignore_error:
    -rm zzz.txt
    echo 'ok'
```

### 自动变量

- $@表示目标文件，$^表示所有依赖文件