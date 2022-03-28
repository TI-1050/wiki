#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)1e5 + 10;

int n;
int ans1, ans2;
int fa[maxn];
char str[110];
vector<pair<int, int> > wolf;
vector<int> human[maxn];

void Init(int n) {
    ans1 = ans2 = 0;
    for (int i = 0; i <= n; ++i) fa[i] = i, human[i].clear();
    wolf.clear();
}

int find(int x) {
    return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

void mix(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        fa[x] = y;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void DFS(int u) {
    for (auto it : human[u]) {
        ++ans2;
        DFS(it);
    }
}

void RUN() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        Init(n);
        for (int i = 1; i <= n; ++i) {
            int u;
            scanf("%d %s", &u, str);
            if (str[0] == 'v') {
                mix(i, u);
                human[u].push_back(i);
            } else {
                wolf.push_back(make_pair(i, u));
            }
        }
        for (auto it : wolf) {
            if (same(it.first, it.second)) {
                ++ans2;
                DFS(it.second);
            }
        }
        printf("%d %d\n", ans1, ans2);
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