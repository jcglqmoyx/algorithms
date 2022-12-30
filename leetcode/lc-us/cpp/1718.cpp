#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        if (n == 1) return {1};
        _n = n, path.resize(n * 2 - 1), st.resize(n + 1);
        dfs(0);
        return path;
    }

private:
    int _n;
    vector<int> path;
    vector<bool> st;

    bool dfs(int index) {
        if (index == path.size()) return true;
        if (path[index]) return dfs(index + 1);
        for (int i = _n; i; i--) {
            if (st[i]) continue;
            if (i == 1) {
                st[i] = true;
                path[index] = i;
                if (dfs(index + 1)) return true;
                path[index] = 0;
                st[i] = false;
            } else {
                if (index + i >= path.size() || path[index + i]) continue;
                st[i] = true;
                path[index] = path[index + i] = i;
                if (dfs(index + 1)) return true;
                path[index] = path[index + i] = 0;
                st[i] = false;
            }
        }
        return false;
    }
};