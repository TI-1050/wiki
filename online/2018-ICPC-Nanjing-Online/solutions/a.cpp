#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t;
ll n;

inline void Run() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        printf("%lld\n", n - 1);
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();

    return 0;
}