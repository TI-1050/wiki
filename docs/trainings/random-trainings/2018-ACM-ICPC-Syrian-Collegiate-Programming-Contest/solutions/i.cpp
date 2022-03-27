#include <bits/stdc++.h>

using namespace std;

using db = double;

const int N = 1e5 + 10;
const db eps = 1e-10;

mt19937 rnd(time(0));

int sgn(db x) {
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}

struct Point {
    db x, y;
    Point(db x = 0, db y = 0) : x(x), y(y) {}
    Point operator+(const Point& b) const {
        return Point(x + b.x, y + b.y);
    }
    Point operator-(const Point& b) const {
        return Point(x - b.x, y - b.y);
    }
    Point operator*(const db& b) const {
        return Point(x * b, y * b);
    }
    Point operator/(const db& b) const {
        return Point(x / b, y / b);
    }
    db operator^(const Point& b) const {
        return x * b.y - y * b.x;
    }
    db operator*(const Point& b) const {
        return x * b.x + y * b.y;
    }
    db len() {
        return hypot(x, y);
    }
    db len2() {
        return x * x + y * y;
    }
    db dis(Point b) {
        return hypot(x - b.x, y - b.y);
    }
    Point rotright() {
        return Point(y, -x);
    }
} p[N];

struct Circle {
    Point p;
    db r;
    Circle() {}
    Circle(Point p, db r) : p(p), r(r) {}
    Circle(db x, db y, db r) : p(Point(x, y)), r(r) {}
    Circle(Point a, Point b, Point c, int opt = 0) {
        if (opt == 0) {
            Point p0 = (a + b) / 2;
            Point v0 = (b - a).rotright();
            Point p1 = (a + c) / 2;
            Point v1 = (c - a).rotright();
            db t = ((p1 - p0) ^ v1) / (v0 ^ v1);
            p = p0 + v0 * t;
            r = p.dis(a);
        }
    }
};

int n, R, r;

Point solve() {
    shuffle(p + 1, p + 1 + n, rnd);
    Circle cir(0, 0, 0);
    for (int i = 1; i <= n; ++i) {
        if (sgn((cir.p - p[i]).len2() - cir.r) > 0) {
            cir.p = p[i];
            cir.r = 0;
            for (int j = 1; j < i; ++j) {
                if (sgn((cir.p - p[j]).len2() - cir.r) > 0) {
                    cir.p = (p[i] + p[j]) / 2;
                    cir.r = (p[j] - cir.p).len2();
                    for (int k = 1; k < j; ++k) {
                        if (sgn((cir.p - p[k]).len2() - cir.r) > 0) {
                            cir = Circle(p[i], p[j], p[k]);
                            cir.r = (p[k] - cir.p).len2();
                        }
                    }
                }
            }
        }
    }
    cir.p.x *= -1;
    cir.p.y *= -1;
    if (sgn(cir.p.x) == 0)
        cir.p.x = 0;
    if (sgn(cir.p.y) == 0)
        cir.p.y = 0;
    return cir.p;
}

int main() {
    freopen("robots.in", "r", stdin);

    int _T;
    scanf("%d", &_T);
    while (_T--) {
        scanf("%d %d %d", &n, &R, &r);
        db x = 0, y = 0;
        for (int i = 1, dx, dy; i <= n; ++i) {
            scanf("%d %d", &dx, &dy);
            x += dx, y += dy;
            p[i] = Point(x, y);
        }
        ++n;
        p[n] = Point(0, 0);
        Point res = solve();
        printf("%.9f %.9f\n", res.x, res.y);
    }
    return 0;
}
