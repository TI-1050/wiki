#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxn = 1e2;

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

    void input() {
        scanf("%lf %lf", &x, &y);
    }

    Point operator-(const Point &b) const {
        return Point(x - b.x, y - b.y);
    }

    double operator^(const Point &b) const {
        return x * b.y - y * b.x;
    }

    double distance(Point p) {
        return hypot(x - p.x, y - p.y);
    }

    double len() {
        return hypot(x, y);
    }

    double operator*(const Point &b) const {
        return x * b.x + y * b.y;
    }
} P[maxn];

int w;
double ans;
double area;

void calc(Point a, Point b)  // low high
{
    if (sgn(a * b) < 0)
        return;
    if (sgn(a * a - w * w) <= 0) {
        if (sgn(a ^ b) < 0)
            return;
        if (sgn((a * b) * (a * b) - w * w * (a * a)) > 0)
            return;
        ans = min(ans, (a ^ b) / sqrt(a * a));
    } else {
        double h = sqrt(a * a - w * w);
        double src1 = atan(h / w);
        if (sgn(a ^ b) >= 0) {
            double src2 = acos((a * b) / (sqrt(a * a) * sqrt(b * b)));
            if (sgn(src1 + src2 - PI / 2) > 0)
                return;
            double len1 = sqrt(b * b) * cos(src1 + src2);
            if (sgn(len1 - w) > 0)
                return;
            ans = min(ans, max(h, sqrt(b * b) * sin(src1 + src2)));
        } else {
            double src2 = acos((a * b) / (sqrt(a * a) * sqrt(b * b)));
            if (sgn(src1 - src2) < 0)
                return;
            double len1 = sqrt(b * b) * cos(src1 - src2);
            if (sgn(len1 - w) > 0)
                return;
            ans = min(ans, h);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 1; i <= 3; ++i) P[i].input();
        //    double a = p[1].distance(p[2]);
        //    double b = p[2].distance(p[3]);
        //    double c = p[3].distance(p[1]);
        //    double p = (a + b + c) / 2.0;
        //    area = sqrt(p * (p - a) * (p - b) * (p - c));
        ans = INF * 1.0;
        scanf("%d", &w);
        calc(P[2] - P[1], P[3] - P[1]);
        calc(P[3] - P[1], P[2] - P[1]);
        calc(P[1] - P[2], P[3] - P[2]);
        calc(P[3] - P[2], P[1] - P[2]);
        calc(P[1] - P[3], P[2] - P[3]);
        calc(P[2] - P[3], P[1] - P[3]);
        for (int i = 1; i <= 3; ++i) P[i].y *= -1.0;
        calc(P[2] - P[1], P[3] - P[1]);
        calc(P[3] - P[1], P[2] - P[1]);
        calc(P[1] - P[2], P[3] - P[2]);
        calc(P[3] - P[2], P[1] - P[2]);
        calc(P[1] - P[3], P[2] - P[3]);
        calc(P[2] - P[3], P[1] - P[3]);
        if (ans >= INF * 1.0)
            puts("impossible");
        else
            printf("%.10f\n", ans);
    }
    return 0;
}