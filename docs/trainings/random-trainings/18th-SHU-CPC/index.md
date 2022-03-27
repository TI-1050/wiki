# “科大讯飞杯”第18届上海大学程序设计联赛春季赛暨高校网络友谊赛

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://ac.nowcoder.com/acm/contest/5278#question)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 12/12  |   O   |   O   |   O   |   O   |   O   |   O   |   Ø   |   O   |   Ø   |   Ø   |   O   |   O   |

- O    在比赛中通过
- Ø    赛后通过
- !      尝试了但是失败了
- \-      没有尝试

## Solutions

### A. 组队比赛

Solved By Hsueh-. 0:04(+)

签到。

### B. 每日一报

Solved By Hsueh-. 0:20(+2)

签到。

### C. 最长非公共子序列

Solved By Hsueh-. 0:07(+)

签到。

### D. 最大字符集

Solved By Hsueh-. 0:41(+)

思路：

特判 $1$ 和 $2$，然后对于 $n > 2$ 的，如下构造：

例如 $n = 5$：

```plain
00
010
0110
01110
```

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/18th-SHU-CPC/solutions/d.cpp
    ---8<--
    ```

### E. 美味的序列

Solved By ltslts. 0:16(+)

思路：

下降的美味度是固定的。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/18th-SHU-CPC/solutions/e.cpp
    ---8<--
    ```

### F. 日期小助手

Solved By Dup4. 0:37(+)

思路：

找出当年和下年的母亲节、父亲节，取合法的，最小的。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/18th-SHU-CPC/solutions/f.cpp
    ---8<--
    ```

### G. 血压游戏

UpSolved By Dup4.

思路：

考虑只有同一深度的点才会打架，那么可以直接做一个基于深度的 dp，听群里说按深度分类，对每个虚树 dfs 也可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/18th-SHU-CPC/solutions/g.cpp
    ---8<--
    ```

### H. 纸牌游戏

Solved By Hsueh- & ltslts. 4:56(+7)

思路：

- 贪心取前 $k$ 个，然后如果不合法，考虑修改几位，显然最多修改两位，因此进行分类：
  - 从小到大暴力判断每一位修改为 $9-0$ 的结果。
  - 修改两位同样是从小到大暴力修改每一位，考虑到当前是修改两位，所以只可能是选两个数字改为 $\% \; 3$ 后减少一或者 $\% \; 3$ 后增加一，暴力判断即可。
- 最后排序一下判断三种情况大小
- 注意特判前导零

```plain
1
733110 3
```

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/18th-SHU-CPC/solutions/h.cpp
    ---8<--
    ```

### I. 古老的打字机

UpSolved By Dup4.

思路：

- 假设我们知道敲击 $i$ 次，字符串长度为 $j$ 的字符串个数，那么可以这么统计答案：
  - 对于每个 $s_i$，假设串 $t$ 的长度为 $n$，那么一共有 $n - |s_i| + 1$ 个起点，再乘上它的价值 $v_i$，以及敲击 $m$ 次长度为 $n$ 的字符串个数 $f[m][i]$，但是要除去 $26^{|s_i|}$，因为这 $|s_i|$ 个位置是确定了的。
  - 那么再考虑如何求 $f[i][j]$，直接 dp 即可，有如下转移：

$$
\begin{eqnarray*}
f[i][j] =
\left\{
\begin{array}{cccc}
f[i - 1][0] + f[i - 1][1] && j = 0 \\
f[i - 1][j - 1] * 26 && j = i \\
f[i - 1][j - 1] * 26 + f[i - 1][j + 1] && other
\end{array}
\right.
\end{eqnarray*}
$$

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/18th-SHU-CPC/solutions/i.cpp
    ---8<--
    ```

### J. 能到达吗

UpSolved By Dup4.

思路：

- 考虑暴力怎么做，每个点往四周合并，一个联通块的贡献是 $\displaystyle {n \choose 2} + n$。
- 那么对于 $n \cdot m$ 的图，按行枚举，每一行连续的空地缩成一个点，这样对于单组数据的复杂度是对的。
- 但是这里是 $T$ 组数据，所以不能按行枚举，只能枚举有障碍物的行，对于连续的整行都是空地的行也要缩点。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/18th-SHU-CPC/solutions/j.cpp
    ---8<--
    ```

### K. 迷宫

Solved By Dup4. 3:36(+3)

思路：

- 从起点和终点分别 bfs 到每个点的最短路，然后枚举一个点，相当于找矩形框内的最小值。
- 注意到矩形框大小一致，考虑从上往下枚举，每次多一行，用 $m$ 个单调队列维护每一列 $2d$ 个元素的最小值，然后从左往右枚举的时候，再来一个单调队列。
- 赛时比较蠢，无脑了一个线段树，但实际上出题人可以直接卡到 $O(nm)$。

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/18th-SHU-CPC/solutions/k.cpp
    ---8<--
    ```

### L. 动物森友会

Solved By Hsueh-. 3:11(+)

思路：

考虑二分时间，那么我们就知道了每个日子有几天，建立网络流去判断，其中左边为任务，向右边的星期几流需要的需求

??? info "Code"
    ```cpp
    ---8<--
    trainings/random-trainings/18th-SHU-CPC/solutions/l.cpp
    ---8<--
    ```
