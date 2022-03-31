#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 2e6 + 10;

string s[] = {"1", "2", "3", "5", "7", "11", "13", "17", "23", "31", "37", "53", "71", "73", "113", "131", "137", "173",
        "311", "317"};

inline void RUN() {
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; ++cas) {
        cout << "Case #" << cas << ": ";
        string ans;
        string str;
        cin >> str;
        for (int i = 0; i < 20; ++i) {
            if (str.length() == s[i].length()) {
                if (str >= s[i])
                    ans = s[i];
            } else if (str.length() < s[i].length()) {
                continue;
            } else
                ans = s[i];
        }
        cout << ans << endl;
    }
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("Text.txt", "r", stdin);
#endif  // LOCAL_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    RUN();

#ifdef LOCAL_JUDGE
    fclose(stdin);
#endif  // LOCAL_JUDGE
}