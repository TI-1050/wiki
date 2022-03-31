# ACM-ICPC 2018 南京赛区网络预赛

???+ info "Contents"
    [TOC]

## A. An Olympian Math Problem

`cout << n - 1 << endl;`

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Nanjing-Online/solutions/a.cpp
    ---8<--
    ```

## B. The writing on the wall

题意：

给出 $n \cdot m$ 的矩形，找出有多少个子矩形不包含黑块。

思路：

枚举每一个当右下角的情况，那么情况总数就是黑块构成的边界里面的格子数量，优先队列优化。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Nanjing-Online/solutions/b.cpp
    ---8<--
    ```

## C. GDY

按题意模拟即可，注意细节。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Nanjing-Online/solutions/c.cpp
    ---8<--
    ```

## D. Jerome's House

留坑。

## E. AC Challenge

题意：

有 $n$ 道题目，每次提交得到分数 $t \cdot a_i + b_i$ 有一些题目的提交必须要某些题目提交之后才能提交，求最后获得的最大分数。

思路：

记忆化搜索，二进制标记状态。

或者 状压 DP。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Nanjing-Online/solutions/e.cpp
    ---8<--
    ```

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Nanjing-Online/solutions/e1.cpp
    ---8<--
    ```

## F. An Easy Problem On The Trees

留坑。

## G. Lpl and Energy-saving Lamps

题意：

有 $n$ 个房间，每次按顺序换灯泡，一个房间要不所有灯泡都换，要不一个都不换，每个月有固定的新灯泡数，没还完留到下个月，询问第几个月能够换掉几个房间以及剩下的房间数。

思路：

线段树维护一个最小值，预处理答案。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Nanjing-Online/solutions/g.cpp
    ---8<--
    ```

## H. Set

留坑。

## I. Skr

留坑。

## J. Sum

题意：

定义

$$
F[n] = \mbox{有多少个}n = ab
$$

$a$ 和 $b$ 都不能是平方数的倍数，$1$ 除外。

求：

$$
\sum_{i = 1} ^ {i = n} F[n]
$$

思路：

* 枚举每个素数，对于拥有不同质因子的数，权值乘 $2$。
* 对于拥有两个相同的质因子的数，权值除以 $2$。
* 对于拥有三个或者三个以上质因子的数，权值为 $0$，最后求和。
* （卡常）

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Nanjing-Online/solutions/j.cpp
    ---8<--
    ```

## K. The Great Nim Game

留坑。

## L. Magical Girl Haze

题意：

有 $n$ 个城市，$m$ 条边，可以令 $k$ 条路权值为 $0$，求 $1 \rightarrow n$ 的最短路。

思路：

对于每个城市，枚举到这个城市，免费 $0-k$ 次的权值，跑一个（立体的？）最短路。

??? info "Code"
    ```cpp
    ---8<--
    online/2018-ICPC-Nanjing-Online/solutions/l.cpp
    ---8<--
    ```
