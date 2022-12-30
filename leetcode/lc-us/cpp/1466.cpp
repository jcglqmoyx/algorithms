#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<bool> st(n);
        unordered_map<int, vector<pair<int, int>>> g;
        for (auto &con: connections) {
            g[con[0]].push_back({con[1], 0});
            g[con[1]].push_back({con[0], 1});
        }
        int cnt = 0;
        st[0] = true;
        dfs(g, 0, st, cnt);
        return cnt;
    }

private:
    void dfs(unordered_map<int, vector<pair<int, int>>> &g, int idx, vector<bool> &st, int &cnt) {
        for (auto &ne: g[idx]) {
            if (st[ne.first]) continue;
            st[ne.first] = true;
            if (!ne.second) cnt++;
            dfs(g, ne.first, st, cnt);
        }
    }
};