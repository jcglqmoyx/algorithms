#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int m, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> f(n + 1, vector<int>(target + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int k = 1; k <= min(j, m); k++) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
                }
            }
        }
        return f[n][target];
    }
};