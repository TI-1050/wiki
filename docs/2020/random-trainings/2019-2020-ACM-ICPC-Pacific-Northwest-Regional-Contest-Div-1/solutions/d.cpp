#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll a, b;

int main() {
    scanf("%lld %lld", &a, &b);
    ll res = 0;
    while (a > b) {
        if (a & 1)
            ++a;
        else
            a /= 2;
        ++res;
    }
    res += b - a;
    printf("%lld\n", res);
    return 0;
}
