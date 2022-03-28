#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

double a, b;

void RUN() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf %lf", &a, &b);
        double ans = 2 * b + a * PI;
        printf("%.6f\n", ans - 5e-7);
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