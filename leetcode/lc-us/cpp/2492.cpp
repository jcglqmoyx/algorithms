#include <bits/stdc++.h>

using namespace std;

class Solution {
    int res;
    vector<bool> st;

    void dfs(vector<vector<int>> &roads, vector<vector<pair<int, int>>> &g, int u) {
        for (auto ne: g[u]) {
            if (st[ne.second]) continue;
            res = min(res, roads[ne.second][2]);
            st[ne.second] = true;
            dfs(roads, g, ne.first);
        }
    }

public:
    int minScore(int n, vector<vector<int>> &roads) {
        res = INT32_MAX;
        vector<vector<pair<int, int>>> g(n + 1);
        st.resize(roads.size(), false);
        for (int i = 0; i < roads.size(); i++) {
            auto &r = roads[i];
            int x = r[0], y = r[1];
            g[x].push_back({y, i});
            g[y].push_back({x, i});
        }
        dfs(roads, g, 1);
        return res;
    }
};