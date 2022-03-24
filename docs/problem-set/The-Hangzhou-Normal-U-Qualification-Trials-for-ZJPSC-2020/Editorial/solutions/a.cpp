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
const int N = 16, M = 100;

int n, m;
ll f[1 << N][M];

void RUN() {
    cin >> n >> m;
    ++n;
    f[0][0] = 1;
    int limit = 1 << n;
    for (int S = 0; S < limit; ++S) {
        for (int i = 0; i < n; ++i) {
            if (S & (1 << i))
                continue;
            if (S == 0 && i == 0)
                continue;
            int nxt = S | (1 << i);
            for (int j = 0; j < m; ++j) {
                if (i >= 10) {
                    f[nxt][(j * 100 + i) % m] += f[S][j];
                } else {
                    f[nxt][(j * 10 + i) % m] += f[S][j];
                }
            }
        }
    }
    cout << f[limit - 1][0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(20);

    RUN();

    return 0;
}