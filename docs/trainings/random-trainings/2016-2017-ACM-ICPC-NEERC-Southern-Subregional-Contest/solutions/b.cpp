#include <bits/stdc++.h>

using namespace std;

int n;

int ask(int x, int y) {
    if (x == y)
        return 0;
    printf("? %d %d\n", x + 1, y + 1);
    fflush(stdout);
    char op[10];
    scanf("%s", op);
    if (op[0] == '<')
        return -1;
    else if (op[1] == '=')
        return 0;
    else
        return 1;
}

int main() {
    int _T;
    scanf("%d", &_T);
    while (_T--) {
        scanf("%d", &n);
        vector<int> big, small;
        for (int i = 0; i < n / 2; ++i) {
            if (ask(2 * i, 2 * i + 1) < 0) {
                big.push_back(2 * i + 1);
                small.push_back(2 * i);
            } else {
                small.push_back(2 * i + 1);
                big.push_back(2 * i);
            }
        }
        if (n & 1) {
            big.push_back(n - 1);
            small.push_back(n - 1);
        }
        int Min = small[0], Max = big[0];
        for (int i = 1, len = small.size(); i < len; ++i) {
            if (ask(Min, small[i]) > 0) {
                Min = small[i];
            }
        }
        for (int i = 1, len = big.size(); i < len; ++i) {
            if (ask(Max, big[i]) < 0) {
                Max = big[i];
            }
        }
        printf("! %d %d\n", Min + 1, Max + 1);
        fflush(stdout);
    }
    return 0;
}
