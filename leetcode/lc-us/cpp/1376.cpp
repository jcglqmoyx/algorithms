#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        _n = n, g.resize(n), inform_time = informTime;
        for (int i = 0; i < n; i++) if (manager[i] != -1) g[manager[i]].push_back(i);
        dfs(headID, 0);
        return res;
    }

private:
    int _n, res = 0;
    vector<int> inform_time;
    vector<vector<int>> g;

    void dfs(int i, int time) {
        if (g[i].empty()) {
            res = max(res, time);
            return;
        }
        for (int j: g[i]) {
            dfs(j, time + inform_time[i]);
        }
    }
};