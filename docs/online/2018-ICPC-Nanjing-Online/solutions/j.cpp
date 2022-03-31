#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e7 + 5;

int n;
int tot;
int isprime[maxn];
int prime[maxn];
int a[maxn];
int ans[maxn];

inline void Init_prime() {
    tot = 1;
    prime[1] = 1;
    a[1] = 1;
    ans[1] = 1;
    for (register int i = 2; i < maxn; ++i) {
        a[i] = 1;
        if (!isprime[i]) {
            prime[tot++] = i;
        }
        for (register int j = 1; j < tot && i * prime[j] < maxn; ++j) {
            isprime[i * prime[j]] = 1;
            if (!(i % prime[j])) {
                break;
            }
        }
    }
    for (register int i = 1; i < tot; ++i) {
        for (register int j = 1; j * prime[i] < maxn; ++j) {
            a[j * prime[i]] <<= 1;
        }
        if (prime[i] > maxn / prime[i])
            continue;
        for (register int j = 1; j * prime[i] * prime[i] < maxn; ++j) {
            if (j % prime[i] == 0) {
                a[j * prime[i] * prime[i]] = 0;
            }
            a[j * prime[i] * prime[i]] >>= 1;
        }
    }
    for (register int i = 1; i < maxn; ++i) {
        ans[i] = ans[i - 1] + a[i];
    }
}

int main() {
    Init_prime();
    int t;
    // cout << tot << endl;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}