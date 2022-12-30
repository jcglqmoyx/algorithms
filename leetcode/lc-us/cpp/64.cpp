#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        vector<vector<int>> dp(grid);
        for (int i = 1; i < dp.size(); i++) dp[i][0] += dp[i - 1][0];
        for (int j = 1; j < dp[0].size(); j++) dp[0][j] += dp[0][j - 1];
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp.back().back();
    }
};