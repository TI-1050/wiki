# 2019-2020 ACM-ICPC Latin American Regional Programming Contest

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://codeforces.com/gym/102428)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |   M   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  9/13  |   -   |   -   |   Ø   |   O   |   O   |   -   |   O   |   Ø   |   O   |   -   |   O   |   O   |   O   |

- O    在比赛中通过
- Ø    赛后通过
- !      尝试了但是失败了
- \-      没有尝试

## Solutions

### A. Algorithm Teaching

UnSolved.

题意：

思路：

### B. Build the Perfect House

UnSolved.

题意：

思路：

### C. Cut Inequality Down

UpSolved by Dup4.

题意：

有一个序列 $a_i$，长度为 $n$，和两个参数 $L, U$，现在每次询问给出 $B, E, X$，要求作如下操作：

- 令 $i$ 从 $B$ 遍历到 $E$。
- 然后令 $\displaystyle X = max(L, min(R, X + a_i))$。
- 输出最后的 $X$。

思路：

- 考虑对于每一次查询，可以 $O(\log n)$ 的时间找到下一个变化的点，那么从下一个变化的点开始往下走，那么容易发现从下一个变化的点开始走的初始值要么是 $L$，要么是 $U$，那么我们可以将每个 $a_i$ 拆成两个点，一个是起始值为 $L$，从第 $i$ 个点开始往下走，一个是起始值为 $U$，从第 $i$ 个点开始往下走，发现会形成树形结构。
- 那么我们每次从初始值找到第一个变化的点之后直接在树上倍增即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Latin-American-Regional-Programming-Contest/solutions/c.cpp
    ---8<--
    ```

### D. Dazzling stars

Solved By Hsueh-. 3:47(+1)

题意：

- 有 `n` 个星星，每个星星有坐标和亮度，问是否存在一个方向，使得这个方向过来亮度从高到低递减。

思路：

处理出每对从亮的到暗的方向向量范围，看有没有交集。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Latin-American-Regional-Programming-Contest/solutions/d.cpp
    ---8<--
    ```

### E. Eggfruit Cake

Solved By Dup4. 0:14(+)

题意：

给出一个字符串环，里面只有 `E` 和 `P` 两种字符，现在问有多少区间，满足这个区间长度小于等于 $S$，并且里面至少有一个 `E`。

思路：

复制一遍，拓展成 $2n$，然后扫一遍即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Latin-American-Regional-Programming-Contest/solutions/e.cpp
    ---8<--
    ```

### F. Fabricating Sculptures

UpSolved by Dup4.

题意：

堆箱子，最底层有 $S$ 个，一共有 $B$ 个箱子，一层一层往上堆，每一层必须连续，且个数不超过之前那一层，并且当前层的箱子必须都要上一层的箱子之上。

思路：

$f[i][j]$ 表示用了 $i$ 个箱子，最上层有 $j$ 个，那么转移有：

$$
f[i][j] = \sum\limits_{k = j}^S f[i - k][k] \cdot (k - j + 1)
$$

然后维护 $f[i][j] \cdot j$ 以及 $f[i][j]$ 的后缀和即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Latin-American-Regional-Programming-Contest/solutions/f.cpp
    ---8<--
    ```

### G. Gluing Pictures

Solved By Dup4. 0:54(+)

题意：

给出一个字符串 $S$，有 $q$ 次询问，每次询问给出一个字符串 $T$，问 $T$ 最少能分成多少段，使得每段都是 $S$ 的一个子串。

思路：

- 考虑 $f[i]$ 表示 $T$ 中的前 $i$ 个字符最少需要多少段，显然 $f$ 具有单调不减性质。
- 然后我们对 $S$ 建 `SAM`，然后用 $T$ 在 `SAM` 上跑匹配，如果不能往下拓展了就跳后缀，维护当前匹配的最长后缀长度，进行转移即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Latin-American-Regional-Programming-Contest/solutions/g.cpp
    ---8<--
    ```

### H. Hold or Continue?

UnSolved.

题意：

思路：

### I. Improve SPAM

Solved By Hsueh-. 1:00(+)

题意：

给定一个 `DAG` 的 SPAM，其中有 `L` 个邮件列表，$n$ 个客户，邮件列表会像里面的邮件客户端的人发邮件，问从 `1` 开始发邮件，用户客户端会收到多少邮件，有多少用户收到邮件。

思路：

搜索水题。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Latin-American-Regional-Programming-Contest/solutions/i.cpp
    ---8<--
    ```

### J. Jumping Grasshoper

UnSolved.

题意：

思路：

### K. Know your Aliens

Solved By Dup4. 1:23(+)

题意：

- 给出一个长度为 $n$ 的字符串 $S$，字符串中只有 `H` 和 `A` 两种字符。
- 现在要构造一个多项式 $P$，对于第 $i$ 个字符：
  - 如果是 `H`，那么要满足 $P(2i) > 0$。
  - 如果是 `A`，那么要满足 $P(2i) < 0$。

这个多项式要满足系数和根均为整数，最高项系数只能为 $1$ 和 $-1$，并且在所有可行答案中最高项要尽可能小。

思路：

- 考虑将多项式写成 $\prod (a_i - x)$ 的形式，那么如果 $P(2i) < 0$，即有奇数个小于 $0$ 的数相乘，否则是偶数个。
- 那么考虑字符串中每个 `H` 和 `A` 的变换的地方，假设第 $i$ 和第 $i + 1$ 个字符不同，那么我们在多项式中插入 $(i \cdot 2 + 1 - x)$，即可符合题意。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Latin-American-Regional-Programming-Contest/solutions/k.cpp
    ---8<--
    ```

### L. Leverage MDT

Solved By Hsueh-. 1:42(+)

题意：

- 给出一个 01 二维矩阵，每次可以将某一行的状态翻转，问任意翻转后，能否找一个最大的正方形，使得正方形内全是 $0$，问最大的正方形面积是多少。

思路：

- 题意等价于找一个最大的正方形，使得正方形内每一行元素一致。
- 先对每一行处理出当前点往后有多少个连续相同的元素，然后二分正方形边长 $x$，然后用同样的思想对于每一列按行枚举进行 check 即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Latin-American-Regional-Programming-Contest/solutions/l.cpp
    ---8<--
    ```

### M. Mountain Ranges

Solved By Hsueh-. 0:08(+)

题意：

问最长的增量不超过 $x$ 的序列。

思路：

签到。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Latin-American-Regional-Programming-Contest/solutions/m.cpp
    ---8<--
    ```
