#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

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

int n, k, sum, sum2;
char s[N];
int cnt[20], cnt2[20];
vector<int> vec, vec1, vec2, vec3;

bool cmp(vector<int> V1, vector<int> V2) {
    for (int i = 0; i < k; ++i) {
        if (V1 > V2)
            return true;
        if (V1 < V2)
            return false;
    }
    return true;
}

void print(vector<int> V) {
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    if (V[0] == 0 && V.size() > 1) {
        puts("-1");
        return;
    }
    for (auto it : V) {
        printf("%d", it);
    }
    puts("");
}

bool ok1(vector<int>& vec) {
    for (int i = k - 1; i >= 0; --i) {
        int it = vec[i];
        for (int j = 9; j >= 0; --j) {
            if (!cnt[j])
                continue;
            if ((sum - it + j) % 3 == 0) {
                vec[i] = j;
                return true;
            }
        }
    }
    return false;
}

bool ok2(vector<int>& vec) {
    for (int i = k - 1; i >= 0; --i) {
        int it = vec[i];
        bool F = false;
        for (int j = 9; j >= 0; --j) {
            if (!cnt[j])
                continue;
            int a = (it % 3 + 2) % 3;
            if (j % 3 == a) {
                vec[i] = j;
                sum = sum - it + j;
                cnt[j]--;
                cnt[it]++;
                F = true;
                break;
            }
        }
        if (F)
            break;
    }
    for (int i = k - 1; i >= 0; --i) {
        int it = vec[i];
        bool F = false;
        for (int j = 9; j >= 0; --j) {
            if (!cnt[j])
                continue;
            int a = (it % 3 + 2) % 3;
            if (j % 3 == a) {
                vec[i] = j;
                sum = sum - it + j;
                cnt[j]--;
                cnt[it]++;
                F = true;
                break;
            }
        }
        if (F)
            break;
    }

    return sum % 3 == 0;
}

bool ok3(vector<int>& vec) {
    for (int i = k - 1; i >= 0; --i) {
        int it = vec[i];
        bool F = false;
        for (int j = 9; j >= 0; --j) {
            if (!cnt2[j])
                continue;
            int a = (it % 3 + 1) % 3;
            if (j % 3 == a) {
                vec[i] = j;
                sum2 = sum2 - it + j;
                cnt2[j]--;
                cnt2[it]++;
                F = true;
                break;
            }
        }
        if (F)
            break;
    }
    for (int i = k - 1; i >= 0; --i) {
        int it = vec[i];
        bool F = false;
        for (int j = 9; j >= 0; --j) {
            if (!cnt2[j])
                continue;
            int a = (it % 3 + 1) % 3;
            if (j % 3 == a) {
                vec[i] = j;
                sum2 = sum2 - it + j;
                cnt2[j]--;
                cnt2[it]++;
                F = true;
                break;
            }
        }
        if (F)
            break;
    }

    return sum2 % 3 == 0;
}

int main() {
    int _T;
    scanf("%d", &_T);
    while (_T--) {
        memset(cnt, 0, sizeof cnt);
        memset(cnt2, 0, sizeof cnt2);
        sum = 0;
        sum2 = 0;
        vec.clear();
        scanf("%s %d", s + 1, &k);
        n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            cnt[s[i] - '0']++;
            cnt2[s[i] - '0']++;
        }
        int need = k;
        for (int i = 9; i >= 0; --i) {
            while (need > 0 && cnt[i]) {
                vec.push_back(i);
                need--;
                cnt[i]--;
                cnt2[i]--;
                sum += i;
                sum2 += i;
            }
        }
        // print(vec);
        if (sum % 3 == 0) {
            print(vec);
            continue;
        }
        vec1 = vec;
        vec2 = vec;
        vec3 = vec;
        bool F1 = ok1(vec1);
        bool F2 = ok2(vec2);
        bool F3 = ok3(vec3);
        sort(vec1.begin(), vec1.end());
        reverse(vec1.begin(), vec1.end());

        sort(vec2.begin(), vec2.end());
        reverse(vec2.begin(), vec2.end());

        sort(vec3.begin(), vec3.end());
        reverse(vec3.begin(), vec3.end());

        if (F1 && (!F2 || vec1 >= vec2) && (!F3 || vec1 >= vec3)) {
            print(vec1);
        } else if (F2 && (!F1 || vec2 >= vec1) && (!F3 || vec2 >= vec3)) {
            print(vec2);
        } else if (F3 && (!F1 || vec3 >= vec1) && (!F2 || vec3 >= vec2)) {
            print(vec3);
        } else {
            puts("-1");
        }
    }
    return 0;
}
