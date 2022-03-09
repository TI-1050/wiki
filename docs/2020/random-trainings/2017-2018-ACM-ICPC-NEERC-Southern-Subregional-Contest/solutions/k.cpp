#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e5 + 10;

int n;
ll a[N], b[N], f[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld %lld", a + i, b + i);
        f[i] = a[i] + b[i];
    }
    for (int i = 2; i <= n; ++i) {
        f[i] = min(f[i - 1] + 1, f[i]);
    }
    for (int i = n - 1; i >= 1; --i) {
        f[i] = min(f[i + 1] + 1, f[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (f[i] < a[i]) {
            puts("-1");
            return 0;
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res += f[i] - a[i];
    }
    printf("%lld\n", res);
    for (int i = 1; i <= n; ++i) {
        printf("%lld%c", f[i], " \n"[i == n]);
    }
    return 0;
}
