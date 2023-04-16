#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>> &grid) {
        auto n = grid.size(), m = grid[0].size();
        vector<int> res(m);
        for (auto j = 0; j < m; j++) {
            size_t t = 0;
            for (auto i = 0; i < n; i++) {
                t = max(t, to_string(grid[i][j]).size());
            }
            res[j] = t;
        }
        return res;
    }
};