#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2000 + 10;

ll a[N];
ll f[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        f[i][i] = a[i] * n;
    }
    for (int len = 2; len <= n; ++len)
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            ll x = f[i][j - 1] + a[j] * (n - (j - i + 1) + 1);
            ll y = f[i + 1][j] + a[i] * (n - (j - i + 1) + 1);
            if (x > y)
                f[i][j] = x;
            else
                f[i][j] = y;
        }
    printf("%lld\n", f[1][n]);
    return 0;
}