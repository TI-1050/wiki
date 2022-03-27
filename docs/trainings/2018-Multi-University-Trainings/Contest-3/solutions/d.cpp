#include <bits/stdc++.h>

using namespace std;

#define N 100010

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline void Init() {
    for (int i = 1; i <= 100; ++i) {
        int res = 0;
        for (int j = 1; j < i; ++j) res += (gcd(i, j) == 1);
        printf("%d %d\n", i, res);
    }
}

int t, n;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n == 1)
            puts("5");
        else
            printf("%d\n", n + 5);
    }
    return 0;
}