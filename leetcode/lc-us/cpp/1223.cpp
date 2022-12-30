#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dieSimulator(int n, vector<int> &rollMax) {
        const int MOD = 1e9 + 7;
        const int m = *max_element(rollMax.begin(), rollMax.end());
        int f[n + 1][6][m + 1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < 6; i++) {
            f[1][i][1] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 1; k <= rollMax[j]; k++) {
                    for (int u = 0; u < 6; u++) {
                        int len = 1;
                        if (u == j) {
                            len = k + 1;
                            if (len > rollMax[u]) {
                                continue;
                            }
                        }
                        f[i + 1][u][len] += f[i][j][k];
                        f[i + 1][u][len] %= MOD;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 1; j <= rollMax[i]; j++) {
                res += f[n][i][j];
                res %= MOD;
            }
        }
        return res;
    }
};