#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10;

int n;
int inv[N];
string s[N];
vector<vector<int> > G;
int linker[N], used[N];

bool dfs(int u) {
    for (auto v : G[u]) {
        if (!used[v]) {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungray() {
    int res = 0;
    memset(linker, -1, sizeof linker);
    for (int u = 1; u <= n; ++u) {
        if (inv[u] % 2 == 0)
            continue;
        memset(used, false, sizeof used);
        if (dfs(u))
            ++res;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    G.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; ++i) {
        int sze = s[i].size();
        for (int j = 1; j <= n; ++j) {
            int cnt = 0;
            for (int k = 0; k < sze; ++k) {
                cnt += s[i][k] != s[j][k];
            }
            if (cnt == 2) {
                G[i].push_back(j);
            }
        }
        for (int j = 0; j < sze; ++j) {
            for (int k = j + 1; k < sze; ++k) {
                inv[i] += (s[i][j] > s[i][k]);
            }
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << i << " " << inv[i] % 2 << endl;
    // }
    int res = hungray();
    // cout << res << endl;
    cout << n - res << endl;
    return 0;
}
