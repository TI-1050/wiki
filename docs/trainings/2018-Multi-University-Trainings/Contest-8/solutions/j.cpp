#include <bits/stdc++.h>
using namespace std;

#define N 100010
int t;
int n, m;
int arr[N];

struct SEG {
    int cnt[N << 2], Max[N << 2];
    void build(int id, int l, int r) {
        cnt[id] = Max[id] = 0;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
    int query(int id, int l, int r, int val) {
        if (l == r)
            return Max[id] > val;
        int mid = (l + r) >> 1;
        if (Max[id] <= val)
            return 0;
        if (Max[id << 1] <= val)
            return query(id << 1 | 1, mid + 1, r, val);
        else
            return cnt[id] - cnt[id << 1] + query(id << 1, l, mid, val);
    }
    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            cnt[id] = 1;
            Max[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(id << 1, l, mid, pos, val);
        else
            update(id << 1 | 1, mid + 1, r, pos, val);
        cnt[id] = cnt[id << 1] + query(id << 1 | 1, mid + 1, r, Max[id << 1]);
        Max[id] = max(Max[id << 1], Max[id << 1 | 1]);
    }
} seg;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
        seg.build(1, 1, n);
        for (int i = 1; i <= n; ++i) seg.update(1, 1, n, i, arr[i]);
        for (int i = 1, x, v; i <= m; ++i) {
            scanf("%d%d", &x, &v);
            seg.update(1, 1, n, x, v);
            printf("%d\n", seg.cnt[1]);
            seg.update(1, 1, n, x, arr[x]);
        }
    }
    return 0;
}