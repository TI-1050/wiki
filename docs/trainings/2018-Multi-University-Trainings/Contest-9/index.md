# 2018 Multi-University Training Contest 9

???+ info "Contents"
    [TOC]

## A. Rikka with Nash Equilibrium

题意：

构造一个 $n \cdot m$ 的矩阵，使得 $[1, n \cdot m]$ 中每个数只出现一次，并且纳什均衡只出现一次。

思路：

从大到小的放置，每一个都可以拓展一行拓展一列或者放在已经拓展的行列焦点，用记忆化搜索或 dp 即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-9/solutions/a.cpp
    ---8<--
    ```

## B. Rikka with Seam

留坑。

## C. Rikka with APSP

留坑。

## D. Rikka with Stone-Paper-Scissors

题意：

每个人有三种牌：「石头、剪刀、布」。

询问第一个人赢第二个人的期望。

思路：

考虑每一次出牌的概率相同，那么答案就是：

$$
\frac{\mbox{赢的情况种数 - 输的情况}}{\mbox{牌数}}
$$

那么所有赢输情况种类数就是：

$$
\frac {a_1 *(b_2 - c_2) + b_1 * (c_2 - a_2) + c_1 * (a_2 - b_2)} {a + b + c}
$$

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-9/solutions/d.cpp
    ---8<--
    ```

## E. Rikka with Rain

留坑。

## F. Rikka with Spanning Tree

留坑。

## G. Rikka with Treasure

留坑。

## H. Rikka with Line Graph

留坑。

## I. Rikka with Bubble Sort

留坑。

## J. Rikka with Time Complexity

留坑。

## K. Rikka with Badminton

题意：

四种人，一种人啥都没有，一种人有拍，一种人有球，一种人有拍有球，求方案数使得有两拍一球。

思路：

考虑三种选择方案：

* 两个有拍 + 一个有球。
* 两个有拍有球。
* 一个有拍，一个有拍有球。

答案就是：

$$
2^a \cdot 2^c \cdot (2^b - 1) \cdot (2^d - 1) + 2^a \cdot 2^c \cdot (2^d - 1 - d) + 2^a \cdot (2^b - 1 - b) \cdot (2^c - 1)
$$

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-9/solutions/k.cpp
    ---8<--
    ```
