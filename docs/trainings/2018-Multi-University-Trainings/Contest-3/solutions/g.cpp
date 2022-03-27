#include <bits/stdc++.h>
using namespace std;

#define N 200010

const double eps = 1e-8;

inline int sgn(double x) {
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

struct Point {
    double x, y;
    int id;
    inline Point() {}
    inline Point(double x, double y) : x(x), y(y) {}
    inline void scan(int _id) {
        id = _id;
        scanf("%lf%lf", &x, &y);
    }
    inline bool operator==(const Point &r) const {
        return sgn(x - r.x) == 0 && sgn(y - r.y) == 0;
    }
    inline bool operator<(const Point &r) const {
        return x < r.x || x == r.x && y < r.y || x == r.x && y == r.y && id < r.id;
    }
    inline Point operator+(const Point &r) const {
        return Point(x + r.x, y + r.y);
    }
    inline Point operator-(const Point &r) const {
        return Point(x - r.x, y - r.y);
    }
    inline double operator^(const Point &r) const {
        return x * r.y - y * r.x;
    }
    inline double distance(const Point &r) const {
        return hypot(x - r.x, y - r.y);
    }
};

struct Polygon {
    int n;
    Point p[N];
    struct cmp {
        Point p;
        inline cmp(const Point &p0) {
            p = p0;
        }
        inline bool operator()(const Point &aa, const Point &bb) {
            Point a = aa, b = bb;
            int d = sgn((a - p) ^ (b - p));
            if (d == 0) {
                return sgn(a.distance(p) - b.distance(p)) < 0;
            }
            return d < 0;
        }
    };
    inline void norm() {
        Point mi = p[0];
        for (int i = 1; i < n; ++i) mi = min(mi, p[i]);
        sort(p, p + n, cmp(mi));
    }
    inline void Graham(Polygon &convex) {
        sort(p + 1, p + n - 1);
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (!(p[i] == p[i - 1]))
                p[cnt++] = p[i];
        }
        n = cnt;
        norm();
        int &top = convex.n;
        top = 0;
        if (n == 2) {
            top = 2;
            convex.p[0] = p[0];
            convex.p[1] = p[1];
            return;
        }
        if (n == 3) {
            top = 3;
            convex.p[0] = p[0];
            convex.p[1] = p[1];
            convex.p[2] = p[2];
            return;
        }
        convex.p[0] = p[0];
        convex.p[1] = p[1];
        top = 2;
        for (int i = 2; i < n; ++i) {
            while (top > 1 && sgn((convex.p[top - 1] - convex.p[top - 2]) ^ (p[i] - convex.p[top - 2])) >= 0) {
                if (sgn((convex.p[top - 1] - convex.p[top - 2]) ^ (p[i] - convex.p[top - 2])) == 0) {
                    if (p[i].id < convex.p[top - 1].id)
                        --top;
                    else
                        break;
                } else {
                    --top;
                }
            }
            convex.p[top++] = p[i];
        }
        if (convex.n == 2 && (convex.p[0] == convex.p[1]))
            --convex.n;
    }
} arr, ans;

int t, n;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        arr.n = n;
        //    cout << n << endl;
        for (int i = 0; i < n; ++i) arr.p[i].scan(i + 1);
        arr.Graham(ans);
        for (int i = 0; i < ans.n; ++i) printf("%d%c", ans.p[i].id, " \n"[i == ans.n - 1]);
    }
    return 0;
}