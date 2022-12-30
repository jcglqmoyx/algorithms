#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        if (!maxMove) return 0;
        vector<vector<vector<int>>> f(m, vector<vector<int>>(n, vector<int>(maxMove + 1)));
        for (int i = 0; i < m; i++) f[i][0][1]++, f[i][n - 1][1]++;
        for (int j = 0; j < n; j++) f[0][j][1]++, f[m - 1][j][1]++;
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (int u = 0; u < 4; u++) {
                        int a = i + dx[u], b = j + dy[u];
                        if (a >= 0 && a < m && b >= 0 && b < n) {
                            f[i][j][k] = (f[i][j][k] + f[a][b][k - 1]) % MOD;
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= maxMove; i++) {
            res = (res + f[startRow][startColumn][i]) % MOD;
        }
        return res;
    }
};