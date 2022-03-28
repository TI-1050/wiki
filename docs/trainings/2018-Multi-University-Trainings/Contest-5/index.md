# 2018 Multi-University Training Contest 5

???+ info "Contents"
    [TOC]

## A. Always Online

Unsolved.

## B.Beautiful Now

Solved.

题意：

给出一个 $n$ 和 $k$。

每次可以将 $n$ 这个数字上的某两位交换，最多交换 $k$ 次，求交换后的最大和最小值。

思路：

很明显有一种思路，对于最小值，尽可能把小的放前面，对于最大值，尽可能把打的放前面。

但是如果有多个最小数字或者最大数字会无法得出放哪个好，因此 BFS 一下即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-5/solutions/b.cpp
    ---8<--
    ```

## C. Call It What You Want

Unsolved.

## D. Daylight

Unsolved.

## E. Everything Has Changed

Solved.

题意：

求多个圆的周长并

思路：

对于不想交和内含的直接 continue，相切的直接相加。

对于相交的可以减去大圆上的弧长，加上小圆的弧长。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-5/solutions/e.cpp
    ---8<--
    ```

## F. Fireflies

Unsolved.

## G. Glad You Came

Upsolved.

题意：

$m$ 个区间操作，每次给 $[L, R]$ 区间内小于 $v$ 的数变为 $v$。

思路：

线段树，维护最大最小值 + 剪枝，因为数据随机才可以这样做。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-5/solutions/g.cpp
    ---8<--
    ```

## H. Hills And Valleys

Upsolved,

题意：

给出一个长为 $n$ 的数字串，每一位范围是 $[0, 9]$，可以翻转其中一段，使得最长非下降子序列最长。

思路：

也就是说，可以存在这样一段：

$$
0, 1, 2, \cdots, x, (x - 1), y, (y - 1), \cdots, x, y + 1, y + 2, \cdots
$$

我们知道，如果不可以翻转，求最长上升子序列的话，我们可以将原串和模式串 $0123456789$ 求最长公共子序列。

那么翻转的话，我们通过枚举翻转的区间 $C(2, 10)$ 构造出上述的模式串，再求最长公共子序列。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-5/solutions/h.cpp
    ---8<--
    ```

## I. Innocence

Unsolved.

## J. Just So You Know

Unsolved.

## K. Kaleidoscope

Unsolved.

## L. Lost In The Echo

Unsolved.
