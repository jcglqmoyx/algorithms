#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (m < k) return 0;

        const int MOD = 1e9 + 7;

        int f[n + 1][k + 1][m + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= m; i++) f[1][1][i] = 1;

        int pre_sum[n + 1][k + 1][m + 1];
        memset(pre_sum, 0, sizeof pre_sum);
        for (int i = 1; i <= m; i++) pre_sum[1][1][i] = i;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= min(i, k); j++) {
                for (int u = 1; u <= m; u++) {
                    f[i][j][u] = (int) ((long long) f[i - 1][j][u] * u % MOD);
                    if (j) {
                        f[i][j][u] = (f[i][j][u] + pre_sum[i - 1][j - 1][u - 1]) % MOD;
                    }
                    pre_sum[i][j][u] = (pre_sum[i][j][u - 1] + f[i][j][u]) % MOD;
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= m; i++) res = (res + f[n][k][i]) % MOD;
        return res;
    }
};