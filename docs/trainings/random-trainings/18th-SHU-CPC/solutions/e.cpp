#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        ans += x;
    }
    ans -= 1ll * n * (n - 1) / 2;
    printf("%lld\n", ans);
    return 0;
}
