#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
char s[N][N];
int vis[N][N];

void gao(int x, int y) {
    if (x < 0 || x > n + 1 || y < 0 || y > m + 1)
        return;
    vis[x][y] = true;
    if (s[x + 1][y] == '.' && !vis[x + 1][y])
        gao(x + 1, y);
    if (s[x - 1][y] == '.' && !vis[x - 1][y])
        gao(x - 1, y);

    if (s[x][y + 1] == '.' && !vis[x][y + 1])
        gao(x, y + 1);
    if (s[x][y - 1] == '.' && !vis[x][y - 1])
        gao(x, y - 1);

    if (s[x + 1][y + 1] == '.' && !vis[x + 1][y + 1] && s[x + 1][y] == '\\')
        gao(x + 1, y + 1);
    if (s[x - 1][y + 1] == '.' && !vis[x - 1][y + 1] && s[x - 1][y] == '/')
        gao(x - 1, y + 1);

    if (s[x + 1][y - 1] == '.' && !vis[x + 1][y - 1] && s[x + 1][y] == '/')
        gao(x + 1, y - 1);
    if (s[x - 1][y - 1] == '.' && !vis[x - 1][y - 1] && s[x - 1][y] == '\\')
        gao(x - 1, y - 1);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    for (int i = 0; i <= m + 1; ++i) {
        gao(0, i);
        gao(n + 1, i);
    }
    for (int i = 0; i <= n + 1; ++i) {
        gao(i, 0);
        gao(i, m + 1);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '/' && s[i][j + 1] == '\\' && s[i + 1][j] == '\\' && s[i + 1][j + 1] == '/')
                res++;
            else if (s[i][j] == '.' && !vis[i][j]) {
                res++;
                gao(i, j);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
