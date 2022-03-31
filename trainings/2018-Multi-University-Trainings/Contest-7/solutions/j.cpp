#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = (ll)1e9 + 7;

int t, n;
ll A, B, C, D, P;

ll Biner(ll x) {
    ll l = x, r = n, res = l;
    x = P / x;
    while (r - l >= 0) {
        ll mid = (l + r) >> 1;
        ll tmp = P / mid;
        if (tmp >= x) {
            l = mid + 1;
            res = mid;
        } else
            r = mid - 1;
    }
    return res;
}

struct node {
    ll a[3][3];
    node() {
        memset(a, 0, sizeof a);
    }
    node operator*(const node &r) const {
        node ans = node();
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k) ans.a[i][j] = (ans.a[i][j] + a[i][k] * r.a[k][j] % MOD) % MOD;
        return ans;
    }
} base;

node qmod(node base, int n) {
    node res = node();
    res.a[0][0] = B, res.a[0][1] = A;
    res.a[0][2] = 1;
    while (n) {
        if (n & 1)
            res = res * base;
        base = base * base;
        n >>= 1;
    }
    return res;
}

ll work() {
    if (n == 1)
        return A;
    if (n == 2)
        return B;
    int l = 3, r;
    while (l <= n) {
        r = Biner(l);
        base.a[2][0] = P / l;
        node res = qmod(base, r - l + 1);
        B = res.a[0][0], A = res.a[0][1];
        l = r + 1;
    }
    return B;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%lld%lld%lld%d", &A, &B, &C, &D, &P, &n);
        memset(base.a, 0, sizeof base.a);
        base.a[0][0] = D, base.a[1][0] = C, base.a[0][1] = 1;
        base.a[2][2] = 1;
        printf("%lld\n", work());
    }
    return 0;
}