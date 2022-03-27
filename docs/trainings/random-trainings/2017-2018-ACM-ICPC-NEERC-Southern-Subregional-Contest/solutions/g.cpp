#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

struct Edge {
    int to, id, val;

    Edge() {}

    Edge(int to, int id, int val) : to(to), id(id), val(val) {}
};

int n, m, s, tot;
vector<vector<Edge>> G, und;
int res[N], vis[N];

void gao1() {
    int cnt = 1;
    memset(vis, 0, sizeof vis);
    memset(res, 0, sizeof res);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto it : G[u]) {
            int v = it.to;
            if (!vis[v]) {
                ++cnt;
                vis[v] = true;
                q.push(v);
            }
        }
        for (auto it : und[u]) {
            int v = it.to, id = it.id, val = it.val;
            if (!vis[v] && !res[id]) {
                res[id] = val;
                ++cnt;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= tot; ++i) {
        if (res[i] == 1)
            putchar('+');
        else
            putchar('-');
    }
    puts("");
}

void gao2() {
    int cnt = 1;
    memset(vis, 0, sizeof vis);
    memset(res, 0, sizeof res);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto it : G[u]) {
            int v = it.to;
            if (!vis[v]) {
                ++cnt;
                vis[v] = true;
                q.push(v);
            }
        }
        for (auto it : und[u]) {
            int v = it.to, id = it.id, val = it.val;
            if (!res[id]) {
                res[id] = -val;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= tot; ++i) {
        if (res[i] == 1)
            putchar('+');
        else
            putchar('-');
    }
    puts("");
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    G.clear();
    G.resize(n + 1);
    und.clear();
    und.resize(n + 1);
    for (int i = 1, op, u, v; i <= m; ++i) {
        scanf("%d %d %d", &op, &u, &v);
        if (op == 1) {
            G[u].push_back(Edge(v, 1, 1));
        } else {
            und[u].push_back(Edge(v, ++tot, 1));
            und[v].push_back(Edge(u, tot, -1));
        }
    }
    gao1();
    gao2();
    return 0;
}
