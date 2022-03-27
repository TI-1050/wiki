#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1 << 10;
const int MOD = 1e9 + 7;

int t, n, m;
ll dp[maxn];
ll ans[12];

inline int cal(int x) {
    int cnt = 0;
    while (x) {
        if (x & 1)
            cnt++;
        x >>= 1;
    }
    return cnt;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(ans, 0, sizeof ans);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        scanf("%d %d", &n, &m);
        while (m--) {
            char op[10];
            int u, v;
            scanf("%s %d %d", op, &u, &v);
            --u, --v;
            for (int s = 0; s < (1 << n); ++s) {
                if ((s & (1 << u)) || (s & (1 << v)))
                    continue;
                int S = s | (1 << u);
                S |= (1 << v);
                if (op[0] == '+') {
                    dp[S] = (dp[S] + dp[s]) % MOD;
                    ans[cal(S)] = (ans[cal(S)] + dp[s]) % MOD;
                } else if (op[0] == '-') {
                    dp[S] = (dp[S] - dp[s] + MOD) % MOD;
                    ans[cal(S)] = (ans[cal(S)] - dp[s] + MOD) % MOD;
                }
            }
            for (int i = 2; i <= n; i += 2) {
                printf("%lld%c", ans[i], " \n"[i == n]);
            }
        }
    }
    return 0;
}