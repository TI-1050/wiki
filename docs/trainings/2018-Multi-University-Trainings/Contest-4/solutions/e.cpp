#include <bits/stdc++.h>

using namespace std;

#define N 110

typedef long long ll;

int n;
int x[2], y[2];
ll arr[N];
ll G[N][N];

inline ll cal(int x, int y) {
    if (x < 0 || y < 0)
        return 0ll;
    ll res = G[n - 1][n - 1] * (x / n) * (y / n) + G[n - 1][y % n] * (x / n) + G[x % n][n - 1] * (y / n) +
             G[x % n][y % n];
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", arr + i);
        }
        for (int i = 0, cnt = 0; i < (n << 2); ++i) {
            for (int j = 0; j <= i; ++j) {
                G[j][i - j] = arr[cnt];
                cnt = (cnt + 1) % n;
            }
        }
        n <<= 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                G[i][j] += (i ? G[i - 1][j] : 0);
                G[i][j] += (j ? G[i][j - 1] : 0);
                G[i][j] -= ((i && j) ? G[i - 1][j - 1] : 0);
            }
        }
        int q;
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
            ll ans = cal(x[1], y[1]) - cal(x[0] - 1, y[1]) - cal(x[1], y[0] - 1) + cal(x[0] - 1, y[0] - 1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}