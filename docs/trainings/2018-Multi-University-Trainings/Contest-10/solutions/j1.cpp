#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f

int t, n, m, K;

struct node {
    int x[10];
    void scan(int vis) {
        scanf("%d", x + vis);
        for (int i = 2; i <= K + 1; ++i) scanf("%d", x + i);
    }
} a[N], b[N];

void Run() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &K);
        for (int i = 1; i <= n; ++i) a[i].scan(0);
        for (int i = 1; i <= m; ++i) b[i].scan(1);
        ll res = 0;
        for (int i = 0; i < (1 << (K + 2)); ++i) {
            bitset<7> bit;
            bit = i;
            ll Max[2] = {-INF, -INF};
            ll Min[2] = {INF, INF};
            for (int j = 1; j <= n; ++j) {
                ll tmp = 0;
                for (int k = 0; k <= K + 1; ++k) tmp += a[j].x[k] * (bit[k] ? 1 : -1);
                Max[0] = max(Max[0], tmp);
                Min[0] = min(Min[0], tmp);
            }
            for (int j = 1; j <= m; ++j) {
                ll tmp = 0;
                for (int k = 0; k <= K + 1; ++k) tmp += b[j].x[k] * (bit[k] ? 1 : -1);
                Max[1] = max(Max[1], tmp);
                Min[1] = min(Min[1], tmp);
            }
            res = max(res, max(Max[0] - Min[1], Max[1] - Min[0]));
        }
        printf("%lld\n", res);
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();
    return 0;
}