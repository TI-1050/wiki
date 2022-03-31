#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[1 << 20];

int n;

struct node {
    ll ai, bi;
    int state;
    inline node() {}
    inline node(ll ai, ll bi, int state) : ai(ai), bi(bi), state(state) {}
} arr[30];

inline ll DFS(int t, int S) {
    if (t > n)
        return 0;
    if (dp[S] != -1)
        return dp[S];
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = 1 << i;
        if ((tmp & S) == 0) {
            if ((S & arr[i].state) != arr[i].state)
                continue;
            res = max(res, t * arr[i].ai + arr[i].bi + DFS(t + 1, (S | tmp)));
        }
    }
    dp[S] = res;
    return res;
}

inline void RUN() {
    while (~scanf("%d", &n)) {
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; ++i) {
            int m;
            int S = 0;
            scanf("%lld %lld %d", &arr[i].ai, &arr[i].bi, &m);
            while (m--) {
                int tmp = 0;
                scanf("%d", &tmp);
                S += (1 << (tmp - 1));
            }
            arr[i].state = S;
        }
        ll ans = DFS(1, 0);
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