#include <bits/stdc++.h>

using namespace std;

class Solution {
    int m, n;
    vector<vector<int>> grid;
    vector<vector<int>> state;
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, int t) {
        if (state[x][y] & t) return;
        state[x][y] |= t;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (~a && a < m && ~b && b < n && grid[a][b] >= grid[x][y]) {
                dfs(a, b, t);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        grid = heights;
        m = (int) grid.size(), n = (int) grid[0].size();
        state = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; i++) dfs(i, 0, 1);
        for (int i = 0; i < n; i++) dfs(0, i, 1);
        for (int i = 0; i < n; i++) dfs(m - 1, i, 2);
        for (int i = 0; i < m; i++) dfs(i, n - 1, 2);
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (state[i][j] == 3) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};