#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    if (n == 1) {
        printf("%d\n", 1);
        printf("%d\n", 1);
    } else if (n == 2) {
        printf("%d\n", 2);
        puts("0");
        puts("11");
    } else {
        printf("%d\n", n - 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (j == 1 || j == i)
                    printf("0");
                else
                    printf("1");
            }
            puts("");
        }
    }
    return 0;
}
