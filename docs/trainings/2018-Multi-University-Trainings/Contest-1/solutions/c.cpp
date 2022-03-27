#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;

struct node {
    int x, y, id;
    inline node() {}
    inline node(int x, int y, int id) : x(x), y(y), id(id) {}
    inline bool operator<(const node &b) const {
        return x == b.x ? y < b.y : x < b.x;
    }
} P[maxn << 2];

int n;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= 3 * n; ++i) {
            scanf("%d %d", &P[i].x, &P[i].y);
            P[i].id = i;
        }
        sort(P + 1, P + 1 + 3 * n);
        for (int i = 1; i <= 3 * n; i += 3) {
            printf("%d %d %d\n", P[i].id, P[i + 1].id, P[i + 2].id);
        }
    }
    return 0;
}