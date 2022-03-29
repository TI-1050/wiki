#include <bits/stdc++.h>
using namespace std;

namespace FastIO {
#define BUF_SIZE 10000005
bool IOerror = false;
inline char NC() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if (p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if (pend == p1) {
            IOerror = true;
            return -1;
        }
    }
    return *p1++;
}

inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

template <typename T>
inline void read(T &x) {
    char ch;
    while (blank(ch = NC()))
        ;
    if (IOerror) {
        x = -1;
        return;
    }
    bool flag = false;
    if (ch == '-') {
        flag = true;
        ch = NC();
    }
    if (!isdigit(ch))
        while (!isdigit(ch = NC()))
            ;
    for (x = ch - '0'; isdigit(ch = NC()); x = x * 10 + ch - '0')
        ;
    if (flag)
        x *= -1;
}
#undef BUF_SIZE
}  // namespace FastIO
using namespace FastIO;

const int maxn = 1e5 + 10;

struct node {
    int id;
    int v;
    node() {}
    node(int id, int v) : id(id), v(v) {}
    bool operator<(const node &r) const {
        return v > r.v;
    }
};

priority_queue<node> q[10];

int n, k;
int ans[maxn];
int arr[maxn][20];

int main() {
    int t;
    read(t);
    while (t--) {
        read(n), read(k);
        for (int i = 1; i <= k; ++i)
            while (!q[i].empty()) q[i].pop();
        for (int i = 1; i <= k; ++i) read(ans[i]);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= (k * 2); ++j) {
                read(arr[i][j]);
            }
            q[1].push(node(i, arr[i][1]));
        }
        int cnt = 0;
        while (1) {
            bool flag = false;
            for (int i = 1; i <= k; ++i) {
                while (!q[i].empty()) {
                    node tmp = q[i].top();
                    if (tmp.v <= ans[i]) {
                        if (i == k) {
                            cnt++;
                            flag = true;
                            for (int j = 1; j <= k; ++j) ans[j] += arr[tmp.id][j + k];
                        } else {
                            tmp.v = arr[tmp.id][i + 1];
                            q[i + 1].push(tmp);
                        }
                        q[i].pop();
                    } else
                        break;
                }
            }
            if (!flag)
                break;
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= k; ++i) printf("%d%c", ans[i], " \n"[i == k]);
    }
    return 0;
}