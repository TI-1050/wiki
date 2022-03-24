#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 200;
const int inf = 0x7ffffff;
struct edge {
    int from, to, w, next;
} e[N * 20];
int head[N];
int vis[N];
int dist[N];
int n, m, t, x;

void add(int i, int j, int w) {
    e[t].from = i;
    e[t].to = j;
    e[t].w = w;
    e[t].next = head[i];
    head[i] = t++;
}

struct E {
    int to, w;
    E() {}
    E(int to, int w) : to(to), w(w) {}
    bool operator<(const E &other) const {
        return w > other.w;
    }
};

void dijkstra(int s) {
    priority_queue<E> pq;
    for (int i = 0; i <= n; ++i) {
        dist[i] = inf;
    }
    dist[s] = 0;
    pq.push(E(s, 0));
    memset(vis, 0, sizeof vis);
    while (!pq.empty()) {
        int u = pq.top().to;
        pq.pop();
        if (u == m)
            return;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].to;
            if (!vis[v] && dist[v] > dist[u] + e[i].w) {
                dist[v] = dist[u] + e[i].w;
                pq.push(E(v, dist[v]));
            }
        }
    }
}

int main() {
    scanf("%d%d", &x, &m);
    if (x > m)
        n = x + 100;
    else
        n = m + 100;
    t = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < n; ++i) {
        add(i, i + 1, 1);
        add(i + 1, i, 1);
        add(i + 1, 0, 3);
        for (int j = 2; i * j <= n && i != 0; ++j) add(i, i * j, 2 + 2 * j);
    }
    dijkstra(x);
    // for (int i = 0; i <= n - 100; ++i) printf("%d %d\n", i, dist[i]);
    printf("%d\n", dist[m]);
    return 0;
}