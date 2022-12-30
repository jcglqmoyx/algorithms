#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, max_time, res = 0;
    vector<int> v;
    vector<bool> st;
    vector<vector<pair<int, int>>> paths;

    void dfs(int u, int value, int time) {
        if (time > max_time) return;
        if (u == 0) res = max(res, value);
        for (auto ne: paths[u]) {
            if (st[ne.first]) {
                dfs(ne.first, value, time + ne.second);
            } else {
                st[ne.first] = true;
                dfs(ne.first, value + v[ne.first], time + ne.second);
                st[ne.first] = false;
            }
        }
    }

public:
    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime) {
        n = (int) values.size(), st.resize(n), max_time = maxTime, v = values, paths.resize(n,
                                                                                            vector<pair<int, int>>());
        for (auto &e: edges) {
            int x = e[0], y = e[1], dist = e[2];
            paths[x].push_back({y, dist});
            paths[y].push_back({x, dist});
        }
        st[0] = true;
        dfs(0, values[0], 0);
        return res;
    }
};