#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define dbg(x...)             \
    do {                      \
        cout << #x << " -> "; \
        err(x);               \
    } while (0)

void err() {
    cout << endl;
}

template <class T, class... Ts>
void err(const T& arg, const Ts&... args) {
    cout << arg << ' ';
    err(args...);
}

const ll INF = 0x3f3f3f3f3f3f3f3f;

template <class Type>
struct Dinic {
    static const int M = 1e6 + 10;
    static const int N = 1e5 + 10;
    struct Edge {
        int to, nxt;
        Type flow;
        Edge() {}
        Edge(int to, int nxt, Type flow) : to(to), nxt(nxt), flow(flow) {}
    } edge[M];
    int S, T;
    int head[N], tot;
    int dep[N];
    void init() {
        memset(head, -1, sizeof head);
        tot = 0;
    }
    void set(int S, int T) {
        this->S = S;
        this->T = T;
    }
    void addedge(int u, int v, ll w, ll rw = 0) {
        // dbg(u, v, w);
        edge[tot] = Edge(v, head[u], w);
        head[u] = tot++;
        edge[tot] = Edge(u, head[v], rw);
        head[v] = tot++;
    }
    bool BFS() {
        memset(dep, -1, sizeof dep);
        queue<int> q;
        q.push(S);
        dep[S] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = head[u]; ~i; i = edge[i].nxt) {
                if (edge[i].flow && dep[edge[i].to] == -1) {
                    dep[edge[i].to] = dep[u] + 1;
                    q.push(edge[i].to);
                }
            }
        }
        return dep[T] >= 0;
    }
    Type DFS(int u, Type f) {
        if (u == T || f == 0)
            return f;
        Type w, used = 0;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            if (edge[i].flow && dep[edge[i].to] == dep[u] + 1) {
                w = DFS(edge[i].to, min(f - used, edge[i].flow));
                edge[i].flow -= w;
                edge[i ^ 1].flow += w;
                used += w;
                if (used == f)
                    return f;
            }
        }
        if (!used)
            dep[u] = -1;
        return used;
    }
    Type solve() {
        Type ans = 0;
        while (BFS()) {
            ans += DFS(S, INF);
        }
        return ans;
    }
};
Dinic<ll> dinic;

const int N = 1e3 + 10;

int n, e;
ll sum;
ll cnt[20];
ll c[N];
int a[N][10];

bool ok(int x) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= 7; ++i) {
        cnt[i] = x / 7;
        if (x % 7 >= i)
            cnt[i]++;
    }
    dinic.init();
    int S = 0, T = n + 10;
    dinic.set(S, T);
    for (int i = 1; i <= n; ++i) {
        dinic.addedge(S, i, c[i]);
        for (int j = 1; j <= a[i][0]; ++j) {
            dinic.addedge(i, n + a[i][j], c[i]);
        }
    }
    for (int i = 1; i <= 7; ++i) {
        dinic.addedge(n + i, T, cnt[i] * e);
    }
    ll res = dinic.solve();
    // dbg(res, sum);
    return res >= sum;
}

int main() {
    scanf("%d %d", &n, &e);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld %d", c + i, &a[i][0]);
        for (int j = 1; j <= a[i][0]; ++j) {
            scanf("%d", &a[i][j]);
        }
        sum += c[i];
    }
    ll l = 0, r = 1e9, res = -1;
    // ok(5);
    while (r - l >= 0) {
        ll mid = (l + r) >> 1;
        if (ok(mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", res);
    return 0;
}
