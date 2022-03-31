#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define ll long long
#define INFLL 0x3f3f3f3f3f3f3f3f

struct Edge {
    int to, nx;
    ll w;
    inline Edge() {}
    inline Edge(int to, int nx, ll w) : to(to), nx(nx), w(w) {}
} edge[N << 1];

int head[N], pos;

inline void Init() {
    memset(head, -1, sizeof head);
    pos = 0;
}

inline void addedge(int u, int v, ll w) {
    edge[++pos] = Edge(v, head[u], w);
    head[u] = pos;
}

struct node {
    int to, p;
    ll w;
    inline node() {}
    inline node(int to, int p, ll w) : to(to), p(p), w(w) {}
    inline bool operator<(const node &r) const {
        return w > r.w;
    }
};

ll dist[N][20];
bool used[N][20];
int t, n, m, k;

inline void Dijkstra() {
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= k; ++j) dist[i][j] = INFLL, used[i][j] = false;
    priority_queue<node> q;
    q.emplace(1, 0, 0);
    dist[1][0] = 0;
    while (!q.empty()) {
        int u = q.top().to;
        int p = q.top().p;
        ll w = q.top().w;
        // cout << w << endl;
        q.pop();
        if (used[u][p])
            continue;
        used[u][p] = true;
        dist[u][p] = w;
        for (int i = head[u]; ~i; i = edge[i].nx) {
            int v = edge[i].to;
            ll c = edge[i].w;
            if (dist[u][p] + c < dist[v][p]) {
                dist[v][p] = dist[u][p] + c;
                q.emplace(v, p, dist[v][p]);
            }
            if (p + 1 <= k && dist[u][p] < dist[v][p + 1]) {
                dist[v][p + 1] = dist[u][p];
                q.emplace(v, p + 1, dist[v][p + 1]);
            }
        }
    }
}

inline void Run() {
    scanf("%d", &t);
    while (t--) {
        Init();
        scanf("%d%d%d", &n, &m, &k);
        int u, v;
        ll w;
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%lld", &u, &v, &w);
            addedge(u, v, w);
        }
        Dijkstra();
        ll ans = dist[n][k];
        printf("%lld\n", ans);
    }
}
int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();

    return 0;
}