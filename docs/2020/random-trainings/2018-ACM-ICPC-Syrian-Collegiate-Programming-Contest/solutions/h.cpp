#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e6 + 10;

int n, m;
ll a[N];
int vis[N];

int main() {
    freopen("bugged.in", "r", stdin);

    int _T;
    scanf("%d", &_T);
    while (_T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", a + i);
        }
        ll res = 0;
        for (int i = 1, s, d; i <= m; ++i) {
            scanf("%d %d", &s, &d);
            vis[s]++;
            vis[d]--;
            res += abs(a[s] - a[d]);
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) {
                res = -1;
                break;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
