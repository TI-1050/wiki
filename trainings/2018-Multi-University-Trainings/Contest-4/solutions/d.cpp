#include <bits/stdc++.h>
using namespace std;

#define N 110
#define ll long long

struct node {
    int a, b, sum;
    inline void scan() {
        scanf("%d%d", &a, &b);
        sum = a + b;
    }
    inline bool operator<(const node &r) const {
        return sum < r.sum;
    }
} arr[N];

int t, n, m;
ll sum;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) arr[i].scan();
        sort(arr + 1, arr + 1 + n);
        int ans = 0;
        sum = 1;
        for (int i = 1; i <= n; ++i) {
            sum *= arr[i].sum;
            if (sum > m)
                break;
            ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}