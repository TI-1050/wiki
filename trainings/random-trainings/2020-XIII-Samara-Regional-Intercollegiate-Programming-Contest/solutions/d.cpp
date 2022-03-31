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
void err(const T& arg, const Ts&... args) {
    cout << arg << ' ';
    err(args...);
}

using pIC = pair<int, char>;

const int N = 2e5 + 10;

int n, m;
vector<vector<pIC>> G;
vector<int> vec[2];
int pre[N];
int d[N];
char s[N];
int pos[N];

int main() {
    memset(d, -1, sizeof d);
    scanf("%d %d", &n, &m);
    G.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        char c;
        scanf("%d %d %c", &u, &v, &c);
        G[u].push_back(pIC(v, c));
        G[v].push_back(pIC(u, c));
    }
    queue<int> q;
    d[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto it : G[u]) {
            int v = it.first;
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    vec[0].push_back(1);
    for (int cas = 1; cas <= d[1]; ++cas) {
        char Max = 'z' + 1;
        for (auto u : vec[0]) {
            for (auto it : G[u]) {
                if (d[u] == d[it.first] + 1 && it.second < Max) {
                    Max = it.second;
                }
            }
        }
        vec[1].clear();
        for (auto u : vec[0]) {
            for (auto it : G[u]) {
                if (d[u] == d[it.first] + 1 && it.second == Max) {
                    pre[it.first] = u;
                    vec[1].push_back(it.first);
                }
            }
        }

        sort(vec[1].begin(), vec[1].end());
        vec[1].resize(unique(vec[1].begin(), vec[1].end()) - vec[1].begin());

        swap(vec[0], vec[1]);
        s[cas] = Max;
    }
    s[d[1] + 1] = 0;
    int u = n, cnt = 0;
    while (true) {
        pos[++cnt] = u;
        if (u == 1)
            break;
        u = pre[u];
    }
    reverse(pos + 1, pos + 1 + cnt);
    printf("%d\n", d[1]);
    for (int i = 1; i <= cnt; ++i) {
        printf("%d%c", pos[i], " \n"[i == cnt]);
    }
    puts(s + 1);
    return 0;
}
