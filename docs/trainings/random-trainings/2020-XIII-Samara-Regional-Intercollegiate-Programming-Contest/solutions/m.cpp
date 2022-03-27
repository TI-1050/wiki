#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e5 + 10;

int n;
int t[N], d[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", t + i, d + i);
    }
    ll res = 0;
    int pos = 1;
    priority_queue<int, vector<int>, greater<int>> q;
    while (true) {
        if (pos > n && q.empty())
            break;
        while (pos <= n && t[pos] <= res) {
            q.push(d[pos]);
            pos++;
        }
        if (!q.empty()) {
            res += q.top();
            q.pop();
        } else {
            res = t[pos];
        }
    }
    printf("%lld\n", res);
    return 0;
}
