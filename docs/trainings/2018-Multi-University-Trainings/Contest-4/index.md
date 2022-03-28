# 2018 Multi-University Training Contest 4

???+ info "Contents"
    [TOC]

## Problem A. Integers Exhibition

留坑。

## Problem B. Harvest of Apples

题意：

计算 $\sum_{i = 0}^{i = m}C(n, i)$。

思路：

由 $sum_{i = 0}^{i = m}C(n,i)$ 可以得到 $sum_{i = 0}^{i = m + 1}C(n,i)$ 以及 $sum_{i = 0}^{i = m}C(n + 1,i)$ 然后用莫对算法求解。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-4/solutions/b.cpp
    ---8<--
    ```

## Problem C. Problems on a Tree

留坑。

## Problem D. Nothing is Impossible

题意：

给出 $n$ 道题目，每道题目有 $a_i$ 种正确选择，$b_i$ 种错误选择。

一共有 $m$ 个人，所有人都要选择一个题目集合去做，相当于去试答案，问最多能试出多少道题目答案。

思路：

排序，前缀积。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-4/solutions/d.cpp
    ---8<--
    ```

## Problem E. Matrix from Arrays

题意：

给出一种构造二维数组的构造方式，然后给出一个左上角，一个右下角，求这个矩形内的数和。

思路：

打表找规律发现，大矩阵是由若干个 $2L \cdot 2L$ 个小矩阵构成的，那么把给出的矩阵分成四块，整块整块的处理，边边角角的处理。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-4/solutions/e.cpp
    ---8<--
    ```

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-4/solutions/e1.cpp
    ---8<--
    ```

## Problem F. Travel Through Time

留坑。

## Problem G. Depth-First Search

留坑。

## Problem H. Eat Cards, Have Fun

留坑。

## Problem I. Delightful Formulas

留坑。

## Problem J. Let Sudoku Rotate

题意：

给出一个 $16 \times 16$ 的数独，有一些 $4 \times 4$ 的矩阵被逆时针旋转过，然后求恢复最少需要旋转多少次。

思路：

爆搜，两条剪枝，一个是判断是否有冲突，一个是判断当前步数是否比已有答案大。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-4/solutions/j.cpp
    ---8<--
    ```

## Problem K. Expression in Memories

按题意模拟即可

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-4/solutions/k.cpp
    ---8<--
    ```

## Problem L. Graph Theory Homework

水。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-4/solutions/l.cpp
    ---8<--
    ```
