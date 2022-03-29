#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 10;

ll arr[maxn][10], brr[maxn][10];
ll crr[maxn];

int n, m, k;

void RUN() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= k; ++j) scanf("%lld", &arr[i][j]);
        for (int i = 1; i <= m; ++i)
            for (int j = 0; j <= k; ++j) scanf("%lld", &brr[i][j]);
        memset(crr, 0, sizeof crr);
        ll ans = 0;
        int limit = (1 << k);
        for (int i = 1; i <= n; ++i) {
            for (int S = 0; S < limit; ++S) {
                ll tmp = arr[i][0];
                for (int j = 0; j < k; ++j) {
                    if (S & (1 << j)) {
                        tmp += arr[i][j + 1];
                    } else {
                        tmp -= arr[i][j + 1];
                    }
                }
                crr[S] = max(crr[S], tmp);
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int S = 0; S < limit; ++S) {
                ll tmp = brr[i][0];
                for (int j = 0; j < k; ++j) {
                    if (S & (1 << j)) {
                        tmp += brr[i][j + 1];
                    } else {
                        tmp -= brr[i][j + 1];
                    }
                }
                ans = max(ans, tmp + crr[limit - 1 - S]);
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
    return 0;
}