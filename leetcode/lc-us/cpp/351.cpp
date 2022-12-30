#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        _m = m, _n = n, cnt = 0, st.resize(9);
        for (int i = 0; i < 9; i++) {
            st[i] = true;
            path.push_back(i);
            dfs(i);
            path.pop_back();
            st[i] = false;
        }
        return cnt;
    }

private:
    int _m, _n;
    int cnt;
    vector<bool> st;
    vector<int> path;

    void dfs(int num) {
        if (path.size() > _n) return;
        if (path.size() >= _m) cnt++;
        for (int i = 0; i < 9; i++) {
            if (st[i]) continue;
            if (num % 3 == i % 3 || num / 3 == i / 3 || num + i == 8) {
                if ((num + i) % 2 == 0 && !st[(num + i) >> 1]) continue;
            }
            path.push_back(i);
            st[i] = true;
            dfs(i);
            path.pop_back();
            st[i] = false;
        }
    }
};