#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 10;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int tot;
bool isprime[maxn];
int prime[maxn];
ll inv[maxn];

inline void Init_prime() {
    inv[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    }
    memset(isprime, true, sizeof isprime);
    tot = 0;
    for (int i = 2; i < maxn; ++i) {
        if (isprime[i]) {
            prime[tot++] = i;
            for (int j = (i << 1); j < maxn; j += i) {
                isprime[i] = false;
            }
        }
    }
}

vector<ll> vec;
ll n, m;
ll ans;

inline void Init(ll x) {
    vec.clear();
    for (int i = 0; i < tot && prime[i] < x; ++i) {
        if (x % prime[i] == 0) {
            vec.push_back(prime[i]);
            while (x % prime[i] == 0) {
                x /= prime[i];
            }
        }
    }
    if (x != 1)
        vec.push_back(x);
}

inline void RUN() {
    Init_prime();
    while (~scanf("%lld %lld", &n, &m)) {
        ans = n % MOD * (n + 1) % MOD * (n + 2) % MOD * inv[3] % MOD;
        if (m == 1) {
            printf("%lld\n", ans);
            continue;
        }
        Init(m);
        int len = vec.size();
        for (int i = 1; i < (1 << len); ++i) {
            int cnt = 0;
            ll t = 1;
            for (int j = 0; j < len; ++j) {
                if (i & (1 << j)) {
                    cnt++;
                    t *= vec[j];
                }
            }
            ll x = n / t;
            ll tmp = x % MOD * (x + 1) % MOD * (2 * x % MOD + 1) % MOD * inv[6] % MOD * t % MOD * (t + 1) % MOD -
                     x % MOD * (x + 1) % MOD * (x - 1) % MOD * inv[3] % MOD * t % MOD;
            tmp = (tmp + MOD) % MOD;
            if (cnt & 1) {
                ans = (ans - tmp + MOD) % MOD;
            } else {
                ans = (ans + tmp) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("Text.txt", "r", stdin);
#endif  // LOCAL_JUDGE

    RUN();

#ifdef LOCAL_JUDGE
    fclose(stdin);
#endif  // LOCAL_JUDGE
}