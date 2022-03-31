#include <bits/stdc++.h>

using namespace std;

#define dbg(x...)             \
    do {                      \
        cout << #x << " -> "; \
        err(x);               \
    } while (0)

void err() {
    cout << endl;
}

template <class T, class... Ts>
void err(const T &arg, const Ts &...args) {
    cout << arg << ' ';
    err(args...);
}

#define endl "\n"
#define all(A) A.begin(), A.end()
using ll = long long;
using db = double;
using pII = pair<int, int>;

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int N = 70;

ll s, x;
int b[N];
int high;

// n:limit of high, m limit of low
bool ok(ll n, ll m) {
    ll remind = 0;
    for (int i = 59; i >= 0; --i) {
        remind <<= 1;
        remind += b[i];
        if (i > high)
            continue;
        ll dec = (i == high ? n : m);
        remind = max(0ll, remind - dec);
        if (remind & 1) {
            if (!dec)
                return false;
            remind++;
        }
    }
    return remind == 0;
}

bool check(ll n) {
    for (int i = 0; i <= 5; ++i) {
        if (n - i >= 0 && ok(n - i, i)) {
            return true;
        }
    }
    return false;
}

void RUN() {
    cin >> s >> x;
    if (s < x || (s - x) % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    if (s == x && s == 0) {
        cout << 0 << endl;
        return;
    }
    memset(b, 0, sizeof b);
    high = 0;
    for (int i = 0; i < 60; ++i) {
        b[i] = (x >> i & 1) + ((s - x) >> i & 2);
        if ((x >> i) & 1) {
            high = max(high, i);
        }
    }
    ll l = 1, r = s, res = -1;
    while (r - l >= 0) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(20);

    int _T;
    cin >> _T;
    while (_T--) {
        RUN();
    }

    return 0;
}