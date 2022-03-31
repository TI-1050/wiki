#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n;
int a[N];
vector<vector<int> > G;
int col[N], in[N], vis[N][6];

int gao() {
    int rt = 0;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            rt = i;
            break;
        }
    }
    int Max = 0;
    queue<int> q;
    q.push(rt);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= 5; ++i) {
            if (vis[u][i])
                continue;
            col[u] = i;
            Max = max(Max, i);
            for (auto v : G[u]) {
                vis[v][i] = 1;
                in[v]--;
                if (in[v] == 0) {
                    q.push(v);
                }
            }
            break;
        }
    }
    return Max;
}

int main() {
    freopen("tour.in", "r", stdin);

    int _T;
    scanf("%d", &_T);
    while (_T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            col[i] = 0;
            in[i] = 0;
            for (int j = 0; j < 6; ++j) {
                vis[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }
        G.clear();
        G.resize(n + 1);
        stack<int> stk;
        for (int i = 1; i <= n; ++i) {
            while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
            if (!stk.empty()) {
                int u = stk.top();
                int v = i;
                G[u].push_back(v);
                in[v]++;
            }
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = n; i >= 1; --i) {
            while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
            if (!stk.empty()) {
                int u = stk.top();
                int v = i;
                G[u].push_back(v);
                in[v]++;
            }
            stk.push(i);
        }
        int Max = gao();
        printf("%d\n", Max);
        for (int i = 1; i <= n; ++i) {
            printf("%d%c", col[i], " \n"[i == n]);
        }
    }
    return 0;
}
