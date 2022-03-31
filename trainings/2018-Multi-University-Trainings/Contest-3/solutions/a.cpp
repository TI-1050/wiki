#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7 + 10;
typedef long long ll;

int t;
int n, m, k;
ll p, q, r, mod;
ll arr[maxn];
ll brr[maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %lld %lld %lld %lld", &n, &m, &k, &p, &q, &r, &mod);
        for (int i = 1; i <= n; ++i) {
            if (i <= k)
                scanf("%lld", arr + i);
            else
                arr[i] = (p * arr[i - 1] + q * i + r) % mod;
        }
        ll A = 0, B = 0;
        int head = 0, tail = -1;
        for (int i = n; i > (n - m + 1); --i) {
            while (head <= tail && arr[i] >= arr[brr[tail]]) tail--;
            brr[++tail] = i;
        }
        for (int i = n - m + 1; i >= 1; --i) {
            while (head <= tail && arr[i] >= arr[brr[tail]]) tail--;
            brr[++tail] = i;
            while (brr[head] - i >= m) head++;
            A += arr[brr[head]] ^ i;
            B += (tail - head + 1) ^ i;
        }
        printf("%lld %lld\n", A, B);
    }
    return 0;
}