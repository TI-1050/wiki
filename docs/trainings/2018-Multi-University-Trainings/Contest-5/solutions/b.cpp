#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;

struct node {
    int num, idx, step;
    node() {}
    node(int num, int idx, int step) : num(num), idx(idx), step(step) {}
};

int n, k;
int cnt;
int arr[maxn];

int BFS1() {
    queue<node> q;
    q.push(node(n, cnt, 0));
    int ans = INF;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        ans = min(ans, now.num);
        if (now.step == k)
            continue;
        if (now.idx == 1)
            continue;
        int tmp = now.num;
        cnt = 0;
        while (tmp) {
            arr[++cnt] = tmp % 10;
            tmp /= 10;
        }
        int Min = now.idx;
        for (int i = now.idx - 1; i >= 1; --i) {
            if (arr[i] == arr[now.idx])
                continue;
            if (arr[i] == 0 && now.idx == cnt)
                continue;
            if (arr[i] < arr[Min])
                Min = i;
        }
        if (Min == now.idx) {
            q.push(node(now.num, now.idx - 1, now.step));
        } else {
            for (int i = now.idx - 1; i >= 1; --i) {
                if (arr[i] == arr[Min]) {
                    swap(arr[i], arr[now.idx]);
                    tmp = 0;
                    for (int j = cnt; j >= 1; --j) {
                        tmp = tmp * 10 + arr[j];
                    }
                    q.push(node(tmp, now.idx - 1, now.step + 1));
                    swap(arr[i], arr[now.idx]);
                }
            }
        }
    }
    return ans;
}

int BFS2() {
    queue<node> q;
    q.push(node(n, cnt, 0));
    int ans = -INF;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        ans = max(ans, now.num);
        if (now.step == k)
            continue;
        if (now.idx == 1)
            continue;
        int tmp = now.num;
        cnt = 0;
        while (tmp) {
            arr[++cnt] = tmp % 10;
            tmp /= 10;
        }
        int Max = now.idx;
        for (int i = now.idx - 1; i >= 1; --i) {
            if (arr[i] == arr[now.idx])
                continue;
            if (arr[i] > arr[Max])
                Max = i;
        }
        if (Max == now.idx) {
            q.push(node(now.num, now.idx - 1, now.step));
        } else {
            for (int i = now.idx - 1; i >= 1; --i) {
                if (arr[i] == arr[Max]) {
                    swap(arr[i], arr[now.idx]);
                    tmp = 0;
                    for (int j = cnt; j >= 1; --j) {
                        tmp = tmp * 10 + arr[j];
                    }
                    q.push(node(tmp, now.idx - 1, now.step + 1));
                    swap(arr[i], arr[now.idx]);
                }
            }
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        int tmp = n;
        cnt = 0;
        while (tmp) {
            cnt++;
            tmp /= 10;
        }
        k = min(k, cnt - 1);
        int ans1 = BFS1();
        int ans2 = BFS2();
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}