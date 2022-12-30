#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int state[6][4] = {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 0, 1, 1},
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 1, 0, 0},
    };

    bool dfs(vector<vector<int>> &grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if (x == m - 1 && y == n - 1) return true;
        int road = grid[x][y];
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] == 0) continue;
            if (state[road - 1][i] == 0 || state[grid[a][b] - 1][i ^ 2] == 0) continue;
            if (dfs(grid, a, b)) return true;
        }
        return false;
    }

public:
    bool hasValidPath(vector<vector<int>> &grid) {
        return dfs(grid, 0, 0);
    }
};