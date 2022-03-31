#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 + 10;

int n, m;
char str[maxn][maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        //        printf("%d %d\n", n, m);
        if (n % 2 == 1 && m % 2 == 1) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    printf("(");
                }
                printf("\n");
            }
        } else if (n % 2 == 1) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (j & 1)
                        printf("(");
                    else
                        printf(")");
                }
                printf("\n");
            }
        } else if (m % 2 == 1) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (i & 1)
                        printf("(");
                    else
                        printf(")");
                }
                printf("\n");
            }
        } else if (n == 2) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (i & 1)
                        printf("(");
                    else
                        printf(")");
                }
                printf("\n");
            }
        } else if (m == 2) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (j & 1)
                        printf("(");
                    else
                        printf(")");
                }
                printf("\n");
            }
        } else if (n == 4) {
            for (int i = 1; i <= m; ++i) printf("(");
            printf("\n");
            for (int i = 1; i <= m; ++i) {
                if (i & 1)
                    printf("(");
                else
                    printf(")");
            }
            printf("\n");
            for (int i = 1; i <= m; ++i) {
                if (i & 1)
                    printf(")");
                else
                    printf("(");
            }
            printf("\n");
            for (int i = 1; i <= m; ++i) printf(")");
            printf("\n");
        } else if (m == 4) {
            for (int i = 1; i <= n; ++i) str[i][1] = '(';
            for (int i = 1; i <= n; ++i) {
                if (i & 1)
                    str[i][2] = '(';
                else
                    str[i][2] = ')';
            }
            for (int i = 1; i <= n; ++i) {
                if (i & 1)
                    str[i][3] = ')';
                else
                    str[i][3] = '(';
            }
            for (int i = 1; i <= n; ++i) str[i][4] = ')';
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    printf("%c", str[i][j]);
                }
                printf("\n");
            }
        } else {
            for (int i = 1; i <= m; ++i) str[1][i] = '(';
            for (int i = 2; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (i & 1) {
                        if (j == 1)
                            str[i][j] = '(';
                        else if (j == m)
                            str[i][j] = ')';
                        else if (j & 1)
                            str[i][j] = ')';
                        else
                            str[i][j] = '(';
                    } else {
                        if (j & 1)
                            str[i][j] = '(';
                        else
                            str[i][j] = ')';
                    }
                }
            }
            for (int i = 1; i <= m; ++i) str[n][i] = ')';
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    printf("%c", str[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}