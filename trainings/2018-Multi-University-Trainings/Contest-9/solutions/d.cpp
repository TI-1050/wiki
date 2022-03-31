#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll a1, b1, c1, a2, b2, c2;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld %lld %lld %lld %lld", &a1, &b1, &c1, &a2, &b2, &c2);
        ll ans = a1 * (b2 - c2) + b1 * (c2 - a2) + c1 * (a2 - b2);
        if (ans % (a1 + b1 + c1) == 0) {
            ans /= a1 + b1 + c1;
            printf("%lld\n", ans);
        } else {
            int flag = 0;
            if (ans < 0) {
                ans = -ans;
                flag = 1;
            }
            ll ans2 = a1 + b1 + c1;
            ll GCD = gcd(ans, ans2);
            ans /= GCD;
            ans2 /= GCD;
            if (flag)
                printf("-");
            printf("%lld/%lld\n", ans, ans2);
        }
    }
    return 0;
}