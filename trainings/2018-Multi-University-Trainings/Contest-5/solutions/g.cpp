#include <bits/stdc++.h>
using namespace std;

#define N 5000010
#define M 100010
#define ui unsigned int
#define ll long long
int t, n, m;
ui x, y, z, w;
ui f[N << 2];
ui MOD = (ui)1 << 30;

ui rng61() {
    x = x ^ (x << 11);
    x = x ^ (x >> 4);
    x = x ^ (x << 5);
    x = x ^ (x >> 14);
    w = x ^ y ^ z;
    x = y;
    y = z;
    z = w;
    return z;
}

struct SEG {
    ui lazy[M << 2], Max[M << 2], Min[M << 2];
    void Init() {
        memset(lazy, 0, sizeof lazy);
        memset(Max, 0, sizeof Max);
        memset(Min, 0, sizeof Min);
    }
    void pushup(int id) {
        Max[id] = max(Max[id << 1], Max[id << 1 | 1]);
        Min[id] = min(Min[id << 1], Min[id << 1 | 1]);
    }
    void pushdown(int id) {
        if (!lazy[id])
            return;
        lazy[id << 1] = lazy[id];
        Max[id << 1] = lazy[id];
        Min[id << 1] = lazy[id];
        lazy[id << 1 | 1] = lazy[id];
        Max[id << 1 | 1] = lazy[id];
        Min[id << 1 | 1] = lazy[id];
        lazy[id] = 0;
    }
    void update(int id, int l, int r, int ql, int qr, ui val) {
        if (Min[id] >= val)
            return;
        if (l >= ql && r <= qr && Max[id] < val) {
            lazy[id] = Max[id] = val;
            return;
        }
        pushdown(id);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            update(id << 1, l, mid, ql, qr, val);
        if (qr > mid)
            update(id << 1 | 1, mid + 1, r, ql, qr, val);
        pushup(id);
    }
    int query(int id, int l, int r, int pos) {
        if (l == r)
            return Max[id];
        pushdown(id);
        int mid = (l + r) >> 1;
        if (pos <= mid)
            return query(id << 1, l, mid, pos);
        else
            return query(id << 1 | 1, mid + 1, r, pos);
    }
} seg;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%u%u%u", &n, &m, &x, &y, &z);
        for (int i = 1; i <= 3 * m; ++i) f[i] = rng61();
        seg.Init();
        for (int i = 1, l, r, v; i <= m; ++i) {
            l = f[3 * i - 2] % n + 1;
            r = f[3 * i - 1] % n + 1;
            v = f[3 * i] % MOD;
            if (l > r)
                swap(l, r);
            seg.update(1, 1, n, l, r, v);
        }
        ll res = 0;
        for (int i = 1; i <= n; ++i) res ^= (ll)seg.query(1, 1, n, i) * (ll)i;
        printf("%lld\n", res);
    }
    return 0;
}