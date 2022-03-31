#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;

struct Edge {
    int to, nxt, cap, flow, cost;
} edge[maxm];

int head[maxn], tot;
int pre[maxn], dis[maxn];
bool vis[maxn];
int N;

void Init(int n) {
    N = n;
    tot = 0;
    for (int i = 0; i < n; ++i) head[i] = -1;
}

void addedge(int u, int v, int cap, int cost) {
    edge[tot].to = v;
    edge[tot].cap = cap;
    edge[tot].cost = cost;
    edge[tot].flow = 0;
    edge[tot].nxt = head[u];
    head[u] = tot++;

    edge[tot].to = u;
    edge[tot].cap = 0;
    edge[tot].cost = -cost;
    edge[tot].flow = 0;
    edge[tot].nxt = head[v];
    head[v] = tot++;
}

bool SPFA(int s, int t) {
    queue<int> q;
    for (int i = 0; i < N; ++i) dis[i] = INF, pre[i] = -1, vis[i] = false;
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost) {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if (pre[t] == -1)
        return false;
    else
        return true;
}

int minCostMaxflow(int s, int t, int &cost) {
    int flow = 0;
    cost = 0;
    while (SPFA(s, t)) {
        int Min = INF;
        for (int i = pre[t]; ~i; i = pre[edge[i ^ 1].to]) {
            if (Min > edge[i].cap - edge[i].flow) {
                Min = edge[i].cap - edge[i].flow;
            }
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

struct node {
    int si, ti, wi, op;
} arr[maxn];

int n, m, K, W;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &n, &m, &K, &W);
        for (int i = 1; i <= m; ++i) scanf("%d %d %d %d", &arr[i].si, &arr[i].ti, &arr[i].wi, &arr[i].op);
        Init(2 * m + 3);
        addedge(0, 2 * m + 1, K, 0);
        for (int i = 1; i <= m; ++i) addedge(2 * m + 1, 2 * i - 1, 1, 0);
        for (int i = 1; i <= m; ++i) addedge(2 * i - 1, 2 * i, 1, -arr[i].wi);
        for (int i = 1; i <= m; ++i) addedge(2 * i, 2 * m + 2, 1, 0);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i == j)
                    continue;
                if (arr[i].ti <= arr[j].si) {
                    if (arr[i].op == arr[j].op) {
                        addedge(2 * i, 2 * j - 1, 1, W);
                    } else {
                        addedge(2 * i, 2 * j - 1, 1, 0);
                    }
                }
            }
        }
        int cost = 0;
        minCostMaxflow(0, 2 * m + 2, cost);
        printf("%d\n", -cost);
    }
    return 0;
}