#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        g = graph;
        vector<int> path = {0};
        dfs(0, path);
        return res;
    }

private:
    vector<vector<int>> res, g;

    void dfs(int idx, vector<int> &path) {
        if (idx == g.size() - 1) {
            res.push_back(path);
            return;
        }
        for (int x: g[idx]) {
            path.push_back(x);
            dfs(x, path);
            path.pop_back();
        }
    }
};