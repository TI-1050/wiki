#include <bits/stdc++.h>

using namespace std;

#define N 64
#define ll long long

const ll MOD = (ll)1e9 + 7;

int t;
ll n;
ll a[N], b[N], c[N];

inline void Init() {
    a[0] = 1;
    for (int i = 1; i <= 59; ++i) a[i] = a[i - 1] << 1;
    b[0] = 1;
    for (int i = 1; i <= 59; ++i) b[i] = (b[i - 1] << 1) + 1;
    c[0] = 1;
    for (int i = 1; i <= 59; ++i)
        c[i] = ((c[i - 1] << 1) % MOD + (a[i - 1] % MOD) * (b[i - 1] % MOD) % MOD + a[i]) % MOD;
    //    for (int i = 0; i <= 59; ++i) printf("%lld %lld %lld\n", a[i], b[i], c[i]);
}

int main() {
    Init();
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        --n;
        ll ans = 1, tmp = 0;
        for (int i = 59; i >= 0; --i) {
            while (n >= b[i]) {
                ans = (ans + c[i]) % MOD;
                ans = (ans + (b[i] % MOD * tmp) % MOD) % MOD;
                tmp = (tmp + a[i]) % MOD;
                n -= b[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}