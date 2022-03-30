#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 10;

int n, m, k;
ll s, ans, val[maxn];
vector<ll> vec;
bool vis[maxn];
ll sum[maxn << 1];
ll que[maxn << 1];

inline ll cal(int count) {
    int len = vec.size();
    for (int i = 0; i < len; ++i) {
        que[i] = que[i + len] = vec[i];
    }
    len <<= 1;
    list<ll> q;
    int st = 0;
    int ed = 0;
    ll res = 0;
    for (int i = 0; i < len; ++i) {
        if (i == 0) {
            sum[i] = que[i];
        } else {
            sum[i] = sum[i - 1] + que[i];
        }
    }
    for (int i = 0; i < len; ++i) {
        while (!q.empty() && sum[q.front()] > sum[i]) {
            q.pop_front();
        }
        q.push_front(i);
        while (!q.empty() && i - q.back() > count) {
            q.pop_back();
        }
        res = max(res, sum[i] - sum[q.back()]);
    }
    return res;
}

inline ll solve() {
    ll mod = m % vec.size();
    ll circle = m / vec.size();
    ll sum = 0;
    for (auto it : vec) {
        sum += it;
    }
    ll max1 = cal(mod);
    ll max2 = cal(vec.size());
    max1 += max(0ll, sum) * circle;
    max2 += max(0LL, sum) * ((circle > 2) ? circle - 1 : 0);
    return max(max1, max2);
}

inline void RUN() {
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        memset(vis, false, sizeof vis);
        scanf("%d %lld %d %d", &n, &s, &m, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", val + i);
        }
        ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                vec.clear();
                vis[i] = true;
                vec.push_back(val[i]);
                for (int j = (i + k) % n; j != i && !vis[j]; j = (j + k) % n) {
                    vis[j] = true;
                    vec.push_back(val[j]);
                }
                ans = max(ans, solve());
            }
        }
        if (ans >= s)
            ans = 0;
        else
            ans = s - ans;
        printf("Case #%d: %lld\n", cas, ans);
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