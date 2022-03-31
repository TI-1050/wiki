#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 20000000;
bool check[MAXN + 10];

ll ans[MAXN + 10];
int phi[MAXN + 10];
int prime[MAXN + 10];
int tot;

void phi_ans_prime_table() {
    memset(check, false, sizeof check);
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i <= MAXN; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > MAXN)
                break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
        if (i & 1)
            ans[i] = ans[i - 1] + phi[i] / 2;
        else
            ans[i] = ans[i - 1] + phi[i];
    }
}

int main() {
    phi_ans_prime_table();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
    return 0;
}