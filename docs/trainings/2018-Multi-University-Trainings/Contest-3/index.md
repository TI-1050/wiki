# 2018 Multi-University Training Contest 3

???+ info "Contents"
    [TOC]

## Problem A. Ascending Rating

题意：

给出 $n$ 个数，给出区间长度 $m$。对于每个区间，初始值的 $max$ 为 $0$，$cnt$ 为 $0$. 遇到一个 $a[i] > ans$, 更新 $ans$ 并且 $cnt++$。

计算

$$
\begin{eqnarray*}
A &=& \sum_{i = 1}^{i = n - m +1} (max \oplus i) \\
B &=& \sum_{i = 1}^{i = n - m +1} (cnt \oplus i)
\end{eqnarray*}
$$

思路：

单调队列，倒着扫一遍，对于每个区间的 $cnt$ 就是队列的长度，扫一遍即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-3/solutions/a.cpp
    ---8<--
    ```

## Problem B. Cut The String

留坑。

## Problem C. Dynamic Graph Matching

题意：

给出 $n$ 个点。

两种操作，一种是加边，一种是减边，每次加一条或者减一条。

每次操作后输出 $1, 2, \cdots, \frac{n}{2}$ 表示对应的数量的边。

问有几种取法，并且任意两个边不能相邻。

思路：

每加一条边，都可以转移状态 比如说 `110100` 到 `111110` 就是 `dp[111110] += dp[110100]`。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-3/solutions/c.cpp
    ---8<--
    ```

## Problem D. Euler Function

打表找规律。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-3/solutions/d.cpp
    ---8<--
    ```

## Problem E. Find The Submatrix

留坑。

## Problem F. Grab The Tree

题意：

一棵树，每个点有点权，小 Q 可以选择若干个点，并且任意两个点之间没有边，小 T 就是剩下的所有点，然后两个人的值就是拥有的点异或起来，求小 Q 赢还是输还是平局。

思路：

显然，只有赢或者平局的情况，只要考虑是否有平局情况就可以，当所有点异或起来为 $0$ 便是平局。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-3/solutions/f.cpp
    ---8<--
    ```

## Problem G. Interstellar Travel

题意：

给出 $n$ 个点。

要从 $i -> j$ 当且仅当 $x_i < x_j$ 花费为 $x_i \cdot y_j - x_j \cdot y_i$。

求从 $1 -> n$ 的权值最小。

如果多解输出字典序最小的解。

思路：

可以发现权值就是叉积。

求个凸包。

然后考虑在一条线上的情况。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-3/solutions/g.cpp
    ---8<--
    ```

## Problem H. Monster Hunter

留坑。

## Problem I. Random Sequence

留坑。

## Problem J. Rectangle Radar Scanner

留坑。

## Problem K. Transport Construction

留坑。

## Problem L. Visual Cube

按题意模拟即可，分块解决。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-3/solutions/l.cpp
    ---8<--
    ```

## Problem M. Walking Plan

题意：

给出一张图，询问从 $u -> v$ 至少经过 $k$ 条路的最少花费。

思路：

因为 $k <= 10000$ 那么我们可以拆成 $k = x * 100 + y$ 然后考虑分块

$G[k][i][j]$ 表示 $i -> j$ 至少经过 $k$ 条路。

$dp[k][i][j]$ 表示 $i -> j$ 至少经过 $k \cdot 100$ 条路。

然后查询的时候枚举中间点。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-3/solutions/m.cpp
    ---8<--
    ```
