# 2016-2017 ACM-ICPC, NEERC, Southern Subregional Contest

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://codeforces.com/contest/730)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  9/12  |   O   |   O   |   O   |   O   |   O   |   -   |   O   |   O   |   O   |   O   |   -   |   -   |

- O    在比赛中通过
- Ø    赛后通过
- !      尝试了但是失败了
- \-      没有尝试

## Solutions

### A. Toda 2

Solved By Hsueh-. 0:39(+)

题意：

每次选 2-5 个人减一分，问所有人同分时候的最大分数。

思路：

模拟题，显然每次只用 2-3 人，那么：

- 如果只有一个最大的就和次大的一起减一分。
- 如果是偶数则选择两个减一分。
- 如果是奇数则选择三个减一分。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2016-2017-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/a.cpp
    ---8<--
    ```

### B. Minimum and Maximum

Solved By Hsueh-. 1:05(+)

题意：

- 给定数组长度，每次可以询问 $a_i, a_j$ 的大小关系。
- 在只能询问 $\frac{3n}{2}-2$ 次的情况下得出的最大值下标和最小值下标。

思路：

- 先询问相邻的两个，大的放在 Big 里，小的放在 Small 里面，那么这时候询问了 $\frac{n}{2}$ 次，每个数组只有 $\frac{n}{2}$ 个元素。
- 接下来最大值去 Big 里面找，最小值去 Small 里找，分别需要 $\frac{n}{2}-1$ 次，就可以了。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2016-2017-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/b.cpp
    ---8<--
    ```

### C. Bulmart

Solved By Hsueh- & Dup4. 3:09(+3)

题意：

- 有 $n$ 个城市，$m$ 条无向边，有 $w$ 个商店，第 $i$ 个商店座落在第 $i$ 个城市，拥有 $k_i$ 件商品，商品的单价为 $p_i$.
- 现在有 $q$ 次询问，每次询问给出 $g_j, r_j, a_j$，表示某人在 $g_j$ 那个城市，需要买入至少 $r_j$ 件物品，总花费不超过 $a_j$，问最少的时间。
- 这里的购买可以让其他城市邮寄过来，时间是花费最长的那个包裹，边权为 $1$。

思路：

- 先预处理出每个点到其他任意一点的最小距离。
- 然后将每个商店按照单价排序，对于每次询问，二分 $t$，然后贪心去符合要求的商店购买。
- 时间复杂度 $O(nm + nw \log n)$。

其实堆优化可撤销贪心也是可以的，赛后过了(

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2016-2017-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/c.cpp
    ---8<--
    ```

### D. Running Over The Bridges

Solved By Dup4 & Hsueh-. 4:09(+3)

题意：

- 有 $n$ 座桥, 第 $i$ 座桥的长度为 $l_i$，在第 $i$ 座桥上最多的停留时间为 $t_i$，现在有一个人要从第 $1$ 座桥按顺序经过这 $n$ 座桥，它的速度是 $2s$ 走一个单位长度，但是有一种药水，每次喝下后持续 $r$ 个时间单位，使得它能够 $1s$ 走一个单位长度，问这个人最少要喝多少次药水，使得能走完这 $n$ 座桥，在满足上述限制的情况下，如果喝的次数小于等于 $10^5$, 那么要输出喝药水的时刻。

思路：

贪心，对于每座桥，考虑对于这座桥最少要喝几次，然后最后一次喝药水，尽量靠后，把药水的收益留给下一座桥。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2016-2017-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/d.cpp
    ---8<--
    ```

### E. Award Ceremony

Solved By Hsueh- & ltslts. 3:50(+)

题意：

- 每个人有一个起始的分数 $a_i$ 以及一个等待揭晓的分数 $d_i$。
- 假设揭开某人后，他的排名变化 $t$。
- 安排一个揭开分数的顺序使得 $\sum t$ 最大。

思路：

显然对每两个人的排名先后顺序变化研究，然后求 sum 即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2016-2017-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/e.cpp
    ---8<--
    ```

### F. Ber Patio

UnSolved.

题意：

思路：

### G. Car Repair Shop

Solved By Dup4. 0:54(+)

题意：

- 有一个修车店，每一时刻只能修一辆车。
- 现在有 $n$ 辆车，每辆车有 $s_i, d_i$，表示顾客希望从 $s_i$ 时刻开始修，$d_i$ 表示这辆车需要修 $d_i$ 时间。

现在对于每辆车：

- 如果 $[s_i, s_i + d_i - 1]$ 这个时间段没被占用，那么这辆车就被安排在这个时间段修。
- 否则，找一个最小的正整数 $x$，满足 $[x, x + d_i - 1]$ 这个时间段没有汽车修，这个时候 $x \leq s_i$ 是被允许的。

思路：

- 用个容器维护一个二元组，然后问题就相当于判断线段是否相交。
- 对于第二种操作，容易发现贪心的选 $x$，可取的值并不多。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2016-2017-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/g.cpp
    ---8<--
    ```

### H. Delete Them

Solved By Dup4. 0:41(+)

题意：

有 $n$ 个字符串，现在选出 $m$ 个字符串，然后要构造一个模式串，使得模式串能匹配上这 $m$ 个字符串，但是不能匹配上剩下的 $n - m$ 个字符串，模式串中可以有 `?`，但是没有 `*`。

思路：

- 对于 $m$ 个字符串，按位考虑，如果当前位相同，就放特定字符，否则放 `?`。
- 然后拿这个模式串去匹配剩下的 $n - m$个，如果能匹配上就无解。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2016-2017-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/h.cpp
    ---8<--
    ```

### I. Olympiad in Programming and Sports

Solved By Hsueh-. 2:49(+7)

题意：

- 有 $n$ 个学生，两个社团 $A, B$，第 $i$ 个学生加入 $A$ 社团，能给 $A$ 社团带来 $a_i$ 点属性值，加入 $B$ 社团能带来 $b_i$ 点属性，现在要挑选 $p$ 个学生加入 $A$ 社团，$s$ 个学生加入 $B$ 社团，使得带来的属性和最大。
- 问最大属性和。

思路：

费用流。

- 源点向每个人流流量 `1`，费用 `0` 的边。
- 每个人向 `A`, `B` 组流流量 `1`，费用为 $-a_i/-b_i$ 的边。
- `A`, `B` 组分别向汇点流 `p`, `s` 的边。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2016-2017-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/i.cpp
    ---8<--
    ```

### J. Bottles

Solved By Dup4. 1:25(+1)

题意：

- 给出 $n$ 个瓶子，每个瓶子里面有 $a_i$ 升水，每个瓶子的容量是 $b_i$，保证 $a_i \leq b_i$, 现在可以将一个瓶子的水倒入另一个瓶子的水，倒入 $1$ 升水需要一个单位时间。
- 现在要将所有水存放在 $k$ 个瓶子中，使得 $k$ 最少，其次保证所用时间 $T$ 最少。

思路：

- 显然，题目要求找 $k$ 个瓶子，使得这 $k$ 个瓶子的容量和大于等于所有水的体积，并且满足剩下 $n - k$ 个瓶子里装的水最少，即转移的水最少，那么就是选中的 $k$ 个瓶子里装的水越多。
- $f[i][j]$ 表示用了 $i$ 个瓶子，体积为 $j$ 时所拥有的水体积的最大值，然后背包即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2016-2017-ACM-ICPC-NEERC-Southern-Subregional-Contest/solutions/j.cpp
    ---8<--
    ```

### K. Roads Orientation Problem

UnSolved.

题意：

思路：

### L. Expression Queries

UnSolved.

题意：

思路：
