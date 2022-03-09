#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int get(char c) {
    if (c == 'A')
        return 1;
    else if (c == 'D')
        return 10;
    else if (c == 'Q')
        return 11;
    else if (c == 'J')
        return 12;
    else if (c == 'K')
        return 13;
    else
        return c - '0';
}

struct E {
    bool First, wildcard;
    vector<int> card;
    int get() {
        if (wildcard) {
            if (First) {
                First = false;
            } else {
                wildcard = false;
                return -1;
            }
        }
        map<int, int> mp;
        for (auto it : card) {
            mp[it]++;
        }
        int Min = INF;
        for (auto it : mp) {
            Min = min(it.second, Min);
        }
        for (auto it : mp) {
            if (it.second == Min) {
                card.erase(find(card.begin(), card.end(), it.first));
                return it.first;
            }
        }
    }

    void insert(int x) {
        if (x == -1) {
            First = wildcard = true;
        } else {
            card.push_back(x);
        }
    }
} a[30];

bool win(int x) {
    if (a[x].wildcard)
        return false;
    if (a[x].card[0] != a[x].card[1])
        return false;
    if (a[x].card[1] != a[x].card[2])
        return false;
    if (a[x].card[2] != a[x].card[3])
        return false;
    return true;
}

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        char s[10];
        scanf("%s", s + 1);
        a[i].card.clear();
        for (int j = 1; j <= 4; ++j) {
            a[i].insert(get(s[j]));
        }
        a[i].First = a[i].wildcard = false;
    }
    a[k].First = a[k].wildcard = true;
    for (int i = 1; i <= n; ++i) {
        if (win(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    int cur = k;
    while (true) {
        int nxt = cur % n + 1;
        a[nxt].insert(a[cur].get());
        if (win(cur))
            break;
        cur = nxt;
    }
    printf("%d\n", cur);
    return 0;
}
