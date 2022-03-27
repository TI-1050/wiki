#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N];

int main() {
    freopen("hello.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 12; ++i) {
            scanf("%d", a + i);
        }
        sort(a + 4, a + 12);
        bool F = true;
        for (int i = 1; i < 12; ++i) {
            if (a[i] < a[i - 1]) {
                F = false;
                break;
            }
        }
        puts(F ? "yes" : "no");
    }
    return 0;
}
