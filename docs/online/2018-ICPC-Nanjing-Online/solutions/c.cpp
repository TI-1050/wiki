#include <bits/stdc++.h>
using namespace std;

int Move[] = {
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        12,
        13,
        1,
        2,
};

struct DT {
    int num[15], cnt;
    int score;
    inline DT() {
        score = 0;
        cnt = 0;
        memset(num, 0, sizeof num);
    }
    inline void Get() {
        for (int i = 1; i <= 13; ++i) score += num[i] * i;
    }
} arr[250];

int t, n, m;
queue<int> q;

inline void work() {
    int turn = 1, pre = -1, tot = 0, nx;
    for (int i = 0; i < 13; ++i)
        if (arr[1].num[Move[i]]) {
            pre = Move[i];
            --arr[1].num[Move[i]];
            --arr[1].cnt;
            break;
        }
    while (true) {
        turn = turn % n + 1;
        if (tot == n - 1) {
            for (int i = turn; i <= n; ++i)
                if (!q.empty()) {
                    ++arr[i].cnt;
                    ++arr[i].num[q.front()];
                    q.pop();
                }
            for (int i = 1; i < turn; ++i)
                if (!q.empty()) {
                    ++arr[i].cnt;
                    ++arr[i].num[q.front()];
                    q.pop();
                }
            for (int i = 0; i < 13; ++i)
                if (arr[turn].num[Move[i]]) {
                    --arr[turn].num[Move[i]];
                    if (--arr[turn].cnt == 0)
                        return;
                    pre = Move[i];
                    tot = 0;
                    break;
                }
        } else if (pre == 2)
            tot++;
        else {
            if (pre == 13)
                nx = 1;
            else
                nx = pre + 1;
            if (arr[turn].num[nx]) {
                --arr[turn].num[nx];
                if (--arr[turn].cnt == 0)
                    return;
                pre = nx;
                tot = 0;
            } else {
                if (arr[turn].num[2]) {
                    --arr[turn].num[2];
                    if (--arr[turn].cnt == 0)
                        return;
                    pre = 2;
                    tot = 0;
                } else
                    tot++;
            }
        }
    }
}

inline void Run() {
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        while (!q.empty()) q.pop();
        printf("Case #%d:\n", kase);
        scanf("%d%d", &n, &m);
        for (int i = 1, u; i <= m; ++i) {
            scanf("%d", &u);
            q.emplace(u);
        }
        for (int i = 1; i <= n; ++i) {
            arr[i] = DT();
            for (int j = 1; j <= 5; ++j) {
                if (!q.empty()) {
                    arr[i].num[q.front()]++;
                    q.pop();
                    ++arr[i].cnt;
                }
            }
        }
        work();
        for (int i = 1; i <= n; ++i) {
            arr[i].Get();
            if (arr[i].score == 0)
                puts("Winner");
            else
                printf("%d\n", arr[i].score);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();
    return 0;
}