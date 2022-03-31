#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
char s[N][N];
int suf[N][N];

bool check(int x) {
    for (int j = 1; j <= m; ++j) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (suf[i][j] >= x)
                ++cnt;
            else
                cnt = 0;
            if (cnt >= x)
                return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
        suf[i][m] = 1;
        for (int j = m - 1; j >= 1; --j) {
            if (s[i][j] == s[i][j + 1])
                suf[i][j] = suf[i][j + 1] + 1;
            else
                suf[i][j] = 1;
        }
    }
    int l = 1, r = 1000, res = -1;
    while (r - l >= 0) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", res * res);
    return 0;
}
