#include <bits/stdc++.h>

using namespace std;

int t, a, b;
char s[10];

inline void work1() {
    int ans = 0;
    int flag = 1;
    if (s[0] == '-')
        flag = -1;
    int len = strlen(s);
    for (int i = 1; i < len; ++i) ans = ans * 10 + s[i] - '0';
    ans *= flag;
    int gap = ans - 8;
    a = (a + gap + 24) % 24;
    printf("%02d:%02d\n", a, b);
    return;
}

inline void work2() {
    int A = 0, B = 0;
    int flag = 1;
    if (s[0] == '-')
        flag = -1;
    int len = strlen(s), i;
    for (i = 1; s[i] != '.'; ++i) A = A * 10 + s[i] - '0';
    for (++i; i < len; ++i) B = B * 10 + s[i] - '0';
    int tot = a * 60 + b;
    A *= flag, B = B * 6 * flag;
    int tmptot = A * 60 + B - 480;
    tot = (tot + tmptot + 24 * 60) % (24 * 60);
    printf("%02d:%02d\n", tot / 60, tot % 60);
    return;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d UTC%s", &a, &b, s);
        bool flag = true;
        for (int i = 0, len = strlen(s); i < len; ++i)
            if (s[i] == '.') {
                flag = false;
                break;
            }
        if (flag)
            work1();
        else
            work2();
    }
    return 0;
}