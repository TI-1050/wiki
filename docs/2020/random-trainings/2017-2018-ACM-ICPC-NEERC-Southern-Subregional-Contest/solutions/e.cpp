#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
string s;
string str[N];
int vis[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> s;
    for (auto it : s) {
        vis[it]++;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> str[i];
    }
    int res = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        char c = i;
        if (vis[i])
            continue;
        bool F = true;
        for (int j = 1; j <= m; ++j) {
            memset(cnt, 0, sizeof cnt);
            bool FF = true;
            for (int k = 0; k < n; ++k) {
                if (s[k] == '*' && vis[str[j][k]]) {
                    FF = false;
                    break;
                }
                if (s[k] == '*') {
                    cnt[str[j][k]]++;
                } else if (s[k] != str[j][k]) {
                    FF = false;
                    break;
                }
            }
            if (FF && !cnt[c]) {
                F = false;
                break;
            }
        }
        res += F;
    }
    cout << res << "\n";
    return 0;
}
