#include <bits/stdc++.h>

using namespace std;

using db = double;

#define dbg(x...)             \
    do {                      \
        cout << #x << " -> "; \
        err(x);               \
    } while (0)

void err() {
    cout << endl;
}

template <class T, class... Ts>
void err(const T &arg, const Ts &...args) {
    cout << arg << ' ';
    err(args...);
}

const db PI = acos(-1.0), eps = 1e-8;
const int N = 2e3 + 10;

int sgn(db x) {
    if (fabs(x) < eps)
        return 0;
    else
        return x > 0 ? 1 : -1;
}

struct Point {
    int x, y;

    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point operator-(const Point &other) const {
        return {x - other.x, y - other.y};
    }
    Point rot() {
        return {-y, x};
    }
} a[N];

struct node {
    Point p;
    int val, id;
    db arc;

    bool operator<(const node &other) const {
        if (sgn(arc - other.arc) == 0)
            return val > other.val;
        else
            return arc < other.arc;
    }
};

int n, tot;
vector<node> vec;
int b[N];
int add[N * N];
int l[N * N], r[N * N];

bool ok() {
    if (vec.empty())
        return true;
    for (auto &it : vec) {
        it.arc = atan2(it.p.y, it.p.x);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0, len = vec.size(); i < len; ++i) {
        if (vec[i].val == 1)
            l[vec[i].id] = i;
        else
            r[vec[i].id] = i;
    }
    for (int i = 0; i < tot; ++i) {
        if (l[i] < r[i]) {
            add[l[i]]++;
            add[r[i] + 1]--;
        } else {
            add[l[i]]++;
            add[0]++;
            add[r[i] + 1]--;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 2 * tot; ++i) {
        cnt += add[i];
        if (cnt == tot)
            return true;
    }
    return false;
}

void push(Point a, Point b) {
    vec.push_back({(a - b).rot(), -1, tot});
    vec.push_back({(b - a).rot(), 1, tot});
    tot++;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &a[i].x, &a[i].y, &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (b[i] == b[j])
                continue;
            if (b[i] > b[j]) {
                push(a[i], a[j]);
            } else {
                push(a[j], a[i]);
            }
        }
    }
    if (ok())
        puts("Y");
    else
        puts("N");
    return 0;
}
