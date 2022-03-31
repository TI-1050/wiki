#include <bits/stdc++.h>

using namespace std;

#define N 100010

struct node {
    int l, r;
    inline void scan() {
        scanf("%d%d", &l, &r);
    }
    inline bool operator<(const node &r) const {
        return l < r.l || (l == r.l && this->r > r.r);
    }
} Data[N];

int t, n, m;
int ans[N];
bool vis[N];
int R;

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(ans, 0, sizeof ans);
        R = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) Data[i].scan();
        sort(Data + 1, Data + 1 + m);
        for (int i = 1; i <= m; ++i) {
            int l = Data[i].l, r = Data[i].r;
            if (R >= r)
                continue;
            if (R + 1 < l)
                for (int j = R + 1; j < l; ++j) ans[j] = 1;
            memset(vis, false, sizeof vis);
            for (int j = l; j <= R; ++j) vis[ans[j]] = true;
            int L = 1;
            for (int j = max(R + 1, l); j <= r; ++j) {
                while (vis[L]) ++L;
                ans[j] = L;
                vis[L] = true;
            }
            R = max(R, r);
        }
        while (R < n) {
            R++;
            ans[R] = 1;
        }
        for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}