#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        if (n % 3 == 0) {
            ll ans = n / 3;
            ans *= n / 3;
            ans *= n / 3;
            printf("%lld\n", ans);
        } else if (n % 4 == 0) {
            ll ans = n / 2;
            ans *= n / 4;
            ans *= n / 4;
            printf("%lld\n", ans);
        } else {
            puts("-1");
        }
    }
    return 0;
}