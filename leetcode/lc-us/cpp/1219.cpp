#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, m;
    int max_gold;

    void dfs(vector<vector<int>> &grid, int i, int j, int gold) {
        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0) return;
        gold += grid[i][j];
        max_gold = max(max_gold, gold);
        int value = grid[i][j];
        grid[i][j] = 0;
        dfs(grid, i + 1, j, gold);
        dfs(grid, i - 1, j, gold);
        dfs(grid, i, j + 1, gold);
        dfs(grid, i, j - 1, gold);
        grid[i][j] = value;
    }

public:
    int getMaximumGold(vector<vector<int>> &grid) {
        n = (int) grid.size(), m = (int) grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    dfs(grid, i, j, 0);
                }
            }
        }
        return max_gold;
    }
};