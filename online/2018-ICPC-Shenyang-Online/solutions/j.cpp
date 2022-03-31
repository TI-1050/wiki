#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define ll long long

struct Edge {
    int to, nx;
    inline Edge() {}
    inline Edge(int to, int nx) : to(to), nx(nx) {}
} edge[N << 1];

int n, q, Maxdeep;
int head[N], pos;
int ord[N], son[N], deep[N], fa[N], cnt;
vector<int> dep[N], Lar;
ll sum[N];

inline void Init() {
    memset(head, -1, sizeof head);
    pos = 0;
    cnt = 0;
    Maxdeep = 0;
    Lar.clear();
    for (int i = 0; i <= 1; ++i) dep[i].clear();
    fa[1] = 1;
    deep[1] = 0;
}

inline void addedge(int u, int v) {
    edge[++pos] = Edge(v, head[u]);
    head[u] = pos;
}

inline void DFS(int u, int pre) {
    ord[u] = ++cnt;
    dep[deep[u]].emplace_back(cnt);
    Maxdeep = max(Maxdeep, deep[u]);
    for (int it = head[u]; ~it; it = edge[it].nx) {
        int v = edge[it].to;
        if (v == pre)
            continue;
        deep[v] = deep[u] + 1;
        DFS(v, u);
    }
    son[u] = cnt;
}

struct node {
    int l, r;
    ll sum;
    inline node() {}
    inline node(int l, int r, ll sum) : l(l), r(r), sum(sum) {}
} tree[N << 2];

inline void pushup(int id) {
    tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
}

inline void build(int id, int l, int r) {
    tree[id] = node(l, r, 0);
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
}

inline void update(int id, int pos, ll val) {
    if (tree[id].l == tree[id].r) {
        tree[id].sum += val;
        return;
    }
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (pos <= mid)
        update(id << 1, pos, val);
    else if (pos > mid)
        update(id << 1 | 1, pos, val);
    pushup(id);
}

ll anssum;

inline void query(int id, int l, int r) {
    if (tree[id].l >= l && tree[id].r <= r) {
        anssum += tree[id].sum;
        return;
    }
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (l <= mid)
        query(id << 1, l, r);
    if (r > mid)
        query(id << 1 | 1, l, r);
}

inline void Run() {
    while (scanf("%d%d", &n, &q) != EOF) {
        Init();
        for (int i = 1, u, v; i < n; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        DFS(1, 1);
        build(1, 1, n);
        int limit = (int)sqrt(100000);
        for (int i = 1; i <= Maxdeep; ++i) {
            if (dep[i].size() >= limit) {
                Lar.emplace_back(i);
                sort(dep[i].begin(), dep[i].end());
            }
        }
        for (int i = 1, op, l, x; i <= q; ++i) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d", &l, &x);
                if (dep[l].size() < limit) {
                    for (auto it : dep[l]) update(1, it, (ll)x);
                } else
                    sum[l] += (ll)x;
            } else {
                scanf("%d", &x);
                anssum = 0;
                query(1, ord[x], son[x]);
                ll ans = anssum;
                int l = ord[x], r = son[x];
                for (auto it : Lar) {
                    if (it < deep[x])
                        continue;
                    int k = upper_bound(dep[it].begin(), dep[it].end(), r) -
                            lower_bound(dep[it].begin(), dep[it].end(), l);
                    if (k == 0)
                        break;
                    ans += sum[it] * k;
                }
                printf("%lld\n", ans);
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