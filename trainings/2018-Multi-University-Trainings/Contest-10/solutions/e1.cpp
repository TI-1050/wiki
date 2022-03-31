#include <bits/stdc++.h>
using namespace std;

#define N 100010
vector<int> num[N], G[N];

int n;
int arr[N], rt[N], ans[N];

void Init() {
    for (int i = 1; i <= 100000; ++i)
        for (int j = i; j <= 100000; j += i) num[j].push_back(i);
}

struct SEG {
#define M N * 400
    int lson[M], rson[M], c[M], cnt;
    void init() {
        cnt = 0;
    }
    void pushup(int id) {
        c[id] = max(c[lson[id]], c[rson[id]]);
    }
    void update(int &x, int l, int r, int pos) {
        if (!x)
            x = ++cnt;
        if (l == r) {
            c[x] = pos;
            return;
        }
        int mid = (l + r) >> 1;
        pos <= mid ? update(lson[x], l, mid, pos) : update(rson[x], mid + 1, r, pos);
        pushup(x);
    }
    int merge(int u, int v, int &sum) {
        if (!u || !v)
            return u | v;
        if (c[u] == c[v])
            sum = max(sum, c[u]);
        if (lson[u] | lson[v])
            lson[u] = merge(lson[u], lson[v], sum);
        if (rson[u] | rson[v])
            rson[u] = merge(rson[u], rson[v], sum);
        return u;
    }
} seg;

void DFS(int u) {
    ans[u] = -1;
    for (auto v : G[u]) {
        DFS(v);
        seg.merge(rt[u], rt[v], ans[u]);
    }
}

void Run() {
    Init();
    while (scanf("%d", &n) != EOF) {
        seg.init();
        for (int i = 2, u; i <= n; ++i) {
            scanf("%d", &u);
            G[u].push_back(i);
        }
        for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
        for (int i = 1; i <= n; ++i)
            for (auto it : num[arr[i]]) seg.update(rt[i], 1, 100000, it);
        DFS(1);
        for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();
    return 0;
}