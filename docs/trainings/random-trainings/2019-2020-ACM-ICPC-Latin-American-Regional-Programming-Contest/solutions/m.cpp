#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, x;
int a[N], b[N];

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        b[i] = a[i] - a[i - 1];
    }
    int res = 1, cnt = 1;
    for (int i = 2; i <= n; ++i) {
        if (b[i] <= x) {
            ++cnt;
        } else {
            cnt = 1;
        }
        res = max(res, cnt);
        // cout << i << " " << cnt << endl;
    }
    printf("%d\n", res);
    return 0;
}
