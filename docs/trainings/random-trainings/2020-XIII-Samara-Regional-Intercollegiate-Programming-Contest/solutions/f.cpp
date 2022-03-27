#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    printf("%d\n", n / 2 + 1);
    for (int i = 1; i <= n / 2 + 1; ++i) {
        printf("%d%c", min(n, 2 * i - 1), " \n"[min(n, 2 * i - 1) == n]);
    }
    return 0;
}
