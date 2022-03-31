#include <bits/stdc++.h>
using namespace std;

#define ll long long

char s[110];
ll suffix[110];
int vis[110];

unordered_map<char, int> mp;

inline void Init() {
    mp.clear();
    mp['('] = 0;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['d'] = 3;
}

stack<char> symbol;
stack<ll> Min, Max;

inline void Run() {
    Init();
    while (scanf("%s", s) != EOF) {
        while (!symbol.empty()) symbol.pop();
        while (!Min.empty()) Min.pop();
        while (!Max.empty()) Max.pop();
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        for (int i = 0, len = strlen(s); i < len; ++i) {
            if (isdigit(s[i])) {
                ll tmp = 0;
                int flag = 1;
                if (i == 1 && s[0] == '-')
                    symbol.pop(), flag = -1;
                else if (i > 1 && s[i - 1] == '-' && s[i - 2] == '(')
                    symbol.pop(), flag = -1;
                for (; i < len && isdigit(s[i]); ++i) {
                    tmp = tmp * 10 + s[i] - '0';
                }
                suffix[++cnt] = tmp * flag;
                --i;
            } else {
                if (symbol.empty())
                    symbol.emplace(s[i]);
                else if (s[i] == '(')
                    symbol.emplace(s[i]);
                else if (s[i] == ')') {
                    while (1) {
                        int top = symbol.top();
                        symbol.pop();
                        if (top == '(')
                            break;
                        suffix[++cnt] = top;
                        vis[cnt] = 1;
                    }
                } else {
                    while (!symbol.empty() && mp[symbol.top()] >= mp[s[i]]) {
                        suffix[++cnt] = symbol.top();
                        symbol.pop();
                        vis[cnt] = 1;
                    }
                    symbol.emplace(s[i]);
                }
            }
        }
        while (!symbol.empty()) {
            suffix[++cnt] = symbol.top();
            symbol.pop();
            vis[cnt] = 1;
        }
        for (int i = 1; i <= cnt; ++i) {
            if (!vis[i]) {
                Min.emplace(suffix[i]);
                Max.emplace(suffix[i]);
            } else {
                ll top1 = Min.top();
                Min.pop();
                ll top2 = Min.top();
                Min.pop();
                ll top3 = Max.top();
                Max.pop();
                ll top4 = Max.top();
                Max.pop();
                if (suffix[i] == '+') {
                    Min.emplace(top1 + top2);
                    Max.emplace(top3 + top4);
                } else if (suffix[i] == '-') {
                    Min.emplace(top2 - top3);
                    Max.emplace(top4 - top1);
                } else if (suffix[i] == '*') {
                    ll ansmin = top2 * top1;
                    ansmin = min(ansmin, top2 * top3);
                    ansmin = min(ansmin, top4 * top1);
                    ansmin = min(ansmin, top4 * top3);
                    ll ansmax = top2 * top1;
                    ansmax = max(ansmax, top2 * top3);
                    ansmax = max(ansmax, top4 * top1);
                    ansmax = max(ansmax, top4 * top3);
                    Min.emplace(ansmin);
                    Max.emplace(ansmax);
                } else {
                    Min.emplace(top2);
                    Max.emplace(top3 * top4);
                }
            }
        }
        printf("%lld %lld\n", Min.top(), Max.top());
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();
    return 0;
}