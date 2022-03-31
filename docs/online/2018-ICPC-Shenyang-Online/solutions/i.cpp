#include <bits/stdc++.h>
using namespace std;

#define N 100010

int t, n, m;
string str, tmp, ttmp, ans, s;
unordered_map<string, char> mp;
unordered_map<char, string> mmp;

inline void Init() {
    mmp.clear();
    mmp['0'] = "0000";
    mmp['1'] = "0001";
    mmp['2'] = "0010";
    mmp['3'] = "0011";
    mmp['4'] = "0100";
    mmp['5'] = "0101";
    mmp['6'] = "0110";
    mmp['7'] = "0111";
    mmp['8'] = "1000";
    mmp['9'] = "1001";
    mmp['A'] = "1010";
    mmp['B'] = "1011";
    mmp['C'] = "1100";
    mmp['D'] = "1101";
    mmp['E'] = "1110";
    mmp['F'] = "1111";
    mmp['a'] = "1010";
    mmp['b'] = "1011";
    mmp['c'] = "1100";
    mmp['d'] = "1101";
    mmp['e'] = "1110";
    mmp['f'] = "1111";
}

inline bool ok(string s) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) cnt += (s[i] == '1');
    if ((s[8] == '0' && (cnt & 1)) || (s[8] == '1' && (cnt & 1) == 0))
        return true;
    return false;
}

inline void Run() {
    cin.tie(0), cout.tie(0);
    Init();
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        mp.clear();
        cin >> m >> n;
        for (int i = 1, num; i <= n; ++i) {
            cin >> num >> str;
            mp[str] = num;
        }
        cin >> s;
        tmp = "";
        str = "";
        for (int i = 0, len = s.size(); i < len; ++i) tmp += mmp[s[i]];
        for (int i = 0, len = tmp.size(); i < len;) {
            if (len - i < 9)
                break;
            ttmp = "";
            for (int cnt = 0; cnt < 9; ++cnt, ++i) ttmp += tmp[i];
            if (ok(ttmp)) {
                ttmp.erase(ttmp.end() - 1);
                str += ttmp;
                // cout << ttmp << endl;
            }
        }
        // for (auto it : mp) cout << it.first << " " << it.second << endl;
        ans.clear(), tmp.clear();
        for (int i = 0, len = str.size(); i < len && ans.size() < m; ++i) {
            tmp += str[i];
            if (mp.find(tmp) != mp.end()) {
                ans += mp[tmp];
                tmp = "";
            }
        }
        cout << ans << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();
    return 0;
}