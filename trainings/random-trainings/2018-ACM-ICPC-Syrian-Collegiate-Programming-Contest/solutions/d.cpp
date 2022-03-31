#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 5e2 + 10;

int n, m;
char G[N][N];
int f[N][N], num[N], val[N];

int gao(int x, int y) {
    if (x == n + 1) {
        return val[y];
    }
    if (f[x][y] != -1)
        return f[x][y];
    int& res = f[x][y];
    res = gao(x + 1, y);
    if (G[x][y] != '.' && y - 1 >= 1)
        res = max(res, gao(x + 1, y - 1));
    if (G[x][y] != '.' && y + 1 <= m)
        res = max(res, gao(x + 1, y + 1));
    return res;
}

int main() {
    freopen("balls.in", "r", stdin);

    int _T;
    scanf("%d", &_T);
    while (_T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i][j] = -1;
            }
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d", num + i);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%s", G[i] + 1);
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d", val + i);
        }
        ll res = 0;
        for (int i = 1; i <= m; ++i) {
            res += 1ll * gao(1, i) * num[i];
        }
        printf("%lld\n", res);
    }
    return 0;
}
