#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10, M = 1e4 + 10;

struct E {
    int id, v;
    E() {}

    E(int id, int v) : id(id), v(v) {}

    bool operator<(const E &other) const {
        return v < other.v;
    }
} a[N];

int n;
int f[M][N];
priority_queue<E> q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].v);
        a[i].id = i;
        q.push(a[i]);
    }
    for (int cas = 1;; ++cas) {
        vector<E> vec;
        vec.push_back(q.top());
        q.pop();
        while (!q.empty()) {
            if (q.top().v == vec[0].v) {
                vec.push_back(q.top());
                q.pop();
            } else {
                break;
            }
        }
        if (vec.size() == n) {
            printf("%d\n", vec[0].v);
            printf("%d\n", cas - 1);
            for (int i = 1; i < cas; ++i) {
                for (int j = 1; j <= n; ++j) {
                    printf("%d", f[i][j]);
                }
                puts("");
            }
            break;
        }
        if (vec.size() == 1) {
            E tmp = q.top();
            q.pop();
            tmp.v = max(tmp.v - 1, 0);
            f[cas][tmp.id] = 1;
            q.push(tmp);
            vec[0].v = max(vec[0].v - 1, 0);
            f[cas][vec[0].id] = 1;
            q.push(vec[0]);
        } else if (vec.size() % 2 == 0) {
            vec[0].v = max(vec[0].v - 1, 0);
            vec[1].v = max(vec[1].v - 1, 0);
            f[cas][vec[0].id] = 1;
            f[cas][vec[1].id] = 1;
            for (auto it : vec) {
                q.push(it);
            }
        } else {
            vec[0].v = max(vec[0].v - 1, 0);
            vec[1].v = max(vec[1].v - 1, 0);
            vec[2].v = max(vec[2].v - 1, 0);
            f[cas][vec[0].id] = 1;
            f[cas][vec[1].id] = 1;
            f[cas][vec[2].id] = 1;
            for (auto it : vec) {
                q.push(it);
            }
        }
    }
    return 0;
}
