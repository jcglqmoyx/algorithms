#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k) {
        int n = (int) vals.size();
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(vals[y]);
            g[y].push_back(vals[x]);
        }
        int res = -1e9;
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end(), greater<>());
            int sum = vals[i];
            int l = min(k, (int) g[i].size());
            for (int j = 0; j < l && g[i][j] > 0; j++) {
                sum += g[i][j];
            }
            res = max(res, sum);
        }
        return res;
    }
};