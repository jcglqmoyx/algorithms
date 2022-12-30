#include <bits/stdc++.h>

using namespace std;

const int N = 70;

int f[N][N][N];

class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        memset(f, -1, sizeof f);
        f[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
        for (int k = 1; k < n; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    for (int a = max(0, i - 1); a <= min(m - 1, i + 1); a++) {
                        for (int b = max(0, j - 1); b <= min(m - 1, j + 1); b++) {
                            if (f[k - 1][a][b] == -1) continue;
                            int t = grid[k][i];
                            if (i != j) t += grid[k][j];
                            f[k][i][j] = max(f[k][i][j], f[k - 1][a][b] + t);
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i != j) {
                    res = max(res, f[n - 1][i][j]);
                }
            }
        }
        return res;
    }
};