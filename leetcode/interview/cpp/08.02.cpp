#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> res, path;

    bool dfs(vector<vector<int>> &grid, int x, int y) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        if (x == n - 1 && y == m - 1) {
            path.push_back({x, y});
            res = path;
            return true;
        }
        grid[x][y] = 1;
        path.push_back({x, y});
        int len = (int) path.size();
        if (x + 1 < n && grid[x + 1][y] != 1) {
            if (dfs(grid, x + 1, y)) {
                return true;
            }
            path.erase(path.begin() + len, path.end());
        }
        if (y + 1 < m && grid[x][y + 1] != 1) {
            if (dfs(grid, x, y + 1)) return true;
            path.erase(path.begin() + len, path.end());
        }
        return false;
    }

public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.front().front() == 1 || obstacleGrid.back().back() == 1) return {};
        dfs(obstacleGrid, 0, 0);
        return res;
    }
};