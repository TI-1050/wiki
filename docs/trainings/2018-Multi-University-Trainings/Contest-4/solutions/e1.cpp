#include <bits/stdc++.h>
using namespace std;

#define N 1100
#define ll long long

int t, n, q, x[2], y[2];
ll arr[N];
ll G[N][N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%lld", arr + i);
        memset(G, 0, sizeof G);
        for (int i = 0, cnt = 0; i <= (n << 2); ++i) {
            for (int j = 0; j <= i; ++j) {
                G[j][i - j] = arr[cnt + 1];
                cnt = (cnt + 1) % n;
            }
        }
        n <<= 1;
        ll base = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) base += G[i][j];
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
            ll ans = 0, tmp;
            // compute Big
            ll xl = (x[1] - x[0] + 1) / n, yl = (y[1] - y[0] + 1) / n;
            ans += (base * xl * yl);
            // compute lower_left corner
            tmp = 0;
            for (int i = x[0] + xl * n; i <= x[1]; ++i) {
                for (int j = y[0], cnt = 1; cnt <= n; ++cnt, ++j) tmp += G[i % n][j % n];
            }
            // compute upper_right corner
            ans += tmp * yl;
            tmp = 0;
            for (int i = x[0], cnt = 1; cnt <= n; ++cnt, ++i) {
                for (int j = y[0] + yl * n; j <= y[1]; ++j) tmp += G[i % n][j % n];
            }
            // compute lower_right corner
            ans += tmp * xl;
            tmp = 0;
            for (int i = x[0] + xl * n; i <= x[1]; ++i) {
                for (int j = y[0] + yl * n; j <= y[1]; ++j) ans += G[i % n][j % n];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}