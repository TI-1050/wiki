#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

struct node {
    int x, y, r;

    void input() {
        scanf("%d %d %d", &x, &y, &r);
    }
} a[N];

int n, m, k;
int fa[N], sze[N];

int find(int x) {
    return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        if (sze[x] > sze[y])
            swap(x, y);
        fa[x] = y;
        sze[y] += sze[x];
    }
}

int sqr(int x) {
    return x * x;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; ++i) {
        a[i].input();
    }
    for (int i = 1; i <= k + 2; ++i) {
        fa[i] = i, sze[i] = 1;
    }
    for (int i = 1; i <= k; ++i) {
        if (a[i].x + a[i].r >= n || a[i].y <= a[i].r)
            merge(i, k + 1);
        if (a[i].x <= a[i].r || a[i].y + a[i].r >= m)
            merge(i, k + 2);
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j < i; ++j) {
            if (sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y) <= sqr(a[i].r + a[j].r)) {
                merge(i, j);
            }
        }
    }
    puts(find(k + 1) == find(k + 2) ? "N" : "S");
    return 0;
}
