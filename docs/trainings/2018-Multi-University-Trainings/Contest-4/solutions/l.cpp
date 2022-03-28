#include <bits/stdc++.h>
using namespace std;

#define N 100010

int t, n;
int arr[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
        int ans = (int)floor(sqrt(abs(arr[1] - arr[n])));
        printf("%d\n", ans);
    }
    return 0;
}