#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 0x3f3f3f3f
#define N 40010

int t;
ll n, a, cnt;

ll arr[N][2];

inline void Run() {
    for (int i = 3; i <= 40000; ++i) {
        cnt = 1;
        ll a = i;
        while ((a & 1) == 0 && a > 4) {
            cnt <<= 1;
            a >>= 1;
        }
        if (a == 4) {
            arr[i][0] = cnt * 3, arr[i][1] = cnt * 4;
        } else {
            ll b = a * a / 2;
            ll c = b + 1;
            arr[i][0] = b * cnt;
            arr[i][1] = c * cnt;
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &n, &a);
        if (n == 0 || n >= 3) {
            puts("-1 -1");
            continue;
        }
        if (n == 1) {
            printf("1 %lld\n", a + 1);
            continue;
        }
        printf("%lld %lld\n", arr[a][0], arr[a][1]);
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();

    return 0;
}