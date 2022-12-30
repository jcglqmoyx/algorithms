#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>> &grid) {
        const int MOD = 1e9 + 7;
        int n = (int) grid.size(), m = (int) grid[0].size();
        long long f[n][m], g[n][m];
        f[0][0] = g[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) f[i][0] = g[i][0] = f[i - 1][0] * grid[i][0];
        for (int j = 1; j < m; j++) f[0][j] = g[0][j] = f[0][j - 1] * grid[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][j] < 0) {
                    f[i][j] = min(g[i][j - 1], g[i - 1][j]) * grid[i][j];
                    g[i][j] = max(f[i][j - 1], f[i - 1][j]) * grid[i][j];
                } else {
                    f[i][j] = max(f[i][j - 1], f[i - 1][j]) * grid[i][j];
                    g[i][j] = min(g[i][j - 1], g[i - 1][j]) * grid[i][j];
                }
            }
        }
        f[n - 1][m - 1] %= MOD;
        return f[n - 1][m - 1] >= 0 ? (int) f[n - 1][m - 1] : -1;
    }
};