#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 5e5 + 10;

int n;
ll a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
        a[i] += a[i - 1];
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= 0) {
            res = max(res, -a[i]);
        }
    }
    printf("%lld\n", res);
    return 0;
}
