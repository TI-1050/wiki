# 2018 Multi-University Training Contest 8

???+ info "Contents"
    [TOC]

## A. Character Encoding

题意：

用 $m$ 个 $[0,n-1]$ 的数去构成 $k$，求方案数。

思路：

当没有 $[0,n-1]$ 这个条件是答案为 $C(k+m-1, m-1)$。

减去有大于的关于 $n$ 的情况，当有 $i$ 个 $n$ 时的种类为 $C(k+m-1-i \cdot n,m-1)$ 个，利用容斥定理可得。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-8/solutions/a.cpp
    ---8<--
    ```

## B. Pizza Hub

题意：

给出一个三角形，以及一个矩形的宽度，求一个最小的高度使得矩形能够覆盖三角形。

思路：

显然一定有一个点在矩形的顶点，枚举计算即可

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-8/solutions/b.cpp
    ---8<--
    ```

## C. City Development

留坑。

## D. Parentheses Matrix

题意：

构造一个矩阵，每一行和每一列都会构成一个括号序列，求合法括号序列尽量多。

思路：

分类讨论：

$n$,$m$ 都是奇数，随便构造。

$n$,$m$ 有一个奇数 那么答案是那个奇数。

比如 $1, 4$：

```plain
()()
```

两个都是偶数，如果有一个为 $2$，

比如 $2,4$；

```plain
((((

))))
```

如果两个都大于 $4$

比如 $6,6$：

```plain
((((((

()()()

(()())

()()()

(()())

)))))
```

像这样构造 答案是 $n + m - 4$。

如果 $n, m$ 中有个 $4$，

比如 $4,4$：

```plain
(())

()()

(())

()()
```

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-8/solutions/d.cpp
    ---8<--
    ```

## E. Magic Square

按题意模拟即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-8/solutions/e.cpp
    ---8<--
    ```

## F. Boolean 3-Array

留坑。

## G. Card Game

留坑。

## H. K-Similar Strings

留坑。

## I. Make ZYB Happy

留坑。

## J. Taotao Picks Apples

题意：

每次可以改变一个值，求改变之后以第一个数开头的最长上升子序列的长度，改变仅当次有效。

思路：

考虑线段树，维护一个 $cnt$, 和一个 $Max$。

两个区间合并的时候；

* 如果 $\mbox{左区间的}Max > \mbox{右区间的} Max$。
* 那么右区间没有贡献。
* 否则递归查找贡献。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-8/solutions/j.cpp
    ---8<--
    ```

## K. Pop the Balloons

留坑。

## L. From ICPC to ACM

留坑。
