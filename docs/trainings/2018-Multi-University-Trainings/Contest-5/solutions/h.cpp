#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define INF 0x3f3f3f3f
int t, n, m, a[N], b[20];
int dp[N][20], tl[N][20], tr[N][20], res, l, r, ql, qr;

void solve() {
    for (int i = 1; i <= m; ++i) dp[0][i] = 0, tl[0][i] = -1, tr[0][i] = -1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
            tl[i][j] = tl[i - 1][j];
            tr[i][j] = tr[i - 1][j];
            if (a[i] == b[j]) {
                ++dp[i][j];
                if (j == ql && tl[i][j] == -1)
                    tl[i][j] = i;
                if (j == qr)
                    tr[i][j] = i;
            }
            if (j > 1 && dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                tl[i][j] = tl[i][j - 1];
                tr[i][j] = tr[i][j - 1];
            }
        }
    if (ql == 1 && qr == 1) {
        res = dp[n][m];
        l = 1;
        r = 1;
    } else if (dp[n][m] > res && tl[n][m] != -1 && tr[n][m] != -1) {
        res = dp[n][m];
        l = tl[n][m];
        r = tr[n][m];
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        res = 1, l = 1, r = 1;
        for (int i = 1; i <= n; ++i) scanf("%1d", a + i);
        for (int i = 1; i <= 10; ++i) b[i] = i - 1;
        m = 10;
        ql = 1, qr = 1;
        solve();
        for (int i = 1; i < m; ++i)
            for (int j = i + 1; j <= 10; ++j) {
                m = 0;
                for (int pos = 1; pos <= i; ++pos) b[++m] = pos - 1;
                ql = m + 1;
                for (int pos = j; pos >= i; --pos) b[++m] = pos - 1;
                qr = m;
                for (int pos = j; pos <= 10; ++pos) b[++m] = pos - 1;
                solve();
                // for (int i = 1; i <= m; ++i) printf("%d%c", b[i], " \n"[i == m]);
            }
        printf("%d %d %d\n", res, l, r);
    }
    return 0;
}