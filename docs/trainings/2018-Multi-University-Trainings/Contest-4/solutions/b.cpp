#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int maxn = 1e5 + 10;

int unit;
ll inv[maxn];
ll invfac[maxn];
ll fac[maxn];
ll ans[maxn];
int n, m;

struct node {
    int l, r, id;
    inline node() {}
    inline node(int l, int r, int id) : l(l), r(r), id(id) {}
    inline bool operator<(const node &b) const {
        if (l / unit != b.l / unit)
            return l / unit < b.l / unit;
        else
            return r < b.r;
    }
} arr[maxn];

inline void Init() {
    fac[0] = invfac[0] = 1;
    fac[1] = inv[1] = invfac[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        invfac[i] = invfac[i - 1] * inv[i] % MOD;
    }
}

inline ll cal(int a, int b) {
    ll res = fac[a] * invfac[b] % MOD * invfac[a - b] % MOD;
    return res;
}

inline void work() {
    ll tmp = 0;
    for (int i = 0; i <= arr[1].r; ++i) {
        tmp = (tmp + cal(arr[1].l, i)) % MOD;
    }
    ans[arr[1].id] = tmp;
    int L = arr[1].l, R = arr[1].r;
    for (int i = 2; i <= n; ++i) {
        while (L < arr[i].l) {
            tmp = (tmp * 2 % MOD - cal(L++, R) + MOD) % MOD;
        }
        while (L > arr[i].l) {
            tmp = (tmp + cal(--L, R) + MOD) % MOD * inv[2] % MOD;
        }
        while (R < arr[i].r) {
            tmp = (tmp + cal(L, ++R)) % MOD;
        }
        while (R > arr[i].r) {
            tmp = (tmp - cal(L, R--) + MOD) % MOD;
        }
        ans[arr[i].id] = tmp;
    }
}

int main() {
    Init();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &arr[i].l, &arr[i].r);
        arr[i].id = i;
    }
    unit = (int)sqrt(n);
    sort(arr + 1, arr + 1 + n);
    work();
    for (int i = 1; i <= n; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}