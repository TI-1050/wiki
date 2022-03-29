# 2018 Multi-University Training Contest 10

???+ info "Contents"
    [TOC]

## Problem A.Alkane

留坑。

## Problem B. Beads

留坑。

## Problem C. Calculate

留坑。

## Problem D. Permutation

留坑。

## Problem E. TeaTree

题意：

每个点会存下任意两个以他为 LCA 的点对的 GCD，求每个点存的 GCD 的最大值。

思路：

DSU on tree。

用 set 维护子树中的因子，对于重儿子不要处理多次。

每次查找的时候，枚举轻儿子中的因子。

还有一种线段树合并的写法。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-10/solutions/e.cpp
    ---8<--
    ```

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-10/solutions/e1.cpp
    ---8<--
    ```

## Problem F. NewNippori

留坑。

## Problem G. Cyclic

打表找规律即可。

$$
F[n] = (n - 2) * F[n - 1] + (n - 1) * F[n - 2] + (i \& 1 ? 1 : -1)
$$

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-10/solutions/g.cpp
    ---8<--
    ```

## Problem H. Pow

水。

??? info "Code"
    ```java
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-10/solutions/h.java
    ---8<--
    ```

## Problem I. Count

题意：

求：

$$
\sum_{i = 1} ^ {i = n} \sum_{j = 1} ^ {j = i - 1} [gcd(i + j, i - j) == 1]
$$

思路：

找规律。

如果是奇数就加上 $\frac {\varphi(n)}{2}$，否则加上 $\varphi(n)$。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-10/solutions/i.cpp
    ---8<--
    ```

## Problem J. CSGO

题意：

有 $n$ 把主武器和 $m$ 把副武器，每把武器有 $k$ 种属性，选取一把主武器和副武器，求题中式子最大值。

思路：

对于每种属性又有加减两种状态，枚举每把武器的每种属性的加减状态，求最大值。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-10/solutions/j.cpp
    ---8<--
    ```

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-10/solutions/j1.cpp
    ---8<--
    ```

## Problem K. Pow2

留坑。

## Problem L.Videos

题意：

每天有 $n$ 个小时，有 $m$ 部电影，$k$ 个人。

每部电影只能被一个人看，得到 $w$ 快乐值。

电影种类有 $A,B$ 两种，同一人连着看同种电影要减去 $W$ 快乐值，如何安排使得快乐值最大。

思路：

将一部电影拆成两个点 $S$ 和 $T$ 流为 $1$，费用为 $-w$。

电影与电影之间如果是可以连着看的，就连边，如果是同种类，费用就是 $W$, 否则就是 $0$，流为 $1$。

源点连出来加一个点，流量为 $k$，限制为 $k$ 个人。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-10/solutions/l.cpp
    ---8<--
    ```
