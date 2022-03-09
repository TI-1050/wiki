#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 10;
const ll p = 11092019;

char s[N];
ll cnt[N];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        cnt[s[i]]++;
    }
    ll res = 1;
    for (int i = 'a'; i <= 'z'; ++i) {
        res = res * (cnt[i] + 1) % p;
    }
    printf("%lld\n", res);
    return 0;
}
