#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;

ll qmod(ll n) {
    ll res = 1;
    ll base = 2;
    while (n) {
        if (n & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        n >>= 1;
    }
    return res;
}

int t;
ll a, b, c, d;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        ll n = a + b + c + d;
        ll res = qmod(a) * qmod(c) % MOD * (qmod(b) - 1 + MOD) % MOD * (qmod(d) - 1 + MOD) % MOD;
        res = (res + qmod(a) * qmod(c) % MOD * (qmod(d) - 1 - d + MOD) % MOD) % MOD;
        res = (res + qmod(a) * (qmod(b) - 1 - b + MOD) % MOD * (qmod(c) - 1 + MOD)) % MOD;
        printf("%lld\n", (qmod(n) - res + MOD) % MOD);
    }
    return 0;
}