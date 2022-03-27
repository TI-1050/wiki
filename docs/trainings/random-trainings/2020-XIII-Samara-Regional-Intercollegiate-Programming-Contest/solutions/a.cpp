#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 5e5 + 10;

int n, q;
ll a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }

    ll res = 0;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == n % 2) {
            res += a[i];
        } else {
            res -= a[i];
        }
    }

    scanf("%d", &q);

    for (int _q = 1, l, r, v; _q <= q; ++_q) {
        scanf("%d %d %d", &l, &r, &v);
        int even = r / 2 - (l - 1) / 2;
        int odd = r - l + 1 - even;
        if (n & 1) {
            res += 1ll * (odd - even) * v;
        } else {
            res += 1ll * (even - odd) * v;
        }
        printf("%lld\n", res);
    }

    return 0;
}
