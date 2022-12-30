#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        vector<int> row_max(n), col_max(m);
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v.push_back({grid[i][j], i, j});
            }
        }
        sort(v.begin(), v.end());
        for (auto &t: v) {
            int r = t[1], c = t[2];
            res[r][c] = max(row_max[r], col_max[c]) + 1;
            row_max[r] = max(row_max[r], res[r][c]);
            col_max[c] = max(col_max[c], res[r][c]);
        }
        return res;
    }
};