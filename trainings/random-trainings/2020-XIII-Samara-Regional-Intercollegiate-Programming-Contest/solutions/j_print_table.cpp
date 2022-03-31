#include <bits/stdc++.h>

using namespace std;

bool ok1(vector<int> v1, vector<int> v2) {
    int cnt = 0;
    for (auto it1 : v1) {
        for (auto it2 : v2) {
            if (it1 > it2) {
                cnt++;
            }
            if (it1 < it2) {
                cnt--;
            }
        }
    }
    return cnt > 0;
}

bool ok2(vector<int> v1, vector<int> v2) {
    int cnt = 0;
    for (int i = 0, len1 = v1.size(); i < len1; ++i) {
        for (int j = 0, len2 = v2.size(); j < len2; ++j) {
            for (int ii = i + 1; ii < len1; ++ii) {
                for (int jj = j + 1; jj < len2; ++jj) {
                    if (v1[i] + v1[ii] > v2[j] + v2[jj]) {
                        cnt++;
                    }
                    if (v1[i] + v1[ii] < v2[j] + v2[jj]) {
                        cnt--;
                    }
                }
            }
        }
    }
    return cnt < 0;
}

bool ok3(vector<int> v1, vector<int> v2) {
    int cnt = 0;
    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v2.size(); ++j) {
            for (int ii = i + 1; ii < v1.size(); ++ii) {
                for (int jj = j + 1; jj < v2.size(); ++jj) {
                    for (int iii = ii + 1; iii < v1.size(); ++iii) {
                        for (int jjj = jj + 1; jjj < v2.size(); ++jjj) {
                            if (v1[i] + v1[ii] + v1[iii] > v2[j] + v2[jj] + v2[jjj]) {
                                cnt++;
                            }
                            if (v1[i] + v1[ii] + v1[iii] < v2[j] + v2[jj] + v2[jjj]) {
                                cnt--;
                            }
                        }
                    }
                }
            }
        }
    }
    return cnt > 0;
}

mt19937 rnd(time(0));
int main() {
    while (true) {
        vector<int> v1, v2;
        for (int i = 1; i <= 10; ++i) {
            if (rnd() % 2 == 0) {
                v1.push_back(i);
            }
            if (rnd() % 2 == 0) {
                v2.push_back(i);
            }
        }
        if (v1.size() < 3 || v2.size() < 3)
            continue;
        if (ok1(v1, v2) && ok2(v1, v2) && ok3(v1, v2)) {
            cout << "ok" << endl;
            for (auto it : v1) {
                cout << it << " ";
            }
            cout << endl;
            for (auto it : v2) {
                cout << it << " ";
            }
            cout << endl;
            system("pause");
        }
    }
    return 0;
}
