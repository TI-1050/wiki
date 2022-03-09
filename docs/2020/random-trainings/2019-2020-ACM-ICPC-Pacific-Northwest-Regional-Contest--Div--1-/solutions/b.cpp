#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, k;
int a[N];
int res[N];
int cnt[N];
int in[N];
stack<int> st;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        cnt[a[i]]--;
        if (in[a[i]])
            continue;
        while (!st.empty() && a[i] < st.top() && cnt[st.top()]) {
            in[st.top()] = 0;
            st.pop();
        }
        in[a[i]] = 1;
        st.push(a[i]);
    }
    for (int i = k; i >= 1; --i) {
        res[i] = st.top();
        st.pop();
    }
    for (int i = 1; i <= k; ++i) {
        printf("%d%c", res[i], " \n"[i == k]);
    }
    return 0;
}
