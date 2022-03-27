#include <bits/stdc++.h>

using namespace std;

int n;
string s;
map<string, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        string t = "";
        for (int j = 0, len = s.size(); j < len; ++j) {
            if (s[j] == 'u')
                t += "oo";
            else {
                if (s[j] == 'h') {
                    while (!t.empty() && t[t.size() - 1] == 'k') {
                        t.pop_back();
                    }
                }
                t += s[j];
            }
        }
        if (!mp.count(t)) {
            mp[t]++;
            ++res;
        }
    }
    cout << res << "\n";
    return 0;
}
