#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

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

mt19937 rnd(time(0));
// int cnt;

int ask(int x, int y) {
    // cnt++;
    // if (x > y)
    //     return 1;
    // else if (x < y)
    //     return -1;
    // else
    //     return 0;
    printf("? %d %d\n", x, y);
    fflush(stdout);
    char c;
    scanf(" %c", &c);
    if (c == '>')
        return 1;
    else if (c == '<')
        return -1;
    else
        return 0;
}

int n;
int res[N];

void gao(vector<int> L, vector<int> R) {
    // dbg(L.size(), R.size());
    if (L.empty())
        return;
    if (L.size() == 1) {
        res[L[0]] = R[0];
        return;
    }
    int pos = rnd() % L.size();
    vector<int> rl, rr;
    int cur = 0;
    for (auto it : R) {
        int op = ask(L[pos], it);
        if (op == -1) {
            rl.push_back(it);
        } else if (op == 1) {
            rr.push_back(it);
        } else {
            cur = it;
        }
    }
    // dbg(cur, pos);
    vector<int> ll, lr;
    for (auto it : L) {
        if (it == L[pos])
            continue;
        int op = ask(it, cur);
        if (op == -1)
            lr.push_back(it);
        else
            ll.push_back(it);
    }
    res[L[pos]] = cur;
    gao(ll, rl);
    gao(lr, rr);
}

vector<int> a, b;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        a.push_back(i);
        b.push_back(i);
    }
    gao(a, b);
    // assert(cnt <= 5 * n * log2(n));
    printf("! ");
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", res[i], " \n"[i == n]);
    }
    fflush(stdout);
    return 0;
}
