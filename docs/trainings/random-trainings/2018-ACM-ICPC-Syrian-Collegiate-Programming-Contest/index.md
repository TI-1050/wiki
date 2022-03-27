# 2018 ACM-ICPC, Syrian Collegiate Programming Contest

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://codeforces.ml/gym/102006)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 10/12  |   O   |   O   |   O   |   O   |   -   |   O   |   O   |   O   |   O   |   O   |   O   |   -   |

- O    在比赛中通过
- Ø    赛后通过
- !      尝试了但是失败了
- \-      没有尝试

## Solutions

### A. Hello SCPC 2018!

Solved By Hsueh-. 0:04(+)

题意：

- 判断十二个数字是否满足；
  - 前4个递增
  - 后面8个严格大于前4个

思路：

模拟。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2018-ACM-ICPC-Syrian-Collegiate-Programming-Contest/solutions/a.cpp
    ---8<--
    ```

### B. Binary Hamming

Solved By Dup4. 0:10(+)

题意：

- 给出两个 `01` 串，可以打乱字母排列顺序，使得两个 `01` 串的汉明码距离最大。

思路：

尽可能贪心放 `01` 使得同一位不同即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2018-ACM-ICPC-Syrian-Collegiate-Programming-Contest/solutions/b.cpp
    ---8<--
    ```

### C. Portals

Solved By Dup4. 1:00(+)

题意：
有一个 $1 \cdot n$ 的迷宫，`.` 表示空地，`#` 表示障碍物，`o` 表示传送门(即含有 `o` 的格子都可以互相到达), `s` 表示起点，`e` 表示终点。
现在可以将 `#` 边成 `.`，问最少的次数使得 `s` 不能到达 `e`。

思路：

- 需要最多的次数是 $2$，并且可以发现肯定是将离 `s` 或者 `e` 最近的 `.` 更改掉，分类讨论一下然后判连通即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2018-ACM-ICPC-Syrian-Collegiate-Programming-Contest/solutions/c.cpp
    ---8<--
    ```

### D. Carnival Slots

Solved By Heush-. 1:44(+)

题意：

- 一张 $n \cdot m$ 的的图，你可以任意修改 `\`,`/` 使得每列掉下来的权值数量和最大。

思路：
- 记忆化搜索。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2018-ACM-ICPC-Syrian-Collegiate-Programming-Contest/solutions/d.cpp
    ---8<--
    ```

### E. 2Nodes

UnSolved.

题意：

- 有一棵树，每个点有颜色(白、红、蓝)，每秒钟，对于每个白色节点，如果它相邻的节点中存在非白色的，那么就将当前节点染色成那个节点的颜色，如果有多个，那么选取标号最小的那个点的颜色作为当前点的染色。
- 现在最多能将 $2$ 个点变成白色，问如何变使得最终红色点最多？

思路：

### F. Pretests

Solved By Dup4. 2:45(+2)

题意：

- 对于一个题目，有 $t$ 组数据，有 $n$ 份待评测的程序，每份程序如果挂在了第 $k$ 个点，那么它需要的测试时间为 $k$，如果通过所有数据，那么测试的时间为 $t$，现在给出每份程序对于每个点的通过情况，可以重新安排测试点的顺序，使得总的测试时间最小。
输出字典序最小的方案。

思路：

- $f[S]$ 表示前 $i$ 个测试点的集合为 $S$，需要的最少测试时间，然后枚举一个 $j$ 进行转移，$j$ 要包含在 $S$ 中。
- 然后发现额外的贡献是测试程序的通过测试点的集合是 $S$ 的超集，然后这部分贡献可以用高维前缀和预处理。
- 总时间复杂度 $O(n \cdot 2^n)$，对于字典序，直接记录一个 `string` 即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2018-ACM-ICPC-Syrian-Collegiate-Programming-Contest/solutions/f.cpp
    ---8<--
    ```

### G. Is Topo Logical?

Solved By Dup4. 3:22(+1)

题意：

- 给出一个 $n$ 和两个入度数组 $a, b$，要求构造一个 $n$ 个点的有向图，满足刚开始时第 $i$ 个点的入度为 $a_i$，跑完拓扑排序后第 $i$ 个点的度数为 $b_i$。

思路：

- 基于 $b$ 数组中是否为 $0$ 将点分成两部分，为 $0$ 的那部分组成一条链，不为 $0$ 的那部分组成一个环。
- 然后根据入度连边即可，根据 $a_i, b_i$ 讨论一下入度的来源。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2018-ACM-ICPC-Syrian-Collegiate-Programming-Contest/solutions/g.cpp
    ---8<--
    ```

### H. Bugged System

Solved By Hsueh-. 1:29(+4)

题意：

- 一个地铁站，有 $n$ 个站，但是存在一个 bug，如果一个人从 $a$ 站进站 $b$ 站出来则不用钱，人们可以交换地铁卡。
- 问 $n$ 个人分别从 $s_i$ 进站，$d_i$ 出站，是否存在一个方案使得大家不花钱。
- 如果存在则输出最小行动距离和。

思路：

- 很显然如果存在则是一个环，那么每个站的进站数量等于出站数量，距离就是每个人的行动距离

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2018-ACM-ICPC-Syrian-Collegiate-Programming-Contest/solutions/h.cpp
    ---8<--
    ```

### I. Rise of the Robots

Solved By Hsueh-. 2:34(+3)

题意：

- 一个半径为$R$的图，一个半径为 $r$ 机器人，经过 $n$ 次操作，每次操作都从 $(x,y)$ 到 $(x+dx_i, y+dy_i)$，问是否存在一个起点，使得机器人没有出整个圆。

思路：

- 猜测可以求出一个圆表示机器人的路径，那么求一个最小覆盖圆即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2018-ACM-ICPC-Syrian-Collegiate-Programming-Contest/solutions/i.cpp
    ---8<--
    ```

### J. Clarifications

Solved By Dup4 & Hsueh-. 4:19(+)

题意：

- 在一场时长为 $m$ 的比赛中，有 $n$ 个问题，有 $k$ 个种类的问题，有两个回答的人 `A` 和 `B`，`A` 能在任何时刻回答任何问题，`B` 只能回答在这之前 `A` 回答过的问题中相同种类的问题。
- 每个问题有两个参数 $t_i, p_i$，分别表示询问的时刻和种类。现在问基于上述限制条件，回答完所有问题最少需要多少时间。

思路：

- 考虑已经被 `A` 回答过的种类是没有区别的，并且优先级最低。
- 然后考虑还没有回答过的，但是已经在队列中了，我们根据他们在队列中出现的次数进行优先级排序，对于 `A` 来说，每次取优先级最高的出来回答掉，然后释放出一些问题，可以让 `B` 也一起帮忙回答。
- 但是如果有两个问题的出现次数相同，我们可以将下一秒会出现的问题也纳入考量之中。
- 维护优先级的操作可以用线段树维护。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2018-ACM-ICPC-Syrian-Collegiate-Programming-Contest/solutions/j.cpp
    ---8<--
    ```

### K. Tourists' Tour

Solved By Dup4 & Hsueh-. 1:11(+1)

题意：

- 有 $n$ 座山峰，每座山峰的高度为 $h_i$，对于第 $i$ 座山峰，如果它左边有比他高的山峰，那么它会找一座离它最近的并且比它高的然后在这之间建立一座桥(即连一条边)。
- 对于右边亦是如此，现在要对这些边进行染色，使得任意两条相邻的边不同色，注意边是无向边。

思路：

强制让高的山峰连向低的山峰，变成 DAG，然后暴力染色即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/2018-ACM-ICPC-Syrian-Collegiate-Programming-Contest/solutions/k.cpp
    ---8<--
    ```

### L. Sad Meals

UnSolved.

题意：

- 有一个厨师做菜，假设他在第 $i$ 天之前已经会了 $x$ 道菜了。
- 那么他在第 $i$ 可能学新菜，即 $a_i = x + 1$。
- 也可能顺着前一天的顺序做菜，即 $a_i = a_{i - 1} + 1$。
- 如果前一天做完了已经学会的菜，那么就重新开始轮回，即做第一道菜$a_i = 1$。
- 现在给出$a$数组，但是挖空了一些位置，要求补充上这些位置，使得满足上述限制条件。

思路：
