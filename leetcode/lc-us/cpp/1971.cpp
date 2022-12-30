#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
        _end = end, flag = false;
        st.resize(n), g.resize(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y), g[y].push_back(x);
        }
        dfs(start);
        return flag;
    }

private:
    int _end;
    bool flag;
    vector<bool> st;
    vector<vector<int>> g;

    void dfs(int start) {
        if (st[start]) return;
        if (start == _end) {
            flag = true;
            return;
        }
        st[start] = true;
        for (int ne: g[start]) {
            dfs(ne);
        }
    }
};