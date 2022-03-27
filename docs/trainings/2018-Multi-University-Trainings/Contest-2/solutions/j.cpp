#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N 100010

int n, m;
ll x, y;
int arr[N], brr[N];
int a[N];

inline void Init() {
    for (int i = 1; i <= n; ++i) brr[i] = arr[i];
    sort(brr + 1, brr + 1 + n);
    m = unique(brr + 1, brr + 1 + n) - brr - 1;
}

inline int Get(int x) {
    return lower_bound(brr + 1, brr + 1 + m, x) - brr;
}

inline int lowbit(int x) {
    return x & (-x);
}

inline void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i)) a[i] += val;
}

inline int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) res += a[i];
    return res;
}

int main() {
    while (scanf("%d%lld%lld", &n, &x, &y) != EOF) {
        for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
        Init();
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; ++i) arr[i] = Get(arr[i]);
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            //    ans += i - 1 - query(arr[i] - 1);
            //    printf("%d %d\n", arr[i], query(arr[i] - 1));
            update(arr[i], 1);
            ans += i - query(arr[i]);
            //    cout << arr[i] << " " << query(arr[i]) << endl;
        }
        printf("%lld\n", min(ans * x, ans * y));
    }
    return 0;
}