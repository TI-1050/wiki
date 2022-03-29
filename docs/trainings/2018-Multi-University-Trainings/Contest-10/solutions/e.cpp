#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n;
vector<int> G[N], num[N];
set<int> s;
int sz[N], son[N], cnt[N], cnt2[N], arr[N], ans[N], Max;
bool isbig[N];

void Init() {
    for (int i = 1; i <= 100000; ++i) {
        int limit = sqrt(i);
        for (int j = 1; j < limit; ++j)
            if (i % j == 0) {
                num[i].push_back(j);
                num[i].push_back(i / j);
            }
        if (i % limit == 0) {
            num[i].push_back(limit);
            if (limit * limit != i)
                num[i].push_back(i / limit);
        }
    }
}

void DFS(int u) {
    sz[u] = 1;
    for (auto v : G[u]) {
        DFS(v);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[v] > sz[son[u]])
            son[u] = v;
    }
}

void update(int u) {
    for (auto it : num[arr[u]]) ++cnt[it];
    for (auto v : G[u])
        if (!isbig[v])
            update(v);
}

void work(int u, int fa) {
    for (auto it : num[arr[u]]) s.insert(it);
    for (auto v : G[u])
        if (!isbig[v])
            work(v, fa);
}

void query(int u) {
    for (auto v : G[u])
        if (!isbig[v]) {
            s.clear();
            work(v, u);
            for (auto it : s)
                if (cnt[it] >= 1 || cnt2[it] >= 1)
                    Max = max(Max, it);
            for (auto it : s) ++cnt2[it];
        }
    for (auto it : num[arr[u]])
        if (cnt[it] >= 1 || cnt2[it] >= 1)
            Max = max(Max, it);
}

void clear(int u) {
    for (auto it : num[arr[u]]) cnt[it] = cnt2[it] = 0;
    for (auto v : G[u]) clear(v);
}

void DSU(int u) {
    for (auto v : G[u])
        if (v != son[u])
            DSU(v);
    if (son[u] != -1) {
        isbig[son[u]] = 1;
        DSU(son[u]);
    }
    Max = -1;
    query(u);
    ans[u] = Max;
    if (isbig[u])
        update(u);
    if (son[u] != -1)
        isbig[son[u]] = 0;
    if (!isbig[u])
        clear(u);
}

int main() {
    Init();
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) G[i].clear();
        memset(son, -1, sizeof son);
        memset(cnt, 0, sizeof cnt);
        memset(cnt2, 0, sizeof cnt2);
        Max = -1;
        s.clear();
        for (int i = 2, u; i <= n; ++i) {
            scanf("%d", &u);
            G[u].push_back(i);
        }
        for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
        DFS(1);
        DSU(1);
        for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}