#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 2010

int t, p;
int a[N][N], b[N][N];

inline void Run() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &p);
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < p; ++j) {
                a[i][j] = (i + j) % p;
                b[i][j] = (i * j) % p;
            }
        }
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < p; ++j) {
                printf("%d%c", a[i][j], " \n"[j == p - 1]);
            }
        }
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < p; ++j) {
                printf("%d%c", b[i][j], " \n"[j == p - 1]);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();

    return 0;
}