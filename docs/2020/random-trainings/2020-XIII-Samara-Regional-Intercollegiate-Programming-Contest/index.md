---
hide:
    - toc
    - navigation
---

# 2020, XIII Samara Regional Intercollegiate Programming Contest

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://codeforces.com/gym/102569)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |   M   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 13/13  |   O   |   O   |   O   |   O   |   O   |   O   |   O   |   O   |   O   |   O   |   O   |   O   |   O   |

- O    在比赛中通过
- Ø    赛后通过
- !    尝试了但是失败了
- .    没有尝试

## Solutions

### A. Array’s Hash

Solved By Hsueh-. 0:29(+)

题意：

- 给定一个序列，每次将 $a_2$ 和 $a_1$ 拿出来，然后将 $a_2-a_1$ 插入到序列中，问最后的序列结果。
- 但是现在有 $k$ 次操作，每次将 $[L_i,R_i]$ 区间内所有数字加上 $v_i$.

思路：

- 如果 $n$ 是奇数，答案是奇数位置的和减去偶数位置的和，如果 $n$ 是偶数，则相反。
- 那么对于每个操作统计有多少个技术位置和偶数位置，加加减减乘乘就好了。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/a.cpp
    --8<--
    ```

### B. Bonuses on a Line

Solved By Dup4. 0:18(+)

题意：

有 $n$ 个物品，分别在 $x_i$ 的位置上，你当前在 $x = 0$ 的位置上，每秒可以向左或者向右移动一格，如果所在的位置有物品，那么捡起该物品，反复经过同一位置物品不会计算多次，问在 $t$ 时间内，最多捡起多少物品。

思路：

只会转向一次，讨论一下即可。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/b.cpp
    --8<--
    ```

### C. Manhattan Distance

Solved By Dup4. 3:53(+2)

题意：

给出 $n$ 个二维平面上的点，定义一个点对的权值为这两个点的曼哈顿距离，现在要输出第 $k$ 小的点对的权值。

思路：

- 二分权值，转化成计数问题。
- 将曼哈顿距离转化成切比雪夫距离，转化成矩形框内的计数问题。
- 时间复杂度 $O(n \log n \log V)$，其中 $V$ 为距离的范围。
- 需要卡常，注意到有单调性，可以适当的一些排序操作转化成有序表的合并。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/c.cpp
    --8<--
    ```

### D. Lexicographically Minimal Shortest Path

Solved By Hsueh-. 1:48(+)

题意：

有 $n$ 个点 $m$ 条边的无向图，无重边和自环，但是每条边上有一个小写字母 $c$, 找 $1 \to n$ 的最短路，如果有多少，输出字典序最小的那条，这里的字典序指的是最短路上的边上的字母按顺序链接组成的字符串字典序。

思路：

- 从 $n$ 出发跑一个最短路，然后再从 $1$ 出发，每次去找是最短路同时字母最小的，如果有多个最小的，那就用 vector 存起来，每个节点都跑一次。
- 由于是分层图，每个点只会被放在 vector 里面一次，所以复杂度为 $O(m+nlog_2n)$。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/d.cpp
    --8<--
    ```

### E. Fluctuations of Mana

Solved By Hsueh-. 0:15(+1)

题意：

有 $n$ 个坐标，每走到第 $i$ 个位置，自身法力值会变化 $a_i$，如果法力值 $\leq 0$ 就会死亡，求刚开始的最小法力值。

思路：

统计前缀和，然后看最小的负值，那么刚开始法力值就要为最小的负数的相反数。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/e.cpp
    --8<--
    ```

### F. Moving Target

Solved By Hsueh-. 0:54(+)

题意：

- 有 $n$ 个窗户，有一个目标在某一个窗户后面，但是并不知道在哪个窗户后面。
- 现在可以射击，如果没有击中，并且目标不在第 $n$ 个窗户后面，那么目标会往右边移动一个窗户的位置，问最少的射击次数保证不管目标在哪儿，都能将他击中。
- 给出射击的位置序列。

思路：

为什么只射击 $1$, $n$ 和奇数位置上的窗户就可以了，有更小的射击次数序列吗？

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/f.cpp
    --8<--
    ```

### G. Nuts and Bolts

Solved By Hsueh- & ltslts. 3:00(+)

题意：

- 有 $n$ 个 `A` 物品，和 $n$ 个 `B` 物品，所有的 `A` 物品的大小为 $[1, n]$ 且两两不同，`B` 物品亦如此。
- 但是并不知道第 $i$ 个物品的大小，可以询问 $5n \log n$ 次，每次询问给出 $(i, j)$，根据第 $i$ 个 `A` 物品和第 $j$ 个 `B` 物品的大小关系返回 `<`, `=`, `>` 三种结果。
- 最后要输出一个排列，表示第 $i$ 个 `A` 物品和第 $p_i$ 个 `B` 物品的大小相同。

思路：

类似于快排，每次将 $L,R$ 两个集合分成小于 $pos$ 和大于 $pos$ 的数字，然后不断递归下去，复杂度大约为 $O(n \log n)$, 统计次数大概是 $n \log n$。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/g.cpp
    --8<--
    ```

### H. Tree Painting

Solved By All. 0:23(+)

题意：

给出一棵树，每次能够选择两个节点，将这两个节点之间的简单路径上的所有点和边都涂色，问最少几次操作能够将这棵树的所有点和边都涂色。

思路：

答案为 $\frac{\mbox{度数为1的点的个数} + 1}{2}$。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/h.cpp
    --8<--
    ```

### I. Sorting Colored Array

Solved By Dup4 & ltslts. 0:32(+)

题意：

有 $n$ 个数字，每个数字有一种颜色 $c_i$，和一个权值 $a_i$, 每次可以选择任意两个相邻的并且颜色不同的数字进行交换，问能否在有限步内使得该序列变成升序。

思路：

显然同一种颜色的数字的相对位置不会改变，不用颜色的可以任意交换，那么只需要判断每一种颜色对应的子序列是否为升序即可。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/i.cpp
    --8<--
    ```

### J. The Battle of Mages

Solved By Hsueh- & ltslts. 2:06(+)

题意：

构造两个长度为 $n,m(3 \leq n, m \leq 10)$ 的序列，使得分别随意选取一个或三个序列中的元素，然后序列一的和大于序列二的和的概率高，分别随意选取两个序列中的元素，然后序列一的和大于序列二的和的概率低

思路：

快乐打表题。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/j.cpp
    --8<--
    ```

??? info "打表代码"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/j_print_table.cpp
    --8<--
    ```

### K. Table

Solved By ltslts. 1:14(+)

题意：

给出一个桌子的4条桌腿长度，要求桌腿安装垂直于桌面，并且桌腿在桌面的投影为一个矩形的4个顶点，判断可否使得桌子稳定站立（桌面可以倾斜）

思路：

![](./images/1586164389_81518.png)

- 以桌面为底面，只要使得 $ABCD$ 四点共面，桌子即可稳定。
- 因为底面的四边形为矩形，所以只要证明 $AB=CD$ 或者 $AC=BD$ 即可证明四边形 $ABDC$ 是平行四边形。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/k.cpp
    --8<--
    ```

### L. The Dragon Land

Solved By Hsueh- & ltslts. 0:59(+)

题意：

- 有 $n$ 只恐龙，打败第 $i$ 只恐龙可以获得 $a_i$ 的金币，但是要扣除花费，花费为你已经击败过的恐龙个数 $+1$，这里是先加上金币，再扣除花费。
- 按顺序打恐龙，每次可以选择打或者不打，问最大收益。

思路：

- 很显然顺序是随意的，因为打的恐龙一样，收益一样，个数一样，所以最终结果一样。
- 对恐龙排序，找最大的几个打。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/l.cpp
    --8<--
    ```

### M. Notifications

Solved By Hsueh-. 0:39(+)

题意：

- 有 $n$ 个任务，每个任务有到达时间和持续时间，为需要多久才能完成所有任务。

思路：

- 模拟。

??? info "Code"
    ```cpp
    --8<--
    2020/random-trainings/2020-XIII-Samara-Regional-Intercollegiate-Programming-Contest/solutions/m.cpp
    --8<--
    ```
