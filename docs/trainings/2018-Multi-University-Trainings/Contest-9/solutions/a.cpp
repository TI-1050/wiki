#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll p;
ll dp[81][81][81 * 81];

ll DFS(int x, int y, int z) {
    if (z >= n * m)
        return 1;
    if (dp[x][y][z] != -1)
        return dp[x][y][z];
    ll res = 0;
    if (x < n)
        res = (res + y * (n - x) % p * DFS(x + 1, y, z + 1)) % p;
    if (y < m)
        res = (res + x * (m - y) % p * DFS(x, y + 1, z + 1)) % p;
    if (x * y > z)
        res = (res + (x * y - z) * DFS(x, y, z + 1)) % p;
    dp[x][y][z] = res;
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %lld", &n, &m, &p);
        memset(dp, -1, sizeof dp);
        ll ans = DFS(1, 1, 1);
        ans = n * m % p * ans % p;
        printf("%lld\n", ans);
    }
    return 0;
}