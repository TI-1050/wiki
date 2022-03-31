#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define ll long long

const ll MOD = 998244353;

ll arr[N];

int main() {
    arr[4] = 1, arr[5] = 8;
    for (int i = 6; i <= 100000; ++i)
        arr[i] = ((i - 2) * arr[i - 1] % MOD + (i - 1) * arr[i - 2] % MOD + ((i & 1) ? 1 : -1) + MOD) % MOD;
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }
}