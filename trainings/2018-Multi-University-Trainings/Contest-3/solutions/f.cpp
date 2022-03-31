#include <bits/stdc++.h>
using namespace std;

#define N 100010

int t, n;
int arr[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", arr + i);
            res ^= arr[i];
        }
        for (int i = 1, u, v; i < n; ++i) scanf("%d%d", &u, &v);
        if (res == 0) {
            puts("D");
            continue;
        }
        puts("Q");
    }
    return 0;
}