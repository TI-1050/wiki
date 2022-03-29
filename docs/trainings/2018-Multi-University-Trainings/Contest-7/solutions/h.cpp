#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
const int DEG = 20;

struct EDGE {
    int u, v, w;
} EDGE[maxn], TEMP;

struct Edge {
    int to, nxt, val;
    Edge() {}
    Edge(int to, int nxt, int val) : to(to), nxt(nxt), val(val) {}
} edge[maxn << 1];

int head[maxn], tot, cnt;
int father[maxn];

void Init(int n) {
    for (int i = 0; i <= n; ++i) head[i] = -1, father[i] = i;
    tot = cnt = 0;
}

int find(int x) {
    return x == father[x] ? father[x] : father[x] = find(father[x]);
}

void mix(int x, int y) {
    x = find(x), y = find(y);
    if (x != y)
        father[x] = y;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void addedge(int u, int v, int val) {
    edge[tot] = Edge(v, head[u], val);
    head[u] = tot++;
}

int dro[maxn];
int ord[maxn], son[maxn];
int fa[maxn][DEG];
int deg[maxn];

void DFS(int u, int pre) {
    ord[u] = ++cnt;
    dro[cnt] = u;
    for (int i = 1; i < DEG; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == pre)
            continue;
        fa[v][0] = u;
        deg[v] = deg[u] + 1;
        DFS(v, u);
    }
    son[u] = cnt;
}

int LCA(int u, int v) {
    if (deg[u] > deg[v])
        swap(u, v);
    int hu = deg[u], hv = deg[v];
    int tu = u, tv = v;
    for (int det = hv - hu, i = 0; det; det >>= 1, ++i) {
        if (det & 1) {
            tv = fa[tv][i];
        }
    }
    if (tu == tv)
        return tu;
    for (int i = DEG - 1; i >= 0; --i) {
        if (fa[tu][i] == fa[tv][i])
            continue;
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}

struct node {
    int l, r;
    ll val, lazy;
    node() {}
    node(int l, int r, ll val, ll lazy) : l(l), r(r), val(val), lazy(lazy) {}
} tree[maxn << 2];

void pushup(int id) {
    tree[id].val = tree[id << 1].val + tree[id << 1 | 1].val;
}

void pushdown(int id) {
    if (tree[id].lazy) {
        ll lazy = tree[id].lazy;
        tree[id << 1].val += lazy;
        tree[id << 1 | 1].val += lazy;
        tree[id << 1].lazy += lazy;
        tree[id << 1 | 1].lazy += lazy;
        tree[id].lazy = 0;
    }
}

void build(int id, int l, int r) {
    tree[id] = node(l, r, 0, 0);
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
}

void update(int id, int l, int r, ll val) {
    if (l <= tree[id].l && r >= tree[id].r) {
        tree[id].val += val;
        tree[id].lazy += val;
        return;
    }
    pushdown(id);
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (mid >= l)
        update(id << 1, l, r, val);
    if (r > mid)
        update(id << 1 | 1, l, r, val);
    pushup(id);
}

ll query(int id, int pos) {
    if (tree[id].l == pos && tree[id].r == pos) {
        return tree[id].val;
    }
    pushdown(id);
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (pos <= mid)
        return query(id << 1, pos);
    if (pos > mid)
        return query(id << 1 | 1, pos);
    pushup(id);
}

ll getdis(int u, int v) {
    int root = LCA(u, v);
    return query(1, ord[u]) + query(1, ord[v]) - 2 * query(1, ord[root]);
}

int n, q;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &q);
        Init(n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &EDGE[i].u, &EDGE[i].v, &EDGE[i].w);
            int u = EDGE[i].u, v = EDGE[i].v, w = EDGE[i].w;
            if (same(u, v)) {
                TEMP = EDGE[i];
                continue;
            }
            mix(u, v);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        fa[1][0] = 1;
        deg[1] = 0;
        DFS(1, -1);
        build(1, 1, n);
        for (int i = 1; i <= n; ++i) {
            int u = EDGE[i].u, v = EDGE[i].v, w = EDGE[i].w;
            if (u == TEMP.u && v == TEMP.v)
                continue;
            if (fa[u][0] == v) {
                update(1, ord[u], son[u], w);
            } else if (fa[v][0] == u)
                ;
            { update(1, ord[v], son[v], w); }
        }
        //        for(int i = 1; i <= n; ++i) cout << ord[i] << endl;
        //        for(int i = 1; i <= n; ++i) cout << i << " " << query(1, ord[i]) << endl;
        while (q--) {
            int op, x, y;
            scanf("%d %d %d", &op, &x, &y);
            if (op == 0) {
                int u = EDGE[x].u, v = EDGE[x].v, w = EDGE[x].w;
                if (u == TEMP.u && v == TEMP.v) {
                    EDGE[x].w = y;
                    TEMP.w = y;
                }
                if (fa[u][0] == v) {
                    update(1, ord[u], son[u], y - w);
                } else if (fa[v][0] == u) {
                    update(1, ord[v], son[v], y - w);
                }
                EDGE[x].w = y;
            } else if (op == 1) {
                ll ans = getdis(x, y);
                ans = min(ans, getdis(x, TEMP.u) + TEMP.w + getdis(y, TEMP.v));
                ans = min(ans, getdis(y, TEMP.u) + TEMP.w + getdis(x, TEMP.v));

                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}