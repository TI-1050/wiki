#include <bits/stdc++.h>

using namespace std;

#define N 100010

struct node {
    int l, r;
    inline node() {}
    inline node(int l, int r) : l(l), r(r) {}
    inline bool operator<(const node &b) const {
        if (l >= r && b.l < b.r)
            return true;
        if (l < r && b.l >= b.r)
            return false;
        if (l >= r && b.l >= b.r)
            return r < b.r;
        if (l < r && b.l < b.r)
            return l > b.l;
    }
} arr[N];

int t, n;
char s[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        int ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s);
            int LL = 0, RR = 0;
            for (int j = 0, len = strlen(s); j < len; ++j) {
                if (s[j] == '(')
                    ++LL;
                else {
                    if (LL) {
                        --LL;
                        ans += 2;
                    } else
                        ++RR;
                }
            }
            arr[i] = node(LL, RR);
        }
        sort(arr + 1, arr + 1 + n);
        int L = 0;
        for (int i = 1; i <= n; ++i) {
            int LL = arr[i].l, RR = arr[i].r;
            ans += min(L, RR) * 2;
            L -= min(L, RR);
            L += LL;
        }
        printf("%d\n", ans);
    }
    return 0;
}