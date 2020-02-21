# 单向链表贪吃蛇 v0.3.1 for Linux
# One-way Listed Link Snake Game v0.3.1 for Linux

## Description
Use pure C and ncurses.
使用纯 c 和 ncurses。

Tested on Fedora28, Windows10 WSL.
已经测试正常的平台：Fedora28，Windows10 WSL。

二进制提供龙芯版和x86版

依赖 ncurses 库
编译命令：gcc snake.c -lncursesw -o snake
注意使用 -lncursesw 否则会出现中文乱码 

若使用 WSL 请将电池使用模式改为 “最佳性能”
会在程序当前目录产生三个配置文件
由于 Linux 下没有 kbhit() 函数，其代码来源于网络。

By SDUST weilinfox

## Release note
2020.02.17 0.3.0 for Linux 完成

2020.02.21 0.3.1 for Linux

## Change log

0.3.0 for Linux 2020-2-17
+ 通过 ncurses 支持 Linux

0.3.1 for Linux 2020-2-21
+ 修复部分 bug
+ 优化界面

