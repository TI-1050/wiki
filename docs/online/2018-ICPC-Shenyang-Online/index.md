# ACM-ICPC 2018 沈阳赛区网络预赛

???+ info "Contents"
    [TOC]

## A. Gudako and Ritsuka

留坑。

## B. Call of Accepted

题意：

定义了一种新的运算符 $x \; d \; y$ 然后给出中缀表达式，求值。

思路：

先中缀转后缀，然后考虑如何最大如何最小，按题意模拟即可。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Shenyang-Online/solutions/b.cpp
    ---8<--
    ```

## C. Convex Hull

留坑。

## D. Made In Heaven

题意：

找第 $k$ 短路。

思路：

A\* 算法。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Shenyang-Online/solutions/d.cpp
    ---8<--
    ```

## E. The cake is a lie

留坑。

## F. Fantastic Graph

题意：

给出一张二分图，若干条边，选择一些边进去，使得所有点的度数在 $[L,R]$ 之间。

思路：

XDL 说爆搜，加上优秀的剪枝（8ms）。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Shenyang-Online/solutions/f.cpp
    ---8<--
    ```

## G. Spare Tire

题意：

给定一个数列 $A$，两个整数 $n,m$，在 $1-n$ 中所有与 $m$ 互质的数记为 $b[i]$，求：

$$
\sum_{i = 1}^{i = p} a_{b_i}
$$

思路：

首先可以发现：

$$
A[i] = i \cdot (i + 1) = i^2+i
$$

$A$ 的前 $n$ 项和为：

$$
\frac{n \cdot (n+1) \cdot (2n+1)}{6} + \frac{n \cdot (n+1)}{2}
$$

因为 $n,m$ 很大有 $10^8$，而且一共有 $15000$ 个 case，所以筛法肯定不行。

考虑到：

$$
2 \times 3 \times 5 \times 7 \times 11 \times 13 \times 17 \times 19 \times 23=223092870 \gt 10^8
$$

所以 $m$ 的质因子的种类肯定少于 $9$ 个。

所以我们可以用容斥。在前 $n$ 项的和的基础上容斥包含 $m$ 的不同因子的项。时间复杂度最多为 $2^9$。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Shenyang-Online/solutions/g.cpp
    ---8<--
    ```

## H. Hamming Weight

留坑。

## I. Lattice's basics in digital electronics

按题意模拟即可。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Shenyang-Online/solutions/i.cpp
    ---8<--
    ```

## J. Ka Chang

题意：

两种操作：

* $1 \; L \; X$ 所有深度为 $L$ 的加上 $x$。
* $2 \; X$ 查询以 $x$ 为根的所有子节点的和。

思路：

以 $x$ 为根的子节点的和可以用 DFS 序使得所有子树的标号在一块。

然后对于更新操作，考虑两种方法操作：

* 暴力更新每个点
* 记录这个深度更新了多少，查询的时候找出这个深度中有子节点有几个，直接加上。

如果只用第二个操作更新，那么当给的树是一条链的时候，查询的复杂度达到 $O(n \log n)$。

只用第一个操作更新，那么更新的操作当给的树是菊花形的时候，更新的复杂度达到 $O(n \log n)$。

那么考虑将两种操作结合，当某个深度中元素个数大于 $sqrt(10^5)$ 的时候，用第二种操作 否则用第一种

然后查询的时候，要记得都加上。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Shenyang-Online/solutions/j.cpp
    ---8<--
    ```

## K. Supreme Number

只有几个数，爆搜出来，判断一下

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Shenyang-Online/solutions/k.cpp
    ---8<--
    ```
