# 2018 Multi-University Training Contest 6

???+ info "Contents"
    [TOC]

## A. oval-and-rectangle

题意：

给出一个椭圆的 $a$ 和 $b$，在 $[0, b]$ 中随机选择 $c$ 使得 $4$ 个顶点在椭圆上构成一个矩形，求矩形周长期望。

思路：

求出每种矩形的周长，除以 $b$。（积分）

![](./images/1459194-20181007164912350-136076649.png){ width="520" }

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-6/solutions/a.cpp
    ---8<--
    ```

## B. bookshelf

留坑。

## C. Ringland

留坑。

## D. Shoot Game

留坑。

## E. black-and-white

留坑。

## F. foam-transformation

留坑。

## G. Variance-MST

留坑。

## H. Rectangle Outline

留坑。

## I. Werewolf

题意：

狼人杀游戏，每个人都会指明另一个人的身份，村民一定不会说谎，狼人可能说谎，求确定的村民和狼人。

思路：

如果全都是狼人，那么逻辑一定成立，所以确定的村民数量为 $0$。

对于狼人可以通过反证法证明，若 $1$ 认为 $2$ 是村民，$2$ 认为 $3$ 为村民，$3$ 认为 $4$ 为村民，$4$ 认为 $2$ 为狼人，反证法得出 $1,2$ 为狼人，以此类推，DFS 一下即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-6/solutions/i.cpp
    ---8<--
    ```

## J. Chopping hands

留坑。

## K. sacul

留坑。

## L. Pinball

题意：

一个小球垂直下落在一个斜板上，求在斜板上弹几次。

思路：

分解小球运动（物理题）

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-6/solutions/l.cpp
    ---8<--
    ```
