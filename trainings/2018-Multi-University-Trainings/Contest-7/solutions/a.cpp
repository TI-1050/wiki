#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;

struct Edge {
    int to, nxt, val;
    Edge() {}
    Edge(int to, int nxt, int val) : to(to), nxt(nxt), val(val){};
} edge[maxn << 1];

set<int> s[maxn];
int head[maxn], tot;

void Init(int n) {
    for (int i = 0; i <= n; ++i) head[i] = -1, s[i].clear();
    tot = 0;
}

void addedge(int u, int v, int val) {
    edge[tot] = Edge(v, head[u], val);
    head[u] = tot++;
}

struct qnode {
    int v, c;
    int pre;
    int fa;
    qnode() {}
    qnode(int v, int c, int pre, int fa) : v(v), c(c), pre(pre), fa(fa) {}
    bool operator<(const qnode &r) const {
        return c > r.c;
    }
};

int n, m;
int dist[maxn];

void BFS(int st) {
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    priority_queue<qnode> q;
    dist[st] = 0;
    q.push(qnode(st, 0, 0, 0));
    while (!q.empty()) {
        qnode tmp = q.top();
        q.pop();
        int u = tmp.v;
        if (tmp.c > dist[u])
            continue;
        else if (tmp.c == dist[u]) {
            if (s[u].find(tmp.pre) != s[u].end())
                continue;
            s[u].insert(tmp.pre);
        } else {
            dist[u] = tmp.c;
            s[u].clear();
            s[u].insert(tmp.pre);
        }
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            int cost = edge[i].val;
            if (v == tmp.fa)
                continue;
            if (dist[u] + (cost != tmp.pre) <= dist[v]) {
                dist[v] = dist[u] + (cost != tmp.pre);
                if (v != n) {
                    q.push(qnode(v, dist[v], cost, u));
                }
            }
        }
    }
}

int main() {
    int t;
    while (scanf("%d %d", &n, &m) != EOF) {
        Init(n);
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        BFS(1);
        if (dist[n] == INF)
            dist[n] = -1;
        printf("%d\n", dist[n]);
    }
    return 0;
}