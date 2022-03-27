# 2018 Multi-University Training Contest 1

???+ info "Contents"
    [TOC]

## A. Maximum Multiple

题意：

给出一个 n 找 x, y, z 使得 $n = x + y +z$ 并且 $n \equiv 0 \pmod x, n \equiv 0 \pmod y, n \equiv 0 \pmod z$ 并且使得 $x \cdot y \cdot z$ 最大。

思路：

设 $a = \frac{n}{x}, b = \frac{n}{y}, c = \frac{n}{z}$ 那么 $\frac{1}{a} + \frac{1}{b} + \frac{1}{c} = 1$ 那么我们考虑去凑 a, b, c。

两种方案 ${3, 3, 3}$ 或者 ${2, 4, 4}$ 取 max。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-1/solutions/a.cpp
    ---8<--
    ```

## B. Balanced Sequence

题意：

求如何拼接，使得 balanced Sequence 最长。

思路：

首先预处理，使得剩下的串都是 `(((` 或者 `)))` 或者 `)))(((`。

`(((` 这种都放左边 `)))` 都放右边。

目前的问题就是 `)))(((` 这种在中间按什么顺序放使得答案最大。

我们定义 $L_1, R_1$  $L_2, R_2$ 分别为两个串的左括号数量和右括号数量：

* 假如 $1$ 放在 $2$ 前面  那么对答案的贡献是 $min(R_1, L_2)$。
* 假如 $1$ 放在 $2$ 后面 那么对答案的贡献是 $min(R_2, L_1)$。

比较对答案的贡献，哪个答案贡献大，选哪种放置方式。

如果读答案的贡献一样大，那么我们让左括号多的放前面，因为这样对后面的答案贡献大。

??? info "Dup4's Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-1/solutions/b.cpp
    ---8<--
    ```

??? info "Hsueh-'s Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-1/solutions/b1.cpp
    ---8<--
    ```

## C. Triangle Partition

水。（排序）

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-1/solutions/c.cpp
    ---8<--
    ```

## D. Distinct Values

按题意模拟即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-1/solutions/d.cpp
    ---8<--
    ```

## E. Maximum Weighted Matching

留坑。

## F. Period Sequence

留坑。

## G. Chiaki Sequence Revisited

题意：

定义 $a_n$，求 $\sum_{i = 1} ^ {i = n} a_i$。

思路：

先不考虑 $a_1$。

我们对每个最后一个 $2$ 的幂次数处理出它前面有多少个数，以及这些数的前缀和是多少。

比如说处理出：

```plain
1 2 4 8 16

1 3 7 15 31

1 5 20 76 288
```

然后给出 $n$ 计算的时候 按二进制拆分 比方说：

$$
27 = 15 + 7 + 3 + 3
$$

定义 $F[i]$ 为 前面 $i$ 个数的前缀和。

$$
ans[27] = F[15] + F[7] + 7 * 8 + F[3] + 3 * (8 + 2) + F[3] + 3 * (8 + 2 + 2)
$$

对于后面，相当于所有数向右偏移。

注意取模。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-1/solutions/g.cpp
    ---8<--
    ```

## H. RMQ Similar Sequence

留坑。

## I. Lyndon Substring

留坑。

## J. Turn Off The Light

留坑。

## K. Time Zone

按题意模拟即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-1/solutions/k.cpp
    ---8<--
    ```
