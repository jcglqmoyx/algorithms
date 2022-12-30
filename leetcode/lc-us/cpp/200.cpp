#include <bits/stdc++.h>

using namespace std;

class Solution {
    int islands = 0;

    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i == (int) grid.size() || j < 0 || j == (int) grid[i].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};