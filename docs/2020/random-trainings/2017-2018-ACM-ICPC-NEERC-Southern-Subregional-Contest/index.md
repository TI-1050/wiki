# 2017-2018 ACM-ICPC, NEERC, Southern Subregional Contest

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://codeforces.com/contest/883)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |   M   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 10/13  |   -   |   -   |   Ø   |   O   |   O   |   O   |   O   |   O   |   O   |   O   |   O   |   -   |   O   |

- O    在比赛中通过
- Ø    赛后通过
- !      尝试了但是失败了
- \-      没有尝试

## Solutions

### A. Automatic Door

UnSolved.

题意：

思路：

### B. Berland Army

UnSolved.

题意：

思路：

###  C. Downloading B++

UpSolved by Dup4.

题意：

要下载一个软件，默认的下载速度是 $t_0 s/byte$, 可以花费 $p_1$ 元，买加速包，能够以 $t_1 s/byte$ 下载 $a_1 byte$，或者花费 $p_2$ 元，能够以 $t_2 s/byte$ 下载 $a_2 byte$，问在 $T$ 时间内下载完，最少需要花多少钱。

思路：

枚举一个加速包的用量，二分另一个加速包的用量。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2017-2018-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/c.cpp
    ---8<--
    ```

###  D. Packmen Strike Back

Solved By Hsueh-. 4:29(+)

题意：

一个 $1 \cdot n$ 的图，给上面的每个 `P` 规定一个方向，一旦方向确定就不能更改，问吃到最大的 `*` 的最下时间。

思路：

- 当 `P` 的个数大于等于 $2$ 的时候可以吃到所有的 `*`。
- 那么二分答案去 check。
- $f_i$ 表示前 $i$ 个 $P$ 能覆盖的最大的 $1 - f_i$。
- 对于 $i$ 个 $P$ 有三种转移，分别是向左，向右或者 $i - 1$ 向左 $i$ 向右，$dp$ 去 check。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2017-2018-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/d.cpp
    ---8<--
    ```

###  E. Field of Wonders

Solved By Hsueh-. 1:39(+)

题意：

长度为 $n$ 的字符串，其中有几个位置是不确定的，但是答案只有 $m$ 种，问一定可以成为 `*` 的字符有几个。

思路：

模拟。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2017-2018-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/e.cpp
    ---8<--
    ```

### F. Lost in Transliteration

Solved By Hsueh-. 0:32(+)

题意：

- `u` 可以变成 `oo`。
- `h` 可以变成 `kh`。
- 问有几种字符串？

思路：

- `u` 变成 `oo`。
- 遇到 `h` 删去前面的 `k`。
- 然后去重统计个数。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2017-2018-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/f.cpp
    ---8<--
    ```

###  G. Orientation of Edges

Solved By Hsueh-. 2:38(+)

题意：

一张混合图，有一些有向边和无向边，给定一个起点，分别给无向边定向使得 `S` 到达的点最多最小，独立回答最大最小值。

思路：

- 最大值，贪心的拓展到没到达的点。
- 最小值，贪心的不拓展到其他点。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2017-2018-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/g.cpp
    ---8<--
    ```

### H. Palindromic Cu

Solved By Dup4. 2:01(+1)

题意：

给出一个字符串 $S$，可以将其中的字符重新排列，问能够分成若干个等长的回文串，求分得的最小数量和方案。

思路：

- 考虑串的个数 $k$ 是 $n$ 的因子，然后暴力枚举。
- 如何判断是否合法？

令 $a = \mbox{出现奇数次字符个数}, len = \frac{n}{k}$：

- 如果 $a = 0$，那么输出原串。
- 否则需要满足 $k \geq a$，$(len - 1)$ 是偶数，并且 $(k - a)$ 也是偶数。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2017-2018-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/h.cpp
    ---8<--
    ```

### I. Photo Processing

Solved By Dup4 & Hsueh-. 2:28(+1)

题意：

- 给出 $n$ 个物品，第 $i$ 个物品的权值为 $a_i$，现在考虑将它们分组，每组物品个数不少于 $k$ 个，一组物品的代价为其物品的极差，考虑如何分组使得最大极差最小。
- 输出这个最小的最大极差。

思路：

先二分 $x$，转为判定性问题，然后 $f[i]$ 表示前 $i$ 个物品是否能够被分成若干组，并且每组的极差小于 $x$，然后转移即可，转移部分相当于查询区间和，以及单点修改，但是注意到更新的点和查询的区间点有单调性，直接动态处理前缀和即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2017-2018-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/i.cpp
    ---8<--
    ```

###  J. Renovation

Solved By Dup4. 4:47(+1)

题意：

有 $n$ 个月份，有 $m$ 个城市要拆，每个城市有两个属性 $b_i, p_i$，每个月份会获得 $a_i$ 元钱，一个城市能在第 $i$ 个月份被拆除当且仅当 $b_i \geq a_i$，并且：

$$
p_i \geq \sum\limits_{i = 1}^n - \sum [j \in \mbox{已经被拆除城市}] \cdot p_j
$$

求最多能拆几座城市。

思路：

- 使劲儿贪心。
- 一座城市如果它要被拆，那么拆的越晚，答案肯定不会更差。
- 那么预处理出每座城市最晚什么时候被拆。
- 然后将城市按 $p_i$ 从小到大排序，一一决策，假设当前这座城市能够被拆，那么一定拆。

怎么样能被拆？

- 假设这座城市最晚被拆的时间为 $j$，那么前 $j$ 个月份还剩下的钱要大于等于 $p_i$，然后我们考虑花哪个月份的钱，肯定是小于 $j$，并且离 $j$ 越近的那个月份，这个可以用线段树维护一下，然后暴力去扣钱，一个每个月份只会被扣光一次。
- 时间复杂度 $O(n \log n)$。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2017-2018-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/j.cpp
    ---8<--
    ```

### K. Road Widening

Solved By Hsueh-. 1:05(+)

题意：

$n$ 条路，每条路分为两种，可以将第二种变成第一种，使得满足 $|s_i-s_{i-1}| \leq 1$，问做大的变化长度。

思路：

正着推一遍，倒着推一遍即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2017-2018-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/k.cpp
    ---8<--
    ```

### L. Berland.Taxi

UnSolved.

题意：

思路：

### M. Quadcopter Competition

Solved By Dup4. 0:17(+)

题意：

在二维平面上给出一个起点和一个 `flag`，然后要求从起点出发绕一圈回来，使得 `flag` 严格被包含于这个圈子。

思路：

分共线和不共线讨论，其实也可以归并成一条。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2017-2018-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/m.cpp
    ---8<--
    ```
