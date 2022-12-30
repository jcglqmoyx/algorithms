#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        int f[1005][1005][2];
        memset(f, 0, sizeof f);
        f[0][0][0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= min(k, i); j++) {
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1]) % MOD;
                f[i][j][1] = f[i - 1][j][1];
                if (j) {
                    f[i][j][1] += f[i - 1][j - 1][0];
                    f[i][j][1] %= MOD;
                    f[i][j][1] += f[i - 1][j - 1][1];
                    f[i][j][1] %= MOD;
                }
            }
        }
        return (f[n - 1][k][0] + f[n - 1][k][1]) % MOD;
    }
};