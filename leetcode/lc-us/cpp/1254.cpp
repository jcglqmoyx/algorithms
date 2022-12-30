#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool closed = true;

    void dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i == (int) grid.size() || j < 0 || j == (int) grid[i].size() || grid[i][j] == 1) {
            return;
        }
        if (i == 0 || j == 0 || i == (int) grid.size() - 1 || j == (int) grid[i].size() - 1) {
            closed = false;
            return;
        }
        grid[i][j] = 1;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

public:
    int closedIsland(vector<vector<int>> &grid) {
        int closed_island = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                closed = true;
                if (grid[i][j] == 0) {
                    dfs(grid, i, j);
                    if (closed) {
                        closed_island++;
                    }
                }
            }
        }
        return closed_island;
    }
};