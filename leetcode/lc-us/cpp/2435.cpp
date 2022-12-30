#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>> &g, int k) {
        const int MOD = 1e9 + 7;
        int n = (int) g.size(), m = (int) g[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] %= k;
            }
        }
        int f[n][m][k];
        memset(f, 0, sizeof f);
        f[0][0][g[0][0]] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i) {
                    for (int u = 0; u < k; u++) {
                        f[i][j][(u + g[i][j]) % k] = (f[i][j][(u + g[i][j]) % k] + f[i - 1][j][u]) % MOD;
                    }
                }
                if (j) {
                    for (int u = 0; u < k; u++) {
                        f[i][j][(u + g[i][j]) % k] = (f[i][j][(u + g[i][j]) % k] + f[i][j - 1][u]) % MOD;
                    }
                }
            }
        }
        return f[n - 1][m - 1][0];
    }
};