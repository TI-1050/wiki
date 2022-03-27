#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

#define dbg(x...)             \
    do {                      \
        cout << #x << " -> "; \
        err(x);               \
    } while (0)

void err() {
    cout << endl;
}

template <class T, class... Ts>
void err(const T& arg, const Ts&... args) {
    cout << arg << ' ';
    err(args...);
}

int n;
char s[N];
int a[N];
int f[N];
int P[N], tot;

bool ok(int l, int r) {
    if (l > r)
        return 1;
    else
        return a[r] - a[l - 1] == 0;
}

bool check(int x) {
    memset(f, 0, sizeof f);
    for (int i = 1; i <= tot; ++i) {
        // left
        if (ok(f[i - 1] + 1, P[i] - x - 1))
            f[i] = max(f[i], P[i]);
        // right
        if (ok(f[i - 1] + 1, P[i] - 1))
            f[i] = max(f[i], P[i] + x);
        // left right
        if (i >= 2 && ok(f[i - 2] + 1, P[i] - x - 1))
            f[i] = max(f[i], P[i - 1] + x);
    }
    // dbg(f[1], f[2]);
    return ok(f[tot] + 1, n);
}

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + (s[i] == '*');
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') {
            P[++tot] = i;
        }
    }
    if (tot == 1) {
        int cnt1 = 0, cnt2 = 0, pos = P[1], l = 0, r = 0;
        for (int i = pos - 1; i >= 1; --i) {
            if (s[i] == '*') {
                ++cnt1;
                l = i;
            }
        }
        for (int i = pos + 1; i <= n; ++i) {
            if (s[i] == '*') {
                ++cnt2;
                r = i;
            }
        }
        int res1 = 0, res2 = 0;
        if (cnt1 > cnt2) {
            res1 = cnt1, res2 = pos - l;
        } else if (cnt2 > cnt1) {
            res1 = cnt2, res2 = r - pos;
        } else {
            res1 = cnt1, res2 = min(pos - l, r - pos);
        }
        printf("%d %d\n", res1, res2);
    } else {
        printf("%d ", a[n]);
        // check(4);
        int l = 0, r = n, res = -1;
        while (r - l >= 0) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
