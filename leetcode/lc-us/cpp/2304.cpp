#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        int f[n][m];
        memset(f, 0, sizeof f);
        for (int j = 0; j < m; j++) f[0][j] = grid[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i][j] = 1e8;
                for (int k = 0; k < m; k++) {
                    f[i][j] = min(f[i][j], grid[i][j] + f[i - 1][k] + moveCost[grid[i - 1][k]][j]);
                }
            }
        }
        int res = 1e8;
        for (int j = 0; j < m; j++) res = min(res, f[n - 1][j]);
        return res;
    }
};