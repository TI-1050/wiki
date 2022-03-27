#include <bits/stdc++.h>

using namespace std;

const int N = 100;

string st;
int a[N], b[N];
int n;
bool flag;
long long ans;

void gao(int t) {
    if (t > (n + 1) / 2) {
        for (int i = t; i <= n; ++i) {
            int x = 0;
            for (int j = 1; j < t; ++j) {
                x += b[j] * b[i - j + 1];
            }
            x = x % 10;
            if (x != a[i])
                return;
        }
        flag = false;
        long long y = 0;
        for (int i = t - 1; i > 0; --i) y = y * 10 + b[i];
        if (y < ans)
            ans = y;
    } else
        for (int i = 0; i < 10; ++i) {
            int x = 0, y = 0;
            b[t] = i;
            for (int j = 1; j <= t; ++j) {
                x += b[j] * b[t - j + 1];
            }
            x = x % 10;
            if (x == a[t])
                gao(t + 1);
        }
}

int main() {
    cin >> st;
    n = st.length();
    ans = 100000000000000;
    for (int i = 0; i < n; ++i) {
        a[n - i] = st[i] - 48;
    }
    if (n & 1) {
        flag = true;
        gao(1);
        if (flag)
            cout << -1 << endl;
        else
            cout << ans << endl;
    } else
        cout << -1 << endl;
    return 0;
}
