#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;

int sgn(double x) {
    if (fabs(x) < eps)
        return 0;
    else
        return x > 0 ? 1 : -1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }

    double distance(Point p) {
        return hypot(x - p.x, y - p.y);
    }
} P;

int n;
double R, r;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %lf", &n, &R);
        double ans = 2 * R * PI;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf %lf %lf", &P.x, &P.y, &r);
            double dis = P.distance(Point(0.0, 0.0));
            if (sgn(dis - (r + R)) >= 0)
                continue;
            else if (sgn(dis - (R - r)) < 0)
                continue;
            else if (sgn(dis - (R - r)) == 0) {
                ans += 2 * PI * r;
                continue;
            }
            double arc1 = (R * R + dis * dis - r * r) / (2.0 * R * dis);
            arc1 = 2 * acos(arc1);
            double arc2 = (r * r + dis * dis - R * R) / (2.0 * r * dis);
            arc2 = 2 * acos(arc2);
            ans -= R * arc1;
            ans += r * arc2;
        }
        printf("%.10f\n", ans);
    }
    return 0;
}