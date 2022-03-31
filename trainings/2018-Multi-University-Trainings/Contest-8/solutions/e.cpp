#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
int t, n;
char G[5][5];

void C(pii a) {
    int x = a.first, y = a.second;
    char tmp[5][5];
    tmp[1][1] = G[x + 1][y];
    tmp[1][2] = G[x][y];
    tmp[2][1] = G[x + 1][y + 1];
    tmp[2][2] = G[x][y + 1];
    for (int i = 1; i <= 2; ++i)
        for (int j = 1; j <= 2; ++j) G[x + i - 1][y + j - 1] = tmp[i][j];
}

void R(pii a) {
    int x = a.first, y = a.second;
    char tmp[5][5];
    tmp[1][1] = G[x][y + 1];
    tmp[1][2] = G[x + 1][y + 1];
    tmp[2][1] = G[x][y];
    tmp[2][2] = G[x + 1][y];
    for (int i = 1; i <= 2; ++i)
        for (int j = 1; j <= 2; ++j) G[x + i - 1][y + j - 1] = tmp[i][j];
}

pii pos[4] = {
        pii(1, 1),
        pii(1, 2),
        pii(2, 1),
        pii(2, 2),
};

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= 3; ++i) scanf("%s", G[i] + 1);
        char op;
        int x;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %c", &x, &op);
            if (op == 'C')
                C(pos[x - 1]);
            else
                R(pos[x - 1]);
        }
        for (int i = 1; i <= 3; ++i) printf("%s\n", G[i] + 1);
    }
    return 0;
}