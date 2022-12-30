#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int f[N][N][N << 1];

class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        memset(f, -0x3f, sizeof f);
        f[1][1][2] = grid[0][0];
        for (int k = 3; k <= n + m; k++) {
            for (int i = max(1, k - m); i <= min(n, k - 1); i++) {
                for (int j = max(1, k - m); j <= min(n, k - 1); j++) {
                    int r1 = i - 1, c1 = k - i - 1, r2 = j - 1, c2 = k - j - 1;
                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;
                    int t = grid[r1][c1];
                    if (r1 != r2) t += grid[r2][c2];
                    for (int r = i - 1; r <= i; r++) {
                        for (int c = j - 1; c <= j; c++) {
                            f[i][j][k] = max(f[i][j][k], f[r][c][k - 1]);
                        }
                    }
                    f[i][j][k] += t;
                }
            }
        }
        return max(0, f[n][n][n + m]);
    }
};