# 2019-2020 ACM-ICPC Brazil Subregional Programming Contest

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://codeforces.ml/gym/102346)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |   M   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 11/13  |   O   |   O   |   -   |   O   |   -   |   O   |   O   |   O   |   O   |   O   |   O   |   O   |   O   |

- O    在比赛中通过
- Ø    赛后通过
- !      尝试了但是失败了
- \-      没有尝试

## Solutions

### A.Artwork

Solved By Hsueh- & ltslts. 0:33(+)

题意：

一个 $n \cdot m$ 的矩阵有 $n$ 个半径为 $R_i$ 的传感器，问能否从 $(0,0)$ 走到 $(n,m)$ 不碰到任何传感器。

思路：

并查集，将 $n$ 个圆并起来，判断左上区域能否与右下区域连通。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/a.cpp
    ---8<--
    ```

### B.Buffoon

Solved By Dup4. 0:07(+)

签到。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/b.cpp
    ---8<--
    ```

### C.Crossings With Danger

Solved By . 0:00(+)

题意：

思路：

### D.Denouncing Mafia

Solved By Dup4 & Hsueh-. 1:39(+1)

题意：

给出一棵树，每次选择一个点，将该点到根的所有点都染色，现在可以选择 $k$ 个点进行染色操作，问最多能染多少个点？

思路：

长链剖分，将每条链剖分出来，然后贪心取$K$条。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/d.cpp
    ---8<--
    ```

### E.Exhibition of Clownfish

Solved By . 0:00(+)

题意：

思路：

### F.Forests in Danger

Solved By Dup4 & ltslts. 4:18(+)

题意：

给出若干条平行于坐标轴的线段和一个四条边都平行于坐标轴的矩形，然后给出一个 $P$，现在要选定一个最小的 $r$，对于每条线段找一个矩形覆盖它，并且保证矩形外的点到这条线段的最短距离为 $r$,要满足这些矩形的面积并和题目给定矩形的面积并大于等于题目给定矩形的面积的 $P \% $。

思路：

二分$r$，然后就是求矩形面积并。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/f.cpp
    ---8<--
    ```

### G.Getting Confidence

Solved By Hsueh-. 1:00(+)

题意：
- $n$ 个物品，$n$ 个货架，$a_{ij}$ 表示物品 $i$ 放在货架 $j$ 的权值，问最大的 $\prod a(i, p_i)$。

思路：

- 取 $log$ 转化为加法，跑费用流。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/g.cpp
    ---8<--
    ```

### H.Hour for a Run

Solved By Hsueh-. 0:06(+)

题意：

操场一圈有 $n$ 个标志，总共跑 $v$ 圈，问 $10 \% \cdots 90 \%$ 会遇到多少障碍物。

思路：

签到。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/h.cpp
    ---8<--
    ```

### I.Interplanetary

Solved By Hsueh-. 3:34(+)

题意：

$n$ 个星球，每个星球又在自己的温度，有 $Q$ 次查询，每次查询问指经过最累或最热的 $K$ 个星球，从 $a$ 到 $b$ 的最短路。

思路：

离线后动态加点跑 Floyd。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/i.cpp
    ---8<--
    ```

### J.Jar of Water Game

Solved By Hsueh-. 2:02(+1)

题意：

一个游戏，总共有 `A23456789DJQK` 和 `wildcard`，$14$ 种牌，按照规则问最后谁赢。

规则如下：

- $n$ 个人坐成一圈，第 $k$ 个人先开始。
- 每个人给自己的下一位，也就是 $1$ 给 $2 \cdots$。
- 如果刚拿到 `wildcard` 则不能将 `wildcard` 给下一家,否则一定给 `wildcard`。
- 否则找到数量最小的给下一家。
- 如果有多个数量最小的则拿出数字最下的。
- 如果一个人手上四张牌都一样则获胜。

思路：

模拟

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/j.cpp
    ---8<--
    ```

### K.Keep Calm and Sell Balloons

Solved By Dup4 & ltslts. 3:14(+)

题意：

- 给出 $2 \cdot N$ 的矩阵，矩阵上的数字从左往右，从上到下，依次为 $1 - 2N$。
- 现在可以任选一个起点出发，每次可以上下左右对角线八个方向走到相邻的并且没有被访问过的点走，问访问完所有点的方案数。

思路：

令 $f[n]$ 表示从 $1$ 出发的方案数。

那么我们考虑怎么递推 $f[n]$：

- 从 $1$ 出发，如果最终回到 $n + 1$，那么每次往右可以选择走上边或者往下边，那么回来回到 $n + 1$ 的路径是固定的，这部分贡献是 $2^{n - 1}$
- 如果第二步走 $n + 1$，那么第三步可以走 $2$ 或者 $n + 2$，容易发现这是一个子问题，方案数为 $2f[n - 1]$。
- 再考虑第三步走 $n + 1$，那么走法是 $1 \to 2 \to n + 1 \to n + 2$ 或者 $1 \to n + 2 \to n + 1 \to 2$，然后就是一个 $n - 2$ 规模的子问题，贡献是 $4f[n - 2]$。

所以有：

$$
\begin{eqnarray*}
f[n] = 2f[n - 1] + 4f[n - 2] + 2^{n - 1}
\end{eqnarray*}
$$

那么四个角的贡献就是 $4f[n]$，我们再考虑中间的贡献。

容易发现，我们发现从第一层的第 $i$ 列出发和从第二层的第 $i$ 列出发的方案数是相同的，所以我们只考虑第一层的第 $i$ 列：

- 显然，它不可能在第二步走到 $n + i$。
- 假设它往右走，方案数为 $2^{n - i}$，然后回到 $n + i$ 这个位置，再往左边走，这部分的方案是 $f[i - 1]$，所以往右走的贡献是 $\displaystyle f[i - 1] \cdot 2^{n - 1}$。
- 同理可得，往左边走的方案数为 $f[n - i] \cdot 2^{i - 1}$。

那么答案就是：

$$
\begin{eqnarray*}
f[n] &=& 4f[n - 2] + 2f[n - 1] + 2^{n - 1} \\
ans &=& 4(f[n] +  \sum\limits_{i = 2}^{n - 1} (f[i - 1] \cdot 2^{n - i} + f[n - i] \cdot 2^{i - 1}) )
\end{eqnarray*}
$$

令 $\displaystyle g[n] = \sum\limits_{i = 2}^{n - 1} f[i - 1] \cdot 2^{n - i}$，有

$$
\begin{eqnarray*}
g[n] = g[n - 1] \cdot 2 + f[n - 2] \cdot 2
\end{eqnarray*}
$$

令$\displaystyle h[n] = \sum\limits_{i = 2}^{n - 1} f[n - i] \cdot 2^{i - 1}$，有

$$
\begin{eqnarray*}
h[n] = h[n - 1] \cdot 2 + f[n - 2] \cdot 2
\end{eqnarray*}
$$

容易发现 $g[n]$ 和 $h[n]$ 是一样的，直接矩阵快速幂即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/k.cpp
    ---8<--
    ```

### L.Less Coin Tosses

Solved By Dup4 & ltslts. 1:07(+)

题意：

有一个硬币，它不是公平的，即掷出正面和反面的概率不同。

现在为了公平，有如下策略：

- 选一个 $n$。
- 那么有 $2^n$ 个 `01串`，Alice 拿一部分，Bob 拿一部分，剩下的舍弃，然后将该硬币投掷 $n$ 次，根据掷出的正反面形成一个长度为 $n$ 的 `01串`，如果该串在 Alice 那部分中，Alice 获胜，如果在 Bob 那部分中，Bob 获胜，否则再来一次。

现在给定 $n$，现在问最少舍弃多少 `01串`，使得该玩法是公平的。

思路：

我们假设投出正面的概率为 $x$，投出反面的概率为 $y$，假设一个长度为 $n$ 的字符串中有 $a$ 个 0，有 $b$ 个 1，那么掷出该 `01串` 的概率为 $x^a \cdot y^b$。

那么可以根据 $(a, b)$ 这个二元组，将所有 `01串` 进行分类，同类的均分给两人，那么容易发现，如果某类字符串是奇数个，那么必然要留下一个。

所以答案就是 $\displaystyle \sum\limits_{i = 0}^n {n \choose i} \% 2 = 2^p$，其中 $p$ 为 $n$ 的二进制表示中 $1$ 的个数。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/l.cpp
    ---8<--
    ```

### M.Maratona Brasileira de Popcorn

Solved By Dup4. 0:33(+)

题意：

有 $n$ 袋爆米花，每袋有 $p_i$ 个爆米花，有 $C$ 个人，每个人每秒钟能够吃 $T$ 个爆米花。

现在有两个限制条件：

- 每个人只能吃一段袋子标号连续的爆米花
- 同一袋里的爆米花只能被同一个人吃

问最少需要多少时间，使得爆米花能被吃完。

思路：

二分时间，贪心 check。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2019-2020-ACM-ICPC-Brazil-Subregional-Programming-Contest/solutions/m.cpp
    ---8<--
    ```
