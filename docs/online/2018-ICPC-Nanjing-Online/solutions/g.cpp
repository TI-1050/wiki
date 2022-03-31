#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define INF 0x3f3f3f3f
#define ll long long

typedef pair<int, int> pii;

int n, m, q, sum;
int arr[N];
pii ans[N];

struct node {
    int l, r, cnt;
    int Min, sum;
    inline node() {}
    inline node(int _l, int _r) {
        l = _l, r = _r;
        Min = sum = 0;
    }
} tree[N << 2];

inline void pushup(int id) {
    tree[id].Min = min(tree[id << 1].Min, tree[id << 1 | 1].Min);
    tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
    tree[id].cnt = tree[id << 1].cnt + tree[id << 1 | 1].cnt;
}

inline void build(int id, int l, int r) {
    tree[id] = node(l, r);
    if (l == r) {
        tree[id].Min = tree[id].sum = arr[l];
        tree[id].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pushup(id);
}

int anssum, remind;

inline void query(int id) {
    if (tree[id].Min <= remind && tree[id].sum <= remind) {
        anssum += tree[id].cnt;
        sum -= tree[id].sum;
        remind -= tree[id].sum;
        tree[id].Min = INF;
        tree[id].sum = 0;
        tree[id].cnt = 0;
        return;
    }
    if (tree[id << 1].Min <= remind)
        query(id << 1);
    if (tree[id << 1 | 1].Min <= remind)
        query(id << 1 | 1);
    pushup(id);
}

inline void out(int x) {
    if (x / 10)
        out(x / 10);
    putchar(x % 10 + '0');
}

inline void Run() {
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(ans, 0, sizeof ans);
        sum = 0;
        for (int i = 1; i <= n; ++i) scanf("%d", arr + i), sum += arr[i];
        build(1, 1, n);
        remind = m;
        for (int i = 1; i <= 100000; ++i, remind += m) {
            if (sum == 0) {
                ans[i] = ans[i - 1];
                continue;
            }
            anssum = 0;
            query(1);
            ans[i].first = ans[i - 1].first + anssum;
            ans[i].second = remind;
        }
        scanf("%d", &q);
        for (int i = 1, x; i <= q; ++i) {
            scanf("%d", &x);
            out(ans[x].first);
            putchar(' ');
            out(ans[x].second);
            putchar('\n');
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