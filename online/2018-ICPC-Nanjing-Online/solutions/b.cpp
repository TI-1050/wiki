#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100010
#define M 110

int t, n, m, k;
int G[N][M];
int low[M];

struct node {
    ll h, num;
    inline node() {}
    inline node(ll h, ll num) : h(h), num(num) {}
    inline bool operator<(const node &r) const {
        return h < r.h;
    }
};

priority_queue<node> q;

int main() {
#ifdef LOCAL_JUDGE
    freopen("Text.txt", "r", stdin);
#endif  // LOCAL_JUDGE
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        printf("Case #%d: ", kase);
        memset(G, 0, sizeof G);
        memset(low, 0, sizeof low);
        while (!q.empty()) q.pop();
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1, x, y; i <= k; ++i) {
            scanf("%d%d", &x, &y);
            G[x][y] = 1;
        }
        ll ans = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // if (i % 1000 == 0) cout << i << endl;
                if (G[i][j] == 1) {
                    while (!q.empty()) q.pop();
                    sum = 0;
                    low[j] = i;
                    continue;
                }
                if (j == 1) {
                    while (!q.empty()) q.pop();
                    sum = 0;
                }
                ll H = i - low[j];
                ll num = 1;
                while (!q.empty() && q.top().h > H) {
                    num += q.top().num;
                    sum -= q.top().h * q.top().num;
                    q.pop();
                }
                sum += num * H;
                ans += sum;
                q.emplace(H, num);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}