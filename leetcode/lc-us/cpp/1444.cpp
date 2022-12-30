#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ways(vector<string> &pizza, int k) {
        const int MOD = 1e9 + 7;
        int n = (int) pizza.size(), m = (int) pizza[0].size();
        int s[n + 2][m + 2], f[k][n + 1][m + 1];
        memset(s, 0, sizeof s), memset(f, -1, sizeof f);
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                s[i][j] = s[i + 1][j] + s[i][j + 1] - s[i + 1][j + 1] + (pizza[i - 1][j - 1] == 'A');
                f[0][i][j] = s[i][j] ? 1 : 0;
            }
        }
        function<int(int, int, int)> dp = [&](int u, int i, int j) -> int {
            int &v = f[u][i][j];
            if (v != -1) return v;
            v = 0;
            for (int r = i + 1; r <= n; r++) {
                if (s[r][j] && s[i][j] - s[r][j] > 0) {
                    v = (v + dp(u - 1, r, j)) % MOD;
                }
            }
            for (int c = j + 1; c <= m; c++) {
                if (s[i][c] && s[i][j] - s[i][c] > 0) {
                    v = (v + dp(u - 1, i, c)) % MOD;
                }
            }
            return v;
        };
        return dp(k - 1, 1, 1);
    }
};