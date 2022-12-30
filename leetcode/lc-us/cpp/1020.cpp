#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>> &grid) {
        n = (int) grid.size(), m = (int) grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0]) {
                flood_fill(grid, i, 0);
            }
            if (grid[i][m - 1]) {
                flood_fill(grid, i, m - 1);
            }
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j]) {
                flood_fill(grid, 0, j);
            }
            if (grid[n - 1][j]) {
                flood_fill(grid, n - 1, j);
            }
        }
        int count = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    int n, m;

    void flood_fill(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        flood_fill(grid, i + 1, j);
        flood_fill(grid, i - 1, j);
        flood_fill(grid, i, j + 1);
        flood_fill(grid, i, j - 1);
    }
};