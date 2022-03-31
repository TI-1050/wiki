#include <bits/stdc++.h>

using namespace std;

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

#define endl "\n"
#define all(A) A.begin(), A.end()
using ll = long long;
using db = double;
using pII = pair<int, int>;

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const db eps = 1e-8;

int sgn(db x) {
    if (fabs(x) < eps)
        return 0;
    else
        return x > 0 ? 1 : -1;
}

struct Point {
    db x, y;

    Point() {}

    Point(db _x, db _y) {
        x = _x, y = _y;
    }

    void input() {
        cin >> x >> y;
    }

    Point operator+(const Point &b) const {
        return Point(x + b.x, y + b.y);
    }

    Point operator-(const Point &b) const {
        return Point(x - b.x, y - b.y);
    }

    double operator^(const Point &b) const {
        return x * b.y - y * b.x;
    }

    double operator*(const Point &b) const {
        return x * b.x + y * b.y;
    }

    double distance(Point p) {
        return hypot(x - p.x, y - p.y);
    }
} dir;

struct Line {
    Point s, e;

    Line() {}

    Line(Point _s, Point _e) {
        s = _s;
        e = _e;
    }

    void input() {
        s.input();
        e.input();
    }

    bool parallel(Line v) {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }

    int relation(Point p) {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0)
            return 1;
        else if (c > 0)
            return 2;
        else
            return 3;
    }

    int linecrossline(Line v) {
        if ((*this).parallel(v))
            return v.relation(s) == 3;
        return 2;
    }

} l1, l2;

db gao(Point a, Point b) {
    Point d = b - a;
    return sgn(dir * d) * a.distance(b);
}

void RUN() {
    l1.input();
    l2.input();
    if (l1.linecrossline(l2) != 1) {
        cout << 0 << endl;
        return;
    }
    dir = l1.e - l1.s;
    db a = 0, b = gao(l1.s, l1.e), c = gao(l1.s, l2.s), d = gao(l1.s, l2.e);
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    db res = 0;
    if (sgn(b - c) <= 0) {
        res = 0;
    } else if (sgn(b - c) >= 0 && sgn(b - d) <= 0) {
        res = min(b - c, b - a);
    } else {
        if (sgn(a - c) <= 0) {
            res = d - c;
        } else if (sgn(a - c) >= 0 && sgn(a - d) <= 0) {
            res = d - a;
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(20);

    int _T;
    cin >> _T;
    while (_T--) {
        RUN();
    }

    return 0;
}