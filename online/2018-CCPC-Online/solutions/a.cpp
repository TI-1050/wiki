#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100010

int t, n;
ll arr[N];
priority_queue<ll, vector<ll>, greater<ll> > q[2];

inline void Run() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%lld", arr + i);
        for (int i = 0; i < 2; ++i)
            while (!q[i].empty()) q[i].pop();
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (q[0].empty() && q[1].empty())
                q[0].emplace(arr[i]);
            else if (q[1].empty()) {
                ll top = q[0].top();
                if (arr[i] > top) {
                    q[0].pop();
                    ans += arr[i] - top;
                    q[1].emplace(arr[i]);
                } else
                    q[0].emplace(arr[i]);
            } else if (q[0].empty()) {
                ll top = q[1].top();
                if (arr[i] > top) {
                    q[1].pop();
                    ans += arr[i] - top;
                    q[0].emplace(top);
                    q[1].emplace(arr[i]);
                } else {
                    q[0].emplace(arr[i]);
                }
            } else {
                ll top1 = q[0].top(), top2 = q[1].top();
                if (top1 < top2) {
                    if (arr[i] > top1) {
                        q[0].pop();
                        ans += arr[i] - top1;
                        q[1].emplace(arr[i]);
                    } else {
                        q[0].emplace(arr[i]);
                    }
                } else {
                    if (arr[i] > top2) {
                        q[1].pop();
                        ans += arr[i] - top2;
                        q[0].emplace(top2);
                        q[1].emplace(arr[i]);
                    } else {
                        q[0].emplace(arr[i]);
                    }
                }
            }
        }
        printf("%lld %d\n", ans, q[1].size() * 2);
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();

    return 0;
}