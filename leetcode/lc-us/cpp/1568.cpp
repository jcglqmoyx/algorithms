#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, m;
    vector<vector<int>> g;

    void dfs(vector<vector<int>> &grid, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return;
        grid[x][y] = 0;
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }

public:
    int minDays(vector<vector<int>> &grid) {
        n = (int) grid.size(), m = (int) grid[0].size();
        g = grid;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    cnt++;
                    if (cnt > 1) return 0;
                    dfs(g, i, j);
                }
            }
        }
        if (!cnt) return 0;
        int ones = 0;
        for (auto &r: grid) {
            for (auto e: r) {
                if (e) ones++;
            }
        }
        if (ones == 1) return 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    g = grid;
                    g[i][j] = 0;
                    cnt = 0;
                    for (int k = 0; k < n; k++) {
                        for (int l = 0; l < m; l++) {
                            if (g[k][l] == 1) {
                                cnt++;
                                dfs(g, k, l);
                            }
                        }
                    }
                    if (cnt > 1) {
                        return 1;
                    }
                }
            }
        }
        return 2;
    }
};
