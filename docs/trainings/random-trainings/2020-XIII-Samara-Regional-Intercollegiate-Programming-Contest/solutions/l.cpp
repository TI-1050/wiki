#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e5 + 10;

int n;
ll a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }
    sort(a + 1, a + 1 + n);
    ll res = 0;
    for (int i = n, j = 1; i >= 1; --i, ++j) {
        res += max(0ll, 1ll * a[i] - j);
    }
    printf("%lld\n", res);
    return 0;
}
