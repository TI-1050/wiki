#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

#define N 1005
#define M 50005

int n, m, k;
ll T;
bool vis[N];
int d[N];

struct node {
    int v;
    int cost;
    node() {}
    node(int v, ll cost) : v(v), cost(cost) {}
    inline bool operator<(const node &b) const {
        return cost + d[v] > b.cost + d[b.v];
    }
} edge[M], revedge[M];

struct Edge {
    int v, cost;
    inline Edge() {}
    inline Edge(int v, int cost) : v(v), cost(cost) {}
};

vector<Edge> E[N], revE[N];

inline void Dijstra(int st) {
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
    }
    priority_queue<node> q;
    d[st] = 0;
    q.push(node(st, 0));
    while (!q.empty()) {
        node tmp = q.top();
        q.pop();
        int u = tmp.v;
        if (vis[u])
            continue;
        vis[u] = true;
        int len = E[u].size();
        for (int i = 0; i < len; ++i) {
            int v = E[u][i].v;
            int cost = E[u][i].cost;
            if (!vis[v] && d[v] > d[u] + cost) {
                d[v] = d[u] + cost;
                q.push(node(v, d[v]));
            }
        }
    }
}

inline int A_star(int st, int ed) {
    priority_queue<node> q;
    q.push(node(st, 0));
    --k;
    while (!q.empty()) {
        node tmp = q.top();
        q.pop();
        int u = tmp.v;
        if (u == ed) {
            if (k)
                --k;
            else
                return tmp.cost;
        }
        int len = revE[u].size();
        for (int i = 0; i < len; ++i) {
            int v = revE[u][i].v;
            int cost = revE[u][i].cost;
            q.push(node(v, tmp.cost + cost));
        }
    }
    return -1;
}

inline void addedge(int u, int v, int w) {
    revE[u].push_back(Edge(v, w));
    E[v].push_back(Edge(u, w));
}

int st, ed;

inline void RUN() {
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 0; i <= n; ++i) {
            E[i].clear();
            revE[i].clear();
        }
        scanf("%d %d %d %lld", &st, &ed, &k, &T);
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
        }
        Dijstra(ed);
        if (d[st] == INF) {
            puts("Whitesnake!");
            continue;
        }
        int ans = A_star(st, ed);
        if (ans == -1) {
            puts("Whitesnake!");
            continue;
        }
        puts(ans <= T ? "yareyaredawa" : "Whitesnake!");
    }
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("Text.txt", "r", stdin);
#endif  // LOCAL_JUDGE

    RUN();

#ifdef LOCAL_JUDGE
    fclose(stdin);
#endif  // LOCAL_JUDGE
}