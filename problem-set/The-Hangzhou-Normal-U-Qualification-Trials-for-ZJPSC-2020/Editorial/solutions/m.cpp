#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define mkp make_pair
#define all(x) (x).begin(), (x).end()
using db = double;
using ll = long long;
using ull = unsigned long long;
using pII = pair<int, int>;
using pLL = pair<ll, ll>;
constexpr int mod = 1e9 + 7;
template <class T1, class T2>
inline void chadd(T1 &x, T2 y, int Mod = mod) {
    x += y;
    while (x >= Mod) x -= Mod;
    while (x < 0) x += Mod;
}
template <class T1, class T2>
inline void chmax(T1 &x, T2 y) {
    if (x < y)
        x = y;
}
template <class T1, class T2>
inline void chmin(T1 &x, T2 y) {
    if (x > y)
        x = y;
}
inline int nextInt() {
    int x;
    cin >> x;
    return x;
}
void rd() {}
template <class T, class... Ts>
void rd(T &arg, Ts &...args) {
    cin >> arg;
    rd(args...);
}
#define dbg(x...)                             \
    do {                                      \
        cout << "\033[32;1m" << #x << " -> "; \
        err(x);                               \
    } while (0)
void err() {
    cout << "\033[39;0m" << endl;
}
template <class T, class... Ts>
void err(const T &arg, const Ts &...args) {
    cout << arg << ' ';
    err(args...);
}
template <template <typename...> class T, typename t, typename... A>
void err(const T<t> &arg, const A &...args) {
    for (auto &v : arg) cout << v << ' ';
    err(args...);
}
void ptt() {
    cout << endl;
}
template <class T, class... Ts>
void ptt(const T &arg, const Ts &...args) {
    cout << ' ' << arg;
    ptt(args...);
}
template <class T, class... Ts>
void pt(const T &arg, const Ts &...args) {
    cout << arg;
    ptt(args...);
}
void pt() {}
template <template <typename...> class T, typename t, typename... A>
void pt(const T<t> &arg, const A &...args) {
    for (int i = 0, sze = arg.size(); i < sze; ++i) cout << arg[i] << " \n"[i == sze - 1];
    pt(args...);
}
inline ll qpow(ll base, ll n) {
    assert(n >= 0);
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return res;
}
// head

unsigned long long k1, k2;
int n, m, q, _u[100001], _v[100001];
unsigned long long xorShift128Plus() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

int wnext(int l, int r, int t) {
    int res = xorShift128Plus() % (r - l + 1) + l;
    for (int i = 1; i < t; ++i) {
        res = max(res, int(xorShift128Plus() % (r - l + 1) + l));
    }
    return res;
}

void gen() {
    int S = min(1000, n);
    for (int i = 1; i <= m; ++i) {
        _u[i] = wnext(1, min(n, ((i % S) + 1) * S), 50);
        _v[i] = wnext(1, min(n, ((i % S) + 1) * S), 50);
        // dbg(_u[i], _v[i]);
    }
}

const int N = 1e5 + 10;
pII pid[N];

struct UFS {
    int fa[N], sze[N];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            fa[i] = 0;
            sze[i] = 1;
        }
    }
    int find(int x) {
        return fa[x] == 0 ? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            if (sze[fx] > sze[fy])
                swap(fx, fy);
            fa[fx] = fy;
            sze[fy] += sze[fx];
            return true;
        }
        return false;
    }
} ufs;

struct Bitset {
    using ull = unsigned long long;
    static constexpr int W = 64;
    int n;
    vector<ull> bits;
    void init(int _n) {
        n = _n + 1;
        bits = vector<ull>(n / W + 10, 0);
    }
    void Or(const Bitset &t) {
        for (int i = 0; i <= n / W; ++i) bits[i] |= t.bits[i];
    }
    void set(int x) {
        bits[x / W] |= 1llu << (x % W);
    }
    int ask(int x) {
        return (bits[x / W] >> (x % W)) & 1;
    }
};

struct Sol {
    vector<vector<int>> G;
    vector<Bitset> b;
    int n;
    vector<int> Low, DFN, sta, Belong;
    int cntSCC, cntSta, cntLow;
    vector<bool> Insta;
    Sol(int _n) {
        n = _n;
        G.clear();
        G.resize(n + 5);
        Low = vector<int>(n + 5, 0);
        DFN = vector<int>(n + 5, 0);
        sta = vector<int>(n + 5, 0);
        Belong = vector<int>(n + 5, 0);
        Insta = vector<bool>(n + 5, false);
        cntSCC = cntSta = cntLow = 0;
    }
    void dfs(int u) {
        Low[u] = DFN[u] = ++cntLow;
        sta[++cntSta] = u;
        Insta[u] = 1;
        for (auto &v : G[u]) {
            if (!DFN[v]) {
                dfs(v);
                Low[u] = min(Low[u], Low[v]);
            } else if (Insta[v])
                Low[u] = min(Low[u], DFN[v]);
        }
        if (Low[u] == DFN[u]) {
            ++cntSCC;
            int v;
            do {
                v = sta[cntSta--];
                Insta[v] = 0;
                Belong[v] = cntSCC;
            } while (v != u);
        }
    }
    void gao() {
        for (int i = 1; i <= n; ++i)
            if (!DFN[i])
                dfs(i);
        b.resize(cntSCC + 5);
        for (int i = 1; i <= cntSCC; ++i) b[i].init(cntSCC + 5), b[i].set(i);
        vector<vector<int>> T;
        T.clear();
        T.resize(cntSCC + 5);
        for (int u = 1; u <= n; ++u) {
            for (auto &v : G[u]) {
                if (Belong[u] == Belong[v])
                    continue;
                T[Belong[v]].push_back(Belong[u]);
            }
        }
        for (int u = 1; u <= cntSCC; ++u) {
            for (auto &v : T[u]) {
                b[v].Or(b[u]);
            }
        }
    }
    int query(int u, int v) {
        if (Belong[u] == Belong[v])
            return 1;
        // dbg(u, v);
        return b[Belong[u]].ask(Belong[v]);
    }
};

vector<Sol> sol;

void numerAS() {
    sol.clear();
    vector<vector<int>> G, vec;
    vec.clear();
    G.clear();
    vec.resize(n + 1);
    G.resize(n + 1);
    ufs.init(n);
    for (int i = 1; i <= m; ++i) {
        int u = _u[i], v = _v[i];
        if (u != v) {
            G[u].push_back(v);
            ufs.merge(u, v);
            // dbg(u, v);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (!G[i].empty()) {
            sort(all(G[i]));
            G[i].erase(unique(all(G[i])), G[i].end());
        }
    for (int i = 1; i <= n; ++i) {
        vec[ufs.find(i)].push_back(i);
    }
    int _pid = -1;
    for (auto &ve : vec)
        if (!ve.empty()) {
            sol.push_back(Sol(SZ(ve)));
            ++_pid;
            int nid = 0;
            for (auto &it : ve) {
                ++nid;
                pid[it] = pII(_pid, nid);
            }
            for (auto &it : ve) {
                for (auto &v : G[it]) {
                    v = pid[v].se;
                }
                sol.back().G[pid[it].se] = G[it];
            }
        }
}

void run() {
    rd(n, m, q, k1, k2);
    gen();
    numerAS();
    for (auto &it : sol) {
        it.gao();
    }
    for (int i = 1, u, v; i <= q; ++i) {
        rd(u, v);
        // dbg(pid[u].fi, pid[u].se, pid[v].se);
        int res = 0;
        if (pid[u].fi == pid[v].fi) {
            res = sol[pid[u].fi].query(pid[u].se, pid[v].se);
        }
        pt(res ? "Yes" : "No");
        cout.flush();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int _T = 1;
    while (_T--) run();
    //    for (int kase = 1; kase <= _T; ++kase) {
    //        cout << "Case #" << kase << ": ";
    //        run();
    //    }
    //    while (cin >> n) run();
    //    run();
    return 0;
}