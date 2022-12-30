#include <bits/stdc++.h>

using namespace std;

class Solution {
    int max_area = 0, cur = 0;

    void dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i == (int) grid.size() || j < 0 ||
            j == (int) grid[i].size() || grid[i][j] == 0) {
            return;
        }
        cur++;
        max_area = max(max_area, cur);
        grid[i][j] = 0;
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    cur = 0;
                    dfs(grid, i, j);
                }
            }
        }
        return max_area;
    }
};