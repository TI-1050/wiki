#include <bits/stdc++.h>

using namespace std;

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

using db = double;

const int N = 2e4 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;

struct Edge {
    int to, nxt, cap, flow;
    db cost;
    Edge() {}
    Edge(int to, int nxt, int cap, int flow, db cost) : to(to), nxt(nxt), cap(cap), flow(flow), cost(cost) {}
} edge[M];

int head[N], tot;
int pre[N];
db dis[N];
bool vis[N];

void Init() {
    tot = 0;
    memset(head, -1, sizeof head);
}

void addedge(int u, int v, int cap, db cost) {
    edge[tot] = Edge(v, head[u], cap, 0, cost);
    head[u] = tot++;
    edge[tot] = Edge(u, head[v], 0, 0, -cost);
    head[v] = tot++;
}

bool SPFA(int S, int T) {
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[S] = 0;
    vis[S] = true;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // dbg(u);
        vis[u] = false;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost) {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    // for (int i = 1; i <= 11; ++i) {
    //     dbg(i, pre[i]);
    // }
    if (pre[T] == -1)
        return false;
    else
        return true;
}

int minCostMaxflow(int s, int t, db& cost) {
    int flow = 0;
    cost = 0;
    while (SPFA(s, t)) {
        int Min = INF;
        for (int i = pre[t]; ~i; i = pre[edge[i ^ 1].to]) {
            Min = min(Min, edge[i].cap - edge[i].flow);
        }
        for (int i = pre[t]; ~i; i = pre[edge[i ^ 1].to]) {
            edge[i].flow += Min;
            edge[i ^ 1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}

int n;
int res[N];

int main() {
    scanf("%d", &n);
    Init();
    int S = 2 * n + 1, T = 2 * n + 2;
    for (int i = 1; i <= n; ++i) {
        addedge(S, i, 1, 0);
        addedge(i + n, T, 1, 0);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            db x = 0;
            scanf("%lf", &x);
            x = log(x);
            addedge(i, j + n, 1, -x);
        }
    }
    db cost;
    minCostMaxflow(S, T, cost);
    for (int u = 1; u <= n; ++u) {
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (v != S && edge[i].cap == edge[i].flow) {
                res[v - n] = u;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", res[i], " \n"[i == n]);
    }
    return 0;
}
