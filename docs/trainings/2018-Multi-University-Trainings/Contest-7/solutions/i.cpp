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

void out(int x) {
    if (x / 10)
        out(x / 10);
    putchar(x % 10 + '0');
}

inline void print(int x) {
    out(x);
    puts("");
}
#undef BUF_SIZE
}  // namespace FastIO
using namespace FastIO;

#define N 100010
#define DEG 20
#define block 400

int t, n, q;
int a[N], b[N], In[N], Out[N], fa[N][20], deep[N], p[N], fp[N], cnt;
vector<int> G[N];

void Init() {
    for (int i = 1; i <= n; ++i) G[i].clear();
    cnt = 0;
    fa[1][0] = 1;
    deep[1] = 0;
}

void DFS(int u) {
    p[u] = ++cnt;
    fp[cnt] = u;
    for (int i = 1; i < DEG; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : G[u])
        if (v != fa[u][0]) {
            deep[v] = deep[u] + 1;
            DFS(v);
        }
}

int GetK(int x, int k) {
    bitset<20> b;
    b = k;
    for (int i = 19; i >= 0; --i)
        if (b[i])
            x = fa[x][i];
    return x;
}

int query(int x) {
    int res = 0;
    x = p[x];
    while (x) {
        res += b[x];
        x = Out[x];
    }
    return res;
}

void update(int x) {
    if (a[x] > deep[x]) {
        b[p[x]] = 1;
        Out[p[x]] = 0;
        In[p[x]] = p[x];
    } else {
        int root = GetK(x, a[x]);
        if ((p[root] - 1) / block != (p[x] - 1) / block) {
            b[p[x]] = 1;
            Out[p[x]] = p[root];
            In[p[x]] = p[x];
        } else {
            b[p[x]] = b[p[root]] + 1;
            Out[p[x]] = Out[p[root]];
            In[p[x]] = p[root];
        }
    }
    x = p[x];
    for (int i = x + 1; i <= n && (i - 1) / block == (x - 1) / block; ++i) {
        if (In[i] != i) {
            b[i] = b[In[i]] + 1;
            Out[i] = Out[In[i]];
        }
    }
}

void Run() {
    read(t);
    while (t--) {
        read(n);
        Init();
        for (int i = 2; i <= n; ++i) {
            read(fa[i][0]);
            G[fa[i][0]].push_back(i);
        }
        DFS(1);
        for (int i = 1; i <= n; ++i) read(a[i]);
        for (int i = 1; i <= n; ++i) {
            int x = fp[i];
            if (a[x] > deep[x]) {
                b[i] = 1;
                Out[i] = 0;
                In[i] = i;
                continue;
            }
            int root = GetK(x, a[x]);
            if ((p[root] - 1) / block != (i - 1) / block) {
                b[i] = 1;
                Out[i] = p[root];
                In[i] = i;
            } else {
                b[i] = b[p[root]] + 1;
                Out[i] = Out[p[root]];
                In[i] = p[root];
            }
        }
        read(q);
        for (int i = 1, op, x, v; i <= q; ++i) {
            read(op);
            read(x);
            if (op == 1)
                print(query(x));
            else {
                read(v);
                a[x] = v;
                update(x);
            }
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