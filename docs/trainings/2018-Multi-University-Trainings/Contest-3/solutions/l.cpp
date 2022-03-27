#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, n, m;
char ans[200][200];

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(ans, 0, sizeof ans);
        scanf("%d%d%d", &a, &b, &c);
        n = (b + c) * 2 + 1;
        m = (a + b) * 2 + 1;
        for (int i = n, cnt = 1; cnt <= c; ++cnt, i -= 2) {
            for (int j = 1; j <= 2 * a; j += 2) ans[i][j] = '+', ans[i][j + 1] = '-';
        }
        for (int i = n - 1, cnt = 1; cnt <= c; ++cnt, i -= 2) {
            for (int j = 1; j <= 2 * a; j += 2) ans[i][j] = '|';
        }
        for (int i = 2 * b + 1, tmp = 0, cnt = 1; cnt <= b + 1; ++cnt, i -= 2, tmp += 2) {
            for (int j = 1 + tmp, cntt = 1; cntt <= a; ++cntt, j += 2) ans[i][j] = '+', ans[i][j + 1] = '-';
        }
        for (int i = 2 * b, tmp = 1, cnt = 1; cnt <= b; ++cnt, tmp += 2, i -= 2) {
            for (int j = 1 + tmp, cntt = 1; cntt <= a; ++cntt, j += 2) ans[i][j] = '/';
        }
        for (int j = m, cntt = 1, tmp = 0; cntt <= b + 1; ++cntt, j -= 2, tmp += 2) {
            for (int i = 1 + tmp, cnt = 1; cnt <= c + 1; ++cnt, i += 2) {
                ans[i][j] = '+';
                if (cnt <= c)
                    ans[i + 1][j] = '|';
            }
        }
        for (int j = m - 1, tmp = 1, cntt = 1; cntt <= b; ++cntt, tmp += 2, j -= 2) {
            for (int i = 1 + tmp, cnt = 1; cnt <= c + 1; ++cnt, i += 2) ans[i][j] = '/';
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                if (!ans[i][j])
                    ans[i][j] = '.';
            ans[i][m + 1] = 0;
            printf("%s\n", ans[i] + 1);
        }
    }
    return 0;
}