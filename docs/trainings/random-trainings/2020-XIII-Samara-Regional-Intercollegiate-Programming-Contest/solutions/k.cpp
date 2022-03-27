#include <bits/stdc++.h>

using namespace std;

int a[5];

int main() {
    for (int i = 1; i <= 4; ++i) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + 1 + 4);
    if (a[4] - a[3] == a[2] - a[1])
        puts("YES");
    else
        puts("NO");
    return 0;
}
