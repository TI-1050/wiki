#include <bits/stdc++.h>
using namespace std;

#define N (1 << 21)
#define ll long long

struct node {
    ll a, b;
    int sta;
    inline void scan() {
        int tot, k;
        sta = 0;
        scanf("%lld%lld%d", &a, &b, &tot);
        while (tot--) {
            scanf("%d", &k);
            sta |= (1 << (k - 1));
        }
    }
} arr[25];

int n;
ll dp[N];

inline ll Count(int x) {
    int res = 0;
    while (x) {
        ++res;
        x &= (x - 1);
    }
    return res;
}

inline void Run() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) arr[i].scan();
        memset(dp, -1, sizeof dp);
        ll ans = 0;
        dp[0] = 0;
        for (int i = 0; i < (1 << n); ++i) {
            if (dp[i] == -1)
                continue;
            for (int j = 1; j <= n; ++j) {
                if (!(i & (1 << (j - 1))) && (i & (arr[j].sta)) == arr[j].sta) {
                    int tmp = i | (1 << (j - 1));
                    ll t = Count(tmp);
                    dp[tmp] = max(dp[tmp], dp[i] + arr[j].a * t + arr[j].b);
                    ans = max(ans, dp[tmp]);
                }
            }
        }
        printf("%lld\n", ans);
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();
    return 0;
}