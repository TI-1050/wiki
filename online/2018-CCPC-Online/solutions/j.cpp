#include <bits/stdc++.h>
using namespace std;

#define N 100010

int t, n, m;
int tmp[N];

struct Data {
    int x, y, v;
    inline void scan() {
        scanf("%d%d%d", &x, &y, &v);
    }
    inline bool operator<(const Data &r) const {
        return x < r.x || x == r.x && y < r.y;
    }
} arr[N];

inline void Init() {
    for (int i = 1; i <= n; ++i) tmp[i] = arr[i].y;
    sort(tmp + 1, tmp + 1 + n);
    m = unique(tmp + 1, tmp + 1 + n) - tmp - 1;
}

inline int Get(int x) {
    return lower_bound(tmp + 1, tmp + 1 + m, x) - tmp;
}

struct node {
    int l, r;
    int Max;
    inline node() {}
    inline node(int l, int r, int Max) : l(l), r(r), Max(Max) {}
} tree[N << 2];

inline void pushup(int id) {
    tree[id].Max = max(tree[id << 1].Max, tree[id << 1 | 1].Max);
}

inline void build(int id, int l, int r) {
    tree[id] = node(l, r, 0);
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
}

inline void update(int id, int pos, int val) {
    if (tree[id].l == tree[id].r) {
        tree[id].Max = max(tree[id].Max, val);
        return;
    }
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (pos <= mid)
        update(id << 1, pos, val);
    else
        update(id << 1 | 1, pos, val);
    pushup(id);
}

int ansMax;

inline void query(int id, int l, int r) {
    if (l > r)
        return;
    if (tree[id].l >= l && tree[id].r <= r) {
        ansMax = max(ansMax, tree[id].Max);
        return;
    }
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (l <= mid)
        query(id << 1, l, r);
    if (r > mid)
        query(id << 1 | 1, l, r);
}

inline void Run() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) arr[i].scan();
        sort(arr + 1, arr + 1 + n);
        Init();
        build(1, 1, n);
        for (int i = 1; i <= n; ++i) arr[i].y = Get(arr[i].y);
        vector<int> v;
        int ans = arr[1].v;
        v.push_back(1);
        for (int i = 2; i <= n; ++i) {
            if (arr[i].x != arr[i - 1].x) {
                for (auto it : v) {
                    update(1, arr[it].y, arr[it].v);
                }
                v.clear();
            }
            ansMax = 0;
            query(1, 1, arr[i].y - 1);
            ans = max(ans, ansMax + arr[i].v);
            // printf("%d %d %d\n", i, ansMax, arr[i].v);
            arr[i].v += ansMax;
            v.push_back(i);
        }
        printf("%d\n", ans);
    }
}

int main() {
#ifdef LOCAL
    freopen("Test.in", "r", stdin);
#endif

    Run();

    return 0;
}