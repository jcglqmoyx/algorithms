#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isThereAPath(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        if ((n + m) % 2 == 0) return false;
        bool f[n][m][(n + m) * 2];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    if (grid[i][j] == 0) f[i][j][1 + n + m] = true;
                    else f[i][j][-1 + n + m] = true;
                }
                if (i) {
                    for (int it = -(i + j); it <= i + j; it++) {
                        if (f[i - 1][j][it + n + m]) {
                            if (grid[i][j] == 0) f[i][j][it + 1 + n + m] = true;
                            else f[i][j][it - 1 + n + m] = true;
                        }
                    }
                }
                if (j) {
                    for (int it = -(i + j); it <= i + j; it++) {
                        if (f[i][j - 1][it + n + m]) {
                            if (grid[i][j] == 0) f[i][j][it + 1 + n + m] = true;
                            else f[i][j][it - 1 + n + m] = true;
                        }
                    }
                }
            }
        }
        return f[n - 1][m - 1][n + m];
    }
};