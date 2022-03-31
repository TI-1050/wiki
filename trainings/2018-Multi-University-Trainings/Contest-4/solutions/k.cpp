#include <bits/stdc++.h>
using namespace std;

#define N 100010

int t;
char s[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        bool flag = true;
        int len = strlen(s);
        for (int i = 0; i < len; ++i) {
            if (s[i] == '*' || s[i] == '+') {
                if (i == 0 || i == len - 1) {
                    flag = false;
                    break;
                } else if (s[i + 1] == '*' || s[i + 1] == '+') {
                    flag = false;
                    break;
                }
            } else if (s[i] == '0') {
                if (i == 0 || s[i - 1] == '*' || s[i - 1] == '+') {
                    if (i + 1 < len && s[i + 1] >= '0' && s[i + 1] <= '9') {
                        flag = false;
                        break;
                    } else if (s[i + 1] == '?')
                        s[i + 1] = '+';
                }
            } else if (s[i] == '?') {
                s[i] = '1';
            }
        }
        if (flag) {
            printf("%s\n", s);
        } else {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}