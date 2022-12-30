#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> res;
        double total = pow(6, n);
        res.reserve(5 * n + 1);
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= i * 6; j++) {
                for (int k = 1; k <= min(j, 6); k++) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        for (int i = n; i <= 6 * n; i++) {
            res.push_back(dp[n][i] / total);
        }
        return res;
    }
};