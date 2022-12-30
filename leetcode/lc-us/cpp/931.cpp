#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = (int) matrix.size();
        if (n == 1) return matrix[0][0];
        vector<vector<int>> dp(matrix);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0 && j < n - 1) {
                    dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
                } else if (j > 0) {
                    dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
                } else if (j < n - 1) {
                    dp[i][j] += min(dp[i - 1][j], dp[i - 1][j + 1]);
                }
            }
        }
        int min_sum = 10000;
        for (int sum: dp.back()) {
            min_sum = min(min_sum, sum);
        }
        return min_sum;
    }
};