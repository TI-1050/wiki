#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 10;

int ans;
bool vis[20];
char s[20];
int G[maxn][maxn];

inline bool judge(int x, int y) {
    for (int i = x * 4 - 3; i <= x * 4; ++i) {
        memset(vis, false, sizeof vis);
        for (int j = 1; j <= y * 4; ++j) {
            if (vis[G[i][j]])
                return false;
            vis[G[i][j]] = true;
        }
    }
    for (int i = y * 4 - 3; i <= y * 4; ++i) {
        memset(vis, false, sizeof vis);
        for (int j = 1; j <= x * 4; ++j) {
            if (vis[G[j][i]])
                return false;
            vis[G[j][i]] = true;
        }
    }
    return true;
}

inline void fun(int x, int y) {
    int tmp[10][10];
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            tmp[j][4 - i + 1] = G[(x - 1) * 4 + i][(y - 1) * 4 + j];
        }
    }
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            G[(x - 1) * 4 + i][(y - 1) * 4 + j] = tmp[i][j];
        }
    }
}
inline void DFS(int x, int y, int res) {
    if (res >= ans)
        return;
    if (y > 4) {
        DFS(x + 1, 1, res);
        return;
    }
    if (x == 5) {
        ans = min(ans, res);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (i) {
            fun(x, y);
            /*            if(x == 3 && y == 1 && i == 1)
            {
            for(int i = x * 4 - 3; i <= x * 4; ++i)
            {
            for(int j = y * 4 - 3; j <= y * 4; ++j)
            {
            printf("%d%c", G[i][j], " \n"[j == y * 4]);
            }
            }
            }*/
        }
        if (judge(x, y)) {
            DFS(x, y + 1, res + i);
        }
    }
    fun(x, y);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ans = 1 << 16;
        for (int i = 1; i <= 16; ++i) {
            scanf("%s", s + 1);
            for (int j = 1; j <= 16; ++j) {
                if (s[j] >= '0' && s[j] <= '9') {
                    G[i][j] = s[j] - '0';
                } else if (s[j] >= 'A' && s[j] <= 'F') {
                    G[i][j] = (s[j] - 'A') + 10;
                }
            }
        }
        //    fun(1, 1);
        DFS(1, 1, 0);
        printf("%d\n", ans);
    }
    return 0;
}