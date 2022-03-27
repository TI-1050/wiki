#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;

struct E {
    int id, a, d;

    bool operator<(const E &other) const {
        if (a != other.a) {
            return a > other.a;
        } else {
            return id < other.id;
        }
    }
} a[N];

int n;

int f(int x, int y) {
    E startX = a[x], startY = a[y];
    E endX = a[x], endY = a[y];
    endX.a += endX.d;
    endY.a += endY.d;
    if (startX < startY && endY < endX)
        return 1;
    if (startY < startX && endX < endY)
        return 1;

    if (startX < startY && endY < startX && endX < endY)
        return 2;
    if (startX < startY && startY < endX && endX < endY)
        return 2;

    if (startY < startX && startX < endY && endY < endX)
        return 2;
    if (startY < startX && endX < startY && endY < endX)
        return 2;
    return 0;
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("input", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &a[i].a, &a[i].d);
        a[i].id = i;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            res += f(i, j);
        }
    }
    printf("%d\n", res);
    return 0;
}
