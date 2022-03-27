#include <bits/stdc++.h>

using namespace std;

#define N 100010

struct node {
    int l, r;
    inline node() {}
    inline node(int l, int r) : l(l), r(r) {}
    inline bool operator<(const node &b) const {
        int t1 = min(l, b.r), t2 = min(r, b.l);
        return t1 > t2 || (t1 == t2 && (l > b.l));
    }
} arr[N];

int t, n;
char s[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        int L = 0, R = 0, ans = 0, cnt = 0;
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
            if (LL && RR)
                arr[++cnt] = node(LL, RR);
            else if (LL)
                L += LL;
            else
                R += RR;
        }
        sort(arr + 1, arr + 1 + cnt);
        for (int i = 1; i <= cnt; ++i) {
            int LL = arr[i].l, RR = arr[i].r;
            ans += min(L, RR) * 2;
            L -= min(L, RR);
            L += LL;
        }
        ans += min(L, R) * 2;
        printf("%d\n", ans);
    }
    return 0;
}