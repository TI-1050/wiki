# 2018 Multi-University Training Contest 2

???+ info "Contents"
    [TOC]

## A. Absolute

留坑。

## B. Counting Permutations

留坑。

## C. Cover

留坑。

## D. Game

`puts("Yes")`。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-2/solutions/d.cpp
    ---8<--
    ```

## E. Hack It

留坑。

## F. Matrix

留坑。

## G. Naive Operations

题意：

给出 $b[]$ 数组，里面是 $1-n$ 的全排列。

两种操作：

* 区间 $+1$。
* 区间求 $\displaystyle \sum_{i = l} ^ {i = r} \lfloor \frac{a_i}{b_i} \rfloor$。

思路：

维护一个 `Min` 表示这个区间内需要的最少的进位，如果有进位，就更新到底，如果没有进位就区间更新。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-2/solutions/g.cpp
    ---8<--
    ```

## H. Odd Shops

留坑。

## I. Segment

留坑。

## J. Swaps and Inversions

水。

逆序对的意义就是每次只能交换相邻两个，最少的交换次数。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-2/solutions/j.cpp
    ---8<--
    ```
