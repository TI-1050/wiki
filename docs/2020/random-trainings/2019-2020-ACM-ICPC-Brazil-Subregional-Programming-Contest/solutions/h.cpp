#include <bits/stdc++.h>

using namespace std;

int v, n;

int main() {
    scanf("%d %d", &v, &n);
    for (int i = 1; i <= 9; ++i) {
        int res = ((v * n * i) + 9) / 10;
        printf("%d%c", res, " \n"[i == 9]);
    }
    return 0;
}
