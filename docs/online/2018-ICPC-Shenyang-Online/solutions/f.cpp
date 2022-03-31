#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 10;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

struct node {
    int l, r;
    inline node() {}
    inline node(int l, int r) : l(l), r(r) {}
} arr[maxn];

bool flag = false;
int n, m, k;
int sum;
int res_L;
int res_R;
int L, R;
int du_left[maxn];
int du_right[maxn];

inline void Init() {
    memset(du_left, 0, sizeof du_left);
    memset(du_right, 0, sizeof du_right);
}

inline void DFS(int idx, int cnt) {
    if (sum == n + m) {
        flag = true;
        return;
    }
    if (idx > k)
        return;
    if (k - idx + 1 + cnt < res_L)
        return;
    if (cnt >= res_R)
        return;
    if (flag)
        return;
    // do
    if (du_left[arr[idx].l] < R && du_right[arr[idx].r] < R) {
        du_left[arr[idx].l]++;
        du_right[arr[idx].r]++;
        if (du_left[arr[idx].l] == L)
            sum++;
        if (du_right[arr[idx].r] == L)
            sum++;
        DFS(idx + 1, cnt + 1);
        if (flag)
            return;
        if (du_left[arr[idx].l] == L)
            sum--;
        if (du_right[arr[idx].r] == L)
            sum--;
        du_left[arr[idx].l]--;
        du_right[arr[idx].r]--;
    }
    // not do
    DFS(idx + 1, cnt);
    if (flag)
        return;
}

inline void RUN() {
    int cas = 0;
    while (~scanf("%d %d %d", &n, &m, &k)) {
        printf("Case %d: ", ++cas);
        Init();
        scanf("%d %d", &L, &R);
        int cnt = 0;
        for (int i = 1; i <= k; ++i) {
            scanf("%d %d", &arr[i].l, &arr[i].r);
            du_left[arr[i].l]++;
            du_right[arr[i].r]++;
            if (du_left[arr[i].l] == L)
                cnt++;
            if (du_right[arr[i].r] == L)
                cnt++;
        }
        if (L == 0) {
            puts("Yes");
            continue;
        }
        if (cnt != n + m) {
            puts("No");
            continue;
        }
        sum = 0;
        res_L = ((n + m) * L + 1) / 2;
        res_R = ((n + m) * R) / 2;
        Init();
        flag = false;
        DFS(1, 0);
        puts(flag ? "Yes" : "No");
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
}