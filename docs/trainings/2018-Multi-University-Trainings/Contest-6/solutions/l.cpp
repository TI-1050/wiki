#include <bits/stdc++.h>

using namespace std;

const double g = 9.8;
double a, b, x, y;

void RUN() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf %lf %lf %lf", &a, &b, &x, &y);
        x = -1.0 * x;
        double Tan = b / a;
        double arc = atan(Tan);
        double vx = g * sin(arc);
        double vy = g * cos(arc);
        double h = (y - b / a * x) * cos(arc);
        double dis = (y - b / a * x) * sin(arc) + x / cos(arc);
        double t = sqrt(2 * dis / vx);
        double per = sqrt(2 * h / vy);
        int ans = 0;
        if (t > per) {
            ans++;
            t -= per;
        }
        ans += t / (per * 2);
        printf("%d\n", ans);
    }
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("Text.txt", "r", stdin);
#endif  // LOCAL_JUDGE

    RUN();

#ifdef LOCAL_JUDGE
    fclose(stdin);
#endif  // LOCAL_JUDGE
    return 0;
}