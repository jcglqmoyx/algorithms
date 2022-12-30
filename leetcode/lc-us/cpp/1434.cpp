#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberWays(vector<vector<int>> &hats) {
        const int MOD = 1e9 + 7;
        int n = (int) hats.size();

        vector<long long> memo(n);
        int max_id = 0;
        for (int i = 0; i < n; i++) {
            long long mask = 0;
            for (int hat: hats[i]) {
                mask |= 1LL << hat;
                max_id = max(max_id, hat);
            }
            memo[i] = mask;
        }

        int f[max_id + 1][1 << n];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= max_id; i++) {
            for (int j = 0; j < 1 << n; j++) {
                f[i][j] = f[i - 1][j];
                for (int k = 0; k < n; k++) {
                    if (j >> k & 1 && memo[k] >> i & 1) {
                        f[i][j] += f[i - 1][j - (1 << k)];
                        f[i][j] %= MOD;
                    }
                }
            }
        }
        return f[max_id][(1 << n) - 1];
    }
};