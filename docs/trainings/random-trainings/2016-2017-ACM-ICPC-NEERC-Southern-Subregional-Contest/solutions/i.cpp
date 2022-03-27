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

struct Min_Cost_Max_Flow {
    static const int N = 1e4 + 10;
    static const int M = 1e6 + 10;
    const int INF = 0x3f3f3f3f;
    struct E {
        int to, nxt, cap, flow, cost;
    } edge[M << 1];
    int head[N], tot;
    int pre[N], dis[N];
    int vis[N];
    int n;

    void init(int _n) {
        n = _n;
        tot = 0;
        memset(head, -1, sizeof head);
    }

    void addedge(int u, int v, int cap, int cost) {
        edge[tot] = {v, head[u], cap, 0, cost};
        head[u] = tot++;
        edge[tot] = {u, head[v], 0, 0, -cost};
        head[v] = tot++;
    }

    bool SPFA(int s, int t) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            dis[i] = INF;
            vis[i] = false;
            pre[i] = -1;
        }
        dis[s] = 0;
        vis[s] = true;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (int i = head[u]; ~i; i = edge[i].nxt) {
                int v = edge[i].to;
                if (edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost) {
                    dis[v] = dis[u] + edge[i].cost;
                    pre[v] = i;
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        if (pre[t] == -1)
            return false;
        else
            return true;
    }

    int gao(int s, int t, int &cost) {
        int flow = 0;
        cost = 0;
        while (SPFA(s, t)) {
            int Min = INF;
            for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to]) {
                if (Min > edge[i].cap - edge[i].flow) {
                    Min = edge[i].cap - edge[i].flow;
                }
            }
            for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to]) {
                edge[i].flow += Min;
                edge[i ^ 1].flow -= Min;
                cost += edge[i].cost * Min;
            }
            flow += Min;
        }
        return flow;
    }
} MSMF;

const int N = 3e3 + 10;

int n, s, p;
int a[N], b[N];

int main() {
#ifdef LOCAL_JUDGE
    freopen("input", "r", stdin);
#endif
    scanf("%d %d %d", &n, &p, &s);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", b + i);
    }
    int A = n + 1, B = n + 2, S = n + 3, T = n + 4;
    MSMF.init(T + 10);
    for (int i = 1; i <= n; ++i) {
        MSMF.addedge(S, i, 1, 0);
        MSMF.addedge(i, A, 1, -a[i]);
        MSMF.addedge(i, B, 1, -b[i]);
    }
    MSMF.addedge(A, T, p, 0);
    MSMF.addedge(B, T, s, 0);
    int cost = 0;
    int flow = MSMF.gao(S, T, cost);
    assert(flow == p + s);
    vector<int> vec_A, vec_B;
    for (int u = 1; u <= n; ++u) {
        for (int i = MSMF.head[u]; ~i; i = MSMF.edge[i].nxt) {
            if (MSMF.edge[i].cap == MSMF.edge[i].flow && MSMF.edge[i].to == A) {
                vec_A.push_back(u);
                break;
            }
            if (MSMF.edge[i].cap == MSMF.edge[i].flow && MSMF.edge[i].to == B) {
                vec_B.push_back(u);
                break;
            }
        }
    }
    //    assert(vec_A.size() == p && vec_B.size() == s);
    printf("%d\n", -cost);
    for (int i = 0, len = vec_A.size(); i < len; ++i) {
        printf("%d%c", vec_A[i], " \n"[i == len - 1]);
    }
    for (int i = 0, len = vec_B.size(); i < len; ++i) {
        printf("%d%c", vec_B[i], " \n"[i == len - 1]);
    }
    return 0;
}
