#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>> &mat) {
        map<int, vector<pair<int, int>>> g;
        int n = (int) mat.size(), m = (int) mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[mat[i][j]].emplace_back(i, j);
            }
        }

        int ans = 0;
        vector<int> row_max(n), col_max(m);
        for (auto &[_, pos]: g) {
            vector<int> mx;
            for (auto &[i, j]: pos) {
                mx.push_back(max(row_max[i], col_max[j]) + 1);
                ans = max(ans, mx.back());
            }
            for (int k = 0; k < pos.size(); k++) {
                auto &[i, j] = pos[k];
                row_max[i] = max(row_max[i], mx[k]);
                col_max[j] = max(col_max[j], mx[k]);
            }
        }
        return ans;
    }
};