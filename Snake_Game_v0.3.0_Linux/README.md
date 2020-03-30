# 单向链表贪吃蛇 v0.3.0 for Linux
# One-way Listed Link Snake Game v0.3.0 for Linux

## Description
Use pure C and ncurses.
使用纯 c 和 ncurses。

Tested on Fedora28, Windows10 WSL.
已经测试正常的平台：Fedora28，Windows10 WSL。

依赖 ncurses 库
编译命令：gcc snake.c -lncursesw -o snake
注意使用 -lncursesw 否则会出现中文乱码 

会在程序当前目录产生三个配置文件
由于 Linux 下没有 kbhit() 函数，其代码来源于网络。

By SDUST weilinfox

## Release note
2019-12-07 第一个测试版本 0.1.2_tested
2019-12-08 第一个 bug free 版本 0.1.2_stable
2019-12-08 第一个定制版本 0.1.dbb
2019-12-08 发现 360 误报毒
2019-12-08 开始 0.1.3 版本编写
2019-12-13 0.1.3 版本功能冻结
2019.12.14 0.2.0 版本冻结
2019.12.21 0.3.0 开始编写
2020.02.17 0.3.0 for Linux 完成

## Change log
0.0.0 2019-12-07
+ 实现基本功能
+ 完善菜单项

0.1.0 2019-12-07
+ 完善功能
+ 解决部分 bug

0.1.1 2019-12-07
+ 完善功能
+ 解决部分 bug

0.1.2 2019-12-07
+ 完善功能
+ Bug free

0.1.3 2019-12-13
+ 优化菜单
+ 游戏模式持久化
+ 解决蛇穿墙 “吃多了” 的问题
+ 增加内置图
+ 自定义图
+ 修复部分 bug

0.2.0 2019-12-14
+ 增加 complete 模式排行榜
+ 增加欢迎界面
+ 修复部分 bug

0.2.1 2019-12-21
+ 预备修复 bug

0.3.0 2019-12-21
+ 修复电源设置可能造成的运行速度 bug

0.3.0 for Linux 2020-2-17
+ 通过 ncurses 支持 Linux

