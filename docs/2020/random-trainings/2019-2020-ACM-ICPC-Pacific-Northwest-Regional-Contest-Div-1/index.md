---
hide:
    - toc
    - navigation
---

# 2019-2020 ACM-ICPC Pacific Northwest Regional Contest (Div. 1)

???+ info "Contents"
    [TOC]

## Contest Info

- [Practice Link](https://codeforces.com/gym/102433)
- [Editorials Link](./assets/2019-2020-ACM-ICPC-Pacific-Northwest-Regional-Contest-Div1-editorials.pdf)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |   M   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  9/13  |   O   |   O   |   O   |   O   |   O   |   -   |   -   |   -   |   O   |   -   |   O   |   O   |   O   |

- O    在比赛中通过
- Ø    赛后通过
- !    尝试了但是失败了
- \-   没有尝试

## Solutions

### A. Radio Prize

Solved By Dup4. 2:26(+)

题意：

给出一棵树，每个点有点权 $t_i$, 每条边有边权 $w_i$, 现在要对于每个点 $i$，计算 $\sum\limits_{j = 1}^n [i \neq j](t_i + t_j) \cdot d(i, j)$，其中 $d(i, j)$ 表示 $i \to j$ 的简单路径的长度。

思路：

将贡献拆成 $t_id(i, j) + t_jd(i, j)$，然后维护距离和、点权和、乘积和，换根 dp 即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Pacific-Northwest-Regional-Contest-Div-1/solutions/a.cpp
    ---8<--
    ```

### B. Perfect Flush

Solved By Hsueh-. 3:00(+1)

题意：

给出 $n$ 个数 $x_i$, 保证 $1 \leq x_i \leq k$，并且保证 $1, \cdots k$ 中每个数至少出现了一次，现在要找出一个字典序最小的子序列，使得这个子序列是一个长度为 $k$ 的排列。

思路：

利用单调栈，如果栈顶元素在后面存在且比当前元素大，则 pop 掉，如果当前元素本身就在栈中则 continue。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Pacific-Northwest-Regional-Contest-Div-1/solutions/b.cpp
    ---8<--
    ```

### C. Coloring Contention

Solved By Hsueh-. 0:48(+)

题意：

- 给出一个 $n$ 个点 $m$ 条边的无向图，没有重边，没有自环，`Alice` 可以将边染成红色或者蓝色，定义一条路径的 `color change` 次数为将路径上经过的边按顺序排列，任意两个相邻的边颜色不同即记一次 `color change`。
- 现在 `Bob` 要选择一条 $1 \to n$ 的路径，问 `Alice` 如果染色，使得 `Bob` 的最优解最大，即 `color change` 次数最多。输出这个最大值。

思路：

- 显然答案的上界为 $1 \to n$ 的 $\mbox{最短路长度} - 1$，猜测一定能有一种方案能够做到。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Pacific-Northwest-Regional-Contest-Div-1/solutions/c.cpp
    ---8<--
    ```

### D. Dividing by Two

Solved By Hsueh-. 0:14(+)

题意：

- 给定两个数字 $A$,$B$，对于 $A$ 有两种操作：
  - 当 $A$ 是偶数则可以除以 $2$。
  - 加一。
- 问最小的操作次数使得 A 变成 B。

思路：

- 如果 $A < B$ 则很显然答案是两者差值。
- 如果 $A = B$ 则很显然答案是 $0$。
- 剩下的模拟即可.

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Pacific-Northwest-Regional-Contest-Div-1/solutions/d.cpp
    ---8<--
    ```

### E. Rainbow Strings

Solved By Hsueh-. 0:18(+)

题意：

定义一个 `rainbow string` 为字符串中任意两个字符都不相同，现在给出一个字符串 $s$，问它有多少个子序列是 `rainbow string`。

思路：

答案为 $\prod (\mbox{每个字符出现次数 + 1})$。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Pacific-Northwest-Regional-Contest-Div-1/solutions/e.cpp
    ---8<--
    ```

### F. Carny Magician

UnSolved.

题意：

思路：

### G. Glow, Little Pixel, Glow

UnSolved.

题意：

思路：

### H. Pivoting Points

UnSolved.

题意：

思路：

### I.Error Correction

Solved By Hsueh- & Dup4. 1:28(+1)

题意：

- 给出 $n$ 个字符串，每个字符串等长，并且任意两个字符不相同，定义任意两个字符串不可以共存当且仅当其中一个字符串可以通过交换一对字符变成另一个字符串，现在要求选出最大的字符串子集，使得其中任意两个字符串都可以共存。

思路：

- 将不能共存的连边，等价于求最大独立集。
- 但是求最大独立集的朴素算法是 $O(n^4)$，但是如果它是二分图，就等价于求最大匹配。
- 那么考虑该图中不会有奇环，因为一次交换可以理解为一个逆序对，一个字符串经过若干次交换回到本身，肯定是经过偶数次交换。
- 那么根据逆序对数量的奇偶性将字符串分成左右两边。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Pacific-Northwest-Regional-Contest-Div-1/solutions/i.cpp
    ---8<--
    ```

### J. Interstellar Travel

UnSolved.

题意：

思路：

### K. Computer Cache

Solved By Dup4. 3:40(+)

题意：

有 $m$ 个数据块，第 $i$ 个数据块的长度为 $s_i$。

有一个 `cache`，支持三种操作：

- `1 i p`, 将第 $i$ 个数据块加载进 `cache`, 起始位置为 $p$。
- `2 p`, 输出 `cache` 中第 $p$ 个位置的数值。
- `3 i l r`, 将第 $i$ 个数据块中的 $[l, r]$ 中每个数字都 $+1 \bmod 256$，即 $x_i = (x_i + 1) \bmod 256$。

思路：

- 考虑查询可能会查询历史版本，容易想到可持久化线段树。
- 但是 $5 \cdot 10^5$ 的数据量，在时间和空间上都不太允许，可以直接离线，记录版本号。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Pacific-Northwest-Regional-Contest-Div-1/solutions/k.cpp
    ---8<--
    ```

### L. Carry Cam Failure

Solved By ltslts. 1:59(+)

题意：

定义十进制下的异或和（即不进位加法），和以此为基础的乘法运算。给出一个 $n$，求 $n$ 在这个规则下的最小的平方根，如果不存在输出 $-1$。

思路：

因为不会进位，所以 $n$ 如果拥有偶数位，肯定不存在平方根，所以平方根的长度为 $\displaystyle \frac{len(n)+1}{2}$。因为 $len(n)<= 25$，并且平方根每一位可能的数字最多只有两个，暴力搜索记录最小的合法的平方根即可，时间复杂度 $\displaystyle O(2^{len(n) / 2})$。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Pacific-Northwest-Regional-Contest-Div-1/solutions/l.cpp
    ---8<--
    ```

### M. Maze Connec

Solved By Hsueh-. 2:10(+)

题意：

思路：

- 存在一张迷宫，将其旋转 $45^o$，问最小破坏几面墙使得所有位置都可以逃出迷宫
- 答案很显然是联通块数量减一，然后研究一下联通规则判断即可

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/2019-2020-ACM-ICPC-Pacific-Northwest-Regional-Contest-Div-1/solutions/m.cpp
    ---8<--
    ```
