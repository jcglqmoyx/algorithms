#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>> &grid) {
        int m = (int) grid.size(), n = (int) grid[0].size();
        int f[m][n][4];
        memset(f, 0, sizeof f);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    f[i][j][0] = 0;
                    f[i][j][2] = 0;
                } else {
                    int l = (j > 0) ? f[i][j - 1][0] : 0, u = (i > 0) ? f[i - 1][j][2] : 0, cur = grid[i][j] == 'E';
                    f[i][j][0] = l + cur;
                    f[i][j][2] = u + cur;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') {
                    f[i][j][1] = 0;
                    f[i][j][3] = 0;
                } else {
                    int r = (j < n - 1) ? f[i][j + 1][1] : 0, d = (i < m - 1) ? f[i + 1][j][3] : 0;
                    int cur = grid[i][j] == 'E';
                    f[i][j][1] = r + cur;
                    f[i][j][3] = d + cur;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '0') continue;
                int g = f[i][j][0] + f[i][j][1] + f[i][j][2] + f[i][j][3];
                ans = max(ans, g);
            }
        }
        return ans;
    }
};