#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = (int)1e9 + 7;
const int maxn = (int)1e5 + 10;

struct Edge {
    int u, v;
    ll w;
    inline Edge() {}
    inline Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
};

int n;
ll ans;
int son[maxn];
vector<Edge> G[maxn];

inline void Init() {
    ans = 0;
    memset(son, 0, sizeof son);
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
    }
}

inline void DFS(int u, int pre) {
    son[u] = 1;
    for (auto it : G[u]) {
        int v = it.v;
        if (v == pre)
            continue;
        DFS(v, u);
        son[u] += son[v];
        ans = (ans + (ll)son[v] * (n - son[v]) % MOD * it.w) % MOD;
    }
}

inline void RUN() {
    while (~scanf("%d", &n)) {
        Init();
        for (int i = 1; i < n; ++i) {
            int u, v;
            ll w;
            scanf("%d %d %lld", &u, &v, &w);
            G[u].push_back(Edge(u, v, w));
            G[v].push_back(Edge(v, u, w));
        }
        DFS(1, -1);
        for (int i = 1; i <= n - 1; ++i) {
            ans = (ans * i) % MOD;
        }
        ans = (ans * 2) % MOD;
        printf("%lld\n", ans);
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
    return 0;
}