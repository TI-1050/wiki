#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int maxn = 1e6 + 10;

ll fac[maxn];
ll inv[maxn];
ll invfac[maxn];

void Init() {
    fac[0] = inv[0] = invfac[0] = 1;
    fac[1] = inv[1] = invfac[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        invfac[i] = invfac[i - 1] * inv[i] % MOD;
    }
}

ll calc(ll n, ll m) {
    if (m > n || m < 0 || n < 0)
        return 0;
    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

int n, m, k;

int main() {
    Init();
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        ll ans = 0;
        for (int i = 0; i <= m; ++i) {
            ll tmp = k - 1ll * i * n + m - 1;
            if (tmp < 0)
                break;
            if (i & 1)
                ans = (ans - calc(m, i) * calc(tmp, m - 1) % MOD + MOD) % MOD;
            else
                ans = (ans + calc(m, i) * calc(tmp, m - 1) % MOD) % MOD;
            //    cout << i << " " << m << " " << calc(m, i);
            //    cout << tmp << " " << m - 1 << " " << calc(tmp, m - 1) << endl;
        }
        printf("%lld\n", ans);
    }
    return 0;
}