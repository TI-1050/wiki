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

const int N = 2e3 + 10;
const ll p = 1e9 + 7;

int n, l;
vector<vector<int>> G;
ll f[N];
int vis[N];

ll gao(int u) {
    if (vis[u])
        return f[u];
    vis[u] = 1;
    if (u > l)
        f[u] = 1;
    for (auto v : G[u]) {
        f[u] = (f[u] + gao(v)) % p;
    }
    return f[u];
}

int main() {
    scanf("%d %d", &n, &l);
    G.clear();
    G.resize(n + 1);
    for (int i = 1, m; i <= l; ++i) {
        scanf("%d", &m);
        for (int j = 1, x; j <= m; ++j) {
            scanf("%d", &x);
            G[i].push_back(x);
        }
    }
    ll res1 = gao(1), res2 = 0;
    for (int i = l + 1; i <= n; ++i) {
        res2 += vis[i];
    }
    printf("%lld %lld\n", res1, res2);
    return 0;
}
