# 第 17 届浙江省程序设计竞赛

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link]()

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  7/12  |   O   |   O   |   O   |   -   |   O   |   -   |   O   |   !   |   O   |   -   |   O   |   -   |

- O    在比赛中通过
- Ø    赛后通过
- !    尝试了但是失败了
- \-   没有尝试

## Reply

Dup4:

- 杭电真强。
- 太菜了啊，赛时连区间第 $k$ 大都不知道怎么求了啊。
- `Hash` 还是 `Trie`, 傻傻分不清了啊。
- 好像除了第一年打省赛把卡着的那一题过了，之后两年都没过啊？

Hsueh-：

- 老了该退役了，比赛的时候并查集都写的一愣一愣的。
- 几何永远出不来，愿天堂没有计算几何。

## Solutions

### Problem A. AD 2020

Solved By Dup4 & Hsueh-. 01:10(+)

题意：

- 如果一个日期字符串中包含 `202` 这个子串，那么称它为 `Disaster Reduction`。
- 给出一个起始日期和一个终止日期，问这之间的日期有多少个 `Disaster Reduction` ？

思路：

预处理一下，处理一个边边角角。

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/17th-zjpsc/solutions/a.cpp
    ---8<--
    ```

### Problem B. Bin Packing Problem

Solved By all. 00:57(+)

题意：

- 给出 $n$ 个石头，和无限个容量为 $C$ 的箱子，每个石头的容量为 $a_i$。
- 现在要将石头都放进箱子中，现在有两种做法：

对于第 $i$ 个石头：

- 按顺序遍历，遇到能放的就放。
- 找一个最小的并且能放下的箱子，将当前的石头放下。

求出两种做法分别求出所需的箱子数量。

思路：

- 线段树维护箱子容量的最大值，优先走左儿子。
- 用一个 `set` 维护即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/17th-zjpsc/solutions/b.cpp
    ---8<--
    ```

### Problem C. Crossword Validation

Solved By Dup4 & Hsueh-. 02:57(+1)

题意：

- 给出一个 $n \cdot n$ 的字符矩阵，横着竖着以 `#` 分割开若干个字符串，再给出 $m$ 个字典，并且字典中每个字符串都有价值 $v_i$。字典中每个字符串都两两不同。
- 现在要将以 `#` 分割开的每个字符串找到字典中对应字符串的价值累加起来。
- 如果出现一个字符串未出现在字典中，那么输出 $-1$。

思路：

- 直接建立一个 `Trie` 即可，刚开始写了个 `Hash`，被卡了。
- 而且 `Trie` 复杂度非常正确，又不会有冲突。
- 听说自然溢出过了？

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/17th-zjpsc/solutions/c.cpp
    ---8<--
    ```

### Problem D. Dividing the Points

Upsolved By -.

题意：

思路：

### Problem E. Easy DP Problem

Solved By all. 02:09(+)

题意：

给出 $dp[i][j]$ 的转移过程：

$$
dp[i][j] =
\left\{
\begin{array}{c}
0 & (i = 0)\\
i^2 + dp[i - 1][j] & (i > 0, j = 0) \\
i^2 + \max(dp[i - 1][j], dp[i - 1][j - 1] + b[i]) & (i > 0, j > 0)
\end{array}
\right.
$$

然后给出 $n$ 个数 $b_i$，每次询问给出 $l_i, r_i, k_i$，要求用 $b_l, \cdots, b_r$ 进行转移, 求 $dp[m_i][k_i]$。

思路：

- 不考虑 $i^2$，那么这个 dp 的意义是找出区间内最大的 $k$ 个数的和。
- 然后对于 $i^2$，它根本不会影响 dp 过程。
- 所以用主席树多维护一下数的和即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/17th-zjpsc/solutions/e.cpp
    ---8<--
    ```

### Problem F. Finding a Sample

Upsolved By -.

题意：

思路：

### Problem G. Gliding

Solved By Hsueh- & ltslts. 03:33(+1)

题意：

- 给出起点终点，$v_f, v_p, v_h$，表示不开降落伞下落速度，开降落伞下落速度，水平移动速度。
- 给出 $n+1$ 个点,每个点都有一个向上速度为 $v_i$ 的水流，在第 $i$ 个水流上的速度为 $v_i - v_p$。
- 问起点到终点的最短时间。

思路：

- 将二维图转化为简单的图，每两个点之间的距离为 $\displaystyle \frac{dis}{v_h}$。
- 可以肯定每个速度为 $v_i$ 的点会向速度更大的点移动，那么很显然将 $n+1$ 个点按照速度排序，然后从 $f[i]$ 向 $f[j](i \lt j)$ 转移，每次转移时间为水平移动时间以及需要停留的时间。
- 简单的二维 $dp$ 方程转移一下即可。

> PS: 最短路边太多了，可能会 `TLE`。

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/17th-zjpsc/solutions/g.cpp
    ---8<--
    ```

### Problem H. Huge Clouds

Upsolved By -.

题意：

思路：

### Problem I. Invoking the Magic

Solved By Hsueh- & ltslts. 00:16(+)

题意：

有 $n$ 对袜子，有一个机器可以将丢进去的 $x$ 堆袜子配对好，问最小的 $x$。

思路：

- 签到。
- 求连通块大小。

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/17th-zjpsc/solutions/i.cpp
    ---8<--
    ```

### Problem J. Just an Old Problem

Upsolved By -.

题意：

思路：

### Problem K. Killing the Brute-forces

Solved By Dup4. 00:14(+)

题意：

签到题。

思路：

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/17th-zjpsc/solutions/k.cpp
    ---8<--
    ```

### Problem L. List of Products

Upsolved By -.

题意：

思路：
