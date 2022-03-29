# 2018 Multi-University Training Contest 7

???+ info "Contents"
    [TOC]

## A. Age of Moyu

题意：

给出一张图，从 $1$ 走到 $n$，如果相邻两次走的边的权值不同，花费 $+1$，否则花费相同，求最小花费。

思路：

用 set 记录有当前点的最小花费有多少种方案到达，然后最短路。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-7/solutions/a.cpp
    ---8<--
    ```

## B. AraBellaC

留坑。

## C. YJJ’s Stack

留坑。

## D. Go to school

留坑。

## E. GuGuFishtion

留坑。

## F. Lord Li's problem

留坑。

## G. Reverse Game

留坑。

## H. Traffic Network in Numazu

题意：

两种操作：

* 第一种是更改一条边权的值。
* 第二种是查询 $x \rightarrow y$ 的最短路径。

给出的是一颗树加一条边。

思路：

将形成环的边单独拿出来考虑。

那么考虑是否经过这条边使得答案更优。

修改操作用线段树或者树状数组维护。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-7/solutions/h.cpp
    ---8<--
    ```

## I. Tree

题意：

一棵树种，每个点有一个权值，表示可以向上跳几步，两种操作，一种是修改某点权值，还有一种是询问某个点需要跳几次跳出。

思路：

DFS 序分块，弹飞绵阳升级版，注意更新的时候，维护一个 $In[u]$ 表示最远跳到块内是第几块，这样就不用多一个 $log$ 复杂度。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-7/solutions/i.cpp
    ---8<--
    ```

## J. Sequence

题意：

求：

$$
F_n = C * F_{n - 2} + D * F_{n - 1} + \lfloor{\frac {p}{n}}\rfloor
$$

思路：

考虑最后一项最多有 $\sqrt n$ 项，按这个值分块矩阵快速幂即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-7/solutions/j.cpp
    ---8<--
    ```

## K. Swordsman

题意：

有五种攻击属性，怪物有五种防御属性，所有攻击属性要大于其对应的防御属性便能将其击杀，击杀后有经验加成，求最多杀死多少怪物。

思路：

用 $5$ 个 set 依次维护即可。

??? info "Code"
    ```cpp
    ---8<--
    trainings/2018-Multi-University-Trainings/Contest-7/solutions/k.cpp
    ---8<--
    ```
