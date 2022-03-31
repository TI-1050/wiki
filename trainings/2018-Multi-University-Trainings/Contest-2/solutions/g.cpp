#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define ll long long

ll arr[N];

struct node {
    int l, r;
    ll Min, lazy, sum, v;
    inline node() {}
    inline node(int _l, int _r) {
        l = _l;
        r = _r;
        Min = 0, lazy = 0, sum = 0, v = 0;
    }
} tree[N << 2];

inline void pushup(int id) {
    tree[id].Min = min(tree[id << 1].Min, tree[id << 1 | 1].Min);
    tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
}

inline void pushdown(int id) {
    if (tree[id].l >= tree[id].r)
        return;
    if (tree[id].lazy) {
        tree[id << 1].lazy += tree[id].lazy;
        tree[id << 1 | 1].lazy += tree[id].lazy;
        tree[id << 1].Min -= tree[id].lazy;
        tree[id << 1 | 1].Min -= tree[id].lazy;
        tree[id].lazy = 0;
    }
}

inline void build(int id, int l, int r) {
    tree[id] = node(l, r);
    if (l == r) {
        tree[id].v = arr[l];
        tree[id].Min = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pushup(id);
}

inline void update(int id, int l, int r) {
    if (tree[id].l == l && tree[id].r == r && tree[id].Min > 1) {
        tree[id].lazy++;
        tree[id].Min--;
        return;
    }
    if (tree[id].l == tree[id].r && tree[id].Min == 1) {
        tree[id].Min = tree[id].v;
        tree[id].sum++;
        return;
    }
    pushdown(id);
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (r <= mid)
        update(id << 1, l, r);
    else if (l > mid)
        update(id << 1 | 1, l, r);
    else {
        update(id << 1, l, mid);
        update(id << 1 | 1, mid + 1, r);
    }
    pushup(id);
}

ll anssum;

inline void query(int id, int l, int r) {
    if (tree[id].l >= l && tree[id].r <= r) {
        anssum += tree[id].sum;
        return;
    }
    pushdown(id);
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (l <= mid)
        query(id << 1, l, r);
    if (r > mid)
        query(id << 1 | 1, l, r);
    pushup(id);
}

int n, m;
char str[100];
int l, r;

int main() {
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 1; i <= n; ++i) scanf("%lld", arr + i);
        build(1, 1, n);
        for (int i = 1; i <= m; ++i) {
            scanf("%s", str);
            if (str[0] == 'a') {
                scanf("%d %d", &l, &r);
                update(1, l, r);
            } else {
                scanf("%d %d", &l, &r);
                anssum = 0;
                query(1, l, r);
                printf("%lld\n", anssum);
            }
        }
    }
    return 0;
}